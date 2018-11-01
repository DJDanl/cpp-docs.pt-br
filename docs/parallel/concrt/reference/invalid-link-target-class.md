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
ms.openlocfilehash: 6748ea64f7be20dd5ce4573cd65b6e1084148b48
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50449108"
---
# <a name="invalidlinktarget-class"></a>Classe invalid_link_target

Esta classe descreve uma exceção gerada quando o `link_target` método de um bloco de mensagens é chamado e o bloco de mensagens é não foi possível vincular ao destino. Isso pode ser o resultado de exceder o número de links que o bloco de mensagens é permitido ou tentar vincular a um destino específico duas vezes para a mesma fonte.

## <a name="syntax"></a>Sintaxe

```
class invalid_link_target : public std::exception;
```

## <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores Públicos

|Nome|Descrição|
|----------|-----------------|
|[invalid_link_target](#ctor)|Sobrecarregado. Constrói um `invalid_link_target` objeto.|

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

`exception`

`invalid_link_target`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** concrt. h

**Namespace:** simultaneidade

##  <a name="ctor"></a> invalid_link_target

Constrói um `invalid_link_target` objeto.

```
explicit _CRTIMP invalid_link_target(_In_z_ const char* _Message) throw();

invalid_link_target() throw();
```

### <a name="parameters"></a>Parâmetros

*Mensagem*<br/>
Uma mensagem descritiva do erro.

## <a name="see-also"></a>Consulte também

[Namespace de simultaneidade](concurrency-namespace.md)<br/>
[Blocos de mensagens assíncronos](../../../parallel/concrt/asynchronous-message-blocks.md)

