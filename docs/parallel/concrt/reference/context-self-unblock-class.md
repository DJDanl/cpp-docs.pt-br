---
title: Classe context_self_unblock
ms.date: 11/04/2016
f1_keywords:
- context_self_unblock
- CONCRT/concurrency::context_self_unblock
- CONCRT/concurrency::context_self_unblock::context_self_unblock
helpviewer_keywords:
- context_self_unblock class
ms.assetid: 9601cd28-4f40-4c2e-89ab-747068956331
ms.openlocfilehash: 5cb7fc951a4c62f4d299ce7d394e9f8268d7ed74
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50622164"
---
# <a name="contextselfunblock-class"></a>Classe context_self_unblock

Esta classe descreve uma exceção gerada quando o `Unblock` método de um `Context` objeto é chamado no mesmo contexto. Isso poderia indicar uma tentativa por um determinado contexto para desbloquear em si.

## <a name="syntax"></a>Sintaxe

```
class context_self_unblock : public std::exception;
```

## <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores Públicos

|Nome|Descrição|
|----------|-----------------|
|[context_self_unblock](#ctor)|Sobrecarregado. Constrói um objeto `context_self_unblock`.|

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

`exception`

`context_self_unblock`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** concrt. h

**Namespace:** simultaneidade

##  <a name="ctor"></a> context_self_unblock

Constrói um objeto `context_self_unblock`.

```
explicit _CRTIMP context_self_unblock(_In_z_ const char* _Message) throw();

context_self_unblock() throw();
```

### <a name="parameters"></a>Parâmetros

*Mensagem*<br/>
Uma mensagem descritiva do erro.

## <a name="see-also"></a>Consulte também

[Namespace de simultaneidade](concurrency-namespace.md)
