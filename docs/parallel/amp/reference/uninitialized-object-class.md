---
title: Classe uninitialized_object | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-amp
ms.topic: reference
f1_keywords:
- uninitialized_object
- AMPRT/uninitialized_object
- AMPRT/Concurrency::uninitialized_object
dev_langs:
- C++
helpviewer_keywords:
- uninitialized_object class
ms.assetid: 6ae3c4e8-64a6-4511-a158-03be197b63af
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 821f3c25d195a2c92ac04fdf5f9e5a59b493c257
ms.sourcegitcommit: 913c3bf23937b64b90ac05181fdff3df947d9f1c
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/18/2018
ms.locfileid: "46113832"
---
# <a name="uninitializedobject-class"></a>Classe uninitialized_object
A exceção que é lançada quando um objeto não inicializado é usado.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
class uninitialized_object : public runtime_exception;  
```  
  
## <a name="members"></a>Membros  
  
### <a name="public-constructors"></a>Construtores Públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[Construtor de uninitialized_object](#ctor)|Inicializa uma nova instância da classe `uninitialized_object`.|  

  
## <a name="inheritance-hierarchy"></a>Hierarquia de herança  
 `exception`  
  
 `runtime_exception`  
  
 `uninitialized_object`  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** amprt. h  
  
 **Namespace:** Simultaneidade  
## <a name="uninitialized_object__ctor"></a> unsupported_feature 

Constrói uma nova instância da exceção de unsupported_feature.  
  
### <a name="syntax"></a>Sintaxe  
  
```  
explicit unsupported_feature(  
    const char * _Message ) throw();  
  
unsupported_feature() throw();  
```  
  
### <a name="parameters"></a>Parâmetros  
*Mensagem*<br/>
Uma descrição do erro.  
  
### <a name="return-value"></a>Valor de retorno  
 O objeto `unsupported_feature`. 

## <a name="see-also"></a>Consulte também  
 [Namespace de simultaneidade (C++ AMP)](concurrency-namespace-cpp-amp.md)
