---
title: Classe uninitialized_object
ms.date: 03/27/2019
f1_keywords:
- uninitialized_object
- AMPRT/uninitialized_object
- AMPRT/Concurrency::uninitialized_object
helpviewer_keywords:
- uninitialized_object class
ms.assetid: 6ae3c4e8-64a6-4511-a158-03be197b63af
ms.openlocfilehash: ef7ded0bf925d3430b70064c4979b75e08f9cf45
ms.sourcegitcommit: a8ef52ff4a4944a1a257bdaba1a3331607fb8d0f
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 02/11/2020
ms.locfileid: "77127693"
---
# <a name="uninitialized_object-class"></a>Classe uninitialized_object

A exceção que é lançada quando um objeto não inicializado é usado.

## <a name="syntax"></a>Sintaxe

```cpp
class uninitialized_object : public runtime_exception;
```

## <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores públicos

|{1&gt;Nome&lt;1}|Descrição|
|----------|-----------------|
|[Construtor de uninitialized_object](#uninitialized_object)|Inicializa uma nova instância da classe `uninitialized_object`.|

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

`exception`

`runtime_exception`

`uninitialized_object`

## <a name="requirements"></a>{1&gt;{2&gt;Requisitos&lt;2}&lt;1}

**Cabeçalho:** amprt. h

**Namespace:** Simultaneidade

## <a name="uninitialized_object"></a>uninitialized_object

Constrói uma nova instância da exceção `uninitialized_object`.

### <a name="syntax"></a>Sintaxe

```cpp
explicit uninitialized_object(
    const char * _Message ) throw();

uninitialized_object() throw();
```

### <a name="parameters"></a>Parâmetros

*_Message*<br/>
Uma descrição do erro.

### <a name="return-value"></a>Valor retornado

O objeto de exceção `uninitialized_object`.

## <a name="see-also"></a>Consulte também

[Namespace de simultaneidade (C++ AMP)](concurrency-namespace-cpp-amp.md)
