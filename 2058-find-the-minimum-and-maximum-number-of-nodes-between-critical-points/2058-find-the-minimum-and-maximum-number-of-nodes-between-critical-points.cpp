class Solution {
public:
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {

        if (head == NULL || head->next == NULL || head->next->next == NULL) {
            return {-1, -1};
        }

        ListNode* prev = head;
        ListNode* curr = head->next;
        ListNode* next = curr->next;

        int pos = 1;

        int first = -1;
        int last = -1;

        int mini = INT_MAX;
        int maxi = -1;

        while (next != NULL) {

            // Check critical point
            if ((curr->val > prev->val && curr->val > next->val) ||
                (curr->val < prev->val && curr->val < next->val)) {

                // First critical point
                if (first == -1) {
                    first = pos;
                }
                else {
                    // Distance from previous critical point
                    mini = min(mini, pos - last);

                    // Distance from first critical point
                    maxi = max(maxi, pos - first);
                }

                last = pos;
            }

            // Move all 3 pointers
            prev = curr;
            curr = next;
            next = next->next;

            pos++;
        }

        // Fewer than 2 critical points
        if (first == last) {
            return {-1, -1};
        }

        return {mini, maxi};
    }
};