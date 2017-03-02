---
title: Estilos de janela com moldura (MFC) | Documentos do Microsoft
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords:
- FWS_ADDTOTITLE
- FWS_SNAPTOBARS
- FWS_PREFIXTITLE
dev_langs:
- C++
helpviewer_keywords:
- frame windows, styles
- FWS_SNAPTOBARS constant
- FWS_PREFIXTITLE constant
- FWS_ADDTOTITLE constant
- styles, windows
ms.assetid: d21f270e-a088-4962-a2ae-8c03334b5a06
caps.latest.revision: 10
author: mikeblome
ms.author: mblome
manager: ghogen
translation.priority.ht:
- cs-cz
- de-de
- es-es
- fr-fr
- it-it
- ja-jp
- ko-kr
- pl-pl
- pt-br
- ru-ru
- tr-tr
- zh-cn
- zh-tw
translationtype: Machine Translation
ms.sourcegitcommit: 3168772cbb7e8127523bc2fc2da5cc9b4f59beb8
ms.openlocfilehash: 76f2f8bde31e3eccd6c5abe9b3943ffc2bee47aa
ms.lasthandoff: 02/25/2017

---
# <a name="frame-window-styles-mfc"></a>Estilos de janela com moldura (MFC)
-   **FWS_ADDTOTITLE** Especifica as informações para acrescentar ao final de um título de janela de quadro. Por exemplo, "Microsoft desenhar – desenho no Document1". Você pode especificar as cadeias de caracteres exibidas na guia cadeias de caracteres de modelo de documento no Assistente de aplicativo. Se você precisar desativar essa opção, substituir o `CWnd::PreCreateWindow` função de membro.  
  
-   **FWS_PREFIXTITLE** mostra o nome do documento antes do nome do aplicativo em um título de janela de quadro. Por exemplo, "Documento – WordPad". Você pode especificar as cadeias de caracteres exibidas na guia cadeias de caracteres de modelo de documento no Assistente de aplicativo. Se você precisar desativar essa opção, substituir o `CWnd::PreCreateWindow` função de membro.  
  
-   **FWS_SNAPTOBARS** dimensionamento de controles da janela do quadro que inclui uma barra quando ele estiver em uma janela flutuante em vez de encaixada para uma janela de quadro de controle. Esse estilo de tamanhos de janela para ajustar a barra de controle.  
  
## <a name="see-also"></a>Consulte também  
 [Estilos usados pelo MFC](../../mfc/reference/styles-used-by-mfc.md)


