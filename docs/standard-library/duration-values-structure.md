---
title: Estrutura duration_values
ms.date: 11/04/2016
f1_keywords:
- chrono/std::chrono::duration_values
- chrono/std::chrono::duration_values::max
- chrono/std::chrono::duration_values::min
- chrono/std::chrono::duration_values::zero
ms.assetid: 7f66d2e3-1faf-47c3-b47e-08f2a87f20e8
ms.openlocfilehash: e2c03b4540ea5f89843562d1310b71635b3bc259
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81368740"
---
# <a name="duration_values-structure"></a>Estrutura duration_values

Fornece valores específicos para o parâmetro de modelo [duration](../standard-library/duration-class.md)`Rep`.

## <a name="syntax"></a>Sintaxe

```cpp
template <class Rep>
struct duration_values;
```

## <a name="members"></a>Membros

### <a name="public-methods"></a>Métodos públicos

|Nome|Descrição|
|----------|-----------------|
|[max](#max)|Estático. Especifica o limite superior para um valor de tipo `Rep`.|
|[Min](#min)|Estático. Especifica o limite inferior para um valor de tipo `Rep`.|
|[Zero](#zero)|Estático. Retorna `Rep(0)`.|

## <a name="requirements"></a>Requisitos

**Cabeçalho:** \<crono>

**Namespace:** std::chrono

## <a name="duration_valuesmax"></a><a name="max"></a>duration_values::max

Método estático que retorna o limite superior para valores do tipo `Ref`.

```cpp
static constexpr Rep max();
```

### <a name="return-value"></a>Valor retornado

Na verdade, retorna `numeric_limits<Rep>::max()`.

### <a name="remarks"></a>Comentários

Quando `Rep` é um tipo definido pelo usuário, o valor retornado deve ser maior que [duration_values::zero](#zero).

## <a name="duration_valuesmin"></a><a name="min"></a>duration_values:min

Método estático que retorna o limite inferior para valores do tipo `Ref`.

```cpp
static constexpr Rep min();
```

### <a name="return-value"></a>Valor retornado

Na verdade, retorna `numeric_limits<Rep>::lowest()`.

### <a name="remarks"></a>Comentários

Quando `Rep` é um tipo definido pelo usuário, o valor retornado deve ser menor ou igual a [duration_values::zero](#zero).

## <a name="duration_valueszero"></a><a name="zero"></a>duration_values::zero

Retorna `Rep(0)`.

```cpp
static constexpr Rep zero();
```

### <a name="remarks"></a>Comentários

Quando `Rep` é um tipo definido pelo usuário, o valor retornado deve representar o infinito aditivo.

## <a name="see-also"></a>Confira também

[Referência de arquivos de cabeçalho](../standard-library/cpp-standard-library-header-files.md)\
[\<crono>](../standard-library/chrono.md)
