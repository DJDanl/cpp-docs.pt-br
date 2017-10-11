---
title: Interface IAxWinHostWindowLic | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-windows
ms.tgt_pltfrm: 
ms.topic: reference
f1_keywords:
- IAxWinHostWindowLic
- No header/ATL::IAxWinHostWindowLic
- No header/ATL::CreateControlLic
- No header/ATL::CreateControlLicEx
dev_langs:
- C++
helpviewer_keywords:
- IAxWinHostWindowLic interface
ms.assetid: 750f1520-6bce-428c-aca0-fccbe3f063c7
caps.latest.revision: 19
author: mikeblome
ms.author: mblome
manager: ghogen
ms.translationtype: MT
ms.sourcegitcommit: c55726a1728185f699afbac4ba68a6dc0f70c2bf
ms.openlocfilehash: 6d0e8c0a8ec941c7a7980b81fcd95df08298ea28
ms.contentlocale: pt-br
ms.lasthandoff: 10/09/2017

---
# <a name="iaxwinhostwindowlic-interface"></a>Interface IAxWinHostWindowLic
Essa interface fornece métodos para manipular um controle licenciado e seu objeto de host.  
  
## <a name="syntax"></a>Sintaxe  
  
```
interface IAxWinHostWindowLic : IAxWinHostWindow
```  
  
## <a name="members"></a>Membros  
  
### <a name="methods"></a>Métodos  
  
|||  
|-|-|  
|[CreateControlLic](#createcontrollic)|Cria um controle licenciado e a anexa ao objeto de host.|  
|[CreateControlLicEx](#createcontrollicex)|Cria um controle licenciado, anexa-o ao objeto de host e, opcionalmente, configura um manipulador de eventos.|  
  
## <a name="remarks"></a>Comentários  
 `IAxWinHostWindowLic`herda de [IAxWinHostWindow](../../atl/reference/iaxwinhostwindow-interface.md) e adiciona métodos que oferecem suporte a criação de controles licenciados.  
  
 Consulte [hospedagem de AXHost de ATL usando do ActiveX controles](../../atl/hosting-activex-controls-using-atl-axhost.md) para obter um exemplo que usa os membros desta interface.  
  
## <a name="requirements"></a>Requisitos  
 A definição desta interface está disponível como IDL ou C++, conforme mostrado abaixo.  
  
|Tipo de definição|Arquivo|  
|---------------------|----------|  
|IDL|ATLIFace.idl|  
|C++|Atliface (também é incluído no atlbase)|  
  
##  <a name="createcontrollic"></a>IAxWinHostWindowLic::CreateControlLic  
 Cria um controle licenciado, inicializa e hospeda na janela identificada por `hWnd`.  
  
```
STDMETHOD(CreateControlLic)(
    LPCOLESTR lpTricsData,
    HWND hWnd,
    IStream* pStream,
    BSTR bstrLic);
```  
  
### <a name="parameters"></a>Parâmetros  
 `bstrLic`  
 [in] BSTR que contém a chave de licença para o controle.  
  
### <a name="remarks"></a>Comentários  
 Consulte [IAxWinHostWindow::CreateControl](../../atl/reference/iaxwinhostwindow-interface.md#createcontrol) para obter uma descrição do valor de retorno e parâmetros restantes.  
  
 Chamar esse método é equivalente a chamar [IAxWinHostWindowLic::CreateControlLicEx](#createcontrollicex)  
  
### <a name="example"></a>Exemplo  
 Consulte [hospedagem de AXHost de ATL usando do ActiveX controles](../../atl/hosting-activex-controls-using-atl-axhost.md) para obter um exemplo que usa `IAxWinHostWindowLic::CreateControlLic`.  
  
##  <a name="createcontrollicex"></a>IAxWinHostWindowLic::CreateControlLicEx  
 Cria um controle ActiveX licenciado, inicializa e hospeda na janela especificada, semelhante ao [IAxWinHostWindow::CreateControl](../../atl/reference/iaxwinhostwindow-interface.md#createcontrol).  
  
```
STDMETHOD(CreateControlLicEx)(
    LPCOLESTR lpszTricsData,
    HWND hWnd,
    IStream* pStream,
    IUnknown** ppUnk,
    REFIID riidAdvise,
    IUnknown* punkAdvise,
    BSTR bstrLic);
```  
  
### <a name="parameters"></a>Parâmetros  
 `bstrLic`  
 [in] BSTR que contém a chave de licença para o controle.  
  
### <a name="remarks"></a>Comentários  
 Consulte [IAxWinHostWindow::CreateControlEx](../../atl/reference/iaxwinhostwindow-interface.md#createcontrolex) para obter uma descrição do valor de retorno e parâmetros restantes.  
  
### <a name="example"></a>Exemplo  
 Consulte [hospedagem de AXHost de ATL usando do ActiveX controles](../../atl/hosting-activex-controls-using-atl-axhost.md) para obter um exemplo que usa `IAxWinHostWindowLic::CreateControlLicEx`.










