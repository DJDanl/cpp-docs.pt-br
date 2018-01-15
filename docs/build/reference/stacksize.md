---
title: STACKSIZE | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-tools
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords: STACKSIZE
dev_langs: C++
helpviewer_keywords: STACKSIZE .def file statement
ms.assetid: 4d8c79bd-1cb4-4e4d-90f2-b5a7a4d20e7a
caps.latest.revision: "7"
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload: cplusplus
ms.openlocfilehash: a9c09bea88c4f9452d0fab9371c8b9af8011fd32
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="stacksize"></a>STACKSIZE
Define o tamanho da pilha, em bytes.  
  
```  
STACKSIZE reserve[,commit]  
```  
  
## <a name="remarks"></a>Comentários  
 É uma maneira equivalente para definir a pilha com o [alocações da pilha](../../build/reference/stack-stack-allocations.md) (/ pilha) opção. Consulte a documentação sobre essa opção para obter detalhes o *reservar* e `commit` argumentos.  
  
 Essa opção não tem nenhum efeito em DLLs.  
  
## <a name="see-also"></a>Consulte também  
 [Regras para instruções de definição do módulo](../../build/reference/rules-for-module-definition-statements.md)