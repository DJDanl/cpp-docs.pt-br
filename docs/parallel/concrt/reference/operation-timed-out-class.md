---
title: Classe operation_timed_out
ms.date: 11/04/2016
f1_keywords:
- operation_timed_out
- CONCRT/concurrency::operation_timed_out
- CONCRT/concurrency::operation_timed_out::operation_timed_out
helpviewer_keywords:
- operation_timed_out class
ms.assetid: 963efe1d-a6e0-477c-9a70-d93d8412c897
ms.openlocfilehash: 8b25a35ac359fe052f9ae3c1cb15363acfbe93e5
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50561168"
---
# <a name="operationtimedout-class"></a>Classe operation_timed_out

Esta classe descreve uma exceção gerada quando uma operação foi atingido.

## <a name="syntax"></a>Sintaxe

```
class operation_timed_out : public std::exception;
```

## <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores Públicos

|Nome|Descrição|
|----------|-----------------|
|[operation_timed_out](#ctor)|Sobrecarregado. Constrói um `operation_timed_out` objeto.|

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

`exception`

`operation_timed_out`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** concrt. h

**Namespace:** simultaneidade

##  <a name="ctor"></a> operation_timed_out

Constrói um `operation_timed_out` objeto.

```
explicit _CRTIMP operation_timed_out(_In_z_ const char* _Message) throw();

operation_timed_out() throw();
```

### <a name="parameters"></a>Parâmetros

*Mensagem*<br/>
Uma mensagem descritiva do erro.

## <a name="see-also"></a>Consulte também

[Namespace de simultaneidade](concurrency-namespace.md)
