---
title: Classe IPropertyPage2Impl | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-atl
ms.topic: reference
f1_keywords:
- IPropertyPage2Impl
- ATLCTL/ATL::IPropertyPage2Impl
- ATLCTL/ATL::IPropertyPage2Impl::EditProperty
dev_langs:
- C++
helpviewer_keywords:
- property pages
- IPropertyPage2 ATL implementation
- IPropertyPage2Impl class
ms.assetid: e89fbe90-203a-47f0-a5de-23616697e1ce
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 204f62e667bd149dd174f960ba31d8388e01394e
ms.sourcegitcommit: be2a7679c2bd80968204dee03d13ca961eaa31ff
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/03/2018
---
# <a name="ipropertypage2impl-class"></a>Classe IPropertyPage2Impl
Essa classe implementa **IUnknown** e herda a implementação padrão de [IPropertyPageImpl](../../atl/reference/ipropertypageimpl-class.md).  
  
> [!IMPORTANT]
>  Essa classe e seus membros não podem ser usados em aplicativos que são executados o tempo de execução do Windows.  
  
## <a name="syntax"></a>Sintaxe  
  
```
template<class T>  
class IPropertyPage2Impl : public IPropertyPageImpl<T>
```  
  
#### <a name="parameters"></a>Parâmetros  
 `T`  
 A classe derivada de `IPropertyPage2Impl`.  
  
## <a name="members"></a>Membros  
  
### <a name="public-methods"></a>Métodos Públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[IPropertyPage2Impl::EditProperty](#editproperty)|Especifica qual controle propriedade receberá o foco quando a página de propriedades é ativada. Retorna a implementação de ATL **E_NOTIMPL**.|  
  
## <a name="remarks"></a>Comentários  
 O [IPropertyPage2](http://msdn.microsoft.com/library/windows/desktop/ms683996) estende a interface [IPropertyPage](http://msdn.microsoft.com/library/windows/desktop/ms691246) adicionando o `EditProperty` método. Esse método permite que um cliente selecionar uma propriedade específica em um objeto de página de propriedade.  
  
 Classe `IPropertyPage2Impl` simplesmente retorna **E_NOTIMPL** para **IPropertyPage2::EditProperty**. No entanto, ele herda a implementação padrão de [IPropertyPageImpl](../../atl/reference/ipropertypageimpl-class.md) e implementa **IUnknown** enviando informações para o despejo compilações dispositivo na depuração.  
  
 Quando você cria uma página de propriedades, sua classe geralmente é derivada de `IPropertyPageImpl`. Para fornecer suporte adicional do **IPropertyPage2**, modifique sua definição de classe e substituir o `EditProperty` método.  
  
 **Artigos relacionados** [Tutorial da ATL](../../atl/active-template-library-atl-tutorial.md), [criando um projeto ATL](../../atl/reference/creating-an-atl-project.md)  
  
## <a name="inheritance-hierarchy"></a>Hierarquia de herança  
 `IPropertyPage`  
  
 [IPropertyPageImpl](../../atl/reference/ipropertypageimpl-class.md)  
  
 `IPropertyPage2Impl`  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** atlctl.h  
  
##  <a name="editproperty"></a>  IPropertyPage2Impl::EditProperty  
 Especifica qual controle propriedade receberá o foco quando a página de propriedades é ativada.  
  
```
HRESULT EditProperty(DISPID dispID);
```  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna **E_NOTIMPL**.  
  
### <a name="remarks"></a>Comentários  
 Consulte [IPropertyPage2::EditProperty](http://msdn.microsoft.com/library/windows/desktop/ms690353) no SDK do Windows.  
  
## <a name="see-also"></a>Consulte também  
 [Classe IPerPropertyBrowsingImpl](../../atl/reference/iperpropertybrowsingimpl-class.md)   
 [Classe ISpecifyPropertyPagesImpl](../../atl/reference/ispecifypropertypagesimpl-class.md)   
 [Visão geral da classe](../../atl/atl-class-overview.md)
