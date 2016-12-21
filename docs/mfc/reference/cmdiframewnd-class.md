---
title: "Classe de CMDIFrameWnd | Microsoft Docs"
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
  - "CMDIFrameWnd"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Classe de CMDIFrameWnd"
  - "Janelas de quadro MDI"
ms.assetid: fa8736e6-511b-4c51-8b4d-eba78378aeb9
caps.latest.revision: 22
caps.handback.revision: 11
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Classe de CMDIFrameWnd
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Fornece a funcionalidade de uma janela de quadro de \(MDI\) de interface de documentos múltiplos do windows, juntamente com membros para gerenciar a janela.  
  
## Sintaxe  
  
```  
class CMDIFrameWnd : public CFrameWnd  
```  
  
## Membros  
  
### Construtores public  
  
|Nome|Descrição|  
|----------|---------------|  
|[CMDIFrameWnd::CMDIFrameWnd](../Topic/CMDIFrameWnd::CMDIFrameWnd.md)|Constrói `CMDIFrameWnd`.|  
  
### Métodos públicos  
  
|Nome|Descrição|  
|----------|---------------|  
|[CMDIFrameWnd::CreateClient](../Topic/CMDIFrameWnd::CreateClient.md)|Cria uma janela de **MDICLIENT** do windows para este `CMDIFrameWnd`.  Chamado pela função de membro de `OnCreate` de `CWnd`.|  
|[CMDIFrameWnd::CreateNewChild](../Topic/CMDIFrameWnd::CreateNewChild.md)|Cria uma nova janela filho.|  
|[CMDIFrameWnd::GetWindowMenuPopup](../Topic/CMDIFrameWnd::GetWindowMenuPopup.md)|Retorna o menu pop\-up da janela.|  
|[CMDIFrameWnd::MDIActivate](../Topic/CMDIFrameWnd::MDIActivate.md)|Alterna uma janela filho MDI diferente.|  
|[CMDIFrameWnd::MDICascade](../Topic/CMDIFrameWnd::MDICascade.md)|Organiza todas as janelas filho em um formato conectado.|  
|[CMDIFrameWnd::MDIGetActive](../Topic/CMDIFrameWnd::MDIGetActive.md)|Recupera a janela filho MDI ativa no momento, junto com um sinalizador indicando se o filho é maximizada.|  
|[CMDIFrameWnd::MDIIconArrange](../Topic/CMDIFrameWnd::MDIIconArrange.md)|Organiza todas as janelas filho minimizadas do documento.|  
|[CMDIFrameWnd::MDIMaximize](../Topic/CMDIFrameWnd::MDIMaximize.md)|Maximize uma janela filho MDI.|  
|[CMDIFrameWnd::MDINext](../Topic/CMDIFrameWnd::MDINext.md)|Alterna a janela filho imediatamente por trás de janela filho ativa no momento e coloca a janela filho ativa no arquivo code\-behind de quaisquer outras janelas filho.|  
|[CMDIFrameWnd::MDIPrev](../Topic/CMDIFrameWnd::MDIPrev.md)|Alterna a janela filho anterior e coloca a janela filho ativa no momento imediatamente por detrás.|  
|[CMDIFrameWnd::MDIRestore](../Topic/CMDIFrameWnd::MDIRestore.md)|Restaura uma janela filho MDI de tamanho maximizado ou minimizado.|  
|[CMDIFrameWnd::MDISetMenu](../Topic/CMDIFrameWnd::MDISetMenu.md)|Substituir o menu de uma janela de quadro MDI, no menu de janela pop\-up, ou ambos.|  
|[CMDIFrameWnd::MDITile](../Topic/CMDIFrameWnd::MDITile.md)|Organiza todas as janelas filho em um formato lado.|  
  
## Comentários  
 Para criar uma janela útil do quadro MDI para seu aplicativo, derive uma classe de `CMDIFrameWnd`.  Adicione variáveis de membros para a classe derivada para específico de armazenamento de dados ao seu aplicativo.  Implementar funções de membro de mensagem\- manipulador e um mapa de mensagem na classe derivada para especificar o que acontece quando as mensagens são todas direcionados para a janela.  
  
 Você pode construir uma janela de quadro MDI chamar a função de membro de [Criar](../Topic/CFrameWnd::Create.md) ou de [LoadFrame](../Topic/CFrameWnd::LoadFrame.md) de `CFrameWnd`.  
  
 Antes de você chamar **Criar** ou `LoadFrame`, você deve criar o objeto da janela do quadro usando o operador no heap C\+\+ **new** .  Antes que chamar\-lhe **Criar** também pode registrar uma classe de janela com a função global de [AfxRegisterWndClass](../Topic/AfxRegisterWndClass.md) para definir estilos de ícone e da classe para o quadro.  
  
 Use a função de membro de **Criar** para passar parâmetros de criação do quadro como argumentos imediatos.  
  
 `LoadFrame` requer menos argumentos de **Criar**, e recupera o invés da maioria dos valores padrão de recursos, incluindo a legenda do quadro, o ícone, a tabela de aceleração, e o menu.  Para ser acessado por `LoadFrame`, todos esses recursos devem ter o mesmo número de identificação de recurso \(por exemplo, **IDR\_MAINFRAME**\).  
  
 Embora **MDIFrameWnd** é derivado de `CFrameWnd`, uma classe de janela do quadro derivado de `CMDIFrameWnd` não precisa ser declarada com `DECLARE_DYNCREATE`.  
  
 A classe herda de `CMDIFrameWnd` grande parte da sua implementação padrão de `CFrameWnd`.  Para uma lista detalhada de esses recursos, consulte a descrição da classe de [CFrameWnd](../../mfc/reference/cframewnd-class.md) .  A classe de `CMDIFrameWnd` possui os seguintes recursos adicionais:  
  
-   Uma janela de quadro MDI gerencia a janela de **MDICLIENT** , reposicionando o em conjunto com barras de controle.  A janela de cliente é o pai MDI direto de janelas filho MDI do quadro.  Os estilos de janela de **WS\_HSCROLL** e de **WS\_VSCROLL** especificados em `CMDIFrameWnd` se aplicam a janela de cliente MDI em vez da janela de quadro chave assim que o usuário pode rolar para a área cliente MDI \(como no gerenciador de programa do windows, por exemplo\).  
  
-   Uma janela de quadro MDI possui um menu padrão que é usado como a barra de menus quando não há nenhuma janela filho MDI ativa.  Quando há um filho MDI ativa, a barra de menus da janela do quadro MDI é substituída automaticamente pelo menu de janela filho MDI.  
  
-   Uma janela de quadro MDI funciona em conjunto com a janela filho MDI atual, se houver.  Por exemplo, as mensagens de comando são delegadas ao filho MDI ativa no momento antes da janela do quadro MDI.  
  
-   Uma janela de quadro MDI tem manipuladores padrão para os seguintes comandos de menu padrão da janela:  
  
    -   **ID\_WINDOW\_TILE\_VERT**  
  
    -   **ID\_WINDOW\_TILE\_HORZ**  
  
    -   **ID\_WINDOW\_CASCADE**  
  
    -   **ID\_WINDOW\_ARRANGE**  
  
-   Uma janela de quadro MDI também tem uma implementação de **ID\_WINDOW\_NEW**, que cria um novo quadro e exibição no documento atual.  Um aplicativo pode substituir essas implementações padrão de comando para personalizar a manipulação de janela MDI.  
  
 Não use o operador C\+\+ **delete** para destruir uma janela do quadro.  Use `CWnd::DestroyWindow` em vez de isso.  A implementação de `CFrameWnd` de `PostNcDestroy` excluirá o objeto C\+\+ quando a janela é destruída.  Quando o usuário fecha a janela do quadro, o manipulador padrão de `OnClose` chamará `DestroyWindow`.  
  
 Para obter mais informações sobre `CMDIFrameWnd`, consulte [Quadro do windows](../../mfc/frame-windows.md).  
  
## Hierarquia de herança  
 [CObject](../Topic/CObject%20Class.md)  
  
 [CCmdTarget](../Topic/CCmdTarget%20Class.md)  
  
 [CWnd](../Topic/CWnd%20Class.md)  
  
 [CFrameWnd](../../mfc/reference/cframewnd-class.md)  
  
 `CMDIFrameWnd`  
  
## Requisitos  
 **Cabeçalho:** afxwin.h  
  
## Consulte também  
 [O MFC prova MDI](../../top/visual-cpp-samples.md)   
 [Exemplo MDIDOCVW MFC](../../top/visual-cpp-samples.md)   
 [Exemplo SNAPVW MFC](../../top/visual-cpp-samples.md)   
 [Classe de CFrameWnd](../../mfc/reference/cframewnd-class.md)   
 [Gráfico da hierarquia](../../mfc/hierarchy-chart.md)   
 [CWnd Class](../Topic/CWnd%20Class.md)   
 [Classe de CMDIChildWnd](../../mfc/reference/cmdichildwnd-class.md)