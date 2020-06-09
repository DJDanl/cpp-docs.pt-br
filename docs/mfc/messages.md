---
title: Mensagens
ms.date: 11/04/2016
helpviewer_keywords:
- messages, MFC
- messages [MFC]
ms.assetid: b1476310-a135-42ca-817c-444fb3675491
ms.openlocfilehash: f36dab679a2e41910b2445a7dab36f5786081563
ms.sourcegitcommit: c21b05042debc97d14875e019ee9d698691ffc0b
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 06/09/2020
ms.locfileid: "84624277"
---
# <a name="messages"></a>Mensagens

O loop de mensagem na `Run` função de membro da classe `CWinApp` recupera mensagens enfileiradas geradas por vários eventos. Por exemplo, quando o usuário clica no mouse, o Windows envia várias mensagens relacionadas ao mouse, como WM_LBUTTONDOWN quando o botão esquerdo do mouse é pressionado e WM_LBUTTONUP quando o botão esquerdo do mouse é liberado. A implementação da estrutura do loop de mensagem do aplicativo distribui a mensagem para a janela apropriada.

As categorias de mensagens importantes são descritas em [categorias de mensagens](message-categories.md).

## <a name="see-also"></a>Consulte também

[Mensagens e comandos no Framework](messages-and-commands-in-the-framework.md)
