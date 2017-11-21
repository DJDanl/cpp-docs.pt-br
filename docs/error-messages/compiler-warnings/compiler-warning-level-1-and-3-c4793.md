---
title: "Compilador aviso (nível 1 e 3) C4793 | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-tools
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords: C4793
dev_langs: C++
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
caps.latest.revision: "28"
author: corob-msft
ms.author: corob
manager: ghogen
ms.openlocfilehash: f2c133848adf634935287589c09b94ed871c93f5
ms.sourcegitcommit: ebec1d449f2bd98aa851667c2bfeb7e27ce657b2
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/24/2017
---
# <a name="compiler-warning-level-1-and-3-c4793"></a>Aviso do compilador (nível 1 e 3) C4793
'function': função é compilada como código nativo: 'motivo'  
  
 O compilador não pode compilar *função* em código gerenciado, mesmo que o [/clr](../../build/reference/clr-common-language-runtime-compilation.md) opção de compilador é especificada. Em vez disso, o compilador emite o aviso C4793 e uma mensagem explicativa continuação e, em seguida, compila *função* em código nativo. Contém a mensagem de continuação a *motivo* texto que explica por que *função* não pode ser compilado para `MSIL`.  
  
 Este é um aviso de nível 1 quando você especificar o `/clr:pure` opção de compilador.  O **/clr: pure** opção de compilador foi preterida no Visual Studio 2015.  
  
 A tabela a seguir lista todas as mensagens de continuação possíveis.  
  
|Mensagem de motivo|Comentários|  
|--------------------|-------------|  
|Tipos de dados alinhados não são suportados em código gerenciado|O CLR deve ser capaz de alocar dados conforme necessário, que talvez não seja possível se a dados são alinhados com declarações como [m128](../../cpp/m128.md) ou [alinhar](../../cpp/align-cpp.md).|  
|Funções que usam ImageBase' não são suportadas em código gerenciado|`__ImageBase`é um símbolo de vinculador especial que normalmente é usado somente pelo código nativo de baixo nível para carregar uma DLL.|  
|varargs não oferece suporte a ' / clr' opção de compilador|Funções nativas não é possível chamar funções gerenciadas que têm [listas de argumentos variáveis](../../cpp/functions-with-variable-argument-lists-cpp.md) (varargs) porque as funções têm requisitos de layout de pilha diferente. No entanto, se você especificar o `/clr:pure` opção de compilador, argumento variável listas têm suporte porque o assembly pode conter apenas funções gerenciadas. Para obter mais informações, consulte [puro e código verificável (C + + CLI)](../../dotnet/pure-and-verifiable-code-cpp-cli.md).|  
|O CLR de 64 bits não dá suporte a dados declarados com o modificador ptr32|Um ponteiro deve ser do mesmo tamanho de um ponteiro nativo na plataforma atual. Para obter mais informações, consulte [ptr32, \_ptr64](../../cpp/ptr32-ptr64.md).|  
|O CLR de 32 bits não dá suporte a dados declarados com o modificador ptr64|Um ponteiro deve ser do mesmo tamanho de um ponteiro nativo na plataforma atual. Para obter mais informações, consulte [ptr32, \_ptr64](../../cpp/ptr32-ptr64.md).|  
|Não há suporte para um ou mais intrínsecos em código gerenciado|O nome do intrínseca não está disponível no momento em que a mensagem é emitida. No entanto, um intrínseco que causa essa mensagem geralmente representa uma instrução de nível baixo de máquina.|  
|Assembly nativo embutido ( ASM') não é suportado em código gerenciado|[Código de assembly embutido](../../assembler/inline/asm.md) pode conter código arbitrário de nativo, que não pode ser gerenciado.|  
|Uma conversão de função virtual não clrcall deve ser compilada como nativo|Não[clrcall](../../cpp/clrcall.md) conversão de função virtual deve usar um endereço de não gerenciado.|  
|Uma função usando setjmp' deve ser compilada como nativo|O CLR deve ser capaz de controlar a execução do programa. No entanto, o [setjmp](../../cpp/using-setjmp-longjmp.md) função ignora a execução do programa regular, salvando e restaurando informações de baixo nível, como registros e estado de execução.|  
  
## <a name="example"></a>Exemplo  
 O exemplo a seguir gera C4793.  
  
```  
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
  
## <a name="example"></a>Exemplo  
 O exemplo a seguir gera C4793.  
  
```  
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