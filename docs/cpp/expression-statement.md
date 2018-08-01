---
title: Instrução de expressão | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-language
ms.topic: language-reference
dev_langs:
- C++
helpviewer_keywords:
- statements [C++], expression
- expression statements
ms.assetid: 547d7f7a-58be-4ffc-a4b3-d64c7ae7538c
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: d94acdfff2fdea2cc35d0856940270ba82e131af
ms.sourcegitcommit: 2b9e8af9b7138f502ffcba64e2721f7ef52af23b
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/01/2018
ms.locfileid: "39405250"
---
# <a name="expression-statement"></a>Instrução de expressão
Instruções de expressão fazem com as expressões sejam avaliadas. Nenhuma transferência de controle ou iteração ocorre como resultado de uma instrução de expressão.  
  
 A sintaxe da instrução de expressão é simplesmente  
  
## <a name="syntax"></a>Sintaxe  
  
```  
[expression ] ;  
```  
  
## <a name="remarks"></a>Comentários  
 Todas as expressões em uma instrução de expressão são avaliadas e todos os efeitos colaterais são concluídos antes que a próxima instrução seja executada. As instruções de expressão mais comuns são atribuições e chamadas de função.  Uma vez que a expressão é opcional, um ponto e vírgula sozinho é considerado uma instrução expression vazia, conhecida como o [nulo](../cpp/null-statement.md) instrução.  
  
## <a name="see-also"></a>Consulte também  
 [Visão geral das instruções C++](../cpp/overview-of-cpp-statements.md)