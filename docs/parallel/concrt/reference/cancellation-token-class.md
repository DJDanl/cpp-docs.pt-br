---
title: Classe cancellation_token
ms.date: 11/04/2016
f1_keywords:
- cancellation_token
- PPLCANCELLATION_TOKEN/concurrency::cancellation_token
- PPLCANCELLATION_TOKEN/concurrency::cancellation_token::cancellation_token
- PPLCANCELLATION_TOKEN/concurrency::cancellation_token::deregister_callback
- PPLCANCELLATION_TOKEN/concurrency::cancellation_token::is_cancelable
- PPLCANCELLATION_TOKEN/concurrency::cancellation_token::is_canceled
- PPLCANCELLATION_TOKEN/concurrency::cancellation_token::none
- PPLCANCELLATION_TOKEN/concurrency::cancellation_token::register_callback
helpviewer_keywords:
- cancellation_token class
ms.assetid: 2787df2b-e9d3-440e-bfd0-841a46a9835f
ms.openlocfilehash: 6f1e204c87a6bc940227416696e3cee233271e64
ms.sourcegitcommit: 1f009ab0f2cc4a177f2d1353d5a38f164612bdb1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/27/2020
ms.locfileid: "87213860"
---
# <a name="cancellation_token-class"></a>Classe cancellation_token

A `cancellation_token` classe representa a capacidade de determinar se alguma operação foi solicitada a cancelar. Um determinado token pode ser associado a um `task_group` , `structured_task_group` ou `task` para fornecer cancelamento implícito. Ele também pode ser sondado para cancelamento ou ter um retorno de chamada registrado para If e quando o associado `cancellation_token_source` for cancelado.

## <a name="syntax"></a>Sintaxe

```cpp
class cancellation_token;
```

## <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores públicos

|Nome|Descrição|
|----------|-----------------|
|[cancellation_token](#ctor)||
|[~ cancellation_token destruidor](#dtor)||

### <a name="public-methods"></a>Métodos públicos

|Nome|Descrição|
|----------|-----------------|
|[deregister_callback](#deregister_callback)|Remove um retorno de chamada registrado anteriormente por meio do `register` método baseado no `cancellation_token_registration` objeto retornado no momento do registro.|
|[is_cancelable](#is_cancelable)|Retorna uma indicação de se esse token pode ser cancelado ou não.|
|[is_canceled](#is_canceled)|Retorna **`true`** se o token foi cancelado.|
|[nenhum](#none)|Retorna um token de cancelamento que nunca pode estar sujeito ao cancelamento.|
|[register_callback](#register_callback)|Registra uma função de retorno de chamada com o token. Se e quando o token for cancelado, o retorno de chamada será feito. Observe que, se o token já estiver cancelado no ponto em que esse método é chamado, o retorno de chamada será feito imediatamente e de forma síncrona.|

### <a name="public-operators"></a>Operadores públicos

|Nome|Descrição|
|----------|-----------------|
|[operador! =](#operator_neq)||
|[operador =](#operator_eq)||
|[operador = =](#operator_eq_eq)||

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

`cancellation_token`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** pplcancellation_token. h

**Namespace:** simultaneidade

## <a name="cancellation_token"></a><a name="dtor"></a>~ cancellation_token

```cpp
~cancellation_token();
```

## <a name="cancellation_token"></a><a name="ctor"></a>cancellation_token

```cpp
cancellation_token(const cancellation_token& _Src);

cancellation_token(cancellation_token&& _Src);
```

### <a name="parameters"></a>parâmetros

*_Src*<br/>
O cancellation_token a ser copiado ou movido.

## <a name="deregister_callback"></a><a name="deregister_callback"></a>deregister_callback

Remove um retorno de chamada registrado anteriormente por meio do `register` método baseado no `cancellation_token_registration` objeto retornado no momento do registro.

```cpp
void deregister_callback(const cancellation_token_registration& _Registration) const;
```

### <a name="parameters"></a>parâmetros

*_Registration*<br/>
O `cancellation_token_registration` objeto correspondente ao retorno de chamada a ser cancelado. Esse token deve ter sido retornado anteriormente de uma chamada para o `register` método.

## <a name="is_cancelable"></a><a name="is_cancelable"></a>is_cancelable

Retorna uma indicação de se esse token pode ser cancelado ou não.

```cpp
bool is_cancelable() const;
```

### <a name="return-value"></a>Valor retornado

Uma indicação de se esse token pode ser cancelado ou não.

## <a name="is_canceled"></a><a name="is_canceled"></a>is_canceled

Retorna **`true`** se o token foi cancelado.

```cpp
bool is_canceled() const;
```

### <a name="return-value"></a>Valor retornado

O valor **`true`** se o token foi cancelado; caso contrário, o valor **`false`** .

## <a name="none"></a><a name="none"></a>None

Retorna um token de cancelamento que nunca pode estar sujeito ao cancelamento.

```cpp
static cancellation_token none();
```

### <a name="return-value"></a>Valor retornado

Um token de cancelamento que não pode ser cancelado.

## <a name="operator"></a><a name="operator_neq"></a>operador! =

```cpp
bool operator!= (const cancellation_token& _Src) const;
```

### <a name="parameters"></a>parâmetros

*_Src*<br/>
O `cancellation_token` a ser comparado.

### <a name="return-value"></a>Valor retornado

## <a name="operator"></a><a name="operator_eq"></a>operador =

```cpp
cancellation_token& operator= (const cancellation_token& _Src);

cancellation_token& operator= (cancellation_token&& _Src);
```

### <a name="parameters"></a>parâmetros

*_Src*<br/>
O `cancellation_token` a ser atribuído.

### <a name="return-value"></a>Valor retornado

## <a name="operator"></a><a name="operator_eq_eq"></a>operador = =

```cpp
bool operator== (const cancellation_token& _Src) const;
```

### <a name="parameters"></a>parâmetros

*_Src*<br/>
O `cancellation_token` a ser comparado.

### <a name="return-value"></a>Valor retornado

## <a name="register_callback"></a><a name="register_callback"></a>register_callback

Registra uma função de retorno de chamada com o token. Se e quando o token for cancelado, o retorno de chamada será feito. Observe que, se o token já estiver cancelado no ponto em que esse método é chamado, o retorno de chamada será feito imediatamente e de forma síncrona.

```cpp
template<typename _Function>
::Concurrency::cancellation_token_registration register_callback(const _Function& _Func) const;
```

### <a name="parameters"></a>parâmetros

*_Function*<br/>
O tipo do objeto de função que será chamado novamente quando `cancellation_token` for cancelado.

*_Func*<br/>
O objeto de função que será chamado de volta quando isso `cancellation_token` for cancelado.

### <a name="return-value"></a>Valor retornado

Um `cancellation_token_registration` objeto que pode ser utilizado no `deregister` método para cancelar o registro de um retorno de chamada previamente registrado e impedir que ele seja feito. O método gerará uma exceção [invalid_operation](invalid-operation-class.md) se for chamado em um `cancellation_token` objeto criado usando o método [cancellation_token:: None](#none) .

## <a name="see-also"></a>Confira também

[Namespace de simultaneidade](concurrency-namespace.md)
