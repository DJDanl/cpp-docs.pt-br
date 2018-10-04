---
title: Classe ActivationFactory | Microsoft Docs
ms.custom: ''
ms.date: 10/03/2018
ms.technology:
- cpp-windows
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
dev_langs:
- C++
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
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- uwp
ms.openlocfilehash: c2e8256b90b243bc02f9ca5bbfb8ee6a933a7fe4
ms.sourcegitcommit: 955ef0f9d966e7c9c65e040f1e28fa83abe102a5
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/04/2018
ms.locfileid: "48788637"
---
# <a name="activationfactory-class"></a>Classe ActivationFactory

Permite que um ou mais classes sejam ativadas pelo tempo de execução do Windows.

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
A interface inicial.

*I1*<br/>
A primeira interface.

*I2*<br/>
A segunda interface.

## <a name="remarks"></a>Comentários

`ActivationFactory` fornece métodos de registro e a funcionalidade básica para o `IActivationFactory` interface. `ActivationFactory` também permite que você forneça uma implementação de fábrica personalizada.

O fragmento de código a seguir simbolicamente ilustra como usar ActivationFactory.

[!code-cpp[wrl-microsoft__wrl__activationfactory#1](../windows/codesnippet/CPP/activationfactory-class_1.cpp)]

O fragmento de código a seguir mostra como usar o [implementa](../windows/implements-structure.md) estrutura para especificar mais de três IDs de interface.

`struct MyFactory : ActivationFactory<Implements<I1, I2, I3>, I4, I5>;`

## <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores Públicos

Nome                                                       | Descrição
---------------------------------------------------------- | ------------------------------------------
[Activationfactory:: Activationfactory](#activationfactory) | Inicializa a classe `ActivationFactory`.

### <a name="public-methods"></a>Métodos públicos

Nome                                                           | Descrição
-------------------------------------------------------------- | --------------------------------------------------------------------------------------------
[Activationfactory:: AddRef](#addref)                           | Incrementa a contagem de referência do atual `ActivationFactory` objeto.
[Activationfactory:: Getiids](#getiids)                         | Recupera uma matriz de IDs de interface implementada.
[Activationfactory:: Getruntimeclassname](#getruntimeclassname) | Obtém o nome de classe de tempo de execução do objeto que atual `ActivationFactory` cria uma instância.
[Activationfactory:: Gettrustlevel](#gettrustlevel)             | Obtém o nível de confiança do objeto que atual `ActivationFactory` cria uma instância.
[Activationfactory:: QueryInterface](#queryinterface)           | Recupera um ponteiro para a interface especificada.
[Activationfactory:: Release](#release)                         | Diminui a contagem de referência do atual `ActivationFactory` objeto.

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

**Namespace:** Microsoft::WRL

## <a name="activationfactory"></a>Activationfactory:: Activationfactory

Inicializa a classe `ActivationFactory`.

```cpp
ActivationFactory();
```

## <a name="addref"></a>Activationfactory:: AddRef

Incrementa a contagem de referência do atual `ActivationFactory` objeto.

```cpp
STDMETHOD_(
   ULONG,
   AddRef
)();
```

### <a name="return-value"></a>Valor de retorno

S_OK se bem-sucedido; Caso contrário, um HRESULT que descreve a falha.

## <a name="getiids"></a>Activationfactory:: Getiids

Recupera uma matriz de IDs de interface implementada.

```cpp
STDMETHOD(
   GetIids
)(_Out_ ULONG *iidCount, _Deref_out_ _Deref_post_cap_(*iidCount) IID **iids);
```

### <a name="parameters"></a>Parâmetros

*iidCount*<br/>
Quando essa operação for concluída, o número de IDs de interface na *iids* matriz.

*IIDs*<br/>
Quando essa operação for concluída, uma matriz de implementado IDs de interface.

### <a name="return-value"></a>Valor de retorno

S_OK se bem-sucedido; Caso contrário, um HRESULT que descreve a falha. E_OUTOFMEMORY é uma possível falha de HRESULT.

## <a name="getruntimeclassname"></a>Activationfactory:: Getruntimeclassname

Obtém o nome de classe de tempo de execução do objeto que atual `ActivationFactory` cria uma instância.

```cpp
STDMETHOD(
   GetRuntimeClassName
)(_Out_ HSTRING* runtimeName);
```

### <a name="parameters"></a>Parâmetros

*runtimeName*<br/>
Quando essa operação for concluída, um identificador para uma cadeia de caracteres que contém o nome de classe de tempo de execução do objeto que atual `ActivationFactory` cria uma instância.

### <a name="return-value"></a>Valor de retorno

S_OK se bem-sucedido; Caso contrário, um HRESULT que descreve a falha.

## <a name="gettrustlevel"></a>Activationfactory:: Gettrustlevel

Obtém o nível de confiança do objeto que atual `ActivationFactory` cria uma instância.

```cpp
STDMETHOD(
   GetTrustLevel
)(_Out_ TrustLevel* trustLvl);
```

### <a name="parameters"></a>Parâmetros

*trustLvl*<br/>
Quando essa operação for concluída, o nível de confiança do tempo de execução de classe que o `ActivationFactory` cria uma instância.

### <a name="return-value"></a>Valor de retorno

S_OK se bem-sucedido; Caso contrário, um erro de asserção é emitido e *trustLvl* é definido como `FullTrust`.

## <a name="queryinterface"></a>Activationfactory:: QueryInterface

Recupera um ponteiro para a interface especificada.

```cpp
STDMETHOD(
   QueryInterface
)(REFIID riid, _Deref_out_ void **ppvObject);
```

### <a name="parameters"></a>Parâmetros

*riid*<br/>
Uma ID de interface.

*ppvObject*<br/>
Quando essa operação for concluída, um ponteiro para a interface especificada pelo parâmetro *riid*.

### <a name="return-value"></a>Valor de retorno

S_OK se bem-sucedido; Caso contrário, um HRESULT que descreve a falha.

## <a name="release"></a>Activationfactory:: Release

Diminui a contagem de referência do atual `ActivationFactory` objeto.

```cpp
STDMETHOD_(
   ULONG,
   Release
)();
```

### <a name="return-value"></a>Valor de retorno

S_OK se bem-sucedido; Caso contrário, um HRESULT que descreve a falha.
