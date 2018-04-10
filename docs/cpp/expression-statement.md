---
title: Instrução de expressão | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.reviewer: ''
ms.suite: ''
ms.technology:
- cpp-language
ms.tgt_pltfrm: ''
ms.topic: language-reference
dev_langs:
- C++
helpviewer_keywords:
- statements [C++], expression
- expression statements
ms.assetid: 547d7f7a-58be-4ffc-a4b3-d64c7ae7538c
caps.latest.revision: 6
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: e627e107df850f31a9cf04981795edd1185c0ce5
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="expression-statement"></a>Instrução de expressão
Instruções de expressão fazem com as expressões sejam avaliadas. Nenhuma transferência de controle ou iteração ocorre como resultado de uma instrução de expressão.  
  
 A sintaxe da instrução de expressão é simplesmente  
  
## <a name="syntax"></a>Sintaxe  
  
```  
[expression ] ;  
```  
  
## <a name="remarks"></a>Comentários  
 Todas as expressões em uma instrução de expressão são avaliadas e todos os efeitos colaterais são concluídos antes que a próxima instrução seja executada. As instruções de expressão mais comuns são atribuições e chamadas de função.  Como a expressão é opcional, um ponto e vírgula sozinho é considerado uma instrução de expressão vazia, conhecida como o [nulo](../cpp/null-statement.md) instrução.  
  
## <a name="see-also"></a>Consulte também  
 [Visão geral das instruções C++](../cpp/overview-of-cpp-statements.md)