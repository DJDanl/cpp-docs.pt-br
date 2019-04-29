---
title: Classe IPropertyPage2Impl
ms.date: 11/04/2016
f1_keywords:
- IPropertyPage2Impl
- ATLCTL/ATL::IPropertyPage2Impl
- ATLCTL/ATL::IPropertyPage2Impl::EditProperty
helpviewer_keywords:
- property pages
- IPropertyPage2 ATL implementation
- IPropertyPage2Impl class
ms.assetid: e89fbe90-203a-47f0-a5de-23616697e1ce
ms.openlocfilehash: bf76182242f7b76e3a2c18f85b72674e88afa737
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62274763"
---
# <a name="ipropertypage2impl-class"></a>Classe IPropertyPage2Impl

Essa classe implementa `IUnknown` e herda a implementação padrão de [IPropertyPageImpl](../../atl/reference/ipropertypageimpl-class.md).

> [!IMPORTANT]
>  Essa classe e seus membros não podem ser usados em aplicativos executados no tempo de execução do Windows.

## <a name="syntax"></a>Sintaxe

```
template<class T>
class IPropertyPage2Impl : public IPropertyPageImpl<T>
```

#### <a name="parameters"></a>Parâmetros

*T*<br/>
Sua classe, derivada de `IPropertyPage2Impl`.

## <a name="members"></a>Membros

### <a name="public-methods"></a>Métodos Públicos

|Nome|Descrição|
|----------|-----------------|
|[IPropertyPage2Impl::EditProperty](#editproperty)|Especifica qual controle de propriedade receberá o foco quando a página de propriedade está ativada. A implementação de ATL retornará E_NOTIMPL.|

## <a name="remarks"></a>Comentários

O [IPropertyPage2](/windows/desktop/api/ocidl/nn-ocidl-ipropertypage2) interface estende [IPropertyPage](/windows/desktop/api/ocidl/nn-ocidl-ipropertypage) adicionando o `EditProperty` método. Esse método permite que um cliente selecionar uma propriedade específica em um objeto de página de propriedade.

Classe `IPropertyPage2Impl` simplesmente retornar E_NOTIMPL para `IPropertyPage2::EditProperty`. No entanto, ele herda a implementação padrão de [IPropertyPageImpl](../../atl/reference/ipropertypageimpl-class.md) e implementa `IUnknown` enviando informações para o despejo de compilações de dispositivo na depuração.

Quando você cria uma página de propriedades, sua classe geralmente é derivada de `IPropertyPageImpl`. Para fornecer suporte a extra `IPropertyPage2`, modifique sua definição de classe e substituir o `EditProperty` método.

**Artigos relacionados** [Tutorial da ATL](../../atl/active-template-library-atl-tutorial.md), [criando um projeto ATL](../../atl/reference/creating-an-atl-project.md)

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

`IPropertyPage`

[IPropertyPageImpl](../../atl/reference/ipropertypageimpl-class.md)

`IPropertyPage2Impl`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** atlctl.h

##  <a name="editproperty"></a>  IPropertyPage2Impl::EditProperty

Especifica qual controle de propriedade receberá o foco quando a página de propriedade está ativada.

```
HRESULT EditProperty(DISPID dispID);
```

### <a name="return-value"></a>Valor de retorno

Returns E_NOTIMPL.

### <a name="remarks"></a>Comentários

Ver [IPropertyPage2::EditProperty](/windows/desktop/api/ocidl/nf-ocidl-ipropertypage2-editproperty) no Windows SDK.

## <a name="see-also"></a>Consulte também

[Classe IPerPropertyBrowsingImpl](../../atl/reference/iperpropertybrowsingimpl-class.md)<br/>
[Classe ISpecifyPropertyPagesImpl](../../atl/reference/ispecifypropertypagesimpl-class.md)<br/>
[Visão geral da classe](../../atl/atl-class-overview.md)
