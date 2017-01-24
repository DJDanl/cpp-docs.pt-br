---
title: "check_stack | Microsoft Docs"
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
  - "vc-pragma.check_stack"
  - "check_stack_CPP"
dev_langs: 
  - "C++"
  - "C"
helpviewer_keywords: 
  - "check_stack (pragma)"
  - "pragmas, check_stack"
  - "pragmas, tabela de uso check_stack"
ms.assetid: f18e20cc-9abb-48b7-ad62-8d384875b996
caps.latest.revision: 7
caps.handback.revision: 7
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# check_stack
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Instrui o compilador para desativar investigações da pilha se **off** \(ou **–**\) forem especificados ou para ativar investigações da pilha se **on** \(ou **\+**\) forem especificados.  
  
## Sintaxe  
  
```  
  
      #pragma check_stack([ {on | off}] )  
#pragma check_stack{+ | –}  
```  
  
## Comentários  
 Se nenhum argumento for fornecido, as investigações da pilha serão tratadas de acordo com o padrão.  Esse pragma entra em vigor na primeira função definida, após a consideração do pragma.  As investigações da pilha não são parte de macros ou funções que forem geradas embutidas.  
  
 Se você não fornecer um argumento para o pragma **check\_stack**, a verificação da pilha volta para o comportamento especificado na linha de comando.  Para obter mais informações, consulte [Referência do compilador](../build/reference/compiler-options.md).  A interação de **\#pragma check\_stack** e a opção [\/Gs](../build/reference/gs-control-stack-checking-calls.md) são resumidas na tabela a seguir.  
  
### Usando o pragma check\_stack  
  
|Sintaxe|Compilado com<br /><br /> Opção \/Gs?|Ação|  
|-------------|-----------------------------------|----------|  
|**\#pragma check\_stack\( \)** ou<br /><br /> **\#pragma check\_stack**|Sim|Desativa a verificação da pilha quanto às funções seguintes|  
|**\#pragma check\_stack\( \)** ou<br /><br /> **\#pragma check\_stack**|Não|Ativa a verificação da pilha quanto às funções seguintes|  
|**\#pragma check\_stack\(on\)**<br /><br /> ou **\#pragma check\_stack \+**|Sim ou não|Ativa a verificação da pilha quanto às funções seguintes|  
|**\#pragma check\_stack\(off\)**<br /><br /> ou **\#pragma check\_stack –**|Sim ou não|Desativa a verificação da pilha quanto às funções seguintes|  
  
## Consulte também  
 [Diretivas Pragma e a palavra\-chave \_\_Pragma](../preprocessor/pragma-directives-and-the-pragma-keyword.md)