---
title: Comando padrão e IDs do Windows | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-mfc
ms.topic: reference
f1_keywords:
- vc.mfc.macros
dev_langs:
- C++
helpviewer_keywords:
- standard command and Window IDs
ms.assetid: 0424805c-fff8-4531-8f0c-15cfb13aa612
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 72b50108a9b880961f0dd8bcded1126a635fb9e7
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
ms.locfileid: "33371644"
---
# <a name="standard-command-and-window-ids"></a>Comando padrão e IDs do Windows
A biblioteca Microsoft Foundation Class define um número de comando padrão e IDs de janela em Afxres.h. Essas IDs são mais comumente usados em editores de recursos e a janela Propriedades para mapear as mensagens para as funções de manipulador. Todos os comandos padrão têm um **ID _** prefixo. Por exemplo, quando você usar o editor de menu, você normalmente associar o item de menu Abrir arquivo para o padrão `ID_FILE_OPEN` comando ID.  
  
 Para comandos mais padrão, o código do aplicativo não precisa fazer referência à ID de comando, porque a própria estrutura manipula os comandos por meio de mapas de mensagem em suas classes de estrutura principal ( `CWinThread`, `CWinApp`, < c4 > `CView` , **CDocument**, e assim por diante).  
  
 Além de IDs de comando padrão, um número de outras IDs padrão é definido que têm um prefixo de **AFX_ID**. Essas IDs incluem IDs de janela padrão (prefixo **AFX_IDW_**), IDs de cadeia de caracteres (prefixo **AFX_IDS_**) e vários outros tipos.  
  
 IDs que começam com o **AFX_ID** prefixo raramente são usados por programadores, mas talvez seja necessário para se referir a essas IDs ao substituir funções do framework que também fazem referência a **AFX_ID**s.  
  
 IDs individualmente não estão documentados nesta referência. Você pode encontrar mais informações sobre eles em notas técnicas [20](../../mfc/tn020-id-naming-and-numbering-conventions.md), [21](../../mfc/tn021-command-and-message-routing.md), e [22](../../mfc/tn022-standard-commands-implementation.md).  
  
> [!NOTE]
>  O arquivo de cabeçalho Afxres.h indiretamente está incluído no Afxwin.h. Você deve incluir explicitamente a instrução a seguir no arquivo de script (. rc) do recurso do aplicativo:  
  
 [!code-cpp[NVC_MFC_Utilities#47](../../mfc/codesnippet/cpp/standard-command-and-window-ids_1.h)]  
  
## <a name="see-also"></a>Consulte também  
 [Macros e globais](../../mfc/reference/mfc-macros-and-globals.md)
