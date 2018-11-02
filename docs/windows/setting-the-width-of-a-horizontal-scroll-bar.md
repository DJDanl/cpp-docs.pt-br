---
title: Definindo a largura de uma barra de rolagem horizontal
ms.date: 11/04/2016
helpviewer_keywords:
- list controls [C++], scroll bar width
- CListBox::SetHorizontalExtent
- controls [C++], scroll bar
- scroll bars [C++], displaying in controls
- horizontal scroll bar width
- CListBox class, scroll bar width
- scroll bars [C++], width
ms.assetid: 51dad141-aa0b-46a3-a82c-46b80d603d94
ms.openlocfilehash: 393571b79d27485e840d150549208c899e8ed1d2
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50625947"
---
# <a name="setting-the-width-of-a-horizontal-scroll-bar"></a>Definindo a largura de uma barra de rolagem horizontal

Quando você adiciona uma caixa de listagem com uma barra de rolagem horizontal para uma caixa de diálogo usando classes do MFC, a barra de rolagem não aparecerá automaticamente no seu aplicativo.

### <a name="to-make-the-scroll-bar-appear"></a>Para tornar o aparecem da barra de rolagem

1. Definir uma largura máxima para o maior elemento chamando [CListBox::SetHorizontalExtent](../mfc/reference/clistbox-class.md#sethorizontalextent) em seu código.

   Sem este conjunto de valores, a barra de rolagem não aparecerá, até mesmo quando os itens na caixa de listagem são mais largas do que a caixa.

Para obter informações sobre como adicionar recursos a projetos gerenciados, consulte [recursos em aplicativos de área de trabalho](/dotnet/framework/resources/index) na *guia do desenvolvedor do .NET Framework*. Para obter informações sobre como adicionar manualmente os arquivos de recursos a projetos gerenciados, acessar recursos, exibir recursos estáticos e atribuir cadeias de caracteres de recurso a propriedades, consulte [criando arquivos de recursos para aplicativos de área de trabalho](/dotnet/framework/resources/creating-resource-files-for-desktop-apps). Para obter informações sobre globalização e localização de recursos em aplicativos gerenciados, consulte [Globalizing e Localizando aplicativos do .NET Framework](/dotnet/standard/globalization-localization/index).

## <a name="requirements"></a>Requisitos

MFC

## <a name="see-also"></a>Consulte também

[Controles em caixas de diálogo](../windows/controls-in-dialog-boxes.md)<br/>
[Controles](../mfc/controls-mfc.md)