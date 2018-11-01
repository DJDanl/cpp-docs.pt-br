---
title: Funções de membro CWinApp substituíveis
ms.date: 11/04/2016
f1_keywords:
- CWinApp
helpviewer_keywords:
- overriding [MFC], overridable functions in CWinApp
- application class [MFC]
- CWinApp class [MFC], overridables
ms.assetid: 07183d5e-734b-45d9-a8b6-9dde4adac0b4
ms.openlocfilehash: 9f1098e305606df9463e308466b7864b019d5a00
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50459270"
---
# <a name="overridable-cwinapp-member-functions"></a>Funções de membro CWinApp substituíveis

[CWinApp](../mfc/reference/cwinapp-class.md) fornece várias funções de membro substituível de chave (`CWinApp` substitui esses membros da classe [CWinThread](../mfc/reference/cwinthread-class.md), do qual `CWinApp` deriva):

- [InitInstance](../mfc/initinstance-member-function.md)

- [Executar](../mfc/run-member-function.md)

- [ExitInstance](../mfc/exitinstance-member-function.md)

- [OnIdle](../mfc/onidle-member-function.md)

As únicas `CWinApp` função de membro que você deve substituir é `InitInstance`.

## <a name="see-also"></a>Consulte também

[CWinApp: a classe do aplicativo](../mfc/cwinapp-the-application-class.md)
