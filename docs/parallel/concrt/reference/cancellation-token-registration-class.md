---
title: Classe cancellation_token_registration
ms.date: 11/04/2016
f1_keywords:
- cancellation_token_registration
- PPLCANCELLATION_TOKEN/concurrency::cancellation_token_registration
- PPLCANCELLATION_TOKEN/concurrency::cancellation_token_registration::cancellation_token_registration
helpviewer_keywords:
- cancellation_token_registration class
ms.assetid: 823d63f4-7233-4d65-8976-6152ccf12d0e
ms.openlocfilehash: 9342841e207c93b66521c2fc742c1b1114682f78
ms.sourcegitcommit: a8ef52ff4a4944a1a257bdaba1a3331607fb8d0f
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 02/11/2020
ms.locfileid: "77142244"
---
# <a name="cancellation_token_registration-class"></a>Classe cancellation_token_registration

A classe `cancellation_token_registration` representa uma notificação de retorno de chamada de um `cancellation_token`. Quando o método de `register` em um `cancellation_token` é usado para receber a notificação de quando o cancelamento ocorre, um objeto `cancellation_token_registration` é retornado como um identificador para o retorno de chamada para que o chamador possa solicitar que um retorno de chamada específico não seja mais feito pelo uso do método `deregister`.

## <a name="syntax"></a>Sintaxe

```cpp
class cancellation_token_registration;
```

## <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores públicos

|{1&gt;Nome&lt;1}|Descrição|
|----------|-----------------|
|[cancellation_token_registration](#ctor)||
|[~ cancellation_token_registration destruidor](#dtor)||

### <a name="public-operators"></a>Operadores públicos

|{1&gt;Nome&lt;1}|Descrição|
|----------|-----------------|
|[operator!=](#operator_neq)||
|[operator=](#operator_eq)||
|[operator==](#operator_eq_eq)||

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

`cancellation_token_registration`

## <a name="requirements"></a>{1&gt;{2&gt;Requisitos&lt;2}&lt;1}

**Cabeçalho:** pplcancellation_token. h

**Namespace:** simultaneidade

## <a name="dtor"></a>~ cancellation_token_registration

```cpp
~cancellation_token_registration();
```

## <a name="ctor"></a>cancellation_token_registration

```cpp
cancellation_token_registration();

cancellation_token_registration(const cancellation_token_registration& _Src);

cancellation_token_registration(cancellation_token_registration&& _Src);
```

### <a name="parameters"></a>Parâmetros

*_Src*<br/>
O `cancellation_token_registration` para copiar ou mover.

## <a name="operator_neq"></a>operador! =

```cpp
bool operator!= (const cancellation_token_registration& _Rhs) const;
```

### <a name="parameters"></a>Parâmetros

*_Rhs*<br/>
O `cancellation_token_registration` a ser comparado.

### <a name="return-value"></a>Valor retornado

## <a name="operator_eq"></a>operador =

```cpp
cancellation_token_registration& operator= (const cancellation_token_registration& _Src);

cancellation_token_registration& operator= (cancellation_token_registration&& _Src);
```

### <a name="parameters"></a>Parâmetros

*_Src*<br/>
O `cancellation_token_registration` a ser atribuído.

### <a name="return-value"></a>Valor retornado

## <a name="operator_eq_eq"></a>operador = =

```cpp
bool operator== (const cancellation_token_registration& _Rhs) const;
```

### <a name="parameters"></a>Parâmetros

*_Rhs*<br/>
O `cancellation_token_registration` a ser comparado.

### <a name="return-value"></a>Valor retornado

## <a name="see-also"></a>Consulte também

[Namespace de simultaneidade](concurrency-namespace.md)
