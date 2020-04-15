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
ms.openlocfilehash: 7d4a478b560be686e4da6f6dea623d6058626562
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81365962"
---
# <a name="ctabctrl-class"></a>Classe CTabCtrl

Fornece a funcionalidade do controle de guia comum do Windows.

## <a name="syntax"></a>Sintaxe

```
class CTabCtrl : public CWnd
```

## <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores públicos

|Nome|Descrição|
|----------|-----------------|
|[CTabCtrl::CTabCtrl](#ctabctrl)|Constrói um objeto `CTabCtrl`.|

### <a name="public-methods"></a>Métodos públicos

|Nome|Descrição|
|----------|-----------------|
|[CTabCtrl::AdjustRect](#adjustrect)|Calcula a área de exibição de um controle de guia dado um retângulo de janela ou calcula o retângulo da janela que corresponderia a uma determinada área de exibição.|
|[CTabCtrl::Criar](#create)|Cria um controle de guia e o `CTabCtrl` anexa a uma instância de um objeto.|
|[CTabCtrl::CreateEx](#createex)|Cria um controle de guia com os estilos estendidos do `CTabCtrl` Windows especificados e o anexa a uma instância de um objeto.|
|[CTabCtrl::DeleteAllItems](#deleteallitems)|Remove todos os itens de um controle de guia.|
|[CTabCtrl::Deleteitem](#deleteitem)|Remove um item de um controle de guia.|
|[CTabCtrl::DeselectAll](#deselectall)|Redefine itens em um controle de guia, limpando todos os que foram pressionados.|
|[CTabCtrl::DrawItem](#drawitem)|Desenha um item especificado de um controle de guia.|
|[CTabCtrl::GetCurFocus](#getcurfocus)|Recupera a guia com o foco atual de um controle de guia.|
|[CTabCtrl::GetCurSel](#getcursel)|Determina a guia selecionada no momento em um controle de guia.|
|[CTabCtrl::GetExtendedStyle](#getextendedstyle)|Recupera os estilos estendidos que estão atualmente em uso para o controle de guias.|
|[CTabCtrl::GetImageList](#getimagelist)|Recupera a lista de imagens associada a um controle de guia.|
|[CTabCtrl::GetItem](#getitem)|Recupera informações sobre uma guia em um controle de guia.|
|[CTabCtrl::GetItemCount](#getitemcount)|Recupera o número de guias no controle da guia.|
|[CTabCtrl::GetItemRect](#getitemrect)|Recupera o retângulo delimitador para uma guia em um controle de guia.|
|[CTabCtrl::GetItemState](#getitemstate)|Recupera o estado do item de controle de guia indicado.|
|[CTabCtrl::GetRowCount](#getrowcount)|Recupera o número atual de linhas de guias em um controle de guias.|
|[CTabCtrl::GetToolTips](#gettooltips)|Recupera a alça do controle de ponta da ferramenta associada a um controle de guia.|
|[CTabCtrl::HighlightItem](#highlightitem)|Define o estado de destaque de um item de guia.|
|[CTabCtrl::HitTest](#hittest)|Determina qual guia, se houver, está em uma posição de tela especificada.|
|[CTabCtrl::InsertItem](#insertitem)|Insere uma nova guia em um controle de guia.|
|[CTabCtrl::RemoveImage](#removeimage)|Remove uma imagem da lista de imagens de um controle de guia.|
|[CTabCtrl::SetCurFocus](#setcurfocus)|Define o foco para uma guia especificada em um controle de guia.|
|[CTabCtrl::SetCurSel](#setcursel)|Seleciona uma guia em um controle de guia.|
|[CTabCtrl::SetExtendedStyle](#setextendedstyle)|Define os estilos estendidos para um controle de guia.|
|[CTabCtrl::SetImageList](#setimagelist)|Atribui uma lista de imagens a um controle de guia.|
|[CTabCtrl::SetItem](#setitem)|Define alguns ou todos os atributos de uma guia.|
|[CTabCtrl::SetItemExtra](#setitemextra)|Define o número de bytes por guia reservado para dados definidos pelo aplicativo em um controle de guia.|
|[CTabCtrl::SetItemSize](#setitemsize)|Define a largura e a altura de um item.|
|[CTabCtrl::SetItemState](#setitemstate)|Define o estado do item de controle de guia indicado.|
|[CTabCtrl::SetMin''''''''''''''''''''''''''''](#setmintabwidth)|Define a largura mínima dos itens em um controle de guia.|
|[CTabCtrl::SetPadding](#setpadding)|Define a quantidade de espaço (preenchimento) em torno do ícone e do rótulo de cada guia em um controle de guia.|
|[CTabCtrl::SetToolTips](#settooltips)|Atribui um controle de ponta de ferramenta a um controle de guia.|

## <a name="remarks"></a>Comentários

Um "controle de guia" é análogo aos divisores em um notebook ou as etiquetas em um gabinete de arquivos. Usando um controle de guia, um aplicativo pode definir várias páginas para a mesma área de uma janela ou caixa de diálogo. Cada página consiste em um conjunto de informações ou um grupo de controles que o aplicativo exibe quando o usuário seleciona a guia correspondente. Um tipo especial de controle de guiaexibe guias que se parecem com botões. Clicar em um botão deve executar imediatamente um comando em vez de exibir uma página.

Este controle (e, `CTabCtrl` portanto, a classe) está disponível apenas para programas em execução sob windows 95/98 e Windows NT versão 3.51 e posterior.

Para obter mais `CTabCtrl`informações sobre como usar, consulte [Controles](../../mfc/controls-mfc.md) e [O uso de CTabCtrl](../../mfc/using-ctabctrl.md).

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

[Cobject](../../mfc/reference/cobject-class.md)

[Ccmdtarget](../../mfc/reference/ccmdtarget-class.md)

[CWnd](../../mfc/reference/cwnd-class.md)

`CTabCtrl`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** afxcmn.h

## <a name="ctabctrladjustrect"></a><a name="adjustrect"></a>CTabCtrl::AdjustRect

Calcula a área de exibição de um controle de guia dado um retângulo de janela ou calcula o retângulo da janela que corresponderia a uma determinada área de exibição.

```
void AdjustRect(BOOL bLarger,   LPRECT lpRect);
```

### <a name="parameters"></a>Parâmetros

*Blarger*<br/>
Indica qual operação executar. Se este parâmetro for TRUE, *lpRect* especifica um retângulo de exibição e recebe o retângulo da janela correspondente. Se este parâmetro for FALSO, *o lpRect* especifica um retângulo de janela e recebe o retângulo de exibição correspondente.

*Lprect*<br/>
Pointer para uma estrutura [RECT](/previous-versions/dd162897\(v=vs.85\)) que especifica o retângulo dado e recebe o retângulo calculado.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFC_CTabCtrl#1](../../mfc/reference/codesnippet/cpp/ctabctrl-class_1.cpp)]

## <a name="ctabctrlcreate"></a><a name="create"></a>CTabCtrl::Criar

Cria um controle de guia e o `CTabCtrl` anexa a uma instância de um objeto.

```
virtual BOOL Create(
    DWORD dwStyle,
    const RECT& rect,
    CWnd* pParentWnd,
    UINT nID);
```

### <a name="parameters"></a>Parâmetros

*Dwstyle*<br/>
Especifica o estilo do controle de guias. Aplique qualquer combinação de estilos de controle de [guia,](/windows/win32/Controls/tab-control-styles)descrito no SDK do Windows. Consulte **Observações** para obter uma lista de estilos de janela que você também pode aplicar ao controle.

*Rect*<br/>
Especifica o tamanho e a posição do controle da guia. Pode ser um objeto [CRect](../../atl-mfc-shared/reference/crect-class.md) ou uma estrutura [RECT.](/previous-versions/dd162897\(v=vs.85\))

*Pparentwnd*<br/>
Especifica a janela pai do controle `CDialog`de guia, geralmente um . Não deve ser NULO.

*nID*<br/>
Especifica o ID do controle da guia.

### <a name="return-value"></a>Valor retornado

VERDADE se a inicialização do objeto foi bem sucedida; caso contrário, FALSO.

### <a name="remarks"></a>Comentários

Você constrói `CTabCtrl` um objeto em dois passos. Primeiro, ligue para o construtor `Create`e, em seguida, ligue, `CTabCtrl` que cria o controle da guia e o anexa ao objeto.

Além dos estilos de controle de guia, você pode aplicar os seguintes estilos de janela a um controle de guia:

- WS_CHILD Cria uma janela filho que representa o controle da guia. Não pode ser usado com o estilo WS_POPUP.

- WS_VISIBLE Cria um controle de guia que é inicialmente visível.

- WS_DISABLED Cria uma janela inicialmente desativada.

- WS_GROUP Especifica o primeiro controle de um grupo de controles no qual o usuário pode mover de um controle para o outro com as teclas de seta. Todos os controles definidos com o estilo WS_GROUP após o primeiro controle pertencem ao mesmo grupo. O próximo controle com o estilo WS_GROUP termina o grupo de estilo e inicia o próximo grupo (ou seja, um grupo termina onde o próximo começa).

- WS_TABSTOP Especifica um dos vários controles através dos quais o usuário pode se mover usando a tecla TAB. A tecla TAB move o usuário para o próximo controle especificado pelo estilo WS_TABSTOP.

Para criar um controle de guia com estilos de janela estendidos, chame [CTabCtrl::CreateEx](#createex) em vez de `Create`.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFC_CTabCtrl#2](../../mfc/reference/codesnippet/cpp/ctabctrl-class_2.cpp)]

## <a name="ctabctrlcreateex"></a><a name="createex"></a>CTabCtrl::CreateEx

Cria um controle (uma janela filho) `CTabCtrl` e o associa ao objeto.

```
virtual BOOL CreateEx(
    DWORD dwExStyle,
    DWORD dwStyle,
    const RECT& rect,
    CWnd* pParentWnd,
    UINT nID);
```

### <a name="parameters"></a>Parâmetros

*Dwexstyle*<br/>
Especifica o estilo estendido do controle que está sendo criado. Para obter uma lista de estilos estendidos do Windows, consulte o parâmetro *dwExStyle* para [CreateWindowEx](/windows/win32/api/winuser/nf-winuser-createwindowexw) no SDK do Windows.

*Dwstyle*<br/>
Especifica o estilo do controle de guias. Aplique qualquer combinação de estilos de controle de [guia,](/windows/win32/Controls/tab-control-styles)descrito no SDK do Windows. Consulte **Observações** em [Criar](#create) para obter uma lista de estilos de janela que você também pode aplicar ao controle.

*Rect*<br/>
Uma referência a uma estrutura [RECT](/previous-versions/dd162897\(v=vs.85\)) descrevendo o tamanho e a posição da janela a ser criada, em coordenadas de cliente de *pParentWnd*.

*Pparentwnd*<br/>
Um ponteiro para a janela que é o pai do controle.

*nID*<br/>
A id da janela infantil do controle.

### <a name="return-value"></a>Valor retornado

Não zero se bem sucedido caso contrário 0.

### <a name="remarks"></a>Comentários

Use `CreateEx` em vez de [Criar](#create) para aplicar estilos estendidos do Windows, especificados pelo prefácio de estilo estendido do Windows **WS_EX_**.

`CreateEx`cria o controle com os estilos estendidos do Windows especificados pelo *dwExStyle*. Defina estilos estendidos específicos para um controle usando [SetExtendedStyle](#setextendedstyle). Por exemplo, `CreateEx` use para definir estilos `SetExtendedStyle` como WS_EX_CONTEXTHELP, mas use para definir estilos como TCS_EX_FLATSEPARATORS. Para obter mais informações, consulte os estilos descritos no [Guia Controle de Estilos Estendidos](/windows/win32/Controls/tab-control-extended-styles) no SDK do Windows.

## <a name="ctabctrlctabctrl"></a><a name="ctabctrl"></a>CTabCtrl::CTabCtrl

Constrói um objeto `CTabCtrl`.

```
CTabCtrl();
```

## <a name="ctabctrldeleteallitems"></a><a name="deleteallitems"></a>CTabCtrl::DeleteAllItems

Remove todos os itens de um controle de guia.

```
BOOL DeleteAllItems();
```

### <a name="return-value"></a>Valor retornado

Não zero se bem sucedido; caso contrário, 0.

## <a name="ctabctrldeleteitem"></a><a name="deleteitem"></a>CTabCtrl::Deleteitem

Remove o item especificado de um controle de guia.

```
BOOL DeleteItem(int nItem);
```

### <a name="parameters"></a>Parâmetros

*Nitem*<br/>
Valor baseado em zero do item a ser excluído.

### <a name="return-value"></a>Valor retornado

Não zero se bem sucedido; caso contrário, 0.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFC_CTabCtrl#3](../../mfc/reference/codesnippet/cpp/ctabctrl-class_3.cpp)]

## <a name="ctabctrldeselectall"></a><a name="deselectall"></a>CTabCtrl::DeselectAll

Redefine itens em um controle de guia, limpando todos os que foram pressionados.

```
void DeselectAll(BOOL fExcludeFocus);
```

### <a name="parameters"></a>Parâmetros

*FExcluFocus*<br/>
Sinalizador que especifica o escopo da desseleção do item. Se este parâmetro estiver definido como FALSE, todos os botões de guia serão redefinidos. Se estiver definido como TRUE, todos os itens da guia, exceto o selecionado no momento, serão redefinidos.

### <a name="remarks"></a>Comentários

Esta função de membro implementa o comportamento da mensagem Win32, [TCM_DESELECTALL](/windows/win32/Controls/tcm-deselectall), conforme descrito no SDK do Windows.

## <a name="ctabctrldrawitem"></a><a name="drawitem"></a>CTabCtrl::DrawItem

Chamado pela estrutura quando um aspecto visual de um controle de guia de desenho do proprietário muda.

```
virtual void DrawItem(LPDRAWITEMSTRUCT lpDrawItemStruct);
```

### <a name="parameters"></a>Parâmetros

*Lpdrawitemstruct*<br/>
Um ponteiro para uma estrutura [DRAWITEMSTRUCT](/windows/win32/api/winuser/ns-winuser-drawitemstruct) descrevendo o item a ser pintado.

### <a name="remarks"></a>Comentários

O `itemAction` membro `DRAWITEMSTRUCT` da estrutura define a ação de desenho a ser realizada.

Por padrão, esta função de membro não faz nada. Substituir esta função de membro para implementar `CTabCtrl` o desenho para um objeto de desenho do proprietário.

O aplicativo deve restaurar todos os objetos GDI (Graphics Device Interface, interface de dispositivo gráfico) selecionados para o contexto de exibição fornecido no *lpDrawItemStruct* antes que essa função de membro seja encerrada.

## <a name="ctabctrlgetcurfocus"></a><a name="getcurfocus"></a>CTabCtrl::GetCurFocus

Recupera o índice da guia com o foco atual.

```
int GetCurFocus() const;
```

### <a name="return-value"></a>Valor retornado

O índice baseado em zero da guia com o foco atual.

## <a name="ctabctrlgetcursel"></a><a name="getcursel"></a>CTabCtrl::GetCurSel

Recupera a guia selecionada no momento em um controle de guia.

```
int GetCurSel() const;
```

### <a name="return-value"></a>Valor retornado

Índice baseado em zero da guia selecionada se for bem sucedido ou - 1 se nenhuma guia for selecionada.

## <a name="ctabctrlgetextendedstyle"></a><a name="getextendedstyle"></a>CTabCtrl::GetExtendedStyle

Recupera os estilos estendidos que estão atualmente em uso para o controle de guias.

```
DWORD GetExtendedStyle();
```

### <a name="return-value"></a>Valor retornado

Representa os estilos estendidos atualmente em uso para o controle de guias. Este valor é uma combinação de [estilos estendidos](/windows/win32/Controls/tab-control-extended-styles)de controle de guia, conforme descrito no SDK do Windows.

### <a name="remarks"></a>Comentários

Esta função de membro implementa o comportamento da [TCM_GETEXTENDEDSTYLE](/windows/win32/Controls/tcm-getextendedstyle)de mensagem Win32 , conforme descrito no SDK do Windows.

## <a name="ctabctrlgetimagelist"></a><a name="getimagelist"></a>CTabCtrl::GetImageList

Recupera a lista de imagens associada a um controle de guia.

```
CImageList* GetImageList() const;
```

### <a name="return-value"></a>Valor retornado

Se for bem-sucedido, um ponteiro para a lista de imagens do controle da guia; caso contrário, NULL.

## <a name="ctabctrlgetitem"></a><a name="getitem"></a>CTabCtrl::GetItem

Recupera informações sobre uma guia em um controle de guia.

```
BOOL GetItem(int nItem,   TCITEM* pTabCtrlItem) const;
```

### <a name="parameters"></a>Parâmetros

*Nitem*<br/>
Índice baseado em zero da guia.

*pTabCtrlItem*<br/>
Ponteiro para uma estrutura [TCITEM,](/windows/win32/api/commctrl/ns-commctrl-tcitemw) usada para especificar as informações a serem recuperadas. Também usado para receber informações sobre a guia. Esta estrutura é `InsertItem`usada `GetItem`com `SetItem` as funções , e membros.

### <a name="return-value"></a>Valor retornado

Retorna TRUE se for bem sucedido; FALSO de outra forma.

### <a name="remarks"></a>Comentários

Quando a mensagem `mask` é enviada, o membro especifica quais atributos retornar. Se `mask` o membro especificar o `pszText` valor TCIF_TEXT, o membro deve conter o `cchTextMax` endereço do buffer que recebe o texto do item e o membro deve especificar o tamanho do buffer.

- `mask`

   Valor especificando `TCITEM` quais membros da estrutura devem ser recuperados ou definidos. Este membro pode ser zero ou uma combinação dos seguintes valores:

  - TCIF_TEXT `pszText` O membro é válido.

  - TCIF_IMAGE `iImage` O membro é válido.

  - TCIF_PARAM `lParam` O membro é válido.

  - TCIF_RTLREADING O `pszText` texto é exibido usando ordem de leitura da direita para a esquerda em sistemas hebraicos ou árabes.

  - TCIF_STATE `dwState` O membro é válido.

- `pszText`

   Pointer para uma seqüência de terminação nula contendo o texto da guia se a estrutura contiver informações sobre uma guia. Se a estrutura estiver recebendo informações, este membro especificar o endereço do buffer que recebe o texto da guia.

- `cchTextMax`

   Tamanho do buffer apontado `pszText`por . Este membro é ignorado se a estrutura não está recebendo informações.

- `iImage`Indexar na lista de imagens do controle de guia, ou - 1 se não houver imagem para a guia.

- `lParam`

   Dados definidos pelo aplicativo associados à guia. Se houver mais de quatro bytes de dados definidos por aplicativo por guia, `TCITEM` um aplicativo deve definir uma estrutura e usá-la em vez da estrutura. O primeiro membro da estrutura definida pelo aplicativo deve ser uma estrutura [TCITEMHEADER.](/windows/win32/api/commctrl/ns-commctrl-tcitemheaderw) A `TCITEMHEADER` estrutura é `TCITEM` idêntica à estrutura, mas sem o `lParam` membro. A diferença entre o tamanho da sua `TCITEMHEADER` estrutura e o tamanho da estrutura deve ser igual ao número de bytes extras por guia.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFC_CTabCtrl#4](../../mfc/reference/codesnippet/cpp/ctabctrl-class_4.cpp)]

## <a name="ctabctrlgetitemcount"></a><a name="getitemcount"></a>CTabCtrl::GetItemCount

Recupera o número de guias no controle da guia.

```
int GetItemCount() const;
```

### <a name="return-value"></a>Valor retornado

Número de itens no controle da guia.

### <a name="example"></a>Exemplo

  Veja o exemplo de [CPropertySheet::GetTabControl](../../mfc/reference/cpropertysheet-class.md#gettabcontrol).

## <a name="ctabctrlgetitemrect"></a><a name="getitemrect"></a>CTabCtrl::GetItemRect

Recupera o retângulo delimitador para a guia especificada em um controle de guia.

```
BOOL GetItemRect(int nItem,   LPRECT lpRect) const;
```

### <a name="parameters"></a>Parâmetros

*Nitem*<br/>
Índice baseado em zero do item da guia.

*Lprect*<br/>
Pointer para uma estrutura [RECT](/previous-versions/dd162897\(v=vs.85\)) que recebe o retângulo delimitador da guia. Essas coordenadas usam o modo de mapeamento atual da viewport.

### <a name="return-value"></a>Valor retornado

Não zero se bem sucedido; caso contrário, 0.

### <a name="example"></a>Exemplo

  Veja o exemplo de [CPropertySheet::GetTabControl](../../mfc/reference/cpropertysheet-class.md#gettabcontrol).

## <a name="ctabctrlgetitemstate"></a><a name="getitemstate"></a>CTabCtrl::GetItemState

Recupera o estado do item de controle de guia identificado por *nItem*.

```
DWORD GetItemState(
    int nItem,
    DWORD dwMask) const;
```

### <a name="parameters"></a>Parâmetros

*Nitem*<br/>
O número de índice baseado em zero do item para o qual recuperar informações do estado.

*Dwmask*<br/>
Máscara especificando qual das bandeiras de estado do item deve retornar. Para obter uma lista de valores, consulte o membro da máscara da estrutura [TCITEM,](/windows/win32/api/commctrl/ns-commctrl-tcitemw) conforme descrito no SDK do Windows.

### <a name="return-value"></a>Valor retornado

Uma referência a um valor DWORD recebendo as informações do estado. Pode ser um dos seguintes valores:

|Valor|Descrição|
|-----------|-----------------|
|TCIS_BUTTONPRESSED|O item de controle de guia satisfaz-se.|
|TCIS_HIGHLIGHTED|O item de controle de guia é destacado, e a guia e o texto são desenhados usando a cor de destaque atual. Ao usar a cor de destaque, esta será uma verdadeira interpolação, não uma cor dithered.|

### <a name="remarks"></a>Comentários

O estado de um item `dwState` é especificado pelo membro da `TCITEM` estrutura.

## <a name="ctabctrlgetrowcount"></a><a name="getrowcount"></a>CTabCtrl::GetRowCount

Recupera o número atual de linhas em um controle de guia.

```
int GetRowCount() const;
```

### <a name="return-value"></a>Valor retornado

O número de linhas de guias no controle da guia.

### <a name="remarks"></a>Comentários

Somente os controles de guia que têm o estilo TCS_MULTILINE podem ter várias linhas de guias.

## <a name="ctabctrlgettooltips"></a><a name="gettooltips"></a>CTabCtrl::GetToolTips

Recupera a alça do controle de ponta da ferramenta associada a um controle de guia.

```
CToolTipCtrl* GetToolTips() const;
```

### <a name="return-value"></a>Valor retornado

Alça do controle de ponta da ferramenta se for bem-sucedida; caso contrário, NULL.

### <a name="remarks"></a>Comentários

Um controle de guia cria um controle de ponta de ferramenta se tiver o estilo TCS_TOOLTIPS. Você também pode atribuir um controle de ponta `SetToolTips` de ferramenta a um controle de guia usando a função membro.

## <a name="ctabctrlhighlightitem"></a><a name="highlightitem"></a>CTabCtrl::HighlightItem

Define o estado de destaque de um item de guia.

```
BOOL HighlightItem(int idItem,   BOOL fHighlight = TRUE);
```

### <a name="parameters"></a>Parâmetros

*idItem*<br/>
Índice baseado em zero de um item de controle de guia.

*fDestaque*<br/>
Valor especificando o estado de destaque a ser definido. Se esse valor for TRUE, a guia será destacada; se FALSE, a guia é definida para o seu estado padrão.

### <a name="return-value"></a>Valor retornado

Não zero se bem sucedido; caso contrário, zero.

### <a name="remarks"></a>Comentários

Esta função de membro implementa a [TCM_HIGHLIGHTITEM](/windows/win32/Controls/tcm-highlightitem)de mensagem Win32 , conforme descrito no SDK do Windows.

## <a name="ctabctrlhittest"></a><a name="hittest"></a>CTabCtrl::HitTest

Determina qual guia, se houver, está na posição de tela especificada.

```
int HitTest(TCHITTESTINFO* pHitTestInfo) const;
```

### <a name="parameters"></a>Parâmetros

*pHitTestInfo*<br/>
Pointer para uma estrutura [TCHITTESTINFO,](/windows/win32/api/commctrl/ns-commctrl-tchittestinfo) conforme descrito no SDK do Windows, que especifica a posição da tela para testar.

### <a name="return-value"></a>Valor retornado

Retorna o índice baseado em zero da guia ou - 1 se nenhuma guia estiver na posição especificada.

## <a name="ctabctrlinsertitem"></a><a name="insertitem"></a>CTabCtrl::InsertItem

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

*Nitem*<br/>
Índice baseado em zero da nova guia.

*pTabCtrlItem*<br/>
Pointer para uma estrutura [TCITEM](/windows/win32/api/commctrl/ns-commctrl-tcitemw) que especifica os atributos da guia.

*Lpszitem*<br/>
Endereço de uma seqüência de terminadas nula que contém o texto da guia.

*Nimage*<br/>
O índice baseado em zero de uma imagem para inserir a partir de uma lista de imagens.

*Nmask*<br/>
Especifica quais `TCITEM` atributos de estrutura a definir. Pode ser zero ou uma combinação dos seguintes valores:

- TCIF_TEXT `pszText` O membro é válido.

- TCIF_IMAGE `iImage` O membro é válido.

- TCIF_PARAM O membro *iParam* é válido.

- TCIF_RTLREADING O `pszText` texto é exibido usando ordem de leitura da direita para a esquerda em sistemas hebraicos ou árabes.

- TCIF_STATE O membro *do DWState* é válido.

*lParam*<br/>
Dados definidos pelo aplicativo associados à guia.

*Dwstate*<br/>
Especifica valores para os estados do item. Para obter mais informações, consulte [TCITEM](/windows/win32/api/commctrl/ns-commctrl-tcitemw) no Windows SDK.

*dwStateMask*<br/>
Especifica quais estados devem ser definidos. Para obter mais informações, consulte [TCITEM](/windows/win32/api/commctrl/ns-commctrl-tcitemw) no Windows SDK.

### <a name="return-value"></a>Valor retornado

Índice baseado em zero da nova guia se for bem-sucedido; caso contrário - 1.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFC_CTabCtrl#5](../../mfc/reference/codesnippet/cpp/ctabctrl-class_5.cpp)]

## <a name="ctabctrlremoveimage"></a><a name="removeimage"></a>CTabCtrl::RemoveImage

Remove a imagem especificada da lista de imagens de um controle de guia.

```
void RemoveImage(int nImage);
```

### <a name="parameters"></a>Parâmetros

*Nimage*<br/>
Índice baseado em zero da imagem para remover.

### <a name="remarks"></a>Comentários

O controle de guia atualiza o índice de imagem de cada guia para que cada guia permaneça associada à mesma imagem.

## <a name="ctabctrlsetcurfocus"></a><a name="setcurfocus"></a>CTabCtrl::SetCurFocus

Define o foco para uma guia especificada em um controle de guia.

```
void SetCurFocus(int nItem);
```

### <a name="parameters"></a>Parâmetros

*Nitem*<br/>
Especifica o índice da guia que obtém o foco.

### <a name="remarks"></a>Comentários

Esta função de membro implementa o comportamento da [TCM_SETCURFOCUS](/windows/win32/Controls/tcm-setcurfocus)de mensagem Win32 , conforme descrito no SDK do Windows.

## <a name="ctabctrlsetcursel"></a><a name="setcursel"></a>CTabCtrl::SetCurSel

Seleciona uma guia em um controle de guia.

```
int SetCurSel(int nItem);
```

### <a name="parameters"></a>Parâmetros

*Nitem*<br/>
O índice baseado em zero do item a ser selecionado.

### <a name="return-value"></a>Valor retornado

Índice baseado em zero da guia previamente selecionada se for bem sucedido, caso contrário - 1.

### <a name="remarks"></a>Comentários

Um controle de guia não envia uma mensagem de notificação TCN_SELCHANGING ou TCN_SELCHANGE quando uma guia é selecionada usando esta função. Essas notificações são enviadas, usando WM_NOTIFY, quando o usuário clica ou usa o teclado para alterar guias.

## <a name="ctabctrlsetextendedstyle"></a><a name="setextendedstyle"></a>CTabCtrl::SetExtendedStyle

Define os estilos estendidos para um controle de guia.

```
DWORD SetExtendedStyle(DWORD dwNewStyle,   DWORD dwExMask = 0);
```

### <a name="parameters"></a>Parâmetros

*dwNewStyle*<br/>
Valor especificando uma combinação de estilos estendidos de controle de guia.

*Dwexmask*<br/>
Um valor DWORD que indica quais estilos no *dwNewStyle* devem ser afetados. Apenas os estilos estendidos no *dwExMask* serão alterados. Todos os outros estilos serão mantidos como estão. Se este parâmetro for zero, todos os estilos no *dwNewStyle* serão afetados.

### <a name="return-value"></a>Valor retornado

Um valor DWORD que contém os [estilos estendidos de controle de guia](/windows/win32/Controls/tab-control-extended-styles)anteriores, conforme descrito no SDK do Windows.

### <a name="return-value"></a>Valor retornado

Esta função de membro implementa o comportamento da [TCM_SETEXTENDEDSTYLE](/windows/win32/Controls/tcm-setextendedstyle)de mensagem Win32, conforme descrito no SDK do Windows.

## <a name="ctabctrlsetimagelist"></a><a name="setimagelist"></a>CTabCtrl::SetImageList

Atribui uma lista de imagens a um controle de guia.

```
CImageList* SetImageList(CImageList* pImageList);
```

### <a name="parameters"></a>Parâmetros

*pImageList*<br/>
Ponteiro para a lista de imagens a ser atribuído ao controle da guia.

### <a name="return-value"></a>Valor retornado

Retorna um ponteiro para a lista de imagens anterior ou NULL se não houver uma lista de imagens anterior.

## <a name="ctabctrlsetitem"></a><a name="setitem"></a>CTabCtrl::SetItem

Define alguns ou todos os atributos de uma guia.

```
BOOL SetItem(int nItem,   TCITEM* pTabCtrlItem);
```

### <a name="parameters"></a>Parâmetros

*Nitem*<br/>
Índice baseado em zero do item.

*pTabCtrlItem*<br/>
Pointer para uma estrutura [TCITEM](/windows/win32/api/commctrl/ns-commctrl-tcitemw) que contém os atributos do novo item. O `mask` membro especifica quais atributos definir. Se `mask` o membro especificar o `pszText` valor TCIF_TEXT, o membro será o `cchTextMax` endereço de uma seqüência de seqüência sumida e o membro será ignorado.

### <a name="return-value"></a>Valor retornado

Não zero se bem sucedido; caso contrário, 0.

### <a name="example"></a>Exemplo

  Veja o exemplo de [GetItem](#getitem).

## <a name="ctabctrlsetitemextra"></a><a name="setitemextra"></a>CTabCtrl::SetItemExtra

Define o número de bytes por guia reservado para dados definidos pelo aplicativo em um controle de guia.

```
BOOL SetItemExtra(int nBytes);
```

### <a name="parameters"></a>Parâmetros

*Nbytes*<br/>
O número de bytes extras a definir.

### <a name="return-value"></a>Valor retornado

Não zero se bem sucedido; caso contrário, zero.

### <a name="remarks"></a>Comentários

Esta função de membro implementa o comportamento da [TCM_SETITEMEXTRA](/windows/win32/Controls/tcm-setitemextra)de mensagem Win32 , conforme descrito no SDK do Windows.

## <a name="ctabctrlsetitemsize"></a><a name="setitemsize"></a>CTabCtrl::SetItemSize

Define a largura e a altura dos itens de controle de guia.

```
CSize SetItemSize(CSize size);
```

### <a name="parameters"></a>Parâmetros

*Tamanho*<br/>
A nova largura e altura, em pixels, dos itens de controle de guia.

### <a name="return-value"></a>Valor retornado

Retorna a largura e a altura antigas dos itens de controle de guia.

## <a name="ctabctrlsetitemstate"></a><a name="setitemstate"></a>CTabCtrl::SetItemState

Define o estado do item de controle de guia identificado por *nItem*.

```
BOOL SetItemState(
    int nItem,
    DWORD dwMask,
    DWORD dwState);
```

### <a name="parameters"></a>Parâmetros

*Nitem*<br/>
O número de índice baseado em zero do item para o qual definir as informações do estado.

*Dwmask*<br/>
Máscara especificando qual das bandeiras de estado do item a definir. Para obter uma lista de valores, consulte o membro da máscara da estrutura [TCITEM,](/windows/win32/api/commctrl/ns-commctrl-tcitemw) conforme descrito no SDK do Windows.

*Dwstate*<br/>
Uma referência a um valor DWORD contendo as informações do estado. Pode ser um dos seguintes valores:

|Valor|Descrição|
|-----------|-----------------|
|TCIS_BUTTONPRESSED|O item de controle de guia satisfaz-se.|
|TCIS_HIGHLIGHTED|O item de controle de guia é destacado, e a guia e o texto são desenhados usando a cor de destaque atual. Ao usar a cor de destaque, esta será uma verdadeira interpolação, não uma cor dithered.|

### <a name="return-value"></a>Valor retornado

Não zero se bem sucedido; caso contrário, 0.

## <a name="ctabctrlsetmintabwidth"></a><a name="setmintabwidth"></a>CTabCtrl::SetMin''''''''''''''''''''''''''''

Define a largura mínima dos itens em um controle de guia.

```
int SetMinTabWidth(int cx);
```

### <a name="parameters"></a>Parâmetros

*Cx*<br/>
Largura mínima a ser definida para um item de controle de guia. Se este parâmetro estiver definido como -1, o controle usará a largura da guia padrão.

### <a name="return-value"></a>Valor retornado

A largura mínima de guia anterior.

### <a name="return-value"></a>Valor retornado

Esta função de membro implementa o comportamento da [TCM_SETMINTABWIDTH](/windows/win32/Controls/tcm-setmintabwidth)de mensagem Win32 , conforme descrito no SDK do Windows.

## <a name="ctabctrlsetpadding"></a><a name="setpadding"></a>CTabCtrl::SetPadding

Define a quantidade de espaço (preenchimento) em torno do ícone e do rótulo de cada guia em um controle de guia.

```
void SetPadding(CSize size);
```

### <a name="parameters"></a>Parâmetros

*Tamanho*<br/>
Define a quantidade de espaço (preenchimento) em torno do ícone e do rótulo de cada guia em um controle de guia.

## <a name="ctabctrlsettooltips"></a><a name="settooltips"></a>CTabCtrl::SetToolTips

Atribui um controle de ponta de ferramenta a um controle de guia.

```
void SetToolTips(CToolTipCtrl* pWndTip);
```

### <a name="parameters"></a>Parâmetros

*pWndTip*<br/>
Alça do controle de ponta da ferramenta.

### <a name="remarks"></a>Comentários

Você pode obter o controle de ponta da ferramenta `GetToolTips`associado a um controle de guia fazendo uma chamada para .

### <a name="example"></a>Exemplo

  Veja o exemplo de [CPropertySheet::GetTabControl](../../mfc/reference/cpropertysheet-class.md#gettabcontrol).

## <a name="see-also"></a>Confira também

[Classe CWnd](../../mfc/reference/cwnd-class.md)<br/>
[Gráfico da hierarquia](../../mfc/hierarchy-chart.md)<br/>
[Classe CHeaderCtrl](../../mfc/reference/cheaderctrl-class.md)<br/>
[Classe CListCtrl](../../mfc/reference/clistctrl-class.md)
