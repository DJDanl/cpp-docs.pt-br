---
title: Mensagens | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-mfc
ms.topic: conceptual
dev_langs:
- C++
helpviewer_keywords:
- messages, MFC
- messages [MFC]
ms.assetid: b1476310-a135-42ca-817c-444fb3675491
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: f25c9cc70cec598f975bbd242af83597311bdc7c
ms.sourcegitcommit: 799f9b976623a375203ad8b2ad5147bd6a2212f0
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/19/2018
ms.locfileid: "46392249"
---
# <a name="messages"></a>Mensagens

O loop de mensagem na `Run` função de membro da classe `CWinApp` recupera na fila de mensagens geradas por vários eventos. Por exemplo, quando o usuário clica com o mouse, o Windows envia várias mensagens relacionados ao mouse, como WM_LBUTTONDOWN quando o botão esquerdo do mouse é pressionado e WM_LBUTTONUP quando o botão esquerdo do mouse é liberado. A implementação da estrutura de loop de mensagem do aplicativo expede a mensagem na janela apropriada.

As categorias importantes de mensagens são descritas em [categorias de mensagem](../mfc/message-categories.md).

## <a name="see-also"></a>Consulte também

[Mensagens e comandos no Framework](../mfc/messages-and-commands-in-the-framework.md)

