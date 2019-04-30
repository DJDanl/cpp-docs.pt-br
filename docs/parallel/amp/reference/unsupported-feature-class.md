---
title: Classe unsupported_feature
ms.date: 03/27/2019
f1_keywords:
- unsupported_feature
- AMPRT/unsupported_feature
- AMPRT/Concurrency::unsupported_feature
helpviewer_keywords:
- unsupported_feature class
ms.assetid: 6b1ab917-df13-48c7-9648-7cb2465a0ff5
ms.openlocfilehash: 7635f999b227d02ec7fd56296fef1b0b047abd29
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62405463"
---
# <a name="unsupportedfeature-class"></a>Classe unsupported_feature

A exceção que é lançada quando um recurso sem suporte é usado.

## <a name="syntax"></a>Sintaxe

```
class unsupported_feature : public runtime_exception;
```

## <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores públicos

|Nome|Descrição|
|----------|-----------------|
|[Construtor de unsupported_feature](#unsupported_feature)|Constrói uma nova instância do `unsupported_feature` exceção.|

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

`exception`

`runtime_exception`

`unsupported_feature`

## <a name="unsupportedfeature"></a>unsupported_feature

  Constrói uma nova instância do `unsupported_feature` exceção.

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
