---
title: Relação entre um objeto de janela do C++ e um HWND
ms.date: 11/19/2018
f1_keywords:
- HWND
helpviewer_keywords:
- Windows window [MFC]
- window objects [MFC], HWND and
- HWND [MFC]
- CWnd class [MFC], HWND
- HWND, window objects [MFC]
ms.assetid: f2e76340-6691-4ee6-9424-0345634a9469
ms.openlocfilehash: 8cf8856be7166768c507932184e257cf69b0eb35
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62309312"
---
# <a name="relationship-between-a-c-window-object-and-an-hwnd"></a>Relação entre um objeto de janela do C++ e um HWND

A janela *objeto* é um objeto de C++ `CWnd` classe (ou uma classe derivada) que seu programa cria diretamente. Ela é ativada e desativada em resposta a chamadas de construtor e destruidor do seu programa. O Windows *janela*, por outro lado, é um identificador opaco a uma estrutura de dados interno do Windows que corresponde a uma janela e consome recursos do sistema quando presentes. Uma janela do Windows é identificada por um "identificador de janela" (`HWND`) e é criada após o `CWnd` objeto é criado por uma chamada para o `Create` a função de membro da classe `CWnd`. A janela pode ser destruída por uma chamada do programa ou por uma ação do usuário. O identificador de janela é armazenado no objeto de janela *m_hWnd* variável de membro. A figura a seguir mostra a relação entre o objeto de janela C++ e a janela do Windows. Criando janelas é discutido [criando Windows](../mfc/creating-windows.md). Destruindo janelas com é discutida [destruindo objetos de janela](../mfc/destroying-window-objects.md).

![CWnd objeto de janela e a janela resultante](../mfc/media/vc37fj1.gif "CWnd objeto de janela e a janela resultante") <br/>
Objeto de janela e a janela do Windows

## <a name="see-also"></a>Consulte também

[Objetos de janela](../mfc/window-objects.md)
