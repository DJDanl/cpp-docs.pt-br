---
title: Classe runtime_exception | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.reviewer: ''
ms.suite: ''
ms.technology:
- cpp-windows
ms.tgt_pltfrm: ''
ms.topic: reference
f1_keywords:
- runtime_exception
- AMPRT/runtime_exception
- AMPRT/Concurrency::runtime_exception
- AMPRT/Concurrency::runtime_exception::get_error_code
dev_langs:
- C++
helpviewer_keywords:
- runtime_exception class
ms.assetid: 8fe3ce2c-3d4c-4b9c-95e8-e592f37adefd
caps.latest.revision: 10
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: 678f0a93577a6e30afbc5e0c6d83aca6b6a7bedc
ms.sourcegitcommit: 0523c88b24d963c33af0529e6ba85ad2c6ee5afb
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/10/2018
---
# <a name="runtimeexception-class"></a>Classe runtime_exception
O tipo base para exceções na biblioteca do C++ Accelerated grandes paralelismo (AMP).  
  
### <a name="syntax"></a>Sintaxe  
  
```  
class runtime_exception : public std::exception;  
```  
  
## <a name="members"></a>Membros  
  
### <a name="public-constructors"></a>Construtores Públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[Construtor de runtime_exception](#ctor)|Inicializa uma nova instância da classe `runtime_exception`.|  
|[~ runtime_exception destruidor](#dtor)|Destrói a `runtime_exception` objeto.|  
  
### <a name="public-methods"></a>Métodos públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[get_error_code](#runtime_exception__get_error_code)|Retorna o código de erro que causou a exceção.|  

  
### <a name="public-operators"></a>Operadores públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[operator=](#operator_eq)|Copia o conteúdo de especificado `runtime_exception` deste objeto.|  
  
## <a name="inheritance-hierarchy"></a>Hierarquia de herança  
 `exception`  
  
 `runtime_exception`  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** amprt.h  
  
 **Namespace:** Simultaneidade  

## <a name="runtime_exception__ctor"></a>  Construtor de runtime_exception  
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
 O HRESULT de erro que causou a exceção.  
  
 `_Other`  
 O `runtime_exception` objeto a ser copiado.  
  
### <a name="return-value"></a>Valor de retorno  
 O objeto `runtime_exception`.  

## <a name="dtor"></a>  ~runtime_exception Destructor  
Destrói o objeto.  
  
### <a name="syntax"></a>Sintaxe  
  
```  
virtual ~runtime_exception() throw();  
```  
  
## <a name="runtime_exception__get_error_code"></a>  get_error_code   
Retorna o código de erro que causou a exceção.  
  
### <a name="syntax"></a>Sintaxe  
  
```  
HRESULT get_error_code() const throw();  
```  
  
### <a name="return-value"></a>Valor de retorno  
 O HRESULT de erro que causou a exceção.  
  
## <a name="runtime_exception__operator_eq"></a>  operator=   
  Copia o conteúdo de especificado `runtime_exception` deste objeto.  
  
### <a name="syntax"></a>Sintaxe  
  
```  
runtime_exception & operator= (    const runtime_exception & _Other ) throw();  
```  
  
### <a name="parameters"></a>Parâmetros  
 `_Other`  
 O `runtime_exception` objeto a ser copiado.  
  
### <a name="return-value"></a>Valor de retorno  
 Uma referência a este `runtime_exception` objeto.  
  

  
## <a name="see-also"></a>Consulte também  
 [Namespace de simultaneidade (C++ AMP)](concurrency-namespace-cpp-amp.md)
