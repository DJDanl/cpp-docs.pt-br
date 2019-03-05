---
title: Objetos gráficos
ms.date: 11/04/2016
f1_keywords:
- HRGN
- HFONT
- HBITMAP
helpviewer_keywords:
- CRgn class [MFC], HRGN handle type
- HPEN [MFC]
- objects [MFC], graphic
- palettes [MFC], creating in device context
- pens [MFC], creating in device context
- bitmaps [MFC], creating in device contexts
- palette objects [MFC]
- memory [MFC], display contexts
- MFC, graphic objects
- regions [MFC], creating in device context
- CPen class [MFC], HPEN handle type
- GDI objects [MFC]
- HRGN [MFC]
- graphic objects [MFC]
- GDI objects [MFC], graphic-object classes
- CFont class [MFC], HFONT handle type
- HFONT and class CFont [MFC]
- HBITMAP and class CBitmap [MFC]
- fonts [MFC], creating in device context
- images [MFC], graphic objects [MFC]
- CBitmap class [MFC], HBITMAP handle type
- HPALETTE and class CPalette [MFC]
- CBrush class [MFC], HBRUSH handle type
- objects [MFC], graphic objects
- drawing [MFC], in device contexts
- device contexts [MFC], graphic objects [MFC]
- brushes [MFC], creating in device context
- region objects [MFC]
- pen objects [MFC]
- GDI [MFC], graphic-object classes
- graphic objects [MFC], creating in device context
- HBRUSH and class CBrush [MFC]
- painting and device context [MFC]
- CPalette class [MFC], HPALETTE handle type
ms.assetid: 41963b25-34b7-4343-8446-34ba516b83ca
ms.openlocfilehash: 58ecf680d64f39ab61589a0ad668c15d1a9cd68c
ms.sourcegitcommit: c3093251193944840e3d0a068ecc30e6449624ba
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/04/2019
ms.locfileid: "57279569"
---
# <a name="graphic-objects"></a>Objetos gráficos

Windows fornece uma variedade de ferramentas a ser usado em contextos de dispositivo de desenho. Ele fornece canetas para desenhar linhas, pincéis interiores de preenchimento e fontes para desenhar o texto. O MFC fornece classes de objetos gráficos equivalentes a ferramentas de desenho no Windows. A tabela a seguir mostra as classes disponíveis e os gráficos do Windows equivalentes tipos de identificador de interface (GDI) do dispositivo.

> [!NOTE]
>  Para obter mais informações, consulte a documentação do SDK de GDI+ em: [ https://msdn.microsoft.com/library/default.aspurl=/library/gdicpp/GDIPlus/GDIPlus.asp ](https://msdn.microsoft.com/library/default.aspurl=/library/gdicpp/gdiplus/gdiplus.asp).

Este artigo explica o uso dessas classes de objeto de gráfico:

### <a name="classes-for-windows-gdi-objects"></a>Classes para objetos GDI do Windows

|Classe|Tipo de identificador do Windows|
|-----------|-------------------------|
|[CPen](../mfc/reference/cpen-class.md)|`HPEN`|
|[CBrush](../mfc/reference/cbrush-class.md)|`HBRUSH`|
|[CFont](../mfc/reference/cfont-class.md)|**HFONT**|
|[CBitmap](../mfc/reference/cbitmap-class.md)|`HBITMAP`|
|[CPalette](../mfc/reference/cpalette-class.md)|`HPALETTE`|
|[CRgn](../mfc/reference/crgn-class.md)|**HRGN**|

> [!NOTE]
>  A classe [CImage](../atl-mfc-shared/reference/cimage-class.md) fornece suporte de aprimorada de bitmaps.

Cada classe de objeto de gráfico na biblioteca de classes tem um construtor que permite que você crie objetos gráficos dessa classe, o que você deve, em seguida, ser inicializado com a função apropriada de criar, como `CreatePen`.

Cada classe de objeto de gráfico na biblioteca de classes tem um operador de conversão que irá converter um objeto MFC para o identificador do Windows associado. O identificador resultante é válido até que o objeto associado Desanexa a ele. Usar o objeto `Detach` função de membro para desanexar o identificador.

O código a seguir converte um `CPen` objeto para um identificador do Windows:

[!code-cpp[NVC_MFCDocViewSDI#5](../mfc/codesnippet/cpp/graphic-objects_1.cpp)]

#### <a name="to-create-a-graphic-object-in-a-device-context"></a>Para criar um objeto gráfico em um contexto de dispositivo

1. Defina um objeto gráfico no quadro da pilha. Inicializar o objeto com a função de tipo específico de criar, tais como `CreatePen`. Como alternativa, inicialize o objeto no construtor. Consulte a discussão sobre [criação de um e dois estágios](../mfc/one-stage-and-two-stage-construction-of-objects.md), que fornece o código de exemplo.

1. [Selecione o objeto no contexto de dispositivo atual](../mfc/selecting-a-graphic-object-into-a-device-context.md), salvando o objeto de gráfico antigo que foi selecionado antes.

1. Quando terminar com o objeto de gráfico atual, selecione o objeto de gráfico antigo volta para o contexto de dispositivo para restaurar seu estado.

1. Permitir que o objeto de gráfico alocada pelo quadro a ser excluído automaticamente quando o escopo é fechado.

> [!NOTE]
>  Se você estiver usando um objeto gráfico repetidamente, você pode alocá-lo uma vez e selecione-o em um contexto de dispositivo cada vez que é necessária. Certifique-se de excluir esse objeto quando você não precisa mais dela.

### <a name="what-do-you-want-to-know-more-about"></a>O que você deseja saber mais sobre

- [Construção de um e dois estágios de objetos gráficos](../mfc/one-stage-and-two-stage-construction-of-objects.md)

- [Exemplo de como construir uma caneta em um e dois estágios](../mfc/one-stage-and-two-stage-construction-of-objects.md)

- [Selecionando um objeto gráfico em um contexto de dispositivo](../mfc/selecting-a-graphic-object-into-a-device-context.md)

- [Contextos de dispositivo](../mfc/device-contexts.md)

## <a name="see-also"></a>Consulte também

[Objetos de janela](../mfc/window-objects.md)
