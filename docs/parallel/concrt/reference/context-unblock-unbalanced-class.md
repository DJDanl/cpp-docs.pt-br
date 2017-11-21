---
title: Classe context_unblock_unbalanced | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-windows
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords:
- context_unblock_unbalanced
- CONCRT/concurrency::context_unblock_unbalanced
- CONCRT/concurrency::context_unblock_unbalanced::context_unblock_unbalanced
dev_langs: C++
helpviewer_keywords: context_unblock_unbalanced class
ms.assetid: a76066c8-19dd-44fa-959a-6941ec1b0d2d
caps.latest.revision: "20"
author: mikeblome
ms.author: mblome
manager: ghogen
ms.openlocfilehash: 45121b3dba14e5672333debf364f5aea2e3e3cd5
ms.sourcegitcommit: ebec1d449f2bd98aa851667c2bfeb7e27ce657b2
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/24/2017
---
# <a name="contextunblockunbalanced-class"></a>Classe context_unblock_unbalanced
Esta classe descreve uma exceção lançada quando chamadas para o `Block` e `Unblock` métodos de um `Context` objeto não estão emparelhados corretamente.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
class context_unblock_unbalanced : public std::exception;  
```  
  
## <a name="members"></a>Membros  
  
### <a name="public-constructors"></a>Construtores públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[context_unblock_unbalanced](#ctor)|Sobrecarregado. Constrói um objeto `context_unblock_unbalanced`.|  
  
## <a name="remarks"></a>Comentários  
 Chamadas para o `Block` e `Unblock` métodos de um `Context` objeto sempre deve ser combinado corretamente. O tempo de execução de simultaneidade permite que as operações de acontecer em qualquer ordem. Por exemplo, uma chamada para `Block` pode ser seguido por uma chamada para `Unblock`, ou vice-versa. Essa exceção será lançada se, por exemplo, duas chamadas para o `Unblock` método foram feitas em uma linha em uma `Context` objeto que não foi bloqueado.  
  
## <a name="inheritance-hierarchy"></a>Hierarquia de herança  
 `exception`  
  
 `context_unblock_unbalanced`  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** concrt.h  
  
 **Namespace:** simultaneidade  
  
##  <a name="ctor"></a>context_unblock_unbalanced 

 Constrói um objeto `context_unblock_unbalanced`.  
  
```  
explicit _CRTIMP context_unblock_unbalanced(_In_z_ const char* _Message) throw();

 
context_unblock_unbalanced() throw();
```  
  
### <a name="parameters"></a>Parâmetros  
 `_Message`  
 Uma mensagem descritiva do erro.  
  
## <a name="see-also"></a>Consulte também  
 [Namespace de simultaneidade](concurrency-namespace.md)
