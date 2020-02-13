---
title: Classe invalid_link_target
ms.date: 11/04/2016
f1_keywords:
- invalid_link_target
- CONCRT/concurrency::invalid_link_target
- CONCRT/concurrency::invalid_link_target::invalid_link_target
helpviewer_keywords:
- invalid_link_target class
ms.assetid: 33b64885-34d8-4d4e-a893-02e9f19c958e
ms.openlocfilehash: bd3d82c06c174c69c60dec33592110f4de72ac99
ms.sourcegitcommit: a8ef52ff4a4944a1a257bdaba1a3331607fb8d0f
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 02/11/2020
ms.locfileid: "77141043"
---
# <a name="invalid_link_target-class"></a>Classe invalid_link_target

Essa classe descreve uma exceção gerada quando o método de `link_target` de um bloco de mensagens é chamado e o bloco de mensagens não é capaz de vincular ao destino. Isso pode ser o resultado de exceder o número de links que o bloco de mensagens é permitido ou tentar vincular um destino específico duas vezes à mesma fonte.

## <a name="syntax"></a>Sintaxe

```cpp
class invalid_link_target : public std::exception;
```

## <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores públicos

|{1&gt;Nome&lt;1}|Descrição|
|----------|-----------------|
|[invalid_link_target](#ctor)|Sobrecarregado. Constrói um objeto `invalid_link_target`.|

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

`exception`

`invalid_link_target`

## <a name="requirements"></a>{1&gt;{2&gt;Requisitos&lt;2}&lt;1}

**Cabeçalho:** ConcRT. h

**Namespace:** simultaneidade

## <a name="ctor"></a>invalid_link_target

Constrói um objeto `invalid_link_target`.

```cpp
explicit _CRTIMP invalid_link_target(_In_z_ const char* _Message) throw();

invalid_link_target() throw();
```

### <a name="parameters"></a>Parâmetros

*_Message*<br/>
Uma mensagem descritiva do erro.

## <a name="see-also"></a>Consulte também

[Namespace de simultaneidade](concurrency-namespace.md)<br/>
[Blocos de mensagens assíncronos](../../../parallel/concrt/asynchronous-message-blocks.md)
