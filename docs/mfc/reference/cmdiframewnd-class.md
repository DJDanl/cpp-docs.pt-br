---
title: Classe CMDIFrameWnd
ms.date: 11/04/2016
f1_keywords:
- CMDIFrameWnd
- AFXWIN/CMDIFrameWnd
- AFXWIN/CMDIFrameWnd::CMDIFrameWnd
- AFXWIN/CMDIFrameWnd::CreateClient
- AFXWIN/CMDIFrameWnd::CreateNewChild
- AFXWIN/CMDIFrameWnd::GetWindowMenuPopup
- AFXWIN/CMDIFrameWnd::MDIActivate
- AFXWIN/CMDIFrameWnd::MDICascade
- AFXWIN/CMDIFrameWnd::MDIGetActive
- AFXWIN/CMDIFrameWnd::MDIIconArrange
- AFXWIN/CMDIFrameWnd::MDIMaximize
- AFXWIN/CMDIFrameWnd::MDINext
- AFXWIN/CMDIFrameWnd::MDIPrev
- AFXWIN/CMDIFrameWnd::MDIRestore
- AFXWIN/CMDIFrameWnd::MDISetMenu
- AFXWIN/CMDIFrameWnd::MDITile
helpviewer_keywords:
- CMDIFrameWnd [MFC], CMDIFrameWnd
- CMDIFrameWnd [MFC], CreateClient
- CMDIFrameWnd [MFC], CreateNewChild
- CMDIFrameWnd [MFC], GetWindowMenuPopup
- CMDIFrameWnd [MFC], MDIActivate
- CMDIFrameWnd [MFC], MDICascade
- CMDIFrameWnd [MFC], MDIGetActive
- CMDIFrameWnd [MFC], MDIIconArrange
- CMDIFrameWnd [MFC], MDIMaximize
- CMDIFrameWnd [MFC], MDINext
- CMDIFrameWnd [MFC], MDIPrev
- CMDIFrameWnd [MFC], MDIRestore
- CMDIFrameWnd [MFC], MDISetMenu
- CMDIFrameWnd [MFC], MDITile
ms.assetid: fa8736e6-511b-4c51-8b4d-eba78378aeb9
ms.openlocfilehash: d5c9bc12e6c3f0ab4742a940547087c9742caf73
ms.sourcegitcommit: 7a6116e48c3c11b97371b8ae4ecc23adce1f092d
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/22/2020
ms.locfileid: "81754550"
---
# <a name="cmdiframewnd-class"></a>Classe CMDIFrameWnd

Fornece a funcionalidade de uma janela de quadro de interface de documento múltiplo do Windows (MDI), juntamente com os membros para gerenciar a janela.

## <a name="syntax"></a>Sintaxe

```
class CMDIFrameWnd : public CFrameWnd
```

## <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores públicos

|Nome|Descrição|
|----------|-----------------|
|[CMDIFrameWnd::CMDIFrameWnd](#cmdiframewnd)|Constrói um `CMDIFrameWnd`.|

### <a name="public-methods"></a>Métodos públicos

|Nome|Descrição|
|----------|-----------------|
|[CMDIFrameWnd::CreateClient](#createclient)|Cria uma janela MDICLIENT `CMDIFrameWnd`do Windows para isso . Chamado pela `OnCreate` função `CWnd`membro de .|
|[CMDIFrameWnd::CreateNewChild](#createnewchild)|Cria uma nova janela para crianças.|
|[CMDIFrameWnd::GetWindowMenuPopup](#getwindowmenupopup)|Retorna o menu pop-up janela.|
|[CMDIFrameWnd::MDIActivate](#mdiactivate)|Ativa uma janela de criança MDI diferente.|
|[CMDIFrameWnd::MDICascade](#mdicascade)|Organiza todas as janelas infantis em um formato em cascata.|
|[CMDIFrameWnd::MDIGetActive](#mdigetactive)|Recupera a janela de criança MDI atualmente ativa, juntamente com uma bandeira indicando se a criança é maximizada ou não.|
|[CMDIFrameWnd::MDIIconArrange](#mdiiconarrange)|Organiza todas as janelas de crianças de documento minimizadas.|
|[CMDIFrameWnd::MDIMaximize](#mdimaximize)|Maximiza uma janela de criança MDI.|
|[CMDIFrameWnd::MDINext](#mdinext)|Ativa a janela da criança imediatamente atrás da janela de criança ativa atualmente e coloca a janela do filho ativa atualmente atrás de todas as outras janelas da criança.|
|[CMDIFrameWnd::MDIPrev](#mdiprev)|Ativa a janela do filho anterior e coloca a janela do filho ativa imediatamente atrás dela.|
|[CMDIFrameWnd::MDIRestore](#mdirestore)|Restaura uma janela de criança MDI de tamanho maximizado ou minimizado.|
|[CMDIFrameWnd::MDISetMenu](#mdisetmenu)|Substitui o menu de uma janela de quadro MDI, o menu pop-up janela ou ambos.|
|[CMDIFrameWnd::MDITile](#mditile)|Organiza todas as janelas de crianças em um formato de ladrilho.|

## <a name="remarks"></a>Comentários

Para criar uma janela de quadro MDI útil `CMDIFrameWnd`para sua aplicação, obtenha uma classe de . Adicione variáveis de membro à classe derivada para armazenar dados específicos do seu aplicativo. Implemente funções de membro manipulador de mensagens e um mapa de mensagem na classe derivada para especificar o que acontece quando as mensagens são direcionadas para a janela.

Você pode construir uma janela de quadro MDI chamando a função [Criar](../../mfc/reference/cframewnd-class.md#create) ou [membro loadFrame](../../mfc/reference/cframewnd-class.md#loadframe) de `CFrameWnd`.

Antes de `Create` `LoadFrame`ligar ou , você deve construir o objeto da janela do quadro no heap usando o **novo** operador C++. Antes `Create` de ligar, você também pode registrar uma classe de janela com a função global [AfxRegisterWndClass](application-information-and-management.md#afxregisterwndclass) para definir os estilos de ícone e classe para o quadro.

Use `Create` a função membro para passar os parâmetros de criação do quadro como argumentos imediatos.

`LoadFrame`requer menos argumentos do que `Create`, e, em vez disso, recupera a maioria de seus valores padrão de recursos, incluindo legenda do quadro, ícone, tabela do acelerador e menu. Para serem `LoadFrame`acessados, todos esses recursos devem ter o mesmo ID de recurso (por exemplo, IDR_MAINFRAME).

Embora `MDIFrameWnd` seja derivado `CFrameWnd`de , uma classe `CMDIFrameWnd` de janela de `DECLARE_DYNCREATE`quadro derivada de não precisa ser declarada com .

A `CMDIFrameWnd` classe herda grande parte `CFrameWnd`de sua implementação padrão de . Para obter uma lista detalhada desses recursos, consulte a descrição da classe [CFrameWnd.](../../mfc/reference/cframewnd-class.md) A `CMDIFrameWnd` classe tem os seguintes recursos adicionais:

- Uma janela de quadro MDI gerencia a janela MDICLIENT, reposicionando-a em conjunto com as barras de controle. A janela do cliente MDI é o pai direto das janelas de moldura de criança MDI. O WS_HSCROLL e WS_VSCROLL estilos `CMDIFrameWnd` de janela especificados em uma aplicação na janela do cliente MDI em vez da janela principal do quadro para que o usuário possa rolar a área do cliente MDI (como no Gerenciador de Programas do Windows, por exemplo).

- Uma janela de quadro MDI possui um menu padrão que é usado como barra de menu quando não há janela de criança MDI ativa. Quando há uma criança MDI ativa, a barra de menu da janela do quadro MDI é automaticamente substituída pelo menu da janela de criança SM.

- Uma janela de quadro MDI funciona em conjunto com a janela de criança MDI atual, se houver uma. Por exemplo, as mensagens de comando são delegadas à criança MDI ativa atualmente antes da janela de quadro MDI.

- Uma janela de quadro MDI tem manipuladores padrão para os seguintes comandos de menu padrão da janela:

  - ID_WINDOW_TILE_VERT

  - ID_WINDOW_TILE_HORZ

  - ID_WINDOW_CASCADE

  - ID_WINDOW_ARRANGE

- Uma janela de quadro MDI também possui uma implementação de ID_WINDOW_NEW, o que cria um novo quadro e exibição no documento atual. Um aplicativo pode substituir essas implementações de comando padrão para personalizar o manuseio de janelas MDI.

Não use o operador de **exclusão** C++ para destruir uma janela de quadro. Use `CWnd::DestroyWindow` em vez disso. A `CFrameWnd` implementação do `PostNcDestroy` excluirá o objeto C++ quando a janela for destruída. Quando o usuário fecha a janela `OnClose` do `DestroyWindow`quadro, o manipulador padrão chamará .

Para obter `CMDIFrameWnd`mais informações, consulte [Frame Windows](../../mfc/frame-windows.md).

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

[Cobject](../../mfc/reference/cobject-class.md)

[Ccmdtarget](../../mfc/reference/ccmdtarget-class.md)

[CWnd](../../mfc/reference/cwnd-class.md)

[CFrameWnd](../../mfc/reference/cframewnd-class.md)

`CMDIFrameWnd`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** afxwin.h

## <a name="cmdiframewndcmdiframewnd"></a><a name="cmdiframewnd"></a>CMDIFrameWnd::CMDIFrameWnd

Constrói um objeto `CMDIFrameWnd`.

```
CMDIFrameWnd();
```

### <a name="remarks"></a>Comentários

Ligue `Create` para `LoadFrame` a função ou membro para criar a janela de quadro MDI visível.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFCWindowing#13](../../mfc/reference/codesnippet/cpp/cmdiframewnd-class_1.cpp)]

## <a name="cmdiframewndcreateclient"></a><a name="createclient"></a>CMDIFrameWnd::CreateClient

Cria a janela de cliente `CMDIChildWnd` MDI que gerencia os objetos.

```
virtual BOOL CreateClient(
    LPCREATESTRUCT lpCreateStruct,
    CMenu* pWindowMenu);
```

### <a name="parameters"></a>Parâmetros

*lpCreateStruct*<br/>
Um ponteiro longo para uma estrutura [CRIATRUCT.](/windows/win32/api/winuser/ns-winuser-createstructw)

*pWindowMenu de janelas*<br/>
Um ponteiro para o menu pop-up janela.

### <a name="return-value"></a>Valor retornado

Não zero se bem sucedido; caso contrário, 0.

### <a name="remarks"></a>Comentários

Esta função de membro deve ser `OnCreate` chamada se você substituir diretamente a função do membro.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFCWindowing#14](../../mfc/reference/codesnippet/cpp/cmdiframewnd-class_2.cpp)]

## <a name="cmdiframewndcreatenewchild"></a><a name="createnewchild"></a>CMDIFrameWnd::CreateNewChild

Cria uma nova janela para crianças.

```
CMDIChildWnd* CreateNewChild(
    CRuntimeClass* pClass,
    UINT nResource,
    HMENU hMenu = NULL,
    HACCEL hAccel = NULL);
```

### <a name="parameters"></a>Parâmetros

*pClass*<br/>
A classe de tempo de execução da janela infantil a ser criada.

*nRecurso*<br/>
O ID dos recursos compartilhados associados à janela da criança.

*Hmenu*<br/>
O menu da janela infantil.

*hAccel*<br/>
O acelerador da janela da criança.

### <a name="remarks"></a>Comentários

Use esta função para criar janelas filho de uma janela de quadro MDI.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFCWindowing#15](../../mfc/reference/codesnippet/cpp/cmdiframewnd-class_3.cpp)]

## <a name="cmdiframewndgetwindowmenupopup"></a><a name="getwindowmenupopup"></a>CMDIFrameWnd::GetWindowMenuPopup

Chame esta função de membro para obter uma alça para o menu pop-up atual chamado "Janela" (o menu pop-up com itens do menu para gerenciamento de janelas MDI).

```
virtual HMENU GetWindowMenuPopup(HMENU hMenuBar);
```

### <a name="parameters"></a>Parâmetros

*hMenuBar*<br/>
A barra de menu atual.

### <a name="return-value"></a>Valor retornado

O menu pop-up janela se existir; caso contrário, NULL.

### <a name="remarks"></a>Comentários

A implementação padrão procura um menu pop-up contendo comandos padrão do menu janela, como ID_WINDOW_NEW e ID_WINDOW_TILE_HORZ.

Substituir esta função de membro se você tiver um menu Janela que não use os IDs de comando de menu padrão.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFCWindowing#16](../../mfc/reference/codesnippet/cpp/cmdiframewnd-class_4.cpp)]

## <a name="cmdiframewndmdiactivate"></a><a name="mdiactivate"></a>CMDIFrameWnd::MDIActivate

Ativa uma janela de criança MDI diferente.

```cpp
void MDIActivate(CWnd* pWndActivate);
```

### <a name="parameters"></a>Parâmetros

*pWndActivate*<br/>
Aponta para a janela de criança MDI a ser ativada.

### <a name="remarks"></a>Comentários

Esta função de membro envia a mensagem [WM_MDIACTIVATE](../../mfc/reference/cwnd-class.md#onmdiactivate) para a janela da criança sendo ativada e a janela da criança sendo desativada.

Esta é a mesma mensagem enviada se o usuário mudar o foco para uma janela de criança MDI usando o mouse ou teclado.

> [!NOTE]
> Uma janela de criança MDI é ativada independentemente da janela do quadro MDI. Quando o quadro se torna ativo, a janela filho que foi ativada pela última vez é enviada uma mensagem [WM_NCACTIVATE](../../mfc/reference/cwnd-class.md#onncactivate) para desenhar uma moldura de janela ativa e barra de legendas, mas não recebe outra mensagem WM_MDIACTIVATE.

### <a name="example"></a>Exemplo

Veja o exemplo de [CMDIFrameWnd::GetWindowMenuPopup](#getwindowmenupopup).

## <a name="cmdiframewndmdicascade"></a><a name="mdicascade"></a>CMDIFrameWnd::MDICascade

Organiza todas as janelas de crianças MDI em um formato em cascata.

```cpp
void MDICascade();
void MDICascade(int nType);
```

### <a name="parameters"></a>Parâmetros

*nType*<br/>
Especifica uma bandeira em cascata. Apenas o seguinte sinalizador pode ser especificado: MDITILE_SKIPDISABLED, que impede que janelas de crianças MDI desativadas sejam em cascata.

### <a name="remarks"></a>Comentários

A primeira `MDICascade`versão de , sem parâmetros, cascata todas as janelas infantis MDI, incluindo as desativadas. A segunda versão opcionalmente não descarta janelas de crianças MDI desativadas em cascata se você especificar MDITILE_SKIPDISABLED para o parâmetro *nType.*

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFCWindowing#17](../../mfc/reference/codesnippet/cpp/cmdiframewnd-class_5.cpp)]

## <a name="cmdiframewndmdigetactive"></a><a name="mdigetactive"></a>CMDIFrameWnd::MDIGetActive

Recupera a janela atual do filho MDI ativo, juntamente com uma bandeira indicando se a janela da criança está maximizada.

```
CMDIChildWnd* MDIGetActive(BOOL* pbMaximized = NULL) const;
```

### <a name="parameters"></a>Parâmetros

*pbMaximizado*<br/>
Um ponteiro para um valor de retorno BOOL. Definir como TRUE no retorno se a janela for maximizada; caso contrário, FALSO.

### <a name="return-value"></a>Valor retornado

Um ponteiro para a janela de criança MDI ativa.

### <a name="example"></a>Exemplo

Veja o exemplo de [CMDIChildWnd::MDIMaximize](../../mfc/reference/cmdichildwnd-class.md#mdimaximize).

## <a name="cmdiframewndmdiiconarrange"></a><a name="mdiiconarrange"></a>CMDIFrameWnd::MDIIconArrange

Organiza todas as janelas de crianças de documento minimizadas.

```cpp
void MDIIconArrange();
```

### <a name="remarks"></a>Comentários

Não afeta janelas de crianças que não são minimizadas.

### <a name="example"></a>Exemplo

Veja o exemplo de [CMDIFrameWnd::MDICascade](#mdicascade).

## <a name="cmdiframewndmdimaximize"></a><a name="mdimaximize"></a>CMDIFrameWnd::MDIMaximize

Maximiza a janela de criança MDI especificada.

```cpp
void MDIMaximize(CWnd* pWnd);
```

### <a name="parameters"></a>Parâmetros

*Pwnd*<br/>
Aponta para a janela para maximizar.

### <a name="remarks"></a>Comentários

Quando uma janela filho é maximizada, o Windows redimensiona-a para fazer com que sua área cliente preencha a janela do cliente. O Windows coloca o menu Controle da janela do filho na barra de menu do quadro para que o usuário possa restaurar ou fechar a janela do filho. Ele também adiciona o título da janela criança ao título da janela de quadros.

Se outra janela de criança MDI for ativada quando a janela de criança MDI atualmente ativa for maximizada, o Windows restaurará a criança ativa no momento e maximizará a janela do filho recém-ativa.

### <a name="example"></a>Exemplo

Veja o exemplo de [CMDIChildWnd::MDIMaximize](../../mfc/reference/cmdichildwnd-class.md#mdimaximize).

## <a name="cmdiframewndmdinext"></a><a name="mdinext"></a>CMDIFrameWnd::MDINext

Ativa a janela da criança imediatamente atrás da janela de criança ativa atualmente e coloca a janela do filho ativa atualmente atrás de todas as outras janelas da criança.

```cpp
void MDINext();
```

### <a name="remarks"></a>Comentários

Se a janela de criança MDI atualmente ativa for maximizada, a função membro restaurará a criança ativa atualmente e maximizará a criança recém-ativa.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFCWindowing#18](../../mfc/reference/codesnippet/cpp/cmdiframewnd-class_6.cpp)]

## <a name="cmdiframewndmdiprev"></a><a name="mdiprev"></a>CMDIFrameWnd::MDIPrev

Ativa a janela do filho anterior e coloca a janela do filho ativa imediatamente atrás dela.

```cpp
void MDIPrev();
```

### <a name="remarks"></a>Comentários

Se a janela de criança MDI atualmente ativa for maximizada, a função membro restaurará a criança ativa atualmente e maximizará a criança recém-ativa.

## <a name="cmdiframewndmdirestore"></a><a name="mdirestore"></a>CMDIFrameWnd::MDIRestore

Restaura uma janela de criança MDI de tamanho maximizado ou minimizado.

```cpp
void MDIRestore(CWnd* pWnd);
```

### <a name="parameters"></a>Parâmetros

*Pwnd*<br/>
Aponta para a janela para restaurar.

### <a name="example"></a>Exemplo

Veja o exemplo de [CMDIChildWnd::MDIRestore](../../mfc/reference/cmdichildwnd-class.md#mdirestore).

## <a name="cmdiframewndmdisetmenu"></a><a name="mdisetmenu"></a>CMDIFrameWnd::MDISetMenu

Substitui o menu de uma janela de quadro MDI, o menu pop-up janela ou ambos.

```
CMenu* MDISetMenu(
    CMenu* pFrameMenu,
    CMenu* pWindowMenu);
```

### <a name="parameters"></a>Parâmetros

*menu pFrame*<br/>
Especifica o menu do novo menu de janela de quadros. Se NULO, o menu não será alterado.

*pWindowMenu de janelas*<br/>
Especifica o menu do novo menu pop-up janela. Se NULO, o menu não será alterado.

### <a name="return-value"></a>Valor retornado

Um ponteiro para o menu da janela de quadros substituído por esta mensagem. O ponteiro pode ser temporário e não deve ser armazenado para uso posterior.

### <a name="remarks"></a>Comentários

Após `MDISetMenu`a chamada, um aplicativo deve chamar `CWnd` a função de membro [DrawMenuBar](../../mfc/reference/cwnd-class.md#drawmenubar) para atualizar a barra de menu.

Se essa chamada substituir o menu pop-up da janela, os itens do menu da janela de criança MDI serão removidos do menu anterior da Janela e adicionados ao novo menu pop-up da Janela.

Se uma janela de criança MDI for maximizada e essa chamada substituir o menu mdi frame-window, os controles de controle e restauração serão removidos do menu anterior da janela de quadros e adicionados ao novo menu.

Não chame essa função de membro se você usar a estrutura para gerenciar suas janelas de crianças MDI.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFCWindowing#19](../../mfc/reference/codesnippet/cpp/cmdiframewnd-class_7.cpp)]

[!code-cpp[NVC_MFCWindowing#20](../../mfc/reference/codesnippet/cpp/cmdiframewnd-class_8.cpp)]

## <a name="cmdiframewndmditile"></a><a name="mditile"></a>CMDIFrameWnd::MDITile

Organiza todas as janelas de crianças em um formato de ladrilho.

```cpp
void MDITile();
void MDITile(int nType);
```

### <a name="parameters"></a>Parâmetros

*nType*<br/>
Especifica um sinalizador de revestimento. Este parâmetro pode ser qualquer uma das seguintes bandeiras:

- MDITILE_HORIZONTAL telhas MDI janelas de crianças para que uma janela apareça acima da outra.

- MDITILE_SKIPDISABLED impede que janelas de crianças MDI desativadas sejam ladrilhos.

- MDITILE_VERTICAL telhas MDI janelas de criança para que uma janela apareça ao lado da outra.

### <a name="remarks"></a>Comentários

A primeira `MDITile`versão de , sem parâmetros, ladrilhos as janelas verticalmente sob as versões 3.1 do Windows e posteriores. A segunda versão ladra janelas vertical ou horizontalmente, dependendo do valor do parâmetro *nType.*

### <a name="example"></a>Exemplo

Veja o exemplo de [CMDIFrameWnd::MDICascade](#mdicascade).

## <a name="see-also"></a>Confira também

[MDI amostra MFC](../../overview/visual-cpp-samples.md)<br/>
[MFC Amostra MDIDOCVW](../../overview/visual-cpp-samples.md)<br/>
[Amostra de MFC SNAPVW](../../overview/visual-cpp-samples.md)<br/>
[Classe CFrameWnd](../../mfc/reference/cframewnd-class.md)<br/>
[Gráfico da hierarquia](../../mfc/hierarchy-chart.md)<br/>
[Classe CWnd](../../mfc/reference/cwnd-class.md)<br/>
[Classe CMDIChildWnd](../../mfc/reference/cmdichildwnd-class.md)
