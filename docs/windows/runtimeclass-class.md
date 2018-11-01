---
title: Classe RuntimeClass
ms.date: 09/11/2018
ms.topic: reference
f1_keywords:
- implements/Microsoft::WRL::RuntimeClass
- implements/Microsoft::WRL::RuntimeClass::AddRef
- implements/Microsoft::WRL::RuntimeClass::DecrementReference
- implements/Microsoft::WRL::RuntimeClass::GetIids
- implements/Microsoft::WRL::RuntimeClass::GetRuntimeClassName
- implements/Microsoft::WRL::RuntimeClass::GetTrustLevel
- implements/Microsoft::WRL::RuntimeClass::GetWeakReference
- implements/Microsoft::WRL::RuntimeClass::InternalAddRef
- implements/Microsoft::WRL::RuntimeClass::QueryInterface
- implements/Microsoft::WRL::RuntimeClass::Release
- implements/Microsoft::WRL::RuntimeClass::RuntimeClass
- implements/Microsoft::WRL::RuntimeClass::~RuntimeClass
helpviewer_keywords:
- Microsoft::WRL::RuntimeClass class
- Microsoft::WRL::RuntimeClass::AddRef method
- Microsoft::WRL::RuntimeClass::DecrementReference method
- Microsoft::WRL::RuntimeClass::GetIids method
- Microsoft::WRL::RuntimeClass::GetRuntimeClassName method
- Microsoft::WRL::RuntimeClass::GetTrustLevel method
- Microsoft::WRL::RuntimeClass::GetWeakReference method
- Microsoft::WRL::RuntimeClass::InternalAddRef method
- Microsoft::WRL::RuntimeClass::QueryInterface method
- Microsoft::WRL::RuntimeClass::Release method
- Microsoft::WRL::RuntimeClass::RuntimeClass, constructor
- Microsoft::WRL::RuntimeClass::~RuntimeClass, destructor
ms.assetid: d52f9d1a-98e5-41f2-a143-8fb629dd0727
ms.openlocfilehash: 23b7d0237562324ddae2207435b2071e8d66e572
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50596814"
---
# <a name="runtimeclass-class"></a>Classe RuntimeClass

Representa uma classe COM ou WinRT que herda as interfaces especificadas e fornece o tempo de execução do Windows especificado, COM clássico e suporte fraco de referência.

Essa classe fornece a implementação de texto clichê de classes do WinRT e COM, fornecendo a implementação de `QueryInterface`, `AddRef`, `Release` etc., gerencia a contagem de referência do módulo e tem suporte para fornecer a fábrica de classes para objetos ativáveis.

## <a name="syntax"></a>Sintaxe

```cpp
template <typename ...TInterfaces> class RuntimeClass
template <unsigned int classFlags, typename ...TInterfaces> class RuntimeClass;
```

### <a name="parameters"></a>Parâmetros

*classFlags*<br/>
Parâmetro opcional. Uma combinação de um ou mais [RuntimeClassType](../windows/runtimeclasstype-enumeration.md) valores de enumeração. O `__WRL_CONFIGURATION_LEGACY__` macro pode ser definida para alterar o valor padrão de classFlags para todas as classes de tempo de execução do projeto. Se definido, RuntimeClass instâncias são não agile por padrão. Quando não definido, as instâncias de RuntimeClass são agile por padrão. Para evitar ambiguidade, sempre especifique o `Microsoft::WRL::FtmBase` na `TInterfaces` ou `RuntimeClassType::InhibitFtmBase`. Observe que, se InhibitFtmBase e FtmBase são que ambos utilizou o objeto será agile.

*TInterfaces*<br/>
A lista de interfaces que o objeto implementa além `IUnknown`, `IInspectable` ou outras interfaces controlados pelo [RuntimeClassType](../windows/runtimeclasstype-enumeration.md). Ele também pode listar outras classes a serem derivadas, notavelmente `Microsoft::WRL::FtmBase` para tornar o objeto agile e fazer com que ela implemente `IMarshal`.

## <a name="members"></a>Membros

`RuntimeClassInitialize`<br/>
Uma função que inicializa o objeto se a `MakeAndInitialize` função de modelo é usada para construir o objeto. Ele retorna S_OK se o objeto foi inicializado com êxito, ou um código de erro COM se a falha na inicialização. O código de erro COM é propagado como o valor de retorno `MakeAndInitialize`. Observe que o `RuntimeClassInitialize` método não será chamado se o `Make` função de modelo é usada para construir o objeto.

### <a name="public-constructors"></a>Construtores públicos

| Nome                                               | Descrição                                                     |
| -------------------------------------------------- | --------------------------------------------------------------- |
| [Runtimeclass:: Runtimeclass](#runtimeclass)        | Inicializa a instância atual do `RuntimeClass` classe.   |
| [RuntimeClass:: ~ RuntimeClass](#tilde-runtimeclass) | A instância atual do realiza o desligamento de `RuntimeClass` classe. |

### <a name="public-methods"></a>Métodos públicos

| Nome                                                      | Descrição                                                                                        |
| --------------------------------------------------------- | -------------------------------------------------------------------------------------------------- |
| [Runtimeclass:: AddRef](#addref)                           | Incrementa a contagem de referência atual `RuntimeClass` objeto.                              |
| [Runtimeclass:: Decrementreference](#decrementreference)   | Diminui a contagem de referência atual `RuntimeClass` objeto.                              |
| [Runtimeclass:: Getiids](#getiids)                         | Obtém uma matriz que contém a interface implementadas pelo atual de IDs `RuntimeClass` objeto. |
| [Runtimeclass:: Getruntimeclassname](#getruntimeclassname) | Obtém o nome de classe de tempo de execução do atual `RuntimeClass` objeto.                                  |
| [Runtimeclass:: Gettrustlevel](#gettrustlevel)             | Obtém o nível de confiança atual `RuntimeClass` objeto.                                         |
| [Runtimeclass:: Getweakreference](#getweakreference)       | Obtém um ponteiro para o objeto de referência fraca para a atual `RuntimeClass` objeto.                 |
| [Runtimeclass:: Internaladdref](#internaladdref)           | Incrementa a contagem de referência para a atual `RuntimeClass` objeto.                               |
| [Runtimeclass:: QueryInterface](#queryinterface)           | Recupera um ponteiro para a ID de interface especificado.                                                 |
| [Runtimeclass:: Release](#release)                         | Executa uma operação de lançamento COM atuais `RuntimeClass` objeto.                             |

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

Isso é um detalhe de implementação.

## <a name="requirements"></a>Requisitos

**Cabeçalho:** Implements. h

**Namespace:** Microsoft::WRL

## <a name="tilde-runtimeclass"></a>RuntimeClass:: ~ RuntimeClass

A instância atual do realiza o desligamento de `RuntimeClass` classe.

```cpp
virtual ~RuntimeClass();
```

## <a name="addref"></a>Runtimeclass:: AddRef

Incrementa a contagem de referência atual `RuntimeClass` objeto.

```cpp
STDMETHOD_(
   ULONG,
   AddRef
)();
```

### <a name="return-value"></a>Valor de retorno

S_OK se bem-sucedido; Caso contrário, um HRESULT que indica o erro.

## <a name="decrementreference"></a>Runtimeclass:: Decrementreference

Diminui a contagem de referência atual `RuntimeClass` objeto.

```cpp
ULONG DecrementReference();
```

### <a name="return-value"></a>Valor de retorno

S_OK se bem-sucedido; Caso contrário, um HRESULT que indica o erro.

## <a name="getiids"></a>Runtimeclass:: Getiids

Obtém uma matriz que contém a interface implementadas pelo atual de IDs `RuntimeClass` objeto.

```cpp
STDMETHOD(
   GetIids
)
   (_Out_ ULONG *iidCount,
   _Deref_out_ _Deref_post_cap_(*iidCount) IID **iids);
```

### <a name="parameters"></a>Parâmetros

*iidCount*<br/>
Quando essa operação for concluída, o número total de elementos na matriz *iids*.

*IIDs*<br/>
Quando essa operação for concluída, um ponteiro para uma matriz de IDs de interface.

### <a name="return-value"></a>Valor de retorno

S_OK se bem-sucedido; Caso contrário, E_OUTOFMEMORY.

## <a name="getruntimeclassname"></a>Runtimeclass:: Getruntimeclassname

Obtém o nome de classe de tempo de execução do atual `RuntimeClass` objeto.

```cpp
STDMETHOD( GetRuntimeClassName )(
    _Out_ HSTRING* runtimeName
);
```

### <a name="parameters"></a>Parâmetros

*runtimeName*<br/>
Quando essa operação for concluída, o nome de classe de tempo de execução.

### <a name="return-value"></a>Valor de retorno

S_OK se bem-sucedido; Caso contrário, um HRESULT que indica o erro.

### <a name="remarks"></a>Comentários

Um erro de asserção é emitido se `__WRL_STRICT__` ou `__WRL_FORCE_INSPECTABLE_CLASS_MACRO__` não está definido.

## <a name="gettrustlevel"></a>Runtimeclass:: Gettrustlevel

Obtém o nível de confiança atual `RuntimeClass` objeto.

```cpp
STDMETHOD(GetTrustLevel)(
    _Out_ TrustLevel* trustLvl
);
```

### <a name="parameters"></a>Parâmetros

*trustLvl*<br/>
Quando essa operação for concluída, o nível de confiança atual `RuntimeClass` objeto.

### <a name="return-value"></a>Valor de retorno

Sempre S_OK.

### <a name="remarks"></a>Comentários

Um erro de asserção é emitido se `__WRL_STRICT__` ou `__WRL_FORCE_INSPECTABLE_CLASS_MACRO__` não está definido.

## <a name="getweakreference"></a>Runtimeclass:: Getweakreference

Obtém um ponteiro para o objeto de referência fraca para a atual `RuntimeClass` objeto.

```cpp
STDMETHOD(
   GetWeakReference
)(_Deref_out_ IWeakReference **weakReference);
```

### <a name="parameters"></a>Parâmetros

*weakReference*<br/>
Quando essa operação for concluída, um ponteiro para um objeto de referência fraca.

### <a name="return-value"></a>Valor de retorno

Sempre S_OK.

## <a name="internaladdref"></a>Runtimeclass:: Internaladdref

Incrementa a contagem de referência para a atual `RuntimeClass` objeto.

```cpp
ULONG InternalAddRef();
```

### <a name="return-value"></a>Valor de retorno

A contagem de referência resultante.

## <a name="queryinterface"></a>Runtimeclass:: QueryInterface

Recupera um ponteiro para a ID de interface especificado.

```cpp
STDMETHOD(
   QueryInterface
)
   (REFIID riid,
   _Deref_out_ void **ppvObject);
```

### <a name="parameters"></a>Parâmetros

*riid*<br/>
Uma ID de interface.

*ppvObject*<br/>
Quando este opereation for concluída, um ponteiro para a interface especificada pelo *riid* parâmetro.

### <a name="return-value"></a>Valor de retorno

S_OK se bem-sucedido; Caso contrário, um HRESULT que indica o erro.

## <a name="release"></a>Runtimeclass:: Release

Executa uma operação de lançamento COM atuais `RuntimeClass` objeto.

```cpp
STDMETHOD_(
   ULONG,
   Release
)();
```

### <a name="return-value"></a>Valor de retorno

S_OK se bem-sucedido; Caso contrário, um HRESULT que indica o erro.

### <a name="remarks"></a>Comentários

Se a contagem de referência se torna zero, o `RuntimeClass` objeto é excluído.

## <a name="runtimeclass"></a>Runtimeclass:: Runtimeclass

Inicializa a instância atual do `RuntimeClass` classe.

```cpp
RuntimeClass();
```
