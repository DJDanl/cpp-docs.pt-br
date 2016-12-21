---
title: "Classe de CMouseManager | Microsoft Docs"
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
  - "CMouseManager"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Classe de CMouseManager"
ms.assetid: a4d05017-4e44-4a40-8b57-4ece0de20481
caps.latest.revision: 26
caps.handback.revision: 16
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Classe de CMouseManager
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Permite que um usuário associa os comandos diferentes com um objeto específico de [CView](../Topic/CView%20Class.md) quando o usuário clica duas vezes no interior que exibem.  
  
## Sintaxe  
  
```  
class CMouseManager : public CObject  
```  
  
## Membros  
  
### Métodos públicos  
  
|Nome|Descrição|  
|----------|---------------|  
|[CMouseManager::AddView](../Topic/CMouseManager::AddView.md)|Adiciona um objeto de `CView` a caixa de diálogo de **Personalização** .  A caixa de diálogo de **Personalização** permite que o usuário clique duas vezes em para associar a um comando para cada uma das visualizações listadas.|  
|[CMouseManager::GetViewDblClickCommand](../Topic/CMouseManager::GetViewDblClickCommand.md)|Retorna o comando que é executado quando o usuário clica duas vezes no interior a visualização fornecida.|  
|[CMouseManager::GetViewIconId](../Topic/CMouseManager::GetViewIconId.md)|Retorna o ícone associado com a identificação fornecida de exibição|  
|[CMouseManager::GetViewIdByName](../Topic/CMouseManager::GetViewIdByName.md)|Retorna a identificação de exibição associado com o nome fornecido de exibição.|  
|[CMouseManager::GetViewNames](../Topic/CMouseManager::GetViewNames.md)|Recupera uma lista de todos os nomes adicionais de exibição.|  
|[CMouseManager::LoadState](../Topic/CMouseManager::LoadState.md)|Carrega o estado de `CMouseManager` de Registro do Windows.|  
|[CMouseManager::SaveState](../Topic/CMouseManager::SaveState.md)|Grava o estado de `CMouseManager` ao Registro do Windows.|  
|[CMouseManager::SetCommandForDblClk](../Topic/CMouseManager::SetCommandForDblClk.md)|Associa o comando fornecido e a visualização fornecida.|  
  
## Comentários  
 A classe de `CMouseManager` mantém uma coleção de objetos de `CView` .  Cada exibição é identificado por um nome e uma identificação  Esses modos de exibição são mostradas na caixa de diálogo de **Personalização** .  O usuário pode alterar o comando que está associado com qualquer modo de exibição pela caixa de diálogo de **Personalização** .  O comando associado é executado quando o usuário clica duas vezes na exibição.  Para suportar isso de uma perspectiva de codificação, você deve processar a mensagem de `WM_LBUTTONDBLCLK` e chamar a função de [CWinAppEx::OnViewDoubleClick](../Topic/CWinAppEx::OnViewDoubleClick.md) no código para o objeto de `CView` .  
  
 Você não deve criar um objeto de `CMouseManager` manualmente.  Será criado pela estrutura do seu aplicativo.  Também será destruído automaticamente quando o usuário sai do aplicativo.  Para obter um ponteiro ao gerenciador do mouse para seu aplicativo, chame [CWinAppEx::GetMouseManager](../Topic/CWinAppEx::GetMouseManager.md).  
  
## Hierarquia de herança  
 [CObject](../Topic/CObject%20Class.md)  
  
 [CMouseManager](../../mfc/reference/cmousemanager-class.md)  
  
## Requisitos  
 **Cabeçalho:** afxmousemanager.h  
  
## Consulte também  
 [Gráfico da hierarquia](../../mfc/hierarchy-chart.md)   
 [Classes](../Topic/MFC%20Classes.md)   
 [Classe de CWinAppEx](../../mfc/reference/cwinappex-class.md)   
 [Personalização de teclado e mouse](../../mfc/keyboard-and-mouse-customization.md)