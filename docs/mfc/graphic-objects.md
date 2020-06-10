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
ms.openlocfilehash: a7d038a971fd1d280c100024f8af9a1ec74d8627
ms.sourcegitcommit: c21b05042debc97d14875e019ee9d698691ffc0b
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 06/09/2020
ms.locfileid: "84618647"
---
# <a name="graphic-objects"></a>Objetos gráficos

O Windows fornece uma variedade de ferramentas de desenho para usar em contextos de dispositivo. Ele fornece as canetas para desenhar linhas, pincéis para preencher interiores e fontes para desenhar texto. O MFC fornece classes de objeto gráfico equivalentes às ferramentas de desenho no Windows. A tabela a seguir mostra as classes disponíveis e os tipos de identificadores da interface de dispositivo gráfico do Windows (GDI) equivalentes.

> [!NOTE]
> Para obter mais informações, consulte a [documentação do SDK do GDI+](/windows/win32/gdiplus/-gdiplus-gdi-start).

Este artigo explica o uso dessas classes de objeto gráfico:

### <a name="classes-for-windows-gdi-objects"></a>Classes para objetos GDI do Windows

|Class|Tipo de identificador do Windows|
|-----------|-------------------------|
|[CPen](reference/cpen-class.md)|`HPEN`|
|[CBrush](reference/cbrush-class.md)|`HBRUSH`|
|[CFont](reference/cfont-class.md)|**HFONT**|
|[CBitmap](reference/cbitmap-class.md)|`HBITMAP`|
|[CPalette](reference/cpalette-class.md)|`HPALETTE`|
|[CRgn](reference/crgn-class.md)|**HRGN**|

> [!NOTE]
> A classe [CImage](../atl-mfc-shared/reference/cimage-class.md) fornece suporte a bitmap aprimorado.

Cada classe de objeto gráfico na biblioteca de classes tem um construtor que permite que você crie objetos gráficos dessa classe, que você deve então inicializar com a função de criação apropriada, como `CreatePen` .

Cada classe de objeto gráfico na biblioteca de classes tem um operador cast que irá converter um objeto MFC no identificador do Windows associado. O identificador resultante é válido até que o objeto associado o desanexe. Use a função de `Detach` membro do objeto para desanexar o identificador.

O código a seguir converte um `CPen` objeto em um identificador do Windows:

[!code-cpp[NVC_MFCDocViewSDI#5](codesnippet/cpp/graphic-objects_1.cpp)]

#### <a name="to-create-a-graphic-object-in-a-device-context"></a>Para criar um objeto gráfico em um contexto de dispositivo

1. Defina um objeto gráfico no quadro de pilhas. Inicialize o objeto com a função de criação específica de tipo, como `CreatePen` . Como alternativa, inicialize o objeto no construtor. Consulte a discussão de [criação de um estágio e de dois estágios](one-stage-and-two-stage-construction-of-objects.md), que fornece código de exemplo.

1. [Selecione o objeto no contexto do dispositivo atual](selecting-a-graphic-object-into-a-device-context.md), salvando o antigo objeto gráfico que foi selecionado antes.

1. Quando terminar com o objeto gráfico atual, selecione o objeto gráfico antigo novamente no contexto do dispositivo para restaurar seu estado.

1. Permitir que o objeto gráfico alocado por quadro seja excluído automaticamente quando o escopo for encerrado.

> [!NOTE]
> Se você estiver usando um objeto gráfico repetidamente, poderá alocá-lo uma vez e selecioná-lo em um contexto de dispositivo toda vez que for necessário. Certifique-se de excluir esse objeto quando você não precisar mais dele.

### <a name="what-do-you-want-to-know-more-about"></a>Do que você deseja saber mais sobre

- [Construção de um estágio e de dois estágios de objetos gráficos](one-stage-and-two-stage-construction-of-objects.md)

- [Exemplo de construção de uma caneta em um e dois estágios](one-stage-and-two-stage-construction-of-objects.md)

- [Selecionando um objeto gráfico em um contexto de dispositivo](selecting-a-graphic-object-into-a-device-context.md)

- [Contextos de dispositivo](device-contexts.md)

## <a name="see-also"></a>Consulte também

[Objetos de janela](window-objects.md)
