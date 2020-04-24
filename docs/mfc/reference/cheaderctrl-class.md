---
title: Classe CHeaderCtrl
ms.date: 11/04/2016
f1_keywords:
- CHeaderCtrl
- AFXCMN/CHeaderCtrl
- AFXCMN/CHeaderCtrl::CHeaderCtrl
- AFXCMN/CHeaderCtrl::ClearAllFilters
- AFXCMN/CHeaderCtrl::ClearFilter
- AFXCMN/CHeaderCtrl::Create
- AFXCMN/CHeaderCtrl::CreateDragImage
- AFXCMN/CHeaderCtrl::CreateEx
- AFXCMN/CHeaderCtrl::DeleteItem
- AFXCMN/CHeaderCtrl::DrawItem
- AFXCMN/CHeaderCtrl::EditFilter
- AFXCMN/CHeaderCtrl::GetBitmapMargin
- AFXCMN/CHeaderCtrl::GetFocusedItem
- AFXCMN/CHeaderCtrl::GetImageList
- AFXCMN/CHeaderCtrl::GetItem
- AFXCMN/CHeaderCtrl::GetItemCount
- AFXCMN/CHeaderCtrl::GetItemDropDownRect
- AFXCMN/CHeaderCtrl::GetItemRect
- AFXCMN/CHeaderCtrl::GetOrderArray
- AFXCMN/CHeaderCtrl::GetOverflowRect
- AFXCMN/CHeaderCtrl::HitTest
- AFXCMN/CHeaderCtrl::InsertItem
- AFXCMN/CHeaderCtrl::Layout
- AFXCMN/CHeaderCtrl::OrderToIndex
- AFXCMN/CHeaderCtrl::SetBitmapMargin
- AFXCMN/CHeaderCtrl::SetFilterChangeTimeout
- AFXCMN/CHeaderCtrl::SetFocusedItem
- AFXCMN/CHeaderCtrl::SetHotDivider
- AFXCMN/CHeaderCtrl::SetImageList
- AFXCMN/CHeaderCtrl::SetItem
- AFXCMN/CHeaderCtrl::SetOrderArray
helpviewer_keywords:
- CHeaderCtrl [MFC], CHeaderCtrl
- CHeaderCtrl [MFC], ClearAllFilters
- CHeaderCtrl [MFC], ClearFilter
- CHeaderCtrl [MFC], Create
- CHeaderCtrl [MFC], CreateDragImage
- CHeaderCtrl [MFC], CreateEx
- CHeaderCtrl [MFC], DeleteItem
- CHeaderCtrl [MFC], DrawItem
- CHeaderCtrl [MFC], EditFilter
- CHeaderCtrl [MFC], GetBitmapMargin
- CHeaderCtrl [MFC], GetFocusedItem
- CHeaderCtrl [MFC], GetImageList
- CHeaderCtrl [MFC], GetItem
- CHeaderCtrl [MFC], GetItemCount
- CHeaderCtrl [MFC], GetItemDropDownRect
- CHeaderCtrl [MFC], GetItemRect
- CHeaderCtrl [MFC], GetOrderArray
- CHeaderCtrl [MFC], GetOverflowRect
- CHeaderCtrl [MFC], HitTest
- CHeaderCtrl [MFC], InsertItem
- CHeaderCtrl [MFC], Layout
- CHeaderCtrl [MFC], OrderToIndex
- CHeaderCtrl [MFC], SetBitmapMargin
- CHeaderCtrl [MFC], SetFilterChangeTimeout
- CHeaderCtrl [MFC], SetFocusedItem
- CHeaderCtrl [MFC], SetHotDivider
- CHeaderCtrl [MFC], SetImageList
- CHeaderCtrl [MFC], SetItem
- CHeaderCtrl [MFC], SetOrderArray
ms.assetid: b847ac90-5fae-4a87-88e0-ca45f77b8b3b
ms.openlocfilehash: de1705d47c5692d3563bc7d9cb2646531819197a
ms.sourcegitcommit: 7a6116e48c3c11b97371b8ae4ecc23adce1f092d
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/22/2020
ms.locfileid: "81750927"
---
# <a name="cheaderctrl-class"></a>Classe CHeaderCtrl

Fornece a funcionalidade do controle de cabeçalho comum do Windows.

## <a name="syntax"></a>Sintaxe

```
class CHeaderCtrl : public CWnd
```

## <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores públicos

|Nome|Descrição|
|----------|-----------------|
|[CHeaderCtrl::CHeaderCtrl](#cheaderctrl)|Constrói um objeto `CHeaderCtrl`.|

### <a name="public-methods"></a>Métodos públicos

|Nome|Descrição|
|----------|-----------------|
|[CHeaderCtrl::ClearAllFilters](#clearallfilters)|Limpa todos os filtros para um controle de cabeçalho.|
|[CHeaderCtrl::ClearFilter](#clearfilter)|Limpa o filtro para um controle de cabeçalho.|
|[CHeaderCtrl::Criar](#create)|Cria um controle de cabeçalho e o anexa a um `CHeaderCtrl` objeto.|
|[CHeaderCtrl::CreateDragImage](#createdragimage)|Cria uma versão transparente da imagem de um item dentro de um controle de cabeçalho.|
|[CHeaderCtrl::CreateEx](#createex)|Cria um controle de cabeçalho com os estilos `CListCtrl` estendidos do Windows especificados e o anexa a um objeto.|
|[CHeaderCtrl::DeleteItem](#deleteitem)|Exclui um item de um controle de cabeçalho.|
|[CHeaderCtrl::DrawItem](#drawitem)|Desenha o item especificado de um controle de cabeçalho.|
|[CHeaderCtrl::EditFilter](#editfilter)|Começa a editar o filtro especificado de um controle de cabeçalho.|
|[CHeaderCtrl::GetBitmapMargin](#getbitmapmargin)|Recupera a largura da margem de um bitmap em um controle de cabeçalho.|
|[CHeaderCtrl::GetFocusedItem](#getfocuseditem)|Obtém o identificador do item no controle de cabeçalho atual que tem o foco.|
|[CHeaderCtrl::GetImageList](#getimagelist)|Recupera a alça de uma lista de imagens usada para desenhar itens de cabeçalho em um controle de cabeçalho.|
|[CHeaderCtrl::GetItem](#getitem)|Recupera informações sobre um item em um controle de cabeçalho.|
|[CHeaderCtrl::GetItemCount](#getitemcount)|Recupera uma contagem dos itens em um controle de cabeçalho.|
|[CHeaderCtrl::GetItemDropDownRect](#getitemdropdownrect)|Obtém as informações delimitador do retângulo para o botão de baixa especificado em um controle de cabeçalho.|
|[CHeaderCtrl::GetItemRect](#getitemrect)|Recupera o retângulo delimitador para um determinado item em um controle de cabeçalho.|
|[CHeaderCtrl::GetOrderArray](#getorderarray)|Recupera a ordem da esquerda para a direita dos itens em um controle de cabeçalho.|
|[CHeaderCtrl::GetOverflowRect](#getoverflowrect)|Obtém o retângulo delimitador do botão de estouro para o controle de cabeçalho atual.|
|[CHeaderCtrl::HitTest](#hittest)|Determina qual item de cabeçalho, se houver, está localizado em um ponto especificado.|
|[CHeaderCtrl::InsertItem](#insertitem)|Insere um novo item em um controle de cabeçalho.|
|[CHeaderCtrl::Layout](#layout)|Recupera o tamanho e a posição de um controle de cabeçalho dentro de um determinado retângulo.|
|[CHeaderCtrl::OrderToIndex](#ordertoindex)|Recupera o valor do índice de um item com base em sua ordem no controle de cabeçalho.|
|[CHeaderCtrl::SetBitmapMargin](#setbitmapmargin)|Define a largura da margem de um bitmap em um controle de cabeçalho.|
|[CHeaderCtrl::SetFilterChangeTimeout](#setfilterchangetimeout)|Define o intervalo de tempo entre o tempo em que uma `HDN_FILTERCHANGE` alteração ocorre nos atributos do filtro e a publicação de uma notificação.|
|[CHeaderCtrl::SetFocusedItem](#setfocuseditem)|Define o foco como um item de cabeçalho especificado no controle de cabeçalho atual.|
|[CHeaderCtrl::SetHotDivider](#sethotdivider)|Altera o divisor entre itens de cabeçalho para indicar um arrasto manual e queda de um item de cabeçalho.|
|[CHeaderCtrl::SetImageList](#setimagelist)|Atribui uma lista de imagens a um controle de cabeçalho.|
|[CHeaderCtrl::SetItem](#setitem)|Define os atributos do item especificado em um controle de cabeçalho.|
|[CHeaderCtrl::SetOrderArray](#setorderarray)|Define a ordem da esquerda para a direita dos itens em um controle de cabeçalho.|

## <a name="remarks"></a>Comentários

Um controle de cabeçalho é uma janela que geralmente está posicionada acima de um conjunto de colunas de texto ou números. Contém um título para cada coluna, e pode ser dividido em partes. O usuário pode arrastar os divisores que separam as partes para definir a largura de cada coluna. Para obter uma ilustração de um controle de cabeçalho, consulte [Controles de cabeçalho](/windows/win32/Controls/header-controls).

Este controle (e, `CHeaderCtrl` portanto, a classe) está disponível apenas para programas que são executados sob o Windows 95/98 e windows NT versão 3.51 e posterior.

A funcionalidade adicionada para controles comuns do Windows 95/Internet Explorer 4.0 inclui o seguinte:

- Encomenda personalizada do item do cabeçalho.

- Arrastar e soltar o item de cabeçalho para reordenar itens de cabeçalho. Use o estilo HDS_DRAGDROP `CHeaderCtrl` ao criar o objeto.

- Texto da coluna cabeçalho constantemente visível durante o redimensionamento da coluna. Use o estilo HDS_FULLDRAG `CHeaderCtrl` ao criar um objeto.

- Rastreamento quente do cabeçalho, que destaca o item de cabeçalho quando o ponteiro está pairando sobre ele. Use o estilo HDS_HOTTRACK `CHeaderCtrl` ao criar o objeto.

- Suporte à lista de imagens. Os itens de cabeçalho `CImageList` podem conter imagens armazenadas em um objeto ou texto.

Para obter mais `CHeaderCtrl`informações sobre como usar, consulte [Controles](../../mfc/controls-mfc.md) e [Usando CHeaderCtrl](../../mfc/using-cheaderctrl.md).

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

[Cobject](../../mfc/reference/cobject-class.md)

[Ccmdtarget](../../mfc/reference/ccmdtarget-class.md)

[CWnd](../../mfc/reference/cwnd-class.md)

`CHeaderCtrl`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** afxcmn.h

## <a name="cheaderctrlcheaderctrl"></a><a name="cheaderctrl"></a>CHeaderCtrl::CHeaderCtrl

Constrói um objeto `CHeaderCtrl`.

```
CHeaderCtrl();
```

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFC_CHeaderCtrl#1](../../mfc/reference/codesnippet/cpp/cheaderctrl-class_1.cpp)]

## <a name="cheaderctrlclearallfilters"></a><a name="clearallfilters"></a>CHeaderCtrl::ClearAllFilters

Limpa todos os filtros para um controle de cabeçalho.

```
BOOL ClearAllFilters();
```

### <a name="return-value"></a>Valor retornado

VERDADE se este método for bem sucedido; caso contrário, FALSE.

### <a name="remarks"></a>Comentários

Este método implementa o comportamento da [mensagem](/windows/win32/Controls/hdm-clearfilter) Win32 HDM_CLEARFILTER com um valor de coluna de -1, conforme descrito no SDK do Windows.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFC_CHeaderCtrl#2](../../mfc/reference/codesnippet/cpp/cheaderctrl-class_2.cpp)]

## <a name="cheaderctrlclearfilter"></a><a name="clearfilter"></a>CHeaderCtrl::ClearFilter

Limpa o filtro para um controle de cabeçalho.

```
BOOL ClearFilter(int nColumn);
```

### <a name="parameters"></a>Parâmetros

*nColuna*<br/>
Valor da coluna indicando qual filtro limpar.

### <a name="return-value"></a>Valor retornado

VERDADE se este método for bem sucedido; caso contrário, FALSE.

### <a name="remarks"></a>Comentários

Este método implementa o comportamento da [mensagem](/windows/win32/Controls/hdm-clearfilter)Win32 HDM_CLEARFILTER , conforme descrito no SDK do Windows.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFC_CHeaderCtrl#3](../../mfc/reference/codesnippet/cpp/cheaderctrl-class_3.cpp)]

## <a name="cheaderctrlcreate"></a><a name="create"></a>CHeaderCtrl::Criar

Cria um controle de cabeçalho e o anexa a um `CHeaderCtrl` objeto.

```
virtual BOOL Create(
    DWORD dwStyle,
    const RECT& rect,
    CWnd* pParentWnd,
    UINT nID);
```

### <a name="parameters"></a>Parâmetros

*Dwstyle*<br/>
Especifica o estilo do controle de cabeçalho. Para obter uma descrição dos estilos de controle de cabeçalho, consulte Estilos de controle de [cabeçalho](/windows/win32/Controls/header-control-styles) no SDK do Windows.

*Rect*<br/>
Especifica o tamanho e a posição do controle de cabeçalho. Pode ser um objeto [CRect](../../atl-mfc-shared/reference/crect-class.md) ou uma estrutura [RECT.](/windows/win32/api/windef/ns-windef-rect)

*Pparentwnd*<br/>
Especifica a janela pai do controle `CDialog`de cabeçalho, geralmente um . Não deve ser NULO.

*nID*<br/>
Especifica o ID do controle de cabeçalho.

### <a name="return-value"></a>Valor retornado

Não zero se a inicialização foi bem sucedida; caso contrário, zero.

### <a name="remarks"></a>Comentários

Você constrói `CHeaderCtrl` um objeto em dois passos. Primeiro, chame o construtor `Create`e depois chame, o que cria `CHeaderCtrl` o controle de cabeçalho e o anexa ao objeto.

Além dos estilos de controle de cabeçalho, você pode usar os seguintes estilos de controle comuns para determinar como o controle de cabeçalho posiciona e redimensiona-se (consulte [Estilos de controle comum](/windows/win32/Controls/common-control-styles) para obter mais informações):

- CCS_BOTTOM Faz com que o controle se posicione na parte inferior da área cliente da janela pai e defina a largura igual à largura da janela pai.

- CCS_NODIVIDER Impede que um destaque de dois pixels seja desenhado na parte superior do controle.

- CCS_NOMOVEY faz com que o controle se redimensione e se mova horizontalmente, mas não verticalmente, em resposta a uma mensagem WM_SIZE. Se o estilo CCS_NORESIZE for usado, este estilo não se aplica. Os controles de cabeçalho têm esse estilo por padrão.

- CCS_NOPARENTALIGN impede que o controle se mova automaticamente para a parte superior ou inferior da janela dos pais. Em vez disso, o controle mantém sua posição dentro da janela pai, apesar de alterações no tamanho da janela pai. Se o estilo CCS_TOP ou CCS_BOTTOM também for usado, a altura será ajustada ao padrão, mas a posição e a largura permanecem inalteradas.

- CCS_NORESIZE Impede que o controle use a largura e a altura padrão ao definir seu tamanho inicial ou um novo tamanho. Em vez disso, o controle usa a largura e a altura especificadas na solicitação de criação ou dimensionamento.

- CCS_TOP faz com que o controle se posicione na parte superior da área cliente da janela pai e defina a largura igual à largura da janela pai.

Você também pode aplicar os seguintes estilos de janela a um controle de cabeçalho (consulte [Estilos de janela](../../mfc/reference/styles-used-by-mfc.md#window-styles) para obter mais informações):

- WS_CHILD cria uma janela para crianças. Não pode ser usado com o estilo WS_POPUP.

- WS_VISIBLE Cria uma janela que é inicialmente visível.

- WS_DISABLED Cria uma janela inicialmente desativada.

- WS_GROUP Especifica o primeiro controle de um grupo de controles no qual o usuário pode mover de um controle para o outro com as teclas de seta. Todos os controles definidos com o estilo WS_GROUP após o primeiro controle pertencem ao mesmo grupo. O próximo controle com o estilo WS_GROUP termina o grupo de estilo e inicia o próximo grupo (ou seja, um grupo termina onde o próximo começa).

- WS_TABSTOP Especifica um dos vários controles através dos quais o usuário pode se mover usando a tecla TAB. A tecla TAB move o usuário para o próximo controle especificado pelo estilo WS_TABSTOP.

Se você quiser usar estilos de janelas estendidos `Create`com o controle, chame [CreateEx](#createex) em vez de .

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFC_CHeaderCtrl#4](../../mfc/reference/codesnippet/cpp/cheaderctrl-class_4.cpp)]

## <a name="cheaderctrlcreateex"></a><a name="createex"></a>CHeaderCtrl::CreateEx

Cria um controle (uma janela filho) `CHeaderCtrl` e associa-o ao objeto.

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
O estilo do controle de cabeçalho. Para obter uma descrição dos estilos de controle de cabeçalho, consulte Estilos de controle de [cabeçalho](/windows/win32/Controls/header-control-styles) no SDK do Windows. Consulte [Criar](#create) para obter uma lista de estilos adicionais.

*Rect*<br/>
Uma referência a uma estrutura [RECT](/windows/win32/api/windef/ns-windef-rect) descrevendo o tamanho e a posição da janela a ser criada, em coordenadas de cliente de *pParentWnd*.

*Pparentwnd*<br/>
Um ponteiro para a janela que é o pai do controle.

*nID*<br/>
A id da janela infantil do controle.

### <a name="return-value"></a>Valor retornado

Não zero se bem sucedido; caso contrário, 0.

### <a name="remarks"></a>Comentários

Use `CreateEx` em `Create` vez de aplicar estilos estendidos do Windows, especificados pelo prefácio de estilo estendido do Windows **WS_EX_**.

## <a name="cheaderctrlcreatedragimage"></a><a name="createdragimage"></a>CHeaderCtrl::CreateDragImage

Cria uma versão transparente da imagem de um item dentro de um controle de cabeçalho.

```
CImageList* CreateDragImage(int nIndex);
```

### <a name="parameters"></a>Parâmetros

*nIndex*<br/>
O índice baseado em zero do item dentro do controle de cabeçalho. A imagem atribuída a este item é a base para a imagem transparente.

### <a name="return-value"></a>Valor retornado

Um ponteiro para um objeto [CImageList](../../mfc/reference/cimagelist-class.md) se for bem sucedido; caso contrário, NULL. A lista retornada contém apenas uma imagem.

### <a name="remarks"></a>Comentários

Esta função de membro implementa o comportamento da [mensagem](/windows/win32/Controls/hdm-createdragimage)Win32 HDM_CREATEDRAGIMAGE , conforme descrito no SDK do Windows. Ele é fornecido para suportar arrastar e soltar o item do cabeçalho.

O `CImageList` objeto para o qual o ponteiro retornado aponta é um objeto temporário e é excluído no próximo processamento de tempo ocioso.

## <a name="cheaderctrldeleteitem"></a><a name="deleteitem"></a>CHeaderCtrl::DeleteItem

Exclui um item de um controle de cabeçalho.

```
BOOL DeleteItem(int nPos);
```

### <a name="parameters"></a>Parâmetros

*Npos*<br/>
Especifica o índice baseado em zero do item a ser excluído.

### <a name="return-value"></a>Valor retornado

Não zero se bem sucedido; caso contrário, 0.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFC_CHeaderCtrl#5](../../mfc/reference/codesnippet/cpp/cheaderctrl-class_5.cpp)]

## <a name="cheaderctrldrawitem"></a><a name="drawitem"></a>CHeaderCtrl::DrawItem

Chamado pela estrutura quando um aspecto visual de um controle de cabeçalho de desenho do proprietário muda.

```
virtual void DrawItem(LPDRAWITEMSTRUCT lpDrawItemStruct);
```

### <a name="parameters"></a>Parâmetros

*Lpdrawitemstruct*<br/>
Um ponteiro para uma estrutura [DRAWITEMSTRUCT](/windows/win32/api/winuser/ns-winuser-drawitemstruct) descrevendo o item a ser pintado.

### <a name="remarks"></a>Comentários

O `itemAction` membro `DRAWITEMSTRUCT` da estrutura define a ação de desenho a ser realizada.

Por padrão, esta função de membro não faz nada. Substituir esta função de membro para implementar `CHeaderCtrl` o desenho para um objeto de desenho do proprietário.

O aplicativo deve restaurar todos os objetos GDI (Graphics Device Interface, interface de dispositivo gráfico) selecionados para o contexto de exibição fornecido no *lpDrawItemStruct* antes que essa função de membro seja encerrada.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFC_CHeaderCtrl#6](../../mfc/reference/codesnippet/cpp/cheaderctrl-class_6.cpp)]

## <a name="cheaderctrleditfilter"></a><a name="editfilter"></a>CHeaderCtrl::EditFilter

Começa a editar o filtro especificado de um controle de cabeçalho.

```
BOOL EditFilter(
    int nColumn,
    BOOL bDiscardChanges);
```

### <a name="parameters"></a>Parâmetros

*nColuna*<br/>
A coluna para editar.

*bDescarteChanges*<br/>
Um valor que especifica como lidar com as alterações de edição do usuário se o usuário estiver no processo de editar o filtro quando a [mensagem HDM_EDITFILTER](/windows/win32/Controls/hdm-editfilter) for enviada.

Especifique TRUE para descartar as alterações feitas pelo usuário ou FALSE para aceitar as alterações feitas pelo usuário.

### <a name="return-value"></a>Valor retornado

VERDADE se este método for bem sucedido; caso contrário, FALSE.

### <a name="remarks"></a>Comentários

Este método implementa o comportamento da [mensagem](/windows/win32/Controls/hdm-editfilter)Win32 HDM_EDITFILTER , conforme descrito no SDK do Windows.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFC_CHeaderCtrl#7](../../mfc/reference/codesnippet/cpp/cheaderctrl-class_7.cpp)]

## <a name="cheaderctrlgetbitmapmargin"></a><a name="getbitmapmargin"></a>CHeaderCtrl::GetBitmapMargin

Recupera a largura da margem de um bitmap em um controle de cabeçalho.

```
int GetBitmapMargin() const;
```

### <a name="return-value"></a>Valor retornado

A largura da margem bitmap em pixels.

### <a name="remarks"></a>Comentários

Esta função de membro implementa o comportamento da [HDM_GETBITMAPMARGIN](/windows/win32/Controls/hdm-getbitmapmargin)de mensagem Win32 , conforme descrito no SDK do Windows.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFC_CHeaderCtrl#8](../../mfc/reference/codesnippet/cpp/cheaderctrl-class_8.cpp)]

## <a name="cheaderctrlgetfocuseditem"></a><a name="getfocuseditem"></a>CHeaderCtrl::GetFocusedItem

Obtém o índice do item que tem o foco no controle de cabeçalho atual.

```
int GetFocusedItem() const;
```

### <a name="return-value"></a>Valor retornado

O índice baseado em zero do item de cabeçalho que tem o foco.

### <a name="remarks"></a>Comentários

Este método envia a mensagem [HDM_GETFOCUSEDITEM,](/windows/win32/Controls/hdm-getfocuseditem) que é descrita no SDK do Windows.

### <a name="example"></a>Exemplo

O exemplo de código a `m_headerCtrl`seguir define a variável, que é usada para acessar o controle de cabeçalho atual. Esta variável é usada no próximo exemplo.

[!code-cpp[NVC_MFC_CHeaderCtrl_s4#6](../../mfc/reference/codesnippet/cpp/cheaderctrl-class_9.h)]

### <a name="example"></a>Exemplo

O exemplo de `SetFocusedItem` código `GetFocusedItem` a seguir demonstra os métodos e métodos. Em uma seção anterior do código, criamos um controle de cabeçalho com cinco colunas. No entanto, você pode arrastar um separador de coluna para que a coluna não fique visível. O exemplo a seguir define e confirma o último cabeçalho da coluna como item de foco.

[!code-cpp[NVC_MFC_CHeaderCtrl_s4#4](../../mfc/reference/codesnippet/cpp/cheaderctrl-class_10.cpp)]

## <a name="cheaderctrlgetimagelist"></a><a name="getimagelist"></a>CHeaderCtrl::GetImageList

Recupera a alça de uma lista de imagens usada para desenhar itens de cabeçalho em um controle de cabeçalho.

```
CImageList* GetImageList() const;
```

### <a name="return-value"></a>Valor retornado

Um ponteiro para um objeto [CImageList.](../../mfc/reference/cimagelist-class.md)

### <a name="remarks"></a>Comentários

Esta função de membro implementa o comportamento da [HDM_GETIMAGELIST](/windows/win32/Controls/hdm-getimagelist)de mensagem Win32 , conforme descrito no SDK do Windows. O `CImageList` objeto para o qual o ponteiro retornado aponta é um objeto temporário e é excluído no próximo processamento de tempo ocioso.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFC_CHeaderCtrl#9](../../mfc/reference/codesnippet/cpp/cheaderctrl-class_11.cpp)]

## <a name="cheaderctrlgetitem"></a><a name="getitem"></a>CHeaderCtrl::GetItem

Recupera informações sobre um item de controle de cabeçalho.

```
BOOL GetItem(
    int nPos,
    HDITEM* pHeaderItem) const;
```

### <a name="parameters"></a>Parâmetros

*Npos*<br/>
Especifica o índice baseado em zero do item a ser recuperado.

*pHeaderItem*<br/>
Pointer para uma estrutura [HDITEM](/windows/win32/api/commctrl/ns-commctrl-hditemw) que recebe o novo item. Esta estrutura é `InsertItem` usada `SetItem` com as funções e membros. Quaisquer sinalizadores `mask` definidos no elemento garantem que os valores nos elementos correspondentes sejam preenchidos corretamente no retorno. Se `mask` o elemento é definido como zero, os valores nos outros elementos estruturais são insignificantes.

### <a name="return-value"></a>Valor retornado

Não zero se bem sucedido; caso contrário, 0.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFC_CHeaderCtrl#10](../../mfc/reference/codesnippet/cpp/cheaderctrl-class_12.cpp)]

## <a name="cheaderctrlgetitemcount"></a><a name="getitemcount"></a>CHeaderCtrl::GetItemCount

Recupera uma contagem dos itens em um controle de cabeçalho.

```
int GetItemCount() const;
```

### <a name="return-value"></a>Valor retornado

Número de itens de controle de cabeçalho se bem sucedido; caso contrário - 1.

### <a name="example"></a>Exemplo

  Veja o exemplo de [CHeaderCtrl::DeleteItem](#deleteitem).

## <a name="cheaderctrlgetitemdropdownrect"></a><a name="getitemdropdownrect"></a>CHeaderCtrl::GetItemDropDownRect

Obtém o retângulo delimitador do botão de saque para um item de cabeçalho no controle de cabeçalho atual.

```
BOOL GetItemDropDownRect(
    int iItem,
    LPRECT lpRect) const;
```

### <a name="parameters"></a>Parâmetros

|Parâmetro|Descrição|
|---------------|-----------------|
|*Iitem*|[em] Índice baseado em zero de um item de cabeçalho cujo estilo é HDF_SPLITBUTTON. Para obter mais `fmt` informações, consulte o membro da estrutura [HDITEM.](/windows/win32/api/commctrl/ns-commctrl-hditemw)|
|*Lprect*|[fora] Ponteiro para uma estrutura [RECT](/windows/win32/api/windef/ns-windef-rect) para receber as informações delimitadordo do retângulo.|

### <a name="return-value"></a>Valor retornado

TRUE se esta função for bem sucedida; caso contrário, FALSE.

### <a name="remarks"></a>Comentários

Este método envia a [mensagem HDM_GETITEMDROPDOWNRECT,](/windows/win32/Controls/hdm-getitemdropdownrect) que é descrita no SDK do Windows.

### <a name="example"></a>Exemplo

O exemplo de código a `m_headerCtrl`seguir define a variável, que é usada para acessar o controle de cabeçalho atual. Esta variável é usada no próximo exemplo.

[!code-cpp[NVC_MFC_CHeaderCtrl_s4#6](../../mfc/reference/codesnippet/cpp/cheaderctrl-class_9.h)]

### <a name="example"></a>Exemplo

O exemplo de `GetItemDropDownRect` código a seguir demonstra o método. Em uma seção anterior do código, criamos um controle de cabeçalho com cinco colunas. O exemplo de código a seguir desenha um retângulo 3D em torno do local na primeira coluna que é reservada para o botão de usuário do cabeçalho.

[!code-cpp[NVC_MFC_CHeaderCtrl_s4#2](../../mfc/reference/codesnippet/cpp/cheaderctrl-class_13.cpp)]

## <a name="cheaderctrlgetitemrect"></a><a name="getitemrect"></a>CHeaderCtrl::GetItemRect

Recupera o retângulo delimitador para um determinado item em um controle de cabeçalho.

```
BOOL GetItemRect(
    int nIndex,
    LPRECT lpRect) const;
```

### <a name="parameters"></a>Parâmetros

*nIndex*<br/>
O índice baseado em zero do item de controle de cabeçalho.

*Lprect*<br/>
Um ponteiro para o endereço de uma estrutura [RECT](/windows/win32/api/windef/ns-windef-rect) que recebe as informações delimitadordo do retângulo.

### <a name="return-value"></a>Valor retornado

Não zero se bem sucedido; caso contrário, 0.

### <a name="remarks"></a>Comentários

Este método implementa o comportamento da [mensagem](/windows/win32/Controls/hdm-getitemrect)Win32 HDM_GETITEMRECT , conforme descrito no SDK do Windows.

## <a name="cheaderctrlgetorderarray"></a><a name="getorderarray"></a>CHeaderCtrl::GetOrderArray

Recupera a ordem da esquerda para a direita dos itens em um controle de cabeçalho.

```
BOOL GetOrderArray(
    LPINT piArray,
    int iCount);
```

### <a name="parameters"></a>Parâmetros

*piArray*<br/>
Um ponteiro para o endereço de um buffer que recebe os valores de índice dos itens no controle de cabeçalho, na ordem em que eles aparecem da esquerda para a direita.

*iCount*<br/>
O número de itens de controle de cabeçalho. Deve ser não negativo.

### <a name="return-value"></a>Valor retornado

Não zero se bem sucedido; caso contrário, 0.

### <a name="remarks"></a>Comentários

Esta função de membro implementa o comportamento da [HDM_GETORDERARRAY](/windows/win32/Controls/hdm-getorderarray)de mensagem Win32 , conforme descrito no SDK do Windows. Ele é fornecido para suportar o pedido de itens de cabeçalho.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFC_CHeaderCtrl#11](../../mfc/reference/codesnippet/cpp/cheaderctrl-class_14.cpp)]

## <a name="cheaderctrlgetoverflowrect"></a><a name="getoverflowrect"></a>CHeaderCtrl::GetOverflowRect

Obtém o retângulo delimitador do botão de estouro do controle de cabeçalho atual.

```
BOOL GetOverflowRect(LPRECT lpRect) const;
```

### <a name="parameters"></a>Parâmetros

|Parâmetro|Descrição|
|---------------|-----------------|
|*Lprect*|[fora] Ponteiro para uma estrutura [RECT](/windows/win32/api/windef/ns-windef-rect) que recebe as informações delimitadordo do retângulo.|

### <a name="return-value"></a>Valor retornado

TRUE se esta função for bem sucedida; caso contrário, FALSE.

### <a name="remarks"></a>Comentários

Se o controle de cabeçalho contiver mais itens do que pode ser exibido simultaneamente, o controle pode exibir um botão de estouro que rola para itens que não são visíveis. O controle de cabeçalho deve ter os estilos HDS_OVERFLOW e HDF_SPLITBUTTON para exibir o botão de estouro. O retângulo delimitador inclui o botão de estouro e só existe quando o botão de estouro é exibido. Para obter mais informações, consulte [Estilos de controle de cabeçalho](/windows/win32/Controls/header-control-styles).

Este método envia a mensagem [HDM_GETOVERFLOWRECT,](/windows/win32/Controls/hdm-getoverflowrect) que é descrita no SDK do Windows.

### <a name="example"></a>Exemplo

O exemplo de código a `m_headerCtrl`seguir define a variável, que é usada para acessar o controle de cabeçalho atual. Esta variável é usada no próximo exemplo.

[!code-cpp[NVC_MFC_CHeaderCtrl_s4#6](../../mfc/reference/codesnippet/cpp/cheaderctrl-class_9.h)]

### <a name="example"></a>Exemplo

O exemplo de `GetOverflowRect` código a seguir demonstra o método. Em uma seção anterior do código, criamos um controle de cabeçalho com cinco colunas. No entanto, você pode arrastar um separador de coluna para que a coluna não fique visível. Se algumas colunas não estiverem visíveis, o controle de cabeçalho desenha um botão de estouro. O exemplo de código a seguir desenha um retângulo 3D em torno da localização do botão de estouro.

[!code-cpp[NVC_MFC_CHeaderCtrl_s4#3](../../mfc/reference/codesnippet/cpp/cheaderctrl-class_15.cpp)]

## <a name="cheaderctrlhittest"></a><a name="hittest"></a>CHeaderCtrl::HitTest

Determina qual item de cabeçalho, se houver, está localizado em um ponto especificado.

```
int HitTest(LPHDHITTESTINFO* phdhti);
```

### <a name="parameters"></a>Parâmetros

|Parâmetro|Descrição|
|---------------|-----------------|
|*phdhti*|[dentro, fora] Pointer para uma estrutura [HDHITTESTINFO](/windows/win32/api/commctrl/ns-commctrl-hdhittestinfo) que especifica o ponto para testar e recebe os resultados do teste.|

### <a name="return-value"></a>Valor retornado

O índice baseado em zero do item cabeçalho, se houver, na posição especificada; caso contrário, -1.

### <a name="remarks"></a>Comentários

Este método envia a mensagem [HDM_HITTEST,](/windows/win32/Controls/hdm-hittest) que é descrita no SDK do Windows.

### <a name="example"></a>Exemplo

O exemplo de código a `m_headerCtrl`seguir define a variável, que é usada para acessar o controle de cabeçalho atual. Esta variável é usada no próximo exemplo.

[!code-cpp[NVC_MFC_CHeaderCtrl_s4#6](../../mfc/reference/codesnippet/cpp/cheaderctrl-class_9.h)]

### <a name="example"></a>Exemplo

O exemplo de `HitTest` código a seguir demonstra o método. Em uma seção anterior deste exemplo de código, criamos um controle de cabeçalho com cinco colunas. No entanto, você pode arrastar um separador de coluna para que a coluna não fique visível. Este exemplo informa o índice da coluna se ela estiver visível e -1 se a coluna não estiver visível.

[!code-cpp[NVC_MFC_CHeaderCtrl_s4#1](../../mfc/reference/codesnippet/cpp/cheaderctrl-class_16.cpp)]

## <a name="cheaderctrlinsertitem"></a><a name="insertitem"></a>CHeaderCtrl::InsertItem

Insere um novo item em um controle de cabeçalho no índice especificado.

```
int InsertItem(
    int nPos,
    HDITEM* phdi);
```

### <a name="parameters"></a>Parâmetros

*Npos*<br/>
O índice de base zero do item a ser inserido. Se o valor for zero, o item será inserido no início do controle do cabeçalho. Se o valor for maior que o valor máximo, o item será inserido no final do controle do cabeçalho.

*phdi*<br/>
Ponteiro para uma estrutura [HDITEM](/windows/win32/api/commctrl/ns-commctrl-hditemw) que contém informações sobre o item a ser inserido.

### <a name="return-value"></a>Valor retornado

Índice do novo item se bem sucedido; caso contrário - 1.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFC_CHeaderCtrl#12](../../mfc/reference/codesnippet/cpp/cheaderctrl-class_17.cpp)]

## <a name="cheaderctrllayout"></a><a name="layout"></a>CHeaderCtrl::Layout

Recupera o tamanho e a posição de um controle de cabeçalho dentro de um determinado retângulo.

```
BOOL Layout(HDLAYOUT* pHeaderLayout);
```

### <a name="parameters"></a>Parâmetros

*pHeaderLayout*<br/>
Ponteiro para uma estrutura [HDLAYOUT,](/windows/win32/api/commctrl/ns-commctrl-hdlayout) que contém informações usadas para definir o tamanho e a posição de um controle de cabeçalho.

### <a name="return-value"></a>Valor retornado

Não zero se bem sucedido; caso contrário, 0.

### <a name="remarks"></a>Comentários

Esta função é usada para determinar as dimensões apropriadas para um novo controle de cabeçalho que deve ocupar o retângulo dado.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFC_CHeaderCtrl#13](../../mfc/reference/codesnippet/cpp/cheaderctrl-class_18.cpp)]

## <a name="cheaderctrlordertoindex"></a><a name="ordertoindex"></a>CHeaderCtrl::OrderToIndex

Recupera o valor do índice de um item com base em sua ordem no controle de cabeçalho.

```
int OrderToIndex(int nOrder) const;
```

### <a name="parameters"></a>Parâmetros

*nOrdem*<br/>
A ordem baseada em zero que o item aparece no controle de cabeçalho, da esquerda para a direita.

### <a name="return-value"></a>Valor retornado

O índice do item, com base em sua ordem no controle de cabeçalho. O índice conta da esquerda para a direita, começando com 0.

### <a name="remarks"></a>Comentários

Esta função de membro implementa o comportamento da [HDM_ORDERTOINDEX](/windows/win32/controls/hdm-ordertoindex)macro Win32 , conforme descrito no SDK do Windows. Ele é fornecido para suportar o pedido de itens de cabeçalho.

## <a name="cheaderctrlsetbitmapmargin"></a><a name="setbitmapmargin"></a>CHeaderCtrl::SetBitmapMargin

Define a largura da margem de um bitmap em um controle de cabeçalho.

```
int SetBitmapMargin(int nWidth);
```

### <a name="parameters"></a>Parâmetros

*Nwidth*<br/>
Largura, especificada em pixels, da margem que envolve um bitmap dentro de um controle de cabeçalho existente.

### <a name="return-value"></a>Valor retornado

A largura da margem bitmap em pixels.

### <a name="remarks"></a>Comentários

Esta função de membro implementa o comportamento da [mensagem](/windows/win32/Controls/hdm-setbitmapmargin)Win32 HDM_SETBITMAPMARGIN , conforme descrito no SDK do Windows.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFC_CHeaderCtrl#14](../../mfc/reference/codesnippet/cpp/cheaderctrl-class_19.cpp)]

## <a name="cheaderctrlsetfilterchangetimeout"></a><a name="setfilterchangetimeout"></a>CHeaderCtrl::SetFilterChangeTimeout

Define o intervalo de tempo entre o tempo em que uma alteração ocorre nos atributos do filtro e a publicação de uma notificação [HDN_FILTERCHANGE.](/windows/win32/Controls/hdn-filterchange)

```
int SetFilterChangeTimeout(DWORD dwTimeOut);
```

### <a name="parameters"></a>Parâmetros

*Dwtimeout*<br/>
Valor de tempo, em milissegundos.

### <a name="return-value"></a>Valor retornado

O índice do controle do filtro sendo modificado.

### <a name="remarks"></a>Comentários

Esta função de membro implementa o comportamento da [HDM_SETFILTERCHANGETIMEOUT](/windows/win32/Controls/hdm-setfilterchangetimeout)de mensagem Win32 , conforme descrito no SDK do Windows.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFC_CHeaderCtrl#15](../../mfc/reference/codesnippet/cpp/cheaderctrl-class_20.cpp)]

## <a name="cheaderctrlsetfocuseditem"></a><a name="setfocuseditem"></a>CHeaderCtrl::SetFocusedItem

Define o foco como um item de cabeçalho especificado no controle de cabeçalho atual.

```
BOOL SetFocusedItem(int iItem);
```

### <a name="parameters"></a>Parâmetros

|Parâmetro|Descrição|
|---------------|-----------------|
|*Iitem*|[em] Índice baseado em zero de um item de cabeçalho.|

### <a name="return-value"></a>Valor retornado

VERDADE se este método for bem sucedido; caso contrário, FALSE.

### <a name="remarks"></a>Comentários

Este método envia a mensagem [HDM_SETFOCUSEDITEM,](/windows/win32/Controls/hdm-setfocuseditem) que é descrita no SDK do Windows.

### <a name="example"></a>Exemplo

O exemplo de código a `m_headerCtrl`seguir define a variável, que é usada para acessar o controle de cabeçalho atual. Esta variável é usada no próximo exemplo.

[!code-cpp[NVC_MFC_CHeaderCtrl_s4#6](../../mfc/reference/codesnippet/cpp/cheaderctrl-class_9.h)]

### <a name="example"></a>Exemplo

O exemplo de `SetFocusedItem` código `GetFocusedItem` a seguir demonstra os métodos e métodos. Em uma seção anterior do código, criamos um controle de cabeçalho com cinco colunas. No entanto, você pode arrastar um separador de coluna para que a coluna não fique visível. O exemplo a seguir define e confirma o último cabeçalho da coluna como item de foco.

[!code-cpp[NVC_MFC_CHeaderCtrl_s4#4](../../mfc/reference/codesnippet/cpp/cheaderctrl-class_10.cpp)]

## <a name="cheaderctrlsethotdivider"></a><a name="sethotdivider"></a>CHeaderCtrl::SetHotDivider

Altera o divisor entre itens de cabeçalho para indicar um arrasto manual e queda de um item de cabeçalho.

```
int SetHotDivider(CPoint pt);
int SetHotDivider(int nIndex);
```

### <a name="parameters"></a>Parâmetros

*pt*<br/>
A posição do ponteiro. O controle de cabeçalho destaca o divisor apropriado com base na posição do ponteiro.

*nIndex*<br/>
O índice do divisor destacado.

### <a name="return-value"></a>Valor retornado

O índice do divisor destacado.

### <a name="remarks"></a>Comentários

Esta função de membro implementa o comportamento da [HDM_SETHOTDIVIDER](/windows/win32/Controls/hdm-sethotdivider)de mensagem Win32 , conforme descrito no SDK do Windows. Ele é fornecido para suportar arrastar e soltar o item do cabeçalho.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFC_CHeaderCtrl#16](../../mfc/reference/codesnippet/cpp/cheaderctrl-class_21.cpp)]

## <a name="cheaderctrlsetimagelist"></a><a name="setimagelist"></a>CHeaderCtrl::SetImageList

Atribui uma lista de imagens a um controle de cabeçalho.

```
CImageList* SetImageList(CImageList* pImageList);
```

### <a name="parameters"></a>Parâmetros

*pImageList*<br/>
Um ponteiro `CImageList` para um objeto que contém a lista de imagens a ser atribuído ao controle de cabeçalho.

### <a name="return-value"></a>Valor retornado

Um ponteiro para o objeto [CImageList](../../mfc/reference/cimagelist-class.md) previamente atribuído ao controle de cabeçalho.

### <a name="remarks"></a>Comentários

Esta função de membro implementa o comportamento da [HDM_SETIMAGELIST](/windows/win32/Controls/hdm-setimagelist)de mensagem Win32 , conforme descrito no SDK do Windows. O `CImageList` objeto para o qual o ponteiro retornado aponta é um objeto temporário e é excluído no próximo processamento de tempo ocioso.

### <a name="example"></a>Exemplo

  Veja o exemplo de [CHeaderCtrl::GetImageList](#getimagelist).

## <a name="cheaderctrlsetitem"></a><a name="setitem"></a>CHeaderCtrl::SetItem

Define os atributos do item especificado em um controle de cabeçalho.

```
BOOL SetItem(
    int nPos,
    HDITEM* pHeaderItem);
```

### <a name="parameters"></a>Parâmetros

*Npos*<br/>
O índice baseado em zero do item a ser manipulado.

*pHeaderItem*<br/>
Ponteiro para uma estrutura [HDITEM](/windows/win32/api/commctrl/ns-commctrl-hditemw) que contém informações sobre o novo item.

### <a name="return-value"></a>Valor retornado

Não zero se bem sucedido; caso contrário, 0.

### <a name="example"></a>Exemplo

  Veja o exemplo de [CHeaderCtrl::GetItem](#getitem).

## <a name="cheaderctrlsetorderarray"></a><a name="setorderarray"></a>CHeaderCtrl::SetOrderArray

Define a ordem da esquerda para a direita dos itens em um controle de cabeçalho.

```
BOOL SetOrderArray(
    int iCount,
    LPINT piArray);
```

### <a name="parameters"></a>Parâmetros

*iCount*<br/>
O número de itens de controle de cabeçalho.

*piArray*<br/>
Um ponteiro para o endereço de um buffer que recebe os valores de índice dos itens no controle de cabeçalho, na ordem em que eles aparecem da esquerda para a direita.

### <a name="return-value"></a>Valor retornado

Não zero se bem sucedido; caso contrário, 0.

### <a name="remarks"></a>Comentários

Esta função de membro implementa o comportamento do [HDM_SETORDERARRAY](/windows/win32/Controls/hdm-setorderarray)macro Win32 , conforme descrito no SDK do Windows. Ele é fornecido para suportar o pedido de itens de cabeçalho.

### <a name="example"></a>Exemplo

  Veja o exemplo de [CHeaderCtrl::GetOrderArray](#getorderarray).

## <a name="see-also"></a>Confira também

[Classe CWnd](../../mfc/reference/cwnd-class.md)<br/>
[Gráfico da hierarquia](../../mfc/hierarchy-chart.md)<br/>
[Classe CTabCtrl](../../mfc/reference/ctabctrl-class.md)<br/>
[Classe CListCtrl](../../mfc/reference/clistctrl-class.md)<br/>
[Classe CImageList](../../mfc/reference/cimagelist-class.md)
