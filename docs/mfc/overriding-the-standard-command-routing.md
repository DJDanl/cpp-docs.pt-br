---
title: Substituindo o roteamento de comando padrão
ms.date: 11/04/2016
helpviewer_keywords:
- MFC, command routing
- command routing [MFC], overriding
- command handling [MFC], routing commands
- overriding, standard command routing
ms.assetid: 872b698a-7432-40c4-9008-68721e8effa5
ms.openlocfilehash: 680b185f8d68a834862bc0fe14bf6e7984effd65
ms.sourcegitcommit: c21b05042debc97d14875e019ee9d698691ffc0b
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 06/09/2020
ms.locfileid: "84617730"
---
# <a name="overriding-the-standard-command-routing"></a>Substituindo o roteamento de comando padrão

Em casos raros, quando você deve implementar alguma variação do roteamento de estrutura padrão, você pode substituí-lo. A ideia é alterar o roteamento em uma ou mais classes substituindo `OnCmdMsg` nessas classes. Faça isso:

- Na classe que interrompe a ordem a ser passada para um objeto não padrão.

- No novo objeto não padrão ou em destinos de comando, ele pode, por sua vez, passar comandos para.

Se você inserir um novo objeto no roteamento, sua classe deverá ser uma classe de destino de comando. Em suas versões de substituição do `OnCmdMsg` , certifique-se de chamar a versão que você está substituindo. Consulte a função membro [OnCmdMsg](reference/ccmdtarget-class.md#oncmdmsg) da classe `CCmdTarget` na *referência do MFC* e as versões dessas classes como `CView` e `CDocument` no código-fonte fornecido para obter exemplos.

## <a name="see-also"></a>Consulte também

[Como o Framework chama um manipulador](how-the-framework-calls-a-handler.md)
