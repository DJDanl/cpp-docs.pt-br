---
title: Classe CMFCRibbonComboBox
ms.date: 11/04/2016
f1_keywords:
- CMFCRibbonComboBox
- AFXRIBBONCOMBOBOX/CMFCRibbonComboBox
- AFXRIBBONCOMBOBOX/CMFCRibbonComboBox::CMFCRibbonComboBox
- AFXRIBBONCOMBOBOX/CMFCRibbonComboBox::AddItem
- AFXRIBBONCOMBOBOX/CMFCRibbonComboBox::DeleteItem
- AFXRIBBONCOMBOBOX/CMFCRibbonComboBox::EnableDropDownListResize
- AFXRIBBONCOMBOBOX/CMFCRibbonComboBox::FindItem
- AFXRIBBONCOMBOBOX/CMFCRibbonComboBox::GetCount
- AFXRIBBONCOMBOBOX/CMFCRibbonComboBox::GetCurSel
- AFXRIBBONCOMBOBOX/CMFCRibbonComboBox::GetDropDownHeight
- AFXRIBBONCOMBOBOX/CMFCRibbonComboBox::GetIntermediateSize
- AFXRIBBONCOMBOBOX/CMFCRibbonComboBox::GetItem
- AFXRIBBONCOMBOBOX/CMFCRibbonComboBox::GetItemData
- AFXRIBBONCOMBOBOX/CMFCRibbonComboBox::HasEditBox
- AFXRIBBONCOMBOBOX/CMFCRibbonComboBox::IsResizeDropDownList
- AFXRIBBONCOMBOBOX/CMFCRibbonComboBox::OnSelectItem
- AFXRIBBONCOMBOBOX/CMFCRibbonComboBox::RemoveAllItems
- AFXRIBBONCOMBOBOX/CMFCRibbonComboBox::SelectItem
- AFXRIBBONCOMBOBOX/CMFCRibbonComboBox::SetDropDownHeight
helpviewer_keywords:
- CMFCRibbonComboBox [MFC], CMFCRibbonComboBox
- CMFCRibbonComboBox [MFC], AddItem
- CMFCRibbonComboBox [MFC], DeleteItem
- CMFCRibbonComboBox [MFC], EnableDropDownListResize
- CMFCRibbonComboBox [MFC], FindItem
- CMFCRibbonComboBox [MFC], GetCount
- CMFCRibbonComboBox [MFC], GetCurSel
- CMFCRibbonComboBox [MFC], GetDropDownHeight
- CMFCRibbonComboBox [MFC], GetIntermediateSize
- CMFCRibbonComboBox [MFC], GetItem
- CMFCRibbonComboBox [MFC], GetItemData
- CMFCRibbonComboBox [MFC], HasEditBox
- CMFCRibbonComboBox [MFC], IsResizeDropDownList
- CMFCRibbonComboBox [MFC], OnSelectItem
- CMFCRibbonComboBox [MFC], RemoveAllItems
- CMFCRibbonComboBox [MFC], SelectItem
- CMFCRibbonComboBox [MFC], SetDropDownHeight
ms.assetid: 9b29a6a4-cf17-4152-9b13-0bf90784b30d
ms.openlocfilehash: 5846b1c5590a756f0a0820583af3d0b159968ea2
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81375233"
---
# <a name="cmfcribboncombobox-class"></a>Classe CMFCRibbonComboBox

A `CMFCRibbonComboBox` classe implementa um controle de caixa combo que você pode adicionar a uma barra de fita, um painel de fita ou um menu popup de fita.

## <a name="syntax"></a>Sintaxe

```cpp
class CMFCRibbonComboBox : public CMFCRibbonEdit
```

## <a name="members"></a>Membros

### <a name="constructors"></a>Construtores

|Nome|Descrição|
|----------|-----------------|
|[CMFCRibbonComboBox::CMFCRibbonComboBox](#cmfcribboncombobox)|Constrói um objeto CMFCRibbonComboBox.|

### <a name="public-methods"></a>Métodos públicos

|Nome|Descrição|
|----------|-----------------|
|[CMFCRibbonComboBox::AddItem](#additem)|Anexa um item exclusivo à caixa de lista.|
|[CMFCRibbonComboBox::Deleteitem](#deleteitem)|Exclui um item especificado da caixa de lista.|
|[CMFCRibbonComboBox::AtivarDropDownListRedimension](#enabledropdownlistresize)|Especifica se a caixa de lista pode alterar o tamanho quando ela cai.|
|[CMFCRibbonComboBox::FindItem](#finditem)|Retorna o índice do primeiro item na caixa de lista que corresponde a uma seqüência especificada.|
|[CMFCRibbonComboBox::GetCount](#getcount)|Retorna o número de itens na caixa de lista.|
|[CMFCRibbonComboBox::GetCurSel](#getcursel)|Obtém o índice do item selecionado no momento na caixa de lista.|
|[CMFCRibbonComboBox::GetDropDownHeight](#getdropdownheight)|Obtém a altura da caixa de lista quando a caixa de lista é derrubada.|
|[CMFCRibbonComboBox::GetIntermediateSize](#getintermediatesize)|Retorna o tamanho da caixa de combinação como exibido no modo intermediário.|
|[CMFCRibbonComboBox::GetItem](#getitem)|Retorna a seqüência associada a um item em um índice especificado na caixa de lista.|
|[CMFCRibbonComboBox::GetItemData](#getitemdata)|Retorna os dados associados a um item em um índice especificado na caixa de lista.|
|[CMFCRibbonComboBox::HasEditBox](#haseditbox)|Indica se o controle contém uma caixa de edição.|
|[CMFCRibbonComboBox::IsResizeDropDownList](#isresizedropdownlist)|Indica se a caixa de lista pode ou não ser redimensionada.|
|[CMFCRibbonComboBox::OnSelectItem](#onselectitem)|Chamado pela estrutura quando o usuário seleciona um item na caixa de lista.|
|[CMFCRibbonComboBox::RemoveAllItems](#removeallitems)|Exclui todos os itens da caixa de lista e limpa a caixa de edição.|
|[CMFCRibbonComboBox::SelectItem](#selectitem)|Seleciona um item na caixa de lista.|
|[CMFCRibbonComboBox::SetDropDownHeight](#setdropdownheight)|Define a altura da caixa de lista quando ela é derrubada.|

## <a name="remarks"></a>Comentários

A caixa de combinação de fita consiste em uma caixa de lista combinada com uma etiqueta estática ou etiqueta que pode ser editada pelo usuário. Você deve especificar qual tipo deseja quando criar sua caixa de combinação de fita.

## <a name="example"></a>Exemplo

O exemplo a seguir demonstra como `CMFCRibbonComboBox` construir um objeto da classe, adicionar um item à caixa de combinação, selecionar um item na caixa de combinação e adicionar uma caixa de combinação a um painel.

[!code-cpp[NVC_MFC_RibbonApp#11](../../mfc/reference/codesnippet/cpp/cmfcribboncombobox-class_1.cpp)]

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

[Cobject](../../mfc/reference/cobject-class.md)

[Cmfcribbonbaseelement](../../mfc/reference/cmfcribbonbaseelement-class.md)

[Cmfcribbonbutton](../../mfc/reference/cmfcribbonbutton-class.md)

[CMFCRibbonEdit](../../mfc/reference/cmfcribbonedit-class.md)

[Cmfcribboncombobox](../../mfc/reference/cmfcribboncombobox-class.md)

## <a name="requirements"></a>Requisitos

**Cabeçalho:** afxribboncombobox.h

## <a name="cmfcribboncomboboxadditem"></a><a name="additem"></a>CMFCRibbonComboBox::AddItem

Anexa um item exclusivo à caixa de lista.

```cpp
virtual INT_PTR AddItem(
    LPCTSTR lpszItem,
    DWORD_PTR dwData=0);
```

### <a name="parameters"></a>Parâmetros

*Lpszitem*<br/>
[em] A seqüência do item a ser adicionado.

*Dwdata*<br/>
[em] Os dados associados ao item a serem adicionados.

### <a name="return-value"></a>Valor retornado

O índice baseado em zero do item anexado.

## <a name="cmfcribboncomboboxcmfcribboncombobox"></a><a name="cmfcribboncombobox"></a>CMFCRibbonComboBox::CMFCRibbonComboBox

Constrói um objeto `CMFCRibbonComboBox`.

```cpp
public:
CMFCRibbonComboBox(
    UINT nID,
    BOOL bHasEditBox=TRUE,
    Int nWidth=-1,
    LPCTSTR lpszLabel=NULL,
    Int nImage=-1);

protected:
CMFCRibbonComboBox();
```

### <a name="parameters"></a>Parâmetros

*nID*<br/>
[em] A id da caixa de combinação.

*bHasEditBox*<br/>
[em] TRUE se você quiser uma caixa de edição dentro do controle; FALSO de outra forma.

*Nwidth*<br/>
[em] Largura da caixa de combinação em pixels; ou -1 para a largura padrão.

*lpszLabel*<br/>
[em] O rótulo de exibição da caixa de combinação.

*Nimage*<br/>
[em] O pequeno índice de imagem da caixa de combinação.

### <a name="remarks"></a>Comentários

A largura padrão é de 108 pixels.

## <a name="cmfcribboncomboboxdeleteitem"></a><a name="deleteitem"></a>CMFCRibbonComboBox::Deleteitem

Exclui um item especificado da caixa de lista.

```cpp
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
[em] A seqüência do item a ser excluído. Se houver vários itens com a mesma string, o primeiro item será excluído.

### <a name="return-value"></a>Valor retornado

TRUE se o item especificado tiver sido excluído; caso contrário, FALSE.

### <a name="remarks"></a>Comentários

## <a name="cmfcribboncomboboxenabledropdownlistresize"></a><a name="enabledropdownlistresize"></a>CMFCRibbonComboBox::AtivarDropDownListRedimension

Especifica se a caixa de lista pode alterar o tamanho quando ela cai.

```cpp
void EnableDropDownListResize(BOOL bEnable=FALSE);
```

### <a name="parameters"></a>Parâmetros

*Benable*<br/>
[em] TRUE para permitir o redimensionamento; FALSO para desativar o redimensionamento.

### <a name="remarks"></a>Comentários

Quando o redimensionamento estiver ativado, a caixa de lista mudará de tamanho para se adequar aos itens exibidos.

## <a name="cmfcribboncomboboxfinditem"></a><a name="finditem"></a>CMFCRibbonComboBox::FindItem

Retorna o índice do primeiro item na caixa de lista que corresponde a uma seqüência especificada.

```cpp
int FindItem(LPCTSTR lpszText) const;
```

### <a name="parameters"></a>Parâmetros

*lpszText*<br/>
[em] A seqüência de um item na caixa de lista.

### <a name="return-value"></a>Valor retornado

O índice baseado em zero do item; ou -1 se o item não for encontrado.

### <a name="remarks"></a>Comentários

## <a name="cmfcribboncomboboxgetcount"></a><a name="getcount"></a>CMFCRibbonComboBox::GetCount

Retorna o número de itens na caixa de lista.

```cpp
INT_PTR GetCount() const;
```

### <a name="return-value"></a>Valor retornado

O número de itens na caixa de lista, ou 0 se a caixa de lista não contiver itens.

### <a name="remarks"></a>Comentários

## <a name="cmfcribboncomboboxgetcursel"></a><a name="getcursel"></a>CMFCRibbonComboBox::GetCurSel

Obtém o índice do item selecionado no momento na caixa de lista.

```cpp
int GetCurSel() const;
```

### <a name="return-value"></a>Valor retornado

O índice baseado em zero do item selecionado no momento na caixa de lista; ou -1 se nenhum item for selecionado.

## <a name="cmfcribboncomboboxgetdropdownheight"></a><a name="getdropdownheight"></a>CMFCRibbonComboBox::GetDropDownHeight

Obtém a altura da caixa de lista quando a caixa de lista é derrubada.

```cpp
int GetDropDownHeight();
```

### <a name="return-value"></a>Valor retornado

A altura, em pixels, da caixa da lista.

### <a name="remarks"></a>Comentários

## <a name="cmfcribboncomboboxgetintermediatesize"></a><a name="getintermediatesize"></a>CMFCRibbonComboBox::GetIntermediateSize

Retorna o tamanho da caixa de combinação como exibido no modo intermediário.

```cpp
virtual CSize GetIntermediateSize(CDC* pDC);
```

### <a name="parameters"></a>Parâmetros

*pDC*<br/>
[em] Ponteiro para um contexto de dispositivo para a caixa de combinação.

### <a name="return-value"></a>Valor retornado

O tamanho da caixa de combinação.

### <a name="remarks"></a>Comentários

O tamanho retornado é baseado no tamanho da caixa de combinação quando exibe imagens pequenas.

## <a name="cmfcribboncomboboxgetitem"></a><a name="getitem"></a>CMFCRibbonComboBox::GetItem

Retorna a seqüência associada a um item em um índice especificado na caixa de lista.

```cpp
LPCTSTR GetItem(int iIndex) const;
```

### <a name="parameters"></a>Parâmetros

*Iindex*<br/>
[em] O índice baseado em zero de um item na caixa de lista.

### <a name="return-value"></a>Valor retornado

Um ponteiro para a seqüência que está associado ao item; caso contrário, NULL se o parâmetro de índice for inválido, ou se o parâmetro de índice for -1 e não houver nenhum item selecionado na caixa de combinação.

### <a name="remarks"></a>Comentários

## <a name="cmfcribboncomboboxgetitemdata"></a><a name="getitemdata"></a>CMFCRibbonComboBox::GetItemData

Retorna os dados associados a um item em um índice especificado na caixa de lista.

```cpp
DWORD_PTR GetItemData(int iIndex) const;
```

### <a name="parameters"></a>Parâmetros

*Iindex*<br/>
[em] O índice baseado em zero de um item na caixa de lista.

### <a name="return-value"></a>Valor retornado

Os dados associados ao item; ou 0 se o item não existir, ou se o parâmetro de índice for -1 e não houver nenhum item selecionado na caixa de lista.

## <a name="cmfcribboncomboboxhaseditbox"></a><a name="haseditbox"></a>CMFCRibbonComboBox::HasEditBox

Indica se o controle contém uma caixa de edição.

```cpp
BOOL HasEditBox() const;
```

### <a name="return-value"></a>Valor retornado

TRUE se o controle contiver uma caixa de edição; caso contrário, FALSE.

### <a name="remarks"></a>Comentários

## <a name="cmfcribboncomboboxisresizedropdownlist"></a><a name="isresizedropdownlist"></a>CMFCRibbonComboBox::IsResizeDropDownList

Indica se a caixa de lista pode ou não ser redimensionada.

```cpp
BOOL IsResizeDropDownList() const;
```

### <a name="return-value"></a>Valor retornado

TRUE se a caixa de lista puder ser redimensionada; caso contrário, FALSO. [CMFCRibbonComboBox::AtivarDropDownListRedimension](#enabledropdownlistresize)

### <a name="remarks"></a>Comentários

Você pode ativar o redimensionamento da caixa de lista usando o [método CMFCRibbonComboBox::EnableDropDownListResize](#enabledropdownlistresize) method.

## <a name="cmfcribboncomboboxonselectitem"></a><a name="onselectitem"></a>CMFCRibbonComboBox::OnSelectItem

Chamado pela estrutura quando um usuário seleciona um item na caixa de lista.

```cpp
virtual void OnSelectItem(int nItem);
```

### <a name="parameters"></a>Parâmetros

*Nitem*<br/>
[em] O índice do item selecionado.

### <a name="remarks"></a>Comentários

Anular este método se você quiser processar uma seleção de entrada do usuário.

## <a name="cmfcribboncomboboxremoveallitems"></a><a name="removeallitems"></a>CMFCRibbonComboBox::RemoveAllItems

Exclui todos os itens da caixa de lista e limpa a caixa de edição.

```cpp
void RemoveAllItems();
```

### <a name="remarks"></a>Comentários

## <a name="cmfcribboncomboboxselectitem"></a><a name="selectitem"></a>CMFCRibbonComboBox::SelectItem

Seleciona um item na caixa de lista.

```cpp
BOOL SelectItem(int iIndex);
BOOL SelectItem(DWORD_PTR dwData);

BOOL SelectItem(LPCTSTR lpszText);
```

### <a name="parameters"></a>Parâmetros

*Iindex*<br/>
[em] O índice baseado em zero de um item na caixa de lista.

*Dwdata*<br/>
[em] Os dados associados a um item na caixa de lista.

*lpszText*<br/>
[em] A seqüência de um item na caixa de lista.

### <a name="return-value"></a>Valor retornado

VERDADEIRO se o método foi bem sucedido; caso contrário, FALSO.

### <a name="remarks"></a>Comentários

## <a name="cmfcribboncomboboxsetdropdownheight"></a><a name="setdropdownheight"></a>CMFCRibbonComboBox::SetDropDownHeight

Define a altura da caixa de lista quando ela é derrubada.

```cpp
void SetDropDownHeight(int nHeight);
```

### <a name="parameters"></a>Parâmetros

*Nheight*<br/>
[em] A altura, em pixels, da caixa da lista.

### <a name="remarks"></a>Comentários

A altura padrão é de 150 pixels.

## <a name="see-also"></a>Confira também

[Gráfico da hierarquia](../../mfc/hierarchy-chart.md)<br/>
[Classes](../../mfc/reference/mfc-classes.md)<br/>
[Classe CMFCRibbonEdit](../../mfc/reference/cmfcribbonedit-class.md)
