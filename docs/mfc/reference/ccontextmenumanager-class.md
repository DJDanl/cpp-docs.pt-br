---
title: "Classe de CContextMenuManager | Microsoft Docs"
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
  - "CContextMenuManager"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Classe de CContextMenuManager"
ms.assetid: 1de20640-243c-47e1-85de-1baa4153bc83
caps.latest.revision: 32
caps.handback.revision: 21
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Classe de CContextMenuManager
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

O objeto de `CContextMenuManager` gerencia o menu de atalho, também conhecido como menus de contexto.  
  
## Sintaxe  
  
```  
class CContextMenuManager : public CObject  
```  
  
## Membros  
  
### Construtores public  
  
|Nome|Descrição|  
|----------|---------------|  
|[CContextMenuManager::CContextMenuManager](../Topic/CContextMenuManager::CContextMenuManager.md)|Constrói um objeto de `CContextMenuManager` .|  
|`CContextMenuManager::~CContextMenuManager`|Destruidor.|  
  
### Métodos públicos  
  
|Nome|Descrição|  
|----------|---------------|  
|[CContextMenuManager::AddMenu](../Topic/CContextMenuManager::AddMenu.md)|Adiciona um novo menu de atalho.|  
|[CContextMenuManager::GetMenuById](../Topic/CContextMenuManager::GetMenuById.md)|Retorna um identificador para o menu associado com a identificação fornecida de recurso|  
|[CContextMenuManager::GetMenuByName](../Topic/CContextMenuManager::GetMenuByName.md)|Retorna um identificador para o menu que corresponde ao nome de menu fornecido.|  
|[CContextMenuManager::GetMenuNames](../Topic/CContextMenuManager::GetMenuNames.md)|Retorna uma lista de nomes de menu.|  
|[CContextMenuManager::LoadState](../Topic/CContextMenuManager::LoadState.md)|Carrega os menus de atalho armazenados no Registro do Windows.|  
|[CContextMenuManager::ResetState](../Topic/CContextMenuManager::ResetState.md)|Limpa o menu de atalho do gerenciador de menu de contexto.|  
|[CContextMenuManager::SaveState](../Topic/CContextMenuManager::SaveState.md)|Salva menu de atalho do Registro do Windows.|  
|[CContextMenuManager::SetDontCloseActiveMenu](../Topic/CContextMenuManager::SetDontCloseActiveMenu.md)|Controles se `CContextMenuManager` fecha o menu de atalho ativa quando mostrar um novo menu de atalho.|  
|[CContextMenuManager::ShowPopupMenu](../Topic/CContextMenuManager::ShowPopupMenu.md)|Exibe o menu de atalho especificado.|  
|[CContextMenuManager::TrackPopupMenu](../Topic/CContextMenuManager::TrackPopupMenu.md)|Exibe o menu de atalho especificado.  Retorna o índice de comando de menu selecionado.|  
  
## Comentários  
 `CContextMenuManager` gerencia menu de atalho e certifique\-se que têm uma aparência consistente.  
  
 Você não deve criar um objeto de `CContextMenuManager` manualmente.  A estrutura do seu aplicativo cria o objeto de `CContextMenuManager` .  Em o entanto, você deve chamar [CWinAppEx::InitContextMenuManager](../Topic/CWinAppEx::InitContextMenuManager.md) quando seu aplicativo é inicializado.  Após inicializado o gerenciador de contexto, use o método [CWinAppEx::GetContextMenuManager](../Topic/CWinAppEx::GetContextMenuManager.md) para obter um ponteiro ao gerenciador de contexto para seu aplicativo.  
  
 Você pode criar menus de atalho em tempo de execução chamando `AddMenu`.  Se você quiser mostrar o menu sem primeira entrada do usuário de recepção, chame `ShowPopupMenu`.  `TrackPopupMenu` é usado quando você desejar criar um menu e uma espera para entrada do usuário.  `TrackPopupMenu` retorna o índice de comando ou de 0 selecionado se o usuário foi encerrado sem selecionar qualquer coisa.  
  
 `CContextMenuManager` também pode salvar e carregar o estado para o Registro do Windows.  
  
## Exemplo  
 O exemplo a seguir demonstra como adicionar um menu para um objeto de `CContextMenuManager` , e não como fechar o menu pop\-up ativa quando o objeto de `CContextMenuManager` exibe um novo menu pop\-up.  Este trecho de código é parte de [Custom de páginas](../../top/visual-cpp-samples.md).  
  
 [!code-cpp[NVC_MFC_CustomPages#4](../../mfc/reference/codesnippet/CPP/ccontextmenumanager-class_1.cpp)]  
  
## Hierarquia de herança  
 [CObject](../Topic/CObject%20Class.md)  
  
 [CContextMenuManager](../../mfc/reference/ccontextmenumanager-class.md)  
  
## Requisitos  
 **Cabeçalho:** afxcontextmenumanager.h  
  
## Consulte também  
 [Gráfico da hierarquia](../../mfc/hierarchy-chart.md)   
 [Classes](../Topic/MFC%20Classes.md)   
 [Classe de CWinAppEx](../../mfc/reference/cwinappex-class.md)   
 [CWinAppEx::InitContextMenuManager](../Topic/CWinAppEx::InitContextMenuManager.md)