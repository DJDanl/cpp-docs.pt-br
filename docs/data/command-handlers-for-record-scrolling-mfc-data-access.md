---
title: Manipuladores de comando para registro de rolagem (MFC acesso a dados) | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-data
ms.topic: conceptual
dev_langs:
- C++
helpviewer_keywords:
- record views [C++], scrolling
- record scrolling [C++]
- scrolling records
ms.assetid: f8b13477-2a37-459e-a30c-806fb78165ac
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- data-storage
ms.openlocfilehash: 03dec2e3eff0f61db5f4c8b7573400a589615b02
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
---
# <a name="command-handlers-for-record-scrolling--mfc-data-access"></a>Manipuladores de comandos para rolagem de registro (Acesso a dados MFC)
O [CRecordView](../mfc/reference/crecordview-class.md) classe fornece um comando de padrão de tratamento para os seguintes comandos padrão:  
  
-   **ID_RECORD_MOVE_FIRST**  
  
-   **ID_RECORD_MOVE_LAST**  
  
-   **ID_RECORD_MOVE_NEXT**  
  
-   **ID_RECORD_MOVE_PREV**  
  
 O `OnMove` função membro fornece tratamento de todos os quatro comandos, mover de registro para registro de comando de padrão. Como esses comandos são emitidos, RFX (ou DFX) carrega o novo registro nos campos do conjunto de registros e DDX move os valores para os controles do formulário de registro. Para obter informações sobre RFX, consulte [troca de campos de registro (RFX)](../data/odbc/record-field-exchange-rfx.md).  
  
> [!NOTE]
>  Certifique-se de usar essas IDs de comando padrão para os objetos de interface de usuário associados com os comandos de navegação de registro padrão.  
  
## <a name="see-also"></a>Consulte também  
 [Suporte de navegação em uma exibição de registro](../data/supporting-navigation-in-a-record-view-mfc-data-access.md)