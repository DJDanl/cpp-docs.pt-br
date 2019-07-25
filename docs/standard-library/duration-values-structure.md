---
title: Estrutura duration_values
ms.date: 11/04/2016
f1_keywords:
- chrono/std::chrono::duration_values
- chrono/std::chrono::duration_values::max
- chrono/std::chrono::duration_values::min
- chrono/std::chrono::duration_values::zero
ms.assetid: 7f66d2e3-1faf-47c3-b47e-08f2a87f20e8
ms.openlocfilehash: ba4b202a5c8c6da742ac884bf58a5b8c55373d14
ms.sourcegitcommit: 0dcab746c49f13946b0a7317fc9769130969e76d
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/24/2019
ms.locfileid: "68454298"
---
# <a name="durationvalues-structure"></a>Estrutura duration_values

Fornece valores específicos para o parâmetro de modelo [duration](../standard-library/duration-class.md) `Rep`.

## <a name="syntax"></a>Sintaxe

```cpp
template <class Rep>
struct duration_values;
```

## <a name="members"></a>Membros

### <a name="public-methods"></a>Métodos Públicos

|Nome|Descrição|
|----------|-----------------|
|[max](#max)|Estático. Especifica o limite superior para um valor de tipo `Rep`.|
|[min](#min)|Estático. Especifica o limite inferior para um valor de tipo `Rep`.|
|[zero](#zero)|Estático. Retorna `Rep(0)`.|

## <a name="requirements"></a>Requisitos

**Cabeçalho:** \<> Chrono

**Namespace:** std::chrono

## <a name="max"></a>  duration_values::max

Método estático que retorna o limite superior para valores do tipo `Ref`.

```cpp
static constexpr Rep max();
```

### <a name="return-value"></a>Valor de retorno

Na verdade, retorna `numeric_limits<Rep>::max()`.

### <a name="remarks"></a>Comentários

Quando `Rep` é um tipo definido pelo usuário, o valor retornado deve ser maior que [duration_values::zero](#zero).

## <a name="min"></a>  duration_values::min

Método estático que retorna o limite inferior para valores do tipo `Ref`.

```cpp
static constexpr Rep min();
```

### <a name="return-value"></a>Valor de retorno

Na verdade, retorna `numeric_limits<Rep>::lowest()`.

### <a name="remarks"></a>Comentários

Quando `Rep` é um tipo definido pelo usuário, o valor retornado deve ser menor ou igual a [duration_values::zero](#zero).

## <a name="zero"></a>  duration_values::zero

Retorna `Rep(0)`.

```cpp
static constexpr Rep zero();
```

### <a name="remarks"></a>Comentários

Quando `Rep` é um tipo definido pelo usuário, o valor retornado deve representar o infinito aditivo.

## <a name="see-also"></a>Consulte também

[Referência de Arquivos de Cabeçalho](../standard-library/cpp-standard-library-header-files.md)\
[\<chrono>](../standard-library/chrono.md)
