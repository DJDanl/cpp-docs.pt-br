---
title: Classe ISpecifyPropertyPagesImpl | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-windows
ms.tgt_pltfrm: 
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
caps.latest.revision: 
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: 716e3ba5d48d39cd189da8d92cca694f09508e42
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="ispecifypropertypagesimpl-class"></a>Classe ISpecifyPropertyPagesImpl
Essa classe implementa **IUnknown** e fornece uma implementação padrão de [ISpecifyPropertyPages](http://msdn.microsoft.com/library/windows/desktop/ms695217) interface.  
  
> [!IMPORTANT]
>  Essa classe e seus membros não podem ser usados em aplicativos que são executados o tempo de execução do Windows.  
  
## <a name="syntax"></a>Sintaxe  
  
```
template<class T>  
class ATL_NO_VTABLE ISpecifyPropertyPagesImpl 
   : public ISpecifyPropertyPages
```  
  
#### <a name="parameters"></a>Parâmetros  
 `T`  
 A classe derivada de `ISpecifyPropertyPagesImpl`.  
  
## <a name="members"></a>Membros  
  
### <a name="public-methods"></a>Métodos Públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[ISpecifyPropertyPagesImpl::GetPages](#getpages)|Preenche os valores de uma matriz de contado de UUID. Cada UUID corresponde ao CLSID para uma das páginas de propriedades que podem ser exibidas na folha de propriedades do objeto.|  
  
## <a name="remarks"></a>Comentários  
 O [ISpecifyPropertyPages](http://msdn.microsoft.com/library/windows/desktop/ms695217) interface permite que um cliente obter uma lista de CLSIDs para as páginas de propriedades com suporte por um objeto. Classe `ISpecifyPropertyPagesImpl` fornece uma implementação padrão dessa interface e implementa **IUnknown** enviando informações para o despejo compilações dispositivo na depuração.  
  
> [!NOTE]
>  Não exponha o **ISpecifyPropertyPages** se o objeto não oferece suporte a páginas de propriedade de interface.  
  
 **Artigos relacionados** [Tutorial da ATL](../../atl/active-template-library-atl-tutorial.md), [criando um projeto ATL](../../atl/reference/creating-an-atl-project.md)  
  
## <a name="inheritance-hierarchy"></a>Hierarquia de herança  
 `ISpecifyPropertyPages`  
  
 `ISpecifyPropertyPagesImpl`  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** atlcom.h  
  
##  <a name="getpages"></a>ISpecifyPropertyPagesImpl::GetPages  
 Preencha a matriz de [CAUUID](http://msdn.microsoft.com/library/windows/desktop/ms680048) estrutura com os CLSIDs para as páginas de propriedades que podem ser exibidas na folha de propriedades do objeto.  
  
```
STDMETHOD(GetPages)(CAUUID* pPages);
```  
  
### <a name="remarks"></a>Comentários  
 ATL usa mapa de propriedade do objeto para recuperar cada CLSID.  
  
 Consulte [ISpecifyPropertyPages::GetPages](http://msdn.microsoft.com/library/windows/desktop/ms687276) no SDK do Windows.  
  
## <a name="see-also"></a>Consulte também  
 [Classe IPropertyPageImpl](../../atl/reference/ipropertypageimpl-class.md)   
 [Classe IPerPropertyBrowsingImpl](../../atl/reference/iperpropertybrowsingimpl-class.md)   
 [Visão geral da classe](../../atl/atl-class-overview.md)
