---
title: Classe CListBox
description: Uma descrição da classe MFC CListBox e suas funções de membro.
ms.date: 01/22/2020
f1_keywords:
- CListBox
- AFXWIN/CListBox
- AFXWIN/CListBox::CListBox
- AFXWIN/CListBox::AddString
- AFXWIN/CListBox::CharToItem
- AFXWIN/CListBox::CompareItem
- AFXWIN/CListBox::Create
- AFXWIN/CListBox::DeleteItem
- AFXWIN/CListBox::DeleteString
- AFXWIN/CListBox::Dir
- AFXWIN/CListBox::DrawItem
- AFXWIN/CListBox::FindString
- AFXWIN/CListBox::FindStringExact
- AFXWIN/CListBox::GetAnchorIndex
- AFXWIN/CListBox::GetCaretIndex
- AFXWIN/CListBox::GetCount
- AFXWIN/CListBox::GetCurSel
- AFXWIN/CListBox::GetHorizontalExtent
- AFXWIN/CListBox::GetItemData
- AFXWIN/CListBox::GetItemDataPtr
- AFXWIN/CListBox::GetItemHeight
- AFXWIN/CListBox::GetItemRect
- AFXWIN/CListBox::GetListBoxInfo
- AFXWIN/CListBox::GetLocale
- AFXWIN/CListBox::GetSel
- AFXWIN/CListBox::GetSelCount
- AFXWIN/CListBox::GetSelItems
- AFXWIN/CListBox::GetText
- AFXWIN/CListBox::GetTextLen
- AFXWIN/CListBox::GetTopIndex
- AFXWIN/CListBox::InitStorage
- AFXWIN/CListBox::InsertString
- AFXWIN/CListBox::ItemFromPoint
- AFXWIN/CListBox::MeasureItem
- AFXWIN/CListBox::ResetContent
- AFXWIN/CListBox::SelectString
- AFXWIN/CListBox::SelItemRange
- AFXWIN/CListBox::SetAnchorIndex
- AFXWIN/CListBox::SetCaretIndex
- AFXWIN/CListBox::SetColumnWidth
- AFXWIN/CListBox::SetCurSel
- AFXWIN/CListBox::SetHorizontalExtent
- AFXWIN/CListBox::SetItemData
- AFXWIN/CListBox::SetItemDataPtr
- AFXWIN/CListBox::SetItemHeight
- AFXWIN/CListBox::SetLocale
- AFXWIN/CListBox::SetSel
- AFXWIN/CListBox::SetTabStops
- AFXWIN/CListBox::SetTopIndex
- AFXWIN/CListBox::VKeyToItem
helpviewer_keywords:
- CListBox [MFC], CListBox
- CListBox [MFC], AddString
- CListBox [MFC], CharToItem
- CListBox [MFC], CompareItem
- CListBox [MFC], Create
- CListBox [MFC], DeleteItem
- CListBox [MFC], DeleteString
- CListBox [MFC], Dir
- CListBox [MFC], DrawItem
- CListBox [MFC], FindString
- CListBox [MFC], FindStringExact
- CListBox [MFC], GetAnchorIndex
- CListBox [MFC], GetCaretIndex
- CListBox [MFC], GetCount
- CListBox [MFC], GetCurSel
- CListBox [MFC], GetHorizontalExtent
- CListBox [MFC], GetItemData
- CListBox [MFC], GetItemDataPtr
- CListBox [MFC], GetItemHeight
- CListBox [MFC], GetItemRect
- CListBox [MFC], GetListBoxInfo
- CListBox [MFC], GetLocale
- CListBox [MFC], GetSel
- CListBox [MFC], GetSelCount
- CListBox [MFC], GetSelItems
- CListBox [MFC], GetText
- CListBox [MFC], GetTextLen
- CListBox [MFC], GetTopIndex
- CListBox [MFC], InitStorage
- CListBox [MFC], InsertString
- CListBox [MFC], ItemFromPoint
- CListBox [MFC], MeasureItem
- CListBox [MFC], ResetContent
- CListBox [MFC], SelectString
- CListBox [MFC], SelItemRange
- CListBox [MFC], SetAnchorIndex
- CListBox [MFC], SetCaretIndex
- CListBox [MFC], SetColumnWidth
- CListBox [MFC], SetCurSel
- CListBox [MFC], SetHorizontalExtent
- CListBox [MFC], SetItemData
- CListBox [MFC], SetItemDataPtr
- CListBox [MFC], SetItemHeight
- CListBox [MFC], SetLocale
- CListBox [MFC], SetSel
- CListBox [MFC], SetTabStops
- CListBox [MFC], SetTopIndex
- CListBox [MFC], VKeyToItem
ms.assetid: 7ba3c699-c286-4cd9-9066-532c41ec05d1
ms.openlocfilehash: 171038ebaaed815aa687c200fe3210bde8000be3
ms.sourcegitcommit: 7a6116e48c3c11b97371b8ae4ecc23adce1f092d
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/22/2020
ms.locfileid: "81753582"
---
# <a name="clistbox-class"></a>Classe CListBox

Fornece a funcionalidade de uma caixa de lista do Windows.

## <a name="syntax"></a>Sintaxe

```
class CListBox : public CWnd
```

## <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores públicos

|Nome|Descrição|
|----------|-----------------|
|[Caixa de clist::CListBox](#clistbox)|Constrói um objeto `CListBox`.|

### <a name="public-methods"></a>Métodos públicos

|Nome|Descrição|
|----------|-----------------|
|[Caixa de lista de c::AddString](#addstring)|Adiciona uma seqüência a uma caixa de lista.|
|[CListBox::CharToItem](#chartoitem)|Substituir para fornecer WM_CHAR de manuseio personalizado para caixas de lista de sorteio de proprietários que não possuem strings.|
|[CListBox::CompareItem](#compareitem)|Chamado pela estrutura para determinar a posição de um novo item em uma caixa de lista de sorteio de proprietários ordenado.|
|[CListBox::Criar](#create)|Cria a caixa de lista do `CListBox` Windows e a anexa ao objeto.|
|[CListBox::DeleteItem](#deleteitem)|Chamado pela estrutura quando o usuário exclui um item de uma caixa de lista de sorteio do proprietário.|
|[CListBox::DeleteString](#deletestring)|Exclui uma seqüência de uma caixa de lista.|
|[CListBox::Dir](#dir)|Adiciona nomes de arquivos, drives ou ambos do diretório atual a uma caixa de lista.|
|[CListBox::DrawItem](#drawitem)|Chamado pela estrutura quando um aspecto visual de uma caixa de lista de sorteio do proprietário é alterado.|
|[Caixa de clist::Findstring](#findstring)|Procura uma seqüência em uma caixa de lista.|
|[Caixa de clist::FindstringExact](#findstringexact)|Encontra a primeira seqüência de caixa de lista que corresponde a uma seqüência especificada.|
|[CListBox::GetAnchorIndex](#getanchorindex)|Recupera o índice baseado em zero do item âncora atual em uma caixa de lista.|
|[CListBox::GetCaretIndex](#getcaretindex)|Determina o índice do item que tem o retângulo de foco em uma caixa de lista de várias seleções.|
|[CListBox::Contagem de contatos](#getcount)|Retorna o número de strings em uma caixa de lista.|
|[CListBox::GetCursel](#getcursel)|Retorna o índice baseado em zero da seqüência de string atualmente selecionada em uma caixa de lista.|
|[CListBox::getHorizontalExtent](#gethorizontalextent)|Retorna a largura em pixels que uma caixa de lista pode ser rolada horizontalmente.|
|[CListBox::GetItemData](#getitemdata)|Retorna um valor associado ao item lista-caixa.|
|[CListBox::GetItemDataPtr](#getitemdataptr)|Retorna um ponteiro para um item de caixa de lista.|
|[CListBox::GetItemHeight](#getitemheight)|Determina a altura dos itens em uma caixa de lista.|
|[CListBox::GetItemRect](#getitemrect)|Retorna o retângulo delimitador do item da caixa de lista como é exibido atualmente.|
|[CListBox::GetListBoxInfo](#getlistboxinfo)|Recupera o número de itens por coluna.|
|[CListBox::GetLocale](#getlocale)|Recupera o identificador local para uma caixa de lista.|
|[CListBox::GetSel](#getsel)|Retorna o estado de seleção de um item de caixa de lista.|
|[CListBox::GetSelCount](#getselcount)|Retorna o número de strings atualmente selecionados em uma caixa de lista de várias seleções.|
|[CListBox::GetSelItems](#getselitems)|Retorna os índices das strings atualmente selecionadas em uma caixa de lista.|
|[Caixa de clist::getText](#gettext)|Copia um item de caixa de lista em um buffer.|
|[CListBox::GetTextLen](#gettextlen)|Retorna o comprimento em bytes de um item de caixa de lista.|
|[CListBox::GetTopIndex](#gettopindex)|Retorna o índice da primeira seqüência visível em uma caixa de lista.|
|[CListBox:InitStorage](#initstorage)|Prealoca blocos de memória para itens de caixa de lista e strings.|
|[Caixa de clist::seqüência de inserção](#insertstring)|Insere uma seqüência em um local específico em uma caixa de lista.|
|[CListBox::ItemFromPoint](#itemfrompoint)|Retorna o índice do item lista-caixa mais próximo de um ponto.|
|[CListBox::MeasureItem](#measureitem)|Chamada pela framework quando uma caixa de lista de sorteio do proprietário é criada para determinar as dimensões da caixa de lista.|
|[CListBox::Redefinirconteúdo](#resetcontent)|Limpa todas as entradas de uma caixa de lista.|
|[CListBox::SelectString](#selectstring)|Pesquisa e seleciona uma seqüência em uma caixa de lista de seleção única.|
|[CListBox::SelItemRange](#selitemrange)|Seleciona ou desmarca uma série de strings em uma caixa de lista de várias seleções.|
|[CListBox::SetAnchorIndex](#setanchorindex)|Define a âncora em uma caixa de lista de seleção múltipla para iniciar uma seleção estendida.|
|[CListBox::SetCaretIndex](#setcaretindex)|Define o retângulo de foco para o item no índice especificado em uma caixa de lista de várias seleções.|
|[CListBox::SetColunaLarguradeserse](#setcolumnwidth)|Define a largura da coluna de uma caixa de lista de várias colunas.|
|[CListBox::SetCursel](#setcursel)|Seleciona uma seqüência de caixa de lista.|
|[CListBox::SetHorizontalExtent](#sethorizontalextent)|Define a largura em pixels que uma caixa de lista pode ser rolada horizontalmente.|
|[CListBox::SetItemData](#setitemdata)|Define um valor associado ao item lista-caixa.|
|[CListBox::SetItemDataPtr](#setitemdataptr)|Define um ponteiro para o item da caixa de lista.|
|[CListBox::SetItemHeight](#setitemheight)|Define a altura dos itens em uma caixa de lista.|
|[CListBox::SetLocale](#setlocale)|Define o identificador local para uma caixa de lista.|
|[CListBox::SetSel](#setsel)|Seleciona ou desmarca um item de caixa de lista em uma caixa de lista de várias seleções.|
|[CListBox::Set's'Sstops](#settabstops)|Define as posições de 'stop' em uma caixa de lista.|
|[CListBox::SetTopIndex](#settopindex)|Define o índice baseado em zero da primeira seqüência visível em uma caixa de lista.|
|[CListBox::VKeyToItem](#vkeytoitem)|Substituição para fornecer manuseamento de WM_KEYDOWN personalizado para caixas de lista com o conjunto de LBS_WANTKEYBOARDINPUT estilo.|

## <a name="remarks"></a>Comentários

Uma caixa de lista exibe uma lista de itens, como nomes de arquivos, que o usuário pode visualizar e selecionar.

Em uma caixa de lista de seleção única, o usuário pode selecionar apenas um item. Em uma caixa de lista de várias seleções, uma série de itens pode ser selecionada. Quando o usuário seleciona um item, ele é destacado e a caixa de lista envia uma mensagem de notificação para a janela pai.

Você pode criar uma caixa de lista a partir de um modelo de diálogo ou diretamente em seu código. Para criá-lo `CListBox` diretamente, construa o objeto e, em seguida, chame a `CListBox` função [Criar](#create) membro para criar o controle de caixa de lista do Windows e anexá-lo ao objeto. Para usar uma caixa de lista em um modelo de diálogo, declare `DDX_Control` uma variável de `DoDataExchange` caixa de lista na classe da caixa de diálogo e use na função da classe caixa de diálogo para conectar a variável membro ao controle. (isso é feito para você automaticamente quando você adiciona uma variável de controle à sua classe caixa de diálogo.)

A construção pode ser um processo de `CListBox`uma etapa em uma classe derivada de . Escreva um construtor para a classe `Create` derivada e ligue de dentro do construtor.

Se você quiser lidar com mensagens de notificação do Windows enviadas por uma caixa de lista para seu pai (geralmente uma classe derivada do [CDialog),](../../mfc/reference/cdialog-class.md)adicione uma função de membro do mapa de mensagem e do manipulador de mensagens à classe pai para cada mensagem.

Cada entrada de mapa de mensagem tem o seguinte formulário:

`ON_Notification( id, memberFxn )`

onde `id` especifica o ID da janela filho do controle `memberFxn` da caixa de lista que envia a notificação e é o nome da função de membro pai que você escreveu para lidar com a notificação.

O protótipo de função dos pais é o seguinte:

`afx_msg void memberFxn( );`

A seguir está uma lista de possíveis entradas de mapa de mensagens e uma descrição dos casos em que seriam enviadas ao pai:

- ON_LBN_DBLCLK O usuário clica duas vezes em uma seqüência em uma caixa de lista. Apenas uma caixa de lista que tenha o [estilo LBS_NOTIFY](../../mfc/reference/styles-used-by-mfc.md#list-box-styles) enviará esta mensagem de notificação.

- ON_LBN_ERRSPACE A caixa de lista não pode alocar memória suficiente para atender à solicitação.

- ON_LBN_KILLFOCUS A caixa de lista está perdendo o foco de entrada.

- ON_LBN_SELCANCEL A seleção atual da caixa de lista é cancelada. Esta mensagem só é enviada quando uma caixa de lista tem o estilo LBS_NOTIFY.

- ON_LBN_SELCHANGE A seleção na caixa de lista mudou. Esta notificação não será enviada se a seleção for alterada pela função [membro CListBox::SetCurSel.](#setcursel) Esta notificação se aplica apenas a uma caixa de lista que tenha o estilo LBS_NOTIFY. A mensagem de notificação LBN_SELCHANGE é enviada para uma caixa de lista de várias seleções sempre que o usuário pressiona uma tecla de seta, mesmo que a seleção não mude.

- ON_LBN_SETFOCUS A caixa de lista está recebendo o foco de entrada.

- ON_WM_CHARTOITEM Uma caixa de lista de sorteio do proprietário que não tem strings recebe uma mensagem WM_CHAR.

- ON_WM_VKEYTOITEM Uma caixa de lista com o estilo LBS_WANTKEYBOARDINPUT recebe uma mensagem WM_KEYDOWN.

Se você `CListBox` criar um objeto dentro de uma `CListBox` caixa de diálogo (através de um recurso de diálogo), o objeto será automaticamente destruído quando o usuário fechar a caixa de diálogo.

Se você `CListBox` criar um objeto dentro de uma `CListBox` janela, talvez seja necessário destruir o objeto. Se você `CListBox` criar o objeto na pilha, ele será destruído automaticamente. Se você `CListBox` criar o objeto no heap usando a **nova** função, você deve chamar **excluir** no objeto para destruí-lo quando o usuário fechar a janela pai.

Se você alocar `CListBox` qualquer memória no `CListBox` objeto, anule o destruidor para descartar a alocação.

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

[Cobject](../../mfc/reference/cobject-class.md)

[Ccmdtarget](../../mfc/reference/ccmdtarget-class.md)

[CWnd](../../mfc/reference/cwnd-class.md)

`CListBox`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** afxwin.h

## <a name="clistboxaddstring"></a><a name="addstring"></a>Caixa de lista de c::AddString

Adiciona uma seqüência a uma caixa de lista.

```
int AddString(LPCTSTR lpszItem);
```

### <a name="parameters"></a>Parâmetros

*Lpszitem*<br/>
Aponta para a seqüência de terminadas nula que deve ser adicionada.

### <a name="return-value"></a>Valor retornado

O índice baseado em zero para a seqüência na caixa de lista. O valor de retorno é LB_ERR se ocorrer um erro; o valor de retorno é LB_ERRSPACE se houver espaço insuficiente para armazenar a nova seqüência.

### <a name="remarks"></a>Comentários

Se a caixa de lista não foi criada com o estilo [LBS_SORT,](../../mfc/reference/styles-used-by-mfc.md#list-box-styles) a seqüência será adicionada ao final da lista. Caso contrário, a seqüência é inserida na lista, e a lista é classificada. Se a caixa de lista foi criada com o estilo LBS_SORT, mas não com `CompareItem` o estilo [LBS_HASSTRINGS,](../../mfc/reference/styles-used-by-mfc.md#list-box-styles) a estrutura classifica a lista por uma ou mais chamadas para a função de membro.

Use [InsertString](#insertstring) para inserir uma string em um local específico dentro da caixa de lista.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFC_CListBox#3](../../mfc/codesnippet/cpp/clistbox-class_1.cpp)]

## <a name="clistboxchartoitem"></a><a name="chartoitem"></a>CListBox::CharToItem

Chamada pela estrutura quando a janela pai da caixa de lista recebe uma mensagem WM_CHARTOITEM da caixa de lista.

```
virtual int CharToItem(
    UINT nKey,
    UINT nIndex);
```

### <a name="parameters"></a>Parâmetros

*nKey*<br/>
O código ANSI do caractere que o usuário digitou.

*nIndex*<br/>
A posição atual do caret da caixa de lista.

### <a name="return-value"></a>Valor retornado

Retorna - 1 ou - 2 para nenhuma ação adicional ou um número não negativo para especificar um índice de um item de caixa de lista no qual executar a ação padrão para o pressionamento da tecla. A implementação padrão retorna - 1.

### <a name="remarks"></a>Comentários

A mensagem WM_CHARTOITEM é enviada pela caixa de lista quando recebe uma mensagem WM_CHAR, mas somente se a caixa de lista atender a todos esses critérios:

- É uma caixa de lista de sorteio sumido.

- Não tem o [LBS_HASSTRINGS](../../mfc/reference/styles-used-by-mfc.md#list-box-styles) conjunto de estilo.

- Tem pelo menos um item.

Você nunca deve chamar isso de função você mesmo. Anular esta função para fornecer seu próprio manuseio personalizado de mensagens de teclado.

Em sua substituição, você deve retornar um valor para dizer à estrutura qual ação você realizou. Um valor de retorno de - 1 ou - 2 indica que você lidou com todos os aspectos da seleção do item e não requer nenhuma ação adicional pela caixa de lista. Antes de retornar - 1 ou - 2, você pode definir a seleção ou mover o caret ou ambos. Para definir a seleção, use [SetCurSel](#setcursel) ou [SetSel](#setsel). Para mover o cuidado, use [SetCaretIndex](#setcaretindex).

Um valor de retorno de 0 ou mais especifica o índice de um item na caixa de lista e indica que a caixa de lista deve executar a ação padrão para o pressionamento da tecla no item dado.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFC_CListBox#4](../../mfc/codesnippet/cpp/clistbox-class_2.cpp)]

## <a name="clistboxclistbox"></a><a name="clistbox"></a>Caixa de clist::CListBox

Constrói um objeto `CListBox`.

```
CListBox();
```

### <a name="remarks"></a>Comentários

Você constrói `CListBox` um objeto em dois passos. Primeiro, ligue para `ClistBox` o `Create`construtor e depois ligue, que inicializa a `CListBox`caixa de lista do Windows e a anexa à .

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFC_CListBox#1](../../mfc/codesnippet/cpp/clistbox-class_3.cpp)]

## <a name="clistboxcompareitem"></a><a name="compareitem"></a>CListBox::CompareItem

Chamado pela estrutura para determinar a posição relativa de um novo item em uma caixa de lista de sorteio de proprietários ordenado.

```
virtual int CompareItem(LPCOMPAREITEMSTRUCT lpCompareItemStruct);
```

### <a name="parameters"></a>Parâmetros

*lpCompareItemStruct*<br/>
Um longo ponteiro `COMPAREITEMSTRUCT` para uma estrutura.

### <a name="return-value"></a>Valor retornado

Indica a posição relativa dos dois itens descritos na estrutura [COMPAREITEMSTRUCT.](/windows/win32/api/winuser/ns-winuser-compareitemstruct) Pode ser qualquer um dos seguintes valores:

|Valor|Significado|
|-----------|-------------|
|-1|Item 1 classificaantes do item 2.|
|0|O item 1 e o item 2 classificam o mesmo.|
|1|Item 1 classifica após o item 2.|

Consulte [CWnd::OnCompareItem](../../mfc/reference/cwnd-class.md#oncompareitem) para obter `COMPAREITEMSTRUCT` uma descrição da estrutura.

### <a name="remarks"></a>Comentários

Por padrão, esta função de membro não faz nada. Se você criar uma caixa de lista de sorteio do proprietário com o estilo LBS_SORT, você deve substituir essa função de membro para ajudar a estrutura na classificação de novos itens adicionados à caixa de lista.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFC_CListBox#5](../../mfc/codesnippet/cpp/clistbox-class_4.cpp)]

## <a name="clistboxcreate"></a><a name="create"></a>CListBox::Criar

Cria a caixa de lista do `CListBox` Windows e a anexa ao objeto.

```
virtual BOOL Create(
    DWORD dwStyle,
    const RECT& rect,
    CWnd* pParentWnd,
    UINT nID);
```

### <a name="parameters"></a>Parâmetros

*Dwstyle*<br/>
Especifica o estilo da caixa de lista. Aplique qualquer combinação de [estilos de caixa de lista](../../mfc/reference/styles-used-by-mfc.md#list-box-styles) na caixa.

*Rect*<br/>
Especifica o tamanho e a posição da caixa de lista. Pode ser `CRect` um objeto `RECT` ou uma estrutura.

*Pparentwnd*<br/>
Especifica a janela pai da caixa `CDialog` de lista (geralmente um objeto). Não deve ser NULO.

*nID*<br/>
Especifica o ID de controle da caixa de lista.

### <a name="return-value"></a>Valor retornado

Não zero se bem sucedido; caso contrário, 0.

### <a name="remarks"></a>Comentários

Você constrói `CListBox` um objeto em dois passos. Primeiro, ligue para o `Create`construtor e, em seguida, ligue, que `CListBox` inicializa a caixa de lista do Windows e a anexa ao objeto.

Quando `Create` é executado, o Windows envia as [mensagens WM_NCCREATE,](../../mfc/reference/cwnd-class.md#onnccreate) [WM_CREATE](../../mfc/reference/cwnd-class.md#oncreate) [WM_NCCALCSIZE](../../mfc/reference/cwnd-class.md#onnccalcsize)e [WM_GETMINMAXINFO](../../mfc/reference/cwnd-class.md#ongetminmaxinfo) para o controle de caixa de lista.

Essas mensagens são tratadas por padrão pelas funções de membro [OnNcCreate,](../../mfc/reference/cwnd-class.md#onnccreate) [OnCreate,](../../mfc/reference/cwnd-class.md#oncreate) [OnNcCalcSize](../../mfc/reference/cwnd-class.md#onnccalcsize)e [OnGetMinMaxInfo](../../mfc/reference/cwnd-class.md#ongetminmaxinfo) na `CWnd` classe base. Para estender o tratamento padrão da `CListBox`mensagem, obtenha uma classe de , adicione um mapa de mensagem à nova classe e anule as funções anteriores do membro do manipulador de mensagens. Substituição, `OnCreate`por exemplo, para realizar a inicialização necessária para uma nova classe.

Aplique os estilos de janela a [seguir](../../mfc/reference/styles-used-by-mfc.md#window-styles) a um controle de caixa de lista.

- WS_CHILD Sempre

- WS_VISIBLE Normalmente

- WS_DISABLED raramente

- WS_VSCROLL Para adicionar uma barra de rolagem vertical

- WS_HSCROLL Para adicionar uma barra de rolagem horizontal

- WS_GROUP Para controles de grupo

- WS_TABSTOP Para permitir a tabulação a este controle

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFC_CListBox#2](../../mfc/codesnippet/cpp/clistbox-class_5.cpp)]

## <a name="clistboxdeleteitem"></a><a name="deleteitem"></a>CListBox::DeleteItem

Chamado pela estrutura quando o usuário exclui um item de um objeto de saque `CListBox` do proprietário ou destrói a caixa de lista.

```
virtual void DeleteItem(LPDELETEITEMSTRUCT lpDeleteItemStruct);
```

### <a name="parameters"></a>Parâmetros

*lpDeleteItemStruct*<br/>
Um ponteiro longo para uma estrutura DO Windows [DELETEITEMSTRUCT](/windows/win32/api/winuser/ns-winuser-deleteitemstruct) que contém informações sobre o item excluído.

### <a name="remarks"></a>Comentários

A implementação padrão desta função não faz nada. Anular esta função para redesenhar uma caixa de lista de sorteio do proprietário conforme necessário.

Consulte [CWnd::OnDeleteItem](../../mfc/reference/cwnd-class.md#ondeleteitem) para obter `DELETEITEMSTRUCT` uma descrição da estrutura.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFC_CListBox#6](../../mfc/codesnippet/cpp/clistbox-class_6.cpp)]

## <a name="clistboxdeletestring"></a><a name="deletestring"></a>CListBox::DeleteString

Exclui o item na posição *nIndex* da caixa de lista.

```
int DeleteString(UINT nIndex);
```

### <a name="parameters"></a>Parâmetros

*nIndex*<br/>
Especifica o índice baseado em zero da string a ser excluído.

### <a name="return-value"></a>Valor retornado

Uma contagem das strings restantes na lista. O valor de retorno é LB_ERR se *nIndex* especificar um índice maior do que o número de itens da lista.

### <a name="remarks"></a>Comentários

Todos os itens que seguem *o nIndex* agora descem uma posição. Por exemplo, se uma caixa de lista contiver dois itens, a exclusão do primeiro item fará com que o item restante esteja agora na primeira posição. *nIndex*=0 para o item na primeira posição.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFC_CListBox#7](../../mfc/codesnippet/cpp/clistbox-class_7.cpp)]

## <a name="clistboxdir"></a><a name="dir"></a>CListBox::Dir

Adiciona uma lista de nomes de arquivos, drives ou ambos a uma caixa de lista.

```
int Dir(
    UINT attr,
    LPCTSTR lpszWildCard);
```

### <a name="parameters"></a>Parâmetros

*Attr*<br/>
Pode ser qualquer combinação dos valores **de enum** descritos em `CFile::GetStatu` [s,](../../mfc/reference/cfile-class.md#getstatus)ou qualquer combinação dos seguintes valores:

|Valor|Significado|
|-----------|-------------|
|0x0000|O arquivo pode ser lido ou escrito para.|
|0x0001|O arquivo pode ser lido, mas não escrito para.|
|0x0002|O arquivo está oculto e não aparece em uma listagem de diretório.|
|0x0004|Arquivo é um arquivo do sistema.|
|0x0010|O nome especificado pelo *lpszWildCard* especifica um diretório.|
|0x0020|O arquivo foi arquivado.|
|0x4000|Inclua todas as unidades que correspondam ao nome especificado pelo *lpszWildCard*.|
|0x8000|Bandeira exclusiva. Se o sinalizador exclusivo estiver definido, apenas arquivos do tipo especificado serão listados. Caso contrário, os arquivos do tipo especificado são listados, além de arquivos "normais".|

*Lpszwildcard*<br/>
Aponta para uma seqüência de especificação de arquivo. A corda pode conter curingas\*(por exemplo, *. ).

### <a name="return-value"></a>Valor retornado

O índice baseado em zero do último nome de arquivo adicionado à lista. O valor de retorno é LB_ERR se ocorrer um erro; o valor de retorno é LB_ERRSPACE se houver espaço insuficiente para armazenar as novas cordas.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFC_CListBox#8](../../mfc/codesnippet/cpp/clistbox-class_8.cpp)]

## <a name="clistboxdrawitem"></a><a name="drawitem"></a>CListBox::DrawItem

Chamado pela estrutura quando um aspecto visual de uma caixa de lista de sorteio do proprietário é alterado.

```
virtual void DrawItem(LPDRAWITEMSTRUCT lpDrawItemStruct);
```

### <a name="parameters"></a>Parâmetros

*Lpdrawitemstruct*<br/>
Um ponteiro longo para uma estrutura [DRAWITEMSTRUCT](/windows/win32/api/winuser/ns-winuser-drawitemstruct) que contém informações sobre o tipo de desenho necessário.

### <a name="remarks"></a>Comentários

Os `itemAction` `itemState` membros da `DRAWITEMSTRUCT` estrutura definem a ação de desenho a ser realizada.

Por padrão, esta função de membro não faz nada. Substituir esta função de membro para implementar `CListBox` o desenho para um objeto de desenho do proprietário. O aplicativo deve restaurar todos os objetos GDI (Graphics Device Interface, interface de dispositivo gráfico) selecionados para o contexto de exibição fornecido no *lpDrawItemStruct* antes que essa função de membro seja encerrada.

Consulte [CWnd::OnDrawItem](../../mfc/reference/cwnd-class.md#ondrawitem) para obter `DRAWITEMSTRUCT` uma descrição da estrutura.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFC_CListBox#9](../../mfc/codesnippet/cpp/clistbox-class_9.cpp)]

## <a name="clistboxfindstring"></a><a name="findstring"></a>Caixa de clist::Findstring

Encontra a primeira seqüência em uma caixa de lista que contém o prefixo especificado sem alterar a seleção de caixa de lista.

```
int FindString(
    int nStartAfter,
    LPCTSTR lpszItem) const;
```

### <a name="parameters"></a>Parâmetros

*nStartAfter*<br/>
Contém o índice baseado em zero do item antes do primeiro item a ser pesquisado. Quando a pesquisa chega à parte inferior da caixa de lista, ela continua do topo da caixa de lista de volta para o item especificado por *nStartAfter*. Se *nStartAfter* for -1, toda a caixa de lista será pesquisada desde o início.

*Lpszitem*<br/>
Aponta para a seqüência de terminadas nula que contém o prefixo a ser pesquisado. A pesquisa é independente do caso, então esta seqüência pode conter qualquer combinação de letras maiúsculas e minúsculas.

### <a name="return-value"></a>Valor retornado

O índice baseado em zero do item correspondente ou LB_ERR se a pesquisa não foi bem sucedida.

### <a name="remarks"></a>Comentários

Use a função [membro SelectString](#selectstring) para encontrar e selecionar uma seqüência de strings.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFC_CListBox#10](../../mfc/codesnippet/cpp/clistbox-class_10.cpp)]

## <a name="clistboxfindstringexact"></a><a name="findstringexact"></a>Caixa de clist::FindstringExact

Encontra a primeira seqüência de caixa de lista que corresponde à seqüência especificada no *lpszFind*.

```
int FindStringExact(
    int nIndexStart,
    LPCTSTR lpszFind) const;
```

### <a name="parameters"></a>Parâmetros

*Nindexstart*<br/>
Especifica o índice baseado em zero do item antes do primeiro item a ser pesquisado. Quando a pesquisa chega à parte inferior da caixa de lista, ela continua do topo da caixa de lista de volta para o item especificado pelo *nIndexStart*. Se *nIndexStart* for -1, toda a caixa de lista será pesquisada desde o início.

*Lpszfind*<br/>
Aponta para a seqüência de nulidade sumida para procurar. Esta seqüência pode conter um nome de arquivo completo, incluindo a extensão. A pesquisa não é sensível ao caso, então a seqüência pode conter qualquer combinação de letras maiúsculas e minúsculas.

### <a name="return-value"></a>Valor retornado

O índice do item correspondente, ou LB_ERR se a pesquisa não foi bem sucedida.

### <a name="remarks"></a>Comentários

Se a caixa de lista foi criada com um estilo `FindStringExact` de sorteio do proprietário, mas sem o estilo [LBS_HASSTRINGS,](../../mfc/reference/styles-used-by-mfc.md#list-box-styles) a função do membro tentará igualar o valor de palavra dupla com o valor de *lpszFind*.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFC_CListBox#11](../../mfc/codesnippet/cpp/clistbox-class_11.cpp)]

## <a name="clistboxgetanchorindex"></a><a name="getanchorindex"></a>CListBox::GetAnchorIndex

Recupera o índice baseado em zero do item âncora atual na caixa de lista.

```
int GetAnchorIndex() const;
```

### <a name="return-value"></a>Valor retornado

O índice do item âncora atual, se bem sucedido; caso contrário, LB_ERR.

### <a name="remarks"></a>Comentários

Em uma caixa de lista de seleção múltipla, o item âncora é o primeiro ou último item em um bloco de itens selecionados contíguos.

### <a name="example"></a>Exemplo

  Veja o exemplo de [CListBox::SetAnchorIndex](#setanchorindex).

## <a name="clistboxgetcaretindex"></a><a name="getcaretindex"></a>CListBox::GetCaretIndex

Determina o índice do item que tem o retângulo de foco em uma caixa de lista de várias seleções.

```
int GetCaretIndex() const;
```

### <a name="return-value"></a>Valor retornado

O índice baseado em zero do item que tem o retângulo de foco em uma caixa de lista. Se a caixa de lista for uma caixa de lista de seleção única, o valor de retorno será o índice do item selecionado, se houver.

### <a name="remarks"></a>Comentários

O item pode ou não ser selecionado.

### <a name="example"></a>Exemplo

  Veja o exemplo de [CListBox::SetCaretIndex](#setcaretindex).

## <a name="clistboxgetcount"></a><a name="getcount"></a>CListBox::Contagem de contatos

Recupera o número de itens em uma caixa de lista.

```
int GetCount() const;
```

### <a name="return-value"></a>Valor retornado

O número de itens na caixa de lista ou LB_ERR se ocorrer um erro.

### <a name="remarks"></a>Comentários

A contagem retornada é maior que o valor do índice do último item (o índice é baseado em zero).

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFC_CListBox#12](../../mfc/codesnippet/cpp/clistbox-class_12.cpp)]

## <a name="clistboxgetcursel"></a><a name="getcursel"></a>CListBox::GetCursel

Recupera o índice baseado em zero do item selecionado no momento, se houver, em uma caixa de lista de seleção única.

```
int GetCurSel() const;
```

### <a name="return-value"></a>Valor retornado

O índice baseado em zero do item selecionado no momento se for uma caixa de lista de seleção única. É LB_ERR se nenhum item for selecionado no momento.

Em uma caixa de lista de múltipla seleção, o índice do item que tem o foco.

### <a name="remarks"></a>Comentários

Não chame `GetCurSel` uma caixa de lista de seleção múltipla. Use [CListBox::GetSelItems](#getselitems) em vez disso.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFC_CListBox#13](../../mfc/codesnippet/cpp/clistbox-class_13.cpp)]

## <a name="clistboxgethorizontalextent"></a><a name="gethorizontalextent"></a>CListBox::getHorizontalExtent

Recupera da caixa de lista a largura em pixels pelos quais ela pode ser rolada horizontalmente.

```
int GetHorizontalExtent() const;
```

### <a name="return-value"></a>Valor retornado

A largura rolável da caixa de lista, em pixels.

### <a name="remarks"></a>Comentários

Isso só é aplicável se a caixa de lista tiver uma barra de rolagem horizontal.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFC_CListBox#14](../../mfc/codesnippet/cpp/clistbox-class_14.cpp)]

## <a name="clistboxgetitemdata"></a><a name="getitemdata"></a>CListBox::GetItemData

Recupera o valor de palavra dupla fornecido pelo aplicativo associado ao item de caixa de lista especificado.

```
DWORD_PTR GetItemData(int nIndex) const;
```

### <a name="parameters"></a>Parâmetros

*nIndex*<br/>
Especifica o índice baseado em zero do item na caixa de lista.

### <a name="return-value"></a>Valor retornado

O valor associado ao item, ou LB_ERR se ocorrer um erro.

### <a name="remarks"></a>Comentários

O valor de palavra dupla foi o parâmetro *dwItemData* de uma chamada [SetItemData.](#setitemdata)

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFC_CListBox#15](../../mfc/codesnippet/cpp/clistbox-class_15.cpp)]

## <a name="clistboxgetitemdataptr"></a><a name="getitemdataptr"></a>CListBox::GetItemDataPtr

Recupera o valor de 32 bits fornecido pelo aplicativo associado ao item de caixa de lista especificado como ponteiro **(vazio).** <strong>\*</strong>

```cpp
void* GetItemDataPtr(int nIndex) const;
```

### <a name="parameters"></a>Parâmetros

*nIndex*<br/>
Especifica o índice baseado em zero do item na caixa de lista.

### <a name="return-value"></a>Valor retornado

Recupera um ponteiro ou -1 se ocorrer um erro.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFC_CListBox#16](../../mfc/codesnippet/cpp/clistbox-class_16.cpp)]

## <a name="clistboxgetitemheight"></a><a name="getitemheight"></a>CListBox::GetItemHeight

Determina a altura dos itens em uma caixa de lista.

```
int GetItemHeight(int nIndex) const;
```

### <a name="parameters"></a>Parâmetros

*nIndex*<br/>
Especifica o índice baseado em zero do item na caixa de lista. Este parâmetro é usado apenas se a caixa de lista tiver o estilo LBS_OWNERDRAWVARIABLE; caso contrário, deve ser definido como 0.

### <a name="return-value"></a>Valor retornado

A altura, em pixels, dos itens da caixa de lista. Se a caixa de lista tiver o estilo [LBS_OWNERDRAWVARIABLE,](../../mfc/reference/styles-used-by-mfc.md#list-box-styles) o valor de retorno será a altura do item especificado pelo *nIndex*. Se ocorrer um erro, o valor de retorno será LB_ERR.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFC_CListBox#17](../../mfc/codesnippet/cpp/clistbox-class_17.cpp)]

## <a name="clistboxgetitemrect"></a><a name="getitemrect"></a>CListBox::GetItemRect

Recupera as dimensões do retângulo que limita um item de caixa de lista como é exibido atualmente na janela da caixa de lista.

```
int GetItemRect(
    int nIndex,
    LPRECT lpRect) const;
```

### <a name="parameters"></a>Parâmetros

*nIndex*<br/>
Especifica o índice baseado em zero do item.

*Lprect*<br/>
Especifica um ponteiro longo para uma [estrutura RECT](/windows/win32/api/windef/ns-windef-rect) que recebe as coordenadas do cliente da caixa de lista do item.

### <a name="return-value"></a>Valor retornado

LB_ERR se ocorrer um erro.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFC_CListBox#18](../../mfc/codesnippet/cpp/clistbox-class_18.cpp)]

## <a name="clistboxgetlistboxinfo"></a><a name="getlistboxinfo"></a>CListBox::GetListBoxInfo

Recupera o número de itens por coluna.

```
DWORD GetListBoxInfo() const;
```

### <a name="return-value"></a>Valor retornado

Número de itens por coluna `CListBox` do objeto.

### <a name="remarks"></a>Comentários

Esta função membro emula a funcionalidade da mensagem [LB_GETLISTBOXINFO,](/windows/win32/Controls/lb-getlistboxinfo) conforme descrito no SDK do Windows.

## <a name="clistboxgetlocale"></a><a name="getlocale"></a>CListBox::GetLocale

Recupera o local usado pela caixa de lista.

```
LCID GetLocale() const;
```

### <a name="return-value"></a>Valor retornado

O valor do identificador local (LCID) para as strings na caixa de lista.

### <a name="remarks"></a>Comentários

O local é usado, por exemplo, para determinar a ordem de classificação das strings em uma caixa de lista classificada.

### <a name="example"></a>Exemplo

  Veja o exemplo de [CListBox::SetLocale](#setlocale).

## <a name="clistboxgetsel"></a><a name="getsel"></a>CListBox::GetSel

Recupera o estado de seleção de um item.

```
int GetSel(int nIndex) const;
```

### <a name="parameters"></a>Parâmetros

*nIndex*<br/>
Especifica o índice baseado em zero do item.

### <a name="return-value"></a>Valor retornado

Um número positivo se o item especificado for selecionado; caso contrário, é 0. O valor de retorno é LB_ERR se ocorrer um erro.

### <a name="remarks"></a>Comentários

Essa função de membro funciona com caixas de lista de seleção única e múltipla.

Para recuperar o índice do item da caixa de lista atualmente selecionado, use [CListBox::GetCurSel](#getcursel).

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFC_CListBox#19](../../mfc/codesnippet/cpp/clistbox-class_19.cpp)]

## <a name="clistboxgetselcount"></a><a name="getselcount"></a>CListBox::GetSelCount

Recupera o número total de itens selecionados em uma caixa de lista de seleção múltipla.

```
int GetSelCount() const;
```

### <a name="return-value"></a>Valor retornado

A contagem de itens selecionados em uma caixa de lista. Se a caixa de lista for uma caixa de lista de seleção única, o valor de retorno será LB_ERR.

### <a name="example"></a>Exemplo

  Veja o exemplo de [CListBox::GetSelItems](#getselitems).

## <a name="clistboxgetselitems"></a><a name="getselitems"></a>CListBox::GetSelItems

Preenche um buffer com uma matriz de inteiros que especifica os números de itens selecionados em uma caixa de lista de várias seleções.

```
int GetSelItems(
    int nMaxItems,
    LPINT rgIndex) const;
```

### <a name="parameters"></a>Parâmetros

*nMaxItems*<br/>
Especifica o número máximo de itens selecionados cujos números de itens devem ser colocados no buffer.

*rgIndex*<br/>
Especifica um ponteiro para um buffer grande o suficiente para o número de inteiros especificados por *nMaxItems*.

### <a name="return-value"></a>Valor retornado

O número real de itens colocados no buffer. Se a caixa de lista for uma caixa `LB_ERR`de lista de seleção única, o valor de retorno será .

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFC_CListBox#20](../../mfc/codesnippet/cpp/clistbox-class_20.cpp)]

## <a name="clistboxgettext"></a><a name="gettext"></a>Caixa de clist::getText

Recebe uma seqüência de uma caixa de lista.

```
int GetText(
    int nIndex,
    LPTSTR lpszBuffer) const;

void GetText(
    int nIndex,
    CString& rString) const;
```

### <a name="parameters"></a>Parâmetros

*nIndex*<br/>
Especifica o índice baseado em zero da string a ser recuperado.

*Lpszbuffer*<br/>
Aponta para o buffer que recebe a string. O buffer deve ter espaço suficiente para a seqüência e um caractere nulo final. O tamanho da seqüência pode ser `GetTextLen` determinado com antecedência, chamando a função de membro.

*rString*<br/>
Uma referência a um objeto `CString`.

### <a name="return-value"></a>Valor retornado

O comprimento (em bytes) da seqüência, excluindo o caractere nulo final. Se *nIndex* não especificar um índice válido, o valor de retorno será LB_ERR.

### <a name="remarks"></a>Comentários

A segunda forma desta função `CString` membro preenche um objeto com o texto da seqüência.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFC_CListBox#21](../../mfc/codesnippet/cpp/clistbox-class_21.cpp)]

## <a name="clistboxgettextlen"></a><a name="gettextlen"></a>CListBox::GetTextLen

Obtém o comprimento de uma seqüência em um item de caixa de lista.

```
int GetTextLen(int nIndex) const;
```

### <a name="parameters"></a>Parâmetros

*nIndex*<br/>
Especifica o índice baseado em zero da string.

### <a name="return-value"></a>Valor retornado

O comprimento da seqüência em caracteres, excluindo o caractere nulo terminando. Se *nIndex* não especificar um índice válido, o valor de retorno será LB_ERR.

### <a name="example"></a>Exemplo

  Veja o exemplo de [CListBox::GetText](#gettext).

## <a name="clistboxgettopindex"></a><a name="gettopindex"></a>CListBox::GetTopIndex

Recupera o índice baseado em zero do primeiro item visível em uma caixa de lista.

```
int GetTopIndex() const;
```

### <a name="return-value"></a>Valor retornado

O índice baseado em zero do primeiro item visível em uma caixa de lista se for bem sucedido, LB_ERR o contrário.

### <a name="remarks"></a>Comentários

Inicialmente, o item 0 está no topo da caixa da lista, mas se a caixa de lista estiver rolada, outro item pode estar no topo.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFC_CListBox#22](../../mfc/codesnippet/cpp/clistbox-class_22.cpp)]

## <a name="clistboxinitstorage"></a><a name="initstorage"></a>CListBox:InitStorage

Aloca a memória para armazenar itens de caixa de lista.

```
int InitStorage(
    int nItems,
    UINT nBytes);
```

### <a name="parameters"></a>Parâmetros

*nItems*<br/>
Especifica o número de itens a serem adicionados.

*Nbytes*<br/>
Especifica a quantidade de memória, em bytes, para alocar para strings de itens.

### <a name="return-value"></a>Valor retornado

Se for bem-sucedido, o número máximo de itens que a caixa de lista pode armazenar antes de uma realocação de memória é necessário, caso contrário, LB_ERRSPACE, o que significa que não há memória suficiente disponível.

### <a name="remarks"></a>Comentários

Chame esta função antes de adicionar um `CListBox`grande número de itens a um .

Essa função ajuda a acelerar a inicialização de caixas de lista que possuem um grande número de itens (mais de 100). Ele pré-aloca a quantidade especificada de memória para que as funções subsequentes [AddString](#addstring), [InsertString](#insertstring)e [Dir](#dir) levem o menor tempo possível. Você pode usar estimativas para os parâmetros. Se você superestimar, alguma memória extra será alocada; se você subestimar, a alocação normal é usada para itens que excedam o valor pré-alocado.

Apenas windows 95/98: O parâmetro *nItems* é limitado a valores de 16 bits. Isso significa que as caixas de lista não podem conter mais de 32.767 itens. Embora o número de itens seja restrito, o tamanho total dos itens em uma caixa de lista é limitado apenas pela memória disponível.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFC_CListBox#23](../../mfc/codesnippet/cpp/clistbox-class_23.cpp)]

## <a name="clistboxinsertstring"></a><a name="insertstring"></a>Caixa de clist::seqüência de inserção

Insere uma seqüência na caixa de lista.

```
int InsertString(
    int nIndex,
    LPCTSTR lpszItem);
```

### <a name="parameters"></a>Parâmetros

*nIndex*<br/>
Especifica o índice baseado em zero da posição para inserir a string. Se este parâmetro for -1, a seqüência será adicionada ao final da lista.

*Lpszitem*<br/>
Aponta para a seqüência de terminadas nula que deve ser inserida.

### <a name="return-value"></a>Valor retornado

O índice baseado em zero da posição em que a corda foi inserida. O valor de retorno é LB_ERR se ocorrer um erro; o valor de retorno é LB_ERRSPACE se houver espaço insuficiente para armazenar a nova seqüência.

### <a name="remarks"></a>Comentários

Ao contrário da função `InsertString` membro [AddString,](#addstring) não faz com que uma lista com o estilo [LBS_SORT](../../mfc/reference/styles-used-by-mfc.md#list-box-styles) seja classificada.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFC_CListBox#24](../../mfc/codesnippet/cpp/clistbox-class_24.cpp)]

## <a name="clistboxitemfrompoint"></a><a name="itemfrompoint"></a>CListBox::ItemFromPoint

Determina o item da caixa de lista mais próximo do ponto especificado no *pt*.

```
UINT ItemFromPoint(
    CPoint pt,
    BOOL& bOutside) const;
```

### <a name="parameters"></a>Parâmetros

*pt*<br/>
Ponto para o qual encontrar o item mais próximo, especificado em relação ao canto superior esquerdo da área cliente da caixa de lista.

*bFora*<br/>
Consulte uma variável BOOL que será definida como TRUE se *o pt* estiver fora da área cliente da caixa de lista, FALSE se *pt* estiver dentro da área cliente da caixa de lista.

### <a name="return-value"></a>Valor retornado

O índice do item mais próximo ao ponto especificado no *pt*.

### <a name="remarks"></a>Comentários

Você pode usar esta função para determinar qual item de caixa de lista o cursor do mouse se move.

### <a name="example"></a>Exemplo

  Veja o exemplo de [CListBox::SetAnchorIndex](#setanchorindex).

## <a name="clistboxmeasureitem"></a><a name="measureitem"></a>CListBox::MeasureItem

Chamado pela estrutura quando uma caixa de lista com um estilo de sorteio do proprietário é criada.

```
virtual void MeasureItem(LPMEASUREITEMSTRUCT lpMeasureItemStruct);
```

### <a name="parameters"></a>Parâmetros

*lpMeasureItemStruct*<br/>
Um ponteiro longo para uma estrutura [MEASUREITEMSTRUCT.](/windows/win32/api/winuser/ns-winuser-measureitemstruct)

### <a name="remarks"></a>Comentários

Por padrão, esta função de membro não faz nada. Anular essa função de membro `MEASUREITEMSTRUCT` e preencher a estrutura para informar o Windows das dimensões da caixa de lista. Se a caixa de lista for criada com o estilo [LBS_OWNERDRAWVARIABLE,](../../mfc/reference/styles-used-by-mfc.md#list-box-styles) a estrutura chamará essa função de membro para cada item na caixa de lista. Caso contrário, este membro é chamado apenas uma vez.

Para obter mais [LBS_OWNERDRAWFIXED](../../mfc/reference/styles-used-by-mfc.md#list-box-styles) informações sobre como usar o estilo LBS_OWNERDRAWFIXED `SubclassDlgItem` em `CWnd`uma caixa de lista de sorteio do proprietário criada com a função de membro de , consulte a discussão na [Nota Técnica 14](../../mfc/tn014-custom-controls.md).

Consulte [CWnd::OnMeasureItem](../../mfc/reference/cwnd-class.md#onmeasureitem) para obter `MEASUREITEMSTRUCT` uma descrição da estrutura.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFC_CListBox#25](../../mfc/codesnippet/cpp/clistbox-class_25.cpp)]

## <a name="clistboxresetcontent"></a><a name="resetcontent"></a>CListBox::Redefinirconteúdo

Remove todos os itens de uma caixa de lista.

```cpp
void ResetContent();
```

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFC_CListBox#26](../../mfc/codesnippet/cpp/clistbox-class_26.cpp)]

## <a name="clistboxselectstring"></a><a name="selectstring"></a>CListBox::SelectString

Pesquisa um item de caixa de lista que corresponda à seqüência especificada e, se um item correspondente for encontrado, ele seleciona o item.

```
int SelectString(
    int nStartAfter,
    LPCTSTR lpszItem);
```

### <a name="parameters"></a>Parâmetros

*nStartAfter*<br/>
Contém o índice baseado em zero do item antes do primeiro item a ser pesquisado. Quando a pesquisa chega à parte inferior da caixa de lista, ela continua do topo da caixa de lista de volta para o item especificado por *nStartAfter*. Se *nStartAfter* for -1, toda a caixa de lista será pesquisada desde o início.

*Lpszitem*<br/>
Aponta para a seqüência de terminadas nula que contém o prefixo a ser pesquisado. A pesquisa é independente do caso, então esta seqüência pode conter qualquer combinação de letras maiúsculas e minúsculas.

### <a name="return-value"></a>Valor retornado

O índice do item selecionado se a pesquisa foi bem sucedida. Se a pesquisa não foi bem sucedida, o valor de retorno será LB_ERR e a seleção atual não será alterada.

### <a name="remarks"></a>Comentários

A caixa de lista é rolada, se necessário, para colocar o item selecionado à vista.

Esta função de membro não pode ser usada com uma caixa de lista que tenha o [estilo LBS_MULTIPLESEL.](../../mfc/reference/styles-used-by-mfc.md#list-box-styles)

Um item é selecionado apenas se seus caracteres iniciais (a partir do ponto de partida) corresponderem aos caracteres na seqüência especificada pelo *lpszItem*.

Use `FindString` a função membro para encontrar uma seqüência sem selecionar o item.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFC_CListBox#27](../../mfc/codesnippet/cpp/clistbox-class_27.cpp)]

## <a name="clistboxselitemrange"></a><a name="selitemrange"></a>CListBox::SelItemRange

Seleciona vários itens consecutivos em uma caixa de lista de várias seleções.

```
int SelItemRange(
    BOOL bSelect,
    int nFirstItem,
    int nLastItem);
```

### <a name="parameters"></a>Parâmetros

*bSelecione*<br/>
Especifica como definir a seleção. Se *bSelect* for TRUE, a seqüência será selecionada e destacada; se FALSE, o destaque é removido e a seqüência de string não é mais selecionada.

*nFirstItem*<br/>
Especifica o índice baseado em zero do primeiro item a ser definido.

*nLastItem*<br/>
Especifica o índice baseado em zero do último item a ser definido.

### <a name="return-value"></a>Valor retornado

LB_ERR se ocorrer um erro.

### <a name="remarks"></a>Comentários

Use esta função de membro apenas com caixas de lista de seleção múltipla. Se você precisar selecionar apenas um item em uma caixa de lista de seleção múltipla — isto é, se *nFirstItem* for igual a *nLastItem* — chame a função de membro [SetSel](#setsel) em vez disso.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFC_CListBox#28](../../mfc/codesnippet/cpp/clistbox-class_28.cpp)]

## <a name="clistboxsetanchorindex"></a><a name="setanchorindex"></a>CListBox::SetAnchorIndex

Define a âncora em uma caixa de lista de seleção múltipla para iniciar uma seleção estendida.

```cpp
void SetAnchorIndex(int nIndex);
```

### <a name="parameters"></a>Parâmetros

*nIndex*<br/>
Especifica o índice baseado em zero do item list-box que será a âncora.

### <a name="remarks"></a>Comentários

Em uma caixa de lista de seleção múltipla, o item âncora é o primeiro ou último item em um bloco de itens selecionados contíguos.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFC_CListBox#29](../../mfc/codesnippet/cpp/clistbox-class_29.cpp)]

## <a name="clistboxsetcaretindex"></a><a name="setcaretindex"></a>CListBox::SetCaretIndex

Define o retângulo de foco para o item no índice especificado em uma caixa de lista de várias seleções.

```
int SetCaretIndex(
    int nIndex,
    BOOL bScroll = TRUE);
```

### <a name="parameters"></a>Parâmetros

*nIndex*<br/>
Especifica o índice baseado em zero do item para receber o retângulo de foco na caixa de lista.

*bScroll*<br/>
Se este valor for 0, o item será rolado até ficar totalmente visível. Se este valor não for 0, o item será rolado até ficar pelo menos parcialmente visível.

### <a name="return-value"></a>Valor retornado

LB_ERR se ocorrer um erro.

### <a name="remarks"></a>Comentários

Se o item não estiver visível, ele será colocado em exibição.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFC_CListBox#30](../../mfc/codesnippet/cpp/clistbox-class_30.cpp)]

## <a name="clistboxsetcolumnwidth"></a><a name="setcolumnwidth"></a>CListBox::SetColunaLarguradeserse

Define a largura em pixels de todas as colunas em uma caixa de lista de várias colunas (criada com o estilo [LBS_MULTICOLUMN).](../../mfc/reference/styles-used-by-mfc.md#list-box-styles)

```cpp
void SetColumnWidth(int cxWidth);
```

### <a name="parameters"></a>Parâmetros

*cxWidth*<br/>
Especifica a largura em pixels de todas as colunas.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFC_CListBox#31](../../mfc/codesnippet/cpp/clistbox-class_31.cpp)]

## <a name="clistboxsetcursel"></a><a name="setcursel"></a>CListBox::SetCursel

Seleciona uma seqüência de strings e rola-a para a exibição, se necessário.

```
int SetCurSel(int nSelect);
```

### <a name="parameters"></a>Parâmetros

*Nselect*<br/>
Especifica o índice baseado em zero da string a ser selecionada. Se *nSelect* for -1, a caixa de lista será definida para não ter seleção.

### <a name="return-value"></a>Valor retornado

LB_ERR se ocorrer um erro.

### <a name="remarks"></a>Comentários

Quando a nova seqüência é selecionada, a caixa de lista remove o destaque da seqüência de string selecionada anteriormente.

Use esta função de membro apenas com caixas de lista de seleção única.

Para definir ou remover uma seleção em uma caixa de lista de seleção múltipla, use [CListBox::SetSel](#setsel).

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFC_CListBox#32](../../mfc/codesnippet/cpp/clistbox-class_32.cpp)]

## <a name="clistboxsethorizontalextent"></a><a name="sethorizontalextent"></a>CListBox::SetHorizontalExtent

Define a largura, em pixels, pela qual uma caixa de lista pode ser rolada horizontalmente.

```cpp
void SetHorizontalExtent(int cxExtent);
```

### <a name="parameters"></a>Parâmetros

*cxExtent*<br/>
Especifica o número de pixels pelos quais a caixa de lista pode ser rolada horizontalmente.

### <a name="remarks"></a>Comentários

Se o tamanho da caixa de lista for menor do que este valor, a barra de rolagem horizontal irá rolar horizontalmente itens na caixa de lista. Se a caixa de lista for tão grande ou maior que esse valor, a barra de rolagem horizontal será oculta.

Para responder a `SetHorizontalExtent`uma chamada, a caixa de lista deve ter sido definida com o estilo [WS_HSCROLL.](../../mfc/reference/styles-used-by-mfc.md#window-styles)

Esta função de membro não é útil para caixas de lista de várias colunas. Para caixas de lista `SetColumnWidth` de várias colunas, ligue para a função membro.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFC_CListBox#33](../../mfc/codesnippet/cpp/clistbox-class_33.cpp)]

## <a name="clistboxsetitemdata"></a><a name="setitemdata"></a>CListBox::SetItemData

Define um valor associado ao item especificado em uma caixa de lista.

```
int SetItemData(
    int nIndex,
    DWORD_PTR dwItemData);
```

### <a name="parameters"></a>Parâmetros

*nIndex*<br/>
Especifica o índice baseado em zero do item.

*dwItemData*<br/>
Especifica o valor a ser associado ao item.

### <a name="return-value"></a>Valor retornado

LB_ERR se ocorrer um erro.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFC_CListBox#34](../../mfc/codesnippet/cpp/clistbox-class_34.cpp)]

## <a name="clistboxsetitemdataptr"></a><a name="setitemdataptr"></a>CListBox::SetItemDataPtr

Define o valor de 32 bits associado ao item especificado em uma caixa de lista para ser o ponteiro especificado **(vazio** <strong>\*</strong>).

```
int SetItemDataPtr(
    int nIndex,
    void* pData);
```

### <a name="parameters"></a>Parâmetros

*nIndex*<br/>
Especifica o índice baseado em zero do item.

*Pdata*<br/>
Especifica o ponteiro a ser associado ao item.

### <a name="return-value"></a>Valor retornado

LB_ERR se ocorrer um erro.

### <a name="remarks"></a>Comentários

Este ponteiro permanece válido para a vida útil da caixa de lista, mesmo que a posição relativa do item na caixa de lista possa mudar à medida que os itens forem adicionados ou removidos. Portanto, o índice do item dentro da caixa pode mudar, mas o ponteiro permanece confiável.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFC_CListBox#35](../../mfc/codesnippet/cpp/clistbox-class_35.cpp)]

## <a name="clistboxsetitemheight"></a><a name="setitemheight"></a>CListBox::SetItemHeight

Define a altura dos itens em uma caixa de lista.

```
int SetItemHeight(
    int nIndex,
    UINT cyItemHeight);
```

### <a name="parameters"></a>Parâmetros

*nIndex*<br/>
Especifica o índice baseado em zero do item na caixa de lista. Este parâmetro é usado apenas se a caixa de lista tiver o estilo LBS_OWNERDRAWVARIABLE; caso contrário, deve ser definido como 0.

*cyItemHeight*<br/>
Especifica a altura, em pixels, do item.

### <a name="return-value"></a>Valor retornado

LB_ERR se o índice ou altura for inválido.

### <a name="remarks"></a>Comentários

Se a caixa de lista tiver o estilo [LBS_OWNERDRAWVARIABLE,](../../mfc/reference/styles-used-by-mfc.md#list-box-styles) esta função definirá a altura do item especificado pelo *nIndex*. Caso contrário, esta função define a altura de todos os itens na caixa de lista.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFC_CListBox#36](../../mfc/codesnippet/cpp/clistbox-class_36.cpp)]

## <a name="clistboxsetlocale"></a><a name="setlocale"></a>CListBox::SetLocale

Define o identificador local para esta caixa de lista.

```
LCID SetLocale(LCID nNewLocale);
```

### <a name="parameters"></a>Parâmetros

*nNewLocale*<br/>
O novo valor de identificador de localização (LCID) definido para a caixa de lista.

### <a name="return-value"></a>Valor retornado

O valor anterior do identificador local (LCID) para esta caixa de lista.

### <a name="remarks"></a>Comentários

Se `SetLocale` não for chamado, o local padrão é obtido a partir do sistema. Este local padrão do sistema pode ser modificado usando a aplicação Regional (ou Internacional) do Painel de Controle.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFC_CListBox#37](../../mfc/codesnippet/cpp/clistbox-class_37.cpp)]

## <a name="clistboxsetsel"></a><a name="setsel"></a>CListBox::SetSel

Seleciona uma seqüência em uma caixa de lista de várias seleções.

```
int SetSel(
    int nIndex,
    BOOL bSelect = TRUE);
```

### <a name="parameters"></a>Parâmetros

*nIndex*<br/>
Contém o índice baseado em zero da string a ser definida. Se -1, a seleção é adicionada ou removida de todas as strings, dependendo do valor de *bSelect*.

*bSelecione*<br/>
Especifica como definir a seleção. Se *bSelect* for TRUE, a seqüência será selecionada e destacada; se FALSE, o destaque é removido e a seqüência de string não é mais selecionada. A seqüência especificada é selecionada e destacada por padrão.

### <a name="return-value"></a>Valor retornado

LB_ERR se ocorrer um erro.

### <a name="remarks"></a>Comentários

Use esta função de membro apenas com caixas de lista de seleção múltipla.

Para selecionar um item em uma caixa de lista de seleção única, use [CListBox::SetCurSel](#setcursel).

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFC_CListBox#38](../../mfc/codesnippet/cpp/clistbox-class_38.cpp)]

## <a name="clistboxsettabstops"></a><a name="settabstops"></a>CListBox::Set's'Sstops

Define as posições de 'stop' em uma caixa de lista.

```cpp
void SetTabStops();
BOOL SetTabStops(const int& cxEachStop);

BOOL SetTabStops(
    int nTabStops,
    LPINT rgTabStops);
```

### <a name="parameters"></a>Parâmetros

*cxEachStop*<br/>
As guias são definidas em todas as unidades de diálogo *cxEachStop.* Consulte *rgTabStops* para obter uma descrição de uma unidade de diálogo.

*Ntabstops*<br/>
Especifica o número de guias a serem paradas na caixa de lista.

*Rgtabstops*<br/>
Aponta para o primeiro membro de uma matriz de inteiros contendo as posições de guia-stop em unidades de diálogo. Uma unidade de diálogo é uma distância horizontal ou vertical. Uma unidade de diálogo horizontal é igual a um quarto da unidade de largura da base de diálogo atual, e uma unidade de diálogo vertical é igual a um oitavo da unidade de altura da base de diálogo atual. As unidades base de diálogo são calculadas com base na altura e largura da fonte atual do sistema. A `GetDialogBaseUnits` função Windows retorna as unidades base de diálogo atuais em pixels. As guias devem ser classificadas em ordem crescente; abas traseiras não são permitidas.

### <a name="return-value"></a>Valor retornado

Não zero se todas as guias foram definidas; caso contrário, 0.

### <a name="remarks"></a>Comentários

Para definir as paradas de guia para o tamanho padrão de 2 unidades de diálogo, chame a versão sem parâmetros desta função de membro. Para definir as paradas de guia para um tamanho diferente de 2, chame a versão com o argumento *cxEachStop.*

Para definir as paradas de guia para uma matriz de tamanhos, use a versão com os argumentos *rgTabStops* e *nTabStops.* Uma parada de guia será definida para cada valor em *rgTabStops*, até o número especificado por *nTabStops*.

Para responder a uma `SetTabStops` chamada à função membro, a caixa de lista deve ter sido criada com o estilo [LBS_USETABSTOPS.](../../mfc/reference/styles-used-by-mfc.md#list-box-styles)

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFC_CListBox#39](../../mfc/codesnippet/cpp/clistbox-class_39.cpp)]

## <a name="clistboxsettopindex"></a><a name="settopindex"></a>CListBox::SetTopIndex

Garante que um item de caixa de lista em particular esteja visível.

```
int SetTopIndex(int nIndex);
```

### <a name="parameters"></a>Parâmetros

*nIndex*<br/>
Especifica o índice baseado em zero do item list-box.

### <a name="return-value"></a>Valor retornado

Zero se for bem sucedido, ou LB_ERR se ocorrer um erro.

### <a name="remarks"></a>Comentários

O sistema rola a caixa de lista até que o item especificado pelo *nIndex* apareça no topo da caixa de lista ou a faixa de rolagem máxima tenha sido atingida.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFC_CListBox#40](../../mfc/codesnippet/cpp/clistbox-class_40.cpp)]

## <a name="clistboxvkeytoitem"></a><a name="vkeytoitem"></a>CListBox::VKeyToItem

Chamada pela estrutura quando a janela pai da caixa de lista recebe uma mensagem WM_VKEYTOITEM da caixa de lista.

```
virtual int VKeyToItem(
    UINT nKey,
    UINT nIndex);
```

### <a name="parameters"></a>Parâmetros

*nKey*<br/>
O código de chave virtual da chave que o usuário pressionou. Para obter uma lista de códigos-chave virtuais padrão, consulte Winuser.h

*nIndex*<br/>
A posição atual do caret da caixa de lista.

### <a name="return-value"></a>Valor retornado

Retorna - 2 para nenhuma ação adicional, - 1 para ação padrão ou um número não negativo para especificar um índice de um item de caixa de lista no qual executar a ação padrão para o pressionamento da tecla.

### <a name="remarks"></a>Comentários

A mensagem WM_VKEYTOITEM é enviada pela caixa de lista quando recebe uma mensagem WM_KEYDOWN, mas somente se a caixa de lista atender a ambos os seguintes:

- Tem o conjunto de estilo [LBS_WANTKEYBOARDINPUT.](../../mfc/reference/styles-used-by-mfc.md#list-box-styles)

- Tem pelo menos um item.

Você nunca deve chamar isso de função você mesmo. Anular esta função para fornecer seu próprio manuseio personalizado de mensagens de teclado.

Você deve retornar um valor para dizer à estrutura qual ação sua substituição realizou. Um valor de retorno de - 2 indica que o aplicativo lidou com todos os aspectos da seleção do item e não requer nenhuma ação adicional pela caixa de lista. Antes de retornar - 2, você pode definir a seleção ou mover o caret ou ambos. Para definir a seleção, use [SetCurSel](#setcursel) ou [SetSel](#setsel). Para mover o cuidado, use [SetCaretIndex](#setcaretindex).

Um valor de retorno de - 1 indica que a caixa de lista deve executar a ação padrão em resposta ao pressionamento da tecla. A implementação padrão retorna - 1.

Um valor de retorno de 0 ou mais especifica o índice de um item na caixa de lista e indica que a caixa de lista deve executar a ação padrão para o pressionamento da tecla no item dado.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFC_CListBox#41](../../mfc/codesnippet/cpp/clistbox-class_41.cpp)]

## <a name="see-also"></a>Confira também

[Tomografia de amostra MFC](../../overview/visual-cpp-samples.md)<br/>
[Classe CWnd](../../mfc/reference/cwnd-class.md)<br/>
[Gráfico da hierarquia](../../mfc/hierarchy-chart.md)<br/>
[Classe CWnd](../../mfc/reference/cwnd-class.md)<br/>
[Classe CButton](../../mfc/reference/cbutton-class.md)<br/>
[Classe CComboBox](../../mfc/reference/ccombobox-class.md)<br/>
[Classe CEdit](../../mfc/reference/cedit-class.md)<br/>
[Classe CScrollBar](../../mfc/reference/cscrollbar-class.md)<br/>
[Classe CStatic](../../mfc/reference/cstatic-class.md)
