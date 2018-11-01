---
title: Como adicionar controles de faixa de opções e manipuladores de evento
ms.date: 11/04/2016
helpviewer_keywords:
- event handlers [MFC], adding
- ribbon controls [MFC], adding
ms.assetid: b31f25bc-ede7-49c3-9e3c-dffe4e174a69
ms.openlocfilehash: 7f5b85fad181dba147c2135784d237bccdceb422
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50637990"
---
# <a name="how-to-add-ribbon-controls-and-event-handlers"></a>Como adicionar controles de faixa de opções e manipuladores de evento

Controles da faixa de opções são elementos como botões e caixas de combinação, que você adiciona aos painéis. Painéis são áreas da barra de faixa de opções que exibem um grupo de controles relacionados.

Neste tópico, abra o Designer de faixa de opções, adicione um botão e, em seguida, vincule um evento que exibe "Hello World".

### <a name="to-open-the-ribbon-designer"></a>Para abrir o Designer de faixa de opções

1. No Visual Studio, sobre o **modo de exibição** menu, clique em **exibição de recurso**.

1. Na **exibição de recurso**, clique duas vezes no recurso de faixa de opções para exibi-lo na superfície de design.

### <a name="to-add-a-button-and-an-event-handler"></a>Para adicionar um botão e um manipulador de eventos

1. Dos **barra de ferramentas**, clique em **botão** e arraste-o para um painel na superfície de design.

1. Clique no botão e, em seguida, clique em **Adicionar manipulador de eventos**.

1. No **Assistente de manipulador de eventos**, confirme as configurações padrão e clique em **adicionar e editar**. Para obter mais informações, consulte [Assistente de manipulador de eventos](../ide/event-handler-wizard.md).

1. No editor de códigos, adicione o seguinte código para a função de manipulador:

```
    MessageBox((LPCTSTR)L"Hello World");

```

## <a name="see-also"></a>Consulte também

[Exemplo de gadget de fita: Aplicativo de gadget de faixa de opções](../visual-cpp-samples.md)<br/>
[Designer da faixa de opções (MFC)](../mfc/ribbon-designer-mfc.md)

