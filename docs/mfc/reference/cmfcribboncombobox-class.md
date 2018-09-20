---
title: Classe CMFCRibbonComboBox | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-mfc
ms.topic: reference
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
dev_langs:
- C++
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
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 2681d5f54211ac2097dcae410ba69743af4b4690
ms.sourcegitcommit: 799f9b976623a375203ad8b2ad5147bd6a2212f0
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/19/2018
ms.locfileid: "46446140"
---
# <a name="cmfcribboncombobox-class"></a>Classe CMFCRibbonComboBox

O `CMFCRibbonComboBox` classe implementa um controle de caixa de combinação que você pode adicionar uma barra de faixa de opções, um painel de faixa de opções ou um menu pop-up de faixa de opções.

## <a name="syntax"></a>Sintaxe

```
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
|[CMFCRibbonComboBox::AddItem](#additem)|Acrescenta um item exclusivo para a caixa de listagem.|
|[CMFCRibbonComboBox::DeleteItem](#deleteitem)|Exclui um item especificado na caixa de listagem.|
|[CMFCRibbonComboBox::EnableDropDownListResize](#enabledropdownlistresize)|Especifica se a caixa de listagem pode alterar o tamanho quando ela cai para baixo.|
|[CMFCRibbonComboBox::FindItem](#finditem)|Retorna o índice do primeiro item na caixa de listagem que corresponde a uma cadeia de caracteres especificada.|
|[CMFCRibbonComboBox::GetCount](#getcount)|Retorna o número de itens na caixa de listagem.|
|[CMFCRibbonComboBox::GetCurSel](#getcursel)|Obtém o índice do item atualmente selecionado na caixa de listagem.|
|[CMFCRibbonComboBox::GetDropDownHeight](#getdropdownheight)|Obtém a altura da caixa de listagem, quando a caixa de listagem é descartada para baixo.|
|[CMFCRibbonComboBox::GetIntermediateSize](#getintermediatesize)|Retorna o tamanho da caixa de combinação, conforme exibido no modo de intermediário.|
|[CMFCRibbonComboBox::GetItem](#getitem)|Retorna a cadeia de caracteres associada a um item em um índice especificado na caixa de listagem.|
|[CMFCRibbonComboBox::GetItemData](#getitemdata)|Retorna os dados associados a um item em um índice especificado na caixa de listagem.|
|[CMFCRibbonComboBox::HasEditBox](#haseditbox)|Indica se o controle contém uma caixa de edição.|
|[CMFCRibbonComboBox::IsResizeDropDownList](#isresizedropdownlist)|Indica se a caixa de listagem pode ser redimensionada.|
|[CMFCRibbonComboBox::OnSelectItem](#onselectitem)|Chamado pelo framework quando o usuário seleciona um item na caixa de listagem.|
|[CMFCRibbonComboBox::RemoveAllItems](#removeallitems)|Exclui todos os itens da caixa de listagem e desmarca a caixa de edição.|
|[CMFCRibbonComboBox::SelectItem](#selectitem)|Seleciona um item na caixa de listagem.|
|[CMFCRibbonComboBox::SetDropDownHeight](#setdropdownheight)|Define a altura da caixa de listagem, quando ele é removido para baixo.|

## <a name="remarks"></a>Comentários

A caixa de combinação da faixa de opções consiste em uma caixa de listagem, combinada com um rótulo estático ou um rótulo que pode ser editado pelo usuário. Você deve especificar o tipo desejado ao criar a caixa de combinação da faixa de opções.

## <a name="example"></a>Exemplo

O exemplo a seguir demonstra como construir um objeto do `CMFCRibbonComboBox` de classe, adicione um item à caixa de combinação, selecione um item na caixa de combinação e adicionar uma caixa de combinação a um painel.

[!code-cpp[NVC_MFC_RibbonApp#11](../../mfc/reference/codesnippet/cpp/cmfcribboncombobox-class_1.cpp)]

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

[CObject](../../mfc/reference/cobject-class.md)

[CMFCRibbonBaseElement](../../mfc/reference/cmfcribbonbaseelement-class.md)

[CMFCRibbonButton](../../mfc/reference/cmfcribbonbutton-class.md)

[CMFCRibbonEdit](../../mfc/reference/cmfcribbonedit-class.md)

[CMFCRibbonComboBox](../../mfc/reference/cmfcribboncombobox-class.md)

## <a name="requirements"></a>Requisitos

**Cabeçalho:** afxribboncombobox.h

##  <a name="additem"></a>  CMFCRibbonComboBox::AddItem

Acrescenta um item exclusivo para a caixa de listagem.

```
virtual INT_PTR AddItem(
    LPCTSTR lpszItem,
    DWORD_PTR dwData=0);
```

### <a name="parameters"></a>Parâmetros

*lpszItem*<br/>
[in] A cadeia de caracteres do item a ser adicionado.

*dwData*<br/>
[in] Os dados associados com o item a ser adicionado.

### <a name="return-value"></a>Valor de retorno

O índice baseado em zero do item acrescentado.

##  <a name="cmfcribboncombobox"></a>  CMFCRibbonComboBox::CMFCRibbonComboBox

Constrói um objeto `CMFCRibbonComboBox`.

```
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
[in] A ID da caixa de combinação.

*bHasEditBox*<br/>
[in] TRUE se você quiser uma caixa de edição dentro do controle; FALSE caso contrário.

*nWidth*<br/>
[in] Largura da caixa de combinação em pixels; ou -1 para a largura padrão.

*lpszLabel*<br/>
[in] O rótulo de exibição da caixa de combinação.

*Nimagem*<br/>
[in] O índice de imagem em miniatura da caixa de combinação.

### <a name="remarks"></a>Comentários

A largura padrão é 108 pixels.

##  <a name="deleteitem"></a>  CMFCRibbonComboBox::DeleteItem

Exclui um item especificado na caixa de listagem.

```
BOOL DeleteItem(int iIndex);
BOOL DeleteItem(DWORD_PTR dwData);

BOOL DeleteItem(LPCTSTR lpszText);
```

### <a name="parameters"></a>Parâmetros

*iIndex*<br/>
[in] O índice baseado em zero do item a ser excluído.

*dwData*<br/>
[in] Os dados associados ao item a ser excluído.

*lpszText*<br/>
[in] A cadeia de caracteres do item a ser excluído. Se houver vários itens com a mesma cadeia de caracteres, o primeiro item é excluído.

### <a name="return-value"></a>Valor de retorno

TRUE se o item especificado foi excluído; Caso contrário, FALSE.

### <a name="remarks"></a>Comentários

##  <a name="enabledropdownlistresize"></a>  CMFCRibbonComboBox::EnableDropDownListResize

Especifica se a caixa de listagem pode alterar o tamanho quando ela cai para baixo.

```
void EnableDropDownListResize(BOOL bEnable=FALSE);
```

### <a name="parameters"></a>Parâmetros

*bAtivar*<br/>
[in] True para habilitar o redimensionamento; FALSE para desabilitar o redimensionamento.

### <a name="remarks"></a>Comentários

Quando o redimensionamento é habilitado, a caixa de listagem será alterar o tamanho de acordo com os itens que ele exibe.

##  <a name="finditem"></a>  CMFCRibbonComboBox::FindItem

Retorna o índice do primeiro item na caixa de listagem que corresponde a uma cadeia de caracteres especificada.

```
int FindItem(LPCTSTR lpszText) const;
```

### <a name="parameters"></a>Parâmetros

*lpszText*<br/>
[in] A cadeia de caracteres de um item na caixa de listagem.

### <a name="return-value"></a>Valor de retorno

O índice baseado em zero do item; ou -1 se o item não for encontrado.

### <a name="remarks"></a>Comentários

##  <a name="getcount"></a>  CMFCRibbonComboBox::GetCount

Retorna o número de itens na caixa de listagem.

```
INT_PTR GetCount() const;
```

### <a name="return-value"></a>Valor de retorno

O número de itens na caixa de listagem, ou 0 se a caixa de listagem não contém itens.

### <a name="remarks"></a>Comentários

##  <a name="getcursel"></a>  CMFCRibbonComboBox::GetCurSel

Obtém o índice do item atualmente selecionado na caixa de listagem.

```
int GetCurSel() const;
```

### <a name="return-value"></a>Valor de retorno

O índice baseado em zero do item atualmente selecionado na caixa de listagem; ou -1 se nenhum item está selecionado.

##  <a name="getdropdownheight"></a>  CMFCRibbonComboBox::GetDropDownHeight

Obtém a altura da caixa de listagem, quando a caixa de listagem é descartada para baixo.

```
int GetDropDownHeight();
```

### <a name="return-value"></a>Valor de retorno

A altura, em pixels, da caixa de listagem.

### <a name="remarks"></a>Comentários

##  <a name="getintermediatesize"></a>  CMFCRibbonComboBox::GetIntermediateSize

Retorna o tamanho da caixa de combinação, conforme exibido no modo de intermediário.

```
virtual CSize GetIntermediateSize(CDC* pDC);
```

### <a name="parameters"></a>Parâmetros

*pDC*<br/>
[in] Ponteiro para um contexto de dispositivo para a caixa de combinação.

### <a name="return-value"></a>Valor de retorno

O tamanho da caixa de combinação.

### <a name="remarks"></a>Comentários

O tamanho retornado baseia-se no tamanho da caixa de combinação quando exibe imagens pequenas.

##  <a name="getitem"></a>  CMFCRibbonComboBox::GetItem

Retorna a cadeia de caracteres associada a um item em um índice especificado na caixa de listagem.

```
LPCTSTR GetItem(int iIndex) const;
```

### <a name="parameters"></a>Parâmetros

*iIndex*<br/>
[in] O índice baseado em zero de um item na caixa de listagem.

### <a name="return-value"></a>Valor de retorno

Um ponteiro para a cadeia de caracteres que está associado com o item; Caso contrário, nulo se o parâmetro de índice é inválido, ou se o parâmetro index é -1 e não há nenhum item selecionado na caixa de combinação.

### <a name="remarks"></a>Comentários

##  <a name="getitemdata"></a>  CMFCRibbonComboBox::GetItemData

Retorna os dados associados a um item em um índice especificado na caixa de listagem.

```
DWORD_PTR GetItemData(int iIndex) const;
```

### <a name="parameters"></a>Parâmetros

*iIndex*<br/>
[in] O índice baseado em zero de um item na caixa de listagem.

### <a name="return-value"></a>Valor de retorno

Os dados associados com o item; ou 0 se o item não existe ou se o parâmetro index é -1 e não há nenhum item selecionado na caixa de listagem.

##  <a name="haseditbox"></a>  CMFCRibbonComboBox::HasEditBox

Indica se o controle contém uma caixa de edição.

```
BOOL HasEditBox() const;
```

### <a name="return-value"></a>Valor de retorno

TRUE se o controle contém uma caixa de edição; Caso contrário, FALSE.

### <a name="remarks"></a>Comentários

##  <a name="isresizedropdownlist"></a>  CMFCRibbonComboBox::IsResizeDropDownList

Indica se a caixa de listagem pode ser redimensionada.

```
BOOL IsResizeDropDownList() const;
```

### <a name="return-value"></a>Valor de retorno

TRUE se a caixa de listagem pode ser redimensionada; Caso contrário, FALSE. [CMFCRibbonComboBox::EnableDropDownListResize](#enabledropdownlistresize)

### <a name="remarks"></a>Comentários

Você pode habilitar o redimensionamento de caixa de lista usando o [CMFCRibbonComboBox::EnableDropDownListResize](#enabledropdownlistresize) método.

##  <a name="onselectitem"></a>  CMFCRibbonComboBox::OnSelectItem

Chamado pelo framework quando um usuário seleciona um item na caixa de listagem.

```
virtual void OnSelectItem(int nItem);
```

### <a name="parameters"></a>Parâmetros

*nItem*<br/>
[in] O índice do item selecionado.

### <a name="remarks"></a>Comentários

Substitua este método se você quiser processar uma seleção de entrada do usuário.

##  <a name="removeallitems"></a>  CMFCRibbonComboBox::RemoveAllItems

Exclui todos os itens da caixa de listagem e desmarca a caixa de edição.

```
void RemoveAllItems();
```

### <a name="remarks"></a>Comentários

##  <a name="selectitem"></a>  CMFCRibbonComboBox::SelectItem

Seleciona um item na caixa de listagem.

```
BOOL SelectItem(int iIndex);
BOOL SelectItem(DWORD_PTR dwData);

BOOL SelectItem(LPCTSTR lpszText);
```

### <a name="parameters"></a>Parâmetros

*iIndex*<br/>
[in] O índice baseado em zero de um item na caixa de listagem.

*dwData*<br/>
[in] Os dados associados a um item na caixa de listagem.

*lpszText*<br/>
[in] A cadeia de caracteres de um item na caixa de listagem.

### <a name="return-value"></a>Valor de retorno

TRUE se o método foi bem-sucedida; Caso contrário, FALSE.

### <a name="remarks"></a>Comentários

##  <a name="setdropdownheight"></a>  CMFCRibbonComboBox::SetDropDownHeight

Define a altura da caixa de listagem, quando ele é removido para baixo.

```
void SetDropDownHeight(int nHeight);
```

### <a name="parameters"></a>Parâmetros

*nHeight*<br/>
[in] A altura, em pixels, da caixa de listagem.

### <a name="remarks"></a>Comentários

A altura padrão é 150 pixels.

## <a name="see-also"></a>Consulte também

[Gráfico da hierarquia](../../mfc/hierarchy-chart.md)<br/>
[Classes](../../mfc/reference/mfc-classes.md)<br/>
[Classe CMFCRibbonEdit](../../mfc/reference/cmfcribbonedit-class.md)
