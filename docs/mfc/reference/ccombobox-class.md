---
title: Classe CComboBox
ms.date: 11/04/2016
f1_keywords:
- CComboBox
- AFXWIN/CComboBox
- AFXWIN/CComboBox::CComboBox
- AFXWIN/CComboBox::AddString
- AFXWIN/CComboBox::Clear
- AFXWIN/CComboBox::CompareItem
- AFXWIN/CComboBox::Copy
- AFXWIN/CComboBox::Create
- AFXWIN/CComboBox::Cut
- AFXWIN/CComboBox::DeleteItem
- AFXWIN/CComboBox::DeleteString
- AFXWIN/CComboBox::Dir
- AFXWIN/CComboBox::DrawItem
- AFXWIN/CComboBox::FindString
- AFXWIN/CComboBox::FindStringExact
- AFXWIN/CComboBox::GetComboBoxInfo
- AFXWIN/CComboBox::GetCount
- AFXWIN/CComboBox::GetCueBanner
- AFXWIN/CComboBox::GetCurSel
- AFXWIN/CComboBox::GetDroppedControlRect
- AFXWIN/CComboBox::GetDroppedState
- AFXWIN/CComboBox::GetDroppedWidth
- AFXWIN/CComboBox::GetEditSel
- AFXWIN/CComboBox::GetExtendedUI
- AFXWIN/CComboBox::GetHorizontalExtent
- AFXWIN/CComboBox::GetItemData
- AFXWIN/CComboBox::GetItemDataPtr
- AFXWIN/CComboBox::GetItemHeight
- AFXWIN/CComboBox::GetLBText
- AFXWIN/CComboBox::GetLBTextLen
- AFXWIN/CComboBox::GetLocale
- AFXWIN/CComboBox::GetMinVisible
- AFXWIN/CComboBox::GetTopIndex
- AFXWIN/CComboBox::InitStorage
- AFXWIN/CComboBox::InsertString
- AFXWIN/CComboBox::LimitText
- AFXWIN/CComboBox::MeasureItem
- AFXWIN/CComboBox::Paste
- AFXWIN/CComboBox::ResetContent
- AFXWIN/CComboBox::SelectString
- AFXWIN/CComboBox::SetCueBanner
- AFXWIN/CComboBox::SetCurSel
- AFXWIN/CComboBox::SetDroppedWidth
- AFXWIN/CComboBox::SetEditSel
- AFXWIN/CComboBox::SetExtendedUI
- AFXWIN/CComboBox::SetHorizontalExtent
- AFXWIN/CComboBox::SetItemData
- AFXWIN/CComboBox::SetItemDataPtr
- AFXWIN/CComboBox::SetItemHeight
- AFXWIN/CComboBox::SetLocale
- AFXWIN/CComboBox::SetMinVisibleItems
- AFXWIN/CComboBox::SetTopIndex
- AFXWIN/CComboBox::ShowDropDown
helpviewer_keywords:
- CComboBox [MFC], CComboBox
- CComboBox [MFC], AddString
- CComboBox [MFC], Clear
- CComboBox [MFC], CompareItem
- CComboBox [MFC], Copy
- CComboBox [MFC], Create
- CComboBox [MFC], Cut
- CComboBox [MFC], DeleteItem
- CComboBox [MFC], DeleteString
- CComboBox [MFC], Dir
- CComboBox [MFC], DrawItem
- CComboBox [MFC], FindString
- CComboBox [MFC], FindStringExact
- CComboBox [MFC], GetComboBoxInfo
- CComboBox [MFC], GetCount
- CComboBox [MFC], GetCueBanner
- CComboBox [MFC], GetCurSel
- CComboBox [MFC], GetDroppedControlRect
- CComboBox [MFC], GetDroppedState
- CComboBox [MFC], GetDroppedWidth
- CComboBox [MFC], GetEditSel
- CComboBox [MFC], GetExtendedUI
- CComboBox [MFC], GetHorizontalExtent
- CComboBox [MFC], GetItemData
- CComboBox [MFC], GetItemDataPtr
- CComboBox [MFC], GetItemHeight
- CComboBox [MFC], GetLBText
- CComboBox [MFC], GetLBTextLen
- CComboBox [MFC], GetLocale
- CComboBox [MFC], GetMinVisible
- CComboBox [MFC], GetTopIndex
- CComboBox [MFC], InitStorage
- CComboBox [MFC], InsertString
- CComboBox [MFC], LimitText
- CComboBox [MFC], MeasureItem
- CComboBox [MFC], Paste
- CComboBox [MFC], ResetContent
- CComboBox [MFC], SelectString
- CComboBox [MFC], SetCueBanner
- CComboBox [MFC], SetCurSel
- CComboBox [MFC], SetDroppedWidth
- CComboBox [MFC], SetEditSel
- CComboBox [MFC], SetExtendedUI
- CComboBox [MFC], SetHorizontalExtent
- CComboBox [MFC], SetItemData
- CComboBox [MFC], SetItemDataPtr
- CComboBox [MFC], SetItemHeight
- CComboBox [MFC], SetLocale
- CComboBox [MFC], SetMinVisibleItems
- CComboBox [MFC], SetTopIndex
- CComboBox [MFC], ShowDropDown
ms.assetid: 4e73b5df-0d2e-4658-9706-38133fb10513
ms.openlocfilehash: df935bb924c7d8908b1166852dc553a73fc71ff3
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81369504"
---
# <a name="ccombobox-class"></a>Classe CComboBox

Fornece a funcionalidade de uma caixa de combinação do Windows.

## <a name="syntax"></a>Sintaxe

```
class CComboBox : public CWnd
```

## <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores públicos

|Nome|Descrição|
|----------|-----------------|
|[CComboBox::CComboBox](#ccombobox)|Constrói um objeto `CComboBox`.|

### <a name="public-methods"></a>Métodos públicos

|Nome|Descrição|
|----------|-----------------|
|[CComboBox::AddString](#addstring)|Adiciona uma seqüência ao final da lista na caixa de lista de uma caixa de combinação ou na posição classificada para caixas de lista com o estilo CBS_SORT.|
|[CComboBox::Clear](#clear)|Exclui (limpa) a seleção atual, se houver, no controle de edição.|
|[CComboBox::CompareItem](#compareitem)|Chamado pelo framework para determinar a posição relativa de um novo item de lista em uma caixa de combinação sorteada pelo proprietário.|
|[CComboBox::Copiar](#copy)|Copia a seleção atual, se houver, na Área de Transferência em formato CF_TEXT.|
|[CComboBox::Criar](#create)|Cria a caixa de combinação e `CComboBox` a prende ao objeto.|
|[CComboBox::Corte](#cut)|Exclui (corta) a seleção atual, se houver, no controle de edição e copia o texto excluído na Área de Transferência em formato CF_TEXT.|
|[CComboBox::DeleteItem](#deleteitem)|Chamado pelo framework quando um item de lista é excluído de uma caixa de combinação desenhada pelo proprietário.|
|[CComboBox::DeleteString](#deletestring)|Exclui uma seqüência da caixa de lista de uma caixa de combinação.|
|[CComboBox::Dir](#dir)|Adiciona uma lista de nomes de arquivos à caixa de lista de uma caixa de combinação.|
|[CComboBox::DrawItem](#drawitem)|Chamado pela estrutura quando um aspecto visual de uma caixa de combinação desenhada pelo proprietário muda.|
|[CComboBox::FindString](#findstring)|Encontra a primeira string que contém o prefixo especificado na caixa de lista de uma caixa de combinação.|
|[CComboBox::FindStringExact](#findstringexact)|Encontra a primeira seqüência de caixa de lista (em uma caixa de combinação) que corresponde à seqüência especificada.|
|[CComboBox::GetComboBoxInfo](#getcomboboxinfo)|Recupera informações sobre `CComboBox` o objeto.|
|[CComboBox::GetCount](#getcount)|Recupera o número de itens na caixa de lista de uma caixa de combinação.|
|[CComboBox::GetCueBanner](#getcuebanner)|Obtém o texto de sinalização exibido para um controle de caixa combo.|
|[CComboBox::GetCurSel](#getcursel)|Recupera o índice do item selecionado no momento, se houver, na caixa de lista de uma caixa de combinação.|
|[CComboBox::GetDroppedControlRect](#getdroppedcontrolrect)|Recupera as coordenadas de tela da caixa de lista visível (descartada) de uma caixa de combo para dada.|
|[CComboBox::GetDroppedState](#getdroppedstate)|Determina se a caixa de lista de uma caixa de combo parada está visível (caiu).|
|[CComboBox::GetD'sroppedWidth](#getdroppedwidth)|Recupera a largura mínima permitida para a parte de caixa de lista gota de uma caixa de combinação.|
|[CComboBox::GetEditSel](#geteditsel)|Obtém as posições de caracteres de início e final da seleção atual no controle de edição de uma caixa de combinação.|
|[CComboBox::GetExtendedUI](#getextendedui)|Determina se uma caixa de combinação tem a interface de usuário padrão ou a interface de usuário estendida.|
|[CComboBox::GetHorizontalExtent](#gethorizontalextent)|Retorna a largura em pixels que a parte de caixa de lista da caixa de combinação pode ser rolada horizontalmente.|
|[CComboBox::GetItemData](#getitemdata)|Recupera o valor de 32 bits fornecido pelo aplicativo associado ao item combo-box especificado.|
|[CComboBox::GetItemDataPtr](#getitemdataptr)|Recupera o ponteiro de 32 bits fornecido pelo aplicativo que está associado ao item combo-box especificado.|
|[CComboBox::GetItemHeight](#getitemheight)|Recupera a altura dos itens da lista em uma caixa de combinação.|
|[CComboBox::GetLBText](#getlbtext)|Obtém uma seqüência da caixa de lista de uma caixa de combinação.|
|[CComboBox::GetLBTextLen](#getlbtextlen)|Obtém o comprimento de uma seqüência na caixa de lista de uma caixa de combinação.|
|[CComboBox::GetLocale](#getlocale)|Recupera o identificador local para uma caixa de combinação.|
|[CComboBox::GetMinVisible](#getminvisible)|Obtém o número mínimo de itens visíveis na lista de itens gotas da caixa de combinação atual.|
|[CComboBox::GetTopIndex](#gettopindex)|Retorna o índice do primeiro item visível na parte de caixa de lista da caixa de combinação.|
|[CComboBox::InitStorage](#initstorage)|Prealoca blocos de memória para itens e strings na parte de caixa de lista da caixa de combinação.|
|[CComboBox::InsertString](#insertstring)|Insere uma seqüência na caixa de lista de uma caixa de combinação.|
|[CComboBox::LimiteTexto](#limittext)|Limita o comprimento do texto que o usuário pode inserir no controle de edição de uma caixa de combinação.|
|[CComboBox::MeasureItem](#measureitem)|Chamado pela estrutura para determinar as dimensões da caixa de combinação quando uma caixa de combinação desenhada pelo proprietário é criada.|
|[CComboBox::Paste](#paste)|Insere os dados da Área de Transferência no controle de edição na posição atual do cursor. Os dados só são inseridos se a Área de Transferência contiver dados em CF_TEXT formato.|
|[CComboBox::Redefinirconteúdo](#resetcontent)|Remove todos os itens da caixa de lista e edita o controle de uma caixa de combinação.|
|[CComboBox::SelectString](#selectstring)|Procura uma seqüência na caixa de lista de uma caixa de combinação e, se a seqüência for encontrada, seleciona a string na caixa de lista e copia a seqüência de string para o controle de edição.|
|[CComboBox::SetCueBanner](#setcuebanner)|Define o texto de sinalização exibido para um controle de caixa combo.|
|[CComboBox::SetCurSel](#setcursel)|Seleciona uma seqüência na caixa de lista de uma caixa de combinação.|
|[CComboBox::Set's'sdelargura-feira](#setdroppedwidth)|Define a largura mínima permitida para a parte de caixa de lista gota de uma caixa de combinação.|
|[CComboBox::SetEditSel](#seteditsel)|Seleciona caracteres no controle de edição de uma caixa de combinação.|
|[CComboBox::SetExtendedUI](#setextendedui)|Seleciona a interface de usuário padrão ou a interface de usuário estendida para uma caixa de combinação que tenha o estilo CBS_DROPDOWN ou CBS_DROPDOWNLIST.|
|[CComboBox::SetHorizontalExtent](#sethorizontalextent)|Define a largura em pixels que a parte de caixa de lista da caixa de combinação pode ser rolada horizontalmente.|
|[CComboBox::SetItemData](#setitemdata)|Define o valor de 32 bits associado ao item especificado em uma caixa de combinação.|
|[CComboBox::SetItemDataPtr](#setitemdataptr)|Define o ponteiro de 32 bits associado ao item especificado em uma caixa de combinação.|
|[CComboBox::SetItemHeight](#setitemheight)|Define a altura dos itens da lista em uma caixa de combinação ou a altura da parte de controle de edição (ou texto estático) de uma caixa de combinação.|
|[CComboBox::SetLocale](#setlocale)|Define o identificador local para uma caixa de combinação.|
|[CComboBox::SetMinVisibleItems](#setminvisibleitems)|Define o número mínimo de itens visíveis na lista de itens gotas da caixa de combinação atual.|
|[CComboBox::SetTopIndex](#settopindex)|Informa a parte de caixa de lista da caixa de combinação para exibir o item com o índice especificado na parte superior.|
|[CComboBox::ShowDropDown](#showdropdown)|Mostra ou esconde a caixa de lista de uma caixa de combinação que tem o estilo CBS_DROPDOWN ou CBS_DROPDOWNLIST.|

## <a name="remarks"></a>Comentários

Uma caixa de combinação consiste em uma caixa de lista combinada com um controle estático ou controle de edição. A parte de caixa de lista do controle pode ser exibida a todo momento ou só pode ser suspensa quando o usuário selecionar a seta suspensa ao lado do controle.

O item atualmente selecionado (se houver) na caixa de lista é exibido no controle estático ou editar. Além disso, se a caixa de combinação tiver o estilo de lista estéreo, o usuário poderá digitar o caractere inicial de um dos itens da lista, e a caixa de lista, se visível, destacará o próximo item com esse caractere inicial.

A tabela a seguir compara os três [estilos](../../mfc/reference/styles-used-by-mfc.md#combo-box-styles)de caixa de combinação .

|Estilo|Quando é caixa de lista visível|Controle estático ou editar|
|-----------|-------------------------------|-----------------------------|
|Simples|Sempre|Editar|
|Drop-down|Quando caiu|Editar|
|Lista de paradas|Quando caiu|Estático|

Você pode `CComboBox` criar um objeto a partir de um modelo de diálogo ou diretamente em seu código. Em ambos os casos, `CComboBox` primeiro chame `CComboBox` o construtor para construir o objeto; em seguida, chame a função [Criar](#create) membro `CComboBox` para criar o controle e anexá-lo ao objeto.

Se você quiser lidar com mensagens de notificação do Windows enviadas por `CDialog`uma caixa de combinação para seu pai (geralmente uma classe derivada), adicione uma função de membro do mapa de mensagem e do manipulador de mensagens à classe pai para cada mensagem.

Cada entrada de mapa de mensagem tem o seguinte formulário:

**ON\_**_Notification_ _(id_, _memberFxn_ **)** **(**

onde `id` especifica o ID da janela de criança do controle `memberFxn` da caixa de combinação que envia a notificação e é o nome da função de membro pai que você escreveu para lidar com a notificação.

O protótipo de função dos pais é o seguinte:

**afx_msg** `void` afx_msg `memberFxn` **(**

A ordem em que determinadas notificações serão enviadas não pode ser prevista. Em particular, uma notificação CBN_SELCHANGE pode ocorrer antes ou depois de uma notificação CBN_CLOSEUP.

As entradas potenciais do mapa de mensagens são as seguintes:

- ON_CBN_CLOSEUP (Windows 3.1 e posteriores.) A caixa de lista de uma caixa de combinação foi fechada. Esta mensagem de notificação não é enviada para uma caixa de combinação que tenha o estilo [CBS_SIMPLE.](../../mfc/reference/styles-used-by-mfc.md#combo-box-styles)

- ON_CBN_DBLCLK O usuário clica duas vezes em uma seqüência na caixa de lista de uma caixa de combinação. Esta mensagem de notificação só é enviada para uma caixa de combinação com o estilo CBS_SIMPLE. Para uma caixa de combinação com o estilo [CBS_DROPDOWN](../../mfc/reference/styles-used-by-mfc.md#combo-box-styles) ou [CBS_DROPDOWNLIST,](../../mfc/reference/styles-used-by-mfc.md#combo-box-styles) um duplo clique não pode ocorrer porque um único clique oculta a caixa de lista.

- ON_CBN_DROPDOWN A caixa de lista de uma caixa de combinação está prestes a ser derrubada (seja visível). Esta mensagem de notificação só pode ocorrer para uma caixa de combinação com o estilo CBS_DROPDOWN ou CBS_DROPDOWNLIST.

- ON_CBN_EDITCHANGE O usuário tomou uma ação que pode ter alterado o texto na parte de controle de edição de uma caixa de combinação. Ao contrário da mensagem CBN_EDITUPDATE, esta mensagem é enviada após o Windows atualizar a tela. Não é enviado se a caixa de combinação tem o estilo CBS_DROPDOWNLIST.

- ON_CBN_EDITUPDATE A parte de controle de edição de uma caixa de combinação está prestes a exibir texto alterado. Esta mensagem de notificação é enviada após o controle formatar o texto, mas antes de exibir o texto. Não é enviado se a caixa de combinação tem o estilo CBS_DROPDOWNLIST.

- ON_CBN_ERRSPACE A caixa de combinação não pode alocar memória suficiente para atender a uma solicitação específica.

- ON_CBN_SELENDCANCEL (Windows 3.1 e posteriores.) Indica que a seleção do usuário deve ser cancelada. O usuário clica em um item e, em seguida, clica em outra janela ou controle para ocultar a caixa de lista de uma caixa de combinação. Esta mensagem de notificação é enviada antes da mensagem de notificação CBN_CLOSEUP para indicar que a seleção do usuário deve ser ignorada. A mensagem de notificação CBN_SELENDCANCEL ou CBN_SELENDOK é enviada mesmo que a mensagem de notificação CBN_CLOSEUP não seja enviada (como no caso de uma caixa de combinação com o estilo CBS_SIMPLE).

- ON_CBN_SELENDOK O usuário seleciona um item e, em seguida, pressiona a tecla ENTER ou clica na tecla SETA para baixo para ocultar a caixa de lista de uma caixa de combinação. Esta mensagem de notificação é enviada antes da mensagem CBN_CLOSEUP para indicar que a seleção do usuário deve ser considerada válida. A mensagem de notificação CBN_SELENDCANCEL ou CBN_SELENDOK é enviada mesmo que a mensagem de notificação CBN_CLOSEUP não seja enviada (como no caso de uma caixa de combinação com o estilo CBS_SIMPLE).

- ON_CBN_KILLFOCUS A caixa de combinação está perdendo o foco de entrada.

- ON_CBN_SELCHANGE A seleção na caixa de lista de uma caixa de combinação está prestes a ser alterada como resultado do usuário clicar na caixa de lista ou alterar a seleção usando as teclas de seta. Ao processar esta mensagem, o texto no controle de edição da `GetLBText` caixa de combinação só pode ser recuperado via ou outra função semelhante. `GetWindowText`não pode ser usado.

- ON_CBN_SETFOCUS A caixa de combinação recebe o foco de entrada.

Se você `CComboBox` criar um objeto dentro de uma `CComboBox` caixa de diálogo (através de um recurso de diálogo), o objeto será automaticamente destruído quando o usuário fechar a caixa de diálogo.

Se você incorporar `CComboBox` um objeto dentro de outro objeto de janela, você não precisa destruí-lo. Se você `CComboBox` criar o objeto na pilha, ele será destruído automaticamente. Se você `CComboBox` criar o objeto no heap usando a **nova** função, você deve chamar **excluir** no objeto para destruí-lo quando a caixa de combinação do Windows for destruída.

**Nota** Se você quiser lidar com mensagens WM_KEYDOWN e WM_CHAR, você tem que subclassificar os controles `CEdit` `CListBox`de edição e caixa de lista da caixa de combinação, derivar classes e , e adicionar manipuladores para essas mensagens para as classes derivadas. Para obter mais informações, consulte [CWnd::SubclassWindow](../../mfc/reference/cwnd-class.md#subclasswindow).

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

[Cobject](../../mfc/reference/cobject-class.md)

[Ccmdtarget](../../mfc/reference/ccmdtarget-class.md)

[CWnd](../../mfc/reference/cwnd-class.md)

`CComboBox`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** afxwin.h

## <a name="ccomboboxaddstring"></a><a name="addstring"></a>CComboBox::AddString

Adiciona uma seqüência à caixa de lista de uma caixa de combinação.

```
int AddString(LPCTSTR lpszString);
```

### <a name="parameters"></a>Parâmetros

*lpszString*<br/>
Aponta para a seqüência de terminadas nula que deve ser adicionada.

### <a name="return-value"></a>Valor retornado

Se o valor de retorno for maior ou igual a 0, será o índice baseado em zero para a string na caixa de lista. O valor de retorno é CB_ERR se ocorrer um erro; o valor de retorno é CB_ERRSPACE se houver espaço insuficiente para armazenar a nova string.

### <a name="remarks"></a>Comentários

Se a caixa de lista não foi criada com o estilo [CBS_SORT,](../../mfc/reference/styles-used-by-mfc.md#combo-box-styles) a seqüência será adicionada ao final da lista. Caso contrário, a seqüência é inserida na lista, e a lista é classificada.

> [!NOTE]
> Esta função não é suportada pelo controle do Windows. `ComboBoxEx` Para obter mais informações sobre este controle, consulte [Controles ComboBoxEx](/windows/win32/Controls/comboboxex-controls) no SDK do Windows.

Para inserir uma seqüência em um local específico dentro da lista, use a função [insertString](#insertstring) member.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFC_CComboBox#3](../../mfc/reference/codesnippet/cpp/ccombobox-class_1.cpp)]

## <a name="ccomboboxccombobox"></a><a name="ccombobox"></a>CComboBox::CComboBox

Constrói um objeto `CComboBox`.

```
CComboBox();
```

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFC_CComboBox#1](../../mfc/reference/codesnippet/cpp/ccombobox-class_2.cpp)]

## <a name="ccomboboxclear"></a><a name="clear"></a>CComboBox::Clear

Exclui (limpa) a seleção atual, se houver, no controle de edição da caixa de combinação.

```
void Clear();
```

### <a name="remarks"></a>Comentários

Para excluir a seleção atual e colocar os conteúdos excluídos na área de transferência, use a função ['Cortar](#cut) membro'.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFC_CComboBox#4](../../mfc/reference/codesnippet/cpp/ccombobox-class_3.cpp)]

## <a name="ccomboboxcompareitem"></a><a name="compareitem"></a>CComboBox::CompareItem

Chamado pela estrutura para determinar a posição relativa de um novo item na parte de caixa de lista de uma caixa de combinação proprietário-sorteio ordenado.

```
virtual int CompareItem(LPCOMPAREITEMSTRUCT lpCompareItemStruct);
```

### <a name="parameters"></a>Parâmetros

*lpCompareItemStruct*<br/>
Um ponteiro longo para uma estrutura [COMPAREITEMSTRUCT.](/windows/win32/api/winuser/ns-winuser-compareitemstruct)

### <a name="return-value"></a>Valor retornado

Indica a posição relativa dos dois itens `COMPAREITEMSTRUCT` descritos na estrutura. Pode ser qualquer um dos seguintes valores:

|Valor|Significado|
|-----------|-------------|
|- 1|Item 1 classificaantes do item 2.|
|0|O item 1 e o item 2 classificam o mesmo.|
|1|Item 1 classifica após o item 2.|

Consulte [CWnd::OnCompareItem](../../mfc/reference/cwnd-class.md#oncompareitem) para `COMPAREITEMSTRUCT`obter uma descrição de .

### <a name="remarks"></a>Comentários

Por padrão, esta função de membro não faz nada. Se você criar uma caixa de combinação de sorteio do proprietário com o estilo LBS_SORT, você deve substituir essa função de membro para ajudar a estrutura na classificação de novos itens adicionados à caixa de lista.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFC_CComboBox#5](../../mfc/reference/codesnippet/cpp/ccombobox-class_4.cpp)]

## <a name="ccomboboxcopy"></a><a name="copy"></a>CComboBox::Copiar

Copia a seleção atual, se houver, no controle de edição da caixa de combinação na Área de Transferência em formato CF_TEXT.

```
void Copy();
```

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFC_CComboBox#6](../../mfc/reference/codesnippet/cpp/ccombobox-class_5.cpp)]

## <a name="ccomboboxcreate"></a><a name="create"></a>CComboBox::Criar

Cria a caixa de combinação e `CComboBox` a prende ao objeto.

```
virtual BOOL Create(
    DWORD dwStyle,
    const RECT& rect,
    CWnd* pParentWnd,
    UINT nID);
```

### <a name="parameters"></a>Parâmetros

*Dwstyle*<br/>
Especifica o estilo da caixa de combinação. Aplique qualquer combinação de [estilos de caixa de combinação](../../mfc/reference/styles-used-by-mfc.md#combo-box-styles) à caixa.

*Rect*<br/>
Aponta para a posição e o tamanho da caixa de combinação. Pode ser uma estrutura `CRect` [RECT](/windows/win32/api/windef/ns-windef-rect) ou um objeto.

*Pparentwnd*<br/>
Especifica a janela pai da caixa de `CDialog`combinação (geralmente a ). Não deve ser NULO.

*nID*<br/>
Especifica o ID de controle da caixa de combinação.

### <a name="return-value"></a>Valor retornado

Não zero se bem sucedido; caso contrário, 0.

### <a name="remarks"></a>Comentários

Você constrói `CComboBox` um objeto em dois passos. Primeiro, ligue para o `Create`construtor e, em seguida, ligue, que `CComboBox` cria a caixa de combinação do Windows e a anexa ao objeto.

Quando `Create` é executado, o Windows envia as [mensagens WM_NCCREATE,](../../mfc/reference/cwnd-class.md#onnccreate) [WM_CREATE](../../mfc/reference/cwnd-class.md#oncreate) [WM_NCCALCSIZE](../../mfc/reference/cwnd-class.md#onnccalcsize)e [WM_GETMINMAXINFO](../../mfc/reference/cwnd-class.md#ongetminmaxinfo) para a caixa de combinação.

Essas mensagens são tratadas por padrão pelas funções de membro [OnNcCreate,](../../mfc/reference/cwnd-class.md#onnccreate) [OnCreate,](../../mfc/reference/cwnd-class.md#oncreate) [OnNcCalcSize](../../mfc/reference/cwnd-class.md#onnccalcsize)e [OnGetMinMaxInfo](../../mfc/reference/cwnd-class.md#ongetminmaxinfo) na `CWnd` classe base. Para estender o tratamento padrão da `CComboBox`mensagem, obtenha uma classe de , adicione um mapa de mensagem à nova classe e anule as funções anteriores do membro do manipulador de mensagens. Substituição, `OnCreate`por exemplo, para realizar a inicialização necessária para uma nova classe.

Aplique os [seguintes estilos de janela](../../mfc/reference/styles-used-by-mfc.md#window-styles) a um controle de caixa de combinação. :

- WS_CHILD Sempre

- WS_VISIBLE Normalmente

- WS_DISABLED raramente

- WS_VSCROLL Para adicionar rolagem vertical para a caixa de lista na caixa de combinação

- WS_HSCROLL Para adicionar rolagem horizontal para a caixa de lista na caixa de combinação

- WS_GROUP Para controles de grupo

- WS_TABSTOP Para incluir a caixa de combinação na ordem de abas

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFC_CComboBox#2](../../mfc/reference/codesnippet/cpp/ccombobox-class_6.cpp)]

## <a name="ccomboboxcut"></a><a name="cut"></a>CComboBox::Corte

Exclui (corta) a seleção atual, se houver, no controle de edição da caixa de combinação e copia o texto excluído na Área de Transferência em formato CF_TEXT.

```
void Cut();
```

### <a name="remarks"></a>Comentários

Para excluir a seleção atual sem colocar o texto excluído na Área de Transferência, ligue para a função ['Limpar](#clear) membro'.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFC_CComboBox#7](../../mfc/reference/codesnippet/cpp/ccombobox-class_7.cpp)]

## <a name="ccomboboxdeleteitem"></a><a name="deleteitem"></a>CComboBox::DeleteItem

Chamado pela estrutura quando o usuário exclui um item de um objeto de saque `CComboBox` do proprietário ou destrói a caixa de combinação.

```
virtual void DeleteItem(LPDELETEITEMSTRUCT lpDeleteItemStruct);
```

### <a name="parameters"></a>Parâmetros

*lpDeleteItemStruct*<br/>
Um ponteiro longo para uma estrutura DO Windows [DELETEITEMSTRUCT](/windows/win32/api/winuser/ns-winuser-deleteitemstruct) que contém informações sobre o item excluído. Consulte [CWnd::OnDeleteItem](../../mfc/reference/cwnd-class.md#ondeleteitem) para obter uma descrição desta estrutura.

### <a name="remarks"></a>Comentários

A implementação padrão desta função não faz nada. Anular esta função para redesenhar a caixa de combinação conforme necessário.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFC_CComboBox#8](../../mfc/reference/codesnippet/cpp/ccombobox-class_8.cpp)]

## <a name="ccomboboxdeletestring"></a><a name="deletestring"></a>CComboBox::DeleteString

Exclui o item na posição *nIndex* da caixa de combinação.

```
int DeleteString(UINT nIndex);
```

### <a name="parameters"></a>Parâmetros

*nIndex*<br/>
Especifica o índice para a seqüência de string a ser excluída.

### <a name="return-value"></a>Valor retornado

Se o valor de retorno for maior ou igual a 0, então é uma contagem das strings restantes na lista. O valor de retorno é CB_ERR se *nIndex* especificar um índice maior do que o número de itens da lista.

### <a name="remarks"></a>Comentários

Todos os itens que seguem *o nIndex* agora descem uma posição. Por exemplo, se uma caixa de combinação contiver dois itens, a exclusão do primeiro item fará com que o item restante esteja agora na primeira posição. *nIndex*=0 para o item na primeira posição.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFC_CComboBox#9](../../mfc/reference/codesnippet/cpp/ccombobox-class_9.cpp)]

## <a name="ccomboboxdir"></a><a name="dir"></a>CComboBox::Dir

Adiciona uma lista de nomes de arquivos ou unidades à caixa de lista de uma caixa de combinação.

```
int Dir(
    UINT attr,
    LPCTSTR lpszWildCard);
```

### <a name="parameters"></a>Parâmetros

*Attr*<br/>
Pode ser qualquer combinação dos valores **de enum** descritos em [CFile::GetStatus](../../mfc/reference/cfile-class.md#getstatus) ou qualquer combinação dos seguintes valores:

- DDL_READWRITE Arquivo pode ser lido ou escrito para.

- DDL_READONLY Arquivo pode ser lido, mas não escrito para.

- DDL_HIDDEN Arquivo está oculto e não aparece em uma listagem de diretório.

- DDL_SYSTEM File é um arquivo do sistema.

- DDL_DIRECTORY O nome especificado pelo *lpszWildCard* especifica um diretório.

- DDL_ARCHIVE arquivo foi arquivado.

- DDL_DRIVES Incluir todas as unidades que correspondam ao nome especificado pelo *lpszWildCard*.

- DDL_EXCLUSIVE bandeira exclusiva. Se o sinalizador exclusivo estiver definido, apenas arquivos do tipo especificado serão listados. Caso contrário, os arquivos do tipo especificado são listados, além de arquivos "normais".

*Lpszwildcard*<br/>
Aponta para uma seqüência de especificação de arquivo. A corda pode conter curingas\*(por exemplo, *. ).

### <a name="return-value"></a>Valor retornado

Se o valor de retorno for maior ou igual a 0, é o índice baseado em zero do último nome de arquivo adicionado à lista. O valor de retorno é CB_ERR se ocorrer um erro; o valor de retorno é CB_ERRSPACE se houver espaço insuficiente para armazenar as novas cordas.

### <a name="remarks"></a>Comentários

Esta função não é suportada pelo controle do Windows. `ComboBoxEx` Para obter mais informações sobre este controle, consulte [Controles ComboBoxEx](/windows/win32/Controls/comboboxex-controls) no SDK do Windows.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFC_CComboBox#10](../../mfc/reference/codesnippet/cpp/ccombobox-class_10.cpp)]

## <a name="ccomboboxdrawitem"></a><a name="drawitem"></a>CComboBox::DrawItem

Chamado pela estrutura quando um aspecto visual de uma caixa de combinação proprietário-draw muda.

```
virtual void DrawItem(LPDRAWITEMSTRUCT lpDrawItemStruct);
```

### <a name="parameters"></a>Parâmetros

*Lpdrawitemstruct*<br/>
Um ponteiro para uma estrutura [DRAWITEMSTRUCT](/windows/win32/api/winuser/ns-winuser-drawitemstruct) que contém informações sobre o tipo de desenho necessário.

### <a name="remarks"></a>Comentários

O `itemAction` membro `DRAWITEMSTRUCT` da estrutura define a ação de desenho a ser realizada. Consulte [CWnd::OnDrawItem](../../mfc/reference/cwnd-class.md#ondrawitem) para obter uma descrição desta estrutura.

Por padrão, esta função de membro não faz nada. Substituir esta função de membro para implementar `CComboBox` o desenho para um objeto de desenho do proprietário. Antes que essa função de membro seja encerrada, o aplicativo deve restaurar todos os objetos GDI (Graphics Device Interface, interface de dispositivo gráfico) selecionados para o contexto de exibição fornecido no *lpDrawItemStruct*.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFC_CComboBox#11](../../mfc/reference/codesnippet/cpp/ccombobox-class_11.cpp)]

## <a name="ccomboboxfindstring"></a><a name="findstring"></a>CComboBox::FindString

Achados, mas não selecionam, a primeira string que contém o prefixo especificado na caixa de lista de uma caixa de combinação.

```
int FindString(
    int nStartAfter,
    LPCTSTR lpszString) const;
```

### <a name="parameters"></a>Parâmetros

*nStartAfter*<br/>
Contém o índice baseado em zero do item antes do primeiro item a ser pesquisado. Quando a pesquisa chega à parte inferior da caixa de lista, ela continua do topo da caixa de lista de volta para o item especificado por *nStartAfter*. Se -1, a caixa de lista inteira é pesquisada desde o início.

*lpszString*<br/>
Aponta para a seqüência de terminadas nula que contém o prefixo a ser pesquisado. A pesquisa é independente do caso, de modo que esta seqüência pode conter qualquer combinação de letras maiúsculas e minúsculas.

### <a name="return-value"></a>Valor retornado

Se o valor de retorno for maior ou igual a 0, é o índice baseado em zero do item correspondente. É CB_ERR se a busca não teve sucesso.

### <a name="remarks"></a>Comentários

Esta função não é suportada pelo controle do Windows. `ComboBoxEx` Para obter mais informações sobre este controle, consulte [Controles ComboBoxEx](/windows/win32/Controls/comboboxex-controls) no SDK do Windows.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFC_CComboBox#12](../../mfc/reference/codesnippet/cpp/ccombobox-class_12.cpp)]

## <a name="ccomboboxfindstringexact"></a><a name="findstringexact"></a>CComboBox::FindStringExact

Ligue `FindStringExact` para a função member para encontrar a primeira seqüência de caixa de lista (em uma caixa de combinação) que corresponda à seqüência especificada no *lpszFind*.

```
int FindStringExact(
    int nIndexStart,
    LPCTSTR lpszFind) const;
```

### <a name="parameters"></a>Parâmetros

*Nindexstart*<br/>
Especifica o índice baseado em zero do item antes do primeiro item a ser pesquisado. Quando a pesquisa chega à parte inferior da caixa de lista, ela continua do topo da caixa de lista de volta para o item especificado pelo *nIndexStart*. Se *nIndexStart* for -1, toda a caixa de lista será pesquisada desde o início.

*Lpszfind*<br/>
Aponta para a seqüência de nulidade sumida para procurar. Esta seqüência pode conter um nome de arquivo completo, incluindo a extensão. A pesquisa não é sensível ao caso, então esta seqüência pode conter qualquer combinação de letras maiúsculas e minúsculas.

### <a name="return-value"></a>Valor retornado

O índice baseado em zero do item correspondente ou CB_ERR se a pesquisa não foi bem sucedida.

### <a name="remarks"></a>Comentários

Se a caixa de combinação foi criada com um estilo `FindStringExact` de sorteio do proprietário, mas sem o estilo [CBS_HASSTRINGS,](../../mfc/reference/styles-used-by-mfc.md#combo-box-styles) tente igualar o valor da palavra dupla com o valor de *lpszFind*.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFC_CComboBox#13](../../mfc/reference/codesnippet/cpp/ccombobox-class_13.cpp)]

## <a name="ccomboboxgetcomboboxinfo"></a><a name="getcomboboxinfo"></a>CComboBox::GetComboBoxInfo

Recupera informações para `CComboBox` o objeto.

```
BOOL GetComboBoxInfo(PCOMBOBOXINFO pcbi) const;
```

### <a name="parameters"></a>Parâmetros

*pcbi*<br/>
Um ponteiro para a estrutura [COMBOBOXINFO.](/windows/win32/api/winuser/ns-winuser-comboboxinfo)

### <a name="return-value"></a>Valor retornado

Retorna TRUE no sucesso, FALSO no fracasso.

### <a name="remarks"></a>Comentários

Esta função membro emula a funcionalidade da mensagem [CB_GETCOMBOBOXINFO,](/windows/win32/Controls/cb-getcomboboxinfo) conforme descrito no SDK do Windows.

## <a name="ccomboboxgetcount"></a><a name="getcount"></a>CComboBox::GetCount

Ligue para esta função de membro para recuperar o número de itens na parte de caixa de lista de uma caixa de combinação.

```
int GetCount() const;
```

### <a name="return-value"></a>Valor retornado

O número de itens. A contagem retornada é maior que o valor do índice do último item (o índice é baseado em zero). É CB_ERR se ocorrer um erro.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFC_CComboBox#14](../../mfc/reference/codesnippet/cpp/ccombobox-class_14.cpp)]

## <a name="ccomboboxgetcuebanner"></a><a name="getcuebanner"></a>CComboBox::GetCueBanner

Obtém o texto de sinalização exibido para um controle de caixa combo.

```
CString GetCueBanner() const;

BOOL GetCueBanner(
    LPTSTR lpszText,
    int cchText) const;
```

### <a name="parameters"></a>Parâmetros

|Parâmetro|Descrição|
|---------------|-----------------|
|*lpszText*|[fora] Pointer para um buffer que recebe o texto do banner de sinalização.|
|*cchText*|[em] Tamanho do buffer que o parâmetro *lpszText* aponta.|

### <a name="return-value"></a>Valor retornado

Na primeira sobrecarga, um objeto [CString](../../atl-mfc-shared/using-cstring.md) que contém o texto do banner de sinalização se ele existir; caso contrário, `CString` um objeto que tem comprimento zero.

-ou-

Na segunda sobrecarga, TRUE se este método for bem sucedido; caso contrário, FALSE.

### <a name="remarks"></a>Comentários

O texto de sugestão é um prompt exibido na área de entrada do controle da caixa de combinação. O texto da sugestão é exibido até que o usuário forneça entrada.

Este método envia a mensagem [CB_GETCUEBANNER,](/windows/win32/Controls/cb-getcuebanner) que é descrita no SDK do Windows.

## <a name="ccomboboxgetcursel"></a><a name="getcursel"></a>CComboBox::GetCurSel

Ligue para esta função de membro para determinar qual item na caixa de combinação está selecionado.

```
int GetCurSel() const;
```

### <a name="return-value"></a>Valor retornado

O índice baseado em zero do item selecionado no momento na caixa de lista de uma caixa de combinação ou CB_ERR se nenhum item for selecionado.

### <a name="remarks"></a>Comentários

`GetCurSel`retorna um índice na lista.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFC_CComboBox#15](../../mfc/reference/codesnippet/cpp/ccombobox-class_15.cpp)]

## <a name="ccomboboxgetdroppedcontrolrect"></a><a name="getdroppedcontrolrect"></a>CComboBox::GetDroppedControlRect

Ligue `GetDroppedControlRect` para a função membro para recuperar as coordenadas de tela da caixa de lista visível (descartada) de uma caixa de combo para dada.

```
void GetDroppedControlRect(LPRECT lprect) const;
```

### <a name="parameters"></a>Parâmetros

*Lprect*<br/>
Aponta para a [estrutura RECT](/windows/win32/api/windef/ns-windef-rect) que deve receber as coordenadas.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFC_CComboBox#16](../../mfc/reference/codesnippet/cpp/ccombobox-class_16.cpp)]

## <a name="ccomboboxgetdroppedstate"></a><a name="getdroppedstate"></a>CComboBox::GetDroppedState

Ligue `GetDroppedState` para a função membro para determinar se a caixa de lista de uma caixa de combo para cada gota está visível (caiu).

```
BOOL GetDroppedState() const;
```

### <a name="return-value"></a>Valor retornado

Não zero se a caixa de lista estiver visível; caso contrário, 0.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFC_CComboBox#17](../../mfc/reference/codesnippet/cpp/ccombobox-class_17.cpp)]

## <a name="ccomboboxgetdroppedwidth"></a><a name="getdroppedwidth"></a>CComboBox::GetD'sroppedWidth

Chame esta função para recuperar a largura mínima permitida, em pixels, da caixa de lista de uma caixa de combinação.

```
int GetDroppedWidth() const;
```

### <a name="return-value"></a>Valor retornado

Se for bem-sucedido, a largura mínima permitida, em pixels; caso contrário, CB_ERR.

### <a name="remarks"></a>Comentários

Esta função só se aplica a caixas de combinação com o [estilo CBS_DROPDOWN](../../mfc/reference/styles-used-by-mfc.md#combo-box-styles) ou [CBS_DROPDOWNLIST.](../../mfc/reference/styles-used-by-mfc.md#combo-box-styles)

Por padrão, a largura mínima permitida da caixa de lista gotícula é 0. A largura mínima permitida pode ser definida chamando [SetDroppedWidth](#setdroppedwidth). Quando a parte da caixa de lista da caixa de combinação é exibida, sua largura é maior da largura mínima permitida ou da largura da caixa combo.

### <a name="example"></a>Exemplo

  Veja o exemplo de [SetDroppedWidth](#setdroppedwidth).

## <a name="ccomboboxgeteditsel"></a><a name="geteditsel"></a>CComboBox::GetEditSel

Obtém as posições de caracteres de início e final da seleção atual no controle de edição de uma caixa de combinação.

```
DWORD GetEditSel() const;
```

### <a name="return-value"></a>Valor retornado

Um valor de 32 bits que contém a posição inicial na palavra de baixa ordem e a posição do primeiro caractere não selecionado após o fim da seleção na palavra de alta ordem. Se esta função for usada em uma caixa de combinação sem um controle de edição, CB_ERR é devolvida.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFC_CComboBox#18](../../mfc/reference/codesnippet/cpp/ccombobox-class_18.cpp)]

## <a name="ccomboboxgetextendedui"></a><a name="getextendedui"></a>CComboBox::GetExtendedUI

Ligue `GetExtendedUI` para a função member para determinar se uma caixa de combinação tem a interface de usuário padrão ou a interface de usuário estendida.

```
BOOL GetExtendedUI() const;
```

### <a name="return-value"></a>Valor retornado

Não zero se a caixa de combinação tiver a interface de usuário estendida; caso contrário, 0.

### <a name="remarks"></a>Comentários

A interface de usuário estendida pode ser identificada das seguintes maneiras:

- Clicando no controle estático exibe a caixa de lista apenas para caixas de combinação com o estilo [CBS_DROPDOWNLIST.](../../mfc/reference/styles-used-by-mfc.md#combo-box-styles)

- Pressionar a tecla SETA para baixo exibe a caixa de lista (F4 está desativado).

A rolagem no controle estático é desativada quando a lista de itens não está visível (as teclas de seta estão desativadas).

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFC_CComboBox#19](../../mfc/reference/codesnippet/cpp/ccombobox-class_19.cpp)]

## <a name="ccomboboxgethorizontalextent"></a><a name="gethorizontalextent"></a>CComboBox::GetHorizontalExtent

Recupera da caixa de combinação a largura em pixels pelas quais a parte de caixa de lista da caixa de combinação pode ser rolada horizontalmente.

```
UINT GetHorizontalExtent() const;
```

### <a name="return-value"></a>Valor retornado

A largura rolável da parte list-box da caixa de combinação, em pixels.

### <a name="remarks"></a>Comentários

Isso só é aplicável se a parte da caixa de lista da caixa de combinação tiver uma barra de rolagem horizontal.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFC_CComboBox#20](../../mfc/reference/codesnippet/cpp/ccombobox-class_20.cpp)]

## <a name="ccomboboxgetitemdata"></a><a name="getitemdata"></a>CComboBox::GetItemData

Recupera o valor de 32 bits fornecido pelo aplicativo associado ao item combo-box especificado.

```
DWORD_PTR GetItemData(int nIndex) const;
```

### <a name="parameters"></a>Parâmetros

*nIndex*<br/>
Contém o índice baseado em zero de um item na caixa de lista da caixa de combinação.

### <a name="return-value"></a>Valor retornado

O valor de 32 bits associado ao item ou CB_ERR se ocorrer um erro.

### <a name="remarks"></a>Comentários

O valor de 32 bits pode ser definido com o parâmetro *dwItemData* de uma chamada de função de membro [SetItemData.](#setitemdata) Use `GetItemDataPtr` a função de membro se o valor de 32 bits a ser recuperado for um ponteiro **(vazio).** <strong>\*</strong>

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFC_CComboBox#21](../../mfc/reference/codesnippet/cpp/ccombobox-class_21.cpp)]

## <a name="ccomboboxgetitemdataptr"></a><a name="getitemdataptr"></a>CComboBox::GetItemDataPtr

Recupera o valor de 32 bits fornecido pelo aplicativo associado ao item combo-box especificado como ponteiro **(vazio).** <strong>\*</strong>

```
void* GetItemDataPtr(int nIndex) const;
```

### <a name="parameters"></a>Parâmetros

*nIndex*<br/>
Contém o índice baseado em zero de um item na caixa de lista da caixa de combinação.

### <a name="return-value"></a>Valor retornado

Recupera um ponteiro ou -1 se ocorrer um erro.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFC_CComboBox#22](../../mfc/reference/codesnippet/cpp/ccombobox-class_22.cpp)]

## <a name="ccomboboxgetitemheight"></a><a name="getitemheight"></a>CComboBox::GetItemHeight

Ligue `GetItemHeight` para a função membro para recuperar a altura dos itens da lista em uma caixa de combinação.

```
int GetItemHeight(int nIndex) const;
```

### <a name="parameters"></a>Parâmetros

*nIndex*<br/>
Especifica o componente da caixa de combinação cuja altura deve ser recuperada. Se o parâmetro *nIndex* for -1, a altura da parte de controle de edição (ou texto estático) da caixa de combinação será recuperada. Se a caixa de combinação tiver o estilo [CBS_OWNERDRAWVARIABLE,](../../mfc/reference/styles-used-by-mfc.md#combo-box-styles) *o nIndex* especificar o índice baseado em zero do item da lista cuja altura deve ser recuperada. Caso contrário, *nIndex* deve ser definido como 0.

### <a name="return-value"></a>Valor retornado

A altura, em pixels, do item especificado em uma caixa combo. O valor de retorno é CB_ERR se ocorrer um erro.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFC_CComboBox#23](../../mfc/reference/codesnippet/cpp/ccombobox-class_23.cpp)]

## <a name="ccomboboxgetlbtext"></a><a name="getlbtext"></a>CComboBox::GetLBText

Obtém uma seqüência da caixa de lista de uma caixa de combinação.

```
int GetLBText(
    int nIndex,
    LPTSTR lpszText) const;

void GetLBText(
    int nIndex,
    CString& rString) const;
```

### <a name="parameters"></a>Parâmetros

*nIndex*<br/>
Contém o índice baseado em zero da string list-box a ser copiado.

*lpszText*<br/>
Aponta para um buffer que é para receber a string. O buffer deve ter espaço suficiente para a seqüência e um caractere nulo final.

*rString*<br/>
Uma referência a um `CString`.

### <a name="return-value"></a>Valor retornado

O comprimento (em bytes) da seqüência, excluindo o caractere nulo final. Se *nIndex* não especificar um índice válido, o valor de retorno será CB_ERR.

### <a name="remarks"></a>Comentários

A segunda forma desta função `CString` membro preenche um objeto com o texto do item.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFC_CComboBox#24](../../mfc/reference/codesnippet/cpp/ccombobox-class_24.cpp)]

## <a name="ccomboboxgetlbtextlen"></a><a name="getlbtextlen"></a>CComboBox::GetLBTextLen

Obtém o comprimento de uma seqüência na caixa de lista de uma caixa de combinação.

```
int GetLBTextLen(int nIndex) const;
```

### <a name="parameters"></a>Parâmetros

*nIndex*<br/>
Contém o índice baseado em zero da seqüência de caixa de lista.

### <a name="return-value"></a>Valor retornado

O comprimento da seqüência em bytes, excluindo o caractere nulo terminante. Se *nIndex* não especificar um índice válido, o valor de retorno será CB_ERR.

### <a name="example"></a>Exemplo

  Veja o exemplo de [CComboBox::GetLBText](#getlbtext).

## <a name="ccomboboxgetlocale"></a><a name="getlocale"></a>CComboBox::GetLocale

Recupera o local usado pela caixa de combinação.

```
LCID GetLocale() const;
```

### <a name="return-value"></a>Valor retornado

O valor do identificador local (LCID) para as strings na caixa de combinação.

### <a name="remarks"></a>Comentários

O local é usado, por exemplo, para determinar a ordem de classificação das strings em uma caixa de combinação ordenada.

### <a name="example"></a>Exemplo

  Veja o exemplo de [CComboBox::SetLocale](#setlocale).

## <a name="ccomboboxgetminvisible"></a><a name="getminvisible"></a>CComboBox::GetMinVisible

Obtém o número mínimo de itens visíveis na lista de itens gotas do controle atual da caixa de combinação.

```
int GetMinVisible() const;
```

### <a name="return-value"></a>Valor retornado

O número mínimo de itens visíveis na lista de parada atual.

### <a name="remarks"></a>Comentários

Este método envia a [mensagem CB_GETMINVISIBLE,](/windows/win32/Controls/cb-setminvisible) que é descrita no SDK do Windows.

## <a name="ccomboboxgettopindex"></a><a name="gettopindex"></a>CComboBox::GetTopIndex

Recupera o índice baseado em zero do primeiro item visível na parte de caixa de lista da caixa de combinação.

```
int GetTopIndex() const;
```

### <a name="return-value"></a>Valor retornado

O índice baseado em zero do primeiro item visível na parte de caixa de lista da caixa de combinação se for bem-sucedido, CB_ERR de outra forma.

### <a name="remarks"></a>Comentários

Inicialmente, o item 0 está no topo da caixa da lista, mas se a caixa de lista estiver rolada, outro item pode estar no topo.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFC_CComboBox#25](../../mfc/reference/codesnippet/cpp/ccombobox-class_25.cpp)]

## <a name="ccomboboxinitstorage"></a><a name="initstorage"></a>CComboBox::InitStorage

Aloca a memória para armazenar itens da caixa de lista na parte de caixa de lista da caixa de combinação.

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

Se for bem-sucedido, o número máximo de itens que a parte de caixa de lista da caixa de combinação pode armazenar antes que uma realocação de memória seja necessária, caso contrário, CB_ERRSPACE, o que significa que não há memória suficiente disponível.

### <a name="remarks"></a>Comentários

Chame esta função antes de adicionar um grande número de `CComboBox`itens à parte de caixa de lista do .

Apenas windows 95/98: O parâmetro *wParam* é limitado a valores de 16 bits. Isso significa que as caixas de lista não podem conter mais de 32.767 itens. Embora o número de itens seja restrito, o tamanho total dos itens em uma caixa de lista é limitado apenas pela memória disponível.

Essa função ajuda a acelerar a inicialização de caixas de lista que possuem um grande número de itens (mais de 100). Ele pré-aloca a quantidade especificada de memória para que as funções subsequentes [AddString](#addstring), [InsertString](#insertstring)e [Dir](#dir) levem o menor tempo possível. Você pode usar estimativas para os parâmetros. Se você superestimar, alguma memória extra será alocada; se você subestimar, a alocação normal é usada para itens que excedam o valor pré-alocado.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFC_CComboBox#26](../../mfc/reference/codesnippet/cpp/ccombobox-class_26.cpp)]

## <a name="ccomboboxinsertstring"></a><a name="insertstring"></a>CComboBox::InsertString

Insere uma seqüência na caixa de lista de uma caixa de combinação.

```
int InsertString(
    int nIndex,
    LPCTSTR lpszString);
```

### <a name="parameters"></a>Parâmetros

*nIndex*<br/>
Contém o índice baseado em zero para a posição na caixa de lista que receberá a string. Se este parâmetro for -1, a seqüência será adicionada ao final da lista.

*lpszString*<br/>
Aponta para a seqüência de terminadas nula que deve ser inserida.

### <a name="return-value"></a>Valor retornado

O índice baseado em zero da posição em que a corda foi inserida. O valor de retorno é CB_ERR se ocorrer um erro. O valor de retorno é CB_ERRSPACE se houver espaço insuficiente para armazenar a nova seqüência.

### <a name="remarks"></a>Comentários

Ao contrário da função `InsertString` membro [AddString,](#addstring) a função membro não faz com que uma lista com o estilo [CBS_SORT](../../mfc/reference/styles-used-by-mfc.md#combo-box-styles) seja classificada.

> [!NOTE]
> Esta função não é suportada pelo controle do Windows. `ComboBoxEx` Para obter mais informações sobre este controle, consulte [Controles ComboBoxEx](/windows/win32/Controls/comboboxex-controls) no SDK do Windows.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFC_CComboBox#27](../../mfc/reference/codesnippet/cpp/ccombobox-class_27.cpp)]

## <a name="ccomboboxlimittext"></a><a name="limittext"></a>CComboBox::LimiteTexto

Limita o comprimento em bytes do texto que o usuário pode inserir no controle de edição de uma caixa de combinação.

```
BOOL LimitText(int nMaxChars);
```

### <a name="parameters"></a>Parâmetros

*nMaxChars*<br/>
Especifica o comprimento (em bytes) do texto que o usuário pode inserir. Se este parâmetro for 0, o comprimento do texto será definido como 65.535 bytes.

### <a name="return-value"></a>Valor retornado

Não zero se bem sucedido. Se for solicitado para uma caixa de combinação com o estilo [CBS_DROPDOWNLIST](../../mfc/reference/styles-used-by-mfc.md#combo-box-styles) ou para uma caixa de combinação sem um controle de edição, o valor de retorno é CB_ERR.

### <a name="remarks"></a>Comentários

Se a caixa de combinação não tiver o estilo [CBS_AUTOHSCROLL](../../mfc/reference/styles-used-by-mfc.md#combo-box-styles), definir o limite de texto para ser maior do que o tamanho do controle de edição não terá efeito.

`LimitText`limita apenas o texto que o usuário pode inserir. Não tem efeito sobre nenhum texto que já esteja no controle de edição quando a mensagem é enviada, nem afeta o comprimento do texto copiado para o controle de edição quando uma seqüência na caixa de lista é selecionada.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFC_CComboBox#28](../../mfc/reference/codesnippet/cpp/ccombobox-class_28.cpp)]

## <a name="ccomboboxmeasureitem"></a><a name="measureitem"></a>CComboBox::MeasureItem

Chamado pela estrutura quando uma caixa de combinação com um estilo de sorteio do proprietário é criada.

```
virtual void MeasureItem(LPMEASUREITEMSTRUCT lpMeasureItemStruct);
```

### <a name="parameters"></a>Parâmetros

*lpMeasureItemStruct*<br/>
Um ponteiro longo para uma estrutura [MEASUREITEMSTRUCT.](/windows/win32/api/winuser/ns-winuser-measureitemstruct)

### <a name="remarks"></a>Comentários

Por padrão, esta função de membro não faz nada. Anular esta função de membro `MEASUREITEMSTRUCT` e preencher a estrutura para informar o Windows das dimensões da caixa de lista na caixa de combinação. Se a caixa de combinação for criada com o estilo [CBS_OWNERDRAWVARIABLE,](../../mfc/reference/styles-used-by-mfc.md#combo-box-styles) a estrutura chamará essa função de membro para cada item na caixa de lista. Caso contrário, este membro é chamado apenas uma vez.

Usar o estilo CBS_OWNERDRAWFIXED em uma caixa de combinação de sorteio do proprietário `CWnd` criada com a função de membro [SubclassDlgItem](../../mfc/reference/cwnd-class.md#subclassdlgitem) envolve mais considerações de programação. Veja a discussão na [Nota Técnica 14](../../mfc/tn014-custom-controls.md).

Consulte [CWnd::OnMeasureItem](../../mfc/reference/cwnd-class.md#onmeasureitem) para obter `MEASUREITEMSTRUCT` uma descrição da estrutura.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFC_CComboBox#29](../../mfc/reference/codesnippet/cpp/ccombobox-class_29.cpp)]

## <a name="ccomboboxpaste"></a><a name="paste"></a>CComboBox::Paste

Insere os dados da Área de Transferência no controle de edição da caixa de combo na posição atual do cursor.

```
void Paste();
```

### <a name="remarks"></a>Comentários

Os dados só são inseridos se a Área de Transferência contiver dados em CF_TEXT formato.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFC_CComboBox#30](../../mfc/reference/codesnippet/cpp/ccombobox-class_30.cpp)]

## <a name="ccomboboxresetcontent"></a><a name="resetcontent"></a>CComboBox::Redefinirconteúdo

Remove todos os itens da caixa de lista e edita o controle de uma caixa de combinação.

```
void ResetContent();
```

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFC_CComboBox#31](../../mfc/reference/codesnippet/cpp/ccombobox-class_31.cpp)]

## <a name="ccomboboxselectstring"></a><a name="selectstring"></a>CComboBox::SelectString

Procura uma seqüência na caixa de lista de uma caixa de combinação e, se a seqüência for encontrada, seleciona a seqüência na caixa de lista e a copia para o controle de edição.

```
int SelectString(
    int nStartAfter,
    LPCTSTR lpszString);
```

### <a name="parameters"></a>Parâmetros

*nStartAfter*<br/>
Contém o índice baseado em zero do item antes do primeiro item a ser pesquisado. Quando a pesquisa chega à parte inferior da caixa de lista, ela continua do topo da caixa de lista de volta para o item especificado por *nStartAfter*. Se -1, a caixa de lista inteira é pesquisada desde o início.

*lpszString*<br/>
Aponta para a seqüência de terminadas nula que contém o prefixo a ser pesquisado. A pesquisa é independente do caso, de modo que esta seqüência pode conter qualquer combinação de letras maiúsculas e minúsculas.

### <a name="return-value"></a>Valor retornado

O índice baseado em zero do item selecionado se a seqüência foi encontrada. Se a pesquisa não foi bem sucedida, o valor de retorno será CB_ERR e a seleção atual não será alterada.

### <a name="remarks"></a>Comentários

Uma seqüência de caracteres é selecionada apenas se seus caracteres iniciais (do ponto de partida) coincidirem com os caracteres da seqüência de prefixo.

Observe que `SelectString` `FindString` as funções e membro encontram `SelectString` uma seqüência, mas a função membro também seleciona a string.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFC_CComboBox#32](../../mfc/reference/codesnippet/cpp/ccombobox-class_32.cpp)]

## <a name="ccomboboxsetcuebanner"></a><a name="setcuebanner"></a>CComboBox::SetCueBanner

Define o texto de sinalização exibido para um controle de caixa combo.

```
BOOL SetCueBanner(LPCTSTR lpszText);
```

### <a name="parameters"></a>Parâmetros

|Parâmetro|Descrição|
|---------------|-----------------|
|*lpszText*|[em] Ponteiro para um buffer com término nulo que contém o texto da deixa.|

### <a name="return-value"></a>Valor retornado

VERDADEIRO se o método for bem sucedido; caso contrário, FALSE.

### <a name="remarks"></a>Comentários

O texto de sugestão é um prompt exibido na área de entrada do controle da caixa de combinação. O texto da sugestão é exibido até que o usuário forneça entrada.

Este método envia a mensagem [CB_SETCUEBANNER,](/windows/win32/Controls/cb-setcuebanner) que é descrita no SDK do Windows.

### <a name="example"></a>Exemplo

O exemplo de código a seguir define a variável, *m_combobox*, que é usada para acessar programáticamente o controle da caixa de combinação. Esta variável é usada no próximo exemplo.

[!code-cpp[NVC_MFC_CComboBox_s1#1](../../mfc/reference/codesnippet/cpp/ccombobox-class_33.h)]

### <a name="example"></a>Exemplo

O exemplo de código a seguir define o banner de sinalização para o controle da caixa de combinação.

[!code-cpp[NVC_MFC_CComboBox_s1#2](../../mfc/reference/codesnippet/cpp/ccombobox-class_34.cpp)]

## <a name="ccomboboxsetcursel"></a><a name="setcursel"></a>CComboBox::SetCurSel

Seleciona uma seqüência na caixa de lista de uma caixa de combinação.

```
int SetCurSel(int nSelect);
```

### <a name="parameters"></a>Parâmetros

*Nselect*<br/>
Especifica o índice baseado em zero da string a ser selecionada. Se -1, qualquer seleção atual na caixa de lista será removida e o controle de edição será eliminado.

### <a name="return-value"></a>Valor retornado

O índice baseado em zero do item selecionado se a mensagem for bem sucedida. O valor de retorno é CB_ERR se *nSelect* for maior do que o número de itens da lista ou se *nSelect* estiver definido como -1, o que limpa a seleção.

### <a name="remarks"></a>Comentários

Se necessário, a caixa de lista rola a seqüência de string em exibição (se a caixa de lista estiver visível). O texto no controle de edição da caixa de combinação é alterado para refletir a nova seleção. Qualquer seleção anterior na caixa de lista é removida.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFC_CComboBox#33](../../mfc/reference/codesnippet/cpp/ccombobox-class_35.cpp)]

## <a name="ccomboboxsetdroppedwidth"></a><a name="setdroppedwidth"></a>CComboBox::Set's'sdelargura-feira

Chame esta função para definir a largura mínima permitida, em pixels, da caixa de lista de uma caixa de combinação.

```
int SetDroppedWidth(UINT nWidth);
```

### <a name="parameters"></a>Parâmetros

*Nwidth*<br/>
A largura mínima permitida da parte list-box da caixa de combinação, em pixels.

### <a name="return-value"></a>Valor retornado

Se for bem-sucedido, a nova largura da caixa de lista, caso contrário, CB_ERR.

### <a name="remarks"></a>Comentários

Esta função só se aplica a caixas de combinação com o [estilo CBS_DROPDOWN](../../mfc/reference/styles-used-by-mfc.md#combo-box-styles) ou [CBS_DROPDOWNLIST.](../../mfc/reference/styles-used-by-mfc.md#combo-box-styles)

Por padrão, a largura mínima permitida da caixa de lista gotícula é 0. Quando a parte da caixa de lista da caixa de combinação é exibida, sua largura é maior da largura mínima permitida ou da largura da caixa combo.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFC_CComboBox#34](../../mfc/reference/codesnippet/cpp/ccombobox-class_36.cpp)]

## <a name="ccomboboxseteditsel"></a><a name="seteditsel"></a>CComboBox::SetEditSel

Seleciona caracteres no controle de edição de uma caixa de combinação.

```
BOOL SetEditSel(
    int nStartChar,
    int nEndChar);
```

### <a name="parameters"></a>Parâmetros

*Nstartchar*<br/>
Especifica a posição inicial. Se a posição inicial estiver definida como -1, então qualquer seleção existente será removida.

*nEndChar*<br/>
Especifica a posição final. Se a posição final estiver definida como -1, então todo o texto da posição inicial até o último caractere no controle de edição será selecionado.

### <a name="return-value"></a>Valor retornado

Não zero se a função do membro for bem sucedida; caso contrário, 0. É CB_ERR `CComboBox` se tem o estilo [CBS_DROPDOWNLIST](../../mfc/reference/styles-used-by-mfc.md#combo-box-styles) ou não tem uma caixa de lista.

### <a name="remarks"></a>Comentários

As posições são baseadas em zero. Para selecionar o primeiro caractere do controle de edição, você especifica uma posição inicial de 0. A posição final é para o personagem logo após o último personagem a selecionar. Por exemplo, para selecionar os quatro primeiros caracteres do controle de edição, você usaria uma posição inicial de 0 e uma posição final de 4.

> [!NOTE]
> Esta função não é suportada pelo controle do Windows. `ComboBoxEx` Para obter mais informações sobre este controle, consulte [Controles ComboBoxEx](/windows/win32/Controls/comboboxex-controls) no SDK do Windows.

### <a name="example"></a>Exemplo

  Veja o exemplo de [CComboBox::GetEditSel](#geteditsel).

## <a name="ccomboboxsetextendedui"></a><a name="setextendedui"></a>CComboBox::SetExtendedUI

Ligue `SetExtendedUI` para a função member para selecionar a interface de usuário padrão ou a interface de usuário estendida para uma caixa de combinação que tenha o [estilo CBS_DROPDOWN](../../mfc/reference/styles-used-by-mfc.md#combo-box-styles) ou [CBS_DROPDOWNLIST.](../../mfc/reference/styles-used-by-mfc.md#combo-box-styles)

```
int SetExtendedUI(BOOL bExtended = TRUE);
```

### <a name="parameters"></a>Parâmetros

*bExtended*<br/>
Especifica se a caixa de combinação deve usar a interface de usuário estendida ou a interface de usuário padrão. Um valor de TRUE seleciona a interface de usuário estendida; um valor de FALSE seleciona a interface de usuário padrão.

### <a name="return-value"></a>Valor retornado

CB_OKAY se a operação for bem sucedida ou CB_ERR se ocorrer um erro.

### <a name="remarks"></a>Comentários

A interface de usuário estendida pode ser identificada das seguintes maneiras:

- Clicando no controle estático exibe a caixa de lista apenas para caixas de combinação com o estilo CBS_DROPDOWNLIST.

- Pressionar a tecla SETA para baixo exibe a caixa de lista (F4 está desativado).

A rolagem no controle estático é desativada quando a lista de itens não está visível (as teclas de seta estão desativadas).

### <a name="example"></a>Exemplo

  Veja o exemplo de [CComboBox::GetExtendedUI](#getextendedui).

## <a name="ccomboboxsethorizontalextent"></a><a name="sethorizontalextent"></a>CComboBox::SetHorizontalExtent

Define a largura, em pixels, pela qual a parte de caixa de lista da caixa de combinação pode ser rolada horizontalmente.

```
void SetHorizontalExtent(UINT nExtent);
```

### <a name="parameters"></a>Parâmetros

*nExtensão*<br/>
Especifica o número de pixels pelos quais a parte de caixa de lista da caixa de combinação pode ser rolada horizontalmente.

### <a name="remarks"></a>Comentários

Se a largura da caixa de lista for menor que esse valor, a barra de rolagem horizontal irá rolar horizontalmente itens na caixa de lista. Se a largura da caixa de lista for igual ou maior que esse valor, a barra de rolagem horizontal estará oculta ou, se a caixa de combinação tiver o estilo [CBS_DISABLENOSCROLL,](../../mfc/reference/styles-used-by-mfc.md#combo-box-styles) desativada.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFC_CComboBox#35](../../mfc/reference/codesnippet/cpp/ccombobox-class_37.cpp)]

## <a name="ccomboboxsetitemdata"></a><a name="setitemdata"></a>CComboBox::SetItemData

Define o valor de 32 bits associado ao item especificado em uma caixa de combinação.

```
int SetItemData(
    int nIndex,
    DWORD_PTR dwItemData);
```

### <a name="parameters"></a>Parâmetros

*nIndex*<br/>
Contém um índice baseado em zero para o item a definir.

*dwItemData*<br/>
Contém o novo valor para associar com o item.

### <a name="return-value"></a>Valor retornado

CB_ERR se ocorrer um erro.

### <a name="remarks"></a>Comentários

Use `SetItemDataPtr` a função de membro se o item de 32 bits for um ponteiro.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFC_CComboBox#36](../../mfc/reference/codesnippet/cpp/ccombobox-class_38.cpp)]

## <a name="ccomboboxsetitemdataptr"></a><a name="setitemdataptr"></a>CComboBox::SetItemDataPtr

Define o valor de 32 bits associado ao item especificado em uma caixa de combinação para ser o ponteiro especificado **(vazio** <strong>\*</strong>).

```
int SetItemDataPtr(
    int nIndex,
    void* pData);
```

### <a name="parameters"></a>Parâmetros

*nIndex*<br/>
Contém um índice baseado em zero no item.

*Pdata*<br/>
Contém o ponteiro para associar com o item.

### <a name="return-value"></a>Valor retornado

CB_ERR se ocorrer um erro.

### <a name="remarks"></a>Comentários

Este ponteiro permanece válido para a vida útil da caixa de combinação, mesmo que a posição relativa do item dentro da caixa de combinação possa mudar à medida que os itens forem adicionados ou removidos. Portanto, o índice do item dentro da caixa pode mudar, mas o ponteiro permanece confiável.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFC_CComboBox#37](../../mfc/reference/codesnippet/cpp/ccombobox-class_39.cpp)]

## <a name="ccomboboxsetitemheight"></a><a name="setitemheight"></a>CComboBox::SetItemHeight

Ligue `SetItemHeight` para a função membro para definir a altura dos itens da lista em uma caixa de combinação ou a altura da parte de controle de edição (ou texto estático) de uma caixa de combinação.

```
int SetItemHeight(
    int nIndex,
    UINT cyItemHeight);
```

### <a name="parameters"></a>Parâmetros

*nIndex*<br/>
Especifica se a altura dos itens da lista ou a altura da parte de controle de edição (ou texto estático) da caixa de combinação está definida.

Se a caixa de combinação tiver o estilo [CBS_OWNERDRAWVARIABLE,](../../mfc/reference/styles-used-by-mfc.md#combo-box-styles) *o nIndex* especificar o índice baseado em zero do item da lista cuja altura deve ser definida; caso contrário, *nIndex* deve ser 0 e a altura de todos os itens da lista será definida.

Se *nIndex* for -1, a altura da parte de edição-controle ou texto estático da caixa de combinação será definida.

*cyItemHeight*<br/>
Especifica a altura, em pixels, do componente combo-box identificado por *nIndex*.

### <a name="return-value"></a>Valor retornado

CB_ERR se o índice ou altura for inválido; caso contrário, 0.

### <a name="remarks"></a>Comentários

A altura da parte de controle de edição (ou texto estático) da caixa de combinação é definida independentemente da altura dos itens da lista. Um aplicativo deve garantir que a altura da parte de controle de edição (ou texto estático) não seja menor do que a altura de um item de caixa de lista em particular.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFC_CComboBox#38](../../mfc/reference/codesnippet/cpp/ccombobox-class_40.cpp)]

## <a name="ccomboboxsetlocale"></a><a name="setlocale"></a>CComboBox::SetLocale

Define o identificador local para esta caixa de combinação.

```
LCID SetLocale(LCID nNewLocale);
```

### <a name="parameters"></a>Parâmetros

*nNewLocale*<br/>
O novo identificador local (LCID) é definido para a caixa de combinação.

### <a name="return-value"></a>Valor retornado

O valor anterior do identificador local (LCID) para esta caixa de combinação.

### <a name="remarks"></a>Comentários

Se `SetLocale` não for chamado, o local padrão é obtido a partir do sistema. Este local padrão do sistema pode ser modificado usando a aplicação Regional (ou Internacional) do Painel de Controle.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFC_CComboBox#39](../../mfc/reference/codesnippet/cpp/ccombobox-class_41.cpp)]

## <a name="ccomboboxsetminvisibleitems"></a><a name="setminvisibleitems"></a>CComboBox::SetMinVisibleItems

Define o número mínimo de itens visíveis na lista de itens paradas do controle atual da caixa de combinação.

```
BOOL SetMinVisibleItems(int iMinVisible);
```

### <a name="parameters"></a>Parâmetros

|Parâmetro|Descrição|
|---------------|-----------------|
|*iMinVisible*|[em] Especifica o número mínimo de itens visíveis.|

### <a name="return-value"></a>Valor retornado

VERDADE se este método for bem sucedido; caso contrário, FALSE.

### <a name="remarks"></a>Comentários

Este método envia a mensagem [CB_SETMINVISIBLE,](/windows/win32/Controls/cb-setminvisible) que é descrita no SDK do Windows.

### <a name="example"></a>Exemplo

O exemplo de código a seguir define a variável, *m_combobox*, que é usada para acessar programáticamente o controle da caixa de combinação. Esta variável é usada no próximo exemplo.

[!code-cpp[NVC_MFC_CComboBox_s1#1](../../mfc/reference/codesnippet/cpp/ccombobox-class_33.h)]

### <a name="example"></a>Exemplo

O exemplo de código a seguir insere 20 itens na lista de itens a baixa de um controle de caixa combo. Em seguida, ele especifica que um mínimo de 10 itens serão exibidos quando um usuário pressiona a seta suspensa.

[!code-cpp[NVC_MFC_CComboBox_s1#2](../../mfc/reference/codesnippet/cpp/ccombobox-class_34.cpp)]

## <a name="ccomboboxsettopindex"></a><a name="settopindex"></a>CComboBox::SetTopIndex

Garante que um determinado item esteja visível na parte de caixa de lista da caixa de combinação.

```
int SetTopIndex(int nIndex);
```

### <a name="parameters"></a>Parâmetros

*nIndex*<br/>
Especifica o índice baseado em zero do item list-box.

### <a name="return-value"></a>Valor retornado

Zero se for bem sucedido, ou CB_ERR se ocorrer um erro.

### <a name="remarks"></a>Comentários

O sistema rola a caixa de lista até que o item especificado pelo *nIndex* apareça no topo da caixa de lista ou a faixa de rolagem máxima tenha sido atingida.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFC_CComboBox#40](../../mfc/reference/codesnippet/cpp/ccombobox-class_42.cpp)]

## <a name="ccomboboxshowdropdown"></a><a name="showdropdown"></a>CComboBox::ShowDropDown

Mostra ou esconde a caixa de lista de uma caixa de combinação que tem o [estilo CBS_DROPDOWN](../../mfc/reference/styles-used-by-mfc.md#combo-box-styles) ou [CBS_DROPDOWNLIST.](../../mfc/reference/styles-used-by-mfc.md#combo-box-styles)

```
void ShowDropDown(BOOL bShowIt = TRUE);
```

### <a name="parameters"></a>Parâmetros

*bShowIt*<br/>
Especifica se a caixa de lista baixa deve ser mostrada ou oculta. Um valor de TRUE mostra a caixa de lista. Um valor de FALSE esconde a caixa de lista.

### <a name="remarks"></a>Comentários

Por padrão, uma caixa combo deste estilo mostrará a caixa de lista.

Esta função de membro não tem efeito em uma caixa de combinação criada com o estilo [CBS_SIMPLE.](../../mfc/reference/styles-used-by-mfc.md#combo-box-styles)

### <a name="example"></a>Exemplo

  Veja o exemplo de [CComboBox::GetDroppedState](#getdroppedstate).

## <a name="see-also"></a>Confira também

[Amostra de MFC CTRLBARS](../../overview/visual-cpp-samples.md)<br/>
[Classe CWnd](../../mfc/reference/cwnd-class.md)<br/>
[Gráfico da hierarquia](../../mfc/hierarchy-chart.md)<br/>
[Classe CWnd](../../mfc/reference/cwnd-class.md)<br/>
[Classe CButton](../../mfc/reference/cbutton-class.md)<br/>
[Classe CEdit](../../mfc/reference/cedit-class.md)<br/>
[Classe CListBox](../../mfc/reference/clistbox-class.md)<br/>
[Classe CScrollBar](../../mfc/reference/cscrollbar-class.md)<br/>
[Classe CStatic](../../mfc/reference/cstatic-class.md)<br/>
[Classe CDialog](../../mfc/reference/cdialog-class.md)
