---
title: Classe IPerPropertyBrowsingImpl | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-windows
ms.tgt_pltfrm: 
ms.topic: reference
f1_keywords:
- IPerPropertyBrowsingImpl
- ATLCTL/ATL::IPerPropertyBrowsingImpl
- ATLCTL/ATL::IPerPropertyBrowsingImpl::GetDisplayString
- ATLCTL/ATL::IPerPropertyBrowsingImpl::GetPredefinedStrings
- ATLCTL/ATL::IPerPropertyBrowsingImpl::GetPredefinedValue
- ATLCTL/ATL::IPerPropertyBrowsingImpl::MapPropertyToPage
dev_langs:
- C++
helpviewer_keywords:
- IPerPropertyBrowsingImpl class
- property pages, accessing information
- IPerPropertyBrowsing, ATL implementation
ms.assetid: 0b1a9be3-d242-4767-be69-663a21e4b728
caps.latest.revision: 
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: dca0c4e519703408af1ca5b6834e4b311c70bd21
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="iperpropertybrowsingimpl-class"></a>Classe IPerPropertyBrowsingImpl
Essa classe implementa **IUnknown** e permite que um cliente acessar as informações nas páginas de propriedades de um objeto.  
  
> [!IMPORTANT]
>  Essa classe e seus membros não podem ser usados em aplicativos que são executados o tempo de execução do Windows.  
  
## <a name="syntax"></a>Sintaxe  
  
```

template <class T>
class ATL_NO_VTABLE IPerPropertyBrowsingImpl :
    public IPerPropertyBrowsing
```  
  
#### <a name="parameters"></a>Parâmetros  
 `T`  
 A classe derivada de `IPerPropertyBrowsingImpl`.  
  
## <a name="members"></a>Membros  
  
### <a name="public-methods"></a>Métodos Públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[IPerPropertyBrowsingImpl::GetDisplayString](#getdisplaystring)|Recupera uma cadeia de caracteres que descreve uma determinada propriedade.|  
|[IPerPropertyBrowsingImpl::GetPredefinedStrings](#getpredefinedstrings)|Recupera uma matriz de cadeias de caracteres correspondentes aos valores de uma determinada propriedade pode aceitar.|  
|[IPerPropertyBrowsingImpl::GetPredefinedValue](#getpredefinedvalue)|Recupera um **VARIANT** que contém o valor de uma propriedade identificada por um DISPID determinado. O DISPID está associado com o nome de cadeia de caracteres recuperado do `GetPredefinedStrings`. Retorna a implementação de ATL **E_NOTIMPL**.|  
|[IPerPropertyBrowsingImpl::MapPropertyToPage](#mappropertytopage)|Recupera o CLSID da página de propriedades associada a uma determinada propriedade.|  
  
## <a name="remarks"></a>Comentários  
 O [IPerPropertyBrowsing](http://msdn.microsoft.com/library/windows/desktop/ms678432) interface permite que um cliente acessar as informações nas páginas de propriedades de um objeto. Classe `IPerPropertyBrowsingImpl` fornece uma implementação padrão dessa interface e implementa **IUnknown** enviando informações para o despejo compilações dispositivo na depuração.  
  
> [!NOTE]
>  Se você estiver usando o Microsoft Access como o aplicativo de contêiner, você deve derivar a classe de `IPerPropertyBrowsingImpl`. Caso contrário, o acesso não carregará o controle.  
  
 **Artigos relacionados** [Tutorial da ATL](../../atl/active-template-library-atl-tutorial.md), [criando um projeto ATL](../../atl/reference/creating-an-atl-project.md)  
  
## <a name="inheritance-hierarchy"></a>Hierarquia de herança  
 `IPerPropertyBrowsing`  
  
 `IPerPropertyBrowsingImpl`  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** atlctl.h  
  
##  <a name="getdisplaystring"></a>IPerPropertyBrowsingImpl::GetDisplayString  
 Recupera uma cadeia de caracteres que descreve uma determinada propriedade.  
  
```
STDMETHOD(GetDisplayString)(
    DISPID dispID,
    BSTR* pBstr);
```  
  
### <a name="remarks"></a>Comentários  
 Consulte [IPerPropertyBrowsing::GetDisplayString](http://msdn.microsoft.com/library/windows/desktop/ms688734) no SDK do Windows.  
  
##  <a name="getpredefinedstrings"></a>IPerPropertyBrowsingImpl::GetPredefinedStrings  
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
 Consulte [IPerPropertyBrowsing: GetPredefinedStrings](http://msdn.microsoft.com/library/windows/desktop/ms679724) no SDK do Windows.  
  
##  <a name="getpredefinedvalue"></a>IPerPropertyBrowsingImpl::GetPredefinedValue  
 Recupera um **VARIANT** que contém o valor de uma propriedade identificada por um DISPID determinado. O DISPID está associado com o nome de cadeia de caracteres recuperado do `GetPredefinedStrings`.  
  
```
STDMETHOD(GetPredefinedValue)(
    DISPID dispID,
    DWORD dwCookie,
    VARIANT* pVarOut);
```  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna **E_NOTIMPL**.  
  
### <a name="remarks"></a>Comentários  
 Implementação do ATL [GetPredefinedStrings](#getpredefinedstrings) não recupera nenhuma cadeia de caracteres correspondente.  
  
 Consulte [IPerPropertyBrowsing::GetPredefinedValue](http://msdn.microsoft.com/library/windows/desktop/ms690401) no SDK do Windows.  
  
##  <a name="mappropertytopage"></a>IPerPropertyBrowsingImpl::MapPropertyToPage  
 Recupera o CLSID da página de propriedades associada com a propriedade especificada.  
  
```
STDMETHOD(MapPropertyToPage)(
    DISPID dispID,
    CLSID* pClsid);
```  
  
### <a name="remarks"></a>Comentários  
 ATL usa mapa de propriedade do objeto para obter essas informações.  
  
 Consulte [IPerPropertyBrowsing::MapPropertyToPage](http://msdn.microsoft.com/library/windows/desktop/ms694476) no SDK do Windows.  
  
## <a name="see-also"></a>Consulte também  
 [Classe IPropertyPageImpl](../../atl/reference/ipropertypageimpl-class.md)   
 [Classe ISpecifyPropertyPagesImpl](../../atl/reference/ispecifypropertypagesimpl-class.md)   
 [Visão geral da classe](../../atl/atl-class-overview.md)
