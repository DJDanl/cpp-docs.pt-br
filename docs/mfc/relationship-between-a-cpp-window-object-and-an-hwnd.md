---
title: Relação entre um objeto de janela do C++ e um HWND | Microsoft Docs
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
ms.openlocfilehash: b51daa375c3c920443316b6e10b6415ee018fdb4
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
ms.locfileid: "33385772"
---
# <a name="relationship-between-a-c-window-object-and-an-hwnd"></a>Relação entre um objeto de janela do C++ e um HWND
A janela *objeto* é um objeto do C++ `CWnd` classe (ou uma classe derivada) que o programa cria diretamente. Ela é ativada e desativada em resposta a chamadas de construtor e destruidor do programa. O Windows *janela*, por outro lado, é um identificador opaco para uma estrutura de dados interno do Windows que corresponde a uma janela e consome recursos do sistema quando presentes. Uma janela do Windows é identificada por um identificador de janela"" (`HWND`) e é criada após o `CWnd` objeto é criado por uma chamada para o **criar** função de membro de classe `CWnd`. A janela pode ser destruída por uma chamada do programa ou por uma ação do usuário. O identificador de janela é armazenado no objeto de janela `m_hWnd` variável de membro. A figura a seguir mostra a relação entre o objeto de janela C++ e a janela do Windows. Criando janelas é abordado em [criando Windows](../mfc/creating-windows.md). Destruindo janelas é abordado em [destruindo objetos de janela](../mfc/destroying-window-objects.md).  
  
 ![CWnd objeto de janela e janela resultante](../mfc/media/vc37fj1.gif "vc37fj1")  
Objeto de janela e janela do Windows  
  
## <a name="see-also"></a>Consulte também  
 [Objetos de janela](../mfc/window-objects.md)

