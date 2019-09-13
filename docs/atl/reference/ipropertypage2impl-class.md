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
ms.openlocfilehash: 5ec6cb2f4fc6931a1bec429068b558bf7ac1906e
ms.sourcegitcommit: fcb48824f9ca24b1f8bd37d647a4d592de1cc925
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/15/2019
ms.locfileid: "69495601"
---
# <a name="ipropertypage2impl-class"></a>Classe IPropertyPage2Impl

Essa classe implementa `IUnknown` e herda a implementação padrão de [IPropertyPageImpl](../../atl/reference/ipropertypageimpl-class.md).

> [!IMPORTANT]
>  Essa classe e seus membros não podem ser usados em aplicativos que são executados no Windows Runtime.

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
|[IPropertyPage2Impl::EditProperty](#editproperty)|Especifica qual controle de propriedade receberá o foco quando a página de Propriedades for ativada. A implementação da ATL retorna E_NOTIMPL.|

## <a name="remarks"></a>Comentários

A interface [IPropertyPage2](/windows/win32/api/ocidl/nn-ocidl-ipropertypage2) estende o [IPropertyPage](/windows/win32/api/ocidl/nn-ocidl-ipropertypage) adicionando o `EditProperty` método. Esse método permite que um cliente selecione uma propriedade específica em um objeto de página de propriedades.

A `IPropertyPage2Impl` classe simplesmente retorna E_NOTIMPL `IPropertyPage2::EditProperty`para. No entanto, ele herda a implementação padrão de [IPropertyPageImpl](../../atl/reference/ipropertypageimpl-class.md) e implementa `IUnknown` enviando informações para o dispositivo de despejo em compilações de depuração.

Quando você cria uma página de propriedades, sua classe normalmente é derivada `IPropertyPageImpl`de. Para fornecer o suporte extra do `IPropertyPage2`, modifique a definição de classe e substitua `EditProperty` o método.

**Artigos relacionados** [Tutorial do ATL](../../atl/active-template-library-atl-tutorial.md), [criando um projeto ATL](../../atl/reference/creating-an-atl-project.md)

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

`IPropertyPage`

[IPropertyPageImpl](../../atl/reference/ipropertypageimpl-class.md)

`IPropertyPage2Impl`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** atlctl. h

##  <a name="editproperty"></a>IPropertyPage2Impl:: EditProperty

Especifica qual controle de propriedade receberá o foco quando a página de Propriedades for ativada.

```
HRESULT EditProperty(DISPID dispID);
```

### <a name="return-value"></a>Valor de retorno

Retorna E_NOTIMPL.

### <a name="remarks"></a>Comentários

Consulte [IPropertyPage2:: EditProperty](/windows/win32/api/ocidl/nf-ocidl-ipropertypage2-editproperty) no SDK do Windows.

## <a name="see-also"></a>Consulte também

[Classe IPerPropertyBrowsingImpl](../../atl/reference/iperpropertybrowsingimpl-class.md)<br/>
[Classe ISpecifyPropertyPagesImpl](../../atl/reference/ispecifypropertypagesimpl-class.md)<br/>
[Visão geral da classe](../../atl/atl-class-overview.md)
