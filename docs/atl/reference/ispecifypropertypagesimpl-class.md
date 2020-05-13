---
title: ISpecifiePropertyPagesImpl Class
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
ms.openlocfilehash: 06b6b60227a659bd35e042952c7464971fc40bdc
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81326407"
---
# <a name="ispecifypropertypagesimpl-class"></a>ISpecifiePropertyPagesImpl Class

Essa classe `IUnknown` implementa e fornece uma implementação padrão da interface [ISpecifiePropertyPages.](/windows/win32/api/ocidl/nn-ocidl-ispecifypropertypages)

> [!IMPORTANT]
> Esta classe e seus membros não podem ser usados em aplicativos executados no Tempo de execução do Windows.

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

### <a name="public-methods"></a>Métodos públicos

|Nome|Descrição|
|----------|-----------------|
|[ISpecifiePropertyPagesImpl::GetPages](#getpages)|Preenche uma matriz contada de valores UUID. Cada UUID corresponde ao CLSID para uma das páginas de propriedade que podem ser exibidas na folha de propriedade do objeto.|

## <a name="remarks"></a>Comentários

A interface [ISpecifiePropertyPages](/windows/win32/api/ocidl/nn-ocidl-ispecifypropertypages) permite que um cliente obtenha uma lista de CLSIDs para as páginas de propriedade suportadas por um objeto. A `ISpecifyPropertyPagesImpl` classe fornece uma implementação `IUnknown` padrão dessa interface e implementa enviando informações para o dispositivo de despejo em compilações de depuração.

> [!NOTE]
> Não exponha `ISpecifyPropertyPages` a interface se o objeto não suportar páginas de propriedade.

**Artigos relacionados** [ATL Tutorial](../../atl/active-template-library-atl-tutorial.md), Criando um Projeto [ATL](../../atl/reference/creating-an-atl-project.md)

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

`ISpecifyPropertyPages`

`ISpecifyPropertyPagesImpl`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** atlcom.h

## <a name="ispecifypropertypagesimplgetpages"></a><a name="getpages"></a>ISpecifiePropertyPagesImpl::GetPages

Preenche a matriz na estrutura [CAUUID](/windows/win32/api/ocidl/ns-ocidl-cauuid) com os CLSIDs para as páginas de propriedade que podem ser exibidas na folha de propriedade do objeto.

```
STDMETHOD(GetPages)(CAUUID* pPages);
```

### <a name="remarks"></a>Comentários

O ATL usa o mapa de propriedade do objeto para recuperar cada CLSID.

Consulte [ISpecifiePropertyPages::GetPages](/windows/win32/api/ocidl/nf-ocidl-ispecifypropertypages-getpages) in the Windows SDK.

## <a name="see-also"></a>Confira também

[Classe IPropertyPageImpl](../../atl/reference/ipropertypageimpl-class.md)<br/>
[Classe IPerPropertyBrowsingImpl](../../atl/reference/iperpropertybrowsingimpl-class.md)<br/>
[Visão geral da classe](../../atl/atl-class-overview.md)
