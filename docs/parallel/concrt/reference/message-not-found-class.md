---
title: Classe message_not_found
ms.date: 11/04/2016
f1_keywords:
- message_not_found
- CONCRT/concurrency::message_not_found
- CONCRT/concurrency::message_not_found::message_not_found
helpviewer_keywords:
- message_not_found class
ms.assetid: a96b9995-5ad7-4600-83c8-c15e329ff10e
ms.openlocfilehash: da0a44b90346959756c1ef7c685bef234fe6e46a
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62394410"
---
# <a name="messagenotfound-class"></a>Classe message_not_found

Esta classe descreve uma exceção gerada quando um bloco de mensagens não conseguir encontrar uma mensagem solicitada.

## <a name="syntax"></a>Sintaxe

```
class message_not_found : public std::exception;
```

## <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores públicos

|Nome|Descrição|
|----------|-----------------|
|[message_not_found](#ctor)|Sobrecarregado. Constrói um objeto `message_not_found`.|

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

`exception`

`message_not_found`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** concrt. h

**Namespace:** simultaneidade

##  <a name="ctor"></a> message_not_found

Constrói um objeto `message_not_found`.

```
explicit _CRTIMP message_not_found(_In_z_ const char* _Message) throw();

message_not_found() throw();
```

### <a name="parameters"></a>Parâmetros

*_Message*<br/>
Uma mensagem descritiva do erro.

## <a name="see-also"></a>Consulte também

[Namespace de simultaneidade](concurrency-namespace.md)<br/>
[Blocos de mensagens assíncronos](../../../parallel/concrt/asynchronous-message-blocks.md)
