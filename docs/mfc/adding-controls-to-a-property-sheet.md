---
title: Adicionando controles a uma folha de propriedades
ms.date: 11/04/2016
helpviewer_keywords:
- controls [MFC], adding to property sheets
- property sheets, adding controls
ms.assetid: 24ad4c0b-c1db-4850-b9f0-34aae8d74571
ms.openlocfilehash: 527c0a5ef6e9dc4fcc9d7668c12e15ec956b0e70
ms.sourcegitcommit: c21b05042debc97d14875e019ee9d698691ffc0b
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 06/09/2020
ms.locfileid: "84616068"
---
# <a name="adding-controls-to-a-property-sheet"></a>Adicionando controles a uma folha de propriedades

Por padrão, uma folha de propriedades aloca a área da janela para as páginas de propriedades, o índice de guias e os botões OK, cancelar e aplicar. (Uma folha de propriedades sem janela restrita não tem os botões OK, cancelar e aplicar.) Você pode adicionar outros controles à folha de propriedades. Por exemplo, você pode adicionar uma janela de visualização à direita da área da página de propriedades para mostrar ao usuário a aparência das configurações atuais, se aplicadas a um objeto externo.

Você pode adicionar controles à caixa de diálogo da folha de propriedades no `OnCreate` manipulador. Acomodar controles adicionais geralmente requer a expansão do tamanho da caixa de diálogo da folha de propriedades. Depois de chamar a classe base **CPropertySheet:: OnCreate**, chame [GetWindowRect](reference/cwnd-class.md#getwindowrect) para obter a largura e a altura da janela da folha de propriedades alocada no momento, expanda as dimensões do retângulo e chame [MoveWindow](reference/cwnd-class.md#movewindow) para alterar o tamanho da janela da folha de propriedades.

## <a name="see-also"></a>Consulte também

[Folhas de propriedades](property-sheets-mfc.md)<br/>
[Classe CPropertyPage](reference/cpropertypage-class.md)<br/>
[Classe CPropertySheet](reference/cpropertysheet-class.md)
