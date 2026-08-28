# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
import heapq


class Solution:
    def mergeKLists(self, lists: List[Optional[ListNode]]) -> Optional[ListNode]:
        heap = []
        ctr = 0
        for ll in lists:
            if ll:
                heapq.heappush(heap, (ll.val, ctr, ll))
                ctr += 1
        head = ListNode()
        curr = head
        while len(heap) != 0:
            _, _, node = heapq.heappop(heap)
            curr.next = node
            curr = curr.next
            if node.next:
                heapq.heappush(heap, (node.next.val, ctr, node.next))
                ctr += 1

        return head.next
