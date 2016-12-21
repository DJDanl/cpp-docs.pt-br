---
title: "conform | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "article"
f1_keywords: 
  - "conform_CPP"
  - "vc-pragma.conform"
dev_langs: 
  - "C++"
  - "C"
helpviewer_keywords: 
  - "pragma de conformidade"
  - "pragma de conformidade forScope"
  - "pragmas, conform"
ms.assetid: 71b3e174-c53c-4bfc-adf3-af39b1554191
caps.latest.revision: 5
caps.handback.revision: 5
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# conform
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

**Específico do C\+\+**  
  
 Especifica o comportamento em tempo de execução da opção de compilador [\/Zc:forScope](../build/reference/zc-forscope-force-conformance-in-for-loop-scope.md).  
  
## Sintaxe  
  
```  
#pragma conform(name [, show ] [, on | off ] [ [, push | pop ] [, identifier ] ] )  
```  
  
#### Parâmetros  
 *name*  
 Especifica o nome da opção de compilador a ser modificada.  O único *name* válido é `forScope`.  
  
 **show** \(opcional\)  
 Faz com que a configuração atual de *name* \(true ou false\) seja exibida por meio de uma mensagem de aviso durante a compilação.  Por exemplo, `#pragma conform(forScope, show)`.  
  
 **on, off** \(opcional\)  
 Definir *name* como **on** habilita a opção de compilador [\/Zc:forScope](../build/reference/zc-forscope-force-conformance-in-for-loop-scope.md).  O padrão é **off**.  
  
 **push** \(opcional\)  
 Envia o valor atual de *name* por push para a pilha interna do compilador.  Se especificar *identifier*, você poderá especificar que o valor **on** ou **off** de *name* seja enviado por push para a pilha.  Por exemplo, `#pragma conform(forScope, push, myname, on)`.  
  
 **pop** \(opcional\)  
 Define o valor de *name* como o valor na parte superior da pilha interna do compilador e depois remove o item mais recente da pilha.  Se identifier for especificado com **pop**, a pilha terá novamente o item mais recente removido até que seja encontrado o registro com *identifier*, o qual também será removido; o valor atual de *name* no próximo registro na pilha se tornará o novo valor de *name*.  Se você especificar pop com um *identifier* que não esteja em um registro na pilha, o **pop** será ignorado.  
  
 *identifier*\(opcional\)  
 Pode ser incluído com um comando **push** ou **pop**.  Se *identifier* for usado, um especificador **on** ou **off** também poderá ser usado.  
  
## Exemplo  
  
```  
// pragma_directive_conform.cpp  
// compile with: /W1  
// C4811 expected  
#pragma conform(forScope, show)  
#pragma conform(forScope, push, x, on)  
#pragma conform(forScope, push, x1, off)  
#pragma conform(forScope, push, x2, off)  
#pragma conform(forScope, push, x3, off)  
#pragma conform(forScope, show)  
#pragma conform(forScope, pop, x1)  
#pragma conform(forScope, show)  
  
int main() {}  
```  
  
## Consulte também  
 [Diretivas Pragma e a palavra\-chave \_\_Pragma](../preprocessor/pragma-directives-and-the-pragma-keyword.md)