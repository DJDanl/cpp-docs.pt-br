---
title: Comando padrão e IDs do Windows
ms.date: 11/04/2016
f1_keywords:
- vc.mfc.macros
helpviewer_keywords:
- standard command and Window IDs
ms.assetid: 0424805c-fff8-4531-8f0c-15cfb13aa612
ms.openlocfilehash: e5f6955407f565d5cc06ef57e9bd273f6c0f7712
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62310040"
---
# <a name="standard-command-and-window-ids"></a>Comando padrão e IDs do Windows

A biblioteca Microsoft Foundation Class define um número de comando padrão e IDs de janela em afxres. h. Essas IDs são mais comumente usadas dentro os editores de recursos e a janela Propriedades para mapear as mensagens para suas funções de manipulador. Todos os comandos padrão têm uma **ID _** prefixo. Por exemplo, quando você usa o editor de menu, você normalmente associar o item de menu Abrir arquivo para o ID de comando ID_FILE_OPEN padrão.

Para comandos mais padrão, o código do aplicativo não precisa fazer referência à ID de comando, porque a estrutura em si lida com os comandos por meio de mapas de mensagem em suas classes de estrutura principal (`CWinThread`, `CWinApp`, `CView`, `CDocument`, e assim por diante).

Além de IDs de comando padrão, um número de outras IDs padrão é definido que têm um prefixo de **AFX_ID**. Essas IDs incluem IDs de janela padrão (prefixo **AFX_IDW_**), IDs de cadeia de caracteres (prefixo **AFX_IDS_**) e vários outros tipos.

As iDs que começam com o **AFX_ID** prefixo raramente são usados por programadores, mas talvez seja necessário para se referir a essas IDs, ao substituir funções do framework que também fazem referência a **AFX_ID**s.

IDs individualmente não estão documentadas nesta referência. Você pode encontrar mais informações sobre eles em notas técnicas [20](../../mfc/tn020-id-naming-and-numbering-conventions.md), [21](../../mfc/tn021-command-and-message-routing.md), e [22](../../mfc/tn022-standard-commands-implementation.md).

> [!NOTE]
>  O arquivo de cabeçalho afxres. h indiretamente está incluído no afxwin. h. Você deve incluir explicitamente a instrução a seguir no arquivo de script (. rc) do recurso do seu aplicativo:

[!code-cpp[NVC_MFC_Utilities#47](../../mfc/codesnippet/cpp/standard-command-and-window-ids_1.h)]

## <a name="see-also"></a>Consulte também

[Macros e globais](../../mfc/reference/mfc-macros-and-globals.md)
