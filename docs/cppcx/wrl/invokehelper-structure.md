---
title: Estrutura InvokeHelper
ms.date: 10/18/2018
ms.topic: reference
f1_keywords:
- event/Microsoft::WRL::Details::InvokeHelper
- event/Microsoft::WRL::Details::InvokeHelper::callback_
- event/Microsoft::WRL::Details::InvokeHelper::Invoke
- event/Microsoft::WRL::Details::InvokeHelper::InvokeHelper
helpviewer_keywords:
- Microsoft::WRL::Details::InvokeHelper structure
- Microsoft::WRL::Details::callback_ data member
- Microsoft::WRL::Details::Invoke method
- Microsoft::WRL::Details::InvokeHelper, constructor
ms.assetid: 555ad2bc-4dd6-4e65-a2e2-1242c395f0e5
ms.openlocfilehash: 9cb4e166628a6b5e7671494446d467e73c9f8cc3
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81371379"
---
# <a name="invokehelper-structure"></a>Estrutura InvokeHelper

Suporta a infra-estrutura WRL e não se destina a ser usado diretamente do seu código.

## <a name="syntax"></a>Sintaxe

```cpp
template<typename TDelegateInterface, typename TCallback, unsigned int argCount>
struct InvokeHelper;

template<typename TDelegateInterface, typename TCallback>
struct InvokeHelper<TDelegateInterface, TCallback, 0> :
    public Microsoft::WRL::RuntimeClass<
        RuntimeClassFlags<Delegate>,
        TDelegateInterface
    >;

template<typename TDelegateInterface, typename TCallback>
struct InvokeHelper<TDelegateInterface, TCallback, 1> :
    public Microsoft::WRL::RuntimeClass<
        RuntimeClassFlags<Delegate>,
        TDelegateInterface
    >;

template<typename TDelegateInterface, typename TCallback>
struct InvokeHelper<TDelegateInterface, TCallback, 2> :
    public Microsoft::WRL::RuntimeClass<
        RuntimeClassFlags<Delegate>,
        TDelegateInterface
    >;

template<typename TDelegateInterface, typename TCallback>
struct InvokeHelper<TDelegateInterface, TCallback, 3> :
    public Microsoft::WRL::RuntimeClass<
        RuntimeClassFlags<Delegate>,
        TDelegateInterface
    >;

template<typename TDelegateInterface, typename TCallback>
struct InvokeHelper<TDelegateInterface, TCallback, 4> :
    Microsoft::WRL::RuntimeClass<
        RuntimeClassFlags<Delegate>,
        TDelegateInterface
    >;

template<typename TDelegateInterface, typename TCallback>
struct InvokeHelper<TDelegateInterface, TCallback, 5> :
    Microsoft::WRL::RuntimeClass<
        RuntimeClassFlags<Delegate>,
        TDelegateInterface
    >;

template<typename TDelegateInterface, typename TCallback>
struct InvokeHelper<TDelegateInterface, TCallback, 6> :
    Microsoft::WRL::RuntimeClass<
        RuntimeClassFlags<Delegate>,
        TDelegateInterface
    >;

template<typename TDelegateInterface, typename TCallback>
struct InvokeHelper<TDelegateInterface, TCallback, 7> :
    Microsoft::WRL::RuntimeClass<
        RuntimeClassFlags<Delegate>,
        TDelegateInterface
    >;

template<typename TDelegateInterface, typename TCallback>
struct InvokeHelper<TDelegateInterface, TCallback, 8> :
    Microsoft::WRL::RuntimeClass<
        RuntimeClassFlags<Delegate>,
        TDelegateInterface
    >;

template<typename TDelegateInterface, typename TCallback>
struct InvokeHelper<TDelegateInterface, TCallback, 9> :
    Microsoft::WRL::RuntimeClass<
        RuntimeClassFlags<Delegate>,
        TDelegateInterface
    >;
```

### <a name="parameters"></a>Parâmetros

*Interface de TDelegate*<br/>
O tipo de interface do delegado.

*TCallback*<br/>
O tipo de função do manipulador de eventos.

*Argcount*<br/>
O número de argumentos em uma `InvokeHelper` especialização.

## <a name="remarks"></a>Comentários

Fornece uma implementação do `Invoke()` método com base no número e tipo de argumentos especificados.

## <a name="members"></a>Membros

### <a name="public-typedefs"></a>Typedefs públicos

Nome     | Descrição
-------- | -----------------------------------------------------------------------------
`Traits` | Um sinônimo para a classe que define o tipo de argumento de manipulador de eventos.

### <a name="public-constructors"></a>Construtores públicos

Nome                                        | Descrição
------------------------------------------- | -------------------------------------------------------
[InvocarHelper::InvocarHelper](#invokehelper) | Inicia uma nova instância da classe `InvokeHelper`.

### <a name="public-methods"></a>Métodos públicos

Nome                            | Descrição
------------------------------- | -----------------------------------------------------------------------------------
[InvocarHelper::Invocar](#invoke) | Chama o manipulador de eventos cuja assinatura contém o número especificado de argumentos.

### <a name="public-data-members"></a>Membros de Dados Públicos

Nome                                 | Descrição
------------------------------------ | ----------------------------------------------------------
[InvocarHelper::callback_](#callback) | Representa o manipulador de eventos para chamar quando um evento ocorre.

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

`InvokeHelper`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** event.h

**Espaço de nome:** Microsoft::WRL::Details

## <a name="invokehelpercallback_"></a><a name="callback"></a>InvocarHelper::callback_

Suporta a infra-estrutura WRL e não se destina a ser usado diretamente do seu código.

```cpp
TCallback callback_;
```

### <a name="remarks"></a>Comentários

Representa o manipulador de eventos para chamar quando um evento ocorre.

O `TCallback` parâmetro modelo especifica o tipo do manipulador de eventos.

## <a name="invokehelperinvoke"></a><a name="invoke"></a>InvocarHelper::Invocar

Suporta a infra-estrutura WRL e não se destina a ser usado diretamente do seu código.

```cpp
STDMETHOD(
   Invoke
)();
STDMETHOD(
   Invoke
)(typename Traits;
STDMETHOD(
   Invoke
)( typename Traits;
STDMETHOD(
   Invoke
)( typename Traits;
STDMETHOD(
   Invoke
)( typename Traits;
STDMETHOD(
   Invoke
)( typename Traits;
STDMETHOD(
   Invoke
)( typename Traits;
STDMETHOD(
   Invoke
)( typename Traits;
STDMETHOD(
   Invoke
)( typename Traits;
STDMETHOD(
   Invoke
)( typename Traits;
```

### <a name="parameters"></a>Parâmetros

*arg1*<br/>
Argumento 1.

*arg2*<br/>
Argumento 2.

*arg3*<br/>
Argumento 3.

*arg4*<br/>
Argumento 4.

*arg5*<br/>
Argumento 5.

*arg6*<br/>
Argumento 6.

*arg7*<br/>
Argumento 7.

*arg8*<br/>
Argumento 8.

*arg9*<br/>
Argumento 9.

### <a name="return-value"></a>Valor retornado

S_OK se for bem sucedido; caso contrário, um HRESULT que descreve o erro.

### <a name="remarks"></a>Comentários

Chama o manipulador de eventos cuja assinatura contém o número especificado de argumentos.

## <a name="invokehelperinvokehelper"></a><a name="invokehelper"></a>InvocarHelper::InvocarHelper

Suporta a infra-estrutura WRL e não se destina a ser usado diretamente do seu código.

```cpp
explicit InvokeHelper(
   TCallback callback
);
```

### <a name="parameters"></a>Parâmetros

*retorno de chamada*<br/>
Um manipulador de eventos.

### <a name="remarks"></a>Comentários

Inicia uma nova instância da classe `InvokeHelper`.

O `TCallback` parâmetro modelo especifica o tipo do manipulador de eventos.
