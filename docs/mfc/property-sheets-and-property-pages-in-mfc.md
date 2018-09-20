---
title: Folhas de propriedades e páginas de propriedade no MFC | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-mfc
ms.topic: conceptual
dev_langs:
- C++
helpviewer_keywords:
- property pages [MFC], MFC
- controls [MFC], property sheets
- property sheets, MFC
- tab dialog boxes
ms.assetid: e1bede2b-0285-4b88-a052-0f8a372807a2
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: f35282ce46aff3a3f0fba5fca505653cd892a392
ms.sourcegitcommit: 799f9b976623a375203ad8b2ad5147bd6a2212f0
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/19/2018
ms.locfileid: "46430027"
---
# <a name="property-sheets-and-property-pages-in-mfc"></a>Folhas de propriedades e páginas de propriedade em MFC

Uma folha de propriedades, também conhecido como uma caixa de diálogo de guia, é uma caixa de diálogo que contém as páginas de propriedades. Cada página de propriedades se baseia em um recurso de modelo de caixa de diálogo e contém controles. Ele é colocado em uma página com uma guia na parte superior. Na guia nomeia a página e indica sua finalidade. Os usuários clicam uma guia na folha de propriedades para selecionar um conjunto de controles.

Use as páginas para agrupar os controles na folha de propriedades em conjuntos significativos. A folha de propriedades independente normalmente tem vários controles de seu próprio. Isso se aplica a todas as páginas.

Folhas de propriedade são com base na classe [CPropertySheet](../mfc/reference/cpropertysheet-class.md). Páginas de propriedades são com base na classe [CPropertyPage](../mfc/reference/cpropertypage-class.md).

Uma folha de propriedades é um tipo especial de caixa de diálogo que é geralmente usado para modificar os atributos de um objeto externo, como a seleção atual em uma exibição. A folha de propriedades tem três partes principais: páginas de propriedade de um ou mais de caixa de diálogo que contém um mostrado de cada vez e uma guia na parte superior de cada página que o usuário clica para selecionar a página. Folhas de propriedades são úteis para situações em que você tem vários grupos semelhantes de configurações ou opções para alterar. Informações de grupos de uma folha de propriedades de uma maneira fácil de entender.

> [!NOTE]
>  Quando você está tentando mostrar uma folha de propriedades usando `CPropertySheet::DoModal`, o sistema pode gerar uma exceção de primeira chance. Essa exceção ocorre porque o sistema está tentando alterar o [estilos de janela](../mfc/reference/styles-used-by-mfc.md#window-styles) do objeto antes do objeto foi criado. Para obter mais informações sobre essa exceção e como evitá-lo ou manipulá-lo, consulte [CPropertySheet::DoModal](../mfc/reference/cpropertysheet-class.md#domodal).

## <a name="see-also"></a>Consulte também

[Folhas de propriedades](../mfc/property-sheets-mfc.md)

