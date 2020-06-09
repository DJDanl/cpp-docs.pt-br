---
title: Como mensagens sem comando alcançam os identificadores
ms.date: 11/04/2016
helpviewer_keywords:
- messages [MFC], routing
- noncommand messages
- Windows messages [MFC], routing
- message handling [MFC], noncommand messages
ms.assetid: e7df8aef-9fae-41f4-9c11-881d8465f602
ms.openlocfilehash: c7b2bf819c5305da4039fae172578298d3b4e609
ms.sourcegitcommit: c21b05042debc97d14875e019ee9d698691ffc0b
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 06/09/2020
ms.locfileid: "84618503"
---
# <a name="how-noncommand-messages-reach-their-handlers"></a>Como mensagens sem comando alcançam os identificadores

Diferentemente dos comandos, as mensagens padrão do Windows não são roteadas por meio de uma cadeia de destinos de comando, mas geralmente são manipuladas pela janela para a qual o Windows envia a mensagem. A janela pode ser uma janela de quadro principal, uma janela filho MDI, um controle padrão, uma caixa de diálogo, uma exibição ou algum outro tipo de janela filho.

Em tempo de execução, cada janela do Windows é anexada a um objeto de janela (derivado diretamente ou indiretamente do `CWnd` ) que tem suas próprias funções de manipulador e de mapeamento de mensagem associadas. A estrutura usa o mapa de mensagens — como para um comando — para mapear mensagens de entrada para manipuladores.

## <a name="see-also"></a>Consulte também

[Como o Framework chama um manipulador](how-the-framework-calls-a-handler.md)
