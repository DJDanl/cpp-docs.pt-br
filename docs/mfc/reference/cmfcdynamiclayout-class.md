---
title: "Classe CMFCDynamicLayout | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "reference"
dev_langs: 
  - "C++"
ms.assetid: c2df2976-f049-47fc-9cf0-abe3e01948bc
caps.latest.revision: 16
caps.handback.revision: 3
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Classe CMFCDynamicLayout
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Especifica como os controles em uma janela são movidos e redimensionados conforme o usuário redimensiona a janela.  
  
## Sintaxe  
  
```  
class CMFCDynamicLayout : public CObject  
```  
  
## Membros  
  
### Construtores Públicos  
  
|Nome|Descrição|  
|----------|---------------|  
|`CMFCDynamicLayout::CMFCDynamicLayout`|Constrói um objeto `CMFCDynamicLayout`.|  
|`CMFCDynamicLayout::~CMFCDynamicLayout`|Destruidor.|  
  
### Métodos Públicos  
  
|Nome|Descrição|  
|----------|---------------|  
|[CMFCDynamicLayout::AddItem](../Topic/CMFCDynamicLayout::AddItem.md)|Adiciona uma janela filho, geralmente um controle à lista de janelas que são controlados pelo Gerenciador de layout dinâmico.|  
|[CMFCDynamicLayout::Adjust](../Topic/CMFCDynamicLayout::Adjust.md)|Adiciona uma janela filho, geralmente um controle à lista de janelas que são controlados pelo Gerenciador de layout dinâmico.|  
|[CMFCDynamicLayout::Create](../Topic/CMFCDynamicLayout::Create.md)|Armazena e valida a janela do host.|  
|[CMFCDynamicLayout::GetHostWnd](../Topic/CMFCDynamicLayout::GetHostWnd.md)|Retorna um ponteiro para uma janela do host.|  
|[CMFCDynamicLayout::GetMinSize](../Topic/CMFCDynamicLayout::GetMinSize.md)|Retorna o tamanho da janela abaixo do qual o layout não é ajustado.|  
|[CMFCDynamicLayout::GetWindowRect](../Topic/CMFCDynamicLayout::GetWindowRect.md)|Recupera o retângulo para a área de cliente da janela atual.|  
|[CMFCDynamicLayout::HasItem](../Topic/CMFCDynamicLayout::HasItem.md)|Verifica se um controle filho foi adicionado ao layout dinâmico.|  
|[CMFCDynamicLayout::IsEmpty](../Topic/CMFCDynamicLayout::IsEmpty.md)|Verifica se um layout dinâmico tem sem janelas filho adicionadas.|  
|[CMFCDynamicLayout::LoadResource](../Topic/CMFCDynamicLayout::LoadResource.md)|Lê o layout dinâmico de recursos AFX\_DIALOG\_LAYOUT e aplica o layout para a janela do host.|  
|estático[CMFCDynamicLayout::MoveHorizontal](../Topic/CMFCDynamicLayout::MoveHorizontal.md)|Obtém uma[MoveSettings](../Topic/CMFCDynamicLayout::MoveSettings%20Structure.md)valor que define o nível de controle filho é movido horizontalmente quando o usuário redimensiona a janela de hospedagem.|  
|estático[CMFCDynamicLayout::MoveHorizontalAndVertical](../Topic/CMFCDynamicLayout::MoveHorizontalAndVertical.md)|Obtém uma[MoveSettings](../Topic/CMFCDynamicLayout::MoveSettings%20Structure.md)valor que define o nível de controle filho é movido horizontalmente quando o usuário redimensiona a janela de hospedagem.|  
|estático[CMFCDynamicLayout::MoveNone](../Topic/CMFCDynamicLayout::MoveNone.md)|Obtém uma[MoveSettings](../Topic/CMFCDynamicLayout::MoveSettings%20Structure.md)valor que não representa nenhum movimento vertical ou horizontal, para um controle filho.|  
|estático[CMFCDynamicLayout::MoveVertical](../Topic/CMFCDynamicLayout::MoveVertical.md)|Obtém uma[MoveSettings](../Topic/CMFCDynamicLayout::MoveSettings%20Structure.md)valor que define o nível de controle filho é movido verticalmente quando o usuário redimensiona a janela de hospedagem.|  
|[CMFCDynamicLayout::SetMinSize](../Topic/CMFCDynamicLayout::SetMinSize.md)|Define o tamanho da janela abaixo do qual o layout não é ajustado.|  
|estático[CMFCDynamicLayout::SizeHorizontal](../Topic/CMFCDynamicLayout::SizeHorizontal.md)|Obtém uma[SizeSettings](../Topic/CMFCDynamicLayout::SizeSettings%20Structure.md)valor que define o nível de controle filho é redimensionado horizontalmente quando o usuário redimensiona a janela de hospedagem.|  
|estático[CMFCDynamicLayout::SizeHorizontalAndVertical](../Topic/CMFCDynamicLayout::SizeHorizontalAndVertical.md)|Obtém uma[SizeSettings](../Topic/CMFCDynamicLayout::SizeSettings%20Structure.md)valor que define o nível de controle filho é redimensionado horizontalmente quando o usuário redimensiona a janela de hospedagem.|  
|estático[CMFCDynamicLayout::SizeNone](../Topic/CMFCDynamicLayout::SizeNone.md)|Obtém uma[SizeSettings](../Topic/CMFCDynamicLayout::SizeSettings%20Structure.md)valor que não representa a nenhuma alteração no tamanho de um controle filho.|  
|estático[CMFCDynamicLayout::SizeVertical](../Topic/CMFCDynamicLayout::SizeVertical.md)|Obtém uma[SizeSettings](../Topic/CMFCDynamicLayout::SizeSettings%20Structure.md)valor que define o nível de controle filho é redimensionado verticalmente quando o usuário redimensiona a janela de hospedagem.|  
  
## Tipos Aninhados  
  
|Nome|Descrição|  
|----------|---------------|  
|[Estrutura CMFCDynamicLayout::MoveSettings](../Topic/CMFCDynamicLayout::MoveSettings%20Structure.md)|Encapsula mover dados para controles em um layout dinâmico.|  
|[CMFCDynamicLayout::SizeSettings Structure](../Topic/CMFCDynamicLayout::SizeSettings%20Structure.md)|Encapsula os dados de alteração de tamanho para controles em um layout dinâmico.|  
  
## Comentários  
  
## Hierarquia de herança  
 [CObject](../Topic/CObject%20Class.md)  
  
 [CMFCDynamicLayout](../../mfc/reference/cmfctoolbarbutton-class.md)  
  
## Requisitos  
 **Cabeçalho:**afxlayout.h  
  
## Consulte também  
 [Gráfico da hierarquia](../../mfc/hierarchy-chart.md)   
 [Classes](../Topic/MFC%20Classes.md)