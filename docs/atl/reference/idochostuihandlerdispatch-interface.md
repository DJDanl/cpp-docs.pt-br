---
title: Interface IDocHostUIHandlerDispatch | Documentos do Microsoft
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-windows
ms.tgt_pltfrm: 
ms.topic: reference
f1_keywords:
- IDocHostUIHandlerDispatch
- atlbase/ATL::IDocHostUIHandlerDispatch
dev_langs:
- C++
helpviewer_keywords:
- IDocHostUIHandlerDispatch interface
ms.assetid: 6963a301-601a-4ac3-8bef-f7b252ea2fc6
caps.latest.revision: 22
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
ms.sourcegitcommit: 3168772cbb7e8127523bc2fc2da5cc9b4f59beb8
ms.openlocfilehash: ba89697fb1c0e81d648d8faaaff1a97bb6a5d9ea
ms.contentlocale: pt-br
ms.lasthandoff: 02/25/2017

---
# <a name="idochostuihandlerdispatch-interface"></a>Interface IDocHostUIHandlerDispatch
Uma interface para o mecanismo de processamento e análise de HTML da Microsoft.  
  
> [!IMPORTANT]
>  Essa classe e seus membros não podem ser usados em aplicativos que são executados a [!INCLUDE[wrt](../../atl/reference/includes/wrt_md.md)].  
  
## <a name="syntax"></a>Sintaxe  
  
```
interface IDocHostUIHandlerDispatch : IDispatch
```  
  
## <a name="members"></a>Membros  
  
### <a name="public-methods"></a>Métodos públicos  
  
> [!NOTE]
>  Os links na tabela a seguir são para os tópicos de referência para os membros do SDK INet o [IDocUIHostHandler](https://msdn.microsoft.com/library/aa753260.aspx) interface. `IDocHostUIHandlerDispatch`tem a mesma funcionalidade que **IDocUIHostHandler**, com a diferença é que `IDocHostUIHandlerDispatch` é um dispinterface enquanto **IDocUIHostHandler** é uma interface personalizada.  
  
|||  
|-|-|  
|[EnableModeless](https://msdn.microsoft.com/library/aa753253.aspx)|Chamada da implementação de MSHTML do [IOleInPlaceActiveObject::EnableModeless](http://msdn.microsoft.com/library/windows/desktop/ms680115). Também é chamado quando o MSHTML exibe a interface do usuário modal.|  
|[FilterDataObject](https://msdn.microsoft.com/library/aa753254.aspx)|Chamado no host por MSHTML para permitir que o host substituir o objeto de dados do MSHTML.|  
|[GetDropTarget](https://msdn.microsoft.com/library/aa753255.aspx)|Chamado pelo MSHTML quando ele está sendo usado como um destino para permitir que o host fornecer uma alternativa [IDropTarget](http://msdn.microsoft.com/library/windows/desktop/ms679679).|  
|[GetExternal](https://msdn.microsoft.com/library/aa753256.aspx)|Chamado pelo MSHTML para obter a interface IDispatch do host.|  
|[GetHostInfo](https://msdn.microsoft.com/library/aa753257.aspx)|Recupera os recursos de interface do usuário do host MSHTML.|  
|[GetOptionKeyPath](https://msdn.microsoft.com/library/aa753258.aspx)|Retorna a chave do registro sob a qual MSHTML armazena as preferências do usuário.|  
|[HideUI](https://msdn.microsoft.com/library/aa753259.aspx)|Chamado quando MSHTML remove seus menus e barras de ferramentas.|  
|[OnDocWindowActivate](https://msdn.microsoft.com/library/aa753261.aspx)|Chamada da implementação de MSHTML do [IOleInPlaceActiveObject::OnDocWindowActivate](http://msdn.microsoft.com/library/windows/desktop/ms687281).|  
|[OnFrameWindowActivate](https://msdn.microsoft.com/library/aa753262.aspx)|Chamada da implementação de MSHTML do [IOleInPlaceActiveObject::OnFrameWindowActivate](http://msdn.microsoft.com/library/windows/desktop/ms683969).|  
|[ResizeBorder](https://msdn.microsoft.com/library/aa753263.aspx)|Chamada da implementação de MSHTML do [IOleInPlaceActiveObject::ResizeBorder](http://msdn.microsoft.com/library/windows/desktop/ms680053).|  
|[ShowContextMenu](https://msdn.microsoft.com/library/aa753264.aspx)|Chamadas de MSHTML para exibir um menu de contexto.|  
|[ShowUI](https://msdn.microsoft.com/library/aa753265.aspx)|Permite que o host substituir as barras de ferramentas e menus MSHTML.|  
|[TranslateAccelerator](https://msdn.microsoft.com/library/aa753266.aspx)|Chamado pelo MSHTML quando [IOleInPlaceActiveObject::TranslateAccelerator](http://msdn.microsoft.com/library/windows/desktop/ms693360) ou [IOleControlSite::TranslateAccelerator](http://msdn.microsoft.com/library/windows/desktop/ms693756) é chamado.|  
|[TranslateUrl](https://msdn.microsoft.com/library/aa753267.aspx)|Chamado pelo MSHTML para permitir que o host a oportunidade de modificar a URL a ser carregado.|  
|[UpdateUI](https://msdn.microsoft.com/library/aa753268.aspx)|Notifica o host que o estado do comando foi alterado.|  
  
## <a name="remarks"></a>Comentários  
 Um host pode substituir os menus, barras de ferramentas e menus de contexto usadas pelo mecanismo de renderização (MSHTML) e análise de HTML da Microsoft ao implementar essa interface.  
  
## <a name="requirements"></a>Requisitos  
 A definição desta interface está disponível como IDL ou C++, conforme mostrado abaixo.  
  
|Tipo de definição|Arquivo|  
|---------------------|----------|  
|IDL|ATLIFace.idl|  
|C++|Atliface (também incluído no atlbase. H)|  
  
## <a name="see-also"></a>Consulte também  
 [IDocUIHostHandler](https://msdn.microsoft.com/library/aa753260.aspx)










