---
title: Classe CMFCRibbonUndoButton
ms.date: 11/04/2016
f1_keywords:
- CMFCRibbonUndoButton
- AFXRIBBONUNDOBUTTON/CMFCRibbonUndoButton
- AFXRIBBONUNDOBUTTON/CMFCRibbonUndoButton::CMFCRibbonUndoButton
- AFXRIBBONUNDOBUTTON/CMFCRibbonUndoButton::AddUndoAction
- AFXRIBBONUNDOBUTTON/CMFCRibbonUndoButton::CleanUpUndoList
- AFXRIBBONUNDOBUTTON/CMFCRibbonUndoButton::GetActionNumber
- AFXRIBBONUNDOBUTTON/CMFCRibbonUndoButton::HasMenu
helpviewer_keywords:
- CMFCRibbonUndoButton [MFC], CMFCRibbonUndoButton
- CMFCRibbonUndoButton [MFC], AddUndoAction
- CMFCRibbonUndoButton [MFC], CleanUpUndoList
- CMFCRibbonUndoButton [MFC], GetActionNumber
- CMFCRibbonUndoButton [MFC], HasMenu
ms.assetid: 5c42adf7-871d-4239-901e-47ae7fb816fc
ms.openlocfilehash: 15cf93d39057f0e235779d47cf24d920d80a807d
ms.sourcegitcommit: 7a6116e48c3c11b97371b8ae4ecc23adce1f092d
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/22/2020
ms.locfileid: "81753506"
---
# <a name="cmfcribbonundobutton-class"></a>Classe CMFCRibbonUndoButton

A `CMFCRibbonUndoButton` classe implementa um botão de lista baixa que contém os comandos de usuário mais recentes. Os usuários podem selecionar um ou mais dos comandos mais recentes da lista de baixa para refazê-los ou desfazê-los.

## <a name="syntax"></a>Sintaxe

```
class CMFCRibbonUndoButton : public CMFCRibbonGallery
```

## <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores públicos

|Nome|Descrição|
|----------|-----------------|
|[CMFCRibbonUndoButton::CMFCRibbonUndoButton](#cmfcribbonundobutton)|Constrói um `CMFCRibbonUndoButton` novo objeto usando o ID de comando que você especifica, o rótulo de texto e as imagens da lista de imagens do objeto pai.|

### <a name="public-methods"></a>Métodos públicos

|Nome|Descrição|
|----------|-----------------|
|[CMFCRibbonUndoButton::AddUndoAction](#addundoaction)|Adiciona uma nova ação à lista de ações.|
|[CMFCRibbonUndoButton::CleanUpUndoList](#cleanupundolist)|Limpa a lista de ação, que é a lista de paradas.|
|[CMFCRibbonUndoButton::GetActionNumber](#getactionnumber)|Determina o número de itens selecionados por um usuário na lista de itens.|
|[CMFCRibbonUndoButton::HasMenu](#hasmenu)|Indica se o objeto contém um menu.|

## <a name="remarks"></a>Comentários

A `CMFCRibbonUndoButton` classe usa uma pilha para representar a lista de paradas.

## <a name="example"></a>Exemplo

O exemplo a seguir demonstra como `CMFCRibbonUndoButton` construir um objeto da classe e adicionar uma nova ação à lista de ações. Este trecho de código faz parte da [amostra Ribbon Gadgets](../../overview/visual-cpp-samples.md).

[!code-cpp[NVC_MFC_RibbonGadgets#2](../../mfc/reference/codesnippet/cpp/cmfcribbonundobutton-class_1.cpp)]

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

[Cobject](../../mfc/reference/cobject-class.md)

[Cmfcribbonbaseelement](../../mfc/reference/cmfcribbonbaseelement-class.md)

[Cmfcribbonbutton](../../mfc/reference/cmfcribbonbutton-class.md)

[Cmfcribbongallery](../../mfc/reference/cmfcribbongallery-class.md)

[Cmfcribbonundobutton](../../mfc/reference/cmfcribbonundobutton-class.md)

## <a name="requirements"></a>Requisitos

**Cabeçalho:** afxribbonundobutton.h

## <a name="cmfcribbonundobuttonaddundoaction"></a><a name="addundoaction"></a>CMFCRibbonUndoButton::AddUndoAction

Adiciona uma nova ação à lista de ações.

```cpp
void AddUndoAction(LPCTSTR lpszLabel);
```

### <a name="parameters"></a>Parâmetros

*lpszLabel*<br/>
[em] O rótulo de ação que será exibido na lista suspensa.

## <a name="cmfcribbonundobuttoncleanupundolist"></a><a name="cleanupundolist"></a>CMFCRibbonUndoButton::CleanUpUndoList

Limpa a lista de ação, que é a lista de paradas.

```cpp
void CleanUpUndoList();
```

## <a name="cmfcribbonundobuttoncmfcribbonundobutton"></a><a name="cmfcribbonundobutton"></a>CMFCRibbonUndoButton::CMFCRibbonUndoButton

Constrói um `CMFCRibbonUndoButton` novo objeto usando o ID de comando que você especifica, o rótulo de texto e as imagens da lista de imagens do objeto pai.

```
CMFCRibbonUndoButton(
    UINT nID,
    LPCTSTR lpszText,
    int nSmallImageIndex=-1,
    int nLargeImageIndex=-1);

CMFCRibbonUndoButton(
    UINT nID,
    LPCTSTR lpszText,
    HICON hIcon);
```

### <a name="parameters"></a>Parâmetros

*nID*<br/>
[em] Especifica o identificador de comando.

*lpszText*<br/>
[em] Especifica o rótulo de texto do botão.

*nSmallImageIndex*<br/>
[em] Índice baseado em zero na lista de imagens do objeto pai para a pequena imagem do botão.

*nLargeImageIndex*<br/>
[em] Índice baseado em zero na lista de imagens do objeto pai para a imagem grande do botão.

*Hicon*<br/>
[em] Uma alça para um ícone que você pode usar como imagem de um botão.

## <a name="cmfcribbonundobuttongetactionnumber"></a><a name="getactionnumber"></a>CMFCRibbonUndoButton::GetActionNumber

Determina o número de itens selecionados por um usuário na lista de itens.

```
int GetActionNumber() const;
```

### <a name="return-value"></a>Valor retornado

O número de itens que um usuário selecionou.

## <a name="cmfcribbonundobuttonhasmenu"></a><a name="hasmenu"></a>CMFCRibbonUndoButton::HasMenu

Indica se o objeto contém um menu.

```
virtual BOOL HasMenu() const;
```

### <a name="return-value"></a>Valor retornado

Sempre retorna TRUE.

### <a name="remarks"></a>Comentários

## <a name="see-also"></a>Confira também

[Gráfico da hierarquia](../../mfc/hierarchy-chart.md)<br/>
[Classes](../../mfc/reference/mfc-classes.md)<br/>
[Classe CMFCRibbonGallery](../../mfc/reference/cmfcribbongallery-class.md)<br/>
[Classe CMFCRibbonButton](../../mfc/reference/cmfcribbonbutton-class.md)
