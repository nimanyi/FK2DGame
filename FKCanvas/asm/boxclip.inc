	mov eax,[ecx]WBmpStruct.ky
	mov edi,[ecx]WBmpStruct.ptr	; Ŀ��λͼ������ָ��
	mov edx,[ebx]WBoxStruct.h	; �������εĸ߶�
	mov h,edx
	sub eax,[ebx]WBoxStruct.ky	; eax = BLIT ��Դλͼ����λ��
	jns _under_firstline

	add h,eax		; ������ҪBLIT������
	jle _endclip
	mov eax,h
	jmp _adjust_height
_endclip:
	xor eax,eax
	ret -1
	
_under_firstline:
	cmp eax,[ecx]WBmpStruct.h	; �Ƚ�Ŀ��λͼ�ĸ߶�
	jge _endclip
	mov edx,eax
	add eax,h
	imul edx,[ecx]WBmpStruct.pitch	; ����Ŀ��λͼָ��
	add edi,edx

_adjust_height:
	
	sub eax,[ecx]WBmpStruct.h	; Box ���¶˺� Ŀ��ͼ�¶˲�(����)
	jl _dealwith_width
	sub h,eax		; ������Ҫ blit ������

_dealwith_width:
	mov edx,[ebx]WBoxStruct.w	; ���� box �Ŀ���
	mov eax,[ecx]WBmpStruct.kx
	mov w,edx
	sub eax,[ebx]WBmpStruct.kx	; eax = BLIT ��Ŀ��λͼ����λ��
	jns _right_firstcol

	add w,eax		; ������Ҫ BLIT ������
	jle _endclip
	mov eax,w
	jmp _adjust_width

_right_firstcol:
	cmp eax,[ecx]WBmpStruct.w	; �Ƚ�Ŀ��λͼ�Ŀ���
	jge _endclip			; ����λͼ����ת
	lea edi,[edi+eax*2]		; ���� this λͼָ��
	add eax,w

_adjust_width:
	sub eax,[ecx]WBmpStruct.w	; bmp ͼ���Ҷ˺�Ŀ��λͼ�Ҷ˲�(����)
	jl _blit
	sub w,eax
