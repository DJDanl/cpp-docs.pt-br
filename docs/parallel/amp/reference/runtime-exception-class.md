---
title: Classe runtime_exception | Documentos do Microsoft
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords:
- amp/Concurrency::direct3d_abort
dev_langs:
- C++
helpviewer_keywords:
- runtime_exception class
ms.assetid: 8fe3ce2c-3d4c-4b9c-95e8-e592f37adefd
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
ms.openlocfilehash: 1a2655ed4c8783dd5f7a3b8af2a7d6a9db88f43e
ms.lasthandoff: 02/25/2017

---
# <a name="runtimeexception-class"></a>Classe runtime_exception
O tipo base para exceções na biblioteca do C++ Accelerated maciça Parallelism (AMP).  
  
### <a name="syntax"></a>Sintaxe  
  
```  
class runtime_exception : public std::exception;  
```  
  
## <a name="members"></a>Membros  
  
### <a name="public-constructors"></a>Construtores públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[Construtor runtime_exception](#ctor)|Inicializa uma nova instância da classe `runtime_exception`.|  
|[~ runtime_exception destruidor](#dtor)|Destrói o `runtime_exception` objeto.|  
  
### <a name="public-methods"></a>Métodos públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[Método get_error_code](#runtime_exception__get_error_code)|Retorna o código de erro que causou a exceção.|  

  
### <a name="public-operators"></a>Operadores públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[operador Operator =](#operator_eq)|Copia o conteúdo especificado `runtime_exception` deste objeto.|  
  
## <a name="inheritance-hierarchy"></a>Hierarquia de herança  
 `exception`  
  
 `runtime_exception`  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** amprt.h  
  
 **Namespace:** Simultaneidade  

## <a name="a-nameruntimeexceptionctora--runtimeexception-constructor"></a><a name="runtime_exception__ctor"></a>Construtor runtime_exception  
Inicializa uma nova instância da classe.  
  
### <a name="syntax"></a>Sintaxe  
  
```  
runtime_exception(  
    const char * _Message,  
    HRESULT _Hresult ) throw();  
  
explicit runtime_exception(  
    HRESULT _Hresult ) throw();  
  
runtime_exception(  
    const runtime_exception & _Other ) throw();  
```  
  
### <a name="parameters"></a>Parâmetros  
 `_Message`  
 Uma descrição do erro que causou a exceção.  
  
 `_Hresult`  
 O HRESULT do erro que causou a exceção.  
  
 `_Other`  
 O `runtime_exception` objeto a ser copiado.  
  
### <a name="return-value"></a>Valor de retorno  
 O objeto `runtime_exception`.  

## <a name="a-namedtora--runtimeexception-destructor"></a><a name="dtor"></a>~ runtime_exception destruidor  
Destrói o objeto.  
  
### <a name="syntax"></a>Sintaxe  
  
```  
virtual ~runtime_exception() throw();  
```  
  
## <a name="a-nameruntimeexceptiongeterrorcodea--geterrorcode"></a><a name="runtime_exception__get_error_code"></a>get_error_code   
Retorna o código de erro que causou a exceção.  
  
### <a name="syntax"></a>Sintaxe  
  
```  
HRESULT get_error_code() const throw();  
```  
  
### <a name="return-value"></a>Valor de retorno  
 O HRESULT do erro que causou a exceção.  
  
## <a name="a-nameruntimeexceptionoperatoreqa--operator"></a><a name="runtime_exception__operator_eq"></a>  operator=   
  Copia o conteúdo especificado `runtime_exception` deste objeto.  
  
### <a name="syntax"></a>Sintaxe  
  
```  
runtime_exception & operator= (    const runtime_exception & _Other ) throw();  
```  
  
### <a name="parameters"></a>Parâmetros  
 `_Other`  
 O `runtime_exception` objeto a ser copiado.  
  
### <a name="return-value"></a>Valor de retorno  
 Uma referência a esta `runtime_exception` objeto.  
  

  
## <a name="see-also"></a>Consulte também  
 [Namespace de simultaneidade (C++ AMP)](concurrency-namespace-cpp-amp.md)

