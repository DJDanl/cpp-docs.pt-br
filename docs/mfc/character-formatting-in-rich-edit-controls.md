---
title: "Formatação de caractere em controles de edição avançada | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-windows
ms.tgt_pltfrm: 
ms.topic: article
dev_langs: C++
helpviewer_keywords:
- formatting [MFC], characters
- rich edit controls [MFC], character formatting in
- CRichEditCtrl class [MFC], character formatting in
ms.assetid: c80f4305-75ad-45f9-8d17-d83d0fe79be5
caps.latest.revision: "10"
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload: cplusplus
ms.openlocfilehash: 93bb2cda113a56276ad54edb5ccdb6c9d430ed06
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="character-formatting-in-rich-edit-controls"></a>Formatação de caractere em controles de edição avançada
Você pode usar funções de membro do controle de edição avançada ([CRichEditCtrl](../mfc/reference/cricheditctrl-class.md)) para formatar caracteres e para recuperar informações de formatação. Para caracteres, você pode especificar o tipo de fonte, tamanho, cor e efeitos como negrito, itálico e protegidos.  
  
 Você pode aplicar formatação de caractere usando o [SetSelectionCharFormat](../mfc/reference/cricheditctrl-class.md#setselectioncharformat) e [SetWordCharFormat](../mfc/reference/cricheditctrl-class.md#setwordcharformat) funções de membro. Para determinar o caractere atual de formatação para o texto selecionado, use o [GetSelectionCharFormat](../mfc/reference/cricheditctrl-class.md#getselectioncharformat) função de membro. O [CHARFORMAT](http://msdn.microsoft.com/library/windows/desktop/bb787881) com essas funções de membro, a estrutura é usada para especificar atributos de caractere. Um dos membros importantes do **CHARFORMAT** é **dwMask**. Em `SetSelectionCharFormat` e `SetWordCharFormat`, **dwMask** Especifica quais atributos de caractere serão definidos pela chamada de função. `GetSelectionCharFormat`informa os atributos do primeiro caractere da seleção; **dwMask** Especifica os atributos que estão consistentes em toda a seleção.  
  
 Você pode também obter e definir a "padrão formatação de caractere," qual é a formatação aplicada a todos os caracteres inseridos posteriormente. Por exemplo, se um aplicativo define a formatação em negrito de padrão de caracteres e o usuário, em seguida, digita um caractere, o caractere está em negrito. Para obter e definir a formatação de caractere padrão, use o [GetDefaultCharFormat](../mfc/reference/cricheditctrl-class.md#getdefaultcharformat) e [SetDefaultCharFormat](../mfc/reference/cricheditctrl-class.md#setdefaultcharformat) funções de membro.  
  
 O atributo "protegido" caractere não altera a aparência do texto. Se o usuário tentar modificar o texto protegido, um controle de edição rica envia sua janela pai um **EN_PROTECTED** mensagem de notificação, permitindo que a janela pai permitir ou impedir a alteração. Para receber essa mensagem de notificação, você deve habilitá-la usando o [SetEventMask](../mfc/reference/cricheditctrl-class.md#seteventmask) função de membro. Para obter mais informações sobre a máscara de evento, consulte [notificações de um controle de edição avançada](../mfc/notifications-from-a-rich-edit-control.md), mais adiante neste tópico.  
  
 Cor de primeiro plano é um atributo de caractere, mas a cor do plano de fundo é uma propriedade do controle de edição avançada. Para definir a cor de plano de fundo, use o [SetBackgroundColor](../mfc/reference/cricheditctrl-class.md#setbackgroundcolor) função de membro.  
  
## <a name="see-also"></a>Consulte também  
 [Usando CRichEditCtrl](../mfc/using-cricheditctrl.md)   
 [Controles](../mfc/controls-mfc.md)

