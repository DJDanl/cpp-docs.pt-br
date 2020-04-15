---
title: Classe AsyncBase
ms.date: 10/08/2018
ms.topic: reference
f1_keywords:
- async/Microsoft::WRL::AsyncBase
- async/Microsoft::WRL::AsyncBase::AsyncBase
- async/Microsoft::WRL::AsyncBase::Cancel
- async/Microsoft::WRL::AsyncBase::CheckValidStateForDelegateCall
- async/Microsoft::WRL::AsyncBase::CheckValidStateForResultsCall
- async/Microsoft::WRL::AsyncBase::Close
- async/Microsoft::WRL::AsyncBase::ContinueAsyncOperation
- async/Microsoft::WRL::AsyncBase::CurrentStatus
- async/Microsoft::WRL::AsyncBase::ErrorCode
- async/Microsoft::WRL::AsyncBase::FireCompletion
- async/Microsoft::WRL::AsyncBase::FireProgress
- async/Microsoft::WRL::AsyncBase::get_ErrorCode
- async/Microsoft::WRL::AsyncBase::get_Id
- async/Microsoft::WRL::AsyncBase::get_Status
- async/Microsoft::WRL::AsyncBase::GetOnComplete
- async/Microsoft::WRL::AsyncBase::GetOnProgress
- async/Microsoft::WRL::AsyncBase::OnCancel
- async/Microsoft::WRL::AsyncBase::OnClose
- async/Microsoft::WRL::AsyncBase::OnStart
- async/Microsoft::WRL::AsyncBase::put_Id
- async/Microsoft::WRL::AsyncBase::PutOnComplete
- async/Microsoft::WRL::AsyncBase::PutOnProgress
- async/Microsoft::WRL::AsyncBase::TryTransitionToCompleted
- async/Microsoft::WRL::AsyncBase::TryTransitionToError
helpviewer_keywords:
- Microsoft::WRL::AsyncBase class
- Microsoft::WRL::AsyncBase::AsyncBase, constructor
- Microsoft::WRL::AsyncBase::Cancel method
- Microsoft::WRL::AsyncBase::CheckValidStateForDelegateCall method
- Microsoft::WRL::AsyncBase::CheckValidStateForResultsCall method
- Microsoft::WRL::AsyncBase::Close method
- Microsoft::WRL::AsyncBase::ContinueAsyncOperation method
- Microsoft::WRL::AsyncBase::CurrentStatus method
- Microsoft::WRL::AsyncBase::ErrorCode method
- Microsoft::WRL::AsyncBase::FireCompletion method
- Microsoft::WRL::AsyncBase::FireProgress method
- Microsoft::WRL::AsyncBase::get_ErrorCode method
- Microsoft::WRL::AsyncBase::get_Id method
- Microsoft::WRL::AsyncBase::get_Status method
- Microsoft::WRL::AsyncBase::GetOnComplete method
- Microsoft::WRL::AsyncBase::GetOnProgress method
- Microsoft::WRL::AsyncBase::OnCancel method
- Microsoft::WRL::AsyncBase::OnClose method
- Microsoft::WRL::AsyncBase::OnStart method
- Microsoft::WRL::AsyncBase::put_Id method
- Microsoft::WRL::AsyncBase::PutOnComplete method
- Microsoft::WRL::AsyncBase::PutOnProgress method
- Microsoft::WRL::AsyncBase::TryTransitionToCompleted method
- Microsoft::WRL::AsyncBase::TryTransitionToError method
ms.assetid: 64259b9b-f427-4ffd-a611-e7a2f82362b2
ms.openlocfilehash: 0254aa4dc243eeffa43850c437a833a6530c01e2
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81371868"
---
# <a name="asyncbase-class"></a>Classe AsyncBase

Implementa a máquina de estado assíncrono do Windows Runtime.

## <a name="syntax"></a>Sintaxe

```cpp
template <
    typename TComplete,
    typename TProgress = Details::Nil,
    AsyncResultType resultType = SingleResult
>
class AsyncBase : public AsyncBase<TComplete, Details::Nil, resultType>;

template <typename TComplete, AsyncResultType resultType>
class AsyncBase<TComplete, Details::Nil, resultType> :
    public Microsoft::WRL::Implements<IAsyncInfo>;
```

### <a name="parameters"></a>Parâmetros

*TComplete*<br/>
Um manipulador de eventos que é chamado quando uma operação assíncrona é concluída.

*TProgress*<br/>
Um manipulador de eventos que é chamado quando uma operação assíncrona em execução relata o progresso atual da operação.

*Resulttype*<br/>
Um dos valores de enumeração [AsyncResultType.](asyncresulttype-enumeration.md) Por padrão, `SingleResult`.

## <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores públicos

Nome                               | Descrição
---------------------------------- | -------------------------------------------------
[Base de sincronização::AsyncBase](#asyncbase) | Inicializa uma instância da classe `AsyncBase`.

### <a name="public-methods"></a>Métodos públicos

Nome                                         | Descrição
-------------------------------------------- | -------------------------------------------------------------------------------------
[AsyncBase::Cancele](#cancel)                 | Cancela uma operação assíncrona.
[AsyncBase::Fechar](#close)                   | Encerra a operação assíncrona.
[AsyncBase::FireComplet](#firecompletion) | Invoca o manipulador de eventos de conclusão ou redefine o delegado de progresso interno.
[AsyncBase::FireProgress](#fireprogress)     | Invoca o manipulador de eventos de progresso atual.
[AsyncBase::get_ErrorCode](#get-errorcode)   | Recupera o código de erro da operação assíncrona atual.
[AsyncBase::get_Id](#get-id)                 | Recupera a alça da operação assíncrona.
[AsyncBase::get_Status](#get-status)         | Recupera um valor que indica o status da operação assíncrona.
[AsyncBase::GetOnComplete](#getoncomplete)   | Copia o endereço do manipulador de eventos de conclusão atual para a variável especificada.
[Base de sincronização::GetOnProgress](#getonprogress)   | Copia o endereço do manipulador de eventos de progresso atual para a variável especificada.
[AsyncBase::put_Id](#put-id)                 | Define a alça da operação assíncrona.
[AsyncBase::PutOnComplete](#putoncomplete)   | Define o endereço do manipulador de eventos de conclusão para o valor especificado.
[Base de async::PutOnProgress](#putonprogress)   | Define o endereço do manipulador de eventos de progresso para o valor especificado.

### <a name="protected-methods"></a>Métodos Protegidos

Nome                                                                         | Descrição
---------------------------------------------------------------------------- | ----------------------------------------------------------------------------------------------------------
[AsyncBase::checkvalidStateForDelegateCall](#checkvalidstatefordelegatecall) | Testa se as propriedades do delegado podem ser modificadas no estado assíncrono atual.
[AsyncBase::checkvalidStateForResultsCall](#checkvalidstateforresultscall)   | Testa se os resultados de uma operação assíncrona podem ser coletados no estado assíncrono atual.
[AsyncBase::ContinueAsyncOperation](#continueasyncoperation)                 | Determina se a operação assíncrona deve continuar sendo processada ou deve parar.
[AsyncBase::CurrentStatus](#currentstatus)                                   | Recupera o status da operação assíncrona atual.
[AsyncBase::ErrorCode](#errorcode)                                           | Recupera o código de erro da operação assíncrona atual.
[AsyncBase::OnCancel](#oncancel)                                             | Quando substituído em uma classe derivada, cancela uma operação assíncrona.
[AsyncBase::OnClose](#onclose)                                               | Quando substituído em uma classe derivada, fecha uma operação assíncrona.
[AsyncBase::OnStart](#onstart)                                               | Quando substituído em uma classe derivada, inicia uma operação assíncrona.
[AsyncBase::Iniciar](#start)                                                   | Começa a operação assíncrona.
[AsyncBase::TrytransitionToCompleted](#trytransitiontocompleted)             | Indica se a operação assíncrona atual foi concluída.
[AsyncBase::TryTransitionToError](#trytransitiontoerror)                     | Indica se o código de erro especificado pode modificar o estado de erro interno.

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

`AsyncBase`

`AsyncBase`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** async.h

**Espaço de nome:** Microsoft::WRL

## <a name="asyncbaseasyncbase"></a><a name="asyncbase"></a>Base de sincronização::AsyncBase

Inicializa uma instância da classe `AsyncBase`.

```cpp
AsyncBase();
```

## <a name="asyncbasecancel"></a><a name="cancel"></a>AsyncBase::Cancele

Cancela uma operação assíncrona.

```cpp
STDMETHOD(
   Cancel
)(void);
```

### <a name="return-value"></a>Valor retornado

Por padrão, sempre retorna S_OK.

### <a name="remarks"></a>Comentários

`Cancel()`é uma implementação padrão de `IAsyncInfo::Cancel`, e não faz nenhum trabalho real. Para realmente cancelar uma operação assíncrona, anule o `OnCancel()` método virtual puro.

## <a name="asyncbasecheckvalidstatefordelegatecall"></a><a name="checkvalidstatefordelegatecall"></a>AsyncBase::checkvalidStateForDelegateCall

Testa se as propriedades do delegado podem ser modificadas no estado assíncrono atual.

```cpp
inline HRESULT CheckValidStateForDelegateCall();
```

### <a name="return-value"></a>Valor retornado

S_OK se as propriedades do delegado puderem ser modificadas; caso contrário, E_ILLEGAL_METHOD_CALL.

## <a name="asyncbasecheckvalidstateforresultscall"></a><a name="checkvalidstateforresultscall"></a>AsyncBase::checkvalidStateForResultsCall

Testa se os resultados de uma operação assíncrona podem ser coletados no estado assíncrono atual.

```cpp
inline HRESULT CheckValidStateForResultsCall();
```

### <a name="return-value"></a>Valor retornado

S_OK se os resultados podem ser coletados; caso contrário, E_ILLEGAL_METHOD_CALLE_ILLEGAL_METHOD_CALL.

## <a name="asyncbaseclose"></a><a name="close"></a>AsyncBase::Fechar

Encerra a operação assíncrona.

```cpp
STDMETHOD(
   Close
)(void) override;
```

### <a name="return-value"></a>Valor retornado

S_OK se a operação fechar ou já estiver encerrada; caso contrário, E_ILLEGAL_STATE_CHANGE.

### <a name="remarks"></a>Comentários

`Close()`é uma implementação padrão de `IAsyncInfo::Close`, e não faz nenhum trabalho real. Para realmente fechar uma operação assíncrona, anular o `OnClose()` método virtual puro.

## <a name="asyncbasecontinueasyncoperation"></a><a name="continueasyncoperation"></a>AsyncBase::ContinueAsyncOperation

Determina se a operação assíncrona deve continuar sendo processada ou deve parar.

```cpp
inline bool ContinueAsyncOperation();
```

### <a name="return-value"></a>Valor retornado

**verdade** se o estado atual da operação assíncrona for *iniciado,* o que significa que a operação deve continuar. Caso contrário, **falso,** o que significa que a operação deve parar.

## <a name="asyncbasecurrentstatus"></a><a name="currentstatus"></a>AsyncBase::CurrentStatus

Recupera o status da operação assíncrona atual.

```cpp
inline void CurrentStatus(
   Details::AsyncStatusInternal *status
);
```

### <a name="parameters"></a>Parâmetros

*status*<br/>
O local onde esta operação armazena o status atual.

### <a name="remarks"></a>Comentários

Esta operação é segura para fios.

## <a name="asyncbaseerrorcode"></a><a name="errorcode"></a>AsyncBase::ErrorCode

Recupera o código de erro da operação assíncrona atual.

```cpp
inline void ErrorCode(
   HRESULT *error
);
```

### <a name="parameters"></a>Parâmetros

*error*<br/>
O local onde esta operação armazena o código de erro atual.

### <a name="remarks"></a>Comentários

Esta operação é segura para fios.

## <a name="asyncbasefirecompletion"></a><a name="firecompletion"></a>AsyncBase::FireComplet

Invoca o manipulador de eventos de conclusão ou redefine o delegado de progresso interno.

```cpp
void FireCompletion(
   void
) override;

virtual void FireCompletion();
```

### <a name="remarks"></a>Comentários

A primeira `FireCompletion()` versão do redefine a variável delegado de progresso interno. A segunda versão invoca o manipulador de eventos de conclusão se a operação assíncrona estiver concluída.

## <a name="asyncbasefireprogress"></a><a name="fireprogress"></a>AsyncBase::FireProgress

Invoca o manipulador de eventos de progresso atual.

```cpp
void FireProgress(
   const typename ProgressTraits::Arg2Type arg
);
```

### <a name="parameters"></a>Parâmetros

*Arg*<br/>
O método de manipulador de eventos para invocar.

### <a name="remarks"></a>Comentários

`ProgressTraits`é derivado da [Estrutura ArgTraitsHelper](argtraitshelper-structure.md).

## <a name="asyncbaseget_errorcode"></a><a name="get-errorcode"></a>AsyncBase::get_ErrorCode

Recupera o código de erro da operação assíncrona atual.

```cpp
STDMETHOD(
   get_ErrorCode
)(HRESULT* errorCode) override;
```

### <a name="parameters"></a>Parâmetros

*errorCode*<br/>
O local onde o código de erro atual é armazenado.

### <a name="return-value"></a>Valor retornado

S_OK se for bem sucedido; caso contrário, E_ILLEGAL_METHOD_CALL se a operação assíncrona atual for encerrada.

## <a name="asyncbaseget_id"></a><a name="get-id"></a>AsyncBase::get_Id

Recupera a alça da operação assíncrona.

```cpp
STDMETHOD(
   get_Id
)(unsigned int *id) override;
```

### <a name="parameters"></a>Parâmetros

*id*<br/>
O local onde a alça deve ser armazenada.

### <a name="return-value"></a>Valor retornado

S_OK se for bem sucedido; caso contrário, E_ILLEGAL_METHOD_CALL.

### <a name="remarks"></a>Comentários

Esse método implementa `IAsyncInfo::get_Id`.

## <a name="asyncbaseget_status"></a><a name="get-status"></a>AsyncBase::get_Status

Recupera um valor que indica o status da operação assíncrona.

```cpp
STDMETHOD(
   get_Status
)(AsyncStatus *status) override;
```

### <a name="parameters"></a>Parâmetros

*status*<br/>
O local onde o status deve ser armazenado. Para obter mais `Windows::Foundation::AsyncStatus` informações, consulte enumeração.

### <a name="return-value"></a>Valor retornado

S_OK se for bem sucedido; caso contrário, E_ILLEGAL_METHOD_CALL.

### <a name="remarks"></a>Comentários

Esse método implementa `IAsyncInfo::get_Status`.

## <a name="asyncbasegetoncomplete"></a><a name="getoncomplete"></a>AsyncBase::GetOnComplete

Copia o endereço do manipulador de eventos de conclusão atual para a variável especificada.

```cpp
STDMETHOD(
   GetOnComplete
)(TComplete** completeHandler);
```

### <a name="parameters"></a>Parâmetros

*completeHandler*<br/>
O local onde o endereço do manipulador de eventos de conclusão atual é armazenado.

### <a name="return-value"></a>Valor retornado

S_OK se for bem sucedido; caso contrário, E_ILLEGAL_METHOD_CALL.

## <a name="asyncbasegetonprogress"></a><a name="getonprogress"></a>Base de sincronização::GetOnProgress

Copia o endereço do manipulador de eventos de progresso atual para a variável especificada.

```cpp
STDMETHOD(
   GetOnProgress
)(TProgress** progressHandler);
```

### <a name="parameters"></a>Parâmetros

*progressHandler*<br/>
O local onde o endereço do manipulador de eventos de progresso atual é armazenado.

### <a name="return-value"></a>Valor retornado

S_OK se for bem sucedido; caso contrário, E_ILLEGAL_METHOD_CALL.

## <a name="asyncbaseoncancel"></a><a name="oncancel"></a>AsyncBase::OnCancel

Quando substituído em uma classe derivada, cancela uma operação assíncrona.

```cpp
virtual void OnCancel(
   void
) = 0;
```

## <a name="asyncbaseonclose"></a><a name="onclose"></a>AsyncBase::OnClose

Quando substituído em uma classe derivada, fecha uma operação assíncrona.

```cpp
virtual void OnClose(
   void
) = 0;
```

## <a name="asyncbaseonstart"></a><a name="onstart"></a>AsyncBase::OnStart

Quando substituído em uma classe derivada, inicia uma operação assíncrona.

```cpp
virtual HRESULT OnStart(
   void
) = 0;
```

## <a name="asyncbaseput_id"></a><a name="put-id"></a>AsyncBase::put_Id

Define a alça da operação assíncrona.

```cpp
STDMETHOD(
   put_Id
)(const unsigned int id);
```

### <a name="parameters"></a>Parâmetros

*id*<br/>
Uma alça não zero.

### <a name="return-value"></a>Valor retornado

S_OK se for bem sucedido; E_INVALIDARG ou E_ILLEGAL_METHOD_CALL.

## <a name="asyncbaseputoncomplete"></a><a name="putoncomplete"></a>AsyncBase::PutOnComplete

Define o endereço do manipulador de eventos de conclusão para o valor especificado.

```cpp
STDMETHOD(
   PutOnComplete
)(TComplete* completeHandler);
```

### <a name="parameters"></a>Parâmetros

*completeHandler*<br/>
O endereço para o qual o manipulador de eventos de conclusão está definido.

### <a name="return-value"></a>Valor retornado

S_OK se for bem sucedido; caso contrário, E_ILLEGAL_METHOD_CALL.

## <a name="asyncbaseputonprogress"></a><a name="putonprogress"></a>Base de async::PutOnProgress

Define o endereço do manipulador de eventos de progresso para o valor especificado.

```cpp
STDMETHOD(
   PutOnProgress
)(TProgress* progressHandler);
```

### <a name="parameters"></a>Parâmetros

*progressHandler*<br/>
O endereço para o qual o manipulador de eventos de progresso está definido.

### <a name="return-value"></a>Valor retornado

S_OK se for bem sucedido; caso contrário, E_ILLEGAL_METHOD_CALL.

## <a name="asyncbasestart"></a><a name="start"></a>AsyncBase::Iniciar

Começa a operação assíncrona.

```cpp
STDMETHOD(
   Start
)(void);
```

### <a name="return-value"></a>Valor retornado

S_OK se a operação começar ou já estiver iniciada; caso contrário, E_ILLEGAL_STATE_CHANGE.

### <a name="remarks"></a>Comentários

`Start()`é um método protegido que não é visível externamente porque as operações de sincronia "hot start" antes de retornar ao chamador.

## <a name="asyncbasetrytransitiontocompleted"></a><a name="trytransitiontocompleted"></a>AsyncBase::TrytransitionToCompleted

Indica se a operação assíncrona atual foi concluída.

```cpp
bool TryTransitionToCompleted(
   void
);
```

### <a name="return-value"></a>Valor retornado

**verdade** se a operação assíncrona tiver sido concluída; caso contrário, **falso**.

## <a name="asyncbasetrytransitiontoerror"></a><a name="trytransitiontoerror"></a>AsyncBase::TryTransitionToError

Indica se o código de erro especificado pode modificar o estado de erro interno.

```cpp
bool TryTransitionToError(
   const HRESULT error
);
```

### <a name="parameters"></a>Parâmetros

*error*<br/>
Um erro HRESULT.

### <a name="return-value"></a>Valor retornado

**verdade** se o estado de erro interno foi alterado; caso contrário, **falso**.

### <a name="remarks"></a>Comentários

Esta operação modifica o estado de erro somente se o estado de erro já estiver definido como S_OK. Esta operação não tem efeito se o estado de erro já estiver errado, cancelado, concluído ou fechado.
