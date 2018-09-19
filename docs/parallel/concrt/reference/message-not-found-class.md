---
title: Classe message_not_found | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-concrt
ms.topic: reference
f1_keywords:
- message_not_found
- CONCRT/concurrency::message_not_found
- CONCRT/concurrency::message_not_found::message_not_found
dev_langs:
- C++
helpviewer_keywords:
- message_not_found class
ms.assetid: a96b9995-5ad7-4600-83c8-c15e329ff10e
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: f28096fccae4f24b236631b3c27178bda7e22771
ms.sourcegitcommit: 913c3bf23937b64b90ac05181fdff3df947d9f1c
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/18/2018
ms.locfileid: "46103978"
---
# <a name="messagenotfound-class"></a>Classe message_not_found
Esta classe descreve uma exceção gerada quando um bloco de mensagens não conseguir encontrar uma mensagem solicitada.  
  
## <a name="syntax"></a>Sintaxe  
  
```
class message_not_found : public std::exception;
```  
  
## <a name="members"></a>Membros  
  
### <a name="public-constructors"></a>Construtores Públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[message_not_found](#ctor)|Sobrecarregado. Constrói um objeto `message_not_found`.|  
  
## <a name="inheritance-hierarchy"></a>Hierarquia de herança  
 `exception`  
  
 `message_not_found`  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** concrt. h  
  
 **Namespace:** simultaneidade  
  
##  <a name="ctor"></a> message_not_found 

 Constrói um objeto `message_not_found`.  
  
```
explicit _CRTIMP message_not_found(_In_z_ const char* _Message) throw();

message_not_found() throw();
```  
  
### <a name="parameters"></a>Parâmetros  
*Mensagem*<br/>
Uma mensagem descritiva do erro.  
  
## <a name="see-also"></a>Consulte também  
 [Namespace de simultaneidade](concurrency-namespace.md)   
 [Blocos de mensagens assíncronos](../../../parallel/concrt/asynchronous-message-blocks.md)



