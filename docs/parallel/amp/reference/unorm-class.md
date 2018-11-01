---
title: Classe unorm
ms.date: 11/04/2016
f1_keywords:
- unorm
- AMP_SHORT_VECTORS/unorm
- AMP_SHORT_VECTORS/Concurrency::graphics::unorm Constructor
ms.assetid: bc30bd20-6452-4d5f-9158-3b11c4c16ed2
ms.openlocfilehash: b485d5efbfbcedbb1e11a3e212465340f0413ee4
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50491553"
---
# <a name="unorm-class"></a>Classe unorm

Representa um número unorm. Cada elemento é flutuante número de ponto no intervalo de [0.0f, 1.0f].

## <a name="syntax"></a>Sintaxe

```
class unorm;
```

## <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores Públicos

|Nome|Descrição|
|----------|-----------------|
|[Construtor de unorm](#ctor)|Sobrecarregado. Construtor padrão. Inicialize a 0.0f.|

### <a name="public-operators"></a>Operadores públicos

|Nome|Descrição|
|----------|-----------------|
|unorm::operator--||
|unorm::operator float|Operador de conversão. Converta o número de unorm em flutuante valor de ponto.|
|unorm::Operator * =||
|unorm::operator/=||
|unorm::Operator + +||
|+ unorm::Operator =||
|unorm::operator=||
|unorm::operator-=||

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

`unorm`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** amp_short_vectors. h

**Namespace:** Concurrency:: Graphics

##  <a name="ctor"></a> unorm

Construtor padrão. Inicialize a 0.0f.

```
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

*Outro*<br/>
O objeto de norma usado para inicializar.

## <a name="see-also"></a>Consulte também

[Namespace Concurrency::graphics](concurrency-graphics-namespace.md)
