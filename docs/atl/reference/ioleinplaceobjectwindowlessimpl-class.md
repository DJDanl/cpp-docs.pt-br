---
title: "Classe de IOleInPlaceObjectWindowlessImpl | Microsoft Docs"
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
  - "IOleInPlaceObjectWindowlessImpl"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "ativação [C++], ATL"
  - "Controles ActiveX [C++], comunicação entre o contêiner e o controle"
  - "controles [ATL], sem o windows"
  - "desativando ATL"
  - "IOleInPlaceObjectWindowless, Implementação de ATL"
  - "Classe de IOleInPlaceObjectWindowlessImpl"
ms.assetid: a2e0feb4-bc59-4adf-aab2-105457bbdbb4
caps.latest.revision: 20
caps.handback.revision: 8
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Classe de IOleInPlaceObjectWindowlessImpl
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Essa classe implementa **IUnknown** e fornece métodos que permitem que um controle sem janelas para receber mensagens de janela e para participar de operações de arrastar e soltar.  
  
> [!IMPORTANT]
>  Essa classe e seus membros não podem ser usados em aplicativos executados em [!INCLUDE[wrt](../../atl/reference/includes/wrt_md.md)].  
  
## Sintaxe  
  
```  
  
      template< class   
      T  
      >  
class IOleInPlaceObjectWindowlessImpl  
```  
  
#### Parâmetros  
 `T`  
 Sua classe, derivada de `IOleInPlaceObjectWindowlessImpl`.  
  
## Membros  
  
### Métodos públicos  
  
|Nome|Descrição|  
|----------|---------------|  
|[IOleInPlaceObjectWindowlessImpl::ContextSensitiveHelp](../Topic/IOleInPlaceObjectWindowlessImpl::ContextSensitiveHelp.md)|Permite que a ajuda contextual.  a implementação de ATL retorna **E\_NOTIMPL**.|  
|[IOleInPlaceObjectWindowlessImpl::GetDropTarget](../Topic/IOleInPlaceObjectWindowlessImpl::GetDropTarget.md)|O fornece a interface de `IDropTarget` para um objeto ativa, sem janelas no lugar que suporta arraste e se a.  a implementação de ATL retorna **E\_NOTIMPL**.|  
|[IOleInPlaceObjectWindowlessImpl::GetWindow](../Topic/IOleInPlaceObjectWindowlessImpl::GetWindow.md)|Obtém um identificador de janela.|  
|[IOleInPlaceObjectWindowlessImpl::InPlaceDeactivate](../Topic/IOleInPlaceObjectWindowlessImpl::InPlaceDeactivate.md)|Desativa um controle no lugar.|  
|[IOleInPlaceObjectWindowlessImpl::OnWindowMessage](../Topic/IOleInPlaceObjectWindowlessImpl::OnWindowMessage.md)|Despacha uma mensagem do recipiente para um controle sem janelas que está ativa no lugar.|  
|[IOleInPlaceObjectWindowlessImpl::ReactivateAndUndo](../Topic/IOleInPlaceObjectWindowlessImpl::ReactivateAndUndo.md)|Reactivates um controle anteriormente desativado.  a implementação de ATL retorna **E\_NOTIMPL**.|  
|[IOleInPlaceObjectWindowlessImpl::SetObjectRects](../Topic/IOleInPlaceObjectWindowlessImpl::SetObjectRects.md)|Indica que parte do controle no local é visível.|  
|[IOleInPlaceObjectWindowlessImpl::UIDeactivate](../Topic/IOleInPlaceObjectWindowlessImpl::UIDeactivate.md)|Desativa e remove a interface do usuário que suporta o ativação in\-loco.|  
  
## Comentários  
 A interface de [IOleInPlaceObject](http://msdn.microsoft.com/library/windows/desktop/ms692646) gerencia o reactivation e a desactivação de controles no local e determina quanto de controle deve estar visível.  A interface de [IOleInPlaceObjectWindowless](http://msdn.microsoft.com/library/windows/desktop/ms687304) permite que um controle sem janelas para receber mensagens de janela e para participar de operações de arrastar e soltar.  A classe `IOleInPlaceObjectWindowlessImpl` fornece uma implementação padrão de `IOleInPlaceObject` e de `IOleInPlaceObjectWindowless` e implementa **IUnknown** enviar informações para o dispositivo de despejo em compilações de depuração.  
  
 **Artigos relacionados** [tutorial de ATL](../Topic/Active%20Template%20Library%20\(ATL\)%20Tutorial.md), [criando um projeto de ATL](../../atl/reference/creating-an-atl-project.md)  
  
## Hierarquia de herança  
 `IOleInPlaceObjectWindowless`  
  
 `IOleInPlaceObjectWindowlessImpl`  
  
## Requisitos  
 **Cabeçalho:** atlctl.h  
  
## Consulte também  
 [Classe de CComControl](../../atl/reference/ccomcontrol-class.md)   
 [Visão geral de classe](../../atl/atl-class-overview.md)