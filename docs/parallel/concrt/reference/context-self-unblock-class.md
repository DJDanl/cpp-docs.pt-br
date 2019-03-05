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
ms.openlocfilehash: 900dc68eac4441bd1db3818d3c1f30698b80a6e0
ms.sourcegitcommit: c3093251193944840e3d0a068ecc30e6449624ba
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/04/2019
ms.locfileid: "57283352"
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

*_Message*<br/>
Uma mensagem descritiva do erro.

## <a name="see-also"></a>Consulte também

[Namespace de simultaneidade](concurrency-namespace.md)
