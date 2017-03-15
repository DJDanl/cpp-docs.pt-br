---
title: Classe improper_lock | Documentos do Microsoft
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords:
- concrt/concurrency::improper_lock
dev_langs:
- C++
helpviewer_keywords:
- improper_lock class
ms.assetid: 8f494942-7748-4a2a-8de2-23414bfe6346
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
ms.openlocfilehash: 5a68573b8963fed90a4346fd421ef479c35dc247
ms.lasthandoff: 02/25/2017

---
# <a name="improperlock-class"></a>Classe improper_lock
Esta classe descreve uma exceção gerada quando um bloqueio é adquirido incorretamente.  
  
## <a name="syntax"></a>Sintaxe  
  
```
class improper_lock : public std::exception;
```  
  
## <a name="members"></a>Membros  
  
### <a name="public-constructors"></a>Construtores públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[Construtor improper_lock](#ctor)|Sobrecarregado. Constrói um `improper_lock exception`.|  
  
## <a name="remarks"></a>Comentários  
 Normalmente, essa exceção é lançada quando é feita uma tentativa de adquirir um bloqueio de não reentrante recursivamente no mesmo contexto.  
  
## <a name="inheritance-hierarchy"></a>Hierarquia de herança  
 `exception`  
  
 `improper_lock`  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** concrt.h  
  
 **Namespace:** simultaneidade  
  
##  <a name="a-namectora-improperlock"></a><a name="ctor"></a>improper_lock 

 Constrói um `improper_lock exception`.  
  
```
explicit _CRTIMP improper_lock(_In_z_ const char* _Message) throw();

improper_lock() throw();
```  
  
### <a name="parameters"></a>Parâmetros  
 `_Message`  
 Uma mensagem descritiva do erro.  
  
## <a name="see-also"></a>Consulte também  
 [Namespace de simultaneidade](concurrency-namespace.md)   
 [Classe CRITICAL_SECTION](critical-section-class.md)   
 [Classe reader_writer_lock](reader-writer-lock-class.md)

