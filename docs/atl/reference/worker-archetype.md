---
title: Arquétipo de trabalhador
ms.date: 11/04/2016
helpviewer_keywords:
- Worker archetype
ms.assetid: 834145cd-09d3-4149-bc99-620e1871cbfb
ms.openlocfilehash: 790cf064fcffe1f0cd3c191c28ed0a0614062406
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62274493"
---
# <a name="worker-archetype"></a>Arquétipo de trabalhador

As classes que estão em conformidade com o *trabalhador* arquétipo fornecer o código para processar itens de trabalho em fila em um pool de threads.

**Implementação**

Para implementar uma classe em conformidade com essa arquétipo, a classe deve fornecer os seguintes recursos:

|Método|Descrição|
|------------|-----------------|
|[Initialize](#initialize)|Chamado para inicializar o objeto de trabalho antes de todas as solicitações são passadas para [Execute](#execute).|
|[Executar](#execute)|Chamado para processar um item de trabalho.|
|[Terminar](#terminate)|Chamado para inicializar o objeto de trabalho depois que todas as solicitações foram passadas ao [Execute](#execute).|

|DefTipo|Descrição|
|-------------|-----------------|
|[RequestType](#requesttype)|Um typedef para o tipo de item de trabalho que pode ser processada pela classe de trabalho.|

Um típico *trabalhador* classe tem esta aparência:

[!code-cpp[NVC_ATL_Utilities#137](../../atl/codesnippet/cpp/worker-archetype_1.cpp)]

**Implementações existentes**

Essas classes estão em conformidade com essa arquétipo:

|Classe|Descrição|
|-----------|-----------------|
|[CNonStatelessWorker](../../atl/reference/cnonstatelessworker-class.md)|Recebe solicitações do pool de threads e os passa para um objeto de trabalho que é criado e destruído para cada solicitação.|

**Use**

Esses parâmetros de modelo espera que a classe de acordo com esse arquétipo:

|Nome do parâmetro|Usado por|
|--------------------|-------------|
|*Trabalhador*|[CThreadPool](../../atl/reference/cthreadpool-class.md)|
|*Trabalhador*|[CNonStatelessWorker](../../atl/reference/cnonstatelessworker-class.md)|

### <a name="requirements"></a>Requisitos

**Cabeçalho:** atlutil

## <a name="execute"></a>WorkerArchetype::Execute

Chamado para processar um item de trabalho.

```
void Execute(
    RequestType request,
    void* pvWorkerParam,
    OVERLAPPED* pOverlapped);
```

#### <a name="parameters"></a>Parâmetros

*request*<br/>
O item de trabalho a serem processados. O item de trabalho é do mesmo tipo que `RequestType`.

*pvWorkerParam*<br/>
Um parâmetro personalizado compreendido pela classe de trabalho. Também é passado para `WorkerArchetype::Initialize` e `Terminate`.

*pOverlapped*<br/>
Um ponteiro para o [OVERLAPPED](/windows/desktop/api/minwinbase/ns-minwinbase-_overlapped) estrutura usada para criar a fila em que o trabalho itens entraram na fila.

## <a name="initialize"></a> WorkerArchetype::Initialize

Chamado para inicializar o objeto de trabalho antes de todas as solicitações são passadas para `WorkerArchetype::Execute`.
```
BOOL Initialize(void* pvParam) throw();
```

#### <a name="parameters"></a>Parâmetros

*pvParam*<br/>
Um parâmetro personalizado compreendido pela classe de trabalho. Também é passado para `WorkerArchetype::Terminate` e `WorkerArchetype::Execute`.

### <a name="return-value"></a>Valor de retorno

Retorna verdadeiro em caso de êxito, FALSE em caso de falha.

## <a name="requesttype"></a> WorkerArchetype::RequestType

Um typedef para o tipo de item de trabalho que pode ser processada pela classe de trabalho.

```
typedef MyRequestType RequestType;
```

### <a name="remarks"></a>Comentários

Esse tipo deve ser usado como o primeiro parâmetro de `WorkerArchetype::Execute` e deve ser capaz de que está sendo convertido de e para um ULONG_PTR.

## <a name="terminate"></a> WorkerArchetype::Terminate

Chamado para inicializar o objeto de trabalho depois que todas as solicitações foram passadas ao `WorkerArchetype::Execute`).

```
void Terminate(void* pvParam) throw();
```

#### <a name="parameters"></a>Parâmetros

*pvParam*<br/>
Um parâmetro personalizado compreendido pela classe de trabalho. Também é passado para `WorkerArchetype::Initialize` e `WorkerArchetype::Execute`.

## <a name="see-also"></a>Consulte também

[Conceitos](../../atl/active-template-library-atl-concepts.md)<br/>
[Componentes de área de trabalho COM da ATL](../../atl/atl-com-desktop-components.md)
