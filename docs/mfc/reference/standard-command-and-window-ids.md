---
title: Comando padrão e IDs do Windows
ms.date: 11/04/2016
helpviewer_keywords:
- standard command and Window IDs
ms.assetid: 0424805c-fff8-4531-8f0c-15cfb13aa612
ms.openlocfilehash: 40783bc19e51afb0e9fe9e4a429df0239a8e7f09
ms.sourcegitcommit: 3caf5261b3ea80d9cf14038c116ba981d655cd13
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/11/2019
ms.locfileid: "70907710"
---
# <a name="standard-command-and-window-ids"></a>Comando padrão e IDs do Windows

O biblioteca MFC define um número de comandos padrão e IDs de janela em Afxres. h. Essas IDs são mais comumente usadas dentro dos editores de recursos e do [Assistente de classe](mfc-class-wizard.md) para mapear mensagens para suas funções de manipulador. Todos os comandos padrão têm um prefixo **ID_** . Por exemplo, ao usar o editor de menu, você normalmente vincula o item de menu abrir arquivo à ID de comando ID_FILE_OPEN padrão.

Para a maioria dos comandos padrão, o código do aplicativo não precisa se referir à ID do comando, porque a própria estrutura manipula os comandos por meio de mapas de`CWinThread`mensagens em `CView`suas `CDocument`classes principais da estrutura (, `CWinApp`,, e assim por diante).

Além das IDs de comando padrão, várias outras IDs padrão são definidas, que têm um prefixo de **AFX_ID**. Essas IDs incluem IDs de janela padrão (prefixo **AFX_IDW_** ), IDs de cadeia de caracteres (prefixo **AFX_IDS_** ) e vários outros tipos.

As IDs que começam com o prefixo **AFX_ID** são raramente usadas pelos programadores, mas talvez seja necessário consultar essas IDs ao substituir funções de estrutura que também se refiram aos **AFX_ID**s.

As IDs não são documentadas individualmente nesta referência. Você pode encontrar mais informações sobre eles nas notas técnicas [20](../../mfc/tn020-id-naming-and-numbering-conventions.md), [21](../../mfc/tn021-command-and-message-routing.md)e [22](../../mfc/tn022-standard-commands-implementation.md).

> [!NOTE]
>  O arquivo de cabeçalho Afxres. h está indiretamente incluído em Afxwin. h. Você deve incluir explicitamente a seguinte instrução no arquivo de script de recurso do aplicativo (. rc):

[!code-cpp[NVC_MFC_Utilities#47](../../mfc/codesnippet/cpp/standard-command-and-window-ids_1.h)]

## <a name="see-also"></a>Consulte também

[Macros e globais](../../mfc/reference/mfc-macros-and-globals.md)
