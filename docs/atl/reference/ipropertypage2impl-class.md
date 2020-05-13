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
ms.openlocfilehash: d112a2411a9debbf2eb77e6b851f4500e8d32ab8
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81329587"
---
# <a name="ipropertypage2impl-class"></a>Classe IPropertyPage2Impl

Esta classe `IUnknown` implementa e herda a implementação padrão do [IPropertyPageImpl](../../atl/reference/ipropertypageimpl-class.md).

> [!IMPORTANT]
> Esta classe e seus membros não podem ser usados em aplicativos executados no Tempo de execução do Windows.

## <a name="syntax"></a>Sintaxe

```
template<class T>
class IPropertyPage2Impl : public IPropertyPageImpl<T>
```

#### <a name="parameters"></a>Parâmetros

*T*<br/>
Sua classe, derivada de `IPropertyPage2Impl`.

## <a name="members"></a>Membros

### <a name="public-methods"></a>Métodos públicos

|Nome|Descrição|
|----------|-----------------|
|[IPropertyPage2Impl::EditProperty](#editproperty)|Especifica qual controle de propriedade receberá o foco quando a página da propriedade for ativada. A implementação da ATL retorna E_NOTIMPL.|

## <a name="remarks"></a>Comentários

A interface [IPropertyPage2](/windows/win32/api/ocidl/nn-ocidl-ipropertypage2) estende o `EditProperty` [IPropertyPage](/windows/win32/api/ocidl/nn-ocidl-ipropertypage) adicionando o método. Esse método permite que um cliente selecione uma propriedade específica em um objeto de página de propriedade.

A `IPropertyPage2Impl` classe simplesmente `IPropertyPage2::EditProperty`retorna E_NOTIMPL para . No entanto, ele herda a implementação padrão `IUnknown` do [IPropertyPageImpl](../../atl/reference/ipropertypageimpl-class.md) e implementa enviando informações para o dispositivo de despejo em compilações de depuração.

Quando você cria uma página de propriedade, `IPropertyPageImpl`sua classe é tipicamente derivada de . Para fornecer o `IPropertyPage2`suporte extra de, modifique `EditProperty` sua definição de classe e anule o método.

**Artigos relacionados** [ATL Tutorial](../../atl/active-template-library-atl-tutorial.md), Criando um Projeto [ATL](../../atl/reference/creating-an-atl-project.md)

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

`IPropertyPage`

[Ipropertypageimpl](../../atl/reference/ipropertypageimpl-class.md)

`IPropertyPage2Impl`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** atlctl.h

## <a name="ipropertypage2impleditproperty"></a><a name="editproperty"></a>IPropertyPage2Impl::EditProperty

Especifica qual controle de propriedade receberá o foco quando a página da propriedade for ativada.

```
HRESULT EditProperty(DISPID dispID);
```

### <a name="return-value"></a>Valor retornado

Volta E_NOTIMPL.

### <a name="remarks"></a>Comentários

Consulte [IPropertyPage2::EditProperty](/windows/win32/api/ocidl/nf-ocidl-ipropertypage2-editproperty) no Windows SDK.

## <a name="see-also"></a>Confira também

[Classe IPerPropertyBrowsingImpl](../../atl/reference/iperpropertybrowsingimpl-class.md)<br/>
[ISpecifiePropertyPagesImpl Class](../../atl/reference/ispecifypropertypagesimpl-class.md)<br/>
[Visão geral da classe](../../atl/atl-class-overview.md)
