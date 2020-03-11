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
ms.openlocfilehash: b87694393af4634ec97d05070aa5513cd132098a
ms.sourcegitcommit: 3e8fa01f323bc5043a48a0c18b855d38af3648d4
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/06/2020
ms.locfileid: "78854112"
---
# <a name="ithreadproxy-structure"></a>Estrutura IThreadProxy

Uma abstração para um thread de execução. Dependendo da chave de política de `SchedulerType` do Agendador que você criar, o Gerenciador de recursos lhe concederá um proxy de thread que é apoiado por um Thread Win32 regular ou um thread de agendáveis (UMS) de modo de usuário. Os threads UMS têm suporte em sistemas operacionais de 64 bits com a versão Windows 7 e superior.

## <a name="syntax"></a>Sintaxe

```cpp
struct IThreadProxy;
```

## <a name="members"></a>Membros

### <a name="public-methods"></a>Métodos públicos

|Nome|DESCRIÇÃO|
|----------|-----------------|
|[IThreadProxy:: GetId](#getid)|Retorna um identificador exclusivo para o proxy de thread.|
|[IThreadProxy:: opção de desativação](#switchout)|Desassocia o contexto da raiz do processador virtual subjacente.|
|[IThreadProxy:: alternar para](#switchto)|Executa uma alternância de contexto cooperativo do contexto atualmente em execução para um diferente.|
|[IThreadProxy::YieldToSystem](#yieldtosystem)|Faz com que o thread de chamada conceda a execução para outro thread que está pronto para ser executado no processador atual. O sistema operacional seleciona o próximo thread a ser executado.|

## <a name="remarks"></a>Comentários

Os proxies de thread são acoplados aos contextos de execução representados pela interface `IExecutionContext` como um meio de expedição do trabalho.

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

`IThreadProxy`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** concrtrm. h

**Namespace:** simultaneidade

## <a name="getid"></a>Método IThreadProxy:: GetId

Retorna um identificador exclusivo para o proxy de thread.

```cpp
virtual unsigned int GetId() const = 0;
```

### <a name="return-value"></a>Valor retornado

Um identificador inteiro exclusivo.

## <a name="switchout"></a>Método IThreadProxy:: SwitchOut

Desassocia o contexto da raiz do processador virtual subjacente.

```cpp
virtual void SwitchOut(SwitchingProxyState switchState = Blocking) = 0;
```

### <a name="parameters"></a>parâmetros

*switchState*<br/>
Indica o estado do proxy de thread que está executando a opção. O parâmetro é do tipo `SwitchingProxyState`.

### <a name="remarks"></a>Comentários

Use `SwitchOut` se você precisar desassociar um contexto da raiz do processador virtual em que ele está sendo executado, por qualquer motivo. Dependendo do valor que você passa para o parâmetro `switchState`e se ele está sendo executado em uma raiz do processador virtual, a chamada retornará imediatamente ou bloqueará o proxy de thread associado ao contexto. É um erro chamar `SwitchOut` com o parâmetro definido como `Idle`. Isso resultará em uma exceção [invalid_argument](../../../standard-library/invalid-argument-class.md) .

`SwitchOut` é útil quando você deseja reduzir o número de raízes do processador virtual que seu Agendador tem, seja porque o Gerenciador de recursos o instruiu a fazer isso, ou porque você solicitou uma raiz de processador virtual sobreassinada temporária e foi feita com ela. Nesse caso, você deve invocar o método [IVirtualProcessorRoot:: Remove](iexecutionresource-structure.md#remove) na raiz do processador virtual, antes de fazer uma chamada para `SwitchOut` com o parâmetro `switchState` definido como `Blocking`. Isso bloqueará o proxy de thread e ele continuará a execução quando uma raiz de processador virtual diferente no Agendador estiver disponível para executá-lo. O proxy de thread de bloqueio pode ser retomado chamando a função `SwitchTo` para alternar para o contexto de execução desse proxy de thread. Você também pode retomar o proxy de thread usando seu contexto associado para ativar uma raiz de processador virtual. Para obter mais informações sobre como fazer isso, consulte [IVirtualProcessorRoot:: Activate](ivirtualprocessorroot-structure.md#activate).

`SwitchOut` também pode ser usado quando você deseja reinicializar o processador virtual para que ele possa ser ativado no futuro enquanto estiver bloqueando o proxy de thread ou temporariamente desanexando-o da raiz do processador virtual em que está sendo executado e o Agendador para o qual ele está expedindo o trabalho. Use `SwitchOut` com o parâmetro `switchState` definido como `Blocking` se você deseja bloquear o proxy de thread. Posteriormente, ele poderá ser retomado usando `SwitchTo` ou `IVirtualProcessorRoot::Activate` conforme observado acima. Use `SwitchOut` com o parâmetro definido como `Nesting` quando desejar desanexar temporariamente esse proxy de thread da raiz do processador virtual em que ele está sendo executado e o Agendador ao qual o processador virtual está associado. Chamar `SwitchOut` com o parâmetro `switchState` definido como `Nesting` enquanto ele está em execução em uma raiz do processador virtual fará com que a raiz seja reinicializada e o proxy de thread atual continue executando sem a necessidade de um. O proxy de thread é considerado como tendo deixado o Agendador até chamar o método [IThreadProxy:: SwitchOut](#switchout) com `Blocking` em um momento posterior. A segunda chamada para `SwitchOut` com o parâmetro definido como `Blocking` destina-se a retornar o contexto para um estado bloqueado, de forma que ele possa ser retomado pelo `SwitchTo` ou `IVirtualProcessorRoot::Activate` no Agendador do qual ele foi desanexado. Como não estava sendo executado em uma raiz do processador virtual, nenhuma reinicialização ocorre.

Uma raiz de processador virtual reinicializada não é diferente de uma raiz do processador virtual totalmente nova, seu Agendador foi concedido pelo Gerenciador de recursos. Você pode usá-lo para execução ativando-o com um contexto de execução usando `IVirtualProcessorRoot::Activate`.

`SwitchOut` deve ser chamado na interface `IThreadProxy` que representa o thread em execução no momento ou os resultados são indefinidos.

Nas bibliotecas e nos cabeçalhos fornecidos com o Visual Studio 2010, esse método não obteve um parâmetro e não reinicializou a raiz do processador virtual. Para preservar o comportamento antigo, o valor de parâmetro padrão de `Blocking` é fornecido.

## <a name="switchto"></a>Método IThreadProxy:: SwitchTo

Executa uma alternância de contexto cooperativo do contexto atualmente em execução para um diferente.

```cpp
virtual void SwitchTo(
    _Inout_ IExecutionContext* pContext,
    SwitchingProxyState switchState) = 0;
```

### <a name="parameters"></a>parâmetros

*pContext*<br/>
O contexto de execução para alternar para o.

*switchState*<br/>
Indica o estado do proxy de thread que está executando a opção. O parâmetro é do tipo `SwitchingProxyState`.

### <a name="remarks"></a>Comentários

Use este método para alternar de um contexto de execução para outro, do método [IExecutionContext::D ispatch](iexecutioncontext-structure.md#dispatch) do primeiro contexto de execução. O método associa o contexto de execução `pContext` com um proxy de thread se ele ainda não estiver associado a um. A propriedade do proxy de thread atual é determinada pelo valor especificado para o argumento `switchState`.

Use o valor `Idle` quando desejar retornar o proxy de thread em execução no momento para o Gerenciador de recursos. Chamar `SwitchTo` com o parâmetro `switchState` definido como `Idle` fará com que o contexto de execução `pContext` inicie a execução no recurso de execução subjacente. A propriedade desse proxy de thread é transferida para o Gerenciador de recursos, e você deve retornar do método `Dispatch` do contexto de execução logo após o retorno de `SwitchTo`, para concluir a transferência. O contexto de execução que o proxy de thread estava expedido é desassociado do proxy de thread, e o Agendador está livre para reutilizá-lo ou destruí-lo como se vê.

Use o valor `Blocking` quando desejar que esse proxy de thread Insira um estado bloqueado. Chamar `SwitchTo` com o parâmetro `switchState` definido como `Blocking` fará com que o contexto de execução `pContext` inicie a execução e bloqueie o proxy de thread atual até que seja retomado. O Agendador retém a propriedade do proxy de thread quando o proxy de thread está no estado `Blocking`. O proxy de thread de bloqueio pode ser retomado chamando a função `SwitchTo` para alternar para o contexto de execução desse proxy de thread. Você também pode retomar o proxy de thread usando seu contexto associado para ativar uma raiz de processador virtual. Para obter mais informações sobre como fazer isso, consulte [IVirtualProcessorRoot:: Activate](ivirtualprocessorroot-structure.md#activate).

Use o valor `Nesting` quando desejar desanexar temporariamente esse proxy de thread da raiz do processador virtual em que ele está sendo executado e o Agendador para o qual ele está expedindo o trabalho. Chamar `SwitchTo` com o parâmetro `switchState` definido como `Nesting` fará com que o contexto de execução `pContext` inicie a execução e o proxy de thread atual também continue sendo executado sem a necessidade de uma raiz do processador virtual. O proxy de thread é considerado como tendo deixado o Agendador até chamar o método [IThreadProxy:: SwitchOut](#switchout) em um momento posterior. O método `IThreadProxy::SwitchOut` poderia bloquear o proxy de thread até que uma raiz do processador virtual esteja disponível para reagendá-lo.

`SwitchTo` deve ser chamado na interface `IThreadProxy` que representa o thread em execução no momento ou os resultados são indefinidos. A função gera `invalid_argument` se o parâmetro `pContext` estiver definido como `NULL`.

## <a name="yieldtosystem"></a>Método IThreadProxy:: YieldToSystem

Faz com que o thread de chamada conceda a execução para outro thread que está pronto para ser executado no processador atual. O sistema operacional seleciona o próximo thread a ser executado.

```cpp
virtual void YieldToSystem() = 0;
```

### <a name="remarks"></a>Comentários

Quando chamado por um proxy de thread apoiado por um thread normal do Windows, `YieldToSystem` se comporta exatamente como a função do Windows `SwitchToThread`. No entanto, quando chamado de threads do modo de usuário agendáveis (UMS), a função `SwitchToThread` delega a tarefa de escolher o próximo thread a ser executado no Agendador de modo de usuário, não no sistema operacional. Para obter o efeito desejado de alternar para um thread pronto diferente no sistema, use `YieldToSystem`.

`YieldToSystem` deve ser chamado na interface `IThreadProxy` que representa o thread em execução no momento ou os resultados são indefinidos.

## <a name="see-also"></a>Confira também

[Namespace de simultaneidade](concurrency-namespace.md)<br/>
[Estrutura IExecutionContext](iexecutioncontext-structure.md)<br/>
[Estrutura IScheduler](ischeduler-structure.md)<br/>
[Estrutura IVirtualProcessorRoot](ivirtualprocessorroot-structure.md)
