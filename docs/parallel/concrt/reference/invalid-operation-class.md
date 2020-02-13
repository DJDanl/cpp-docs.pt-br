---
title: Classe invalid_operation
ms.date: 11/04/2016
f1_keywords:
- invalid_operation
- CONCRT/concurrency::invalid_operation
- CONCRT/concurrency::invalid_operation::invalid_operation
helpviewer_keywords:
- invalid_operation class
ms.assetid: 26ba07dc-fcdf-44cb-b748-a31d35205b52
ms.openlocfilehash: e17d530569d16ba0084a58bf0be00d4a8423b7f6
ms.sourcegitcommit: a8ef52ff4a4944a1a257bdaba1a3331607fb8d0f
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 02/11/2020
ms.locfileid: "77140878"
---
# <a name="invalid_operation-class"></a>Classe invalid_operation

Essa classe descreve uma exceção lançada quando uma operação inválida é executada e não é mais precisamente descrita por outro tipo de exceção lançado pelo Tempo de Execução de Simultaneidade.

## <a name="syntax"></a>Sintaxe

```cpp
class invalid_operation : public std::exception;
```

## <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores públicos

|{1&gt;Nome&lt;1}|Descrição|
|----------|-----------------|
|[invalid_operation](#ctor)|Sobrecarregado. Constrói um objeto `invalid_operation`.|

## <a name="remarks"></a>Comentários

Os vários métodos que lançam essa exceção geralmente documentam em que circunstâncias eles vão jogá-la.

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

`exception`

`invalid_operation`

## <a name="requirements"></a>{1&gt;{2&gt;Requisitos&lt;2}&lt;1}

**Cabeçalho:** ConcRT. h

**Namespace:** simultaneidade

## <a name="ctor"></a>invalid_operation

Constrói um objeto `invalid_operation`.

```cpp
explicit _CRTIMP invalid_operation(_In_z_ const char* _Message) throw();

invalid_operation() throw();
```

### <a name="parameters"></a>Parâmetros

*_Message*<br/>
Uma mensagem descritiva do erro.

## <a name="see-also"></a>Consulte também

[Namespace de simultaneidade](concurrency-namespace.md)
