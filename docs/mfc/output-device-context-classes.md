---
title: Classes de saída (contexto do dispositivo)
ms.date: 11/04/2016
f1_keywords:
- vc.classes.output
helpviewer_keywords:
- device contexts [MFC], classes
- screen output classes [MFC]
- printing classes [MFC]
- window drawing classes [MFC]
- painting classes [MFC]
- output classes [MFC]
ms.assetid: 35fd6435-a38e-42c6-a3fa-cd6f39370fc3
ms.openlocfilehash: 1d76570e7bfd4ce587b3803235394ec5406d30b2
ms.sourcegitcommit: c3093251193944840e3d0a068ecc30e6449624ba
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/04/2019
ms.locfileid: "57266647"
---
# <a name="output-device-context-classes"></a>Classes de saída (contexto do dispositivo)

Essas classes encapsulam os diferentes tipos de contextos de dispositivo disponíveis no Windows.

A maioria das seguintes classes encapsula um identificador para um contexto de dispositivo do Windows. Um contexto de dispositivo é um objeto do Windows que contém informações sobre os atributos de desenho de um dispositivo, como uma exibição ou uma impressora. Todas as chamadas de desenho são feitas por meio de um objeto de contexto de dispositivo. As classes adicionais derivadas `CDC` encapsulam funcionalidades especializadas de contexto de dispositivo, incluindo suporte para metarquivos do Windows.

[CDC](../mfc/reference/cdc-class.md)<br/>
A classe base para contextos de dispositivo. Usados diretamente para acessar a exibição inteira e para acessar os contextos de nondisplay, como impressoras.

[CPaintDC](../mfc/reference/cpaintdc-class.md)<br/>
Um contexto de exibição usado em `OnPaint` funções de membro do windows. Automaticamente chama `BeginPaint` na construção e `EndPaint` na destruição.

[CClientDC](../mfc/reference/cclientdc-class.md)<br/>
Um contexto de exibição para áreas de cliente do windows. Usado, por exemplo, para desenhar em uma resposta imediata para eventos de mouse.

[CWindowDC](../mfc/reference/cwindowdc-class.md)<br/>
Um contexto de exibição para o windows inteiro, incluindo áreas cliente e não cliente.

[CMetaFileDC](../mfc/reference/cmetafiledc-class.md)<br/>
Um contexto de dispositivo para metarquivos do Windows. Um metarquivo do Windows contém uma sequência de comandos de interface (GDI) do dispositivo de gráficos que podem ser reproduzidos para criar uma imagem. Chamadas feitas para as funções de membro de um `CMetaFileDC` são registradas em um metarquivo.

## <a name="related-classes"></a>Classes relacionadas

[CPoint](../atl-mfc-shared/reference/cpoint-class.md)<br/>
Contém pares de coordenadas (x, y).

[CSize](../atl-mfc-shared/reference/csize-class.md)<br/>
Mantém a distância, posições relativas ou valores de pares.

[CRect](../atl-mfc-shared/reference/crect-class.md)<br/>
Contém as coordenadas das áreas retangulares.

[CRgn](../mfc/reference/crgn-class.md)<br/>
Encapsula uma região GDI para manipular uma área irregular, elíptica ou poligonal dentro de uma janela. Usado em conjunto com as funções de membro de recorte na classe `CDC`.

[CRectTracker](../mfc/reference/crecttracker-class.md)<br/>
Exibe e manipula a interface do usuário para redimensionar e mover objetos retangulares.

[CColorDialog](../mfc/reference/ccolordialog-class.md)<br/>
Fornece uma caixa de diálogo padrão para selecionar uma cor.

[CFontDialog](../mfc/reference/cfontdialog-class.md)<br/>
Fornece uma caixa de diálogo padrão para selecionar uma fonte.

[CPrintDialog](../mfc/reference/cprintdialog-class.md)<br/>
Fornece uma caixa de diálogo padrão para imprimir um arquivo.

## <a name="see-also"></a>Consulte também

[Visão geral da classe](../mfc/class-library-overview.md)
