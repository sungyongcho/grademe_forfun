/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   해설.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sucho <sucho@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 08:55:51 by sucho             #+#    #+#             */
/*   Updated: 2023/05/17 09:44:51 by sucho            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"
#include <stdio.h>

// 가능하면 재귀 이해하고 쓰는게 가장 쉬운것 같음
int	ft_list_size(t_list *begin_list)
{
	if (begin_list == 0)
		return (0);
	else
		return (1 + ft_list_size(begin_list->next));
}

int	ft_list_size_with_print_data(t_list *begin_list)
{
	printf("[%s]\n", begin_list->data);
	if (begin_list == 0)
		return (0);
	else
		return (1 + ft_list_size(begin_list->next));
}

void	linked_list_print(t_list *begin)
{
	// begin->next 가 안 비어 있다 = linked list에 다음 element가 남아 있다
	while (begin->next){
		// 우선 출력
		printf("%s\n", begin->data);
		// 지금 들어온 begin이 가리키는 주소를 begin->next로 변경
		// 하면...
		// begin은 begin->next가 됨
		begin = begin->next;
	}
}

void	linked_list_print_final(t_list *begin)
{
	// begin이 안 비어 있다 -> 구조체 안에 있는 '원소'(begin.data, begin.next) 값이 쓰레기이든 아니든
	// 일단 비어있진 않음
	while (begin != NULL){
		// 우선 출력
		printf("%s\n", begin->data);
		// 똑같이:
		// 지금 들어온 begin이 가리키는 주소를 begin->next로 변경
		// 하면...
		// begin은 begin->next가 됨
		begin = begin->next;
	}
}

int	ft_list_size_mine(t_list *begin_list)
{
	int result;

	result = 0;
	while (begin_list != NULL){
		result++;
		begin_list = begin_list->next;
	}
	return result;
}

int main(){

	t_list a;
	t_list b;
	t_list c;

// #1.
// 	typedef struct    s_list
// {
//     struct s_list *next;
//     void          *data;
// }                t_list;

//  a.next = b; 를 할 경우 컴파일 에러가 발생
// ft_list_size.c:32:9: error: assigning to 'struct s_list *' from incompatible type 't_list' (aka 'struct s_list'); take the address with &
//         a.next = b;
//                ^ ~
//                  &
// 자료 형이 다르기 때문에 &를 붙였더니 잘 됨
// 구조체 내부에 선언된 struct s_list *next; '포인터 변수' 의 주소값을 할당 해주는 !!!!!!!!!(= 포인터의 '주소값'을 변경)!!!!!!!!
// 그래서 아래 코드는 잘 작동함
	a.next = &b;
	a.data = "aaa";

	b.next = &c;
	b.data = "bbb";

	c.next = '\0';
	c.data = "ccc";
	// output: 3
	printf("#1. %d\n",ft_list_size(&a));

// 2. 포인터?
	// 그냥 복사
	t_list pointer_no;
	pointer_no = a;

	printf("#2-1. %d\n",ft_list_size(&pointer_no));

	// 포인터
	t_list	*pointer_y;

	// 포인터라서 주소 할당
	pointer_y = &a;

	// 포인터 변수로 선언 -> 함수 파라미터와 타입 똑같음 -> 그대로 집어넣음
	printf("#2-2. %d\n",ft_list_size(pointer_y));

	// 이건 왜 4가 나올까? 주소값 전달도 가능?
	printf("#2-3. %d\n",ft_list_size(&pointer_y));

	// ChatGPT:
	// In your code, pointer is a pointer variable that points to the a variable.
	// When you pass &pointer to the ft_list_size function, you are essentially passing the address of the pointer variable itself,
	// 'not' the address of the a variable. As a result, the ft_list_size function treats it as a separate linked list with one node (pointer), resulting in a size of 1 rather than 3.

	// 확인방법
	printf("==================\n");
	int result = ft_list_size_with_print_data(pointer_y);
	printf("#2-4. %d\n",result);

	printf("==================\n");

	printf("==================\n");
	result = ft_list_size_with_print_data(&pointer_y); // 시작 't_list.data' 값부터 다르게 출력되는듯?
	printf("#2-5. %d\n",result);

	printf("==================\n");


// 3. 포인터 특성 활용해서 순회, linked list data 순서대로 출력해보기 (함수 참조)
	printf("========linked_list_print=======\n");
	linked_list_print(&a);
	printf("================================\n");
	// 전체 다 프린트 하는거면 aaa, bbb, ccc가 나와야 하는데 aaa, bbb 만 나옴

	printf("========linked_list_print=======\n");
	linked_list_print_final(&a);
	printf("================================\n");

// 4. ft_list_size 구현
// linked_list_print 코드를 그대로 이용
	if (ft_list_size(&a) == ft_list_size_mine(&a))
		printf("#4. %d\n",ft_list_size_mine(&a));
		printf("same\n");

}
