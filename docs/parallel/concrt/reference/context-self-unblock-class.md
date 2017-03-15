---
title: Classe context_self_unblock | Documentos do Microsoft
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords:
- concrt/concurrency::context_self_unblock
dev_langs:
- C++
helpviewer_keywords:
- context_self_unblock class
ms.assetid: 9601cd28-4f40-4c2e-89ab-747068956331
caps.latest.revision: 21
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
ms.openlocfilehash: 4976bcf083d94da672ceacb1b9232252728ed5ec
ms.lasthandoff: 02/25/2017

---
# <a name="contextselfunblock-class"></a>Classe context_self_unblock
Esta classe descreve uma exceção gerada quando o `Unblock` método de um `Context` objeto é chamado no mesmo contexto. Isso indica uma tentativa por um determinado contexto para desbloquear a mesmo.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
class context_self_unblock : public std::exception;  
```  
  
## <a name="members"></a>Membros  
  
### <a name="public-constructors"></a>Construtores públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[Construtor context_self_unblock](#ctor)|Sobrecarregado. Constrói um objeto `context_self_unblock`.|  
  
## <a name="inheritance-hierarchy"></a>Hierarquia de herança  
 `exception`  
  
 `context_self_unblock`  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** concrt.h  
  
 **Namespace:** simultaneidade  
  
##  <a name="a-namectora-contextselfunblock"></a><a name="ctor"></a>context_self_unblock 

 Constrói um objeto `context_self_unblock`.  
  
```  
explicit _CRTIMP context_self_unblock(_In_z_ const char* _Message) throw();

 
context_self_unblock() throw();
```  
  
### <a name="parameters"></a>Parâmetros  
 `_Message`  
 Uma mensagem descritiva do erro.  
  
## <a name="see-also"></a>Consulte também  
 [Namespace de simultaneidade](concurrency-namespace.md)

