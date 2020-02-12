---
title: Classe context_unblock_unbalanced
ms.date: 11/04/2016
f1_keywords:
- context_unblock_unbalanced
- CONCRT/concurrency::context_unblock_unbalanced
- CONCRT/concurrency::context_unblock_unbalanced::context_unblock_unbalanced
helpviewer_keywords:
- context_unblock_unbalanced class
ms.assetid: a76066c8-19dd-44fa-959a-6941ec1b0d2d
ms.openlocfilehash: 261ec96c1a83fbec423e6dbbfe403c4db53a2962
ms.sourcegitcommit: a8ef52ff4a4944a1a257bdaba1a3331607fb8d0f
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 02/11/2020
ms.locfileid: "77143103"
---
# <a name="context_unblock_unbalanced-class"></a>Classe context_unblock_unbalanced

Essa classe descreve uma exceção gerada quando chamadas para os métodos `Block` e `Unblock` de um objeto `Context` não são emparelhadas corretamente.

## <a name="syntax"></a>Sintaxe

```cpp
class context_unblock_unbalanced : public std::exception;
```

## <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores públicos

|{1&gt;Nome&lt;1}|Descrição|
|----------|-----------------|
|[context_unblock_unbalanced](#ctor)|Sobrecarregado. Constrói um objeto `context_unblock_unbalanced`.|

## <a name="remarks"></a>Comentários

Chamadas para os métodos `Block` e `Unblock` de um objeto `Context` devem ser sempre emparelhadas adequadamente. O Tempo de Execução de Simultaneidade permite que as operações ocorram em qualquer ordem. Por exemplo, uma chamada para `Block` pode ser seguida por uma chamada para `Unblock`ou vice-versa. Essa exceção seria lançada se, por exemplo, duas chamadas para o método `Unblock` fossem feitas em uma linha, em um objeto `Context` que não foi bloqueado.

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

`exception`

`context_unblock_unbalanced`

## <a name="requirements"></a>{1&gt;{2&gt;Requisitos&lt;2}&lt;1}

**Cabeçalho:** ConcRT. h

**Namespace:** simultaneidade

## <a name="ctor"></a>context_unblock_unbalanced

Constrói um objeto `context_unblock_unbalanced`.

```cpp
explicit _CRTIMP context_unblock_unbalanced(_In_z_ const char* _Message) throw();

context_unblock_unbalanced() throw();
```

### <a name="parameters"></a>Parâmetros

*_Message*<br/>
Uma mensagem descritiva do erro.

## <a name="see-also"></a>Consulte também

[Namespace de simultaneidade](concurrency-namespace.md)
