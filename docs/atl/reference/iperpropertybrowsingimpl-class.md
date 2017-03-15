---
title: Classe IPerPropertyBrowsingImpl | Documentos do Microsoft
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: reference
f1_keywords:
- ATL.IPerPropertyBrowsingImpl
- IPerPropertyBrowsing
- ATL::IPerPropertyBrowsingImpl
- ATL::IPerPropertyBrowsingImpl<T>
- IPerPropertyBrowsingImpl
- ATL.IPerPropertyBrowsingImpl<T>
dev_langs:
- C++
helpviewer_keywords:
- IPerPropertyBrowsingImpl class
- property pages, accessing information
- IPerPropertyBrowsing, ATL implementation
ms.assetid: 0b1a9be3-d242-4767-be69-663a21e4b728
caps.latest.revision: 20
author: mikeblome
ms.author: mblome
manager: ghogen
translation.priority.ht:
- cs-cz
- de-de
- es-es
- fr-fr
- it-it
- ja-jp
- ko-kr
- pl-pl
- pt-br
- ru-ru
- tr-tr
- zh-cn
- zh-tw
translationtype: Machine Translation
ms.sourcegitcommit: 0e0c08ddc57d437c51872b5186ae3fc983bb0199
ms.openlocfilehash: 8f2c2016a83cad906be22183fcffa20ae3da3042
ms.lasthandoff: 02/25/2017

---
# <a name="iperpropertybrowsingimpl-class"></a>Classe IPerPropertyBrowsingImpl
Essa classe implementa **IUnknown** e permite que um cliente acessar as informações nas páginas de propriedades de um objeto.  
  
> [!IMPORTANT]
>  Essa classe e seus membros não podem ser usados em aplicativos que são executados a [!INCLUDE[wrt](../../atl/reference/includes/wrt_md.md)].  
  
## <a name="syntax"></a>Sintaxe  
  
```

template <class T>
class ATL_NO_VTABLE IPerPropertyBrowsingImpl :
    public IPerPropertyBrowsing
```  
  
#### <a name="parameters"></a>Parâmetros  
 `T`  
 Sua classe derivada de `IPerPropertyBrowsingImpl`.  
  
## <a name="members"></a>Membros  
  
### <a name="public-methods"></a>Métodos Públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[IPerPropertyBrowsingImpl::GetDisplayString](#getdisplaystring)|Recupera uma cadeia de caracteres que descreve uma determinada propriedade.|  
|[IPerPropertyBrowsingImpl::GetPredefinedStrings](#getpredefinedstrings)|Recupera uma matriz de cadeias de caracteres correspondentes aos valores de uma determinada propriedade pode aceitar.|  
|[IPerPropertyBrowsingImpl::GetPredefinedValue](#getpredefinedvalue)|Recupera um **VARIANT** que contém o valor de uma propriedade identificada por um determinado DISPID. O DISPID está associado com o nome de cadeia de caracteres recuperado do `GetPredefinedStrings`. Retorna a implementação de ATL **E_NOTIMPL**.|  
|[IPerPropertyBrowsingImpl::MapPropertyToPage](#mappropertytopage)|Recupera o CLSID da página de propriedades associada a uma determinada propriedade.|  
  
## <a name="remarks"></a>Comentários  
 O [IPerPropertyBrowsing](http://msdn.microsoft.com/library/windows/desktop/ms678432) interface permite que um cliente acessar as informações nas páginas de propriedades de um objeto. Classe `IPerPropertyBrowsingImpl` fornece uma implementação padrão dessa interface e implementa **IUnknown** enviando informações para o despejo de compilações de dispositivo no modo de depuração.  
  
> [!NOTE]
>  Se você estiver usando o Microsoft Access como o aplicativo de contêiner, você deve derivar a classe de `IPerPropertyBrowsingImpl`. Caso contrário, o acesso não carregará seu controle.  
  
 **Artigos relacionados** [Tutorial da ATL](../../atl/active-template-library-atl-tutorial.md), [criando um projeto do ATL](../../atl/reference/creating-an-atl-project.md)  
  
## <a name="inheritance-hierarchy"></a>Hierarquia de herança  
 `IPerPropertyBrowsing`  
  
 `IPerPropertyBrowsingImpl`  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** atlctl.h  
  
##  <a name="a-namegetdisplaystringa--iperpropertybrowsingimplgetdisplaystring"></a><a name="getdisplaystring"></a>IPerPropertyBrowsingImpl::GetDisplayString  
 Recupera uma cadeia de caracteres que descreve uma determinada propriedade.  
  
```
STDMETHOD(GetDisplayString)(
    DISPID dispID,
    BSTR* pBstr);
```  
  
### <a name="remarks"></a>Comentários  
 Consulte [IPerPropertyBrowsing::GetDisplayString](http://msdn.microsoft.com/library/windows/desktop/ms688734) no [!INCLUDE[winSDK](../../atl/includes/winsdk_md.md)].  
  
##  <a name="a-namegetpredefinedstringsa--iperpropertybrowsingimplgetpredefinedstrings"></a><a name="getpredefinedstrings"></a>IPerPropertyBrowsingImpl::GetPredefinedStrings  
 Preenche cada matriz com zero itens.  
  
```
STDMETHOD(GetPredefinedStrings)(
    DISPID dispID,
    CALPOLESTR* pCaStringsOut,
    CADWORD* pCaCookiesOut);
```  
  
### <a name="return-value"></a>Valor de retorno  
 Implementação do ATL [GetPredefinedValue](#getpredefinedvalue) retorna **E_NOTIMPL**.  
  
### <a name="remarks"></a>Comentários  
 Consulte [IPerPropertyBrowsing: GetPredefinedStrings](http://msdn.microsoft.com/library/windows/desktop/ms679724) no [!INCLUDE[winSDK](../../atl/includes/winsdk_md.md)].  
  
##  <a name="a-namegetpredefinedvaluea--iperpropertybrowsingimplgetpredefinedvalue"></a><a name="getpredefinedvalue"></a>IPerPropertyBrowsingImpl::GetPredefinedValue  
 Recupera um **VARIANT** que contém o valor de uma propriedade identificada por um determinado DISPID. O DISPID está associado com o nome de cadeia de caracteres recuperado do `GetPredefinedStrings`.  
  
```
STDMETHOD(GetPredefinedValue)(
    DISPID dispID,
    DWORD dwCookie,
    VARIANT* pVarOut);
```  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna **E_NOTIMPL**.  
  
### <a name="remarks"></a>Comentários  
 Implementação do ATL [GetPredefinedStrings](#getpredefinedstrings) recupera cadeias de caracteres não correspondentes.  
  
 Consulte [IPerPropertyBrowsing::GetPredefinedValue](http://msdn.microsoft.com/library/windows/desktop/ms690401) no [!INCLUDE[winSDK](../../atl/includes/winsdk_md.md)].  
  
##  <a name="a-namemappropertytopagea--iperpropertybrowsingimplmappropertytopage"></a><a name="mappropertytopage"></a>IPerPropertyBrowsingImpl::MapPropertyToPage  
 Recupera o CLSID da página de propriedades associada com a propriedade especificada.  
  
```
STDMETHOD(MapPropertyToPage)(
    DISPID dispID,
    CLSID* pClsid);
```  
  
### <a name="remarks"></a>Comentários  
 ATL usa mapa de propriedade do objeto para obter essas informações.  
  
 Consulte [IPerPropertyBrowsing::MapPropertyToPage](http://msdn.microsoft.com/library/windows/desktop/ms694476) no [!INCLUDE[winSDK](../../atl/includes/winsdk_md.md)].  
  
## <a name="see-also"></a>Consulte também  
 [Classe IPropertyPageImpl](../../atl/reference/ipropertypageimpl-class.md)   
 [Classe ISpecifyPropertyPagesImpl](../../atl/reference/ispecifypropertypagesimpl-class.md)   
 [Visão geral da classe](../../atl/atl-class-overview.md)

