---
title: Classe cancellation_token_source
ms.date: 11/04/2016
f1_keywords:
- cancellation_token_source
- PPLCANCELLATION_TOKEN/concurrency::cancellation_token_source
- PPLCANCELLATION_TOKEN/concurrency::cancellation_token_source::cancellation_token_source
- PPLCANCELLATION_TOKEN/concurrency::cancellation_token_source::cancel
- PPLCANCELLATION_TOKEN/concurrency::cancellation_token_source::create_linked_source
- PPLCANCELLATION_TOKEN/concurrency::cancellation_token_source::get_token
helpviewer_keywords:
- cancellation_token_source class
ms.assetid: 3548b1a0-12b0-4334-95db-4bf57141c066
ms.openlocfilehash: 131c4155ad902221d14f90f750f89c31479e2067
ms.sourcegitcommit: a8ef52ff4a4944a1a257bdaba1a3331607fb8d0f
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 02/11/2020
ms.locfileid: "77142225"
---
# <a name="cancellation_token_source-class"></a>Classe cancellation_token_source

A classe `cancellation_token_source` representa a capacidade de cancelar algumas operações canceláveis.

## <a name="syntax"></a>Sintaxe

```cpp
class cancellation_token_source;
```

## <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores públicos

|{1&gt;Nome&lt;1}|Descrição|
|----------|-----------------|
|[cancellation_token_source](#ctor)|Sobrecarregado. Constrói um novo `cancellation_token_source`. A origem pode ser usada para sinalizar o cancelamento de alguma operação cancelável.|
|[~ cancellation_token_source destruidor](#dtor)||

### <a name="public-methods"></a>Métodos públicos

|{1&gt;Nome&lt;1}|Descrição|
|----------|-----------------|
|[cancel](#cancel)|Cancela o token. Qualquer `task_group`, `structured_task_group`ou `task` que utilize o token será cancelado após essa chamada e lançará uma exceção no próximo ponto de interrupção.|
|[create_linked_source](#create_linked_source)|Sobrecarregado. Cria um `cancellation_token_source` que é cancelado quando o token fornecido é cancelado.|
|[get_token](#get_token)|Retorna um token de cancelamento associado a essa fonte. O token retornado pode ser sondado para cancelamento ou fornecer um retorno de chamada se e quando o cancelamento ocorrer.|

### <a name="public-operators"></a>Operadores públicos

|{1&gt;Nome&lt;1}|Descrição|
|----------|-----------------|
|[operator!=](#operator_neq)||
|[operator=](#operator_eq)||
|[operator==](#operator_eq_eq)||

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

`cancellation_token_source`

## <a name="requirements"></a>{1&gt;{2&gt;Requisitos&lt;2}&lt;1}

**Cabeçalho:** pplcancellation_token. h

**Namespace:** simultaneidade

## <a name="dtor"></a>~ cancellation_token_source

```cpp
~cancellation_token_source();
```

## <a name="cancel"></a>Cancelar

Cancela o token. Qualquer `task_group`, `structured_task_group`ou `task` que utilize o token será cancelado após essa chamada e lançará uma exceção no próximo ponto de interrupção.

```cpp
void cancel() const;
```

## <a name="ctor"></a>cancellation_token_source

Constrói um novo `cancellation_token_source`. A origem pode ser usada para sinalizar o cancelamento de alguma operação cancelável.

```cpp
cancellation_token_source();

cancellation_token_source(const cancellation_token_source& _Src);

cancellation_token_source(cancellation_token_source&& _Src);
```

### <a name="parameters"></a>Parâmetros

*_Src*<br/>
Objeto a ser copiado ou movido.

## <a name="create_linked_source"></a>create_linked_source

Cria um `cancellation_token_source` que é cancelado quando o token fornecido é cancelado.

```cpp
static cancellation_token_source create_linked_source(
    cancellation_token& _Src);

template<typename _Iter>
static cancellation_token_source create_linked_source(_Iter _Begin, _Iter _End);
```

### <a name="parameters"></a>Parâmetros

*_Iter*<br/>
Tipo de iterador.

*_Src*<br/>
Um token cujo cancelamento causará o cancelamento da origem do token retornado. Observe que a origem do token retornado também pode ser cancelada independentemente da origem contida nesse parâmetro.

*_Begin*<br/>
O C++ iterador de biblioteca padrão correspondente ao início do intervalo de tokens para escutar o cancelamento de.

*_End*<br/>
O C++ iterador de biblioteca padrão que corresponde ao final do intervalo de tokens para escutar o cancelamento de.

### <a name="return-value"></a>Valor retornado

Um `cancellation_token_source` que é cancelado quando o token fornecido pelo parâmetro `_Src` é cancelado.

## <a name="get_token"></a>get_token

Retorna um token de cancelamento associado a essa fonte. O token retornado pode ser sondado para cancelamento ou fornecer um retorno de chamada se e quando o cancelamento ocorrer.

```cpp
cancellation_token get_token() const;
```

### <a name="return-value"></a>Valor retornado

Um token de cancelamento associado a essa fonte.

## <a name="operator_neq"></a>operador! =

```cpp
bool operator!= (const cancellation_token_source& _Src) const;
```

### <a name="parameters"></a>Parâmetros

*_Src*<br/>
Ocorre.

### <a name="return-value"></a>Valor retornado

## <a name="operator_eq"></a>operador =

```cpp
cancellation_token_source& operator= (const cancellation_token_source& _Src);

cancellation_token_source& operator= (cancellation_token_source&& _Src);
```

### <a name="parameters"></a>Parâmetros

*_Src*<br/>
Ocorre.

### <a name="return-value"></a>Valor retornado

## <a name="operator_eq_eq"></a>operador = =

```cpp
bool operator== (const cancellation_token_source& _Src) const;
```

### <a name="parameters"></a>Parâmetros

*_Src*<br/>
Ocorre.

### <a name="return-value"></a>Valor retornado

## <a name="see-also"></a>Consulte também

[Namespace de simultaneidade](concurrency-namespace.md)
