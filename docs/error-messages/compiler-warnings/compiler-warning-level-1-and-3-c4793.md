---
title: Aviso do compilador (nível 1 e 3) C4793
ms.date: 11/04/2016
f1_keywords:
- C4793
helpviewer_keywords:
- C6634
- C6635
- C6640
- C6630
- C6639
- C6636
- C6638
- C6631
- C6637
- C4793
ms.assetid: 819ada53-1d9c-49b8-a629-baf8c12314e6
ms.openlocfilehash: de6f514d8e3ad8e7715c9cd13a695e3398fffc8d
ms.sourcegitcommit: 857fa6b530224fa6c18675138043aba9aa0619fb
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/24/2020
ms.locfileid: "80164801"
---
# <a name="compiler-warning-level-1-and-3-c4793"></a>Aviso do compilador (nível 1 e 3) C4793

> '*Function*': a função é compilada como código nativo: '*Reason*'

## <a name="remarks"></a>Comentários

O compilador não pode compilar a *função* em código gerenciado, embora a opção de compilador [/CLR](../../build/reference/clr-common-language-runtime-compilation.md) seja especificada. Em vez disso, o compilador emite o Aviso C4793 e uma mensagem de continuação explicativa e, em seguida, compila a *função* no código nativo. A mensagem de continuação contém o texto do *motivo* que explica por que a *função* não pode ser compilada para `MSIL`.

Esse é um aviso de nível 1 quando você especifica a opção de compilador **/CLR: Pure** .  A opção de compilador **/CLR: Pure** foi preterida no visual Studio 2015 e não tem suporte no visual Studio 2017.

A tabela a seguir lista todas as mensagens de continuação possíveis.

|Mensagem de motivo|Comentários|
|--------------------|-------------|
|Não há suporte para tipos de dados alinhados em código gerenciado|O CLR deve ser capaz de alocar dados conforme necessário, o que pode não ser possível se os dados estiverem alinhados com declarações como [__m128](../../cpp/m128.md) ou [alinhar](../../cpp/align-cpp.md).|
|Funções que usam ' __ImageBase ' não são suportadas em código gerenciado|`__ImageBase` é um símbolo de vinculador especial que é normalmente usado somente por código nativo de baixo nível para carregar uma DLL.|
|Não há suporte para varargs na opção de compilador '/CLR '|As funções nativas não podem chamar funções gerenciadas que têm varargs ( [listas de argumentos variáveis](../../cpp/functions-with-variable-argument-lists-cpp.md) ) porque as funções têm requisitos de layout de pilha diferentes. No entanto, se você especificar a opção de compilador **/CLR: Pure** , as listas de argumentos variáveis serão suportadas porque o assembly pode conter apenas funções gerenciadas. Para obter mais informações, consulte [puro e verificável CodeC++(/CLI)](../../dotnet/pure-and-verifiable-code-cpp-cli.md).|
|O CLR de 64 bits não dá suporte a dados declarados com o modificador de __ptr32|Um ponteiro deve ter o mesmo tamanho de um ponteiro nativo na plataforma atual. Para obter mais informações, consulte [__ptr32, \__ptr64](../../cpp/ptr32-ptr64.md).|
|O CLR de 32 bits não dá suporte a dados declarados com o modificador de __ptr64|Um ponteiro deve ter o mesmo tamanho de um ponteiro nativo na plataforma atual. Para obter mais informações, consulte [__ptr32, \__ptr64](../../cpp/ptr32-ptr64.md).|
|Não há suporte para um ou mais intrínsecos no código gerenciado|O nome do intrínseco não está disponível no momento em que a mensagem é emitida. No entanto, um intrínseco que causa essa mensagem normalmente representa uma instrução de computador de nível baixo.|
|O assembly nativo embutido (' __asm ') não tem suporte no código gerenciado|O [código de assembly embutido](../../assembler/inline/asm.md) pode conter código nativo arbitrário, que não pode ser gerenciado.|
|Uma conversão de função virtual não __clrcall deve ser compilada como nativa|Uma conversão de função virtual não[__clrcall](../../cpp/clrcall.md) deve usar um endereço não gerenciado.|
|Uma função que usa ' _setjmp ' deve ser compilada como nativa|O CLR deve ser capaz de controlar a execução do programa. No entanto, a função [setjmp](../../cpp/using-setjmp-longjmp.md) ignora a execução regular do programa salvando e restaurando informações de baixo nível, como registros e estado de execução.|

## <a name="example"></a>Exemplo

O exemplo a seguir gera C4793.

```cpp
// C4793.cpp
// compile with: /c /clr /W3
// processor: x86
int asmfunc(void) {   // C4793, compiled as unmanaged, native code
   __asm {
      mov eax, 0
   }
}
```

```Output
warning C4793: 'asmfunc' : function is compiled as native code:
        Inline native assembly ('__asm') is not supported in managed code
```

O exemplo a seguir gera C4793.

```cpp
// C4793_b.cpp
// compile with: /c /clr /W3
#include <setjmp.h>
jmp_buf test_buf;

void f() {
   setjmp(test_buf);   // C4793 warning
}
```

```Output
warning C4793: 'f' : function is compiled as native code:
        A function using '_setjmp' must be compiled as native
```
