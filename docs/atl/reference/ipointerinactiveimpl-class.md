---
title: "Classe de IPointerInactiveImpl | Microsoft Docs"
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
  - "IPointerInactiveImpl"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "objetos inativos"
  - "Implementação de IPointerInactive ATL"
  - "Classe de IPointerInactiveImpl"
ms.assetid: e1fe9ea6-d38a-4527-9112-eb344771e0b7
caps.latest.revision: 21
caps.handback.revision: 10
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Classe de IPointerInactiveImpl
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Essa classe implementa **IUnknown** e métodos de interface de [IPointerInactive](http://msdn.microsoft.com/library/windows/desktop/ms693712) .  
  
> [!IMPORTANT]
>  Essa classe e seus membros não podem ser usados em aplicativos executados em [!INCLUDE[wrt](../../atl/reference/includes/wrt_md.md)].  
  
## Sintaxe  
  
```  
  
      template< class   
      T  
      >  
class IPointerInactiveImpl  
```  
  
#### Parâmetros  
 `T`  
 Sua classe, derivada de `IPointerInactiveImpl`.  
  
## Membros  
  
### Métodos públicos  
  
|Nome|Descrição|  
|----------|---------------|  
|[IPointerInactiveImpl::GetActivationPolicy](../Topic/IPointerInactiveImpl::GetActivationPolicy.md)|Recupera a diretiva atual de ativação para o objeto.  a implementação de ATL retorna **E\_NOTIMPL**.|  
|[IPointerInactiveImpl::OnInactiveMouseMove](../Topic/IPointerInactiveImpl::OnInactiveMouseMove.md)|Notifica o objeto que o ponteiro do mouse sobre ele se mover, indicando que o objeto pode acionar eventos de mouse.  a implementação de ATL retorna **E\_NOTIMPL**.|  
|[IPointerInactiveImpl::OnInactiveSetCursor](../Topic/IPointerInactiveImpl::OnInactiveSetCursor.md)|Define o ponteiro do mouse para o objeto inativo.  a implementação de ATL retorna **E\_NOTIMPL**.|  
  
## Comentários  
 Um objeto inativo é um que é carregado ou simplesmente executar.  A o contrário de um objeto ativa, um objeto inativo não pode receber mensagens do windows mouse e teclado.  Assim, os objetos usam inativos menos recursos e são geralmente mais eficientes.  
  
 A interface de [IPointerInactive](http://msdn.microsoft.com/library/windows/desktop/ms693712) permite que um objeto suporta um nível mínimo de interação do mouse permanece inativo.  Essa funcionalidade é particularmente útil para controles.  
  
 A classe implementa `IPointerInactiveImpl` os métodos de `IPointerInactive` simplesmente retornando **E\_NOTIMPL**.  Em o entanto, implementa **IUnknown** enviar informações para o dispositivo de despejo em compilações de depuração.  
  
 **Artigos relacionados** [tutorial de ATL](../Topic/Active%20Template%20Library%20\(ATL\)%20Tutorial.md), [criando um projeto de ATL](../../atl/reference/creating-an-atl-project.md)  
  
## Hierarquia de herança  
 `IPointerInactive`  
  
 `IPointerInactiveImpl`  
  
## Requisitos  
 **Cabeçalho:** atlctl.h  
  
## Consulte também  
 [Visão geral de classe](../../atl/atl-class-overview.md)