---
title: Substituindo o roteamento de comando padrão
ms.date: 11/04/2016
helpviewer_keywords:
- MFC, command routing
- command routing [MFC], overriding
- command handling [MFC], routing commands
- overriding, standard command routing
ms.assetid: 872b698a-7432-40c4-9008-68721e8effa5
ms.openlocfilehash: 5383c1053894d44e23baf51b19ac3df4e60158e5
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62410155"
---
# <a name="overriding-the-standard-command-routing"></a>Substituindo o roteamento de comando padrão

Em casos raros quando você deve implementar algumas variações do roteamento de estrutura padrão, você pode substituí-la. A ideia é alterar o roteamento em uma ou mais classes por meio da substituição `OnCmdMsg` nessas classes. Fazer isso:

- Na classe que interrompe a ordem para passar para um objeto não padrão.

- No novo objeto não padrão ou em destinos de comando-lo por sua vez pode passar comandos para.

Se você inserir algum objeto novo em roteamento, sua classe deve ser uma classe de destino do comando. Em suas versões de substituição do `OnCmdMsg`, certifique-se de chamar a versão que você está substituindo. Consulte a [OnCmdMsg](../mfc/reference/ccmdtarget-class.md#oncmdmsg) função de membro da classe `CCmdTarget` no *referência da MFC* e as versões em tais classes como `CView` e `CDocument` no código-fonte fornecido para obter exemplos.

## <a name="see-also"></a>Consulte também

[Como o Framework chama um manipulador](../mfc/how-the-framework-calls-a-handler.md)
