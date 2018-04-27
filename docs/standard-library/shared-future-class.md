---
title: Classe shared_future | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.reviewer: ''
ms.suite: ''
ms.technology:
- cpp-standard-libraries
ms.tgt_pltfrm: ''
ms.topic: reference
f1_keywords:
- future/std::shared_future
- future/std::shared_future::shared_future
- future/std::shared_future::get
- future/std::shared_future::valid
- future/std::shared_future::wait
- future/std::shared_future::wait_for
- future/std::shared_future::wait_until
dev_langs:
- C++
ms.assetid: 454ebedd-f42b-405f-99a5-a25cc9ad7c90
caps.latest.revision: 13
author: corob-msft
ms.author: corob
manager: ghogen
helpviewer_keywords:
- std::shared_future [C++]
- std::shared_future [C++], shared_future
- std::shared_future [C++], get
- std::shared_future [C++], valid
- std::shared_future [C++], wait
- std::shared_future [C++], wait_for
- std::shared_future [C++], wait_until
ms.workload:
- cplusplus
ms.openlocfilehash: 7f022d48dcd5cbc8afa1b9d3100cd27c2ad12175
ms.sourcegitcommit: dd1a509526fa8bb18e97ab7bc7b91cbdb3ec7059
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/26/2018
---
# <a name="sharedfuture-class"></a>Classe shared_future

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

### <a name="public-constructors"></a>Construtores Públicos

|Nome|Descrição|
|----------|-----------------|
|[shared_future](#shared_future)|Constrói um objeto `shared_future`.|

### <a name="public-methods"></a>Métodos Públicos

|Nome|Descrição|
|----------|-----------------|
|[get](#get)|Recupera o resultado armazenado no *estado assíncrono associado*.|
|[valid](#valid)|Especifica se o objeto não está vazio.|
|[wait](#wait)|Bloqueia o thread atual até que o estado assíncrono associado esteja pronto.|
|[wait_for](#wait_for)|Bloqueia até que o estado assíncrono associado esteja pronto ou até que o tempo especificado tenha decorrido.|
|[wait_until](#wait_until)|Bloqueia até que o estado assíncrono associado esteja pronto ou até um ponto no tempo especificado.|

### <a name="public-operators"></a>Operadores públicos

|Nome|Descrição|
|----------|-----------------|
|[shared_future::operator=](#op_eq)|Atribui um novo estado assíncrono associado.|

## <a name="requirements"></a>Requisitos

**Cabeçalho:** \<futuro >

**Namespace:** std

## <a name="get"></a>  shared_future::get

Recupera o resultado armazenado no *estado assíncrono associado*.

```cpp
const Ty& get() const;

Ty& get() const;

void get() const;
```

### <a name="remarks"></a>Comentários

Se o resultado for uma exceção, o método a gerará novamente. Caso contrário, o resultado será retornado.

Antes de recuperar o resultado, este método bloqueia o thread atual até que o estado assíncrono associado esteja pronto.

Para a especialização parcial `shared_future<Ty&>`, o valor armazenado será efetivamente uma referência ao objeto que foi passado para o *provedor assíncrono* como o valor retornado.

Como não existe nenhum valor armazenado para a especialização `shared_future<void>`, o método retorna `void`.

## <a name="op_eq"></a>  shared_future::operator=

Transfere o *estado assíncrono associado* de um objeto especificado.

```cpp
shared_future& operator=(shared_future&& Right) noexcept;
shared_future& operator=(const shared_future& Right);
```

### <a name="parameters"></a>Parâmetros

`Right` Um `shared_future` objeto.

### <a name="return-value"></a>Valor de retorno

`*this`

### <a name="remarks"></a>Comentários

Para o primeiro operador, `Right` não tem mais um estado assíncrono associado após a operação.

Para o segundo método, `Right` mantém seu estado assíncrono associado.

## <a name="shared_future"></a> Construtor shared_future::shared_future

Constrói um objeto `shared_future`.

```cpp
shared_future() noexcept;
shared_future(future<Ty>&& Right) noexcept;
shared_future(shared_future&& Right) noexcept;
shared_future(const shared_future& Right);
```

### <a name="parameters"></a>Parâmetros

`Right` Um [futuros](../standard-library/future-class.md) ou `shared_future` objeto.

### <a name="remarks"></a>Comentários

O primeiro construtor cria um objeto `shared_future` que não tem nenhum *estado assíncrono associado*.

O segundo e terceiro construtores criam um objeto `shared_future` e transferem o estado assíncrono associado de `Right`. `Right` não tem mais um estado assíncrono associado.

O quarto construtor cria um objeto `shared_future` que tem o mesmo estado assíncrono associado que `Right`.

## <a name="valid"></a>  shared_future:: valid

Especifica se o objeto tem um *estado assíncrono associado*.

```cpp
bool valid() noexcept;
```

### <a name="return-value"></a>Valor de retorno

`true` se o objeto tiver um estado assíncrono associado; caso contrário, `false`.

## <a name="wait"></a>  shared_future:: wait

Bloqueia o thread atual até que o *estado assíncrono associado* esteja *pronto*.

```cpp
void wait() const;
```

### <a name="remarks"></a>Comentários

Um estado assíncrono associado ficará pronto somente se seu provedor assíncrono tiver armazenado um valor retornado ou armazenado uma exceção.

## <a name="wait_for"></a>  shared_future::wait_for

Bloqueia o thread atual até que o estado assíncrono associado seja *ready* ou até que o intervalo de tempo especificado tenha decorrido.

```cpp
template <class Rep, class Period>
future_status wait_for(
    const chrono::duration<Rep, Period>& Rel_time) const;
```

### <a name="parameters"></a>Parâmetros

`Rel_time` Um [chrono::duration](../standard-library/duration-class.md) objeto que especifica um intervalo de tempo máximo que os blocos de thread.

### <a name="return-value"></a>Valor de retorno

Um [future_status](../standard-library/future-enums.md#future_status) que indica o motivo do retorno.

### <a name="remarks"></a>Comentários

Um estado assíncrono associado ficará *pronto* somente se seu provedor assíncrono tiver armazenado um valor retornado ou armazenado uma exceção.

## <a name="wait_until"></a>  shared_future::wait_until

Bloqueia o thread atual até que o estado assíncrono associado esteja *pronto* ou após um determinado ponto no tempo.

```cpp
template <class Clock, class Duration>
future_status wait_until(
    const chrono::time_point<Clock, Duration>& Abs_time) const;
```

### <a name="parameters"></a>Parâmetros

`Abs_time` Um [chrono::time_point](../standard-library/time-point-class.md) objeto que especifica uma hora após o qual o thread pode desbloquear.

### <a name="return-value"></a>Valor de retorno

Um [future_status](../standard-library/future-enums.md#future_status) que indica o motivo do retorno.

### <a name="remarks"></a>Comentários

Um estado assíncrono associado ficará pronto somente se seu provedor assíncrono tiver armazenado um valor retornado ou armazenado uma exceção.

## <a name="see-also"></a>Consulte também

[Referência de Arquivos de Cabeçalho](../standard-library/cpp-standard-library-header-files.md)<br/>
[\<future>](../standard-library/future.md)<br/>
