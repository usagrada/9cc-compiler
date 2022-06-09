#include "9cc.h"

int main(int argc, char **argv)
{
    if (argc != 2)
    {
        error("引数の個数が正しくありません");
        return 1;
    }

    user_input = argv[1];

    // トークナイズする
    token = tokenize(argv[1]);
    Node *node = expr();

    // アセンブリの前半部分を出力
    printf(".intel_syntax noprefix\n");
    printf(".globl main\n");
    printf("main:\n");

    // 式の最初は数でなければならないので、それをチェックして
    // 最初のmov命令を出力
    // printf("  mov rax, %d\n", expect_number());
    gen(node);

    printf("  pop rax\n");
    printf("  ret\n");
    return 0;
}
