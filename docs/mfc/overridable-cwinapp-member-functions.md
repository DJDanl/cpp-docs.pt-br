---
title: Funções de membro CWinApp substituíveis | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-mfc
ms.topic: conceptual
f1_keywords:
- CWinApp
dev_langs:
- C++
helpviewer_keywords:
- overriding [MFC], overridable functions in CWinApp
- application class [MFC]
- CWinApp class [MFC], overridables
ms.assetid: 07183d5e-734b-45d9-a8b6-9dde4adac0b4
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: d454ce65a2068a00f9b2c7f5934951f295738c12
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
ms.locfileid: "33347705"
---
# <a name="overridable-cwinapp-member-functions"></a>Funções de membro CWinApp substituíveis
[CWinApp](../mfc/reference/cwinapp-class.md) fornece várias funções de membro substituível de chave (`CWinApp` substitui esses membros da classe [CWinThread](../mfc/reference/cwinthread-class.md), do qual `CWinApp` deriva):  
  
-   [InitInstance](../mfc/initinstance-member-function.md)  
  
-   [Executar](../mfc/run-member-function.md)  
  
-   [ExitInstance](../mfc/exitinstance-member-function.md)  
  
-   [OnIdle](../mfc/onidle-member-function.md)  
  
 A única `CWinApp` é de função de membro que você deve substituir `InitInstance`.  
  
## <a name="see-also"></a>Consulte também  
 [CWinApp: a classe do aplicativo](../mfc/cwinapp-the-application-class.md)
