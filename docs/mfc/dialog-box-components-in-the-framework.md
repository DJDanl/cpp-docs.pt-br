---
title: Componentes da caixa de diálogo no Framework
ms.date: 11/04/2016
helpviewer_keywords:
- MFC dialog boxes [MFC], creating
- dialog classes [MFC], dialog box components
- MFC dialog boxes [MFC], about MFC dialog boxes
- dialog templates [MFC], MFC framework
- MFC dialog boxes [MFC], dialog resource
ms.assetid: 592db160-0a8a-49be-ac72-ead278aca53f
ms.openlocfilehash: b3290107337f60854e6abbd2f744aaa38af0b741
ms.sourcegitcommit: c21b05042debc97d14875e019ee9d698691ffc0b
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 06/09/2020
ms.locfileid: "84616920"
---
# <a name="dialog-box-components-in-the-framework"></a>Componentes da caixa de diálogo no Framework

Na estrutura do MFC, uma caixa de diálogo tem dois componentes:

- Um recurso de modelo de diálogo que especifica os controles da caixa de diálogo e seu posicionamento.

   O recurso de caixa de diálogo armazena um modelo de caixa de diálogo do qual o Windows cria a janela de diálogo e a exibe. O modelo especifica as características da caixa de diálogo, incluindo o tamanho, o local, o estilo e os tipos e as posições dos controles da caixa de diálogo. Normalmente, você usará um modelo de caixa de diálogo armazenado como um recurso, mas também poderá criar seu próprio modelo na memória.

- Uma classe de caixa de diálogo, derivada de [CDialog](reference/cdialog-class.md), para fornecer uma interface programática para gerenciar a caixa de diálogo.

   Uma caixa de diálogo é uma janela e será anexada a uma janela do Windows quando visível. Quando a janela de diálogo é criada, o recurso de modelo de caixa de diálogo é usado como um modelo para criar controles de janela filho para a caixa de diálogo.

## <a name="see-also"></a>Consulte também

[Caixas de diálogo](dialog-boxes.md)<br/>
[Trabalhar com caixas de diálogo no MFC](life-cycle-of-a-dialog-box.md)
