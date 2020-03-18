---
title: Funções de membro CWinApp substituíveis
ms.date: 11/04/2016
helpviewer_keywords:
- overriding [MFC], overridable functions in CWinApp
- application class [MFC]
- CWinApp class [MFC], overridables
ms.assetid: 07183d5e-734b-45d9-a8b6-9dde4adac0b4
ms.openlocfilehash: 28ba243bd755e25db5f2cb03d08013f082fbc918
ms.sourcegitcommit: 63784729604aaf526de21f6c6b62813882af930a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/17/2020
ms.locfileid: "79447258"
---
# <a name="overridable-cwinapp-member-functions"></a>Funções de membro CWinApp substituíveis

O [CWinApp](../mfc/reference/cwinapp-class.md) fornece várias funções de membro substituíveis de chave (`CWinApp` substitui esses membros da classe [CWinThread](../mfc/reference/cwinthread-class.md), da qual `CWinApp` deriva):

- [InitInstance](../mfc/initinstance-member-function.md)

- [Executar](../mfc/run-member-function.md)

- [ExitInstance](../mfc/exitinstance-member-function.md)

- [Agenda](../mfc/onidle-member-function.md)

A única função de membro `CWinApp` que você deve substituir é `InitInstance`.

## <a name="see-also"></a>Consulte também

[CWinApp: a classe do aplicativo](../mfc/cwinapp-the-application-class.md)
