// 맨 처음 읽을때 5번 읽지 마세요!!!

void	ft_list_remove_if(t_list **begin_list, void *data_ref, int (*cmp)())
{
	// 1. 파라미터로 받아오는 begin_list가 null 이다 -> begin_list 가 비어있다.
	//    일단 다음걸로

	// 5. !! begin_list 가 비어있다 = linked_list가 끝났다 !!
	//    !!    = linked_list 처음부터 끝까지 돌았다        !!
	if(begin_list == NULL || *begin_list = NULL)
		return;

	// 2. 포인터 지정해
	t_list *cur = *begin_list;

	// 3. 삭제 함수 포인터
	if (cmp(cur->data, data_ref) == 0)
	{
		// *begin_list = cur 이었던 상태 ('다음') 에서 *begin_list = cur->next; ('다다음') 로 바꿔줌
		*begin_list = cur->next;
		// '다다음'을 이어줬으니 '다음' 은 삭제
		free(cur);
		// 지웠으니까 다음
		// 5번으로
		ft_list_remove_if(begin_list, data_ref, cmp);
	}

	// 4. 2번에서 대입한 cur = *begin_list; 다시 그대로 씀
	//	  (이후는 복잡하면 이해 안해도됨) cur가 위 조건문 타고 free 된 상태일 수도 있음
	//                             free 되었으면 다시 재할당 (삭제 안되있어도 똑같은 코드라 동작에 이상 없음)
	cur = *begin_list;
	// 지웠으니까 다음
	// 5번으로
	ft_list_remove_if(&cur->next, data_ref, cmp);
    // (위 조건문에 들어가는 값의 차이는, cur 재 할당 이후에 &cur->next로 linked-list의 다음 원소(node)로 이동하기 위해서)
}
