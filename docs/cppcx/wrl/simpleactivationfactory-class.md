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
ms.openlocfilehash: 1831a816d0967c2ca53f941128639ea368c1b727
ms.sourcegitcommit: 5cecccba0a96c1b4ccea1f7a1cfd91f259cc5bde
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/01/2019
ms.locfileid: "58783968"
---
# <a name="simpleactivationfactory-class"></a>Classe SimpleActivationFactory

Fornece um mecanismo fundamental para criar um tempo de execução do Windows ou a classe base do COM clássico.

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

O exemplo de código a seguir demonstra como usar SimpleActivationFactory com o [ActivatableClassWithFactoryEx](activatableclass-macros.md) macro.

`ActivatableClassWithFactoryEx(MyClass, SimpleActivationFactory, MyServerName);`

## <a name="members"></a>Membros

### <a name="public-methods"></a>Métodos Públicos

|Nome|Descrição|
|----------|-----------------|
|[Método SimpleActivationFactory::ActivateInstance](#activateinstance)|Cria uma instância da interface especificada.|
|[Método SimpleActivationFactory::GetRuntimeClassName](#getruntimeclassname)|Obtém o nome de classe de tempo de execução de uma instância da classe especificada o *Base* parâmetro de modelo de classe.|
|[Método SimpleActivationFactory::GetTrustLevel](#gettrustlevel)|Obtém o nível de confiança de uma instância da classe especificada o *Base* parâmetro de modelo de classe.|

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

**Namespace:** Microsoft::WRL

## <a name="activateinstance"></a>Método simpleactivationfactory:: Activateinstance

Cria uma instância da interface especificada.

```cpp
STDMETHOD( ActivateInstance )(
    _Deref_out_ IInspectable **ppvObject
);
```

#### <a name="parameters"></a>Parâmetros

*ppvObject*<br/>
Quando essa operação for concluída, ponteiro para uma instância do objeto especificado pelo `Base` parâmetro de modelo de classe.

### <a name="return-value"></a>Valor de retorno

S_OK se bem-sucedido; Caso contrário, um HRESULT que indica o erro.

### <a name="remarks"></a>Comentários

Se `__WRL_STRICT__` é definido, um erro de asserção será emitido se a classe base especificada no parâmetro de modelo de classe não é derivada da [RuntimeClass](runtimeclass-class.md), ou não está configurada com o WinRt ou WinRtClassicComMix [ RuntimeClassType](runtimeclasstype-enumeration.md) valor de enumeração.

## <a name="getruntimeclassname"></a>Método simpleactivationfactory:: Getruntimeclassname

Obtém o nome de classe de tempo de execução de uma instância da classe especificada pelo `Base` parâmetro de modelo de classe.

```cpp
STDMETHOD( GetRuntimeClassName )(
    _Out_ HSTRING* runtimeName
);
```

#### <a name="parameters"></a>Parâmetros

*runtimeName*<br/>
Quando essa operação for concluída, o nome de classe de tempo de execução.

### <a name="return-value"></a>Valor de retorno

S_OK se bem-sucedido; Caso contrário, um HRESULT que indica o erro.

### <a name="remarks"></a>Comentários

Se `__WRL_STRICT__` é definido, um erro de asserção será emitido se a classe especificada pelo `Base` parâmetro de modelo de classe não é derivado de [RuntimeClass](runtimeclass-class.md), ou não está configurada com o WinRt ou WinRtClassicComMix [RuntimeClassType](runtimeclasstype-enumeration.md) valor de enumeração.

## <a name="gettrustlevel"></a>Método simpleactivationfactory:: Gettrustlevel

Obtém o nível de confiança de uma instância da classe especificada pelo `Base` parâmetro de modelo de classe.

```cpp
STDMETHOD(
   GetTrustLevel
)(_Out_ TrustLevel* trustLvl);
```

#### <a name="parameters"></a>Parâmetros

*trustLvl*<br/>
Quando essa operação for concluída, o nível de confiança do objeto da classe atual.

### <a name="return-value"></a>Valor de retorno

Sempre S_OK.
