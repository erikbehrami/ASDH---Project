#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
#include <queue>
#include <stack>
#include <map>
#include <map>
using namespace std;

// Definimi i pemes binare
//----------------------------------------------------------------------------------------
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
//----------------------------------------------------------------------------------------
// Shtimi i vlerave ne peme
TreeNode *insert(TreeNode *root, int val)
{
    if (root == nullptr)
    {
        return new TreeNode(val);
    }

    if (val < root->val)
    {
        root->left = insert(root->left, val);
    }
    else
    {
        root->right = insert(root->right, val);
    }

    return root;
}
// Anetaret ne Peme
void TreeMember(TreeNode *&root)
{
    int n;
    for (int i = 0; i < 5; i++)
    {
        cout << "Member " << i + 1 << ": ";
        cin >> n;
        root = insert(root, n);
    }
}
// Printimi i Pemes
void printTree(TreeNode *node)
{
    if (node == NULL)
    {
        return;
    }
    cout << node->val << " ";
    printTree(node->left);
    printTree(node->right);
}
// Definimi i Listes se Lidhur
struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
// Shtimi i anetareve ne liste te lidhur
void addNode(ListNode *&head, int value)
{
    ListNode *newNode = new ListNode(value);
    if (head == NULL)
    {
        head = newNode;
    }
    else
    {
        ListNode *current = head;
        while (current->next != NULL)
        {
            current = current->next;
        }
        current->next = newNode;
    }
}
// Antaret ne liste te lidhur
void LinkedListMembers(ListNode *&head)
{
    int a;
    for (int i = 0; i < 5; i++)
    {
        cout << "Member " << i + 1 << ": ";
        cin >> a;
        addNode(head, a);
    }
}
// Printimi i listes se lidhur
void printLinkedList(ListNode *head)
{
    ListNode *current = head;
    while (current != NULL)
    {
        cout << current->val << " ";
        current = current->next;
    }
}
//{----------------------------------------------------------------------------------------}//
//{----------------------------------------------------------------------------------------}//

// 1 - Time: O(n), Space: O(n)
class Solution1
{
    void calculateSum(TreeNode *root, int low, int high, int &sum)
    {
        if (root == NULL)
        {
            return;
        }
        if (root->val >= low && root->val <= high)
        {
            sum += root->val;
        }
        calculateSum(root->left, low, high, sum);
        calculateSum(root->right, low, high, sum);
    }

public:
    int rangeSumBST(TreeNode *root, int low, int high)
    {
        int sum = 0;
        calculateSum(root, low, high, sum);
        return sum;
    }
};

//{----------------------------------------------------------------------------------------}

// 2 -  Time: O(logn), Space: O(logn)
class Solution2
{
public:
    TreeNode *n;
    TreeNode *searchBST(TreeNode *root, int val)
    {
        if (root == NULL)
        {
            return NULL;
        }
        else if (root->val == val)
        {
            n = root;
        }
        else if (root->val < val)
        {
            searchBST(root->right, val);
        }
        else
        {
            searchBST(root->left, val);
        }
        return n;
    }
};
//----------------------------------------------------------------------------------------

// 3 - Time: O(n), Space: O(n)
class Solution3
{
public:
    TreeNode *sortedArrayToBSTHelper(vector<int> &nums, int start, int end)
    {
        if (start > end)
        {
            return NULL;
        }
        int n = (start + end) / 2;
        TreeNode *root = new TreeNode(nums[n]);
        root->left = sortedArrayToBSTHelper(nums, start, n - 1);
        root->right = sortedArrayToBSTHelper(nums, n + 1, end);
        return root;
    }

    TreeNode *sortedArrayToBST(vector<int> &nums)
    {
        return sortedArrayToBSTHelper(nums, 0, nums.size() - 1);
    }
};
//----------------------------------------------------------------------------------------

// 4 - Time: O(n), Space: O(n)
class Solution4
{
public:
    vector<int> v;
    void elements(TreeNode *root)
    {
        if (root = NULL)
            return;

        v.push_back(root->val);
        elements(root->left);
        elements(root->right);
    }

    bool findTarget(TreeNode *root, int k)
    {
        elements(root);
        unordered_map<int, int> mp;

        for (int i = 0; i < v.size(); i++)
        {
            int num = v[i]; // [num + x = k => x = k - num]
            if (mp.find(k - num) != mp.end())
            {
                return true;
            }
            else
            {
                mp[v[i]] = i;
            }
        }
        return false;
    }
};
//----------------------------------------------------------------------------------------

// 5 - Time: O(nlogn), Space: O(n)
class Solution5
{
public:
    vector<int> v;
    void preorder(TreeNode *root)
    {
        if (root == NULL)
            return;

        v.push_back(root->val);
        preorder(root->left);
        preorder(root->right);
    }
    vector<int> getAllElements(TreeNode *root1, TreeNode *root2)
    {
        preorder(root1);
        preorder(root2);
        sort(v.begin(), v.end());
        return v;
    }
};
//----------------------------------------------------------------------------------------

// 6 - Time: O(n), Space: O(1)
class Solution6
{
public:
    ListNode *middleNode(ListNode *head)
    {
        ListNode *lista = head;
        int i = 0;
        while (lista != NULL)
        {
            lista = lista->next;
            i++;
        }
        int rez = i / 2;
        ListNode *middle = head;
        int j = 0;
        while (j < rez)
        {
            middle = middle->next;
            j++;
        }
        return middle;
    }
};
//----------------------------------------------------------------------------------------

// 7 - Time: O(n), Space: O(n)
class Solution7
{
public:
    ListNode *reverseList(ListNode *head)
    {
        stack<int> st;
        if (head == NULL)
        {
            return head;
        }
        ListNode *temp = head;
        while (temp)
        {
            st.push(temp->val);
            temp = temp->next;
        }
        ListNode *temp1 = head;
        while (!st.empty())
        {
            int topval = st.top();
            st.pop();
            temp1->val = topval;
            temp1 = temp1->next;
        }
        return head;
    }
};
//----------------------------------------------------------------------------------------

// 8 - Time: O(n), Space: O(n)
class Solution8
{
public:
    ListNode *mergeTwoLists(ListNode *list1, ListNode *list2)
    {
        if (list1 == nullptr)
        {
            return list2;
        }
        if (list2 == nullptr)
        {
            return list1;
        }
        if (list1->val <= list2->val)
        {
            list1->next = mergeTwoLists(list1->next, list2);
            return list1;
        }
        else
        {
            list2->next = mergeTwoLists(list1, list2->next);
            return list2;
        }
    }
};
//----------------------------------------------------------------------------------------

// 9 - Time: O(n), Space: O(1)
class Solution9
{
public:
    ListNode *deleteDuplicates(ListNode *head)
    {
        ListNode *lista = head;
        while (lista != NULL && lista->next != NULL)
        {
            if (lista->val == lista->next->val)
            {
                lista->next = lista->next->next;
            }
            else
            {
                lista = lista->next;
            }
        }
        return head;
    }
};
//----------------------------------------------------------------------------------------

// 10 - Time: O(n), Space: O(1)
class Solution10
{
public:
    bool hasCycle(ListNode *head)
    {
        ListNode *f1 = head;
        ListNode *f2 = head;
        while (f1 != NULL && f1->next != NULL)
        {
            f1 = f1->next->next;
            f2 = f2->next;
            if (f1 == f2)
            {
                return true;
            }
        }
        return false;
    }
};
//----------------------------------------------------------------------------------------

// 11 - Time: O(n), Space: O(n)
class Solution11
{
public:
    bool isValid(string s)
    {
        stack<char> e;
        for (int i = 0; i < s.length(); i++)
        {
            char c = s[i];
            if (c == '(' || c == '[' || c == '{')
            {
                e.push(c);
            }
            else
            {
                if (e.empty())
                {
                    return false;
                }
                char top = e.top();
                if ((c == ')' && top == '(') || (c == ']' && top == '[') || (c == '}' && top == '{'))
                {
                    e.pop();
                }
                else
                {
                    return false;
                }
            }
        }
        return e.empty();
    }
};
//----------------------------------------------------------------------------------------

// 12 - Time: O(n), Space: O(n)
class Solution12
{
public:
    int timeRequiredToBuy(vector<int> &tickets, int k)
    {
        int a = 0;
        while (true)
        {
            if (tickets[k] == 0)
                break;
            for (int i = 0; i < tickets.size(); i++)
            {
                if (tickets[k] == 0)
                    break;
                if (tickets[i] > 0)
                {
                    tickets[i] -= 1;
                    a += 1;
                }
            }
        }
        return a;
    }
};
//----------------------------------------------------------------------------------------

// 13 - Time: O(n^2), Space: O(1)
class Solution13
{
public:
    int firstUniqChar(string s)
    {

        for (int i = 0; i < s.length(); i++)
        {
            char z = s[i];
            bool isUnique = true;

            for (int j = 0; j < s.length(); j++)
            {
                if (i != j && z == s[j])
                {
                    isUnique = false;
                    break;
                }
            }

            if (isUnique)
            {
                return i;
            }
        }

        return -1;
    }
};
//----------------------------------------------------------------------------------------

// 14 - Time: O(n), Space: O(n)
class Solution14
{
public:
    string removeDuplicates(string s)
    {
        stack<char> stack;

        for (char c : s)
        {
            if (!stack.empty() && stack.top() == c)
            {
                stack.pop();
            }
            else
            {
                stack.push(c);
            }
        }

        string result;
        while (!stack.empty())
        {
            result = stack.top() + result;
            stack.pop();
        }
        return result;
    }
};
//----------------------------------------------------------------------------------------

// 15 - Space: O(n)
class MyStack
{
public:
    queue<int> q;
    MyStack() {}
    void push(int x)
    {
        q.push(x); // Time: O(n)
        int s = q.size();
        for (int i = 0; i < s - 1; i++)
        {
            q.push(q.front());
            q.pop();
        }
    }

    int pop() // Time: O(1)
    {
        int top = q.front();
        q.pop();
        return top;
    }

    int top()
    {
        return q.front(); // Time: O(1)
    }

    bool empty()
    {
        return q.empty();
    }
};
//----------------------------------------------------------------------------------------

// 16 - Time: O(n), Space: O(n)
class Solution16
{
public:
    vector<int> twoSum(vector<int> &nums, int target)
    {
        unordered_map<int, int> hash;

        for (int i = 0; i < nums.size(); i++)
        {
            int num = nums[i]; // [num + x = target => x = target - num]
            if (hash.find(target - num) != hash.end())
            {
                return {i, hash[target - num]};
            }
            else
            {
                hash[num] = i;
            }
        }

        return {-1, -1};
    }
};
//----------------------------------------------------------------------------------------

// 17 - Time: O(n), Space: O(n)
class Solution17
{
public:
    int findPermutationDifference(string s, string t)
    {
        int sum = 0;
        map<char, int> sMap;
        map<char, int> tMap;

        for (int i = 0; i < s.size(); i++)
        {
            sMap[s[i]] = i;
            tMap[t[i]] = i;
        }

        for (int i = 0; i < s.size(); i++)
        {
            sum += (abs(sMap[s[i]] - tMap[s[i]]));
        }

        return sum;
    }
};
//----------------------------------------------------------------------------------------

// 18 - Time: O(n), Space: O(n)
class Solution18 {
public:
        vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        int length = nums.size();
        map <int, int> mp;
        vector <int> numsSorted = nums;
        sort(numsSorted.begin(), numsSorted.end());

        for(int i = length - 1; i >= 0; i--){
            mp[numsSorted[i]] = i;
        }
        for(int i = 0; i < length; i++){

            nums[i] = mp[nums[i]];
        }

        return nums;
    }

};

//----------------------------------------------------------------------------------------
// 19 - Time: O(n), Space: O(n)
class Solution19
{
public:
    int numJewelsInStones(string jewels, string stones)
    {
        map<char, bool> m;

        for (auto x : jewels)
        {
            m[x] = true;
        }
        int count = 0;
        for (auto x : stones)
        {
            if (m[x])
            {
                count++;
            }
        }

        return count;
    }
};

//----------------------------------------------------------------------------------------
// 20 -  Time: O(n), Space: O(n)
class Solution20
{
public:
    char repeatedCharacter(string s)
    {
        unordered_map<char, int> m;

        for (int i = 0; i < s.size(); i++)
        {

            if (m.find(s[i]) != m.end())
            {
                return s[i];
            }
            else
            {
                m[s[i]] = i;
            }
        }

        return ' ';
    }
};

int main()
{
    cout << "<This is a simple program that includes the solutions of 20 leetcode problems>" << endl;
start:
    cout << "--------------------------------------------------------------" << endl;
    cout << "List of functions: " << endl;
    cout << "1. Range Sum of BST" << endl;
    cout << "2. Search in a Binary Search Tree" << endl;
    cout << "3. Convert Sorted Array to Binary Search Tree" << endl;
    cout << "4. Two Sum IV - Input is a BST" << endl;
    cout << "5. All Elements in Two Binary Search Trees" << endl;
    cout << "6. Middle of the Linked List" << endl;
    cout << "7. Reverse Linked List" << endl;
    cout << "8. Merge Two Sorted Lists" << endl;
    cout << "9. Remove Duplicates from Sorted List" << endl;
    cout << "10. Linked List Cycle" << endl;
    cout << "11. Number of Recent Calls" << endl;
    cout << "12. Time Needed to Buy Tickets" << endl;
    cout << "13. First Unique Character in a String" << endl;
    cout << "14. Remove All Adjacent Duplicates In String" << endl;
    cout << "15. Implement Stack using Queues" << endl;
    cout << "16. Two Sum" << endl;
    cout << "17. Permutation Difference between Two Strings" << endl;
    cout << "18. How Many Numbers Are Smaller Than The Current One" << endl;
    cout << "19. Jewels and Stones" << endl;
    cout << "20. First Letter to Appear Twice" << endl;
    cout << "--------------------------------------------------------------" << endl;
    cout << "The solution of which problem do you want: ";
    int a;
    cin >> a;
    switch (a)
    {
    case 1:
    {
        TreeNode *root = NULL;

        cout << "<Members of tree>\n";
        TreeMember(root);

        int low = 7;
        int high = 15;

        Solution1 res;
        int result = res.rangeSumBST(root, low, high);

        cout << "Sum of values in range [" << low << ", " << high << "] is: " << result << endl;
        break;
    }
    case 2:
    {
        TreeNode *root = NULL;

        cout << "<Members of tree>\n";
        TreeMember(root);

        int val;
        cout << "Value: ";
        cin >> val;

        Solution2 solution;
        TreeNode *result = solution.searchBST(root, val);

        if (result != nullptr)
        {
            cout << "Node found with value: " << result->val << endl;
        }
        else
        {
            cout << "Node not found" << endl;
        }

        break;
    }
    case 3:
    {
        Solution3 solution;
        vector<int> nums = {1, 2, 3, 4, 5, 6, 7};

        cout << "Sorted Vector {";
        for (int i = 0; i < nums.size(); i++)
        {
            cout << nums.at(i) << " ";
        }
        cout << "\b}\n";

        TreeNode *root = solution.sortedArrayToBST(nums);

        cout << "Tree {";
        printTree(root);
        cout << "\b}\n";

        break;
    }
    case 4:
    {
        Solution4 solution;
        TreeNode *root = NULL;
        int target;

        cout << "<Members of tree>\n";
        TreeMember(root);

        cout << "Target: ";
        cin >> target;

        bool found = solution.findTarget(root, target);
        if (found)
        {
            cout << "The pair with the sum of " << target << " exist in tree." << endl;
        }
        else
        {
            cout << "The pair with the sum of " << target << " doesn't exist in tree." << endl;
        }

        break;
    }
    case 5:
    {
        Solution5 solution;
        TreeNode *root1 = NULL;
        TreeNode *root2 = NULL;

        cout << "<First Tree>\n";
        TreeMember(root1);

        cout << "<Second Tree>\n";
        TreeMember(root2);

        vector<int> v = solution.getAllElements(root1, root2);
        cout << "Sorted Elements: ";
        for (int i = 0; i < v.size(); i++)
        {
            cout << v.at(i) << " ";
        }
        cout << "\n";
        break;
    }
    case 6:
    {
        Solution6 solution;
        ListNode *head = NULL;

        cout << "<Members of the linked list>\n";
        LinkedListMembers(head);

        ListNode *middle = solution.middleNode(head);

        cout << "The middle node value is: " << middle->val << endl;

        break;
    }
    case 7:
    {
        Solution7 solution;
        ListNode *head = NULL;

        cout << "<Members of the linked list>\n";
        LinkedListMembers(head);
        ListNode *reverse = solution.reverseList(head);

        cout << "Reversed Linked List {";
        printLinkedList(reverse);
        cout << "\b}\n";

        break;
    }
    case 8:
    {
        Solution8 solution;
        ListNode *head1 = NULL;
        ListNode *head2 = NULL;

        cout << "<Members of the first linked list>\n";
        LinkedListMembers(head1);

        cout << "<Members of the second linked list>\n";
        LinkedListMembers(head2);

        ListNode *head = solution.mergeTwoLists(head1, head2);

        cout << "Merged list {";
        printLinkedList(head);
        cout << "\b}\n";
        break;
    }
    case 9:
    {
        Solution9 solution;
        ListNode *head = NULL;

        cout << "<Members of the linked list>\n";
        LinkedListMembers(head);
        ListNode *list = solution.deleteDuplicates(head);

        cout << "Linked list after {";
        printLinkedList(list);
        cout << "\b}\n";
        break;
    }
    case 10:
    {
        Solution10 solution;
        ListNode *head = NULL;

        cout << "<Members of the linked list>\n";
        LinkedListMembers(head);

        bool f = solution.hasCycle(head);

        if (f)
        {
            cout << "The linked list has Cycle\n";
        }
        else
        {
            cout << "The linked list doesn't have Cycle\n";
        }
        break;
    }
    case 11:
    {
        Solution11 solution;

        string a;
        cout << "Write a string: ";
        cin >> a;

        if (solution.isValid(a))
        {
            cout << "Valid Parentheses\n";
        }
        else
        {
            cout << "Invalid Parentheses\n";
        }

        break;
    }

    case 12:
    {
        Solution12 solution;

        vector<int> v = {};
        int k, a;

        for (int i = 0; i < 3; i++)
        {
            cout << "Tickets " << i + 1 << ": ";
            cin >> a;
            v.push_back(a);
        }
        cout << "Enter a number: ";
        cin >> k;

        cout << "The time taken for the person at position " << k
             << " to finish buying tickets is: " << solution.timeRequiredToBuy(v, k - 1) << "\n";
        break;
    }
    case 13:
    {
        Solution13 solution;
        string s;

        cout << "Write a String: ";
        cin >> s;

        int rez = solution.firstUniqChar(s);

        if (rez == -1)
        {
            cout << "The String has no unique character\n";
        }
        else
        {
            cout << "The unique character of the string is found in position " << rez + 1 << ": " << s.at(rez) << endl;
        }
        break;
    }
    case 14:
    {
        Solution14 solution;
        string s;

        cout << "Write a String: ";
        cin >> s;

        string rez = solution.removeDuplicates(s);

        cout << "String after: " << rez << endl;
        break;
    }
    case 15:
    {
        MyStack stack;
        int a;

        for (int i = 0; i < 4; i++)
        {
            cout << "Member " << i + 1 << ": ";
            cin >> a;
            stack.push(a);
        }

        cout << "Top element is: " << stack.top() << endl;
        cout << "Popped element is: " << stack.pop() << endl;
        cout << "Top element after pop is: " << stack.top() << endl;
        cout << "Popped element is: " << stack.pop() << endl;
        cout << "Is stack empty?, " << (stack.empty() ? "Yes" : "No") << endl;
        cout << "Is stack empty?, " << (stack.empty() ? "Yes" : "No") << endl;
        break;
    }
    case 16:
    {
        Solution16 solution;
        vector<int> v;
        int target, a;

        cout << "Vector elements: \n";
        for (int i = 0; i < 5; i++)
        {
            cout << "v[" << i << "]: ";
            cin >> a;
            v.push_back(a);
        }

        cout << "Sum target: ";
        cin >> a;

        vector<int> v1 = solution.twoSum(v, a);

        cout << "{" << v1[1] << ", " << v1[0] << "}\n";
        break;
    }
    case 17:
    {
        Solution17 solution;
        string a, b;

        cout << "Write first string: ";
        cin >> a;
        cout << "Write second string: ";
        cin >> b;

        int n = solution.findPermutationDifference(a, b);

        cout << "Permutation Difference between Two Strings: " << a << " and " << b << " is " << n << endl;

        break;
    }
    case 18:
    {
        Solution18 solution;
        vector<int> v;
        int a;

        cout << "Vector elements: \n";
        for (int i = 0; i < 5; i++)
        {
            cout << "v[" << i << "]: ";
            cin >> a;
            v.push_back(a);
        }

        v = solution.smallerNumbersThanCurrent(v);
        cout << "Smaller number than current one: {";

        for (int i = 0; i < v.size(); i++)
        {   
            if(i!=v.size() - 1)
            cout << v[i] << ", ";
            else
            cout << v[i] << "}.\n";
        }
         
        break;
    }
    case 19:
    {
        Solution19 solution;
        string a, b;

        cout << "Jewels: ";
        cin >> a;
        cout << "Stones: ";
        cin >> b;

        int result = solution.numJewelsInStones(a, b);
        cout << "Number of stones that are also jewels is: " << result << endl;

        break;
    }
    case 20:
    {
        Solution20 solution;
        string s;

        cout << "String: ";
        cin >> s;

        cout << "The first letter to appear twice is: " << solution.repeatedCharacter(s) << endl;
        break;
    }
    default:
        cout << "<<Invalid function>>";
    }
    cout << "--------------------------------------------------------------\n";
    cout << "Do you want to try it again (Yes/No): ";
    string x;
    cin >> x;
    if (x == "Yes" || x == "yes")
    {
        goto start;
    }
    else
    {
        "GoodBye";
    }
}
