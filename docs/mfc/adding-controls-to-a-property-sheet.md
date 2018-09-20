---
title: Adicionando controles a uma folha de propriedades | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-mfc
ms.topic: conceptual
dev_langs:
- C++
helpviewer_keywords:
- controls [MFC], adding to property sheets
- property sheets, adding controls
ms.assetid: 24ad4c0b-c1db-4850-b9f0-34aae8d74571
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 0783571ed77d3d8dfaca69edf06330e62d8e98d0
ms.sourcegitcommit: 799f9b976623a375203ad8b2ad5147bd6a2212f0
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/19/2018
ms.locfileid: "46398480"
---
# <a name="adding-controls-to-a-property-sheet"></a>Adicionando controles a uma folha de propriedades

Por padrão, uma folha de propriedades aloca a área da janela para as páginas de propriedades, o índice de tabulação e os botões Okey, cancelar e aplicar. (Uma folha de propriedades sem janela restrita não tem Okey, cancelar e aplicar botões.) Você pode adicionar outros controles para a folha de propriedades. Por exemplo, você pode adicionar uma janela de visualização para a direita da área da página de propriedade para mostrar ao usuário como as configurações atuais ficaria se aplicado a um objeto externo.

Você pode adicionar controles para a caixa de diálogo de folha de propriedade no `OnCreate` manipulador. Acomodar controles adicionais geralmente requer a expansão do tamanho da caixa de diálogo de folha de propriedade. Depois de chamar a classe base **CPropertySheet::OnCreate**, chame [GetWindowRect](../mfc/reference/cwnd-class.md#getwindowrect) para obter a largura e altura da janela de folha de propriedade atualmente alocados, expanda o retângulo dimensões e chamada [MoveWindow](../mfc/reference/cwnd-class.md#movewindow) para alterar o tamanho da janela de folha de propriedade.

## <a name="see-also"></a>Consulte também

[Folhas de propriedades](../mfc/property-sheets-mfc.md)<br/>
[Classe CPropertyPage](../mfc/reference/cpropertypage-class.md)<br/>
[Classe CPropertySheet](../mfc/reference/cpropertysheet-class.md)
