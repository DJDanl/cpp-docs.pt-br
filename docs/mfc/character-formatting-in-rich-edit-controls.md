---
title: Formatação de caractere em controles de edição avançada | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-mfc
ms.topic: conceptual
dev_langs:
- C++
helpviewer_keywords:
- formatting [MFC], characters
- rich edit controls [MFC], character formatting in
- CRichEditCtrl class [MFC], character formatting in
ms.assetid: c80f4305-75ad-45f9-8d17-d83d0fe79be5
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: e7b56570a2821cef3cd2d2676a5260f42bc2ffaf
ms.sourcegitcommit: 9a0905c03a73c904014ec9fd3d6e59e4fa7813cd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/29/2018
ms.locfileid: "43210764"
---
# <a name="character-formatting-in-rich-edit-controls"></a>Formatação de caractere em controles de edição avançada
Você pode usar funções de membro do controle de edição avançada ([CRichEditCtrl](../mfc/reference/cricheditctrl-class.md)) para formatar caracteres e para recuperar informações de formatação. Para caracteres, você pode especificar a face de tipos, tamanho, cor e efeitos como negrito, itálico e protegidos.  
  
 Você pode aplicar a formatação de caracteres usando o [SetSelectionCharFormat](../mfc/reference/cricheditctrl-class.md#setselectioncharformat) e [SetWordCharFormat](../mfc/reference/cricheditctrl-class.md#setwordcharformat) funções de membro. Para determinar a formatação do texto selecionado do caractere atual, use o [GetSelectionCharFormat](../mfc/reference/cricheditctrl-class.md#getselectioncharformat) função de membro. O [CHARFORMAT](/windows/desktop/api/richedit/ns-richedit-_charformat) com essas funções de membro, a estrutura é usada para especificar atributos de caractere. Um dos membros importantes da **CHARFORMAT** é **dwMask**. Na `SetSelectionCharFormat` e `SetWordCharFormat`, **dwMask** Especifica quais atributos de caractere serão definidos por essa chamada de função. `GetSelectionCharFormat` informa os atributos do primeiro caractere na seleção; **dwMask** Especifica os atributos que são consistentes em toda a seleção.  
  
 Você pode também obter e definir a "padrão formatação de caractere," qual é a formatação aplicada a qualquer caractere subsequentemente inserida. Por exemplo, se um aplicativo define o caractere de padrão de formatação em negrito e em seguida, o usuário digita um caractere, esse caractere está em negrito. Para obter e definir a formatação de caractere padrão, use o [GetDefaultCharFormat](../mfc/reference/cricheditctrl-class.md#getdefaultcharformat) e [SetDefaultCharFormat](../mfc/reference/cricheditctrl-class.md#setdefaultcharformat) funções de membro.  
  
 O atributo "protegida" caractere não altera a aparência do texto. Se o usuário tenta modificar texto protegido, um controle rich edit envia sua janela pai um **EN_PROTECTED** mensagem de notificação, permitindo que a janela pai permitir ou impedir a alteração. Para receber esta mensagem de notificação, você deve habilitá-la usando o [SetEventMask](../mfc/reference/cricheditctrl-class.md#seteventmask) função de membro. Para obter mais informações sobre a máscara de evento, consulte [as notificações de um controle de edição de Rich](../mfc/notifications-from-a-rich-edit-control.md), mais adiante neste tópico.  
  
 Cor de primeiro plano é um atributo de caractere, mas a cor do plano de fundo é uma propriedade do controle de edição avançada. Para definir a cor do plano de fundo, use o [SetBackgroundColor](../mfc/reference/cricheditctrl-class.md#setbackgroundcolor) função de membro.  
  
## <a name="see-also"></a>Consulte também  
 [Usando CRichEditCtrl](../mfc/using-cricheditctrl.md)   
 [Controles](../mfc/controls-mfc.md)

