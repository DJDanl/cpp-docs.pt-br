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
ms.openlocfilehash: e7ca3b10e09b0d6818fbc7f5607ebc9c95c7f15c
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50623243"
---
# <a name="compiler-warning-level-1-and-3-c4793"></a>Aviso do compilador (nível 1 e 3) C4793

> '*função*': função é compilada como código nativo: '*motivo*'

## <a name="remarks"></a>Comentários

O compilador não pode ser compilado *função* em código gerenciado, mesmo que o [/clr](../../build/reference/clr-common-language-runtime-compilation.md) for especificada a opção de compilador. Em vez disso, o compilador emite aviso C4793 e uma mensagem explicativa continuação e, em seguida, compila *função* em código nativo. A mensagem de continuação contém o *motivo* texto que explica o motivo *função* não pode ser compilada para `MSIL`.

Esse é um aviso de nível 1 quando você especificar o **/clr: pure** opção de compilador.  O **/clr: pure** opção do compilador é preterida no Visual Studio 2015 e sem suporte no Visual Studio 2017.

A tabela a seguir lista todas as mensagens de continuação possíveis.

|Mensagem de motivo|Comentários|
|--------------------|-------------|
|Não há suporte para tipos de dados alinhados no código gerenciado|O CLR deve ser capaz de alocar dados conforme necessário, que talvez não seja possível se os dados alinhados com declarações, como [__m128](../../cpp/m128.md) ou [alinhar](../../cpp/align-cpp.md).|
|Funções que usam ImageBase' não são suportadas em código gerenciado|`__ImageBase` é um símbolo de vinculador especial que normalmente é usado somente pelo código nativo de baixo nível para carregar uma DLL.|
|varargs não são compatíveis com o ' / clr' opção de compilador|Funções nativas não é possível chamar funções gerenciadas que tenham [listas de argumentos variáveis](../../cpp/functions-with-variable-argument-lists-cpp.md) (varargs) porque as funções têm requisitos de layout de pilha diferente. No entanto, se você especificar o **/clr: pure** opção de compilador, o argumento variável listas têm suporte porque o assembly pode conter apenas funções gerenciadas. Para obter mais informações, consulte [código puro e verificável (C + + / CLI)](../../dotnet/pure-and-verifiable-code-cpp-cli.md).|
|O CLR de 64 bits não dá suporte a dados declarados com o modificador __ptr32|Um ponteiro deve ser do mesmo tamanho que um ponteiro nativo na plataforma atual. Para obter mais informações, consulte [__ptr32, \__ptr64](../../cpp/ptr32-ptr64.md).|
|O CLR de 32 bits não dá suporte a dados declarados com o modificador __ptr64|Um ponteiro deve ser do mesmo tamanho que um ponteiro nativo na plataforma atual. Para obter mais informações, consulte [__ptr32, \__ptr64](../../cpp/ptr32-ptr64.md).|
|Não há suporte para um ou mais intrínsecos em código gerenciado|O nome do intrínseco não está disponível no momento em que a mensagem é emitida. No entanto, um intrínseco que faz com que essa mensagem geralmente representa uma instrução de baixo nível de máquina.|
|Não há suporte para o assembly nativo do embutido ( ASM') no código gerenciado|[Código de assembly embutido](../../assembler/inline/asm.md) pode conter código nativo arbitrário, que não pode ser gerenciado.|
|Uma conversão de função virtual não clrcall deve ser compilada como nativas|Um não -[clrcall](../../cpp/clrcall.md) conversão de função virtual deve usar um endereço não gerenciado.|
|Uma função usando 'setjmp' deve ser compilada como nativo|O CLR deve ser capaz de controlar a execução do programa. No entanto, o [setjmp](../../cpp/using-setjmp-longjmp.md) função ignora a execução do programa regular, salvando e restaurando informações de baixo nível, como registros e o estado de execução.|

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