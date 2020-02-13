---
title: Classe unorm
ms.date: 11/04/2016
f1_keywords:
- unorm
- AMP_SHORT_VECTORS/unorm
- AMP_SHORT_VECTORS/Concurrency::graphics::unorm Constructor
ms.assetid: bc30bd20-6452-4d5f-9158-3b11c4c16ed2
ms.openlocfilehash: 7c9ec967be8be618e5f8ab3bad1bfd940bfeaef4
ms.sourcegitcommit: a8ef52ff4a4944a1a257bdaba1a3331607fb8d0f
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 02/11/2020
ms.locfileid: "77126299"
---
# <a name="unorm-class"></a>Classe unorm

Representa um número de unorm. Cada elemento é um número de ponto flutuante no intervalo de [0,0 f, 1,0 f].

## <a name="syntax"></a>Sintaxe

```cpp
class unorm;
```

## <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores públicos

|{1&gt;Nome&lt;1}|Descrição|
|----------|-----------------|
|[Construtor unorm](#ctor)|Sobrecarregado. Construtor padrão. Inicialize para 0,0 f.|

### <a name="public-operators"></a>Operadores públicos

|{1&gt;Nome&lt;1}|Descrição|
|----------|-----------------|
|unorm::operator--||
|float de unorm:: Operator|Operador de conversão. Converta o número unorm em um valor de ponto flutuante.|
|unorm:: Operator * =||
|unorm::operator/=||
|unorm:: operador + +||
|unorm::operator+=||
|unorm::operator=||
|unorm::operator-=||

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

`unorm`

## <a name="requirements"></a>{1&gt;{2&gt;Requisitos&lt;2}&lt;1}

**Cabeçalho:** amp_short_vectors. h

**Namespace:** Simultaneidade:: Graphics

## <a name="ctor"></a>unorm

Construtor padrão. Inicialize para 0,0 f.

```cpp
unorm(
    void) restrict(amp,
    cpu);

explicit unorm(
    float _V) restrict(amp,
    cpu);

explicit unorm(
    unsigned int _V) restrict(amp,
    cpu);

explicit unorm(
    int _V) restrict(amp,
    cpu);

explicit unorm(
    double _V) restrict(amp,
    cpu);

unorm(
    const unorm& _Other) restrict(amp,
    cpu);

inline explicit unorm(
    const norm& _Other) restrict(amp,
    cpu);
```

### <a name="parameters"></a>Parâmetros

*_V*<br/>
O valor usado para inicializar.

*_Other*<br/>
O objeto de regra usado para inicializar.

## <a name="see-also"></a>Consulte também

[Namespace Concurrency::graphics](concurrency-graphics-namespace.md)
