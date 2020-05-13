---
title: Classe shared_future
ms.date: 11/04/2016
f1_keywords:
- future/std::shared_future
- future/std::shared_future::shared_future
- future/std::shared_future::get
- future/std::shared_future::valid
- future/std::shared_future::wait
- future/std::shared_future::wait_for
- future/std::shared_future::wait_until
ms.assetid: 454ebedd-f42b-405f-99a5-a25cc9ad7c90
helpviewer_keywords:
- std::shared_future [C++]
- std::shared_future [C++], shared_future
- std::shared_future [C++], get
- std::shared_future [C++], valid
- std::shared_future [C++], wait
- std::shared_future [C++], wait_for
- std::shared_future [C++], wait_until
ms.openlocfilehash: 65ea01a9ced1ca69cd1b1526e7594c4b54387553
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81336775"
---
# <a name="shared_future-class"></a>Classe shared_future

Descreve um *objeto de retorno assíncrono*. Diferente de um objeto [future](../standard-library/future-class.md), um *provedor assíncrono* pode ser associado a qualquer quantidade de objetos `shared_future`.

## <a name="syntax"></a>Sintaxe

```cpp
template <class Ty>
class shared_future;
```

## <a name="remarks"></a>Comentários

Não chame nenhum método diferente de `valid`, `operator=` e o destruidor em um objeto `shared_future` que seja *vazio*.

Objetos `shared_future` não estão sincronizados. Chamar métodos no mesmo objeto de vários threads gera uma corrida de dados com resultados imprevisíveis.

## <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores públicos

|Nome|Descrição|
|----------|-----------------|
|[shared_future](#shared_future)|Constrói um objeto `shared_future`.|

### <a name="public-methods"></a>Métodos públicos

|Nome|Descrição|
|----------|-----------------|
|[get](#get)|Recupera o resultado armazenado no *estado assíncrono associado*.|
|[Válido](#valid)|Especifica se o objeto não está vazio.|
|[Esperar](#wait)|Bloqueia o thread atual até que o estado assíncrono associado esteja pronto.|
|[wait_for](#wait_for)|Bloqueia até que o estado assíncrono associado esteja pronto ou até que o tempo especificado tenha decorrido.|
|[wait_until](#wait_until)|Bloqueia até que o estado assíncrono associado esteja pronto ou até um ponto no tempo especificado.|

### <a name="public-operators"></a>Operadores públicos

|Nome|Descrição|
|----------|-----------------|
|[shared_future::operator=](#op_eq)|Atribui um novo estado assíncrono associado.|

## <a name="requirements"></a>Requisitos

**Cabeçalho:** \<> futuro

**Namespace:** std

## <a name="shared_futureget"></a><a name="get"></a>shared_future::get

Recupera o resultado armazenado no *estado assíncrono associado*.

```cpp
const Ty& get() const;

Ty& get() const;

void get() const;
```

### <a name="remarks"></a>Comentários

Se o resultado for uma exceção, o método a gerará novamente. Caso contrário, o resultado será retornado.

Antes de recuperar o resultado, este método bloqueia o thread atual até que o estado assíncrono associado esteja pronto.

Para a especialização `shared_future<Ty&>`parcial, o valor armazenado é efetivamente uma referência ao objeto que foi passado ao provedor *assíncrono* como o valor de retorno.

Como não existe valor armazenado `shared_future<void>`para a especialização, o método retorna **vazio**.

## <a name="shared_futureoperator"></a><a name="op_eq"></a>shared_future:operador=

Transfere um *estado assíncrono associado* de um objeto especificado.

```cpp
shared_future& operator=(shared_future&& Right) noexcept;
shared_future& operator=(const shared_future& Right);
```

### <a name="parameters"></a>Parâmetros

*Certo*\
Um objeto `shared_future` .

### <a name="return-value"></a>Valor retornado

`*this`

### <a name="remarks"></a>Comentários

Para o primeiro operador, *a Right* não tem mais um estado assíncrono associado após a operação.

Para o segundo método, *right* mantém seu estado assíncrono associado.

## <a name="shared_futureshared_future-constructor"></a><a name="shared_future"></a>shared_future:shared_future Construtor

Constrói um objeto `shared_future`.

```cpp
shared_future() noexcept;
shared_future(future<Ty>&& Right) noexcept;
shared_future(shared_future&& Right) noexcept;
shared_future(const shared_future& Right);
```

### <a name="parameters"></a>Parâmetros

*Certo*\
Um objeto [future](../standard-library/future-class.md) ou `shared_future`.

### <a name="remarks"></a>Comentários

O primeiro construtor constrói `shared_future` um objeto que não tem *estado assíncrono associado.*

O segundo e terceiro construtores constroem um `shared_future` objeto e transferem o estado assíncrono associado da *Direita*. *A direita* não tem mais um estado assíncrono associado.

O quarto construtor constrói `shared_future` um objeto que tem o mesmo estado assíncrono associado que *o Direito*.

## <a name="shared_futurevalid"></a><a name="valid"></a>shared_future::válido

Especifica se o objeto tem um *estado assíncrono associado*.

```cpp
bool valid() noexcept;
```

### <a name="return-value"></a>Valor retornado

**verdade** se o objeto tem um estado assíncrono associado; caso contrário, **falso**.

## <a name="shared_futurewait"></a><a name="wait"></a>shared_future::espere

Bloqueia a rosca atual até que o *estado assíncrono associado* esteja *pronto*.

```cpp
void wait() const;
```

### <a name="remarks"></a>Comentários

Um estado assíncrono associado ficará pronto somente se seu provedor assíncrono tiver armazenado um valor retornado ou armazenado uma exceção.

## <a name="shared_futurewait_for"></a><a name="wait_for"></a>shared_future:wait_for

Bloqueia o thread atual até que o estado assíncrono associado seja *ready* ou até que o intervalo de tempo especificado tenha decorrido.

```cpp
template <class Rep, class Period>
future_status wait_for(
    const chrono::duration<Rep, Period>& Rel_time) const;
```

### <a name="parameters"></a>Parâmetros

*Rel_time*\
Um objeto [chrono::duration](../standard-library/duration-class.md) que especifica um intervalo de tempo máximo durante o qual o thread fica bloqueado.

### <a name="return-value"></a>Valor retornado

Um [future_status](../standard-library/future-enums.md#future_status) que indica o motivo do retorno.

### <a name="remarks"></a>Comentários

Um estado assíncrono associado só está *pronto* se seu provedor assíncrono tiver armazenado um valor de retorno ou armazenado uma exceção.

## <a name="shared_futurewait_until"></a><a name="wait_until"></a>shared_future:wait_until

Bloqueia o thread atual até que o estado assíncrono associado esteja *pronto* ou após um determinado ponto no tempo.

```cpp
template <class Clock, class Duration>
future_status wait_until(
    const chrono::time_point<Clock, Duration>& Abs_time) const;
```

### <a name="parameters"></a>Parâmetros

*Abs_time*\
Um objeto [chrono::time_point](../standard-library/time-point-class.md) que especifica um tempo após o qual o thread pode ser desbloqueado.

### <a name="return-value"></a>Valor retornado

Um [future_status](../standard-library/future-enums.md#future_status) que indica o motivo do retorno.

### <a name="remarks"></a>Comentários

Um estado assíncrono associado ficará pronto somente se seu provedor assíncrono tiver armazenado um valor retornado ou armazenado uma exceção.

## <a name="see-also"></a>Confira também

[Referência de arquivos de cabeçalho](../standard-library/cpp-standard-library-header-files.md)\
[\<>futuros](../standard-library/future.md)
