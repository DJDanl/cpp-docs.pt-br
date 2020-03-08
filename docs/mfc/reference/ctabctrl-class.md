---
title: Classe CTabCtrl
ms.date: 11/04/2016
f1_keywords:
- CTabCtrl
- AFXCMN/CTabCtrl
- AFXCMN/CTabCtrl::CTabCtrl
- AFXCMN/CTabCtrl::AdjustRect
- AFXCMN/CTabCtrl::Create
- AFXCMN/CTabCtrl::CreateEx
- AFXCMN/CTabCtrl::DeleteAllItems
- AFXCMN/CTabCtrl::DeleteItem
- AFXCMN/CTabCtrl::DeselectAll
- AFXCMN/CTabCtrl::DrawItem
- AFXCMN/CTabCtrl::GetCurFocus
- AFXCMN/CTabCtrl::GetCurSel
- AFXCMN/CTabCtrl::GetExtendedStyle
- AFXCMN/CTabCtrl::GetImageList
- AFXCMN/CTabCtrl::GetItem
- AFXCMN/CTabCtrl::GetItemCount
- AFXCMN/CTabCtrl::GetItemRect
- AFXCMN/CTabCtrl::GetItemState
- AFXCMN/CTabCtrl::GetRowCount
- AFXCMN/CTabCtrl::GetToolTips
- AFXCMN/CTabCtrl::HighlightItem
- AFXCMN/CTabCtrl::HitTest
- AFXCMN/CTabCtrl::InsertItem
- AFXCMN/CTabCtrl::RemoveImage
- AFXCMN/CTabCtrl::SetCurFocus
- AFXCMN/CTabCtrl::SetCurSel
- AFXCMN/CTabCtrl::SetExtendedStyle
- AFXCMN/CTabCtrl::SetImageList
- AFXCMN/CTabCtrl::SetItem
- AFXCMN/CTabCtrl::SetItemExtra
- AFXCMN/CTabCtrl::SetItemSize
- AFXCMN/CTabCtrl::SetItemState
- AFXCMN/CTabCtrl::SetMinTabWidth
- AFXCMN/CTabCtrl::SetPadding
- AFXCMN/CTabCtrl::SetToolTips
helpviewer_keywords:
- CTabCtrl [MFC], CTabCtrl
- CTabCtrl [MFC], AdjustRect
- CTabCtrl [MFC], Create
- CTabCtrl [MFC], CreateEx
- CTabCtrl [MFC], DeleteAllItems
- CTabCtrl [MFC], DeleteItem
- CTabCtrl [MFC], DeselectAll
- CTabCtrl [MFC], DrawItem
- CTabCtrl [MFC], GetCurFocus
- CTabCtrl [MFC], GetCurSel
- CTabCtrl [MFC], GetExtendedStyle
- CTabCtrl [MFC], GetImageList
- CTabCtrl [MFC], GetItem
- CTabCtrl [MFC], GetItemCount
- CTabCtrl [MFC], GetItemRect
- CTabCtrl [MFC], GetItemState
- CTabCtrl [MFC], GetRowCount
- CTabCtrl [MFC], GetToolTips
- CTabCtrl [MFC], HighlightItem
- CTabCtrl [MFC], HitTest
- CTabCtrl [MFC], InsertItem
- CTabCtrl [MFC], RemoveImage
- CTabCtrl [MFC], SetCurFocus
- CTabCtrl [MFC], SetCurSel
- CTabCtrl [MFC], SetExtendedStyle
- CTabCtrl [MFC], SetImageList
- CTabCtrl [MFC], SetItem
- CTabCtrl [MFC], SetItemExtra
- CTabCtrl [MFC], SetItemSize
- CTabCtrl [MFC], SetItemState
- CTabCtrl [MFC], SetMinTabWidth
- CTabCtrl [MFC], SetPadding
- CTabCtrl [MFC], SetToolTips
ms.assetid: 42e4aff6-46ae-4b2c-beaa-d1dce8d82138
ms.openlocfilehash: a0ca4cbad48c420250fe39e131de5504b1ae70f3
ms.sourcegitcommit: 3e8fa01f323bc5043a48a0c18b855d38af3648d4
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/06/2020
ms.locfileid: "78875864"
---
# <a name="ctabctrl-class"></a>Classe CTabCtrl

Fornece a funcionalidade do controle de guia comum do Windows.

## <a name="syntax"></a>Sintaxe

```
class CTabCtrl : public CWnd
```

## <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores públicos

|{1&gt;Nome&lt;1}|Descrição|
|----------|-----------------|
|[CTabCtrl::CTabCtrl](#ctabctrl)|Constrói um objeto `CTabCtrl`.|

### <a name="public-methods"></a>Métodos públicos

|{1&gt;Nome&lt;1}|Descrição|
|----------|-----------------|
|[CTabCtrl::AdjustRect](#adjustrect)|Calcula a área de exibição de um controle guia, dado um retângulo de janela, ou calcula o retângulo da janela que corresponderia a uma determinada área de exibição.|
|[CTabCtrl:: criar](#create)|Cria um controle guia e o anexa a uma instância de um objeto `CTabCtrl`.|
|[CTabCtrl::CreateEx](#createex)|Cria um controle guia com os estilos estendidos do Windows especificados e o anexa a uma instância de um objeto `CTabCtrl`.|
|[CTabCtrl::D eleteAllItems](#deleteallitems)|Remove todos os itens de um controle guia.|
|[CTabCtrl::D eleteItem](#deleteitem)|Remove um item de um controle guia.|
|[CTabCtrl::D eselectAll](#deselectall)|Redefine os itens em um controle guia, limpando os que foram pressionados.|
|[CTabCtrl::D rawItem](#drawitem)|Desenha um item especificado de um controle guia.|
|[CTabCtrl::GetCurFocus](#getcurfocus)|Recupera a guia com o foco atual de um controle guia.|
|[CTabCtrl:: GetCurSel](#getcursel)|Determina a guia selecionada no momento em um controle guia.|
|[CTabCtrl:: Extended](#getextendedstyle)|Recupera os estilos estendidos que estão em uso no momento para o controle de guia.|
|[CTabCtrl:: GetImageList](#getimagelist)|Recupera a lista de imagens associada a um controle guia.|
|[CTabCtrl:: GetItem](#getitem)|Recupera informações sobre uma guia em um controle guia.|
|[CTabCtrl:: GetItemCount](#getitemcount)|Recupera o número de guias no controle guia.|
|[CTabCtrl::GetItemRect](#getitemrect)|Recupera o retângulo delimitador para uma guia em um controle guia.|
|[CTabCtrl:: GetItemState](#getitemstate)|Recupera o estado do item de controle de guia indicado.|
|[CTabCtrl:: GetRowCount](#getrowcount)|Recupera o número atual de linhas de guias em um controle guia.|
|[CTabCtrl:: GetToolTips](#gettooltips)|Recupera o identificador do controle de dica de ferramenta associado a um controle guia.|
|[CTabCtrl::HighlightItem](#highlightitem)|Define o estado de realce de um item de guia.|
|[CTabCtrl:: HitTest](#hittest)|Determina qual guia, se houver, está em uma posição de tela especificada.|
|[CTabCtrl:: InsertItem](#insertitem)|Insere uma nova guia em um controle guia.|
|[CTabCtrl::RemoveImage](#removeimage)|Remove uma imagem da lista de imagens de um controle guia.|
|[CTabCtrl::SetCurFocus](#setcurfocus)|Define o foco para uma guia especificada em um controle guia.|
|[CTabCtrl:: setcurseal](#setcursel)|Seleciona uma guia em um controle guia.|
|[CTabCtrl:: Extended](#setextendedstyle)|Define os estilos estendidos para um controle guia.|
|[CTabCtrl:: SetImageList](#setimagelist)|Atribui uma lista de imagens a um controle guia.|
|[CTabCtrl::SetItem](#setitem)|Define alguns ou todos os atributos de uma guia.|
|[CTabCtrl::SetItemExtra](#setitemextra)|Define o número de bytes por tabulação reservados para dados definidos pelo aplicativo em um controle guia.|
|[CTabCtrl:: setitems](#setitemsize)|Define a largura e a altura de um item.|
|[CTabCtrl:: SetItemState](#setitemstate)|Define o estado do item de controle de guia indicado.|
|[CTabCtrl::SetMinTabWidth](#setmintabwidth)|Define a largura mínima dos itens em um controle guia.|
|[CTabCtrl:: setpadding](#setpadding)|Define a quantidade de espaço (preenchimento) em volta do ícone e do rótulo de cada guia em um controle guia.|
|[CTabCtrl:: SetToolTips](#settooltips)|Atribui um controle de dica de ferramenta a um controle guia.|

## <a name="remarks"></a>Comentários

Um "controle de guia" é análogo aos divisores em um bloco de anotações ou aos rótulos em um arquivo de gabinete. Usando um controle guia, um aplicativo pode definir várias páginas para a mesma área de uma janela ou caixa de diálogo. Cada página consiste em um conjunto de informações ou um grupo de controles que o aplicativo exibe quando o usuário seleciona a guia correspondente. Um tipo especial de controle guia exibe guias que se parecem com botões. Clicar em um botão deve executar imediatamente um comando em vez de exibir uma página.

Esse controle (e, portanto, a classe `CTabCtrl`) está disponível somente para programas em execução no Windows 95/98 e no Windows NT versão 3,51 e posterior.

Para obter mais informações sobre como usar `CTabCtrl`, consulte [controles](../../mfc/controls-mfc.md) e [usando CTabCtrl](../../mfc/using-ctabctrl.md).

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

[CObject](../../mfc/reference/cobject-class.md)

[CCmdTarget](../../mfc/reference/ccmdtarget-class.md)

[CWnd](../../mfc/reference/cwnd-class.md)

`CTabCtrl`

## <a name="requirements"></a>{1&gt;{2&gt;Requisitos&lt;2}&lt;1}

**Cabeçalho:** afxcmn. h

##  <a name="adjustrect"></a>CTabCtrl::AdjustRect

Calcula a área de exibição de um controle guia, dado um retângulo de janela, ou calcula o retângulo da janela que corresponderia a uma determinada área de exibição.

```
void AdjustRect(BOOL bLarger,   LPRECT lpRect);
```

### <a name="parameters"></a>Parâmetros

*bLarger*<br/>
Indica qual operação deve ser executada. Se esse parâmetro for TRUE, *lpRect* especificará um retângulo de exibição e receberá o retângulo de janela correspondente. Se esse parâmetro for FALSE, *lpRect* especificará um retângulo de janela e receberá o retângulo de exibição correspondente.

*lpRect*<br/>
Ponteiro para uma estrutura [Rect](/previous-versions/dd162897\(v=vs.85\)) que especifica o retângulo fornecido e recebe o retângulo calculado.

### <a name="example"></a>{1&gt;Exemplo&lt;1}

[!code-cpp[NVC_MFC_CTabCtrl#1](../../mfc/reference/codesnippet/cpp/ctabctrl-class_1.cpp)]

##  <a name="create"></a>CTabCtrl:: criar

Cria um controle guia e o anexa a uma instância de um objeto `CTabCtrl`.

```
virtual BOOL Create(
    DWORD dwStyle,
    const RECT& rect,
    CWnd* pParentWnd,
    UINT nID);
```

### <a name="parameters"></a>Parâmetros

*dwStyle*<br/>
Especifica o estilo do controle da guia. Aplique qualquer combinação de [estilos de controle de guia](/windows/win32/Controls/tab-control-styles), descrita na SDK do Windows. Consulte **comentários** para obter uma lista de estilos de janela que você também pode aplicar ao controle.

*Rect*<br/>
Especifica o tamanho e a posição do controle de guia. Pode ser um objeto [CRect](../../atl-mfc-shared/reference/crect-class.md) ou uma estrutura [Rect](/previous-versions/dd162897\(v=vs.85\)) .

*pParentWnd*<br/>
Especifica a janela pai do controle de guia, geralmente um `CDialog`. Ele não deve ser nulo.

*nID*<br/>
Especifica a ID do controle da guia.

### <a name="return-value"></a>Valor retornado

TRUE se a inicialização do objeto foi bem-sucedida; caso contrário, FALSE.

### <a name="remarks"></a>Comentários

Você constrói um objeto `CTabCtrl` em duas etapas. Primeiro, chame o construtor e, em seguida, chame `Create`, que cria o controle guia e o anexa ao objeto `CTabCtrl`.

Além dos estilos de controle de guia, você pode aplicar os seguintes estilos de janela a um controle guia:

- WS_CHILD cria uma janela filho que representa o controle guia. Não pode ser usado com o estilo de WS_POPUP.

- WS_VISIBLE cria um controle guia inicialmente visível.

- WS_DISABLED Cria uma janela que está inicialmente desabilitada.

- WS_GROUP especifica o primeiro controle de um grupo de controles no qual o usuário pode passar de um controle para o próximo com as teclas de direção. Todos os controles definidos com o estilo de WS_GROUP após o primeiro controle pertencem ao mesmo grupo. O próximo controle com o estilo WS_GROUP encerra o grupo de estilos e inicia o próximo grupo (ou seja, um grupo termina onde o próximo começa).

- WS_TABSTOP especifica um dos vários controles pelos quais o usuário pode se mover usando a tecla TAB. A tecla TAB move o usuário para o próximo controle especificado pelo estilo de WS_TABSTOP.

Para criar um controle guia com estilos de janela estendidos, chame [CTabCtrl:: CreateEx](#createex) em vez de `Create`.

### <a name="example"></a>{1&gt;Exemplo&lt;1}

[!code-cpp[NVC_MFC_CTabCtrl#2](../../mfc/reference/codesnippet/cpp/ctabctrl-class_2.cpp)]

##  <a name="createex"></a>CTabCtrl::CreateEx

Cria um controle (uma janela filho) e o associa ao objeto `CTabCtrl`.

```
virtual BOOL CreateEx(
    DWORD dwExStyle,
    DWORD dwStyle,
    const RECT& rect,
    CWnd* pParentWnd,
    UINT nID);
```

### <a name="parameters"></a>Parâmetros

*dwExStyle*<br/>
Especifica o estilo estendido do controle que está sendo criado. Para obter uma lista de estilos estendidos do Windows, consulte o parâmetro *dwExStyle* para [CreateWindowEx](/windows/win32/api/winuser/nf-winuser-createwindowexw) no SDK do Windows.

*dwStyle*<br/>
Especifica o estilo do controle da guia. Aplique qualquer combinação de [estilos de controle de guia](/windows/win32/Controls/tab-control-styles), descrita na SDK do Windows. Consulte **comentários** em [criar](#create) para obter uma lista de estilos de janela que você também pode aplicar ao controle.

*Rect*<br/>
Uma referência a uma estrutura [Rect](/previous-versions/dd162897\(v=vs.85\)) que descreve o tamanho e a posição da janela a ser criada, nas coordenadas de cliente de *pParentWnd*.

*pParentWnd*<br/>
Um ponteiro para a janela que é o pai do controle.

*nID*<br/>
A ID da janela filho do controle.

### <a name="return-value"></a>Valor retornado

Diferente de zero, se for bem-sucedido 0.

### <a name="remarks"></a>Comentários

Use `CreateEx` em vez de [Create](#create) para aplicar estilos estendidos do Windows, especificados pelo **WS_EX_** de prefácio de estilo estendido do Windows.

`CreateEx` cria o controle com os estilos estendidos do Windows especificados por *dwExStyle*. Defina estilos estendidos específicos para um controle usando [Extended](#setextendedstyle). Por exemplo, use `CreateEx` para definir esses estilos como WS_EX_CONTEXTHELP, mas use `SetExtendedStyle` para definir esses estilos como TCS_EX_FLATSEPARATORS. Para obter mais informações, consulte os estilos descritos em [controle de guia estilos estendidos](/windows/win32/Controls/tab-control-extended-styles) na SDK do Windows.

##  <a name="ctabctrl"></a>CTabCtrl::CTabCtrl

Constrói um objeto `CTabCtrl`.

```
CTabCtrl();
```

##  <a name="deleteallitems"></a>CTabCtrl::D eleteAllItems

Remove todos os itens de um controle guia.

```
BOOL DeleteAllItems();
```

### <a name="return-value"></a>Valor retornado

Diferente de zero, se for bem-sucedido; caso contrário, 0.

##  <a name="deleteitem"></a>CTabCtrl::D eleteItem

Remove o item especificado de um controle guia.

```
BOOL DeleteItem(int nItem);
```

### <a name="parameters"></a>Parâmetros

*nItem*<br/>
Valor de base zero do item a ser excluído.

### <a name="return-value"></a>Valor retornado

Diferente de zero, se for bem-sucedido; caso contrário, 0.

### <a name="example"></a>{1&gt;Exemplo&lt;1}

[!code-cpp[NVC_MFC_CTabCtrl#3](../../mfc/reference/codesnippet/cpp/ctabctrl-class_3.cpp)]

##  <a name="deselectall"></a>CTabCtrl::D eselectAll

Redefine os itens em um controle guia, limpando os que foram pressionados.

```
void DeselectAll(BOOL fExcludeFocus);
```

### <a name="parameters"></a>Parâmetros

*fExcludeFocus*<br/>
Sinalizador que especifica o escopo da desmarcação do item. Se esse parâmetro for definido como FALSE, todos os botões da guia serão redefinidos. Se estiver definido como TRUE, todos os itens da guia, exceto o selecionado no momento, serão redefinidos.

### <a name="remarks"></a>Comentários

Essa função de membro implementa o comportamento da mensagem Win32, [TCM_DESELECTALL](/windows/win32/Controls/tcm-deselectall), conforme descrito no SDK do Windows.

##  <a name="drawitem"></a>CTabCtrl::D rawItem

Chamado pelo Framework quando um aspecto visual de um controle de guia de desenho proprietário é alterado.

```
virtual void DrawItem(LPDRAWITEMSTRUCT lpDrawItemStruct);
```

### <a name="parameters"></a>Parâmetros

*lpDrawItemStruct*<br/>
Um ponteiro para uma estrutura [DRAWITEMSTRUCT](/windows/win32/api/winuser/ns-winuser-drawitemstruct) que descreve o item a ser pintado.

### <a name="remarks"></a>Comentários

O membro `itemAction` da estrutura de `DRAWITEMSTRUCT` define a ação de desenho a ser executada.

Por padrão, essa função de membro não faz nada. Substitua essa função de membro para implementar o desenho de um objeto de `CTabCtrl` de desenho proprietário.

O aplicativo deve restaurar todos os objetos da interface de dispositivo de gráficos (GDI) selecionados para o contexto de exibição fornecido em *lpDrawItemStruct* antes que essa função de membro seja encerrada.

##  <a name="getcurfocus"></a>CTabCtrl::GetCurFocus

Recupera o índice da guia com o foco atual.

```
int GetCurFocus() const;
```

### <a name="return-value"></a>Valor retornado

O índice de base zero da guia com o foco atual.

##  <a name="getcursel"></a>CTabCtrl:: GetCurSel

Recupera a guia selecionada no momento em um controle guia.

```
int GetCurSel() const;
```

### <a name="return-value"></a>Valor retornado

Índice de base zero da guia selecionada se for bem-sucedido ou-1 se nenhuma guia for selecionada.

##  <a name="getextendedstyle"></a>CTabCtrl:: Extended

Recupera os estilos estendidos que estão em uso no momento para o controle de guia.

```
DWORD GetExtendedStyle();
```

### <a name="return-value"></a>Valor retornado

Representa os estilos estendidos em uso no momento para o controle de guia. Esse valor é uma combinação de [estilos estendidos de controle de guia](/windows/win32/Controls/tab-control-extended-styles), conforme descrito na SDK do Windows.

### <a name="remarks"></a>Comentários

Essa função de membro implementa o comportamento do [TCM_GETEXTENDEDSTYLE](/windows/win32/Controls/tcm-getextendedstyle)de mensagens Win32, conforme descrito no SDK do Windows.

##  <a name="getimagelist"></a>CTabCtrl:: GetImageList

Recupera a lista de imagens que está associada a um controle guia.

```
CImageList* GetImageList() const;
```

### <a name="return-value"></a>Valor retornado

Se for bem-sucedido, um ponteiro para a lista de imagens do controle guia; caso contrário, NULL.

##  <a name="getitem"></a>CTabCtrl:: GetItem

Recupera informações sobre uma guia em um controle guia.

```
BOOL GetItem(int nItem,   TCITEM* pTabCtrlItem) const;
```

### <a name="parameters"></a>Parâmetros

*nItem*<br/>
Índice de base zero da guia.

*pTabCtrlItem*<br/>
Ponteiro para uma estrutura [TCITEM](/windows/win32/api/commctrl/ns-commctrl-tcitemw) , usado para especificar as informações a serem recuperadas. Também usado para receber informações sobre a guia. Essa estrutura é usada com as funções de membro `InsertItem`, `GetItem`e `SetItem`.

### <a name="return-value"></a>Valor retornado

Retornará TRUE se for bem-sucedido; Caso contrário, FALSE.

### <a name="remarks"></a>Comentários

Quando a mensagem é enviada, o membro `mask` especifica quais atributos serão retornados. Se o membro de `mask` especifica o valor de TCIF_TEXT, o membro `pszText` deve conter o endereço do buffer que recebe o texto do item e o membro `cchTextMax` deve especificar o tamanho do buffer.

- `mask`

   Valor que especifica quais membros da estrutura de `TCITEM` recuperar ou definir. Esse membro pode ser zero ou uma combinação dos seguintes valores:

   - TCIF_TEXT o membro de `pszText` é válido.

   - TCIF_IMAGE o membro de `iImage` é válido.

   - TCIF_PARAM o membro de `lParam` é válido.

   - TCIF_RTLREADING o texto de `pszText` é exibido usando a ordem de leitura da direita para a esquerda em sistemas hebraico ou árabe.

   - TCIF_STATE o membro de `dwState` é válido.

- `pszText`

   Ponteiro para uma cadeia de caracteres terminada em nulo que contém o texto da guia se a estrutura contiver informações sobre uma guia. Se a estrutura estiver recebendo informações, esse membro especificará o endereço do buffer que receberá o texto da guia.

- `cchTextMax`

   Tamanho do buffer apontado por `pszText`. Esse membro será ignorado se a estrutura não estiver recebendo informações.

- `iImage` índice na lista de imagens do controle guia, ou-1 se não houver nenhuma imagem para a guia.

- `lParam`

   Dados definidos pelo aplicativo associados à guia. Se houver mais de quatro bytes de dados definidos pelo aplicativo por guia, um aplicativo deverá definir uma estrutura e usá-lo em vez da estrutura de `TCITEM`. O primeiro membro da estrutura definida pelo aplicativo deve ser uma estrutura [TCITEMHEADER](/windows/win32/api/commctrl/ns-commctrl-tcitemheaderw). A estrutura de `TCITEMHEADER` é idêntica à estrutura de `TCITEM`, mas sem o membro `lParam`. A diferença entre o tamanho da sua estrutura e o tamanho da estrutura de `TCITEMHEADER` deve ser igual ao número de bytes extras por guia.

### <a name="example"></a>{1&gt;Exemplo&lt;1}

[!code-cpp[NVC_MFC_CTabCtrl#4](../../mfc/reference/codesnippet/cpp/ctabctrl-class_4.cpp)]

##  <a name="getitemcount"></a>CTabCtrl:: GetItemCount

Recupera o número de guias no controle guia.

```
int GetItemCount() const;
```

### <a name="return-value"></a>Valor retornado

Número de itens no controle de guia.

### <a name="example"></a>{1&gt;Exemplo&lt;1}

  Consulte o exemplo para [CPropertySheet:: GetTabControl](../../mfc/reference/cpropertysheet-class.md#gettabcontrol).

##  <a name="getitemrect"></a>CTabCtrl::GetItemRect

Recupera o retângulo delimitador para a guia especificada em um controle guia.

```
BOOL GetItemRect(int nItem,   LPRECT lpRect) const;
```

### <a name="parameters"></a>Parâmetros

*nItem*<br/>
Índice de base zero do item de guia.

*lpRect*<br/>
Ponteiro para uma estrutura [Rect](/previous-versions/dd162897\(v=vs.85\)) que recebe o retângulo delimitador da guia. Essas coordenadas usam o modo de mapeamento atual do visor.

### <a name="return-value"></a>Valor retornado

Diferente de zero, se for bem-sucedido; caso contrário, 0.

### <a name="example"></a>{1&gt;Exemplo&lt;1}

  Consulte o exemplo para [CPropertySheet:: GetTabControl](../../mfc/reference/cpropertysheet-class.md#gettabcontrol).

##  <a name="getitemstate"></a>CTabCtrl:: GetItemState

Recupera o estado do item de controle de guia identificado por *nItem*.

```
DWORD GetItemState(
    int nItem,
    DWORD dwMask) const;
```

### <a name="parameters"></a>Parâmetros

*nItem*<br/>
O número de índice com base em zero do item para o qual recuperar informações de estado.

*dwMask*<br/>
Máscara que especifica qual dos sinalizadores de estado do item deve ser retornado. Para obter uma lista de valores, consulte o membro mask da estrutura [TCITEM](/windows/win32/api/commctrl/ns-commctrl-tcitemw) , conforme descrito na SDK do Windows.

### <a name="return-value"></a>Valor retornado

Uma referência a um valor DWORD que recebe as informações de estado. Pode ser um dos seguintes valores:

|{1&gt;Valor&lt;1}|Descrição|
|-----------|-----------------|
|TCIS_BUTTONPRESSED|O item de controle guia é selecionado.|
|TCIS_HIGHLIGHTED|O item de controle guia é realçado e a guia e o texto são desenhados usando a cor de realce atual. Ao usar a cor de realce, essa será uma interpolação real, não uma cor de dificada.|

### <a name="remarks"></a>Comentários

O estado de um item é especificado pelo membro de `dwState` da estrutura de `TCITEM`.

##  <a name="getrowcount"></a>CTabCtrl:: GetRowCount

Recupera o número atual de linhas em um controle guia.

```
int GetRowCount() const;
```

### <a name="return-value"></a>Valor retornado

O número de linhas de guias no controle de guia.

### <a name="remarks"></a>Comentários

Somente controles de guia que têm o estilo de TCS_MULTILINE podem ter várias linhas de guias.

##  <a name="gettooltips"></a>CTabCtrl:: GetToolTips

Recupera o identificador do controle de dica de ferramenta associado a um controle guia.

```
CToolTipCtrl* GetToolTips() const;
```

### <a name="return-value"></a>Valor retornado

Identificador do controle de dica de ferramenta se bem-sucedido; caso contrário, NULL.

### <a name="remarks"></a>Comentários

Um controle guia cria um controle de dica de ferramenta se ele tem o estilo de TCS_TOOLTIPS. Você também pode atribuir um controle de dica de ferramenta a um controle guia usando a função membro `SetToolTips`.

##  <a name="highlightitem"></a>CTabCtrl::HighlightItem

Define o estado de realce de um item de guia.

```
BOOL HighlightItem(int idItem,   BOOL fHighlight = TRUE);
```

### <a name="parameters"></a>Parâmetros

*idItem*<br/>
Índice de base zero de um item de controle de guia.

*fHighlight*<br/>
Valor que especifica o estado de realce a ser definido. Se esse valor for TRUE, a guia será realçada; Se for FALSE, a guia será definida como seu estado padrão.

### <a name="return-value"></a>Valor retornado

Diferente de zero, se for bem-sucedido; caso contrário, zero.

### <a name="remarks"></a>Comentários

Essa função de membro implementa a mensagem Win32 [TCM_HIGHLIGHTITEM](/windows/win32/Controls/tcm-highlightitem), conforme descrito no SDK do Windows.

##  <a name="hittest"></a>CTabCtrl:: HitTest

Determina qual guia, se houver, está na posição de tela especificada.

```
int HitTest(TCHITTESTINFO* pHitTestInfo) const;
```

### <a name="parameters"></a>Parâmetros

*pHitTestInfo*<br/>
Ponteiro para uma estrutura [TCHITTESTINFO](/windows/win32/api/commctrl/ns-commctrl-tchittestinfo) , conforme descrito na SDK do Windows, que especifica a posição da tela a ser testada.

### <a name="return-value"></a>Valor retornado

Retorna o índice de base zero da guia ou-1 se nenhuma guia estiver na posição especificada.

##  <a name="insertitem"></a>CTabCtrl:: InsertItem

Insere uma nova guia em um controle de guia existente.

```
LONG InsertItem(
    int nItem,
    TCITEM* pTabCtrlItem);

LONG InsertItem(
    int nItem,
    LPCTSTR lpszItem);

LONG InsertItem(
    int nItem,
    LPCTSTR lpszItem,
    int nImage);

LONG InsertItem(
    UINT nMask,
    int nItem,
    LPCTSTR lpszItem,
    int nImage,
    LPARAM lParam);

LONG InsertItem(
    UINT nMask,
    int nItem,
    LPCTSTR lpszItem,
    int nImage,
    LPARAM lParam,
    DWORD dwState,
    DWORD dwStateMask);
```

### <a name="parameters"></a>Parâmetros

*nItem*<br/>
Índice de base zero da nova guia.

*pTabCtrlItem*<br/>
Ponteiro para uma estrutura [TCITEM](/windows/win32/api/commctrl/ns-commctrl-tcitemw) que especifica os atributos da guia.

*lpszItem*<br/>
Endereço de uma cadeia de caracteres terminada em nulo que contém o texto da guia.

*Nimagem*<br/>
O índice de base zero de uma imagem a ser inserida a partir de uma lista de imagens.

*nMask*<br/>
Especifica quais atributos de estrutura de `TCITEM` definir. Pode ser zero ou uma combinação dos seguintes valores:

- TCIF_TEXT o membro de `pszText` é válido.

- TCIF_IMAGE o membro de `iImage` é válido.

- TCIF_PARAM o membro *lParam* é válido.

- TCIF_RTLREADING o texto de `pszText` é exibido usando a ordem de leitura da direita para a esquerda em sistemas hebraico ou árabe.

- TCIF_STATE o membro *dwState* é válido.

*lParam*<br/>
Dados definidos pelo aplicativo associados à guia.

*dwState*<br/>
Especifica valores para os Estados do item. Para obter mais informações, consulte [TCITEM](/windows/win32/api/commctrl/ns-commctrl-tcitemw) no SDK do Windows.

*dwStateMask*<br/>
Especifica quais Estados devem ser definidos. Para obter mais informações, consulte [TCITEM](/windows/win32/api/commctrl/ns-commctrl-tcitemw) no SDK do Windows.

### <a name="return-value"></a>Valor retornado

Índice de base zero da nova guia se for bem-sucedido; caso contrário,-1.

### <a name="example"></a>{1&gt;Exemplo&lt;1}

[!code-cpp[NVC_MFC_CTabCtrl#5](../../mfc/reference/codesnippet/cpp/ctabctrl-class_5.cpp)]

##  <a name="removeimage"></a>CTabCtrl::RemoveImage

Remove a imagem especificada da lista de imagens de um controle guia.

```
void RemoveImage(int nImage);
```

### <a name="parameters"></a>Parâmetros

*Nimagem*<br/>
Índice de base zero da imagem a ser removida.

### <a name="remarks"></a>Comentários

O controle guia atualiza o índice de imagem de cada guia para que cada guia permaneça associada à mesma imagem.

##  <a name="setcurfocus"></a>CTabCtrl::SetCurFocus

Define o foco para uma guia especificada em um controle guia.

```
void SetCurFocus(int nItem);
```

### <a name="parameters"></a>Parâmetros

*nItem*<br/>
Especifica o índice da guia que obtém o foco.

### <a name="remarks"></a>Comentários

Essa função de membro implementa o comportamento do [TCM_SETCURFOCUS](/windows/win32/Controls/tcm-setcurfocus)de mensagens Win32, conforme descrito no SDK do Windows.

##  <a name="setcursel"></a>CTabCtrl:: setcurseal

Seleciona uma guia em um controle guia.

```
int SetCurSel(int nItem);
```

### <a name="parameters"></a>Parâmetros

*nItem*<br/>
O índice de base zero do item a ser selecionado.

### <a name="return-value"></a>Valor retornado

Índice de base zero da guia selecionada anteriormente se for bem-sucedido, caso contrário,-1.

### <a name="remarks"></a>Comentários

Um controle guia não envia uma mensagem de notificação TCN_SELCHANGING ou TCN_SELCHANGE quando uma guia é selecionada usando essa função. Essas notificações são enviadas, usando WM_NOTIFY, quando o usuário clica ou usa o teclado para alterar as guias.

##  <a name="setextendedstyle"></a>CTabCtrl:: Extended

Define os estilos estendidos para um controle guia.

```
DWORD SetExtendedStyle(DWORD dwNewStyle,   DWORD dwExMask = 0);
```

### <a name="parameters"></a>Parâmetros

*dwNewStyle*<br/>
Valor que especifica uma combinação de estilos estendidos de controle de guia.

*dwExMask*<br/>
Um valor DWORD que indica quais estilos em *dwNewStyle* devem ser afetados. Somente os estilos estendidos em *dwExMask* serão alterados. Todos os outros estilos serão mantidos como estão. Se esse parâmetro for zero, todos os estilos em *dwNewStyle* serão afetados.

### <a name="return-value"></a>Valor retornado

Um valor DWORD que contém os [estilos estendidos do controle de guia](/windows/win32/Controls/tab-control-extended-styles)anterior, conforme descrito na SDK do Windows.

### <a name="return-value"></a>Valor retornado

Essa função de membro implementa o comportamento do [TCM_SETEXTENDEDSTYLE](/windows/win32/Controls/tcm-setextendedstyle)de mensagens Win32, conforme descrito no SDK do Windows.

##  <a name="setimagelist"></a>CTabCtrl:: SetImageList

Atribui uma lista de imagens a um controle guia.

```
CImageList* SetImageList(CImageList* pImageList);
```

### <a name="parameters"></a>Parâmetros

*pImageList*<br/>
Ponteiro para a lista de imagens a ser atribuída ao controle de guia.

### <a name="return-value"></a>Valor retornado

Retorna um ponteiro para a lista de imagens anterior ou NULL se não houver nenhuma lista de imagens anterior.

##  <a name="setitem"></a>CTabCtrl::SetItem

Define alguns ou todos os atributos de uma guia.

```
BOOL SetItem(int nItem,   TCITEM* pTabCtrlItem);
```

### <a name="parameters"></a>Parâmetros

*nItem*<br/>
Índice de base zero do item.

*pTabCtrlItem*<br/>
Ponteiro para uma estrutura [TCITEM](/windows/win32/api/commctrl/ns-commctrl-tcitemw) que contém os novos atributos de item. O membro `mask` especifica quais atributos definir. Se o membro de `mask` especifica o valor de TCIF_TEXT, o membro de `pszText` é o endereço de uma cadeia de caracteres terminada em nulo e o membro de `cchTextMax` é ignorado.

### <a name="return-value"></a>Valor retornado

Diferente de zero, se for bem-sucedido; caso contrário, 0.

### <a name="example"></a>{1&gt;Exemplo&lt;1}

  Consulte o exemplo de [GetItem](#getitem).

##  <a name="setitemextra"></a>CTabCtrl::SetItemExtra

Define o número de bytes por tabulação reservados para dados definidos pelo aplicativo em um controle guia.

```
BOOL SetItemExtra(int nBytes);
```

### <a name="parameters"></a>Parâmetros

*nBytes*<br/>
O número de bytes extras a serem definidos.

### <a name="return-value"></a>Valor retornado

Diferente de zero, se for bem-sucedido; caso contrário, zero.

### <a name="remarks"></a>Comentários

Essa função de membro implementa o comportamento do [TCM_SETITEMEXTRA](/windows/win32/Controls/tcm-setitemextra)de mensagens Win32, conforme descrito no SDK do Windows.

##  <a name="setitemsize"></a>CTabCtrl:: setitems

Define a largura e a altura dos itens de controle da guia.

```
CSize SetItemSize(CSize size);
```

### <a name="parameters"></a>Parâmetros

*size*<br/>
A nova largura e altura, em pixels, dos itens de controle de guia.

### <a name="return-value"></a>Valor retornado

Retorna a largura e a altura antigas dos itens de controle da guia.

##  <a name="setitemstate"></a>CTabCtrl:: SetItemState

Define o estado do item de controle de guia identificado por *nItem*.

```
BOOL SetItemState(
    int nItem,
    DWORD dwMask,
    DWORD dwState);
```

### <a name="parameters"></a>Parâmetros

*nItem*<br/>
O número de índice com base em zero do item para o qual definir informações de estado.

*dwMask*<br/>
Máscara que especifica quais dos sinalizadores de estado do item definir. Para obter uma lista de valores, consulte o membro mask da estrutura [TCITEM](/windows/win32/api/commctrl/ns-commctrl-tcitemw) , conforme descrito na SDK do Windows.

*dwState*<br/>
Uma referência a um valor DWORD que contém as informações de estado. Pode ser um dos seguintes valores:

|{1&gt;Valor&lt;1}|Descrição|
|-----------|-----------------|
|TCIS_BUTTONPRESSED|O item de controle guia é selecionado.|
|TCIS_HIGHLIGHTED|O item de controle guia é realçado e a guia e o texto são desenhados usando a cor de realce atual. Ao usar a cor de realce, essa será uma interpolação real, não uma cor de dificada.|

### <a name="return-value"></a>Valor retornado

Diferente de zero, se for bem-sucedido; caso contrário, 0.

##  <a name="setmintabwidth"></a>CTabCtrl::SetMinTabWidth

Define a largura mínima dos itens em um controle guia.

```
int SetMinTabWidth(int cx);
```

### <a name="parameters"></a>Parâmetros

*CX*<br/>
Largura mínima a ser definida para um item de controle de guia. Se esse parâmetro for definido como-1, o controle usará a largura de guia padrão.

### <a name="return-value"></a>Valor retornado

A largura de tabulação mínima anterior.

### <a name="return-value"></a>Valor retornado

Essa função de membro implementa o comportamento do [TCM_SETMINTABWIDTH](/windows/win32/Controls/tcm-setmintabwidth)de mensagens Win32, conforme descrito no SDK do Windows.

##  <a name="setpadding"></a>CTabCtrl:: setpadding

Define a quantidade de espaço (preenchimento) em volta do ícone e do rótulo de cada guia em um controle guia.

```
void SetPadding(CSize size);
```

### <a name="parameters"></a>Parâmetros

*size*<br/>
Define a quantidade de espaço (preenchimento) em volta do ícone e do rótulo de cada guia em um controle guia.

##  <a name="settooltips"></a>CTabCtrl:: SetToolTips

Atribui um controle de dica de ferramenta a um controle guia.

```
void SetToolTips(CToolTipCtrl* pWndTip);
```

### <a name="parameters"></a>Parâmetros

*pWndTip*<br/>
Identificador do controle de dica de ferramenta.

### <a name="remarks"></a>Comentários

Você pode obter o controle de dica de ferramenta associado a um controle guia fazendo uma chamada para `GetToolTips`.

### <a name="example"></a>{1&gt;Exemplo&lt;1}

  Consulte o exemplo para [CPropertySheet:: GetTabControl](../../mfc/reference/cpropertysheet-class.md#gettabcontrol).

## <a name="see-also"></a>Consulte também

[Classe CWnd](../../mfc/reference/cwnd-class.md)<br/>
[Gráfico da hierarquia](../../mfc/hierarchy-chart.md)<br/>
[Classe CHeaderCtrl](../../mfc/reference/cheaderctrl-class.md)<br/>
[Classe CListCtrl](../../mfc/reference/clistctrl-class.md)
