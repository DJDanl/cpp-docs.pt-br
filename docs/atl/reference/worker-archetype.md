---
title: Arquétipo operário
ms.date: 11/04/2016
helpviewer_keywords:
- Worker archetype
ms.assetid: 834145cd-09d3-4149-bc99-620e1871cbfb
ms.openlocfilehash: b0b32232d7386df0c0f13a1c3af1003369b906e0
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81329341"
---
# <a name="worker-archetype"></a>Arquétipo operário

As classes que estão em conformidade com o arquétipo do *trabalhador* fornecem o código para processar itens de trabalho enfileirados em um pool de segmentos.

**Implementação**

Para implementar uma classe em conformidade com este arquétipo, a classe deve fornecer as seguintes características:

|Método|Descrição|
|------------|-----------------|
|[Inicializar](#initialize)|Chamado para inicializar o objeto do trabalhador antes que quaisquer solicitações sejam passadas para [Executar](#execute).|
|[Executar](#execute)|Chamado para processar um item de trabalho.|
|[Encerrar](#terminate)|Chamado para desinicializar o objeto do trabalhador depois de todos os pedidos terem sido passados para [Executar](#execute).|

|Typedef|Descrição|
|-------------|-----------------|
|[RequestType](#requesttype)|Um typedef para o tipo de item de trabalho que pode ser processado pela classe trabalhadora.|

Uma típica classe *operária* é assim:

[!code-cpp[NVC_ATL_Utilities#137](../../atl/codesnippet/cpp/worker-archetype_1.cpp)]

**Implementações existentes**

Estas classes estão em conformidade com este arquétipo:

|Classe|Descrição|
|-----------|-----------------|
|[Cnonstatelessworker](../../atl/reference/cnonstatelessworker-class.md)|Recebe solicitações do pool de segmentos e as repassa para um objeto de trabalhador que é criado e destruído para cada solicitação.|

**Usar**

Esses parâmetros de modelo esperam que a classe esteja em conformidade com este arquétipo:

|Nome do parâmetro|Usado por|
|--------------------|-------------|
|*Trabalho*|[Cthreadpool](../../atl/reference/cthreadpool-class.md)|
|*Trabalho*|[Cnonstatelessworker](../../atl/reference/cnonstatelessworker-class.md)|

### <a name="requirements"></a>Requisitos

**Cabeçalho:** atlutil.h

## <a name="workerarchetypeexecute"></a><a name="execute"></a>Arquiquelo do trabalhador::Executar

Chamado para processar um item de trabalho.

```
void Execute(
    RequestType request,
    void* pvWorkerParam,
    OVERLAPPED* pOverlapped);
```

#### <a name="parameters"></a>Parâmetros

*Solicitação*<br/>
O item de trabalho a ser processado. O item de trabalho é `RequestType`do mesmo tipo que .

*pvWorkerParam*<br/>
Um parâmetro personalizado compreendido pela classe trabalhadora. Também passou `WorkerArchetype::Initialize` `Terminate`para e .

*pSobreposição*<br/>
Um ponteiro para a estrutura [SOBREPOSTA](/windows/win32/api/minwinbase/ns-minwinbase-overlapped) usada para criar a fila em que os itens de trabalho estavam enfileirados.

## <a name="workerarchetypeinitialize"></a><a name="initialize"></a>Arquivo do trabalhador::Inicializar

Chamado para inicializar o objeto do `WorkerArchetype::Execute`trabalhador antes que quaisquer solicitações sejam passadas para .

```
BOOL Initialize(void* pvParam) throw();
```

#### <a name="parameters"></a>Parâmetros

*Pvparam*<br/>
Um parâmetro personalizado compreendido pela classe trabalhadora. Também passou `WorkerArchetype::Terminate` `WorkerArchetype::Execute`para e .

### <a name="return-value"></a>Valor retornado

Return TRUE on success, FALSE on failure.

## <a name="workerarchetyperequesttype"></a><a name="requesttype"></a>Arquivo do trabalhador::RequestType

Um typedef para o tipo de item de trabalho que pode ser processado pela classe trabalhadora.

```
typedef MyRequestType RequestType;
```

### <a name="remarks"></a>Comentários

Este tipo deve ser usado como `WorkerArchetype::Execute` o primeiro parâmetro e deve ser capaz de ser lançado de e para uma ULONG_PTR.

## <a name="workerarchetypeterminate"></a><a name="terminate"></a>Arquiquelo do trabalhador::Terminar

Chamado para desinicializar o objeto do `WorkerArchetype::Execute`trabalhador depois de todos os pedidos terem sido passados para ).

```
void Terminate(void* pvParam) throw();
```

#### <a name="parameters"></a>Parâmetros

*Pvparam*<br/>
Um parâmetro personalizado compreendido pela classe trabalhadora. Também passou `WorkerArchetype::Initialize` `WorkerArchetype::Execute`para e .

## <a name="see-also"></a>Confira também

[Conceitos](../../atl/active-template-library-atl-concepts.md)<br/>
[Componentes de área de trabalho COM da ATL](../../atl/atl-com-desktop-components.md)
