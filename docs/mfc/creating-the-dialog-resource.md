---
title: Criando o recurso da caixa de diálogo
ms.date: 11/04/2016
helpviewer_keywords:
- dialog resources
- MFC dialog boxes [MFC], creating
- dialog templates [MFC], creating dialog resource
- templates [MFC], creating
- resources [MFC], creating dialog boxes
- MFC dialog boxes [MFC], dialog resource
ms.assetid: 0b83bd33-14d3-4611-8129-fccdae18053e
ms.openlocfilehash: efaef11cfdc036a201ced3357ca81b37a5dc29db
ms.sourcegitcommit: c21b05042debc97d14875e019ee9d698691ffc0b
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 06/09/2020
ms.locfileid: "84619620"
---
# <a name="creating-the-dialog-resource"></a>Criando o recurso da caixa de diálogo

Para projetar a [caixa de diálogo](dialog-boxes.md) e criar o recurso de diálogo, use o [Editor de caixa de diálogo](../windows/dialog-editor.md). No editor de caixa de diálogo, você pode:

- Ajuste o tamanho e o local que a caixa de diálogo terá quando for exibida.

- Arraste vários tipos de controles de uma paleta de controles e solte-os onde desejar na caixa de diálogo.

- Posicione os controles com botões de alinhamento na barra de ferramentas.

- Teste sua caixa de diálogo simulando a aparência e o comportamento que ela terá em seu programa. No modo de teste, você pode manipular os controles da caixa de diálogo digitando texto em caixas de texto, clicando em cliques e assim por diante.

Quando você terminar, o recurso de modelo de caixa de diálogo será armazenado no arquivo de script de recurso do aplicativo. Você pode editá-lo mais tarde, se necessário. Para obter uma descrição completa de como criar e editar recursos de caixa de diálogo, consulte os tópicos do [Editor de caixa de diálogo](../windows/dialog-editor.md) . Essa técnica também é usada para criar os recursos de modelo de caixa de diálogo para as classes [CFormView](reference/cformview-class.md) e [CRecordView](reference/crecordview-class.md) .

Quando a aparência da caixa de diálogo for adequada a você, crie uma classe de caixa de diálogo e mapeie suas mensagens, conforme discutido na [criação de uma classe de caixa de diálogo com assistentes de código](creating-a-dialog-class-with-code-wizards.md).

## <a name="see-also"></a>Consulte também

[Caixas de diálogo](dialog-boxes.md)<br/>
[Trabalhar com caixas de diálogo no MFC](life-cycle-of-a-dialog-box.md)
