---
title: "Classe de IOleControlImpl | Microsoft Docs"
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
  - "IOleControlImpl"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Classe de IOleControlImpl"
ms.assetid: 5a4255ad-ede4-49ca-ba9a-07c2e919fa85
caps.latest.revision: 22
caps.handback.revision: 10
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Classe de IOleControlImpl
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Essa classe fornece uma implementação padrão de interface de **IOleControl** e implementa **IUnknown**.  
  
> [!IMPORTANT]
>  Essa classe e seus membros não podem ser usados em aplicativos executados em [!INCLUDE[wrt](../../atl/reference/includes/wrt_md.md)].  
  
## Sintaxe  
  
```  
  
      template< class   
      T  
      >  
class IOleControlImpl  
```  
  
#### Parâmetros  
 `T`  
 Sua classe, derivada de `IOleControlImpl`.  
  
## Membros  
  
### Métodos públicos  
  
|Nome|Descrição|  
|----------|---------------|  
|[IOleControlImpl::FreezeEvents](../Topic/IOleControlImpl::FreezeEvents.md)|Indica se o contêiner ignora ou aceita eventos do controle.|  
|[IOleControlImpl::GetControlInfo](../Topic/IOleControlImpl::GetControlInfo.md)|Preenche as informações sobre o comportamento do teclado ao controle.  a implementação de ATL retorna **E\_NOTIMPL**.|  
|[IOleControlImpl::OnAmbientPropertyChange](../Topic/IOleControlImpl::OnAmbientPropertyChange.md)|Informa um controle que uma ou mais das propriedades de ambiente de controles foram alterados.  a implementação de ATL retorna `S_OK`.|  
|[IOleControlImpl::OnMnemonic](../Topic/IOleControlImpl::OnMnemonic.md)|Informa o controle que um usuário pressionou um pressionamento de tecla especificado.  a implementação de ATL retorna **E\_NOTIMPL**.|  
  
## Comentários  
 A classe `IOleControlImpl` fornece uma implementação padrão de interface de [IOleControl](http://msdn.microsoft.com/library/windows/desktop/ms694320) e implementa **IUnknown** enviar informações para o dispositivo de despejo em compilações de depuração.  
  
 **Artigos relacionados** [tutorial de ATL](../Topic/Active%20Template%20Library%20\(ATL\)%20Tutorial.md), [criando um projeto de ATL](../../atl/reference/creating-an-atl-project.md)  
  
## Hierarquia de herança  
 `IOleControl`  
  
 `IOleControlImpl`  
  
## Requisitos  
 **Cabeçalho:** atlctl.h  
  
## Consulte também  
 [Classe de IOleObjectImpl](../../atl/reference/ioleobjectimpl-class.md)   
 [ActiveX Controls Interfaces](http://msdn.microsoft.com/library/windows/desktop/ms692724)   
 [Visão geral de classe](../../atl/atl-class-overview.md)