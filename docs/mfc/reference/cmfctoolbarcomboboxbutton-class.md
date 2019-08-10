---
title: Classe CMFCToolBarComboBoxButton
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
ms.openlocfilehash: 639a5f98ff4780bd26388796039e85b812621b36
ms.sourcegitcommit: 46d24d6e70c03e05484923d9efc6ed5150e96a64
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/09/2019
ms.locfileid: "68915975"
---
# <a name="cmfctoolbarcomboboxbutton-class"></a>Classe CMFCToolBarComboBoxButton

Um botão da barra de ferramentas que contém um controle de caixa de combinação ( [classe CComboBox](../../mfc/reference/ccombobox-class.md)).

## <a name="syntax"></a>Sintaxe

```
class CMFCToolBarComboBoxButton : public CMFCToolBarButton
```

## <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores públicos

|Nome|Descrição|
|----------|-----------------|
|[CMFCToolBarComboBoxButton::CMFCToolBarComboBoxButton](#cmfctoolbarcomboboxbutton)|Constrói um `CMFCToolBarComboBoxButton`.|

### <a name="public-methods"></a>Métodos públicos

|Nome|Descrição|
|----------|-----------------|
|[CMFCToolBarComboBoxButton::AddItem](#additem)|Adiciona um item ao final da lista da caixa de combinação.|
|[CMFCToolBarComboBoxButton::AddSortedItem](#addsorteditem)|Adiciona um item à lista da caixa de combinação. A ordem dos itens na lista é especificada por `Compare`.|
|[CMFCToolBarComboBoxButton::Compare](#compare)|Compara dois itens. Chamado para classificar os itens `AddSortedItems` que o adiciona à lista da caixa de combinação.|
|[CMFCToolBarComboBoxButton::CreateEdit](#createedit)|Cria um novo controle de edição para o botão da caixa de combinação.|
|[CMFCToolBarComboBoxButton::DeleteItem](#deleteitem)|Exclui um item da lista da caixa de combinação.|
|[CMFCToolBarComboBoxButton::FindItem](#finditem)|Retorna o índice do item que contém uma cadeia de caracteres especificada.|
|[CMFCToolBarComboBoxButton::GetByCmd](#getbycmd)|Retorna um ponteiro para o botão da caixa de combinação com uma ID de comando especificada.|
|[CMFCToolBarComboBoxButton::GetComboBox](#getcombobox)|Retorna um ponteiro para o controle da caixa de combinação que é inserido no botão da caixa de combinação.|
|[CMFCToolBarComboBoxButton::GetCount](#getcount)|Retorna o número de itens na lista da caixa de combinação.|
|[CMFCToolBarComboBoxButton::GetCountAll](#getcountall)|Localiza o botão de caixa de combinação que tem uma ID de comando especificada. Retorna o número de itens na lista da caixa de combinação desse botão.|
|[CMFCToolBarComboBoxButton::GetCurSel](#getcursel)|Retorna o índice do item selecionado na lista da caixa de combinação.|
|[CMFCToolBarComboBoxButton::GetCurSelAll](#getcurselall)|Localiza o botão de caixa de combinação que tem uma ID de comando especificada e retorna o índice do item selecionado na lista da caixa de combinação desse botão.|
|[CMFCToolBarComboBoxButton::GetEditCtrl](#geteditctrl)|Retorna um ponteiro para o controle de edição que é inserido no botão da caixa de combinação.|
|[CMFCToolBarComboBoxButton::GetItem](#getitem)|Retorna a cadeia de caracteres associada a um índice especificado na lista da caixa de combinação.|
|[CMFCToolBarComboBoxButton::GetItemAll](#getitemall)|Localiza o botão de caixa de combinação que tem uma ID de comando especificada e retorna a cadeia de caracteres associada a um índice na lista da caixa de combinação desse botão.|
|[CMFCToolBarComboBoxButton::GetItemData](#getitemdata)|Retorna o valor de 32 bits que está associado a um índice especificado na lista da caixa de combinação.|
|[CMFCToolBarComboBoxButton::GetItemDataAll](#getitemdataall)|Localiza o botão de caixa de combinação que tem uma ID de comando especificada e retorna o valor de 32 bits que está associado a um índice na lista da caixa de combinação desse botão.|
|[CMFCToolBarComboBoxButton::GetItemDataPtrAll](#getitemdataptrall)|Localiza o botão de caixa de combinação que tem uma ID de comando especificada. Recupera o valor de 32 bits associado a um índice na lista da caixa de combinação desse botão e retorna o valor de 32 bits como um ponteiro.|
|[CMFCToolBarComboBoxButton::GetText](#gettext)|Retorna o texto do controle de edição da caixa de combinação.|
|[CMFCToolBarComboBoxButton::GetTextAll](#gettextall)|Localiza o botão de caixa de combinação que tem uma ID de comando especificada e retorna o texto do controle de edição desse botão.|
|[CMFCToolBarComboBoxButton::IsCenterVert](#iscentervert)|Determina se os botões da caixa de combinação no aplicativo estão centralizados ou alinhados com a parte superior da barra de ferramentas.|
|[CMFCToolBarComboBoxButton::IsFlatMode](#isflatmode)|Determina se os botões da caixa de combinação no aplicativo têm uma aparência plana.|
|[CMFCToolBarComboBoxButton::RemoveAllItems](#removeallitems)|Remove todos os itens da caixa de listagem e edita o controle da caixa de combinação.|
|[CMFCToolBarComboBoxButton::SelectItem](#selectitem)|Seleciona um item na caixa de combinação de acordo com seu índice, o valor de 32 bits ou a cadeia de caracteres e notifica o controle da caixa de combinação sobre a seleção.|
|[CMFCToolBarComboBoxButton::SelectItemAll](#selectitemall)|Localiza o botão de caixa de combinação que tem uma ID de comando especificada. Chama `SelectItem` para selecionar um item na caixa de combinação desse botão de acordo com sua cadeia de caracteres, índice ou valor de 32 bits.|
|[CMFCToolBarComboBoxButton::SetCenterVert](#setcentervert)|Especifica se os botões da caixa de combinação no aplicativo estão centralizados verticalmente ou alinhados com a parte superior da barra de ferramentas.|
|[CMFCToolBarComboBoxButton::SetDropDownHeight](#setdropdownheight)|Define a altura da caixa de listagem suspensa.|
|[CMFCToolBarComboBoxButton::SetFlatMode](#setflatmode)|Especifica se os botões da caixa de combinação no aplicativo têm uma aparência plana.|

## <a name="remarks"></a>Comentários

Para adicionar um botão de caixa de combinação a uma barra de ferramentas, siga estas etapas:

1. Reserve uma ID de recurso fictícia para o botão no recurso de barra de ferramentas pai.

2. Construa um `CMFCToolBarComboBoxButton` objeto.

3. No manipulador de mensagens que processa a mensagem AFX_WM_RESETTOOLBAR, substitua o botão fictício pelo novo botão de caixa de combinação usando [CMFCToolBar:: ReplaceButton](../../mfc/reference/cmfctoolbar-class.md#replacebutton).

Para obter mais informações, confira [Passo a passo: Colocando controles em barras de](../../mfc/walkthrough-putting-controls-on-toolbars.md)ferramentas. Para obter um exemplo de um botão da barra de ferramentas da caixa de combinação, consulte o projeto de exemplo VisualStudioDemo.

## <a name="example"></a>Exemplo

O exemplo a seguir demonstra como usar vários métodos na `CMFCToolBarComboBoxButton` classe. O exemplo mostra como habilitar as caixas editar e combinação, definir a posição vertical dos botões da caixa de combinação no aplicativo, definir a altura da caixa de listagem quando ela for desativada, definir a aparência do estilo plano dos botões da caixa de combinação no aplicativo e defina o texto na caixa de edição do botão da caixa de combinação. Este trecho de código faz parte do [exemplo de demonstração do Visual Studio](../../overview/visual-cpp-samples.md).

[!code-cpp[NVC_MFC_VisualStudioDemo#36](../../mfc/codesnippet/cpp/cmfctoolbarcomboboxbutton-class_1.cpp)]
[!code-cpp[NVC_MFC_VisualStudioDemo#37](../../mfc/codesnippet/cpp/cmfctoolbarcomboboxbutton-class_2.cpp)]

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

[CObject](../../mfc/reference/cobject-class.md)

[CMFCToolBarButton](../../mfc/reference/cmfctoolbarbutton-class.md)

[CMFCToolBarComboBoxButton](../../mfc/reference/cmfctoolbarcomboboxbutton-class.md)

## <a name="requirements"></a>Requisitos

**Cabeçalho:** afxtoolbarcomboboxbutton. h

##  <a name="additem"></a>  CMFCToolBarComboBoxButton::AddItem

Anexa um item exclusivo à caixa de listagem.

```
virtual INT_PTR AddItem(
    LPCTSTR lpszItem,
    DWORD_PTR dwData=0);
```

### <a name="parameters"></a>Parâmetros

*lpszItem*<br/>
no O texto do item a ser adicionado à caixa de listagem.

*dwData*<br/>
no Os dados associados ao item a ser adicionado à caixa de listagem.

### <a name="return-value"></a>Valor de retorno

O índice do último item na caixa de listagem.

### <a name="remarks"></a>Comentários

Não use esse método quando o estilo da caixa de listagem for classificado.

Se o texto do item já estiver na caixa de listagem, os novos dados serão armazenados com o item existente. A pesquisa do item diferencia maiúsculas de minúsculas.

##  <a name="addsorteditem"></a>  CMFCToolBarComboBoxButton::AddSortedItem

Adiciona um item à caixa de listagem na ordem que é definida pelo método [Compare](#compare) .

```
virtual INT_PTR AddSortedItem(
    LPCTSTR lpszItem,
    DWORD_PTR dwData=0);
```

### <a name="parameters"></a>Parâmetros

*lpszItem*<br/>
no O texto do item a ser adicionado à caixa de listagem.

*dwData*<br/>
no Os dados associados ao item a ser adicionado à caixa de listagem.

### <a name="return-value"></a>Valor de retorno

Índice do item que foi adicionado à caixa de listagem.

### <a name="remarks"></a>Comentários

Use esta função para adicionar itens à caixa de listagem em uma ordem específica.

##  <a name="canbestretched"></a>CMFCToolBarComboBoxButton::CanBeStretched

Indica se o tamanho do botão da caixa de combinação pode ser alterado.

```
virtual BOOL CanBeStretched() const;
```

### <a name="return-value"></a>Valor de retorno

Retorna TRUE.

##  <a name="cmfctoolbarcomboboxbutton"></a>CMFCToolBarComboBoxButton::CMFCToolBarComboBoxButton

Constrói um objeto [CMFCToolBarComboBoxButton](../../mfc/reference/cmfctoolbarcomboboxbutton-class.md) .

```
CMFCToolBarComboBoxButton(
    UINT uiID,
    int iImage,
    DWORD dwStyle=CBS_DROPDOWNLIST,
    int iWidth=0);
```

### <a name="parameters"></a>Parâmetros

*uiID*<br/>
no A ID de comando do novo botão.

*iImage*<br/>
no O índice de imagem da imagem associada ao novo botão.

*dwStyle*<br/>
no O estilo do botão novo.

*iWidth*<br/>
no A largura, em pixels, do botão novo.

### <a name="remarks"></a>Comentários

A largura padrão é de 150 pixels.

Para obter uma lista de estilos de botão da barra de ferramentas, consulte [estilos de controle](../../mfc/reference/toolbar-control-styles.md)

##  <a name="cleardata"></a>CMFCToolBarComboBoxButton::ClearData

Exclui dados definidos pelo usuário.

```
virtual void ClearData();
```

### <a name="remarks"></a>Comentários

Por padrão, esse método não faz nada. Substitua esse método em uma classe derivada se você quiser excluir qualquer dado definido pelo usuário.

##  <a name="compare"></a>CMFCToolBarComboBoxButton:: Compare

Compara duas cadeias de caracteres.

```
virtual int Compare(
    LPCTSTR lpszItem1,
    LPCTSTR lpszItem2);
```

### <a name="parameters"></a>Parâmetros

*lpszItem1*<br/>
no A primeira cadeia de caracteres a ser comparada.

*lpszItem2*<br/>
no A segunda cadeia de caracteres para comparar.

### <a name="return-value"></a>Valor de retorno

Um valor que indica a relação de lexicográfica que diferencia maiúsculas de minúsculas entre as cadeias de caracteres. A tabela a seguir lista os valores possíveis:

|Valor|Descrição|
|-----------|-----------------|
|\<0|A primeira cadeia de caracteres é menor do que a segunda.|
|0|A primeira cadeia de caracteres é igual à segunda.|
|>0|A primeira cadeia de caracteres é maior que a segunda.|

### <a name="remarks"></a>Comentários

Substitua esse método para alterar como os itens são classificados na caixa de listagem.

A comparação diferencia maiúsculas de minúsculas.

Esse método é chamado apenas do método [AddSortedItem](#addsorteditem) .

##  <a name="copyfrom"></a>CMFCToolBarComboBoxButton::CopyFrom

Copia o estado do especificado `CMFCToolBarComboBoxButton` para o objeto atual.

```
virtual void CopyFrom(const CMFCToolBarButton& src);
```

### <a name="parameters"></a>Parâmetros

*src*<br/>
no O objeto `CMFCToolBarComboBoxButton` de origem.

##  <a name="createcombo"></a>CMFCToolBarComboBoxButton:: CreateCombo

Cria uma nova caixa de combinação para o botão de caixa de combinação.

```
virtual CComboBox* CreateCombo(
    CWnd* pWndParent,
    const CRect& rect);
```

### <a name="parameters"></a>Parâmetros

*pWndParent*<br/>
no Um ponteiro para a janela pai do botão.

*rect*<br/>
no Retângulo delimitador da caixa de combinação.

### <a name="return-value"></a>Valor de retorno

Um ponteiro para a nova caixa de combinação se o método foi bem-sucedido; caso contrário, NULL.

##  <a name="createedit"></a>CMFCToolBarComboBoxButton:: CreateEdit

Cria uma nova caixa de edição para o botão da caixa de combinação.

```
virtual CMFCToolBarComboBoxEdit* CreateEdit(
    CWnd* pWndParent,
    const CRect& rect,
    DWORD dwEditStyle);
```

### <a name="parameters"></a>Parâmetros

*pWndParent*<br/>
no Um ponteiro para a janela pai do botão.

*rect*<br/>
no Retângulo delimitador da nova caixa de edição.

*dwEditStyle*<br/>
no Estilo de controle da nova caixa de edição.

### <a name="return-value"></a>Valor de retorno

Um ponteiro para a nova caixa de edição se o método foi bem-sucedido; caso contrário, NULL.

### <a name="remarks"></a>Comentários

A estrutura chama esse método quando ele cria uma nova caixa de edição para um botão de caixa de combinação. Substitua esse método para alterar a forma como o [CMFCToolBarComboBoxEdit](../../mfc/reference/cmfctoolbarcomboboxedit-class.md) é criado.

##  <a name="deleteitem"></a>  CMFCToolBarComboBoxButton::DeleteItem

Exclui um item especificado da caixa de listagem.

```
BOOL DeleteItem(int iIndex);
BOOL DeleteItem(DWORD_PTR dwData);
BOOL DeleteItem(LPCTSTR lpszText);
```

### <a name="parameters"></a>Parâmetros

*iIndex*<br/>
no O índice de base zero do item a ser excluído.

*dwData*<br/>
no Os dados associados ao item a ser excluído.

*lpszText*<br/>
no O texto do item a ser excluído. Se houver vários itens com o mesmo texto, o primeiro item será excluído.

### <a name="return-value"></a>Valor de retorno

TRUE se o item foi localizado e excluído com êxito; caso contrário, FALSE.

### <a name="remarks"></a>Comentários

##  <a name="duplicatedata"></a>CMFCToolBarComboBoxButton::D uplicateData

Duplica os dados definidos pelo usuário.

```
virtual void DuplicateData();
```

### <a name="remarks"></a>Comentários

Por padrão, esse método não faz nada. Substitua esse método em uma classe derivada se desejar copiar qualquer dado definido pelo usuário.

##  <a name="enablewindow"></a>CMFCToolBarComboBoxButton::EnableWindow

Habilita ou desabilita as caixas de edição e de combinação.

```
virtual void EnableWindow(BOOL bEnable = TRUE);
```

### <a name="parameters"></a>Parâmetros

*bEnable*<br/>
no TRUE para habilitar as caixas editar e de combinação; FALSE para desabilitar as caixas de edição e de combinação.

### <a name="remarks"></a>Comentários

Quando desabilitado, os controles não podem se tornar ativos e não podem aceitar a entrada do usuário.

##  <a name="exporttomenubutton"></a>CMFCToolBarComboBoxButton::ExportToMenuButton

Copia uma cadeia de caracteres da tabela de cadeia de caracteres do aplicativo para o menu especificado usando a ID de comando do botão de caixa de combinação.

```
virtual BOOL ExportToMenuButton(CMFCToolBarMenuButton& menuButton) const;
```

### <a name="parameters"></a>Parâmetros

*menuButton*<br/>
fora Referência a um botão de menu.

### <a name="return-value"></a>Valor de retorno

Sempre verdadeiro.

##  <a name="finditem"></a>CMFCToolBarComboBoxButton::FindItem

Retorna o índice do primeiro item na caixa de listagem que contém uma cadeia de caracteres especificada.

```
int FindItem(LPCTSTR lpszText) const;
```

### <a name="parameters"></a>Parâmetros

*lpszText*<br/>
no O texto a ser pesquisado na caixa de listagem.

### <a name="return-value"></a>Valor de retorno

O índice do item; ou CB_ERR se o item não for encontrado.

### <a name="remarks"></a>Comentários

##  <a name="getbycmd"></a>CMFCToolBarComboBoxButton::GetByCmd

Obtém um ponteiro para o botão da caixa de combinação que tem uma ID de comando especificada.

```
static CMFCToolBarComboBoxButton* GetByCmd(
    UINT uiCmd,
    BOOL bIsFocus=FALSE);
```

### <a name="parameters"></a>Parâmetros

*uiCmd*<br/>
no A ID de comando de um botão de caixa de combinação.

*bIsFocus*<br/>
no TRUE para pesquisar apenas botões focados; FALSE para pesquisar todos os botões.

### <a name="return-value"></a>Valor de retorno

Um ponteiro para um botão de caixa de combinação; ou NULL se o botão não for encontrado.

### <a name="remarks"></a>Comentários

##  <a name="getcombobox"></a>CMFCToolBarComboBoxButton:: getcombobox

Retorna um ponteiro para a caixa de combinação no botão da caixa de combinação.

```
CComboBox* GetComboBox() const;
```

### <a name="return-value"></a>Valor de retorno

Um ponteiro para o objeto da [classe CComboBox](../../mfc/reference/ccombobox-class.md) se o método foi bem-sucedido; caso contrário, NULL.

### <a name="remarks"></a>Comentários

##  <a name="getcontextmenuid"></a>  CMFCToolBarComboBoxButton::GetContextMenuID

Obtém a ID de recurso do menu de atalho para o botão da caixa de combinação.

```
UINT GetContextMenuID();
```

### <a name="return-value"></a>Valor de retorno

A ID de recurso do menu de atalho.

##  <a name="getcount"></a>CMFCToolBarComboBoxButton:: GetCount

Retorna o número de itens na caixa de listagem.

```
INT_PTR GetCount() const;
```

### <a name="return-value"></a>Valor de retorno

O número de itens na caixa de listagem.

### <a name="remarks"></a>Comentários

##  <a name="getcountall"></a>CMFCToolBarComboBoxButton::GetCountAll

Obtém o número de itens na caixa de listagem de um botão de caixa de combinação que tem uma ID de comando especificada.

```
static int GetCountAll(UINT uiCmd);
```

### <a name="parameters"></a>Parâmetros

*uiCmd*<br/>
no A ID de comando de um botão de caixa de combinação.

### <a name="return-value"></a>Valor de retorno

O número de itens na caixa de listagem; caso contrário, CB_ERR se o botão de caixa de combinação não for encontrado.

### <a name="remarks"></a>Comentários

##  <a name="getcursel"></a>  CMFCToolBarComboBoxButton::GetCurSel

Obtém o índice do item atualmente selecionado na caixa de listagem.

```
int GetCurSel() const;
```

### <a name="return-value"></a>Valor de retorno

O índice do item atualmente selecionado na caixa de listagem; ou CB_ERR se nenhum item for selecionado.

### <a name="remarks"></a>Comentários

O índice da caixa de listagem é baseado em zero.

##  <a name="getcurselall"></a>  CMFCToolBarComboBoxButton::GetCurSelAll

Retorna o índice do item atualmente selecionado na caixa de listagem de um botão de caixa de combinação que tem uma ID de comando especificada.

```
static int GetCurSelAll(UINT uiCmd);
```

### <a name="parameters"></a>Parâmetros

*uiCmd*<br/>
no A ID de comando de um botão de caixa de combinação.

### <a name="return-value"></a>Valor de retorno

O índice do item atualmente selecionado na caixa de listagem; caso contrário, CB_ERR se nenhum item for selecionado ou se um botão de caixa de combinação não for encontrado.

### <a name="remarks"></a>Comentários

O índice da caixa de listagem é baseado em zero.

##  <a name="geteditctrl"></a>  CMFCToolBarComboBoxButton::GetEditCtrl

Retorna um ponteiro para a caixa de edição no botão da caixa de combinação.

```
virtual CEdit* GetEditCtrl();
```

### <a name="return-value"></a>Valor de retorno

Um ponteiro para a caixa de edição se o método foi bem-sucedido; caso contrário, NULL.

### <a name="remarks"></a>Comentários

##  <a name="gethwnd"></a>  CMFCToolBarComboBoxButton::GetHwnd

Retorna o identificador da janela para a caixa de combinação.

```
virtual HWND GetHwnd();
```

### <a name="return-value"></a>Valor de retorno

O identificador de janela, ou nulo, se a caixa de combinação não estiver associada a um objeto de janela.

##  <a name="getitem"></a>CMFCToolBarComboBoxButton:: GetItem

Retorna a cadeia de caracteres associada a um item em um índice especificado na caixa de listagem.

```
LPCTSTR GetItem(int iIndex=-1) const;
```

### <a name="parameters"></a>Parâmetros

*iIndex*<br/>
no Índice de base zero de um item na caixa de listagem.

### <a name="return-value"></a>Valor de retorno

Um ponteiro para a cadeia de caracteres associada ao item; caso contrário, NULL se o parâmetro de índice for inválido ou se o parâmetro de índice for-1 e não houver nenhum item selecionado na caixa de combinação.

### <a name="remarks"></a>Comentários

Um parâmetro de índice de-1 retorna a cadeia de caracteres do item selecionado no momento.

##  <a name="getitemall"></a>  CMFCToolBarComboBoxButton::GetItemAll

Retorna a cadeia de caracteres associada a um item em um índice especificado na caixa de listagem de um botão de caixa de combinação que tem uma ID de comando especificada.

```
static LPCTSTR GetItemAll(
    UINT uiCmd,
    int iIndex=-1);
```

### <a name="parameters"></a>Parâmetros

*uiCmd*<br/>
no A ID de comando de um botão de caixa de combinação.

*iIndex*<br/>
no O índice de base zero de um item na caixa de listagem.

### <a name="return-value"></a>Valor de retorno

Um ponteiro para a cadeia de caracteres do item se o método foi bem-sucedido; caso contrário, NULL se o índice for inválido, um botão de caixa de combinação não for encontrado ou se o índice for-1 e não houver nenhum item selecionado na caixa de combinação.

### <a name="remarks"></a>Comentários

Um valor de índice de-1 retorna a cadeia de caracteres do item selecionado no momento.

##  <a name="getitemdata"></a>  CMFCToolBarComboBoxButton::GetItemData

Retorna os dados associados a um item em um índice específico na caixa de listagem.

```
DWORD_PTR GetItemData(int iIndex=-1) const;
```

### <a name="parameters"></a>Parâmetros

*iIndex*<br/>
no O índice de base zero de um item na caixa de listagem.

### <a name="return-value"></a>Valor de retorno

Os dados associados ao item; ou 0 se o item não existir.

### <a name="remarks"></a>Comentários

Um parâmetro de índice de-1 retorna os dados associados ao item atualmente selecionado.

##  <a name="getitemdataall"></a>  CMFCToolBarComboBoxButton::GetItemDataAll

Retorna os dados associados a um item em um índice específico na caixa de listagem de um botão de caixa de combinação que tem uma ID de comando específica.

```
static DWORD_PTR GetItemDataAll(
    UINT uiCmd,
    int iIndex=-1);
```

### <a name="parameters"></a>Parâmetros

*uiCmd*<br/>
no A ID de comando de um botão de caixa de combinação.

*iIndex*<br/>
no O índice de base zero de um item na caixa de listagem.

### <a name="return-value"></a>Valor de retorno

Os dados associados ao item se o método foi bem-sucedido; caso contrário, 0 se o índice especificado não for válido ou CB_ERR se o botão de caixa de combinação não for encontrado.

### <a name="remarks"></a>Comentários

Um parâmetro de índice de-1 retorna os dados associados ao item atualmente selecionado.

##  <a name="getitemdataptrall"></a>  CMFCToolBarComboBoxButton::GetItemDataPtrAll

Retorna os dados associados a um item em um índice específico na caixa de listagem de um botão de caixa de combinação que tem uma ID de comando específica. Esses dados são retornados como um ponteiro.

```
static void* GetItemDataPtrAll(
    UINT uiCmd,
    int iIndex=-1);
```

### <a name="parameters"></a>Parâmetros

*uiCmd*<br/>
no A ID de comando do botão de caixa de combinação.

*iIndex*<br/>
no O índice de base zero de um item na caixa de listagem.

### <a name="return-value"></a>Valor de retorno

Um ponteiro associado ao item se o método foi bem-sucedido; caso contrário,-1 se ocorrer um erro, ou NULL se o botão da caixa de combinação não for encontrado.

### <a name="remarks"></a>Comentários

##  <a name="getprompt"></a>CMFCToolBarComboBoxButton:: GetPrompt

Retorna a cadeia de caracteres do prompt para o botão da caixa de combinação.

```
virtual CString GetPrompt() const;
```

### <a name="return-value"></a>Valor de retorno

A cadeia de caracteres do prompt.

### <a name="remarks"></a>Comentários

Este método não está implementado no momento.

##  <a name="gettext"></a>  CMFCToolBarComboBoxButton::GetText

Obtém o texto na caixa de edição.

```
LPCTSTR GetText() const;
```

### <a name="return-value"></a>Valor de retorno

O texto na caixa de edição.

### <a name="remarks"></a>Comentários

##  <a name="gettextall"></a>  CMFCToolBarComboBoxButton::GetTextAll

Obtém o texto na caixa de edição de um botão de caixa de combinação que tem uma ID de comando especificada.

```
static LPCTSTR GetTextAll(UINT uiCmd);
```

### <a name="parameters"></a>Parâmetros

*uiCmd*<br/>
no A ID de comando de um botão de caixa de combinação específico.

### <a name="return-value"></a>Valor de retorno

O texto na caixa de edição se o método foi bem-sucedido; caso contrário, NULL.

### <a name="remarks"></a>Comentários

##  <a name="hasfocus"></a>CMFCToolBarComboBoxButton::HasFocus

Indica se a caixa de combinação tem o foco no momento.

```
virtual BOOL HasFocus() const;
```

### <a name="return-value"></a>Valor de retorno

TRUE se a caixa de combinação tiver o foco no momento; caso contrário, FALSE.

### <a name="remarks"></a>Comentários

Esse método também retornará TRUE se qualquer janela filho da caixa de combinação tiver o foco no momento.

##  <a name="iscentervert"></a>  CMFCToolBarComboBoxButton::IsCenterVert

Retorna a posição vertical dos botões da caixa de combinação no aplicativo.

```
static BOOL IsCenterVert();
```

### <a name="return-value"></a>Valor de retorno

TRUE se os botões estiverem centralizados; FALSE se os botões estiverem alinhados na parte superior.

### <a name="remarks"></a>Comentários

##  <a name="isflatmode"></a>  CMFCToolBarComboBoxButton::IsFlatMode

Retorna a aparência de estilo plano dos botões da caixa de combinação no aplicativo.

```
static BOOL IsFlatMode();
```

### <a name="return-value"></a>Valor de retorno

TRUE se os botões tiverem um estilo simples; caso contrário, FALSE.

### <a name="remarks"></a>Comentários

O estilo plano padrão para os botões da caixa de combinação é FALSE.

##  <a name="isownerof"></a>  CMFCToolBarComboBoxButton::IsOwnerOf

Indica se o identificador especificado está associado ao botão da caixa de combinação ou a um de seus filhos.

```
virtual BOOL IsOwnerOf(HWND hwnd);
```

### <a name="parameters"></a>Parâmetros

*hwnd*<br/>
no Um identificador de janela.

### <a name="return-value"></a>Valor de retorno

TRUE se o identificador for associada com o botão de caixa de combinação ou um de seus filhos; caso contrário, FALSE.

##  <a name="isribbonbutton"></a>CMFCToolBarComboBoxButton::IsRibbonButton

Indica se o botão da caixa de combinação reside em um painel da faixa de forma.

```
BOOL IsRibbonButton() const;
```

### <a name="return-value"></a>Valor de retorno

Sempre FALSE.

### <a name="remarks"></a>Comentários

Por padrão, esse método sempre retorna FALSE, o que significa que o botão de caixa de combinação nunca é exibido em um painel da faixa de meios.

##  <a name="iswindowvisible"></a>  CMFCToolBarComboBoxButton::IsWindowVisible

Retorna o estado de visibilidade do botão da caixa de combinação.

```
virtual BOOL IsWindowVisible();
```

### <a name="return-value"></a>Valor de retorno

O estado de visibilidade do botão da caixa de combinação.

##  <a name="notifycommand"></a>CMFCToolBarComboBoxButton::NotifyCommand

Indica se o botão de caixa de combinação processa a mensagem.

```
virtual BOOL NotifyCommand(int iNotifyCode);
```

### <a name="parameters"></a>Parâmetros

*iNotifyCode*<br/>
no A mensagem de notificação associada ao comando.

### <a name="return-value"></a>Valor de retorno

Se o botão da caixa de combinação processa a mensagem.

##  <a name="onaddtocustomizepage"></a>  CMFCToolBarComboBoxButton::OnAddToCustomizePage

Chamado pelo Framework quando o botão é adicionado à caixa de diálogo **Personalizar** .

```
virtual void OnAddToCustomizePage();
```

##  <a name="oncalculatesize"></a>CMFCToolBarComboBoxButton::OnCalculateSize

Chamado pelo Framework para calcular o tamanho do botão.

```
virtual SIZE OnCalculateSize(
    CDC* pDC,
    const CSize& sizeDefault,
    BOOL bHorz);
```

### <a name="parameters"></a>Parâmetros

*pDC*<br/>
no O contexto do dispositivo que exibe o botão da caixa de combinação.

*sizeDefault*<br/>
no O tamanho padrão do botão de caixa de combinação.

*bHorz*<br/>
no O estado de encaixe da barra de ferramentas pai. VERDADEIRO quando a barra de ferramentas é encaixada horizontalmente e falsa quando a barra de ferramentas é encaixada verticalmente.

### <a name="return-value"></a>Valor de retorno

Uma `SIZE` estrutura que contém as dimensões do botão da caixa de combinação, em pixels.

##  <a name="onchangeparentwnd"></a>  CMFCToolBarComboBoxButton::OnChangeParentWnd

Chamado pelo Framework quando o botão da caixa de combinação é inserido em uma nova barra de ferramentas.

```
virtual void OnChangeParentWnd(CWnd* pWndParent);
```

### <a name="parameters"></a>Parâmetros

*pWndParent*<br/>
no Ponteiro para a nova barra de ferramentas pai.

##  <a name="onclick"></a>CMFCToolBarComboBoxButton:: OnClick

Chamado pelo Framework quando o usuário clica no botão da caixa de combinação.

```
virtual BOOL OnClick(
    CWnd* pWnd,
    BOOL bDelay = TRUE);
```

### <a name="parameters"></a>Parâmetros

*pWnd*<br/>
no Ponteiro para a janela pai do botão de caixa de combinação.

*bDelay*<br/>
no Reservado para uso em uma classe derivada.

### <a name="return-value"></a>Valor de retorno

TRUE se o método tratar o evento; caso contrário, FALSE.

##  <a name="onctlcolor"></a>  CMFCToolBarComboBoxButton::OnCtlColor

Chamado pelo Framework quando o usuário altera a cor da barra de ferramentas pai para definir a cor do botão da caixa de combinação.

```
virtual HBRUSH OnCtlColor(
    CDC* pDC,
    UINT nCtlColor);
```

### <a name="parameters"></a>Parâmetros

*pDC*<br/>
no O contexto do dispositivo que exibe o botão da caixa de combinação.

*nCtlColor*<br/>
no Não utilizado.

### <a name="return-value"></a>Valor de retorno

Identificador para o pincel usado pela estrutura para pintar o plano de fundo do botão da caixa de combinação.

### <a name="remarks"></a>Comentários

Esse método também define a cor do texto do botão de caixa de combinação.

##  <a name="ondraw"></a>CMFCToolBarComboBoxButton:: OnDraw

Chamado pelo Framework para desenhar o botão de caixa de combinação usando os estilos e as opções especificadas.

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
no O contexto do dispositivo que exibe o botão.

*rect*<br/>
no O retângulo delimitador do botão.

*pImages*<br/>
no A coleção de imagens que está associada ao botão.

*bHorz*<br/>
no O estado de encaixe da barra de ferramentas pai. VERDADEIRO quando a barra de ferramentas é encaixada horizontalmente e falsa quando a barra de ferramentas é encaixada verticalmente.

*bCustomizeMode*<br/>
no Se o aplicativo está no modo de personalização.

*bHighlight*<br/>
no Se o botão de caixa de combinação deve ser desenhado realçado.

*bDrawBorder*<br/>
no Se o botão de caixa de combinação deve ser desenhado com uma borda.

*bGrayDisabledButtons*<br/>
no TRUE para desenhar botões desabilitados em sombreados; FALSE para usar a coleção de imagens desabilitadas.

##  <a name="ondrawoncustomizelist"></a>  CMFCToolBarComboBoxButton::OnDrawOnCustomizeList

Chamado pelo Framework para desenhar o botão da caixa de combinação no painel **comandos** da caixa de diálogo **Personalizar** .

```
virtual int OnDrawOnCustomizeList(
    CDC* pDC,
    const CRect& rect,
    BOOL bSelected);
```

### <a name="parameters"></a>Parâmetros

*pDC*<br/>
no O contexto do dispositivo que exibe o botão da caixa de combinação.

*rect*<br/>
no O retângulo delimitador do botão de caixa de combinação.

*bSelected*<br/>
no TRUE se o botão da caixa de combinação estiver selecionado; caso contrário, FALSE.

### <a name="return-value"></a>Valor de retorno

A largura, em pixels, do botão da caixa de combinação.

##  <a name="onglobalfontschanged"></a>  CMFCToolBarComboBoxButton::OnGlobalFontsChanged

Chamado pelo Framework para definir a fonte do botão de caixa de combinação quando a fonte do aplicativo é alterada.

```
virtual void OnGlobalFontsChanged();
```

##  <a name="onmove"></a>CMFCToolBarComboBoxButton:: OnMove

Chamado pelo Framework para alterar o local do botão da caixa de combinação quando a barra de ferramentas pai é movida.

```
virtual void OnMove();
```

##  <a name="onshow"></a>  CMFCToolBarComboBoxButton::OnShow

Chamado pelo Framework quando o botão da caixa de combinação é ocultado ou exibido.

```
virtual void OnShow(BOOL bShow);
```

### <a name="parameters"></a>Parâmetros

*bShow*<br/>
no Se deseja ocultar ou exibir o botão de caixa de combinação.

##  <a name="onsize"></a>  CMFCToolBarComboBoxButton::OnSize

Chamado pelo Framework para alterar o tamanho do botão da caixa de combinação quando a barra de ferramentas pai muda de tamanho.

```
virtual void OnSize(int iSize);
```

### <a name="parameters"></a>Parâmetros

*iSize*<br/>
no A nova largura do botão de caixa de combinação.

##  <a name="onupdatetooltip"></a>  CMFCToolBarComboBoxButton::OnUpdateToolTip

Chamado pelo Framework quando o usuário altera a dica de ferramenta para o botão de caixa de combinação.

```
virtual BOOL OnUpdateToolTip(
    CWnd* pWndParent,
    int iButtonIndex,
    CToolTipCtrl& wndToolTip,
    CString& str);
```

### <a name="parameters"></a>Parâmetros

*pWndParent*<br/>
no Ponteiro para a janela pai do botão de caixa de combinação.

*iButtonIndex*<br/>
no ID do botão da caixa de combinação.

*wndToolTip*<br/>
no A dica de ferramenta a ser associada ao botão da caixa de combinação.

*str*<br/>
no O texto da dica de ferramenta.

### <a name="return-value"></a>Valor de retorno

TRUE se o método tratar o evento; caso contrário, FALSE.

##  <a name="removeallitems"></a>  CMFCToolBarComboBoxButton::RemoveAllItems

Exclui todos os itens da lista e das caixas de edição.

```
void RemoveAllItems();
```

### <a name="remarks"></a>Comentários

Remove todos os itens da caixa de listagem e edita o controle de uma caixa de combinação.

##  <a name="selectitem"></a>CMFCToolBarComboBoxButton::SelectItem

Seleciona um item na caixa de listagem.

```
BOOL SelectItem(
    int iIndex,
    BOOL bNotify=TRUE);

BOOL SelectItem(DWORD_PTR dwData);
BOOL SelectItem(LPCTSTR lpszText);
```

### <a name="parameters"></a>Parâmetros

*iIndex*<br/>
no O índice de base zero de um item na caixa de listagem.

*bNotify*<br/>
no TRUE para notificar o botão da caixa de combinação da seleção; caso contrário, FALSE.

*dwData*<br/>
no Os dados associados a um item na caixa de listagem.

*lpszText*<br/>
no O texto de um item na caixa de listagem.

### <a name="return-value"></a>Valor de retorno

TRUE se o método foi bem-sucedido; caso contrário, FALSE.

### <a name="remarks"></a>Comentários

##  <a name="selectitemall"></a>CMFCToolBarComboBoxButton::SelectItemAll

Seleciona um item na caixa de listagem de um botão de caixa de combinação que tem uma ID de comando especificada.

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

*uiCmd*<br/>
no A ID de comando do botão da caixa de combinação que contém a caixa de listagem.

*iIndex*<br/>
no O índice de base zero do item na caixa de listagem. Um valor de-1 remove qualquer seleção atual na caixa de listagem e limpa a caixa de edição.

*dwData*<br/>
no Os dados de um item na caixa de listagem.

*lpszText*<br/>
no O texto de um item na caixa de listagem.

### <a name="return-value"></a>Valor de retorno

TRUE se o método foi bem-sucedido; caso contrário, FALSE.

### <a name="remarks"></a>Comentários

##  <a name="serialize"></a>CMFCToolBarComboBoxButton:: Serialize

Lê este objeto de um arquivo ou grava-o em um arquivo morto.

```
virtual void Serialize(CArchive& ar);
```

### <a name="parameters"></a>Parâmetros

*ar*<br/>
[entrada, saída] O `CArchive` objeto a ser serializado.

### <a name="remarks"></a>Comentários

As configurações no `CArchive` objeto determinam se esse método lê ou grava no arquivo morto.

##  <a name="setaccdata"></a>  CMFCToolBarComboBoxButton::SetACCData

Popula o objeto especificado `CAccessibilityData` usando dados de acessibilidade do botão de caixa de combinação.

```
virtual BOOL SetACCData(
    CWnd* pParent,
    CAccessibilityData& data);
```

### <a name="parameters"></a>Parâmetros

*pParent*<br/>
no A janela pai do botão de caixa de combinação.

*data*<br/>
fora Um `CAccessibilityData` objeto que recebe os dados de acessibilidade do botão de caixa de combinação.

### <a name="return-value"></a>Valor de retorno

TRUE se o método foi bem-sucedido; caso contrário, FALSE.

##  <a name="setcentervert"></a>  CMFCToolBarComboBoxButton::SetCenterVert

Define a posição vertical dos botões da caixa de combinação no aplicativo.

```
static void SetCenterVert(BOOL bCenterVert=TRUE);
```

### <a name="parameters"></a>Parâmetros

*bCenterVert*<br/>
no TRUE para centralizar o botão de caixa de combinação na barra de ferramentas; FALSE para alinhar o botão da caixa de combinação à parte superior da barra de ferramentas.

### <a name="remarks"></a>Comentários

Por padrão, os botões da caixa de combinação são alinhados à parte superior.

##  <a name="setcontextmenuid"></a>  CMFCToolBarComboBoxButton::SetContextMenuID

Define a ID de recurso do menu de atalho para o botão da caixa de combinação.

```
void SetContextMenuID(UINT uiResID);
```

### <a name="parameters"></a>Parâmetros

*uiResID*<br/>
no A ID de recurso do menu de atalho.

##  <a name="setdropdownheight"></a>  CMFCToolBarComboBoxButton::SetDropDownHeight

Define a altura da caixa de listagem quando ela é descartada.

```
void SetDropDownHeight(int nHeight);
```

### <a name="parameters"></a>Parâmetros

*nHeight*<br/>
no A altura, em pixels, da caixa de listagem.

### <a name="remarks"></a>Comentários

A altura padrão é de 150 pixels.

##  <a name="setflatmode"></a>  CMFCToolBarComboBoxButton::SetFlatMode

Define a aparência de estilo plano dos botões da caixa de combinação no aplicativo.

```
static void SetFlatMode(BOOL bFlat=TRUE);
```

### <a name="parameters"></a>Parâmetros

*bFlat*<br/>
no VERDADEIRO para uma aparência de estilo simples; caso contrário, FALSE.

### <a name="remarks"></a>Comentários

O estilo plano padrão para os botões da caixa de combinação é FALSE.

##  <a name="setstyle"></a>CMFCToolBarComboBoxButton:: SetStyle

Define o estilo especificado para o botão da caixa de combinação e redesenha o controle se ele não estiver desabilitado.

```
virtual void SetStyle(UINT nStyle);
```

### <a name="parameters"></a>Parâmetros

*nStyle*<br/>
no Uma combinação de bits de bit (ou) de estilos de barra de ferramentas.

### <a name="remarks"></a>Comentários

Para obter uma lista de estilos de botão da barra de ferramentas, consulte [estilos de controle](../../mfc/reference/toolbar-control-styles.md)

##  <a name="settext"></a>CMFCToolBarComboBoxButton:: SetText

Define o texto na caixa de edição do botão da caixa de combinação.

```
void SetText(LPCTSTR lpszText);
```

### <a name="parameters"></a>Parâmetros

*lpszText*<br/>
no Ponteiro para uma cadeia de caracteres que contém o texto da caixa de edição.

## <a name="see-also"></a>Consulte também

[Gráfico da hierarquia](../../mfc/hierarchy-chart.md)<br/>
[Classes](../../mfc/reference/mfc-classes.md)<br/>
[Classe CMFCToolBarButton](../../mfc/reference/cmfctoolbarbutton-class.md)<br/>
[Classe CComboBox](../../mfc/reference/ccombobox-class.md)<br/>
[CMFCToolBar::ReplaceButton](../../mfc/reference/cmfctoolbar-class.md#replacebutton)<br/>
[Passo a passo: colocar controles em barras de ferramentas](../../mfc/walkthrough-putting-controls-on-toolbars.md)
