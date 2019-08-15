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
ms.openlocfilehash: 7e9cb903742cdc31c1d9bba2c4aabbb0472407c1
ms.sourcegitcommit: fcb48824f9ca24b1f8bd37d647a4d592de1cc925
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/15/2019
ms.locfileid: "69495957"
---
# <a name="idispatchimpl-class"></a>Classe IDispatchImpl

Fornece uma implementação padrão para a `IDispatch` parte de uma interface dupla.

> [!IMPORTANT]
>  Essa classe e seus membros não podem ser usados em aplicativos que são executados no Windows Runtime.

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
no Uma interface dupla.

*piid*<br/>
no Um ponteiro para o IID de *T*.

*plibid*<br/>
no Um ponteiro para o LIBID da biblioteca de tipos que contém informações sobre a interface. Por padrão, a biblioteca de tipos de nível de servidor é passada.

*wMajor*<br/>
no A versão principal da biblioteca de tipos. Por padrão, o valor é 1.

*wMinor*<br/>
no A versão secundária da biblioteca de tipos. Por padrão, o valor é 0.

*tihclass*<br/>
no A classe usada para gerenciar as informações de tipo para *T*. Por padrão, o valor é `CComTypeInfoHolder`.

## <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores públicos

|Nome|Descrição|
|----------|-----------------|
|[IDispatchImpl::IDispatchImpl](#idispatchimpl)|O construtor. Chama `AddRef` a variável de membro protegido que gerencia as informações de tipo para a interface dupla. O destruidor chama `Release`.|

### <a name="public-methods"></a>Métodos públicos

|Nome|Descrição|
|----------|-----------------|
|[IDispatchImpl::GetIDsOfNames](#getidsofnames)|Mapeia um conjunto de nomes para um conjunto correspondente de identificadores de expedição.|
|[IDispatchImpl::GetTypeInfo](#gettypeinfo)|Recupera as informações de tipo para a interface dupla.|
|[IDispatchImpl::GetTypeInfoCount](#gettypeinfocount)|Determina se há informações de tipo disponíveis para a interface dupla.|
|[IDispatchImpl::Invoke](#invoke)|Fornece acesso aos métodos e às propriedades expostas pela interface dual.|

## <a name="remarks"></a>Comentários

`IDispatchImpl`fornece uma implementação padrão para a `IDispatch` parte de qualquer interface dupla em um objeto. Uma interface dupla deriva de `IDispatch` e usa apenas tipos compatíveis com a automação. Como uma dispinterface, uma interface dupla dá suporte à ligação antecipada e à ligação tardia; no entanto, uma interface dupla também dá suporte à associação vtable.

O exemplo a seguir mostra uma implementação típica `IDispatchImpl`do.

[!code-cpp[NVC_ATL_COM#47](../../atl/codesnippet/cpp/idispatchimpl-class_1.h)]

Por padrão, a `IDispatchImpl` classe pesquisa as informações de tipo para *T* no registro. Para implementar uma interface não registrada, você pode usar `IDispatchImpl` a classe sem acessar o registro usando um número de versão predefinido. Se você criar um `IDispatchImpl` objeto que tenha 0xFFFF como o valor de *wMajor* e 0xFFFF como o valor de *wMinor*, a `IDispatchImpl` classe recuperará a biblioteca de tipos do arquivo. dll em vez do registro.

`IDispatchImpl`contém um membro estático do tipo `CComTypeInfoHolder` que gerencia as informações de tipo para a interface dupla. Se você tiver vários objetos que implementam a mesma interface dual, apenas uma instância `CComTypeInfoHolder` do será usada.

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

`T`

`IDispatchImpl`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** atlcom. h

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

Consulte [IDispatch:: GetIDsOfNames](/windows/win32/api/oaidl/nf-oaidl-idispatch-getidsofnames) na SDK do Windows.

##  <a name="gettypeinfo"></a>  IDispatchImpl::GetTypeInfo

Recupera as informações de tipo para a interface dupla.

```
STDMETHOD(GetTypeInfo)(
    UINT itinfo,
    LCID lcid,
    ITypeInfo** pptinfo);
```

### <a name="remarks"></a>Comentários

Consulte [IDispatch:: GetTypeInfo](/windows/win32/api/oaidl/nf-oaidl-idispatch-gettypeinfo) no SDK do Windows.

##  <a name="gettypeinfocount"></a>  IDispatchImpl::GetTypeInfoCount

Determina se há informações de tipo disponíveis para a interface dupla.

```
STDMETHOD(GetTypeInfoCount)(UINT* pctinfo);
```

### <a name="remarks"></a>Comentários

Consulte `IDispatch::GetTypeInfoCount` na SDK do Windows.

##  <a name="idispatchimpl"></a>  IDispatchImpl::IDispatchImpl

O construtor. Chama `AddRef` a variável de membro protegido que gerencia as informações de tipo para a interface dupla. O destruidor chama `Release`.

```
IDispatchImpl();
```

##  <a name="invoke"></a>  IDispatchImpl::Invoke

Fornece acesso aos métodos e às propriedades expostas pela interface dual.

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

Consulte [IDispatch:: Invoke](/windows/win32/api/oaidl/nf-oaidl-idispatch-invoke) no SDK do Windows.

## <a name="see-also"></a>Consulte também

[Visão geral da classe](../../atl/atl-class-overview.md)
