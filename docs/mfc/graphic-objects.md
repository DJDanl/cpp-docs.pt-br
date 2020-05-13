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
ms.openlocfilehash: 0201e53114b71c02877762f89cc65fc46d17700c
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81370522"
---
# <a name="graphic-objects"></a>Objetos gráficos

O Windows fornece uma variedade de ferramentas de desenho para usar em contextos de dispositivos. Ele fornece canetas para desenhar linhas, pincéis para preencher interiores e fontes para desenhar texto. O MFC fornece classes de objetos gráficos equivalentes às ferramentas de desenho no Windows. A tabela abaixo mostra as classes disponíveis e os tipos de interface de dispositivo gráfico (GDI) equivalentes.

> [!NOTE]
> Para obter mais informações, consulte a [documentação GDI+ SDK](/windows/win32/gdiplus/-gdiplus-gdi-start).

Este artigo explica o uso dessas classes de objetos gráficos:

### <a name="classes-for-windows-gdi-objects"></a>Aulas para objetos Windows GDI

|Classe|Tipo de alça do Windows|
|-----------|-------------------------|
|[Cpen](../mfc/reference/cpen-class.md)|`HPEN`|
|[Cbrush](../mfc/reference/cbrush-class.md)|`HBRUSH`|
|[Cfont](../mfc/reference/cfont-class.md)|**Hfont**|
|[Cbitmap](../mfc/reference/cbitmap-class.md)|`HBITMAP`|
|[Cpalette](../mfc/reference/cpalette-class.md)|`HPALETTE`|
|[Crgn](../mfc/reference/crgn-class.md)|**HRGN**|

> [!NOTE]
> A classe [CImage](../atl-mfc-shared/reference/cimage-class.md) oferece suporte aprimorado ao bitmap.

Cada classe de objetográfico na biblioteca de classe tem um construtor que permite criar objetos gráficos dessa classe, que você deve então inicializar com a função de criação apropriada, como `CreatePen`.

Cada classe de objetográfico na biblioteca de classe tem um operador de elenco que lançará um objeto MFC para a alça do Windows associada. A pega resultante é válida até que o objeto associado o desconecte. Use a função `Detach` de membro do objeto para desprender a pega.

O código a `CPen` seguir lança um objeto para uma alça do Windows:

[!code-cpp[NVC_MFCDocViewSDI#5](../mfc/codesnippet/cpp/graphic-objects_1.cpp)]

#### <a name="to-create-a-graphic-object-in-a-device-context"></a>Para criar um objeto gráfico em um contexto de dispositivo

1. Defina um objeto gráfico no quadro de pilha. Inicialize o objeto com a função de `CreatePen`criação específica do tipo, como . Alternativamente, inicialize o objeto na construtora. Veja a discussão da [criação de um estágio e dois estágios,](../mfc/one-stage-and-two-stage-construction-of-objects.md)que fornece código de exemplo.

1. [Selecione o objeto no contexto atual do dispositivo,](../mfc/selecting-a-graphic-object-into-a-device-context.md)salvando o objeto gráfico antigo que foi selecionado antes.

1. Quando terminar com o objeto gráfico atual, selecione o objeto gráfico antigo de volta ao contexto do dispositivo para restaurar seu estado.

1. Permitir que o objeto gráfico alocado em quadro seja excluído automaticamente quando o escopo for eliminado.

> [!NOTE]
> Se você estiver usando um objeto gráfico repetidamente, você pode alocá-lo uma vez e selecioná-lo em um contexto de dispositivo cada vez que for necessário. Certifique-se de excluir tal objeto quando você não precisar mais dele.

### <a name="what-do-you-want-to-know-more-about"></a>O que você quer saber mais sobre

- [Construção de objetos gráficos em um estágio e dois estágios](../mfc/one-stage-and-two-stage-construction-of-objects.md)

- [Exemplo de construção de uma caneta em um e dois estágios](../mfc/one-stage-and-two-stage-construction-of-objects.md)

- [Selecionando um objeto gráfico em um contexto de dispositivo](../mfc/selecting-a-graphic-object-into-a-device-context.md)

- [Contextos de dispositivo](../mfc/device-contexts.md)

## <a name="see-also"></a>Confira também

[Objetos de janela](../mfc/window-objects.md)
