---
title: Estrutura short_vector
ms.date: 11/04/2016
f1_keywords:
- short_vector
- AMP_SHORT_VECTORS/short_vector
- AMP_SHORT_VECTORS/Concurrency::graphics::short_vector::short_vector Constructor
ms.assetid: e4f50b8f-1150-437d-b58c-79c5fb883708
ms.openlocfilehash: 535aeee1ea52ae6b248220d9330cd1d2235a99a4
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50594045"
---
# <a name="shortvector-structure"></a>Estrutura short_vector

short_vector fornece metaprogramação definições que são úteis para a programação de vetores curtos genericamente.

## <a name="syntax"></a>Sintaxe

```
template<
    typename _Scalar_type,
    int _Size
>
struct short_vector;
template<>
struct short_vector<unsigned int, 1>;
template<>
struct short_vector<unsigned int, 2>;
template<>
struct short_vector<unsigned int, 3>;
template<>
struct short_vector<unsigned int, 4>;
template<>
struct short_vector<int, 1>;
template<>
struct short_vector<int, 2>;
template<>
struct short_vector<int, 3>;
template<>
struct short_vector<int, 4>;
template<>
struct short_vector<float, 1>;
template<>
struct short_vector<float, 2>;
template<>
struct short_vector<float, 3>;
template<>
struct short_vector<float, 4>;
template<>
struct short_vector<unorm, 1>;
template<>
struct short_vector<unorm, 2>;
template<>
struct short_vector<unorm, 3>;
template<>
struct short_vector<unorm, 4>;
template<>
struct short_vector<norm, 1>;
template<>
struct short_vector<norm, 2>;
template<>
struct short_vector<norm, 3>;
template<>
struct short_vector<norm, 4>;
template<>
struct short_vector<double, 1>;
template<>
struct short_vector<double, 2>;
template<>
struct short_vector<double, 3>;
template<>
struct short_vector<double, 4>;
```

#### <a name="parameters"></a>Parâmetros

*_Scalar_type*<br/>

*Tamanho*<br/>

## <a name="members"></a>Membros

### <a name="public-typedefs"></a>Typedefs públicos

|Nome|Descrição|
|----------|-----------------|
|`type`||

### <a name="public-constructors"></a>Construtores Públicos

|Nome|Descrição|
|----------|-----------------|
|[short_vector:: short_vector construtor](#ctor)||

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

`short_vector`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** amp_short_vectors. h

**Namespace:** Concurrency:: Graphics

##  <a name="ctor"></a>  short_vector:: short_vector construtor

```
short_vector();
```

## <a name="see-also"></a>Consulte também

[Namespace Concurrency::graphics](concurrency-graphics-namespace.md)
