---
title: Classe CMFCImageEditorDialog
ms.date: 11/19/2018
f1_keywords:
- CMFCImageEditorDialog
- AFXIMAGEEDITORDIALOG/CMFCImageEditorDialog
- AFXIMAGEEDITORDIALOG/CMFCImageEditorDialog::CMFCImageEditorDialog
helpviewer_keywords:
- CMFCImageEditorDialog [MFC], CMFCImageEditorDialog
ms.assetid: 6a7d08f3-1ec2-4062-9b79-a0c2776b58d1
ms.openlocfilehash: 23c2a919428689fe107b82041bd87b758ede2bc9
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81367475"
---
# <a name="cmfcimageeditordialog-class"></a>Classe CMFCImageEditorDialog

A `CMFCImageEditorDialog` classe suporta uma caixa de diálogo de editor de imagem.

## <a name="syntax"></a>Sintaxe

```
class CMFCImageEditorDialog : public CDialogEx
```

## <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores públicos

|Nome|Descrição|
|----------|-----------------|
|[CMFCImageEditorDiálogo::CMFCImageEditorDiálogo](#cmfcimageeditordialog)|Constrói um objeto `CMFCImageEditorDialog`.|

## <a name="remarks"></a>Comentários

A `CMFCImageEditorDialog` classe fornece uma caixa de diálogo que inclui:

- Uma área de imagem que você usa para modificar pixels individuais em uma imagem.

- Desenho de ferramentas para modificar os pixels na área da imagem.

- Uma paleta de cores para especificar a cor usada pelas ferramentas de desenho.

- Uma área de visualização que exibe o efeito de sua edição.

A ilustração a seguir mostra uma caixa de diálogo do editor de imagens.

![Caixa de diálogo CMFCImageEditorCaixa de diálogo](../../mfc/reference/media/imageedit.png "Caixa de diálogo CMFCImageEditorCaixa de diálogo")

Uma maneira de `CMFCImageEditorDialog` usar um objeto `CBitmap` é passá-lo uma imagem a ser editada. Não crie uma imagem grande porque a área de edição de imagens tem um tamanho limitado e o tamanho de pixel lógico é ajustado para se adequar à área. Ligue `DoModal` para o método para iniciar uma caixa de diálogo modal.

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

[Cobject](../../mfc/reference/cobject-class.md)

[Ccmdtarget](../../mfc/reference/ccmdtarget-class.md)

[CWnd](../../mfc/reference/cwnd-class.md)

[Cdialog](../../mfc/reference/cdialog-class.md)

[Cdialogex](../../mfc/reference/cdialogex-class.md)

[Cmfcimageeditordialog](../../mfc/reference/cmfcimageeditordialog-class.md)

## <a name="requirements"></a>Requisitos

**Cabeçalho:** afximageeditordialog.h

## <a name="cmfcimageeditordialogcmfcimageeditordialog"></a><a name="cmfcimageeditordialog"></a>CMFCImageEditorDiálogo::CMFCImageEditorDiálogo

Constrói um objeto `CMFCImageEditorDialog`.

```
CMFCImageEditorDialog(
    CBitmap* pBitmap,
    CWnd* pParent=NULL,
    int nBitsPixel=-1);
```

### <a name="parameters"></a>Parâmetros

*Pbitmap*<br/>
Ponteiro para uma imagem.

*pParent*<br/>
Ponteiro para a janela pai da caixa de diálogo atual do editor de imagens.

*nBitsPixel*<br/>
O número de bits usados para representar a cor de um único pixel, que também é referido como profundidade de cor.  Se o parâmetro *nBitsPixel* for -1, a profundidade de cor será derivada da imagem especificada pelo parâmetro *pBitmap.* O valor padrão é -1.

### <a name="return-value"></a>Valor retornado

Para modificar uma imagem, passe `CMFCImageEditorDialog` um ponteiro de imagem para o construtor. Em seguida, chame o `DoModal` método para abrir uma caixa de diálogo modal. Quando `DoModal` o método retorna, o bitmap contém a nova imagem.

### <a name="remarks"></a>Comentários

### <a name="example"></a>Exemplo

O exemplo a seguir demonstra como `CMFCImageEditorDialog` construir um objeto da classe. Este exemplo faz parte da [amostra Novos Controles](../../overview/visual-cpp-samples.md).

[!code-cpp[NVC_MFC_NewControls#8](../../mfc/reference/codesnippet/cpp/cmfcimageeditordialog-class_1.cpp)]
[!code-cpp[NVC_MFC_NewControls#40](../../mfc/reference/codesnippet/cpp/cmfcimageeditordialog-class_2.cpp)]

## <a name="see-also"></a>Confira também

[Gráfico da hierarquia](../../mfc/hierarchy-chart.md)<br/>
[Classes](../../mfc/reference/mfc-classes.md)<br/>
[Classe CMFCToolBar](../../mfc/reference/cmfctoolbar-class.md)
