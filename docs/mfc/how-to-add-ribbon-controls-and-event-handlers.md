---
title: 'Como: Adicionar controles de faixa de opções e manipuladores de eventos'
ms.date: 11/04/2016
helpviewer_keywords:
- event handlers [MFC], adding
- ribbon controls [MFC], adding
ms.assetid: b31f25bc-ede7-49c3-9e3c-dffe4e174a69
ms.openlocfilehash: c21e8b86962ebf37ca1a06bae056d09b9a9dbb2f
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62389509"
---
# <a name="how-to-add-ribbon-controls-and-event-handlers"></a>Como: Adicionar controles de faixa de opções e manipuladores de eventos

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

[Exemplo de gadget de fita: Aplicativo de gadget de faixa de opções](../overview/visual-cpp-samples.md)<br/>
[Designer da faixa de opções (MFC)](../mfc/ribbon-designer-mfc.md)
