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
ms.openlocfilehash: 5d4fd1c957b7f4d0d6ad10379a448309743aa11a
ms.sourcegitcommit: 1e6386be9084f70def7b3b8b4bab319a117102b2
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/30/2019
ms.locfileid: "71685079"
---
# <a name="property-sheets-and-property-pages-mfc"></a>Folhas de propriedades e páginas de propriedade (MFC)

Uma [caixa de diálogo](../mfc/dialog-boxes.md) MFC pode assumir uma aparência de "guia de diálogo" incorporando folhas de propriedades e páginas de propriedades. Chamado de "folha de propriedades" no MFC, esse tipo de caixa de diálogo, semelhante a muitas caixas de diálogo no Microsoft Word, Excel C++e Visual, parece conter uma pilha de planilhas com guias, muito como uma pilha de pastas de arquivos vista de frente para trás ou de um grupo de janelas em cascata. Os controles na guia frontal são visíveis; somente a guia rotulada é visível nas guias traseiras. As folhas de propriedades são particularmente úteis para gerenciar grandes números de propriedades ou configurações que se enquadram razoavelmente em vários grupos. Normalmente, uma folha de propriedades pode simplificar uma interface do usuário substituindo várias caixas de diálogo separadas.

A partir da versão 4,0 do MFC, as folhas de propriedades e as páginas de propriedades são implementadas usando os controles comuns fornecidos com o Windows 95 e o Windows NT versão 3,51 e posteriores.

As folhas de propriedades são implementadas com classes [CPropertySheet](../mfc/reference/cpropertysheet-class.md) e [CPropertyPage](../mfc/reference/cpropertypage-class.md) (descritas na *referência do MFC*). `CPropertySheet` define a caixa de diálogo geral, que pode conter várias "páginas" com base em `CPropertyPage`.

Para obter informações sobre como criar e trabalhar com folhas de propriedades, consulte o tópico [folhas de propriedades](../mfc/property-sheets-mfc.md).

## <a name="see-also"></a>Consulte também

[Caixas de diálogo](../mfc/dialog-boxes.md)<br/>
[Trabalhando com caixas de diálogo no MFC](../mfc/life-cycle-of-a-dialog-box.md)<br/>
[Folhas de propriedades e páginas de propriedade no MFC](../mfc/property-sheets-and-property-pages-in-mfc.md)<br/>
[Trocando dados](../mfc/exchanging-data.md)<br/>
[Criando uma folha de propriedades sem janela restrita](../mfc/creating-a-modeless-property-sheet.md)<br/>
[Tratando o botão Aplicar](../mfc/handling-the-apply-button.md)
