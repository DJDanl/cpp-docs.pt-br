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
ms.openlocfilehash: d2e043c8c9f4ad86636cd0e9ea7d695826b6c8fb
ms.sourcegitcommit: 3e8fa01f323bc5043a48a0c18b855d38af3648d4
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/06/2020
ms.locfileid: "78866419"
---
# <a name="cframewnd-class"></a>Classe CFrameWnd

Fornece a funcionalidade de uma janela de estrutura de pop-up ou janelas de documento único do Windows (SDI), juntamente com membros para gerenciar a janela.

## <a name="syntax"></a>Sintaxe

```
class CFrameWnd : public CWnd
```

## <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores públicos

|{1&gt;Nome&lt;1}|Descrição|
|----------|-----------------|
|[CFrameWnd:: CFrameWnd](#cframewnd)|Constrói um objeto `CFrameWnd`.|

### <a name="public-methods"></a>Métodos públicos

|{1&gt;Nome&lt;1}|Descrição|
|----------|-----------------|
|[CFrameWnd:: ActivateFrame](#activateframe)|Torna o quadro visível e disponível para o usuário.|
|[CFrameWnd:: BeginModalState](#beginmodalstate)|Define a janela do quadro como modal.|
|[CFrameWnd:: criar](#create)|Chame para criar e inicializar a janela de quadro do Windows associada ao objeto `CFrameWnd`.|
|[CFrameWnd:: CreateView](#createview)|Cria uma exibição dentro de um quadro que não é derivado de `CView`.|
|[CFrameWnd::D ockControlBar](#dockcontrolbar)|Encaixa uma barra de controle.|
|[CFrameWnd:: EnableDocking](#enabledocking)|Permite que uma barra de controle seja encaixada.|
|[CFrameWnd:: endjanelarestritastate](#endmodalstate)|Encerra o estado modal da janela do quadro. Habilita todas as janelas desabilitadas pelo `BeginModalState`.|
|[CFrameWnd:: FloatControlBar](#floatcontrolbar)|Flutua uma barra de controle.|
|[CFrameWnd:: GetActiveDocument](#getactivedocument)|Retorna o objeto de `CDocument` ativo.|
|[CFrameWnd:: GetActiveFrame](#getactiveframe)|Retorna o objeto de `CFrameWnd` ativo.|
|[CFrameWnd:: GetActiveView](#getactiveview)|Retorna o objeto de `CView` ativo.|
|[CFrameWnd:: GetControlBar](#getcontrolbar)|Recupera a barra de controle.|
|[CFrameWnd:: GetDockState](#getdockstate)|Recupera o estado de encaixe de uma janela do quadro.|
|[CFrameWnd:: getbarrademenustate](#getmenubarstate)|Recupera o estado de exibição do menu no aplicativo MFC atual.|
|[CFrameWnd:: GetMenuBarVisibility](#getmenubarvisibility)|Indica se o comportamento padrão do menu no aplicativo MFC atual está oculto ou visível.|
|[CFrameWnd:: GetMessageBar](#getmessagebar)|Retorna um ponteiro para a barra de status que pertence à janela do quadro.|
|[CFrameWnd:: GetMessageString](#getmessagestring)|Recupera a mensagem correspondente a uma ID de comando.|
|[CFrameWnd:: getTitle](#gettitle)|Recupera o título da barra de controle relacionada.|
|[CFrameWnd:: InitialUpdateFrame](#initialupdateframe)|Faz com que a função de membro `OnInitialUpdate` pertencente a todas as exibições na janela do quadro seja chamada.|
|[CFrameWnd:: injanelarestritastate](#inmodalstate)|Retorna um valor que indica se uma janela de quadro está ou não em um estado modal.|
|[CFrameWnd:: istracking](#istracking)|Determina se a barra de divisão está sendo movida no momento.|
|[CFrameWnd:: LoadAccelTable](#loadacceltable)|Chame para carregar uma tabela de acelerador.|
|[CFrameWnd:: LoadBarState](#loadbarstate)|Chame para restaurar as configurações da barra de controle.|
|[CFrameWnd:: LoadFrame](#loadframe)|Chame para criar dinamicamente uma janela de quadro por meio de informações de recursos.|
|[CFrameWnd:: NegotiateBorderSpace](#negotiateborderspace)|Negocia o espaço de borda na janela do quadro.|
|[CFrameWnd:: OnBarCheck](#onbarcheck)|Chamado sempre que uma ação é executada na barra de controle especificada.|
|[CFrameWnd:: OnContextHelp](#oncontexthelp)|Manipula a ajuda do SHIFT + F1 para itens no local.|
|[CFrameWnd:: OnSetPreviewMode](#onsetpreviewmode)|Define a janela do quadro principal do aplicativo dentro e fora do modo de visualização de impressão.|
|[CFrameWnd:: OnUpdateControlBarMenu](#onupdatecontrolbarmenu)|Chamado pelo Framework quando o menu associado é atualizado.|
|[CFrameWnd:: RecalcLayout](#recalclayout)|Reposiciona as barras de controle do objeto `CFrameWnd`.|
|[CFrameWnd:: SaveBarState](#savebarstate)|Chame para salvar as configurações da barra de controle.|
|[CFrameWnd:: SetActivePreviewView](#setactivepreviewview)|Designa a exibição especificada como a exibição ativa para visualização avançada.|
|[CFrameWnd:: SetActiveView](#setactiveview)|Define o objeto de `CView` ativo.|
|[CFrameWnd:: SetDockState](#setdockstate)|Chame para encaixar a janela do quadro na janela principal.|
|[CFrameWnd:: setbarrademenustate](#setmenubarstate)|Define o estado de exibição do menu no aplicativo MFC atual como oculto ou exibido.|
|[CFrameWnd:: SetMenuBarVisibility](#setmenubarvisibility)|Define o comportamento padrão do menu no aplicativo MFC atual como oculto ou visível.|
|[CFrameWnd:: SetMessageText](#setmessagetext)|Define o texto de uma barra de status padrão.|
|[CFrameWnd:: SetProgressBarPosition](#setprogressbarposition)|Define a posição atual da barra de progresso do Windows 7 exibida na barra de tarefas.|
|[CFrameWnd:: SetProgressBarRange](#setprogressbarrange)|Define o intervalo da barra de progresso do Windows 7 exibida na barra de tarefas.|
|[CFrameWnd:: setprogressbarstate](#setprogressbarstate)|Define o tipo e o estado do indicador de progresso exibido em um botão da barra de tarefas.|
|[CFrameWnd:: SetTaskbarOverlayIcon](#settaskbaroverlayicon)|Sobrecarregado. Aplica uma sobreposição a um botão da barra de tarefas para indicar o status do aplicativo ou uma notificação ao usuário.|
|[CFrameWnd:: SetTitle](#settitle)|Define o título da barra de controle relacionada.|
|[CFrameWnd:: ShowControlBar](#showcontrolbar)|Chame para mostrar a barra de controle.|
|[CFrameWnd:: ShowOwnedWindows](#showownedwindows)|Mostra todas as janelas descendentes do objeto `CFrameWnd`.|

### <a name="protected-methods"></a>Métodos protegidos

|{1&gt;Nome&lt;1}|Descrição|
|----------|-----------------|
|[CFrameWnd:: OnCreateClient](#oncreateclient)|Cria uma janela de cliente para o quadro.|
|[CFrameWnd:: OnHideMenuBar](#onhidemenubar)|Chamado antes que o menu no aplicativo do MFC atual esteja oculto.|
|[CFrameWnd:: OnShowMenuBar](#onshowmenubar)|Chamado antes que o menu no aplicativo do MFC atual seja exibido.|

### <a name="public-data-members"></a>Membros de Dados Públicos

|{1&gt;Nome&lt;1}|Descrição|
|----------|-----------------|
|[CFrameWnd:: m_bAutoMenuEnable](#m_bautomenuenable)|Controla a funcionalidade habilitar e desabilitar automaticamente para itens de menu.|
|[CFrameWnd:: rectDefault](#rectdefault)|Passe esse `CRect` estático como um parâmetro ao criar um objeto `CFrameWnd` para permitir que o Windows escolha o tamanho inicial e a posição da janela.|

## <a name="remarks"></a>Comentários

Para criar uma janela de quadro útil para seu aplicativo, derive uma classe de `CFrameWnd`. Adicione variáveis de membro à classe derivada para armazenar dados específicos ao seu aplicativo. Implemente funções de membro do manipulador de mensagens e um mapa de mensagens na classe derivada para especificar o que acontece quando as mensagens são direcionadas para a janela.

Há três maneiras de construir uma janela de quadro:

- Construí-lo diretamente usando [Create](#create).

- Construí-lo diretamente usando o [LoadFrame](#loadframe).

- Construí-lo indiretamente usando um modelo de documento.

Antes de chamar `Create` ou `LoadFrame`, você deve construir o objeto quadro-janela no heap usando o C++ operador **novo** . Antes de chamar `Create`, você também pode registrar uma classe de janela com a função global [AfxRegisterWndClass](../../mfc/reference/application-information-and-management.md#afxregisterwndclass) para definir o ícone e os estilos de classe para o quadro.

Use a função de membro `Create` para passar os parâmetros de criação do quadro como argumentos imediatos.

`LoadFrame` requer menos argumentos que `Create`e, em vez disso, recupera a maioria de seus valores padrão de recursos, incluindo a legenda, o ícone, a tabela de acelerador e o menu do quadro. Para ser acessível por `LoadFrame`, todos esses recursos devem ter a mesma ID de recurso (por exemplo, IDR_MAINFRAME).

Quando um objeto de `CFrameWnd` contém exibições e documentos, eles são criados indiretamente pela estrutura em vez de diretamente pelo programador. O objeto `CDocTemplate` orquestra a criação do quadro, a criação das exibições que as contém e a conexão das exibições para o documento apropriado. Os parâmetros do Construtor `CDocTemplate` especificam a `CRuntimeClass` das três classes envolvidas (documento, quadro e exibição). Um objeto `CRuntimeClass` é usado pela estrutura para criar dinamicamente novos quadros quando especificado pelo usuário (por exemplo, usando o comando arquivo novo ou a janela MDI (interface de vários documentos) novo comando.

Uma classe de janela de quadro derivada de `CFrameWnd` deve ser declarada com DECLARE_DYNCREATE para que o mecanismo de RUNTIME_CLASS acima funcione corretamente.

Uma `CFrameWnd` contém implementações padrão para executar as seguintes funções de uma janela principal em um aplicativo típico do Windows:

- Uma janela de quadro `CFrameWnd` controla uma exibição atualmente ativa que é independente da janela ativa do Windows ou do foco de entrada atual. Quando o quadro é reativado, o modo de exibição ativo é notificado chamando `CView::OnActivateView`.

- Mensagens de comando e muitas mensagens de notificação de quadro comuns, incluindo aquelas tratadas pelas funções `OnSetFocus`, `OnHScroll`e `OnVScroll` de `CWnd`, são delegadas por uma janela de quadro de `CFrameWnd` para a exibição ativa no momento.

- O modo de exibição atualmente ativo (ou janela de quadro filho MDI ativo no caso de um quadro MDI) pode determinar a legenda da janela do quadro. Esse recurso pode ser desabilitado desativando o FWS_ADDTOTITLE o bit do estilo da janela do quadro.

- Uma janela de quadro `CFrameWnd` gerencia o posicionamento das barras de controle, exibições e outras janelas filhas dentro da área de cliente da janela do quadro. Uma janela de quadro também faz a atualização de tempo ocioso da barra de ferramentas e de outros botões da barra de controle. Uma janela de quadro `CFrameWnd` também tem implementações padrão de comandos para alternar e desativar a barra de ferramentas e a barra de status.

- Uma janela de quadro `CFrameWnd` gerencia a barra de menus principal. Quando um menu pop-up é exibido, a janela do quadro usa o mecanismo de UPDATE_COMMAND_UI para determinar quais itens de menu devem ser habilitados, desabilitados ou marcados. Quando o usuário seleciona um item de menu, a janela do quadro atualiza a barra de status com a cadeia de caracteres da mensagem para esse comando.

- Uma janela de quadro `CFrameWnd` tem uma tabela de acelerador opcional que converte automaticamente aceleradores de teclado.

- Uma janela de quadro `CFrameWnd` tem uma ID de ajuda opcional definida com `LoadFrame` que é usada para a ajuda contextual. Uma janela de quadro é o principal orquestrador de estados semimodal, como a ajuda contextual (SHIFT + F1) e os modos de visualização de impressão.

- Uma janela de quadro `CFrameWnd` abrirá um arquivo arrastado do Gerenciador de arquivos e será Descartado na janela do quadro. Se uma extensão de arquivo for registrada e associada ao aplicativo, a janela do quadro responderá à solicitação aberta de intercâmbio de dados dinâmicos (DDE) que ocorre quando o usuário abre um arquivo de dados no Gerenciador de arquivos ou quando a função `ShellExecute` do Windows é chamada.

- Se a janela do quadro for a janela principal do aplicativo (ou seja, `CWinThread::m_pMainWnd`), quando o usuário fechar o aplicativo, a janela do quadro solicitará que o usuário salve os documentos modificados (para `OnClose` e `OnQueryEndSession`).

- Se a janela do quadro for a janela principal do aplicativo, a janela do quadro será o contexto para executar o WinHelp. Fechar a janela do quadro desligará o WINHELP. EXE se foi iniciado para obter ajuda para este aplicativo.

Não use o C++ operador **delete** para destruir uma janela de quadro. Use `CWnd::DestroyWindow` em seu lugar. A implementação `CFrameWnd` do `PostNcDestroy` excluirá o C++ objeto quando a janela for destruída. Quando o usuário fechar a janela do quadro, o manipulador de `OnClose` padrão chamará `DestroyWindow`.

Para obter mais informações sobre `CFrameWnd`, consulte [janelas de quadros](../../mfc/frame-windows.md).

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

[CObject](../../mfc/reference/cobject-class.md)

[CCmdTarget](../../mfc/reference/ccmdtarget-class.md)

[CWnd](../../mfc/reference/cwnd-class.md)

`CFrameWnd`

## <a name="requirements"></a>{1&gt;{2&gt;Requisitos&lt;2}&lt;1}

**Cabeçalho:** Afxwin. h

##  <a name="activateframe"></a>CFrameWnd:: ActivateFrame

Chame essa função de membro para ativar e restaurar a janela do quadro para que ela fique visível e disponível para o usuário.

```
virtual void ActivateFrame(int nCmdShow = -1);
```

### <a name="parameters"></a>Parâmetros

*nCmdShow*<br/>
Especifica o parâmetro a ser passado para [CWnd:: sawindow](../../mfc/reference/cwnd-class.md#showwindow). Por padrão, o quadro é mostrado e restaurado corretamente.

### <a name="remarks"></a>Comentários

Essa função de membro geralmente é chamada após um evento de interface não usuário, como um DDE, OLE ou outro evento que pode mostrar a janela do quadro ou seu conteúdo ao usuário.

A implementação padrão ativa o quadro e o coloca na parte superior da ordem Z e, se necessário, executa as mesmas etapas para a janela do quadro principal do aplicativo.

Substitua essa função de membro para alterar a forma como um quadro é ativado. Por exemplo, você pode forçar o Windows filho MDI a ser maximizado. Adicione a funcionalidade apropriada e, em seguida, chame a versão da classe base com um *nCmdShow*explícito.

### <a name="example"></a>{1&gt;Exemplo&lt;1}

[!code-cpp[NVC_MFCWindowing#1](../../mfc/reference/codesnippet/cpp/cframewnd-class_1.cpp)]

##  <a name="beginmodalstate"></a>CFrameWnd:: BeginModalState

Chame essa função de membro para tornar uma janela de quadro modal.

```
virtual void BeginModalState();
```

##  <a name="cframewnd"></a>CFrameWnd:: CFrameWnd

Constrói um objeto `CFrameWnd`, mas não cria a janela de quadro visível.

```
CFrameWnd();
```

### <a name="remarks"></a>Comentários

Chame `Create` para criar a janela visível.

##  <a name="create"></a>CFrameWnd:: criar

Chame para criar e inicializar a janela de quadro do Windows associada ao objeto `CFrameWnd`.

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
Aponta para uma cadeia de caracteres terminada em nulo que nomeia a classe do Windows. O nome da classe pode ser qualquer nome registrado com a função global `AfxRegisterWndClass` ou `RegisterClass` função do Windows. Se NULL, usa os atributos de `CFrameWnd` padrão predefinidos.

*lpszWindowName*<br/>
Aponta para uma cadeia de caracteres de caractere terminada em nulo que representa o nome da janela. Usado como texto para a barra de título.

*dwStyle*<br/>
Especifica os atributos de [estilo](../../mfc/reference/styles-used-by-mfc.md#window-styles) de janela. Inclua o estilo de FWS_ADDTOTITLE se desejar que a barra de título exiba automaticamente o nome do documento representado na janela.

*Rect*<br/>
Especifica o tamanho e a posição da janela. O valor *rectDefault* permite que o Windows especifique o tamanho e a posição da nova janela.

*pParentWnd*<br/>
Especifica a janela pai desta janela do quadro. Esse parâmetro deve ser nulo para janelas de quadro de nível superior.

*lpszMenuName*<br/>
Identifica o nome do recurso de menu a ser usado com a janela. Use MAKEINTRESOURCE se o menu tiver uma ID de inteiro em vez de uma cadeia de caracteres. Esse parâmetro pode ser nulo.

*dwExStyle*<br/>
Especifica os atributos de [estilo](../../mfc/reference/styles-used-by-mfc.md#extended-window-styles) estendido da janela.

*pContext*<br/>
Especifica um ponteiro para uma estrutura [CCreateContext](../../mfc/reference/ccreatecontext-structure.md) . Esse parâmetro pode ser nulo.

### <a name="return-value"></a>Valor retornado

Diferente de zero se a inicialização for bem-sucedida; caso contrário, 0.

### <a name="remarks"></a>Comentários

Construa um objeto `CFrameWnd` em duas etapas. Primeiro, invoque o construtor, que constrói o objeto `CFrameWnd` e, em seguida, chame `Create`, que cria a janela do quadro do Windows e o anexa ao objeto `CFrameWnd`. `Create` Inicializa o nome da classe da janela e o nome da janela e registra os valores padrão para seu estilo, pai e menu associado.

Use `LoadFrame` em vez de `Create` para carregar a janela do quadro de um recurso em vez de especificar seus argumentos.

##  <a name="createview"></a>CFrameWnd:: CreateView

Chame `CreateView` para criar uma exibição dentro de um quadro.

```
CWnd* CreateView(
    CCreateContext* pContext,
    UINT nID = AFX_IDW_PANE_FIRST);
```

### <a name="parameters"></a>Parâmetros

*pContext*<br/>
Especifica o tipo de exibição e documento.

*nID*<br/>
O número de identificação de uma exibição.

### <a name="return-value"></a>Valor retornado

Ponteiro para um objeto `CWnd` se for bem-sucedido; caso contrário, NULL.

### <a name="remarks"></a>Comentários

Use essa função de membro para criar "exibições" que não são `CView`derivadas em um quadro. Depois de chamar `CreateView`, você deve definir manualmente a exibição como ativa e defini-la como visível; essas tarefas não são executadas automaticamente pelo `CreateView`.

##  <a name="dockcontrolbar"></a>CFrameWnd::D ockControlBar

Faz com que uma barra de controle seja encaixada na janela do quadro.

```
void DockControlBar(
    CControlBar* pBar,
    UINT nDockBarID = 0,
    LPCRECT lpRect = NULL);
```

### <a name="parameters"></a>Parâmetros

*pBar*<br/>
Aponta para a barra de controle a ser encaixada.

*nDockBarID*<br/>
Determina quais lados da janela do quadro devem ser considerados para encaixe. Pode ser 0, ou um ou mais dos seguintes:

- AFX_IDW_DOCKBAR_TOP encaixe no lado superior da janela do quadro.

- AFX_IDW_DOCKBAR_BOTTOM encaixe no lado inferior da janela do quadro.

- AFX_IDW_DOCKBAR_LEFT encaixe no lado esquerdo da janela do quadro.

- AFX_IDW_DOCKBAR_RIGHT encaixe no lado direito da janela do quadro.

Se 0, a barra de controle poderá ser encaixada em qualquer lado habilitado para encaixe na janela do quadro de destino.

*lpRect*<br/>
Determina, em coordenadas de tela, onde a barra de controle será encaixada na área não cliente da janela de quadro de destino.

### <a name="remarks"></a>Comentários

A barra de controle será encaixada em um dos lados da janela do quadro especificado nas chamadas para [CControlBar:: EnableDocking](../../mfc/reference/ccontrolbar-class.md#enabledocking) e [CFrameWnd:: EnableDocking](#enabledocking). O lado escolhido é determinado por *nDockBarID*.

##  <a name="enabledocking"></a>CFrameWnd:: EnableDocking

Chame essa função para habilitar as barras de controle encaixáveis em uma janela do quadro.

```
void EnableDocking(DWORD dwDockStyle);
```

### <a name="parameters"></a>Parâmetros

*dwDockStyle*<br/>
Especifica quais lados da janela do quadro podem servir como sites de encaixe para barras de controle. Pode ser um ou mais dos seguintes:

- CBRS_ALIGN_TOP permite o encaixe na parte superior da área do cliente.

- CBRS_ALIGN_BOTTOM permite o encaixe na parte inferior da área do cliente.

- CBRS_ALIGN_LEFT permite o encaixe no lado esquerdo da área do cliente.

- CBRS_ALIGN_RIGHT permite o encaixe no lado direito da área do cliente.

- CBRS_ALIGN_ANY permite o encaixe em qualquer lado da área do cliente.

### <a name="remarks"></a>Comentários

Por padrão, as barras de controle serão encaixadas em um lado da janela do quadro na seguinte ordem: superior, inferior, esquerda, direita.

### <a name="example"></a>{1&gt;Exemplo&lt;1}

  Consulte o exemplo de [CToolBar:: Create](../../mfc/reference/ctoolbar-class.md#create).

##  <a name="endmodalstate"></a>CFrameWnd:: endjanelarestritastate

Chame essa função de membro para alterar uma janela de quadro de modal para sem janela restrita.

```
virtual void EndModalState();
```

### <a name="remarks"></a>Comentários

`EndModalState` habilita todas as janelas desabilitadas pelo [BeginModalState](#beginmodalstate).

##  <a name="floatcontrolbar"></a>CFrameWnd:: FloatControlBar

Chame essa função para fazer com que uma barra de controle não seja encaixada na janela do quadro.

```
void FloatControlBar(
    CControlBar* pBar,
    CPoint point,
    DWORD dwStyle = CBRS_ALIGN_TOP);
```

### <a name="parameters"></a>Parâmetros

*pBar*<br/>
Aponta para a barra de controle a ser flutuante.

*empresas*<br/>
O local, em coordenadas da tela, onde o canto superior esquerdo da barra de controle será colocado.

*dwStyle*<br/>
Especifica se a barra de controle deve ser alinhada horizontal ou verticalmente dentro de sua nova janela do quadro. Pode ser qualquer um dos seguintes:

- CBRS_ALIGN_TOP Orienta a barra de controle verticalmente.

- CBRS_ALIGN_BOTTOM Orienta a barra de controle verticalmente.

- CBRS_ALIGN_LEFT orienta a barra de controle horizontalmente.

- CBRS_ALIGN_RIGHT orienta a barra de controle horizontalmente.

Se os estilos forem passados especificando a orientação horizontal e vertical, a barra de ferramentas será orientada horizontalmente.

### <a name="remarks"></a>Comentários

Normalmente, isso é feito na inicialização do aplicativo quando o programa está restaurando as configurações da execução anterior.

Essa função é chamada pela estrutura quando o usuário causa uma operação de soltar liberando o botão esquerdo do mouse enquanto arrasta a barra de controle sobre um local que não está disponível para encaixe.

##  <a name="getactivedocument"></a>CFrameWnd:: GetActiveDocument

Chame essa função de membro para obter um ponteiro para o `CDocument` atual anexado à exibição ativa atual.

```
virtual CDocument* GetActiveDocument();
```

### <a name="return-value"></a>Valor retornado

Um ponteiro para o [CDocument](../../mfc/reference/cdocument-class.md)atual. Se não houver nenhum documento atual, retornará NULL.

##  <a name="getactiveframe"></a>CFrameWnd:: GetActiveFrame

Chame essa função de membro para obter um ponteiro para a janela filho MDI (interface de vários documentos) ativa de uma janela de quadro MDI.

```
virtual CFrameWnd* GetActiveFrame();
```

### <a name="return-value"></a>Valor retornado

Um ponteiro para a janela filho MDI ativa. Se o aplicativo for um aplicativo SDI ou se a janela do quadro MDI não tiver nenhum documento ativo, o implícito **desse** ponteiro será retornado.

### <a name="remarks"></a>Comentários

Se não houver nenhum filho MDI ativo ou o aplicativo for uma interface de documento único (SDI), o implícito **desse** ponteiro será retornado.

##  <a name="getactiveview"></a>CFrameWnd:: GetActiveView

Chame essa função de membro para obter um ponteiro para o modo de exibição ativo (se houver) anexado a uma janela de quadro (`CFrameWnd`).

```
CView* GetActiveView() const;
```

### <a name="return-value"></a>Valor retornado

Um ponteiro para o [cvisualização](../../mfc/reference/cview-class.md)atual. Se não houver nenhuma exibição atual, retornará NULL.

### <a name="remarks"></a>Comentários

Essa função retorna NULL quando chamada para uma janela de quadro principal MDI (`CMDIFrameWnd`). Em um aplicativo MDI, a janela do quadro principal MDI não tem uma exibição associada a ela. Em vez disso, cada janela filho individual (`CMDIChildWnd`) tem uma ou mais exibições associadas. O modo de exibição ativo em um aplicativo MDI pode ser obtido primeiro encontrando a janela filho MDI ativa e, em seguida, localizando o modo de exibição ativo dessa janela filho. A janela filho MDI ativa pode ser encontrada chamando a função `MDIGetActive` ou `GetActiveFrame` conforme demonstrado no seguinte:

[!code-cpp[NVC_MFCWindowing#2](../../mfc/reference/codesnippet/cpp/cframewnd-class_2.cpp)]

##  <a name="getcontrolbar"></a>CFrameWnd:: GetControlBar

Chame `GetControlBar` para obter acesso à barra de controle associada à ID.

```
CControlBar* GetControlBar(UINT nID);
```

### <a name="parameters"></a>Parâmetros

*nID*<br/>
O número de ID de uma barra de controle.

### <a name="return-value"></a>Valor retornado

Um ponteiro para a barra de controle associada à ID.

### <a name="remarks"></a>Comentários

O parâmetro *NID* refere-se ao identificador exclusivo passado para o método `Create` da barra de controle. Para obter mais informações sobre barras de controle, consulte o tópico denominado [barras de controle](../../mfc/control-bars.md).

`GetControlBar` retornará a barra de controle mesmo se ela estiver flutuante e, portanto, não for uma janela filho do quadro no momento.

##  <a name="getdockstate"></a>CFrameWnd:: GetDockState

Chame essa função de membro para armazenar informações de estado sobre as barras de controle da janela do quadro em um objeto `CDockState`.

```
void GetDockState(CDockState& state) const;
```

### <a name="parameters"></a>Parâmetros

*state*<br/>
Contém o estado atual das barras de controle da janela do quadro no retorno.

### <a name="remarks"></a>Comentários

Em seguida, você pode gravar o conteúdo de `CDockState` no armazenamento usando `CDockState::SaveState` ou `Serialize`. Se posteriormente você quiser restaurar as barras de controle para um estado anterior, carregue o estado com `CDockState::LoadState` ou `Serialize`e, em seguida, chame `SetDockState` para aplicar o estado anterior às barras de controle da janela do quadro.

##  <a name="getmenubarstate"></a>CFrameWnd:: getbarrademenustate

Recupera o estado de exibição do menu no aplicativo MFC atual.

```
virtual DWORD GetMenuBarState();
```

### <a name="return-value"></a>Valor retornado

O valor de retorno pode ter os seguintes valores:

- AFX_MBS_VISIBLE (0x01)-o menu está visível.

- AFX_MBS_HIDDEN (0x02)-o menu está oculto.

### <a name="remarks"></a>Comentários

Se ocorrer um erro em tempo de execução, esse método é declarado no modo de depuração e gera uma exceção derivada da classe [CException](../../mfc/reference/cexception-class.md) .

##  <a name="getmenubarvisibility"></a>CFrameWnd:: GetMenuBarVisibility

Indica se o estado padrão do menu no aplicativo MFC atual está oculto ou visível.

```
virtual DWORD CFrameWnd::GetMenuBarVisibility();
```

### <a name="return-value"></a>Valor retornado

Esse método retorna um dos seguintes valores:

- AFX_MBV_KEEPVISIBLE (0x01) – o menu é exibido o tempo todo e, por padrão, não tem o foco.

- AFX_MBV_DISPLAYONFOCUS (0x02)-o menu fica oculto por padrão. Se o menu estiver oculto, pressione a tecla ALT para exibir o menu e dar a ele o foco. Se o menu for exibido, pressione a tecla ALT ou ESC para ocultá-lo.

- AFX_MBV_ DISPLAYONFOCUS (0x02) &#124; AFX_MBV_DISPLAYONF10 (0x04) (combinação de bits bit (ou))-o menu fica oculto por padrão. Se o menu estiver oculto, pressione a tecla F10 para exibir o menu e dar a ele o foco. Se o menu for exibido, pressione a tecla F10 para ativar ou desativar o foco no menu. O menu é exibido até que você pressione a tecla ALT ou ESC para ocultá-lo.

### <a name="remarks"></a>Comentários

Se ocorrer um erro em tempo de execução, esse método é declarado no modo de depuração e gera uma exceção derivada da classe [CException](../../mfc/reference/cexception-class.md) .

##  <a name="getmessagebar"></a>CFrameWnd:: GetMessageBar

Chame essa função de membro para obter um ponteiro para a barra de status.

```
virtual CWnd* GetMessageBar();
```

### <a name="return-value"></a>Valor retornado

Ponteiro para a janela de barra de status.

##  <a name="getmessagestring"></a>CFrameWnd:: GetMessageString

Substitua essa função para fornecer cadeias de caracteres personalizadas para IDs de comando.

```
virtual void GetMessageString(
    UINT nID,
    CString& rMessage) const;
```

### <a name="parameters"></a>Parâmetros

*nID*<br/>
ID de recurso da mensagem desejada.

*rMessage*<br/>
`CString` objeto no qual a mensagem será colocada.

### <a name="remarks"></a>Comentários

A implementação padrão simplesmente carrega a cadeia de caracteres especificada por *NID* do arquivo de recurso. Essa função é chamada pelo Framework quando a cadeia de caracteres de mensagem na barra de status precisa ser atualizada.

##  <a name="gettitle"></a>CFrameWnd:: getTitle

Recupera o título do objeto de janela.

```
CString GetTitle() const;
```

### <a name="return-value"></a>Valor retornado

Um objeto [CString](../../atl-mfc-shared/reference/cstringt-class.md) que contém o título atual do objeto Window.

##  <a name="initialupdateframe"></a>CFrameWnd:: InitialUpdateFrame

Chame `IntitialUpdateFrame` depois de criar um novo quadro com `Create`.

```
void InitialUpdateFrame(
    CDocument* pDoc,
    BOOL bMakeVisible);
```

### <a name="parameters"></a>Parâmetros

*pDoc*<br/>
Aponta para o documento ao qual a janela do quadro está associada. Pode ser NULO.

*bMakeVisible*<br/>
Se for TRUE, indica que o quadro deve ficar visível e ativo. Se for FALSE, nenhum descendente será tornado visível.

### <a name="remarks"></a>Comentários

Isso faz com que todas as exibições nessa janela de quadro recebam suas chamadas de `OnInitialUpdate`.

Além disso, se não havia um modo de exibição ativo anteriormente, a exibição primária da janela do quadro será ativada. A exibição primária é uma exibição com uma ID filho de AFX_IDW_PANE_FIRST. Por fim, a janela do quadro será visível se *bMakeVisible* for diferente de zero. Se *bMakeVisible* for 0, o foco atual e o estado visível da janela do quadro permanecerão inalterados. Não é necessário chamar essa função ao usar a implementação do arquivo novo e o arquivo aberto da estrutura.

##  <a name="inmodalstate"></a>CFrameWnd:: injanelarestritastate

Chame essa função de membro para verificar se uma janela de quadro é modal ou sem janela restrita.

```
BOOL InModalState() const;
```

### <a name="return-value"></a>Valor retornado

Diferente de zero, se sim; caso contrário, 0.

##  <a name="istracking"></a>CFrameWnd:: istracking

Chame essa função de membro para determinar se a barra de divisão na janela está sendo movida no momento.

```
BOOL IsTracking() const;
```

### <a name="return-value"></a>Valor retornado

Diferente de zero se uma operação de divisor estiver em andamento; caso contrário, 0.

##  <a name="loadacceltable"></a>CFrameWnd:: LoadAccelTable

Chame para carregar a tabela de acelerador especificada.

```
BOOL LoadAccelTable(LPCTSTR lpszResourceName);
```

### <a name="parameters"></a>Parâmetros

*lpszResourceName*<br/>
Identifica o nome do recurso de acelerador. Use MAKEINTRESOURCE se o recurso for identificado com uma ID de inteiro.

### <a name="return-value"></a>Valor retornado

Diferente de zero se a tabela de acelerador foi carregada com êxito; caso contrário, 0.

### <a name="remarks"></a>Comentários

Somente uma tabela pode ser carregada de cada vez.

As tabelas de acelerador carregadas dos recursos são liberadas automaticamente quando o aplicativo é encerrado.

Se você chamar `LoadFrame` para criar a janela do quadro, a estrutura carregará uma tabela de acelerador junto com os recursos de menu e ícone, e uma chamada subsequente para essa função de membro será desnecessária.

##  <a name="loadbarstate"></a>CFrameWnd:: LoadBarState

Chame essa função para restaurar as configurações de cada barra de controle pertencente à janela do quadro.

```
void LoadBarState(LPCTSTR lpszProfileName);
```

### <a name="parameters"></a>Parâmetros

*lpszProfileName*<br/>
Nome de uma seção no arquivo de inicialização (INI) ou uma chave no registro do Windows em que as informações de estado são armazenadas.

### <a name="remarks"></a>Comentários

As informações restauradas incluem visibilidade, orientação horizontal/vertical, estado de encaixe e posição da barra de controle.

As configurações que você deseja restaurar devem ser gravadas no registro antes de você chamar `LoadBarState`. Grave as informações no registro chamando [CWinApp:: SetRegistryKey](../../mfc/reference/cwinapp-class.md#setregistrykey). Grave as informações no arquivo INI chamando [SaveBarState](#savebarstate).

##  <a name="loadframe"></a>CFrameWnd:: LoadFrame

Chame para criar dinamicamente uma janela de quadro por meio de informações de recursos.

```
virtual BOOL LoadFrame(
    UINT nIDResource,
    DWORD dwDefaultStyle = WS_OVERLAPPEDWINDOW | FWS_ADDTOTITLE,
    CWnd* pParentWnd = NULL,
    CCreateContext* pContext = NULL);
```

### <a name="parameters"></a>Parâmetros

*nIDResource*<br/>
A ID dos recursos compartilhados associados à janela do quadro.

*dwDefaultStyle*<br/>
O [estilo](../../mfc/reference/styles-used-by-mfc.md#window-styles)do quadro. Inclua o estilo de FWS_ADDTOTITLE se desejar que a barra de título exiba automaticamente o nome do documento representado na janela.

*pParentWnd*<br/>
Um ponteiro para o pai do quadro.

*pContext*<br/>
Um ponteiro para uma estrutura [CCreateContext](../../mfc/reference/ccreatecontext-structure.md) . Esse parâmetro pode ser nulo.

### <a name="remarks"></a>Comentários

Construa um objeto `CFrameWnd` em duas etapas. Primeiro, invoque o construtor, que constrói o objeto `CFrameWnd` e, em seguida, chame `LoadFrame`, que carrega a janela do quadro do Windows e os recursos associados e anexa a janela do quadro ao objeto `CFrameWnd`. O parâmetro *nIDResource* especifica o menu, a tabela de acelerador, o ícone e o recurso de cadeia de caracteres do título para a janela do quadro.

Use a função membro `Create` em vez de `LoadFrame` quando desejar especificar todos os parâmetros de criação da janela do quadro.

A estrutura chama `LoadFrame` quando cria uma janela de quadro usando um objeto de modelo de documento.

A estrutura usa o argumento *pContext* para especificar os objetos a serem conectados à janela do quadro, incluindo quaisquer objetos de exibição contidos. Você pode definir o argumento *pContext* como nulo ao chamar `LoadFrame`.

##  <a name="m_bautomenuenable"></a>CFrameWnd:: m_bAutoMenuEnable

Quando esse membro de dados é habilitado (que é o padrão), os itens de menu que não têm ON_UPDATE_COMMAND_UI ou manipuladores de ON_COMMAND serão desabilitados automaticamente quando o usuário extrair um menu.

```
BOOL m_bAutoMenuEnable;
```

### <a name="remarks"></a>Comentários

Itens de menu que têm um manipulador de ON_COMMAND, mas nenhum manipulador de ON_UPDATE_COMMAND_UI será habilitado automaticamente.

Quando esse membro de dados é definido, os itens de menu são habilitados automaticamente da mesma maneira que os botões da barra de ferramentas são habilitados.

> [!NOTE]
> `m_bAutoMenuEnable` não tem efeito sobre itens de menu de nível superior.

Esse membro de dados simplifica a implementação de comandos opcionais com base na seleção atual e reduz a necessidade de escrever ON_UPDATE_COMMAND_UI manipuladores para habilitar e Desabilitar itens de menu.

### <a name="example"></a>{1&gt;Exemplo&lt;1}

[!code-cpp[NVC_MFCWindowing#3](../../mfc/reference/codesnippet/cpp/cframewnd-class_3.cpp)]

##  <a name="negotiateborderspace"></a>CFrameWnd:: NegotiateBorderSpace

Chame essa função de membro para negociar o espaço de borda em uma janela de quadro durante a ativação de OLE local.

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
Ponteiro para uma estrutura [Rect](/windows/win32/api/windef/ns-windef-rect) ou um objeto [CRect](../../atl-mfc-shared/reference/crect-class.md) que especifica as coordenadas da borda.

### <a name="return-value"></a>Valor retornado

Diferente de zero, se for bem-sucedido; caso contrário, 0.

### <a name="remarks"></a>Comentários

Essa função de membro é a `CFrameWnd` implementação da negociação de espaço de borda OLE.

##  <a name="onbarcheck"></a>CFrameWnd:: OnBarCheck

Chamado sempre que uma ação é executada na barra de controle especificada.

```
afx_msg BOOL OnBarCheck(UINT nID);
```

### <a name="parameters"></a>Parâmetros

*nID*<br/>
A ID da barra de controle que está sendo mostrada.

### <a name="return-value"></a>Valor retornado

Diferente de zero se a barra de controle existir; caso contrário, 0.

##  <a name="oncontexthelp"></a>CFrameWnd:: OnContextHelp

Manipula a ajuda do SHIFT + F1 para itens no local.

```
afx_msg void OnContextHelp();
```

### <a name="remarks"></a>Comentários

Para habilitar a ajuda contextual, você deve adicionar um

[!code-cpp[NVC_MFCDocViewSDI#16](../../mfc/codesnippet/cpp/cframewnd-class_4.cpp)]

para o mapa de mensagens de classe `CFrameWnd` e também adiciona uma entrada de tabela de aceleração, normalmente SHIFT + F1, para habilitar essa função de membro.

Se seu aplicativo for um contêiner OLE, `OnContextHelp` colocará todos os itens no local contidos no objeto janela do quadro no modo de ajuda. O cursor muda para uma seta e um ponto de interrogação, e o usuário pode mover o ponteiro do mouse e pressionar o botão esquerdo do mouse para selecionar uma caixa de diálogo, janela, menu ou botão de comando. Essa função de membro chama a função do Windows `WinHelp` com o contexto de ajuda do objeto sob o cursor.

##  <a name="oncreateclient"></a>CFrameWnd:: OnCreateClient

Chamado pelo Framework durante a execução de `OnCreate`.

```
virtual BOOL OnCreateClient(
    LPCREATESTRUCT lpcs,
    CCreateContext* pContext);
```

### <a name="parameters"></a>Parâmetros

*LPC*<br/>
Um ponteiro para uma estrutura [CREATEstruct](/windows/win32/api/winuser/ns-winuser-createstructw) do Windows.

*pContext*<br/>
Um ponteiro para uma estrutura [CCreateContext](../../mfc/reference/ccreatecontext-structure.md) .

### <a name="return-value"></a>Valor retornado

Diferente de zero, se for bem-sucedido; caso contrário, 0.

### <a name="remarks"></a>Comentários

Nunca chame essa função.

A implementação padrão dessa função cria um objeto `CView` com base nas informações fornecidas em *pContext*, se possível.

Substitua essa função para substituir os valores passados no objeto `CCreateContext` ou para alterar a forma como os controles na área do cliente principal da janela do quadro são criados. Os membros de `CCreateContext` que você pode substituir são descritos na classe [CCreateContext](../../mfc/reference/ccreatecontext-structure.md) .

> [!NOTE]
>  Não substitua valores passados na estrutura de `CREATESTRUCT`. Eles são apenas para uso informativo. Se você quiser substituir o retângulo de janela inicial, por exemplo, substitua a função membro `CWnd` [PreCreateWindow](../../mfc/reference/cwnd-class.md#precreatewindow).

##  <a name="onhidemenubar"></a>CFrameWnd:: OnHideMenuBar

Essa função é chamada quando o sistema está prestes a ocultar a barra de menus no aplicativo do MFC atual.

```
virtual void OnHideMenuBar();
```

### <a name="remarks"></a>Comentários

Esse manipulador de eventos permite que seu aplicativo execute ações personalizadas quando o sistema está prestes a ocultar o menu. Não é possível impedir que o menu fique oculto, mas você pode, por exemplo, chamar outros métodos para recuperar o estilo ou o estado do menu.

##  <a name="onsetpreviewmode"></a>CFrameWnd:: OnSetPreviewMode

Chame essa função de membro para definir a janela de quadro principal do aplicativo dentro e fora do modo de visualização de impressão.

```
virtual void OnSetPreviewMode(
    BOOL bPreview,
    CPrintPreviewState* pState);
```

### <a name="parameters"></a>Parâmetros

*bPreview*<br/>
Especifica se o aplicativo deve ser colocado no modo de visualização de impressão ou não. Defina como TRUE para colocar na visualização de impressão, FALSE para cancelar o modo de visualização.

*pState*<br/>
Um ponteiro para uma estrutura de `CPrintPreviewState`.

### <a name="remarks"></a>Comentários

A implementação padrão desabilita todas as barras de ferramentas padrão e oculta o menu principal e a janela principal do cliente. Isso transforma as janelas de quadro MDI em janelas de quadro de SDI temporárias.

Substitua essa função de membro para personalizar a ocultação e a exibição de barras de controle e outras partes de janela do quadro durante a visualização de impressão. Chame a implementação da classe base de dentro da versão substituída.

##  <a name="onshowmenubar"></a>CFrameWnd:: OnShowMenuBar

Essa função é chamada quando o sistema está prestes a exibir a barra de menus no aplicativo do MFC atual.

```
virtual void OnShowMenuBar();
```

### <a name="remarks"></a>Comentários

Esse manipulador de eventos permite que seu aplicativo execute ações personalizadas quando o menu está prestes a ser exibido. Não é possível impedir que o menu seja exibido, mas você pode, por exemplo, chamar outros métodos para recuperar o estilo ou o estado do menu.

##  <a name="onupdatecontrolbarmenu"></a>CFrameWnd:: OnUpdateControlBarMenu

Chamado pelo Framework quando o menu associado é atualizado.

```
afx_msg void OnUpdateControlBarMenu(CCmdUI* pCmdUI);
```

### <a name="parameters"></a>Parâmetros

*pCmdUI*<br/>
Um ponteiro para um objeto [CCmdUI](../../mfc/reference/ccmdui-class.md) que representa o menu que gerou o comando Update. O manipulador de atualização chama a função de membro [Enable](../../mfc/reference/ccmdui-class.md#enable) do objeto `CCmdUI` por meio de *pCmdUI* para atualizar a interface do usuário.

##  <a name="recalclayout"></a>CFrameWnd:: RecalcLayout

Chamado pelo Framework quando as barras de controle padrão são ativadas ou desativadas ou quando a janela do quadro é redimensionada.

```
virtual void RecalcLayout(BOOL bNotify = TRUE);
```

### <a name="parameters"></a>Parâmetros

*bNotify*<br/>
Determina se o item in-loco ativo para a janela do quadro recebe a notificação da alteração de layout. Se for TRUE, o item será notificado; caso contrário, FALSE.

### <a name="remarks"></a>Comentários

A implementação padrão dessa função de membro chama a função membro `CWnd` `RepositionBars` para reposicionar todas as barras de controle no quadro, bem como na janela principal do cliente (geralmente uma `CView` ou MDICLIENT).

Substitua essa função de membro para controlar a aparência e o comportamento das barras de controle depois que o layout da janela do quadro for alterado. Por exemplo, chame-o quando você ativar ou desativar as barras de controle ou adicionar outra barra de controle.

##  <a name="rectdefault"></a>CFrameWnd:: rectDefault

Passe esse `CRect` estático como um parâmetro ao criar uma janela para permitir que o Windows escolha o tamanho inicial e a posição da janela.

```
static AFX_DATA const CRect rectDefault;
```

##  <a name="savebarstate"></a>CFrameWnd:: SaveBarState

Chame essa função para armazenar informações sobre cada barra de controle de propriedade da janela do quadro.

```
void SaveBarState(LPCTSTR lpszProfileName) const;
```

### <a name="parameters"></a>Parâmetros

*lpszProfileName*<br/>
Nome de uma seção no arquivo de inicialização ou uma chave no registro do Windows em que as informações de estado são armazenadas.

### <a name="remarks"></a>Comentários

Essas informações podem ser lidas no arquivo de inicialização usando [LoadBarState](#loadbarstate). As informações armazenadas incluem visibilidade, orientação horizontal/vertical, estado de encaixe e posição da barra de controle.

##  <a name="setactivepreviewview"></a>CFrameWnd:: SetActivePreviewView

Designa a exibição especificada como a exibição ativa para visualização avançada.

```
void SetActivePreviewView(CView* pViewNew);
```

### <a name="parameters"></a>Parâmetros

*pViewNew*<br/>
Um ponteiro para uma exibição a ser ativada.

### <a name="remarks"></a>Comentários

##  <a name="setactiveview"></a>CFrameWnd:: SetActiveView

Chame essa função de membro para definir o modo de exibição ativo.

```
void SetActiveView(
    CView* pViewNew,
    BOOL bNotify = TRUE);
```

### <a name="parameters"></a>Parâmetros

*pViewNew*<br/>
Especifica um ponteiro para um objeto [cvisualização](../../mfc/reference/cview-class.md) ou nulo para nenhuma exibição ativa.

*bNotify*<br/>
Especifica se a exibição deve ser notificada da ativação. Se for TRUE, `OnActivateView` será chamado para a nova exibição; Se for FALSE, não será.

### <a name="remarks"></a>Comentários

A estrutura chamará essa função automaticamente, pois o usuário altera o foco para uma exibição dentro da janela do quadro. Você pode chamar `SetActiveView` explicitamente para alterar o foco para a exibição especificada.

##  <a name="setdockstate"></a>CFrameWnd:: SetDockState

Chame essa função de membro para aplicar informações de estado armazenadas em um objeto `CDockState` às barras de controle da janela do quadro.

```
void SetDockState(const CDockState& state);
```

### <a name="parameters"></a>Parâmetros

*state*<br/>
Aplique o estado armazenado às barras de controle da janela do quadro.

### <a name="remarks"></a>Comentários

Para restaurar um estado anterior das barras de controle, você pode carregar o estado armazenado com `CDockState::LoadState` ou `Serialize`e, em seguida, usar `SetDockState` para aplicá-lo às barras de controle da janela do quadro. O estado anterior é armazenado no objeto `CDockState` com `GetDockState`

##  <a name="setmenubarstate"></a>CFrameWnd:: setbarrademenustate

Define o estado de exibição do menu no aplicativo MFC atual como oculto ou exibido.

```
virtual BOOL SetMenuBarState(DWORD nState);
```

### <a name="parameters"></a>Parâmetros

|Parâmetro|Descrição|
|---------------|-----------------|
|*nState*|no Especifica se o menu deve ser exibido ou ocultado. O parâmetro *nState* pode ter os seguintes valores:<br /><br />-AFX_MBS_VISIBLE (0x01) – exibe o menu se ele estiver oculto, mas não tem efeito se estiver visível.<br />-AFX_MBS_HIDDEN (0x02) – oculta o menu se ele estiver visível, mas não tem efeito se estiver oculto.|

### <a name="return-value"></a>Valor retornado

TRUE se esse método alterar o estado do menu com êxito; caso contrário, FALSE.

### <a name="remarks"></a>Comentários

Se ocorrer um erro em tempo de execução, esse método é declarado no modo de depuração e gera uma exceção derivada da classe [CException](../../mfc/reference/cexception-class.md) .

##  <a name="setmenubarvisibility"></a>CFrameWnd:: SetMenuBarVisibility

Define o comportamento padrão do menu no aplicativo MFC atual como oculto ou visível.

```
virtual void SetMenuBarVisibility(DWORD nStyle);
```

### <a name="parameters"></a>Parâmetros

|Parâmetro|Descrição|
|---------------|-----------------|
|*nStyle*|no Especifica se o menu está oculto por padrão ou está visível e tem o foco. O parâmetro *nStyle* pode ter os seguintes valores:<br /><br />-AFX_MBV_KEEPVISIBLE (0x01)-<br />     O menu é exibido o tempo todo e, por padrão, não tem o foco.<br />-AFX_MBV_DISPLAYONFOCUS (0x02)-<br />     O menu fica oculto por padrão. Se o menu estiver oculto, pressione a tecla ALT para exibir o menu e dar a ele o foco. Se o menu for exibido, pressione a tecla ALT ou ESC para ocultar o menu.<br />-AFX_MBV_ DISPLAYONFOCUS (0x02) &#124; AFX_MBV_DISPLAYONF10 (0x04)<br />     (combinação de bits bit (ou))-o menu fica oculto por padrão. Se o menu estiver oculto, pressione a tecla F10 para exibir o menu e dar a ele o foco. Se o menu for exibido, pressione a tecla F10 para ativar ou desativar o foco no menu. O menu é exibido até que você pressione a tecla ALT ou ESC para ocultá-lo.|

### <a name="remarks"></a>Comentários

Se o valor do parâmetro *nStyle* não for válido, esse método será declarado no modo de depuração e gerará [CInvalidArgException](../../mfc/reference/cinvalidargexception-class.md) no modo de liberação. No caso de outros erros de tempo de execução, esse método é declarado no modo de depuração e gera uma exceção derivada da classe [CException](../../mfc/reference/cexception-class.md) .

Esse método afeta o estado dos menus em aplicativos escritos para o Windows Vista e posterior.

##  <a name="setmessagetext"></a>CFrameWnd:: SetMessageText

Chame essa função para inserir uma cadeia de caracteres no painel da barra de status que tem uma ID de 0.

```
void SetMessageText(LPCTSTR lpszText);
void SetMessageText(UINT nID);
```

### <a name="parameters"></a>Parâmetros

*lpszText*<br/>
Aponta para a cadeia de caracteres a ser colocada na barra de status.

*nID*<br/>
ID de recurso da cadeia de caracteres a ser colocada na barra de status.

### <a name="remarks"></a>Comentários

Normalmente, esse é o painel mais à esquerda e mais longo da barra de status.

##  <a name="setprogressbarposition"></a>CFrameWnd:: SetProgressBarPosition

Define a posição atual da barra de progresso do Windows 7 exibida na barra de tarefas.

```
void SetProgressBarPosition(int nProgressPos);
```

### <a name="parameters"></a>Parâmetros

*nProgressPos*<br/>
Especifica a posição a ser definida. Ele deve estar dentro do intervalo definido por `SetProgressBarRange`.

### <a name="remarks"></a>Comentários

##  <a name="setprogressbarrange"></a>CFrameWnd:: SetProgressBarRange

Define o intervalo para a barra de progresso do Windows 7 exibida na barra de tarefas.

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

##  <a name="setprogressbarstate"></a>CFrameWnd:: setprogressbarstate

Define o tipo e o estado do indicador de progresso exibido em um botão da barra de tarefas.

```
void SetProgressBarState(TBPFLAG tbpFlags);
```

### <a name="parameters"></a>Parâmetros

*tbpFlags*<br/>
Sinalizadores que controlam o estado atual do botão de progresso. Especifique apenas um dos sinalizadores a seguir porque todos os Estados são mutuamente exclusivos: TBPF_NOPROGRESS, TBPF_INDETERMINATE, TBPF_NORMAL, TBPF_ERROR, TBPF_PAUSED.

### <a name="remarks"></a>Comentários

##  <a name="settaskbaroverlayicon"></a>CFrameWnd:: SetTaskbarOverlayIcon

Sobrecarregado. Aplica uma sobreposição a um botão da barra de tarefas para indicar o status do aplicativo ou para notificar o usuário.

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
Especifica a ID de recurso de um ícone a ser usado como a sobreposição. Consulte a descrição de *HICON* para obter detalhes.

*lpcszDescr*<br/>
Um ponteiro para uma cadeia de caracteres que fornece uma versão de texto alt das informações transmitidas pela sobreposição, para fins de acessibilidade.

*hIcon*<br/>
O identificador de um ícone a ser usado como a sobreposição. Isso deve ser um pequeno ícone, medindo 16 pixels em 96 pontos por polegada (DPI). Se um ícone de sobreposição já estiver aplicado ao botão da barra de tarefas, essa sobreposição existente será substituída. Esse valor pode ser nulo. A forma como um valor nulo é manipulado depende se o botão da barra de tarefas representa uma única janela ou um grupo de janelas. É responsabilidade do aplicativo de chamada liberar *HICON* quando ele não for mais necessário.

### <a name="return-value"></a>Valor retornado

Verdadeiro se for bem-sucedido; FALSE se a versão do sistema operacional for menor do que o Windows 7 ou se ocorrer um erro ao definir o ícone.

### <a name="remarks"></a>Comentários

##  <a name="settitle"></a>CFrameWnd:: SetTitle

Define o título do objeto de janela.

```
void SetTitle(LPCTSTR lpszTitle);
```

### <a name="parameters"></a>Parâmetros

*lpszTitle*<br/>
Um ponteiro para uma cadeia de caracteres que contém o título do objeto de janela.

##  <a name="showcontrolbar"></a>CFrameWnd:: ShowControlBar

Chame essa função de membro para mostrar ou ocultar a barra de controle.

```
void ShowControlBar(
    CControlBar* pBar,
    BOOL bShow,
    BOOL bDelay);
```

### <a name="parameters"></a>Parâmetros

*pBar*<br/>
Ponteiro para a barra de controle a ser mostrado ou ocultado.

*bShow*<br/>
Se for TRUE, especifica que a barra de controle deve ser mostrada. Se for FALSE, especifica que a barra de controle deve ser ocultada.

*bDelay*<br/>
Se for TRUE, o atraso mostrará a barra de controle. Se for FALSE, mostrará a barra de controle imediatamente.

##  <a name="showownedwindows"></a>CFrameWnd:: ShowOwnedWindows

Chame essa função de membro para mostrar todas as janelas descendentes do objeto `CFrameWnd`.

```
void ShowOwnedWindows(BOOL bShow);
```

### <a name="parameters"></a>Parâmetros

*bShow*<br/>
Especifica se as janelas de propriedade devem ser mostradas ou ocultas.

## <a name="see-also"></a>Consulte também

[Classe CWnd](../../mfc/reference/cwnd-class.md)<br/>
[Gráfico da hierarquia](../../mfc/hierarchy-chart.md)<br/>
[Classe CWnd](../../mfc/reference/cwnd-class.md)<br/>
[Classe CMDIFrameWnd](../../mfc/reference/cmdiframewnd-class.md)<br/>
[Classe CMDIChildWnd](../../mfc/reference/cmdichildwnd-class.md)<br/>
[Classe CView](../../mfc/reference/cview-class.md)<br/>
[Classe CDocTemplate](../../mfc/reference/cdoctemplate-class.md)<br/>
[Estrutura CRuntimeClass](../../mfc/reference/cruntimeclass-structure.md)
