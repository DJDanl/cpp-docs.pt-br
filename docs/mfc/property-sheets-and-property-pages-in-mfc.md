---
title: Folhas de propriedades e páginas de propriedade em MFC
ms.date: 11/04/2016
helpviewer_keywords:
- property pages [MFC], MFC
- controls [MFC], property sheets
- property sheets, MFC
- tab dialog boxes
ms.assetid: e1bede2b-0285-4b88-a052-0f8a372807a2
ms.openlocfilehash: 10fb34c79745e672d30dd2d3c3b97d457583f795
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81371177"
---
# <a name="property-sheets-and-property-pages-in-mfc"></a>Folhas de propriedades e páginas de propriedade em MFC

Uma folha de propriedade, também conhecida como caixa de diálogo de guia, é uma caixa de diálogo que contém páginas de propriedade. Cada página de propriedade é baseada em um recurso de modelo de diálogo e contém controles. Ele está incluído em uma página com uma guia em cima. A guia nomeia a página e indica seu propósito. Os usuários clicam em uma guia na folha de propriedades para selecionar um conjunto de controles.

Use páginas para agrupar os controles na folha de propriedades em conjuntos significativos. A folha de propriedade contida normalmente tem vários controles próprios. Estes se aplicam a todas as páginas.

As folhas de propriedade são baseadas na classe [CPropertySheet](../mfc/reference/cpropertysheet-class.md). As páginas de propriedade são baseadas na classe [CPropertyPage](../mfc/reference/cpropertypage-class.md).

Uma folha de propriedades é um tipo especial de caixa de diálogo que geralmente é usada para modificar os atributos de algum objeto externo, como a seleção atual em uma exibição. A folha de propriedades tem três partes principais: a caixa de diálogo contendo, uma ou mais páginas de propriedade mostradas uma de cada vez e uma guia na parte superior de cada página que o usuário clica para selecionar essa página. As folhas de propriedade são úteis para situações em que você tem vários grupos semelhantes de configurações ou opções para alterar. Uma folha de propriedade agrupa informações de forma fácil de entender.

> [!NOTE]
> Quando você está tentando mostrar uma `CPropertySheet::DoModal`folha de propriedade usando, o sistema pode gerar uma exceção de primeira chance. Essa exceção ocorre porque o sistema está tentando alterar os Estilos de [janela](../mfc/reference/styles-used-by-mfc.md#window-styles) do objeto antes que o objeto tenha sido criado. Para obter mais informações sobre essa exceção e também como evitá-la ou manuseá-la, consulte [CPropertySheet::DoModal](../mfc/reference/cpropertysheet-class.md#domodal).

## <a name="see-also"></a>Confira também

[Folhas de propriedades](../mfc/property-sheets-mfc.md)
