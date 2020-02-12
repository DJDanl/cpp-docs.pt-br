---
title: Classe invalid_oversubscribe_operation
ms.date: 11/04/2016
f1_keywords:
- invalid_oversubscribe_operation
- CONCRT/concurrency::invalid_oversubscribe_operation
- CONCRT/concurrency::invalid_oversubscribe_operation::invalid_oversubscribe_operation
helpviewer_keywords:
- invalid_oversubscribe_operation class
ms.assetid: 0a9c5f08-d5e6-4ad0-90a9-517472b3ac28
ms.openlocfilehash: 7a879fc2da2f963cd4b5ea5fcd7e9506f86ce051
ms.sourcegitcommit: a8ef52ff4a4944a1a257bdaba1a3331607fb8d0f
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 02/11/2020
ms.locfileid: "77140841"
---
# <a name="invalid_oversubscribe_operation-class"></a>Classe invalid_oversubscribe_operation

Essa classe descreve uma exceção gerada quando o método `Context::Oversubscribe` é chamado com o parâmetro `_BeginOversubscription` definido como **false** sem uma chamada anterior ao método `Context::Oversubscribe` com o parâmetro `_BeginOversubscription` definido como **true**.

## <a name="syntax"></a>Sintaxe

```cpp
class invalid_oversubscribe_operation : public std::exception;
```

## <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores públicos

|{1&gt;Nome&lt;1}|Descrição|
|----------|-----------------|
|[invalid_oversubscribe_operation](#ctor)|Sobrecarregado. Constrói um objeto `invalid_oversubscribe_operation`.|

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

`exception`

`invalid_oversubscribe_operation`

## <a name="requirements"></a>{1&gt;{2&gt;Requisitos&lt;2}&lt;1}

**Cabeçalho:** ConcRT. h

**Namespace:** simultaneidade

## <a name="ctor"></a>invalid_oversubscribe_operation

Constrói um objeto `invalid_oversubscribe_operation`.

```cpp
explicit _CRTIMP invalid_oversubscribe_operation(_In_z_ const char* _Message) throw();

invalid_oversubscribe_operation() throw();
```

### <a name="parameters"></a>Parâmetros

*_Message*<br/>
Uma mensagem descritiva do erro.

## <a name="see-also"></a>Consulte também

[Namespace de simultaneidade](concurrency-namespace.md)
