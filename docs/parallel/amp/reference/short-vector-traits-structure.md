---
title: Estrutura short_vector_traits
ms.date: 11/04/2016
f1_keywords:
- short_vector_traits
- AMP_SHORT_VECTORS/short_vector_traits
- AMP_SHORT_VECTORS/Concurrency::graphics::short_vector_traits::short_vector_traits
- AMP_SHORT_VECTORS/Concurrency::graphics::short_vector_traits::size Constant
ms.assetid: cd9492da-9e02-4a6e-9d50-b61252cdb460
ms.openlocfilehash: fd86228417234f705d3f765624cd942c982df875
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50456180"
---
# <a name="shortvectortraits-structure"></a>Estrutura short_vector_traits

short_vector_traits permite a recuperação do comprimento do vetor subjacente e um tipo escalar de um tipo de vetor curto ou um tipo escalar

## <a name="syntax"></a>Sintaxe

```
template<
    typename T
>
struct short_vector_traits;
template<>
struct short_vector_traits<unsigned int>;
template<>
struct short_vector_traits<uint_2>;
template<>
struct short_vector_traits<uint_3>;
template<>
struct short_vector_traits<uint_4>;
template<>
struct short_vector_traits<int>;
template<>
struct short_vector_traits<int_2>;
template<>
struct short_vector_traits<int_3>;
template<>
struct short_vector_traits<int_4>;
template<>
struct short_vector_traits<float>;
template<>
struct short_vector_traits<float_2>;
template<>
struct short_vector_traits<float_3>;
template<>
struct short_vector_traits<float_4>;
template<>
struct short_vector_traits<unorm>;
template<>
struct short_vector_traits<unorm_2>;
template<>
struct short_vector_traits<unorm_3>;
template<>
struct short_vector_traits<unorm_4>;
template<>
struct short_vector_traits<norm>;
template<>
struct short_vector_traits<norm_2>;
template<>
struct short_vector_traits<norm_3>;
template<>
struct short_vector_traits<norm_4>;
template<>
struct short_vector_traits<double>;
template<>
struct short_vector_traits<double_2>;
template<>
struct short_vector_traits<double_3>;
template<>
struct short_vector_traits<double_4>;
```

#### <a name="parameters"></a>Parâmetros

`T`

## <a name="members"></a>Membros

### <a name="public-typedefs"></a>Typedefs públicos

|Nome|Descrição|
|----------|-----------------|
|`value_type`||

### <a name="public-constructors"></a>Construtores Públicos

|Nome|Descrição|
|----------|-----------------|
|[short_vector_traits:: short_vector_traits construtor](#ctor)||

### <a name="public-constants"></a>Constantes públicas

|Nome|Descrição|
|----------|-----------------|
|[short_vector_traits:: Size constante](#size)||

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

`short_vector_traits`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** amp_short_vectors. h

**Namespace:** Concurrency:: Graphics

##  <a name="ctor"></a>  short_vector_traits:: short_vector_traits construtor

```
short_vector_traits();
```

##  <a name="size"></a>  short_vector_traits:: Size constante

```
static int const size = 1;
```

## <a name="see-also"></a>Consulte também

[Namespace Concurrency::graphics](concurrency-graphics-namespace.md)
