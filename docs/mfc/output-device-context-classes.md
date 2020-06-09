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
ms.openlocfilehash: b15f5034604f9d6b67574288140b79b144692478
ms.sourcegitcommit: c21b05042debc97d14875e019ee9d698691ffc0b
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 06/09/2020
ms.locfileid: "84615355"
---
# <a name="output-device-context-classes"></a>Classes de saída (contexto do dispositivo)

Essas classes encapsulam os diferentes tipos de contextos de dispositivo disponíveis no Windows.

A maioria das classes a seguir encapsula um identificador para um contexto de dispositivo do Windows. Um contexto de dispositivo é um objeto do Windows que contém informações sobre os atributos de desenho de um dispositivo, como uma exibição ou uma impressora. Todas as chamadas de desenho são feitas por meio de um objeto de contexto de dispositivo. Classes adicionais derivadas do `CDC` encapsulamento de funcionalidade de contexto de dispositivo especializada, incluindo suporte para metaarquivos do Windows.

[CDC](reference/cdc-class.md)<br/>
A classe base para contextos de dispositivo. Usado diretamente para acessar a exibição inteira e para acessar contextos não exibidos, como impressoras.

[CPaintDC](reference/cpaintdc-class.md)<br/>
Um contexto de exibição usado em `OnPaint` funções de membro do Windows. Chama automaticamente a `BeginPaint` construção e a `EndPaint` destruição.

[CClientDC](reference/cclientdc-class.md)<br/>
Um contexto de exibição para áreas de cliente do Windows. Usado, por exemplo, para desenhar em uma resposta imediata para eventos do mouse.

[CWindowDC](reference/cwindowdc-class.md)<br/>
Um contexto de exibição para todo o Windows, incluindo as áreas cliente e não cliente.

[CMetaFileDC](reference/cmetafiledc-class.md)<br/>
Um contexto de dispositivo para os metaarquivos do Windows. Um metarquivo do Windows contém uma sequência de comandos de interface de dispositivo de gráficos (GDI) que podem ser reproduzidos para criar uma imagem. As chamadas feitas às funções de membro de um `CMetaFileDC` são registradas em um metarquivo.

## <a name="related-classes"></a>Classes relacionadas

[CPoint](../atl-mfc-shared/reference/cpoint-class.md)<br/>
Mantém pares de coordenadas (x, y).

[CSize](../atl-mfc-shared/reference/csize-class.md)<br/>
Mantém a distância, as posições relativas ou os valores emparelhados.

[CRect](../atl-mfc-shared/reference/crect-class.md)<br/>
Mantém as coordenadas de áreas retangulares.

[CRgn](reference/crgn-class.md)<br/>
Encapsula uma região GDI para manipular uma área elíptica, poligonal ou irregular dentro de uma janela. Usado em conjunto com as funções de membro de recorte na classe `CDC` .

[CRectTracker](reference/crecttracker-class.md)<br/>
Exibe e manipula a interface do usuário para redimensionar e mover objetos retangulares.

[CColorDialog](reference/ccolordialog-class.md)<br/>
Fornece uma caixa de diálogo padrão para selecionar uma cor.

[CFontDialog](reference/cfontdialog-class.md)<br/>
Fornece uma caixa de diálogo padrão para selecionar uma fonte.

[CPrintDialog](reference/cprintdialog-class.md)<br/>
Fornece uma caixa de diálogo padrão para imprimir um arquivo.

## <a name="see-also"></a>Consulte também

[Visão geral da classe](class-library-overview.md)
