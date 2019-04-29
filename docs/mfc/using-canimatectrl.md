---
title: Usando CAnimateCtrl
ms.date: 11/04/2016
f1_keywords:
- CAnimateCtrl
helpviewer_keywords:
- animation controls [MFC], CAnimateCtrl class
- controls [MFC], animation
- CAnimateCtrl class [MFC], about CAnimateCtrl class [MFC]
ms.assetid: 696c0805-bef0-4e2e-a9e7-b37b9215b7f0
ms.openlocfilehash: b967cc6dde6b4f639ef081b3821f6a7e5a2fe295
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62351635"
---
# <a name="using-canimatectrl"></a>Usando CAnimateCtrl

Um controle de animação, representado pela classe [CAnimateCtrl](../mfc/reference/canimatectrl-class.md), é uma janela que exibe um clipe em formato de áudio vídeo intercalados (AVI) — o formato de áudio/vídeo do Windows padrão. Um clipe AVI é uma série de quadros de bitmap, como um filme.

Uma vez que o thread continua executando enquanto o clipe AVI é exibido, um uso comum para um controle de animação é indicar a atividade do sistema durante uma operação demorada. Por exemplo, a caixa de diálogo Localizar o Windows exibe uma lente de movimentação como o sistema procurará um arquivo.

Controles de animação só podem reproduzir clipes AVI simples, e eles não dão suporte a som. (Para obter uma lista completa de limitações, consulte [CAnimateCtrl](../mfc/reference/canimatectrl-class.md).) Uma vez que os recursos de um controle de animação são muito limitados e sujeitos a alterações, você deve usar uma alternativa como o controle MCIWnd se precisar de um controle para fornecer a reprodução de multimídia e/ou recursos de gravação. Para obter mais informações sobre o controle MCIWnd, consulte a documentação de multimídia.

## <a name="what-do-you-want-to-know-more-about"></a>O que você deseja saber mais sobre

- [Usando um controle de animação](../mfc/using-an-animation-control.md)

- [Notificações enviadas por controles de animação](../mfc/notifications-sent-by-animation-controls.md)

## <a name="see-also"></a>Consulte também

[Controles](../mfc/controls-mfc.md)
