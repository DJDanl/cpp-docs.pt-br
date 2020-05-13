---
title: Classe IDispatchImpl
ms.date: 11/04/2016
f1_keywords:
- IDispatchImpl
- ATLCOM/ATL::IDispatchImpl
- ATLCOM/ATL::IDispatchImpl::IDispatchImpl
- ATLCOM/ATL::IDispatchImpl::GetIDsOfNames
- ATLCOM/ATL::IDispatchImpl::GetTypeInfo
- ATLCOM/ATL::IDispatchImpl::GetTypeInfoCount
- ATLCOM/ATL::IDispatchImpl::Invoke
helpviewer_keywords:
- dual interfaces, classes
- IDispatchImpl class
- IDispatch class support in ATL
ms.assetid: 8108eb36-1228-4127-a203-3ab5ba488892
ms.openlocfilehash: 3b3899a0c4a49aa7fb1bd82af330f5f1cc7329c4
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81329804"
---
# <a name="idispatchimpl-class"></a>Classe IDispatchImpl

Fornece uma implementação `IDispatch` padrão para a parte de uma interface dupla.

> [!IMPORTANT]
> Esta classe e seus membros não podem ser usados em aplicativos executados no Tempo de execução do Windows.

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
[em] Uma interface dupla.

*Piid*<br/>
[em] Um ponteiro para o IID de *T*.

*plibid*<br/>
[em] Um ponteiro para o LIBID da biblioteca do tipo que contém informações sobre a interface. Por padrão, a biblioteca do tipo nível do servidor é aprovada.

*wMajor*<br/>
[em] A versão principal da biblioteca do tipo. Por padrão, o valor é 1.

*wMenor*<br/>
[em] A versão menor da biblioteca do tipo. Por padrão, o valor é 0.

*tihclass*<br/>
[em] A classe usada para gerenciar as informações do tipo para *T*. Por padrão, o `CComTypeInfoHolder`valor é .

## <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores públicos

|Nome|Descrição|
|----------|-----------------|
|[IDispatchImpl::IDispatchImpl](#idispatchimpl)|O construtor. Chama `AddRef` a variável membro protegido que gerencia as informações do tipo para a interface dupla. O destruidor chama `Release`.|

### <a name="public-methods"></a>Métodos públicos

|Nome|Descrição|
|----------|-----------------|
|[IDispatchImpl::GetIDsOfNames](#getidsofnames)|Mapeia um conjunto de nomes para um conjunto correspondente de identificadores de expedição.|
|[IDispatchImpl::GetTypeInfo](#gettypeinfo)|Recupera as informações do tipo para a interface dupla.|
|[IDispatchImpl::GetTypeInfoCount](#gettypeinfocount)|Determina se há informações de tipo disponíveis para a interface dupla.|
|[IDispatchImpl::Invocar](#invoke)|Fornece acesso aos métodos e propriedades expostos pela interface dupla.|

## <a name="remarks"></a>Comentários

`IDispatchImpl`fornece uma implementação `IDispatch` padrão para a parte de qualquer interface dupla em um objeto. Uma interface dupla `IDispatch` deriva e usa apenas tipos compatíveis com automação. Como uma dispinterface, uma interface dupla suporta vinculação antecipada e vinculação tardia; no entanto, uma interface dupla também suporta vinculação vtable.

O exemplo a seguir `IDispatchImpl`mostra uma implementação típica de .

[!code-cpp[NVC_ATL_COM#47](../../atl/codesnippet/cpp/idispatchimpl-class_1.h)]

Por padrão, `IDispatchImpl` a classe procura as informações do tipo para *T* no registro. Para implementar uma interface não registrada, `IDispatchImpl` você pode usar a classe sem acessar o registro usando um número de versão predefinido. Se você `IDispatchImpl` criar um objeto que tenha 0xFFFF como valor para *wMajor* e `IDispatchImpl` 0xFFFF como valor para *wMinor,* a classe recuperará a biblioteca do tipo do arquivo .dll em vez do registro.

`IDispatchImpl`contém um membro `CComTypeInfoHolder` estático do tipo que gerencia as informações do tipo para a interface dupla. Se você tiver vários objetos que implementam `CComTypeInfoHolder` a mesma interface dupla, apenas uma instância de será usada.

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

`T`

`IDispatchImpl`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** atlcom.h

## <a name="idispatchimplgetidsofnames"></a><a name="getidsofnames"></a>IDispatchImpl::GetIDsOfNames

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

Consulte [IDispatch::GetIDsOfNames](/windows/win32/api/oaidl/nf-oaidl-idispatch-getidsofnames) no Windows SDK.

## <a name="idispatchimplgettypeinfo"></a><a name="gettypeinfo"></a>IDispatchImpl::GetTypeInfo

Recupera as informações do tipo para a interface dupla.

```
STDMETHOD(GetTypeInfo)(
    UINT itinfo,
    LCID lcid,
    ITypeInfo** pptinfo);
```

### <a name="remarks"></a>Comentários

Consulte [IDispatch::GetTypeInfo](/windows/win32/api/oaidl/nf-oaidl-idispatch-gettypeinfo) no Windows SDK.

## <a name="idispatchimplgettypeinfocount"></a><a name="gettypeinfocount"></a>IDispatchImpl::GetTypeInfoCount

Determina se há informações de tipo disponíveis para a interface dupla.

```
STDMETHOD(GetTypeInfoCount)(UINT* pctinfo);
```

### <a name="remarks"></a>Comentários

Veja `IDispatch::GetTypeInfoCount` no Windows SDK.

## <a name="idispatchimplidispatchimpl"></a><a name="idispatchimpl"></a>IDispatchImpl::IDispatchImpl

O construtor. Chama `AddRef` a variável membro protegido que gerencia as informações do tipo para a interface dupla. O destruidor chama `Release`.

```
IDispatchImpl();
```

## <a name="idispatchimplinvoke"></a><a name="invoke"></a>IDispatchImpl::Invocar

Fornece acesso aos métodos e propriedades expostos pela interface dupla.

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

Consulte [IDispatch::Invocar](/windows/win32/api/oaidl/nf-oaidl-idispatch-invoke) no Windows SDK.

## <a name="see-also"></a>Confira também

[Visão geral da classe](../../atl/atl-class-overview.md)
