---
title: SDI e MDI
ms.date: 11/04/2016
helpviewer_keywords:
- frame windows [MFC], SDI applications
- frame windows [MFC], MDI applications
- MFC, windows
- single document interface (SDI) [MFC], applications
- MDI [MFC], vs. SDI
ms.assetid: bb7239d9-4759-4f63-bfff-44a04b48c067
ms.openlocfilehash: 9730e7baf9589c4b05a60703c619aae2e941bdec
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81372764"
---
# <a name="sdi-and-mdi"></a>SDI e MDI

O MFC facilita o trabalho com aplicativos De interface de documento único (SDI) e De interface de vários documentos (MDI).

Os aplicativos SDI permitem apenas uma janela aberta de quadro de documento por vez. Os aplicativos MDI permitem que várias janelas de quadros de documentos sejam abertas na mesma instância de um aplicativo. Um aplicativo MDI tem uma janela dentro da qual várias janelas de crianças MDI, que são as próprias janelas do quadro, podem ser abertas, cada uma contendo um documento separado. Em alguns aplicativos, as janelas de crianças podem ser de diferentes tipos, como janelas de gráficos e janelas de planilhas. Nesse caso, a barra de menu pode mudar à medida que janelas infantis MDI de diferentes tipos são ativadas.

> [!NOTE]
> No Windows 95 e posteriores, os aplicativos são comumente SDI porque o sistema operacional adotou uma visão "centrada em documentos".

Para obter mais informações, consulte [Documentos, Visualizações e o Quadro](../mfc/documents-views-and-the-framework.md).

## <a name="see-also"></a>Confira também

[Usando as classes para escrever aplicativos para Windows](../mfc/using-the-classes-to-write-applications-for-windows.md)
