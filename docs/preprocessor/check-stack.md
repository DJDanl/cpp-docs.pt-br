---
title: check_stack | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-tools
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords:
- vc-pragma.check_stack
- check_stack_CPP
dev_langs: C++
helpviewer_keywords:
- check_stack pragma
- pragmas, check_stack
- pragmas, check_stack usage table
ms.assetid: f18e20cc-9abb-48b7-ad62-8d384875b996
caps.latest.revision: "7"
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload: cplusplus
ms.openlocfilehash: e48952788e7bbef86ade1177ce243da503ec8b9b
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="checkstack"></a>check_stack
Instrui o compilador desativar sondas de pilha se **off** (ou  **-** ) for especificado, ou para ativar sondas de pilha se **na** (ou  **+** ) for especificado.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
  
      #pragma check_stack([ {on | off}] )  
#pragma check_stack{+ | -}  
```  
  
## <a name="remarks"></a>Comentários  
 Se nenhum argumento for fornecido, as investigações da pilha serão tratadas de acordo com o padrão. Esse pragma entra em vigor na primeira função definida, após a consideração do pragma. As investigações da pilha não são parte de macros ou funções que forem geradas embutidas.  
  
 Se você não fornecer um argumento para o **check_stack** pragma, verificação de pilha é revertida para o comportamento especificado na linha de comando. Para obter mais informações, consulte [compilador](../build/reference/compiler-options.md). A interação entre o **#pragma check_stack** e [/Gs](../build/reference/gs-control-stack-checking-calls.md) opção é resumida na tabela a seguir.  
  
### <a name="using-the-checkstack-pragma"></a>Usando o pragma check_stack  
  
|Sintaxe|Compilado com<br /><br /> Opção /Gs?|Ação|  
|------------|------------------------------------|------------|  
|**() de check_stack #pragma** ou<br /><br /> **check_stack #pragma**|Sim|Desativa a verificação da pilha quanto às funções seguintes|  
|**() de check_stack #pragma** ou<br /><br /> **check_stack #pragma**|Não|Ativa a verificação da pilha quanto às funções seguintes|  
|**#pragma check_stack(on)**<br /><br /> ou **#pragma check_stack +**|Sim ou não|Ativa a verificação da pilha quanto às funções seguintes|  
|**#pragma check_stack(off)**<br /><br /> ou **#pragma check_stack -**|Sim ou não|Desativa a verificação da pilha quanto às funções seguintes|  
  
## <a name="see-also"></a>Consulte também  
 [Diretivas Pragma e a palavra-chave __Pragma](../preprocessor/pragma-directives-and-the-pragma-keyword.md)