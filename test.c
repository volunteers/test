/* local header files */
#include <iostream>
#include "stdlib.h"
#include "stdio.h"
#include <math.h>
#include <string.h>
//#include <string>
#include <ctype.h>

    

/* 3/6/2013 */
int reverse_int(int x) 
{
  int sign = 0;
  int rem, temp = 0;
  if (x == 0) return 0;
  if (x < 0) 
  {
    sign = 1;
    x = -x;
  }
  while (x > 0)
  {
    rem = x%10;
    temp = 10*temp + rem;
    x /= 10;
  }
  if (sign == 1)
  {
    return -temp;
  }
  
  return temp;
}
void test_reverse_int()
{
  printf("%d\n", reverse_int(-24)); // 11, -20, 
}

int closeSQRT(int n)
{
  int low = 0, high = n/2+1;
  int m;
  if (n < 0) return -1;
  while (low+1 < high)
  {
    m = (low + high)/2;
    if (m*m < n)
      low = m;
    else if (m*m > n)
      high = m;
    else return m;
  }
  if (n-low*low < high*high-n) return low;
  else return high;
}
void test_closeSQRT()
{
  printf("%d\n", closeSQRT(15));
}

double sqrt2(double n)		/* old version is wrong, your test cases are so limited */
{
  if (n < 0) return -1;
  if (n ==0 || n == 1) return n;
  double p = 0.00001;
  double low = 0., high = n/2.;
  double m;
  if (n < 1) high = 1;
  while (low < high)
  {
    m = (low + high)/2.;
    if (fabs(m*m-n) < p)
      return m;
    else if (m*m - n > 0)
      high = m;
    else 
      low = m;
  }
  return m;
}
void test_sqrt2()
{
  printf("%f\n", sqrt2(0.4));
}

void bestStock(int *a, int size, int *buy, int *sell)
{
  int i, j, diff, low = a[0], temp = 0;
  for (i=0; i<size; i++)
  {
    if (low > a[i])
    {
      j = i;
      low = a[i];
    }
    diff = a[i] - low;
    if (diff > temp)
    {
      temp = diff;
      *sell = i;
      *buy = j;
    }
  }
}
void test_bestStock()
{
  int buy, sell;
  int a[]={4,2,3,7,3,1,9};
  int size = 7;
  bestStock(a, size, &buy, &sell);
  printf("buy=%d, sell=%d\n", a[buy], a[sell]);
}


int palindrom(int x)
{
  int l, r;
  int div = 1;
  while (x/div >= 10)
  {
    div *= 10;
  }
  while (x > 10)
  {
    l = x/div;
    r = x%10; 
    if (l != r)
      return 0;
    x %= div;
    x /= 10;
    div /= 100;
  }
  return 1;
}
void test_palindrom()
{
  printf("is it palindrom? (%d_)\n", palindrom(123121));
}


int rand7()			/* from rand5 to rand7 */
{
  int i;
  while(1)
  {
    //    i = 5*rand5() + rand5();
    if (i < 21)
      return i%7;
  }
}
  
void sum2value(int nums[],int size,int value) /* sort first, or use hash table */
{
  int front=0, end=size-1;
  int i;
  while(front < end)
  {
    if (nums[front] + nums[end] > value)
      end--;
    else if (nums[front] + nums[end] < value)
      front++;
    else
    {
      printf("find 2 values\n");
      return;
    }
  }
  printf("cannot find\n");
}
void test_sum2value()
{
  int nums[7] = {1, 2, 3, 4, 5, 6, 7};
  int size = 7;
  sum2value(nums, size, 17);
}

int fibonacci (int n)		/* c = b + a, f(n)=f(n-1)+f(n-2) */
{
  int a=0, b=1, c;
  int i;
  if (n == 0) return 0;
  if (n == 1) return 1;
  for (i = 2; i <= n; i++)
  {
    c = a + b;
    a = b;
    b = c;
  }
  return c;
}
int fibonacci2(int n)
{
  if (n == 0) return 0;
  if (n == 1) return 1;
  return (fibonacci2(n-1)+ fibonacci2(n-2));
}
  
  
void test_fibonacci()
{
  printf("fibonacci result=%d\n", fibonacci(9));
  printf("fibonacci result=%d\n", fibonacci2(9));
}

void * memmove(void * pvDest, const void * pvSrc, size_t n) 
{
  char *Dest = (char*)pvDest;
  char *Src = (char*)pvSrc;
  if ((Dest > Src) && (Dest < Src + n))	/* overlap */
  {
    Dest += n-1;
    Src += n-1;
    while(n-- > 0)
      *(Dest--) = *(Src--);
  }
  else
  {
    while(n-- > 0)
      *(Dest++) = *(Src++);
  }
}
    
int numZeros(int num) 		/* n!, how many zeroes at the end */
{
  int m = 0;
  while (num/5)
  {
    m += num/5;
    num /= 5;
  }
  return m;
}



void test_numZeros()
{
  printf("how many zeros? (%d)\n", numZeros(100));
}
/* 3/12/2013 */
int addwithBinary(int a, int b)	/* 10, 11 */
{
  int x, y;
  while (b!= 0)
  {
    x = a^b;			/* 01 */
    y = (a&b)<<1;		/* 100 */
    //x += y;			/* 101 */
    a = x;			/* 101 */
    b = y;			/* 100 */
  }
  return x;
}
void test_addwithBinary()
{
  printf("%d\n", addwithBinary(2,3));
}

void test_typedef()
{
  printf("%d\n", (int)((char *)1000 + 1));
  printf("%d\n", (int)((char *)1000));
}

double pow_(double x, int n)
{
  int flag = 0;
  double r;
  if (n == 0) return 1.;
  if (n == 1) return x;
  if (n < 0)
  {
    n = -n;
    flag = 1;
  }
  r = pow_(x, n/2);
  r = r*r;
  if (n%2==1)
    r *= x;
  if (flag == 1)
    return 1/r;
  return r;
}

void test_pow_()
{
  printf("%f\n", pow_(3,-2));
}

int isPrime(int n)
{
  if (n < 3) return 0;
  if (n % 2 == 0) return (n==2);
  if (n % 3 == 0) return (n==3);
  if (n % 5 == 0) return (n==5);
  int i;
  for (i = 7; i*i <= n; i+=2)
  {
    if (n % i == 0)
      return 0;
  }
  return 1;
}

void test_isPrime()
{
  printf("isPrime %d\n", isPrime(9));
}

/* 3/13/2013 */
int atoi_(char *s)		/* check -, left to right, overflow, valid char */
{
  int flag = 0;
  int r = 0;
  if (s == NULL) return 0;
  if (*s == '-')
  {
    flag = 1;
    s++;
  }
  else if (*s == '+')
    s++;
  while (*s != '\0')
  {
    if (*s < '0' || *s > '9')
    {
      s++;
      continue;
    }
    r = r*10 + (*s - '0');
    s++;
  }
  if (flag == 1)
    return -r;
  return r;
}
/*
int status = 0;
float atof(char *)
{
  status = 0;
  int flag = 1;
  if (*s == '-')
  {
    flag = -1;
    s++;
  }
  while(*s != '\0')
  {
    */
/* void test_atoi_() */
/* { */
/*   printf("int = %d\n", atoi_("-12e90")); */
/* } */
 
/* 3/20/2013 */
int searchInsert(int A[], int n, int target) /* O(n)solution [1,3],2    [1,3,5],2 */
{
  if (A==NULL) return -1;
  int i;
  if (A[0] > target) return 0;
  if (A[n-1] < target) return n;
  for (i = 0; i < n-1; i++)
  {
    if (A[i] == target) return i;
    if (A[i] < target && target < A[i+1])
      return i+1;
  }
  return n-1;
}

int searchInsert2(int A[], int n, int target) /* O(lg(N)) solution */
{
  if (A == NULL) return -1;
  int l = 0, u = n-1;
  int m = 0;
  if (A[0] > target) return 0;
  if (A[n-1] < target) return n;
  while (l <= u)
  {
    m = (l+u)/2;
    if (A[m] == target)
      return m;
    if (A[m] > target)
    {
      if (A[m-1] < target)
	return m;
      else
	u = m-1;
    }
    else
    {
      if (A[m+1] > target)
	return m+1;
      else
	l = m+1;
    }
  }
}


int isSubstring(char *x, char *y)
{
  if (x==NULL || y==NULL) return 0;
  if (*x == '\0' || *y == '\0') return 0;
  char *p1, *p2;
  int isSub = 0;
  while (*x != '\0')
  {
    p1 = x;
    p2 = y;
    while (*p2)
    {
      if (*p1 != *p2)
      {
	isSub = 0;
	break;
      }
      p1++;
      p2++;
      isSub = 1;
    }
    if (isSub ==1) return 1;
    x++;
  }
  return isSub;
}
void testisSubstring()
{
//  printf("%d\n", isSubstring("111abcdelll", "2abcde"));
}

int findContinueMaxSum(int *a,int size)
{
  int i, temp = a[0];
  int sum = 0;
  for (i = 0; i < size; i++)
  {
    sum += a[i];
    if (temp < sum)
    {
      temp = sum;
    }
    if (sum < 0)
      sum = 0;
  }
  return temp;
}
/* merge two sorted array */
void mergeab2(int a[],int b[],int lenA,int lenB)
{
  int i=lenA, j=lenB;
  int k = lenA + lenB -1;
  while (i>=0 && j>=0)
  {
    if (a[i] >= b[j])
      a[k--] = a[i--];
    else
      a[k--] = b[j--];
  }
  while (j>=0)
    a[i--] = b[j--];
}
  
/* 3/21/2013 */
/*replace space with %20
/* copy to new string */
char * replaceSpace( char *str)
{
  if (*str=='\0' || str == NULL) return str;
  int i=0, len;
  char *p = str;
  while (*p)
  {
    if (*p == ' ')
    {
      i++;
    }
    p++;
  }
  i *= 2;
  len = i + p-str + 1;
  printf("i=%d, len=%d, new len = %d\n", i, p-str, len);
  char *newS = (char *)malloc(len * sizeof(char));
  newS = newS + len;
  *newS = *p;
  newS--;
  p--;
  
  while (p >= str)
  {
    if (*p == ' ')
    {
      *newS-- = '0';
      *newS-- = '2';
      *newS-- = '%';
    }
    else
    {
      *newS-- = *p;
      //      printf("%c", *newS);

    }
    p--;
  }
  newS++;
  return newS;
}

 void testreplaceSpace()
 {
//   printf("%s\n", replaceSpace(" hello world  "));
 }

int countNumWords(const char *str) /* abc abc, ...abc, abc... */
{
  int isValid = 1;
  int count = 0;
  while (*str)
  {
    if (*str == ' ')
    {
      isValid = 1;
    }
    if (*str != ' ' && isValid == 1)
    {
      count++;
      isValid = 0;
    }

    str++;
  }
  return count;
}
 void testcountNumWords()
 {
   printf("word#=%d\n", countNumWords(" a b "));
 }

#if 1
void reverseString4( char *str)
{
  char *p = str;
  char *p2 = str;
  char temp;
  while(*p++);
    
  int i = 0;
  p-=2; ;
  while (p2 < p)
  {
    temp = *p;
    *p = *p2;
    *p2 = temp;
    p2++;
    p--;
  }
  for (i = 0; i<6; i++)
    printf("--%c", str[i]);
}
#endif
#if 0
void reverseString4( char *str)
{
       char * end = str;
       if (str == NULL) return ;
       while (*end)
            end++;
      end--;

      
       while (str < end)
      {
            *str ^= *end;
            *end ^= *str;
            *str ^= *end;
            str++;
            end--;
      }
}
#endif
 void testreverseString4()
 {
   char *s = (char *)malloc(10);
   /* strcpy(s, "123456"); */
   printf("%s\n", s);
   reverseString4(s);
   printf("\n%s\n", s);
   free(s);
 }

char* strstr2 (const char * str1,const char * str2)
{

}


/* 4/1/2013 */
typedef struct ListNode{
    int val;
    ListNode *next;
}ListNode;

void addListNode_head(ListNode **list, int val)
{
    ListNode *temp = *list;
    (*list)->val = val;
    (*list)->next = temp;
}
void addListNode_end(ListNode **list, int val)
{
    ListNode *temp = *list;
    while(temp);
    temp->val = val;
    temp->next = NULL;
}
void printList(ListNode *list)
{
    int count = 0;
    int i;
    ListNode *temp = list;
    while (temp != NULL)
    {
	count++;
	/* printf("count=%d\n", count); */
	temp = temp->next;
    }
    for (i = 0; i < count; i++)
    {
	printf("%d ", list->val);
	list = list->next;
    }
    printf("\n");
}
	     
void createList(ListNode **list)
{
    int i;
    ListNode *curr = *list;
    for (i = 0; i < 9; i++)
    {
	ListNode *temp = (ListNode *)malloc(sizeof(ListNode));
	temp->val = i;
	temp->next = NULL;
	if (*list == NULL)
	{
	    *list = temp;
	    curr = temp;
	}
	else
	    (curr)->next = temp;
	curr = temp;
    }
}
     
ListNode * reverseList(ListNode *list)
{
    ListNode *prev = NULL;
    ListNode *head = list;
    while (head)
    {
        ListNode *next = head->next;
        head->next = prev;
        prev = head;
        head = next;
    }
    return prev;
}

void removeOneNode(ListNode **list, int n)
{
    int i = 0;
    ListNode *temp = *list;
    if (n == 0)
    {
	ListNode *next = temp->next;
	*list = next;
    }
    while (temp->next != NULL)
    {
	i++;
	if (i == n)
	{
	    ListNode *next = temp->next->next;
	    temp->next = next;
	}
	temp = temp->next;
    }
}

ListNode *reverseBetween(ListNode *head, int m, int n)
{
    int i = 0;
    ListNode **reserve = &head;
    ListNode *temp = head;
    while(i < m)
    {
	temp = temp->next;
	reserve = &((*reserve)->next);
	i++;
    }
    ListNode *prev = NULL;

    while (i < n)
    {
	ListNode *next = temp->next;
	temp->next = prev;
	prev = temp;
	temp = next;
	i++;
    }
    printList(prev);

    (*reserve)->next = temp;
    *reserve = prev;

    return head;
}

ListNode *removeNthFromEnd(ListNode *head, int n)
{
    ListNode *front = head;
    ListNode **back = &head;
    while(n > 0)
    {
	front = front->next;
	n--;
    }
    while (front->next != NULL)
    {
	back = &((*back)->next);
	front = front->next;
    }
    ListNode *temp = (*back)->next->next;
    (*back)->next = temp;
    return head;
}

/* 4/2/2013 */
/* the reverse of list (1 -> remaining list) will be reverse (remaining list -> 1)
   reverse(1-2-3-4) euqals to reverse(2-3-4)->1
*/
ListNode *reverseList_recursive(ListNode *list)
{
    if (list == NULL || list->next == NULL)
	return list;
    ListNode *reserve = reverseList_recursive(list->next);

    /* need to find the tail of remainingReverse and update the tail as our beginning element */
    ListNode *cur = reserve;
    while (cur->next != NULL)
	cur = cur->next;

    /* assign beginning element in original list to reversed list tail */
    cur->next = list;

    /* update beginning element list next to NULL */
    list->next = NULL;
    return reserve;
}


/* 4/3/2013 */

void printParenthsis(int left, int right, char *s, int pairs)
{
    if (left == pairs &&right == pairs)
    {
	printf("%s\n", s);
	/* s[0]='\0'; */
	/* return; */
    }
    else{
	
    if (left < pairs)
    {
	/* printParenthsis(left + 1, right, strcat(s, "("), pairs); */
	/* if (left < right) */
	    /* printParenthsis(left, right - 1, strcat(s, ")")); */
    }
    if (right < pairs)
	;	/* printParenthsis(left, right +1, strcat(s, ")"), 3); */
    }
}

void testPrintParent()		/* Wrong~~~~~~ */
{
    char *s = (char *)malloc(3*3);
     s[6] = '\0'; 
     printParenthsis(0,0,s, 3);
}

/* 4/8/2013 */
void reverseS(char *s, int start, int end)
{
    char temp;
    while (start < end)
    {
	temp = s[start];
	s[start] = s[end];
	s[end] = temp;
	start++;
	end--;
    }
}
char * reverseString(char *s)
{
    char size = strlen(s);
    int i, j = 0;
    reverseS(s, 0, size-1);

    for (i = 0; i <= size; i++)
    {
	if (s[i] == ' '  || s[i] == '\0')
	{
	    reverseS(s, j, i-1);
	    j = i + 1;
	}
    }
    return s;
}
void testreverseString()
{
    char *a = (char *)malloc(10 * sizeof(char));
    strcpy(a, "abc def");
    printf("%s\n", reverseString(a));
    free(a);
}


/* 4/9/2013 */
int lengthLongestSubString(char *s, int size) /* this one is wrong, think of "abcabcda, should return abcd, but failed */
{
    if (size <= 1) return size;
    if (s == NULL) return -1;
    int i, count = 0, temp = 0;
    int a[256] = {0};
    /* for (i = 0; i < 256; i++) */
    /* { */
    /* 	a[i] = -1; */
    /* } */
    for (i = 0; i < size; i++)
    {
	if (a[s[i]] == 0)
	{
	    a[s[i]] = 1;
	    count++;
	 
	}
	else
	{
	    if (temp < count)
		temp = count;
	    count = 0;
	}
    }
    if (temp < count) return count;
    return temp;
}

int lengthLongestSubString2(char *s, int size) /* correct version */
{
    if (size <= 1) return size;
    int i, j = 0, count, temp = 0;
    int map[256] = {0};

    for (i = 0; i < size; i++)
    {
	if (map[s[i]] == 0)
	{
	    map[s[i]] = 1;
	}
	else
	{
	    count = i-j;
	    if (temp < count)
		temp = count;
	    while (s[j] != s[i])
	    {
		map[s[j]] = 0;
		j++;
	    }
	    j++;
	}
    }
    if (temp < (i-j)) return (i-j);
    return temp;
}

void testlengthLongestSubString()
{
    char s[6];
    strcpy(s, "abcabcde");
    printf("lognest:%d\n",lengthLongestSubString2(s, 9));
}

/* 4/10/2013 */

int isPalindrome(char *s)
{
    int size = strlen(s);
    if (size <= 1) return 1;
    int front = 0, back = size -1;
    while (front < back)
    {
	if (isalpha(s[front]) && isalpha(s[back]))
	{
	    if (s[front] == s[back] || abs(s[front]-s[back]) == 32)
	    {
		front++;
		back--;
	    }
	    else
		return 0;
	}
	if (!isalpha(s[front]))
	    front++;
	if (!isalpha(s[back]))
	    back--;
    }
    return 1;
}
void testisPalindrome()
{
    printf("%d\n", isPalindrome("1a2"));
}
/*
 *  ======== main ========
 */

int main(int argc, char* argv[])
{
    testisPalindrome();
    
    
    ListNode *list = NULL;//(ListNode*)malloc(sizeof(ListNode));
    createList(&list);
    ListNode *list3 = reverseList_recursive(list);
    printList(list3);
  return 0;
    testlengthLongestSubString();
  //tetestreverseString();
  //testPrintParent();st_sqrt2();
    removeNthFromEnd(list, 4);
    //ListNode *list2 = reverseList(list);
    //removeOneNode(&list2, 11);
    /* ListNode *list3 = reverseBetween(list, 2,5); */
  testreverseString4();
  testcountNumWords();
  testreplaceSpace();
  testisSubstring();
//  test_atoi_();
  test_isPrime();
  test_pow_();
  test_typedef();
  test_addwithBinary();
  test_numZeros();
  test_fibonacci();
  test_sum2value();
  test_palindrom();
  test_bestStock();
  test_closeSQRT();
  test_reverse_int();
}
