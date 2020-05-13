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
ms.openlocfilehash: 0d1ee9acc1cfabc71ecf33fcb5919d826899c671
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81329566"
---
# <a name="iprovideclassinfo2impl-class"></a>Classe IProvideClassInfo2Impl

Essa classe fornece uma implementação padrão dos métodos [IProvideClassInfo](/windows/win32/api/ocidl/nn-ocidl-iprovideclassinfo) e [IProvideClassInfo2.](/windows/win32/api/ocidl/nn-ocidl-iprovideclassinfo2)

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

*pcoclídeos*<br/>
Um ponteiro para o identificador da coclasse.

*psrcid*<br/>
Um ponteiro para o identificador para a saída padrão da coclasse.

*plibid*<br/>
Um ponteiro para o LIBID da biblioteca do tipo que contém informações sobre a interface. Por padrão, a biblioteca do tipo nível do servidor é aprovada.

*wMajor*<br/>
A versão principal da biblioteca de tipos. O valor padrão é 1.

*wMenor*<br/>
A versão secundária da biblioteca de tipos. O valor padrão é 0.

*tihclass*<br/>
A classe costumava gerenciar as informações do tipo da coclasse. O valor padrão é `CComTypeInfoHolder`.

## <a name="members"></a>Membros

### <a name="constructors"></a>Construtores

|Nome|Descrição|
|----------|-----------------|
|[IProvideClassInfo2Impl::IProvideClassInfo2Impl](#iprovideclassinfo2impl)|Construtor.|

### <a name="public-methods"></a>Métodos públicos

|Nome|Descrição|
|----------|-----------------|
|[IProvideClassInfo2Impl::GetClassInfo](#getclassinfo)|Recupera um `ITypeInfo` ponteiro para as informações do tipo coclasse.|
|[IProvideClassInfo2Impl::GetGUID](#getguid)|Recupera o GUID para a saída do objeto.|

### <a name="protected-data-members"></a>Membros de Dados Protegidos

|Nome|Descrição|
|----------|-----------------|
|[IProvideClassInfo2Impl::_tih](#_tih)|Gerencia as informações do tipo para a coclasse.|

## <a name="remarks"></a>Comentários

A interface [IProvideClassInfo2](/windows/win32/api/ocidl/nn-ocidl-iprovideclassinfo2) estende [o IProvideClassInfo](/windows/win32/api/ocidl/nn-ocidl-iprovideclassinfo) adicionando o `GetGUID` método. Este método permite que um cliente recupere o IID de interface de saída de um objeto para seu conjunto de eventos padrão. A `IProvideClassInfo2Impl` classe fornece uma `IProvideClassInfo` `IProvideClassInfo2` implementação padrão dos métodos.

`IProvideClassInfo2Impl`contém um membro `CComTypeInfoHolder` estático do tipo que gerencia as informações do tipo para a coclasse.

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

`IProvideClassInfo2`

`IProvideClassInfo2Impl`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** atlcom.h

## <a name="iprovideclassinfo2implgetclassinfo"></a><a name="getclassinfo"></a>IProvideClassInfo2Impl::GetClassInfo

Recupera um `ITypeInfo` ponteiro para as informações do tipo coclasse.

```
STDMETHOD(GetClassInfo)(ITypeInfo** pptinfo);
```

### <a name="remarks"></a>Comentários

Consulte [IProvideClassInfo::GetClassInfo](/windows/win32/api/ocidl/nf-ocidl-iprovideclassinfo-getclassinfo) no Windows SDK.

## <a name="iprovideclassinfo2implgetguid"></a><a name="getguid"></a>IProvideClassInfo2Impl::GetGUID

Recupera o GUID para a saída do objeto.

```
STDMETHOD(GetGUID)(
    DWORD dwGuidKind,
    GUID* pGUID);
```

### <a name="remarks"></a>Comentários

Consulte [IProvideClassInfo2::GetGUID](/windows/win32/api/ocidl/nf-ocidl-iprovideclassinfo2-getguid) no Windows SDK.

## <a name="iprovideclassinfo2impliprovideclassinfo2impl"></a><a name="iprovideclassinfo2impl"></a>IProvideClassInfo2Impl::IProvideClassInfo2Impl

O construtor.

```
IProvideClassInfo2Impl();
```

### <a name="remarks"></a>Comentários

Chama `AddRef` o membro [_tih.](#_tih) O destruidor chama `Release`.

## <a name="iprovideclassinfo2impl_tih"></a><a name="_tih"></a>IProvideClassInfo2Impl::_tih

Este membro de dados estáticos é uma instância do parâmetro `CComTypeInfoHolder`modelo de classe, *tihclass*, que por padrão é .

```
static  tihclass
    _tih;
```

### <a name="remarks"></a>Comentários

`_tih`gerencia as informações do tipo para a coclasse.

## <a name="see-also"></a>Confira também

[Visão geral da classe](../../atl/atl-class-overview.md)
