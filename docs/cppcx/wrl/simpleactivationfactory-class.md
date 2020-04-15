---
title: Classe SimpleActivationFactory
ms.date: 09/07/2018
ms.topic: reference
f1_keywords:
- module/Microsoft::WRL::SimpleActivationFactory
- module/Microsoft::WRL::SimpleActivationFactory::ActivateInstance
- module/Microsoft::WRL::SimpleActivationFactory::GetRuntimeClassName
- module/Microsoft::WRL::SimpleActivationFactory::GetTrustLevel
helpviewer_keywords:
- Microsoft::WRL::SimpleActivationFactory class
- Microsoft::WRL::SimpleActivationFactory::ActivateInstance method
- Microsoft::WRL::SimpleActivationFactory::GetRuntimeClassName method
- Microsoft::WRL::SimpleActivationFactory::GetTrustLevel method
ms.assetid: aff768e0-0038-4fd7-95d2-ad7d308da41c
ms.openlocfilehash: 39e539c63e91b508f51656114ee8fbd68150991f
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81370944"
---
# <a name="simpleactivationfactory-class"></a>Classe SimpleActivationFactory

Fornece um mecanismo fundamental para criar um Windows Runtime ou uma classe base COM clássica.

## <a name="syntax"></a>Sintaxe

```cpp
template<typename Base>
class SimpleActivationFactory : public ActivationFactory<>;
```

### <a name="parameters"></a>Parâmetros

*Base*<br/>
Uma classe base.

## <a name="remarks"></a>Comentários

A classe base deve fornecer um construtor padrão.

O exemplo de código a seguir demonstra como usar SimpleActivationFactory com a macro [ActivatableClassWithFactoryEx.](activatableclass-macros.md)

`ActivatableClassWithFactoryEx(MyClass, SimpleActivationFactory, MyServerName);`

## <a name="members"></a>Membros

### <a name="public-methods"></a>Métodos públicos

|Nome|Descrição|
|----------|-----------------|
|[Método SimpleActivationFactory::ActivateInstance](#activateinstance)|Cria uma instância da interface especificada.|
|[Método SimpleActivationFactory::GetRuntimeClassName](#getruntimeclassname)|Obtém o nome da classe de tempo de execução de uma instância da classe especificada pelo parâmetro de modelo de classe *Base.*|
|[Método SimpleActivationFactory::GetTrustLevel](#gettrustlevel)|Obtém o nível de confiança de uma instância da classe especificada pelo parâmetro de modelo de classe *Base.*|

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

`SimpleActivationFactory`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** module.h

**Espaço de nome:** Microsoft::WRL

## <a name="simpleactivationfactoryactivateinstance-method"></a><a name="activateinstance"></a>SimpleActivationFactory::ActivateInstance Method

Cria uma instância da interface especificada.

```cpp
STDMETHOD( ActivateInstance )(
    _Deref_out_ IInspectable **ppvObject
);
```

#### <a name="parameters"></a>Parâmetros

*Ppvobject*<br/>
Quando esta operação for concluída, ponteiro para uma `Base` instância do objeto especificado pelo parâmetro modelo de classe.

### <a name="return-value"></a>Valor retornado

S_OK se for bem sucedido; caso contrário, um HRESULT que indica o erro.

### <a name="remarks"></a>Comentários

Se `__WRL_STRICT__` for definido, um erro de afirmação será emitido se a classe base especificada no parâmetro de modelo de classe não for derivada do [RuntimeClass](runtimeclass-class.md)ou não estiver configurada com o valor de enumeração WinRt ou WinRtClassicComMix [RuntimeClassType.](runtimeclasstype-enumeration.md)

## <a name="simpleactivationfactorygetruntimeclassname-method"></a><a name="getruntimeclassname"></a>SimplesAtivade fábrica::GetRuntimeClassName Method

Obtém o nome da classe de tempo de `Base` execução de uma instância da classe especificada pelo parâmetro de modelo de classe.

```cpp
STDMETHOD( GetRuntimeClassName )(
    _Out_ HSTRING* runtimeName
);
```

#### <a name="parameters"></a>Parâmetros

*runtimeName*<br/>
Quando esta operação for concluída, o nome da classe de tempo de execução.

### <a name="return-value"></a>Valor retornado

S_OK se for bem sucedido; caso contrário, um HRESULT que indica o erro.

### <a name="remarks"></a>Comentários

Se `__WRL_STRICT__` for definido, um erro de afirmação será `Base` emitido se a classe especificada pelo parâmetro de modelo de classe não for derivada do [RuntimeClass](runtimeclass-class.md)ou não estiver configurada com o valor de enumeração WinRt ou WinRtClassicComMix [RuntimeClassType.](runtimeclasstype-enumeration.md)

## <a name="simpleactivationfactorygettrustlevel-method"></a><a name="gettrustlevel"></a>SimpleActivationFactory::GetTrustLevel Method

Obtém o nível de confiança de uma `Base` instância da classe especificada pelo parâmetro de modelo de classe.

```cpp
STDMETHOD(
   GetTrustLevel
)(_Out_ TrustLevel* trustLvl);
```

#### <a name="parameters"></a>Parâmetros

*trustLvl*<br/>
Quando esta operação for concluída, o nível de confiança do objeto de classe atual.

### <a name="return-value"></a>Valor retornado

Sempre S_OK.
