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
ms.openlocfilehash: f656ecc76b175eae523059c60bb8a3efc6f0b312
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81326480"
---
# <a name="ipersistpropertybagimpl-class"></a>Classe IPersistPropertyBagImpl

Esta classe `IUnknown` implementa e permite que um objeto salve suas propriedades em um saco de propriedade fornecido pelo cliente.

> [!IMPORTANT]
> Esta classe e seus membros não podem ser usados em aplicativos executados no Tempo de execução do Windows.

## <a name="syntax"></a>Sintaxe

```
template <class T>
class ATL_NO_VTABLE IPersistPropertyBagImpl : public IPersistPropertyBag
```

#### <a name="parameters"></a>Parâmetros

*T*<br/>
Sua classe, derivada de `IPersistPropertyBagImpl`.

## <a name="members"></a>Membros

### <a name="public-methods"></a>Métodos públicos

|Nome|Descrição|
|----------|-----------------|
|[IPersistPropertyBagImpl::GetClassID](#getclassid)|Recupera o CLSID do objeto.|
|[IPersistPropertyBagImpl::InitNew](#initnew)|Inicializa um objeto recém-criado. A implementação da ATL retorna S_OK.|
|[IPersistPropertyBagImpl::Load](#load)|Carrega as propriedades do objeto a partir de um saco de propriedade fornecido pelo cliente.|
|[IPersistPropertyBagImpl::Salvar](#save)|Salva as propriedades do objeto em um saco de propriedade fornecido pelo cliente.|

## <a name="remarks"></a>Comentários

A interface [IPersistPropertyBag](/previous-versions/windows/internet-explorer/ie-developer/platform-apis/aa768205\(v=vs.85\)) permite que um objeto salve suas propriedades em uma bolsa de propriedade fornecida pelo cliente. A `IPersistPropertyBagImpl` classe fornece uma implementação `IUnknown` padrão dessa interface e implementa enviando informações para o dispositivo de despejo em compilações de depuração.

`IPersistPropertyBag`funciona em conjunto com [iPropertyBag](/previous-versions/windows/internet-explorer/ie-developer/platform-apis/aa768196\(v=vs.85\)) e [IErrorLog](/previous-versions/windows/internet-explorer/ie-developer/platform-apis/aa768231\(v=vs.85\)). Essas duas últimas interfaces devem ser implementadas pelo cliente. Através `IPropertyBag`de , o cliente salva e carrega as propriedades individuais do objeto. Através `IErrorLog`de , tanto o objeto quanto o cliente podem relatar quaisquer erros encontrados.

**Artigos relacionados** [ATL Tutorial](../../atl/active-template-library-atl-tutorial.md), Criando um Projeto [ATL](../../atl/reference/creating-an-atl-project.md)

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

`IPersistPropertyBag`

`IPersistPropertyBagImpl`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** atlcom.h

## <a name="ipersistpropertybagimplgetclassid"></a><a name="getclassid"></a>IPersistPropertyBagImpl::GetClassID

Recupera o CLSID do objeto.

```
STDMETHOD(GetClassID)(CLSID* pClassID);
```

### <a name="remarks"></a>Comentários

Consulte [IPersist::GetClassID](/windows/win32/api/objidl/nf-objidl-ipersist-getclassid) no Windows SDK.

## <a name="ipersistpropertybagimplinitnew"></a><a name="initnew"></a>IPersistPropertyBagImpl::InitNew

Inicializa um objeto recém-criado.

```
STDMETHOD(InitNew)();
```

### <a name="return-value"></a>Valor retornado

Retorna S_OK.

### <a name="remarks"></a>Comentários

Consulte [iPersistPropertyBag::InitNew](/previous-versions/windows/internet-explorer/ie-developer/platform-apis/aa768204\(v=vs.85\)) no Windows SDK.

## <a name="ipersistpropertybagimplload"></a><a name="load"></a>IPersistPropertyBagImpl::Load

Carrega as propriedades do objeto a partir de um saco de propriedade fornecido pelo cliente.

```
STDMETHOD(Load)(LPPROPERTYBAG pPropBag, LPERRORLOG pErrorLog);
```

### <a name="remarks"></a>Comentários

O ATL usa o mapa de propriedade do objeto para recuperar essas informações.

Consulte [iPersistPropertyBag::Load](/previous-versions/windows/internet-explorer/ie-developer/platform-apis/aa768206\(v=vs.85\)) in the Windows SDK.

## <a name="ipersistpropertybagimplsave"></a><a name="save"></a>IPersistPropertyBagImpl::Salvar

Salva as propriedades do objeto em um saco de propriedade fornecido pelo cliente.

```
STDMETHOD(Save)(
    LPPROPERTYBAG pPropBag,
    BOOL fClearDirty,
    BOOL fSaveAllProperties);
```

### <a name="remarks"></a>Comentários

A ATL usa o mapa de propriedade do objeto para armazenar essas informações. Por padrão, este método salva todas as propriedades, independentemente do valor de *fSaveAllProperties*.

Consulte [iPersistPropertyBag::Salvar](/previous-versions/windows/internet-explorer/ie-developer/platform-apis/aa768207\(v=vs.85\)) no SDK do Windows.

## <a name="see-also"></a>Confira também

[Begin_prop_map](property-map-macros.md#begin_prop_map)<br/>
[Visão geral da classe](../../atl/atl-class-overview.md)
