---
title: Estilos de janela com moldura (C++)
ms.date: 11/04/2016
helpviewer_keywords:
- window styles [MFC]
- PreCreateWindow method, setting window styles
- windows [MFC], MFC
- frame windows [MFC], styles
- MFC, frame windows
- styles [MFC], windows
ms.assetid: fc5058c1-eec8-48d8-9f76-3fc01cfa53f7
ms.openlocfilehash: 3c22944537370a44aee1af1cf71281264ed4969b
ms.sourcegitcommit: c21b05042debc97d14875e019ee9d698691ffc0b
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 06/09/2020
ms.locfileid: "84626452"
---
# <a name="frame-window-styles-c"></a>Estilos de janela com moldura (C++)

As janelas de quadros obtidas com a estrutura são adequadas para a maioria dos programas, mas você pode obter mais flexibilidade usando as funções avançadas [PreCreateWindow](reference/cwnd-class.md#precreatewindow) e a função global do MFC [AfxRegisterWndClass](reference/application-information-and-management.md#afxregisterwndclass). `PreCreateWindow`é uma função membro do `CWnd` .

Se você aplicar os estilos de **WS_HSCROLL** e **WS_VSCROLL** à janela do quadro principal, eles serão aplicados à janela **MdiClient** para que os usuários possam rolar a área **MdiClient** .

Se o bit do estilo de **FWS_ADDTOTITLE** da janela for definido (que é por padrão), a exibição informará à janela do quadro qual título exibir na barra de título da janela com base no nome do documento da exibição.

## <a name="what-do-you-want-to-know-more-about"></a>Do que você deseja saber mais sobre

- [Gerenciando janelas filho MDI (MDICLIENT)](managing-mdi-child-windows.md), a janela em um quadro MDI que contém as janelas filho MDI

- [Alternando os estilos de uma janela criada por MFC](changing-the-styles-of-a-window-created-by-mfc.md)

- [Estilos de janela](reference/styles-used-by-mfc.md#window-styles)

## <a name="see-also"></a>Consulte também

[Janelas com moldura](frame-windows.md)
