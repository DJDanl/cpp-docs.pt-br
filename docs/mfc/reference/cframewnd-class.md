---
title: Classe CFrameWnd
ms.date: 11/04/2016
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
ms.openlocfilehash: 3259780d73004c9d1654c26434b55627923cfe23
ms.sourcegitcommit: 975098222db3e8b297607cecaa1f504570a11799
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/10/2018
ms.locfileid: "53178786"
---
# <a name="cframewnd-class"></a>Classe CFrameWnd

Fornece a funcionalidade de uma janela de quadro pop-up, juntamente com os membros para gerenciar a janela ou Windows interface SDI (SDI) sobreposta.

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
|[CFrameWnd::BeginModalState](#beginmodalstate)|Define a janela do quadro até o modal.|
|[CFrameWnd::Create](#create)|Chamada para criar e inicializar a janela de quadro do Windows associada a `CFrameWnd` objeto.|
|[CFrameWnd::CreateView](#createview)|Cria uma exibição em um quadro que não é derivado de `CView`.|
|[CFrameWnd::DockControlBar](#dockcontrolbar)|Encaixa uma barra de controle.|
|[CFrameWnd::EnableDocking](#enabledocking)|Permite que uma barra de controle encaixado.|
|[CFrameWnd::EndModalState](#endmodalstate)|Termina um estado modal da janela do quadro. Permite que todas as janelas desabilitadas por `BeginModalState`.|
|[CFrameWnd::FloatControlBar](#floatcontrolbar)|Flutua uma barra de controle.|
|[CFrameWnd::GetActiveDocument](#getactivedocument)|Retorna a ativa `CDocument` objeto.|
|[CFrameWnd::GetActiveFrame](#getactiveframe)|Retorna a ativa `CFrameWnd` objeto.|
|[CFrameWnd::GetActiveView](#getactiveview)|Retorna a ativa `CView` objeto.|
|[CFrameWnd::GetControlBar](#getcontrolbar)|Recupera a barra de controle.|
|[CFrameWnd::GetDockState](#getdockstate)|Recupera o estado de encaixe de uma janela de quadro.|
|[CFrameWnd::GetMenuBarState](#getmenubarstate)|Recupera o estado de exibição do menu no aplicativo MFC atual.|
|[CFrameWnd::GetMenuBarVisibility](#getmenubarvisibility)|Indica se o comportamento padrão do menu no aplicativo MFC atual está oculto ou visível.|
|[CFrameWnd::GetMessageBar](#getmessagebar)|Retorna um ponteiro para a barra que pertencem a janela do quadro de status.|
|[CFrameWnd::GetMessageString](#getmessagestring)|Recupera a mensagem que corresponde a uma ID de comando.|
|[CFrameWnd::GetTitle](#gettitle)|Recupera o título da barra de controle relacionado.|
|[CFrameWnd::InitialUpdateFrame](#initialupdateframe)|Faz com que o `OnInitialUpdate` que pertencem a todas as exibições na janela do quadro a ser chamada de função de membro.|
|[CFrameWnd::InModalState](#inmodalstate)|Retorna um valor que indica se uma janela de quadro está em um estado modal.|
|[CFrameWnd::IsTracking](#istracking)|Determina se barra divisória atualmente está sendo movida.|
|[CFrameWnd::LoadAccelTable](#loadacceltable)|Chamada para carregar uma tabela de aceleradores.|
|[CFrameWnd::LoadBarState](#loadbarstate)|Chamada para restaurar as configurações de barra de controle.|
|[CFrameWnd::LoadFrame](#loadframe)|Chamada para criar dinamicamente uma janela do quadro de informações sobre o recurso.|
|[CFrameWnd::NegotiateBorderSpace](#negotiateborderspace)|Negocia o espaço de borda na janela do quadro.|
|[CFrameWnd::OnBarCheck](#onbarcheck)|Chamado sempre que uma ação é executada na barra de controle especificado.|
|[CFrameWnd::OnContextHelp](#oncontexthelp)|Manipula SHIFT + F1 Ajuda para os itens no local.|
|[CFrameWnd::OnSetPreviewMode](#onsetpreviewmode)|Define a janela do quadro principal do aplicativo para dentro e fora do modo de visualização de impressão.|
|[CFrameWnd::OnUpdateControlBarMenu](#onupdatecontrolbarmenu)|Chamado pelo framework quando o menu associado é atualizado.|
|[CFrameWnd::RecalcLayout](#recalclayout)|Reposiciona as barras de controle do `CFrameWnd` objeto.|
|[CFrameWnd::SaveBarState](#savebarstate)|Chamada para salvar as configurações de barra de controle.|
|[CFrameWnd::SetActivePreviewView](#setactivepreviewview)|Designa o modo de exibição especificado para ser o modo de exibição ativo para visualização avançada.|
|[CFrameWnd::SetActiveView](#setactiveview)|Define o ativo `CView` objeto.|
|[CFrameWnd::SetDockState](#setdockstate)|Chamada para encaixar a janela do quadro na janela principal.|
|[CFrameWnd::SetMenuBarState](#setmenubarstate)|Define o estado de exibição do menu no aplicativo MFC atual exibido ou oculto.|
|[CFrameWnd::SetMenuBarVisibility](#setmenubarvisibility)|Define o comportamento padrão do menu no aplicativo MFC atual para ser visível ou oculto.|
|[CFrameWnd::SetMessageText](#setmessagetext)|Define o texto de uma barra de status padrão.|
|[CFrameWnd::SetProgressBarPosition](#setprogressbarposition)|Define a posição atual para a barra de progresso do Windows 7 exibida na barra de tarefas.|
|[CFrameWnd::SetProgressBarRange](#setprogressbarrange)|Define o intervalo para a barra de progresso do Windows 7 exibido na barra de tarefas.|
|[CFrameWnd::SetProgressBarState](#setprogressbarstate)|Define o tipo e estado do indicador de progresso exibido em um botão de barra de tarefas.|
|[CFrameWnd::SetTaskbarOverlayIcon](#settaskbaroverlayicon)|Sobrecarregado. Aplica-se de uma sobreposição a um botão de barra de tarefas para indicar o status de aplicativo ou uma notificação ao usuário.|
|[CFrameWnd::SetTitle](#settitle)|Define o título da barra de controle relacionado.|
|[CFrameWnd::ShowControlBar](#showcontrolbar)|Chamada para mostrar a barra de controle.|
|[CFrameWnd::ShowOwnedWindows](#showownedwindows)|Mostra todas as janelas que são descendentes do `CFrameWnd` objeto.|

### <a name="protected-methods"></a>Métodos Protegidos

|Nome|Descrição|
|----------|-----------------|
|[CFrameWnd::OnCreateClient](#oncreateclient)|Cria uma janela de cliente para o quadro.|
|[CFrameWnd::OnHideMenuBar](#onhidemenubar)|Chamado antes que o menu do aplicativo do MFC atual está oculto.|
|[CFrameWnd::OnShowMenuBar](#onshowmenubar)|Chamado antes que o menu no aplicativo MFC atual é exibido.|

### <a name="public-data-members"></a>Membros de Dados Públicos

|Nome|Descrição|
|----------|-----------------|
|[CFrameWnd::m_bAutoMenuEnable](#m_bautomenuenable)|Controles automática habilitam e desabilitar a funcionalidade para itens de menu.|
|[CFrameWnd::rectDefault](#rectdefault)|Passe essa estática `CRect` como um parâmetro durante a criação de um `CFrameWnd` objeto para permitir que o Windows escolher o tamanho inicial e a posição da janela.|

## <a name="remarks"></a>Comentários

Para criar uma janela de quadro úteis para seu aplicativo, derive uma classe de `CFrameWnd`. Adicione variáveis de membro à classe derivada para armazenar dados específicos ao seu aplicativo. Implementar funções de membro de manipulador de mensagens e uma mensagem do mapa na classe derivada para especificar o que acontece quando as mensagens são direcionadas para a janela.

Há três maneiras de construir uma janela de quadro:

- Diretamente construí-la usando [criar](#create).

- Diretamente construí-la usando [LoadFrame](#loadframe).

- Indiretamente construí-la usando um modelo de documento.

Antes de você chamar `Create` ou `LoadFrame`, você deve construir o objeto de janela do quadro na pilha usando o C++ **novos** operador. Antes de chamar `Create`, você também pode registrar uma classe de janela com o [AfxRegisterWndClass](../../mfc/reference/application-information-and-management.md#afxregisterwndclass) função global para definir os estilos de ícone e a classe para o quadro.

Use o `Create` a função de membro para passar parâmetros de criação do quadro imediatos como argumentos.

`LoadFrame` requer menos argumentos que `Create`e em vez disso, recupera a maioria de seus valores padrão de recursos, incluindo a legenda do quadro, ícone, tabela de Aceleradores e menu. Para ser acessível por `LoadFrame`, todos esses recursos devem ter a mesma ID de recurso (por exemplo, IDR_MAINFRAME).

Quando um `CFrameWnd` objeto contém documentos e exibições, são criadas indiretamente pelo framework em vez de diretamente pelo programador. O `CDocTemplate` objeto orquestra a criação de quadro, a criação dos modos de exibição que contém e a conexão dos modos de exibição para o documento apropriado. Os parâmetros do `CDocTemplate` construtor especifique o `CRuntimeClass` das três classes envolvidas (documento, quadro e exibição). Um `CRuntimeClass` objeto é usado pelo framework para criar dinamicamente novos quadros quando especificado pelo usuário (por exemplo, usando o novo arquivo ou o comando vários documentos (interface MDI) nova janela).

Uma classe de janela com moldura derivada de `CFrameWnd` deve ser declarado com DECLARE_DYNCREATE para que o mecanismo RUNTIME_CLASS acima funcione corretamente.

Um `CFrameWnd` contém implementações padrão para executar as seguintes funções de uma janela principal em um aplicativo típico para Windows:

- Um `CFrameWnd` janela do quadro mantém o controle de um modo de exibição ativo no momento que é independente da janela ativa do Windows ou o foco de entrada atual. Quando o quadro é reativado, a exibição ativa é notificada por meio da chamada `CView::OnActivateView`.

- Comando mensagens e muitas mensagens de notificação de quadro comuns, incluindo aqueles manipulados pela `OnSetFocus`, `OnHScroll`, e `OnVScroll` funções de `CWnd`, são delegadas por um `CFrameWnd` janela do quadro para a exibição ativa no momento.

- A exibição ativa no momento (ou a janela do quadro de filho MDI ativa no momento no caso de um quadro MDI) pode determinar a legenda da janela do quadro. Esse recurso pode ser desabilitado, desativando o bit de estilo FWS_ADDTOTITLE da janela do quadro.

- Um `CFrameWnd` janela do quadro que gerencia o posicionamento das outras janelas filho dentro da área de cliente da janela de quadro, exibições e as barras de controle. Uma janela de quadro também faz a atualização de tempo ocioso da barra de ferramentas e outros botões da barra de controle. Um `CFrameWnd` janela de quadro também tem implementações padrão de comandos para ativar e desativar a barra de ferramentas e barras de status.

- Um `CFrameWnd` gerencia a janela do quadro a barra de menus principal. Quando um menu pop-up é exibido, a janela de quadro usa o mecanismo UPDATE_COMMAND_UI para determinar quais itens de menu devem ser habilitados, desabilitados ou marcadas. Quando o usuário seleciona um item de menu, a janela do quadro atualiza a barra de status com a cadeia de caracteres de mensagem para o comando.

- Um `CFrameWnd` janela de quadro possui uma tabela de aceleradores opcional que converte automaticamente os aceleradores de teclado.

- Um `CFrameWnd` janela de quadro tem uma ID de ajuda opcionais definidos com `LoadFrame` que é usado para obter ajuda contextual. Uma janela do quadro é o principal orquestrador de estados semimodais como modos de visualização de impressão e ajuda contextual (SHIFT + F1).

- Um `CFrameWnd` janela do quadro abrirá um arquivo do Gerenciador de arquivos de arrastado e solto sobre a janela do quadro. Se uma extensão de arquivo é registrada e associada ao aplicativo, a janela do quadro responde às dinâmico de dados (DDE) do exchange solicitação aberta que ocorre quando o usuário abre um arquivo de dados no Gerenciador de arquivos ou quando o `ShellExecute` Windows função é chamada.

- Se a janela do quadro é a janela principal do aplicativo (ou seja, `CWinThread::m_pMainWnd`), quando o usuário fecha o aplicativo, a janela do quadro solicita ao usuário para salvar todos os documentos modificados (para `OnClose` e `OnQueryEndSession`).

- Se a janela do quadro é a janela principal do aplicativo, a janela do quadro é o contexto para a execução de WinHelp. Fechando a janela do quadro será desligado WINHELP. EXE se ele foi iniciado para obter ajuda para este aplicativo.

Não use o C++ **excluir** operador para destruir uma janela do quadro. Use `CWnd::DestroyWindow` em seu lugar. O `CFrameWnd` implementação de `PostNcDestroy` excluirá o objeto de C++, quando a janela for destruída. Quando o usuário fechar a janela do quadro, o padrão `OnClose` manipulador chamará `DestroyWindow`.

Para obter mais informações sobre `CFrameWnd`, consulte [quadro Windows](../../mfc/frame-windows.md).

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

[CObject](../../mfc/reference/cobject-class.md)

[CCmdTarget](../../mfc/reference/ccmdtarget-class.md)

[CWnd](../../mfc/reference/cwnd-class.md)

`CFrameWnd`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** afxwin. h

##  <a name="activateframe"></a>  CFrameWnd::ActivateFrame

Chame essa função de membro para ativar e restaurar a janela do quadro para que fique visível e disponível para o usuário.

```
virtual void ActivateFrame(int nCmdShow = -1);
```

### <a name="parameters"></a>Parâmetros

*nCmdShow*<br/>
Especifica o parâmetro para passar para [CWnd::ShowWindow](../../mfc/reference/cwnd-class.md#showwindow). Por padrão, o quadro é mostrado e restaurado corretamente.

### <a name="remarks"></a>Comentários

Geralmente, essa função membro é chamada após um evento de interface de não usuário, como DDE, OLE ou outro evento que pode mostrar a janela do quadro ou seu conteúdo para o usuário.

A implementação padrão ativa o quadro e coloca-o na parte superior da ordem Z e, se necessário, executa as mesmas etapas para a janela do quadro principal do aplicativo.

Substitua essa função de membro para alterar como um quadro é ativado. Por exemplo, você pode forçar janelas MDI filho a ser maximizada. Adicionar a funcionalidade apropriada e, em seguida, chamar a versão da classe base com um explícito *nCmdShow*.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFCWindowing#1](../../mfc/reference/codesnippet/cpp/cframewnd-class_1.cpp)]

##  <a name="beginmodalstate"></a>  CFrameWnd::BeginModalState

Chame essa função de membro para tornar uma janela com moldura modal.

```
virtual void BeginModalState();
```

##  <a name="cframewnd"></a>  CFrameWnd::CFrameWnd

Constrói um `CFrameWnd` do objeto, mas não cria a janela do quadro visíveis.

```
CFrameWnd();
```

### <a name="remarks"></a>Comentários

Chamar `Create` para criar a janela visível.

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

*lpszClassName*<br/>
Aponta para uma cadeia de caracteres terminada em nulo que nomeia a classe Windows. O nome de classe pode ser qualquer nome registrado com o `AfxRegisterWndClass` função global ou o `RegisterClass` função do Windows. Se for NULL, usa o padrão predefinido `CFrameWnd` atributos.

*lpszWindowName*<br/>
Aponta para uma cadeia de caracteres com terminação nula que representa o nome da janela. Usado como o texto da barra de título.

*dwStyle*<br/>
Especifica a janela [estilo](../../mfc/reference/styles-used-by-mfc.md#window-styles) atributos. Inclua o estilo FWS_ADDTOTITLE se desejar que a barra de título para exibir automaticamente o nome do documento representado na janela.

*Rect*<br/>
Especifica o tamanho e posição da janela. O *rectDefault* valor permite que o Windows especificar o tamanho e posição da nova janela.

*pParentWnd*<br/>
Especifica a janela pai dessa janela de quadro. Esse parâmetro deve ser NULL para janelas de quadro de nível superior.

*lpszMenuName*<br/>
Identifica o nome do recurso de menu a ser usado com a janela. Use MAKEINTRESOURCE se o menu tem uma ID de inteiro em vez de uma cadeia de caracteres. Esse parâmetro pode ser NULL.

*dwExStyle*<br/>
Especifica a janela estendida [estilo](../../mfc/reference/styles-used-by-mfc.md#extended-window-styles) atributos.

*pContext*<br/>
Especifica um ponteiro para um [CCreateContext](../../mfc/reference/ccreatecontext-structure.md) estrutura. Esse parâmetro pode ser NULL.

### <a name="return-value"></a>Valor de retorno

Diferente de zero se a inicialização for bem-sucedida; Caso contrário, 0.

### <a name="remarks"></a>Comentários

Construir um `CFrameWnd` objeto em duas etapas. Primeiro, invocar o construtor, que constrói a `CFrameWnd` do objeto e, em seguida, chame `Create`, que cria a janela de quadro do Windows e anexa-o para o `CFrameWnd` objeto. `Create` inicializa o nome da classe da janela e o nome da janela e registra os valores padrão para o seu estilo, o pai e o menu associado.

Use `LoadFrame` em vez de `Create` para carregar a janela do quadro de um recurso em vez de especificar seus argumentos.

##  <a name="createview"></a>  CFrameWnd::CreateView

Chamar `CreateView` para criar uma exibição em um quadro.

```
CWnd* CreateView(
    CCreateContext* pContext,
    UINT nID = AFX_IDW_PANE_FIRST);
```

### <a name="parameters"></a>Parâmetros

*pContext*<br/>
Especifica o tipo de exibição e o documento.

*nID*<br/>
O número de identificação de um modo de exibição.

### <a name="return-value"></a>Valor de retorno

Ponteiro para um `CWnd` objeto se for bem-sucedido; caso contrário, NULL.

### <a name="remarks"></a>Comentários

Usar essa função de membro para criar "exibições" que não são `CView`-derivadas dentro de um quadro. Depois de chamar `CreateView`, você deve definir o modo como o Active Directory manualmente e defini-lo para ser visível; essas tarefas não são executadas automaticamente pelo `CreateView`.

##  <a name="dockcontrolbar"></a>  CFrameWnd::DockControlBar

Faz com que uma barra de controle encaixado na janela do quadro.

```
void DockControlBar(
    CControlBar* pBar,
    UINT nDockBarID = 0,
    LPCRECT lpRect = NULL);
```

### <a name="parameters"></a>Parâmetros

*pBar*<br/>
Aponta para a barra de controle encaixado.

*nDockBarID*<br/>
Determina qual lado da janela do quadro a serem considerados para encaixar. Ele pode ser 0, ou um ou mais das seguintes opções:

- AFX_IDW_DOCKBAR_TOP Dock para o lado superior da janela do quadro.

- Encaixar na AFX_IDW_DOCKBAR_BOTTOM lado inferior da janela do quadro.

- AFX_IDW_DOCKBAR_LEFT Dock para o lado esquerdo da janela do quadro.

- AFX_IDW_DOCKBAR_RIGHT Dock para o lado direito da janela do quadro.

Se for 0, a barra de controle pode ser encaixada de qualquer lado habilitado para encaixar na janela de quadro de destino.

*lpRect*<br/>
Determina, em coordenadas da tela, em que a barra de controle será encaixada na área não cliente da janela de quadro de destino.

### <a name="remarks"></a>Comentários

A barra de controle será encaixada para um dos lados da janela do quadro especificado nas chamadas para ambos [CControlBar::EnableDocking](../../mfc/reference/ccontrolbar-class.md#enabledocking) e [CFrameWnd::EnableDocking](#enabledocking). O escolhido lado é determinado pela *nDockBarID*.

##  <a name="enabledocking"></a>  CFrameWnd::EnableDocking

Chame essa função para habilitar as barras de controle encaixáveis em uma janela do quadro.

```
void EnableDocking(DWORD dwDockStyle);
```

### <a name="parameters"></a>Parâmetros

*dwDockStyle*<br/>
Especifica quais lados da janela de quadro podem servir como sites para barras de controle de encaixe. Ele pode ser um ou mais das seguintes opções:

- CBRS_ALIGN_TOP permite o encaixe na parte superior da área de cliente.

- CBRS_ALIGN_BOTTOM permite o encaixe na parte inferior da área de cliente.

- CBRS_ALIGN_LEFT permite o encaixe no lado esquerdo da área de cliente.

- CBRS_ALIGN_RIGHT permite o encaixe no lado direito da área de cliente.

- CBRS_ALIGN_ANY permite o encaixe em qualquer lado da área de cliente.

### <a name="remarks"></a>Comentários

Por padrão, as barras de controle serão encaixadas para um lado da janela do quadro na seguinte ordem: superior, inferior, esquerda, direita.

### <a name="example"></a>Exemplo

  Veja o exemplo de [CToolBar::Create](../../mfc/reference/ctoolbar-class.md#create).

##  <a name="endmodalstate"></a>  CFrameWnd::EndModalState

Chame essa função de membro para alterar uma janela do quadro de janela restrita para sem janela restrita.

```
virtual void EndModalState();
```

### <a name="remarks"></a>Comentários

`EndModalState` permite que todas as janelas desabilitadas por [BeginModalState](#beginmodalstate).

##  <a name="floatcontrolbar"></a>  CFrameWnd::FloatControlBar

Chame essa função para fazer com que uma barra de controle não seja encaixado na janela do quadro.

```
void FloatControlBar(
    CControlBar* pBar,
    CPoint point,
    DWORD dwStyle = CBRS_ALIGN_TOP);
```

### <a name="parameters"></a>Parâmetros

*pBar*<br/>
Aponta para a barra de controle para ser flutuante.

*ponto*<br/>
O local, em coordenadas da tela, onde o canto superior esquerdo da barra de controle será colocado.

*dwStyle*<br/>
Especifica se deve ser alinhado a barra de controle horizontal ou verticalmente dentro de sua nova janela de quadro. Ele pode ser qualquer um dos seguintes:

- CBRS_ALIGN_TOP orienta a barra de controle verticalmente.

- CBRS_ALIGN_BOTTOM orienta a barra de controle verticalmente.

- CBRS_ALIGN_LEFT orienta a barra de controle horizontalmente.

- CBRS_ALIGN_RIGHT orienta a barra de controle horizontalmente.

Se os estilos são passados para especificar a orientação horizontal e vertical, a barra de ferramentas será orientada horizontalmente.

### <a name="remarks"></a>Comentários

Normalmente, isso é feito na inicialização do aplicativo quando o programa está restaurando as configurações da execução anterior.

Essa função é chamada pelo framework quando o usuário faz com que uma operação de soltar soltando o botão esquerdo do mouse enquanto arrasta a barra de controle sobre um local que não está disponível para encaixar.

##  <a name="getactivedocument"></a>  CFrameWnd::GetActiveDocument

Chame essa função de membro para obter um ponteiro para a atual `CDocument` anexado ao modo de exibição ativo atual.

```
virtual CDocument* GetActiveDocument();
```

### <a name="return-value"></a>Valor de retorno

Um ponteiro para o atual [CDocument](../../mfc/reference/cdocument-class.md). Se não houver nenhum documento atual, retorna NULL.

##  <a name="getactiveframe"></a>  CFrameWnd::GetActiveFrame

Chame essa função de membro para obter um ponteiro para o Active Directory várias janela filho de MDI (interface MDI) de documento de uma janela de quadro MDI.

```
virtual CFrameWnd* GetActiveFrame();
```

### <a name="return-value"></a>Valor de retorno

Um ponteiro para a janela filho MDI ativo. Se o aplicativo é um aplicativo SDI ou a janela do quadro MDI não tem nenhum documento ativo, implícito **isso** ponteiro será retornado.

### <a name="remarks"></a>Comentários

Se não houver nenhum filho MDI ativo ou o aplicativo é uma interface de documento único (SDI) implícita **isso** ponteiro é retornado.

##  <a name="getactiveview"></a>  CFrameWnd::GetActiveView

Chame essa função de membro para obter um ponteiro para a exibição ativa (se houver) anexada a uma janela de quadro ( `CFrameWnd`).

```
CView* GetActiveView() const;
```

### <a name="return-value"></a>Valor de retorno

Um ponteiro para o atual [CView](../../mfc/reference/cview-class.md). Se não houver nenhum modo de exibição atual, retorna NULL.

### <a name="remarks"></a>Comentários

Essa função retorna nulo quando chamado de uma janela de quadro principal de MDI ( `CMDIFrameWnd`). Em um aplicativo MDI, a janela principal do quadro MDI não tem um modo de exibição associado a ele. Em vez disso, cada janela filho individual ( `CMDIChildWnd`) tem um ou mais modos de exibição associados. A exibição ativa em um aplicativo MDI pode ser obtida pela primeira vez encontrando a janela filho MDI ativo e, em seguida, localizar o modo de exibição ativo para essa janela filho. A janela filho MDI ativo pode ser encontrada chamando a função `MDIGetActive` ou `GetActiveFrame` conforme demonstrado a seguir:

[!code-cpp[NVC_MFCWindowing#2](../../mfc/reference/codesnippet/cpp/cframewnd-class_2.cpp)]

##  <a name="getcontrolbar"></a>  CFrameWnd::GetControlBar

Chamar `GetControlBar` para acessar a barra de controle que está associada com a ID.

```
CControlBar* GetControlBar(UINT nID);
```

### <a name="parameters"></a>Parâmetros

*nID*<br/>
O número de identificação de uma barra de controle.

### <a name="return-value"></a>Valor de retorno

Um ponteiro para a barra de controle que está associado com a ID.

### <a name="remarks"></a>Comentários

O *nID* parâmetro refere-se para o identificador exclusivo passado para o `Create` método da barra de controle. Para obter mais informações sobre barras de controle, consulte o tópico intitulado [barras de controle](../../mfc/control-bars.md).

`GetControlBar` retornará a barra de controle, mesmo se ele está flutuando e, portanto, não é atualmente uma janela filho do quadro.

##  <a name="getdockstate"></a>  CFrameWnd::GetDockState

Chame essa função de membro para armazenar informações de estado sobre barras de controle da janela de quadro em uma `CDockState` objeto.

```
void GetDockState(CDockState& state) const;
```

### <a name="parameters"></a>Parâmetros

*state*<br/>
Contém o estado atual das barras de controle da janela de quadro após o retorno.

### <a name="remarks"></a>Comentários

Em seguida, você pode gravar o conteúdo de `CDockState` para o armazenamento usando `CDockState::SaveState` ou `Serialize`. Se posteriormente você desejar restaurar as barras de controle para um estado anterior, carregar o estado com `CDockState::LoadState` ou `Serialize`, em seguida, chame `SetDockState` para aplicar o estado anterior a barras de controle da janela do quadro.

##  <a name="getmenubarstate"></a>  CFrameWnd::GetMenuBarState

Recupera o estado de exibição do menu no aplicativo MFC atual.

```
virtual DWORD GetMenuBarState();
```

### <a name="return-value"></a>Valor de retorno

O valor de retorno pode ter os seguintes valores:

- AFX_MBS_VISIBLE (0x01) – menu está visível.

- AFX_MBS_HIDDEN (0x02) – menu está oculto.

### <a name="remarks"></a>Comentários

Se ocorrer um erro de tempo de execução, esse método asserções in no modo de depuração e gera uma exceção que deriva de [CException](../../mfc/reference/cexception-class.md) classe.

##  <a name="getmenubarvisibility"></a>  CFrameWnd::GetMenuBarVisibility

Indica se o estado padrão do menu no aplicativo MFC atual está visível ou oculto.

```
virtual DWORD CFrameWnd::GetMenuBarVisibility();
```

### <a name="return-value"></a>Valor de retorno

Esse método retorna um dos seguintes valores:

- AFX_MBV_KEEPVISIBLE (0x01) – o menu é exibido em todos os momentos e por padrão não tem o foco.

- AFX_MBV_DISPLAYONFOCUS (0x02) – menu está oculto por padrão. Se o menu estiver oculto, pressione a tecla ALT para exibir o menu e dê a ele o foco. Se o menu é exibido, pressione a tecla ALT ou ESC para ocultá-la.

- AFX_MBV_ DISPLAYONFOCUS (0x02) &#124; AFX_MBV_DISPLAYONF10 (0x04) (combinação bit a bit (OR)) - menu está oculto por padrão. Se o menu estiver oculto, pressione a tecla F10 para exibir o menu e dê a ele o foco. Se o menu é exibido, pressione a tecla F10 para alternar o foco ou desativar o menu. O menu é exibido até que você pressionar a tecla ALT ou ESC para ocultá-la.

### <a name="remarks"></a>Comentários

Se ocorrer um erro de tempo de execução, esse método asserções in no modo de depuração e gera uma exceção que deriva de [CException](../../mfc/reference/cexception-class.md) classe.

##  <a name="getmessagebar"></a>  CFrameWnd::GetMessageBar

Chame essa função de membro para obter um ponteiro para a barra de status.

```
virtual CWnd* GetMessageBar();
```

### <a name="return-value"></a>Valor de retorno

Ponteiro para a janela da barra de status.

##  <a name="getmessagestring"></a>  CFrameWnd::GetMessageString

Substitua essa função para fornecer cadeias de caracteres personalizadas para IDs de comando.

```
virtual void GetMessageString(
    UINT nID,
    CString& rMessage) const;
```

### <a name="parameters"></a>Parâmetros

*nID*<br/>
ID do recurso da mensagem desejada.

*rMessage*<br/>
`CString` objeto no qual colocar a mensagem.

### <a name="remarks"></a>Comentários

A implementação padrão simplesmente carrega a cadeia de caracteres especificada por *nID* do arquivo de recurso. Essa função é chamada pelo framework quando a cadeia de caracteres de mensagem na barra de status precisa ser atualizado.

##  <a name="gettitle"></a>  CFrameWnd::GetTitle

Recupera o título do objeto window.

```
CString GetTitle() const;
```

### <a name="return-value"></a>Valor de retorno

Um [CString](../../atl-mfc-shared/reference/cstringt-class.md) objeto que contém o título atual do objeto window.

##  <a name="initialupdateframe"></a>  CFrameWnd::InitialUpdateFrame

Chame `IntitialUpdateFrame` depois de criar um novo quadro com `Create`.

```
void InitialUpdateFrame(
    CDocument* pDoc,
    BOOL bMakeVisible);
```

### <a name="parameters"></a>Parâmetros

*pDoc*<br/>
Aponta para o documento ao qual a janela do quadro está associada. Pode ser NULL.

*bMakeVisible*<br/>
Se for TRUE, indica que o quadro deve se tornar visíveis e ativos. Se for FALSE, nenhum descendentes se tornam visíveis.

### <a name="remarks"></a>Comentários

Isso faz com que todos os modos de exibição nessa janela de quadro para receber seus `OnInitialUpdate` chamadas.

Além disso, se não havia anteriormente um modo de exibição ativo, o modo de exibição principal da janela do quadro ficará ativo. O modo de exibição primário é uma exibição com uma ID de AFX_IDW_PANE_FIRST filho. Por fim, a janela do quadro se torna visível se *bMakeVisible* é diferente de zero. Se *bMakeVisible* for 0, o foco atual e o estado visível da janela do quadro permanecerá inalterados. Não é necessário chamar essa função ao usar a implementação da estrutura de arquivo novo e abrir arquivo.

##  <a name="inmodalstate"></a>  CFrameWnd::InModalState

Chame essa função de membro para verificar se uma janela do quadro é modal ou sem janela restrita.

```
BOOL InModalState() const;
```

### <a name="return-value"></a>Valor de retorno

Diferente de zero se Sim; Caso contrário, 0.

##  <a name="istracking"></a>  CFrameWnd::IsTracking

Chame essa função de membro para determinar se a barra de divisão na janela está sendo movida no momento.

```
BOOL IsTracking() const;
```

### <a name="return-value"></a>Valor de retorno

Diferente de zero se uma operação de divisão está em andamento. Caso contrário, 0.

##  <a name="loadacceltable"></a>  CFrameWnd::LoadAccelTable

Chamada para carregar a tabela do acelerador especificado.

```
BOOL LoadAccelTable(LPCTSTR lpszResourceName);
```

### <a name="parameters"></a>Parâmetros

*lpszResourceName*<br/>
Identifica o nome do recurso acelerador. Use MAKEINTRESOURCE se o recurso é identificado com uma ID de inteiro.

### <a name="return-value"></a>Valor de retorno

Diferente de zero se a tabela de aceleradores foi carregada com êxito; Caso contrário, 0.

### <a name="remarks"></a>Comentários

Somente uma tabela pode ser carregada ao mesmo tempo.

Tabelas de aceleradores carregadas de recursos são liberadas automaticamente quando o aplicativo é encerrado.

Se você chamar `LoadFrame` para criar a janela do quadro, o framework carrega uma tabela de aceleradores junto com os recursos de menu e o ícone e uma chamada subsequente para essa função membro, em seguida, é desnecessária.

##  <a name="loadbarstate"></a>  CFrameWnd::LoadBarState

Chame essa função para restaurar as configurações de cada barra de controle pertencentes a janela do quadro.

```
void LoadBarState(LPCTSTR lpszProfileName);
```

### <a name="parameters"></a>Parâmetros

*lpszProfileName*<br/>
Nome de uma seção no arquivo de inicialização (INI) ou uma chave do registro do Windows em que as informações de estado são armazenadas.

### <a name="remarks"></a>Comentários

Informações restauradas incluem visibilidade e posição da barra de controle, estado de encaixe e orientação horizontal/vertical.

As configurações que você deseja restaurar devem ser gravadas no registro antes de chamar `LoadBarState`. Gravar as informações no registro, chamando [CWinApp::SetRegistryKey](../../mfc/reference/cwinapp-class.md#setregistrykey). Gravar as informações no arquivo INI chamando [SaveBarState](#savebarstate).

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

*nIDResource*<br/>
A ID de recursos compartilhados associados com a janela do quadro.

*dwDefaultStyle*<br/>
O quadro [estilo](../../mfc/reference/styles-used-by-mfc.md#window-styles). Inclua o estilo FWS_ADDTOTITLE se desejar que a barra de título para exibir automaticamente o nome do documento representado na janela.

*pParentWnd*<br/>
Um ponteiro para o pai do quadro.

*pContext*<br/>
Um ponteiro para um [CCreateContext](../../mfc/reference/ccreatecontext-structure.md) estrutura. Esse parâmetro pode ser NULL.

### <a name="remarks"></a>Comentários

Construir um `CFrameWnd` objeto em duas etapas. Primeiro, invocar o construtor, que constrói a `CFrameWnd` do objeto e, em seguida, chame `LoadFrame`, que carrega a janela de quadro do Windows e os recursos associados e anexa a janela do quadro para o `CFrameWnd` objeto. O *nIDResource* parâmetro especifica o menu, a tabela de aceleradores, o ícone e o recurso de cadeia de caracteres do título para a janela do quadro.

Use o `Create` função de membro em vez de `LoadFrame` quando você deseja especificar todos os parâmetros de criação da janela do quadro.

A estrutura chama `LoadFrame` quando ele cria uma janela de quadro usando um objeto de modelo de documento.

A estrutura usa a *pContext* argumento para especificar os objetos sejam conectadas a janela do quadro, incluindo qualquer contidos objetos de exibição. Você pode definir as *pContext* argumento como NULL quando você chama `LoadFrame`.

##  <a name="m_bautomenuenable"></a>  CFrameWnd::m_bAutoMenuEnable

Quando este membro de dados está habilitado (que é o padrão), os itens de menu que não têm manipuladores ON_UPDATE_COMMAND_UI ou ON_COMMAND serão desabilitados automaticamente quando o usuário efetua pull de um menu suspenso.

```
BOOL m_bAutoMenuEnable;
```

### <a name="remarks"></a>Comentários

Itens de menu que têm um manipulador ON_COMMAND mas nenhum manipulador ON_UPDATE_COMMAND_UI serão habilitados automaticamente.

Quando este membro de dados é definido, itens de menu são habilitados automaticamente da mesma forma que os botões da barra de ferramentas estão habilitados.

> [!NOTE]
> `m_bAutoMenuEnable` não tem nenhum efeito nos itens de menu de nível superior.

Este membro de dados simplifica a implementação de comandos opcionais com base na seleção atual e reduz a necessidade de escrever manipuladores ON_UPDATE_COMMAND_UI para habilitar e desabilitar itens de menu.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFCWindowing#3](../../mfc/reference/codesnippet/cpp/cframewnd-class_3.cpp)]

##  <a name="negotiateborderspace"></a>  CFrameWnd::NegotiateBorderSpace

Chame essa função de membro para negociar o espaço de borda em uma janela de quadro durante a ativação de local OLE.

```
virtual BOOL NegotiateBorderSpace(
    UINT nBorderCmd,
    LPRECT lpRectBorder);
```

### <a name="parameters"></a>Parâmetros

*nBorderCmd*<br/>
Contém um dos seguintes valores do `enum BorderCmd`:

- `borderGet` = 1

- `borderRequest` = 2

- `borderSet` = 3

*lpRectBorder*<br/>
Ponteiro para um [RECT](/windows/desktop/api/windef/ns-windef-tagrect) estrutura ou um [CRect](../../atl-mfc-shared/reference/crect-class.md) objeto que especifica as coordenadas da borda.

### <a name="return-value"></a>Valor de retorno

Diferente de zero se bem-sucedido; Caso contrário, 0.

### <a name="remarks"></a>Comentários

Essa função de membro é o `CFrameWnd` implementação de negociação de espaço de borda do OLE.

##  <a name="onbarcheck"></a>  CFrameWnd::OnBarCheck

Chamado sempre que uma ação é executada na barra de controle especificado.

```
afx_msg BOOL OnBarCheck(UINT nID);
```

### <a name="parameters"></a>Parâmetros

*nID*<br/>
A ID do controle de barra que está sendo mostrado.

### <a name="return-value"></a>Valor de retorno

Diferente de zero se a barra de controle existir; Caso contrário, 0.

##  <a name="oncontexthelp"></a>  CFrameWnd::OnContextHelp

Manipula SHIFT + F1 Ajuda para os itens no local.

```
afx_msg void OnContextHelp();
```

### <a name="remarks"></a>Comentários

Para habilitar a Ajuda contextual, você deve adicionar um

[!code-cpp[NVC_MFCDocViewSDI#16](../../mfc/codesnippet/cpp/cframewnd-class_4.cpp)]

instrução para seu `CFrameWnd` mapa de mensagem de classe e também adicionar uma entrada de tabela de aceleradores, normalmente SHIFT + F1, para ativar essa função de membro.

Se seu aplicativo for um OLE Container, `OnContextHelp` coloca todos os itens no local contidos no objeto de janela do quadro no modo de Ajuda. O cursor muda para uma seta e um ponto de interrogação e o usuário pode, em seguida, mova o ponteiro do mouse e pressione o botão esquerdo do mouse para selecionar uma caixa de diálogo, janela, menu ou botão de comando. Essa função membro chama a função do Windows `WinHelp` com o contexto da Ajuda do objeto sob o cursor.

##  <a name="oncreateclient"></a>  CFrameWnd::OnCreateClient

Chamado pelo framework durante a execução de `OnCreate`.

```
virtual BOOL OnCreateClient(
    LPCREATESTRUCT lpcs,
    CCreateContext* pContext);
```

### <a name="parameters"></a>Parâmetros

*denominado LPC*<br/>
Um ponteiro para um Windows [CREATESTRUCT](/windows/desktop/api/winuser/ns-winuser-tagcreatestructa) estrutura.

*pContext*<br/>
Um ponteiro para um [CCreateContext](../../mfc/reference/ccreatecontext-structure.md) estrutura.

### <a name="return-value"></a>Valor de retorno

Diferente de zero se bem-sucedido; Caso contrário, 0.

### <a name="remarks"></a>Comentários

Nunca chame essa função.

A implementação padrão dessa função cria uma `CView` objeto das informações fornecidas em *pContext*, se possível.

Substituir essa função para substituir os valores passados no `CCreateContext` de objeto ou para alterar os maneira como os controles na área de cliente principal da janela do quadro são criados. O `CCreateContext` você pode substituir os membros são descritos em de [CCreateContext](../../mfc/reference/ccreatecontext-structure.md) classe.

> [!NOTE]
>  Não substitua os valores passados no `CREATESTRUCT` estrutura. Eles são somente para fins informativos. Se você quiser substituir o retângulo da janela inicial, por exemplo, substituir a `CWnd` função de membro [PreCreateWindow](../../mfc/reference/cwnd-class.md#precreatewindow).

##  <a name="onhidemenubar"></a>  CFrameWnd::OnHideMenuBar

Essa função é chamada quando o sistema está prestes a ocultar a barra de menu no aplicativo MFC atual.

```
virtual void OnHideMenuBar();
```

### <a name="remarks"></a>Comentários

Esse manipulador de eventos permite que seu aplicativo executar ações personalizadas quando o sistema está prestes a ocultar o menu. Você não pode impedir que o menu sendo ocultada, mas você pode, por exemplo, chamar outros métodos para recuperar o estado ou o estilo de menu.

##  <a name="onsetpreviewmode"></a>  CFrameWnd::OnSetPreviewMode

Chame essa função de membro para definir a janela do quadro principal do aplicativo para dentro e fora do modo de visualização de impressão.

```
virtual void OnSetPreviewMode(
    BOOL bPreview,
    CPrintPreviewState* pState);
```

### <a name="parameters"></a>Parâmetros

*bPreview*<br/>
Especifica se deve ou não colocar o aplicativo no modo de visualização de impressão. Defina como verdadeiro para colocar na visualização de impressão, FALSE para cancelar o modo de visualização.

*pState*<br/>
Um ponteiro para um `CPrintPreviewState` estrutura.

### <a name="remarks"></a>Comentários

A implementação padrão desabilita todas as barras de ferramentas padrão e oculta o menu principal e a janela principal do cliente. Isso transforma janelas de quadro MDI em janelas de quadro SDI temporárias.

Substitua essa função de membro para personalizar a exibição e ocultação de barras de controle e outras partes da janela de quadro durante a visualização de impressão. Chame a implementação de classe base de dentro a versão substituída.

##  <a name="onshowmenubar"></a>  CFrameWnd::OnShowMenuBar

Essa função é chamada quando o sistema está prestes a exibir a barra de menu no aplicativo MFC atual.

```
virtual void OnShowMenuBar();
```

### <a name="remarks"></a>Comentários

Esse manipulador de eventos permite que seu aplicativo executar ações personalizadas quando o menu está prestes a ser exibido. Você não pode impedir que o menu seja exibida, mas você pode, por exemplo, chamar outros métodos para recuperar o estado ou o estilo de menu.

##  <a name="onupdatecontrolbarmenu"></a>  CFrameWnd::OnUpdateControlBarMenu

Chamado pelo framework quando o menu associado é atualizado.

```
afx_msg void OnUpdateControlBarMenu(CCmdUI* pCmdUI);
```

### <a name="parameters"></a>Parâmetros

*pCmdUI*<br/>
Um ponteiro para um [CCmdUI](../../mfc/reference/ccmdui-class.md) objeto que representa o menu que gerou o comando update. Chamadas do manipulador de atualização do [habilitar](../../mfc/reference/ccmdui-class.md#enable) função de membro da `CCmdUI` por meio do objeto *pCmdUI* para atualizar a interface do usuário.

##  <a name="recalclayout"></a>  CFrameWnd::RecalcLayout

Chamado pelo framework quando as barras de controle padrão são ativadas ou desativados ou quando a janela do quadro é redimensionada.

```
virtual void RecalcLayout(BOOL bNotify = TRUE);
```

### <a name="parameters"></a>Parâmetros

*bNotify*<br/>
Determina se o item ativo in-loco para a janela do quadro recebe notificação de alteração de layout. Se for TRUE, o item é notificado; Caso contrário, FALSE.

### <a name="remarks"></a>Comentários

A implementação padrão essa função membro chama o `CWnd` função de membro `RepositionBars` reposicionar as barras de controle no quadro, bem como na janela principal do cliente (geralmente um `CView` ou MDICLIENT).

Substitua essa função de membro para controlar a aparência e comportamento das barras de controle depois que o layout da janela do quadro foi alterado. Por exemplo, chamá-lo quando você ativa ou desativar a barras de controle ou adiciona outra barra de controle.

##  <a name="rectdefault"></a>  CFrameWnd::rectDefault

Passe essa estático `CRect` como um parâmetro durante a criação de uma janela para permitir que o Windows escolher o tamanho inicial e a posição da janela.

```
static AFX_DATA const CRect rectDefault;
```

##  <a name="savebarstate"></a>  CFrameWnd::SaveBarState

Chame essa função para armazenar informações sobre cada barra de controle pertencente a janela do quadro.

```
void SaveBarState(LPCTSTR lpszProfileName) const;
```

### <a name="parameters"></a>Parâmetros

*lpszProfileName*<br/>
Nome de uma seção no arquivo de inicialização ou uma chave do registro do Windows em que as informações de estado são armazenadas.

### <a name="remarks"></a>Comentários

Essas informações podem ser lidos do arquivo de inicialização usando [LoadBarState](#loadbarstate). As informações armazenadas incluem visibilidade, orientação horizontal/vertical, estado e a posição da barra de controle de encaixe.

##  <a name="setactivepreviewview"></a>  CFrameWnd::SetActivePreviewView

Designa o modo de exibição especificado para ser o modo de exibição ativo para visualização avançada.

```
void SetActivePreviewView(CView* pViewNew);
```

### <a name="parameters"></a>Parâmetros

*pViewNew*<br/>
Um ponteiro para um modo de exibição a ser ativado.

### <a name="remarks"></a>Comentários

##  <a name="setactiveview"></a>  CFrameWnd::SetActiveView

Chame essa função de membro para definir o modo ativo.

```
void SetActiveView(
    CView* pViewNew,
    BOOL bNotify = TRUE);
```

### <a name="parameters"></a>Parâmetros

*pViewNew*<br/>
Especifica um ponteiro para um [CView](../../mfc/reference/cview-class.md) objeto, ou nulo para nenhum modo de exibição ativo.

*bNotify*<br/>
Especifica se a exibição é para ser notificado de ativação. Se for TRUE, `OnActivateView` é chamado para a nova exibição; se FALSE, não é.

### <a name="remarks"></a>Comentários

A estrutura chamará essa função automaticamente conforme o usuário altera o foco para um modo de exibição dentro da janela de quadro. Você pode chamar explicitamente `SetActiveView` para alterar o foco para a exibição especificada.

##  <a name="setdockstate"></a>  CFrameWnd::SetDockState

Chame essa função de membro para aplicar as informações de estado armazenadas em um `CDockState` objeto às barras de controle da janela do quadro.

```
void SetDockState(const CDockState& state);
```

### <a name="parameters"></a>Parâmetros

*state*<br/>
Aplica o estado armazenado para barras de controle da janela do quadro.

### <a name="remarks"></a>Comentários

Para restaurar um estado anterior das barras de controle, você pode carregar o estado armazenado com `CDockState::LoadState` ou `Serialize`, em seguida, use `SetDockState` aplicá-la em barras de controle da janela do quadro. O estado anterior é armazenado no `CDockState` do objeto com `GetDockState`

##  <a name="setmenubarstate"></a>  CFrameWnd::SetMenuBarState

Define o estado de exibição do menu no aplicativo MFC atual exibido ou oculto.

```
virtual BOOL SetMenuBarState(DWORD nState);
```

### <a name="parameters"></a>Parâmetros

|Parâmetro|Descrição|
|---------------|-----------------|
|*nState*|[in] Especifica se deseja exibir ou ocultar o menu. O *nState* parâmetro pode ter os seguintes valores:<br /><br />-AFX_MBS_VISIBLE (0x01) - exibe o menu, se ele está oculto, mas não tem nenhum efeito se ele estiver visível.<br />-AFX_MBS_HIDDEN (0x02) – oculta o menu, se ele estiver visível, mas não tem nenhum efeito se ele está oculto.|

### <a name="return-value"></a>Valor de retorno

TRUE se esse método com êxito altera o estado de menu; Caso contrário, FALSE.

### <a name="remarks"></a>Comentários

Se ocorrer um erro de tempo de execução, esse método asserções in no modo de depuração e gera uma exceção que deriva de [CException](../../mfc/reference/cexception-class.md) classe.

##  <a name="setmenubarvisibility"></a>  CFrameWnd::SetMenuBarVisibility

Define o comportamento padrão do menu no aplicativo MFC atual para ser visível ou oculto.

```
virtual void SetMenuBarVisibility(DWORD nStyle);
```

### <a name="parameters"></a>Parâmetros

|Parâmetro|Descrição|
|---------------|-----------------|
|*nStyle*|[in] Especifica se o menu é por padrão, ocultada, ou estiver visível e tem o foco. O *nStyle* parâmetro pode ter os seguintes valores:<br /><br />-AFX_MBV_KEEPVISIBLE (0X01)-<br />     O menu é exibido em todos os momentos e por padrão não tem o foco.<br />-AFX_MBV_DISPLAYONFOCUS (0X02)-<br />     O menu está oculto por padrão. Se o menu estiver oculto, pressione a tecla ALT para exibir o menu e dê a ele o foco. Se o menu é exibido, pressione a tecla ALT ou ESC para ocultar o menu.<br />-AFX_MBV_ DISPLAYONFOCUS (0x02) &#124; AFX_MBV_DISPLAYONF10 (0x04)<br />     (combinação bit a bit (OR)) - menu está oculto por padrão. Se o menu estiver oculto, pressione a tecla F10 para exibir o menu e dê a ele o foco. Se o menu é exibido, pressione a tecla F10 para alternar o foco ou desativar o menu. O menu é exibido até que você pressionar a tecla ALT ou ESC para ocultá-la.|

### <a name="remarks"></a>Comentários

Se o valor de *nStyle* parâmetro não é válido, esse método declara no modo de depuração e gera [CInvalidArgException](../../mfc/reference/cinvalidargexception-class.md) no modo de versão. No caso de outros erros de tempo de execução, esse método asserções in no modo de depuração e gera uma exceção derivada de [CException](../../mfc/reference/cexception-class.md) classe.

Esse método afeta o estado dos menus em aplicativos escritos para o Windows Vista e versões posteriores.

##  <a name="setmessagetext"></a>  CFrameWnd::SetMessageText

Chame essa função para colocar uma cadeia de caracteres no painel de barra de status que tem uma ID igual a 0.

```
void SetMessageText(LPCTSTR lpszText);
void SetMessageText(UINT nID);
```

### <a name="parameters"></a>Parâmetros

*lpszText*<br/>
Aponta para a cadeia de caracteres a ser colocado na barra de status.

*nID*<br/>
ID de recurso de cadeia de caracteres da cadeia de caracteres a ser colocado na barra de status.

### <a name="remarks"></a>Comentários

Isso normalmente é o painel mais à esquerda e mais longo, da barra de status.

##  <a name="setprogressbarposition"></a>  CFrameWnd::SetProgressBarPosition

Define a posição atual para a barra de progresso do Windows 7 exibida na barra de tarefas.

```
void SetProgressBarPosition(int nProgressPos);
```

### <a name="parameters"></a>Parâmetros

*nProgressPos*<br/>
Especifica a posição a ser definido. Ele deve estar dentro do intervalo definido por `SetProgressBarRange`.

### <a name="remarks"></a>Comentários

##  <a name="setprogressbarrange"></a>  CFrameWnd::SetProgressBarRange

Define o intervalo para a barra de progresso do Windows 7 exibido na barra de tarefas.

```
void SetProgressBarRange(
    int nRangeMin,
    int nRangeMax);
```

### <a name="parameters"></a>Parâmetros

*nRangeMin*<br/>
Valor mínimo.

*nRangeMax*<br/>
Valor máximo.

### <a name="remarks"></a>Comentários

##  <a name="setprogressbarstate"></a>  CFrameWnd::SetProgressBarState

Define o tipo e estado do indicador de progresso exibido em um botão de barra de tarefas.

```
void SetProgressBarState(TBPFLAG tbpFlags);
```

### <a name="parameters"></a>Parâmetros

*tbpFlags*<br/>
Sinalizadores que controlam o estado atual do botão de andamento. Especifique apenas um dos seguintes sinalizadores porque todos os estados são mutuamente exclusivos: TBPF_NOPROGRESS, TBPF_INDETERMINATE, TBPF_NORMAL, TBPF_ERROR, TBPF_PAUSED.

### <a name="remarks"></a>Comentários

##  <a name="settaskbaroverlayicon"></a>  CFrameWnd::SetTaskbarOverlayIcon

Sobrecarregado. Aplica-se de uma sobreposição para um botão de barra de tarefas para indicar o status do aplicativo ou para notificar o usuário.

```
BOOL SetTaskbarOverlayIcon(
    UINT nIDResource,
    LPCTSTR lpcszDescr);

BOOL SetTaskbarOverlayIcon(
    HICON hIcon,
    LPCTSTR lpcszDescr);
```

### <a name="parameters"></a>Parâmetros

*nIDResource*<br/>
Especifica a ID do recurso de um ícone a ser usado como a sobreposição. Consulte a descrição para *hIcon* para obter detalhes.

*lpcszDescr*<br/>
Um ponteiro para uma cadeia de caracteres que fornece uma versão de texto alt das informações transmitidas pela sobreposição, para fins de acessibilidade.

*hIcon*<br/>
O identificador de um ícone a ser usado como a sobreposição. Isso deve ser um pequeno ícone, medindo 16 x 16 pixels com 96 pontos por polegada (dpi). Se um ícone sobreposto for aplicado ao botão da barra de tarefas, essa sobreposição existente será substituída. Esse valor pode ser NULL. Como um valor NULL é tratado depende se o botão de barra de tarefas representa uma única janela ou um grupo do windows. É responsabilidade do aplicativo de chamada para liberar *hIcon* quando ele não for mais necessário.

### <a name="return-value"></a>Valor de retorno

VERDADEIRO se bem-sucedido; FALSE se a versão do sistema operacional é menor que o Windows 7 ou se ocorrer um erro o ícone de configuração.

### <a name="remarks"></a>Comentários

##  <a name="settitle"></a>  CFrameWnd::SetTitle

Define o título do objeto window.

```
void SetTitle(LPCTSTR lpszTitle);
```

### <a name="parameters"></a>Parâmetros

*lpszTitle*<br/>
Um ponteiro para uma cadeia de caracteres que contém o título do objeto window.

##  <a name="showcontrolbar"></a>  CFrameWnd::ShowControlBar

Chame essa função de membro para mostrar ou ocultar a barra de controle.

```
void ShowControlBar(
    CControlBar* pBar,
    BOOL bShow,
    BOOL bDelay);
```

### <a name="parameters"></a>Parâmetros

*pBar*<br/>
Ponteiro para a barra de controle para ser mostrado ou ocultado.

*bMostrar*<br/>
Se for TRUE, especifica que a barra de controle deve ser mostrado. Se for FALSE, especifica que a barra de controle deve ser ocultada.

*bDelay*<br/>
Se for TRUE, atraso mostrando a barra de controle. Se for FALSE, mostre o controle de barra imediatamente.

##  <a name="showownedwindows"></a>  CFrameWnd::ShowOwnedWindows

Chame essa função de membro para mostrar todas as janelas que são descendentes do `CFrameWnd` objeto.

```
void ShowOwnedWindows(BOOL bShow);
```

### <a name="parameters"></a>Parâmetros

*bMostrar*<br/>
Especifica se as janelas de propriedade devem ser mostrados ou ocultados.

## <a name="see-also"></a>Consulte também

[Classe CWnd](../../mfc/reference/cwnd-class.md)<br/>
[Gráfico da hierarquia](../../mfc/hierarchy-chart.md)<br/>
[Classe CWnd](../../mfc/reference/cwnd-class.md)<br/>
[Classe CMDIFrameWnd](../../mfc/reference/cmdiframewnd-class.md)<br/>
[Classe CMDIChildWnd](../../mfc/reference/cmdichildwnd-class.md)<br/>
[Classe CView](../../mfc/reference/cview-class.md)<br/>
[Classe CDocTemplate](../../mfc/reference/cdoctemplate-class.md)<br/>
[Estrutura CRuntimeClass](../../mfc/reference/cruntimeclass-structure.md)
