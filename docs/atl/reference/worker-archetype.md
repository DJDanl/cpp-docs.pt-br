---
title: Arquétipo de trabalho
ms.date: 11/04/2016
helpviewer_keywords:
- Worker archetype
ms.assetid: 834145cd-09d3-4149-bc99-620e1871cbfb
ms.openlocfilehash: 2e57c575ed778184cf319bb84e61f585fcfa2111
ms.sourcegitcommit: 44eeb065c3148d0484de791080a3f963109744fc
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/18/2020
ms.locfileid: "79509335"
---
# <a name="worker-archetype"></a>Arquétipo de trabalho

As classes que estão em conformidade com o arquétipo de *trabalho* fornecem o código para processar itens de trabalho em fila em um pool de threads.

**Implementação**

Para implementar uma classe que esteja de acordo com esse arquétipo, a classe deve fornecer os seguintes recursos:

|Método|DESCRIÇÃO|
|------------|-----------------|
|[Initialize](#initialize)|Chamado para inicializar o objeto de trabalho antes de qualquer solicitação ser passada para [execução](#execute).|
|[Executar](#execute)|Chamado para processar um item de trabalho.|
|[Encerrar](#terminate)|Chamado para cancelar a inicialização do objeto de trabalho depois que todas as solicitações tiverem sido passadas para [execução](#execute).|

|Typedef|DESCRIÇÃO|
|-------------|-----------------|
|[RequestType](#requesttype)|Um typedef para o tipo de item de trabalho que pode ser processado pela classe Worker.|

Uma classe de *trabalho* típica tem esta aparência:

[!code-cpp[NVC_ATL_Utilities#137](../../atl/codesnippet/cpp/worker-archetype_1.cpp)]

**Implementações existentes**

Essas classes estão em conformidade com esse arquétipo:

|Classe|DESCRIÇÃO|
|-----------|-----------------|
|[CNonStatelessWorker](../../atl/reference/cnonstatelessworker-class.md)|Recebe solicitações do pool de threads e as passa para um objeto de trabalho que é criado e destruído para cada solicitação.|

**Uso**

Esses parâmetros de modelo esperam que a classe esteja em conformidade com esse arquétipo:

|Nome do parâmetro|Usado por|
|--------------------|-------------|
|*Funcionários*|[CThreadPool](../../atl/reference/cthreadpool-class.md)|
|*Funcionários*|[CNonStatelessWorker](../../atl/reference/cnonstatelessworker-class.md)|

### <a name="requirements"></a>Requisitos

**Cabeçalho:** atlutil. h

## <a name="execute"></a>WorkerArchetype:: execute

Chamado para processar um item de trabalho.

```
void Execute(
    RequestType request,
    void* pvWorkerParam,
    OVERLAPPED* pOverlapped);
```

#### <a name="parameters"></a>parâmetros

*solicitação*<br/>
O item de trabalho a ser processado. O item de trabalho é do mesmo tipo que `RequestType`.

*pvWorkerParam*<br/>
Um parâmetro personalizado compreendido pela classe Worker. Também passado para `WorkerArchetype::Initialize` e `Terminate`.

*pOverlapped*<br/>
Um ponteiro para a estrutura [sobreposta](/windows/win32/api/minwinbase/ns-minwinbase-overlapped) usada para criar a fila na qual os itens de trabalho foram enfileirados.

## <a name="initialize"></a>WorkerArchetype:: Initialize

Chamado para inicializar o objeto de trabalho antes de qualquer solicitação ser passada para `WorkerArchetype::Execute`.

```
BOOL Initialize(void* pvParam) throw();
```

#### <a name="parameters"></a>parâmetros

*pvParam*<br/>
Um parâmetro personalizado compreendido pela classe Worker. Também passado para `WorkerArchetype::Terminate` e `WorkerArchetype::Execute`.

### <a name="return-value"></a>Valor retornado

Retornar verdadeiro em caso de êxito, falso em caso de falha.

## <a name="requesttype"></a>WorkerArchetype:: RequestType

Um typedef para o tipo de item de trabalho que pode ser processado pela classe Worker.

```
typedef MyRequestType RequestType;
```

### <a name="remarks"></a>Comentários

Esse tipo deve ser usado como o primeiro parâmetro de `WorkerArchetype::Execute` e deve ser capaz de ser convertido de e para um ULONG_PTR.

## <a name="terminate"></a>WorkerArchetype:: Terminate

Chamado para cancelar a inicialização do objeto de trabalho depois que todas as solicitações forem passadas para `WorkerArchetype::Execute`).

```
void Terminate(void* pvParam) throw();
```

#### <a name="parameters"></a>parâmetros

*pvParam*<br/>
Um parâmetro personalizado compreendido pela classe Worker. Também passado para `WorkerArchetype::Initialize` e `WorkerArchetype::Execute`.

## <a name="see-also"></a>Confira também

[Conceitos](../../atl/active-template-library-atl-concepts.md)<br/>
[Componentes de área de trabalho COM da ATL](../../atl/atl-com-desktop-components.md)
