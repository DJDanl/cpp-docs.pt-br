---
title: Classe scheduler_worker_creation_error | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-windows
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords:
- scheduler_worker_creation_error
- CONCRT/concurrency::scheduler_worker_creation_error
- CONCRT/concurrency::scheduler_worker_creation_error::scheduler_worker_creation_error
dev_langs: C++
helpviewer_keywords: scheduler_worker_creation_error class
ms.assetid: 4aec1c3e-c32a-41b2-899d-2d898f23b3c7
caps.latest.revision: "9"
author: mikeblome
ms.author: mblome
manager: ghogen
ms.openlocfilehash: 0a628d0ce3d85a2bdcae9c7d25550cbd36386e67
ms.sourcegitcommit: ebec1d449f2bd98aa851667c2bfeb7e27ce657b2
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/24/2017
---
# <a name="schedulerworkercreationerror-class"></a>Classe scheduler_worker_creation_error
Esta classe descreve uma exceção gerada devido a uma falha ao criar um contexto de execução do trabalho no tempo de execução de simultaneidade.  
  
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
 Essa exceção normalmente é lançada quando uma chamada para o sistema operacional para criar contextos de execução de dentro do tempo de execução de simultaneidade falhar. Contextos de execução são threads que executam tarefas em tempo de execução de simultaneidade. O código de erro que normalmente seria retornado de uma chamada ao método Win32 `GetLastError` é convertido em um valor do tipo `HRESULT` e podem ser recuperados usando o método da classe base `get_error_code`.  
  
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
