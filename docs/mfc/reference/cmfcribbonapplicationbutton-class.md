---
title: Classe CMFCRibbonApplicationButton
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
ms.openlocfilehash: d1dc8ef6e801623aa96cb4b47936413cd17f24f0
ms.sourcegitcommit: c3bf94210bdb73be80527166264d49e33784152c
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/06/2019
ms.locfileid: "68821244"
---
# <a name="cmfcribbonapplicationbutton-class"></a>Classe CMFCRibbonApplicationButton

Implementa um botão especial localizado no canto superior esquerdo da janela do aplicativo. Quando clicado, o botão abre um menu que geralmente contém comandos de **arquivo** comuns, como **abrir**, **salvar**e **sair**.

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
|`CMFCRibbonApplicationButton::GetThisClass`|Usado pela estrutura para obter um ponteiro para o objeto [CRuntimeClass](../../mfc/reference/cruntimeclass-structure.md) que está associado a esse tipo de classe.|
|[CMFCRibbonApplicationButton:: SetImage](#setimage)|Atribui uma imagem ao botão do aplicativo da faixa de faixas.|

## <a name="example"></a>Exemplo

O exemplo a seguir demonstra como usar vários métodos na `CMFCRibbonApplicationButton` classe. O exemplo mostra como atribuir uma imagem ao botão do aplicativo e como definir sua dica de ferramenta. Este trecho de código faz parte do [exemplo de cliente de desenho](../../overview/visual-cpp-samples.md).

[!code-cpp[NVC_MFC_DrawClient#4](../../mfc/reference/codesnippet/cpp/cmfcribbonapplicationbutton-class_1.h)]
[!code-cpp[NVC_MFC_DrawClient#5](../../mfc/reference/codesnippet/cpp/cmfcribbonapplicationbutton-class_2.cpp)]

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

[CObject](../../mfc/reference/cobject-class.md)

[CMFCRibbonBaseElement](../../mfc/reference/cmfcribbonbaseelement-class.md)

[CMFCRibbonButton](../../mfc/reference/cmfcribbonbutton-class.md)

[CMFCRibbonApplicationButton](../../mfc/reference/cmfcribbonapplicationbutton-class.md)

## <a name="requirements"></a>Requisitos

**Cabeçalho:** afxRibbonBar. h

##  <a name="cmfcribbonapplicationbutton"></a>CMFCRibbonApplicationButton::CMFCRibbonApplicationButton

Constrói e inicializa um objeto [CMFCRibbonApplicationButton](../../mfc/reference/cmfcribbonapplicationbutton-class.md) .

```
CMFCRibbonApplicationButton();
CMFCRibbonApplicationButton(UINT uiBmpResID);
CMFCRibbonApplicationButton(HBITMAP hBmp);
```

### <a name="parameters"></a>Parâmetros

*uiBmpResID*<br/>
A ID de recurso da imagem a ser exibida no botão do aplicativo.

*hBmp*<br/>
Um identificador para um bitmap a ser exibido no botão do aplicativo.

### <a name="remarks"></a>Comentários

O botão aplicativo da faixa de das faixas é um botão especial localizado no canto superior esquerdo da janela do aplicativo. Quando um usuário clica nesse botão, o aplicativo abre um menu que geralmente contém comandos de **arquivo** comuns, como **abrir**, **salvar**e **sair**.

##  <a name="setimage"></a>CMFCRibbonApplicationButton:: SetImage

Atribui uma imagem ao botão do aplicativo.

```
void SetImage(UINT uiBmpResID);
void SetImage(HBITMAP hBmp);
```

### <a name="parameters"></a>Parâmetros

*uiBmpResID*<br/>
no A ID de recurso da imagem a ser exibida no botão do aplicativo.

*hBmp*<br/>
no Um identificador para um bitmap a ser exibido no botão do aplicativo.

### <a name="remarks"></a>Comentários

Use esse método para atribuir uma nova imagem ao botão do aplicativo da faixa de faixas depois de criar o botão. O botão aplicativo está localizado no canto superior esquerdo da janela do aplicativo.

## <a name="see-also"></a>Consulte também

[Gráfico da hierarquia](../../mfc/hierarchy-chart.md)<br/>
[Classes](../../mfc/reference/mfc-classes.md)<br/>
[Classe CMFCRibbonButton](../../mfc/reference/cmfcribbonbutton-class.md)
