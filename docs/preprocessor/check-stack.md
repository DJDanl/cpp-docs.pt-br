---
title: check_stack | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-tools
ms.tgt_pltfrm: 
ms.topic: reference
f1_keywords:
- vc-pragma.check_stack
- check_stack_CPP
dev_langs:
- C++
helpviewer_keywords:
- check_stack pragma
- pragmas, check_stack
- pragmas, check_stack usage table
ms.assetid: f18e20cc-9abb-48b7-ad62-8d384875b996
caps.latest.revision: 
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: 70f88d1eabb58f384d754803674b35f0bd9dbeda
ms.sourcegitcommit: d51ed21ab2b434535f5c1d553b22e432073e1478
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 02/23/2018
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
|**#pragma check_stack( )** or<br /><br /> **#pragma check_stack**|Sim|Desativa a verificação da pilha quanto às funções seguintes|  
|**#pragma check_stack( )** or<br /><br /> **#pragma check_stack**|Não|Ativa a verificação da pilha quanto às funções seguintes|  
|**#pragma check_stack(on)**<br /><br /> ou **#pragma check_stack +**|Sim ou não|Ativa a verificação da pilha quanto às funções seguintes|  
|**#pragma check_stack(off)**<br /><br /> ou **#pragma check_stack -**|Sim ou não|Desativa a verificação da pilha quanto às funções seguintes|  
  
## <a name="see-also"></a>Consulte também  
 [Diretivas Pragma e a palavra-chave __Pragma](../preprocessor/pragma-directives-and-the-pragma-keyword.md)