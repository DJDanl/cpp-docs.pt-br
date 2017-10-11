---
title: "Instrução de expressão | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-language
ms.tgt_pltfrm: 
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
ms.translationtype: HT
ms.sourcegitcommit: 6ffef5f51e57cf36d5984bfc43d023abc8bc5c62
ms.openlocfilehash: b48bf6d0dfd1c1ce29d1d116a77d3445bd5e1e30
ms.contentlocale: pt-br
ms.lasthandoff: 09/25/2017

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
