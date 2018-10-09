---
title: Classe CComboBox | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-mfc
ms.topic: reference
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
dev_langs:
- C++
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
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 912bbd37d4d9afcb60158d41b82b7fa829eeb4ec
ms.sourcegitcommit: d3c41b16bf05af2149090e996d8e71cd6cd55c7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/09/2018
ms.locfileid: "48890641"
---
# <a name="ccombobox-class"></a>Classe CComboBox

Fornece a funcionalidade de uma caixa de combinação do Windows.

## <a name="syntax"></a>Sintaxe

```
class CComboBox : public CWnd
```

## <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores Públicos

|Nome|Descrição|
|----------|-----------------|
|[CComboBox::CComboBox](#ccombobox)|Constrói um objeto `CComboBox`.|

### <a name="public-methods"></a>Métodos Públicos

|Nome|Descrição|
|----------|-----------------|
|[CComboBox:: AddString](#addstring)|Adiciona uma cadeia de caracteres ao final da lista na caixa de listagem de uma caixa de combinação ou na posição classificada das caixas de listagem com o estilo CBS_SORT.|
|[CComboBox::Clear](#clear)|Exclui (limpa) a seleção atual, se houver, no controle de edição.|
|[CComboBox::CompareItem](#compareitem)|Chamado pelo framework para determinar a posição relativa de um novo item de lista em uma caixa de combinação classificada desenhado pelo proprietário.|
|[CComboBox::Copy](#copy)|Copia a seleção atual, se houver, na área de transferência no formato CF_TEXT.|
|[CComboBox::Create](#create)|Cria a caixa de combinação e anexa-o para o `CComboBox` objeto.|
|[CComboBox::Cut](#cut)|Exclui (cortes) a seleção atual, se houver, na edição de controlar e copia o texto excluído na área de transferência no formato CF_TEXT.|
|[CComboBox::DeleteItem](#deleteitem)|Chamado pelo framework quando um item de lista é excluído de uma caixa de combinação do desenho proprietário.|
|[CComboBox::DeleteString](#deletestring)|Exclui uma cadeia de caracteres da caixa de listagem de uma caixa de combinação.|
|[CComboBox::Dir](#dir)|Adiciona uma lista de nomes de arquivo para a caixa de listagem de uma caixa de combinação.|
|[CComboBox::DrawItem](#drawitem)|Chamado pelo framework quando um aspecto visual de um alterações de caixa de combinação do desenho proprietário.|
|[CComboBox:: FindString](#findstring)|Localiza a primeira cadeia de caracteres que contém o prefixo especificado na caixa de listagem de uma caixa de combinação.|
|[CComboBox::FindStringExact](#findstringexact)|Localiza a primeira cadeia de caixa de listagem (em uma caixa de combinação) que corresponde à cadeia de caracteres especificada.|
|[CComboBox::GetComboBoxInfo](#getcomboboxinfo)|Recupera informações sobre o `CComboBox` objeto.|
|[CComboBox::GetCount](#getcount)|Recupera o número de itens na caixa de listagem de uma caixa de combinação.|
|[CComboBox::GetCueBanner](#getcuebanner)|Obtém o texto de indicação que é exibido para um controle de caixa de combinação.|
|[CComboBox::GetCurSel](#getcursel)|Recupera o índice do item selecionado no momento, se houver, na caixa de listagem de uma caixa de combinação.|
|[CComboBox::GetDroppedControlRect](#getdroppedcontrolrect)|Recupera as coordenadas de tela da caixa de lista (removidos para baixo) visível de uma caixa de combinação suspensa.|
|[CComboBox::GetDroppedState](#getdroppedstate)|Determina se a caixa de listagem de uma caixa de combinação suspensa está visível (ignorados para baixo).|
|[CComboBox::GetDroppedWidth](#getdroppedwidth)|Recupera a largura mínima permitida para a parte de caixa de listagem suspensa de uma caixa de combinação.|
|[CComboBox::GetEditSel](#geteditsel)|Obtém as posições de caractere inicial e final da seleção atual no controle de edição de uma caixa de combinação.|
|[CComboBox::GetExtendedUI](#getextendedui)|Determina se uma caixa de combinação tem a interface do usuário padrão ou a interface do usuário estendida.|
|[CComboBox::GetHorizontalExtent](#gethorizontalextent)|Retorna a largura em pixels, a parte da caixa de listagem da caixa de combinação pode ser rolada horizontalmente.|
|[CComboBox::GetItemData](#getitemdata)|Recupera o valor de 32 bits fornecida pelo aplicativo associado ao item de caixa de combinação especificado.|
|[CComboBox::GetItemDataPtr](#getitemdataptr)|Recupera o ponteiro de 32 bits fornecida pelo aplicativo que está associado com o item de caixa de combinação especificado.|
|[CComboBox::GetItemHeight](#getitemheight)|Recupera a altura dos itens de lista em uma caixa de combinação.|
|[CComboBox::GetLBText](#getlbtext)|Obtém uma cadeia de caracteres da caixa de listagem de uma caixa de combinação.|
|[CComboBox::GetLBTextLen](#getlbtextlen)|Obtém o comprimento de uma cadeia de caracteres na caixa de listagem de uma caixa de combinação.|
|[CComboBox::GetLocale](#getlocale)|Recupera o identificador de localidade para uma caixa de combinação.|
|[CComboBox::GetMinVisible](#getminvisible)|Obtém o número mínimo de itens visíveis na lista suspensa da caixa de combinação atual.|
|[CComboBox::GetTopIndex](#gettopindex)|Retorna o índice do primeiro item visível na parte de caixa de listagem da caixa de combinação.|
|[CComboBox::InitStorage](#initstorage)|Pré-aloca blocos de memória para cadeias de caracteres na parte de caixa de listagem da caixa de combinação e itens.|
|[CComboBox::InsertString](#insertstring)|Insere uma cadeia de caracteres na caixa de listagem de uma caixa de combinação.|
|[CComboBox::LimitText](#limittext)|Limita o comprimento do texto que o usuário pode inserir no controle de edição de uma caixa de combinação.|
|[CComboBox::MeasureItem](#measureitem)|Chamado pelo framework para determinar as dimensões da caixa de combinação quando uma caixa de combinação do desenho proprietário é criada.|
|[CComboBox::Paste](#paste)|Insere os dados da área de transferência no controle de edição na posição atual do cursor. Dados são inseridos somente se a área de transferência contém dados no formato CF_TEXT.|
|[CComboBox::ResetContent](#resetcontent)|Remove todos os itens da lista de caixa e editar o controle de uma caixa de combinação.|
|[CComboBox::SelectString](#selectstring)|Pesquisa uma cadeia de caracteres na caixa de listagem de uma caixa de combinação e, se a cadeia de caracteres for encontrada, seleciona a cadeia de caracteres na caixa de listagem e copia a cadeia de caracteres para o controle de edição.|
|[CComboBox::SetCueBanner](#setcuebanner)|Define o texto de indicação que é exibido para um controle de caixa de combinação.|
|[CComboBox::SetCurSel](#setcursel)|Seleciona uma cadeia de caracteres na caixa de listagem de uma caixa de combinação.|
|[CComboBox::SetDroppedWidth](#setdroppedwidth)|Define a largura mínima permitida para a parte de caixa de listagem suspensa de uma caixa de combinação.|
|[CComboBox::SetEditSel](#seteditsel)|Seleciona os caracteres no controle de edição de uma caixa de combinação.|
|[CComboBox::SetExtendedUI](#setextendedui)|Seleciona a interface do usuário padrão ou a interface do usuário estendida para uma caixa de combinação que tem o estilo CBS_DROPDOWN ou CBS_DROPDOWNLIST.|
|[CComboBox::SetHorizontalExtent](#sethorizontalextent)|Define a largura em pixels, a parte da caixa de listagem da caixa de combinação pode ser rolada horizontalmente.|
|[CComboBox::SetItemData](#setitemdata)|Define o valor de 32 bits associado com o item especificado em uma caixa de combinação.|
|[CComboBox::SetItemDataPtr](#setitemdataptr)|Define o ponteiro de 32 bits associado com o item especificado em uma caixa de combinação.|
|[CComboBox::SetItemHeight](#setitemheight)|Define a altura de itens de lista em uma caixa de combinação ou a altura da parte do controle de edição (ou texto estático) de uma caixa de combinação.|
|[CComboBox::SetLocale](#setlocale)|Define o identificador de localidade para uma caixa de combinação.|
|[CComboBox::SetMinVisibleItems](#setminvisibleitems)|Define o número mínimo de itens visíveis na lista suspensa da caixa de combinação atual.|
|[CComboBox::SetTopIndex](#settopindex)|Informa a parte da caixa de listagem da caixa de combinação para exibir o item com o índice especificado na parte superior.|
|[CComboBox::ShowDropDown](#showdropdown)|Mostra ou oculta a caixa de listagem de uma caixa de combinação que tem o estilo CBS_DROPDOWN ou CBS_DROPDOWNLIST.|

## <a name="remarks"></a>Comentários

Uma caixa de combinação consiste em uma caixa de listagem, combinada com um controle estático ou um controle de edição. A parte da caixa de listagem do controle pode ser exibida em todos os momentos ou talvez somente lista suspensa quando o usuário seleciona a seta suspensa ao lado do controle.

O item atualmente selecionado (se houver) na caixa de listagem é exibida nas estático ou controle de edição. Além disso, se a caixa de combinação tem o estilo de lista suspensa, o usuário pode digitar o caractere inicial de um dos itens na lista e a caixa de listagem, se estiver visível, realçará o próximo item com esse caractere inicial.

A tabela a seguir compara a caixa de combinação de três [estilos](../../mfc/reference/styles-used-by-mfc.md#combo-box-styles).

|Estilo|Quando a caixa de listagem está visível|Controle de edição ou estático|
|-----------|-------------------------------|-----------------------------|
|Simples|Sempre|Editar|
|Lista suspensa|Quando descartado para baixo|Editar|
|Lista suspensa|Quando descartado para baixo|Estático|

Você pode criar um `CComboBox` objeto de um modelo de caixa de diálogo ou diretamente em seu código. Em ambos os casos, chame o construtor `CComboBox` para construir o `CComboBox` objeto; em seguida, chame o [Create](#create) função de membro para criar o controle e anexá-lo para o `CComboBox` objeto.

Se você quiser manipular mensagens de notificação do Windows enviadas por uma caixa de combinação para seu pai (normalmente uma classe derivada de `CDialog`), adicione uma função de membro de entrada e o manipulador de mensagens do mapa de mensagem para a classe pai para cada mensagem.

Cada entrada de mapa de mensagem usa o seguinte formato:

**On _** notificação **(**`id`**,**`memberFxn`**)**

em que `id` Especifica a ID de janela filho do controle de caixa de combinação enviando a notificação e `memberFxn` é o nome da função de membro pai que você tenha escrito para manipular a notificação.

O protótipo de função do pai é o seguinte:

**afx_msg** `void` `memberFxn` **();**

A ordem em que determinadas notificações serão enviadas não pode ser prevista. Em particular, uma notificação CBN_SELCHANGE pode ocorrer antes ou depois de uma notificação CBN_CLOSEUP.

Entradas de mapa de mensagem possíveis são os seguintes:

- ON_CBN_CLOSEUP (Windows 3.1 e posterior). A caixa de listagem de uma caixa de combinação foi fechada. Esta mensagem de notificação não foi enviada por uma caixa de combinação que tem o [CBS_SIMPLE](../../mfc/reference/styles-used-by-mfc.md#combo-box-styles) estilo.

- ON_CBN_DBLCLK o usuário clica duas vezes em uma cadeia de caracteres na caixa de listagem de uma caixa de combinação. Esta mensagem de notificação é enviada somente para uma caixa de combinação com o estilo CBS_SIMPLE. Para uma caixa de combinação com o [CBS_DROPDOWN](../../mfc/reference/styles-used-by-mfc.md#combo-box-styles) ou [CBS_DROPDOWNLIST](../../mfc/reference/styles-used-by-mfc.md#combo-box-styles) de estilo, um clique duplo não pode ocorrer porque um único clique oculta a caixa de listagem.

- A caixa de listagem de uma caixa de combinação está prestes a lista suspensa de ON_CBN_DROPDOWN (ficar visível). Esta mensagem de notificação só pode acontecer para uma caixa de combinação com o estilo CBS_DROPDOWN ou CBS_DROPDOWNLIST.

- ON_CBN_EDITCHANGE o usuário executou uma ação que pode ter alterado o texto na parte do controle de edição de uma caixa de combinação. Ao contrário de mensagem CBN_EDITUPDATE, esta mensagem é enviada depois que a tela de atualizações do Windows. Ele não será enviado se a caixa de combinação tem o estilo CBS_DROPDOWNLIST.

- ON_CBN_EDITUPDATE a parte do controle de edição de uma caixa de combinação é sobre o texto de exibição alterado. Esta mensagem de notificação é enviada depois que o controle formatou o texto, mas antes de exibir o texto. Ele não será enviado se a caixa de combinação tem o estilo CBS_DROPDOWNLIST.

- ON_CBN_ERRSPACE a caixa de combinação não é possível alocar memória suficiente para atender a uma solicitação específica.

- ON_CBN_SELENDCANCEL (Windows 3.1 e posterior). Indica que a seleção do usuário deve ser cancelada. O usuário clica em um item e, em seguida, clica em outra janela ou controle para ocultar a caixa de listagem de uma caixa de combinação. Esta mensagem de notificação é enviada antes da mensagem de notificação CBN_CLOSEUP para indicar que a seleção do usuário deve ser ignorada. A mensagem de notificação CBN_SELENDCANCEL ou CBN_SELENDOK é enviada, mesmo se a mensagem de notificação CBN_CLOSEUP não for enviada (como no caso de uma caixa de combinação com o estilo CBS_SIMPLE).

- ON_CBN_SELENDOK o usuário seleciona um item e, em seguida, pressionar a tecla ENTER ou clica a tecla de seta para baixo para ocultar a caixa de listagem de uma caixa de combinação. Esta mensagem de notificação é enviada antes da mensagem CBN_CLOSEUP para indicar que a seleção do usuário deve ser considerada válida. A mensagem de notificação CBN_SELENDCANCEL ou CBN_SELENDOK é enviada, mesmo se a mensagem de notificação CBN_CLOSEUP não for enviada (como no caso de uma caixa de combinação com o estilo CBS_SIMPLE).

- ON_CBN_KILLFOCUS a caixa de combinação está perdendo o foco de entrada.

- ON_CBN_SELCHANGE a seleção na caixa de listagem de uma caixa de combinação está prestes a ser alterado como resultado o usuário clicar na caixa de listagem ou alterar a seleção usando as teclas de direção. Ao processar essa mensagem, o texto no controle de edição da caixa de combinação só pode ser recuperado por meio de `GetLBText` ou outra função semelhante. `GetWindowText` não pode ser usado.

- A caixa de combinação ON_CBN_SETFOCUS recebe o foco de entrada.

Se você criar uma `CComboBox` objeto dentro de uma caixa de diálogo (por meio de um recurso de caixa de diálogo), o `CComboBox` objeto será destruído automaticamente quando o usuário fecha a caixa de diálogo.

Se você inserir um `CComboBox` objeto dentro de outra janela do objeto, você não precisará destruí-lo. Se você criar o `CComboBox` do objeto na pilha, ele será destruído automaticamente. Se você criar o `CComboBox` objeto no heap usando a **novos** função, você deve chamar **excluir** no objeto a destruí-la quando a caixa de combinação do Windows é destruída.

**Observação** se você quiser manipular mensagens WM_KEYDOWN e WM_CHAR, você tem a subclasse da caixa de combinação editar e controles de caixa de lista, derivar classes de `CEdit` e `CListBox`, e adicionar manipuladores para essas mensagens para as classes derivadas. Para obter mais informações, consulte [CWnd::SubclassWindow](../../mfc/reference/cwnd-class.md#subclasswindow).

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

[CObject](../../mfc/reference/cobject-class.md)

[CCmdTarget](../../mfc/reference/ccmdtarget-class.md)

[CWnd](../../mfc/reference/cwnd-class.md)

`CComboBox`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** afxwin. h

##  <a name="addstring"></a>  CComboBox:: AddString

Adiciona uma cadeia de caracteres para a caixa de listagem de uma caixa de combinação.

```
int AddString(LPCTSTR lpszString);
```

### <a name="parameters"></a>Parâmetros

*lpszString*<br/>
Aponta para a cadeia de caracteres terminada em nulo a ser adicionado.

### <a name="return-value"></a>Valor de retorno

Se o valor retornado for maior que ou igual a 0, ele é o índice baseado em zero na cadeia de caracteres na caixa de listagem. O valor de retorno será CB_ERR se ocorrer um erro; o valor de retorno é CB_ERRSPACE se não houver espaço suficiente está disponível para armazenar a nova cadeia de caracteres.

### <a name="remarks"></a>Comentários

Se a caixa de listagem não foi criada com o [CBS_SORT](../../mfc/reference/styles-used-by-mfc.md#combo-box-styles) estilo, a cadeia de caracteres é adicionada ao final da lista. Caso contrário, a cadeia de caracteres é inserida na lista, e a lista é classificada.

> [!NOTE]
>  Não há suporte para essa função, o Windows `ComboBoxEx` controle. Para obter mais informações sobre esse controle, consulte [ComboBoxEx controles](/windows/desktop/Controls/comboboxex-controls) no SDK do Windows.

Para inserir uma cadeia de caracteres em um local específico dentro da lista, use o [InsertString](#insertstring) função de membro.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFC_CComboBox#3](../../mfc/reference/codesnippet/cpp/ccombobox-class_1.cpp)]

##  <a name="ccombobox"></a>  CComboBox::CComboBox

Constrói um objeto `CComboBox`.

```
CComboBox();
```

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFC_CComboBox#1](../../mfc/reference/codesnippet/cpp/ccombobox-class_2.cpp)]

##  <a name="clear"></a>  CComboBox::Clear

Exclui (limpa) a seleção atual, se houver, no controle de edição da caixa de combinação.

```
void Clear();
```

### <a name="remarks"></a>Comentários

Para excluir a seleção atual e colocar o conteúdo excluído na área de transferência, use o [Recortar](#cut) função de membro.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFC_CComboBox#4](../../mfc/reference/codesnippet/cpp/ccombobox-class_3.cpp)]

##  <a name="compareitem"></a>  CComboBox::CompareItem

Chamado pelo framework para determinar a posição relativa de um novo item na parte de caixa de listagem de uma caixa de combinação do desenho proprietário classificado.

```
virtual int CompareItem(LPCOMPAREITEMSTRUCT lpCompareItemStruct);
```

### <a name="parameters"></a>Parâmetros

*lpCompareItemStruct*<br/>
Um ponteiro longo para um [COMPAREITEMSTRUCT](../../mfc/reference/compareitemstruct-structure.md) estrutura.

### <a name="return-value"></a>Valor de retorno

Indica a posição relativa dos dois itens descrito o `COMPAREITEMSTRUCT` estrutura. Ele pode ser qualquer um dos seguintes valores:

|Valor|Significado|
|-----------|-------------|
|- 1|Item 1 classifica antes do item 2.|
|0|Item 1 e item 2 classificar o mesmo.|
|1|Item 1 classifica após o item 2.|

Ver [CWnd::OnCompareItem](../../mfc/reference/cwnd-class.md#oncompareitem) para obter uma descrição de `COMPAREITEMSTRUCT`.

### <a name="remarks"></a>Comentários

Por padrão, essa função membro não faz nada. Se você criar uma caixa de combinação do desenho proprietário com o estilo LBS_SORT, você deve substituir essa função de membro para ajudar a estrutura de novos itens adicionados à caixa de listagem de classificação.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFC_CComboBox#5](../../mfc/reference/codesnippet/cpp/ccombobox-class_4.cpp)]

##  <a name="copy"></a>  CComboBox::Copy

Copia a seleção atual, se houver, no controle de edição da caixa de combinação na área de transferência no formato CF_TEXT.

```
void Copy();
```

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFC_CComboBox#6](../../mfc/reference/codesnippet/cpp/ccombobox-class_5.cpp)]

##  <a name="create"></a>  CComboBox::Create

Cria a caixa de combinação e anexa-o para o `CComboBox` objeto.

```
virtual BOOL Create(
    DWORD dwStyle,
    const RECT& rect,
    CWnd* pParentWnd,
    UINT nID);
```

### <a name="parameters"></a>Parâmetros

*dwStyle*<br/>
Especifica o estilo da caixa de combinação. Aplicar qualquer combinação de [estilos de caixa de combinação](../../mfc/reference/styles-used-by-mfc.md#combo-box-styles) à caixa.

*Rect*<br/>
Aponta para a posição e tamanho da caixa de combinação. Pode ser um [estrutura RECT](../../mfc/reference/rect-structure1.md) ou um `CRect` objeto.

*pParentWnd*<br/>
Especifica a janela do pai da caixa de combinação (geralmente um `CDialog`). Ele não deve ser NULL.

*nID*<br/>
Especifica a ID do controle. da caixa de combinação

### <a name="return-value"></a>Valor de retorno

Diferente de zero se bem-sucedido; Caso contrário, 0.

### <a name="remarks"></a>Comentários

Você constrói um `CComboBox` objeto em duas etapas. Primeiro, chame o construtor e, em seguida, chame `Create`, que cria a caixa de combinação do Windows e anexa-o para o `CComboBox` objeto.

Quando `Create` envios do Windows, executa o [WM_NCCREATE](../../mfc/reference/cwnd-class.md#onnccreate), [WM_CREATE](../../mfc/reference/cwnd-class.md#oncreate), [WM_NCCALCSIZE](../../mfc/reference/cwnd-class.md#onnccalcsize), e [WM_GETMINMAXINFO](../../mfc/reference/cwnd-class.md#ongetminmaxinfo) mensagens para a caixa de combinação.

Essas mensagens são manipuladas por padrão, o [OnNcCreate](../../mfc/reference/cwnd-class.md#onnccreate), [OnCreate](../../mfc/reference/cwnd-class.md#oncreate), [OnNcCalcSize](../../mfc/reference/cwnd-class.md#onnccalcsize), e [OnGetMinMaxInfo](../../mfc/reference/cwnd-class.md#ongetminmaxinfo) funções de membro no `CWnd` classe base. Para estender o tratamento de mensagem padrão, derive uma classe de `CComboBox`, adicionar um mapa de mensagem para a nova classe e substituir as funções de membro de manipulador de mensagens anterior. Substituir `OnCreate`, por exemplo, para executar a inicialização necessária para uma nova classe.

Aplicar o seguinte [estilos de janela](../../mfc/reference/styles-used-by-mfc.md#window-styles) a um controle de caixa de combinação. :

- Sempre WS_CHILD

- Normalmente, WS_VISIBLE

- WS_DISABLED raramente

- WS_VSCROLL para adicionar a rolagem vertical para a caixa de listagem na caixa de combinação

- WS_HSCROLL para adicionar a rolagem horizontal para a caixa de listagem na caixa de combinação

- WS_GROUP para agrupar controles

- WS_TABSTOP para incluir a caixa de combinação na ordem de tabulação

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFC_CComboBox#2](../../mfc/reference/codesnippet/cpp/ccombobox-class_6.cpp)]

##  <a name="cut"></a>  CComboBox::Cut

Exclusões (cortes) a seleção atual, se houver, na caixa de combinação editar, controlar e copia o texto excluído na área de transferência no formato CF_TEXT.

```
void Cut();
```

### <a name="remarks"></a>Comentários

Para excluir a seleção atual sem colocar o texto excluído na área de transferência, chame o [clara](#clear) função de membro.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFC_CComboBox#7](../../mfc/reference/codesnippet/cpp/ccombobox-class_7.cpp)]

##  <a name="deleteitem"></a>  CComboBox::DeleteItem

Chamado pelo framework quando o usuário exclui um item de um desenho proprietário `CComboBox` de objeto ou destrói a caixa de combinação.

```
virtual void DeleteItem(LPDELETEITEMSTRUCT lpDeleteItemStruct);
```

### <a name="parameters"></a>Parâmetros

*lpDeleteItemStruct*<br/>
Um ponteiro longo para um Windows [DELETEITEMSTRUCT](../../mfc/reference/deleteitemstruct-structure.md) estrutura que contém informações sobre o item excluído. Ver [CWnd::OnDeleteItem](../../mfc/reference/cwnd-class.md#ondeleteitem) para obter uma descrição dessa estrutura.

### <a name="remarks"></a>Comentários

A implementação padrão dessa função não faz nada. Substitua essa função para redesenhar a caixa de combinação, conforme necessário.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFC_CComboBox#8](../../mfc/reference/codesnippet/cpp/ccombobox-class_8.cpp)]

##  <a name="deletestring"></a>  CComboBox::DeleteString

Exclui o item na posição *nIndex* da caixa de combinação.

```
int DeleteString(UINT nIndex);
```

### <a name="parameters"></a>Parâmetros

*nIndex*<br/>
Especifica o índice na cadeia de caracteres que deve ser excluído.

### <a name="return-value"></a>Valor de retorno

Se o valor retornado for maior que ou igual a 0, ele é uma contagem das cadeias de caracteres restantes na lista. O valor de retorno será CB_ERR se *nIndex* Especifica um índice maior que o número de itens na lista.

### <a name="remarks"></a>Comentários

Todos os itens que seguem *nIndex* agora mover uma posição para baixo. Por exemplo, se uma caixa de combinação contém dois itens, excluir o primeiro item fará com que o item restante ser, agora, na primeira posição. *nIndex*= 0 para o item na primeira posição.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFC_CComboBox#9](../../mfc/reference/codesnippet/cpp/ccombobox-class_9.cpp)]

##  <a name="dir"></a>  CComboBox::Dir

Adiciona uma lista de nomes de arquivos ou unidades à caixa de listagem de uma caixa de combinação.

```
int Dir(
    UINT attr,
    LPCTSTR lpszWildCard);
```

### <a name="parameters"></a>Parâmetros

*attr*<br/>
Pode ser qualquer combinação da **enum** valores descritos na [cfile:: getStatus](../../mfc/reference/cfile-class.md#getstatus) ou qualquer combinação dos valores a seguir:

- Arquivo DDL_READWRITE pode ser lido ou gravado para.

- DDL_READONLY arquivo podem ser lidos do mas não gravado.

- Arquivo DDL_HIDDEN está oculta e não aparece em uma listagem de diretório.

- DDL_SYSTEM é um arquivo de sistema.

- DDL_DIRECTORY o nome especificado por *lpszWildCard* Especifica um diretório.

- Arquivo DDL_ARCHIVE foi arquivado.

- DDL_DRIVES incluem todas as unidades que corresponde ao nome especificado por *lpszWildCard*.

- Sinalizador DDL_EXCLUSIVE exclusivo. Se o sinalizador exclusivo é definido, somente os arquivos do tipo especificado serão listados. Caso contrário, os arquivos do tipo especificado são listados, além de arquivos "normais".

*lpszWildCard*<br/>
Aponta para uma cadeia de caracteres de especificação de arquivo. A cadeia de caracteres pode conter caracteres curinga (por exemplo, *.\*).

### <a name="return-value"></a>Valor de retorno

Se o valor retornado for maior que ou igual a 0, ele é o índice baseado em zero do último nome de arquivo adicionado à lista. O valor de retorno será CB_ERR se ocorrer um erro; o valor de retorno é CB_ERRSPACE se não houver espaço suficiente está disponível para armazenar novas cadeias de caracteres.

### <a name="remarks"></a>Comentários

Não há suporte para essa função, o Windows `ComboBoxEx` controle. Para obter mais informações sobre esse controle, consulte [ComboBoxEx controles](/windows/desktop/Controls/comboboxex-controls) no SDK do Windows.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFC_CComboBox#10](../../mfc/reference/codesnippet/cpp/ccombobox-class_10.cpp)]

##  <a name="drawitem"></a>  CComboBox::DrawItem

Chamado pelo framework quando um aspecto visual de um alterações de caixa de combinação do desenho proprietário.

```
virtual void DrawItem(LPDRAWITEMSTRUCT lpDrawItemStruct);
```

### <a name="parameters"></a>Parâmetros

*lpDrawItemStruct*<br/>
Um ponteiro para um [DRAWITEMSTRUCT](../../mfc/reference/drawitemstruct-structure.md) estrutura que contém informações sobre o tipo de desenho necessárias.

### <a name="remarks"></a>Comentários

O `itemAction` membro o `DRAWITEMSTRUCT` estrutura define a ação de desenho a ser executada. Ver [CWnd::OnDrawItem](../../mfc/reference/cwnd-class.md#ondrawitem) para obter uma descrição dessa estrutura.

Por padrão, essa função membro não faz nada. Substituir essa função de membro para implementar o desenho de um desenho proprietário `CComboBox` objeto. Antes que essa função de membro seja encerrado, o aplicativo deve restaurar todos os objetos de interface (GDI) do dispositivo gráficos selecionados para o contexto de exibição fornecido no *lpDrawItemStruct*.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFC_CComboBox#11](../../mfc/reference/codesnippet/cpp/ccombobox-class_11.cpp)]

##  <a name="findstring"></a>  CComboBox:: FindString

Encontra, mas não selecionar, a primeira cadeia de caracteres que contém o prefixo especificado na caixa de listagem de uma caixa de combinação.

```
int FindString(
    int nStartAfter,
    LPCTSTR lpszString) const;
```

### <a name="parameters"></a>Parâmetros

*nStartAfter*<br/>
Contém o índice baseado em zero do item antes do primeiro item a ser pesquisado. Quando a pesquisa alcançar a parte inferior da caixa de listagem, ele continua na parte superior da caixa de listagem para o item especificado pela *nStartAfter*. Se-1, a caixa de listagem inteira é pesquisada desde o início.

*lpszString*<br/>
Aponta para a cadeia de caracteres terminada em nulo que contém o prefixo a ser pesquisado. A pesquisa é o caso independente, portanto, essa cadeia de caracteres pode conter qualquer combinação de letras maiusculas e minúsculas.

### <a name="return-value"></a>Valor de retorno

Se o valor retornado for maior que ou igual a 0, ele é o índice baseado em zero do item correspondente. Ele será CB_ERR se a pesquisa foi bem-sucedida.

### <a name="remarks"></a>Comentários

Não há suporte para essa função, o Windows `ComboBoxEx` controle. Para obter mais informações sobre esse controle, consulte [ComboBoxEx controles](/windows/desktop/Controls/comboboxex-controls) no SDK do Windows.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFC_CComboBox#12](../../mfc/reference/codesnippet/cpp/ccombobox-class_12.cpp)]

##  <a name="findstringexact"></a>  CComboBox::FindStringExact

Chame o `FindStringExact` função de membro para localizar a primeira cadeia de caixa de listagem (em uma caixa de combinação) que corresponde à cadeia de caracteres especificada no *lpszFind*.

```
int FindStringExact(
    int nIndexStart,
    LPCTSTR lpszFind) const;
```

### <a name="parameters"></a>Parâmetros

*nIndexStart*<br/>
Especifica o índice baseado em zero do item antes do primeiro item a ser pesquisado. Quando a pesquisa alcançar a parte inferior da caixa de listagem, ele continua na parte superior da caixa de listagem para o item especificado pela *nIndexStart*. Se *nIndexStart* é -1, a caixa de listagem inteira é pesquisada desde o início.

*lpszFind*<br/>
Aponta para a cadeia de caracteres terminada em nulo a ser pesquisado. Essa cadeia de caracteres pode conter um nome de arquivo completo, incluindo a extensão. A pesquisa não diferencia maiusculas de minúsculas, para que essa cadeia de caracteres pode conter qualquer combinação de letras maiusculas e minúsculas.

### <a name="return-value"></a>Valor de retorno

O índice baseado em zero do item correspondente ou CB_ERR se a pesquisa foi bem-sucedida.

### <a name="remarks"></a>Comentários

Se a caixa de combinação foi criada com um estilo de desenho do proprietário, mas sem os [CBS_HASSTRINGS](../../mfc/reference/styles-used-by-mfc.md#combo-box-styles) estilo `FindStringExact` tenta corresponder o valor de palavras duplas contra o valor de *lpszFind*.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFC_CComboBox#13](../../mfc/reference/codesnippet/cpp/ccombobox-class_13.cpp)]

##  <a name="getcomboboxinfo"></a>  CComboBox::GetComboBoxInfo

Recupera informações para o `CComboBox` objeto.

```
BOOL GetComboBoxInfo(PCOMBOBOXINFO pcbi) const;
```

### <a name="parameters"></a>Parâmetros

*pcbi*<br/>
Um ponteiro para o [COMBOBOXINFO](/windows/desktop/api/winuser/ns-winuser-tagcomboboxinfo) estrutura.

### <a name="return-value"></a>Valor de retorno

Retorna verdadeiro em caso de êxito, FALSE em caso de falha.

### <a name="remarks"></a>Comentários

Essa função membro emula a funcionalidade dos [CB_GETCOMBOBOXINFO](/windows/desktop/Controls/cb-getcomboboxinfo) da mensagem, conforme descrito no SDK do Windows.

##  <a name="getcount"></a>  CComboBox::GetCount

Chame essa função de membro para recuperar o número de itens na parte da caixa de listagem de uma caixa de combinação.

```
int GetCount() const;
```

### <a name="return-value"></a>Valor de retorno

O número de itens. A contagem retornada é maior do que o valor de índice do último item (o índice é baseado em zero). Ele será CB_ERR se ocorrer um erro.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFC_CComboBox#14](../../mfc/reference/codesnippet/cpp/ccombobox-class_14.cpp)]

##  <a name="getcuebanner"></a>  CComboBox::GetCueBanner

Obtém o texto de indicação que é exibido para um controle de caixa de combinação.

```
CString GetCueBanner() const;

BOOL GetCueBanner(
    LPTSTR lpszText,
    int cchText) const;
```

### <a name="parameters"></a>Parâmetros

|Parâmetro|Descrição|
|---------------|-----------------|
|*lpszText*|[out] Ponteiro para um buffer que recebe o texto da faixa de indicação.|
|*cchText*|[in] Tamanho do buffer que o *lpszText* parâmetro aponta.|

### <a name="return-value"></a>Valor de retorno

Na primeira sobrecarga, uma [CString](../../atl-mfc-shared/using-cstring.md) objeto que contém o texto da faixa de indicação se existir; caso contrário, um `CString` objeto que tem comprimento zero.

-ou-

Na segunda sobrecarga, TRUE se este método for bem-sucedida; Caso contrário, FALSE.

### <a name="remarks"></a>Comentários

Texto de indicação é um aviso que é exibido na área de entrada de controle de caixa de combinação. O texto de indicação é exibido até que o usuário forneça uma entrada.

Esse método envia o [CB_GETCUEBANNER](/windows/desktop/Controls/cb-getcuebanner) mensagem, que é descrita no SDK do Windows.

##  <a name="getcursel"></a>  CComboBox::GetCurSel

Chame essa função de membro para determinar qual item da caixa de combinação está selecionado.

```
int GetCurSel() const;
```

### <a name="return-value"></a>Valor de retorno

O índice baseado em zero do item atualmente selecionado na caixa de listagem de uma caixa de combinação ou CB_ERR se nenhum item está selecionado.

### <a name="remarks"></a>Comentários

`GetCurSel` Retorna um índice na lista.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFC_CComboBox#15](../../mfc/reference/codesnippet/cpp/ccombobox-class_15.cpp)]

##  <a name="getdroppedcontrolrect"></a>  CComboBox::GetDroppedControlRect

Chamar o `GetDroppedControlRect` a função de membro para recuperar as coordenadas de tela da caixa visível (descartado) na lista suspensa de uma caixa de combinação suspensa.

```
void GetDroppedControlRect(LPRECT lprect) const;
```

### <a name="parameters"></a>Parâmetros

*lprect*<br/>
Aponta para o [estrutura RECT](../../mfc/reference/rect-structure1.md) que deve receber as coordenadas.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFC_CComboBox#16](../../mfc/reference/codesnippet/cpp/ccombobox-class_16.cpp)]

##  <a name="getdroppedstate"></a>  CComboBox::GetDroppedState

Chamar o `GetDroppedState` a função de membro para determinar se a caixa de listagem de uma caixa de combinação suspensa está visível (ignorados para baixo).

```
BOOL GetDroppedState() const;
```

### <a name="return-value"></a>Valor de retorno

Diferente de zero se a caixa de listagem estiver visível; Caso contrário, 0.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFC_CComboBox#17](../../mfc/reference/codesnippet/cpp/ccombobox-class_17.cpp)]

##  <a name="getdroppedwidth"></a>  CComboBox::GetDroppedWidth

Chame essa função para recuperar a largura mínima permitida, em pixels, da caixa de listagem de uma caixa de combinação.

```
int GetDroppedWidth() const;
```

### <a name="return-value"></a>Valor de retorno

Se for bem-sucedido, a largura mínima permitida, em pixels. Caso contrário, CB_ERR.

### <a name="remarks"></a>Comentários

Essa função só se aplica a caixas de combinação com o [CBS_DROPDOWN](../../mfc/reference/styles-used-by-mfc.md#combo-box-styles) ou [CBS_DROPDOWNLIST](../../mfc/reference/styles-used-by-mfc.md#combo-box-styles) estilo.

Por padrão, a largura mínima permitida da caixa de listagem suspensa é 0. A largura mínima de permitido pode ser definida chamando [SetDroppedWidth](#setdroppedwidth). Quando a parte da caixa de listagem da caixa de combinação é exibida, sua largura seja o maior entre a largura mínima de permitidos ou a largura da caixa de combinação.

### <a name="example"></a>Exemplo

  Veja o exemplo de [SetDroppedWidth](#setdroppedwidth).

##  <a name="geteditsel"></a>  CComboBox::GetEditSel

Obtém as posições de caractere inicial e final da seleção atual no controle de edição de uma caixa de combinação.

```
DWORD GetEditSel() const;
```

### <a name="return-value"></a>Valor de retorno

Um valor de 32 bits que contém a posição inicial da palavra de ordem inferior e a posição do primeiro caractere não selecionado após o fim da seleção da palavra de ordem superior. Se essa função é usada em uma caixa de combinação sem um controle de edição, CB_ERR será retornado.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFC_CComboBox#18](../../mfc/reference/codesnippet/cpp/ccombobox-class_18.cpp)]

##  <a name="getextendedui"></a>  CComboBox::GetExtendedUI

Chamar o `GetExtendedUI` a função de membro para determinar se uma caixa de combinação tem a interface do usuário padrão ou a interface do usuário estendida.

```
BOOL GetExtendedUI() const;
```

### <a name="return-value"></a>Valor de retorno

Diferente de zero se a caixa de combinação tem a interface do usuário estendida; Caso contrário, 0.

### <a name="remarks"></a>Comentários

A interface do usuário estendida pode ser identificada das seguintes maneiras:

- Clicando no controle estático exibe a caixa de listagem somente para caixas de combinação com o [CBS_DROPDOWNLIST](../../mfc/reference/styles-used-by-mfc.md#combo-box-styles) estilo.

- Pressionar a tecla de seta para baixo exibirá a caixa de lista (F4 está desabilitado).

Rolagem no controle estático é desabilitada quando a lista de itens não está visível (seta chaves estão desabilitadas).

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFC_CComboBox#19](../../mfc/reference/codesnippet/cpp/ccombobox-class_19.cpp)]

##  <a name="gethorizontalextent"></a>  CComboBox::GetHorizontalExtent

Recupera de caixa de combinação a largura em pixels pelo qual a parte da caixa de listagem da caixa de combinação pode ser rolada horizontalmente.

```
UINT GetHorizontalExtent() const;
```

### <a name="return-value"></a>Valor de retorno

A largura rolável da parte de caixa de listagem da caixa de combinação, em pixels.

### <a name="remarks"></a>Comentários

Isso é aplicável somente se a parte de caixa de listagem da caixa de combinação tem uma barra de rolagem horizontal.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFC_CComboBox#20](../../mfc/reference/codesnippet/cpp/ccombobox-class_20.cpp)]

##  <a name="getitemdata"></a>  CComboBox::GetItemData

Recupera o valor de 32 bits fornecida pelo aplicativo associado ao item de caixa de combinação especificado.

```
DWORD_PTR GetItemData(int nIndex) const;
```

### <a name="parameters"></a>Parâmetros

*nIndex*<br/>
Contém o índice baseado em zero de um item na caixa de listagem da caixa de combinação.

### <a name="return-value"></a>Valor de retorno

O valor de 32 bits associado com o item ou CB_ERR se ocorrer um erro.

### <a name="remarks"></a>Comentários

O valor de 32 bits pode ser definido com o *dwItemData* parâmetro de uma [SetItemData](#setitemdata) chamada de função de membro. Use o `GetItemDataPtr` se o valor de 32 bits a ser recuperado é um ponteiro de função de membro (**void** <strong>\*</strong>).

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFC_CComboBox#21](../../mfc/reference/codesnippet/cpp/ccombobox-class_21.cpp)]

##  <a name="getitemdataptr"></a>  CComboBox::GetItemDataPtr

Recupera o valor de 32 bits fornecida pelo aplicativo associado ao item de caixa de combinação especificado como um ponteiro (**void** <strong>\*</strong>).

```
void* GetItemDataPtr(int nIndex) const;
```

### <a name="parameters"></a>Parâmetros

*nIndex*<br/>
Contém o índice baseado em zero de um item na caixa de listagem da caixa de combinação.

### <a name="return-value"></a>Valor de retorno

Recupera um ponteiro ou -1 se ocorrer um erro.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFC_CComboBox#22](../../mfc/reference/codesnippet/cpp/ccombobox-class_22.cpp)]

##  <a name="getitemheight"></a>  CComboBox::GetItemHeight

Chamar o `GetItemHeight` a função de membro para recuperar a altura dos itens de lista em uma caixa de combinação.

```
int GetItemHeight(int nIndex) const;
```

### <a name="parameters"></a>Parâmetros

*nIndex*<br/>
Especifica o componente da caixa de combinação cuja altura deve ser recuperado. Se o *nIndex* parâmetro é -1, a altura da parte do controle de edição (ou texto estático) da caixa de combinação é recuperada. Se a caixa de combinação com o [CBS_OWNERDRAWVARIABLE](../../mfc/reference/styles-used-by-mfc.md#combo-box-styles) estilo *nIndex* Especifica o índice baseado em zero do item cuja altura deve ser recuperado da lista. Caso contrário, *nIndex* deve ser definido como 0.

### <a name="return-value"></a>Valor de retorno

A altura, em pixels, do item especificado em uma caixa de combinação. O valor de retorno será CB_ERR se ocorrer um erro.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFC_CComboBox#23](../../mfc/reference/codesnippet/cpp/ccombobox-class_23.cpp)]

##  <a name="getlbtext"></a>  CComboBox::GetLBText

Obtém uma cadeia de caracteres da caixa de listagem de uma caixa de combinação.

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
Contém o índice baseado em zero da cadeia de caracteres da caixa de listagem a ser copiado.

*lpszText*<br/>
Aponta para um buffer que receberá a cadeia de caracteres. O buffer deve ter espaço suficiente para a cadeia de caracteres e um caractere nulo de terminação.

*rString*<br/>
Uma referência a um `CString`.

### <a name="return-value"></a>Valor de retorno

O comprimento (em bytes) da cadeia de caracteres, exceto o caractere nulo de terminação. Se *nIndex* não especifica um índice válido, o valor de retorno será CB_ERR.

### <a name="remarks"></a>Comentários

O segundo formulário desse membro de função preenche uma `CString` objeto com o texto do item.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFC_CComboBox#24](../../mfc/reference/codesnippet/cpp/ccombobox-class_24.cpp)]

##  <a name="getlbtextlen"></a>  CComboBox::GetLBTextLen

Obtém o comprimento de uma cadeia de caracteres na caixa de listagem de uma caixa de combinação.

```
int GetLBTextLen(int nIndex) const;
```

### <a name="parameters"></a>Parâmetros

*nIndex*<br/>
Contém o índice baseado em zero da cadeia de caracteres de caixa de listagem.

### <a name="return-value"></a>Valor de retorno

O comprimento da cadeia de caracteres em bytes, exceto o caractere nulo de terminação. Se *nIndex* não especifica um índice válido, o valor de retorno será CB_ERR.

### <a name="example"></a>Exemplo

  Veja o exemplo de [CComboBox::GetLBText](#getlbtext).

##  <a name="getlocale"></a>  CComboBox::GetLocale

Recupera a localidade usada por caixa de combinação.

```
LCID GetLocale() const;
```

### <a name="return-value"></a>Valor de retorno

O valor LCID (identificador) da localidade para cadeias de caracteres na caixa de combinação.

### <a name="remarks"></a>Comentários

A localidade é usada, por exemplo, para determinar a ordem de classificação das cadeias de caracteres em uma caixa de combinação classificada.

### <a name="example"></a>Exemplo

  Veja o exemplo de [CComboBox::SetLocale](#setlocale).

##  <a name="getminvisible"></a>  CComboBox::GetMinVisible

Obtém o número mínimo de itens visíveis na lista suspensa de controle de caixa de combinação atual.

```
int GetMinVisible() const;
```

### <a name="return-value"></a>Valor de retorno

O número mínimo de itens visíveis na lista suspensa atual.

### <a name="remarks"></a>Comentários

Esse método envia o [CB_GETMINVISIBLE](/windows/desktop/Controls/cb-setminvisible) mensagem, que é descrita no SDK do Windows.

##  <a name="gettopindex"></a>  CComboBox::GetTopIndex

Recupera o índice baseado em zero do primeiro item visível na parte de caixa de listagem da caixa de combinação.

```
int GetTopIndex() const;
```

### <a name="return-value"></a>Valor de retorno

O índice baseado em zero do primeiro item visível na parte de caixa de listagem da caixa de combinação, se for bem-sucedido, CB_ERR caso contrário.

### <a name="remarks"></a>Comentários

Inicialmente, o item 0 é na parte superior da caixa de listagem, mas se a caixa de listagem é rolada, outro item pode ser na parte superior.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFC_CComboBox#25](../../mfc/reference/codesnippet/cpp/ccombobox-class_25.cpp)]

##  <a name="initstorage"></a>  CComboBox::InitStorage

Aloca memória para armazenar itens de caixa de lista na parte de caixa de listagem da caixa de combinação.

```
int InitStorage(
    int nItems,
    UINT nBytes);
```

### <a name="parameters"></a>Parâmetros

*nItems*<br/>
Especifica o número de itens a serem adicionados.

*nBytes*<br/>
Especifica a quantidade de memória, em bytes, para alocar para cadeias de caracteres do item.

### <a name="return-value"></a>Valor de retorno

Se for bem-sucedido, o número máximo de itens que a parte da caixa de listagem da caixa de combinação pode armazenar antes de uma realocação de memória é necessário, CB_ERRSPACE caso contrário, o que significa que não há memória suficiente está disponível.

### <a name="remarks"></a>Comentários

Chame essa função antes de adicionar um grande número de itens à parte da caixa de listagem a `CComboBox`.

Windows 95/98 somente: O *wParam* parâmetro está limitado aos valores de 16 bits. Isso significa que caixas de listagem não podem conter mais de 32.767 itens. Embora o número de itens é restrito, o tamanho total dos itens em uma caixa de listagem é limitado apenas pela memória disponível.

Essa função ajuda a acelerar a inicialização de caixas de listagem que têm um grande número de itens (mais de 100). Ele pré-aloca a quantidade especificada de memória de modo que os próximos [AddString](#addstring), [InsertString](#insertstring), e [Dir](#dir) funções usam o menor tempo possível. Você pode usar estimativas para os parâmetros. Se você superestimar, alguma memória extra será alocada; Se você subestimar, a alocação normal é usada para os itens que excedem a quantidade pré-alocada.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFC_CComboBox#26](../../mfc/reference/codesnippet/cpp/ccombobox-class_26.cpp)]

##  <a name="insertstring"></a>  CComboBox::InsertString

Insere uma cadeia de caracteres na caixa de listagem de uma caixa de combinação.

```
int InsertString(
    int nIndex,
    LPCTSTR lpszString);
```

### <a name="parameters"></a>Parâmetros

*nIndex*<br/>
Contém o índice baseado em zero para a posição na caixa de listagem que receberá a cadeia de caracteres. Se esse parâmetro for -1, a cadeia de caracteres é adicionada ao final da lista.

*lpszString*<br/>
Aponta para a cadeia de caracteres terminada em nulo que deve ser inserido.

### <a name="return-value"></a>Valor de retorno

O índice baseado em zero da posição em que a cadeia de caracteres foi inserida. O valor de retorno será CB_ERR se ocorrer um erro. O valor de retorno é CB_ERRSPACE se não houver espaço suficiente está disponível para armazenar a nova cadeia de caracteres.

### <a name="remarks"></a>Comentários

Ao contrário o [AddString](#addstring) função de membro, o `InsertString` função de membro não faz com que uma lista com o [CBS_SORT](../../mfc/reference/styles-used-by-mfc.md#combo-box-styles) estilo a ser classificado.

> [!NOTE]
>  Não há suporte para essa função, o Windows `ComboBoxEx` controle. Para obter mais informações sobre esse controle, consulte [ComboBoxEx controles](/windows/desktop/Controls/comboboxex-controls) no SDK do Windows.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFC_CComboBox#27](../../mfc/reference/codesnippet/cpp/ccombobox-class_27.cpp)]

##  <a name="limittext"></a>  CComboBox::LimitText

Limita o comprimento em bytes, do texto que o usuário pode inserir no controle de edição de uma caixa de combinação.

```
BOOL LimitText(int nMaxChars);
```

### <a name="parameters"></a>Parâmetros

*nMaxChars*<br/>
Especifica o comprimento (em bytes) do texto que o usuário pode inserir. Se esse parâmetro for 0, o comprimento do texto é definido como 65.535 bytes.

### <a name="return-value"></a>Valor de retorno

Diferente de zero se for bem-sucedido. Se for chamado para uma caixa de combinação com o estilo [CBS_DROPDOWNLIST](../../mfc/reference/styles-used-by-mfc.md#combo-box-styles) ou para uma caixa de combinação sem um controle de edição, o valor de retorno será CB_ERR.

### <a name="remarks"></a>Comentários

Se a caixa de combinação não tem o estilo [CBS_AUTOHSCROLL](../../mfc/reference/styles-used-by-mfc.md#combo-box-styles), definir o limite de texto para ser maior que o tamanho do controle de edição não terá efeito.

`LimitText` apenas limita o texto que o usuário pode inserir. Ele tem nenhum efeito em qualquer texto já está no controle de edição quando a mensagem é enviada, nem afeta o tamanho do texto copiado para o controle de edição quando uma cadeia de caracteres na caixa de listagem está selecionada.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFC_CComboBox#28](../../mfc/reference/codesnippet/cpp/ccombobox-class_28.cpp)]

##  <a name="measureitem"></a>  CComboBox::MeasureItem

Chamado pelo framework quando uma caixa de combinação com um estilo de desenho proprietário é criada.

```
virtual void MeasureItem(LPMEASUREITEMSTRUCT lpMeasureItemStruct);
```

### <a name="parameters"></a>Parâmetros

*lpMeasureItemStruct*<br/>
Um ponteiro longo para um [MEASUREITEMSTRUCT](../../mfc/reference/measureitemstruct-structure.md) estrutura.

### <a name="remarks"></a>Comentários

Por padrão, essa função membro não faz nada. Substituir essa função de membro e preencha o `MEASUREITEMSTRUCT` estrutura para informar ao Windows das dimensões da lista de caixa na caixa de combinação. Se a caixa de combinação é criada com o [CBS_OWNERDRAWVARIABLE](../../mfc/reference/styles-used-by-mfc.md#combo-box-styles) estilo, a estrutura chama essa função de membro para cada item na caixa de listagem. Caso contrário, esse membro é chamado apenas uma vez.

Usando o estilo CBS_OWNERDRAWFIXED em uma caixa de combinação do desenho proprietário criados com o [SubclassDlgItem](../../mfc/reference/cwnd-class.md#subclassdlgitem) função de membro de `CWnd` envolve considerações de programação ainda mais. Consulte a discussão na [14 de observação técnica](../../mfc/tn014-custom-controls.md).

Ver [CWnd::OnMeasureItem](../../mfc/reference/cwnd-class.md#onmeasureitem) para obter uma descrição de `MEASUREITEMSTRUCT` estrutura.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFC_CComboBox#29](../../mfc/reference/codesnippet/cpp/ccombobox-class_29.cpp)]

##  <a name="paste"></a>  CComboBox::Paste

Insere os dados da área de transferência no controle de edição da caixa de combinação na posição atual do cursor.

```
void Paste();
```

### <a name="remarks"></a>Comentários

Dados são inseridos somente se a área de transferência contém dados no formato CF_TEXT.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFC_CComboBox#30](../../mfc/reference/codesnippet/cpp/ccombobox-class_30.cpp)]

##  <a name="resetcontent"></a>  CComboBox::ResetContent

Remove todos os itens da lista de caixa e editar o controle de uma caixa de combinação.

```
void ResetContent();
```

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFC_CComboBox#31](../../mfc/reference/codesnippet/cpp/ccombobox-class_31.cpp)]

##  <a name="selectstring"></a>  CComboBox::SelectString

Pesquisa uma cadeia de caracteres na caixa de listagem de uma caixa de combinação e se a cadeia de caracteres for encontrada, seleciona a cadeia de caracteres na caixa de listagem e copia para o controle de edição.

```
int SelectString(
    int nStartAfter,
    LPCTSTR lpszString);
```

### <a name="parameters"></a>Parâmetros

*nStartAfter*<br/>
Contém o índice baseado em zero do item antes do primeiro item a ser pesquisado. Quando a pesquisa alcançar a parte inferior da caixa de listagem, ele continua na parte superior da caixa de listagem para o item especificado pela *nStartAfter*. Se-1, a caixa de listagem inteira é pesquisada desde o início.

*lpszString*<br/>
Aponta para a cadeia de caracteres terminada em nulo que contém o prefixo a ser pesquisado. A pesquisa é o caso independente, portanto, essa cadeia de caracteres pode conter qualquer combinação de letras maiusculas e minúsculas.

### <a name="return-value"></a>Valor de retorno

O índice baseado em zero do item selecionado se a cadeia de caracteres foi encontrada. Se a pesquisa tiver sido bem-sucedida, o valor de retorno será CB_ERR e a seleção atual não é alterada.

### <a name="remarks"></a>Comentários

Uma cadeia de caracteres é selecionada apenas se seus caracteres inicias (do ponto de partida) corresponder aos caracteres na cadeia de caracteres de prefixo.

Observe que o `SelectString` e `FindString` funções de membro localizar uma cadeia de caracteres, mas o `SelectString` função de membro também seleciona a cadeia de caracteres.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFC_CComboBox#32](../../mfc/reference/codesnippet/cpp/ccombobox-class_32.cpp)]

##  <a name="setcuebanner"></a>  CComboBox::SetCueBanner

Define o texto de indicação que é exibido para um controle de caixa de combinação.

```
BOOL SetCueBanner(LPCTSTR lpszText);
```

### <a name="parameters"></a>Parâmetros

|Parâmetro|Descrição|
|---------------|-----------------|
|*lpszText*|[in] Ponteiro para um buffer de terminação nula que contém o texto de indicação.|

### <a name="return-value"></a>Valor de retorno

TRUE se o método for bem-sucedido; Caso contrário, FALSE.

### <a name="remarks"></a>Comentários

Texto de indicação é um aviso que é exibido na área de entrada de controle de caixa de combinação. O texto de indicação é exibido até que o usuário forneça uma entrada.

Esse método envia o [CB_SETCUEBANNER](/windows/desktop/Controls/cb-setcuebanner) mensagem, que é descrita no SDK do Windows.

### <a name="example"></a>Exemplo

O exemplo de código a seguir define a variável *m_combobox*, que é usado para acessar programaticamente o controle de caixa de combinação. Essa variável é usada no exemplo a seguir.

[!code-cpp[NVC_MFC_CComboBox_s1#1](../../mfc/reference/codesnippet/cpp/ccombobox-class_33.h)]

### <a name="example"></a>Exemplo

O exemplo de código a seguir define a faixa de indicação para o controle de caixa de combinação.

[!code-cpp[NVC_MFC_CComboBox_s1#2](../../mfc/reference/codesnippet/cpp/ccombobox-class_34.cpp)]

##  <a name="setcursel"></a>  CComboBox::SetCurSel

Seleciona uma cadeia de caracteres na caixa de listagem de uma caixa de combinação.

```
int SetCurSel(int nSelect);
```

### <a name="parameters"></a>Parâmetros

*nSelecione*<br/>
Especifica o índice baseado em zero da cadeia de caracteres para selecionar. Se-1, qualquer seleção atual na caixa de listagem é removida e o controle de edição está desmarcado.

### <a name="return-value"></a>Valor de retorno

O índice baseado em zero do item selecionado se a mensagem for bem-sucedida. O valor de retorno será CB_ERR se *nSelecione* é maior que o número de itens na lista ou se *nSelecione* é definido como -1, que limpa a seleção.

### <a name="remarks"></a>Comentários

Se necessário, a caixa de listagem rola a cadeia de caracteres na exibição (se a caixa de listagem é visível). O texto no controle de edição da caixa de combinação é alterado para refletir a nova seleção. Qualquer seleção anterior na caixa de listagem é removida.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFC_CComboBox#33](../../mfc/reference/codesnippet/cpp/ccombobox-class_35.cpp)]

##  <a name="setdroppedwidth"></a>  CComboBox::SetDroppedWidth

Chame essa função para definir a largura mínima permitida, em pixels, da caixa de listagem de uma caixa de combinação.

```
int SetDroppedWidth(UINT nWidth);
```

### <a name="parameters"></a>Parâmetros

*nWidth*<br/>
A largura mínima permitida da parte de caixa de listagem da caixa de combinação, em pixels.

### <a name="return-value"></a>Valor de retorno

Se for bem-sucedido, a nova largura da caixa de listagem, caso contrário CB_ERR.

### <a name="remarks"></a>Comentários

Essa função só se aplica a caixas de combinação com o [CBS_DROPDOWN](../../mfc/reference/styles-used-by-mfc.md#combo-box-styles) ou [CBS_DROPDOWNLIST](../../mfc/reference/styles-used-by-mfc.md#combo-box-styles) estilo.

Por padrão, a largura mínima permitida da caixa de listagem suspensa é 0. Quando a parte da caixa de listagem da caixa de combinação é exibida, sua largura seja o maior entre a largura mínima de permitidos ou a largura da caixa de combinação.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFC_CComboBox#34](../../mfc/reference/codesnippet/cpp/ccombobox-class_36.cpp)]

##  <a name="seteditsel"></a>  CComboBox::SetEditSel

Seleciona os caracteres no controle de edição de uma caixa de combinação.

```
BOOL SetEditSel(
    int nStartChar,
    int nEndChar);
```

### <a name="parameters"></a>Parâmetros

*nStartChar*<br/>
Especifica a posição inicial. Se a posição inicial é definida como -1, em seguida, qualquer seleção existente será removida.

*nEndChar*<br/>
Especifica a posição final. Se a posição final estiver definida como -1, em seguida, todo o texto da posição inicial até o último caractere no controle de edição é selecionado.

### <a name="return-value"></a>Valor de retorno

Diferente de zero se a função de membro for bem-sucedida; Caso contrário, 0. Ele será CB_ERR se `CComboBox` tem o [CBS_DROPDOWNLIST](../../mfc/reference/styles-used-by-mfc.md#combo-box-styles) estilizar ou não tem uma caixa de listagem.

### <a name="remarks"></a>Comentários

As posições são baseados em zero. Para selecionar o primeiro caractere de controle de edição, você deve especificar uma posição inicial de 0. A posição final é o caractere logo após o último caractere para selecionar. Por exemplo, para selecionar os quatro primeiros caracteres do controle de edição, você usaria uma posição inicial de 0 e uma posição final de 4.

> [!NOTE]
>  Não há suporte para essa função, o Windows `ComboBoxEx` controle. Para obter mais informações sobre esse controle, consulte [ComboBoxEx controles](/windows/desktop/Controls/comboboxex-controls) no SDK do Windows.

### <a name="example"></a>Exemplo

  Veja o exemplo de [CComboBox::GetEditSel](#geteditsel).

##  <a name="setextendedui"></a>  CComboBox::SetExtendedUI

Chame o `SetExtendedUI` função de membro para selecionar a interface do usuário padrão ou a interface do usuário estendida para uma caixa de combinação que tem o [CBS_DROPDOWN](../../mfc/reference/styles-used-by-mfc.md#combo-box-styles) ou [CBS_DROPDOWNLIST](../../mfc/reference/styles-used-by-mfc.md#combo-box-styles) estilo.

```
int SetExtendedUI(BOOL bExtended = TRUE);
```

### <a name="parameters"></a>Parâmetros

*bO*<br/>
Especifica se a caixa de combinação deve usar a interface do usuário estendida ou a interface do usuário padrão. Um valor TRUE seleciona a interface do usuário estendida; um valor FALSE seleciona a interface de usuário padrão.

### <a name="return-value"></a>Valor de retorno

CB_OKAY se a operação for bem-sucedida, ou CB_ERR se ocorrer um erro.

### <a name="remarks"></a>Comentários

A interface do usuário estendida pode ser identificada das seguintes maneiras:

- Clicando no controle estático exibe a caixa de listagem somente para caixas de combinação com o estilo CBS_DROPDOWNLIST.

- Pressionar a tecla de seta para baixo exibirá a caixa de lista (F4 está desabilitado).

Rolagem no controle estático é desabilitada quando a lista de itens não estiver visível (e as teclas de direção estão desabilitadas).

### <a name="example"></a>Exemplo

  Veja o exemplo de [CComboBox::GetExtendedUI](#getextendedui).

##  <a name="sethorizontalextent"></a>  CComboBox::SetHorizontalExtent

Define a largura, em pixels, pela qual a parte da caixa de listagem da caixa de combinação pode ser rolada horizontalmente.

```
void SetHorizontalExtent(UINT nExtent);
```

### <a name="parameters"></a>Parâmetros

*nExtent*<br/>
Especifica o número de pixels pelo qual a parte da caixa de listagem da caixa de combinação pode ser rolada horizontalmente.

### <a name="remarks"></a>Comentários

Se a largura da caixa de listagem é menor do que esse valor, a barra de rolagem horizontal rolar horizontalmente itens na caixa de listagem. Se a largura da caixa de listagem é igual ou maior que esse valor, a barra de rolagem horizontal está oculto ou, se a caixa de combinação com o [CBS_DISABLENOSCROLL](../../mfc/reference/styles-used-by-mfc.md#combo-box-styles) estilo, desabilitado.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFC_CComboBox#35](../../mfc/reference/codesnippet/cpp/ccombobox-class_37.cpp)]

##  <a name="setitemdata"></a>  CComboBox::SetItemData

Define o valor de 32 bits associado com o item especificado em uma caixa de combinação.

```
int SetItemData(
    int nIndex,
    DWORD_PTR dwItemData);
```

### <a name="parameters"></a>Parâmetros

*nIndex*<br/>
Contém um índice baseado em zero para o item a ser definido.

*dwItemData*<br/>
Contém o novo valor a ser associado ao item.

### <a name="return-value"></a>Valor de retorno

CB_ERR se ocorrer um erro.

### <a name="remarks"></a>Comentários

Use o `SetItemDataPtr` se o item de 32 bits deve ser um ponteiro de função de membro.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFC_CComboBox#36](../../mfc/reference/codesnippet/cpp/ccombobox-class_38.cpp)]

##  <a name="setitemdataptr"></a>  CComboBox::SetItemDataPtr

Define o valor de 32 bits associado com o item especificado em uma caixa de combinação para ser o ponteiro especificado (**void** <strong>\*</strong>).

```
int SetItemDataPtr(
    int nIndex,
    void* pData);
```

### <a name="parameters"></a>Parâmetros

*nIndex*<br/>
Contém um índice baseado em zero para o item.

*pData*<br/>
Contém o ponteiro para associar o item.

### <a name="return-value"></a>Valor de retorno

CB_ERR se ocorrer um erro.

### <a name="remarks"></a>Comentários

Esse ponteiro permanece válido durante a vida útil da caixa de combinação, mesmo que a posição relativa do item dentro da caixa de combinação pode mudar à medida que itens são adicionados ou removidos. Portanto, o índice do item dentro da caixa pode alterar, mas o ponteiro permanece confiável.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFC_CComboBox#37](../../mfc/reference/codesnippet/cpp/ccombobox-class_39.cpp)]

##  <a name="setitemheight"></a>  CComboBox::SetItemHeight

Chamar o `SetItemHeight` a função de membro para definir a altura de itens de lista em uma caixa de combinação ou a altura da parte do controle de edição (ou texto estático) de uma caixa de combinação.

```
int SetItemHeight(
    int nIndex,
    UINT cyItemHeight);
```

### <a name="parameters"></a>Parâmetros

*nIndex*<br/>
Especifica se a altura de itens de lista ou a altura da parte do controle de edição (ou texto estático) da caixa de combinação é definida.

Se a caixa de combinação com o [CBS_OWNERDRAWVARIABLE](../../mfc/reference/styles-used-by-mfc.md#combo-box-styles) estilo *nIndex* Especifica o índice baseado em zero do item de lista cuja altura deve ser definida; caso contrário, *nIndex* deve ser 0 e a altura de todos os itens de lista será definida.

Se *nIndex* é -1, a altura do controle de edição ou parte do texto estático da caixa de combinação deve ser definido.

*cyItemHeight*<br/>
Especifica a altura, em pixels, do componente caixa de combinação identificado pelo *nIndex*.

### <a name="return-value"></a>Valor de retorno

CB_ERR se o índice ou a altura é inválida; Caso contrário, 0.

### <a name="remarks"></a>Comentários

A altura da parte do controle de edição (ou texto estático) da caixa de combinação é definida independentemente da altura dos itens da lista. Um aplicativo deve garantir que a altura da parte do controle de edição (ou texto estático) não é menor do que a altura de um item específico da caixa de listagem.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFC_CComboBox#38](../../mfc/reference/codesnippet/cpp/ccombobox-class_40.cpp)]

##  <a name="setlocale"></a>  CComboBox::SetLocale

Define o identificador de localidade para esta caixa de combinação.

```
LCID SetLocale(LCID nNewLocale);
```

### <a name="parameters"></a>Parâmetros

*nNewLocale*<br/>
O novo valor LCID (identificador) de localidade a ser definido para a caixa de combinação.

### <a name="return-value"></a>Valor de retorno

O valor LCID (identificador) localidade anterior para a caixa de combinação.

### <a name="remarks"></a>Comentários

Se `SetLocale` não for chamado, o padrão localidade é obtida do sistema. Essa localidade padrão do sistema pode ser modificada por meio do painel de controle de aplicativo regionais (ou internacional).

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFC_CComboBox#39](../../mfc/reference/codesnippet/cpp/ccombobox-class_41.cpp)]

##  <a name="setminvisibleitems"></a>  CComboBox::SetMinVisibleItems

Define o número mínimo de itens visíveis na lista suspensa da caixa de combinação de atual de controle de caixa.

```
BOOL SetMinVisibleItems(int iMinVisible);
```

### <a name="parameters"></a>Parâmetros

|Parâmetro|Descrição|
|---------------|-----------------|
|*iMinVisible*|[in] Especifica o número mínimo de itens visíveis.|

### <a name="return-value"></a>Valor de retorno

TRUE se esse método for bem-sucedida; Caso contrário, FALSE.

### <a name="remarks"></a>Comentários

Esse método envia o [CB_SETMINVISIBLE](/windows/desktop/Controls/cb-setminvisible) mensagem, que é descrita no SDK do Windows.

### <a name="example"></a>Exemplo

O exemplo de código a seguir define a variável *m_combobox*, que é usado para acessar programaticamente o controle de caixa de combinação. Essa variável é usada no exemplo a seguir.

[!code-cpp[NVC_MFC_CComboBox_s1#1](../../mfc/reference/codesnippet/cpp/ccombobox-class_33.h)]

### <a name="example"></a>Exemplo

O exemplo de código a seguir insere 20 itens na lista suspensa de um controle de caixa de combinação. Em seguida, ele especifica que um mínimo de 10 itens ser exibida quando um usuário pressiona a seta suspensa.

[!code-cpp[NVC_MFC_CComboBox_s1#2](../../mfc/reference/codesnippet/cpp/ccombobox-class_34.cpp)]

##  <a name="settopindex"></a>  CComboBox::SetTopIndex

Garante que um determinado item está visível na parte de caixa de listagem da caixa de combinação.

```
int SetTopIndex(int nIndex);
```

### <a name="parameters"></a>Parâmetros

*nIndex*<br/>
Especifica o índice baseado em zero do item de caixa de listagem.

### <a name="return-value"></a>Valor de retorno

Zero se tiver êxito, ou CB_ERR se ocorrer um erro.

### <a name="remarks"></a>Comentários

O sistema rola para a caixa de listagem até que o item especificado pelo *nIndex* aparece na parte superior da lista de caixa ou o intervalo de rolagem máximo foi atingido.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFC_CComboBox#40](../../mfc/reference/codesnippet/cpp/ccombobox-class_42.cpp)]

##  <a name="showdropdown"></a>  CComboBox::ShowDropDown

Mostra ou oculta a caixa de listagem de uma caixa de combinação que tem o [CBS_DROPDOWN](../../mfc/reference/styles-used-by-mfc.md#combo-box-styles) ou [CBS_DROPDOWNLIST](../../mfc/reference/styles-used-by-mfc.md#combo-box-styles) estilo.

```
void ShowDropDown(BOOL bShowIt = TRUE);
```

### <a name="parameters"></a>Parâmetros

*bShowIt*<br/>
Especifica se a caixa de listagem suspensa deve ser mostrado ou ocultado. Um valor TRUE mostra a caixa de listagem. Um valor falso oculta a caixa de listagem.

### <a name="remarks"></a>Comentários

Por padrão, uma caixa de combinação desse estilo mostrará a caixa de listagem.

Essa função de membro não tem nenhum efeito em uma caixa de combinação criado com o [CBS_SIMPLE](../../mfc/reference/styles-used-by-mfc.md#combo-box-styles) estilo.

### <a name="example"></a>Exemplo

  Veja o exemplo de [CComboBox::GetDroppedState](#getdroppedstate).

## <a name="see-also"></a>Consulte também

[Exemplo MFC CTRLBARS](../../visual-cpp-samples.md)<br/>
[Classe CWnd](../../mfc/reference/cwnd-class.md)<br/>
[Gráfico da hierarquia](../../mfc/hierarchy-chart.md)<br/>
[Classe CWnd](../../mfc/reference/cwnd-class.md)<br/>
[Classe CButton](../../mfc/reference/cbutton-class.md)<br/>
[Classe CEdit](../../mfc/reference/cedit-class.md)<br/>
[Classe CListBox](../../mfc/reference/clistbox-class.md)<br/>
[Classe CScrollBar](../../mfc/reference/cscrollbar-class.md)<br/>
[Classe CStatic](../../mfc/reference/cstatic-class.md)<br/>
[Classe CDialog](../../mfc/reference/cdialog-class.md)
