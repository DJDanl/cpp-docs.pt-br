---
title: Estrutura IThreadProxy
ms.date: 11/04/2016
f1_keywords:
- IThreadProxy
- CONCRTRM/concurrency::IThreadProxy
- CONCRTRM/concurrency::IThreadProxy::IThreadProxy::GetId
- CONCRTRM/concurrency::IThreadProxy::IThreadProxy::SwitchOut
- CONCRTRM/concurrency::IThreadProxy::IThreadProxy::SwitchTo
- CONCRTRM/concurrency::IThreadProxy::IThreadProxy::YieldToSystem
helpviewer_keywords:
- IThreadProxy structure
ms.assetid: feb89241-a555-4e61-ad48-40add54daeca
ms.openlocfilehash: fc2fb2df06225a5c963fe39178c1b4a10f77953d
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81368137"
---
# <a name="ithreadproxy-structure"></a>Estrutura IThreadProxy

Uma abstração para um fio de execução. Dependendo da `SchedulerType` chave de política do agendador criado, o Gerenciador de recursos concederá a você um proxy de thread que é apoiado por um thread Win32 regular ou por um segmento de ums (ums) de modo de usuário. Os threads UMS são suportados em sistemas operacionais de 64 bits com a versão Windows 7 ou superior.

## <a name="syntax"></a>Sintaxe

```cpp
struct IThreadProxy;
```

## <a name="members"></a>Membros

### <a name="public-methods"></a>Métodos públicos

|Nome|Descrição|
|----------|-----------------|
|[IThreadProxy::GetId](#getid)|Retorna um identificador exclusivo para o proxy thread.|
|[IThreadProxy::SwitchOut](#switchout)|Desassocia o contexto da raiz do processador virtual subjacente.|
|[IThreadProxy::Switchto](#switchto)|Realiza um contexto cooperativo mudar do contexto de execução atual para outro.|
|[ithreadproxy::yieldtosystem](#yieldtosystem)|Faz com que o thread de chamada conceda a execução para outro thread que está pronto para ser executado no processador atual. O sistema operacional seleciona o próximo segmento a ser executado.|

## <a name="remarks"></a>Comentários

Os proxies de thread são acoplados aos contextos de execução representados pela interface `IExecutionContext` como meio de despachar o trabalho.

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

`IThreadProxy`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** concrtrm.h

**Namespace:** concurrency

## <a name="ithreadproxygetid-method"></a><a name="getid"></a>IThreadProxy::Método GetId

Retorna um identificador exclusivo para o proxy thread.

```cpp
virtual unsigned int GetId() const = 0;
```

### <a name="return-value"></a>Valor retornado

Um identificador inteiro único.

## <a name="ithreadproxyswitchout-method"></a><a name="switchout"></a>IThreadProxy::Método de saída de switch

Desassocia o contexto da raiz do processador virtual subjacente.

```cpp
virtual void SwitchOut(SwitchingProxyState switchState = Blocking) = 0;
```

### <a name="parameters"></a>Parâmetros

*switchEstado*<br/>
Indica o estado do proxy de segmento que está executando o switch. O parâmetro é `SwitchingProxyState`do tipo .

### <a name="remarks"></a>Comentários

Use `SwitchOut` se você precisar desassociar um contexto da raiz do processador virtual em que ele está sendo executado, por qualquer motivo. Dependendo do valor que você passar `switchState`para o parâmetro, e se ele está ou não executando em uma raiz de processador virtual, a chamada retornará imediatamente ou bloqueará o proxy de segmento associado ao contexto. É um erro `SwitchOut` chamar com o `Idle`parâmetro definido para . Fazê-lo resultará em uma exceção [invalid_argument.](../../../standard-library/invalid-argument-class.md)

`SwitchOut`é útil quando você deseja reduzir o número de raízes do processador virtual que seu agendador tem, seja porque o Gerenciador de recursos instruiu você a fazê-lo, ou porque você solicitou uma raiz de processador virtual com subscrição excessiva temporária, e está feito com ele. Neste caso, você deve invocar o método [IVirtualProcessorRoot::Remover](iexecutionresource-structure.md#remove) na raiz `SwitchOut` do processador `switchState` virtual, antes de fazer uma chamada para com o parâmetro definido como `Blocking`. Isso bloqueará o proxy do segmento e ele retomará a execução quando uma raiz de processador virtual diferente no agendador estiver disponível para executá-lo. O proxy do segmento de bloqueio `SwitchTo` pode ser retomado chamando a função para mudar para o contexto de execução deste proxy de segmento. Você também pode retomar o proxy de thread, usando seu contexto associado para ativar uma raiz de processador virtual. Para obter mais informações sobre como fazer isso, consulte [IVirtualProcessorRoot::Activate](ivirtualprocessorroot-structure.md#activate).

`SwitchOut`também pode ser usado quando você quiser reinicializar o processador virtual para que ele possa ser ativado no futuro, bloqueando o proxy do segmento ou temporariamente desvinculando-o da raiz do processador virtual em que ele está sendo executado, e o agendador para o qual ele está despachando funciona. Use `SwitchOut` com o `switchState` parâmetro `Blocking` definido para se desejar bloquear o proxy de segmento. Mais tarde, pode `SwitchTo` ser `IVirtualProcessorRoot::Activate` retomado usando um ou como observado acima. Use `SwitchOut` com o parâmetro `Nesting` definido para quando você quiser separar temporariamente este proxy de segmento da raiz do processador virtual em que ele está sendo executado, e o agendador com o qual o processador virtual está associado. A `SwitchOut` chamada com `switchState` o `Nesting` parâmetro definido enquanto ele estiver sendo executado em uma raiz de processador virtual fará com que a raiz seja reinicializada e o proxy atual do segmento continue sendo executado sem a necessidade de um. Considera-se que o proxy de thread deixou o agendador até que `Blocking` ele chame o método [IThreadProxy::SwitchOut](#switchout) com um momento posterior. A segunda `SwitchOut` chamada com o `Blocking` parâmetro definido destina-se a devolver o contexto a um `SwitchTo` estado `IVirtualProcessorRoot::Activate` bloqueado para que ele possa ser retomado por um ou no agendador de que se desvinculou. Como ele não estava sendo executado em uma raiz de processador virtual, nenhuma reinicialização ocorre.

Uma raiz de processador virtual reinicializada não é diferente de uma nova raiz de processador virtual que seu agendador foi concedido pelo Gerenciador de Recursos. Você pode usá-lo para execução ativando-o com um contexto de execução usando `IVirtualProcessorRoot::Activate`.

`SwitchOut`deve ser chamado `IThreadProxy` na interface que representa o segmento de execução atual ou os resultados são indefinidos.

Nas bibliotecas e cabeçalhos que foram enviados com o Visual Studio 2010, este método não teve um parâmetro e não reinicializou a raiz do processador virtual. Para preservar o comportamento antigo, `Blocking` o valor do parâmetro padrão é fornecido.

## <a name="ithreadproxyswitchto-method"></a><a name="switchto"></a>IThreadProxy::SwitchTo Method

Realiza um contexto cooperativo mudar do contexto de execução atual para outro.

```cpp
virtual void SwitchTo(
    _Inout_ IExecutionContext* pContext,
    SwitchingProxyState switchState) = 0;
```

### <a name="parameters"></a>Parâmetros

*pContext*<br/>
O contexto de execução para mudar cooperativamente para.

*switchEstado*<br/>
Indica o estado do proxy de segmento que está executando o switch. O parâmetro é `SwitchingProxyState`do tipo .

### <a name="remarks"></a>Comentários

Use este método para mudar de um contexto de execução para outro, a partir do método [IExecutionContext::Dispatch](iexecutioncontext-structure.md#dispatch) do primeiro contexto de execução. O método associa `pContext` o contexto de execução a um proxy de segmento se ele ainda não estiver associado a um. A propriedade do proxy atual do segmento é `switchState` determinada pelo valor especificado para o argumento.

Use o `Idle` valor quando quiser retornar o proxy de thread em execução no momento para o Gerenciador de recursos. A `SwitchTo` chamada com `switchState` o `Idle` parâmetro definido `pContext` fará com que o contexto de execução comece a ser executado no recurso de execução subjacente. A propriedade deste proxy de segmento é transferida para o Gerenciador de `Dispatch` recursos, `SwitchTo` e espera-se que você retorne do método do contexto de execução logo após o retorno, a fim de concluir a transferência. O contexto de execução que o proxy thread estava despachando é dissociado do proxy thread, e o agendador é livre para reutilizá-lo ou destruí-lo como achar melhor.

Use o `Blocking` valor quando quiser que este proxy de segmento insira um estado bloqueado. A `SwitchTo` chamada com `switchState` o `Blocking` parâmetro definido `pContext` fará com que o contexto de execução comece a ser executado e bloqueie o proxy atual do segmento até que ele seja retomado. O agendador mantém a propriedade do proxy thread `Blocking` quando o proxy thread está no estado. O proxy do segmento de bloqueio `SwitchTo` pode ser retomado chamando a função para mudar para o contexto de execução deste proxy de segmento. Você também pode retomar o proxy de thread, usando seu contexto associado para ativar uma raiz de processador virtual. Para obter mais informações sobre como fazer isso, consulte [IVirtualProcessorRoot::Activate](ivirtualprocessorroot-structure.md#activate).

Use o `Nesting` valor quando quiser separar temporariamente esse proxy de segmento da raiz do processador virtual em que está sendo executado, e o agendador para o qual está despachando funciona. A `SwitchTo` chamada com `switchState` o `Nesting` parâmetro definido `pContext` fará com que o contexto de execução comece a ser executado e o proxy atual do segmento também continua sendo executado sem a necessidade de uma raiz de processador virtual. Considera-se que o proxy de thread deixou o agendador até chamar o método [IThreadProxy::SwitchOut](#switchout) posteriormente. O `IThreadProxy::SwitchOut` método pode bloquear o proxy de thread até que uma raiz de processador virtual esteja disponível para reprogramá-lo.

`SwitchTo`deve ser chamado `IThreadProxy` na interface que representa o segmento de execução atual ou os resultados são indefinidos. A função `invalid_argument` é aquecida se o parâmetro `pContext` estiver definido como `NULL`.

## <a name="ithreadproxyyieldtosystem-method"></a><a name="yieldtosystem"></a>IThreadProxy::YieldToSystem Method

Faz com que o thread de chamada conceda a execução para outro thread que está pronto para ser executado no processador atual. O sistema operacional seleciona o próximo segmento a ser executado.

```cpp
virtual void YieldToSystem() = 0;
```

### <a name="remarks"></a>Comentários

Quando chamado por um proxy de thread `YieldToSystem` apoiado por um segmento `SwitchToThread`regular do Windows, comporta-se exatamente como a função Windows . No entanto, quando chamada de threads ums `SwitchToThread` (ums) de modo de usuário, a função delega a tarefa de escolher o próximo segmento para executar para o agendador do modo de usuário, não para o sistema operacional. Para obter o efeito desejado de mudar para um segmento `YieldToSystem`pronto diferente no sistema, use .

`YieldToSystem`deve ser chamado `IThreadProxy` na interface que representa o segmento de execução atual ou os resultados são indefinidos.

## <a name="see-also"></a>Confira também

[namespace de concorrência](concurrency-namespace.md)<br/>
[Estrutura IExecutionContext](iexecutioncontext-structure.md)<br/>
[Estrutura IScheduler](ischeduler-structure.md)<br/>
[Estrutura IVirtualProcessorRoot](ivirtualprocessorroot-structure.md)
