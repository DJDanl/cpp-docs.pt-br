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
ms.openlocfilehash: 155e96762d47b340ac078fad791f3078dba9a871
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50497122"
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

*Mensagem*<br/>
Uma descrição do erro.

### <a name="return-value"></a>Valor de retorno

O objeto `unsupported_feature`.

## <a name="requirements"></a>Requisitos

**Cabeçalho:** amprt. h

**Namespace:** Simultaneidade

## <a name="see-also"></a>Consulte também

[Namespace de simultaneidade (C++ AMP)](concurrency-namespace-cpp-amp.md)
