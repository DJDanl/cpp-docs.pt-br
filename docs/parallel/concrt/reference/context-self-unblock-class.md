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
ms.openlocfilehash: 883d5630251a6ea13afba1164f221a0da1773c17
ms.sourcegitcommit: a8ef52ff4a4944a1a257bdaba1a3331607fb8d0f
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 02/11/2020
ms.locfileid: "77143108"
---
# <a name="context_self_unblock-class"></a>Classe context_self_unblock

Essa classe descreve uma exceção gerada quando o método de `Unblock` de um objeto de `Context` é chamado do mesmo contexto. Isso indica uma tentativa por um determinado contexto para desbloquear a si mesmo.

## <a name="syntax"></a>Sintaxe

```cpp
class context_self_unblock : public std::exception;
```

## <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores públicos

|{1&gt;Nome&lt;1}|Descrição|
|----------|-----------------|
|[context_self_unblock](#ctor)|Sobrecarregado. Constrói um objeto `context_self_unblock`.|

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

`exception`

`context_self_unblock`

## <a name="requirements"></a>{1&gt;{2&gt;Requisitos&lt;2}&lt;1}

**Cabeçalho:** ConcRT. h

**Namespace:** simultaneidade

## <a name="ctor"></a>context_self_unblock

Constrói um objeto `context_self_unblock`.

```cpp
explicit _CRTIMP context_self_unblock(_In_z_ const char* _Message) throw();

context_self_unblock() throw();
```

### <a name="parameters"></a>Parâmetros

*_Message*<br/>
Uma mensagem descritiva do erro.

## <a name="see-also"></a>Consulte também

[Namespace de simultaneidade](concurrency-namespace.md)
