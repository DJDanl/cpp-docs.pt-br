---
title: Classe context_unblock_unbalanced | Documentos do Microsoft
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords:
- concrt/concurrency::context_unblock_unbalanced
dev_langs:
- C++
helpviewer_keywords:
- context_unblock_unbalanced class
ms.assetid: a76066c8-19dd-44fa-959a-6941ec1b0d2d
caps.latest.revision: 20
author: mikeblome
ms.author: mblome
manager: ghogen
translation.priority.ht:
- cs-cz
- de-de
- es-es
- fr-fr
- it-it
- ja-jp
- ko-kr
- pl-pl
- pt-br
- ru-ru
- tr-tr
- zh-cn
- zh-tw
translationtype: Machine Translation
ms.sourcegitcommit: fc190feb08d9b221cd1cc21a9c91ad567c86c848
ms.openlocfilehash: 7341ff5d10b7f7752c49f18ea9b810824e347b1c
ms.lasthandoff: 02/25/2017

---
# <a name="contextunblockunbalanced-class"></a>Classe context_unblock_unbalanced
Esta classe descreve uma exceção lançada quando chama o `Block` e `Unblock` métodos de um `Context` objeto não estão emparelhados corretamente.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
class context_unblock_unbalanced : public std::exception;  
```  
  
## <a name="members"></a>Membros  
  
### <a name="public-constructors"></a>Construtores públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[Construtor context_unblock_unbalanced](#ctor)|Sobrecarregado. Constrói um objeto `context_unblock_unbalanced`.|  
  
## <a name="remarks"></a>Comentários  
 Chamadas para o `Block` e `Unblock` métodos de um `Context` objeto sempre deve ser combinado corretamente. O tempo de execução de simultaneidade permite que as operações de acontecer em qualquer ordem. Por exemplo, uma chamada para `Block` pode ser seguido por uma chamada para `Unblock`, ou vice-versa. Esta exceção seria lançada se, por exemplo, duas chamadas para o `Unblock` método foram feitas em uma linha em uma `Context` objeto que não foi bloqueado.  
  
## <a name="inheritance-hierarchy"></a>Hierarquia de herança  
 `exception`  
  
 `context_unblock_unbalanced`  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** concrt.h  
  
 **Namespace:** simultaneidade  
  
##  <a name="a-namectora-contextunblockunbalanced"></a><a name="ctor"></a>context_unblock_unbalanced 

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

