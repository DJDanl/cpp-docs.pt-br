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
ms.openlocfilehash: 321ad0364257d7c20d54f9fdc884073381117c6f
ms.sourcegitcommit: 1f009ab0f2cc4a177f2d1353d5a38f164612bdb1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/27/2020
ms.locfileid: "87222947"
---
# <a name="cmdiframewnd-class"></a>Classe CMDIFrameWnd

Fornece a funcionalidade de uma janela de quadro MDI (interface de vários documentos do Windows), juntamente com membros para gerenciar a janela.

## <a name="syntax"></a>Sintaxe

```
class CMDIFrameWnd : public CFrameWnd
```

## <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores públicos

|Nome|Descrição|
|----------|-----------------|
|[CMDIFrameWnd:: CMDIFrameWnd](#cmdiframewnd)|Constrói um `CMDIFrameWnd`.|

### <a name="public-methods"></a>Métodos públicos

|Nome|Descrição|
|----------|-----------------|
|[CMDIFrameWnd:: CreateClient](#createclient)|Cria uma janela do Windows MDICLIENT para isso `CMDIFrameWnd` . Chamado pela `OnCreate` função membro do `CWnd` .|
|[CMDIFrameWnd:: CreateNewChild](#createnewchild)|Cria uma nova janela filho.|
|[CMDIFrameWnd:: GetWindowMenuPopup](#getwindowmenupopup)|Retorna o menu pop-up da janela.|
|[CMDIFrameWnd:: MDIActivate](#mdiactivate)|Ativa uma janela filho MDI diferente.|
|[CMDIFrameWnd:: MDICascade](#mdicascade)|Organiza todas as janelas filhas em um formato em cascata.|
|[CMDIFrameWnd:: MDIGetActive](#mdigetactive)|Recupera a janela filho MDI ativa no momento, juntamente com um sinalizador que indica se o filho está ou não maximizado.|
|[CMDIFrameWnd:: MDIIconArrange](#mdiiconarrange)|Organiza todas as janelas filhas do documento minimizadas.|
|[CMDIFrameWnd:: MDIMaximize](#mdimaximize)|Maximiza uma janela filho MDI.|
|[CMDIFrameWnd:: MDINext](#mdinext)|Ativa a janela filho imediatamente atrás da janela filho ativa no momento e coloca a janela filho ativa no momento por trás de todas as outras janelas filhas.|
|[CMDIFrameWnd:: MDIPrev](#mdiprev)|Ativa a janela filho anterior e coloca a janela filho ativa no momento imediatamente atrás dela.|
|[CMDIFrameWnd:: MDIRestore](#mdirestore)|Restaura uma janela filho MDI do tamanho maximizado ou minimizado.|
|[CMDIFrameWnd:: MDISetMenu](#mdisetmenu)|Substitui o menu de uma janela de quadro MDI, o menu pop-up da janela ou ambos.|
|[CMDIFrameWnd:: MDITile](#mditile)|Organiza todas as janelas filhas em um formato de lado.|

## <a name="remarks"></a>Comentários

Para criar uma janela de quadro MDI útil para seu aplicativo, derive uma classe de `CMDIFrameWnd` . Adicione variáveis de membro à classe derivada para armazenar dados específicos ao seu aplicativo. Implemente funções de membro do manipulador de mensagens e um mapa de mensagens na classe derivada para especificar o que acontece quando as mensagens são direcionadas para a janela.

Você pode construir uma janela de quadro MDI chamando a função de membro [Create](../../mfc/reference/cframewnd-class.md#create) ou [LoadFrame](../../mfc/reference/cframewnd-class.md#loadframe) de `CFrameWnd` .

Antes de chamar `Create` ou `LoadFrame` , você deve construir o objeto de janela do quadro no heap usando o **`new`** operador C++. Antes de chamar `Create` , você também pode registrar uma classe de janela com a função global [AfxRegisterWndClass](application-information-and-management.md#afxregisterwndclass) para definir os estilos de ícone e classe para o quadro.

Use a `Create` função membro para passar os parâmetros de criação do quadro como argumentos imediatos.

`LoadFrame`requer menos argumentos que `Create` e, em vez disso, recupera a maioria de seus valores padrão de recursos, incluindo a legenda, o ícone, a tabela de acelerador e o menu do quadro. Para ser acessado pelo `LoadFrame` , todos esses recursos devem ter a mesma ID de recurso (por exemplo, IDR_MAINFRAME).

Embora `MDIFrameWnd` seja derivado de `CFrameWnd` , uma classe de janela de quadro derivada de `CMDIFrameWnd` não precisa ser declarada com `DECLARE_DYNCREATE` .

A `CMDIFrameWnd` classe herda grande parte de sua implementação padrão do `CFrameWnd` . Para obter uma lista detalhada desses recursos, consulte a descrição da classe [CFrameWnd](../../mfc/reference/cframewnd-class.md) . A `CMDIFrameWnd` classe tem os seguintes recursos adicionais:

- Uma janela de quadro MDI gerencia a janela MDICLIENT, reposicionando-a em conjunto com barras de controle. A janela do cliente MDI é o pai direto de janelas de quadros filho MDI. Os estilos de janela WS_HSCROLL e WS_VSCROLL especificados em um `CMDIFrameWnd` aplicar à janela do cliente MDI em vez da janela do quadro principal para que o usuário possa rolar a área do cliente MDI (como no Gerenciador de programas do Windows, por exemplo).

- Uma janela de quadro MDI possui um menu padrão que é usado como a barra de menus quando não há nenhuma janela filho MDI ativa. Quando há um filho MDI ativo, a barra de menus da janela de quadro MDI é substituída automaticamente pelo menu da janela filho MDI.

- Uma janela de quadro MDI funciona em conjunto com a janela filho MDI atual, se houver uma. Por exemplo, as mensagens de comando são delegadas para o filho MDI ativo no momento antes da janela do quadro MDI.

- Uma janela de quadro MDI tem manipuladores padrão para os seguintes comandos de menu de janela padrão:

  - ID_WINDOW_TILE_VERT

  - ID_WINDOW_TILE_HORZ

  - ID_WINDOW_CASCADE

  - ID_WINDOW_ARRANGE

- Uma janela de quadro MDI também tem uma implementação de ID_WINDOW_NEW, que cria um novo quadro e uma exibição no documento atual. Um aplicativo pode substituir essas implementações de comando padrão para personalizar a manipulação de janelas MDI.

Não use o operador C++ **`delete`** para destruir uma janela de quadro. Use `CWnd::DestroyWindow` em vez disso. A `CFrameWnd` implementação do `PostNcDestroy` irá excluir o objeto C++ quando a janela for destruída. Quando o usuário fechar a janela do quadro, o `OnClose` manipulador padrão chamará `DestroyWindow` .

Para obter mais informações sobre o `CMDIFrameWnd` , consulte [janelas de quadros](../../mfc/frame-windows.md).

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

[CObject](../../mfc/reference/cobject-class.md)

[CCmdTarget](../../mfc/reference/ccmdtarget-class.md)

[CWnd](../../mfc/reference/cwnd-class.md)

[CFrameWnd](../../mfc/reference/cframewnd-class.md)

`CMDIFrameWnd`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** Afxwin. h

## <a name="cmdiframewndcmdiframewnd"></a><a name="cmdiframewnd"></a>CMDIFrameWnd:: CMDIFrameWnd

Constrói um objeto `CMDIFrameWnd`.

```
CMDIFrameWnd();
```

### <a name="remarks"></a>Comentários

Chame a `Create` `LoadFrame` função de membro ou para criar a janela de quadro MDI visível.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFCWindowing#13](../../mfc/reference/codesnippet/cpp/cmdiframewnd-class_1.cpp)]

## <a name="cmdiframewndcreateclient"></a><a name="createclient"></a>CMDIFrameWnd:: CreateClient

Cria a janela do cliente MDI que gerencia os `CMDIChildWnd` objetos.

```
virtual BOOL CreateClient(
    LPCREATESTRUCT lpCreateStruct,
    CMenu* pWindowMenu);
```

### <a name="parameters"></a>parâmetros

*lpCreateStruct*<br/>
Um ponteiro longo para uma estrutura [CREATESTRUCT](/windows/win32/api/winuser/ns-winuser-createstructw) .

*pWindowMenu*<br/>
Um ponteiro para o menu pop-up da janela.

### <a name="return-value"></a>Valor retornado

Diferente de zero, se for bem-sucedido; caso contrário, 0.

### <a name="remarks"></a>Comentários

Essa função de membro deve ser chamada se você substituir a `OnCreate` função de membro diretamente.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFCWindowing#14](../../mfc/reference/codesnippet/cpp/cmdiframewnd-class_2.cpp)]

## <a name="cmdiframewndcreatenewchild"></a><a name="createnewchild"></a>CMDIFrameWnd:: CreateNewChild

Cria uma nova janela filho.

```
CMDIChildWnd* CreateNewChild(
    CRuntimeClass* pClass,
    UINT nResource,
    HMENU hMenu = NULL,
    HACCEL hAccel = NULL);
```

### <a name="parameters"></a>parâmetros

*pClass*<br/>
A classe de tempo de execução da janela filho a ser criada.

*nResource*<br/>
A ID dos recursos compartilhados associados à janela filho.

*hMenu*<br/>
Menu da janela filho.

*hAccel*<br/>
O acelerador da janela filho.

### <a name="remarks"></a>Comentários

Use essa função para criar janelas filhas de uma janela de quadro MDI.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFCWindowing#15](../../mfc/reference/codesnippet/cpp/cmdiframewnd-class_3.cpp)]

## <a name="cmdiframewndgetwindowmenupopup"></a><a name="getwindowmenupopup"></a>CMDIFrameWnd:: GetWindowMenuPopup

Chame essa função de membro para obter um identificador para o menu pop-up atual chamado "Window" (o menu pop-up com itens de menu para o gerenciamento de janelas MDI).

```
virtual HMENU GetWindowMenuPopup(HMENU hMenuBar);
```

### <a name="parameters"></a>parâmetros

*hMenuBar*<br/>
A barra de menus atual.

### <a name="return-value"></a>Valor retornado

O menu pop-up da janela, se houver; caso contrário, NULL.

### <a name="remarks"></a>Comentários

A implementação padrão procura um menu pop-up que contém comandos de menu de janela padrão, como ID_WINDOW_NEW e ID_WINDOW_TILE_HORZ.

Substitua essa função de membro se você tiver um menu de janela que não use as IDs de comando de menu padrão.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFCWindowing#16](../../mfc/reference/codesnippet/cpp/cmdiframewnd-class_4.cpp)]

## <a name="cmdiframewndmdiactivate"></a><a name="mdiactivate"></a>CMDIFrameWnd:: MDIActivate

Ativa uma janela filho MDI diferente.

```cpp
void MDIActivate(CWnd* pWndActivate);
```

### <a name="parameters"></a>parâmetros

*pWndActivate*<br/>
Aponta para a janela filho MDI a ser ativada.

### <a name="remarks"></a>Comentários

Essa função de membro envia a mensagem de [WM_MDIACTIVATE](../../mfc/reference/cwnd-class.md#onmdiactivate) para a janela filho que está sendo ativada e a janela filho sendo desativada.

Essa é a mesma mensagem que será enviada se o usuário alterar o foco para uma janela filho MDI usando o mouse ou o teclado.

> [!NOTE]
> Uma janela filho MDI é ativada independentemente da janela do quadro MDI. Quando o quadro se torna ativo, a janela filho que foi ativada pela última vez é enviada uma mensagem de [WM_NCACTIVATE](../../mfc/reference/cwnd-class.md#onncactivate) para desenhar um quadro de janela e uma barra de legenda ativas, mas não recebe outra mensagem de WM_MDIACTIVATE.

### <a name="example"></a>Exemplo

Consulte o exemplo de [CMDIFrameWnd:: GetWindowMenuPopup](#getwindowmenupopup).

## <a name="cmdiframewndmdicascade"></a><a name="mdicascade"></a>CMDIFrameWnd:: MDICascade

Organiza todas as janelas filhas MDI em um formato em cascata.

```cpp
void MDICascade();
void MDICascade(int nType);
```

### <a name="parameters"></a>parâmetros

*nType*<br/>
Especifica um sinalizador em cascata. Somente o sinalizador a seguir pode ser especificado: MDITILE_SKIPDISABLED, que impede que janelas filho MDI desabilitadas sejam colocadas em cascata.

### <a name="remarks"></a>Comentários

A primeira versão do `MDICascade` , sem parâmetros, propaga todas as janelas filho MDI, incluindo aquelas desabilitadas. A segunda versão, opcionalmente, não desabilita as janelas filho MDI desativadas se você especificar MDITILE_SKIPDISABLED para o parâmetro *ndeclarações* .

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFCWindowing#17](../../mfc/reference/codesnippet/cpp/cmdiframewnd-class_5.cpp)]

## <a name="cmdiframewndmdigetactive"></a><a name="mdigetactive"></a>CMDIFrameWnd:: MDIGetActive

Recupera a janela filho MDI ativo atual, junto com um sinalizador que indica se a janela filho está maximizada.

```
CMDIChildWnd* MDIGetActive(BOOL* pbMaximized = NULL) const;
```

### <a name="parameters"></a>parâmetros

*pbMaximized*<br/>
Um ponteiro para um valor de retorno BOOL. Definir como TRUE no retorno se a janela for maximizada; caso contrário, FALSE.

### <a name="return-value"></a>Valor retornado

Um ponteiro para a janela filho MDI ativa.

### <a name="example"></a>Exemplo

Consulte o exemplo de [CMDIChildWnd:: MDIMaximize](../../mfc/reference/cmdichildwnd-class.md#mdimaximize).

## <a name="cmdiframewndmdiiconarrange"></a><a name="mdiiconarrange"></a>CMDIFrameWnd:: MDIIconArrange

Organiza todas as janelas filhas do documento minimizadas.

```cpp
void MDIIconArrange();
```

### <a name="remarks"></a>Comentários

Ele não afeta as janelas filhas que não são minimizadas.

### <a name="example"></a>Exemplo

Consulte o exemplo de [CMDIFrameWnd:: MDICascade](#mdicascade).

## <a name="cmdiframewndmdimaximize"></a><a name="mdimaximize"></a>CMDIFrameWnd:: MDIMaximize

Maximiza a janela filho MDI especificada.

```cpp
void MDIMaximize(CWnd* pWnd);
```

### <a name="parameters"></a>parâmetros

*pWnd*<br/>
Aponta para a janela a ser maximizada.

### <a name="remarks"></a>Comentários

Quando uma janela filho é maximizada, o Windows a redimensiona para que sua área cliente preencha a janela do cliente. O Windows coloca o menu de controle da janela filho na barra de menus do quadro para que o usuário possa restaurar ou fechar a janela filho. Ele também adiciona o título da janela filho ao título da janela do quadro.

Se outra janela filho MDI for ativada quando a janela filho MDI ativa no momento for maximizada, o Windows restaurará o filho ativo no momento e maximizará a janela filho ativada recentemente.

### <a name="example"></a>Exemplo

Consulte o exemplo de [CMDIChildWnd:: MDIMaximize](../../mfc/reference/cmdichildwnd-class.md#mdimaximize).

## <a name="cmdiframewndmdinext"></a><a name="mdinext"></a>CMDIFrameWnd:: MDINext

Ativa a janela filho imediatamente atrás da janela filho ativa no momento e coloca a janela filho ativa no momento por trás de todas as outras janelas filhas.

```cpp
void MDINext();
```

### <a name="remarks"></a>Comentários

Se a janela filho MDI ativa no momento for maximizada, a função de membro restaurará o filho ativo no momento e maximizará o filho que acabou de ser ativado.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFCWindowing#18](../../mfc/reference/codesnippet/cpp/cmdiframewnd-class_6.cpp)]

## <a name="cmdiframewndmdiprev"></a><a name="mdiprev"></a>CMDIFrameWnd:: MDIPrev

Ativa a janela filho anterior e coloca a janela filho ativa no momento imediatamente atrás dela.

```cpp
void MDIPrev();
```

### <a name="remarks"></a>Comentários

Se a janela filho MDI ativa no momento for maximizada, a função de membro restaurará o filho ativo no momento e maximizará o filho que acabou de ser ativado.

## <a name="cmdiframewndmdirestore"></a><a name="mdirestore"></a>CMDIFrameWnd:: MDIRestore

Restaura uma janela filho MDI do tamanho maximizado ou minimizado.

```cpp
void MDIRestore(CWnd* pWnd);
```

### <a name="parameters"></a>parâmetros

*pWnd*<br/>
Aponta para a janela a ser restaurada.

### <a name="example"></a>Exemplo

Consulte o exemplo de [CMDIChildWnd:: MDIRestore](../../mfc/reference/cmdichildwnd-class.md#mdirestore).

## <a name="cmdiframewndmdisetmenu"></a><a name="mdisetmenu"></a>CMDIFrameWnd:: MDISetMenu

Substitui o menu de uma janela de quadro MDI, o menu pop-up da janela ou ambos.

```
CMenu* MDISetMenu(
    CMenu* pFrameMenu,
    CMenu* pWindowMenu);
```

### <a name="parameters"></a>parâmetros

*pFrameMenu*<br/>
Especifica o menu do novo menu de janela de quadro. Se for NULL, o menu não será alterado.

*pWindowMenu*<br/>
Especifica o menu do menu pop-up de nova janela. Se for NULL, o menu não será alterado.

### <a name="return-value"></a>Valor retornado

Um ponteiro para o menu de janela de quadro substituído por esta mensagem. O ponteiro pode ser temporário e não deve ser armazenado para uso posterior.

### <a name="remarks"></a>Comentários

Depois de chamar `MDISetMenu` , um aplicativo deve chamar a função membro [DrawMenuBar](../../mfc/reference/cwnd-class.md#drawmenubar) do `CWnd` para atualizar a barra de menus.

Se essa chamada substituir o menu pop-up da janela, os itens do menu de janela filho MDI serão removidos do menu da janela anterior e adicionados ao menu pop-up da nova janela.

Se uma janela filho MDI for maximizada e essa chamada substituir o menu de janela do quadro MDI, o menu de controle e os controles de restauração serão removidos do menu da janela do quadro anterior e adicionados ao novo menu.

Não chame essa função de membro se você usar a estrutura para gerenciar suas janelas filhas MDI.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFCWindowing#19](../../mfc/reference/codesnippet/cpp/cmdiframewnd-class_7.cpp)]

[!code-cpp[NVC_MFCWindowing#20](../../mfc/reference/codesnippet/cpp/cmdiframewnd-class_8.cpp)]

## <a name="cmdiframewndmditile"></a><a name="mditile"></a>CMDIFrameWnd:: MDITile

Organiza todas as janelas filhas em um formato de lado.

```cpp
void MDITile();
void MDITile(int nType);
```

### <a name="parameters"></a>parâmetros

*nType*<br/>
Especifica um sinalizador de divisão. Esse parâmetro pode ser qualquer um dos seguintes sinalizadores:

- MDITILE_HORIZONTAL organiza as janelas filho MDI para que uma janela seja exibida acima de outra.

- MDITILE_SKIPDISABLED Impede que janelas filho MDI desativadas sejam colocadas lado a lado.

- MDITILE_VERTICAL organiza as janelas filho MDI para que uma janela seja exibida ao lado de outra.

### <a name="remarks"></a>Comentários

A primeira versão do `MDITile` , sem parâmetros, organiza as janelas verticalmente nas versões 3,1 e posteriores do Windows. A segunda versão organiza as janelas vertical ou horizontalmente, dependendo do valor do parâmetro *ndeclarações* .

### <a name="example"></a>Exemplo

Consulte o exemplo de [CMDIFrameWnd:: MDICascade](#mdicascade).

## <a name="see-also"></a>Confira também

[MDI de exemplo do MFC](../../overview/visual-cpp-samples.md)<br/>
[Exemplo de MDIDOCVW do MFC](../../overview/visual-cpp-samples.md)<br/>
[Exemplo de SNAPVW do MFC](../../overview/visual-cpp-samples.md)<br/>
[Classe CFrameWnd](../../mfc/reference/cframewnd-class.md)<br/>
[Gráfico de hierarquia](../../mfc/hierarchy-chart.md)<br/>
[Classe CWnd](../../mfc/reference/cwnd-class.md)<br/>
[Classe CMDIChildWnd](../../mfc/reference/cmdichildwnd-class.md)
