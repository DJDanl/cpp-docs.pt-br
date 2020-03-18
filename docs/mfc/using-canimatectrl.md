---
title: Usando CAnimateCtrl
ms.date: 11/04/2016
helpviewer_keywords:
- animation controls [MFC], CAnimateCtrl class
- controls [MFC], animation
- CAnimateCtrl class [MFC], about CAnimateCtrl class [MFC]
ms.assetid: 696c0805-bef0-4e2e-a9e7-b37b9215b7f0
ms.openlocfilehash: 79c1a0111317514ef6fd68acd0c6a2ebdccc3ba4
ms.sourcegitcommit: 63784729604aaf526de21f6c6b62813882af930a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/17/2020
ms.locfileid: "79447111"
---
# <a name="using-canimatectrl"></a>Usando CAnimateCtrl

Um controle de animação, representado pela classe [CAnimateCtrl](../mfc/reference/canimatectrl-class.md), é uma janela que exibe um clipe no formato AVI (vídeo de áudio Intercalado) — o formato padrão de vídeo/áudio do Windows. Um clipe AVI é uma série de quadros de bitmap, como um filme.

Como seu thread continua sendo executado enquanto o clipe AVI é exibido, um uso comum para um controle de animação é para indicar a atividade do sistema durante uma operação demorada. Por exemplo, a caixa de diálogo Localizar do Windows exibe uma lupa de movimentação à medida que o sistema procura um arquivo.

Os controles de animação só podem reproduzir clipes AVI simples e não oferecem suporte a som. (Para obter uma lista completa de limitações, consulte [CAnimateCtrl](../mfc/reference/canimatectrl-class.md).) Como os recursos de um controle de animação são severamente limitados e estão sujeitos a alterações, você deve usar uma alternativa como o controle MCIWnd se precisar de um controle para fornecer recursos de reprodução e/ou gravação de multimídia. Para obter mais informações sobre o controle MCIWnd, consulte a documentação de multimídia.

## <a name="what-do-you-want-to-know-more-about"></a>Do que você deseja saber mais sobre

- [Usando um controle de animação](../mfc/using-an-animation-control.md)

- [Notificações enviadas por controles de animação](../mfc/notifications-sent-by-animation-controls.md)

## <a name="see-also"></a>Consulte também

[Controles](../mfc/controls-mfc.md)
