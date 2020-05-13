---
title: Classe future
ms.date: 11/04/2016
f1_keywords:
- future/std::future
- future/std::future::future
- future/std::future::get
- future/std::future::share
- future/std::future::valid
- future/std::future::wait
- future/std::future::wait_for
- future/std::future::wait_until
ms.assetid: 495e82c3-5341-4e37-87dd-b40107fbdfb6
helpviewer_keywords:
- std::future [C++]
- std::future [C++], future
- std::future [C++], get
- std::future [C++], share
- std::future [C++], valid
- std::future [C++], wait
- std::future [C++], wait_for
- std::future [C++], wait_until
ms.openlocfilehash: e71c750ddeb198faa3ae9c5960b2668c376241ed
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81370710"
---
# <a name="future-class"></a>Classe future

Descreve um *objeto de retorno assíncrono*.

## <a name="syntax"></a>Sintaxe

```cpp
template <class Ty>
class future;
```

## <a name="remarks"></a>Comentários

Cada *provedor assíncrono* padrão retorna um objeto cujo tipo é uma instanciação desse modelo. Um objeto `future` fornece apenas o acesso ao provedor assíncrono ao qual está associado. Se precisar de vários objetos de retorno assíncronos associados ao mesmo provedor assíncrono, copie o objeto `future` para um objeto [shared_future](../standard-library/shared-future-class.md).

## <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores públicos

|Nome|Descrição|
|----------|-----------------|
|[Futuro](#future)|Constrói um objeto `future`.|

### <a name="public-methods"></a>Métodos públicos

|Nome|Descrição|
|----------|-----------------|
|[get](#get)|Recupera o resultado armazenado no estado assíncrono associado.|
|[compartilhar](#share)|Converte o objeto em um `shared_future`.|
|[Válido](#valid)|Especifica se o objeto não está vazio.|
|[Esperar](#wait)|Bloqueia o thread atual até que o estado assíncrono associado esteja pronto.|
|[wait_for](#wait_for)|Bloqueia até que o estado assíncrono associado esteja pronto ou até que o tempo especificado tenha decorrido.|
|[wait_until](#wait_until)|Bloqueia até que o estado assíncrono associado esteja pronto ou até um ponto no tempo especificado.|

### <a name="public-operators"></a>Operadores públicos

|Nome|Descrição|
|----------|-----------------|
|[future::operator=](#op_eq)|Transfere o estado assíncrono associado de um objeto especificado.|

## <a name="requirements"></a>Requisitos

**Cabeçalho:** \<> futuro

**Namespace:** std

## <a name="futurefuture-constructor"></a><a name="future"></a>futuro::futuro Construtor

Constrói um objeto `future`.

```cpp
future() noexcept;
future(future&& Other) noexcept;
```

### <a name="parameters"></a>Parâmetros

*Outros*\
Um objeto `future` .

### <a name="remarks"></a>Comentários

O primeiro construtor cria um objeto `future` que não tem nenhum estado assíncrono associado.

O segundo construtor constrói `future` um objeto e transfere o estado assíncrono associado de *Outro*. *Outros* não têm mais um estado assíncrono associado.

## <a name="futureget"></a><a name="get"></a>futuro::get

Recupera o resultado armazenado no estado assíncrono associado.

```cpp
Ty get();
```

### <a name="return-value"></a>Valor retornado

Se o resultado for uma exceção, o método a gerará novamente. Caso contrário, o resultado será retornado.

### <a name="remarks"></a>Comentários

Antes de recuperar o resultado, este método bloqueia o thread atual até que o estado assíncrono associado esteja pronto.

Para a especialização parcial `future<Ty&>`, o valor armazenado será efetivamente uma referência ao objeto que foi passado para o provedor assíncrono como o valor retornado.

Como não existe valor armazenado `future<void>`para a especialização, o método retorna **vazio**.

Em outras especializações, o método move seu valor retornado do valor armazenado. Portanto, chame este método apenas uma vez.

## <a name="futureoperator"></a><a name="op_eq"></a>futuro::operador=

Transfere o estado assíncrono associado de um objeto especificado.

```cpp
future& operator=(future&& Right) noexcept;
```

### <a name="parameters"></a>Parâmetros

*Certo*\
Um objeto `future` .

### <a name="return-value"></a>Valor retornado

`*this`

### <a name="remarks"></a>Comentários

Após a transferência, *right* não tem mais um estado assíncrono associado.

## <a name="futureshare"></a><a name="share"></a>futuro::compartilhar

Converte o objeto em um objeto [shared_future](../standard-library/shared-future-class.md).

```cpp
shared_future<Ty> share();
```

### <a name="return-value"></a>Valor retornado

`shared_future(move(*this))`

## <a name="futurevalid"></a><a name="valid"></a>futuro::válido

Especifica se o objeto tem um estado assíncrono associado.

```cpp
bool valid() noexcept;
```

### <a name="return-value"></a>Valor retornado

**verdade** se o objeto tem um estado assíncrono associado; caso contrário, **falso**.

## <a name="futurewait"></a><a name="wait"></a>futuro::espere

Bloqueia o thread atual até que o estado assíncrono associado esteja *pronto*.

```cpp
void wait() const;
```

### <a name="remarks"></a>Comentários

Um estado assíncrono associado só está *pronto* se seu provedor assíncrono tiver armazenado um valor de retorno ou armazenado uma exceção.

## <a name="futurewait_for"></a><a name="wait_for"></a>futuro::wait_for

Bloqueia o thread atual até que o estado assíncrono associado esteja *pronto* ou até que o intervalo de tempo especificado tenha decorrido.

```cpp
template <class Rep, class Period>
future_status wait_for(const chrono::duration<Rep, Period>& Rel_time) const;
```

### <a name="parameters"></a>Parâmetros

*Rel_time*\
Um objeto [chrono::duration](../standard-library/duration-class.md) que especifica um intervalo de tempo máximo durante o qual o thread fica bloqueado.

### <a name="return-value"></a>Valor retornado

Um [future_status](../standard-library/future-enums.md#future_status) que indica o motivo do retorno.

### <a name="remarks"></a>Comentários

Um estado assíncrono associado ficará pronto somente se seu provedor assíncrono tiver armazenado um valor retornado ou armazenado uma exceção.

## <a name="futurewait_until"></a><a name="wait_until"></a>futuro::wait_until

Bloqueia o thread atual até que o estado assíncrono associado esteja *pronto* ou após um determinado ponto no tempo.

```cpp
template <class Clock, class Duration>
future_status wait_until(const chrono::time_point<Clock, Duration>& Abs_time) const;
```

### <a name="parameters"></a>Parâmetros

*Abs_time*\
Um objeto [chrono::time_point](../standard-library/time-point-class.md) que especifica um tempo após o qual o thread pode ser desbloqueado.

### <a name="return-value"></a>Valor retornado

Um [future_status](../standard-library/future-enums.md#future_status) que indica o motivo do retorno.

### <a name="remarks"></a>Comentários

Um estado assíncrono associado só está *pronto* se seu provedor assíncrono tiver armazenado um valor de retorno ou armazenado uma exceção.

## <a name="see-also"></a>Confira também

[Referência de arquivos de cabeçalho](../standard-library/cpp-standard-library-header-files.md)\
[\<>futuros](../standard-library/future.md)
