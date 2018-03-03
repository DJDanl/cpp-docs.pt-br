---
title: "Acesso fortemente tipado a controles sem assistentes de código | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-windows
ms.tgt_pltfrm: 
ms.topic: article
dev_langs:
- C++
helpviewer_keywords:
- dialog boxes [MFC], accessing controls
- dialog box controls [MFC], accessing
ms.assetid: 325b4927-d49b-42b4-8e0b-fc84f31fb059
caps.latest.revision: 
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: 0c5a4adce63851620326add61857433b32e1fad5
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="type-safe-access-to-controls-without-code-wizards"></a>Acesso fortemente tipado a controles sem assistentes de código
A primeira abordagem para criar acesso fortemente tipado a controles usa uma função de membro embutida para converter o tipo de retorno da classe `CWnd`do `GetDlgItem` a função de membro para o tipo apropriado de controle do C++, como neste exemplo:  
  
 [!code-cpp[NVC_MFCControlLadenDialog#50](../mfc/codesnippet/cpp/type-safe-access-to-controls-without-code-wizards_1.cpp)]  
  
 Você pode usar essa função de membro para o controle de acesso de uma maneira de tipo seguro com o código semelhante ao seguinte:  
  
 [!code-cpp[NVC_MFCControlLadenDialog#51](../mfc/codesnippet/cpp/type-safe-access-to-controls-without-code-wizards_2.cpp)]  
  
## <a name="see-also"></a>Consulte também  
 [Acesso fortemente tipado a controles em uma caixa de diálogo](../mfc/type-safe-access-to-controls-in-a-dialog-box.md)   
 [Acesso fortemente tipado a controles com assistentes de código](../mfc/type-safe-access-to-controls-with-code-wizards.md)

