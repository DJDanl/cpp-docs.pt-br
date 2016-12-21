---
title: "Aviso do compilador (n&#237;vel 1 e 3) C4793 | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "error-reference"
f1_keywords: 
  - "C4793"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "C4793"
  - "C6630"
  - "C6631"
  - "C6634"
  - "C6635"
  - "C6636"
  - "C6637"
  - "C6638"
  - "C6639"
  - "C6640"
ms.assetid: 819ada53-1d9c-49b8-a629-baf8c12314e6
caps.latest.revision: 28
caps.handback.revision: 26
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Aviso do compilador (n&#237;vel 1 e 3) C4793
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

função “”: a função é criada como o código nativo: “motivo”  
  
 O compilador não pode criar *function* em código gerenciado, mesmo que a opção do compilador de [\/clr](../../build/reference/clr-common-language-runtime-compilation.md) é especificada.  Em vez disso, o compilador emite C4793 de aviso e uma mensagem explicativa de acompanhamento, e compila\-se em *function* em código nativo.  A mensagem de acompanhamento contém o texto de *reason* que explica por *function* não pode ser compilado a `MSIL`.  
  
 Este é um aviso de nível 1 quando você especifica a opção do compilador de `/clr:pure` .  
  
 A tabela a seguir lista todas as mensagens possíveis de continuação.  
  
|Mensagem do motivo|Comentários|  
|------------------------|-----------------|  
|Os tipos de dados alinhados não têm suporte em código gerenciado|CLR deve poder atribuir quando necessário, os dados que não podem ser possíveis se os dados forem alinhados com as declarações como [\_\_m128](../Topic/__m128.md) ou [alinhar](../../cpp/align-cpp.md).|  
|As funções que usam o “\_\_ImageBase” não têm suporte em código gerenciado|`__ImageBase` é um símbolo especial do vinculador que é normalmente usado apenas pelo código nativo de baixo nível para carregar um DLL.|  
|os varargs não têm suporte pela opção do compilador de “\/clr”|As funções nativos não podem chamar funções gerenciadas que têm [listas de argumento variáveis](../Topic/Variable%20Argument%20Lists.md) varargs \(\) porque as funções têm requisitos diferentes de layout da pilha.  No entanto, se você especificar a opção de compilador de `/clr:pure` , as listas de argumento variáveis têm suporte porque o assembly pode conter somente funções gerenciadas.  Para obter mais informações, consulte [Código puro e verificável](../../dotnet/pure-and-verifiable-code-cpp-cli.md).|  
|CLR de 64 bits não oferece suporte a dados declarados com o modificador \_\_ptr32|Um ponteiro deve ser o mesmo tamanho como um ponteiro nativo na plataforma atual.  Para obter mais informações, consulte [\_\_ptr32, \_\_ptr64](../../cpp/ptr32-ptr64.md).|  
|CLR de 32 bits não oferece suporte a dados declarados com o modificador \_\_ptr64|Um ponteiro deve ser o mesmo tamanho como um ponteiro nativo na plataforma atual.  Para obter mais informações, consulte [\_\_ptr32, \_\_ptr64](../../cpp/ptr32-ptr64.md).|  
|Um ou mais intrinsics não têm suporte em código gerenciado|O nome intrínsecos não está disponível na mensagem é emitida.  No entanto, um intrínseco que provocou essa mensagem normalmente representa uma instrução de computador de baixo nível.|  
|O assembly nativo \_\_asm embutida \(“"\) não têm suporte em código gerenciado|[Código do assembly embutido](../../assembler/inline/asm.md) pode conter código nativo, arbitrário que não pode ser gerenciado.|  
|Um thunk virtual da função de non\-\_\_clrcall deve ser compilado como o modo nativo|Um thunk virtual não da função de[\_\_clrcall](../../cpp/clrcall.md) deve usar um endereço não gerenciado.|  
|Uma função que usa o “\_setjmp” deve ser criada como o modo nativo|CLR deve ser capaz da execução de programa do controle.  No entanto, a execução do programa normal de desvios da função de [setjmp](../../cpp/using-setjmp-longjmp.md) salvando e restaurando informações de baixo nível como registros e estado da execução.|  
  
## Exemplo  
 O exemplo a seguir produz C4793.  
  
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
  
  **C4793 de aviso: “asmfunc”: a função é criada como o código nativo:**  
 **O assembly nativo \_\_asm embutida \(“"\) não têm suporte em código gerenciado**   
## Exemplo  
 O exemplo a seguir produz C4793.  
  
```  
// C4793_b.cpp  
// compile with: /c /clr /W3  
#include <setjmp.h>  
jmp_buf test_buf;  
  
void f() {  
   setjmp(test_buf);   // C4793 warning  
}  
```  
  
  **C4793 de aviso: “f”: a função é criada como o código nativo:**  
 **Uma função que usa o “\_setjmp” deve ser criada como o modo nativo**