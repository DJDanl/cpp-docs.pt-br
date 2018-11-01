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
ms.openlocfilehash: 75ff46a829bd129c7f73bf11a303a67ab1526969
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50641110"
---
# <a name="sdi-and-mdi"></a>SDI e MDI

MFC torna mais fácil trabalhar com a interface de documento único (SDI) e aplicativos de interface de documentos múltiplos (MDI).

Aplicativos SDI permitem que apenas uma janela de quadro do documento aberto por vez. Aplicativos MDI permitir que o documento de várias janelas com moldura aberto na mesma instância de um aplicativo. Um aplicativo MDI tem uma janela dentro do qual MDI várias janelas filho, que são as próprias janelas de quadro, podem ser abertas, cada um contendo um documento separado. Em alguns aplicativos, as janelas filho podem ser de tipos diferentes, como janelas de gráfico e planilha. Nesse caso, a barra de menus pode alterar como as janelas MDI filho de tipos diferentes são ativadas.

> [!NOTE]
>  No Windows 95 e posterior, aplicativos são comumente SDI porque o sistema operacional adotou um modo de exibição "centralizado em documento".

Para obter mais informações, consulte [documentos, exibições e estrutura](../mfc/documents-views-and-the-framework.md).

## <a name="see-also"></a>Consulte também

[Usando as classes para escrever aplicativos para Windows](../mfc/using-the-classes-to-write-applications-for-windows.md)
