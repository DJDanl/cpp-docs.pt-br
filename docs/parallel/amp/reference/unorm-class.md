---
title: Classe unorm | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-amp
ms.topic: reference
f1_keywords:
- unorm
- AMP_SHORT_VECTORS/unorm
- AMP_SHORT_VECTORS/Concurrency::graphics::unorm Constructor
dev_langs:
- C++
ms.assetid: bc30bd20-6452-4d5f-9158-3b11c4c16ed2
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 131a928c5943ab9bf4dcc327b044d76e5646ede7
ms.sourcegitcommit: 799f9b976623a375203ad8b2ad5147bd6a2212f0
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/19/2018
ms.locfileid: "46377377"
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
