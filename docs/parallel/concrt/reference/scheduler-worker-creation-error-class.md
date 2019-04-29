---
title: Classe scheduler_worker_creation_error
ms.date: 11/04/2016
f1_keywords:
- scheduler_worker_creation_error
- CONCRT/concurrency::scheduler_worker_creation_error
- CONCRT/concurrency::scheduler_worker_creation_error::scheduler_worker_creation_error
helpviewer_keywords:
- scheduler_worker_creation_error class
ms.assetid: 4aec1c3e-c32a-41b2-899d-2d898f23b3c7
ms.openlocfilehash: 66e7485787606c22aba2970dbe481a7d29e66621
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62337356"
---
# <a name="schedulerworkercreationerror-class"></a>Classe scheduler_worker_creation_error

Esta classe descreve uma exceção gerada devido a uma falha ao criar um contexto de execução do trabalho no tempo de execução de simultaneidade.

## <a name="syntax"></a>Sintaxe

```
class scheduler_worker_creation_error : public scheduler_resource_allocation_error;
```

## <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores públicos

|Nome|Descrição|
|----------|-----------------|
|[scheduler_worker_creation_error](#ctor)|Sobrecarregado. Constrói um objeto `scheduler_worker_creation_error`.|

## <a name="remarks"></a>Comentários

Essa exceção normalmente é lançada quando a falha de uma chamada para o sistema operacional para criar os contextos de execução de dentro do tempo de execução de simultaneidade. Contextos de execução são threads que executam tarefas no tempo de execução de simultaneidade. O código de erro que normalmente seria retornado de uma chamada para o método do Win32 `GetLastError` é convertido em um valor do tipo `HRESULT` e pode ser recuperado usando o método de classe base `get_error_code`.

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

`exception`

[scheduler_resource_allocation_error](scheduler-resource-allocation-error-class.md)

`scheduler_worker_creation_error`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** concrt. h

**Namespace:** simultaneidade

##  <a name="ctor"></a> scheduler_worker_creation_error

Constrói um objeto `scheduler_worker_creation_error`.

```
scheduler_worker_creation_error(
    _In_z_ const char* _Message,
    HRESULT _Hresult) throw();

explicit _CRTIMP scheduler_worker_creation_error(
    HRESULT _Hresult) throw();
```

### <a name="parameters"></a>Parâmetros

*_Message*<br/>
Uma mensagem descritiva do erro.

*_Hresult*<br/>
O `HRESULT` valor do erro que causou a exceção.

## <a name="see-also"></a>Consulte também

[Namespace de simultaneidade](concurrency-namespace.md)
