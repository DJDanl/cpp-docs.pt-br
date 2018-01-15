---
title: "Acesso fortemente tipado a controles em uma caixa de diálogo | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-windows
ms.tgt_pltfrm: 
ms.topic: article
dev_langs: C++
helpviewer_keywords:
- common controls [MFC], in dialog boxes
- Windows common controls [MFC], in dialog boxes
- safe access to dialog box controls
- dialog boxes [MFC], type-safe access to controls
- controls [MFC], accessing in dialog boxes
- type-safe access to dialog box controls
- MFC dialog boxes [MFC], type-safe access to controls
ms.assetid: 67021025-dd93-4d6a-8bed-a1348fe50685
caps.latest.revision: "9"
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload: cplusplus
ms.openlocfilehash: b6005f34b28a634b36aad93186a34a8806b8033d
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="type-safe-access-to-controls-in-a-dialog-box"></a>Acesso fortemente tipado a controles em uma caixa de diálogo
Os controles em uma caixa de diálogo podem usar as interfaces das classes de controle do MFC como `CListBox` e `CEdit`. É possível criar um objeto de controle e anexá-lo a um controle de caixa de diálogo. Em seguida, é possível acessar o controle por meio de sua interface de classe, chamando funções de membro para operação no controle. Os métodos descritos aqui foram projetados para dar acesso fortemente tipado a um controle. Isso é especialmente útil para controles como caixas de edição e de listagem.  
  
 Existem duas abordagens para estabelecer uma conexão entre um controle em uma caixa de diálogo e uma variável de membro de controle do C++ em uma classe derivada por `CDialog`:  
  
-   [Sem assistentes de código](../mfc/type-safe-access-to-controls-without-code-wizards.md)  
  
-   [Com assistentes de código](../mfc/type-safe-access-to-controls-with-code-wizards.md)  
  
## <a name="see-also"></a>Consulte também  
 [Caixas de diálogo](../mfc/dialog-boxes.md)

