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
ms.openlocfilehash: 3fcba210d4018d22487d234b437acfee3634cec6
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62386129"
---
# <a name="invokehelper-structure"></a>Estrutura InvokeHelper

Oferece suporte a infraestrutura do WRL e não se destina a ser usado diretamente do seu código.

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

*TDelegateInterface*<br/>
O tipo de interface do delegado.

*TCallback*<br/>
O tipo da função de manipulador de eventos.

*argCount*<br/>
O número de argumentos em uma `InvokeHelper` especialização.

## <a name="remarks"></a>Comentários

Fornece uma implementação do `Invoke()` método com base no tipo de argumentos e o número especificado.

## <a name="members"></a>Membros

### <a name="public-typedefs"></a>Typedefs públicos

Nome     | Descrição
-------- | -----------------------------------------------------------------------------
`Traits` | Um sinônimo para a classe que define o tipo de cada argumento de manipulador de eventos.

### <a name="public-constructors"></a>Construtores públicos

Nome                                        | Descrição
------------------------------------------- | -------------------------------------------------------
[InvokeHelper::InvokeHelper](#invokehelper) | Inicializa uma nova instância da classe `InvokeHelper`.

### <a name="public-methods"></a>Métodos públicos

Nome                            | Descrição
------------------------------- | -----------------------------------------------------------------------------------
[InvokeHelper::Invoke](#invoke) | Chama o manipulador de eventos cuja assinatura contém o número especificado de argumentos.

### <a name="public-data-members"></a>Membros de Dados Públicos

Nome                                 | Descrição
------------------------------------ | ----------------------------------------------------------
[InvokeHelper::callback_](#callback) | Representa o manipulador de eventos para chamar quando ocorre um evento.

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

`InvokeHelper`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** Event. h

**Namespace:** Microsoft::WRL::Details

## <a name="callback"></a>InvokeHelper::callback_

Oferece suporte a infraestrutura do WRL e não se destina a ser usado diretamente do seu código.

```cpp
TCallback callback_;
```

### <a name="remarks"></a>Comentários

Representa o manipulador de eventos para chamar quando ocorre um evento.

O `TCallback` parâmetro de modelo especifica o tipo de manipulador de eventos.

## <a name="invoke"></a>InvokeHelper::Invoke

Oferece suporte a infraestrutura do WRL e não se destina a ser usado diretamente do seu código.

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
Argumento de 4.

*arg5*<br/>
Argumento 5.

*arg6*<br/>
Argumento 6.

*arg7*<br/>
Argumento de 7.

*arg8*<br/>
Argumento de 8.

*arg9*<br/>
Argumento de 9.

### <a name="return-value"></a>Valor de retorno

S_OK se bem-sucedido; Caso contrário, um HRESULT que descreve o erro.

### <a name="remarks"></a>Comentários

Chama o manipulador de eventos cuja assinatura contém o número especificado de argumentos.

## <a name="invokehelper"></a>InvokeHelper::InvokeHelper

Oferece suporte a infraestrutura do WRL e não se destina a ser usado diretamente do seu código.

```cpp
explicit InvokeHelper(
   TCallback callback
);
```

### <a name="parameters"></a>Parâmetros

*callback*<br/>
Um manipulador de eventos.

### <a name="remarks"></a>Comentários

Inicializa uma nova instância da classe `InvokeHelper`.

O `TCallback` parâmetro de modelo especifica o tipo de manipulador de eventos.
