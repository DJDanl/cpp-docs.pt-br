---
title: "Classe de CDockState | Microsoft Docs"
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
  - "CDockState"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Classe de CDockState"
  - "estado de encaixe"
  - "barras de controle de encaixe"
  - "inserindo janelas de ferramenta"
  - "posição, barra de controle"
  - "tamanho"
  - "tamanho, barra de controle"
  - "estados, barra de controle encaixável"
ms.assetid: 09e7c10b-3abd-4cb2-ad36-42420fe6bc36
caps.latest.revision: 23
caps.handback.revision: 12
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Classe de CDockState
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Uma classe serializada de `CObject` que carrega, descarrega, ou desmarca o estado de uma ou mais barras de controle de encaixe na memória persistente \(um arquivo\).  
  
## Sintaxe  
  
```  
class CDockState : public CObject  
```  
  
## Membros  
  
### Métodos públicos  
  
|Nome|Descrição|  
|----------|---------------|  
|[CDockState::Clear](../Topic/CDockState::Clear.md)|Limpa informações do estado da plataforma.|  
|[CDockState::GetVersion](../Topic/CDockState::GetVersion.md)|Retorna o número de versão armazenado de estado da barra.|  
|[CDockState::LoadState](../Topic/CDockState::LoadState.md)|Recupera informações do estado do Registro ou do arquivo .ini.|  
|[CDockState::SaveState](../Topic/CDockState::SaveState.md)|Salva informações de estado para o Registro ou arquivo de INI.|  
  
### Membros públicos de dados  
  
|Nome|Descrição|  
|----------|---------------|  
|[CDockState::m\_arrBarInfo](../Topic/CDockState::m_arrBarInfo.md)|Matriz de ponteiros para informações de estado armazenada dock com uma entrada para cada barra de controle.|  
  
## Comentários  
 O estado da plataforma inclui o tamanho e a posição da barra e se está entrada.  Para recuperar o estado armazenado dock, `CDockState` verifica a posição e, se a barra não estiver visível com as configurações atuais da tela, `CDockState` de barra tanto a posição da barra de modo que é visível.  O objetivo principal de `CDockState` é armazenar o estado de um número inteiro de barras de controle e permitir que o estado salvo e é carregado no Registro, o arquivo .ini do aplicativo, ou no formato binário como parte do conteúdo de um objeto de `CArchive` .  
  
 A barra pode ser qualquer controle barra de encaixável, incluindo uma barra de ferramentas, uma barra de status, ou uma barra da caixa de diálogo.  Os objetos de`CDockState` são escritos e a leitura ou um arquivo através de um objeto de `CArchive` .  
  
 [CFrameWnd::GetDockState](../Topic/CFrameWnd::GetDockState.md) recupera informações do estado de `CControlBar` de qualquer janela de quadro objeta\-o e colocar\-l no objeto de `CDockState` .  Você pode escrever o conteúdo do objeto de `CDockState` ao armazenamento com [Serialize](../Topic/CObject::Serialize.md) ou [CDockState::SaveState](../Topic/CDockState::SaveState.md).  Se você deseja posteriormente para restaurar o estado das barras de controle na janela do quadro, você pode carregar o estado com `Serialize` ou [CDockState::LoadState](../Topic/CDockState::LoadState.md), então usa [CFrameWnd::SetDockState](../Topic/CFrameWnd::SetDockState.md) para aplicar o estado salvo às barras de controle window do quadro.  
  
 Para obter mais informações sobre como inserir barras de controle, consulte os artigos [barras de controle](../Topic/Control%20Bars.md), [Barras de ferramentas: Encaixe e flutuantes](../../mfc/docking-and-floating-toolbars.md), e [Quadro do windows](../../mfc/frame-windows.md).  
  
## Hierarquia de herança  
 [CObject](../Topic/CObject%20Class.md)  
  
 `CDockState`  
  
## Requisitos  
 **Cabeçalho:** afxadv.h  
  
## Consulte também  
 [Classe de CObject](../Topic/CObject%20Class.md)   
 [Gráfico da hierarquia](../../mfc/hierarchy-chart.md)