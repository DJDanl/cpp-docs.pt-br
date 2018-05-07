---
title: 'Como: adicionar controles de faixa de opções e manipuladores de eventos | Microsoft Docs'
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-mfc
ms.topic: conceptual
dev_langs:
- C++
helpviewer_keywords:
- event handlers [MFC], adding
- ribbon controls [MFC], adding
ms.assetid: b31f25bc-ede7-49c3-9e3c-dffe4e174a69
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 176323137b2ace0d27d9de162da7fa022441aa88
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
---
# <a name="how-to-add-ribbon-controls-and-event-handlers"></a>Como adicionar controles de faixa de opções e manipuladores de evento
Controles de faixa de opções são elementos, como botões e caixas de combinação, o que você adicionar a painéis. Painéis são áreas da barra de faixa de opções que exibem um grupo de controles relacionados.  
  
 Neste tópico, abra o Designer de faixa de opções, adicione um botão e, em seguida, vincular um evento que exibe "Hello World".  
  
### <a name="to-open-the-ribbon-designer"></a>Para abrir o Designer de faixa de opções  
  
1.  No Visual Studio, no **exibição** menu, clique em **exibição recursos**.  
  
2.  Em **exibição recursos**, clique duas vezes o recurso de faixa de opções para exibi-lo na superfície de design.  
  
### <a name="to-add-a-button-and-an-event-handler"></a>Para adicionar um botão e um manipulador de eventos  
  
1.  Do **barra de ferramentas**, clique em **botão** e arraste-o para um painel na superfície de design.  
  
2.  Clique no botão e, em seguida, clique em **Adicionar manipulador de eventos**.  
  
3.  No **Assistente de manipulador de eventos**, confirme as configurações padrão e clique em **adicionar e editar**. Para obter mais informações, consulte [Assistente de manipulador de eventos](../ide/event-handler-wizard.md).  
  
4.  No editor de códigos, adicione o seguinte código para a função de manipulador:  
  
 ```  
    MessageBox((LPCTSTR)L"Hello World");

 ```  
  
## <a name="see-also"></a>Consulte também  
 [RibbonGadgets exemplo: Aplicativo de Gadgets da faixa de opções](../visual-cpp-samples.md)   
 [Designer da faixa de opções (MFC)](../mfc/ribbon-designer-mfc.md)

