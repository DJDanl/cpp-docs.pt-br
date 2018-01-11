---
title: Classe bad_target | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-windows
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords:
- bad_target
- CONCRT/concurrency::bad_target
- CONCRT/concurrency::bad_target::bad_target
dev_langs: C++
helpviewer_keywords: bad_target class
ms.assetid: e6dcddbf-9217-4fac-ac7f-7b8b4781d2f5
caps.latest.revision: "19"
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload: cplusplus
ms.openlocfilehash: 37cba64767d492559a52e9bf84c132b5f5ba1b50
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="badtarget-class"></a>Classe bad_target
Esta classe descreve uma exceção gerada quando um bloco de mensagens é fornecido um ponteiro para um destino que não é válido para a operação que está sendo executada.  
  
## <a name="syntax"></a>Sintaxe  
  
```
class bad_target : public std::exception;
```  
  
## <a name="members"></a>Membros  
  
### <a name="public-constructors"></a>Construtores Públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[bad_target](#ctor)|Sobrecarregado. Constrói um objeto `bad_target`.|  
  
## <a name="remarks"></a>Comentários  
 Normalmente, essa exceção é lançada por motivos como um destino de tentativa de consumir uma mensagem que é reservada para um destino diferente ou liberar uma reserva de que ele não mantém.  
  
## <a name="inheritance-hierarchy"></a>Hierarquia de herança  
 `exception`  
  
 `bad_target`  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** concrt.h  
  
 **Namespace:** simultaneidade  
  
##  <a name="ctor"></a>bad_target 

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



