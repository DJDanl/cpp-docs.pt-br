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
ms.openlocfilehash: bbf20e2269e6d62206e06e748174d7b88898cd68
ms.sourcegitcommit: 1f009ab0f2cc4a177f2d1353d5a38f164612bdb1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/27/2020
ms.locfileid: "87198093"
---
# <a name="classfactory-class"></a>Classe ClassFactory

Implementa a funcionalidade básica da `IClassFactory` interface.

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

### <a name="parameters"></a>parâmetros

*I0*<br/>
A interface inicial.

*I1*<br/>
A primeira interface.

*I2*<br/>
A segunda interface.

## <a name="remarks"></a>Comentários

Utilize `ClassFactory` o para fornecer uma implementação de fábrica definida pelo usuário.

O padrão de programação a seguir demonstra como usar a estrutura [Implements](implements-structure.md) para especificar mais de três interfaces em uma fábrica de classes.

`struct MyFactory : ClassFactory<Implements<I1, I2, I3>, I4, I5>`

## <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores públicos

Nome                                        | Descrição
------------------------------------------- | -----------
[ClassFactory::ClassFactory](#classfactory) |

### <a name="public-methods"></a>Métodos públicos

Nome                                            | Descrição
----------------------------------------------- | ----------------------------------------------------------------------------------------------------------------
[ClassFactory:: AddRef](#addref)                 | Incrementa a contagem de referência para o `ClassFactory` objeto atual.
[ClassFactory::LockServer](#lockserver)         | Incrementa ou Decrementa o número de objetos subjacentes que são rastreados pelo objeto atual `ClassFactory` .
[ClassFactory:: QueryInterface](#queryinterface) | Recupera um ponteiro para a interface especificada pelo parâmetro.
[ClassFactory:: versão](#release)               | Decrementa a contagem de referência para o `ClassFactory` objeto atual.

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

**Cabeçalho:** Module. h

**Namespace:** Microsoft:: WRL

## <a name="classfactoryaddref"></a><a name="addref"></a>ClassFactory:: AddRef

Incrementa a contagem de referência para o `ClassFactory` objeto atual.

```cpp
STDMETHOD_(
   ULONG,
   AddRef
)();
```

### <a name="return-value"></a>Valor retornado

S_OK se for bem-sucedido; caso contrário, um HRESULT que descreve a falha.

## <a name="classfactoryclassfactory"></a><a name="classfactory"></a>ClassFactory::ClassFactory

```cpp
WRL_NOTHROW ClassFactory();
```

## <a name="classfactorylockserver"></a><a name="lockserver"></a>ClassFactory::LockServer

Incrementa ou Decrementa o número de objetos subjacentes que são rastreados pelo objeto atual `ClassFactory` .

```cpp
STDMETHOD(
   LockServer
)(BOOL fLock);
```

### <a name="parameters"></a>parâmetros

*fLock*<br/>
**`true`** para incrementar o número de objetos rastreados. **`false`** para diminuir o número de objetos rastreados.

### <a name="return-value"></a>Valor retornado

S_OK se for bem-sucedido; caso contrário, E_FAIL.

### <a name="remarks"></a>Comentários

`ClassFactory`mantém o controle de objetos em uma instância subjacente da classe [Module](module-class.md) .

## <a name="classfactoryqueryinterface"></a><a name="queryinterface"></a>ClassFactory:: QueryInterface

Recupera um ponteiro para a interface especificada pelo parâmetro.

```cpp
STDMETHOD(
   QueryInterface
)(REFIID riid, _Deref_out_ void **ppvObject);
```

### <a name="parameters"></a>parâmetros

*riid*<br/>
Uma ID de interface.

*ppvObject*<br/>
Quando essa operação for concluída, um ponteiro para a interface especificada pelo parâmetro *riid*.

### <a name="return-value"></a>Valor retornado

S_OK se for bem-sucedido; caso contrário, um HRESULT que descreve a falha.

## <a name="classfactoryrelease"></a><a name="release"></a>ClassFactory:: versão

Decrementa a contagem de referência para o `ClassFactory` objeto atual.

```cpp
STDMETHOD_(
   ULONG,
   Release
)();
```

### <a name="return-value"></a>Valor retornado

S_OK se for bem-sucedido; caso contrário, um HRESULT que descreve a falha.
