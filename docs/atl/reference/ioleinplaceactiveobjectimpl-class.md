---
title: "Classe de IOleInPlaceActiveObjectImpl | Microsoft Docs"
ms.custom: ""
ms.date: "12/16/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "reference"
f1_keywords: 
  - "IOleInPlaceActiveObjectImpl"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Controles ActiveX [C++], comunicação entre o contêiner e o controle"
  - "IOleInPlaceActiveObject, Implementação de ATL"
  - "Classe de IOleInPlaceActiveObjectImpl"
ms.assetid: 44e6cc6d-a2dc-4187-98e3-73cf0320dea9
caps.latest.revision: 22
caps.handback.revision: 9
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Classe de IOleInPlaceActiveObjectImpl
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Essa classe fornece métodos para ajudar a comunicação entre um controle no lugar e o contêiner.  
  
> [!IMPORTANT]
>  Essa classe e seus membros não podem ser usados em aplicativos executados em [!INCLUDE[wrt](../../atl/reference/includes/wrt_md.md)].  
  
## Sintaxe  
  
```  
  
      template< class   
      T  
      >  
class IOleInPlaceActiveObjectImpl  
```  
  
#### Parâmetros  
 `T`  
 Sua classe, derivada de `IOleInPlaceActiveObjectImpl`.  
  
## Membros  
  
### Métodos públicos  
  
|Nome|Descrição|  
|----------|---------------|  
|[IOleInPlaceActiveObjectImpl::ContextSensitiveHelp](../Topic/IOleInPlaceActiveObjectImpl::ContextSensitiveHelp.md)|Permite que a ajuda contextual.  a implementação de ATL retorna **E\_NOTIMPL**.|  
|[IOleInPlaceActiveObjectImpl::EnableModeless](../Topic/IOleInPlaceActiveObjectImpl::EnableModeless.md)|Permite caixas de diálogo sem\-modo.  a implementação de ATL retorna `S_OK`.|  
|[IOleInPlaceActiveObjectImpl::GetWindow](../Topic/IOleInPlaceActiveObjectImpl::GetWindow.md)|Obtém um identificador de janela.|  
|[IOleInPlaceActiveObjectImpl::OnDocWindowActivate](../Topic/IOleInPlaceActiveObjectImpl::OnDocWindowActivate.md)|Notifica o controle quando a janela do documento recipiente é ativada ou desativada.  a implementação de ATL retorna `S_OK`.|  
|[IOleInPlaceActiveObjectImpl::OnFrameWindowActivate](../Topic/IOleInPlaceActiveObjectImpl::OnFrameWindowActivate.md)|Notifica o controle quando a janela de nível superior do quadro recipiente é ativada ou desativada.  Retorna a implementação de ATL|  
|[IOleInPlaceActiveObjectImpl::ResizeBorder](../Topic/IOleInPlaceActiveObjectImpl::ResizeBorder.md)|Informa o controle que precisam redimensionar as bordas.  a implementação de ATL retorna `S_OK`.|  
|[IOleInPlaceActiveObjectImpl::TranslateAccelerator](../Topic/IOleInPlaceActiveObjectImpl::TranslateAccelerator.md)|Processa mensagens de tecla aceleradora de menu do recipiente.  a implementação de ATL retorna **E\_NOTIMPL**.|  
  
## Comentários  
 A comunicação de assistências de interface de [IOleInPlaceActiveObject](http://msdn.microsoft.com/library/windows/desktop/ms691299) entre um controle no lugar e o contêiner; por exemplo, comunicando o estado ativo do controle e recipiente, e informando o controle precisa redimensionar\-se.  A classe `IOleInPlaceActiveObjectImpl` fornece uma implementação padrão de `IOleInPlaceActiveObject` e suporta **IUnknown** enviar informações para o dispositivo de despejo em compilações de depuração.  
  
 **Artigos relacionados** [tutorial de ATL](../Topic/Active%20Template%20Library%20\(ATL\)%20Tutorial.md), [criando um projeto de ATL](../../atl/reference/creating-an-atl-project.md)  
  
## Hierarquia de herança  
 `IOleInPlaceActiveObject`  
  
 `IOleInPlaceActiveObjectImpl`  
  
## Requisitos  
 **Cabeçalho:** atlctl.h  
  
## Consulte também  
 [Classe de CComControl](../../atl/reference/ccomcontrol-class.md)   
 [ActiveX Controls Interfaces](http://msdn.microsoft.com/library/windows/desktop/ms692724)   
 [Visão geral de classe](../../atl/atl-class-overview.md)