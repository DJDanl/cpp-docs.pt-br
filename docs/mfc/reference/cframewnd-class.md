---
title: "Classe de CFrameWnd | Microsoft Docs"
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
  - "CFrameWnd"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Classe de CFrameWnd"
  - "classes da janela de quadro chave, classe base"
  - "quadro do windows, criando"
  - "interface (SDI) do documento único, quadro do windows"
ms.assetid: e2220aba-5bf4-4002-b960-fbcafcad01f1
caps.latest.revision: 21
caps.handback.revision: 9
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Classe de CFrameWnd
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Fornece a funcionalidade de uma interface janela pop\-up ou sobrepostos de \(SDI\) do único documento do windows do quadro, juntamente com membros para gerenciar a janela.  
  
## Sintaxe  
  
```  
class CFrameWnd : public CWnd  
```  
  
## Membros  
  
### Construtores public  
  
|Nome|Descrição|  
|----------|---------------|  
|[CFrameWnd::CFrameWnd](../Topic/CFrameWnd::CFrameWnd.md)|Constrói um objeto de `CFrameWnd` .|  
  
### Métodos públicos  
  
|Nome|Descrição|  
|----------|---------------|  
|[CFrameWnd::ActivateFrame](../Topic/CFrameWnd::ActivateFrame.md)|Torna o quadro visível e disponível para o usuário.|  
|[CFrameWnd::BeginModalState](../Topic/CFrameWnd::BeginModalState.md)|Define a janela do quadro a janela restrita.|  
|[CFrameWnd::Create](../Topic/CFrameWnd::Create.md)|Chame para criar e inicializar a janela do quadro do windows associada com o objeto de `CFrameWnd` .|  
|[CFrameWnd::CreateView](../Topic/CFrameWnd::CreateView.md)|Criar um modo de exibição em um quadro que não é derivado de `CView`.|  
|[CFrameWnd::DockControlBar](../Topic/CFrameWnd::DockControlBar.md)|Insere uma barra de controle.|  
|[CFrameWnd::EnableDocking](../Topic/CFrameWnd::EnableDocking.md)|Permite que uma barra de controle é entrada.|  
|[CFrameWnd::EndModalState](../Topic/CFrameWnd::EndModalState.md)|Encerra o estado modal da janela do quadro.  Permite que todas as janelas desativadas por `BeginModalState`.|  
|[CFrameWnd::FloatControlBar](../Topic/CFrameWnd::FloatControlBar.md)|Flutua uma barra de controle.|  
|[CFrameWnd::GetActiveDocument](../Topic/CFrameWnd::GetActiveDocument.md)|Retorna o objeto de **CDocument** ativo.|  
|[CFrameWnd::GetActiveFrame](../Topic/CFrameWnd::GetActiveFrame.md)|Retorna o objeto de `CFrameWnd` ativo.|  
|[CFrameWnd::GetActiveView](../Topic/CFrameWnd::GetActiveView.md)|Retorna o objeto de `CView` ativo.|  
|[CFrameWnd::GetControlBar](../Topic/CFrameWnd::GetControlBar.md)|Recupera a barra de controle.|  
|[CFrameWnd::GetDockState](../Topic/CFrameWnd::GetDockState.md)|Recupera o estado da plataforma de uma janela do quadro.|  
|[CFrameWnd::GetMenuBarState](../Topic/CFrameWnd::GetMenuBarState.md)|Recupera o estado de exibição do menu no aplicativo MFC do atual.|  
|[CFrameWnd::GetMenuBarVisibility](../Topic/CFrameWnd::GetMenuBarVisibility.md)|Indica se o comportamento padrão do menu no aplicativo MFC do atual está oculto ou visível.|  
|[CFrameWnd::GetMessageBar](../Topic/CFrameWnd::GetMessageBar.md)|Retorna um ponteiro para a barra de status que pertence à janela do quadro.|  
|[CFrameWnd::GetMessageString](../Topic/CFrameWnd::GetMessageString.md)|Recupera a mensagem correspondente a uma identificação de comando|  
|[CFrameWnd::GetTitle](../Topic/CFrameWnd::GetTitle.md)|Recupera o controle de barra de título relacionada.|  
|[CFrameWnd::InitialUpdateFrame](../Topic/CFrameWnd::InitialUpdateFrame.md)|Faz com que a função de membro de `OnInitialUpdate` que pertence a todas as visualizações na janela do quadro a ser chamada.|  
|[CFrameWnd::InModalState](../Topic/CFrameWnd::InModalState.md)|Retorna um valor indicando se uma janela de quadro chave está em um estado modal.|  
|[CFrameWnd::IsTracking](../Topic/CFrameWnd::IsTracking.md)|Determina se a barra separator está sendo movida atualmente.|  
|[CFrameWnd::LoadAccelTable](../Topic/CFrameWnd::LoadAccelTable.md)|Chame para carregar uma tabela de aceleração.|  
|[CFrameWnd::LoadBarState](../Topic/CFrameWnd::LoadBarState.md)|Chame para restaurar configurações da barra de controle.|  
|[CFrameWnd::LoadFrame](../Topic/CFrameWnd::LoadFrame.md)|Chame para criar dinamicamente uma janela de quadro de informações de recurso.|  
|[CFrameWnd::NegotiateBorderSpace](../Topic/CFrameWnd::NegotiateBorderSpace.md)|Negocia o espaço da borda na janela do quadro.|  
|[CFrameWnd::OnBarCheck](../Topic/CFrameWnd::OnBarCheck.md)|Chamado sempre que uma ação é executada na barra de controle especificada.|  
|[CFrameWnd::OnContextHelp](../Topic/CFrameWnd::OnContextHelp.md)|Ajuda handles SHIFT\+F1 para itens no lugar.|  
|[CFrameWnd::OnSetPreviewMode](../Topic/CFrameWnd::OnSetPreviewMode.md)|Define a janela de quadro chave do aplicativo e fora do modo de visualização de impressão.|  
|[CFrameWnd::OnUpdateControlBarMenu](../Topic/CFrameWnd::OnUpdateControlBarMenu.md)|Chamado pela estrutura quando o menu associado é atualizado.|  
|[CFrameWnd::RecalcLayout](../Topic/CFrameWnd::RecalcLayout.md)|Reposiciona barras de controle do objeto de `CFrameWnd` .|  
|[CFrameWnd::SaveBarState](../Topic/CFrameWnd::SaveBarState.md)|Chamada para salvar as configurações da barra de controle.|  
|[CFrameWnd::SetActivePreviewView](../Topic/CFrameWnd::SetActivePreviewView.md)|Designa a exibição especificado para ser o modo ativo para a visualização rico.|  
|[CFrameWnd::SetActiveView](../Topic/CFrameWnd::SetActiveView.md)|Defina o objeto ativa de `CView` .|  
|[CFrameWnd::SetDockState](../Topic/CFrameWnd::SetDockState.md)|Chame para encaixar a janela de quadro chave na janela.|  
|[CFrameWnd::SetMenuBarState](../Topic/CFrameWnd::SetMenuBarState.md)|Define o estado de exibição do menu no aplicativo MFC do atual a oculto ou exibido.|  
|[CFrameWnd::SetMenuBarVisibility](../Topic/CFrameWnd::SetMenuBarVisibility.md)|Define o comportamento padrão do menu no aplicativo MFC do atual estar ocultos ou visível.|  
|[CFrameWnd::SetMessageText](../Topic/CFrameWnd::SetMessageText.md)|Define o texto de uma barra de status padrão.|  
|[CFrameWnd::SetProgressBarPosition](../Topic/CFrameWnd::SetProgressBarPosition.md)|Define a posição atual para a barra de progresso Windows 7 exibida na barra de tarefas.|  
|[CFrameWnd::SetProgressBarRange](../Topic/CFrameWnd::SetProgressBarRange.md)|Os conjuntos variam para a barra de progresso Windows 7 exibida na barra de tarefas.|  
|[CFrameWnd::SetProgressBarState](../Topic/CFrameWnd::SetProgressBarState.md)|Define o tipo e o estado do indexador de progresso exibido em um botão da barra de tarefas.|  
|[CFrameWnd::SetTaskbarOverlayIcon](../Topic/CFrameWnd::SetTaskbarOverlayIcon.md)|Sobrecarregado.  Aplica uma sobreposição a um botão da barra de tarefas para indicar o status do aplicativo ou uma notificação para o usuário.|  
|[CFrameWnd::SetTitle](../Topic/CFrameWnd::SetTitle.md)|Define o título da barra de controle relacionada.|  
|[CFrameWnd::ShowControlBar](../Topic/CFrameWnd::ShowControlBar.md)|Chame para mostrar a barra de controle.|  
|[CFrameWnd::ShowOwnedWindows](../Topic/CFrameWnd::ShowOwnedWindows.md)|Mostra todas as janelas que são descendentes do objeto de `CFrameWnd` .|  
  
### Métodos protegidos  
  
|Nome|Descrição|  
|----------|---------------|  
|[CFrameWnd::OnCreateClient](../Topic/CFrameWnd::OnCreateClient.md)|Cria uma janela de cliente para o quadro.|  
|[CFrameWnd::OnHideMenuBar](../Topic/CFrameWnd::OnHideMenuBar.md)|Chamado antes do menu no aplicativo MFC do atual está oculto.|  
|[CFrameWnd::OnShowMenuBar](../Topic/CFrameWnd::OnShowMenuBar.md)|Chamado antes do menu no aplicativo MFC do atual é exibido.|  
  
### Membros públicos de dados  
  
|Nome|Descrição|  
|----------|---------------|  
|[CFrameWnd::m\_bAutoMenuEnable](../Topic/CFrameWnd::m_bAutoMenuEnable.md)|O automática de controles ativar e desativar a funcionalidade para itens de menu.|  
|[CFrameWnd::rectDefault](../Topic/CFrameWnd::rectDefault.md)|Passar este `CRect` estático como um parâmetro ao criar um objeto de `CFrameWnd` para permitir que o windows escolham o tamanho inicial e a posição da janela.|  
  
## Comentários  
 Para criar uma janela útil do quadro para seu aplicativo, derive uma classe de `CFrameWnd`.  Adicione variáveis de membros para a classe derivada para específico de armazenamento de dados ao seu aplicativo.  Implementar funções de membro de mensagem\- manipulador e um mapa de mensagem na classe derivada para especificar o que acontece quando as mensagens são todas direcionados para a janela.  
  
 Existem três maneiras para construir uma janela de quadro:  
  
-   Construir\-la diretamente usando [Criar](../Topic/CFrameWnd::Create.md).  
  
-   Construir\-lo diretamente usando [LoadFrame](../Topic/CFrameWnd::LoadFrame.md).  
  
-   Construir\-lo indiretamente usando um modelo do documento.  
  
 Antes de você chamar **Criar** ou `LoadFrame`, você deve criar o objeto de quadro\- janela na heap usando o operador de **new** C\+\+.  Antes de chamar **Criar**, você também pode registrar uma classe de janela com a função global de [AfxRegisterWndClass](../Topic/AfxRegisterWndClass.md) para definir estilos de ícone e da classe para o quadro.  
  
 Use a função de membro de **Criar** para passar parâmetros de criação do quadro como argumentos imediatos.  
  
 `LoadFrame` requer menos argumentos de **Criar**, e recupera o invés da maioria dos valores padrão de recursos, incluindo a legenda do quadro, o ícone, a tabela de aceleração, e o menu.  Para ser acessíveis por `LoadFrame`, todos esses recursos devem ter o mesmo número de identificação de recurso \(por exemplo, **IDR\_MAINFRAME**\).  
  
 Quando um objeto de `CFrameWnd` contém visões e documentos, eles são criados indiretamente pela estrutura em vez de diretamente pelo programador.  O objeto de `CDocTemplate` orquestra a criação de quadro chave, a criação de modos de exibição continente, e a conexão de modos de exibição ao documento apropriado.  Os parâmetros do construtor de `CDocTemplate` especificam `CRuntimeClass` das três classes envolvidas \(documento, quadro, e exibição\).  Um objeto de `CRuntimeClass` é usado pela estrutura para criar dinamicamente quando novos quadros especificado pelo usuário \(por exemplo, usando o comando novo Arquivo de comando ou da janela de \(MDI\) de interface de documentos múltiplos o novo\).  
  
 Uma classe derivada de quadro\- janela de `CFrameWnd` deve ser declarada com `DECLARE_DYNCREATE` para que o mecanismo de `RUNTIME_CLASS` anterior funcione corretamente.  
  
 `CFrameWnd` contém implementações padrão para executar as seguintes funções de uma janela principal em um aplicativo típico do windows:  
  
-   Uma janela do quadro de `CFrameWnd` mantém registro de uma exibição ativa no momento que é independente da janela ativa do windows atual ou de foco de entrada.  Quando o quadro reactivated, a exibição está ativa notificada chamando `CView::OnActivateView`.  
  
-   As mensagens de comando e muitas mensagens comuns de quadro\- notificação, incluindo aqueles tratadas por `OnSetFocus`, `OnHScroll`, e funções de `OnVScroll` de `CWnd`, são delegadas por uma janela do quadro de `CFrameWnd` para o modo ativo no momento.  
  
-   Modo ativo \(ou a janela filho ativa no momento do quadro MDI no caso de um quadro MDI\) podem determinar a legenda da janela do quadro.  Esse recurso pode ser desativado desativando o bit de estilo de **FWS\_ADDTOTITLE** da janela do quadro.  
  
-   Uma janela do quadro de `CFrameWnd` gerencia o posicionamento de barras de controle, de exibição, e outras janelas filho dentro da área cliente da janela do quadro.  Uma janela de quadro chave também torna atualizar de tempo ocioso da barra de ferramentas e outros botões da barra de controle.  Uma janela do quadro de `CFrameWnd` também tem implementações dos comandos para ativar \/desativar e fora da barra de ferramentas e statusbar.  
  
-   Uma janela do quadro de `CFrameWnd` gerencia a barra de menu principal.  Quando um menu pop\-up é exibido, a janela de quadro chave usa o mecanismo de **UPDATE\_COMMAND\_UI** para determinar quais itens de menu devem ser ativado, desativado, ou verificado.  Quando o usuário seleciona um item de menu, a janela do quadro atualiza a barra de status com a cadeia de mensagem para o comando.  
  
-   Uma janela do quadro de `CFrameWnd` possui uma tabela de aceleração opcional que transladar automaticamente aceleradores de teclado.  
  
-   Uma janela do quadro de `CFrameWnd` tem uma identificação opcional da ajuda definido com `LoadFrame` que é usado para a ajuda contextual.  Uma janela de quadro chave é o orchestrator de estados semimodal como modos da ajuda contextual \(SHIFT\+F1\) e de visualização de impressão.  
  
-   Uma janela do quadro de `CFrameWnd` abrirá um arquivo do gerenciador de arquivos arrastado e solto na janela do quadro.  Se uma extensão de arquivo é registrada e associada ao aplicativo, a janela do quadro responde à solicitação de aberta \(DDE\) de troca dinâmicas de dados que ocorre quando o usuário abre um arquivo de dados no gerenciador de arquivos ou quando a função do windows de **ShellExecute** é chamada.  
  
-   Se a janela de quadro chave é a janela principal do aplicativo \(ou seja, `CWinThread::m_pMainWnd`\), quando o usuário fecha o aplicativo, a janela do quadro solicita ao usuário para salvar todos os documentos alterados \(para `OnClose` e `OnQueryEndSession`\).  
  
-   Se a janela de quadro chave é a janela principal do aplicativo, a janela de quadro chave é o contexto para executar WinHelp.  Fechando a janela do quadro fechado WINHELP.EXE se foi iniciado para a ajuda para este aplicativo.  
  
 Não use o operador C\+\+ **delete** para destruir uma janela do quadro.  Use `CWnd::DestroyWindow` em vez de isso.  A implementação de `CFrameWnd` de `PostNcDestroy` excluirá o objeto C\+\+ quando a janela é destruída.  Quando o usuário fecha a janela do quadro, o manipulador padrão de `OnClose` chamará `DestroyWindow`.  
  
 Para obter mais informações sobre `CFrameWnd`, consulte [Quadro do windows](../../mfc/frame-windows.md).  
  
## Hierarquia de herança  
 [CObject](../Topic/CObject%20Class.md)  
  
 [CCmdTarget](../Topic/CCmdTarget%20Class.md)  
  
 [CWnd](../Topic/CWnd%20Class.md)  
  
 `CFrameWnd`  
  
## Requisitos  
 **Cabeçalho:** afxwin.h  
  
## Consulte também  
 [CWnd Class](../Topic/CWnd%20Class.md)   
 [Gráfico da hierarquia](../../mfc/hierarchy-chart.md)   
 [CWnd Class](../Topic/CWnd%20Class.md)   
 [Classe de CMDIFrameWnd](../../mfc/reference/cmdiframewnd-class.md)   
 [Classe de CMDIChildWnd](../../mfc/reference/cmdichildwnd-class.md)   
 [Classe de CView](../Topic/CView%20Class.md)   
 [Classe de CDocTemplate](../../mfc/reference/cdoctemplate-class.md)   
 [Estrutura de CRuntimeClass](../Topic/CRuntimeClass%20Structure.md)