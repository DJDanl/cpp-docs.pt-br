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
ms.openlocfilehash: 6ad784720833d2ae5de7d653d132ba144aec2677
ms.sourcegitcommit: a8ef52ff4a4944a1a257bdaba1a3331607fb8d0f
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 02/11/2020
ms.locfileid: "77126365"
---
# <a name="runtime_exception-class"></a>Classe runtime_exception

O tipo base para exceções na biblioteca C++ de amp (grande paralelismo) acelerada.

### <a name="syntax"></a>Sintaxe

```cpp
class runtime_exception : public std::exception;
```

## <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores públicos

|{1&gt;Nome&lt;1}|Descrição|
|----------|-----------------|
|[Construtor de runtime_exception](#ctor)|Inicializa uma nova instância da classe `runtime_exception`.|
|[~ runtime_exception destruidor](#dtor)|Destrói o objeto `runtime_exception`.|

### <a name="public-methods"></a>Métodos públicos

|{1&gt;Nome&lt;1}|Descrição|
|----------|-----------------|
|[get_error_code](#get_error_code)|Retorna o código de erro que causou a exceção.|

### <a name="public-operators"></a>Operadores públicos

|{1&gt;Nome&lt;1}|Descrição|
|----------|-----------------|
|[operator=](#operator_eq)|Copia o conteúdo do objeto `runtime_exception` especificado para este.|

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

`exception`

`runtime_exception`

## <a name="requirements"></a>{1&gt;{2&gt;Requisitos&lt;2}&lt;1}

**Cabeçalho:** amprt. h

**Namespace:** Simultaneidade

## <a name="ctor"></a>Construtor de runtime_exception

Inicializa uma nova instância da classe.

### <a name="syntax"></a>Sintaxe

```cpp
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
O objeto `runtime_exception` a ser copiado.

### <a name="return-value"></a>Valor retornado

O objeto `runtime_exception`.

## <a name="dtor"></a>~ runtime_exception destruidor

Destrói o objeto.

### <a name="syntax"></a>Sintaxe

```cpp
virtual ~runtime_exception() throw();
```

## <a name="get_error_code"></a>get_error_code

Retorna o código de erro que causou a exceção.

### <a name="syntax"></a>Sintaxe

```cpp
HRESULT get_error_code() const throw();
```

### <a name="return-value"></a>Valor retornado

O HRESULT do erro que causou a exceção.

## <a name="operator_eq"></a>  operator=
  Copia o conteúdo do objeto `runtime_exception` especificado para este.

### <a name="syntax"></a>Sintaxe

```cpp
runtime_exception & operator= (    const runtime_exception & _Other ) throw();
```

### <a name="parameters"></a>Parâmetros

*_Other*<br/>
O objeto `runtime_exception` a ser copiado.

### <a name="return-value"></a>Valor retornado

Uma referência a este objeto de `runtime_exception`.

## <a name="see-also"></a>Consulte também

[Namespace de simultaneidade (C++ AMP)](concurrency-namespace-cpp-amp.md)
