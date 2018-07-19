---
title: Classe IObjectWithSiteImpl | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-atl
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
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 3a9403ed1a4ba82a1e60c42ed0e57e975e73d1dd
ms.sourcegitcommit: 7d68f8303e021e27dc8f4d36e764ed836e93d24f
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/06/2018
ms.locfileid: "37883782"
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
 *T*  
 Sua classe, derivada de `IObjectWithSiteImpl`.  
  
## <a name="members"></a>Membros  
  
### <a name="public-methods"></a>Métodos Públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[IObjectWithSiteImpl::GetSite](#getsite)|Consulta o site para um ponteiro de interface.|  
|[IObjectWithSiteImpl::SetChildSite](#setchildsite)|Fornece o objeto com o site `IUnknown` ponteiro.|  
|[IObjectWithSiteImpl::SetSite](#setsite)|Fornece o objeto com o site `IUnknown` ponteiro.|  
  
### <a name="public-data-members"></a>Membros de Dados Públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[IObjectWithSiteImpl::m_spUnkSite](#m_spunksite)|Gerencia o site `IUnknown` ponteiro.|  
  
## <a name="remarks"></a>Comentários  
 O [IObjectWithSite](http://msdn.microsoft.com/library/windows/desktop/ms693765) interface permite que um objeto para se comunicar com seu site. Classe `IObjectWithSiteImpl` fornece uma implementação padrão dessa interface e implementa `IUnknown` enviando informações para o despejo de compilações de dispositivo na depuração.  
  
 `IObjectWithSiteImpl` Especifica os dois métodos. O cliente primeiro chama `SetSite`, passando o site `IUnknown` ponteiro. Esse ponteiro é armazenado dentro do objeto e podem ser recuperado posteriormente por meio de uma chamada para `GetSite`.  
  
 Normalmente, você deriva sua classe de `IObjectWithSiteImpl` quando você estiver criando um objeto que não é um controle. Para controles, derive sua classe de [IOleObjectImpl](../../atl/reference/ioleobjectimpl-class.md), que também fornece um ponteiro de site. Deriva sua classe ambos `IObjectWithSiteImpl` e `IOleObjectImpl`.  
  
## <a name="inheritance-hierarchy"></a>Hierarquia de herança  
 `IObjectWithSite`  
  
 `IObjectWithSiteImpl`  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** atlcom  
  
##  <a name="getsite"></a>  IObjectWithSiteImpl::GetSite  
 Consulta o site de um ponteiro para a interface identificada pelo `riid`.  
  
```
STDMETHOD(GetSite)(
    REFIID riid,
    void** ppvSite);
```  
  
### <a name="remarks"></a>Comentários  
 Se o site oferece suporte a essa interface, o ponteiro é retornado por meio de `ppvSite`. Caso contrário, `ppvSite` é definido como NULL.  
  
 Ver [IObjectWithSite::GetSite](http://msdn.microsoft.com/library/windows/desktop/ms694452) no Windows SDK.  
  
##  <a name="m_spunksite"></a>  IObjectWithSiteImpl::m_spUnkSite  
 Gerencia o site `IUnknown` ponteiro.  
  
```
CComPtr<IUnknown> m_spUnkSite;
```  
  
### <a name="remarks"></a>Comentários  
 `m_spUnkSite` inicialmente recebe esse ponteiro por meio de uma chamada para [SetSite](#setsite).  
  
##  <a name="setchildsite"></a>  IObjectWithSiteImpl::SetChildSite  
 Fornece o objeto com o site `IUnknown` ponteiro.  
  
```
HRESULT SetChildSite(IUnknown* pUnkSite);
```  
  
### <a name="parameters"></a>Parâmetros  
 *pUnkSite*  
 [in] Ponteiro para o `IUnknown` ponteiro de interface do site gerenciando este objeto. Se for NULL, o objeto deve chamar `IUnknown::Release` em qualquer site existente no ponto em que o objeto não sabe que seu site.  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna S_OK.  
  
##  <a name="setsite"></a>  IObjectWithSiteImpl::SetSite  
 Fornece o objeto com o site `IUnknown` ponteiro.  
  
```
STDMETHOD(SetSite)(IUnknown* pUnkSite);
```  
  
### <a name="remarks"></a>Comentários  
 Ver [IObjectWithSite::SetSite](http://msdn.microsoft.com/library/windows/desktop/ms683869) no Windows SDK.  
  
## <a name="see-also"></a>Consulte também  
 [Visão geral da classe](../../atl/atl-class-overview.md)
