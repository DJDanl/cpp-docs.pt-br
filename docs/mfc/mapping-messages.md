---
title: Mapeando mensagens | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-mfc
ms.topic: conceptual
dev_langs:
- C++
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
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 7324da5eaff15d240cabbaede2c2982021361257
ms.sourcegitcommit: 799f9b976623a375203ad8b2ad5147bd6a2212f0
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/19/2018
ms.locfileid: "46410970"
---
# <a name="mapping-messages"></a>Mapeando mensagens

Cada classe de estrutura que pode receber mensagens ou comandos tem seu próprio "mapa de mensagens". A estrutura usa mapas de mensagem para se conectar a mensagens e comandos para suas funções do manipulador. Qualquer classe derivada da classe `CCmdTarget` pode ter um mapa de mensagem. Outros artigos explicam os mapas de mensagem em detalhes e descrevem como usá-los.

Apesar do nome "mapa de mensagens," mensagem manipulam mapas de mensagens e comandos — todas as três categorias de mensagens listados na [categorias de mensagem](../mfc/message-categories.md).

## <a name="see-also"></a>Consulte também

[Mensagens e comandos no Framework](../mfc/messages-and-commands-in-the-framework.md)

