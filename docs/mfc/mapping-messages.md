---
title: Mapeando mensagens
ms.date: 11/04/2016
helpviewer_keywords:
- message maps [MFC], about message maps
- mappings [MFC], commands
- commands [MFC], mapping
- command mapping [MFC]
- message handling [MFC], connecting to handler functions
- commands [MFC], connecting to handler functions
- mappings [MFC], messages
- messages [MFC], mapping
ms.assetid: 996f0652-0698-4b8c-b893-cdaa836d9d0f
ms.openlocfilehash: 16d6d7725d82bed6c9bfc02e408b68dcf7ffe5e4
ms.sourcegitcommit: c21b05042debc97d14875e019ee9d698691ffc0b
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 06/09/2020
ms.locfileid: "84625498"
---
# <a name="mapping-messages"></a>Mapeando mensagens

Cada classe de estrutura que pode receber mensagens ou comandos tem seu próprio "mapa de mensagens". A estrutura usa mapas de mensagem para conectar mensagens e comandos às suas funções de manipulador. Qualquer classe derivada da classe `CCmdTarget` pode ter um mapa de mensagens. Outros artigos explicam os mapas de mensagens em detalhes e descrevem como usá-los.

Apesar do nome "mapa de mensagens", os mapas de mensagens lidam com mensagens e comandos — todas as três categorias de mensagens listadas em [categorias de mensagens](message-categories.md).

## <a name="see-also"></a>Consulte também

[Mensagens e comandos no Framework](messages-and-commands-in-the-framework.md)
