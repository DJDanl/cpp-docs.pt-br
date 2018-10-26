---
title: Classe IDispatchImpl | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-atl
ms.topic: reference
f1_keywords:
- IDispatchImpl
- ATLCOM/ATL::IDispatchImpl
- ATLCOM/ATL::IDispatchImpl::IDispatchImpl
- ATLCOM/ATL::IDispatchImpl::GetIDsOfNames
- ATLCOM/ATL::IDispatchImpl::GetTypeInfo
- ATLCOM/ATL::IDispatchImpl::GetTypeInfoCount
- ATLCOM/ATL::IDispatchImpl::Invoke
dev_langs:
- C++
helpviewer_keywords:
- dual interfaces, classes
- IDispatchImpl class
- IDispatch class support in ATL
ms.assetid: 8108eb36-1228-4127-a203-3ab5ba488892
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 8f457f47cc04791bc46aaa531d787f4d3f7044e1
ms.sourcegitcommit: a9dcbcc85b4c28eed280d8e451c494a00d8c4c25
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/25/2018
ms.locfileid: "50055353"
---
# <a name="idispatchimpl-class"></a>Classe IDispatchImpl

Fornece uma implementação padrão para o `IDispatch` faz parte de uma interface dupla.

> [!IMPORTANT]
>  Essa classe e seus membros não podem ser usados em aplicativos executados no tempo de execução do Windows.

## <a name="syntax"></a>Sintaxe

```
template<class T,
        const IID* piid= &__uuidof(T),
        const GUID* plibid = &CAtlModule::m_libid,
        WORD wMajor = 1,
        WORD wMinor = 0,
        class tihclass = CComTypeInfoHolder>
class ATL_NO_VTABLE IDispatchImpl : public T
```

#### <a name="parameters"></a>Parâmetros

*T*<br/>
[in] Uma interface dupla.

*piid*<br/>
[in] Um ponteiro para o IID da *T*.

*plibid*<br/>
[in] Um ponteiro para o LIBID da biblioteca de tipos que contém informações sobre a interface. Por padrão, a biblioteca de tipos de nível de servidor é passada.

*wMajor*<br/>
[in] A versão principal da biblioteca de tipos. Por padrão, o valor é 1.

*wMinor*<br/>
[in] A versão secundária da biblioteca de tipos. Por padrão, o valor é 0.

*tihclass*<br/>
[in] A classe usada para gerenciar as informações de tipo de *T*. Por padrão, o valor é `CComTypeInfoHolder`.

## <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores Públicos

|Nome|Descrição|
|----------|-----------------|
|[IDispatchImpl::IDispatchImpl](#idispatchimpl)|O construtor. Chamadas `AddRef` na variável de membro protegida que gerencia as informações de tipo para a interface dupla. O destruidor chama `Release`.|

### <a name="public-methods"></a>Métodos públicos

|Nome|Descrição|
|----------|-----------------|
|[IDispatchImpl::GetIDsOfNames](#getidsofnames)|Mapeia um conjunto de nomes para um conjunto correspondente de identificadores de expedição.|
|[IDispatchImpl::GetTypeInfo](#gettypeinfo)|Recupera as informações de tipo para a interface dupla.|
|[IDispatchImpl::GetTypeInfoCount](#gettypeinfocount)|Determina se as informações de tipo está disponível para a interface dupla.|
|[IDispatchImpl::Invoke](#invoke)|Fornece acesso aos métodos e propriedades expostas pela interface dupla.|

## <a name="remarks"></a>Comentários

`IDispatchImpl` Fornece uma implementação padrão para o `IDispatch` faz parte de qualquer interface dupla em um objeto. Deriva de uma interface dupla `IDispatch` e usa apenas os tipos compatíveis com a automação. Como um dispinterface, uma interface dupla oferece suporte a associação antecipada e associação tardia; No entanto, uma interface dupla também oferece suporte a associação vtable.

O exemplo a seguir mostra uma implementação típica do `IDispatchImpl`.

[!code-cpp[NVC_ATL_COM#47](../../atl/codesnippet/cpp/idispatchimpl-class_1.h)]

Por padrão, o `IDispatchImpl` classe procura informações de tipo para *T* no registro. Para implementar uma interface de cancelar o registro, você pode usar o `IDispatchImpl` classe sem acessar o registro usando um número de versão predefinidos. Se você criar uma `IDispatchImpl` objeto que tem 0xFFFF como o valor para *wMajor* e 0xFFFF como o valor para *wMinor*, o `IDispatchImpl` classe recupera a biblioteca de tipos de arquivo. dll em vez da Registro.

`IDispatchImpl` contém um membro estático do tipo `CComTypeInfoHolder` que gerencia as informações de tipo para a interface dupla. Se você tiver vários objetos que implementam a dupla mesma interface, apenas uma instância de `CComTypeInfoHolder` é usado.

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

`T`

`IDispatchImpl`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** atlcom

##  <a name="getidsofnames"></a>  IDispatchImpl::GetIDsOfNames

Mapeia um conjunto de nomes para um conjunto correspondente de identificadores de expedição.

```
STDMETHOD(GetIDsOfNames)(
    REFIID riid,
    LPOLESTR* rgszNames,
    UINT cNames,
    LCID lcid,
    DISPID* rgdispid);
```

### <a name="remarks"></a>Comentários

Ver [IDispatch::GetIDsOfNames](/previous-versions/windows/desktop/api/oaidl/nf-oaidl-idispatch-getidsofnames) no Windows SDK.

##  <a name="gettypeinfo"></a>  IDispatchImpl::GetTypeInfo

Recupera as informações de tipo para a interface dupla.

```
STDMETHOD(GetTypeInfo)(
    UINT itinfo,
    LCID lcid,
    ITypeInfo** pptinfo);
```

### <a name="remarks"></a>Comentários

Ver [IDispatch:: GetTypeInfo](/previous-versions/windows/desktop/api/oaidl/nf-oaidl-idispatch-gettypeinfo) no Windows SDK.

##  <a name="gettypeinfocount"></a>  IDispatchImpl::GetTypeInfoCount

Determina se as informações de tipo está disponível para a interface dupla.

```
STDMETHOD(GetTypeInfoCount)(UINT* pctinfo);
```

### <a name="remarks"></a>Comentários

Consulte `IDispatch::GetTypeInfoCount` no Windows SDK.

##  <a name="idispatchimpl"></a>  IDispatchImpl::IDispatchImpl

O construtor. Chamadas `AddRef` na variável de membro protegida que gerencia as informações de tipo para a interface dupla. O destruidor chama `Release`.

```
IDispatchImpl();
```

##  <a name="invoke"></a>  IDispatchImpl::Invoke

Fornece acesso aos métodos e propriedades expostas pela interface dupla.

```
STDMETHOD(Invoke)(
    DISPID dispidMember,
    REFIID riid,
    LCID lcid,
    WORD wFlags,
    DISPPARAMS* pdispparams,
    VARIANT* pvarResult,
    EXCEPINFO* pexcepinfo,
    UINT* puArgErr);
```

### <a name="remarks"></a>Comentários

Ver [IDispatch:: Invoke](/previous-versions/windows/desktop/api/oaidl/nf-oaidl-idispatch-invoke) no Windows SDK.

## <a name="see-also"></a>Consulte também

[Visão geral da classe](../../atl/atl-class-overview.md)
