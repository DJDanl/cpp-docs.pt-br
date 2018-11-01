---
title: Adicionando controles a uma folha de propriedades
ms.date: 11/04/2016
helpviewer_keywords:
- controls [MFC], adding to property sheets
- property sheets, adding controls
ms.assetid: 24ad4c0b-c1db-4850-b9f0-34aae8d74571
ms.openlocfilehash: 141339bd146fec20f02e73e24bb9dae387f4e3ed
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50502772"
---
# <a name="adding-controls-to-a-property-sheet"></a>Adicionando controles a uma folha de propriedades

Por padrão, uma folha de propriedades aloca a área da janela para as páginas de propriedades, o índice de tabulação e os botões Okey, cancelar e aplicar. (Uma folha de propriedades sem janela restrita não tem Okey, cancelar e aplicar botões.) Você pode adicionar outros controles para a folha de propriedades. Por exemplo, você pode adicionar uma janela de visualização para a direita da área da página de propriedade para mostrar ao usuário como as configurações atuais ficaria se aplicado a um objeto externo.

Você pode adicionar controles para a caixa de diálogo de folha de propriedade no `OnCreate` manipulador. Acomodar controles adicionais geralmente requer a expansão do tamanho da caixa de diálogo de folha de propriedade. Depois de chamar a classe base **CPropertySheet::OnCreate**, chame [GetWindowRect](../mfc/reference/cwnd-class.md#getwindowrect) para obter a largura e altura da janela de folha de propriedade atualmente alocados, expanda o retângulo dimensões e chamada [MoveWindow](../mfc/reference/cwnd-class.md#movewindow) para alterar o tamanho da janela de folha de propriedade.

## <a name="see-also"></a>Consulte também

[Folhas de propriedades](../mfc/property-sheets-mfc.md)<br/>
[Classe CPropertyPage](../mfc/reference/cpropertypage-class.md)<br/>
[Classe CPropertySheet](../mfc/reference/cpropertysheet-class.md)
