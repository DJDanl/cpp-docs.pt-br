---
title: Funções de membro CWinApp substituíveis
ms.date: 11/04/2016
helpviewer_keywords:
- overriding [MFC], overridable functions in CWinApp
- application class [MFC]
- CWinApp class [MFC], overridables
ms.assetid: 07183d5e-734b-45d9-a8b6-9dde4adac0b4
ms.openlocfilehash: 7ae72a52c37582f8398ebc03f404ff105fe14650
ms.sourcegitcommit: c21b05042debc97d14875e019ee9d698691ffc0b
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 06/09/2020
ms.locfileid: "84624009"
---
# <a name="overridable-cwinapp-member-functions"></a>Funções de membro CWinApp substituíveis

O [CWinApp](reference/cwinapp-class.md) fornece várias funções de membro substituíveis de chave ( `CWinApp` substitui esses membros da classe [CWinThread](reference/cwinthread-class.md), a partir da qual `CWinApp` deriva):

- [InitInstance](initinstance-member-function.md)

- [Executar](run-member-function.md)

- [ExitInstance](exitinstance-member-function.md)

- [Agenda](onidle-member-function.md)

A única `CWinApp` função de membro que você deve substituir é `InitInstance` .

## <a name="see-also"></a>Consulte também

[CWinApp: a classe do aplicativo](cwinapp-the-application-class.md)
