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
ms.openlocfilehash: 34743ce48510eec9d8f7862e5ed951a722932962
ms.sourcegitcommit: 3e8fa01f323bc5043a48a0c18b855d38af3648d4
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/06/2020
ms.locfileid: "78876068"
---
# <a name="cancellation_token-class"></a>Classe cancellation_token

A classe `cancellation_token` representa a capacidade de determinar se alguma operação foi solicitada a cancelar. Um determinado token pode ser associado a um `task_group`, `structured_task_group`ou `task` para fornecer cancelamento implícito. Ele também pode ser sondado para cancelamento ou ter um retorno de chamada registrado para If e quando o `cancellation_token_source` associado for cancelado.

## <a name="syntax"></a>Sintaxe

```cpp
class cancellation_token;
```

## <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores públicos

|Nome|DESCRIÇÃO|
|----------|-----------------|
|[cancellation_token](#ctor)||
|[~ cancellation_token destruidor](#dtor)||

### <a name="public-methods"></a>Métodos públicos

|Nome|DESCRIÇÃO|
|----------|-----------------|
|[deregister_callback](#deregister_callback)|Remove um retorno de chamada registrado anteriormente por meio do método `register` com base no objeto `cancellation_token_registration` retornado no momento do registro.|
|[is_cancelable](#is_cancelable)|Retorna uma indicação de se esse token pode ser cancelado ou não.|
|[is_canceled](#is_canceled)|Retornará **true** se o token tiver sido cancelado.|
|[nenhum](#none)|Retorna um token de cancelamento que nunca pode estar sujeito ao cancelamento.|
|[register_callback](#register_callback)|Registra uma função de retorno de chamada com o token. Se e quando o token for cancelado, o retorno de chamada será feito. Observe que, se o token já estiver cancelado no ponto em que esse método é chamado, o retorno de chamada será feito imediatamente e de forma síncrona.|

### <a name="public-operators"></a>Operadores públicos

|Nome|DESCRIÇÃO|
|----------|-----------------|
|[operator!=](#operator_neq)||
|[operator=](#operator_eq)||
|[operator==](#operator_eq_eq)||

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

`cancellation_token`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** pplcancellation_token. h

**Namespace:** simultaneidade

## <a name="dtor"></a>~ cancellation_token

```cpp
~cancellation_token();
```

## <a name="ctor"></a>cancellation_token

```cpp
cancellation_token(const cancellation_token& _Src);

cancellation_token(cancellation_token&& _Src);
```

### <a name="parameters"></a>parâmetros

*_Src*<br/>
O cancellation_token a ser copiado ou movido.

## <a name="deregister_callback"></a>deregister_callback

Remove um retorno de chamada registrado anteriormente por meio do método `register` com base no objeto `cancellation_token_registration` retornado no momento do registro.

```cpp
void deregister_callback(const cancellation_token_registration& _Registration) const;
```

### <a name="parameters"></a>parâmetros

*_Registration*<br/>
O objeto `cancellation_token_registration` correspondente ao retorno de chamada a ser cancelado. Esse token deve ter sido retornado anteriormente de uma chamada para o método `register`.

## <a name="is_cancelable"></a>is_cancelable

Retorna uma indicação de se esse token pode ser cancelado ou não.

```cpp
bool is_cancelable() const;
```

### <a name="return-value"></a>Valor retornado

Uma indicação de se esse token pode ser cancelado ou não.

## <a name="is_canceled"></a>is_canceled

Retornará **true** se o token tiver sido cancelado.

```cpp
bool is_canceled() const;
```

### <a name="return-value"></a>Valor retornado

O valor **true** se o token tiver sido cancelado; caso contrário, o valor **false**.

## <a name="none"></a>None

Retorna um token de cancelamento que nunca pode estar sujeito ao cancelamento.

```cpp
static cancellation_token none();
```

### <a name="return-value"></a>Valor retornado

Um token de cancelamento que não pode ser cancelado.

## <a name="operator_neq"></a>operador! =

```cpp
bool operator!= (const cancellation_token& _Src) const;
```

### <a name="parameters"></a>parâmetros

*_Src*<br/>
O `cancellation_token` a ser comparado.

### <a name="return-value"></a>Valor retornado

## <a name="operator_eq"></a>operador =

```cpp
cancellation_token& operator= (const cancellation_token& _Src);

cancellation_token& operator= (cancellation_token&& _Src);
```

### <a name="parameters"></a>parâmetros

*_Src*<br/>
O `cancellation_token` a ser atribuído.

### <a name="return-value"></a>Valor retornado

## <a name="operator_eq_eq"></a>operador = =

```cpp
bool operator== (const cancellation_token& _Src) const;
```

### <a name="parameters"></a>parâmetros

*_Src*<br/>
O `cancellation_token` a ser comparado.

### <a name="return-value"></a>Valor retornado

## <a name="register_callback"></a>register_callback

Registra uma função de retorno de chamada com o token. Se e quando o token for cancelado, o retorno de chamada será feito. Observe que, se o token já estiver cancelado no ponto em que esse método é chamado, o retorno de chamada será feito imediatamente e de forma síncrona.

```cpp
template<typename _Function>
::Concurrency::cancellation_token_registration register_callback(const _Function& _Func) const;
```

### <a name="parameters"></a>parâmetros

*_Function*<br/>
O tipo do objeto de função que será chamado novamente quando este `cancellation_token` for cancelado.

*_Func*<br/>
O objeto de função que será chamado de volta quando este `cancellation_token` for cancelado.

### <a name="return-value"></a>Valor retornado

Um objeto `cancellation_token_registration` que pode ser utilizado no método `deregister` para cancelar o registro de um retorno de chamada previamente registrado e impedir que ele seja feito. O método gerará uma exceção [invalid_operation](invalid-operation-class.md) se for chamado em um objeto `cancellation_token` que foi criado usando o método [cancellation_token:: None](#none) .

## <a name="see-also"></a>Confira também

[Namespace de simultaneidade](concurrency-namespace.md)
