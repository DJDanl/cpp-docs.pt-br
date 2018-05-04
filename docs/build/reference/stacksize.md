---
title: STACKSIZE | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-tools
ms.topic: reference
f1_keywords:
- STACKSIZE
dev_langs:
- C++
helpviewer_keywords:
- STACKSIZE .def file statement
ms.assetid: 4d8c79bd-1cb4-4e4d-90f2-b5a7a4d20e7a
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 1b2093762b3c6f21d319c53a85da5ec5b430a1fd
ms.sourcegitcommit: be2a7679c2bd80968204dee03d13ca961eaa31ff
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/03/2018
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