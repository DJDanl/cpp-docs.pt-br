---
title: Comando padrão e IDs do Windows
ms.date: 11/04/2016
helpviewer_keywords:
- standard command and Window IDs
ms.assetid: 0424805c-fff8-4531-8f0c-15cfb13aa612
ms.openlocfilehash: a7f9e37702c686e13379d4034be94949f92e5e79
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81372951"
---
# <a name="standard-command-and-window-ids"></a>Comando padrão e IDs do Windows

A Biblioteca de Classes da Microsoft Foundation define uma série de IDs padrão de comando e janela em Afxres.h. Esses IDs são mais comumente usados dentro dos editores de recursos e do [Assistente de Classe](mfc-class-wizard.md) para mapear mensagens para suas funções de manipulador. Todos os comandos padrão têm um prefixo **ID_.** Por exemplo, quando você usa o editor de menu, você normalmente vincula o item do menu File Open ao iD de comando ID_FILE_OPEN padrão.

Para a maioria dos comandos padrão, o código do aplicativo não precisa se referir ao ID de`CWinThread`comando, porque a própria estrutura lida com os comandos através de mapas de mensagens em suas classes de quadro principal ( , `CWinApp` `CView`, , `CDocument`, e assim por diante).

Além dos IDs de comando padrão, uma série de outros IDs padrão são definidos que têm um prefixo de **AFX_ID**. Esses IDs incluem IDs de janela padrão **(prefixo AFX_IDW_),** IDs de seqüência **(prefixo AFX_IDS_),** e vários outros tipos.

IDs que começam com o prefixo **AFX_ID** raramente são usados por programadores, mas você pode precisar se referir a esses IDs ao sobrepor funções de estrutura que também se referem ao **AFX_ID**s.

Os IDs não são documentados individualmente nesta referência. Você pode encontrar mais informações sobre eles nas Notas Técnicas [20,](../../mfc/tn020-id-naming-and-numbering-conventions.md) [21](../../mfc/tn021-command-and-message-routing.md)e [22](../../mfc/tn022-standard-commands-implementation.md).

> [!NOTE]
> O arquivo de cabeçalho Afxres.h está indiretamente incluído em Afxwin.h. Você deve incluir explicitamente a seguinte instrução no arquivo de script de recurso do aplicativo (.rc):

[!code-cpp[NVC_MFC_Utilities#47](../../mfc/codesnippet/cpp/standard-command-and-window-ids_1.h)]

## <a name="see-also"></a>Confira também

[Macros e globais](../../mfc/reference/mfc-macros-and-globals.md)
