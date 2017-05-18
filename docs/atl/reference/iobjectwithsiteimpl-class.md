---
title: Classe IObjectWithSiteImpl | Documentos do Microsoft
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-windows
ms.tgt_pltfrm: 
ms.topic: reference
f1_keywords:
- IObjectWithSiteImpl
- ATLCOM/ATL::IObjectWithSiteImpl
- ATLCOM/ATL::IObjectWithSiteImpl::GetSite
- ATLCOM/ATL::IObjectWithSiteImpl::SetChildSite
- ATLCOM/ATL::IObjectWithSiteImpl::SetSite
- ATLCOM/ATL::IObjectWithSiteImpl::m_spUnkSite
dev_langs:
- C++
helpviewer_keywords:
- IObjectWithSiteImpl class
ms.assetid: 4e1f774f-bc3d-45ee-9a1c-c3533a511588
caps.latest.revision: 18
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
ms.translationtype: Machine Translation
ms.sourcegitcommit: 0e0c08ddc57d437c51872b5186ae3fc983bb0199
ms.openlocfilehash: 49c52810417650c3d80fe4d0c09ccb2b67208ad4
ms.contentlocale: pt-br
ms.lasthandoff: 02/25/2017

---
# <a name="iobjectwithsiteimpl-class"></a>Classe IObjectWithSiteImpl
Essa classe fornece métodos que permitem a um objeto para se comunicar com seu site.  
  
## <a name="syntax"></a>Sintaxe  
  
```
template <class T>
    class ATL_NO_VTABLE IObjectWithSiteImpl :
    public IObjectWithSite
```  
  
#### <a name="parameters"></a>Parâmetros  
 `T`  
 Sua classe derivada de `IObjectWithSiteImpl`.  
  
## <a name="members"></a>Membros  
  
### <a name="public-methods"></a>Métodos Públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[IObjectWithSiteImpl::GetSite](#getsite)|Consulta o site para um ponteiro de interface.|  
|[IObjectWithSiteImpl::SetChildSite](#setchildsite)|Fornece o objeto com o site **IUnknown** ponteiro.|  
|[IObjectWithSiteImpl::SetSite](#setsite)|Fornece o objeto com o site **IUnknown** ponteiro.|  
  
### <a name="public-data-members"></a>Membros de Dados Públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[IObjectWithSiteImpl::m_spUnkSite](#m_spunksite)|Gerencia o site **IUnknown** ponteiro.|  
  
## <a name="remarks"></a>Comentários  
 O [IObjectWithSite](http://msdn.microsoft.com/library/windows/desktop/ms693765) interface permite que um objeto para se comunicar com seu site. Classe `IObjectWithSiteImpl` fornece uma implementação padrão dessa interface e implementa **IUnknown** enviando informações para o despejo de compilações de dispositivo no modo de depuração.  
  
 `IObjectWithSiteImpl`Especifica os dois métodos. O cliente primeiro chama `SetSite`, passando o site **IUnknown** ponteiro. Esse ponteiro é armazenado no objeto e pode ser recuperado posteriormente por meio de uma chamada para `GetSite`.  
  
 Normalmente, você deriva a classe de `IObjectWithSiteImpl` quando você estiver criando um objeto que não é um controle. Para controles, derive a classe de [IOleObjectImpl](../../atl/reference/ioleobjectimpl-class.md), que também fornece um ponteiro de site. Não derivar a classe de ambos `IObjectWithSiteImpl` e `IOleObjectImpl`.  
  
## <a name="inheritance-hierarchy"></a>Hierarquia de herança  
 `IObjectWithSite`  
  
 `IObjectWithSiteImpl`  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** atlcom.h  
  
##  <a name="getsite"></a>IObjectWithSiteImpl::GetSite  
 Consulta o site de um ponteiro para a interface identificada pelo `riid`.  
  
```
STDMETHOD(GetSite)(
    REFIID riid,
    void** ppvSite);
```  
  
### <a name="remarks"></a>Comentários  
 Se o site oferece suporte a essa interface, o ponteiro é retornado por meio de `ppvSite`. Caso contrário, `ppvSite` é definido como **nulo**.  
  
 Consulte [IObjectWithSite::GetSite](http://msdn.microsoft.com/library/windows/desktop/ms694452) no [!INCLUDE[winSDK](../../atl/includes/winsdk_md.md)].  
  
##  <a name="m_spunksite"></a>IObjectWithSiteImpl::m_spUnkSite  
 Gerencia o site **IUnknown** ponteiro.  
  
```
CComPtr<IUnknown> m_spUnkSite;
```  
  
### <a name="remarks"></a>Comentários  
 `m_spUnkSite`inicialmente recebe esse ponteiro através de uma chamada para [SetSite](#setsite).  
  
##  <a name="setchildsite"></a>IObjectWithSiteImpl::SetChildSite  
 Fornece o objeto com o site **IUnknown** ponteiro.  
  
```
HRESULT SetChildSite(IUnknown* pUnkSite);
```  
  
### <a name="parameters"></a>Parâmetros  
 *pUnkSite*  
 [in] Ponteiro para o **IUnknown** ponteiro de interface do site gerenciando este objeto. Se for NULL, o objeto deve chamar `IUnknown::Release` em qualquer site existente no ponto em que o objeto não tem seu site.  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna `S_OK`.  
  
##  <a name="setsite"></a>IObjectWithSiteImpl::SetSite  
 Fornece o objeto com o site **IUnknown** ponteiro.  
  
```
STDMETHOD(SetSite)(IUnknown* pUnkSite);
```  
  
### <a name="remarks"></a>Comentários  
 Consulte [IObjectWithSite::SetSite](http://msdn.microsoft.com/library/windows/desktop/ms683869) no [!INCLUDE[winSDK](../../atl/includes/winsdk_md.md)].  
  
## <a name="see-also"></a>Consulte também  
 [Visão geral da classe](../../atl/atl-class-overview.md)

