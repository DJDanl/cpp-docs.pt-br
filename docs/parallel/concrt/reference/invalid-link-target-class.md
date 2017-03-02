---
title: Classe invalid_link_target | Documentos do Microsoft
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords:
- concrt/concurrency::invalid_link_target
dev_langs:
- C++
helpviewer_keywords:
- invalid_link_target class
ms.assetid: 33b64885-34d8-4d4e-a893-02e9f19c958e
caps.latest.revision: 19
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
ms.openlocfilehash: da613342099cff27b52cfbbe4de941259c6ae073
ms.lasthandoff: 02/25/2017

---
# <a name="invalidlinktarget-class"></a>Classe invalid_link_target
Esta classe descreve uma exceção gerada quando o `link_target` método de um bloco de mensagens é chamado e o bloco de mensagens não pode vincular ao destino. Isso pode ser o resultado de exceder o número de links que o bloco de mensagens é permitido ou a tentativa de vincular a um destino específico duas vezes para a mesma fonte.  
  
## <a name="syntax"></a>Sintaxe  
  
```
class invalid_link_target : public std::exception;
```  
  
## <a name="members"></a>Membros  
  
### <a name="public-constructors"></a>Construtores públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[Construtor invalid_link_target](#ctor)|Sobrecarregado. Constrói uma `invalid_link_target` objeto.|  
  
## <a name="inheritance-hierarchy"></a>Hierarquia de herança  
 `exception`  
  
 `invalid_link_target`  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** concrt.h  
  
 **Namespace:** simultaneidade  
  
##  <a name="a-namectora-invalidlinktarget"></a><a name="ctor"></a>invalid_link_target 

 Constrói uma `invalid_link_target` objeto.  
  
```
explicit _CRTIMP invalid_link_target(_In_z_ const char* _Message) throw();

invalid_link_target() throw();
```  
  
### <a name="parameters"></a>Parâmetros  
 `_Message`  
 Uma mensagem descritiva do erro.  
  
## <a name="see-also"></a>Consulte também  
 [Namespace de simultaneidade](concurrency-namespace.md)   
 [Blocos de mensagens assíncronos](../../../parallel/concrt/asynchronous-message-blocks.md)




