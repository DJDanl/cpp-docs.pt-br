---
title: Folhas de propriedades e páginas de propriedade (MFC) | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-mfc
ms.topic: conceptual
dev_langs:
- C++
helpviewer_keywords:
- MFC dialog boxes [MFC], tabs
- property pages [MFC], property sheets
- CPropertyPage class [MFC], property sheets and pages
- CPropertySheet class [MFC], property sheets and pages
- property sheets, propert pages
ms.assetid: de8fea12-6c35-4cef-8625-b8073a379446
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 882b2d93ba7938017f64b1ad8fb8e680e0af42db
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
ms.locfileid: "33348976"
---
# <a name="property-sheets-and-property-pages-mfc"></a>Folhas de propriedades e páginas de propriedade (MFC)
Um MFC [caixa de diálogo](../mfc/dialog-boxes.md) pode levar uma aparência "caixa de diálogo de guia" incorporando folhas de propriedades e páginas de propriedade. Esse tipo de caixa de diálogo semelhante a várias caixas de diálogo no Microsoft Word, Excel e Visual C++, chamado "folha de propriedades" no MFC, parece conter uma pilha de folhas com guias, bem como uma pilha de pastas de arquivos visto de frente para trás, ou um grupo de janelas em cascata. Controles da guia front são visíveis; somente a guia rotulada está visível nas guias traseiras. Folhas de propriedades são particularmente úteis para o gerenciamento de grandes números de propriedades ou configurações que se enquadram bem se vários grupos. Normalmente, uma folha de propriedades pode simplificar uma interface do usuário, substituindo várias caixas de diálogo separada.  
  
 A partir da versão 4.0 do MFC, folhas de propriedades e páginas de propriedade são implementadas usando os controles comuns fornecidos com a versão do Windows 95 e Windows NT 3.51 e posterior.  
  
 Folhas de propriedades são implementadas com classes [CPropertySheet](../mfc/reference/cpropertysheet-class.md) e [CPropertyPage](../mfc/reference/cpropertypage-class.md) (descrito o *referência MFC*). `CPropertySheet` Define a caixa de diálogo geral, que pode conter várias "páginas" com base em `CPropertyPage`.  
  
 Para obter informações sobre como criar e trabalhar com folhas de propriedades, consulte o tópico [folhas de propriedade](../mfc/property-sheets-mfc.md).  
  
## <a name="see-also"></a>Consulte também  
 [Caixas de diálogo](../mfc/dialog-boxes.md)   
 [Ciclo de vida de uma caixa de diálogo](../mfc/life-cycle-of-a-dialog-box.md)   
 [Folhas de propriedades e páginas de propriedade em MFC](../mfc/property-sheets-and-property-pages-in-mfc.md)   
 [Troca de dados](../mfc/exchanging-data.md)   
 [Criando uma folha de propriedades sem janela restrita](../mfc/creating-a-modeless-property-sheet.md)   
 [Tratando o botão Aplicar](../mfc/handling-the-apply-button.md)

