---
title: Como adicionar controles de faixa de opções e manipuladores de evento
ms.date: 11/04/2016
helpviewer_keywords:
- event handlers [MFC], adding
- ribbon controls [MFC], adding
ms.assetid: b31f25bc-ede7-49c3-9e3c-dffe4e174a69
ms.openlocfilehash: 560524c36dbf57faec3b4b6372cade047f9fe7de
ms.sourcegitcommit: c21b05042debc97d14875e019ee9d698691ffc0b
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 06/09/2020
ms.locfileid: "84618477"
---
# <a name="how-to-add-ribbon-controls-and-event-handlers"></a>Como adicionar controles de faixa de opções e manipuladores de evento

Os controles da faixa de faixas são elementos, como botões e caixas de combinação, que você adiciona aos painéis. Painéis são áreas da barra da faixa de faixas que exibem um grupo de controles relacionados.

Neste tópico, você abrirá o designer de faixa de faixas, adicionará um botão e, em seguida, vinculará um evento que exibe "Olá, Mundo".

### <a name="to-open-the-ribbon-designer"></a>Para abrir o designer de faixa de uma

1. No Visual Studio, no menu **Exibir** , clique em **modo de exibição de recursos**.

1. Em **modo de exibição de recursos**, clique duas vezes no recurso da faixa de bits para exibi-lo na superfície de design.

### <a name="to-add-a-button-and-an-event-handler"></a>Para adicionar um botão e um manipulador de eventos

1. Na **barra de ferramentas**, clique no **botão** e arraste-o para um painel na superfície de design.

1. Clique com o botão direito do mouse no botão e clique em **Adicionar manipulador de eventos**.

1. No **Assistente de manipulador de eventos**, confirme as configurações padrão e clique em **Adicionar e editar**. Para obter mais informações, consulte [Assistente de manipulador de eventos](../ide/event-handler-wizard.md).

1. No editor de código, adicione o seguinte código à função de manipulador:

```
    MessageBox((LPCTSTR)L"Hello World");
```

## <a name="see-also"></a>Consulte também

[Exemplo de RibbonGadgets: aplicativo de gadgets de faixa de faixas](../overview/visual-cpp-samples.md)<br/>
[Designer de faixa de Ribbon (MFC)](ribbon-designer-mfc.md)
