---
title: Classe CFrameWnd | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-mfc
ms.topic: reference
f1_keywords:
- CFrameWnd
- AFXWIN/CFrameWnd
- AFXWIN/CFrameWnd::CFrameWnd
- AFXWIN/CFrameWnd::ActivateFrame
- AFXWIN/CFrameWnd::BeginModalState
- AFXWIN/CFrameWnd::Create
- AFXWIN/CFrameWnd::CreateView
- AFXWIN/CFrameWnd::DockControlBar
- AFXWIN/CFrameWnd::EnableDocking
- AFXWIN/CFrameWnd::EndModalState
- AFXWIN/CFrameWnd::FloatControlBar
- AFXWIN/CFrameWnd::GetActiveDocument
- AFXWIN/CFrameWnd::GetActiveFrame
- AFXWIN/CFrameWnd::GetActiveView
- AFXWIN/CFrameWnd::GetControlBar
- AFXWIN/CFrameWnd::GetDockState
- AFXWIN/CFrameWnd::GetMenuBarState
- AFXWIN/CFrameWnd::GetMenuBarVisibility
- AFXWIN/CFrameWnd::GetMessageBar
- AFXWIN/CFrameWnd::GetMessageString
- AFXWIN/CFrameWnd::GetTitle
- AFXWIN/CFrameWnd::InitialUpdateFrame
- AFXWIN/CFrameWnd::InModalState
- AFXWIN/CFrameWnd::IsTracking
- AFXWIN/CFrameWnd::LoadAccelTable
- AFXWIN/CFrameWnd::LoadBarState
- AFXWIN/CFrameWnd::LoadFrame
- AFXWIN/CFrameWnd::NegotiateBorderSpace
- AFXWIN/CFrameWnd::OnBarCheck
- AFXWIN/CFrameWnd::OnContextHelp
- AFXWIN/CFrameWnd::OnSetPreviewMode
- AFXWIN/CFrameWnd::OnUpdateControlBarMenu
- AFXWIN/CFrameWnd::RecalcLayout
- AFXWIN/CFrameWnd::SaveBarState
- AFXWIN/CFrameWnd::SetActivePreviewView
- AFXWIN/CFrameWnd::SetActiveView
- AFXWIN/CFrameWnd::SetDockState
- AFXWIN/CFrameWnd::SetMenuBarState
- AFXWIN/CFrameWnd::SetMenuBarVisibility
- AFXWIN/CFrameWnd::SetMessageText
- AFXWIN/CFrameWnd::SetProgressBarPosition
- AFXWIN/CFrameWnd::SetProgressBarRange
- AFXWIN/CFrameWnd::SetProgressBarState
- AFXWIN/CFrameWnd::SetTaskbarOverlayIcon
- AFXWIN/CFrameWnd::SetTitle
- AFXWIN/CFrameWnd::ShowControlBar
- AFXWIN/CFrameWnd::ShowOwnedWindows
- AFXWIN/CFrameWnd::OnCreateClient
- AFXWIN/CFrameWnd::OnHideMenuBar
- AFXWIN/CFrameWnd::OnShowMenuBar
- AFXWIN/CFrameWnd::m_bAutoMenuEnable
- AFXWIN/CFrameWnd::rectDefault
dev_langs:
- C++
helpviewer_keywords:
- CFrameWnd [MFC], CFrameWnd
- CFrameWnd [MFC], ActivateFrame
- CFrameWnd [MFC], BeginModalState
- CFrameWnd [MFC], Create
- CFrameWnd [MFC], CreateView
- CFrameWnd [MFC], DockControlBar
- CFrameWnd [MFC], EnableDocking
- CFrameWnd [MFC], EndModalState
- CFrameWnd [MFC], FloatControlBar
- CFrameWnd [MFC], GetActiveDocument
- CFrameWnd [MFC], GetActiveFrame
- CFrameWnd [MFC], GetActiveView
- CFrameWnd [MFC], GetControlBar
- CFrameWnd [MFC], GetDockState
- CFrameWnd [MFC], GetMenuBarState
- CFrameWnd [MFC], GetMenuBarVisibility
- CFrameWnd [MFC], GetMessageBar
- CFrameWnd [MFC], GetMessageString
- CFrameWnd [MFC], GetTitle
- CFrameWnd [MFC], InitialUpdateFrame
- CFrameWnd [MFC], InModalState
- CFrameWnd [MFC], IsTracking
- CFrameWnd [MFC], LoadAccelTable
- CFrameWnd [MFC], LoadBarState
- CFrameWnd [MFC], LoadFrame
- CFrameWnd [MFC], NegotiateBorderSpace
- CFrameWnd [MFC], OnBarCheck
- CFrameWnd [MFC], OnContextHelp
- CFrameWnd [MFC], OnSetPreviewMode
- CFrameWnd [MFC], OnUpdateControlBarMenu
- CFrameWnd [MFC], RecalcLayout
- CFrameWnd [MFC], SaveBarState
- CFrameWnd [MFC], SetActivePreviewView
- CFrameWnd [MFC], SetActiveView
- CFrameWnd [MFC], SetDockState
- CFrameWnd [MFC], SetMenuBarState
- CFrameWnd [MFC], SetMenuBarVisibility
- CFrameWnd [MFC], SetMessageText
- CFrameWnd [MFC], SetProgressBarPosition
- CFrameWnd [MFC], SetProgressBarRange
- CFrameWnd [MFC], SetProgressBarState
- CFrameWnd [MFC], SetTaskbarOverlayIcon
- CFrameWnd [MFC], SetTitle
- CFrameWnd [MFC], ShowControlBar
- CFrameWnd [MFC], ShowOwnedWindows
- CFrameWnd [MFC], OnCreateClient
- CFrameWnd [MFC], OnHideMenuBar
- CFrameWnd [MFC], OnShowMenuBar
- CFrameWnd [MFC], m_bAutoMenuEnable
- CFrameWnd [MFC], rectDefault
ms.assetid: e2220aba-5bf4-4002-b960-fbcafcad01f1
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 35a3fb35115e1fd86a2ccf168e048a697a17dc01
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
---
# <a name="cframewnd-class"></a>Classe CFrameWnd
Fornece a funcionalidade de uma interface de documento único do Windows (SDI) sobrepostas ou janela pop-up do quadro, juntamente com os membros para gerenciar a janela.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
class CFrameWnd : public CWnd  
```  
  
## <a name="members"></a>Membros  
  
### <a name="public-constructors"></a>Construtores Públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CFrameWnd::CFrameWnd](#cframewnd)|Constrói um objeto `CFrameWnd`.|  
  
### <a name="public-methods"></a>Métodos Públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CFrameWnd::ActivateFrame](#activateframe)|Torna o quadro visível e disponível para o usuário.|  
|[CFrameWnd::BeginModalState](#beginmodalstate)|Define a janela do quadro de janela restrita.|  
|[CFrameWnd::Create](#create)|Chamada para criar e inicializar a janela de quadro do Windows associada a `CFrameWnd` objeto.|  
|[CFrameWnd::CreateView](#createview)|Cria uma exibição em um intervalo que não é derivado de `CView`.|  
|[CFrameWnd::DockControlBar](#dockcontrolbar)|Encaixa uma barra de controle.|  
|[CFrameWnd::EnableDocking](#enabledocking)|Permite que uma barra de controle encaixado.|  
|[CFrameWnd::EndModalState](#endmodalstate)|Termina em estado modal da janela do quadro. Permite que todas as janelas desabilitadas por `BeginModalState`.|  
|[CFrameWnd::FloatControlBar](#floatcontrolbar)|Flutua uma barra de controle.|  
|[CFrameWnd::GetActiveDocument](#getactivedocument)|Retorna o ativo **CDocument** objeto.|  
|[CFrameWnd::GetActiveFrame](#getactiveframe)|Retorna o ativo `CFrameWnd` objeto.|  
|[CFrameWnd::GetActiveView](#getactiveview)|Retorna o ativo `CView` objeto.|  
|[CFrameWnd::GetControlBar](#getcontrolbar)|Recupera a barra de controle.|  
|[CFrameWnd::GetDockState](#getdockstate)|Recupera o estado de encaixe de uma janela do quadro.|  
|[CFrameWnd::GetMenuBarState](#getmenubarstate)|Recupera o estado de exibição do menu do aplicativo atual do MFC.|  
|[CFrameWnd::GetMenuBarVisibility](#getmenubarvisibility)|Indica se o comportamento padrão do menu do aplicativo MFC atual está oculto ou visível.|  
|[CFrameWnd::GetMessageBar](#getmessagebar)|Retorna um ponteiro para o status barra que pertencem a janela do quadro.|  
|[CFrameWnd::GetMessageString](#getmessagestring)|Recupera a mensagem correspondente a uma ID de comando.|  
|[CFrameWnd::GetTitle](#gettitle)|Recupera o título da barra de controle relacionados.|  
|[CFrameWnd::InitialUpdateFrame](#initialupdateframe)|Faz com que o `OnInitialUpdate` pertencentes a todos os modos de exibição na janela do quadro para ser chamado de função de membro.|  
|[CFrameWnd::InModalState](#inmodalstate)|Retorna um valor que indica se uma janela do quadro está em um estado modal.|  
|[CFrameWnd::IsTracking](#istracking)|Determina se a barra de divisão no momento está sendo movida.|  
|[CFrameWnd::LoadAccelTable](#loadacceltable)|Chamada para uma tabela de aceleradores de carga.|  
|[CFrameWnd::LoadBarState](#loadbarstate)|Chamada para restaurar as configurações de barra de controle.|  
|[CFrameWnd::LoadFrame](#loadframe)|Chamada para criar dinamicamente uma janela do quadro de informações sobre o recurso.|  
|[CFrameWnd::NegotiateBorderSpace](#negotiateborderspace)|Negocia o espaço de borda na janela do quadro.|  
|[CFrameWnd::OnBarCheck](#onbarcheck)|Chamado sempre que uma ação é executada na barra de controle especificado.|  
|[CFrameWnd::OnContextHelp](#oncontexthelp)|Lida com SHIFT + F1 Ajuda para os itens no local.|  
|[CFrameWnd::OnSetPreviewMode](#onsetpreviewmode)|Define a janela do quadro principal do aplicativo dentro e fora do modo de visualização de impressão.|  
|[CFrameWnd::OnUpdateControlBarMenu](#onupdatecontrolbarmenu)|Chamado pelo framework quando o menu associado é atualizado.|  
|[CFrameWnd::RecalcLayout](#recalclayout)|Reposiciona as barras de controle do `CFrameWnd` objeto.|  
|[CFrameWnd::SaveBarState](#savebarstate)|Chamada para salvar as configurações de barra de controle.|  
|[CFrameWnd::SetActivePreviewView](#setactivepreviewview)|Designa o modo de exibição especificado para ser o modo de exibição ativo para visualização avançada.|  
|[CFrameWnd::SetActiveView](#setactiveview)|Define o ativo `CView` objeto.|  
|[CFrameWnd::SetDockState](#setdockstate)|Chamada para encaixar a janela do quadro da janela principal.|  
|[CFrameWnd::SetMenuBarState](#setmenubarstate)|Define o estado de exibição do menu no aplicativo atual do MFC para exibidos ou ocultos.|  
|[CFrameWnd::SetMenuBarVisibility](#setmenubarvisibility)|Define o comportamento padrão do menu no aplicativo MFC atual visível ou oculto.|  
|[CFrameWnd::SetMessageText](#setmessagetext)|Define o texto de uma barra de status padrão.|  
|[CFrameWnd::SetProgressBarPosition](#setprogressbarposition)|Define a posição atual para a barra de progresso do Windows 7 exibida na barra de tarefas.|  
|[CFrameWnd::SetProgressBarRange](#setprogressbarrange)|Define o intervalo para a barra de progresso do Windows 7 exibido na barra de tarefas.|  
|[CFrameWnd::SetProgressBarState](#setprogressbarstate)|Define o tipo e estado do indicador de andamento exibido em um botão de barra de tarefas.|  
|[CFrameWnd::SetTaskbarOverlayIcon](#settaskbaroverlayicon)|Sobrecarregado. Aplica uma sobreposição a um botão de barra de tarefas para indicar o status do aplicativo ou uma notificação ao usuário.|  
|[CFrameWnd::SetTitle](#settitle)|Define o título da barra de controle relacionados.|  
|[CFrameWnd::ShowControlBar](#showcontrolbar)|Chamada para mostrar a barra de controle.|  
|[CFrameWnd::ShowOwnedWindows](#showownedwindows)|Mostra todas as janelas que são descendentes do `CFrameWnd` objeto.|  
  
### <a name="protected-methods"></a>Métodos Protegidos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CFrameWnd::OnCreateClient](#oncreateclient)|Cria uma janela de cliente para o quadro.|  
|[CFrameWnd::OnHideMenuBar](#onhidemenubar)|Chamado antes que o menu do aplicativo do MFC atual está oculto.|  
|[CFrameWnd::OnShowMenuBar](#onshowmenubar)|Chamado antes que o menu do aplicativo do MFC atual é exibido.|  
  
### <a name="public-data-members"></a>Membros de Dados Públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CFrameWnd::m_bAutoMenuEnable](#m_bautomenuenable)|Controles automática habilitam e desabilitar a funcionalidade para itens de menu.|  
|[CFrameWnd::rectDefault](#rectdefault)|Transmita esse estático `CRect` como um parâmetro ao criar um `CFrameWnd` objeto para permitir que o Windows escolha o tamanho inicial e a posição da janela.|  
  
## <a name="remarks"></a>Comentários  
 Para criar uma janela do quadro úteis para seu aplicativo, derive uma classe de `CFrameWnd`. Adicione variáveis de membro para a classe derivada para armazenar dados específicos do aplicativo. Implementar funções de membro de manipulador de mensagens e uma mensagem do mapa na classe derivada para especificar o que acontece quando as mensagens são direcionadas para a janela.  
  
 Há três maneiras de construir uma janela do quadro:  
  
-   Construir diretamente usando [criar](#create).  
  
-   Construir diretamente usando [LoadFrame](#loadframe).  
  
-   Indiretamente construí-lo usando um modelo de documento.  
  
 Antes de chamar o **criar** ou `LoadFrame`, você deve construir o objeto de janela do quadro na pilha usando o C++ **novo** operador. Antes de chamar **criar**, você também pode registrar uma classe de janela com o [AfxRegisterWndClass](../../mfc/reference/application-information-and-management.md#afxregisterwndclass) função global para definir os estilos de ícone e a classe do quadro.  
  
 Use o **criar** função de membro para passar parâmetros de criação do quadro imediatos como argumentos.  
  
 `LoadFrame` requer menos argumentos que **criar**e em vez disso, recupera a maioria de seus valores padrão de recursos, incluindo a legenda do quadro, ícone, tabela de Aceleradores e menu. Para ser acessível por `LoadFrame`, todos esses recursos devem ter a mesma ID de recurso (por exemplo, **IDR_MAINFRAME**).  
  
 Quando um `CFrameWnd` objeto contém exibições e documentos, elas são criadas indiretamente pelo framework em vez de diretamente pelo programador. O `CDocTemplate` objeto coordena a criação do quadro, a criação de modos de exibição de conteúdo e a conexão dos modos de exibição para o documento apropriado. Os parâmetros do `CDocTemplate` construtor especificar o `CRuntimeClass` das três classes envolvidos (documento, quadro e exibição). Um `CRuntimeClass` objeto é usado pelo framework para criar dinamicamente novos quadros quando especificado pelo usuário (por exemplo, usando o novo arquivo ou o comando vários documentos MDI (interface) nova janela).  
  
 Uma classe de janela com moldura derivada de `CFrameWnd` deve ser declarado com `DECLARE_DYNCREATE` para que as opções acima `RUNTIME_CLASS` mecanismo funcione corretamente.  
  
 Um `CFrameWnd` contém implementações padrão para executar as seguintes funções de uma janela principal em um aplicativo típico do Windows:  
  
-   Um `CFrameWnd` janela do quadro mantém o controle de um modo de exibição ativo no momento que é independente da janela ativa do Windows ou o foco de entrada atual. Quando o quadro for reativado, o modo de exibição ativo é notificado chamando `CView::OnActivateView`.  
  
-   Comando mensagens e muitas mensagens de notificação de quadro comuns, incluindo aqueles tratadas pelo `OnSetFocus`, `OnHScroll`, e `OnVScroll` funções de `CWnd`, são delegadas por um `CFrameWnd` janela do quadro para a exibição ativa no momento.  
  
-   A exibição ativa no momento (ou a janela de quadro de filho MDI ativa no momento no caso de um quadro MDI) pode determinar a legenda da janela do quadro. Esse recurso pode ser desativado, desativando o **FWS_ADDTOTITLE** bit de estilo da janela do quadro.  
  
-   Um `CFrameWnd` janela do quadro que gerencia o posicionamento das outras janelas filho dentro da área cliente da janela do quadro, exibições e as barras de controle. Uma janela do quadro também faz a atualização de tempo ocioso de barra de ferramentas e outros botões da barra de controle. Um `CFrameWnd` janela do quadro também tem implementações padrão de comandos de alternância ativa e desativa a barra de ferramentas e barra de status.  
  
-   Um `CFrameWnd` janela do quadro gerencia a barra de menus principal. Quando um menu pop-up for exibido, a janela do quadro usa o **UPDATE_COMMAND_UI** mecanismo para determinar quais itens de menu devem ser habilitados, desabilitados ou marcadas. Quando o usuário seleciona um item de menu, a janela do quadro atualiza a barra de status com a cadeia de caracteres de mensagem para o comando.  
  
-   Um `CFrameWnd` janela do quadro tem uma tabela de aceleradores opcional que converte automaticamente os aceleradores de teclado.  
  
-   Um `CFrameWnd` janela do quadro tem uma ID de ajuda opcional definido com `LoadFrame` que é usado para obter ajuda contextual. Uma janela do quadro é o principal orquestrador de estados semimodais como a Ajuda contextual (SHIFT + F1) e modos de visualização de impressão.  
  
-   Um `CFrameWnd` janela do quadro abrirá um arquivo do Gerenciador de arquivos de arrastados e soltos na janela do quadro. Se uma extensão de arquivo é registrada e associada ao aplicativo, a janela do quadro responde para a solicitação de abrir dinâmico de dados (DDE) do exchange que ocorre quando o usuário abre um arquivo de dados no Gerenciador de arquivos ou quando o **ShellExecute** Função do Windows é chamada.  
  
-   Se a janela do quadro é a janela principal do aplicativo (ou seja, `CWinThread::m_pMainWnd`), quando o usuário fecha o aplicativo, a janela do quadro solicita ao usuário para salvar todos os documentos modificados (para `OnClose` e `OnQueryEndSession`).  
  
-   Se a janela do quadro é a janela principal do aplicativo, a janela do quadro é o contexto de execução WinHelp. Fechando a janela do quadro será desligado WINHELP. EXE se ela foi iniciada para obter ajuda para este aplicativo.  
  
 Não use o C++ **excluir** operador destruir uma janela do quadro. Use `CWnd::DestroyWindow` em seu lugar. O `CFrameWnd` implementação de `PostNcDestroy` excluirá o objeto C++ quando a janela é destruída. Quando o usuário fecha a janela do quadro, o padrão `OnClose` manipulador chamará `DestroyWindow`.  
  
 Para obter mais informações sobre `CFrameWnd`, consulte [janelas com moldura](../../mfc/frame-windows.md).  
  
## <a name="inheritance-hierarchy"></a>Hierarquia de herança  
 [CObject](../../mfc/reference/cobject-class.md)  
  
 [CCmdTarget](../../mfc/reference/ccmdtarget-class.md)  
  
 [CWnd](../../mfc/reference/cwnd-class.md)  
  
 `CFrameWnd`  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** afxwin.h  
  
##  <a name="activateframe"></a>  CFrameWnd::ActivateFrame  
 Chame essa função de membro para ativar e restaurar a janela do quadro para que ele está visível e disponível para o usuário.  
  
```  
virtual void ActivateFrame(int nCmdShow = -1);
```  
  
### <a name="parameters"></a>Parâmetros  
 `nCmdShow`  
 Especifica o parâmetro para passar para [CWnd::ShowWindow](../../mfc/reference/cwnd-class.md#showwindow). Por padrão, o quadro é mostrado e restaurado corretamente.  
  
### <a name="remarks"></a>Comentários  
 Essa função de membro normalmente é chamada após um evento de interface do usuário não como DDE, OLE ou outro evento que pode mostrar a janela do quadro ou seu conteúdo para o usuário.  
  
 A implementação padrão ativa do quadro e coloca na parte superior da ordem Z e, se necessário, executa as mesmas etapas para a janela do quadro principal do aplicativo.  
  
 Substitua essa função de membro para alterar como um quadro é ativado. Por exemplo, você pode forçar o windows filho MDI ser maximizada. Adicionar a funcionalidade apropriada, em seguida, chame a versão da classe base com explícito `nCmdShow`.  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_MFCWindowing#1](../../mfc/reference/codesnippet/cpp/cframewnd-class_1.cpp)]  
  
##  <a name="beginmodalstate"></a>  CFrameWnd::BeginModalState  
 Chame essa função de membro para tornar uma janela com moldura modal.  
  
```  
virtual void BeginModalState();
```  
  
##  <a name="cframewnd"></a>  CFrameWnd::CFrameWnd  
 Constrói um `CFrameWnd` do objeto, mas não criar a janela do quadro visíveis.  
  
```  
CFrameWnd();
```  
  
### <a name="remarks"></a>Comentários  
 Chamar **criar** para criar a janela visível.  
  
##  <a name="create"></a>  CFrameWnd::Create  
 Chamada para criar e inicializar a janela de quadro do Windows associada a `CFrameWnd` objeto.  
  
```  
virtual BOOL Create(
    LPCTSTR lpszClassName,  
    LPCTSTR lpszWindowName,  
    DWORD dwStyle = WS_OVERLAPPEDWINDOW,  
    const RECT& rect = rectDefault,  
    CWnd* pParentWnd = NULL,  
    LPCTSTR lpszMenuName = NULL,  
    DWORD dwExStyle = 0,  
    CCreateContext* pContext = NULL);
```  
  
### <a name="parameters"></a>Parâmetros  
 `lpszClassName`  
 Aponta para uma cadeia de caracteres terminada em nulo que nomeia a classe do Windows. O nome da classe pode ser qualquer nome registrado com o `AfxRegisterWndClass` função global ou **RegisterClass** função do Windows. Se **nulo**, usa o padrão predefinido `CFrameWnd` atributos.  
  
 `lpszWindowName`  
 Aponta para uma cadeia de caracteres terminada em nulo que representa o nome da janela. Usado como o texto da barra de título.  
  
 `dwStyle`  
 Especifica a janela [estilo](../../mfc/reference/styles-used-by-mfc.md#window-styles) atributos. Incluir o **FWS_ADDTOTITLE** se desejar que a barra de título para exibir automaticamente o nome do documento representado na janela de estilo.  
  
 `rect`  
 Especifica o tamanho e a posição da janela. O `rectDefault` valor permite que o Windows especificar o tamanho e a posição da nova janela.  
  
 `pParentWnd`  
 Especifica a janela pai desta janela do quadro. Esse parâmetro deve ser **nulo** para janelas de quadro de nível superior.  
  
 *lpszMenuName*  
 Identifica o nome do recurso de menu a ser usado com a janela. Use **MAKEINTRESOURCE** se o menu tem uma ID de inteiro em vez de uma cadeia de caracteres. Esse parâmetro pode ser **nulo**.  
  
 `dwExStyle`  
 Especifica a janela estendida [estilo](../../mfc/reference/styles-used-by-mfc.md#extended-window-styles) atributos.  
  
 `pContext`  
 Especifica um ponteiro para um [CCreateContext](../../mfc/reference/ccreatecontext-structure.md) estrutura. Esse parâmetro pode ser **nulo**.  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se a inicialização for bem-sucedida; Caso contrário, 0.  
  
### <a name="remarks"></a>Comentários  
 Construir um `CFrameWnd` objeto em duas etapas. Primeiro, chamar o construtor, que constrói o `CFrameWnd` do objeto e, em seguida, chame **criar**, que cria a janela do quadro de Windows e anexa-o para o `CFrameWnd` objeto. **Criar** inicializa o nome da classe da janela e o nome da janela e registra os valores padrão para seu estilo, o pai e o menu associado.  
  
 Use `LoadFrame` em vez de **criar** para carregar a janela do quadro de um recurso em vez de especificar seus argumentos.  
  
##  <a name="createview"></a>  CFrameWnd::CreateView  
 Chamar `CreateView` para criar uma exibição de um quadro.  
  
```  
CWnd* CreateView(
    CCreateContext* pContext,  
    UINT nID = AFX_IDW_PANE_FIRST);
```  
  
### <a name="parameters"></a>Parâmetros  
 `pContext`  
 Especifica o tipo de documento e de exibição.  
  
 `nID`  
 O número de identificação de um modo de exibição.  
  
### <a name="return-value"></a>Valor de retorno  
 Ponteiro para um `CWnd` objeto se for bem-sucedida; caso contrário **nulo**.  
  
### <a name="remarks"></a>Comentários  
 Use esta função de membro para criar "exibe" que não são `CView`-derivado de um quadro. Depois de chamar `CreateView`, manualmente, você deve definir o modo como ativo e defini-lo para ser visível; essas tarefas não são executadas automaticamente pelo `CreateView`.  
  
##  <a name="dockcontrolbar"></a>  CFrameWnd::DockControlBar  
 Faz com que uma barra de controle para ser encaixada na janela do quadro.  
  
```  
void DockControlBar(
    CControlBar* pBar,  
    UINT nDockBarID = 0,  
    LPCRECT lpRect = NULL);
```  
  
### <a name="parameters"></a>Parâmetros  
 `pBar`  
 Aponta para a barra de controle encaixado.  
  
 `nDockBarID`  
 Determina quais lados do considerar para encaixar a janela do quadro. Pode ser 0, ou um ou mais dos seguintes:  
  
- `AFX_IDW_DOCKBAR_TOP` Encaixe o lado superior da janela do quadro.  
  
- **AFX_IDW_DOCKBAR_BOTTOM** encaixe para o lado inferior da janela do quadro.  
  
- `AFX_IDW_DOCKBAR_LEFT` Encaixe o lado esquerdo da janela do quadro.  
  
- `AFX_IDW_DOCKBAR_RIGHT` Encaixe o lado direito da janela do quadro.  
  
 Se for 0, a barra de controle pode ser encaixada para qualquer lado habilitado para encaixar na janela do quadro de destino.  
  
 `lpRect`  
 Determina, em coordenadas da tela, em que a barra de controle será encaixada na área não cliente da janela do quadro de destino.  
  
### <a name="remarks"></a>Comentários  
 A barra de controle será encaixada para um dos lados da janela do quadro especificado nas chamadas ao [CControlBar::EnableDocking](../../mfc/reference/ccontrolbar-class.md#enabledocking) e [CFrameWnd::EnableDocking](#enabledocking). O lado escolhido é determinado por `nDockBarID`.  
  
##  <a name="enabledocking"></a>  CFrameWnd::EnableDocking  
 Chame essa função para habilitar as barras de controle encaixáveis em uma janela do quadro.  
  
```  
void EnableDocking(DWORD dwDockStyle);
```  
  
### <a name="parameters"></a>Parâmetros  
 `dwDockStyle`  
 Especifica que as laterais da janela do quadro podem servir como sites de barras de controle de encaixe. Pode ser uma ou mais das seguintes opções:  
  
- `CBRS_ALIGN_TOP` Permite que o encaixe na parte superior da área cliente.  
  
- `CBRS_ALIGN_BOTTOM` Permite que o encaixe na parte inferior da área do cliente.  
  
- `CBRS_ALIGN_LEFT` Permite que o encaixe no lado esquerdo da área cliente.  
  
- `CBRS_ALIGN_RIGHT` Permite que o encaixe no lado direito da área do cliente.  
  
- `CBRS_ALIGN_ANY` Permite que o encaixe em qualquer lado da área do cliente.  
  
### <a name="remarks"></a>Comentários  
 Por padrão, as barras de controle serão encaixadas para um lado da janela do quadro na seguinte ordem: superior, inferior, esquerda, direita.  
  
### <a name="example"></a>Exemplo  
  Consulte o exemplo para [CToolBar::Create](../../mfc/reference/ctoolbar-class.md#create).  
  
##  <a name="endmodalstate"></a>  CFrameWnd::EndModalState  
 Chame essa função de membro para alterar uma janela do quadro de janela restrita para sem janela restrita.  
  
```  
virtual void EndModalState();
```  
  
### <a name="remarks"></a>Comentários  
 `EndModalState` permite que todas as janelas desabilitadas por [BeginModalState](#beginmodalstate).  
  
##  <a name="floatcontrolbar"></a>  CFrameWnd::FloatControlBar  
 Chame essa função para fazer com que uma barra de controle para não ser encaixada na janela do quadro.  
  
```  
void FloatControlBar(
    CControlBar* pBar,  
    CPoint point,  
    DWORD dwStyle = CBRS_ALIGN_TOP);
```  
  
### <a name="parameters"></a>Parâmetros  
 `pBar`  
 Aponta para a barra de controle para ser flutuante.  
  
 `point`  
 O local, em coordenadas da tela, onde o canto superior esquerdo da barra de controle será colocado.  
  
 `dwStyle`  
 Especifica se deseja alinhar a barra de controle horizontal ou verticalmente em sua nova janela do quadro. Ele pode ser qualquer um dos seguintes:  
  
- `CBRS_ALIGN_TOP` Orienta a barra de controle verticalmente.  
  
- `CBRS_ALIGN_BOTTOM` Orienta a barra de controle verticalmente.  
  
- `CBRS_ALIGN_LEFT` Orienta a barra de controle horizontalmente.  
  
- `CBRS_ALIGN_RIGHT` Orienta a barra de controle horizontalmente.  
  
 Se os estilos são passados para especificar a orientação horizontal e vertical, a barra de ferramentas serão orientada horizontalmente.  
  
### <a name="remarks"></a>Comentários  
 Normalmente, isso é feito na inicialização do aplicativo quando o programa está restaurando as configurações da execução anterior.  
  
 Essa função é chamada pelo framework quando o usuário faz com que uma operação de soltar soltando o botão esquerdo do mouse enquanto arrasta a barra de controle sobre um local que não está disponível para encaixe.  
  
##  <a name="getactivedocument"></a>  CFrameWnd::GetActiveDocument  
 Chamar essa função de membro para obter um ponteiro para o atual **CDocument** anexado à exibição ativa atual.  
  
```  
virtual CDocument* GetActiveDocument();
```  
  
### <a name="return-value"></a>Valor de retorno  
 Um ponteiro para o atual [CDocument](../../mfc/reference/cdocument-class.md). Se não houver nenhum documento atual, retorna **nulo**.  
  
##  <a name="getactiveframe"></a>  CFrameWnd::GetActiveFrame  
 Chame essa função de membro para obter um ponteiro para o active múltiplos interface MDI filho janela de uma janela de quadro MDI.  
  
```  
virtual CFrameWnd* GetActiveFrame();
```  
  
### <a name="return-value"></a>Valor de retorno  
 Um ponteiro para a janela filho MDI ativo. Se o aplicativo é um aplicativo SDI ou a janela do quadro MDI não tem nenhum documento ativo, o implícito **isso** ponteiro será retornado.  
  
### <a name="remarks"></a>Comentários  
 Se não há nenhum filho MDI ativo ou se o aplicativo é uma interface de documento único (SDI), o implícita **isso** ponteiro será retornado.  
  
##  <a name="getactiveview"></a>  CFrameWnd::GetActiveView  
 Chamar essa função de membro para obter um ponteiro para o modo de exibição ativo (se houver) anexado a uma janela do quadro ( `CFrameWnd`).  
  
```  
CView* GetActiveView() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 Um ponteiro para o atual [CView](../../mfc/reference/cview-class.md). Se não houver nenhum modo de exibição atual, retorna **nulo**.  
  
### <a name="remarks"></a>Comentários  
 Essa função retorna **nulo** quando chamado de uma janela do quadro principal MDI ( `CMDIFrameWnd`). Em um aplicativo MDI, a janela do quadro principal MDI não tem uma exibição associada a ele. Em vez disso, cada janela filho individual ( `CMDIChildWnd`) tem um ou mais modos de exibição associados. O modo de exibição ativo em um aplicativo MDI pode ser obtido pelo primeiro localizar a janela filho MDI ativo e, em seguida, localizar o modo de exibição ativo para essa janela filho. A janela filho MDI ativo pode ser encontrada chamando a função `MDIGetActive` ou **GetActiveFrame** conforme demonstrado a seguir:  
  
 [!code-cpp[NVC_MFCWindowing#2](../../mfc/reference/codesnippet/cpp/cframewnd-class_2.cpp)]  
  
##  <a name="getcontrolbar"></a>  CFrameWnd::GetControlBar  
 Chamar `GetControlBar` para acessar a barra de controle que está associada com a ID.  
  
```  
CControlBar* GetControlBar(UINT nID);
```  
  
### <a name="parameters"></a>Parâmetros  
 `nID`  
 O número de identificação de uma barra de controle.  
  
### <a name="return-value"></a>Valor de retorno  
 Um ponteiro para a barra de controle que está associado com a ID.  
  
### <a name="remarks"></a>Comentários  
 O `nID` parâmetro refere-se para o identificador passado para o **criar** método da barra de controle. Para obter mais informações sobre barras de controle, consulte o tópico intitulado [barras de controle](../../mfc/control-bars.md).  
  
 `GetControlBar` retornará a barra de controle, mesmo se ele estiver flutuando e, portanto, não é atualmente uma janela filho do quadro.  
  
##  <a name="getdockstate"></a>  CFrameWnd::GetDockState  
 Chamar essa função de membro para armazenar informações de estado sobre barras de controle da janela do quadro em uma `CDockState` objeto.  
  
```  
void GetDockState(CDockState& state) const;  
```  
  
### <a name="parameters"></a>Parâmetros  
 `state`  
 Contém o estado atual das barras de controle da janela do quadro após retornar.  
  
### <a name="remarks"></a>Comentários  
 Em seguida, você pode gravar o conteúdo de `CDockState` para o armazenamento usando `CDockState::SaveState` ou `Serialize`. Se você desejar restaurar as barras de controle para um estado anterior, carregar o estado com `CDockState::LoadState` ou `Serialize`, em seguida, chame `SetDockState` para aplicar o estado anterior a barras de controle da janela do quadro.  
  
##  <a name="getmenubarstate"></a>  CFrameWnd::GetMenuBarState  
 Recupera o estado de exibição do menu do aplicativo atual do MFC.  
  
```  
virtual DWORD GetMenuBarState();
```  
  
### <a name="return-value"></a>Valor de retorno  
 O valor de retorno pode ter os seguintes valores:  
  
-   AFX_MBS_VISIBLE (0x01) - menu está visível.  
  
-   AFX_MBS_HIDDEN (0x02) - menu está oculto.  
  
### <a name="remarks"></a>Comentários  
 Se ocorrer um erro de tempo de execução, esse método declarações no modo de depuração e gera uma exceção derivada de [CException](../../mfc/reference/cexception-class.md) classe.  
  
##  <a name="getmenubarvisibility"></a>  CFrameWnd::GetMenuBarVisibility  
 Indica se o estado padrão do menu do aplicativo MFC atual está visível ou oculto.  
  
```  
virtual DWORD CFrameWnd::GetMenuBarVisibility();
```  
  
### <a name="return-value"></a>Valor de retorno  
 Esse método retorna um dos seguintes valores:  
  
-   AFX_MBV_KEEPVISIBLE (0x01) - o menu é exibido em todos os horários e, por padrão não tem o foco.  
  
-   AFX_MBV_DISPLAYONFOCUS (0x02) - menu está oculto por padrão. Se o menu estiver oculto, pressione a tecla ALT para exibir o menu e dê a ele o foco. Se o menu é exibido, pressione a tecla ALT ou ESC para ocultá-la.  
  
-   AFX_MBV_ DISPLAYONFOCUS (0x02) &#124; AFX_MBV_DISPLAYONF10 (0x04) (combinação bit a bit (ou)) - menu está oculto por padrão. Se o menu estiver oculto, pressione a tecla F10 para exibir o menu e dê a ele o foco. Se o menu é exibido, pressione a tecla F10 para alternar o foco ou desativar o menu. O menu é exibido até que você pressionar a tecla ALT ou ESC para ocultá-la.  
  
### <a name="remarks"></a>Comentários  
 Se ocorrer um erro de tempo de execução, esse método declarações no modo de depuração e gera uma exceção derivada de [CException](../../mfc/reference/cexception-class.md) classe.  
  
##  <a name="getmessagebar"></a>  CFrameWnd::GetMessageBar  
 Chame essa função de membro para obter um ponteiro para a barra de status.  
  
```  
virtual CWnd* GetMessageBar();
```  
  
### <a name="return-value"></a>Valor de retorno  
 Ponteiro para a janela de barra de status.  
  
##  <a name="getmessagestring"></a>  CFrameWnd::GetMessageString  
 Substitua essa função para fornecer cadeias de caracteres personalizadas de IDs de comando.  
  
```  
virtual void GetMessageString(
    UINT nID,  
    CString& rMessage) const;  
```  
  
### <a name="parameters"></a>Parâmetros  
 `nID`  
 ID do recurso da mensagem desejado.  
  
 `rMessage`  
 `CString` objeto no qual colocar a mensagem.  
  
### <a name="remarks"></a>Comentários  
 A implementação padrão simplesmente carrega a cadeia de caracteres especificada por `nID` do arquivo de recurso. Essa função é chamada pelo framework quando a cadeia de caracteres de mensagem na barra de status precisa ser atualizado.  
  
##  <a name="gettitle"></a>  CFrameWnd::GetTitle  
 Recupera o título do objeto de janela.  
  
```  
CString GetTitle() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 Um [CString](../../atl-mfc-shared/reference/cstringt-class.md) objeto que contém o título atual do objeto de janela.  
  
##  <a name="initialupdateframe"></a>  CFrameWnd::InitialUpdateFrame  
 Chamar **IntitialUpdateFrame** depois de criar um novo quadro com **criar**.  
  
```  
void InitialUpdateFrame(
    CDocument* pDoc,  
    BOOL bMakeVisible);
```  
  
### <a name="parameters"></a>Parâmetros  
 `pDoc`  
 Aponta para o documento para que a janela do quadro está associada. Pode ser **nulo**.  
  
 `bMakeVisible`  
 Se **TRUE**, indica que o quadro deve se tornar visíveis e ativos. Se **FALSE**, sem descendentes ficam visíveis.  
  
### <a name="remarks"></a>Comentários  
 Isso faz com que todas as exibições nessa janela de quadro para receber seus `OnInitialUpdate` chamadas.  
  
 Além disso, se não houve anteriormente um modo de exibição ativo, a primeira exibição da janela do quadro fica ativa. O modo de exibição principal é uma exibição com a identificação de filho de **AFX_IDW_PANE_FIRST**. Por fim, a janela do quadro é tornada visível se `bMakeVisible` é diferente de zero. Se `bMakeVisible` for 0, o foco atual e o estado visível da janela do quadro permanecerá inalteradas. Não é necessário chamar essa função ao usar a implementação da estrutura de arquivo novo e abrir arquivo.  
  
##  <a name="inmodalstate"></a>  CFrameWnd::InModalState  
 Chame essa função de membro para verificar se uma janela do quadro é modal ou sem janela restrita.  
  
```  
BOOL InModalState() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se Sim. Caso contrário, 0.  
  
##  <a name="istracking"></a>  CFrameWnd::IsTracking  
 Chame essa função de membro para determinar se a barra de divisão na janela atualmente está sendo movida.  
  
```  
BOOL IsTracking() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se uma operação de divisão está em andamento. Caso contrário, 0.  
  
##  <a name="loadacceltable"></a>  CFrameWnd::LoadAccelTable  
 Chamada para carregar a tabela de aceleradores especificado.  
  
```  
BOOL LoadAccelTable(LPCTSTR lpszResourceName);
```  
  
### <a name="parameters"></a>Parâmetros  
 `lpszResourceName`  
 Identifica o nome do recurso acelerador. Use **MAKEINTRESOURCE** se o recurso é identificado com um ID de inteiro.  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se a tabela de aceleradores foi carregada com êxito; Caso contrário, 0.  
  
### <a name="remarks"></a>Comentários  
 Somente uma tabela pode ser carregada ao mesmo tempo.  
  
 Tabelas de teclas aceleradoras carregadas de recursos serão liberadas automaticamente quando o aplicativo termina.  
  
 Se você chamar `LoadFrame` para criar a janela do quadro, o framework carrega uma tabela de aceleradores junto com os recursos de menu e o ícone e uma chamada subsequente para essa função de membro, em seguida, é desnecessária.  
  
##  <a name="loadbarstate"></a>  CFrameWnd::LoadBarState  
 Chame essa função para restaurar as configurações de cada barra de controle pertencentes a janela do quadro.  
  
```  
void LoadBarState(LPCTSTR lpszProfileName);
```  
  
### <a name="parameters"></a>Parâmetros  
 `lpszProfileName`  
 Nome de uma seção no arquivo de inicialização (INI) ou uma chave no registro do Windows onde informações de estado são armazenadas.  
  
### <a name="remarks"></a>Comentários  
 Informações restauradas incluem visibilidade, orientação horizontal/vertical, estado de encaixe e posição da barra de controle.  
  
 As configurações que você deseja restaurar devem ser gravadas no registro antes de chamar `LoadBarState`. Gravar as informações do registro chamando [CWinApp::SetRegistryKey](../../mfc/reference/cwinapp-class.md#setregistrykey). Gravar as informações do arquivo INI chamando [SaveBarState](#savebarstate).  
  
##  <a name="loadframe"></a>  CFrameWnd::LoadFrame  
 Chamada para criar dinamicamente uma janela do quadro de informações sobre o recurso.  
  
```  
virtual BOOL LoadFrame(
    UINT nIDResource,  
    DWORD dwDefaultStyle = WS_OVERLAPPEDWINDOW | FWS_ADDTOTITLE,  
    CWnd* pParentWnd = NULL,  
    CCreateContext* pContext = NULL);
```  
  
### <a name="parameters"></a>Parâmetros  
 `nIDResource`  
 A ID de recursos compartilhados associados com a janela do quadro.  
  
 *dwDefaultStyle*  
 O quadro [estilo](../../mfc/reference/styles-used-by-mfc.md#window-styles). Incluir o **FWS_ADDTOTITLE** se desejar que a barra de título para exibir automaticamente o nome do documento representado na janela de estilo.  
  
 `pParentWnd`  
 Um ponteiro para o pai do quadro.  
  
 `pContext`  
 Um ponteiro para um [CCreateContext](../../mfc/reference/ccreatecontext-structure.md) estrutura. Esse parâmetro pode ser **nulo**.  
  
### <a name="remarks"></a>Comentários  
 Construir um `CFrameWnd` objeto em duas etapas. Primeiro, chamar o construtor, que constrói o `CFrameWnd` do objeto e, em seguida, chame `LoadFrame`, que carrega a janela do quadro de Windows e os recursos associados e anexa a janela do quadro para o `CFrameWnd` objeto. O `nIDResource` parâmetro especifica o menu, a tabela de aceleradores, o ícone e o recurso de cadeia de caracteres do título para a janela do quadro.  
  
 Use o **criar** função de membro em vez de `LoadFrame` quando quiser especificar todos os parâmetros de criação da janela do quadro.  
  
 A estrutura chama `LoadFrame` quando ele cria uma janela do quadro usando um objeto de modelo de documento.  
  
 A estrutura usa o `pContext` argumento para especificar os objetos para serem conectados a janela do quadro, incluindo qualquer contidos objetos de exibição. Você pode definir o `pContext` argumento **nulo** quando você chama `LoadFrame`.  
  
##  <a name="m_bautomenuenable"></a>  CFrameWnd::m_bAutoMenuEnable  
 Quando este membro de dados está habilitado (que é o padrão), itens de menu que não possuem `ON_UPDATE_COMMAND_UI` ou `ON_COMMAND` manipuladores serão desabilitados automaticamente quando o usuário recebe um menu suspenso.  
  
```  
BOOL m_bAutoMenuEnable;  
```  
  
### <a name="remarks"></a>Comentários  
 Itens de menu que possuem um `ON_COMMAND` manipulador mas não `ON_UPDATE_COMMAND_UI` manipulador será automaticamente habilitado.  
  
 Quando o membro de dados for definido, itens de menu são habilitados automaticamente da mesma forma que os botões da barra de ferramentas estão habilitadas.  
  
> [!NOTE]
> `m_bAutoMenuEnable` não tem nenhum efeito em itens de menu de nível superior.  
  
 Este membro de dados simplifica a implementação de comandos opcionais com base na seleção atual e reduz a necessidade de escrever `ON_UPDATE_COMMAND_UI` manipuladores para habilitar e desabilitar itens de menu.  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_MFCWindowing#3](../../mfc/reference/codesnippet/cpp/cframewnd-class_3.cpp)]  
  
##  <a name="negotiateborderspace"></a>  CFrameWnd::NegotiateBorderSpace  
 Chame essa função de membro para negociar o espaço de borda em uma janela do quadro durante a ativação de local OLE.  
  
```  
virtual BOOL NegotiateBorderSpace(
    UINT nBorderCmd,  
    LPRECT lpRectBorder);
```  
  
### <a name="parameters"></a>Parâmetros  
 *nBorderCmd*  
 Contém um dos seguintes valores do **enum BorderCmd**:  
  
- **borderGet** = 1  
  
- **borderRequest** = 2  
  
- **borderSet** = 3  
  
 `lpRectBorder`  
 Ponteiro para um [RECT](../../mfc/reference/rect-structure1.md) estrutura ou um [CRect](../../atl-mfc-shared/reference/crect-class.md) objeto que especifica as coordenadas da borda.  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se for bem-sucedida; Caso contrário, 0.  
  
### <a name="remarks"></a>Comentários  
 Essa função de membro é o **CFrameWnd** implementação da negociação de espaço de borda OLE.  
  
##  <a name="onbarcheck"></a>  CFrameWnd::OnBarCheck  
 Chamado sempre que uma ação é executada na barra de controle especificado.  
  
```  
afx_msg BOOL OnBarCheck(UINT nID);
```  
  
### <a name="parameters"></a>Parâmetros  
 `nID`  
 A ID do controle da barra sendo mostrado.  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se a barra de controle existente; Caso contrário, 0.  
  
##  <a name="oncontexthelp"></a>  CFrameWnd::OnContextHelp  
 Lida com SHIFT + F1 Ajuda para os itens no local.  
  
```  
afx_msg void OnContextHelp();
```  
  
### <a name="remarks"></a>Comentários  
 Para habilitar a Ajuda contextual, você deve adicionar um  
  
 [!code-cpp[NVC_MFCDocViewSDI#16](../../mfc/codesnippet/cpp/cframewnd-class_4.cpp)]  
  
 instrução para sua `CFrameWnd` classe mapa de mensagem e também adicionar uma entrada de tabela de aceleradores, normalmente SHIFT + F1, para habilitar essa função de membro.  
  
 Se seu aplicativo for um OLE Container, `OnContextHelp` coloca todos os itens no local contidos no objeto de janela do quadro no modo de Ajuda. O cursor muda para uma seta e um ponto de interrogação e o usuário pode, em seguida, mova o ponteiro do mouse e pressione o botão esquerdo do mouse para selecionar uma caixa de diálogo, janela, menu ou botão de comando. Esta função de membro chama a função do Windows `WinHelp` com o contexto de Ajuda do objeto sob o cursor.  
  
##  <a name="oncreateclient"></a>  CFrameWnd::OnCreateClient  
 Chamado pelo framework durante a execução de `OnCreate`.  
  
```  
virtual BOOL OnCreateClient(
    LPCREATESTRUCT lpcs,  
    CCreateContext* pContext);
```  
  
### <a name="parameters"></a>Parâmetros  
 `lpcs`  
 Um ponteiro para um Windows [CREATESTRUCT](../../mfc/reference/createstruct-structure.md) estrutura.  
  
 `pContext`  
 Um ponteiro para um [CCreateContext](../../mfc/reference/ccreatecontext-structure.md) estrutura.  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se for bem-sucedida; Caso contrário, 0.  
  
### <a name="remarks"></a>Comentários  
 Nunca chame essa função.  
  
 A implementação padrão dessa função cria uma `CView` objeto a partir das informações fornecidas em `pContext`, se possível.  
  
 Substituir essa função para substituir valores passados a `CCreateContext` de objeto ou para alterar os maneira como os controles na área da janela do quadro principal do cliente são criados. O `CCreateContext` descritos membros, você pode substituir o [CCreateContext](../../mfc/reference/ccreatecontext-structure.md) classe.  
  
> [!NOTE]
>  Não substitua os valores passados a `CREATESTRUCT` estrutura. Eles são somente para fins informativos. Se você deseja substituir o retângulo de janela inicial, por exemplo, substituir o `CWnd` função de membro [PreCreateWindow](../../mfc/reference/cwnd-class.md#precreatewindow).  
  
##  <a name="onhidemenubar"></a>  CFrameWnd::OnHideMenuBar  
 Esta função é chamada quando o sistema está prestes a ocultar a barra de menu no aplicativo atual do MFC.  
  
```  
virtual void OnHideMenuBar();
```  
  
### <a name="remarks"></a>Comentários  
 Este manipulador de eventos permite que seu aplicativo executar ações personalizadas quando o sistema está prestes a ocultar o menu. Você não pode impedir o menu ocultada, mas você pode, por exemplo, chamar outros métodos para recuperar o estado ou o estilo do menu.  
  
##  <a name="onsetpreviewmode"></a>  CFrameWnd::OnSetPreviewMode  
 Chame essa função de membro para definir a janela do quadro principal do aplicativo dentro e fora do modo de visualização de impressão.  
  
```  
virtual void OnSetPreviewMode(
    BOOL bPreview,  
    CPrintPreviewState* pState);
```  
  
### <a name="parameters"></a>Parâmetros  
 *bPreview*  
 Especifica se deve ou não colocar o aplicativo no modo de visualização de impressão. Definido como **TRUE** para colocar na visualização de impressão, **FALSE** para cancelar o modo de visualização.  
  
 `pState`  
 Um ponteiro para um **CPrintPreviewState** estrutura.  
  
### <a name="remarks"></a>Comentários  
 A implementação padrão desabilita todas as barras de ferramentas padrão e oculta o menu principal e a janela principal do cliente. Isso ativa a janelas de quadro MDI em janelas de quadro SDI temporárias.  
  
 Substitua essa função de membro para personalizar a exibição e ocultação de barras de controle e outras partes da janela de quadro durante a visualização de impressão. Chame a implementação da classe base de dentro da versão substituída.  
  
##  <a name="onshowmenubar"></a>  CFrameWnd::OnShowMenuBar  
 Esta função é chamada quando o sistema está prestes a exibir a barra de menu no aplicativo atual do MFC.  
  
```  
virtual void OnShowMenuBar();
```  
  
### <a name="remarks"></a>Comentários  
 Este manipulador de eventos permite que seu aplicativo executar ações personalizadas ao menu está prestes a ser exibido. Você não pode impedir que o menu seja exibida, mas você pode, por exemplo, chamar outros métodos para recuperar o estado ou o estilo do menu.  
  
##  <a name="onupdatecontrolbarmenu"></a>  CFrameWnd::OnUpdateControlBarMenu  
 Chamado pelo framework quando o menu associado é atualizado.  
  
```  
afx_msg void OnUpdateControlBarMenu(CCmdUI* pCmdUI);
```  
  
### <a name="parameters"></a>Parâmetros  
 `pCmdUI`  
 Um ponteiro para um [CCmdUI](../../mfc/reference/ccmdui-class.md) objeto que representa o menu que gerou o comando de atualização. As chamadas do manipulador de atualização de [habilitar](../../mfc/reference/ccmdui-class.md#enable) função membro do `CCmdUI` por meio do objeto `pCmdUI` para atualizar a interface do usuário.  
  
##  <a name="recalclayout"></a>  CFrameWnd::RecalcLayout  
 Chamado pelo framework quando as barras de controle padrão são ligadas ou desligadas ou quando a janela do quadro é redimensionada.  
  
```  
virtual void RecalcLayout(BOOL bNotify = TRUE);
```  
  
### <a name="parameters"></a>Parâmetros  
 `bNotify`  
 Determina se o item ativo do local para a janela do quadro recebe notificação de alteração de layout. Se **TRUE**, o item é notificado; caso contrário **FALSE**.  
  
### <a name="remarks"></a>Comentários  
 A implementação padrão desta função de membro chama o `CWnd` função de membro `RepositionBars` para reposicionar as barras de controle no quadro, bem como a janela principal do cliente (geralmente um `CView` ou **MDICLIENT**) .  
  
 Substitua essa função de membro para controlar a aparência e comportamento das barras de controle depois que o layout da janela do quadro é alterado. Por exemplo, chame quando você ativa ou desativar o barras de controle ou adiciona outra barra de controle.  
  
##  <a name="rectdefault"></a>  CFrameWnd::rectDefault  
 Transmita esse estático `CRect` como um parâmetro ao criar uma janela para permitir que o Windows escolha o tamanho inicial e a posição da janela.  
  
```  
static AFX_DATA const CRect rectDefault;  
```  
  
##  <a name="savebarstate"></a>  CFrameWnd::SaveBarState  
 Chame essa função para armazenar informações sobre cada barra de controle pertencente a janela do quadro.  
  
```  
void SaveBarState(LPCTSTR lpszProfileName) const;  
```  
  
### <a name="parameters"></a>Parâmetros  
 `lpszProfileName`  
 Nome de uma seção no arquivo de inicialização ou uma chave no registro do Windows onde informações de estado são armazenadas.  
  
### <a name="remarks"></a>Comentários  
 Essas informações podem ser lidos do arquivo de inicialização usando [LoadBarState](#loadbarstate). As informações armazenadas incluem visibilidade, orientação horizontal/vertical, estado e a posição da barra de controle de encaixe.  
  
##  <a name="setactivepreviewview"></a>  CFrameWnd::SetActivePreviewView  
 Designa o modo de exibição especificado para ser o modo de exibição ativo para visualização avançada.  
  
```  
void SetActivePreviewView(CView* pViewNew);
```  
  
### <a name="parameters"></a>Parâmetros  
 `pViewNew`  
 Um ponteiro para um modo de exibição a ser ativado.  
  
### <a name="remarks"></a>Comentários  
  
##  <a name="setactiveview"></a>  CFrameWnd::SetActiveView  
 Chame essa função de membro para definir o modo de exibição ativo.  
  
```  
void SetActiveView(
    CView* pViewNew,  
    BOOL bNotify = TRUE);
```  
  
### <a name="parameters"></a>Parâmetros  
 *pViewNew*  
 Especifica um ponteiro para um [CView](../../mfc/reference/cview-class.md) objeto, ou **nulo** para nenhum modo de exibição ativo.  
  
 `bNotify`  
 Especifica se o modo de exibição para ser notificado de ativação. Se **TRUE**, `OnActivateView` é chamado para a nova exibição; se **FALSE**, não é.  
  
### <a name="remarks"></a>Comentários  
 A estrutura chamará essa função automaticamente conforme o usuário altera o foco para um modo de exibição dentro da janela do quadro. Você pode chamar explicitamente `SetActiveView` para alterar o foco para o modo de exibição especificado.  
  
##  <a name="setdockstate"></a>  CFrameWnd::SetDockState  
 Chamar essa função de membro para aplicar as informações de estado armazenadas em uma `CDockState` objeto barras de controle da janela do quadro.  
  
```  
void SetDockState(const CDockState& state);
```  
  
### <a name="parameters"></a>Parâmetros  
 `state`  
 Aplica o estado armazenado em barras de controle da janela do quadro.  
  
### <a name="remarks"></a>Comentários  
 Para restaurar um estado anterior das barras de controle, você pode carregar o estado armazenado com `CDockState::LoadState` ou `Serialize`, em seguida, use `SetDockState` a barras de controle da janela do quadro. O estado anterior é armazenado no `CDockState` do objeto com `GetDockState`  
  
##  <a name="setmenubarstate"></a>  CFrameWnd::SetMenuBarState  
 Define o estado de exibição do menu no aplicativo atual do MFC para exibidos ou ocultos.  
  
```  
virtual BOOL SetMenuBarState(DWORD nState);
```  
  
### <a name="parameters"></a>Parâmetros  
  
|Parâmetro|Descrição|  
|---------------|-----------------|  
|[in] `nState`|Especifica se deseja exibir ou ocultar o menu. O `nState` parâmetro pode ter os seguintes valores:<br /><br /> -AFX_MBS_VISIBLE (0x01) - exibe o menu se ele está oculto, mas não tem nenhum efeito se ele estiver visível.<br />-AFX_MBS_HIDDEN (0x02) - oculta o menu se ele estiver visível, mas não tem nenhum efeito se ele estiver oculto.|  
  
### <a name="return-value"></a>Valor de retorno  
 `true` Se esse método com êxito altera o estado de menu; Caso contrário, `false`.  
  
### <a name="remarks"></a>Comentários  
 Se ocorrer um erro de tempo de execução, esse método declarações no modo de depuração e gera uma exceção derivada de [CException](../../mfc/reference/cexception-class.md) classe.  
  
##  <a name="setmenubarvisibility"></a>  CFrameWnd::SetMenuBarVisibility  
 Define o comportamento padrão do menu no aplicativo MFC atual visível ou oculto.  
  
```  
virtual void SetMenuBarVisibility(DWORD nStyle);
```  
  
### <a name="parameters"></a>Parâmetros  
  
|Parâmetro|Descrição|  
|---------------|-----------------|  
|[in] `nStyle`|Especifica se o menu é por padrão, ou está visível e tem o foco. O `nStyle` parâmetro pode ter os seguintes valores:<br /><br /> -AFX_MBV_KEEPVISIBLE (0X01)<br />     O menu é exibido em todos os momentos e por padrão não tem o foco.<br />-AFX_MBV_DISPLAYONFOCUS (0X02)-<br />     O menu é ocultado por padrão. Se o menu estiver oculto, pressione a tecla ALT para exibir o menu e dê a ele o foco. Se o menu é exibido, pressione a tecla ALT ou ESC para ocultar o menu.<br />-AFX_MBV_ DISPLAYONFOCUS (0x02) &#124; AFX_MBV_DISPLAYONF10 (0x04)<br />     (combinação bit a bit (ou)) - menu está oculto por padrão. Se o menu estiver oculto, pressione a tecla F10 para exibir o menu e dê a ele o foco. Se o menu é exibido, pressione a tecla F10 para alternar o foco ou desativar o menu. O menu é exibido até que você pressionar a tecla ALT ou ESC para ocultá-la.|  
  
### <a name="remarks"></a>Comentários  
 Se o valor de `nStyle` parâmetro não é válido, esse método declarações no modo de depuração e gera [CInvalidArgException](../../mfc/reference/cinvalidargexception-class.md) no modo de liberação. No caso de outros erros de tempo de execução, esse método declarações no modo de depuração e gera uma exceção derivada de [CException](../../mfc/reference/cexception-class.md) classe.  
  
 Esse método afeta o estado de menus em aplicativos gravados para [!INCLUDE[windowsver](../../build/reference/includes/windowsver_md.md)] e posterior.  
  
##  <a name="setmessagetext"></a>  CFrameWnd::SetMessageText  
 Chame essa função para inserir uma cadeia de caracteres no painel de barra de status que tem uma ID de 0.  
  
```  
void SetMessageText(LPCTSTR lpszText);  
void SetMessageText(UINT nID);
```  
  
### <a name="parameters"></a>Parâmetros  
 `lpszText`  
 Aponta para a cadeia de caracteres a ser colocado na barra de status.  
  
 `nID`  
 ID de recurso de cadeia de caracteres da cadeia de caracteres a ser colocado na barra de status.  
  
### <a name="remarks"></a>Comentários  
 Normalmente, isso é o mais à esquerda e mais longo, o painel da barra de status.  
  
##  <a name="setprogressbarposition"></a>  CFrameWnd::SetProgressBarPosition  
 Define a posição atual para a barra de progresso do Windows 7 exibida na barra de tarefas.  
  
```  
void SetProgressBarPosition(int nProgressPos);
```  
  
### <a name="parameters"></a>Parâmetros  
 `nProgressPos`  
 Especifica a posição para definir. Ele deve estar dentro do intervalo definido por `SetProgressBarRange`.  
  
### <a name="remarks"></a>Comentários  
  
##  <a name="setprogressbarrange"></a>  CFrameWnd::SetProgressBarRange  
 Define o intervalo para a barra de progresso do Windows 7 exibido na barra de tarefas.  
  
```  
void SetProgressBarRange(
    int nRangeMin,  
    int nRangeMax);
```  
  
### <a name="parameters"></a>Parâmetros  
 `nRangeMin`  
 Valor mínimo.  
  
 `nRangeMax`  
 Valor máximo.  
  
### <a name="remarks"></a>Comentários  
  
##  <a name="setprogressbarstate"></a>  CFrameWnd::SetProgressBarState  
 Define o tipo e estado do indicador de andamento exibido em um botão de barra de tarefas.  
  
```  
void SetProgressBarState(TBPFLAG tbpFlags);
```  
  
### <a name="parameters"></a>Parâmetros  
 `tbpFlags`  
 Sinalizadores que controlam o estado atual do botão de andamento. Especifique apenas um dos seguintes sinalizadores porque todos os estados são mutuamente exclusivos: TBPF_NOPROGRESS, TBPF_INDETERMINATE, TBPF_NORMAL, TBPF_ERROR, TBPF_PAUSED.  
  
### <a name="remarks"></a>Comentários  
  
##  <a name="settaskbaroverlayicon"></a>  CFrameWnd::SetTaskbarOverlayIcon  
 Sobrecarregado. Aplica uma sobreposição a um botão de barra de tarefas para indicar o status do aplicativo ou para notificar o usuário.  
  
```  
BOOL SetTaskbarOverlayIcon(
    UINT nIDResource,  
    LPCTSTR lpcszDescr);

 
BOOL SetTaskbarOverlayIcon(
    HICON hIcon,  
    LPCTSTR lpcszDescr);
```  
  
### <a name="parameters"></a>Parâmetros  
 `nIDResource`  
 Especifica a ID de recurso de um ícone a ser usado como a sobreposição. Consulte a descrição para `hIcon` para obter detalhes.  
  
 `lpcszDescr`  
 Um ponteiro para uma cadeia de caracteres que fornece uma versão de texto alt das informações transmitidas por na sobreposição, para fins de acessibilidade.  
  
 `hIcon`  
 O identificador de um ícone a ser usado como a sobreposição. Isso deve ser um pequeno ícone medindo 16x16 pixels a 96 pontos por polegada (dpi). Se um ícone de sobreposição já foi aplicado ao botão da barra de tarefas, essa sobreposição existente será substituída. Este valor pode ser `NULL`. Como um `NULL` valor é tratado depende se o botão da barra de tarefas representa uma única janela ou um grupo do windows. É responsabilidade do aplicativo de chamada para liberar `hIcon` quando ele não for mais necessário.  
  
### <a name="return-value"></a>Valor de retorno  
 `TRUE` Se for bem-sucedida; `FALSE` se a versão do sistema operacional é menor que o Windows 7 ou se ocorrer um erro de ícone de configuração.  
  
### <a name="remarks"></a>Comentários  
  
##  <a name="settitle"></a>  CFrameWnd::SetTitle  
 Define o título do objeto de janela.  
  
```  
void SetTitle(LPCTSTR lpszTitle);
```  
  
### <a name="parameters"></a>Parâmetros  
 `lpszTitle`  
 Um ponteiro para uma cadeia de caracteres que contém o título do objeto de janela.  
  
##  <a name="showcontrolbar"></a>  CFrameWnd::ShowControlBar  
 Chame essa função de membro para mostrar ou ocultar a barra de controle.  
  
```  
void ShowControlBar(
    CControlBar* pBar,  
    BOOL bShow,  
    BOOL bDelay);
```  
  
### <a name="parameters"></a>Parâmetros  
 `pBar`  
 Ponteiro para a barra de controle deve ser mostrado ou oculto.  
  
 `bShow`  
 Se **TRUE**, especifica que a barra de controle deve ser mostrado. Se **FALSE**, especifica que a barra de controle deve ser ocultada.  
  
 *bDelay*  
 Se **TRUE**, atrasar a exibição da barra de controle. Se **FALSE**, mostrar o controle de barra imediatamente.  
  
##  <a name="showownedwindows"></a>  CFrameWnd::ShowOwnedWindows  
 Chamar essa função de membro para mostrar todas as janelas que são descendentes do `CFrameWnd` objeto.  
  
```  
void ShowOwnedWindows(BOOL bShow);
```  
  
### <a name="parameters"></a>Parâmetros  
 `bShow`  
 Especifica se as janelas de propriedade devem ser mostrados ou ocultados.  
  
## <a name="see-also"></a>Consulte também  
 [Classe CWnd](../../mfc/reference/cwnd-class.md)   
 [Gráfico de hierarquia](../../mfc/hierarchy-chart.md)   
 [Classe CWnd](../../mfc/reference/cwnd-class.md)   
 [Classe CMDIFrameWnd](../../mfc/reference/cmdiframewnd-class.md)   
 [Classe CMDIChildWnd](../../mfc/reference/cmdichildwnd-class.md)   
 [Classe CView](../../mfc/reference/cview-class.md)   
 [Classe CDocTemplate](../../mfc/reference/cdoctemplate-class.md)   
 [Estrutura CRuntimeClass](../../mfc/reference/cruntimeclass-structure.md)
