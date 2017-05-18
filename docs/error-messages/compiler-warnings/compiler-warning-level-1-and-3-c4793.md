---
title: "Compilador aviso (nível 1 e 3) C4793 | Documentos do Microsoft"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-tools
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords:
- C4793
dev_langs:
- C++
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
caps.latest.revision: 28
author: corob-msft
ms.author: corob
manager: ghogen
translation.priority.ht:
- cs-cz
- de-de
- es-es
- fr-fr
- it-it
- ja-jp
- ko-kr
- pl-pl
- pt-br
- ru-ru
- tr-tr
- zh-cn
- zh-tw
ms.translationtype: Machine Translation
ms.sourcegitcommit: cc82b83860786ffc3f0aee73ede18ecadef16a7a
ms.openlocfilehash: a217d2074affa1598aef93882fb299c6fcdef5a6
ms.contentlocale: pt-br
ms.lasthandoff: 02/25/2017

---
# <a name="compiler-warning-level-1-and-3-c4793"></a>Aviso do compilador (nível 1 e 3) C4793
'function': função é compilada como código nativo: 'razão'  
  
 O compilador não pode compilar *função* em código gerenciado, mesmo que o [/clr](../../build/reference/clr-common-language-runtime-compilation.md) opção de compilador é especificada. Em vez disso, o compilador emite uma mensagem explicativa continuação e aviso C4793 e compila *função* em código nativo. Contém a mensagem de continuação a *motivo* texto que explica por que *função* não pode ser compilada para `MSIL`.  
  
 Esse é um aviso de nível 1 quando você especificar o `/clr:pure` opção de compilador.  O **/clr: puro** opção de compilador foi preterida no Visual Studio 2015.  
  
 A tabela a seguir lista todas as mensagens de continuação possíveis.  
  
|Mensagem de motivo|Comentários|  
|--------------------|-------------|  
|Não há suporte para tipos de dados alinhados no código gerenciado|O CLR deve ser capaz de alocar dados conforme necessário, que talvez não seja possível se os dados são alinhados com declarações como [m128](../../cpp/m128.md) ou [alinhar](../../cpp/align-cpp.md).|  
|Não há suporte para funções que usam ImageBase' em código gerenciado|`__ImageBase`é um símbolo de vinculador especial que normalmente é usado somente pelo código nativo de baixo nível para carregar uma DLL.|  
|varargs não oferece suporte a ' / clr' opção de compilador|Funções nativas não podem chamar funções gerenciadas que têm [listas de argumentos variáveis](../../cpp/functions-with-variable-argument-lists-cpp.md) (varargs) porque as funções têm requisitos de layout de pilha diferente. No entanto, se você especificar o `/clr:pure` opção de compilador, argumento variável listas têm suporte porque o assembly pode conter apenas funções gerenciadas. Para obter mais informações, consulte [puro e código verificável (C + + / CLI)](../../dotnet/pure-and-verifiable-code-cpp-cli.md).|  
|O CLR de 64 bits não oferece suporte a dados declarados com o modificador ptr32|Um ponteiro deve ser do mesmo tamanho que um ponteiro nativo na plataforma atual. Para obter mais informações, consulte [ptr32, \_ptr64](../../cpp/ptr32-ptr64.md).|  
|O CLR de 32 bits não oferece suporte a dados declarados com o modificador ptr64|Um ponteiro deve ser do mesmo tamanho que um ponteiro nativo na plataforma atual. Para obter mais informações, consulte [ptr32, \_ptr64](../../cpp/ptr32-ptr64.md).|  
|Não há suporte para um ou mais intrínsecos em código gerenciado|O nome do intrínseco não está disponível no momento em que a mensagem é emitida. No entanto, um intrínseco que faz com que essa mensagem geralmente representa uma instrução de baixo nível de máquina.|  
|Não há suporte para o assembly nativo embutido ( ASM') em código gerenciado|[Código de assembly embutido](../../assembler/inline/asm.md) pode conter código nativo arbitrário, que não pode ser gerenciado.|  
|Uma conversão de função virtual não clrcall deve ser compilada como nativo|Não[clrcall](../../cpp/clrcall.md) conversão de função virtual deve usar um endereço não gerenciado.|  
|Uma função usando '_setjmp' deve ser compilada como nativo|O CLR deve ser capaz de controlar a execução do programa. No entanto, o [setjmp](../../cpp/using-setjmp-longjmp.md) função ignora a execução do programa regular, salvando e restaurando informações de baixo nível, como registros e o estado de execução.|  
  
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
