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
ms.openlocfilehash: 66794789e51a2635fae646cca49e4fae8385dfe0
ms.sourcegitcommit: 1f009ab0f2cc4a177f2d1353d5a38f164612bdb1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/27/2020
ms.locfileid: "87211145"
---
# <a name="simpleclassfactory-class"></a>Classe SimpleClassFactory

Fornece um mecanismo fundamental para criar uma classe base.

## <a name="syntax"></a>Sintaxe

```cpp
template<typename Base>
class SimpleClassFactory : public ClassFactory<>;
```

### <a name="parameters"></a>parâmetros

*Polybase*<br/>
Uma classe base.

## <a name="remarks"></a>Comentários

A classe base deve fornecer um construtor padrão.

O exemplo de código a seguir demonstra como usar `SimpleClassFactory` o com a macro [ActivatableClassWithFactoryEx](activatableclass-macros.md) .

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

**Cabeçalho:** Module. h

**Namespace:** Microsoft:: WRL

## <a name="simpleclassfactorycreateinstance-method"></a><a name="createinstance"></a>Método SimpleClassFactory:: CreateInstance

Cria uma instância da interface especificada.

```cpp
STDMETHOD( CreateInstance )(
   _Inout_opt_ IUnknown* pUnkOuter,
   REFIID riid,
   _Deref_out_ void** ppvObject
);
```

#### <a name="parameters"></a>parâmetros

*pUnkOuter*<br/>
Deve ser **`nullptr`** ; caso contrário, o valor de retorno será CLASS_E_NOAGGREGATION.

SimpleClassFactory não dá suporte à agregação. Se a agregação tiver suporte e o objeto que está sendo criado fazia parte de uma agregação, *pUnkOuter* seria um ponteiro para a `IUnknown` interface de controle da agregação.

*riid*<br/>
ID da interface do objeto a ser criado.

*ppvObject*<br/>
Quando essa operação é concluída, o ponteiro para uma instância do objeto especificado pelo parâmetro *riid* .

### <a name="return-value"></a>Valor retornado

S_OK se for bem-sucedido; caso contrário, um HRESULT que indica o erro.

### <a name="remarks"></a>Comentários

Se `__WRL_STRICT__` for definido, um erro de declaração será emitido se a classe base especificada no parâmetro de modelo de classe não for derivada de [RuntimeClass](runtimeclass-class.md)ou não estiver configurada com o valor de enumeração ClassicCom ou WinRtClassicComMix [RuntimeClassType](runtimeclasstype-enumeration.md) .
