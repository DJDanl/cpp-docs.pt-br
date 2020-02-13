---
title: Classe improper_scheduler_attach
ms.date: 11/04/2016
f1_keywords:
- improper_scheduler_attach
- CONCRT/concurrency::improper_scheduler_attach
- CONCRT/concurrency::improper_scheduler_attach::improper_scheduler_attach
helpviewer_keywords:
- improper_scheduler_attach class
ms.assetid: 5a76da0a-091b-4748-8f62-b3a28f674f9e
ms.openlocfilehash: 85adf3f919d94a82f5a68a5cd9e5f44cdca10006
ms.sourcegitcommit: a8ef52ff4a4944a1a257bdaba1a3331607fb8d0f
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 02/11/2020
ms.locfileid: "77141221"
---
# <a name="improper_scheduler_attach-class"></a>Classe improper_scheduler_attach

Essa classe descreve uma exceção gerada quando o método `Attach` é chamado em um objeto `Scheduler` que já está anexado ao contexto atual.

## <a name="syntax"></a>Sintaxe

```cpp
class improper_scheduler_attach : public std::exception;
```

## <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores públicos

|{1&gt;Nome&lt;1}|Descrição|
|----------|-----------------|
|[improper_scheduler_attach](#ctor)|Sobrecarregado. Constrói um objeto `improper_scheduler_attach`.|

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

`exception`

`improper_scheduler_attach`

## <a name="requirements"></a>{1&gt;{2&gt;Requisitos&lt;2}&lt;1}

**Cabeçalho:** ConcRT. h

**Namespace:** simultaneidade

## <a name="ctor"></a>improper_scheduler_attach

Constrói um objeto `improper_scheduler_attach`.

```cpp
explicit _CRTIMP improper_scheduler_attach(_In_z_ const char* _Message) throw();

improper_scheduler_attach() throw();
```

### <a name="parameters"></a>Parâmetros

*_Message*<br/>
Uma mensagem descritiva do erro.

## <a name="see-also"></a>Consulte também

[Namespace de simultaneidade](concurrency-namespace.md)<br/>
[Classe Scheduler](scheduler-class.md)
