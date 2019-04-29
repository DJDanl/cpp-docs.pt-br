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
ms.openlocfilehash: 23821c91cd4158f6ec3989cdf537a5d8067e8225
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62337512"
---
# <a name="cancellationtoken-class"></a>Classe cancellation_token

O `cancellation_token` classe representa a capacidade de determinar se alguma operação foi solicitada para cancelar. Um token determinado pode ser associado com um `task_group`, `structured_task_group`, ou `task` para fornecer cancelamento implícito. Ele também pode ser pesquisado para cancelamento ou ter um retorno de chamada registrado para se e quando associado `cancellation_token_source` é cancelada.

## <a name="syntax"></a>Sintaxe

```
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
|[deregister_callback](#deregister_callback)|Remove um retorno de chamada registrado anteriormente por meio de `register` método com base no `cancellation_token_registration` objeto retornado no momento do registro.|
|[is_cancelable](#is_cancelable)|Retorna um valor que indica se este token pode ser cancelado ou não.|
|[is_canceled](#is_canceled)|Retorna **verdadeira** se o token foi cancelado.|
|[none](#none)|Retorna um token de cancelamento que nunca pode estar sujeitos a cancelamento.|
|[register_callback](#register_callback)|Registra uma função de retorno de chamada com o token. Se e quando o token é cancelado, o retorno de chamada será feito. Observe que, se o token já tiver sido cancelado no ponto em que esse método é chamado, o retorno de chamada será feito imediatamente e de forma síncrona.|

### <a name="public-operators"></a>Operadores públicos

|Nome|Descrição|
|----------|-----------------|
|[operator!=](#operator_neq)||
|[operator=](#operator_eq)||
|[operator==](#operator_eq_eq)||

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

`cancellation_token`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** pplcancellation_token. h

**Namespace:** simultaneidade

##  <a name="dtor"></a> ~cancellation_token

```
~cancellation_token();
```

##  <a name="ctor"></a> cancellation_token

```
cancellation_token(const cancellation_token& _Src);

cancellation_token(cancellation_token&& _Src);
```

### <a name="parameters"></a>Parâmetros

*_Src*<br/>
Cancellation_token a ser copiado ou movido.

##  <a name="deregister_callback"></a> deregister_callback

Remove um retorno de chamada registrado anteriormente por meio de `register` método com base no `cancellation_token_registration` objeto retornado no momento do registro.

```
void deregister_callback(const cancellation_token_registration& _Registration) const;
```

### <a name="parameters"></a>Parâmetros

*_Registration*<br/>
O `cancellation_token_registration` objeto correspondente para o retorno de chamada a ser cancelado. Esse token deve ter sido retornado de uma chamada para o `register` método.

##  <a name="is_cancelable"></a> is_cancelable

Retorna um valor que indica se este token pode ser cancelado ou não.

```
bool is_cancelable() const;
```

### <a name="return-value"></a>Valor de retorno

Uma indicação se este token pode ser cancelado ou não.

##  <a name="is_canceled"></a> is_canceled

Retorna **verdadeira** se o token foi cancelado.

```
bool is_canceled() const;
```

### <a name="return-value"></a>Valor de retorno

O valor **verdadeira** se o token tiver sido cancelada; caso contrário, o valor **falso**.

##  <a name="none"></a> None

Retorna um token de cancelamento que nunca pode estar sujeitos a cancelamento.

```
static cancellation_token none();
```

### <a name="return-value"></a>Valor de retorno

Um token de cancelamento que não pode ser cancelado.

##  <a name="operator_neq"></a> operador! =

```
bool operator!= (const cancellation_token& _Src) const;
```

### <a name="parameters"></a>Parâmetros

*_Src*<br/>
O `cancellation_token` de comparação.

### <a name="return-value"></a>Valor de retorno

##  <a name="operator_eq"></a> operator=

```
cancellation_token& operator= (const cancellation_token& _Src);

cancellation_token& operator= (cancellation_token&& _Src);
```

### <a name="parameters"></a>Parâmetros

*_Src*<br/>
O `cancellation_token` atribuir.

### <a name="return-value"></a>Valor de retorno

##  <a name="operator_eq_eq"></a> operator==

```
bool operator== (const cancellation_token& _Src) const;
```

### <a name="parameters"></a>Parâmetros

*_Src*<br/>
O `cancellation_token` de comparação.

### <a name="return-value"></a>Valor de retorno

##  <a name="register_callback"></a> register_callback

Registra uma função de retorno de chamada com o token. Se e quando o token é cancelado, o retorno de chamada será feito. Observe que, se o token já tiver sido cancelado no ponto em que esse método é chamado, o retorno de chamada será feito imediatamente e de forma síncrona.

```
template<typename _Function>
::Concurrency::cancellation_token_registration register_callback(const _Function& _Func) const;
```

### <a name="parameters"></a>Parâmetros

*_Function*<br/>
O tipo do objeto de função que será chamado quando este `cancellation_token` é cancelada.

*_Func*<br/>
O objeto de função que será chamado quando este `cancellation_token` é cancelada.

### <a name="return-value"></a>Valor de retorno

Um `cancellation_token_registration` objeto que pode ser utilizado no `deregister` método para cancelar o registro de um retorno de chamada registrado anteriormente e impedir que ele está sendo feita. O método gerará uma [invalid_operation](invalid-operation-class.md) exceção se ele for chamado em um `cancellation_token` objeto que foi criado usando o [cancellation_token:: none](#none) método.

## <a name="see-also"></a>Consulte também

[Namespace de simultaneidade](concurrency-namespace.md)
