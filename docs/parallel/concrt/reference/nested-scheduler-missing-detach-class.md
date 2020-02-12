---
title: Classe nested_scheduler_missing_detach
ms.date: 11/04/2016
f1_keywords:
- nested_scheduler_missing_detach
- CONCRT/concurrency::nested_scheduler_missing_detach
- CONCRT/concurrency::nested_scheduler_missing_detach::nested_scheduler_missing_detach
helpviewer_keywords:
- nested_scheduler_missing_detach class
ms.assetid: 65d3f277-6d43-4160-97ef-caf8b26c1641
ms.openlocfilehash: 8c9553b036890c4ce28f1060bfe2f58ee1904935
ms.sourcegitcommit: a8ef52ff4a4944a1a257bdaba1a3331607fb8d0f
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 02/11/2020
ms.locfileid: "77138864"
---
# <a name="nested_scheduler_missing_detach-class"></a>Classe nested_scheduler_missing_detach

Essa classe descreve uma exceção gerada quando o Tempo de Execução de Simultaneidade detecta que você não chamou o método `CurrentScheduler::Detach` em um contexto anexado a um segundo Agendador usando o método `Attach` do objeto `Scheduler`.

## <a name="syntax"></a>Sintaxe

```cpp
class nested_scheduler_missing_detach : public std::exception;
```

## <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores públicos

|{1&gt;Nome&lt;1}|Descrição|
|----------|-----------------|
|[nested_scheduler_missing_detach](#ctor)|Sobrecarregado. Constrói um objeto `nested_scheduler_missing_detach`.|

## <a name="remarks"></a>Comentários

Essa exceção é gerada somente quando você Aninha um Agendador dentro de outro chamando o método `Attach` de um objeto `Scheduler` em um contexto que já pertença ou esteja anexado a outro agendador. O Tempo de Execução de Simultaneidade gera essa exceção de forma oportuna quando pode detectar o cenário como uma ajuda para localizar o problema. Nem toda instância de inativo para chamar o método `CurrentScheduler::Detach` é garantida para gerar essa exceção.

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

`exception`

`nested_scheduler_missing_detach`

## <a name="requirements"></a>{1&gt;{2&gt;Requisitos&lt;2}&lt;1}

**Cabeçalho:** ConcRT. h

**Namespace:** simultaneidade

## <a name="ctor"></a>nested_scheduler_missing_detach

Constrói um objeto `nested_scheduler_missing_detach`.

```cpp
explicit _CRTIMP nested_scheduler_missing_detach(_In_z_ const char* _Message) throw();

nested_scheduler_missing_detach() throw();
```

### <a name="parameters"></a>Parâmetros

*_Message*<br/>
Uma mensagem descritiva do erro.

## <a name="see-also"></a>Consulte também

[Namespace de simultaneidade](concurrency-namespace.md)<br/>
[Classe Scheduler](scheduler-class.md)
