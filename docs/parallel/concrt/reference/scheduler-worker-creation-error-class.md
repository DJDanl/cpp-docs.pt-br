---
title: Classe scheduler_worker_creation_error | Documentos do Microsoft
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-windows
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords:
- scheduler_worker_creation_error
- CONCRT/concurrency::scheduler_worker_creation_error
- CONCRT/concurrency::scheduler_worker_creation_error::scheduler_worker_creation_error
dev_langs:
- C++
helpviewer_keywords:
- scheduler_worker_creation_error class
ms.assetid: 4aec1c3e-c32a-41b2-899d-2d898f23b3c7
caps.latest.revision: 9
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
ms.translationtype: Machine Translation
ms.sourcegitcommit: 5faef5bd1be6cc02d6614a6f6193c74167a8ff23
ms.openlocfilehash: aee9d72447aca692fa25d675bdc5f727fa5b5c15
ms.contentlocale: pt-br
ms.lasthandoff: 03/17/2017

---
# <a name="schedulerworkercreationerror-class"></a>Classe scheduler_worker_creation_error
Esta classe descreve uma exceção lançada devido a uma falha ao criar um contexto de execução do trabalho em tempo de execução de simultaneidade.  
  
## <a name="syntax"></a>Sintaxe  
  
```
class scheduler_worker_creation_error : public scheduler_resource_allocation_error;
```  
  
## <a name="members"></a>Membros  
  
### <a name="public-constructors"></a>Construtores públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[scheduler_worker_creation_error](#ctor)|Sobrecarregado. Constrói um objeto `scheduler_worker_creation_error`.|  
  
## <a name="remarks"></a>Comentários  
 Essa exceção geralmente é lançada quando uma chamada para o sistema operacional para criar contextos de execução de dentro do Runtime de simultaneidade falhar. Contextos de execução são threads que executam tarefas no tempo de execução de simultaneidade. O código de erro que normalmente seria retornado de uma chamada para o método Win32 `GetLastError` é convertido em um valor do tipo `HRESULT` e podem ser recuperados usando o método da classe base `get_error_code`.  
  
## <a name="inheritance-hierarchy"></a>Hierarquia de herança  
 `exception`  
  
 [scheduler_resource_allocation_error](scheduler-resource-allocation-error-class.md)  
  
 `scheduler_worker_creation_error`  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** concrt.h  
  
 **Namespace:** simultaneidade  
  
##  <a name="ctor"></a>scheduler_worker_creation_error 

 Constrói um objeto `scheduler_worker_creation_error`.  
  
```
scheduler_worker_creation_error(
    _In_z_ const char* _Message,
    HRESULT _Hresult) throw();

explicit _CRTIMP scheduler_worker_creation_error(
    HRESULT _Hresult) throw();
```  
  
### <a name="parameters"></a>Parâmetros  
 `_Message`  
 Uma mensagem descritiva do erro.  
  
 `_Hresult`  
 O `HRESULT` valor do erro que causou a exceção.  
  
## <a name="see-also"></a>Consulte também  
 [Namespace de simultaneidade](concurrency-namespace.md)

