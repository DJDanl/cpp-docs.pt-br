---
title: Estilos de janela estendidos | Documentos do Microsoft
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords:
- WS_EX_TOOLWINDOW
- WS_EX_LEFTSCROLLBAR
- WS_EX_RTLREADING
- WS_EX_WINDOWEDGE
- WS_EX_CLIENTEDGE
- WS_EX_STATICEDGE
- WS_EX_LTRREADING
- WS_EX_DLGMODALFRAME
- WS_EX_RIGHTSCROLLBAR
- WS_EX_CONTROLPARENT
- WS_EX_ACCEPTFILES
- WS_EX_TRANSPARENT
- WS_EX_RIGHT
- WS_EX_APPWINDOW
- WS_EX_TOPMOST
- WS_EX_CONTEXTHELP
- WS_EX_MDICHILD
- WS_EX_LEFT
- WS_EX_OVERLAPPEDWINDOW
- WS_EX_PALETTEWINDOW
- WS_EX_NOPARENTNOTIFY
dev_langs:
- C++
helpviewer_keywords:
- WS_EX_PALETTEWINDOW constant
- WS_EX_NOPARENTNOTIFY constant
- WS_EX_RIGHT constant
- WS_EX_DLGMODALFRAME constant
- WS_EX_APPWINDOW constant
- WS_EX_STATICEDGE constant
- WS_EX_LTRREADING constant
- WS_EX_RIGHTSCROLLBAR constant
- WS_EX_CONTROLPARENT constant
- WS_EX_MDICHILD constant
- WS_EX_TOPMOST constant
- WS_EX_RTLREADING constant
- WS_EX_LEFT constant
- WS_EX_TOOLWINDOW constant
- WS_EX_ACCEPTFILES constant
- WS_EX_WINDOWEDGE constant
- WS_EX_OVERLAPPEDWINDOW constant
- extended window styles
- WS_EX_LEFTSCROLLBAR constant
- WS_EX_TRANSPARENT constant
- WS_EX_CLIENTEDGE constant
- WS_EX_CONTEXTHELP constant
- styles, windows
ms.assetid: d18e6c69-0a01-49ed-b58a-55b3802b47c1
caps.latest.revision: 14
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
ms.openlocfilehash: e5a735ffcdaa78a4764e57b3c311979f24b7fdda
ms.lasthandoff: 02/25/2017

---
# <a name="extended-window-styles"></a>Estilos de janela estendidos
-   **WS_EX_ACCEPTFILES** Especifica que uma janela criada com esse estilo aceita arquivos de arrastar e soltar.  
  
-   **WS_EX_APPWINDOW** força uma janela de nível superior para a barra de tarefas quando a janela está visível.  
  
-   **WS_EX_CLIENTEDGE** Especifica que uma janela tem uma aparência 3D — ou seja, uma borda com uma borda em baixo-relevo.  
  
-   **WS_EX_CONTEXTHELP** inclui um ponto de interrogação na barra de título da janela. Quando o usuário clica no ponto de interrogação, o cursor muda para um ponto de interrogação com um ponteiro. Se o usuário clica em uma janela filho, o filho recebe um **WM_HELP** mensagem.  
  
-   **WS_EX_CONTROLPARENT** permite que o usuário navegar entre as janelas filho da janela usando a tecla TAB.  
  
-   **WS_EX_DLGMODALFRAME** designa uma janela com uma borda dupla (opcionalmente) pode ser criada com um barra de título ao especificar o **WS_CAPTION** sinalizador de estilo a `dwStyle` parâmetro.  
  
-   **WS_EX_LAYERED** a janela é uma [de janela em camadas](http://msdn.microsoft.com/library/ms632599.aspx#layered). Este estilo não pode ser usado se a janela tem uma [classe estilo](http://msdn.microsoft.com/library/ms633574.aspx#class_styles) do **CS_OWNDC** ou **CS_CLASSDC**. No entanto, [!INCLUDE[win8_first](../../mfc/reference/includes/win8_first_md.md)] oferece suporte a **WS_EX_LAYERED** estilo para janelas filho, em que versões anteriores do Windows o suporte somente para janelas de nível superior.  
  
-   **WS_EX_LEFT** fornece propriedades genéricas alinhado à esquerda da janela. Esse é o padrão.  
  
-   **WS_EX_LEFTSCROLLBAR** coloca uma barra de rolagem vertical à esquerda da área do cliente.  
  
-   **WS_EX_LTRREADING** exibe o texto da janela usando esquerda para direita ler propriedades de ordem. Esse é o padrão.  
  
-   **WS_EX_MDICHILD** cria uma janela filho MDI.  
  
-   **WS_EX_NOPARENTNOTIFY** Especifica que uma janela filho criada com esse estilo não enviará a `WM_PARENTNOTIFY` mensagem para sua janela pai quando a janela filho é criada ou destruída.  
  
-   **WS_EX_OVERLAPPEDWINDOW** combina o **WS_EX_CLIENTEDGE** e **WS_EX_WINDOWEDGE** estilos  
  
-   **WS_EX_PALETTEWINDOW** combina o **WS_EX_WINDOWEDGE** e **WS_EX_TOPMOST** estilos.  
  
-   **WS_EX_RIGHT** fornece uma janela de propriedades genéricas alinhado à direita. Isso depende da classe de janela.  
  
-   **WS_EX_RIGHTSCROLLBAR** coloca uma barra de rolagem vertical (se presente) à direita da área do cliente. Esse é o padrão.  
  
-   **WS_EX_RTLREADING** exibe o texto da janela usando a leitura da direita para esquerda solicitar propriedades.  
  
-   **WS_EX_STATICEDGE** cria uma janela com um estilo de borda tridimensional se destina a ser usado para itens que não aceitam entrada do usuário.  
  
-   **WS_EX_TOOLWINDOW** cria uma janela de ferramenta, que é uma janela que se destina a ser usada como uma barra de ferramentas flutuante. Uma janela de ferramentas tem uma barra de título que seja menor do que uma barra de títulos normal e o título da janela é desenhado usando uma fonte menor. Uma janela de ferramenta não aparecer na barra de tarefas ou na janela que aparece quando o usuário pressionar ALT + TAB.  
  
-   **WS_EX_TOPMOST** Especifica que uma janela criada com esse estilo deve ser colocada acima de tudo nontopmost windows e fique acima deles mesmo quando a janela é desativada. Um aplicativo pode usar o `SetWindowPos` a função de membro para adicionar ou remover esse atributo.  
  
-   **WS_EX_TRANSPARENT** Especifica que uma janela criada com esse estilo deve ser transparente. Ou seja, todas as janelas que estão sob a janela não são obscurecidas pela janela. Recebe uma janela criada com esse estilo `WM_PAINT` mensagens somente depois que todas as janelas de irmão abaixo dele foram atualizadas.  
  
-   **WS_EX_WINDOWEDGE** Especifica que uma janela tem uma borda com uma borda aumentada.  
  
## <a name="see-also"></a>Consulte também  
 [Estilos usados pelo MFC](../../mfc/reference/styles-used-by-mfc.md)   
 [CWnd::CreateEx](../../mfc/reference/cwnd-class.md#createex)   
 [CreateWindowEx](http://msdn.microsoft.com/library/windows/desktop/ms632680)


