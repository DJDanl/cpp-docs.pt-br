---
title: "Classe context_unblock_unbalanced | Microsoft Docs"
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
  - "concrt/concurrency::context_unblock_unbalanced"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Classe context_unblock_unbalanced"
ms.assetid: a76066c8-19dd-44fa-959a-6941ec1b0d2d
caps.latest.revision: 20
caps.handback.revision: 20
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Classe context_unblock_unbalanced
[!INCLUDE[vs2017banner](../../../assembler/inline/includes/vs2017banner.md)]

Esta classe descreve uma exceção lançada quando chama o `Block` e `Unblock` métodos de um `Context` objeto não estão emparelhados corretamente.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
class context_unblock_unbalanced : public std::exception;  
```  
  
## <a name="members"></a>Membros  
  
### <a name="public-constructors"></a>Construtores públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[context_unblock_unbalanced:: context_unblock_unbalanced construtor](#context_unblock_unbalanced__context_unblock_unbalanced_constructor)|Sobrecarregado. Constrói um objeto `context_unblock_unbalanced`.|  
  
## <a name="remarks"></a>Comentários  
 Chamadas para o `Block` e `Unblock` métodos de um `Context` objeto sempre deve ser combinado corretamente. O tempo de execução de simultaneidade permite que as operações de acontecer em qualquer ordem. Por exemplo, uma chamada para `Block` pode ser seguido por uma chamada para `Unblock`, ou vice-versa. Esta exceção seria lançada se, por exemplo, duas chamadas para o `Unblock` método foram feitas em uma linha em uma `Context` objeto que não foi bloqueado.  
  
## <a name="inheritance-hierarchy"></a>Hierarquia de herança  
 `exception`  
  
 `context_unblock_unbalanced`  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** concrt.h  
  
 **Namespace:** simultaneidade  
  
##  <a name="a-namecontextunblockunbalancedcontextunblockunbalancedconstructora-contextunblockunbalancedcontextunblockunbalanced-constructor"></a><a name="context_unblock_unbalanced__context_unblock_unbalanced_constructor"></a>  context_unblock_unbalanced:: context_unblock_unbalanced construtor  
 Constrói um objeto `context_unblock_unbalanced`.  
  
```  
explicit _CRTIMP context_unblock_unbalanced(_In_z_ const char* _Message) throw();

 
context_unblock_unbalanced() throw();
```  
  
### <a name="parameters"></a>Parâmetros  
 `_Message`  
 Uma mensagem descritiva do erro.  
  
## <a name="see-also"></a>Consulte também  
 [Namespace Concurrency](../../../parallel/concrt/reference/concurrency-namespace.md)
