---
title: CMFCToolBarComboBoxClasse de botão
ms.date: 11/04/2016
f1_keywords:
- CMFCToolBarComboBoxButton
- AFXTOOLBARCOMBOBOXBUTTON/CMFCToolBarComboBoxButton
- AFXTOOLBARCOMBOBOXBUTTON/CMFCToolBarComboBoxButton::CMFCToolBarComboBoxButton
- AFXTOOLBARCOMBOBOXBUTTON/CMFCToolBarComboBoxButton::AddItem
- AFXTOOLBARCOMBOBOXBUTTON/CMFCToolBarComboBoxButton::AddSortedItem
- AFXTOOLBARCOMBOBOXBUTTON/CMFCToolBarComboBoxButton::Compare
- AFXTOOLBARCOMBOBOXBUTTON/CMFCToolBarComboBoxButton::CreateEdit
- AFXTOOLBARCOMBOBOXBUTTON/CMFCToolBarComboBoxButton::DeleteItem
- AFXTOOLBARCOMBOBOXBUTTON/CMFCToolBarComboBoxButton::FindItem
- AFXTOOLBARCOMBOBOXBUTTON/CMFCToolBarComboBoxButton::GetByCmd
- AFXTOOLBARCOMBOBOXBUTTON/CMFCToolBarComboBoxButton::GetComboBox
- AFXTOOLBARCOMBOBOXBUTTON/CMFCToolBarComboBoxButton::GetCount
- AFXTOOLBARCOMBOBOXBUTTON/CMFCToolBarComboBoxButton::GetCountAll
- AFXTOOLBARCOMBOBOXBUTTON/CMFCToolBarComboBoxButton::GetCurSel
- AFXTOOLBARCOMBOBOXBUTTON/CMFCToolBarComboBoxButton::GetCurSelAll
- AFXTOOLBARCOMBOBOXBUTTON/CMFCToolBarComboBoxButton::GetEditCtrl
- AFXTOOLBARCOMBOBOXBUTTON/CMFCToolBarComboBoxButton::GetItem
- AFXTOOLBARCOMBOBOXBUTTON/CMFCToolBarComboBoxButton::GetItemAll
- AFXTOOLBARCOMBOBOXBUTTON/CMFCToolBarComboBoxButton::GetItemData
- AFXTOOLBARCOMBOBOXBUTTON/CMFCToolBarComboBoxButton::GetItemDataAll
- AFXTOOLBARCOMBOBOXBUTTON/CMFCToolBarComboBoxButton::GetItemDataPtrAll
- AFXTOOLBARCOMBOBOXBUTTON/CMFCToolBarComboBoxButton::GetText
- AFXTOOLBARCOMBOBOXBUTTON/CMFCToolBarComboBoxButton::GetTextAll
- AFXTOOLBARCOMBOBOXBUTTON/CMFCToolBarComboBoxButton::IsCenterVert
- AFXTOOLBARCOMBOBOXBUTTON/CMFCToolBarComboBoxButton::IsFlatMode
- AFXTOOLBARCOMBOBOXBUTTON/CMFCToolBarComboBoxButton::RemoveAllItems
- AFXTOOLBARCOMBOBOXBUTTON/CMFCToolBarComboBoxButton::SelectItem
- AFXTOOLBARCOMBOBOXBUTTON/CMFCToolBarComboBoxButton::SelectItemAll
- AFXTOOLBARCOMBOBOXBUTTON/CMFCToolBarComboBoxButton::SetCenterVert
- AFXTOOLBARCOMBOBOXBUTTON/CMFCToolBarComboBoxButton::SetDropDownHeight
- AFXTOOLBARCOMBOBOXBUTTON/CMFCToolBarComboBoxButton::SetFlatMode
helpviewer_keywords:
- CMFCToolBarComboBoxButton [MFC], CMFCToolBarComboBoxButton
- CMFCToolBarComboBoxButton [MFC], AddItem
- CMFCToolBarComboBoxButton [MFC], AddSortedItem
- CMFCToolBarComboBoxButton [MFC], Compare
- CMFCToolBarComboBoxButton [MFC], CreateEdit
- CMFCToolBarComboBoxButton [MFC], DeleteItem
- CMFCToolBarComboBoxButton [MFC], FindItem
- CMFCToolBarComboBoxButton [MFC], GetByCmd
- CMFCToolBarComboBoxButton [MFC], GetComboBox
- CMFCToolBarComboBoxButton [MFC], GetCount
- CMFCToolBarComboBoxButton [MFC], GetCountAll
- CMFCToolBarComboBoxButton [MFC], GetCurSel
- CMFCToolBarComboBoxButton [MFC], GetCurSelAll
- CMFCToolBarComboBoxButton [MFC], GetEditCtrl
- CMFCToolBarComboBoxButton [MFC], GetItem
- CMFCToolBarComboBoxButton [MFC], GetItemAll
- CMFCToolBarComboBoxButton [MFC], GetItemData
- CMFCToolBarComboBoxButton [MFC], GetItemDataAll
- CMFCToolBarComboBoxButton [MFC], GetItemDataPtrAll
- CMFCToolBarComboBoxButton [MFC], GetText
- CMFCToolBarComboBoxButton [MFC], GetTextAll
- CMFCToolBarComboBoxButton [MFC], IsCenterVert
- CMFCToolBarComboBoxButton [MFC], IsFlatMode
- CMFCToolBarComboBoxButton [MFC], RemoveAllItems
- CMFCToolBarComboBoxButton [MFC], SelectItem
- CMFCToolBarComboBoxButton [MFC], SelectItemAll
- CMFCToolBarComboBoxButton [MFC], SetCenterVert
- CMFCToolBarComboBoxButton [MFC], SetDropDownHeight
- CMFCToolBarComboBoxButton [MFC], SetFlatMode
ms.assetid: 32fa39f7-8e4e-4f0a-a31d-7b540d969a6c
ms.openlocfilehash: 0d003bdacf13403ad8dc4be4ec7e6f71ea57d156
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81372188"
---
# <a name="cmfctoolbarcomboboxbutton-class"></a>CMFCToolBarComboBoxClasse de botão

Um botão de barra de ferramentas que contém um controle de caixa combo [(CComboBox Class](../../mfc/reference/ccombobox-class.md)).

## <a name="syntax"></a>Sintaxe

```
class CMFCToolBarComboBoxButton : public CMFCToolBarButton
```

## <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores públicos

|Nome|Descrição|
|----------|-----------------|
|[CMFCToolBarComboBoxButton::CMFCToolBarComboBoxBotão](#cmfctoolbarcomboboxbutton)|Constrói um `CMFCToolBarComboBoxButton`.|

### <a name="public-methods"></a>Métodos públicos

|Nome|Descrição|
|----------|-----------------|
|[CMFCToolBarComboBoxButton::AddItem](#additem)|Adiciona um item ao final da lista de caixas de combinação.|
|[CMFCToolBarComboBoxButton::AddSortedItem](#addsorteditem)|Adiciona um item à lista de caixas de combinação. A ordem dos itens da lista é `Compare`especificada por .|
|[CMFCToolBarComboBoxButton::Compare](#compare)|Compara dois itens. Chamado para classificar itens `AddSortedItems` que adicionam à lista de caixas de combinação.|
|[CMFCToolBarComboBoxButton::CreateEdit](#createedit)|Cria um novo controle de edição para o botão de caixa de combinação.|
|[CMFCToolBarComboBoxButton::DeleteItem](#deleteitem)|Exclui um item da lista de caixas de combinação.|
|[CMFCToolBarComboBoxButton::FindItem](#finditem)|Retorna o índice do item que contém uma seqüência de string especificada.|
|[CMFCToolBarComboBoxButton::GetByCmd](#getbycmd)|Retorna um ponteiro para o botão da caixa de combinação com um ID de comando especificado.|
|[CMFCToolBarComboBoxButton::GetComboBox](#getcombobox)|Retorna um ponteiro para o controle da caixa de combinação que está incorporado no botão da caixa de combinação.|
|[CMFCToolBarComboBoxButton::GetCount](#getcount)|Retorna o número de itens na lista de caixas de combinação.|
|[CMFCToolBarComboBoxButton::GetCountAll](#getcountall)|Encontra o botão de caixa de combinação que tem um ID de comando especificado. Retorna o número de itens na lista de caixas de combinação desse botão.|
|[CMFCToolBarComboBoxButton::GetCurSel](#getcursel)|Retorna o índice do item selecionado na lista de caixas de combinação.|
|[CMFCToolBarComboBoxButton::GetCurSelAll](#getcurselall)|Encontra o botão de caixa de combinação que tem um ID de comando especificado e retorna o índice do item selecionado na lista de caixas de combinação desse botão.|
|[CMFCToolBarComboBoxButton::GetEditCtrl](#geteditctrl)|Retorna um ponteiro para o controle de edição que está incorporado no botão de caixa de combinação.|
|[CMFCToolBarComboBoxButton::GetItem](#getitem)|Retorna a seqüência de string associada a um índice especificado na lista de caixas de combinação.|
|[CMFCToolBarComboBoxButton::GetItemAll](#getitemall)|Encontra o botão de caixa de combinação que tem um ID de comando especificado e retorna a string que está associada a um índice na lista de caixas de combinação desse botão.|
|[CMFCToolBarComboBoxButton::GetItemData](#getitemdata)|Retorna o valor de 32 bits associado a um índice especificado na lista de caixas de combinação.|
|[CMFCToolBarComboBoxButton::GetItemDataAll](#getitemdataall)|Encontra o botão de caixa de combinação que tem um ID de comando especificado e retorna o valor de 32 bits que está associado a um índice na lista de caixas de combinação desse botão.|
|[CMFCToolBarComboBoxButton::GetItemDataPtrAll](#getitemdataptrall)|Encontra o botão de caixa de combinação que tem um ID de comando especificado. Recupera o valor de 32 bits que está associado a um índice na lista de caixas de combinação desse botão e retorna o valor de 32 bits como ponteiro.|
|[CMFCToolBarComboBoxButton::GetText](#gettext)|Retorna o texto do controle de edição da caixa de combinação.|
|[CMFCToolBarComboBoxButton::GetTextAll](#gettextall)|Encontra o botão de caixa de combinação que tem um ID de comando especificado e retorna o texto do controle de edição desse botão.|
|[CMFCToolBarComboBoxButton::IsCenterVert](#iscentervert)|Determina se os botões da caixa combo no aplicativo estão centrados ou alinhados com a parte superior da barra de ferramentas.|
|[CMFCToolBarComboBoxButton::IsFlatMode](#isflatmode)|Determina se os botões da caixa combo no aplicativo têm uma aparência plana.|
|[CMFCToolBarComboBoxButton::RemoveAllItems](#removeallitems)|Remove todos os itens da caixa de lista e edita o controle da caixa de combinação.|
|[CMFCToolBarComboBoxButton::SelectItem](#selectitem)|Seleciona um item na caixa de combinação de acordo com seu índice, valor de 32 bits ou string, e notifica o controle da caixa de combinação sobre a seleção.|
|[CMFCToolBarComboBoxButton::SelectItemAll](#selectitemall)|Encontra o botão de caixa de combinação que tem um ID de comando especificado. Chama `SelectItem` para selecionar um item na caixa de combinação desse botão de acordo com seu valor de string, índice ou 32 bits.|
|[CMFCToolBarComboBoxButton::SetCenterVert](#setcentervert)|Especifica se os botões da caixa combo no aplicativo estão centrados verticalmente ou alinhados com a parte superior da barra de ferramentas.|
|[CMFCToolBarComboBoxButton::SetDropDownHeight](#setdropdownheight)|Define a altura da caixa de lista baixa.|
|[CMFCToolBarComboBoxButton::SetFlatMode](#setflatmode)|Especifica se os botões da caixa combo no aplicativo têm uma aparência plana.|

## <a name="remarks"></a>Comentários

Para adicionar um botão de caixa combo a uma barra de ferramentas, siga estas etapas:

1. Reserve um ID de recurso de boneco para o botão no recurso da barra de ferramentas pai.

2. Construa `CMFCToolBarComboBoxButton` um objeto.

3. No manipulador de mensagens que processa a mensagem AFX_WM_RESETTOOLBAR, substitua o botão manequim pelo novo botão de caixa de combinação usando [CMFCToolBar::ReplaceButton](../../mfc/reference/cmfctoolbar-class.md#replacebutton).

Para obter mais informações, consulte [Passo a Passo: Colocando controles nas barras de ferramentas](../../mfc/walkthrough-putting-controls-on-toolbars.md). Para um exemplo de um botão de barra de ferramentas da caixa de combinação, consulte o exemplo do projeto VisualStudioDemo.

## <a name="example"></a>Exemplo

O exemplo a seguir demonstra como `CMFCToolBarComboBoxButton` usar vários métodos na classe. O exemplo mostra como ativar as caixas de edição e combinação, definir a posição vertical dos botões de caixa de combinação no aplicativo, definir a altura da caixa de lista quando ela for derrubada, definir a aparência de estilo plano dos botões de caixa de combinação no aplicativo e definir o texto na caixa de edição do botão de caixa de combinação. Este trecho de código faz parte da [amostra visual studio demo](../../overview/visual-cpp-samples.md).

[!code-cpp[NVC_MFC_VisualStudioDemo#36](../../mfc/codesnippet/cpp/cmfctoolbarcomboboxbutton-class_1.cpp)]
[!code-cpp[NVC_MFC_VisualStudioDemo#37](../../mfc/codesnippet/cpp/cmfctoolbarcomboboxbutton-class_2.cpp)]

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

[Cobject](../../mfc/reference/cobject-class.md)

[Cmfctoolbarbutton](../../mfc/reference/cmfctoolbarbutton-class.md)

[Cmfctoolbarcomboboxbutton](../../mfc/reference/cmfctoolbarcomboboxbutton-class.md)

## <a name="requirements"></a>Requisitos

**Cabeçalho:** afxtoolbarcomboboxbutton.h

## <a name="cmfctoolbarcomboboxbuttonadditem"></a><a name="additem"></a>CMFCToolBarComboBoxButton::AddItem

Anexa um item exclusivo à caixa de lista.

```
virtual INT_PTR AddItem(
    LPCTSTR lpszItem,
    DWORD_PTR dwData=0);
```

### <a name="parameters"></a>Parâmetros

*Lpszitem*<br/>
[em] O texto do item para adicionar à caixa de lista.

*Dwdata*<br/>
[em] Os dados associados ao item para adicionar à caixa de lista.

### <a name="return-value"></a>Valor retornado

O índice do último item na caixa de lista.

### <a name="remarks"></a>Comentários

Não use este método quando o estilo da caixa de lista estiver classificado.

Se o texto do item já estiver na caixa de lista, os novos dados são armazenados com o item existente. A busca pelo item é sensível ao caso.

## <a name="cmfctoolbarcomboboxbuttonaddsorteditem"></a><a name="addsorteditem"></a>CMFCToolBarComboBoxButton::AddSortedItem

Adiciona um item à caixa de lista na ordem definida pelo método [Compare.](#compare)

```
virtual INT_PTR AddSortedItem(
    LPCTSTR lpszItem,
    DWORD_PTR dwData=0);
```

### <a name="parameters"></a>Parâmetros

*Lpszitem*<br/>
[em] O texto do item para adicionar à caixa de lista.

*Dwdata*<br/>
[em] Os dados associados ao item para adicionar à caixa de lista.

### <a name="return-value"></a>Valor retornado

Índice do item que foi adicionado à caixa de lista.

### <a name="remarks"></a>Comentários

Use esta função para adicionar itens à caixa de lista em uma ordem específica.

## <a name="cmfctoolbarcomboboxbuttoncanbestretched"></a><a name="canbestretched"></a>CMFCToolBarComboBoxButton::CanBeStretched

Indica se o tamanho do botão da caixa combo pode mudar.

```
virtual BOOL CanBeStretched() const;
```

### <a name="return-value"></a>Valor retornado

Retorna TRUE.

## <a name="cmfctoolbarcomboboxbuttoncmfctoolbarcomboboxbutton"></a><a name="cmfctoolbarcomboboxbutton"></a>CMFCToolBarComboBoxButton::CMFCToolBarComboBoxBotão

Constrói um objeto [CMFCToolBarComboBoxButton.](../../mfc/reference/cmfctoolbarcomboboxbutton-class.md)

```
CMFCToolBarComboBoxButton(
    UINT uiID,
    int iImage,
    DWORD dwStyle=CBS_DROPDOWNLIST,
    int iWidth=0);
```

### <a name="parameters"></a>Parâmetros

*Uiid*<br/>
[em] O iD de comando do novo botão.

*Iimage*<br/>
[em] O índice de imagem da imagem associada ao novo botão.

*Dwstyle*<br/>
[em] O estilo do novo botão.

*iWidth*<br/>
[em] A largura, em pixels, do novo botão.

### <a name="remarks"></a>Comentários

A largura padrão é de 150 pixels.

Para obter uma lista de estilos de botão da barra de ferramentas, consulte [Estilos de controle da barra de ferramentas](../../mfc/reference/toolbar-control-styles.md)

## <a name="cmfctoolbarcomboboxbuttoncleardata"></a><a name="cleardata"></a>CMFCToolBarComboBoxButton::ClearData

Exclui dados definidos pelo usuário.

```
virtual void ClearData();
```

### <a name="remarks"></a>Comentários

Por padrão, este método não faz nada. Anular este método em uma classe derivada se você quiser excluir quaisquer dados definidos pelo usuário.

## <a name="cmfctoolbarcomboboxbuttoncompare"></a><a name="compare"></a>CMFCToolBarComboBoxButton::Compare

Compara duas cadeias de caracteres.

```
virtual int Compare(
    LPCTSTR lpszItem1,
    LPCTSTR lpszItem2);
```

### <a name="parameters"></a>Parâmetros

*lpszItem1*<br/>
[em] A primeira corda a ser comparada.

*lpszItem2*<br/>
[em] A segunda corda para comparar.

### <a name="return-value"></a>Valor retornado

Um valor que indica a relação lexicográfica sensível ao caso entre as cordas. A tabela a seguir lista os valores possíveis: 

|Valor|Descrição|
|-----------|-----------------|
|\<0|A primeira corda é menor que a segunda.|
|0|A primeira corda é igual à segunda.|
|>0|A primeira corda é maior que a segunda.|

### <a name="remarks"></a>Comentários

Anular este método para alterar a forma como os itens são classificados na caixa de lista.

A comparação é sensível a maiúsculas e minúsculas.

Este método é chamado apenas a partir do método [AddSortedItem.](#addsorteditem)

## <a name="cmfctoolbarcomboboxbuttoncopyfrom"></a><a name="copyfrom"></a>CMFCToolBarComboBoxButton::CopyFrom

Copia o estado do `CMFCToolBarComboBoxButton` especificado para o objeto atual.

```
virtual void CopyFrom(const CMFCToolBarButton& src);
```

### <a name="parameters"></a>Parâmetros

*src*<br/>
[em] O `CMFCToolBarComboBoxButton` objeto de origem.

## <a name="cmfctoolbarcomboboxbuttoncreatecombo"></a><a name="createcombo"></a>CMFCToolBarComboBoxButton::CreateCombo

Cria uma nova caixa de combinação para o botão de caixa de combinação.

```
virtual CComboBox* CreateCombo(
    CWnd* pWndParent,
    const CRect& rect);
```

### <a name="parameters"></a>Parâmetros

*pWndParent*<br/>
[em] Um ponteiro para a janela pai do botão.

*Rect*<br/>
[em] Retângulo delimitador da caixa de combinação.

### <a name="return-value"></a>Valor retornado

Um ponteiro para a nova caixa de combinação se o método foi bem sucedido; caso contrário, NULL.

## <a name="cmfctoolbarcomboboxbuttoncreateedit"></a><a name="createedit"></a>CMFCToolBarComboBoxButton::CreateEdit

Cria uma nova caixa de edição para o botão caixa de combinação.

```
virtual CMFCToolBarComboBoxEdit* CreateEdit(
    CWnd* pWndParent,
    const CRect& rect,
    DWORD dwEditStyle);
```

### <a name="parameters"></a>Parâmetros

*pWndParent*<br/>
[em] Um ponteiro para a janela pai do botão.

*Rect*<br/>
[em] Retângulo delimitador da nova caixa de edição.

*dwEditStyle*<br/>
[em] Estilo de controle da nova caixa de edição.

### <a name="return-value"></a>Valor retornado

Um ponteiro para a nova caixa de edição se o método foi bem sucedido; caso contrário, NULL.

### <a name="remarks"></a>Comentários

A estrutura chama esse método quando cria uma nova caixa de edição para um botão de caixa de combinação. Anular este método para alterar a forma como [o CMFCToolBarComboBoxEdit](../../mfc/reference/cmfctoolbarcomboboxedit-class.md) é criado.

## <a name="cmfctoolbarcomboboxbuttondeleteitem"></a><a name="deleteitem"></a>CMFCToolBarComboBoxButton::DeleteItem

Exclui um item especificado da caixa de lista.

```
BOOL DeleteItem(int iIndex);
BOOL DeleteItem(DWORD_PTR dwData);
BOOL DeleteItem(LPCTSTR lpszText);
```

### <a name="parameters"></a>Parâmetros

*Iindex*<br/>
[em] O índice baseado em zero do item a ser excluído.

*Dwdata*<br/>
[em] Os dados associados ao item a ser excluído.

*lpszText*<br/>
[em] O texto do item a ser excluído. Se houver vários itens com o mesmo texto, o primeiro item será excluído.

### <a name="return-value"></a>Valor retornado

TRUE se o item foi localizado e excluído com sucesso; caso contrário, FALSE.

### <a name="remarks"></a>Comentários

## <a name="cmfctoolbarcomboboxbuttonduplicatedata"></a><a name="duplicatedata"></a>CMFCToolBarComboBoxButton::DuplicateData

Duplica dados definidos pelo usuário.

```
virtual void DuplicateData();
```

### <a name="remarks"></a>Comentários

Por padrão, este método não faz nada. Anular este método em uma classe derivada se você quiser copiar quaisquer dados definidos pelo usuário.

## <a name="cmfctoolbarcomboboxbuttonenablewindow"></a><a name="enablewindow"></a>CMFCToolBarComboBoxButton::Ativarjanela

Ativa ou desativa as caixas de edição e combinação.

```
virtual void EnableWindow(BOOL bEnable = TRUE);
```

### <a name="parameters"></a>Parâmetros

*Benable*<br/>
[em] TRUE para ativar as caixas de edição e combinação; FALSE para desativar as caixas de edição e combinação.

### <a name="remarks"></a>Comentários

Quando desativados, os controles não podem se tornar ativos e não podem aceitar a entrada do usuário.

## <a name="cmfctoolbarcomboboxbuttonexporttomenubutton"></a><a name="exporttomenubutton"></a>CMFCToolBarComboBoxButton::ExportToMenuButton

Copia uma seqüência de string da tabela de strings do aplicativo para o menu especificado usando o iD de comando do botão de caixa de combinação.

```
virtual BOOL ExportToMenuButton(CMFCToolBarMenuButton& menuButton) const;
```

### <a name="parameters"></a>Parâmetros

*menuButton*<br/>
[fora] Referência a um botão de menu.

### <a name="return-value"></a>Valor retornado

Sempre TRUE.

## <a name="cmfctoolbarcomboboxbuttonfinditem"></a><a name="finditem"></a>CMFCToolBarComboBoxButton::FindItem

Retorna o índice do primeiro item na caixa de lista que contém uma seqüência de string especificada.

```
int FindItem(LPCTSTR lpszText) const;
```

### <a name="parameters"></a>Parâmetros

*lpszText*<br/>
[em] O texto para o qual procurar na caixa de lista.

### <a name="return-value"></a>Valor retornado

O índice do item; ou CB_ERR se o item não for encontrado.

### <a name="remarks"></a>Comentários

## <a name="cmfctoolbarcomboboxbuttongetbycmd"></a><a name="getbycmd"></a>CMFCToolBarComboBoxButton::GetByCmd

Obtém um ponteiro para o botão de caixa de combinação que tem um ID de comando especificado.

```
static CMFCToolBarComboBoxButton* GetByCmd(
    UINT uiCmd,
    BOOL bIsFocus=FALSE);
```

### <a name="parameters"></a>Parâmetros

*Uicmd*<br/>
[em] O ID de comando de um botão de caixa combo.

*bIsFocus*<br/>
[em] VERDADEIRO para pesquisar apenas botões focados; FALSO para pesquisar todos os botões.

### <a name="return-value"></a>Valor retornado

Um ponteiro para um botão de caixa combo; ou NULO se o botão não for encontrado.

### <a name="remarks"></a>Comentários

## <a name="cmfctoolbarcomboboxbuttongetcombobox"></a><a name="getcombobox"></a>CMFCToolBarComboBoxButton::GetComboBox

Retorna um ponteiro para a caixa de combinação no botão caixa de combinação.

```
CComboBox* GetComboBox() const;
```

### <a name="return-value"></a>Valor retornado

Um ponteiro para o objeto [Classe CComboBox](../../mfc/reference/ccombobox-class.md) se o método tiver sido bem sucedido; caso contrário, NULL.

### <a name="remarks"></a>Comentários

## <a name="cmfctoolbarcomboboxbuttongetcontextmenuid"></a><a name="getcontextmenuid"></a>CMFCToolBarComboBoxButton::GetContextMenuID

Obtém o iD de recurso do menu de atalho para o botão de caixa de combinação.

```
UINT GetContextMenuID();
```

### <a name="return-value"></a>Valor retornado

O iD de recurso do menu de atalho.

## <a name="cmfctoolbarcomboboxbuttongetcount"></a><a name="getcount"></a>CMFCToolBarComboBoxButton::GetCount

Retorna o número de itens na caixa de lista.

```
INT_PTR GetCount() const;
```

### <a name="return-value"></a>Valor retornado

O número de itens na caixa de lista.

### <a name="remarks"></a>Comentários

## <a name="cmfctoolbarcomboboxbuttongetcountall"></a><a name="getcountall"></a>CMFCToolBarComboBoxButton::GetCountAll

Obtém o número de itens na caixa de lista de um botão de caixa de combinação que tem um ID de comando especificado.

```
static int GetCountAll(UINT uiCmd);
```

### <a name="parameters"></a>Parâmetros

*Uicmd*<br/>
[em] O ID de comando de um botão de caixa combo.

### <a name="return-value"></a>Valor retornado

O número de itens na caixa de lista; caso contrário, CB_ERR se o botão da caixa de combinação não for encontrado.

### <a name="remarks"></a>Comentários

## <a name="cmfctoolbarcomboboxbuttongetcursel"></a><a name="getcursel"></a>CMFCToolBarComboBoxButton::GetCurSel

Obtém o índice do item selecionado no momento na caixa de lista.

```
int GetCurSel() const;
```

### <a name="return-value"></a>Valor retornado

O índice do item selecionado no momento na caixa de lista; ou CB_ERR se nenhum item for selecionado.

### <a name="remarks"></a>Comentários

O índice de caixa de lista é baseado em zero.

## <a name="cmfctoolbarcomboboxbuttongetcurselall"></a><a name="getcurselall"></a>CMFCToolBarComboBoxButton::GetCurSelAll

Retorna o índice do item selecionado no momento na caixa de lista de um botão de caixa de combinação que tem um ID de comando especificado.

```
static int GetCurSelAll(UINT uiCmd);
```

### <a name="parameters"></a>Parâmetros

*Uicmd*<br/>
[em] O ID de comando de um botão de caixa combo.

### <a name="return-value"></a>Valor retornado

O índice do item selecionado no momento na caixa de lista; caso contrário, CB_ERR se nenhum item for selecionado ou um botão de caixa de combinação não for encontrado.

### <a name="remarks"></a>Comentários

O índice de caixa de lista é baseado em zero.

## <a name="cmfctoolbarcomboboxbuttongeteditctrl"></a><a name="geteditctrl"></a>CMFCToolBarComboBoxButton::GetEditCtrl

Retorna um ponteiro para a caixa de edição no botão caixa de combinação.

```
virtual CEdit* GetEditCtrl();
```

### <a name="return-value"></a>Valor retornado

Um ponteiro para a caixa de edição se o método foi bem sucedido; caso contrário, NULL.

### <a name="remarks"></a>Comentários

## <a name="cmfctoolbarcomboboxbuttongethwnd"></a><a name="gethwnd"></a>CMFCToolBarComboBoxButton::GetHwnd

Retorna a alça da janela para a caixa de combinação.

```
virtual HWND GetHwnd();
```

### <a name="return-value"></a>Valor retornado

A alça da janela ou NULL se a caixa de combinação não estiver associada a um objeto de janela.

## <a name="cmfctoolbarcomboboxbuttongetitem"></a><a name="getitem"></a>CMFCToolBarComboBoxButton::GetItem

Retorna a seqüência associada a um item em um índice especificado na caixa de lista.

```
LPCTSTR GetItem(int iIndex=-1) const;
```

### <a name="parameters"></a>Parâmetros

*Iindex*<br/>
[em] Índice baseado em zero de um item na caixa de lista.

### <a name="return-value"></a>Valor retornado

Um ponteiro para a seqüência que está associado ao item; caso contrário, NULL se o parâmetro de índice for inválido, ou se o parâmetro de índice for -1 e não houver nenhum item selecionado na caixa de combinação.

### <a name="remarks"></a>Comentários

Um parâmetro de índice de -1 retorna a seqüência do item atualmente selecionado.

## <a name="cmfctoolbarcomboboxbuttongetitemall"></a><a name="getitemall"></a>CMFCToolBarComboBoxButton::GetItemAll

Retorna a seqüência associada a um item em um índice especificado na caixa de lista de um botão de caixa de combinação que tem um ID de comando especificado.

```
static LPCTSTR GetItemAll(
    UINT uiCmd,
    int iIndex=-1);
```

### <a name="parameters"></a>Parâmetros

*Uicmd*<br/>
[em] O ID de comando de um botão de caixa combo.

*Iindex*<br/>
[em] O índice baseado em zero de um item na caixa de lista.

### <a name="return-value"></a>Valor retornado

Um ponteiro para a seqüência do item se o método foi bem sucedido; caso contrário, NULL se o índice for inválido, um botão de caixa de combinação não for encontrado ou se o índice for -1 e não houver nenhum item selecionado na caixa de combinação.

### <a name="remarks"></a>Comentários

Um valor de índice de -1 retorna a seqüência do item selecionado no momento.

## <a name="cmfctoolbarcomboboxbuttongetitemdata"></a><a name="getitemdata"></a>CMFCToolBarComboBoxButton::GetItemData

Retorna os dados associados a um item em um índice específico na caixa de lista.

```
DWORD_PTR GetItemData(int iIndex=-1) const;
```

### <a name="parameters"></a>Parâmetros

*Iindex*<br/>
[em] O índice baseado em zero de um item na caixa de lista.

### <a name="return-value"></a>Valor retornado

Os dados associados ao item; ou 0 se o item não existir.

### <a name="remarks"></a>Comentários

Um parâmetro de índice de -1 retorna os dados associados ao item selecionado no momento.

## <a name="cmfctoolbarcomboboxbuttongetitemdataall"></a><a name="getitemdataall"></a>CMFCToolBarComboBoxButton::GetItemDataAll

Retorna os dados associados a um item em um índice específico na caixa de lista de um botão de caixa de combinação que tem um ID de comando específico.

```
static DWORD_PTR GetItemDataAll(
    UINT uiCmd,
    int iIndex=-1);
```

### <a name="parameters"></a>Parâmetros

*Uicmd*<br/>
[em] O ID de comando de um botão de caixa combo.

*Iindex*<br/>
[em] O índice baseado em zero de um item na caixa de lista.

### <a name="return-value"></a>Valor retornado

Os dados associados ao item se o método foi bem sucedido; caso contrário, 0 se o índice especificado não for válido, ou CB_ERR se o botão de caixa de combinação não for encontrado.

### <a name="remarks"></a>Comentários

Um parâmetro de índice de -1 retorna os dados associados ao item selecionado no momento.

## <a name="cmfctoolbarcomboboxbuttongetitemdataptrall"></a><a name="getitemdataptrall"></a>CMFCToolBarComboBoxButton::GetItemDataPtrAll

Retorna os dados associados a um item em um índice específico na caixa de lista de um botão de caixa de combinação que tem um ID de comando específico. Esses dados são devolvidos como um ponteiro.

```
static void* GetItemDataPtrAll(
    UINT uiCmd,
    int iIndex=-1);
```

### <a name="parameters"></a>Parâmetros

*Uicmd*<br/>
[em] O ID de comando do botão da caixa de combinação.

*Iindex*<br/>
[em] O índice baseado em zero de um item na caixa de lista.

### <a name="return-value"></a>Valor retornado

Um ponteiro associado ao item se o método foi bem sucedido; caso contrário, -1 se ocorrer um erro ou NULO se o botão de caixa de combinação não for encontrado.

### <a name="remarks"></a>Comentários

## <a name="cmfctoolbarcomboboxbuttongetprompt"></a><a name="getprompt"></a>CMFCToolBarComboBoxButton::GetPrompt

Retorna a seqüência de entrada para o botão caixa de combinação.

```
virtual CString GetPrompt() const;
```

### <a name="return-value"></a>Valor retornado

A seqüência de alerta.

### <a name="remarks"></a>Comentários

Este método não é atualmente implementado.

## <a name="cmfctoolbarcomboboxbuttongettext"></a><a name="gettext"></a>CMFCToolBarComboBoxButton::GetText

Recebe o texto na caixa de edição.

```
LPCTSTR GetText() const;
```

### <a name="return-value"></a>Valor retornado

O texto na caixa de edição.

### <a name="remarks"></a>Comentários

## <a name="cmfctoolbarcomboboxbuttongettextall"></a><a name="gettextall"></a>CMFCToolBarComboBoxButton::GetTextAll

Obtém o texto na caixa de edição de um botão de caixa de combinação que tem um ID de comando especificado.

```
static LPCTSTR GetTextAll(UINT uiCmd);
```

### <a name="parameters"></a>Parâmetros

*Uicmd*<br/>
[em] O ID de comando de um botão de caixa de combinação específico.

### <a name="return-value"></a>Valor retornado

O texto na caixa de edição se o método foi bem sucedido; caso contrário, NULL.

### <a name="remarks"></a>Comentários

## <a name="cmfctoolbarcomboboxbuttonhasfocus"></a><a name="hasfocus"></a>CMFCToolBarComboBoxButton::HasFocus

Indica se a caixa de combinação atualmente tem o foco.

```
virtual BOOL HasFocus() const;
```

### <a name="return-value"></a>Valor retornado

TRUE se a caixa de combinação atualmente tiver o foco; caso contrário, FALSE.

### <a name="remarks"></a>Comentários

Este método também retorna TRUE se qualquer janela filho da caixa de combinação atualmente tiver o foco.

## <a name="cmfctoolbarcomboboxbuttoniscentervert"></a><a name="iscentervert"></a>CMFCToolBarComboBoxButton::IsCenterVert

Retorna a posição vertical dos botões da caixa de combinação no aplicativo.

```
static BOOL IsCenterVert();
```

### <a name="return-value"></a>Valor retornado

VERDADE se os botões estiverem centrados; FALSO se os botões estiverem alinhados na parte superior.

### <a name="remarks"></a>Comentários

## <a name="cmfctoolbarcomboboxbuttonisflatmode"></a><a name="isflatmode"></a>CMFCToolBarComboBoxButton::IsFlatMode

Retorna a aparência estilo plano dos botões da caixa de combinação no aplicativo.

```
static BOOL IsFlatMode();
```

### <a name="return-value"></a>Valor retornado

TRUE se os botões tiverem um estilo plano; caso contrário, FALSE.

### <a name="remarks"></a>Comentários

O estilo plano padrão para botões de caixa de combinação é FALSE.

## <a name="cmfctoolbarcomboboxbuttonisownerof"></a><a name="isownerof"></a>CMFCToolBarComboBoxButton::IsOwnerOf

Indica se a alça especificada está associada ao botão da caixa de combinação ou a um de seus filhos.

```
virtual BOOL IsOwnerOf(HWND hwnd);
```

### <a name="parameters"></a>Parâmetros

*Hwnd*<br/>
[em] Uma alça de janela.

### <a name="return-value"></a>Valor retornado

VERDADE se a alça estiver assoada com o botão da caixa de combinação, ou um de seus filhos; caso contrário, FALSE.

## <a name="cmfctoolbarcomboboxbuttonisribbonbutton"></a><a name="isribbonbutton"></a>CMFCToolBarComboBoxButton::IsRibbonButton

Indica se o botão da caixa de combinação reside em um painel de fita.

```
BOOL IsRibbonButton() const;
```

### <a name="return-value"></a>Valor retornado

Sempre FALSE.

### <a name="remarks"></a>Comentários

Por padrão, este método sempre retorna FALSE, o que significa que o botão de caixa de combinação nunca é exibido em um painel de fita.

## <a name="cmfctoolbarcomboboxbuttoniswindowvisible"></a><a name="iswindowvisible"></a>CMFCToolBarComboBoxButton::IsWindowVisible

Retorna o estado de visibilidade do botão de caixa de combinação.

```
virtual BOOL IsWindowVisible();
```

### <a name="return-value"></a>Valor retornado

O estado de visibilidade do botão da caixa de combinação.

## <a name="cmfctoolbarcomboboxbuttonnotifycommand"></a><a name="notifycommand"></a>CMFCToolBarComboBoxButton::NotificarComando

Indica se o botão de caixa de combinação processa a mensagem.

```
virtual BOOL NotifyCommand(int iNotifyCode);
```

### <a name="parameters"></a>Parâmetros

*iNotifyCode*<br/>
[em] A mensagem de notificação que está associada ao comando.

### <a name="return-value"></a>Valor retornado

Se o botão de caixa de combinação processa a mensagem.

## <a name="cmfctoolbarcomboboxbuttononaddtocustomizepage"></a><a name="onaddtocustomizepage"></a>CMFCToolBarComboBoxButton::OnAddToCustomPage

Chamado pela estrutura quando o botão é adicionado à caixa de diálogo **Personalizar.**

```
virtual void OnAddToCustomizePage();
```

## <a name="cmfctoolbarcomboboxbuttononcalculatesize"></a><a name="oncalculatesize"></a>CMFCToolBarComboBoxButton::OnCalculateSize

Chamado pela estrutura para calcular o tamanho do botão.

```
virtual SIZE OnCalculateSize(
    CDC* pDC,
    const CSize& sizeDefault,
    BOOL bHorz);
```

### <a name="parameters"></a>Parâmetros

*pDC*<br/>
[em] O contexto do dispositivo que exibe o botão da caixa de combinação.

*tamanhoPadrão*<br/>
[em] O tamanho padrão do botão da caixa de combinação.

*Bhorz*<br/>
[em] O estado das docas da barra de ferramentas dos pais. TRUE quando a barra de ferramentas estiver encaixada horizontalmente e FALSA quando a barra de ferramentas estiver encaixada verticalmente.

### <a name="return-value"></a>Valor retornado

Uma `SIZE` estrutura que contém as dimensões do botão de caixa combo, em pixels.

## <a name="cmfctoolbarcomboboxbuttononchangeparentwnd"></a><a name="onchangeparentwnd"></a>CMFCToolBarComboBoxButton::OnChangeParentWnd

Chamado pela estrutura quando o botão de caixa de combinação é inserido em uma nova barra de ferramentas.

```
virtual void OnChangeParentWnd(CWnd* pWndParent);
```

### <a name="parameters"></a>Parâmetros

*pWndParent*<br/>
[em] Ponteiro para a nova barra de ferramentas dos pais.

## <a name="cmfctoolbarcomboboxbuttononclick"></a><a name="onclick"></a>CMFCToolBarComboBoxButton::OnClick

Chamado pela estrutura quando o usuário clica no botão caixa de combinação.

```
virtual BOOL OnClick(
    CWnd* pWnd,
    BOOL bDelay = TRUE);
```

### <a name="parameters"></a>Parâmetros

*Pwnd*<br/>
[em] Ponteiro para a janela pai do botão da caixa de combinação.

*bAtraso*<br/>
[em] Reservado para uso em uma classe derivada.

### <a name="return-value"></a>Valor retornado

TRUE se o método lida com o evento; caso contrário, FALSE.

## <a name="cmfctoolbarcomboboxbuttononctlcolor"></a><a name="onctlcolor"></a>CMFCToolBarComboBoxButton::OnCtlColor

Chamado pela estrutura quando o usuário altera a cor da barra de ferramentas pai para definir a cor do botão da caixa de combinação.

```
virtual HBRUSH OnCtlColor(
    CDC* pDC,
    UINT nCtlColor);
```

### <a name="parameters"></a>Parâmetros

*pDC*<br/>
[em] O contexto do dispositivo que exibe o botão da caixa de combinação.

*nCtlColor*<br/>
[em] Utilizadas.

### <a name="return-value"></a>Valor retornado

Manuseie o pincel que a estrutura usa para pintar o fundo do botão da caixa de combinação.

### <a name="remarks"></a>Comentários

Este método também define a cor do texto do botão da caixa de combinação.

## <a name="cmfctoolbarcomboboxbuttonondraw"></a><a name="ondraw"></a>CMFCToolBarComboBoxButton::OnDraw

Chamado pela estrutura para desenhar o botão de caixa de combinação usando os estilos e opções especificados.

```
virtual void OnDraw(
    CDC* pDC,
    const CRect& rect,
    CMFCToolBarImages* pImages,
    BOOL bHorz = TRUE,
    BOOL bCustomizeMode = FALSE,
    BOOL bHighlight = FALSE,
    BOOL bDrawBorder = TRUE,
    BOOL bGrayDisabledButtons = TRUE);
```

### <a name="parameters"></a>Parâmetros

*Pdc*<br/>
[em] O contexto do dispositivo que exibe o botão.

*Rect*<br/>
[em] O retângulo delimitador do botão.

*pImagens*<br/>
[em] A coleção de imagens que está associada ao botão.

*Bhorz*<br/>
[em] O estado das docas da barra de ferramentas dos pais. TRUE quando a barra de ferramentas estiver encaixada horizontalmente e FALSA quando a barra de ferramentas estiver encaixada verticalmente.

*bPersonalizeMode*<br/>
[em] Se o aplicativo está no modo de personalização.

*bDestaque*<br/>
[em] Se para desenhar o botão de caixa de combinação destacado.

*bDrawBorder*<br/>
[em] Se para desenhar o botão de caixa de combinação com uma borda.

*bGrayDisabledButtons*<br/>
[em] TRUE para desenhar botões desativados sombreados; FALSO para usar a coleção de imagens desativadas.

## <a name="cmfctoolbarcomboboxbuttonondrawoncustomizelist"></a><a name="ondrawoncustomizelist"></a>CMFCToolBarComboBoxButton::OnDrawOnCustomizeList

Chamado pela estrutura para desenhar o botão de caixa de combinação no painel **Comandos** da caixa de diálogo **Personalizar.**

```
virtual int OnDrawOnCustomizeList(
    CDC* pDC,
    const CRect& rect,
    BOOL bSelected);
```

### <a name="parameters"></a>Parâmetros

*pDC*<br/>
[em] O contexto do dispositivo que exibe o botão da caixa de combinação.

*Rect*<br/>
[em] O retângulo delimitador do botão da caixa de combinação.

*bSelecionado*<br/>
[em] TRUE se o botão de caixa de combinação for selecionado; caso contrário, FALSE.

### <a name="return-value"></a>Valor retornado

A largura, em pixels, do botão de caixa combo.

## <a name="cmfctoolbarcomboboxbuttononglobalfontschanged"></a><a name="onglobalfontschanged"></a>CMFCToolBarComboBoxButton::OnGlobalFontsChanged

Chamado pelo framework para definir a fonte do botão da caixa de combinação quando a fonte do aplicativo for mudada.

```
virtual void OnGlobalFontsChanged();
```

## <a name="cmfctoolbarcomboboxbuttononmove"></a><a name="onmove"></a>CMFCToolBarComboBoxButton::OnMove

Chamado pela estrutura para alterar a localização do botão da caixa de combinação quando a barra de ferramentas pai se mover.

```
virtual void OnMove();
```

## <a name="cmfctoolbarcomboboxbuttononshow"></a><a name="onshow"></a>CMFCToolBarComboBoxButton::OnShow

Chamado pela estrutura quando o botão da caixa de combinação estiver oculto ou exibido.

```
virtual void OnShow(BOOL bShow);
```

### <a name="parameters"></a>Parâmetros

*Bshow*<br/>
[em] Seja para ocultar ou exibir o botão da caixa de combinação.

## <a name="cmfctoolbarcomboboxbuttononsize"></a><a name="onsize"></a>CMFCToolBarComboBoxButton::OnSize

Chamado pela estrutura para alterar o tamanho do botão da caixa de combinação quando a barra de ferramentas pai muda de tamanho.

```
virtual void OnSize(int iSize);
```

### <a name="parameters"></a>Parâmetros

*iSize*<br/>
[em] A nova largura do botão da caixa de combinação.

## <a name="cmfctoolbarcomboboxbuttononupdatetooltip"></a><a name="onupdatetooltip"></a>CMFCToolBarComboBoxButton::OnUpdateToolTip

Chamado pelo framework quando o usuário altera a ponta da ferramenta para o botão da caixa de combinação.

```
virtual BOOL OnUpdateToolTip(
    CWnd* pWndParent,
    int iButtonIndex,
    CToolTipCtrl& wndToolTip,
    CString& str);
```

### <a name="parameters"></a>Parâmetros

*pWndParent*<br/>
[em] Ponteiro para a janela pai para o botão da caixa de combinação.

*iButtonIndex*<br/>
[em] ID do botão da caixa de combinação.

*wndToolTip*<br/>
[em] A dica da ferramenta para associar com o botão da caixa de combinação.

*Str*<br/>
[em] O texto da dica da ferramenta.

### <a name="return-value"></a>Valor retornado

TRUE se o método lida com o evento; caso contrário, FALSE.

## <a name="cmfctoolbarcomboboxbuttonremoveallitems"></a><a name="removeallitems"></a>CMFCToolBarComboBoxButton::RemoveAllItems

Exclui todos os itens da lista e edita caixas.

```
void RemoveAllItems();
```

### <a name="remarks"></a>Comentários

Remove todos os itens da caixa de lista e edita o controle de uma caixa de combinação.

## <a name="cmfctoolbarcomboboxbuttonselectitem"></a><a name="selectitem"></a>CMFCToolBarComboBoxButton::SelectItem

Seleciona um item na caixa de lista.

```
BOOL SelectItem(
    int iIndex,
    BOOL bNotify=TRUE);

BOOL SelectItem(DWORD_PTR dwData);
BOOL SelectItem(LPCTSTR lpszText);
```

### <a name="parameters"></a>Parâmetros

*Iindex*<br/>
[em] O índice baseado em zero de um item na caixa de lista.

*bNotificar*<br/>
[em] TRUE para notificar o botão de caixa combo da seleção; caso contrário, FALSO.

*Dwdata*<br/>
[em] Os dados associados a um item na caixa de lista.

*lpszText*<br/>
[em] O texto de um item na caixa de lista.

### <a name="return-value"></a>Valor retornado

VERDADEIRO se o método foi bem sucedido; caso contrário, FALSO.

### <a name="remarks"></a>Comentários

## <a name="cmfctoolbarcomboboxbuttonselectitemall"></a><a name="selectitemall"></a>CMFCToolBarComboBoxButton::SelectItemAll

Seleciona um item na caixa de lista de um botão de caixa de combinação que tenha um ID de comando especificado.

```
static BOOL SelectItemAll(
    UINT uiCmd,
    int iIndex);

static BOOL SelectItemAll(
    UINT uiCmd,
    DWORD_PTR dwData);

static BOOL SelectItemAll(
    UINT uiCmd,
    LPCTSTR lpszText);
```

### <a name="parameters"></a>Parâmetros

*Uicmd*<br/>
[em] O ID de comando do botão de caixa de combinação que contém a caixa de lista.

*Iindex*<br/>
[em] O índice baseado em zero do item na caixa de lista. Um valor de -1 remove qualquer seleção atual na caixa de lista e limpa a caixa de edição.

*Dwdata*<br/>
[em] Os dados de um item na caixa de lista.

*lpszText*<br/>
[em] O texto de um item na caixa de lista.

### <a name="return-value"></a>Valor retornado

VERDADEIRO se o método foi bem sucedido; caso contrário, FALSO.

### <a name="remarks"></a>Comentários

## <a name="cmfctoolbarcomboboxbuttonserialize"></a><a name="serialize"></a>CMFCToolBarComboBoxButton::Serialize

Lê este objeto de um arquivo ou grava-o em um arquivo.

```
virtual void Serialize(CArchive& ar);
```

### <a name="parameters"></a>Parâmetros

*ar*<br/>
[dentro, fora] O `CArchive` objeto para serializar.

### <a name="remarks"></a>Comentários

As configurações `CArchive` no objeto determinam se esse método lê ou grava no arquivo.

## <a name="cmfctoolbarcomboboxbuttonsetaccdata"></a><a name="setaccdata"></a>CMFCToolBarComboBoxButton::SetACCData

Preenche o objeto `CAccessibilityData` especificado usando dados de acessibilidade do botão caixa de combinação.

```
virtual BOOL SetACCData(
    CWnd* pParent,
    CAccessibilityData& data);
```

### <a name="parameters"></a>Parâmetros

*pParent*<br/>
[em] A janela pai do botão da caixa de combinação.

*dados*<br/>
[fora] Um `CAccessibilityData` objeto que recebe os dados de acessibilidade do botão caixa de combinação.

### <a name="return-value"></a>Valor retornado

VERDADEIRO se o método foi bem sucedido; caso contrário, FALSO.

## <a name="cmfctoolbarcomboboxbuttonsetcentervert"></a><a name="setcentervert"></a>CMFCToolBarComboBoxButton::SetCenterVert

Define a posição vertical dos botões da caixa de combinação no aplicativo.

```
static void SetCenterVert(BOOL bCenterVert=TRUE);
```

### <a name="parameters"></a>Parâmetros

*bCenterVert*<br/>
[em] TRUE para centralizar o botão de caixa de combinação na barra de ferramentas; FALSE para alinhar o botão da caixa de combinação à parte superior da barra de ferramentas.

### <a name="remarks"></a>Comentários

Por padrão, os botões da caixa combo estão alinhados à parte superior.

## <a name="cmfctoolbarcomboboxbuttonsetcontextmenuid"></a><a name="setcontextmenuid"></a>CMFCToolBarComboBoxButton::SetContextMenuID

Define o ID de recurso do menu de atalho para o botão caixa de combinação.

```
void SetContextMenuID(UINT uiResID);
```

### <a name="parameters"></a>Parâmetros

*uiResID*<br/>
[em] O iD de recurso do menu de atalho.

## <a name="cmfctoolbarcomboboxbuttonsetdropdownheight"></a><a name="setdropdownheight"></a>CMFCToolBarComboBoxButton::SetDropDownHeight

Define a altura da caixa de lista quando ela é derrubada.

```
void SetDropDownHeight(int nHeight);
```

### <a name="parameters"></a>Parâmetros

*Nheight*<br/>
[em] A altura, em pixels, da caixa da lista.

### <a name="remarks"></a>Comentários

A altura padrão é de 150 pixels.

## <a name="cmfctoolbarcomboboxbuttonsetflatmode"></a><a name="setflatmode"></a>CMFCToolBarComboBoxButton::SetFlatMode

Define a aparência de estilo plano dos botões da caixa de combinação no aplicativo.

```
static void SetFlatMode(BOOL bFlat=TRUE);
```

### <a name="parameters"></a>Parâmetros

*bFlat*<br/>
[em] TRUE para uma aparência de estilo plano; caso contrário, FALSO.

### <a name="remarks"></a>Comentários

O estilo plano padrão para botões de caixa de combinação é FALSE.

## <a name="cmfctoolbarcomboboxbuttonsetstyle"></a><a name="setstyle"></a>CMFCToolBarComboBoxButton::SetStyle

Define o estilo especificado para o botão caixa de combinação e redesenha o controle se ele não estiver desativado.

```
virtual void SetStyle(UINT nStyle);
```

### <a name="parameters"></a>Parâmetros

*nStyle*<br/>
[em] Uma combinação bitwise (OR) de estilos de barra de ferramentas.

### <a name="remarks"></a>Comentários

Para obter uma lista de estilos de botão da barra de ferramentas, consulte [Estilos de controle da barra de ferramentas](../../mfc/reference/toolbar-control-styles.md)

## <a name="cmfctoolbarcomboboxbuttonsettext"></a><a name="settext"></a>CMFCToolBarComboBoxButton::SetText

Define o texto na caixa de edição do botão caixa de combinação.

```
void SetText(LPCTSTR lpszText);
```

### <a name="parameters"></a>Parâmetros

*lpszText*<br/>
[em] Pointer para uma seqüência que contém o texto para a caixa de edição.

## <a name="see-also"></a>Confira também

[Gráfico da hierarquia](../../mfc/hierarchy-chart.md)<br/>
[Classes](../../mfc/reference/mfc-classes.md)<br/>
[Classe CMFCToolBarButton](../../mfc/reference/cmfctoolbarbutton-class.md)<br/>
[Classe CComboBox](../../mfc/reference/ccombobox-class.md)<br/>
[CMFCToolBar::Substituir botão](../../mfc/reference/cmfctoolbar-class.md#replacebutton)<br/>
[Instruções passo a passo: colocando controles em barras de ferramentas](../../mfc/walkthrough-putting-controls-on-toolbars.md)
