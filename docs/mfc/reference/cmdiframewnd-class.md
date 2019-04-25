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
ms.openlocfilehash: 9f5289491a7c14749865cfd163417440bc542aba
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62164183"
---
# <a name="cmdiframewnd-class"></a>Classe CMDIFrameWnd

Fornece a funcionalidade de um Windows vários janela de quadro de MDI (interface MDI) do documento, juntamente com os membros para gerenciar a janela.

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
|[CMDIFrameWnd::CreateClient](#createclient)|Cria uma janela MDICLIENT do Windows para este `CMDIFrameWnd`. Chamado pelo `OnCreate` função de membro de `CWnd`.|
|[CMDIFrameWnd::CreateNewChild](#createnewchild)|Cria uma nova janela filho.|
|[CMDIFrameWnd::GetWindowMenuPopup](#getwindowmenupopup)|Retorna o menu pop-up da janela.|
|[CMDIFrameWnd::MDIActivate](#mdiactivate)|Ativa uma janela filho da MDI diferente.|
|[CMDIFrameWnd::MDICascade](#mdicascade)|Organiza todas as janelas filho em um formato em cascata.|
|[CMDIFrameWnd::MDIGetActive](#mdigetactive)|Recupera a janela de filho MDI ativa no momento, junto com um sinalizador que indica se o filho é maximizado.|
|[CMDIFrameWnd::MDIIconArrange](#mdiiconarrange)|Organiza todas as janelas filho de documento minimizada.|
|[CMDIFrameWnd::MDIMaximize](#mdimaximize)|Maximiza uma janela filho MDI.|
|[CMDIFrameWnd::MDINext](#mdinext)|Ativa a janela filho imediatamente por trás da janela filho ativa no momento e coloca a janela filho ativa no momento por trás de todas as outras janelas filho.|
|[CMDIFrameWnd::MDIPrev](#mdiprev)|Ativa a janela filho anterior e coloca a janela filho ativa no momento imediatamente por trás dele.|
|[CMDIFrameWnd::MDIRestore](#mdirestore)|Restaura uma janela filho MDI de tamanho minimizado ou maximizado.|
|[CMDIFrameWnd::MDISetMenu](#mdisetmenu)|Substitui o menu de uma janela de quadro MDI, no menu pop-up da janela ou ambos.|
|[CMDIFrameWnd::MDITile](#mditile)|Organiza todas as janelas filho em um formato lado a lado.|

## <a name="remarks"></a>Comentários

Para criar uma janela de quadro MDI úteis para seu aplicativo, derive uma classe de `CMDIFrameWnd`. Adicione variáveis de membro à classe derivada para armazenar dados específicos ao seu aplicativo. Implementar funções de membro de manipulador de mensagens e uma mensagem do mapa na classe derivada para especificar o que acontece quando as mensagens são direcionadas para a janela.

Você pode construir uma janela de quadro MDI chamando o [Create](../../mfc/reference/cframewnd-class.md#create) ou [LoadFrame](../../mfc/reference/cframewnd-class.md#loadframe) função de membro de `CFrameWnd`.

Antes de chamar `Create` ou `LoadFrame`, você deve construir o objeto de janela de quadro na pilha usando o C++ **novos** operador. Antes de chamar `Create` você também pode registrar uma classe de janela com o [AfxRegisterWndClass](application-information-and-management.md#afxregisterwndclass) função global para definir os estilos de ícone e a classe para o quadro.

Use o `Create` a função de membro para passar parâmetros de criação do quadro imediatos como argumentos.

`LoadFrame` requer menos argumentos que `Create`e em vez disso, recupera a maioria de seus valores padrão de recursos, incluindo a legenda do quadro, ícone, tabela de Aceleradores e menu. Para ser acessado por `LoadFrame`, todos esses recursos devem ter a mesma ID de recurso (por exemplo, IDR_MAINFRAME).

Embora `MDIFrameWnd` deriva `CFrameWnd`, derivado de uma classe de janela de quadro `CMDIFrameWnd` não precisa ser declarado com `DECLARE_DYNCREATE`.

O `CMDIFrameWnd` classe herda grande parte da sua implementação do padrão de `CFrameWnd`. Para obter uma lista detalhada desses recursos, consulte a [CFrameWnd](../../mfc/reference/cframewnd-class.md) descrição de classe. O `CMDIFrameWnd` classe tem os seguintes recursos adicionais:

- Uma janela de quadro MDI gerencia a janela MDICLIENT, reposicionamento-lo em conjunto com barras de controle. A janela do cliente MDI é o pai direto de janelas de quadro MDI filho. Os estilos de janela WS_HSCROLL e WS_VSCROLL especificados em um `CMDIFrameWnd` se aplicam a janela do cliente MDI em vez da janela de quadro principal para que o usuário pode rolar a área de cliente do MDI (como o Windows gerente de programa, por exemplo).

- Uma janela de quadro MDI possui um menu padrão que é usado como a barra de menus quando não houver nenhuma janela filho da MDI ativa. Quando há um filho MDI ativo, a barra de menus da janela de quadro MDI é substituída automaticamente pelo menu de janela filho MDI.

- Uma janela de quadro MDI funciona em conjunto com a janela filho MDI atual, se houver um. Por exemplo, mensagens de comando são delegadas para o filho MDI ativo no momento antes da janela de quadro MDI.

- Uma janela de quadro MDI tem manipuladores padrão para os seguintes comandos de menu de janela padrão:

    - ID_WINDOW_TILE_VERT

    - ID_WINDOW_TILE_HORZ

    - ID_WINDOW_CASCADE

    - ID_WINDOW_ARRANGE

- Uma janela de quadro MDI também tem uma implementação de ID_WINDOW_NEW, que cria um novo quadro e o modo de exibição no documento atual. Um aplicativo pode substituir essas implementações de comando padrão para personalizar a manipulação de janela MDI.

Não use o C++ **excluir** operador para destruir uma janela do quadro. Use `CWnd::DestroyWindow` em seu lugar. O `CFrameWnd` implementação de `PostNcDestroy` excluirá o objeto de C++, quando a janela for destruída. Quando o usuário fechar a janela do quadro, o padrão `OnClose` manipulador chamará `DestroyWindow`.

Para obter mais informações sobre `CMDIFrameWnd`, consulte [quadro Windows](../../mfc/frame-windows.md).

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

[CObject](../../mfc/reference/cobject-class.md)

[CCmdTarget](../../mfc/reference/ccmdtarget-class.md)

[CWnd](../../mfc/reference/cwnd-class.md)

[CFrameWnd](../../mfc/reference/cframewnd-class.md)

`CMDIFrameWnd`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** afxwin. h

##  <a name="cmdiframewnd"></a>  CMDIFrameWnd::CMDIFrameWnd

Constrói um objeto `CMDIFrameWnd`.

```
CMDIFrameWnd();
```

### <a name="remarks"></a>Comentários

Chame o `Create` ou `LoadFrame` a função de membro para criar a janela de quadro MDI visível.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFCWindowing#13](../../mfc/reference/codesnippet/cpp/cmdiframewnd-class_1.cpp)]

##  <a name="createclient"></a>  CMDIFrameWnd::CreateClient

Cria a janela do cliente MDI que gerencia o `CMDIChildWnd` objetos.

```
virtual BOOL CreateClient(
    LPCREATESTRUCT lpCreateStruct,
    CMenu* pWindowMenu);
```

### <a name="parameters"></a>Parâmetros

*lpCreateStruct*<br/>
Um ponteiro longo para um [CREATESTRUCT](/windows/desktop/api/winuser/ns-winuser-tagcreatestructa) estrutura.

*pWindowMenu*<br/>
Um ponteiro para o menu pop-up da janela.

### <a name="return-value"></a>Valor de retorno

Diferente de zero se bem-sucedido; Caso contrário, 0.

### <a name="remarks"></a>Comentários

Essa função membro deve ser chamada, se você substituir o `OnCreate` diretamente a função de membro.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFCWindowing#14](../../mfc/reference/codesnippet/cpp/cmdiframewnd-class_2.cpp)]

##  <a name="createnewchild"></a>  CMDIFrameWnd::CreateNewChild

Cria uma nova janela filho.

```
CMDIChildWnd* CreateNewChild(
    CRuntimeClass* pClass,
    UINT nResource,
    HMENU hMenu = NULL,
    HACCEL hAccel = NULL);
```

### <a name="parameters"></a>Parâmetros

*pClass*<br/>
A classe de tempo de execução da janela filho a ser criado.

*nResource*<br/>
A ID de recursos compartilhados associados com a janela filho.

*hMenu*<br/>
Menu da janela filho.

*hAccel*<br/>
Aceleração da janela filho.

### <a name="remarks"></a>Comentários

Use essa função crie janelas de uma janela de quadro MDI filho.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFCWindowing#15](../../mfc/reference/codesnippet/cpp/cmdiframewnd-class_3.cpp)]

##  <a name="getwindowmenupopup"></a>  CMDIFrameWnd::GetWindowMenuPopup

Chame essa função de membro para obter um identificador para o menu pop-up atual denominado "Janela" (o menu pop-up com itens de menu para o gerenciamento de janelas MDI).

```
virtual HMENU GetWindowMenuPopup(HMENU hMenuBar);
```

### <a name="parameters"></a>Parâmetros

*hMenuBar*<br/>
A barra de menu atual.

### <a name="return-value"></a>Valor de retorno

O menu pop-up da janela se uma existe; Caso contrário, nulo.

### <a name="remarks"></a>Comentários

A implementação padrão procura um menu pop-up que contém os comandos de menu de janela padrão como ID_WINDOW_NEW e ID_WINDOW_TILE_HORZ.

Substitua essa função membro, se você tiver um menu de janela que não usa o IDs de comando de menu padrão.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFCWindowing#16](../../mfc/reference/codesnippet/cpp/cmdiframewnd-class_4.cpp)]

##  <a name="mdiactivate"></a>  CMDIFrameWnd::MDIActivate

Ativa uma janela filho da MDI diferente.

```
void MDIActivate(CWnd* pWndActivate);
```

### <a name="parameters"></a>Parâmetros

*pWndActivate*<br/>
Aponta para a janela filho da MDI para ser ativado.

### <a name="remarks"></a>Comentários

Essa função de membro envia o [WM_MDIACTIVATE](../../mfc/reference/cwnd-class.md#onmdiactivate) mensagem para a janela filho que está sendo ativado e a janela filho que está sendo desativado.

Isso é a mesma mensagem que será enviada se o usuário altera o foco para uma janela filho MDI, usando o mouse ou teclado.

> [!NOTE]
>  Uma janela filho MDI é ativada independentemente da janela do quadro MDI. Quando o quadro for ativo, a janela filho que foi ativada pela última vez é enviada um [WM_NCACTIVATE](../../mfc/reference/cwnd-class.md#onncactivate) mensagem para desenhar um quadro de janela ativa e a barra de legenda, mas ele não recebe outra mensagem WM_MDIACTIVATE.

### <a name="example"></a>Exemplo

Veja o exemplo de [CMDIFrameWnd::GetWindowMenuPopup](#getwindowmenupopup).

##  <a name="mdicascade"></a>  CMDIFrameWnd::MDICascade

Organiza todas as janelas filho MDI em um formato em cascata.

```
void MDICascade();
void MDICascade(int nType);
```

### <a name="parameters"></a>Parâmetros

*nType*<br/>
Especifica um sinalizador em cascata. Pode ser especificado apenas o seguinte sinalizador: MDITILE_SKIPDISABLED, que impede que janelas filho na MDI desabilitadas sendo colocados em cascata.

### <a name="remarks"></a>Comentários

A primeira versão do `MDICascade`, sem parâmetros, propaga-se todas as janelas de filho MDI, incluindo aqueles de desabilitado. A segunda versão faz não desabilitado MDI filho em cascata, opcionalmente, se você especificar MDITILE_SKIPDISABLED para o *nType* parâmetro.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFCWindowing#17](../../mfc/reference/codesnippet/cpp/cmdiframewnd-class_5.cpp)]

##  <a name="mdigetactive"></a>  CMDIFrameWnd::MDIGetActive

Recupera a atual active janela filho MDI, juntamente com um sinalizador que indica se a janela filho é maximizada.

```
CMDIChildWnd* MDIGetActive(BOOL* pbMaximized = NULL) const;
```

### <a name="parameters"></a>Parâmetros

*pbMaximized*<br/>
Um ponteiro para um valor de retorno booleano. Defina como verdadeiro no retorno, se a janela está maximizada; Caso contrário, FALSE.

### <a name="return-value"></a>Valor de retorno

Um ponteiro para a janela filho MDI ativo.

### <a name="example"></a>Exemplo

Veja o exemplo de [CMDIChildWnd::MDIMaximize](../../mfc/reference/cmdichildwnd-class.md#mdimaximize).

##  <a name="mdiiconarrange"></a>  CMDIFrameWnd::MDIIconArrange

Organiza todas as janelas filho de documento minimizada.

```
void MDIIconArrange();
```

### <a name="remarks"></a>Comentários

Ele não afeta as janelas filho que não sejam minimizadas.

### <a name="example"></a>Exemplo

Veja o exemplo de [CMDIFrameWnd::MDICascade](#mdicascade).

##  <a name="mdimaximize"></a>  CMDIFrameWnd::MDIMaximize

Maximiza a janela filho MDI especificada.

```
void MDIMaximize(CWnd* pWnd);
```

### <a name="parameters"></a>Parâmetros

*pWnd*<br/>
Aponta para a janela a ser maximizada.

### <a name="remarks"></a>Comentários

Quando uma janela filho é maximizada, Windows redimensiona para tornar sua área de cliente a preencher a janela do cliente. Windows coloca o menu de controle da janela filho na barra de menus do quadro para que o usuário possa restaurar ou feche a janela filho. Ele também adiciona o título da janela filho para o título da janela do quadro.

Se outra janela filho da MDI é ativada quando a janela filho da MDI ativa no momento estiver maximizada, o Windows restaura o filho ativo no momento e maximiza a janela filho recém-ativado.

### <a name="example"></a>Exemplo

Veja o exemplo de [CMDIChildWnd::MDIMaximize](../../mfc/reference/cmdichildwnd-class.md#mdimaximize).

##  <a name="mdinext"></a>  CMDIFrameWnd::MDINext

Ativa a janela filho imediatamente por trás da janela filho ativa no momento e coloca a janela filho ativa no momento por trás de todas as outras janelas filho.

```
void MDINext();
```

### <a name="remarks"></a>Comentários

Se a janela filho da MDI ativa no momento estiver maximizada, a função de membro restaura o filho ativo no momento e maximiza o filho recém-ativado.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFCWindowing#18](../../mfc/reference/codesnippet/cpp/cmdiframewnd-class_6.cpp)]

##  <a name="mdiprev"></a>  CMDIFrameWnd::MDIPrev

Ativa a janela filho anterior e coloca a janela filho ativa no momento imediatamente por trás dele.

```
void MDIPrev();
```

### <a name="remarks"></a>Comentários

Se a janela filho da MDI ativa no momento estiver maximizada, a função de membro restaura o filho ativo no momento e maximiza o filho recém-ativado.

##  <a name="mdirestore"></a>  CMDIFrameWnd::MDIRestore

Restaura uma janela filho MDI de tamanho minimizado ou maximizado.

```
void MDIRestore(CWnd* pWnd);
```

### <a name="parameters"></a>Parâmetros

*pWnd*<br/>
Aponta para a janela a ser restaurada.

### <a name="example"></a>Exemplo

Veja o exemplo de [CMDIChildWnd::MDIRestore](../../mfc/reference/cmdichildwnd-class.md#mdirestore).

##  <a name="mdisetmenu"></a>  CMDIFrameWnd::MDISetMenu

Substitui o menu de uma janela de quadro MDI, no menu pop-up da janela ou ambos.

```
CMenu* MDISetMenu(
    CMenu* pFrameMenu,
    CMenu* pWindowMenu);
```

### <a name="parameters"></a>Parâmetros

*pFrameMenu*<br/>
Especifica o menu do novo menu janela do quadro. Se for NULL, o menu não é alterado.

*pWindowMenu*<br/>
Especifica o menu do novo menu pop-up da janela. Se for NULL, o menu não é alterado.

### <a name="return-value"></a>Valor de retorno

Um ponteiro para o menu de janela com moldura substituído por esta mensagem. O ponteiro pode ser temporário e não deve ser armazenado para uso posterior.

### <a name="remarks"></a>Comentários

Depois de chamar `MDISetMenu`, um aplicativo deve chamar o [DrawMenuBar](../../mfc/reference/cwnd-class.md#drawmenubar) a função de membro de `CWnd` para atualizar a barra de menus.

Se essa chamada substitui o menu pop-up da janela, itens de menu de janela filho MDI são removidos do menu janela anterior e adicionados ao novo menu pop-up da janela.

Se uma janela filho MDI é maximizada e essa chamada substitui o menu de janela de quadro MDI, os controles de menu e a restauração de controle são removidos do menu janela do quadro anterior e adicionados ao menu novo.

Não chame essa função membro se você usar a estrutura para gerenciamento de janelas filho MDI.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFCWindowing#19](../../mfc/reference/codesnippet/cpp/cmdiframewnd-class_7.cpp)]

[!code-cpp[NVC_MFCWindowing#20](../../mfc/reference/codesnippet/cpp/cmdiframewnd-class_8.cpp)]

##  <a name="mditile"></a>  CMDIFrameWnd::MDITile

Organiza todas as janelas filho em um formato lado a lado.

```
void MDITile();
void MDITile(int nType);
```

### <a name="parameters"></a>Parâmetros

*nType*<br/>
Especifica um sinalizador de lado a lado. Esse parâmetro pode ser qualquer um dos seguintes sinalizadores:

- MDITILE_HORIZONTAL blocos janelas MDI filho para que uma janela aparece acima do outro.

- Impede a MDITILE_SKIPDISABLED desabilitado janelas MDI filhas do que está sendo colocada lado a lado.

- MDITILE_VERTICAL blocos janelas MDI filho para que uma janela é exibida ao lado do outro.

### <a name="remarks"></a>Comentários

A primeira versão do `MDITile`, sem parâmetros, os blocos do windows verticalmente em Windows versões 3.1 e posteriores. A segunda versão blocos windows vertical ou horizontalmente, dependendo do valor da *nType* parâmetro.

### <a name="example"></a>Exemplo

Veja o exemplo de [CMDIFrameWnd::MDICascade](#mdicascade).

## <a name="see-also"></a>Consulte também

[Exemplo MFC MDI](../../overview/visual-cpp-samples.md)<br/>
[Exemplo MFC MDIDOCVW](../../overview/visual-cpp-samples.md)<br/>
[Exemplo MFC SNAPVW](../../overview/visual-cpp-samples.md)<br/>
[Classe CFrameWnd](../../mfc/reference/cframewnd-class.md)<br/>
[Gráfico da hierarquia](../../mfc/hierarchy-chart.md)<br/>
[Classe CWnd](../../mfc/reference/cwnd-class.md)<br/>
[Classe CMDIChildWnd](../../mfc/reference/cmdichildwnd-class.md)
