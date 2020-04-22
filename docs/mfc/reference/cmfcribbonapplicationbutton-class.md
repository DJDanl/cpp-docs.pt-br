---
title: Classe de botão de aplicação cmfcribbon
ms.date: 11/04/2016
f1_keywords:
- CMFCRibbonApplicationButton
- AFXRIBBONBAR/CMFCRibbonApplicationButton
- AFXRIBBONBAR/CMFCRibbonApplicationButton::CMFCRibbonApplicationButton
- AFXRIBBONBAR/CMFCRibbonApplicationButton::SetImage
helpviewer_keywords:
- CMFCRibbonApplicationButton [MFC], CMFCRibbonApplicationButton
- CMFCRibbonApplicationButton [MFC], SetImage
ms.assetid: beb81757-fabd-4641-9130-876ba8505b78
ms.openlocfilehash: b28d075c5fcc4313e1a62ae731b3fad8ef4d8a12
ms.sourcegitcommit: 7a6116e48c3c11b97371b8ae4ecc23adce1f092d
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/22/2020
ms.locfileid: "81749937"
---
# <a name="cmfcribbonapplicationbutton-class"></a>Classe de botão de aplicação cmfcribbon

Implementa um botão especial localizado no canto superior esquerdo da janela de aplicação. Quando clicado, o botão abre um menu que geralmente contém comandos comuns **de arquivo** como **Open**, **Save**e **Exit**.

## <a name="syntax"></a>Sintaxe

```
class CMFCRibbonApplicationButton : public CMFCRibbonButton
```

## <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores públicos

|Nome|Descrição|
|----------|-----------------|
|[CMFCRibbonApplicationButton::CMFCRibbonApplicationButton](#cmfcribbonapplicationbutton)|Constrói e inicializa um objeto `CMFCRibbonApplicationButton`.|

### <a name="public-methods"></a>Métodos públicos

|Nome|Descrição|
|----------|-----------------|
|`CMFCRibbonApplicationButton::CreateObject`|Usado pela estrutura para criar uma instância dinâmica desse tipo de classe.|
|`CMFCRibbonApplicationButton::GetThisClass`|Usado pela estrutura para obter um ponteiro para o objeto [CRuntimeClass](../../mfc/reference/cruntimeclass-structure.md) que está associado a este tipo de classe.|
|[CMFCRibbonApplicationButton::SetImage](#setimage)|Atribui uma imagem ao botão de aplicação da fita.|

## <a name="example"></a>Exemplo

O exemplo a seguir demonstra como `CMFCRibbonApplicationButton` usar vários métodos na classe. O exemplo mostra como atribuir uma imagem ao botão de aplicativo e como definir sua dica de ferramenta. Este trecho de código faz parte da [amostra Draw Client](../../overview/visual-cpp-samples.md).

[!code-cpp[NVC_MFC_DrawClient#4](../../mfc/reference/codesnippet/cpp/cmfcribbonapplicationbutton-class_1.h)]
[!code-cpp[NVC_MFC_DrawClient#5](../../mfc/reference/codesnippet/cpp/cmfcribbonapplicationbutton-class_2.cpp)]

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

[Cobject](../../mfc/reference/cobject-class.md)

[Cmfcribbonbaseelement](../../mfc/reference/cmfcribbonbaseelement-class.md)

[Cmfcribbonbutton](../../mfc/reference/cmfcribbonbutton-class.md)

[Botão de aplicação do CMFCRibbon](../../mfc/reference/cmfcribbonapplicationbutton-class.md)

## <a name="requirements"></a>Requisitos

**Cabeçalho:** afxRibbonBar.h

## <a name="cmfcribbonapplicationbuttoncmfcribbonapplicationbutton"></a><a name="cmfcribbonapplicationbutton"></a>CMFCRibbonApplicationButton::CMFCRibbonApplicationButton

Constrói e inicializa um objeto [CMFCRibbonApplicationButton.](../../mfc/reference/cmfcribbonapplicationbutton-class.md)

```
CMFCRibbonApplicationButton();
CMFCRibbonApplicationButton(UINT uiBmpResID);
CMFCRibbonApplicationButton(HBITMAP hBmp);
```

### <a name="parameters"></a>Parâmetros

*uiBmpResID*<br/>
O ID de recurso da imagem a ser exibido no botão do aplicativo.

*hBmp*<br/>
Uma alça para um bitmap para exibir no botão de aplicativo.

### <a name="remarks"></a>Comentários

O botão de aplicação da fita é um botão especial que está localizado no canto superior esquerdo da janela de aplicação. Quando um usuário clica neste botão, o aplicativo abre um menu que geralmente contém comandos comuns **de arquivo,** como **Open**, **Save**e **Exit**.

## <a name="cmfcribbonapplicationbuttonsetimage"></a><a name="setimage"></a>CMFCRibbonApplicationButton::SetImage

Atribui uma imagem ao botão de aplicativo.

```cpp
void SetImage(UINT uiBmpResID);
void SetImage(HBITMAP hBmp);
```

### <a name="parameters"></a>Parâmetros

*uiBmpResID*<br/>
[em] O ID de recurso da imagem a ser exibido no botão do aplicativo.

*hBmp*<br/>
[em] Uma alça para um bitmap para exibir no botão de aplicativo.

### <a name="remarks"></a>Comentários

Use este método para atribuir uma nova imagem ao botão de aplicativo de fita depois de criar o botão. O botão de aplicação está localizado no canto superior esquerdo da janela de aplicação.

## <a name="see-also"></a>Confira também

[Gráfico da hierarquia](../../mfc/hierarchy-chart.md)<br/>
[Classes](../../mfc/reference/mfc-classes.md)<br/>
[Classe CMFCRibbonButton](../../mfc/reference/cmfcribbonbutton-class.md)
