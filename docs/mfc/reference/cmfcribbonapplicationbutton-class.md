---
title: Classe CMFCRibbonApplicationButton | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-mfc
ms.topic: reference
f1_keywords:
- CMFCRibbonApplicationButton
- AFXRIBBONBAR/CMFCRibbonApplicationButton
- AFXRIBBONBAR/CMFCRibbonApplicationButton::CMFCRibbonApplicationButton
- AFXRIBBONBAR/CMFCRibbonApplicationButton::SetImage
dev_langs:
- C++
helpviewer_keywords:
- CMFCRibbonApplicationButton [MFC], CMFCRibbonApplicationButton
- CMFCRibbonApplicationButton [MFC], SetImage
ms.assetid: beb81757-fabd-4641-9130-876ba8505b78
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 7b82e0da2ac080ea65807b92f7eab549fe3301bf
ms.sourcegitcommit: 799f9b976623a375203ad8b2ad5147bd6a2212f0
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/19/2018
ms.locfileid: "46393796"
---
# <a name="cmfcribbonapplicationbutton-class"></a>Classe CMFCRibbonApplicationButton

Implementa um botão especial localizado no canto superior esquerdo da janela do aplicativo. Quando clicado, o botão abre um menu que geralmente contém comuns **arquivo** comandos como **abra**, **salvar**, e **Exit**.

## <a name="syntax"></a>Sintaxe

```
class CMFCRibbonApplicationButton : public CMFCRibbonButton
```

## <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores Públicos

|Nome|Descrição|
|----------|-----------------|
|[CMFCRibbonApplicationButton::CMFCRibbonApplicationButton](#cmfcribbonapplicationbutton)|Constrói e inicializa um objeto `CMFCRibbonApplicationButton`.|

### <a name="public-methods"></a>Métodos públicos

|Nome|Descrição|
|----------|-----------------|
|`CMFCRibbonApplicationButton::CreateObject`|Usado pelo framework para criar uma instância dinâmica desse tipo de classe.|
|`CMFCRibbonApplicationButton::GetThisClass`|Usado pelo framework para obter um ponteiro para o [CRuntimeClass](../../mfc/reference/cruntimeclass-structure.md) objeto que está associado com esse tipo de classe.|
|[CMFCRibbonApplicationButton::SetImage](#setimage)|Atribui uma imagem para o botão do aplicativo de faixa de opções.|

## <a name="example"></a>Exemplo

O exemplo a seguir demonstra como usar vários métodos no `CMFCRibbonApplicationButton` classe. O exemplo mostra como atribuir uma imagem para o botão do aplicativo e como definir sua dica de ferramenta. Este trecho de código é parte do [desenhar o cliente de exemplo](../../visual-cpp-samples.md).

[!code-cpp[NVC_MFC_DrawClient#4](../../mfc/reference/codesnippet/cpp/cmfcribbonapplicationbutton-class_1.h)]
[!code-cpp[NVC_MFC_DrawClient#5](../../mfc/reference/codesnippet/cpp/cmfcribbonapplicationbutton-class_2.cpp)]

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

[CObject](../../mfc/reference/cobject-class.md)

[CMFCRibbonBaseElement](../../mfc/reference/cmfcribbonbaseelement-class.md)

[CMFCRibbonButton](../../mfc/reference/cmfcribbonbutton-class.md)

[CMFCRibbonApplicationButton](../../mfc/reference/cmfcribbonapplicationbutton-class.md)

## <a name="requirements"></a>Requisitos

**Cabeçalho:** afxribbonbar. H

##  <a name="cmfcribbonapplicationbutton"></a>  CMFCRibbonApplicationButton::CMFCRibbonApplicationButton

Constrói e inicializa um [CMFCRibbonApplicationButton](../../mfc/reference/cmfcribbonapplicationbutton-class.md) objeto.

```
CMFCRibbonApplicationButton();
CMFCRibbonApplicationButton(UINT uiBmpResID);
  CMFCRibbonApplicationButton(HBITMAP hBmp);
```

### <a name="parameters"></a>Parâmetros

*uiBmpResID*<br/>
A ID de recurso da imagem a ser exibido no botão de aplicativo.

*hBmp*<br/>
Um identificador para um bitmap a ser exibido no botão de aplicativo.

### <a name="remarks"></a>Comentários

O botão do aplicativo de faixa de opções é um botão especial localizado no canto superior esquerdo da janela do aplicativo. Quando um usuário clica nesse botão, o aplicativo abre um menu que geralmente contém comuns **arquivo** comandos, como **abra**, **salvar**, e **sair**.

##  <a name="setimage"></a>  CMFCRibbonApplicationButton::SetImage

Atribui uma imagem para o botão do aplicativo.

```
void SetImage(UINT uiBmpResID);
void SetImage(HBITMAP hBmp);
```

### <a name="parameters"></a>Parâmetros

*uiBmpResID*<br/>
[in] A ID de recurso da imagem a ser exibido no botão de aplicativo.

*hBmp*<br/>
[in] Um identificador para um bitmap a ser exibido no botão de aplicativo.

### <a name="remarks"></a>Comentários

Use esse método para atribuir uma nova imagem para o botão da faixa de opções do aplicativo depois de criar o botão. O botão do aplicativo está localizado no canto superior esquerdo da janela do aplicativo.

## <a name="see-also"></a>Consulte também

[Gráfico da hierarquia](../../mfc/hierarchy-chart.md)<br/>
[Classes](../../mfc/reference/mfc-classes.md)<br/>
[Classe CMFCRibbonButton](../../mfc/reference/cmfcribbonbutton-class.md)
