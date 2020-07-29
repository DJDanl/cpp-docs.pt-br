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
ms.openlocfilehash: 0c95d234fee412c1dacb014dd135ca56fc73bf5e
ms.sourcegitcommit: 1f009ab0f2cc4a177f2d1353d5a38f164612bdb1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/27/2020
ms.locfileid: "87193959"
---
# <a name="invalid_oversubscribe_operation-class"></a>Classe invalid_oversubscribe_operation

Essa classe descreve uma exceção lançada quando o `Context::Oversubscribe` método é chamado com o `_BeginOversubscription` parâmetro definido como **`false`** sem uma chamada anterior ao `Context::Oversubscribe` método com o `_BeginOversubscription` parâmetro definido como **`true`** .

## <a name="syntax"></a>Sintaxe

```cpp
class invalid_oversubscribe_operation : public std::exception;
```

## <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores públicos

|Nome|Descrição|
|----------|-----------------|
|[invalid_oversubscribe_operation](#ctor)|Sobrecarregado. Constrói um `invalid_oversubscribe_operation` objeto.|

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

`exception`

`invalid_oversubscribe_operation`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** ConcRT. h

**Namespace:** simultaneidade

## <a name="invalid_oversubscribe_operation"></a><a name="ctor"></a>invalid_oversubscribe_operation

Constrói um `invalid_oversubscribe_operation` objeto.

```cpp
explicit _CRTIMP invalid_oversubscribe_operation(_In_z_ const char* _Message) throw();

invalid_oversubscribe_operation() throw();
```

### <a name="parameters"></a>parâmetros

*_Message*<br/>
Uma mensagem descritiva do erro.

## <a name="see-also"></a>Confira também

[Namespace de simultaneidade](concurrency-namespace.md)
