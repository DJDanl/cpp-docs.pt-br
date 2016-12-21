---
title: "Classe de CWinTraits | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "reference"
f1_keywords: 
  - "CWinTraits"
  - "CMDIChildWinTraits"
  - "ATL.CWinTraits"
  - "CFrameWinTraits"
  - "ATL::CWinTraits"
  - "CControlWinTraits"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Classe de CControlWinTraits"
  - "Classe de CFrameWinTraits"
  - "Classe de CMDIChildWinTraits"
  - "Classe de CWinTraits"
  - "estilos de janela, valores padrão para ATL"
ms.assetid: f78f486e-6d9c-42c6-8e86-371e05aa7e59
caps.latest.revision: 19
caps.handback.revision: 7
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Classe de CWinTraits
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Essa classe fornece um método para padronizar os estilos usados para criar um objeto da janela.  
  
> [!IMPORTANT]
>  Essa classe e seus membros não podem ser usados em aplicativos executados em tempo de execução do windows.  
  
## Sintaxe  
  
```  
  
      template <  
DWORD t_dwStyle= 0,  
DWORD t_dwExStyle= 0  
>  
class CWinTraits  
```  
  
#### Parâmetros  
 `t_dwStyle`  
 Usar como padrão estilos de janela padrão.  
  
 `t_dwExStyle`  
 Estilos estendidos de janela default.  
  
## Membros  
  
### Métodos públicos  
  
|Nome|Descrição|  
|----------|---------------|  
|[CWinTraits::GetWndExStyle](../Topic/CWinTraits::GetWndExStyle.md)|\(Static\) Recupera os estilos estendidos para o objeto de `CWinTraits` .|  
|[CWinTraits::GetWndStyle](../Topic/CWinTraits::GetWndStyle.md)|\(Static\) Recupera os estilos padrão para o objeto de `CWinTraits` .|  
  
## Comentários  
 Essa classe de [traços da janela](../../atl/understanding-window-traits.md) fornece um método simples para padronizar os estilos usados para a criação de um objeto da janela de ATL.  Use uma especialização de essa classe como um parâmetro de modelo a [CWindowImpl](../Topic/CWindowImpl%20Class.md) ou outro de classes da janela de ATL para especificar o padrão e os estilos estendidos usados para instâncias de classe da janela.  
  
 Use esse modelo quando você deseja fornecer os estilos de janela padrão que serão usados somente quando nenhum outro estilo é especificado na chamada a [CWindowImpl::Create](../Topic/CWindowImpl::Create.md).  
  
 ATL fornece três especializações predefinidas de esse modelo para combinações de uso geral de estilos de janela:  
  
 `CControlWinTraits`  
 Projetado para uma janela de controle padrão.  Os seguintes estilos padrão são usados: **WS\_CHILD**, **WS\_VISIBLE**, **WS\_CLIPCHILDREN**, e **WS\_CLIPSIBLINGS**.  Não há nenhum estilo estendido.  
  
 `CFrameWinTraits`  
 Projetado para uma janela do quadro padrão.  Os estilos padrões utilizados incluem: **WS\_OVERLAPPEDWINDOW**, **WS\_CLIPCHILDREN**, e **WS\_CLIPSIBLINGS**.  Os estilos estendidos usados incluem: **WS\_EX\_APPWINDOW** e **WS\_EX\_WINDOWEDGE**.  
  
 `CMDIChildWinTraits`  
 Projetado para uma janela filho MDI padrão.  Os estilos padrões utilizados incluem: **WS\_OVERLAPPEDWINDOW**, **WS\_CHILD**, **WS\_VISIBLE**, **WS\_CLIPCHILDREN**, e **WS\_CLIPSIBLINGS**.  Os estilos estendidos usados incluem: **WS\_EX\_MDICHILD**.  
  
 Se você quiser garantir que determinados estilos são definidos para todas as instâncias da classe da janela para permitir que outros estilos ser definido em vez de em uma base por instância, use [CWinTraitsOR](../../atl/reference/cwintraitsor-class.md) .  
  
## Requisitos  
 **Cabeçalho:** atlwin.h  
  
## Consulte também  
 [Class Members](http://msdn.microsoft.com/pt-br/dbe6a147-3f01-4aea-a3fb-fe6ebadc31f8)   
 [Visão geral de classe](../../atl/atl-class-overview.md)   
 [A janela de traços entendendo](../../atl/understanding-window-traits.md)