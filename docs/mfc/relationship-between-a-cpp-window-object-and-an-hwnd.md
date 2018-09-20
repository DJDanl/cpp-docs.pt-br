---
title: Relação entre um objeto de janela C++ e um HWND | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-mfc
ms.topic: conceptual
f1_keywords:
- HWND
dev_langs:
- C++
helpviewer_keywords:
- Windows window [MFC]
- window objects [MFC], HWND and
- HWND [MFC]
- CWnd class [MFC], HWND
- HWND, window objects [MFC]
ms.assetid: f2e76340-6691-4ee6-9424-0345634a9469
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 844f62b110f54ba3e2c8909a78d58c9f2c01dcac
ms.sourcegitcommit: 799f9b976623a375203ad8b2ad5147bd6a2212f0
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/19/2018
ms.locfileid: "46392808"
---
# <a name="relationship-between-a-c-window-object-and-an-hwnd"></a>Relação entre um objeto de janela do C++ e um HWND

A janela *objeto* é um objeto de C++ `CWnd` classe (ou uma classe derivada) que seu programa cria diretamente. Ela é ativada e desativada em resposta a chamadas de construtor e destruidor do seu programa. O Windows *janela*, por outro lado, é um identificador opaco a uma estrutura de dados interno do Windows que corresponde a uma janela e consome recursos do sistema quando presentes. Uma janela do Windows é identificada por um "identificador de janela" (`HWND`) e é criada após o `CWnd` objeto é criado por uma chamada para o `Create` a função de membro da classe `CWnd`. A janela pode ser destruída por uma chamada do programa ou por uma ação do usuário. O identificador de janela é armazenado no objeto de janela *m_hWnd* variável de membro. A figura a seguir mostra a relação entre o objeto de janela C++ e a janela do Windows. Criando janelas é discutido [criando Windows](../mfc/creating-windows.md). Destruindo janelas com é discutida [destruindo objetos de janela](../mfc/destroying-window-objects.md).

![CWnd objeto de janela e a janela resultante](../mfc/media/vc37fj1.gif "vc37fj1") objeto de janela e a janela do Windows

## <a name="see-also"></a>Consulte também

[Objetos de janela](../mfc/window-objects.md)

