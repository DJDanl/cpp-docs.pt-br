---
title: Classe uninitialized_object | Documentos do Microsoft
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords:
- amprt/Concurrency::uninitialized_object
dev_langs:
- C++
helpviewer_keywords:
- uninitialized_object class
ms.assetid: 6ae3c4e8-64a6-4511-a158-03be197b63af
caps.latest.revision: 10
author: mikeblome
ms.author: mblome
manager: ghogen
translation.priority.ht:
- de-de
- es-es
- fr-fr
- it-it
- ja-jp
- ko-kr
- ru-ru
- zh-cn
- zh-tw
translation.priority.mt:
- cs-cz
- pl-pl
- pt-br
- tr-tr
translationtype: Machine Translation
ms.sourcegitcommit: fc190feb08d9b221cd1cc21a9c91ad567c86c848
ms.openlocfilehash: 1ff7840ec3ff4ab00b7e13d647c329a892dade42
ms.lasthandoff: 02/25/2017

---
# <a name="uninitializedobject-class"></a>Classe uninitialized_object
A exceção que é lançada quando é usado um objeto não inicializado.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
class uninitialized_object : public runtime_exception;  
```  
  
## <a name="members"></a>Membros  
  
### <a name="public-constructors"></a>Construtores públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[Construtor uninitialized_object](#ctor)|Inicializa uma nova instância da classe `uninitialized_object`.|  

  
## <a name="inheritance-hierarchy"></a>Hierarquia de herança  
 `exception`  
  
 `runtime_exception`  
  
 `uninitialized_object`  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** amprt.h  
  
 **Namespace:** Simultaneidade  
## <a name="a-nameuninitializedobjectctora-unsupportedfeature"></a><a name="uninitialized_object__ctor"></a>unsupported_feature 

Cria uma nova instância da exceção unsupported_feature.  
  
### <a name="syntax"></a>Sintaxe  
  
```  
explicit unsupported_feature(  
    const char * _Message ) throw();  
  
unsupported_feature() throw();  
```  
  
### <a name="parameters"></a>Parâmetros  
 `_Message`  
 Uma descrição do erro.  
  
### <a name="return-value"></a>Valor de retorno  
 O objeto `unsupported_feature`. 

## <a name="see-also"></a>Consulte também  
 [Namespace de simultaneidade (C++ AMP)](concurrency-namespace-cpp-amp.md)

