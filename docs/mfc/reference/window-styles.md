---
title: Estilos de janela | Documentos do Microsoft
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords:
- WS_MINIMIZEBOX
- WS_SIZEBOX
- WS_CLIPCHILDREN
- WS_TILED
- WS_GROUP
- WS_VSCROLL
- WS_CHILD
- WS_TABSTOP
- WS_HSCROLL
- WS_THICKFRAME
- WS_DISABLED
- WS_POPUP
- WS_ICONIC
- WS_MAXIMIZE
- WS_VISIBLE
- WS_POPUPWINDOW
- WS_TILEDWINDOW
- WS_DLGFRAME
- WS_MINIMIZE
- WS_CAPTION
- WS_OVERLAPPED
- WS_BORDER
- WS_MAXIMIZEBOX
- WS_OVERLAPPEDWINDOW
- WS_SYSMENU
- WS_CHILDWINDOW
- WS_CLIPSIBLINGS
dev_langs:
- C++
helpviewer_keywords:
- WS_THICKFRAME constant
- WS_TILEDWINDOW constant
- WS_MAXIMIZEBOX constant
- WS_DLGFRAME constant
- WS_CHILDWINDOW constant
- window styles, in MFC
- WS_CHILD constant
- WS_GROUP constant
- WS_MINIMIZE constant
- WS_CAPTION constant
- WS_MAXIMIZE constant
- WS_POPUP constant
- WS_SYSMENU constant
- WS_TILED constant
- window styles
- WS_POPUPWINDOW constant
- WS_CLIPSIBLINGS constant
- WS_BORDER constant
- WS_DISABLED constant
- WS_VSCROLL constant
- WS_OVERLAPPED constant
- WS_MINIMIZEBOX constant
- WS_VISIBLE constant
- WS_OVERLAPPEDWINDOW constant
- WS_TABSTOP constant
- WS_ICONIC constant
- WS_SIZEBOX constant
- WS_HSCROLL constant
- WS_CLIPCHILDREN constant
- styles, windows
ms.assetid: c85ffbe4-f4ff-4227-917a-48ec4a411842
caps.latest.revision: 12
author: mikeblome
ms.author: mblome
manager: ghogen
translation.priority.ht:
- cs-cz
- de-de
- es-es
- fr-fr
- it-it
- ja-jp
- ko-kr
- pl-pl
- pt-br
- ru-ru
- tr-tr
- zh-cn
- zh-tw
translationtype: Machine Translation
ms.sourcegitcommit: 040985df34f2613b4e4fae29498721aef15d50cb
ms.openlocfilehash: d814e3a10132fb3fe88969ce434f8286b02afba5
ms.lasthandoff: 02/25/2017

---
# <a name="window-styles"></a>Estilos de janela
-   `WS_BORDER`Cria uma janela que tem uma borda.  
  
-   **WS_CAPTION** cria uma janela com uma barra de título (implica o `WS_BORDER` estilo). Não pode ser usado com o **WS_DLGFRAME** estilo.  
  
-   **Estilo** cria uma janela filho. Não pode ser usado com o `WS_POPUP` estilo.  
  
-   **WS_CHILDWINDOW** igual a **WS_CHILD** estilo.  
  
-   **WS_CLIPCHILDREN** exclui a área ocupada pelas janelas filho quando você desenhar dentro da janela pai. Usado quando você cria a janela pai.  
  
-   **WS_CLIPSIBLINGS** janelas filho de clipes em relação umas às outras; ou seja, quando uma janela filho específico recebe uma mensagem de pintura, o **WS_CLIPSIBLINGS** estilo Recorta todas as outras janelas sobrepostas filho não a região da janela filho a ser atualizado. (Se **WS_CLIPSIBLINGS** não for fornecido e sobreposição de windows do filho, quando você desenha na área do cliente de uma janela filho, é possível desenhar na área do cliente de uma janela filho vizinhos.) Para uso com o **WS_CHILD** somente de estilo.  
  
-   **WS_DISABLED** cria uma janela que é inicialmente desabilitada.  
  
-   **WS_DLGFRAME** cria uma janela com uma borda dupla, mas sem título.  
  
-   **WS_GROUP** Especifica o primeiro controle de um grupo de controles em que o usuário pode mover de um controle próximo com as teclas de direção. Todos os controles definidos com o **WS_GROUP** estilos **FALSE** após o primeiro controle pertencem ao mesmo grupo. O próximo controle com o **WS_GROUP** estilo inicia o próximo grupo (ou seja, termina um grupo onde começa o próximo).  
  
-   **WS_HSCROLL** cria uma janela que tem uma barra de rolagem horizontal.  
  
-   **WS_ICONIC** cria uma janela que inicialmente é minimizada. Mesmo que o **WS_MINIMIZE** estilo.  
  
-   **WS_MAXIMIZE** cria uma janela de tamanho máximo.  
  
-   **WS_MAXIMIZEBOX** cria uma janela com um botão maximizar.  
  
-   **WS_MINIMIZE** cria uma janela que inicialmente é minimizada. Para uso com o **WS_OVERLAPPED** somente de estilo.  
  
-   **WS_MINIMIZEBOX** cria uma janela com um botão Minimizar.  
  
-   **WS_OVERLAPPED** cria uma janela sobreposta. Uma janela sobreposta normalmente tem uma legenda e uma borda.  
  
-   **WS_OVERLAPPEDWINDOW** cria uma janela sobreposta com o **WS_OVERLAPPED**, **WS_CAPTION**, **WS_SYSMENU**, **WS_THICKFRAME**, **WS_MINIMIZEBOX**, e **WS_MAXIMIZEBOX** estilos.  
  
-   `WS_POPUP`Cria uma janela pop-up. Não pode ser usado com o **WS_CHILD** estilo.  
  
-   **WS_POPUPWINDOW** cria uma janela pop-up com a `WS_BORDER`, `WS_POPUP`, e **WS_SYSMENU** estilos. O **WS_CAPTION** estilo deve ser combinado com a **WS_POPUPWINDOW** estilo para tornar visível o menu de controle.  
  
-   **WS_SIZEBOX** cria uma janela que tem uma borda de dimensionamento. Mesmo que o **WS_THICKFRAME** estilo.  
  
-   **WS_SYSMENU** cria uma janela que tenha uma caixa do menu de controle em sua barra de título. Usado somente para janelas com barras de título.  
  
-   **WS_TABSTOP** Especifica um número de controles por meio do qual o usuário pode mover usando a tecla TAB. A tecla TAB move o usuário para o próximo controle especificado pelo **WS_TABSTOP** estilo.  
  
-   **WS_THICKFRAME** cria uma janela com um quadro espesso que pode ser usado para dimensionar a janela.  
  
-   **WS_TILED** cria uma janela sobreposta. Uma janela sobreposta tem uma barra de título e uma borda. Mesmo que o **WS_OVERLAPPED** estilo.  
  
-   **WS_TILEDWINDOW** cria uma janela sobreposta com o **WS_OVERLAPPED**, **WS_CAPTION**, **WS_SYSMENU**, **WS_THICKFRAME**, **WS_MINIMIZEBOX**, e **WS_MAXIMIZEBOX** estilos. Mesmo que o **WS_OVERLAPPEDWINDOW** estilo.  
  
-   **WS_VISIBLE** cria uma janela que é visível inicialmente.  
  
-   **WS_VSCROLL** cria uma janela que tem uma barra de rolagem vertical.  
  
## <a name="see-also"></a>Consulte também  
 [Estilos usados pelo MFC](../../mfc/reference/styles-used-by-mfc.md)   
 [CWnd::Create](../../mfc/reference/cwnd-class.md#create)   
 [CWnd::CreateEx](../../mfc/reference/cwnd-class.md#createex)   
 [CreateWindow](http://msdn.microsoft.com/library/windows/desktop/ms632679)


