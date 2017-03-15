---
title: "Comando padrão e IDs do Windows | Documentos do Microsoft"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords:
- vc.mfc.macros
dev_langs:
- C++
helpviewer_keywords:
- standard command and Window IDs
ms.assetid: 0424805c-fff8-4531-8f0c-15cfb13aa612
caps.latest.revision: 13
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
ms.sourcegitcommit: 5187996fc377bca8633360082d07f7ec8a68ee57
ms.openlocfilehash: d308f3f9efc5933124460d9839a0e94fffa60b4a
ms.lasthandoff: 02/25/2017

---
# <a name="standard-command-and-window-ids"></a>Comando padrão e IDs do Windows
A biblioteca Microsoft Foundation Class define um número de comando padrão e IDs de janela em Afxres.h. Essas IDs são mais comumente usados em editores de recursos e a janela Propriedades para mapear as mensagens para as funções de manipulador. Todos os comandos padrão têm uma **ID _** prefixo. Por exemplo, quando você usar o editor de menu, você normalmente associar o item de menu Abrir arquivo para o padrão `ID_FILE_OPEN` comando ID.  
  
 Para comandos mais padrão, o código do aplicativo não precisa se referir a ID de comando, como a própria estrutura lida com os comandos por meio de mapas de mensagem em suas classes de estrutura principal ( `CWinThread`, `CWinApp`, `CView`, **CDocument**, e assim por diante).  
  
 Além de IDs de comando padrão, um número de outros IDs padrão é definido com um prefixo de **AFX_ID**. Essas identificações de incluem identificações de janela padrão (prefixo **AFX_IDW_**), IDs de cadeia de caracteres (prefixo **AFX_IDS_**) e vários outros tipos.  
  
 IDs que começam com o **AFX_ID** prefixo raramente são usados por programadores, mas talvez seja necessário para se referir a essas IDs ao substituir funções do framework que também se referem a **AFX_ID**s.  
  
 IDs individualmente não são documentadas nesta referência. Você pode encontrar mais informações sobre eles em Observações técnicas [20](../../mfc/tn020-id-naming-and-numbering-conventions.md), [21](../../mfc/tn021-command-and-message-routing.md), e [22](../../mfc/tn022-standard-commands-implementation.md).  
  
> [!NOTE]
>  O arquivo de cabeçalho Afxres.h indiretamente está incluído em afxwin. h. Você deve incluir explicitamente a instrução a seguir no arquivo de script (. rc) do recurso do aplicativo:  
  
 [!code-cpp[47 NVC_MFC_Utilities](../../mfc/codesnippet/cpp/standard-command-and-window-ids_1.h)]  
  
## <a name="see-also"></a>Consulte também  
 [Macros e globais](../../mfc/reference/mfc-macros-and-globals.md)

