---
title: Classe ActivationFactory
ms.date: 10/03/2018
ms.topic: reference
f1_keywords:
- module/Microsoft::WRL::ActivationFactory
- module/Microsoft::WRL::ActivationFactory::ActivationFactory
- module/Microsoft::WRL::ActivationFactory::AddRef
- module/Microsoft::WRL::ActivationFactory::GetIids
- module/Microsoft::WRL::ActivationFactory::GetRuntimeClassName
- module/Microsoft::WRL::ActivationFactory::GetTrustLevel
- module/Microsoft::WRL::ActivationFactory::QueryInterface
- module/Microsoft::WRL::ActivationFactory::Release
helpviewer_keywords:
- Microsoft::WRL::ActivationFactory class
- Microsoft::WRL::ActivationFactory::ActivationFactory, constructor
- Microsoft::WRL::ActivationFactory::AddRef method
- Microsoft::WRL::ActivationFactory::GetIids method
- Microsoft::WRL::ActivationFactory::GetRuntimeClassName method
- Microsoft::WRL::ActivationFactory::GetTrustLevel method
- Microsoft::WRL::ActivationFactory::QueryInterface method
- Microsoft::WRL::ActivationFactory::Release method
ms.assetid: 5faddf1f-43b6-4f8a-97de-8c9d3ae1e1ff
ms.openlocfilehash: 0655caeb3f49a18e9c57c78f0008901aaaedda4a
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81368699"
---
# <a name="activationfactory-class"></a>Classe ActivationFactory

Permite que uma ou mais classes sejam ativadas pelo Windows Runtime.

## <a name="syntax"></a>Sintaxe

```cpp
template <
    typename I0 = Details::Nil,
    typename I1 = Details::Nil,
    typename I2 = Details::Nil
>
class ActivationFactory :
    public Details::RuntimeClass<
        typename Details::InterfaceListHelper<
            IActivationFactory,
            I0,
            I1,
            I2,
            Details::Nil
        >::TypeT,
        RuntimeClassFlags<WinRt | InhibitWeakReference>,
        false
    >;
```

### <a name="parameters"></a>Parâmetros

*I0*<br/>
A interface zero.

*I1*<br/>
A primeira interface.

*I2*<br/>
A segunda interface.

## <a name="remarks"></a>Comentários

`ActivationFactory`fornece métodos de registro e `IActivationFactory` funcionalidade básica para a interface. `ActivationFactory`também permite que você forneça uma implementação de fábrica personalizada.

O fragmento de código a seguir ilustra simbolicamente como usar ActivationFactory.

[!code-cpp[wrl-microsoft__wrl__activationfactory#1](../codesnippet/CPP/activationfactory-class_1.cpp)]

O fragmento de código a seguir mostra como usar a estrutura [Implementos](implements-structure.md) para especificar mais de três IDs de interface.

`struct MyFactory : ActivationFactory<Implements<I1, I2, I3>, I4, I5>;`

## <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores públicos

Nome                                                       | Descrição
---------------------------------------------------------- | ------------------------------------------
[AtivaçãoFábrica::AtivaçãoFábrica](#activationfactory) | Inicializa a classe `ActivationFactory`.

### <a name="public-methods"></a>Métodos públicos

Nome                                                           | Descrição
-------------------------------------------------------------- | --------------------------------------------------------------------------------------------
[AtivaçãoFábrica::AddRef](#addref)                           | Incrementa a contagem `ActivationFactory` de referência do objeto atual.
[AtivaçãoFábrica::GetIids](#getiids)                         | Recupera um conjunto de IDs de interface implementados.
[AtivaçãoFábrica::GetRuntimeClassName](#getruntimeclassname) | Obtém o nome da classe de `ActivationFactory` tempo de execução do objeto que a corrente instancia.
[ActivationFactory::GetTrustLevel](#gettrustlevel)             | Obtém o nível de confiança `ActivationFactory` do objeto que a corrente instancia.
[AtivaçãoFábrica::QueryInterface](#queryinterface)           | Recupera um ponteiro para a interface especificada.
[AtivaçãoFábrica::Lançamento](#release)                         | Decreta a contagem de `ActivationFactory` referência do objeto atual.

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

`I0`

`ChainInterfaces`

`I0`

`RuntimeClassBase`

`ImplementsHelper`

`DontUseNewUseMake`

`RuntimeClassFlags`

`RuntimeClassBaseT`

`RuntimeClass`

`ActivationFactory`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** module.h

**Espaço de nome:** Microsoft::WRL

## <a name="activationfactoryactivationfactory"></a><a name="activationfactory"></a>AtivaçãoFábrica::AtivaçãoFábrica

Inicializa a classe `ActivationFactory`.

```cpp
ActivationFactory();
```

## <a name="activationfactoryaddref"></a><a name="addref"></a>AtivaçãoFábrica::AddRef

Incrementa a contagem `ActivationFactory` de referência do objeto atual.

```cpp
STDMETHOD_(
   ULONG,
   AddRef
)();
```

### <a name="return-value"></a>Valor retornado

S_OK se for bem sucedido; caso contrário, um HRESULT que descreve a falha.

## <a name="activationfactorygetiids"></a><a name="getiids"></a>AtivaçãoFábrica::GetIids

Recupera um conjunto de IDs de interface implementados.

```cpp
STDMETHOD(
   GetIids
)(_Out_ ULONG *iidCount, _Deref_out_ _Deref_post_cap_(*iidCount) IID **iids);
```

### <a name="parameters"></a>Parâmetros

*IidCount*<br/>
Quando esta operação for concluída, o número de IDs intercetas na matriz *iids.*

*Iids*<br/>
Quando esta operação for concluída, uma matriz de IDs de interface implementados.

### <a name="return-value"></a>Valor retornado

S_OK se for bem sucedido; caso contrário, um HRESULT que descreve a falha. E_OUTOFMEMORY é um possível fracasso HRESULT.

## <a name="activationfactorygetruntimeclassname"></a><a name="getruntimeclassname"></a>AtivaçãoFábrica::GetRuntimeClassName

Obtém o nome da classe de `ActivationFactory` tempo de execução do objeto que a corrente instancia.

```cpp
STDMETHOD(
   GetRuntimeClassName
)(_Out_ HSTRING* runtimeName);
```

### <a name="parameters"></a>Parâmetros

*runtimeName*<br/>
Quando esta operação for concluída, uma alça para uma string que contém `ActivationFactory` o nome da classe de tempo de execução do objeto que a corrente instancia.

### <a name="return-value"></a>Valor retornado

S_OK se for bem sucedido; caso contrário, um HRESULT que descreve a falha.

## <a name="activationfactorygettrustlevel"></a><a name="gettrustlevel"></a>ActivationFactory::GetTrustLevel

Obtém o nível de confiança `ActivationFactory` do objeto que a corrente instancia.

```cpp
STDMETHOD(
   GetTrustLevel
)(_Out_ TrustLevel* trustLvl);
```

### <a name="parameters"></a>Parâmetros

*trustLvl*<br/>
Quando esta operação é concluída, o nível de `ActivationFactory` confiança da classe de tempo de execução que a instancia.

### <a name="return-value"></a>Valor retornado

S_OK se for bem sucedido; caso contrário, um erro de afirmação é `FullTrust`emitido e *trustLvl* é definido para .

## <a name="activationfactoryqueryinterface"></a><a name="queryinterface"></a>AtivaçãoFábrica::QueryInterface

Recupera um ponteiro para a interface especificada.

```cpp
STDMETHOD(
   QueryInterface
)(REFIID riid, _Deref_out_ void **ppvObject);
```

### <a name="parameters"></a>Parâmetros

*riid*<br/>
Um ID de interface.

*Ppvobject*<br/>
Quando esta operação estiver concluída, um ponteiro para a interface especificado por *parâmetro riid*.

### <a name="return-value"></a>Valor retornado

S_OK se for bem sucedido; caso contrário, um HRESULT que descreve a falha.

## <a name="activationfactoryrelease"></a><a name="release"></a>AtivaçãoFábrica::Lançamento

Decreta a contagem de `ActivationFactory` referência do objeto atual.

```cpp
STDMETHOD_(
   ULONG,
   Release
)();
```

### <a name="return-value"></a>Valor retornado

S_OK se for bem sucedido; caso contrário, um HRESULT que descreve a falha.
