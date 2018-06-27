---
title: Objetos de janela | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-mfc
ms.topic: conceptual
dev_langs:
- C++
helpviewer_keywords:
- objects [MFC], window
- Windows window [MFC]
- MFC, windows
- frame windows [MFC], C++ window objects
- window objects [MFC]
- windows [MFC], C++ window objects
- window messages [MFC]
- HWND
- messages [MFC], Windows
- Visual C++, window objects [MFC]
- HWND, window objects [MFC]
ms.assetid: 28b33ce2-af05-4617-9d03-1cb9a02be687
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: f040978c898dae3bfd4ca21c2cf9886fde9b5238
ms.sourcegitcommit: c6b095c5f3de7533fd535d679bfee0503e5a1d91
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 06/26/2018
ms.locfileid: "36951266"
---
# <a name="window-objects"></a>Objetos de janela
MFC fornece a classe [CWnd](../mfc/reference/cwnd-class.md) para encapsular o `HWND` identificador de uma janela. O `CWnd` objeto é um objeto de janela C++, diferente de `HWND` que representa uma janela de janela, mas que o contém. Use `CWnd` derivar sua própria janela filho classes ou use uma das muitas classes MFC derivado de `CWnd`. Classe `CWnd` é a classe base para todas as janelas, incluindo janelas com moldura, caixas de diálogo, janelas filho, controles e barras de controle, como barras de ferramentas. Uma boa compreensão de [a relação entre um objeto de janela C++ e um HWND](../mfc/relationship-between-a-cpp-window-object-and-an-hwnd.md) é essencial para a programação eficaz com MFC.  
  
 MFC fornece alguma funcionalidade padrão e o gerenciamento do windows, mas você pode derivar sua própria classe de `CWnd` e usar suas funções de membro para personalizar a funcionalidade fornecida. Você pode criar janelas de filho, criando uma `CWnd` objeto e chamar sua [criar](../mfc/reference/cwnd-class.md#create) membro de função, em seguida, personalizar as janelas filho usando `CWnd` funções de membro. Você pode inserir objetos derivados de [CView](../mfc/reference/cview-class.md), como exibições de formulário ou modos de exibição de árvore, em uma janela do quadro. E você pode dar suporte a vários modos de exibição de documentos por meio de painéis do divisor, fornecidos pela classe [CSplitterWnd](../mfc/reference/csplitterwnd-class.md).  
  
 Cada objeto derivado da classe `CWnd` contém um mapa de mensagem, por meio do qual você pode mapear as mensagens do Windows ou IDs de comando para seus próprios manipuladores.  
  
 A literatura geral na programação para Windows é um bom recurso para aprender a usar o `CWnd` funções de membro, que encapsula o `HWND` APIs.  
  
## <a name="functions-for-operating-on-a-cwnd"></a>Funções para a operação em um CWnd  
 `CWnd` e seus [classes de janela derivadas](../mfc/derived-window-classes.md) fornecer funções de membro para inicializar o objeto de construtores e destruidores criam estruturas subjacentes do Windows e acessar o encapsulada `HWND`. `CWnd` também fornece funções de membro que encapsula as APIs do Windows para enviar mensagens, acessando o estado da janela, converter coordenadas, atualizar, rolagem, acessar a área de transferência e muitas outras tarefas. A maioria das APIs de gerenciamento de janela do Windows que usam um `HWND` argumento são encapsulados como funções de membro `CWnd`. Os nomes de funções e seus parâmetros serão preservados no `CWnd` função de membro. Para obter detalhes sobre as APIs do Windows encapsulado por `CWnd`, consulte a classe [CWnd](../mfc/reference/cwnd-class.md).  
  
## <a name="cwnd-and-windows-messages"></a>CWnd e mensagens do Windows  
 Uma das principais finalidades dos `CWnd` é fornecer uma interface para lidar com mensagens do Windows, como WM_PAINT ou WM_MOUSEMOVE. Muitas das funções de membro de `CWnd` são manipuladores para mensagens padrão — aquelas que começam com o identificador **afx_msg** e o prefixo "On", como `OnPaint` e `OnMouseMove`. [Manipulação e mapeamento de mensagem](../mfc/message-handling-and-mapping.md) abrange as mensagens e manipulação com detalhes de mensagens. As informações nesse local se aplica ao windows da estrutura e aquelas que você criou para fins especiais.  
  
### <a name="what-do-you-want-to-know-more-about"></a>O que você deseja saber mais sobre  
  
-   [A relação entre um objeto de janela C++ e um HWND](../mfc/relationship-between-a-cpp-window-object-and-an-hwnd.md)  
  
-   [Classes de janela derivadas](../mfc/derived-window-classes.md)  
  
-   [Criando janelas](../mfc/creating-windows.md)  
  
-   [Destruindo objetos de janela](../mfc/destroying-window-objects.md)  
  
-   [Desanexando um CWnd de seu HWND](../mfc/detaching-a-cwnd-from-its-hwnd.md)  
  
-   [Trabalhando com objetos de janela](../mfc/working-with-window-objects.md)  
  
-   [Contextos de dispositivo](../mfc/device-contexts.md): objetos que compõem o desenho de dispositivo do Windows independente  
  
-   [Objetos gráficos](../mfc/graphic-objects.md): canetas, pincéis, fontes, bitmaps, paletas, regiões  
  
## <a name="see-also"></a>Consulte também  
 [Windows](../mfc/windows.md)

