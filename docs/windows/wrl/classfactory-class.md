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
ms.openlocfilehash: ccc1c43e8c68053a773883c25704cdea086bd0b1
ms.sourcegitcommit: 360b55e89e5954f494e52b1cf989fbaceda06f1c
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 01/16/2019
ms.locfileid: "54335448"
---
# <a name="classfactory-class"></a>Classe ClassFactory

Implementa a funcionalidade básica do `IClassFactory` interface.

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
A interface inicial.

*I1*<br/>
A primeira interface.

*I2*<br/>
A segunda interface.

## <a name="remarks"></a>Comentários

Utilizar `ClassFactory` para fornecer uma implementação de fábrica definidos pelo usuário.

O padrão de programação a seguir demonstra como usar o [implementa](implements-structure.md) estrutura para especificar mais de três interfaces em uma fábrica de classes.

`struct MyFactory : ClassFactory<Implements<I1, I2, I3>, I4, I5>`

## <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores Públicos

Nome                                        | Descrição
------------------------------------------- | -----------
[ClassFactory::ClassFactory](#classfactory) |

### <a name="public-methods"></a>Métodos públicos

Nome                                            | Descrição
----------------------------------------------- | ----------------------------------------------------------------------------------------------------------------
[ClassFactory::AddRef](#addref)                 | Incrementa a contagem de referência atual `ClassFactory` objeto.
[ClassFactory::LockServer](#lockserver)         | Aumenta ou diminui o número de subjacente objetos que são controladas pelo atual `ClassFactory` objeto.
[ClassFactory::QueryInterface](#queryinterface) | Recupera um ponteiro para a interface especificada pelo parâmetro.
[ClassFactory::Release](#release)               | Diminui a contagem de referência atual `ClassFactory` objeto.

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

**Namespace:** Microsoft::WRL

## <a name="addref"></a>ClassFactory::AddRef

Incrementa a contagem de referência atual `ClassFactory` objeto.

```cpp
STDMETHOD_(
   ULONG,
   AddRef
)();
```

### <a name="return-value"></a>Valor de retorno

S_OK se bem-sucedido; Caso contrário, um HRESULT que descreve a falha.

## <a name="classfactory"></a>ClassFactory::ClassFactory

```cpp
WRL_NOTHROW ClassFactory();
```

## <a name="lockserver"></a>ClassFactory::LockServer

Aumenta ou diminui o número de subjacente objetos que são controladas pelo atual `ClassFactory` objeto.

```cpp
STDMETHOD(
   LockServer
)(BOOL fLock);
```

### <a name="parameters"></a>Parâmetros

*fLock*<br/>
**True** para incrementar o número de objetos rastreados. **False** para diminuir o número de objetos rastreadas.

### <a name="return-value"></a>Valor de retorno

S_OK se bem-sucedido; Caso contrário, E_FAIL.

### <a name="remarks"></a>Comentários

`ClassFactory` mantém o controle de objetos em uma instância subjacente do [módulo](module-class.md) classe.

## <a name="queryinterface"></a>ClassFactory::QueryInterface

Recupera um ponteiro para a interface especificada pelo parâmetro.

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

## <a name="release"></a>ClassFactory::Release

Diminui a contagem de referência atual `ClassFactory` objeto.

```cpp
STDMETHOD_(
   ULONG,
   Release
)();
```

### <a name="return-value"></a>Valor de retorno

S_OK se bem-sucedido; Caso contrário, um HRESULT que descreve a falha.
