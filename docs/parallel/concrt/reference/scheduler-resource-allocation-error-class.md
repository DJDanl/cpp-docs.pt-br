---
title: Classe scheduler_resource_allocation_error | Documentos do Microsoft
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords:
- scheduler_resource_allocation_error
- CONCRT/concurrency::scheduler_resource_allocation_error
- CONCRT/concurrency::scheduler_resource_allocation_error::scheduler_resource_allocation_error
- CONCRT/concurrency::scheduler_resource_allocation_error::get_error_code
dev_langs:
- C++
helpviewer_keywords:
- scheduler_resource_allocation_error class
ms.assetid: 8b40449a-7abb-4d0a-bb85-c0e9a495ae97
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
ms.sourcegitcommit: 5faef5bd1be6cc02d6614a6f6193c74167a8ff23
ms.openlocfilehash: 84f32bb6192057c9d5872147cc8ef0bd2c13b349
ms.lasthandoff: 03/17/2017

---
# <a name="schedulerresourceallocationerror-class"></a>Classe scheduler_resource_allocation_error
Esta classe descreve uma exceção lançada devido a uma falha ao adquirir um recurso crítico em tempo de execução de simultaneidade.  
  
## <a name="syntax"></a>Sintaxe  
  
```
class scheduler_resource_allocation_error : public std::exception;
```  
  
## <a name="members"></a>Membros  
  
### <a name="public-constructors"></a>Construtores públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[scheduler_resource_allocation_error](#ctor)|Sobrecarregado. Constrói um objeto `scheduler_resource_allocation_error`.|  
  
### <a name="public-methods"></a>Métodos Públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[get_error_code](#get_error_code)|Retorna o código de erro que causou a exceção.|  
  
## <a name="remarks"></a>Comentários  
 Essa exceção geralmente é lançada quando a falha de uma chamada para o sistema operacional de dentro do Runtime de simultaneidade. O código de erro que normalmente seria retornado de uma chamada para o método Win32 `GetLastError` é convertido em um valor do tipo `HRESULT` e podem ser recuperados usando o `get_error_code` método.  
  
## <a name="inheritance-hierarchy"></a>Hierarquia de herança  
 `exception`  
  
 `scheduler_resource_allocation_error`  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** concrt.h  
  
 **Namespace:** simultaneidade  
  
##  <a name="get_error_code"></a>get_error_code 

 Retorna o código de erro que causou a exceção.  
  
```
HRESULT get_error_code() const throw();
```  
  
### <a name="return-value"></a>Valor de retorno  
 O `HRESULT` valor do erro que causou a exceção.  
  
##  <a name="ctor"></a>scheduler_resource_allocation_error 

 Constrói um objeto `scheduler_resource_allocation_error`.  
  
```
scheduler_resource_allocation_error(
    _In_z_ const char* _Message,
    HRESULT _Hresult) throw();

explicit _CRTIMP scheduler_resource_allocation_error(
    HRESULT _Hresult) throw();
```  
  
### <a name="parameters"></a>Parâmetros  
 `_Message`  
 Uma mensagem descritiva do erro.  
  
 `_Hresult`  
 O `HRESULT` valor do erro que causou a exceção.  
  
## <a name="see-also"></a>Consulte também  
 [Namespace de simultaneidade](concurrency-namespace.md)

