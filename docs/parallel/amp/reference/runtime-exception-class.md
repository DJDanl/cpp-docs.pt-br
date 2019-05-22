---
title: Classe runtime_exception
ms.date: 03/27/2019
f1_keywords:
- runtime_exception
- AMPRT/runtime_exception
- AMPRT/Concurrency::runtime_exception
- AMPRT/Concurrency::runtime_exception::get_error_code
helpviewer_keywords:
- runtime_exception class
ms.assetid: 8fe3ce2c-3d4c-4b9c-95e8-e592f37adefd
ms.openlocfilehash: 8ed3fb5edd861eaecd0bf9a39687a2a63fdfe695
ms.sourcegitcommit: a61d17cffdd50f1c3c6e082a01bbcbc85b6cc5a7
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/21/2019
ms.locfileid: "65975176"
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
|[Construtor de runtime_exception](#ctor)|Inicializa uma nova instância da classe `runtime_exception`.|
|[~ runtime_exception destruidor](#dtor)|Destrói o `runtime_exception` objeto.|

### <a name="public-methods"></a>Métodos públicos

|Nome|Descrição|
|----------|-----------------|
|[get_error_code](#get_error_code)|Retorna o código de erro que causou a exceção.|

### <a name="public-operators"></a>Operadores públicos

|Nome|Descrição|
|----------|-----------------|
|[operator=](#operator_eq)|Copia o conteúdo especificado `runtime_exception` esse objeto.|

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

`exception`

`runtime_exception`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** amprt. h

**Namespace:** Concorrência

## <a name="ctor"></a>  Construtor de runtime_exception

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

*_Message*<br/>
Uma descrição do erro que causou a exceção.

*_Hresult*<br/>
O HRESULT do erro que causou a exceção.

*_Other*<br/>
O `runtime_exception` objeto a ser copiado.

### <a name="return-value"></a>Valor de retorno

O objeto `runtime_exception`.

## <a name="dtor"></a>  ~ runtime_exception destruidor

Destrói o objeto.

### <a name="syntax"></a>Sintaxe

```
virtual ~runtime_exception() throw();
```

## <a name="get_error_code"></a> get_error_code

Retorna o código de erro que causou a exceção.

### <a name="syntax"></a>Sintaxe

```
HRESULT get_error_code() const throw();
```

### <a name="return-value"></a>Valor de retorno

O HRESULT do erro que causou a exceção.

## <a name="operator_eq"></a>  operator=
  Copia o conteúdo especificado `runtime_exception` esse objeto.

### <a name="syntax"></a>Sintaxe

```
runtime_exception & operator= (    const runtime_exception & _Other ) throw();
```

### <a name="parameters"></a>Parâmetros

*_Other*<br/>
O `runtime_exception` objeto a ser copiado.

### <a name="return-value"></a>Valor de retorno

Uma referência a este `runtime_exception` objeto.

## <a name="see-also"></a>Consulte também

[Namespace de simultaneidade (C++ AMP)](concurrency-namespace-cpp-amp.md)
