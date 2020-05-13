---
title: Estrutura system_clock
ms.date: 11/04/2016
f1_keywords:
- chrono/std::chrono::system_clock
- chrono/std::chrono::system_clock::from_time_t
- chrono/std::chrono::system_clock::now
- chrono/std::chrono::system_clock::to_time_t
- chrono/std::chrono::system_clock::is_monotonic Constant
- chrono/std::chrono::system_clock::is_steady Constant
ms.assetid: a97bd46e-267a-4836-9f7d-af1f664e99ae
ms.openlocfilehash: ca516551bb1b41d96b99aaf7b842666c9341ee7d
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81376520"
---
# <a name="system_clock-structure"></a>Estrutura system_clock

Representa um *tipo de relógio* baseado no relógio em tempo real do sistema.

## <a name="syntax"></a>Sintaxe

```cpp
struct system_clock;
```

## <a name="remarks"></a>Comentários

Um *tipo de relógio* é usado para obter a hora atual como UTC. O tipo incorpora uma instanciação de [duration](../standard-library/duration-class.md) e o modelo de classe [time_point](../standard-library/time-point-class.md) e define uma função membro estática `now()` que retorna a hora.

Um relógio será *monotônico* se o valor retornado por uma primeira chamada a `now()` for sempre menor ou igual ao valor retornado por uma chamada posterior a `now()`.

Um relógio será *estável* se ele for *monotônico* e se o tempo entre os tiques do relógio for constante.

## <a name="members"></a>Membros

### <a name="public-typedefs"></a>Typedefs públicos

|Nome|Descrição|
|----------|-----------------|
|`system_clock::duration`|Um sinônimo de `duration<rep, period>`.|
|`system_clock::period`|Um sinônimo do tipo que é usado para representar o período de tiques na instanciação independente de `duration`.|
|`system_clock::rep`|Um sinônimo do tipo que é usado para representar o número de tiques do relógio na instanciação independente de `duration`.|
|`system_clock::time_point`|Um sinônimo de `time_point<Clock, duration>`, em que `Clock` é um sinônimo do próprio tipo de relógio ou de outro tipo de relógio que se baseia na mesma época e que tem o mesmo tipo `duration` aninhado.|

### <a name="public-methods"></a>Métodos públicos

|Nome|Descrição|
|----------|-----------------|
|[from_time_t](#from_time_t)|Estático. Retorna um `time_point` que mais se aproxima de um tempo especificado.|
|[Nwo](#now)|Estático. Retorna a data atual.|
|[to_time_t](#to_time_t)|Estático. Retorna um objeto `time_t` que mais se aproxima de um `time_point` especificado.|

### <a name="public-constants"></a>Constantes públicas

|Nome|Descrição|
|----------|-----------------|
|[Constante system_clock::is_monotonic](#is_monotonic_constant)|Especifica se o tipo de relógio é monotônico.|
|[Constante system_clock::is_steady](#is_steady_constant)|Especifica se o tipo de relógio é estável.|

## <a name="requirements"></a>Requisitos

**Cabeçalho:** \<crono>

**Namespace:** std::chrono

## <a name="system_clockfrom_time_t"></a><a name="from_time_t"></a>system_clock:from_time_t

Método estático que retorna um [time_point](../standard-library/time-point-class.md) que mais se aproxima do tempo que é representado por *Tm*.

```cpp
static time_point from_time_t(time_t Tm) noexcept;
```

### <a name="parameters"></a>Parâmetros

*Tm*\
Um objeto [time_t](../c-runtime-library/standard-types.md).

## <a name="system_clockis_monotonic-constant"></a><a name="is_monotonic_constant"></a>system_clock:is_monotonic Constante

Valor estático que especifica se o tipo de relógio é monotônico.

```cpp
static const bool is_monotonic = false;
```

### <a name="return-value"></a>Valor retornado

Nesta implementação, `system_clock::is_monotonic` sempre retorna **falso**.

### <a name="remarks"></a>Comentários

Um relógio será *monotônico* se o valor retornado por uma primeira chamada a `now()` for sempre menor ou igual ao valor retornado por uma chamada posterior a `now()`.

## <a name="system_clockis_steady-constant"></a><a name="is_steady_constant"></a>system_clock::is_steady Constante

Valor estático que especifica se o tipo de relógio é *estável*.

```cpp
static const bool is_steady = false;
```

### <a name="return-value"></a>Valor retornado

Nesta implementação, `system_clock::is_steady` sempre retorna **falso**.

### <a name="remarks"></a>Comentários

Um relógio será *estável* se ele for [monotônico](#is_monotonic_constant) e se o tempo entre os tiques do relógio for constante.

## <a name="system_clocknow"></a><a name="now"></a>system_clock::agora

Método estático que retorna a hora atual.

```cpp
static time_point now() noexcept;
```

### <a name="return-value"></a>Valor retornado

Um objeto [time_point](../standard-library/time-point-class.md) que representa a hora atual.

## <a name="system_clockto_time_t"></a><a name="to_time_t"></a>system_clock:to_time_t

Método estático que retorna um [time_t](../c-runtime-library/standard-types.md) que mais se aproxima do tempo que é representado pelo *Tempo*.

```cpp
static time_t to_time_t(const time_point& Time) noexcept;
```

### <a name="parameters"></a>Parâmetros

*Tempo*\
Um objeto [time_point](../standard-library/time-point-class.md).

## <a name="see-also"></a>Confira também

[Referência de arquivos de cabeçalho](../standard-library/cpp-standard-library-header-files.md)\
[\<crono>](../standard-library/chrono.md)\
[Struct steady_clock](../standard-library/steady-clock-struct.md)
