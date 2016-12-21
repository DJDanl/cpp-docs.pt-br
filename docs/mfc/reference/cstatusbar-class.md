---
title: "Classe de CStatusBar | Microsoft Docs"
ms.custom: ""
ms.date: "12/14/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "reference"
f1_keywords: 
  - "CStatusBar"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Classe de CStatusBar"
  - "indexadores"
  - "indexadores, barra de status"
  - "barras de status"
  - "indexadores de status"
ms.assetid: a3bde3db-e71c-4881-a3ca-1d5481c345ba
caps.latest.revision: 24
caps.handback.revision: 12
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Classe de CStatusBar
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Uma barra de controle com uma linha de painéis de saída de texto, ou indexadores de “”.  
  
## Sintaxe  
  
```  
class CStatusBar : public CControlBar  
```  
  
## Membros  
  
### Construtores public  
  
|Nome|Descrição|  
|----------|---------------|  
|[CStatusBar::CStatusBar](../Topic/CStatusBar::CStatusBar.md)|Constrói um objeto de `CStatusBar` .|  
  
### Métodos públicos  
  
|Nome|Descrição|  
|----------|---------------|  
|[CStatusBar::CommandToIndex](../Topic/CStatusBar::CommandToIndex.md)|Obtém o índice para uma determinada identificação do indexador|  
|[CStatusBar::Create](../Topic/CStatusBar::Create.md)|Cria a barra de status, anexá\-la ao objeto de `CStatusBar` , defina a altura inicial da fonte e da barra.|  
|[CStatusBar::CreateEx](../Topic/CStatusBar::CreateEx.md)|Cria um objeto de `CStatusBar` com os estilos adicionais para o objeto inserido de `CStatusBarCtrl` .|  
|[CStatusBar::DrawItem](../Topic/CStatusBar::DrawItem.md)|Chamado quando uma aparência visual de alterações de controle de barra de status do proprietário.|  
|[CStatusBar::GetItemID](../Topic/CStatusBar::GetItemID.md)|Obtém a identificação do indexador para um índice especificado.|  
|[CStatusBar::GetItemRect](../Topic/CStatusBar::GetItemRect.md)|Obtém o retângulo de exibição para um índice especificado.|  
|[CStatusBar::GetPaneInfo](../Topic/CStatusBar::GetPaneInfo.md)|Obtém a identificação, o estilo, e a largura do indexador para um índice especificado.|  
|[CStatusBar::GetPaneStyle](../Topic/CStatusBar::GetPaneStyle.md)|Obtém o estilo do indexador para um índice especificado.|  
|[CStatusBar::GetPaneText](../Topic/CStatusBar::GetPaneText.md)|Obtém o texto do indexador para um índice especificado.|  
|[CStatusBar::GetStatusBarCtrl](../Topic/CStatusBar::GetStatusBarCtrl.md)|Permite acesso direto ao controle comum subjacente.|  
|[CStatusBar::SetIndicators](../Topic/CStatusBar::SetIndicators.md)|Define IDs do indexador.|  
|[CStatusBar::SetPaneInfo](../Topic/CStatusBar::SetPaneInfo.md)|Define a identificação, o estilo, e a largura do indexador para um índice especificado.|  
|[CStatusBar::SetPaneStyle](../Topic/CStatusBar::SetPaneStyle.md)|Defina o estilo do indexador para um índice especificado.|  
|[CStatusBar::SetPaneText](../Topic/CStatusBar::SetPaneText.md)|Define o texto do indicador para um índice especificado.|  
  
## Comentários  
 Os painéis de saída são geralmente usados como linhas de mensagem e como indicadores de status.  Os exemplos incluem as linhas de ajuda mensagem de menu que explicam rapidamente o comando de menu selecionado e marcadores que mostram o status da CAPS de SCROLL LOCK, de EM UM LOCK, e outras teclas.  
  
 [CStatusBar::GetStatusBarCtrl](../Topic/CStatusBar::GetStatusBarCtrl.md), uma função de membro novo a MFC 4,0, permite que você aproveite de suporte comuns de controle do windows para personalização e funcionalidade adicional de barra de status.  As funções de membro de`CStatusBar` dão\-no mais da funcionalidade dos controles comuns do windows; no entanto, quando você chama `GetStatusBarCtrl`, você pode dar às barras de status ainda mais das características Windows 95 \/98 de barra de status.  Quando você chama `GetStatusBarCtrl`, retornará uma referência a um objeto de `CStatusBarCtrl` .  Consulte [CStatusBarCtrl](../../mfc/reference/cstatusbarctrl-class.md) para obter mais informações sobre como criar barras de ferramentas usando controles comuns.  Para obter informações mais gerais sobre controles comuns, consulte [Controles comuns](http://msdn.microsoft.com/library/windows/desktop/bb775493) em [!INCLUDE[winSDK](../../atl/includes/winsdk_md.md)].  
  
 A estrutura armazena informações do indexador em uma matriz com o indexador mais à esquerda na posição 0.  Quando você cria uma barra de status, você usa uma matriz de IDs de cadeia de caracteres que a estrutura associa com os indicadores correspondentes.  Você pode usar uma identificação de cadeia de caracteres ou um índice para acessar um indexador.  
  
 Por padrão, o primeiro indexador é extensível”: “ pega o comprimento da barra de status não usado pelos outros painéis do indexador, para que os outros painéis são alinhados à direita.  
  
 Para criar uma barra de status, siga estas etapas:  
  
1.  Construir o objeto de `CStatusBar` .  
  
2.  Chame a função de [Criar](../Topic/CStatusBar::Create.md) \(ou [CreateEx](../Topic/CStatusBar::CreateEx.md)\) para criar a janela de barra de status para e anexá\-la ao objeto de `CStatusBar` .  
  
3.  Chame [SetIndicators](../Topic/CStatusBar::SetIndicators.md) para associar uma identificação de cadeia de caracteres com cada indexador.  
  
 Existem três maneiras para atualizar o texto em um painel de barra de status:  
  
1.  Chamada [CWnd::SetWindowText](../Topic/CWnd::SetWindowText.md) para atualizar somente texto no painel 0.  
  
2.  Chamada [CCmdUI::SetText](../Topic/CCmdUI::SetText.md) no manipulador de `ON_UPDATE_COMMAND_UI` statusbar.  
  
3.  Chamada [SetPaneText](../Topic/CStatusBar::SetPaneText.md) para atualizar o texto para qualquer painel.  
  
 Chamada [SetPaneStyle](../Topic/CStatusBar::SetPaneStyle.md) para atualizar o estilo de um painel de barra de status.  
  
 Para obter mais informações sobre como usar `CStatusBar`, consulte o artigo [Implementação de barra de status no MFC](../../mfc/status-bar-implementation-in-mfc.md) e [Observe técnica 31: barras de controle](../../mfc/tn031-control-bars.md).  
  
## Hierarquia de herança  
 [CObject](../Topic/CObject%20Class.md)  
  
 [CCmdTarget](../Topic/CCmdTarget%20Class.md)  
  
 [CWnd](../Topic/CWnd%20Class.md)  
  
 [CControlBar](../../mfc/reference/ccontrolbar-class.md)  
  
 `CStatusBar`  
  
## Requisitos  
 **Cabeçalho:** afxext.h  
  
## Consulte também  
 [O MFC exemplos CTRLBARS](../../top/visual-cpp-samples.md)   
 [Exemplo DLGCBR32 MFC](../../top/visual-cpp-samples.md)   
 [Classe de CControlBar](../../mfc/reference/ccontrolbar-class.md)   
 [Gráfico da hierarquia](../../mfc/hierarchy-chart.md)   
 [Classe de CStatusBarCtrl](../../mfc/reference/cstatusbarctrl-class.md)   
 [Classe de CControlBar](../../mfc/reference/ccontrolbar-class.md)   
 [CWnd::SetWindowText](../Topic/CWnd::SetWindowText.md)   
 [CStatusBar::SetIndicators](../Topic/CStatusBar::SetIndicators.md)