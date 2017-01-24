---
title: "Classe de CMFCBaseVisualManager | Microsoft Docs"
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
  - "CMFCBaseVisualManager"
  - "CMFCBaseVisualManager.~CMFCBaseVisualManager"
  - "~CMFCBaseVisualManager"
  - "CMFCBaseVisualManager::~CMFCBaseVisualManager"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Destruidor de ~CMFCBaseVisualManager"
  - "Classe de CMFCBaseVisualManager"
  - "Classe de CMFCBaseVisualManager, destruidor"
ms.assetid: d56f3afc-cdea-4de1-825a-a08999c571e0
caps.latest.revision: 24
caps.handback.revision: 12
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Classe de CMFCBaseVisualManager
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Uma camada entre gerentes visuais derivados e o tema a API do windows.  
  
 `CMFCBaseVisualManager` carrega UxTheme.dll, se disponível, e gerencia o acesso a métodos API de tema do windows.  
  
 Essa classe é somente para uso interno.  
  
## Sintaxe  
  
```  
class CMFCBaseVisualManager: public CObject  
```  
  
## Membros  
  
### Construtores public  
  
|||  
|-|-|  
|Nome|Descrição|  
|[CMFCBaseVisualManager::CMFCBaseVisualManager](../Topic/CMFCBaseVisualManager::CMFCBaseVisualManager.md)|As compilações e inicializam um objeto de `CMFCBaseVisualManager` .|  
|`CMFCBaseVisualManager::~CMFCBaseVisualManager`|Destruidor.|  
  
### Métodos públicos  
  
|||  
|-|-|  
|Nome|Descrição|  
|[CMFCBaseVisualManager::DrawCheckBox](../Topic/CMFCBaseVisualManager::DrawCheckBox.md)|Desenha um controle de caixa de seleção usando o tema atual do windows.|  
|[CMFCBaseVisualManager::DrawComboBorder](../Topic/CMFCBaseVisualManager::DrawComboBorder.md)|Desenha uma borda da caixa de combinação usando o tema atual do windows.|  
|[CMFCBaseVisualManager::DrawComboDropButton](../Topic/CMFCBaseVisualManager::DrawComboDropButton.md)|Desenha um botão suspenso da caixa de combinação usando o tema atual do windows.|  
|[CMFCBaseVisualManager::DrawPushButton](../Topic/CMFCBaseVisualManager::DrawPushButton.md)|Desenha um botão de ação usando o tema atual do windows.|  
|[CMFCBaseVisualManager::DrawRadioButton](../Topic/CMFCBaseVisualManager::DrawRadioButton.md)|Desenha um controle de botão de opção usando o tema atual do windows.|  
|[CMFCBaseVisualManager::DrawStatusBarProgress](../Topic/CMFCBaseVisualManager::DrawStatusBarProgress.md)|Desenha uma barra de progresso em um controle de barra de status \([Classe de CMFCStatusBar](../../mfc/reference/cmfcstatusbar-class.md)\) que usa o tema atual do windows.|  
|[CMFCBaseVisualManager::FillReBarPane](../Topic/CMFCBaseVisualManager::FillReBarPane.md)|Preenche o plano de fundo do controle rebar usando o tema atual do windows.|  
|[CMFCBaseVisualManager::GetStandardWindowsTheme](../Topic/CMFCBaseVisualManager::GetStandardWindowsTheme.md)|Obtém o tema atual do windows.|  
  
### Métodos protegidos  
  
|||  
|-|-|  
|Nome|Descrição|  
|[CMFCBaseVisualManager::CleanUpThemes](../Topic/CMFCBaseVisualManager::CleanUpThemes.md)|Chama `CloseThemeData` para todas as alças obtidas em `UpdateSystemColors`.|  
|[CMFCBaseVisualManager::UpdateSystemColors](../Topic/CMFCBaseVisualManager::UpdateSystemColors.md)|Chamadas `OpenThemeData` para obter as alças para desenhar vários controles: o windows, barras de ferramentas, botões, e assim por diante.|  
  
## Comentários  
 Você não precisa instanciar objetos diretamente de essa classe.  
  
 Porque é uma classe base para todos os gerentes visuais, você pode chamar apenas [CMFCVisualManager::GetInstance](../Topic/CMFCVisualManager::GetInstance.md), obtém um ponteiro para o gerenciador visual atual, e acessa os métodos para `CMFCBaseVisualManager` usando esse ponteiro.  Em o entanto, se você tiver que exibir um controle usando o tema atual do windows, é melhor usar a interface de `CMFCVisualManagerWindows` .  
  
## Hierarquia de herança  
 [CObject](../Topic/CObject%20Class.md)  
  
 [CMFCBaseVisualManager](../../mfc/reference/cmfcbasevisualmanager-class.md)  
  
## Requisitos  
 **Cabeçalho:** afxvisualmanager.h  
  
## Consulte também  
 [Gráfico da hierarquia](../../mfc/hierarchy-chart.md)   
 [Classes](../Topic/MFC%20Classes.md)