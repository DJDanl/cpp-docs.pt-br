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
ms.openlocfilehash: 64b4124ba3c60fdcb53fc29c7b791c0f73a49579
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81376229"
---
# <a name="runtimeclass-class"></a>Classe RuntimeClass

Representa uma classe WinRT ou COM que herda as interfaces especificadas e fornece o suporte de referência especificado do Windows Runtime, o COM clássico e o suporte de referência fraco.

Esta classe fornece a implementação de caldeiras das `QueryInterface`classes `AddRef` `Release` WinRT e COM, fornecendo a implementação de , etc., gerencia a contagem de referência do módulo e tem suporte para fornecer a fábrica de classe para objetos activáveis.

## <a name="syntax"></a>Sintaxe

```cpp
template <typename ...TInterfaces> class RuntimeClass
template <unsigned int classFlags, typename ...TInterfaces> class RuntimeClass;
```

### <a name="parameters"></a>Parâmetros

*classFlags*<br/>
Parâmetro opcional. Uma combinação de um ou mais valores de enumeração [RuntimeClassType.](runtimeclasstype-enumeration.md) A `__WRL_CONFIGURATION_LEGACY__` macro pode ser definida para alterar o valor padrão do classFlags para todas as classes de tempo de execução no projeto. Se definidas, as instâncias do RuntimeClass não são ágeis por padrão. Quando não definidas, as instâncias do RuntimeClass são ágeis por padrão. Para evitar a ambiguidade, especifique sempre a `Microsoft::WRL::FtmBase` in `TInterfaces` ou `RuntimeClassType::InhibitFtmBase`. Observe que, se o InhibitFtmBase e o FtmBase forem usados, o objeto será ágil.

*Interfaces T*<br/>
A lista de interfaces que `IUnknown` `IInspectable` o objeto implementa além ou outras interfaces controladas pelo [RuntimeClassType](runtimeclasstype-enumeration.md). Também pode listar outras classes a serem `Microsoft::WRL::FtmBase` derivadas, notadamente para `IMarshal`tornar o objeto ágil e fazê-lo implementar .

## <a name="members"></a>Membros

`RuntimeClassInitialize`<br/>
Uma função que inicializa o `MakeAndInitialize` objeto se a função de modelo for usada para construir o objeto. Ele retorna S_OK se o objeto foi inicializado com sucesso ou um código de erro COM se a inicialização falhar. O código de erro COM é `MakeAndInitialize`propagado como o valor de retorno de . Observe que `RuntimeClassInitialize` o método não `Make` é chamado se a função de modelo for usada para construir o objeto.

### <a name="public-constructors"></a>Construtores públicos

| Nome                                               | Descrição                                                     |
| -------------------------------------------------- | --------------------------------------------------------------- |
| [Classe de execução::RuntimeClass](#runtimeclass)        | Inicializa a instância atual `RuntimeClass` da classe.   |
| [RuntimeClass::~RuntimeClass](#tilde-runtimeclass) | Desinicializa a instância `RuntimeClass` atual da classe. |

### <a name="public-methods"></a>Métodos públicos

| Nome                                                      | Descrição                                                                                        |
| --------------------------------------------------------- | -------------------------------------------------------------------------------------------------- |
| [Classe de execução::AddRef](#addref)                           | Incrementa a contagem `RuntimeClass` de referência para o objeto atual.                              |
| [RuntimeClass::DecrementReference](#decrementreference)   | Decreta a contagem de `RuntimeClass` referência para o objeto atual.                              |
| [RuntimeClass::GetIids](#getiids)                         | Obtém uma matriz que pode conter os `RuntimeClass` IDs de interface implementados pelo objeto atual. |
| [Classe de execução::GetRuntimeClassName](#getruntimeclassname) | Obtém o nome da `RuntimeClass` classe de tempo de execução do objeto atual.                                  |
| [Classe de execução::GetTrustLevel](#gettrustlevel)             | Obtém o nível `RuntimeClass` de confiança do objeto atual.                                         |
| [Classe de execução::GetWeakReference](#getweakreference)       | Obtém um ponteiro para o `RuntimeClass` objeto de referência fraco para o objeto atual.                 |
| [Classe de execução::InternalAddRef](#internaladdref)           | Incrementa a contagem `RuntimeClass` de referência ao objeto atual.                               |
| [Classe de execução::QueryInterface](#queryinterface)           | Recupera um ponteiro para o ID de interface especificado.                                                 |
| [RuntimeClass::Lançamento](#release)                         | Executa uma operação de `RuntimeClass` liberação COM no objeto atual.                             |

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

Isso é um detalhe de implementação.

## <a name="requirements"></a>Requisitos

**Cabeçalho:** implements.h

**Espaço de nome:** Microsoft::WRL

## <a name="runtimeclassruntimeclass"></a><a name="tilde-runtimeclass"></a>RuntimeClass::~RuntimeClass

Desinicializa a instância `RuntimeClass` atual da classe.

```cpp
virtual ~RuntimeClass();
```

## <a name="runtimeclassaddref"></a><a name="addref"></a>Classe de execução::AddRef

Incrementa a contagem `RuntimeClass` de referência para o objeto atual.

```cpp
STDMETHOD_(
   ULONG,
   AddRef
)();
```

### <a name="return-value"></a>Valor retornado

S_OK se for bem sucedido; caso contrário, um HRESULT que indica o erro.

## <a name="runtimeclassdecrementreference"></a><a name="decrementreference"></a>RuntimeClass::DecrementReference

Decreta a contagem de `RuntimeClass` referência para o objeto atual.

```cpp
ULONG DecrementReference();
```

### <a name="return-value"></a>Valor retornado

S_OK se for bem sucedido; caso contrário, um HRESULT que indica o erro.

## <a name="runtimeclassgetiids"></a><a name="getiids"></a>RuntimeClass::GetIids

Obtém uma matriz que pode conter os `RuntimeClass` IDs de interface implementados pelo objeto atual.

```cpp
STDMETHOD(
   GetIids
)
   (_Out_ ULONG *iidCount,
   _Deref_out_ _Deref_post_cap_(*iidCount) IID **iids);
```

### <a name="parameters"></a>Parâmetros

*IidCount*<br/>
Quando esta operação for concluída, o número total de elementos em *iids*de matriz .

*Iids*<br/>
Quando esta operação for concluída, um ponteiro para uma matriz de IDs de interface.

### <a name="return-value"></a>Valor retornado

S_OK se for bem sucedido; caso contrário, E_OUTOFMEMORY.

## <a name="runtimeclassgetruntimeclassname"></a><a name="getruntimeclassname"></a>Classe de execução::GetRuntimeClassName

Obtém o nome da `RuntimeClass` classe de tempo de execução do objeto atual.

```cpp
STDMETHOD( GetRuntimeClassName )(
    _Out_ HSTRING* runtimeName
);
```

### <a name="parameters"></a>Parâmetros

*runtimeName*<br/>
Quando esta operação for concluída, o nome da classe de tempo de execução.

### <a name="return-value"></a>Valor retornado

S_OK se for bem sucedido; caso contrário, um HRESULT que indica o erro.

### <a name="remarks"></a>Comentários

Um erro de afirmação é emitido se `__WRL_STRICT__` ou `__WRL_FORCE_INSPECTABLE_CLASS_MACRO__` não for definido.

## <a name="runtimeclassgettrustlevel"></a><a name="gettrustlevel"></a>Classe de execução::GetTrustLevel

Obtém o nível `RuntimeClass` de confiança do objeto atual.

```cpp
STDMETHOD(GetTrustLevel)(
    _Out_ TrustLevel* trustLvl
);
```

### <a name="parameters"></a>Parâmetros

*trustLvl*<br/>
Quando esta operação for concluída, o `RuntimeClass` nível de confiança do objeto atual.

### <a name="return-value"></a>Valor retornado

Sempre S_OK.

### <a name="remarks"></a>Comentários

Um erro de afirmação é emitido se `__WRL_STRICT__` ou `__WRL_FORCE_INSPECTABLE_CLASS_MACRO__` não for definido.

## <a name="runtimeclassgetweakreference"></a><a name="getweakreference"></a>Classe de execução::GetWeakReference

Obtém um ponteiro para o `RuntimeClass` objeto de referência fraco para o objeto atual.

```cpp
STDMETHOD(
   GetWeakReference
)(_Deref_out_ IWeakReference **weakReference);
```

### <a name="parameters"></a>Parâmetros

*Weakreference*<br/>
Quando esta operação for concluída, um ponteiro para um objeto de referência fraco.

### <a name="return-value"></a>Valor retornado

Sempre S_OK.

## <a name="runtimeclassinternaladdref"></a><a name="internaladdref"></a>Classe de execução::InternalAddRef

Incrementa a contagem `RuntimeClass` de referência ao objeto atual.

```cpp
ULONG InternalAddRef();
```

### <a name="return-value"></a>Valor retornado

A contagem de referência resultante.

## <a name="runtimeclassqueryinterface"></a><a name="queryinterface"></a>Classe de execução::QueryInterface

Recupera um ponteiro para o ID de interface especificado.

```cpp
STDMETHOD(
   QueryInterface
)
   (REFIID riid,
   _Deref_out_ void **ppvObject);
```

### <a name="parameters"></a>Parâmetros

*riid*<br/>
Um ID de interface.

*Ppvobject*<br/>
Quando esta operação for concluída, um ponteiro para a interface especificado pelo parâmetro *riid.*

### <a name="return-value"></a>Valor retornado

S_OK se for bem sucedido; caso contrário, um HRESULT que indica o erro.

## <a name="runtimeclassrelease"></a><a name="release"></a>RuntimeClass::Lançamento

Executa uma operação de `RuntimeClass` liberação COM no objeto atual.

```cpp
STDMETHOD_(
   ULONG,
   Release
)();
```

### <a name="return-value"></a>Valor retornado

S_OK se for bem sucedido; caso contrário, um HRESULT que indica o erro.

### <a name="remarks"></a>Comentários

Se a contagem de `RuntimeClass` referência se tornar zero, o objeto será excluído.

## <a name="runtimeclassruntimeclass"></a><a name="runtimeclass"></a>Classe de execução::RuntimeClass

Inicializa a instância atual `RuntimeClass` da classe.

```cpp
RuntimeClass();
```
