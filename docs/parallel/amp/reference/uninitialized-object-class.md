---
title: Classe uninitialized_object
ms.date: 11/04/2016
f1_keywords:
- uninitialized_object
- AMPRT/uninitialized_object
- AMPRT/Concurrency::uninitialized_object
helpviewer_keywords:
- uninitialized_object class
ms.assetid: 6ae3c4e8-64a6-4511-a158-03be197b63af
ms.openlocfilehash: 5dc03964e8ddef0cd1aab785316eabd98c39e59e
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50544524"
---
# <a name="uninitializedobject-class"></a>Classe uninitialized_object

A exceção que é lançada quando um objeto não inicializado é usado.

## <a name="syntax"></a>Sintaxe

```
class uninitialized_object : public runtime_exception;
```

## <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores Públicos

|Nome|Descrição|
|----------|-----------------|
|[Construtor de uninitialized_object](#ctor)|Inicializa uma nova instância da classe `uninitialized_object`.|

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

`exception`

`runtime_exception`

`uninitialized_object`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** amprt. h

**Namespace:** Simultaneidade
## <a name="uninitialized_object__ctor"></a> unsupported_feature

Constrói uma nova instância da exceção de unsupported_feature.

### <a name="syntax"></a>Sintaxe

```
explicit unsupported_feature(
    const char * _Message ) throw();

unsupported_feature() throw();
```

### <a name="parameters"></a>Parâmetros

*Mensagem*<br/>
Uma descrição do erro.

### <a name="return-value"></a>Valor de retorno

O objeto `unsupported_feature`.

## <a name="see-also"></a>Consulte também

[Namespace de simultaneidade (C++ AMP)](concurrency-namespace-cpp-amp.md)
