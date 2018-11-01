---
title: Folhas de propriedades e páginas de propriedade (MFC)
ms.date: 11/04/2016
helpviewer_keywords:
- MFC dialog boxes [MFC], tabs
- property pages [MFC], property sheets
- CPropertyPage class [MFC], property sheets and pages
- CPropertySheet class [MFC], property sheets and pages
- property sheets, propert pages
ms.assetid: de8fea12-6c35-4cef-8625-b8073a379446
ms.openlocfilehash: 971b8cde1560e54f87269e8b85a41cdec55c091d
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50445390"
---
# <a name="property-sheets-and-property-pages-mfc"></a>Folhas de propriedades e páginas de propriedade (MFC)

Um MFC [caixa de diálogo](../mfc/dialog-boxes.md) pode levar uma aparência "guia de caixa de diálogo" incorporando as folhas de propriedades e páginas de propriedades. Esse tipo de caixa de diálogo semelhante a muitas caixas de diálogo no Microsoft Word, Excel e Visual C++, chamado "folha de propriedades" no MFC, parece conter uma pilha de folhas com guias, assim como uma pilha de pastas de arquivos visto de frente para trás, ou um grupo de janelas em cascata. Controles da guia frontal são visíveis; somente a guia rotulada está visível nas guias traseiras. Folhas de propriedade são particularmente úteis para gerenciar grandes números de propriedades ou configurações que se enquadram bem organizado em vários grupos. Normalmente, uma folha de propriedades pode simplificar uma interface do usuário, substituindo várias caixas de diálogo separadas.

A partir do MFC versão 4.0, folhas de propriedades e páginas de propriedade são implementadas usando controles comuns que vêm com a versão do Windows 95 e Windows NT 3.51 e posterior.

Folhas de propriedades são implementadas com classes [CPropertySheet](../mfc/reference/cpropertysheet-class.md) e [CPropertyPage](../mfc/reference/cpropertypage-class.md) (descrito o *referência da MFC*). `CPropertySheet` Define a caixa de diálogo geral, que pode conter várias "páginas" com base em `CPropertyPage`.

Para obter informações sobre como criar e trabalhar com folhas de propriedades, consulte o tópico [folhas de propriedade](../mfc/property-sheets-mfc.md).

## <a name="see-also"></a>Consulte também

[Caixas de diálogo](../mfc/dialog-boxes.md)<br/>
[Ciclo de vida de uma caixa de diálogo](../mfc/life-cycle-of-a-dialog-box.md)<br/>
[Folhas de propriedades e páginas de propriedade no MFC](../mfc/property-sheets-and-property-pages-in-mfc.md)<br/>
[Trocando dados](../mfc/exchanging-data.md)<br/>
[Criando uma folha de propriedades sem janela restrita](../mfc/creating-a-modeless-property-sheet.md)<br/>
[Tratando o botão Aplicar](../mfc/handling-the-apply-button.md)

