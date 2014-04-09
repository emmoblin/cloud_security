1. generate linker script.

����Ĭ�ϵ����ӿ��ƽű��ļ�������Ϊlinker.lds

ͨ������gcc -Wl,--verbose���Ի��Ĭ�ϵ����ӿ��ƽű�, ��ѡ�� "=======..."֮����ı�������Ϊlinker.lds�ļ�

2. Add function control to the linker.lds file

��linker.lds�ļ������ӱ�����Ҫ���Ƶ���䣺
       ������
       /*����__initcall_start����Ϊ��ǰλ��,��.����ǰλ��*/
     __initcall_start = .;
     function_ptrs   : { *(function_ptrs) }
     __initcall_end = .;
     /*����3�д������function_ptrs��λ��__initcall_start��__initcall_end֮��*/
     code_segment    : { *(code_segment) }
    ��δ���copy��linker.lds�ļ���
           __bss_start = .;
���֮ǰ

3. compiler

���
gcc -Tlinker.lds -o doinitcall doinitcall.c
       ���У�
-Tѡ�����ldҪ�õ����ӿ��ƽű��ļ�,��Ϊ���ӳ�������ݡ���ʽ���£�
              -T commandfile ��
              --script=commandfile

4. results

ִ�г�����Կ������½����
$ ./doinitcall      
       in main()
       call_p: 0x804961c
       my_init () #1
       call_p: 0x8049620
       my_init () #2