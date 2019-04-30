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
ms.openlocfilehash: db51f7b083cc0cbd9337fbbe5c672d190208f328
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62394384"
---
# <a name="nestedschedulermissingdetach-class"></a>Classe nested_scheduler_missing_detach

Esta classe descreve uma exceção gerada quando o tempo de execução de simultaneidade detecta que você não chamou o `CurrentScheduler::Detach` método em um contexto que é anexado a um agendador segundo usando o `Attach` método da `Scheduler` objeto.

## <a name="syntax"></a>Sintaxe

```
class nested_scheduler_missing_detach : public std::exception;
```

## <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores públicos

|Nome|Descrição|
|----------|-----------------|
|[nested_scheduler_missing_detach](#ctor)|Sobrecarregado. Constrói um objeto `nested_scheduler_missing_detach`.|

## <a name="remarks"></a>Comentários

Essa exceção é gerada somente quando você aninhar um agendador dentro de outra, chamando o `Attach` método de um `Scheduler` objeto em um contexto que já é de propriedade ou anexado a outro Agendador. O tempo de execução de simultaneidade gera esta exceção oportunamente quando ele pode detectar o cenário como um auxílio para localizar o problema. Nem toda instância de não conseguir chamar o `CurrentScheduler::Detach` método é garantido que lançam essa exceção.

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

`exception`

`nested_scheduler_missing_detach`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** concrt. h

**Namespace:** simultaneidade

##  <a name="ctor"></a> nested_scheduler_missing_detach

Constrói um objeto `nested_scheduler_missing_detach`.

```
explicit _CRTIMP nested_scheduler_missing_detach(_In_z_ const char* _Message) throw();

nested_scheduler_missing_detach() throw();
```

### <a name="parameters"></a>Parâmetros

*_Message*<br/>
Uma mensagem descritiva do erro.

## <a name="see-also"></a>Consulte também

[Namespace de simultaneidade](concurrency-namespace.md)<br/>
[Classe Scheduler](scheduler-class.md)
