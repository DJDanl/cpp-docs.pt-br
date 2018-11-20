---
title: Implementação da barra de status no MFC
ms.date: 11/19/2018
f1_keywords:
- COldStatusBar
helpviewer_keywords:
- status bars [MFC], implementing in MFC
- CStatusBarCtrl class [MFC], and MFC status bars
- CStatusBar class [MFC], and CStatusBarCtrl class [MFC]
- CStatusBarCtrl class [MFC], and CStatusBar class [MFC]
- status bars [MFC], backward compatibility
- status bars [MFC], old with COldStatusBar class [MFC]
- COldStatusBar class [MFC]
- status bars [MFC], and CStatusBarCtrl class
- CStatusBar class [MFC], and MFC status bars
- status indicators
- status bars [MFC], Windows 95 implementation
ms.assetid: be5cd876-38e3-4d5c-b8cb-16d57a16a142
ms.openlocfilehash: 521b24646b673159d14e89bd57ea698a7ba73381
ms.sourcegitcommit: 9e891eb17b73d98f9086d9d4bfe9ca50415d9a37
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 11/20/2018
ms.locfileid: "52175360"
---
# <a name="status-bar-implementation-in-mfc"></a>Implementação da barra de status no MFC

Um [CStatusBar](../mfc/reference/cstatusbar-class.md) objeto é uma barra de controle com uma linha de painéis de saída de texto. Os painéis de saída normalmente são usados como linhas de mensagem e como os indicadores de status. Exemplos incluem as linhas de mensagem de Ajuda do menu que explicam resumidamente o comando de menu selecionado e os indicadores que mostram o status de SCROLL LOCK, NUM LOCK e outras chaves.

A partir do MFC versão 4.0, barras de status são implementadas usando a classe [CStatusBarCtrl](../mfc/reference/cstatusbarctrl-class.md), que encapsula um controle comum da barra de status. Para compatibilidade com versões anteriores, o MFC retém a implementação da barra de status mais antiga na classe `COldStatusBar`. Descreve a documentação de versões anteriores do MFC `COldStatusBar` sob `CStatusBar`.

[CStatusBar::GetStatusBarCtrl](../mfc/reference/cstatusbar-class.md#getstatusbarctrl), uma função de membro novo a MFC 4.0, permite que você tirar proveito do suporte do controle do Windows comuns para personalização e funcionalidade adicional da barra de status. `CStatusBar` funções de membro lhe oferece a maioria da funcionalidade dos controles comuns do Windows; No entanto, quando você chama `GetStatusBarCtrl`, você pode dar as barras de status ainda mais as características de uma barra de status. Quando você chama `GetStatusBarCtrl`, ele retornará uma referência a um `CStatusBarCtrl` objeto. Você pode usar essa referência para manipular o controle de barra de status.

A figura a seguir mostra uma barra de status que exibe vários indicadores.

![Barra de status](../mfc/media/vc37dy1.gif "barra de Status") <br/>
Uma barra de Status

Como a barra de ferramentas, o objeto de barra de status é inserido em sua janela de quadro pai e é construído automaticamente quando a janela do quadro é construída. Barra de status, como todas as barras de controle é destruída automaticamente também quando o quadro pai é destruído.

## <a name="what-do-you-want-to-know-more-about"></a>O que você deseja saber mais sobre

- [Atualizando o texto de um painel da barra de status](../mfc/updating-the-text-of-a-status-bar-pane.md)

- Classes MFC [CStatusBar](../mfc/reference/cstatusbar-class.md) e [CStatusBarCtrl](../mfc/reference/cstatusbarctrl-class.md)

- [Barras de controle](../mfc/control-bars.md)

- [Barras da caixa de diálogo](../mfc/dialog-bars.md)

- [Barras de ferramentas (implementação de barra de ferramentas do MFC)](../mfc/mfc-toolbar-implementation.md)

## <a name="see-also"></a>Consulte também

[Barras de status](../mfc/status-bars.md)

