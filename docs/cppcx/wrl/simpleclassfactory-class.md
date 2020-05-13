---
title: Classe SimpleClassFactory
ms.date: 09/7/2018
ms.topic: reference
f1_keywords:
- module/Microsoft::WRL::SimpleClassFactory
- module/Microsoft::WRL::SimpleClassFactory::CreateInstance
helpviewer_keywords:
- Microsoft::WRL::SimpleClassFactory class
- Microsoft::WRL::SimpleClassFactory::CreateInstance method
ms.assetid: 6edda1b2-4e44-4e14-9364-72f519249962
ms.openlocfilehash: 924b9d2c30f11e6f0444d9c647807f1c86dcc411
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81373559"
---
# <a name="simpleclassfactory-class"></a>Classe SimpleClassFactory

Fornece um mecanismo fundamental para criar uma classe base.

## <a name="syntax"></a>Sintaxe

```cpp
template<typename Base>
class SimpleClassFactory : public ClassFactory<>;
```

### <a name="parameters"></a>Parâmetros

*Base*<br/>
Uma classe base.

## <a name="remarks"></a>Comentários

A classe base deve fornecer um construtor padrão.

O exemplo de código `SimpleClassFactory` a seguir demonstra como usar com a macro [ActivatableClassWithFactoryEx.](activatableclass-macros.md)

`ActivatableClassWithFactoryEx(MyClass, SimpleClassFactory, MyServerName);`

## <a name="members"></a>Membros

### <a name="public-methods"></a>Métodos públicos

|Nome|Descrição|
|----------|-----------------|
|[Método SimpleClassFactory::CreateInstance](#createinstance)|Cria uma instância da interface especificada.|

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

`SimpleClassFactory`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** module.h

**Espaço de nome:** Microsoft::WRL

## <a name="simpleclassfactorycreateinstance-method"></a><a name="createinstance"></a>SimpleClasseFábrica::Método de criaçãode ocorrência

Cria uma instância da interface especificada.

```cpp
STDMETHOD( CreateInstance )(
   _Inout_opt_ IUnknown* pUnkOuter,
   REFIID riid,
   _Deref_out_ void** ppvObject
);
```

#### <a name="parameters"></a>Parâmetros

*Punkouter*<br/>
Deve `nullptr`ser; caso contrário, o valor de retorno é CLASS_E_NOAGGREGATION.

SimpleClassFactory não suporta agregação. Se a agregação fosse suportada e o objeto que estava sendo criado fosse parte de `IUnknown` um agregado, *pUnkOuter* seria um ponteiro para a interface de controle do agregado.

*riid*<br/>
Interface ID do objeto a ser criado.

*Ppvobject*<br/>
Quando esta operação for concluída, ponteiro para uma instância do objeto especificado pelo parâmetro *riid.*

### <a name="return-value"></a>Valor retornado

S_OK se for bem sucedido; caso contrário, um HRESULT que indica o erro.

### <a name="remarks"></a>Comentários

Se `__WRL_STRICT__` for definido, um erro de afirmação será emitido se a classe base especificada no parâmetro de modelo de classe não for derivada do [RuntimeClass](runtimeclass-class.md)ou não estiver configurada com o valor de enumeração ClassicCom ou WinRtClassicComMix [RuntimeClassType.](runtimeclasstype-enumeration.md)
