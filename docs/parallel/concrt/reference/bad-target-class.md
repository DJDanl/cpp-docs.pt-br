---
title: Classe bad_target | Documentos do Microsoft
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords:
- concrt/concurrency::bad_target
dev_langs:
- C++
helpviewer_keywords:
- bad_target class
ms.assetid: e6dcddbf-9217-4fac-ac7f-7b8b4781d2f5
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
ms.openlocfilehash: a22ebb69195dcea91799dc1c2e301a578dd227bc
ms.lasthandoff: 02/25/2017

---
# <a name="badtarget-class"></a>Classe bad_target
Esta classe descreve uma exceção gerada quando um bloco de mensagens é dado um ponteiro para um destino que é inválido para a operação que está sendo executada.  
  
## <a name="syntax"></a>Sintaxe  
  
```
class bad_target : public std::exception;
```  
  
## <a name="members"></a>Membros  
  
### <a name="public-constructors"></a>Construtores públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[Construtor bad_target](#ctor)|Sobrecarregado. Constrói um objeto `bad_target`.|  
  
## <a name="remarks"></a>Comentários  
 Normalmente, essa exceção é lançada por motivos como um destino de tentativa de receber uma mensagem que é reservada para um destino diferente ou liberar uma reserva de que ele não mantém.  
  
## <a name="inheritance-hierarchy"></a>Hierarquia de herança  
 `exception`  
  
 `bad_target`  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** concrt.h  
  
 **Namespace:** simultaneidade  
  
##  <a name="a-namectora-badtarget"></a><a name="ctor"></a>bad_target 

 Constrói um objeto `bad_target`.  
  
```
explicit _CRTIMP bad_target(_In_z_ const char* _Message) throw();

bad_target() throw();
```  
  
### <a name="parameters"></a>Parâmetros  
 `_Message`  
 Uma mensagem descritiva do erro.  
  
## <a name="see-also"></a>Consulte também  
 [Namespace de simultaneidade](concurrency-namespace.md)   
 [Blocos de mensagens assíncronos](../../../parallel/concrt/asynchronous-message-blocks.md)




