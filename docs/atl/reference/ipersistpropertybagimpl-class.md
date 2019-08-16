---
title: Classe IPersistPropertyBagImpl
ms.date: 11/04/2016
f1_keywords:
- IPersistPropertyBagImpl
- ATLCOM/ATL::IPersistPropertyBagImpl
- ATLCOM/ATL::IPersistPropertyBagImpl::GetClassID
- ATLCOM/ATL::IPersistPropertyBagImpl::InitNew
- ATLCOM/ATL::IPersistPropertyBagImpl::Load
- ATLCOM/ATL::IPersistPropertyBagImpl::Save
helpviewer_keywords:
- IPersistPropertyBagImpl class
ms.assetid: 712af24d-99f8-40f2-9811-53b3ff6e5b19
ms.openlocfilehash: 15b9c9738d921c4c6f7837f9280c6dd6b09392d6
ms.sourcegitcommit: fcb48824f9ca24b1f8bd37d647a4d592de1cc925
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/15/2019
ms.locfileid: "69495771"
---
# <a name="ipersistpropertybagimpl-class"></a>Classe IPersistPropertyBagImpl

Essa classe implementa `IUnknown` e permite que um objeto salve suas propriedades em um recipiente de propriedades fornecido pelo cliente.

> [!IMPORTANT]
>  Essa classe e seus membros não podem ser usados em aplicativos que são executados no Windows Runtime.

## <a name="syntax"></a>Sintaxe

```
template <class T>
class ATL_NO_VTABLE IPersistPropertyBagImpl : public IPersistPropertyBag
```

#### <a name="parameters"></a>Parâmetros

*T*<br/>
Sua classe, derivada de `IPersistPropertyBagImpl`.

## <a name="members"></a>Membros

### <a name="public-methods"></a>Métodos Públicos

|Nome|Descrição|
|----------|-----------------|
|[IPersistPropertyBagImpl::GetClassID](#getclassid)|Recupera o CLSID do objeto.|
|[IPersistPropertyBagImpl::InitNew](#initnew)|Inicializa um objeto recém-criado. A implementação da ATL retorna S_OK.|
|[IPersistPropertyBagImpl::Load](#load)|Carrega as propriedades do objeto de um recipiente de propriedades fornecido pelo cliente.|
|[IPersistPropertyBagImpl::Save](#save)|Salva as propriedades do objeto em um recipiente de propriedades fornecido pelo cliente.|

## <a name="remarks"></a>Comentários

A interface [IPersistPropertyBag](/previous-versions/windows/internet-explorer/ie-developer/platform-apis/aa768205\(v=vs.85\)) permite que um objeto salve suas propriedades em um recipiente de propriedades fornecido pelo cliente. Fornece uma implementação padrão dessa interface e implementa `IUnknown` enviando informações para o dispositivo de despejo em compilações de depuração. `IPersistPropertyBagImpl`

`IPersistPropertyBag`funciona em conjunto com [IPropertyBag](/previous-versions/windows/internet-explorer/ie-developer/platform-apis/aa768196\(v=vs.85\)) e [IErrorLog](/previous-versions/windows/internet-explorer/ie-developer/platform-apis/aa768231\(v=vs.85\)). Essas duas últimas interfaces devem ser implementadas pelo cliente. Por `IPropertyBag`meio do, o cliente salva e carrega as propriedades individuais do objeto. Por `IErrorLog`meio do, o objeto e o cliente podem relatar quaisquer erros encontrados.

**Artigos relacionados** [Tutorial do ATL](../../atl/active-template-library-atl-tutorial.md), [criando um projeto ATL](../../atl/reference/creating-an-atl-project.md)

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

`IPersistPropertyBag`

`IPersistPropertyBagImpl`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** atlcom. h

##  <a name="getclassid"></a>  IPersistPropertyBagImpl::GetClassID

Recupera o CLSID do objeto.

```
STDMETHOD(GetClassID)(CLSID* pClassID);
```

### <a name="remarks"></a>Comentários

Consulte [IPersist:: GetClassID](/windows/win32/api/objidl/nf-objidl-ipersist-getclassid) na SDK do Windows.

##  <a name="initnew"></a>  IPersistPropertyBagImpl::InitNew

Inicializa um objeto recém-criado.

```
STDMETHOD(InitNew)();
```

### <a name="return-value"></a>Valor de retorno

Retorna S_OK.

### <a name="remarks"></a>Comentários

Consulte [IPersistPropertyBag:: InitNew](/previous-versions/windows/internet-explorer/ie-developer/platform-apis/aa768204\(v=vs.85\)) na SDK do Windows.

##  <a name="load"></a>  IPersistPropertyBagImpl::Load

Carrega as propriedades do objeto de um recipiente de propriedades fornecido pelo cliente.

```
STDMETHOD(Load)(LPPROPERTYBAG pPropBag, LPERRORLOG pErrorLog);
```

### <a name="remarks"></a>Comentários

A ATL usa o mapa de propriedades do objeto para recuperar essas informações.

Consulte [IPersistPropertyBag:: Load](/previous-versions/windows/internet-explorer/ie-developer/platform-apis/aa768206\(v=vs.85\)) no SDK do Windows.

##  <a name="save"></a>  IPersistPropertyBagImpl::Save

Salva as propriedades do objeto em um recipiente de propriedades fornecido pelo cliente.

```
STDMETHOD(Save)(
    LPPROPERTYBAG pPropBag,
    BOOL fClearDirty,
    BOOL fSaveAllProperties);
```

### <a name="remarks"></a>Comentários

A ATL usa o mapa de propriedades do objeto para armazenar essas informações. Por padrão, esse método salva todas as propriedades, independentemente do valor de *fSaveAllProperties*.

Consulte [IPersistPropertyBag:: Save](/previous-versions/windows/internet-explorer/ie-developer/platform-apis/aa768207\(v=vs.85\)) no SDK do Windows.

## <a name="see-also"></a>Consulte também

[BEGIN_PROP_MAP](property-map-macros.md#begin_prop_map)<br/>
[Visão geral da classe](../../atl/atl-class-overview.md)
