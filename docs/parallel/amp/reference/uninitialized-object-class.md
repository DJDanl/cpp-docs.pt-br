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
ms.openlocfilehash: a977957fcb28a7f4c6c849c954026e2bda4e728c
ms.sourcegitcommit: a61d17cffdd50f1c3c6e082a01bbcbc85b6cc5a7
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/21/2019
ms.locfileid: "65975151"
---
# <a name="uninitializedobject-class"></a>Classe uninitialized_object

A exceção que é lançada quando um objeto não inicializado é usado.

## <a name="syntax"></a>Sintaxe

```
class uninitialized_object : public runtime_exception;
```

## <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores públicos

|Nome|Descrição|
|----------|-----------------|
|[Construtor de uninitialized_object](#uninitialized_object)|Inicializa uma nova instância da classe `uninitialized_object`.|

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

`exception`

`runtime_exception`

`uninitialized_object`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** amprt. h

**Namespace:** Concorrência

## <a name="uninitialized_object"></a> uninitialized_object

Constrói uma nova instância do `uninitialized_object` exceção.

### <a name="syntax"></a>Sintaxe

```
explicit uninitialized_object(
    const char * _Message ) throw();

uninitialized_object() throw();
```

### <a name="parameters"></a>Parâmetros

*_Message*<br/>
Uma descrição do erro.

### <a name="return-value"></a>Valor de retorno

O `uninitialized_object` objeto de exceção.

## <a name="see-also"></a>Consulte também

[Namespace de simultaneidade (C++ AMP)](concurrency-namespace-cpp-amp.md)
