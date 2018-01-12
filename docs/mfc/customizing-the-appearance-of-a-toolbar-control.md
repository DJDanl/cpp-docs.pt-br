---
title: "Personalizando a aparência de um controle de barra de ferramentas | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-windows
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords: TBSTYLE_
dev_langs: C++
helpviewer_keywords:
- flat toolbars
- CToolBar class [MFC], styles
- transparent toolbars
- TBSTYLE_ styles [MFC]
- CToolBarCtrl class [MFC], object styles
- toolbar controls [MFC], style
ms.assetid: fd0a73db-7ad1-4fe4-889b-02c3980f49e8
caps.latest.revision: "11"
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload: cplusplus
ms.openlocfilehash: 5c40b7e055585a11b90c2cec1fefb967b51b35cf
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="customizing-the-appearance-of-a-toolbar-control"></a>Personalizando a aparência de um controle de barra de ferramentas
Classe `CToolBarCtrl` fornece vários estilos que afetam a aparência (e, ocasionalmente, o comportamento) do objeto da barra de ferramentas. Modificar o objeto de barra de ferramentas, definindo o `dwCtrlStyle` parâmetro o `CToolBarCtrl::Create` (ou `CToolBar::CreateEx`) função de membro, quando você cria o controle de barra de ferramentas.  
  
 Os seguintes estilos afetam o aspecto de "3D" dos botões de barra de ferramentas e o posicionamento do texto do botão:  
  
-   **TBSTYLE_FLAT** cria uma barra de ferramentas simples em que a barra de ferramentas e os botões são transparentes. Texto do botão é exibido sob os bitmaps de botão. Quando esse estilo é usado, o botão sob o cursor automaticamente é realçado.  
  
-   **TBSTYLE_TRANSPARENT** cria uma barra de ferramentas transparente. Na barra de ferramentas transparente, a barra de ferramentas é transparente, mas os botões não estiverem. Texto do botão é exibido sob os bitmaps de botão.  
  
-   **TBSTYLE_LIST** locais de texto à direita do botão bitmaps de botão.  
  
> [!NOTE]
>  Para evitar problemas de redesenhar a **TBSTYLE_FLAT** e **TBSTYLE_TRANSPARENT** estilos devem ser definidos antes do objeto de barra de ferramentas está visível.  
  
 Os seguintes estilos determinam se a barra de ferramentas permite que um usuário reposicionar botões individuais dentro de um objeto de barra de ferramentas usando arrastar e soltar:  
  
-   **TBSTYLE_ALTDRAG** permite que os usuários alterar a posição de um botão barra de ferramentas arrastando-o enquanto mantém pressionada a tecla ALT. Se esse estilo não for especificado, o usuário deve manter pressionada a tecla SHIFT enquanto arrasta um botão.  
  
    > [!NOTE]
    >  O `CCS_ADJUSTABLE` estilo deve ser especificado para habilitar os botões da barra de ferramentas ser arrastado.  
  
-   **TBSTYLE_REGISTERDROP** gera **TBN_GETOBJECT** mensagens para solicitar descartam objetos de destino quando o ponteiro do mouse passa sobre botões da barra de notificação.  
  
 Os estilos restantes afetam os aspectos visuais e do objeto da barra de ferramentas:  
  
-   `TBSTYLE_WRAPABLE`Cria uma barra de ferramentas que pode ter várias linhas de botões. Botões da barra de ferramentas podem "encapsular" para a próxima linha quando ela se torne muito estreita para incluir todos os botões na mesma linha. Quebra automática ocorre em limites nongroup e separação.  
  
-   **TBSTYLE_CUSTOMERASE** gera **NM_CUSTOMDRAW** quando ele processa as mensagens de notificação `WM_ERASEBKGND` mensagens.  
  
-   `TBSTYLE_TOOLTIPS`Cria um controle de dica de ferramenta que um aplicativo pode usar para exibir o texto descritivo para os botões na barra de ferramentas.  
  
 Para obter uma lista completa de estilos de barra de ferramentas e estendidos, consulte [controle de barra de ferramentas e os estilos de botão](http://msdn.microsoft.com/library/windows/desktop/bb760439) e [estilos de barra de ferramentas estendido](http://msdn.microsoft.com/library/windows/desktop/bb760430) no SDK do Windows.  
  
## <a name="see-also"></a>Consulte também  
 [Usando CToolBarCtrl](../mfc/using-ctoolbarctrl.md)   
 [Controles](../mfc/controls-mfc.md)

