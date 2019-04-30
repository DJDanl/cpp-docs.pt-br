---
title: Como mensagens sem comando alcançam os identificadores
ms.date: 11/04/2016
helpviewer_keywords:
- messages [MFC], routing
- noncommand messages
- Windows messages [MFC], routing
- message handling [MFC], noncommand messages
ms.assetid: e7df8aef-9fae-41f4-9c11-881d8465f602
ms.openlocfilehash: 4b9fb0a72b330380f0207db9968199a7e4c3d9b3
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62407933"
---
# <a name="how-noncommand-messages-reach-their-handlers"></a>Como mensagens sem comando alcançam os identificadores

Diferentemente dos comandos, mensagens padrão do Windows não sejam roteadas por meio de uma cadeia de comando destinos, mas geralmente são manipuladas pela janela para o qual o Windows envia a mensagem. A janela pode ser uma janela do quadro principal, uma janela filho MDI, um controle padrão, uma caixa de diálogo, uma exibição ou algum outro tipo de janela filho.

Em tempo de execução, cada janela de Windows é anexada a um objeto de janela (derivado direta ou indiretamente de `CWnd`) que tem suas próprias funções de mapa e o manipulador de mensagem associado. A estrutura usa o mapa da mensagem — como para um comando — para mapear as mensagens de entrada para manipuladores.

## <a name="see-also"></a>Consulte também

[Como o Framework chama um manipulador](../mfc/how-the-framework-calls-a-handler.md)
