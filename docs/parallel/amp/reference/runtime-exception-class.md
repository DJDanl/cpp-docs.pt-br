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
ms.openlocfilehash: ff54357055d373db98f469b071edc75fce75e0b4
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81336793"
---
# <a name="runtime_exception-class"></a>Classe runtime_exception

O tipo base para exceções na biblioteca C++ Accelerated Massive Parallelism (AMP).

### <a name="syntax"></a>Sintaxe

```cpp
class runtime_exception : public std::exception;
```

## <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores públicos

|Nome|Descrição|
|----------|-----------------|
|[Construtor runtime_exception](#ctor)|Inicia uma nova instância da classe `runtime_exception`.|
|[~runtime_exception Destructor](#dtor)|Destrói o `runtime_exception` objeto.|

### <a name="public-methods"></a>Métodos públicos

|Nome|Descrição|
|----------|-----------------|
|[get_error_code](#get_error_code)|Retorna o código de erro que causou a exceção.|

### <a name="public-operators"></a>Operadores públicos

|Nome|Descrição|
|----------|-----------------|
|[operador=](#operator_eq)|Copia o conteúdo do `runtime_exception` objeto especificado para este.|

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

`exception`

`runtime_exception`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** amprt.h

**Namespace:** Simultaneidade

## <a name="runtime_exception-constructor"></a><a name="ctor"></a>Construtor runtime_exception

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

## <a name="runtime_exception-destructor"></a><a name="dtor"></a>~runtime_exception Destructor

Destrói o objeto.

### <a name="syntax"></a>Sintaxe

```cpp
virtual ~runtime_exception() throw();
```

## <a name="get_error_code"></a><a name="get_error_code"></a>get_error_code

Retorna o código de erro que causou a exceção.

### <a name="syntax"></a>Sintaxe

```cpp
HRESULT get_error_code() const throw();
```

### <a name="return-value"></a>Valor retornado

O HRESULT do erro que causou a exceção.

## <a name="operator"></a><a name="operator_eq"></a>operador=

Copia o conteúdo do `runtime_exception` objeto especificado para este.

### <a name="syntax"></a>Sintaxe

```cpp
runtime_exception & operator= (    const runtime_exception & _Other ) throw();
```

### <a name="parameters"></a>Parâmetros

*_Other*<br/>
O objeto `runtime_exception` a ser copiado.

### <a name="return-value"></a>Valor retornado

Uma referência `runtime_exception` a este objeto.

## <a name="see-also"></a>Confira também

[Namespace de simultaneidade (C++ AMP)](concurrency-namespace-cpp-amp.md)
