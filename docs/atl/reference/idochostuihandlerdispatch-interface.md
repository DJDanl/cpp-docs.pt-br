---
title: Interface IDocHostUIHandlerDispatch | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-atl
ms.topic: reference
f1_keywords:
- IDocHostUIHandlerDispatch
- atlbase/ATL::IDocHostUIHandlerDispatch
dev_langs:
- C++
helpviewer_keywords:
- IDocHostUIHandlerDispatch interface
ms.assetid: 6963a301-601a-4ac3-8bef-f7b252ea2fc6
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 57dbb9e5ed73ce8ed85d7c90d05705cefdd4ed9b
ms.sourcegitcommit: 9a0905c03a73c904014ec9fd3d6e59e4fa7813cd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/29/2018
ms.locfileid: "43194761"
---
# <a name="idochostuihandlerdispatch-interface"></a>Interface IDocHostUIHandlerDispatch
Uma interface para a análise de HTML da Microsoft e o mecanismo de renderização.  
  
> [!IMPORTANT]
>  Essa classe e seus membros não podem ser usados em aplicativos executados no tempo de execução do Windows.  
  
## <a name="syntax"></a>Sintaxe  
  
```
interface IDocHostUIHandlerDispatch : IDispatch
```  
  
## <a name="members"></a>Membros  
  
### <a name="public-methods"></a>Métodos públicos  
  
> [!NOTE]
>  Os links na tabela a seguir são para os tópicos de referência de SDK INet para os membros do [IDocUIHostHandler](https://msdn.microsoft.com/library/aa753260.aspx) interface. `IDocHostUIHandlerDispatch` tem a mesma funcionalidade que `IDocUIHostHandler`, com a diferença sendo que `IDocHostUIHandlerDispatch` é um dispinterface enquanto `IDocUIHostHandler` é uma interface personalizada.  
  
|||  
|-|-|  
|[EnableModeless](https://msdn.microsoft.com/library/aa753253.aspx)|Chamada da implementação do MSHTML do [IOleInPlaceActiveObject::EnableModeless](/windows/desktop/api/oleidl/nf-oleidl-ioleinplaceactiveobject-enablemodeless). Também é chamado quando o MSHTML exibe a interface do usuário modal.|  
|[FilterDataObject](https://msdn.microsoft.com/library/aa753254.aspx)|Chamado no host pelo MSHTML para permitir que o host substituir o objeto de dados do MSHTML.|  
|[GetDropTarget](https://msdn.microsoft.com/library/aa753255.aspx)|Chamado pelo MSHTML quando ele está sendo usado como um destino de soltar para permitir que o host fornecer uma alternativa [IDropTarget](/windows/desktop/api/oleidl/nn-oleidl-idroptarget).|  
|[GetExternal](https://msdn.microsoft.com/library/aa753256.aspx)|Chamado pelo MSHTML para obter a interface IDispatch do host.|  
|[GetHostInfo](https://msdn.microsoft.com/library/aa753257.aspx)|Recupera os recursos de interface do usuário do host MSHTML.|  
|[GetOptionKeyPath](https://msdn.microsoft.com/library/aa753258.aspx)|Retorna a chave do registro sob a qual MSHTML armazena as preferências do usuário.|  
|[HideUI](https://msdn.microsoft.com/library/aa753259.aspx)|Chamado quando MSHTML remove seus menus e barras de ferramentas.|  
|[OnDocWindowActivate](https://msdn.microsoft.com/library/aa753261.aspx)|Chamada da implementação do MSHTML do [IOleInPlaceActiveObject::OnDocWindowActivate](/windows/desktop/api/oleidl/nf-oleidl-ioleinplaceactiveobject-ondocwindowactivate).|  
|[OnFrameWindowActivate](https://msdn.microsoft.com/library/aa753262.aspx)|Chamada da implementação do MSHTML do [IOleInPlaceActiveObject::OnFrameWindowActivate](/windows/desktop/api/oleidl/nf-oleidl-ioleinplaceactiveobject-onframewindowactivate).|  
|[ResizeBorder](https://msdn.microsoft.com/library/aa753263.aspx)|Chamada da implementação do MSHTML do [IOleInPlaceActiveObject::ResizeBorder](/windows/desktop/api/oleidl/nf-oleidl-ioleinplaceactiveobject-resizeborder).|  
|[ShowContextMenu](https://msdn.microsoft.com/library/aa753264.aspx)|Chamado de MSHTML para exibir um menu de contexto.|  
|[ShowUI](https://msdn.microsoft.com/library/aa753265.aspx)|Permite que o host substituir as barras de ferramentas e menus MSHTML.|  
|[TranslateAccelerator](https://msdn.microsoft.com/library/aa753266.aspx)|Chamado pelo MSHTML quando [IOleInPlaceActiveObject::TranslateAccelerator](/windows/desktop/api/oleidl/nf-oleidl-ioleinplaceactiveobject-translateaccelerator) ou [IOleControlSite::TranslateAccelerator](/windows/desktop/api/ocidl/nf-ocidl-iolecontrolsite-translateaccelerator) é chamado.|  
|[TranslateUrl](https://msdn.microsoft.com/library/aa753267.aspx)|Chamado pelo MSHTML para permitir que o host a oportunidade de modificar a URL a ser carregado.|  
|[UpdateUI](https://msdn.microsoft.com/library/aa753268.aspx)|Notifica o host que o estado do comando foi alterado.|  
  
## <a name="remarks"></a>Comentários  
 Um host pode substituir os menus, barras de ferramentas e menus de contexto usados pela análise de HTML da Microsoft e o mecanismo de renderização (MSHTML) implementando essa interface.  
  
## <a name="requirements"></a>Requisitos  
 A definição desta interface está disponível como IDL ou C++, conforme mostrado abaixo.  
  
|Tipo de definição|Arquivo|  
|---------------------|----------|  
|IDL|ATLIFace.idl|  
|C++|Atliface (também é incluído em atlbase. H)|  
  
## <a name="see-also"></a>Consulte também  
 [IDocUIHostHandler](https://msdn.microsoft.com/library/aa753260.aspx)









