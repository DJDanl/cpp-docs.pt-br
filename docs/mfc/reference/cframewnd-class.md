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
ms.openlocfilehash: 3bb93420b39be5d6fb9a6691cec8300fdccb0e73
ms.sourcegitcommit: 7a6116e48c3c11b97371b8ae4ecc23adce1f092d
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/22/2020
ms.locfileid: "81754981"
---
# <a name="cframewnd-class"></a>Classe CFrameWnd

Fornece a funcionalidade de uma interface de documento único do Windows (SDI) sobreposta ou uma janela de quadro pop-up, juntamente com os membros para gerenciar a janela.

## <a name="syntax"></a>Sintaxe

```
class CFrameWnd : public CWnd
```

## <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores públicos

|Nome|Descrição|
|----------|-----------------|
|[CFrameWnd::CFrameWnd](#cframewnd)|Constrói um objeto `CFrameWnd`.|

### <a name="public-methods"></a>Métodos públicos

|Nome|Descrição|
|----------|-----------------|
|[CFrameWnd::Ativarquadro](#activateframe)|Torna o quadro visível e disponível para o usuário.|
|[CFrameWnd::BeginModalState](#beginmodalstate)|Define a janela da moldura para modal.|
|[CFrameWnd::Criar](#create)|Chamada para criar e inicializar a `CFrameWnd` janela de quadro do Windows associada ao objeto.|
|[CFrameWnd::CreateView](#createview)|Cria uma visão dentro de um `CView`quadro que não é derivado de .|
|[CFrameWnd::DockControlBar](#dockcontrolbar)|Docas uma barra de controle.|
|[CFrameWnd::Ativar docking](#enabledocking)|Permite que uma barra de controle seja encaixada.|
|[CFrameWnd::EndModalState](#endmodalstate)|Acaba com o estado modal da janela de quadros. Habilita todas as janelas `BeginModalState`desativadas por .|
|[CFrameWnd::FloatControlBar](#floatcontrolbar)|Flutua uma barra de controle.|
|[CFrameWnd::GetActiveDocument](#getactivedocument)|Retorna o `CDocument` objeto ativo.|
|[CFrameWnd::GetActiveFrame](#getactiveframe)|Retorna o `CFrameWnd` objeto ativo.|
|[CFrameWnd::GetActiveView](#getactiveview)|Retorna o `CView` objeto ativo.|
|[CFrameWnd::GetControlBar](#getcontrolbar)|Recupera a barra de controle.|
|[CFrameWnd::GetDockState](#getdockstate)|Recupera o estado das docas de uma janela de quadro.|
|[CFrameWnd::GetMenuBarState](#getmenubarstate)|Recupera o estado de exibição do menu no aplicativo MFC atual.|
|[CFrameWnd::GetMenuBarVisibility](#getmenubarvisibility)|Indica se o comportamento padrão do menu no aplicativo MFC atual está oculto ou visível.|
|[CFrameWnd::GetMessageBar](#getmessagebar)|Retorna um ponteiro para a barra de status pertencente à janela do quadro.|
|[CFrameWnd::GetMessageString](#getmessagestring)|Recupera mensagem correspondente a um ID de comando.|
|[CFrameWnd::GetTitle](#gettitle)|Recupera o título da barra de controle relacionada.|
|[CFrameWnd::InitialUpdateFrame](#initialupdateframe)|Faz `OnInitialUpdate` com que a função do membro pertencente a todas as visualizações na janela do quadro seja chamada.|
|[CFrameWnd::InModalState](#inmodalstate)|Retorna um valor indicando se uma janela de quadro está ou não em um estado modal.|
|[CFrameWnd::IsTracking](#istracking)|Determina se a barra de divisor está sendo movida no momento.|
|[CFrameWnd::LoadAccelTable](#loadacceltable)|Ligue para carregar uma mesa de acelerador.|
|[CFrameWnd::LoadBarState](#loadbarstate)|Chamada para restaurar as configurações da barra de controle.|
|[CFrameWnd::''''''''''''''''''''](#loadframe)|Chamada para criar dinamicamente uma janela de quadro a partir de informações de recursos.|
|[CFrameWnd::NegocieBorderSpace](#negotiateborderspace)|Negocia espaço na fronteira na janela da moldura.|
|[CFrameWnd::OnBarCheck](#onbarcheck)|Chamado sempre que uma ação é realizada na barra de controle especificada.|
|[CFrameWnd::OnContextHelp](#oncontexthelp)|Manuseio shift+F1 Ajuda para itens no local.|
|[CFrameWnd::Visualização de insetMode](#onsetpreviewmode)|Define a janela principal do quadro do aplicativo para dentro e para fora do modo de visualização de impressão.|
|[CFrameWnd::OnUpdateControlBarmenu](#onupdatecontrolbarmenu)|Chamado pelo framework quando o menu associado é atualizado.|
|[CFrameWnd::RecalcLayout](#recalclayout)|Reposiciona as barras `CFrameWnd` de controle do objeto.|
|[CFrameWnd::SaveBarState](#savebarstate)|Chamada para salvar as configurações da barra de controle.|
|[CFrameWnd::SetActivePreviewView](#setactivepreviewview)|Designa a exibição especificada como a exibição ativa de Visualização Rica.|
|[CFrameWnd::SetActiveView](#setactiveview)|Define o `CView` objeto ativo.|
|[CFrameWnd::SetDockState](#setdockstate)|Chamada para encaixar a janela da moldura na janela principal.|
|[CFrameWnd::SetMenuBarState](#setmenubarstate)|Define o estado de exibição do menu no aplicativo MFC atual como oculto ou exibido.|
|[CFrameWnd::SetMenuBarVisibility](#setmenubarvisibility)|Define o comportamento padrão do menu no aplicativo MFC atual para ser oculto ou visível.|
|[CFrameWnd::SetMessageText](#setmessagetext)|Define o texto de uma barra de status padrão.|
|[CFrameWnd::SetProgressBarPosition](#setprogressbarposition)|Define a posição atual para a barra de progresso do Windows 7 exibida na barra de tarefas.|
|[CFrameWnd::SetProgressBarRange](#setprogressbarrange)|Define o intervalo para a barra de progresso do Windows 7 exibida na barra de tarefas.|
|[CFrameWnd::SetProgressBarState](#setprogressbarstate)|Define o tipo e o estado do indicador de progresso exibidos em um botão de barra de tarefas.|
|[CFrameWnd::SetTasktaskOverlayIcon](#settaskbaroverlayicon)|Sobrecarregado. Aplica uma sobreposição a um botão de barra de tarefas para indicar o status do aplicativo ou uma notificação ao usuário.|
|[CFrameWnd::SetTitle](#settitle)|Define o título da barra de controle relacionada.|
|[CFrameWnd::ShowControlBar](#showcontrolbar)|Ligue para mostrar a barra de controle.|
|[CFrameWnd::ShowOwnedWindows](#showownedwindows)|Mostra todas as janelas que `CFrameWnd` são descendentes do objeto.|

### <a name="protected-methods"></a>Métodos Protegidos

|Nome|Descrição|
|----------|-----------------|
|[CFrameWnd::OnCreateClient](#oncreateclient)|Cria uma janela de cliente para o quadro.|
|[CFrameWnd::OnHideMenuBar](#onhidemenubar)|Chamado antes que o menu no aplicativo MFC atual esteja oculto.|
|[CFrameWnd::OnShowMenubar](#onshowmenubar)|Chamado antes que o menu no aplicativo MFC atual seja exibido.|

### <a name="public-data-members"></a>Membros de Dados Públicos

|Nome|Descrição|
|----------|-----------------|
|[CFrameWnd::m_bAutoMenuEnable](#m_bautomenuenable)|Controla a ativação automática e desativa a funcionalidade para itens do menu.|
|[CFrameWnd::rectDefault](#rectdefault)|Passe essa `CRect` estática como parâmetro `CFrameWnd` ao criar um objeto para permitir que o Windows escolha o tamanho e a posição iniciais da janela.|

## <a name="remarks"></a>Comentários

Para criar uma janela de quadro útil `CFrameWnd`para sua aplicação, obtenha uma classe de . Adicione variáveis de membro à classe derivada para armazenar dados específicos do seu aplicativo. Implemente funções de membro manipulador de mensagens e um mapa de mensagem na classe derivada para especificar o que acontece quando as mensagens são direcionadas para a janela.

Há três maneiras de construir uma janela de quadro:

- Construa-o diretamente usando [criar](#create).

- Construa-o diretamente usando [loadframe](#loadframe).

- Construa-o indiretamente usando um modelo de documento.

Antes de `Create` ligar `LoadFrame`ou , você deve construir o objeto de janela de quadro no heap usando o **novo** operador C++. Antes `Create`de ligar, você também pode registrar uma classe de janela com a função global [AfxRegisterWndClass](../../mfc/reference/application-information-and-management.md#afxregisterwndclass) para definir os estilos de ícone e classe para o quadro.

Use `Create` a função membro para passar os parâmetros de criação do quadro como argumentos imediatos.

`LoadFrame`requer menos argumentos do que `Create`, e, em vez disso, recupera a maioria de seus valores padrão de recursos, incluindo legenda do quadro, ícone, tabela do acelerador e menu. Para serem `LoadFrame`acessíveis por , todos esses recursos devem ter o mesmo ID de recurso (por exemplo, IDR_MAINFRAME).

Quando `CFrameWnd` um objeto contém visualizações e documentos, eles são criados indiretamente pela estrutura, em vez de diretamente pelo programador. O `CDocTemplate` objeto orquestra a criação do quadro, a criação das visualizações que contêm e a conexão das visualizações com o documento apropriado. Os parâmetros `CDocTemplate` da construtora `CRuntimeClass` especificam as três classes envolvidas (documento, quadro e exibição). Um `CRuntimeClass` objeto é usado pela estrutura para criar dinamicamente novos quadros quando especificado pelo usuário (por exemplo, usando o comando File New ou o comando Window New (Interface de documento múltiplo) ).

Uma classe de janela `CFrameWnd` de quadro derivada deve ser declarada com DECLARE_DYNCREATE para que o mecanismo RUNTIME_CLASS acima funcione corretamente.

A `CFrameWnd` contém implementações padrão para executar as seguintes funções de uma janela principal em um aplicativo típico para Windows:

- Uma `CFrameWnd` janela de quadro mantém o controle de uma exibição ativa atualmente independente da janela ativa do Windows ou do foco de entrada atual. Quando o quadro é reativado, a exibição `CView::OnActivateView`ativa é notificada ligando para .

- Mensagens de comando e muitas mensagens comuns de `OnSetFocus` `OnHScroll`notificação `OnVScroll` de quadros, incluindo aquelas `CFrameWnd` manuseadas pelo , e funções de , são delegadas por uma janela de `CWnd`quadro para a exibição ativa atualmente.

- A exibição ativa atualmente (ou atualmente ativa janela de quadro de filho MDI no caso de um quadro MDI) pode determinar a legenda da janela do quadro. Esse recurso pode ser desativado desligando o FWS_ADDTOTITLE estilo da janela do quadro.

- Uma `CFrameWnd` janela de quadro gerencia o posicionamento das barras de controle, visualizações e outras janelas de crianças dentro da área cliente da janela do quadro. Uma janela de quadro também faz a atualização em tempo ocioso da barra de ferramentas e outros botões da barra de controle. Uma `CFrameWnd` janela de quadro também tem implementações padrão de comandos para alternar e desligar a barra de ferramentas e a barra de status.

- Uma `CFrameWnd` janela de quadro gerencia a barra de menu principal. Quando um menu pop-up é exibido, a janela do quadro usa o mecanismo UPDATE_COMMAND_UI para determinar quais itens do menu devem ser ativados, desativados ou verificados. Quando o usuário seleciona um item do menu, a janela do quadro atualiza a barra de status com a seqüência de mensagens para esse comando.

- Uma `CFrameWnd` janela de quadro tem uma tabela de acelerador opcional que traduz automaticamente os aceleradores do teclado.

- Uma `CFrameWnd` janela de quadro tem um `LoadFrame` conjunto de iD de ajuda opcional com o que é usado para ajuda sensível ao contexto. Uma janela de quadro é o principal orquestrador de estados semimodais, como ajuda sensível ao contexto (SHIFT+F1) e modos de visualização de impressão.

- Uma `CFrameWnd` janela de quadro abrirá um arquivo arrastado do Gerenciador de arquivos e cairá na janela do quadro. Se uma extensão de arquivo estiver registrada e associada ao aplicativo, a janela do quadro responderá à solicitação aberta de troca `ShellExecute` de dados dinâmica (DDE) que ocorre quando o usuário abre um arquivo de dados no Gerenciador de arquivos ou quando a função Do Windows é chamada.

- Se a janela do quadro for a `CWinThread::m_pMainWnd`janela principal do aplicativo (ou seja, ) quando o usuário `OnClose` fechar `OnQueryEndSession`o aplicativo, a janela do quadro solicita ao usuário que salve quaisquer documentos modificados (para e ).

- Se a janela do quadro for a janela principal do aplicativo, a janela do quadro será o contexto para executar o WinHelp. O fechamento da janela do quadro será desligado WINHELP. EXE se ele foi lançado para ajudar para este aplicativo.

Não use o operador de **exclusão** C++ para destruir uma janela de quadro. Use `CWnd::DestroyWindow` em vez disso. A `CFrameWnd` implementação do `PostNcDestroy` excluirá o objeto C++ quando a janela for destruída. Quando o usuário fecha a janela `OnClose` do `DestroyWindow`quadro, o manipulador padrão chamará .

Para obter `CFrameWnd`mais informações, consulte [Frame Windows](../../mfc/frame-windows.md).

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

[Cobject](../../mfc/reference/cobject-class.md)

[Ccmdtarget](../../mfc/reference/ccmdtarget-class.md)

[CWnd](../../mfc/reference/cwnd-class.md)

`CFrameWnd`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** afxwin.h

## <a name="cframewndactivateframe"></a><a name="activateframe"></a>CFrameWnd::Ativarquadro

Ligue para esta função de membro para ativar e restaurar a janela do quadro para que ela seja visível e disponível para o usuário.

```
virtual void ActivateFrame(int nCmdShow = -1);
```

### <a name="parameters"></a>Parâmetros

*Ncmdshow*<br/>
Especifica o parâmetro a ser aprovado para [CWnd::ShowWindow](../../mfc/reference/cwnd-class.md#showwindow). Por padrão, o quadro é mostrado e corretamente restaurado.

### <a name="remarks"></a>Comentários

Essa função de membro é geralmente chamada após um evento de interface não-usuário, como um DDE, OLE ou outro evento que possa mostrar a janela do quadro ou seu conteúdo para o usuário.

A implementação padrão ativa o quadro e o leva ao topo da ordem Z e, se necessário, executa as mesmas etapas para a janela principal do quadro do aplicativo.

Substituir esta função de membro para alterar a forma como um quadro é ativado. Por exemplo, você pode forçar janelas de crianças MDI a serem maximizadas. Adicione a funcionalidade apropriada e, em seguida, chame a versão de classe base com um *nCmdShow*explícito .

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFCWindowing#1](../../mfc/reference/codesnippet/cpp/cframewnd-class_1.cpp)]

## <a name="cframewndbeginmodalstate"></a><a name="beginmodalstate"></a>CFrameWnd::BeginModalState

Ligue para esta função de membro para fazer um modal de janela de quadro.

```
virtual void BeginModalState();
```

## <a name="cframewndcframewnd"></a><a name="cframewnd"></a>CFrameWnd::CFrameWnd

Constrói um `CFrameWnd` objeto, mas não cria a janela do quadro visível.

```
CFrameWnd();
```

### <a name="remarks"></a>Comentários

Ligue `Create` para criar a janela visível.

## <a name="cframewndcreate"></a><a name="create"></a>CFrameWnd::Criar

Chamada para criar e inicializar a `CFrameWnd` janela de quadro do Windows associada ao objeto.

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

*Lpszclassname*<br/>
Aponta para uma seqüência de caracteres com término nulo que nomeia a classe Windows. O nome da classe pode ser `AfxRegisterWndClass` qualquer nome `RegisterClass` registrado com a função global ou a função Windows. Se NULA, usa `CFrameWnd` os atributos padrão predefinidos.

*lpszWindowName*<br/>
Aponta para uma seqüência de caracteres com término nulo que representa o nome da janela. Usado como texto para a barra de título.

*Dwstyle*<br/>
Especifica os atributos de [estilo](../../mfc/reference/styles-used-by-mfc.md#window-styles) da janela. Inclua o estilo FWS_ADDTOTITLE se quiser que a barra de título exiba automaticamente o nome do documento representado na janela.

*Rect*<br/>
Especifica o tamanho e a posição da janela. O valor *rectDefault* permite que o Windows especifique o tamanho e a posição da nova janela.

*Pparentwnd*<br/>
Especifica a janela pai desta janela de quadro. Este parâmetro deve ser NULO para janelas de quadrode nível superior.

*lpszMenuName*<br/>
Identifica o nome do recurso de menu a ser usado com a janela. Use MAKEINTRESOURCE se o menu tiver um ID inteiro em vez de uma seqüência de string. Este parâmetro pode ser NULO.

*Dwexstyle*<br/>
Especifica os atributos de [estilo](../../mfc/reference/styles-used-by-mfc.md#extended-window-styles) estendidos da janela.

*pContext*<br/>
Especifica um ponteiro para uma estrutura [CCreateContext.](../../mfc/reference/ccreatecontext-structure.md) Este parâmetro pode ser NULO.

### <a name="return-value"></a>Valor retornado

Não zero se a inicialização for bem sucedida; caso contrário, 0.

### <a name="remarks"></a>Comentários

Construa `CFrameWnd` um objeto em dois passos. Primeiro, invoque o construtor, `CFrameWnd` que constrói `Create`o objeto, e depois chame , `CFrameWnd` que cria a janela do quadro do Windows e o anexa ao objeto. `Create`inicializa o nome da classe da janela e o nome da janela e registra valores padrão para seu estilo, pai e menu associado.

Use `LoadFrame` em `Create` vez de carregar a janela de quadro de um recurso em vez de especificar seus argumentos.

## <a name="cframewndcreateview"></a><a name="createview"></a>CFrameWnd::CreateView

Chamada `CreateView` para criar uma visão dentro de um quadro.

```
CWnd* CreateView(
    CCreateContext* pContext,
    UINT nID = AFX_IDW_PANE_FIRST);
```

### <a name="parameters"></a>Parâmetros

*pContext*<br/>
Especifica o tipo de exibição e documento.

*nID*<br/>
O número de ida de uma vista.

### <a name="return-value"></a>Valor retornado

Ponteiro para `CWnd` um objeto se for bem sucedido; caso contrário, NULL.

### <a name="remarks"></a>Comentários

Use esta função de membro para `CView`criar "visualizações" que não são derivadas dentro de um quadro. Após `CreateView`a chamada, você deve definir manualmente a exibição como ativa e defini-la como visível; essas tarefas não são `CreateView`executadas automaticamente por .

## <a name="cframewnddockcontrolbar"></a><a name="dockcontrolbar"></a>CFrameWnd::DockControlBar

Faz com que uma barra de controle seja encaixada na janela da moldura.

```cpp
void DockControlBar(
    CControlBar* pBar,
    UINT nDockBarID = 0,
    LPCRECT lpRect = NULL);
```

### <a name="parameters"></a>Parâmetros

*Pbar*<br/>
Aponta para a barra de controle a ser encaixada.

*nDockBarID*<br/>
Determina quais lados da janela de quadro a considerar para acoplamento. Pode ser 0, ou um ou mais dos seguintes:

- AFX_IDW_DOCKBAR_TOP Dock para o lado superior da janela da moldura.

- AFX_IDW_DOCKBAR_BOTTOM Doca para o lado inferior da janela da moldura.

- AFX_IDW_DOCKBAR_LEFT doca para o lado esquerdo da janela da moldura.

- AFX_IDW_DOCKBAR_RIGHT Doca para o lado direito da janela da moldura.

Se 0, a barra de controle pode ser encaixada em qualquer lado habilitado para acoplar na janela do quadro de destino.

*Lprect*<br/>
Determina, em coordenadas de tela, onde a barra de controle será encaixada na área não cliente da janela do quadro de destino.

### <a name="remarks"></a>Comentários

A barra de controle será encaixada em um dos lados da janela do quadro especificado nas chamadas para [CControlBar::EnableDocking](../../mfc/reference/ccontrolbar-class.md#enabledocking) e [CFrameWnd::EnableDocking](#enabledocking). O lado escolhido é determinado por *nDockBarID*.

## <a name="cframewndenabledocking"></a><a name="enabledocking"></a>CFrameWnd::Ativar docking

Chame esta função para habilitar barras de controle ancoráveis em uma janela de quadro.

```cpp
void EnableDocking(DWORD dwDockStyle);
```

### <a name="parameters"></a>Parâmetros

*dwDockStyle*<br/>
Especifica quais lados da janela do quadro podem servir como locais de encaixe para barras de controle. Pode ser um ou mais dos seguintes:

- CBRS_ALIGN_TOP permite acoplar no topo da área do cliente.

- CBRS_ALIGN_BOTTOM permite acoplar na parte inferior da área do cliente.

- CBRS_ALIGN_LEFT permite acoplar no lado esquerdo da área do cliente.

- CBRS_ALIGN_RIGHT Permite acoplar no lado direito da área do cliente.

- CBRS_ALIGN_ANY permite ancorar em qualquer lado da área do cliente.

### <a name="remarks"></a>Comentários

Por padrão, as barras de controle serão encaixadas em um lado da janela do quadro na seguinte ordem: superior, inferior, esquerda, direita.

### <a name="example"></a>Exemplo

  Veja o exemplo de [CToolBar::Create](../../mfc/reference/ctoolbar-class.md#create).

## <a name="cframewndendmodalstate"></a><a name="endmodalstate"></a>CFrameWnd::EndModalState

Chame esta função de membro para alterar uma janela de quadro de modal para modeless.

```
virtual void EndModalState();
```

### <a name="remarks"></a>Comentários

`EndModalState`habilita todas as janelas desativadas pelo [BeginModalState](#beginmodalstate).

## <a name="cframewndfloatcontrolbar"></a><a name="floatcontrolbar"></a>CFrameWnd::FloatControlBar

Chame esta função para fazer com que uma barra de controle não seja encaixada na janela do quadro.

```cpp
void FloatControlBar(
    CControlBar* pBar,
    CPoint point,
    DWORD dwStyle = CBRS_ALIGN_TOP);
```

### <a name="parameters"></a>Parâmetros

*Pbar*<br/>
Aponta para a barra de controle a ser flutuada.

*Ponto*<br/>
A localização, em coordenadas de tela, onde o canto superior esquerdo da barra de controle será colocado.

*Dwstyle*<br/>
Especifica se deve alinhar a barra de controle horizontal ou verticalmente dentro de sua nova janela de quadro. Pode ser qualquer um dos seguintes:

- CBRS_ALIGN_TOP orienta a barra de controle verticalmente.

- CBRS_ALIGN_BOTTOM orienta a barra de controle verticalmente.

- CBRS_ALIGN_LEFT orienta a barra de controle horizontalmente.

- CBRS_ALIGN_RIGHT Orienta a barra de controle horizontalmente.

Se os estilos forem passados especificando orientação horizontal e vertical, a barra de ferramentas será orientada horizontalmente.

### <a name="remarks"></a>Comentários

Normalmente, isso é feito na inicialização do aplicativo quando o programa está restaurando as configurações da execução anterior.

Essa função é chamada pela framework quando o usuário causa uma operação de queda liberando o botão esquerdo do mouse enquanto arrasta a barra de controle sobre um local que não está disponível para acoplamento.

## <a name="cframewndgetactivedocument"></a><a name="getactivedocument"></a>CFrameWnd::GetActiveDocument

Chame esta função de membro para `CDocument` obter um ponteiro para a corrente anexada à exibição ativa atual.

```
virtual CDocument* GetActiveDocument();
```

### <a name="return-value"></a>Valor retornado

Um ponteiro para o [CDocument](../../mfc/reference/cdocument-class.md)atual . Se não houver documento atual, retorna NULL.

## <a name="cframewndgetactiveframe"></a><a name="getactiveframe"></a>CFrameWnd::GetActiveFrame

Chame esta função de membro para obter um ponteiro para a janela de criança mdi (interface de documento múltiplo ativo) de uma janela de quadro MDI.

```
virtual CFrameWnd* GetActiveFrame();
```

### <a name="return-value"></a>Valor retornado

Um ponteiro para a janela de criança MDI ativa. Se o aplicativo for um aplicativo SDI ou a janela do quadro MDI não tiver nenhum documento ativo, o **ponteiro** implícito será devolvido.

### <a name="remarks"></a>Comentários

Se não houver um filho MDI ativo ou o aplicativo for uma única interface de documento (SDI), o **ponteiro** implícito será devolvido.

## <a name="cframewndgetactiveview"></a><a name="getactiveview"></a>CFrameWnd::GetActiveView

Chame esta função de membro para obter um ponteiro para a exibição ativa (se houver) anexada a uma janela de quadros ( `CFrameWnd`).

```
CView* GetActiveView() const;
```

### <a name="return-value"></a>Valor retornado

Um ponteiro para o [CView](../../mfc/reference/cview-class.md)atual . Se não houver uma visão atual, retorna NULL.

### <a name="remarks"></a>Comentários

Esta função retorna NULL quando solicitada para `CMDIFrameWnd`uma janela de quadro principal MDI ( ). Em uma aplicação MDI, a janela de quadro principal do MDI não tem uma visão associada a ele. Em vez disso, `CMDIChildWnd`cada janela infantil individual () tem uma ou mais vistas associadas. A exibição ativa em um aplicativo MDI pode ser obtida primeiro encontrando a janela de criança MDI ativa e, em seguida, encontrando a exibição ativa para essa janela filho. A janela de criança MDI ativa `MDIGetActive` pode `GetActiveFrame` ser encontrada chamando a função ou como demonstrado no seguinte:

[!code-cpp[NVC_MFCWindowing#2](../../mfc/reference/codesnippet/cpp/cframewnd-class_2.cpp)]

## <a name="cframewndgetcontrolbar"></a><a name="getcontrolbar"></a>CFrameWnd::GetControlBar

Chamada `GetControlBar` para obter acesso à barra de controle que está associada com o ID.

```
CControlBar* GetControlBar(UINT nID);
```

### <a name="parameters"></a>Parâmetros

*nID*<br/>
O número de id de uma barra de controle.

### <a name="return-value"></a>Valor retornado

Um ponteiro para a barra de controle que está associado com o ID.

### <a name="remarks"></a>Comentários

O parâmetro *nID* refere-se ao identificador `Create` único passado para o método da barra de controle. Para obter mais informações sobre barras de controle, consulte o tópico intitulado [Barras de Controle](../../mfc/control-bars.md).

`GetControlBar`vai retornar a barra de controle mesmo que esteja flutuando e, portanto, não é atualmente uma janela infantil do quadro.

## <a name="cframewndgetdockstate"></a><a name="getdockstate"></a>CFrameWnd::GetDockState

Ligue para esta função de membro para armazenar informações `CDockState` de estado sobre as barras de controle da janela do quadro em um objeto.

```cpp
void GetDockState(CDockState& state) const;
```

### <a name="parameters"></a>Parâmetros

*state*<br/>
Contém o estado atual das barras de controle da janela do quadro no retorno.

### <a name="remarks"></a>Comentários

Em seguida, você `CDockState` pode escrever `CDockState::SaveState` `Serialize`o conteúdo de armazenamento usando ou . Se você quiser restaurar as barras de controle em `CDockState::LoadState` um `Serialize`estado `SetDockState` anterior, carregue o estado com ou , em seguida, ligue para aplicar o estado anterior às barras de controle da janela do quadro.

## <a name="cframewndgetmenubarstate"></a><a name="getmenubarstate"></a>CFrameWnd::GetMenuBarState

Recupera o estado de exibição do menu no aplicativo MFC atual.

```
virtual DWORD GetMenuBarState();
```

### <a name="return-value"></a>Valor retornado

O valor de retorno pode ter os seguintes valores:

- AFX_MBS_VISIBLE (0x01) - O menu é visível.

- AFX_MBS_HIDDEN (0x02) - O menu está escondido.

### <a name="remarks"></a>Comentários

Se ocorrer um erro de tempo de execução, este método será afirmado no modo Debug e levanta uma exceção derivada da classe [CException.](../../mfc/reference/cexception-class.md)

## <a name="cframewndgetmenubarvisibility"></a><a name="getmenubarvisibility"></a>CFrameWnd::GetMenuBarVisibility

Indica se o estado padrão do menu no aplicativo MFC atual está oculto ou visível.

```
virtual DWORD CFrameWnd::GetMenuBarVisibility();
```

### <a name="return-value"></a>Valor retornado

Este método retorna um dos seguintes valores:

- AFX_MBV_KEEPVISIBLE (0x01) - O menu é exibido o tempo todo, e por padrão não tem o foco.

- AFX_MBV_DISPLAYONFOCUS (0x02) - O menu está oculto por padrão. Se o menu estiver oculto, pressione a tecla ALT para exibir o menu e dar-lhe o foco. Se o menu for exibido, pressione a tecla ALT ou ESC para escondê-lo.

- AFX_MBV_ DISPLAYONFOCUS (0x02) &#124; AFX_MBV_DISPLAYONF10 (0x04) (bitwise combination (OR)) - O menu está oculto por padrão. Se o menu estiver oculto, pressione a tecla F10 para exibir o menu e dar-lhe o foco. Se o menu for exibido, pressione a tecla F10 para alternar o foco dentro ou fora do menu. O menu é exibido até que você pressione a tecla ALT ou ESC para escondê-lo.

### <a name="remarks"></a>Comentários

Se ocorrer um erro de tempo de execução, este método será afirmado no modo Debug e levanta uma exceção derivada da classe [CException.](../../mfc/reference/cexception-class.md)

## <a name="cframewndgetmessagebar"></a><a name="getmessagebar"></a>CFrameWnd::GetMessageBar

Ligue para esta função de membro para obter um ponteiro para a barra de status.

```
virtual CWnd* GetMessageBar();
```

### <a name="return-value"></a>Valor retornado

Ponteiro para a janela da barra de status.

## <a name="cframewndgetmessagestring"></a><a name="getmessagestring"></a>CFrameWnd::GetMessageString

Substituir esta função para fornecer strings personalizadas para IDs de comando.

```
virtual void GetMessageString(
    UINT nID,
    CString& rMessage) const;
```

### <a name="parameters"></a>Parâmetros

*nID*<br/>
ID de recursos da mensagem desejada.

*rMessage*<br/>
`CString`objeto em que colocar a mensagem.

### <a name="remarks"></a>Comentários

A implementação padrão simplesmente carrega a string especificada por *nID* do arquivo de recursos. Essa função é chamada pelo framework quando a seqüência de mensagens na barra de status precisa ser atualizada.

## <a name="cframewndgettitle"></a><a name="gettitle"></a>CFrameWnd::GetTitle

Recupera o título do objeto da janela.

```
CString GetTitle() const;
```

### <a name="return-value"></a>Valor retornado

Um objeto [CString](../../atl-mfc-shared/reference/cstringt-class.md) contendo o título atual do objeto da janela.

## <a name="cframewndinitialupdateframe"></a><a name="initialupdateframe"></a>CFrameWnd::InitialUpdateFrame

Ligue `IntitialUpdateFrame` depois de criar `Create`um novo quadro com .

```cpp
void InitialUpdateFrame(
    CDocument* pDoc,
    BOOL bMakeVisible);
```

### <a name="parameters"></a>Parâmetros

*pDoc*<br/>
Aponta para o documento ao qual a janela do quadro está associada. Pode ser NULL.

*Bmakevisible*<br/>
Se TRUE, indica que o quadro deve se tornar visível e ativo. Se FALSO, nenhum descendente é visível.

### <a name="remarks"></a>Comentários

Isso faz com que todas as `OnInitialUpdate` visualizações na janela do quadro recebam suas chamadas.

Além disso, se não houvesse uma visualização ativa anteriormente, a visão primária da janela do quadro é ativa. A visão primária é uma visão com uma id infantil de AFX_IDW_PANE_FIRST. Finalmente, a janela do quadro é tornada visível se *bMakeVisible* não for zero. Se *bMakeVisible* for 0, o foco atual e o estado visível da janela do quadro permanecerão inalterados. Não é necessário chamar essa função ao usar a implementação do Arquivo Novo e Arquivo Aberto.

## <a name="cframewndinmodalstate"></a><a name="inmodalstate"></a>CFrameWnd::InModalState

Ligue para esta função de membro para verificar se uma janela de quadro é modal ou modeless.

```
BOOL InModalState() const;
```

### <a name="return-value"></a>Valor retornado

Não zero se sim; caso contrário, 0.

## <a name="cframewndistracking"></a><a name="istracking"></a>CFrameWnd::IsTracking

Ligue para esta função de membro para determinar se a barra de divisor na janela está sendo movida no momento.

```
BOOL IsTracking() const;
```

### <a name="return-value"></a>Valor retornado

Não zero se uma operação de divisor estiver em andamento; caso contrário, 0.

## <a name="cframewndloadacceltable"></a><a name="loadacceltable"></a>CFrameWnd::LoadAccelTable

Ligue para carregar a tabela do acelerador especificada.

```
BOOL LoadAccelTable(LPCTSTR lpszResourceName);
```

### <a name="parameters"></a>Parâmetros

*Lpszresourcename*<br/>
Identifica o nome do recurso do acelerador. Use MAKEINTRESOURCE se o recurso for identificado com um ID inteiro.

### <a name="return-value"></a>Valor retornado

Não zero se a tabela do acelerador foi carregada com sucesso; caso contrário, 0.

### <a name="remarks"></a>Comentários

Apenas uma mesa pode ser carregada de cada vez.

As tabelas do acelerador carregadas de recursos são liberadas automaticamente quando o aplicativo termina.

Se você `LoadFrame` chamar para criar a janela de quadro, a estrutura carrega uma tabela de acelerador junto com os recursos do menu e do ícone, e uma chamada subseqüente para esta função de membro é então desnecessária.

## <a name="cframewndloadbarstate"></a><a name="loadbarstate"></a>CFrameWnd::LoadBarState

Chame esta função para restaurar as configurações de cada barra de controle de propriedade da janela do quadro.

```cpp
void LoadBarState(LPCTSTR lpszProfileName);
```

### <a name="parameters"></a>Parâmetros

*Lpszprofilename*<br/>
Nome de uma seção no arquivo de inicialização (INI) ou de uma chave no registro do Windows onde as informações do estado são armazenadas.

### <a name="remarks"></a>Comentários

As informações restauradas incluem visibilidade, orientação horizontal/vertical, estado de acoplamento e posição de barra de controle.

As configurações que deseja restaurar devem ser escritas no registro antes de você chamar `LoadBarState`. Escreva as informações no registro ligando para [CWinApp::SetRegistryKey](../../mfc/reference/cwinapp-class.md#setregistrykey). Escreva as informações para o arquivo INI ligando para [SaveBarState](#savebarstate).

## <a name="cframewndloadframe"></a><a name="loadframe"></a>CFrameWnd::''''''''''''''''''''

Chamada para criar dinamicamente uma janela de quadro a partir de informações de recursos.

```
virtual BOOL LoadFrame(
    UINT nIDResource,
    DWORD dwDefaultStyle = WS_OVERLAPPEDWINDOW | FWS_ADDTOTITLE,
    CWnd* pParentWnd = NULL,
    CCreateContext* pContext = NULL);
```

### <a name="parameters"></a>Parâmetros

*Nidresource*<br/>
O ID dos recursos compartilhados associados à janela do quadro.

*dwDefaultStyle*<br/>
O [estilo](../../mfc/reference/styles-used-by-mfc.md#window-styles)do quadro. Inclua o estilo FWS_ADDTOTITLE se quiser que a barra de título exiba automaticamente o nome do documento representado na janela.

*Pparentwnd*<br/>
Um ponteiro para o pai do quadro.

*pContext*<br/>
Um ponteiro para uma estrutura [CCreateContext.](../../mfc/reference/ccreatecontext-structure.md) Este parâmetro pode ser NULO.

### <a name="remarks"></a>Comentários

Construa `CFrameWnd` um objeto em dois passos. Primeiro, invoque o construtor, `CFrameWnd` que constrói `LoadFrame`o objeto, e depois chame, que carrega a janela `CFrameWnd` do quadro do Windows e os recursos associados e anexa a janela do quadro ao objeto. O parâmetro *nIDResource* especifica o menu, a tabela do acelerador, o ícone e o recurso de string do título para a janela do quadro.

Use `Create` a função `LoadFrame` membro em vez de quando quiser especificar todos os parâmetros de criação da janela do quadro.

A estrutura `LoadFrame` é chamada quando cria uma janela de quadro usando um objeto de modelo de documento.

A estrutura usa o argumento *pContext* para especificar os objetos a serem conectados à janela do quadro, incluindo quaisquer objetos de exibição contidos. Você pode definir o *argumento pContext* para NULL quando você chamar `LoadFrame`.

## <a name="cframewndm_bautomenuenable"></a><a name="m_bautomenuenable"></a>CFrameWnd::m_bAutoMenuEnable

Quando esse membro de dados estiver ativado (que é o padrão), os itens do menu que não têm ON_UPDATE_COMMAND_UI ou ON_COMMAND manipuladores serão automaticamente desativados quando o usuário puxar um menu.

```
BOOL m_bAutoMenuEnable;
```

### <a name="remarks"></a>Comentários

Os itens do menu que possuem um manipulador de ON_COMMAND, mas nenhum manipulador de ON_UPDATE_COMMAND_UI serão habilitados automaticamente.

Quando este membro de dados é definido, os itens do menu são automaticamente ativados da mesma forma que os botões da barra de ferramentas estão ativados.

> [!NOTE]
> `m_bAutoMenuEnable`não tem efeito em itens de menu de nível superior.

Esse membro de dados simplifica a implementação de comandos opcionais com base na seleção atual e reduz a necessidade de escrever ON_UPDATE_COMMAND_UI manipuladores para habilitar e desativar itens de menu.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFCWindowing#3](../../mfc/reference/codesnippet/cpp/cframewnd-class_3.cpp)]

## <a name="cframewndnegotiateborderspace"></a><a name="negotiateborderspace"></a>CFrameWnd::NegocieBorderSpace

Chame esta função de membro para negociar espaço de borda em uma janela de quadro durante a ativação no local do OLE.

```
virtual BOOL NegotiateBorderSpace(
    UINT nBorderCmd,
    LPRECT lpRectBorder);
```

### <a name="parameters"></a>Parâmetros

*nBorderCmd*<br/>
Contém um dos seguintes `enum BorderCmd`valores do :

- `borderGet` = 1

- `borderRequest` = 2

- `borderSet`= 3

*lpRectBorder*<br/>
Ponteiro para uma estrutura [RECT](/windows/win32/api/windef/ns-windef-rect) ou um objeto [CRect](../../atl-mfc-shared/reference/crect-class.md) que especifique as coordenadas da borda.

### <a name="return-value"></a>Valor retornado

Não zero se bem sucedido; caso contrário, 0.

### <a name="remarks"></a>Comentários

Esta função membro `CFrameWnd` é a implementação da negociação espacial de fronteira OLE.

## <a name="cframewndonbarcheck"></a><a name="onbarcheck"></a>CFrameWnd::OnBarCheck

Chamado sempre que uma ação é realizada na barra de controle especificada.

```
afx_msg BOOL OnBarCheck(UINT nID);
```

### <a name="parameters"></a>Parâmetros

*nID*<br/>
O ID da barra de controle sendo mostrado.

### <a name="return-value"></a>Valor retornado

Não zero se a barra de controle existisse; caso contrário, 0.

## <a name="cframewndoncontexthelp"></a><a name="oncontexthelp"></a>CFrameWnd::OnContextHelp

Manuseio shift+F1 Ajuda para itens no local.

```
afx_msg void OnContextHelp();
```

### <a name="remarks"></a>Comentários

Para habilitar uma ajuda sensível ao contexto, você deve adicionar um

[!code-cpp[NVC_MFCDocViewSDI#16](../../mfc/codesnippet/cpp/cframewnd-class_4.cpp)]

declaração `CFrameWnd` ao mapa de mensagens da classe e também adicionar uma entrada de tabela de acelerador, tipicamente SHIFT+F1, para habilitar essa função de membro.

Se o aplicativo for um `OnContextHelp` contêiner OLE, coloque todos os itens no local contidos no objeto da janela do quadro no modo Ajuda. O cursor muda para uma seta e um ponto de interrogação, e o usuário pode mover o ponteiro do mouse e pressionar o botão esquerdo do mouse para selecionar uma caixa de diálogo, janela, menu ou botão de comando. Esta função de membro `WinHelp` chama a função Windows com o contexto de ajuda do objeto sob o cursor.

## <a name="cframewndoncreateclient"></a><a name="oncreateclient"></a>CFrameWnd::OnCreateClient

Chamado pelo quadro durante `OnCreate`a execução de .

```
virtual BOOL OnCreateClient(
    LPCREATESTRUCT lpcs,
    CCreateContext* pContext);
```

### <a name="parameters"></a>Parâmetros

*lpcs*<br/>
Um ponteiro para uma estrutura do Windows [CREATESTRUCT.](/windows/win32/api/winuser/ns-winuser-createstructw)

*pContext*<br/>
Um ponteiro para uma estrutura [CCreateContext.](../../mfc/reference/ccreatecontext-structure.md)

### <a name="return-value"></a>Valor retornado

Não zero se bem sucedido; caso contrário, 0.

### <a name="remarks"></a>Comentários

Nunca chame essa função.

A implementação padrão dessa `CView` função cria um objeto a partir das informações fornecidas no *pContext*, se possível.

Substituir essa função para substituir valores passados no `CCreateContext` objeto ou para alterar a forma como os controles na área principal do cliente da janela de quadro são criados. Os `CCreateContext` membros que você pode substituir são descritos na classe [CCreateContext.](../../mfc/reference/ccreatecontext-structure.md)

> [!NOTE]
> Não substitua os `CREATESTRUCT` valores passados na estrutura. São apenas para uso informativo. Se você quiser substituir o retângulo inicial da janela, por exemplo, anule a `CWnd` função de membro [PreCreateWindow](../../mfc/reference/cwnd-class.md#precreatewindow).

## <a name="cframewndonhidemenubar"></a><a name="onhidemenubar"></a>CFrameWnd::OnHideMenuBar

Esta função é chamada quando o sistema está prestes a ocultar a barra de menu no aplicativo MFC atual.

```
virtual void OnHideMenuBar();
```

### <a name="remarks"></a>Comentários

Este manipulador de eventos permite que seu aplicativo execute ações personalizadas quando o sistema está prestes a ocultar o menu. Não é possível impedir que o menu fique oculto, mas pode, por exemplo, chamar outros métodos para recuperar o estilo ou o estado do menu.

## <a name="cframewndonsetpreviewmode"></a><a name="onsetpreviewmode"></a>CFrameWnd::Visualização de insetMode

Chame esta função de membro para definir a janela principal do quadro do aplicativo para dentro e para fora do modo de visualização de impressão.

```
virtual void OnSetPreviewMode(
    BOOL bPreview,
    CPrintPreviewState* pState);
```

### <a name="parameters"></a>Parâmetros

*bPreview*<br/>
Especifica se deve ou não colocar o aplicativo no modo de visualização de impressão. Definido como TRUE para colocar na visualização de impressão, FALSE para cancelar o modo de visualização.

*Pstate*<br/>
Um ponteiro `CPrintPreviewState` para uma estrutura.

### <a name="remarks"></a>Comentários

A implementação padrão desativa todas as barras de ferramentas padrão e oculta o menu principal e a janela principal do cliente. Isso transforma as janelas do quadro MDI em janelas temporárias de moldura SDI.

Substituir esta função de membro para personalizar o ocultamento e a exibição de barras de controle e outras partes da janela do quadro durante a visualização de impressão. Chame a implementação da classe base de dentro da versão substituída.

## <a name="cframewndonshowmenubar"></a><a name="onshowmenubar"></a>CFrameWnd::OnShowMenubar

Esta função é chamada quando o sistema está prestes a exibir a barra de menu no aplicativo MFC atual.

```
virtual void OnShowMenuBar();
```

### <a name="remarks"></a>Comentários

Este manipulador de eventos permite que seu aplicativo execute ações personalizadas quando o menu está prestes a ser exibido. Não é possível impedir que o menu seja exibido, mas pode, por exemplo, chamar outros métodos para recuperar o estilo ou o estado do menu.

## <a name="cframewndonupdatecontrolbarmenu"></a><a name="onupdatecontrolbarmenu"></a>CFrameWnd::OnUpdateControlBarmenu

Chamado pelo framework quando o menu associado é atualizado.

```
afx_msg void OnUpdateControlBarMenu(CCmdUI* pCmdUI);
```

### <a name="parameters"></a>Parâmetros

*pCmdUI*<br/>
Um ponteiro para um objeto [CCmdUI](../../mfc/reference/ccmdui-class.md) representando o menu que gerou o comando update. O manipulador de atualizações chama `CCmdUI` a função [De habilitar](../../mfc/reference/ccmdui-class.md#enable) o membro do objeto através de *pCmdUI* para atualizar a interface do usuário.

## <a name="cframewndrecalclayout"></a><a name="recalclayout"></a>CFrameWnd::RecalcLayout

Chamada pela estrutura quando as barras de controle padrão são alternadas ou desligadas ou quando a janela do quadro é redimensionada.

```
virtual void RecalcLayout(BOOL bNotify = TRUE);
```

### <a name="parameters"></a>Parâmetros

*bNotificar*<br/>
Determina se o item ativo no local para a janela do quadro recebe a notificação da alteração de layout. Se TRUE, o item é notificado; caso contrário, FALSO.

### <a name="remarks"></a>Comentários

A implementação padrão desta `CWnd` função `RepositionBars` membro chama a função de membro para reposicionar todas as `CView` barras de controle no quadro, bem como na janela principal do cliente (geralmente um ou MDICLIENT).

Substituir esta função de membro para controlar a aparência e o comportamento das barras de controle depois que o layout da janela do quadro foi alterado. Por exemplo, ligue-o quando ligar ou desligar as barras de controle ou adicionar outra barra de controle.

## <a name="cframewndrectdefault"></a><a name="rectdefault"></a>CFrameWnd::rectDefault

Passe esta `CRect` estática como um parâmetro ao criar uma janela para permitir que o Windows escolha o tamanho e a posição iniciais da janela.

```
static AFX_DATA const CRect rectDefault;
```

## <a name="cframewndsavebarstate"></a><a name="savebarstate"></a>CFrameWnd::SaveBarState

Ligue para esta função para armazenar informações sobre cada barra de controle de propriedade da janela do quadro.

```cpp
void SaveBarState(LPCTSTR lpszProfileName) const;
```

### <a name="parameters"></a>Parâmetros

*Lpszprofilename*<br/>
Nome de uma seção no arquivo de inicialização ou de uma chave no registro do Windows onde as informações do estado são armazenadas.

### <a name="remarks"></a>Comentários

Essas informações podem ser lidas a partir do arquivo de inicialização usando [LoadBarState](#loadbarstate). As informações armazenadas incluem visibilidade, orientação horizontal/vertical, estado de acoplamento e posição da barra de controle.

## <a name="cframewndsetactivepreviewview"></a><a name="setactivepreviewview"></a>CFrameWnd::SetActivePreviewView

Designa a exibição especificada como a exibição ativa de Visualização Rica.

```cpp
void SetActivePreviewView(CView* pViewNew);
```

### <a name="parameters"></a>Parâmetros

*pViewNew*<br/>
Um ponteiro para uma visão a ser ativada.

### <a name="remarks"></a>Comentários

## <a name="cframewndsetactiveview"></a><a name="setactiveview"></a>CFrameWnd::SetActiveView

Chame esta função de membro para definir a exibição ativa.

```cpp
void SetActiveView(
    CView* pViewNew,
    BOOL bNotify = TRUE);
```

### <a name="parameters"></a>Parâmetros

*pViewNew*<br/>
Especifica um ponteiro para um objeto [CView](../../mfc/reference/cview-class.md) ou NULL para nenhuma exibição ativa.

*bNotificar*<br/>
Especifica se a exibição deve ser notificada da ativação. Se VERDADEIRO, `OnActivateView` é chamado para a nova visão; se FALSO, não é.

### <a name="remarks"></a>Comentários

A estrutura chamará essa função automaticamente à medida que o usuário altera o foco para uma exibição dentro da janela do quadro. Você pode ligar `SetActiveView` explicitamente para alterar o foco para a exibição especificada.

## <a name="cframewndsetdockstate"></a><a name="setdockstate"></a>CFrameWnd::SetDockState

Ligue para esta função de membro `CDockState` para aplicar informações de estado armazenadas em um objeto nas barras de controle da janela do quadro.

```cpp
void SetDockState(const CDockState& state);
```

### <a name="parameters"></a>Parâmetros

*state*<br/>
Aplique o estado armazenado nas barras de controle da janela do quadro.

### <a name="remarks"></a>Comentários

Para restaurar um estado anterior das barras de controle, `Serialize`você `SetDockState` pode carregar o estado armazenado com `CDockState::LoadState` ou , em seguida, usá-lo para aplicá-lo nas barras de controle da janela do quadro. O estado anterior é `CDockState` armazenado no objeto com`GetDockState`

## <a name="cframewndsetmenubarstate"></a><a name="setmenubarstate"></a>CFrameWnd::SetMenuBarState

Define o estado de exibição do menu no aplicativo MFC atual como oculto ou exibido.

```
virtual BOOL SetMenuBarState(DWORD nState);
```

### <a name="parameters"></a>Parâmetros

|Parâmetro|Descrição|
|---------------|-----------------|
|*Nstate*|[em] Especifica se é exibido ou ocultado o menu. O parâmetro *nState* pode ter os seguintes valores:<br /><br />- AFX_MBS_VISIBLE (0x01) - Exibe o menu se estiver oculto, mas não tem efeito se for visível.<br />- AFX_MBS_HIDDEN (0x02) - Oculta o menu se for visível, mas não tem efeito se estiver escondido.|

### <a name="return-value"></a>Valor retornado

TRUE se esse método mudar com sucesso o estado do menu; caso contrário, FALSE.

### <a name="remarks"></a>Comentários

Se ocorrer um erro de tempo de execução, este método será afirmado no modo Debug e levanta uma exceção derivada da classe [CException.](../../mfc/reference/cexception-class.md)

## <a name="cframewndsetmenubarvisibility"></a><a name="setmenubarvisibility"></a>CFrameWnd::SetMenuBarVisibility

Define o comportamento padrão do menu no aplicativo MFC atual para ser oculto ou visível.

```
virtual void SetMenuBarVisibility(DWORD nStyle);
```

### <a name="parameters"></a>Parâmetros

|Parâmetro|Descrição|
|---------------|-----------------|
|*nStyle*|[em] Especifica se o menu está oculto por padrão ou se é visível e tem o foco. O parâmetro *nStyle* pode ter os seguintes valores:<br /><br />- AFX_MBV_KEEPVISIBLE (0x01) -<br />     O menu é exibido o tempo todo, e por padrão não tem o foco.<br />- AFX_MBV_DISPLAYONFOCUS (0x02) -<br />     O menu está oculto por padrão. Se o menu estiver oculto, pressione a tecla ALT para exibir o menu e dar-lhe o foco. Se o menu for exibido, pressione a tecla ALT ou ESC para ocultar o menu.<br />- AFX_MBV_ DISPLAYONFOCUS (0x02) &#124; AFX_MBV_DISPLAYONF10 (0x04)<br />     (bitwise combination (OR)) - O menu está oculto por padrão. Se o menu estiver oculto, pressione a tecla F10 para exibir o menu e dar-lhe o foco. Se o menu for exibido, pressione a tecla F10 para alternar o foco dentro ou fora do menu. O menu é exibido até que você pressione a tecla ALT ou ESC para escondê-lo.|

### <a name="remarks"></a>Comentários

Se o valor do parâmetro *nStyle* não for válido, este método será afirmado no modo Debug e aumenta [cInvalidArgException](../../mfc/reference/cinvalidargexception-class.md) no modo de liberação. No caso de outros erros de tempo de execução, este método afirma no modo Debug e levanta uma exceção derivada da classe [CException.](../../mfc/reference/cexception-class.md)

Este método afeta o estado dos menus em aplicativos escritos para o Windows Vista e posteriormente.

## <a name="cframewndsetmessagetext"></a><a name="setmessagetext"></a>CFrameWnd::SetMessageText

Chame esta função para colocar uma seqüência no painel da barra de status que tenha um ID de 0.

```cpp
void SetMessageText(LPCTSTR lpszText);
void SetMessageText(UINT nID);
```

### <a name="parameters"></a>Parâmetros

*lpszText*<br/>
Aponta para a string a ser colocada na barra de status.

*nID*<br/>
ID de recurso de string da string a ser colocada na barra de status.

### <a name="remarks"></a>Comentários

Este é tipicamente o painel mais à esquerda e mais longo da barra de status.

## <a name="cframewndsetprogressbarposition"></a><a name="setprogressbarposition"></a>CFrameWnd::SetProgressBarPosition

Define a posição atual para a barra de progresso do Windows 7 exibida na barra de tarefas.

```cpp
void SetProgressBarPosition(int nProgressPos);
```

### <a name="parameters"></a>Parâmetros

*nProgressPos*<br/>
Especifica a posição a definir. Deve estar dentro do `SetProgressBarRange`intervalo definido por .

### <a name="remarks"></a>Comentários

## <a name="cframewndsetprogressbarrange"></a><a name="setprogressbarrange"></a>CFrameWnd::SetProgressBarRange

Define o intervalo para a barra de progresso do Windows 7 exibida na barra de tarefas.

```cpp
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

## <a name="cframewndsetprogressbarstate"></a><a name="setprogressbarstate"></a>CFrameWnd::SetProgressBarState

Define o tipo e o estado do indicador de progresso exibidos em um botão de barra de tarefas.

```cpp
void SetProgressBarState(TBPFLAG tbpFlags);
```

### <a name="parameters"></a>Parâmetros

*TbpFlags*<br/>
Sinalizadores que controlam o estado atual do botão de progresso. Especifique apenas uma das seguintes bandeiras porque todos os estados são mutuamente exclusivos: TBPF_NOPROGRESS, TBPF_INDETERMINATE, TBPF_NORMAL, TBPF_ERROR, TBPF_PAUSED.

### <a name="remarks"></a>Comentários

## <a name="cframewndsettaskbaroverlayicon"></a><a name="settaskbaroverlayicon"></a>CFrameWnd::SetTasktaskOverlayIcon

Sobrecarregado. Aplica uma sobreposição a um botão de barra de tarefas para indicar o status do aplicativo ou notificar o usuário.

```
BOOL SetTaskbarOverlayIcon(
    UINT nIDResource,
    LPCTSTR lpcszDescr);

BOOL SetTaskbarOverlayIcon(
    HICON hIcon,
    LPCTSTR lpcszDescr);
```

### <a name="parameters"></a>Parâmetros

*Nidresource*<br/>
Especifica o ID de recurso de um ícone para usar como sobreposição. Consulte a descrição *de hIcon* para obter detalhes.

*lpcszDescr*<br/>
Um ponteiro para uma seqüência que fornece uma versão de texto alt das informações transmitidas pela sobreposição, para fins de acessibilidade.

*Hicon*<br/>
A alça de um ícone para usar como sobreposição. Este deve ser um pequeno ícone, medindo 16x16 pixels a 96 pontos por polegada (dpi). Se um ícone de sobreposição já estiver aplicado no botão barra de tarefas, essa sobreposição existente será substituída. Este valor pode ser NULO. A forma como um valor NULL é manipulado depende se o botão de barra de tarefas representa uma única janela ou um grupo de janelas. É responsabilidade do aplicativo de chamada liberar *hIcon* quando ele não é mais necessário.

### <a name="return-value"></a>Valor retornado

VERDADE se bem sucedido; FALSO se a versão do SISTEMA OPERACIONAL for menor que o Windows 7 ou se ocorrer um erro na configuração do ícone.

### <a name="remarks"></a>Comentários

## <a name="cframewndsettitle"></a><a name="settitle"></a>CFrameWnd::SetTitle

Define o título do objeto da janela.

```cpp
void SetTitle(LPCTSTR lpszTitle);
```

### <a name="parameters"></a>Parâmetros

*lpszTitle*<br/>
Um ponteiro para uma seqüência de caracteres contendo o título do objeto da janela.

## <a name="cframewndshowcontrolbar"></a><a name="showcontrolbar"></a>CFrameWnd::ShowControlBar

Ligue para esta função de membro para mostrar ou ocultar a barra de controle.

```cpp
void ShowControlBar(
    CControlBar* pBar,
    BOOL bShow,
    BOOL bDelay);
```

### <a name="parameters"></a>Parâmetros

*Pbar*<br/>
Ponteiro para a barra de controle a ser mostrado ou escondido.

*Bshow*<br/>
Se TRUE, especifica que a barra de controle deve ser mostrada. Se FALSO, especifica que a barra de controle deve ser ocultada.

*bAtraso*<br/>
Se TRUE, demore a mostrar a barra de controle. Se FALSO, mostre a barra de controle imediatamente.

## <a name="cframewndshowownedwindows"></a><a name="showownedwindows"></a>CFrameWnd::ShowOwnedWindows

Chame esta função de membro para mostrar `CFrameWnd` todas as janelas que são descendentes do objeto.

```cpp
void ShowOwnedWindows(BOOL bShow);
```

### <a name="parameters"></a>Parâmetros

*Bshow*<br/>
Especifica se as janelas de propriedade devem ser mostradas ou ocultas.

## <a name="see-also"></a>Confira também

[Classe CWnd](../../mfc/reference/cwnd-class.md)<br/>
[Gráfico da hierarquia](../../mfc/hierarchy-chart.md)<br/>
[Classe CWnd](../../mfc/reference/cwnd-class.md)<br/>
[Classe CMDIFrameWnd](../../mfc/reference/cmdiframewnd-class.md)<br/>
[Classe CMDIChildWnd](../../mfc/reference/cmdichildwnd-class.md)<br/>
[Classe CView](../../mfc/reference/cview-class.md)<br/>
[Classe CDocTemplate](../../mfc/reference/cdoctemplate-class.md)<br/>
[Estrutura CRuntimeClass](../../mfc/reference/cruntimeclass-structure.md)
