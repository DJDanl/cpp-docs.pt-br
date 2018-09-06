---
title: Classe ISpecifyPropertyPagesImpl | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-atl
ms.topic: reference
f1_keywords:
- ISpecifyPropertyPagesImpl
- ATLCOM/ATL::ISpecifyPropertyPagesImpl
- ATLCOM/ATL::ISpecifyPropertyPagesImpl::GetPages
dev_langs:
- C++
helpviewer_keywords:
- property pages, CLSIDs associated with
- ISpecifyPropertyPages
- ISpecifyPropertyPagesImpl class
ms.assetid: 4e4b9795-b656-4d56-9b8c-85941e7731f9
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: d231f493fd2b2f2c492eec224a0ae041f175f53d
ms.sourcegitcommit: 92dbc4b9bf82fda96da80846c9cfcdba524035af
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/05/2018
ms.locfileid: "43767344"
---
# <a name="ispecifypropertypagesimpl-class"></a>Classe ISpecifyPropertyPagesImpl

Essa classe implementa `IUnknown` e fornece uma implementação padrão do [ISpecifyPropertyPages](/windows/desktop/api/ocidl/nn-ocidl-ispecifypropertypages) interface.

> [!IMPORTANT]
>  Essa classe e seus membros não podem ser usados em aplicativos executados no tempo de execução do Windows.

## <a name="syntax"></a>Sintaxe

```
template<class T>  
class ATL_NO_VTABLE ISpecifyPropertyPagesImpl 
   : public ISpecifyPropertyPages
```

#### <a name="parameters"></a>Parâmetros

*T*  
Sua classe, derivada de `ISpecifyPropertyPagesImpl`.

## <a name="members"></a>Membros

### <a name="public-methods"></a>Métodos Públicos

|Nome|Descrição|
|----------|-----------------|
|[ISpecifyPropertyPagesImpl::GetPages](#getpages)|Preenche os valores de uma matriz de contado de UUID. Cada UUID corresponde ao CLSID para uma das páginas de propriedades que podem ser exibidas na folha de propriedades do objeto.|

## <a name="remarks"></a>Comentários

O [ISpecifyPropertyPages](/windows/desktop/api/ocidl/nn-ocidl-ispecifypropertypages) interface permite que um cliente para obter uma lista de CLSIDs para as páginas de propriedades com suporte por um objeto. Classe `ISpecifyPropertyPagesImpl` fornece uma implementação padrão dessa interface e implementa `IUnknown` enviando informações para o despejo de compilações de dispositivo na depuração.

> [!NOTE]
>  Não exponha o `ISpecifyPropertyPages` se seu objeto não dá suporte a páginas de propriedades de interface.

**Artigos relacionados** [Tutorial da ATL](../../atl/active-template-library-atl-tutorial.md), [criando um projeto ATL](../../atl/reference/creating-an-atl-project.md)

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

`ISpecifyPropertyPages`

`ISpecifyPropertyPagesImpl`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** atlcom

##  <a name="getpages"></a>  ISpecifyPropertyPagesImpl::GetPages

Preenche a matriz de [CAUUID](/windows/desktop/api/ocidl/ns-ocidl-tagcauuid) estrutura com os CLSIDs para as páginas de propriedades que podem ser exibidos na folha de propriedades do objeto.

```
STDMETHOD(GetPages)(CAUUID* pPages);
```

### <a name="remarks"></a>Comentários

ATL usa o mapa de propriedade do objeto para recuperar cada CLSID.

Ver [ISpecifyPropertyPages::GetPages](/windows/desktop/api/ocidl/nf-ocidl-ispecifypropertypages-getpages) no Windows SDK.

## <a name="see-also"></a>Consulte também

[Classe IPropertyPageImpl](../../atl/reference/ipropertypageimpl-class.md)   
[Classe IPerPropertyBrowsingImpl](../../atl/reference/iperpropertybrowsingimpl-class.md)   
[Visão geral da classe](../../atl/atl-class-overview.md)
