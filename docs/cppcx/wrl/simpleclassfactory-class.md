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
ms.openlocfilehash: 9a4c169944d56b693efa681bf7089636477012ea
ms.sourcegitcommit: 5cecccba0a96c1b4ccea1f7a1cfd91f259cc5bde
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/01/2019
ms.locfileid: "58783804"
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

O exemplo de código a seguir demonstra como usar `SimpleClassFactory` com o [ActivatableClassWithFactoryEx](activatableclass-macros.md) macro.

`ActivatableClassWithFactoryEx(MyClass, SimpleClassFactory, MyServerName);`

## <a name="members"></a>Membros

### <a name="public-methods"></a>Métodos Públicos

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

**Namespace:** Microsoft::WRL

## <a name="createinstance"></a>Método simpleclassfactory:: CreateInstance

Cria uma instância da interface especificada.

```cpp
STDMETHOD( CreateInstance )(
   _Inout_opt_ IUnknown* pUnkOuter,
   REFIID riid,
   _Deref_out_ void** ppvObject
);
```

#### <a name="parameters"></a>Parâmetros

*pUnkOuter*<br/>
Deve ser `nullptr`; caso contrário, o valor retornado é CLASS_E_NOAGGREGATION.

SimpleClassFactory não dá suporte a agregação. Se havia suporte para a agregação e o objeto que está sendo criado fazia parte de uma agregação *pUnkOuter* seria um ponteiro para o controle `IUnknown` interface da agregação.

*riid*<br/>
ID do objeto para criar a interface.

*ppvObject*<br/>
Quando essa operação for concluída, ponteiro para uma instância do objeto especificado o *riid* parâmetro.

### <a name="return-value"></a>Valor de retorno

S_OK se bem-sucedido; Caso contrário, um HRESULT que indica o erro.

### <a name="remarks"></a>Comentários

Se `__WRL_STRICT__` é definido, um erro de asserção será emitido se a classe base especificada no parâmetro de modelo de classe não é derivada da [RuntimeClass](runtimeclass-class.md), ou não está configurada com o ClassicCom ou WinRtClassicComMix [ RuntimeClassType](runtimeclasstype-enumeration.md) valor de enumeração.
