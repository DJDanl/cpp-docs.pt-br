---
title: Classe ClassFactory
ms.date: 10/03/2018
ms.topic: reference
f1_keywords:
- module/Microsoft::WRL::ClassFactory
- module/Microsoft::WRL::ClassFactory::AddRef
- module/Microsoft::WRL::ClassFactory::ClassFactory
- module/Microsoft::WRL::ClassFactory::LockServer
- module/Microsoft::WRL::ClassFactory::QueryInterface
- module/Microsoft::WRL::ClassFactory::Release
helpviewer_keywords:
- Microsoft::WRL::ClassFactory class
- Microsoft::WRL::ClassFactory::AddRef method
- Microsoft::WRL::ClassFactory::ClassFactory, constructor
- Microsoft::WRL::ClassFactory::LockServer method
- Microsoft::WRL::ClassFactory::QueryInterface method
- Microsoft::WRL::ClassFactory::Release method
ms.assetid: f13e6bce-722b-4f18-b7cf-3ffa6345c1db
ms.openlocfilehash: 3b738cc8f439e6653162ab99b0a26e87aa8fee36
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81372675"
---
# <a name="classfactory-class"></a>Classe ClassFactory

Implementa a funcionalidade básica `IClassFactory` da interface.

## <a name="syntax"></a>Sintaxe

```cpp
template <
    typename I0 = Details::Nil,
    typename I1 = Details::Nil,
    typename I2 = Details::Nil
>
class ClassFactory :
    public Details::RuntimeClass<
        typename Details::InterfaceListHelper<
            IClassFactory,
            I0,
            I1,
            I2,
            Details::Nil
        >::TypeT,
        RuntimeClassFlags<ClassicCom | InhibitWeakReference>,
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

Utilize `ClassFactory` para fornecer uma implementação de fábrica definida pelo usuário.

O padrão de programação a seguir demonstra como usar a estrutura [Implements](implements-structure.md) para especificar mais de três interfaces em uma fábrica de classe.

`struct MyFactory : ClassFactory<Implements<I1, I2, I3>, I4, I5>`

## <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores públicos

Nome                                        | Descrição
------------------------------------------- | -----------
[ClassFactory::ClassFactory](#classfactory) |

### <a name="public-methods"></a>Métodos públicos

Nome                                            | Descrição
----------------------------------------------- | ----------------------------------------------------------------------------------------------------------------
[ClasseFábrica::AddRef](#addref)                 | Incrementa a contagem `ClassFactory` de referência para o objeto atual.
[ClasseFábrica::Bloqueioservidor](#lockserver)         | Incrementa ou diminui o número de objetos subjacentes que `ClassFactory` são rastreados pelo objeto atual.
[ClassFactory::QueryInterface](#queryinterface) | Recupera um ponteiro para a interface especificada por parâmetro.
[ClassFactory::Lançamento](#release)               | Decreta a contagem de `ClassFactory` referência para o objeto atual.

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

`ClassFactory`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** module.h

**Espaço de nome:** Microsoft::WRL

## <a name="classfactoryaddref"></a><a name="addref"></a>ClasseFábrica::AddRef

Incrementa a contagem `ClassFactory` de referência para o objeto atual.

```cpp
STDMETHOD_(
   ULONG,
   AddRef
)();
```

### <a name="return-value"></a>Valor retornado

S_OK se for bem sucedido; caso contrário, um HRESULT que descreve a falha.

## <a name="classfactoryclassfactory"></a><a name="classfactory"></a>ClassFactory::ClassFactory

```cpp
WRL_NOTHROW ClassFactory();
```

## <a name="classfactorylockserver"></a><a name="lockserver"></a>ClasseFábrica::Bloqueioservidor

Incrementa ou diminui o número de objetos subjacentes que `ClassFactory` são rastreados pelo objeto atual.

```cpp
STDMETHOD(
   LockServer
)(BOOL fLock);
```

### <a name="parameters"></a>Parâmetros

*Rebanho*<br/>
**fiel** ao incremento do número de objetos rastreados. **falso** para diminuir o número de objetos rastreados.

### <a name="return-value"></a>Valor retornado

S_OK se for bem sucedido; caso contrário, E_FAIL.

### <a name="remarks"></a>Comentários

`ClassFactory`mantém o controle de objetos em uma instância subjacente da classe [Module.](module-class.md)

## <a name="classfactoryqueryinterface"></a><a name="queryinterface"></a>ClassFactory::QueryInterface

Recupera um ponteiro para a interface especificada por parâmetro.

```cpp
STDMETHOD(
   QueryInterface
)(REFIID riid, _Deref_out_ void **ppvObject);
```

### <a name="parameters"></a>Parâmetros

*riid*<br/>
Um ID de interface.

*Ppvobject*<br/>
Quando esta operação for concluída, um ponteiro para a interface especificado por parâmetro *riid*.

### <a name="return-value"></a>Valor retornado

S_OK se for bem sucedido; caso contrário, um HRESULT que descreve a falha.

## <a name="classfactoryrelease"></a><a name="release"></a>ClassFactory::Lançamento

Decreta a contagem de `ClassFactory` referência para o objeto atual.

```cpp
STDMETHOD_(
   ULONG,
   Release
)();
```

### <a name="return-value"></a>Valor retornado

S_OK se for bem sucedido; caso contrário, um HRESULT que descreve a falha.
