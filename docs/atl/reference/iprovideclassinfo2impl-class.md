---
title: Classe IProvideClassInfo2Impl
ms.date: 11/04/2016
f1_keywords:
- IProvideClassInfo2Impl
- ATLCOM/ATL::IProvideClassInfo2Impl
- ATLCOM/ATL::IProvideClassInfo2Impl::IProvideClassInfo2Impl
- ATLCOM/ATL::IProvideClassInfo2Impl::GetClassInfo
- ATLCOM/ATL::IProvideClassInfo2Impl::GetGUID
- ATLCOM/ATL::IProvideClassInfo2Impl::_tih
helpviewer_keywords:
- IProvideClassInfo2Impl class
- IProvideClassInfo2 ATL implementation
- class information, ATL
ms.assetid: d74956e8-9c69-4cba-b99d-ca1ac031bb9d
ms.openlocfilehash: f0ff3607002d32b4e21f7fc2199cc5da3662af8b
ms.sourcegitcommit: fcb48824f9ca24b1f8bd37d647a4d592de1cc925
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/15/2019
ms.locfileid: "69495535"
---
# <a name="iprovideclassinfo2impl-class"></a>Classe IProvideClassInfo2Impl

Essa classe fornece uma implementação padrão dos métodos [IProvideClassInfo](/windows/win32/api/ocidl/nn-ocidl-iprovideclassinfo) e [IProvideClassInfo2](/windows/win32/api/ocidl/nn-ocidl-iprovideclassinfo2) .

## <a name="syntax"></a>Sintaxe

```
template <const CLSID* pcoclsid,
    const IID* psrcid,
    const GUID* plibid = &CAtlModule::m_libid,
    WORD wMajor = 1,
    WORD wMinor = 0, class tihclass = CComTypeInfoHolder>
class ATL_NO_VTABLE IProvideClassInfo2Impl : public IProvideClassInfo2
```

#### <a name="parameters"></a>Parâmetros

*pcoclsid*<br/>
Um ponteiro para o identificador da coclasse.

*psrcid*<br/>
Um ponteiro para o identificador da dispinterface de saída padrão da coclass.

*plibid*<br/>
Um ponteiro para o LIBID da biblioteca de tipos que contém informações sobre a interface. Por padrão, a biblioteca de tipos de nível de servidor é passada.

*wMajor*<br/>
A versão principal da biblioteca de tipos. O valor padrão é 1.

*wMinor*<br/>
A versão secundária da biblioteca de tipos. O valor padrão é 0.

*tihclass*<br/>
A classe usada para gerenciar as informações de tipo coclass. O valor padrão é `CComTypeInfoHolder`.

## <a name="members"></a>Membros

### <a name="constructors"></a>Construtores

|Nome|Descrição|
|----------|-----------------|
|[IProvideClassInfo2Impl::IProvideClassInfo2Impl](#iprovideclassinfo2impl)|Construtor.|

### <a name="public-methods"></a>Métodos públicos

|Nome|Descrição|
|----------|-----------------|
|[IProvideClassInfo2Impl::GetClassInfo](#getclassinfo)|Recupera um `ITypeInfo` ponteiro para as informações de tipo coclass.|
|[IProvideClassInfo2Impl::GetGUID](#getguid)|Recupera o GUID para a dispinterface de saída do objeto.|

### <a name="protected-data-members"></a>Membros de dados protegidos

|Nome|Descrição|
|----------|-----------------|
|[IProvideClassInfo2Impl::_tih](#_tih)|Gerencia as informações de tipo para a coclass.|

## <a name="remarks"></a>Comentários

A interface [IProvideClassInfo2](/windows/win32/api/ocidl/nn-ocidl-iprovideclassinfo2) estende o [IProvideClassInfo](/windows/win32/api/ocidl/nn-ocidl-iprovideclassinfo) adicionando o `GetGUID` método. Esse método permite que um cliente recupere o IID de interface de saída de um objeto para seu conjunto de eventos padrão. `IProvideClassInfo2` A `IProvideClassInfo2Impl` classeforneceumaimplementaçãopadrão`IProvideClassInfo` dos métodos e.

`IProvideClassInfo2Impl`contém um membro estático do tipo `CComTypeInfoHolder` que gerencia as informações de tipo para a coclasse.

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

`IProvideClassInfo2`

`IProvideClassInfo2Impl`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** atlcom. h

##  <a name="getclassinfo"></a>  IProvideClassInfo2Impl::GetClassInfo

Recupera um `ITypeInfo` ponteiro para as informações de tipo coclass.

```
STDMETHOD(GetClassInfo)(ITypeInfo** pptinfo);
```

### <a name="remarks"></a>Comentários

Consulte [IProvideClassInfo:: GetClassInfo](/windows/win32/api/ocidl/nf-ocidl-iprovideclassinfo-getclassinfo) na SDK do Windows.

##  <a name="getguid"></a>  IProvideClassInfo2Impl::GetGUID

Recupera o GUID para a dispinterface de saída do objeto.

```
STDMETHOD(GetGUID)(
    DWORD dwGuidKind,
    GUID* pGUID);
```

### <a name="remarks"></a>Comentários

Consulte [IProvideClassInfo2:: GetGUID](/windows/win32/api/ocidl/nf-ocidl-iprovideclassinfo2-getguid) na SDK do Windows.

##  <a name="iprovideclassinfo2impl"></a>  IProvideClassInfo2Impl::IProvideClassInfo2Impl

O construtor.

```
IProvideClassInfo2Impl();
```

### <a name="remarks"></a>Comentários

Chamadas `AddRef` no membro [_tih](#_tih) . O destruidor chama `Release`.

##  <a name="_tih"></a>  IProvideClassInfo2Impl::_tih

Esse membro de dados estáticos é uma instância do parâmetro de modelo de classe, *tihclass*, que `CComTypeInfoHolder`por padrão é.

```
static  tihclass
    _tih;
```

### <a name="remarks"></a>Comentários

`_tih`gerencia as informações de tipo para a coclass.

## <a name="see-also"></a>Consulte também

[Visão geral da classe](../../atl/atl-class-overview.md)
