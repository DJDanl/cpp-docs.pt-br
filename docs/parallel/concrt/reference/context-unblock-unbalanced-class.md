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
ms.openlocfilehash: f4f385cde2a27665afa5eb9869eb52bc42c70111
ms.sourcegitcommit: c3093251193944840e3d0a068ecc30e6449624ba
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/04/2019
ms.locfileid: "57283989"
---
# <a name="contextunblockunbalanced-class"></a>Classe context_unblock_unbalanced

Esta classe descreve uma exceção lançada quando chamadas para o `Block` e `Unblock` métodos de um `Context` objeto não são emparelhados corretamente.

## <a name="syntax"></a>Sintaxe

```
class context_unblock_unbalanced : public std::exception;
```

## <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores Públicos

|Nome|Descrição|
|----------|-----------------|
|[context_unblock_unbalanced](#ctor)|Sobrecarregado. Constrói um objeto `context_unblock_unbalanced`.|

## <a name="remarks"></a>Comentários

Chamadas para o `Block` e `Unblock` métodos de um `Context` objeto sempre deve ser combinado corretamente. O tempo de execução de simultaneidade permite que as operações de acontecer em qualquer ordem. Por exemplo, uma chamada para `Block` pode ser seguido por uma chamada para `Unblock`, ou vice-versa. Essa exceção seria lançada se, por exemplo, duas chamadas para o `Unblock` método foram feitas em uma linha em um `Context` objeto que não foi bloqueado.

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

`exception`

`context_unblock_unbalanced`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** concrt. h

**Namespace:** simultaneidade

##  <a name="ctor"></a> context_unblock_unbalanced

Constrói um objeto `context_unblock_unbalanced`.

```
explicit _CRTIMP context_unblock_unbalanced(_In_z_ const char* _Message) throw();

context_unblock_unbalanced() throw();
```

### <a name="parameters"></a>Parâmetros

*_Message*<br/>
Uma mensagem descritiva do erro.

## <a name="see-also"></a>Consulte também

[Namespace de simultaneidade](concurrency-namespace.md)
