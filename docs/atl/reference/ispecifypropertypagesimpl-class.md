---
title: Classe ISpecifyPropertyPagesImpl
ms.date: 11/04/2016
f1_keywords:
- ISpecifyPropertyPagesImpl
- ATLCOM/ATL::ISpecifyPropertyPagesImpl
- ATLCOM/ATL::ISpecifyPropertyPagesImpl::GetPages
helpviewer_keywords:
- property pages, CLSIDs associated with
- ISpecifyPropertyPages
- ISpecifyPropertyPagesImpl class
ms.assetid: 4e4b9795-b656-4d56-9b8c-85941e7731f9
ms.openlocfilehash: c201cf6d9d89ab1a6a8e888deee1be79e5770490
ms.sourcegitcommit: fcb48824f9ca24b1f8bd37d647a4d592de1cc925
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/15/2019
ms.locfileid: "69495405"
---
# <a name="ispecifypropertypagesimpl-class"></a>Classe ISpecifyPropertyPagesImpl

Essa classe implementa `IUnknown` e fornece uma implementação padrão da interface [ISpecifyPropertyPages](/windows/win32/api/ocidl/nn-ocidl-ispecifypropertypages) .

> [!IMPORTANT]
>  Essa classe e seus membros não podem ser usados em aplicativos que são executados no Windows Runtime.

## <a name="syntax"></a>Sintaxe

```
template<class T>
class ATL_NO_VTABLE ISpecifyPropertyPagesImpl
   : public ISpecifyPropertyPages
```

#### <a name="parameters"></a>Parâmetros

*T*<br/>
Sua classe, derivada de `ISpecifyPropertyPagesImpl`.

## <a name="members"></a>Membros

### <a name="public-methods"></a>Métodos Públicos

|Nome|Descrição|
|----------|-----------------|
|[ISpecifyPropertyPagesImpl:: GetPages](#getpages)|Preenche uma matriz contada de valores UUID. Cada UUID corresponde ao CLSID para uma das páginas de propriedades que podem ser exibidas na folha de propriedades do objeto.|

## <a name="remarks"></a>Comentários

A interface [ISpecifyPropertyPages](/windows/win32/api/ocidl/nn-ocidl-ispecifypropertypages) permite que um cliente obtenha uma lista de CLSIDs para as páginas de propriedades com suporte de um objeto. Fornece uma implementação padrão dessa interface e implementa `IUnknown` enviando informações para o dispositivo de despejo em compilações de depuração. `ISpecifyPropertyPagesImpl`

> [!NOTE]
>  Não expor a interface `ISpecifyPropertyPages` se seu objeto não oferecer suporte a páginas de propriedades.

**Artigos relacionados** [Tutorial do ATL](../../atl/active-template-library-atl-tutorial.md), [criando um projeto ATL](../../atl/reference/creating-an-atl-project.md)

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

`ISpecifyPropertyPages`

`ISpecifyPropertyPagesImpl`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** atlcom. h

##  <a name="getpages"></a>ISpecifyPropertyPagesImpl:: GetPages

Preenche a matriz na estrutura [CAUUID](/windows/win32/api/ocidl/ns-ocidl-cauuid) com os CLSIDs para as páginas de propriedades que podem ser exibidas na folha de propriedades do objeto.

```
STDMETHOD(GetPages)(CAUUID* pPages);
```

### <a name="remarks"></a>Comentários

A ATL usa o mapa de propriedades do objeto para recuperar cada CLSID.

Consulte [ISpecifyPropertyPages::](/windows/win32/api/ocidl/nf-ocidl-ispecifypropertypages-getpages) GetPages no SDK do Windows.

## <a name="see-also"></a>Consulte também

[Classe IPropertyPageImpl](../../atl/reference/ipropertypageimpl-class.md)<br/>
[Classe IPerPropertyBrowsingImpl](../../atl/reference/iperpropertybrowsingimpl-class.md)<br/>
[Visão geral da classe](../../atl/atl-class-overview.md)
