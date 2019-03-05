---
title: Classe unsupported_feature
ms.date: 11/04/2016
f1_keywords:
- unsupported_feature
- AMPRT/unsupported_feature
- AMPRT/Concurrency::unsupported_feature
helpviewer_keywords:
- unsupported_feature class
ms.assetid: 6b1ab917-df13-48c7-9648-7cb2465a0ff5
ms.openlocfilehash: 6a742c3fd1965882c3fa72cb1fab985cd4d981d1
ms.sourcegitcommit: c3093251193944840e3d0a068ecc30e6449624ba
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/04/2019
ms.locfileid: "57272536"
---
# <a name="unsupportedfeature-class"></a>Classe unsupported_feature

A exceção que é lançada quando um recurso sem suporte é usado.

## <a name="syntax"></a>Sintaxe

```
class unsupported_feature : public runtime_exception;
```

## <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores Públicos

|Nome|Descrição|
|----------|-----------------|
|[Construtor de unsupported_feature](#ctor)|Constrói uma nova instância do `unsupported_feature` exceção.|

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

`exception`

`runtime_exception`

`unsupported_feature`

## <a name="unsupported_feature__ctor"></a> unsupported_feature

  Constrói uma nova instância da exceção de unsupported_feature.

### <a name="syntax"></a>Sintaxe

```
explicit unsupported_feature(
    const char * _Message ) throw();

unsupported_feature() throw();
```

### <a name="parameters"></a>Parâmetros

*_Message*<br/>
Uma descrição do erro.

### <a name="return-value"></a>Valor de retorno

O objeto `unsupported_feature`.

## <a name="requirements"></a>Requisitos

**Cabeçalho:** amprt. h

**Namespace:** Concorrência

## <a name="see-also"></a>Consulte também

[Namespace de simultaneidade (C++ AMP)](concurrency-namespace-cpp-amp.md)
