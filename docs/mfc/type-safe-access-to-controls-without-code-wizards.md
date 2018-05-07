---
title: Acesso fortemente tipado a controles sem assistentes de código | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-mfc
ms.topic: conceptual
dev_langs:
- C++
helpviewer_keywords:
- dialog boxes [MFC], accessing controls
- dialog box controls [MFC], accessing
ms.assetid: 325b4927-d49b-42b4-8e0b-fc84f31fb059
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: bb861995c16411bb58e3051c5ffc78f75931ae8f
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
---
# <a name="type-safe-access-to-controls-without-code-wizards"></a>Acesso fortemente tipado a controles sem assistentes de código
A primeira abordagem para criar acesso fortemente tipado a controles usa uma função de membro embutida para converter o tipo de retorno da classe `CWnd`do `GetDlgItem` a função de membro para o tipo apropriado de controle do C++, como neste exemplo:  
  
 [!code-cpp[NVC_MFCControlLadenDialog#50](../mfc/codesnippet/cpp/type-safe-access-to-controls-without-code-wizards_1.cpp)]  
  
 Você pode usar essa função de membro para o controle de acesso de uma maneira de tipo seguro com o código semelhante ao seguinte:  
  
 [!code-cpp[NVC_MFCControlLadenDialog#51](../mfc/codesnippet/cpp/type-safe-access-to-controls-without-code-wizards_2.cpp)]  
  
## <a name="see-also"></a>Consulte também  
 [Acesso fortemente tipado a controles em uma caixa de diálogo](../mfc/type-safe-access-to-controls-in-a-dialog-box.md)   
 [Acesso fortemente tipado a controles com assistentes de código](../mfc/type-safe-access-to-controls-with-code-wizards.md)

