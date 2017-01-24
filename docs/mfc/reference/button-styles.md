---
title: "Estilos de bot&#227;o | Microsoft Docs"
ms.custom: ""
ms.date: "12/10/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "article"
f1_keywords: 
  - "BS_DEFPUSHBUTTON"
  - "BS_NOTIFY"
  - "BS_MULTILINE"
  - "BS_AUTOCHECKBOX"
  - "BS_3STATE"
  - "BS_BITMAP"
  - "BS_TOP"
  - "BS_PUSHBUTTON"
  - "BS_PUSHLIKE"
  - "BS_AUTO3STATE"
  - "BS_CHECKBOX"
  - "BS_AUTORADIOBUTTON"
  - "BS_RADIOBUTTON"
  - "BS_OWNERDRAW"
  - "BS_LEFT"
  - "BS_USERBUTTON"
  - "BS_RIGHTBUTTON"
  - "BS_RIGHT"
  - "BS_LEFTTEXT"
  - "BS_TEXT"
  - "BS_BOTTOM"
  - "BS_GROUPBOX"
  - "BS_FLAT"
  - "BS_VCENTER"
  - "BS_ICON"
  - "BS_CENTER"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Constante BS_3STATE"
  - "Constante BS_AUTO3STATE"
  - "Constante BS_AUTOCHECKBOX"
  - "Constante BS_AUTORADIOBUTTON"
  - "Constante BS_BITMAP"
  - "Constante BS_BOTTOM"
  - "Constante BS_CENTER"
  - "Constante BS_CHECKBOX"
  - "Constante BS_DEFPUSHBUTTON"
  - "Constante BS_FLAT"
  - "Constante BS_GROUPBOX"
  - "Constante BS_ICON"
  - "Constante BS_LEFT"
  - "Constante BS_LEFTTEXT"
  - "Constante BS_MULTILINE"
  - "Constante BS_NOTIFY"
  - "Constante BS_OWNERDRAW"
  - "Constante BS_PUSHBUTTON"
  - "Constante BS_PUSHLIKE"
  - "Constante BS_RADIOBUTTON"
  - "Constante BS_RIGHT"
  - "Constante BS_RIGHTBUTTON"
  - "Constante BS_TEXT"
  - "Constante BS_TOP"
  - "Constante BS_USERBUTTON"
  - "Constante BS_VCENTER"
  - "objetos de botão (CButton), estilos de botão"
  - "estilos, objetos de botão"
ms.assetid: 41206f72-2b92-4250-ae32-31184046402f
caps.latest.revision: 20
caps.handback.revision: 15
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Estilos de bot&#227;o
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Este tópico descreve tipos e estilos de botão.  
  
## Tipos de botão  
 A tabela a seguir lista tipos de botão.  É possível escolher opcionalmente um dos seguintes:  Se você não especificar um tipo de botão, o padrão será `BS_PUSHBUTTON`.  
  
|Tipo|Descrição|  
|----------|---------------|  
|`BS_3STATE`|Cria um botão da caixa de seleção com três estados: `BST_CHECKED`, `BST_INDETERMINATE` e `BST_UNCHECKED`.  Clicar no botão envia uma notificação `BN_CLICKED` à janela do proprietário, mas não altera o estado do botão.  Por padrão, o texto associado é exibido à direita da caixa de seleção.  Para exibir texto à esquerda da caixa de seleção, use o estilo `BS_LEFTTEXT` ou `BS_RIGHTBUTTON`.|  
|`BS_AUTO3STATE`|Cria um botão da caixa de seleção com três estados: `BST_CHECKED`, `BST_INDETERMINATE` e `BST_UNCHECKED`.  Clicar no botão envia uma notificação `BN_CLICKED` à janela do proprietário e altera o estado do botão.  O botão indica o ciclo na ordem `BST_CHECKED`, `BST_INDETERMINATE` e `BST_UNCHECKED`.  Por padrão, o texto associado é exibido à direita da caixa de seleção.  Para exibir texto à esquerda da caixa de seleção, use o estilo `BS_LEFTTEXT` ou `BS_RIGHTBUTTON`.|  
|`BS_AUTOCHECKBOX`|Cria um botão da caixa de seleção com dois estados: `BST_CHECKED` e `BST_UNCHECKED`.  Clicar no botão envia uma notificação `BN_CLICKED` à janela do proprietário e altera o estado do botão.  Por padrão, o texto associado é exibido à direita da caixa de seleção.  Para exibir texto à esquerda da caixa de seleção, use o estilo `BS_LEFTTEXT` ou `BS_RIGHTBUTTON`.|  
|`BS_AUTORADIOBUTTON`|Cria um botão de opção com dois estados: `BST_CHECKED` e `BST_UNCHECKED`.  Botões de opção são geralmente usados em grupos, com cada grupo tendo um máximo de uma opção marcada por vez.  Clicar no botão envia uma notificação `BN_CLICKED` para a janela do proprietário, define o estado do botão de opção clicado como `BST_CHECKED` e define os estados de todos os outros botões de opção no grupo de botões como `BST_UNCHECKED`.  Por padrão, o texto associado é exibido à direita do botão de opção.  Para exibir texto à esquerda do botão de opção, use o estilo `BS_LEFTTEXT` ou `BS_RIGHTBUTTON`.|  
|`BS_CHECKBOX`|Cria um botão da caixa de seleção com dois estados: `BST_CHECKED` e `BST_UNCHECKED`.  Clicar no botão envia uma notificação `BN_CLICKED` à janela do proprietário, mas não altera o estado do botão.  Por padrão, o texto associado é exibido à direita da caixa de seleção.  Para exibir texto à esquerda da caixa de seleção, use o estilo `BS_LEFTTEXT` ou `BS_RIGHTBUTTON`.|  
|`BS_COMMANDLINK`|Cria um botão de link de comando.  Um botão de link de comando é um botão de comando específico para o [!INCLUDE[windowsver](../Token/windowsver_md.md)] que exibe uma seta verde à esquerda do texto principal e uma nota abaixo do texto principal.  É possível definir o texto de observação usando [CButton::SetNote](../Topic/CButton::SetNote.md).|  
|`BS_DEFCOMMANDLINK`|Cria um botão de link de comando.  Um botão de link de comando é um botão de comando específico para o [!INCLUDE[windowsver](../Token/windowsver_md.md)] que exibe uma seta verde à esquerda do texto principal e uma nota abaixo do texto principal.  É possível definir o texto de observação usando [CButton::SetNote](../Topic/CButton::SetNote.md).  Se o botão está em uma caixa de diálogo, pressionar a tecla ENTER envia uma notificação `BN_CLICKED` à caixa de diálogo mesmo quando o botão não tiver o foco de entrada.|  
|`BS_DEFPUSHBUTTON`|Cria um botão de comando que tem uma borda preta pesada.  Se o botão está em uma caixa de diálogo, pressionar a tecla ENTER envia uma notificação `BN_CLICKED` à caixa de diálogo mesmo quando o botão não tiver o foco de entrada.|  
|`BS_DEFSPLITBUTTON`|Cria um botão de divisão.  Um botão de divisão é um botão de comando específico para o [!INCLUDE[windowsver](../Token/windowsver_md.md)] que contém um botão adjacente a uma seta suspensa.  Ao clicar no botão, o comando padrão é executado.  Ao clicar na seta suspensa, um menu de comandos adicionais é exibido.  Se o botão de divisão está em uma caixa de diálogo, pressionar a tecla ENTER enviará uma notificação `BN_CLICKED` à caixa de diálogo mesmo quando o botão não tiver o foco de entrada.|  
|`BS_GROUPBOX`|Cria um retângulo em que outros botões podem ser agrupados.  O texto associado a esse estilo é exibido no canto superior esquerdo do retângulo.|  
|`BS_OWNERDRAW`|Cria um botão desenhado pelo proprietário.  A estrutura chama o método `DrawItem` quando um aspecto visual do botão é alterado.  Esse estilo deve ser definido ao usar a classe `CBitmapButton`.|  
|`BS_PUSHBUTTON`|Cria um botão de comando que envia uma notificação de `BN_CLICKED` à janela do proprietário quando o usuário clica no botão.|  
|`BS_RADIOBUTTON`|Cria um botão de opção com dois estados: `BST_CHECKED` e `BST_UNCHECKED`.  Botões de opção são geralmente usados em grupos, com cada grupo tendo um máximo de uma opção marcada por vez.  Clicar no botão envia uma notificação `BN_CLICKED` à janela do proprietário, mas não altera automaticamente o estado de qualquer botão no grupo.  Por padrão, o texto associado é exibido à direita do botão de opção.  Para exibir texto à esquerda do botão de opção, use o estilo `BS_LEFTTEXT` ou `BS_RIGHTBUTTON`.|  
|`BS_SPLITBUTTON`|Cria um botão de divisão.  Um botão de divisão é um botão de comando específico para o [!INCLUDE[windowsver](../Token/windowsver_md.md)] que contém um botão adjacente a uma seta suspensa.  Ao clicar no botão, o comando padrão é executado.  Ao clicar na seta suspensa, um menu de comandos adicionais é exibido.|  
|`BS_USERBUTTON`|Obsoleto, mas oferecido para compatibilidade com versões de 16 bits do Windows.  Os aplicativos baseados em Win32 devem usar `BS_OWNERDRAW` em vez disso.|  
  
## Estilos de botão de opção e de caixa de seleção  
 A tabela a seguir lista estilos específicos para botões de opção e caixas de seleção.  Esses estilos são ignorados em todos os outros tipos de botão.  É possível escolher opcionalmente um ou mais dos seguintes:  
  
|Style|Descrição|  
|-----------|---------------|  
|`BS_LEFTTEXT`|Quando combinado com um estilo de botão de opção ou de caixa de seleção, o texto aparece no lado esquerdo do botão de opção ou da caixa de seleção.|  
|`BS_RIGHTBUTTON`|Quando combinado com um estilo de botão de opção ou de caixa de seleção, o texto aparece no lado esquerdo do botão de opção ou da caixa de seleção.  Esse estilo é idêntico ao estilo `BS_LEFTTEXT`.|  
|`BS_PUSHLIKE`|Faz com que uma caixa de seleção ou um botão de opção se pareça e se comporte como um botão de comando.  O botão aparecerá pressionado quando seu estado for `BST_CHECKED`, pressionado e esmaecido quando seu estado for `BST_INDETERMINATE` e liberado quando seu estado for `BST_UNCHECKED`.|  
  
## Estilos de Alinhamento de Texto  
 A tabela a seguir lista opções de alinhamento de texto horizontal e vertical.  É possível escolher opcionalmente um dos seguintes:  
  
|Style|Descrição|  
|-----------|---------------|  
|`BS_LEFT`|Alinhamento do texto à esquerda no retângulo do botão.  No entanto, se o botão for uma caixa de seleção ou um botão de opção que não tem o estilo `BS_RIGHTBUTTON` , o texto é alinhado à esquerda no lado direito da caixa de seleção ou do botão de opção.|  
|`BS_RIGHT`|Alinhamento do texto à direita no retângulo do botão.  No entanto, se o botão for uma caixa de seleção ou um botão de opção que não tem o estilo `BS_RIGHTBUTTON` , o texto é alinhado à direita no lado direito da caixa de seleção ou do botão de opção.|  
|`BS_CENTER`|Centralize o texto horizontalmente no retângulo do botão.|  
|`BS_TOP`|Coloca texto na parte superior do retângulo do botão.|  
|`BS_BOTTOM`|Coloca texto na parte inferior do retângulo do botão.|  
|`BS_VCENTER`|Centraliza o texto verticalmente no retângulo do botão.|  
  
## Opções de conteúdo do botão  
 A tabela a seguir lista as opções que indicam o que é exibido no botão.  Os tipos de botão que exibem apenas texto ignoram esses estilos.  É possível escolher opcionalmente um dos seguintes:  
  
|Style|Descrição|  
|-----------|---------------|  
|`BS_BITMAP`|Especifica que o botão exiba um bitmap.|  
|`BS_ICON`|Especifica que o botão exiba um ícone.|  
|`BS_TEXT`|Especifica que o botão exiba texto.|  
  
## Outras opções  
 A tabela a seguir lista as opções adicionais que você pode usar com qualquer tipo de botão.  É possível escolher opcionalmente um ou mais dos seguintes:  
  
|Style|Descrição|  
|-----------|---------------|  
|`BS_FLAT`|Especifica que o botão é bidimensional e não é desenhado com o sombreamento padrão para criar uma imagem tridimensional.|  
|`BS_MULTILINE`|Ajusta o texto do botão para várias linhas se a cadeia de caracteres de texto for muito longa para caber em uma única linha no retângulo do botão.|  
|`BS_NOTIFY`|Habilita um botão para enviar mensagens de notificação `BN_DBLCLK`, `BN_KILLFOCUS` e `BN_SETFOCUS` à sua janela pai.  Observe que os botões enviam a notificação `BN_CLICKED` independentemente se esse estilo é especificado.|  
  
## Consulte também  
 [Estilos usados pelo MFC](../../mfc/reference/styles-used-by-mfc.md)   
 [CButton::Create](../Topic/CButton::Create.md)   
 [Estilos de botão](http://msdn.microsoft.com/library/windows/desktop/bb775951)   
 [BN\_CLICKED Notification](_win32_bn_clicked_notification)