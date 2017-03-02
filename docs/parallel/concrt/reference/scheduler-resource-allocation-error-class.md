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
- concrt/concurrency::scheduler_resource_allocation_error
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
ms.sourcegitcommit: fc190feb08d9b221cd1cc21a9c91ad567c86c848
ms.openlocfilehash: 52233a99e1d1a715fc7d52599ffeff18a3c2c34b
ms.lasthandoff: 02/25/2017

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
|[Construtor scheduler_resource_allocation_error](#ctor)|Sobrecarregado. Constrói um objeto `scheduler_resource_allocation_error`.|  
  
### <a name="public-methods"></a>Métodos Públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[Método get_error_code](#get_error_code)|Retorna o código de erro que causou a exceção.|  
  
## <a name="remarks"></a>Comentários  
 Essa exceção geralmente é lançada quando a falha de uma chamada para o sistema operacional de dentro do Runtime de simultaneidade. O código de erro que normalmente seria retornado de uma chamada para o método Win32 `GetLastError` é convertido em um valor do tipo `HRESULT` e podem ser recuperados usando o `get_error_code` método.  
  
## <a name="inheritance-hierarchy"></a>Hierarquia de herança  
 `exception`  
  
 `scheduler_resource_allocation_error`  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** concrt.h  
  
 **Namespace:** simultaneidade  
  
##  <a name="a-namegeterrorcodea-geterrorcode"></a><a name="get_error_code"></a>get_error_code 

 Retorna o código de erro que causou a exceção.  
  
```
HRESULT get_error_code() const throw();
```  
  
### <a name="return-value"></a>Valor de retorno  
 O `HRESULT` valor do erro que causou a exceção.  
  
##  <a name="a-namectora-schedulerresourceallocationerror"></a><a name="ctor"></a>scheduler_resource_allocation_error 

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

