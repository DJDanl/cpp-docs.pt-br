---
title: Estilos de botão | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-mfc
ms.topic: reference
f1_keywords:
- BS_DEFPUSHBUTTON
- BS_NOTIFY
- BS_MULTILINE
- BS_AUTOCHECKBOX
- BS_3STATE
- BS_BITMAP
- BS_TOP
- BS_PUSHBUTTON
- BS_PUSHLIKE
- BS_AUTO3STATE
- BS_CHECKBOX
- BS_AUTORADIOBUTTON
- BS_RADIOBUTTON
- BS_OWNERDRAW
- BS_LEFT
- BS_USERBUTTON
- BS_RIGHTBUTTON
- BS_RIGHT
- BS_LEFTTEXT
- BS_TEXT
- BS_BOTTOM
- BS_GROUPBOX
- BS_FLAT
- BS_VCENTER
- BS_ICON
- BS_CENTER
dev_langs:
- C++
helpviewer_keywords:
- BS_NOTIFY constant [MFC]
- BS_RIGHTBUTTON constant [MFC]
- styles [MFC], button objects
- BS_USERBUTTON constant [MFC]
- BS_VCENTER constant [MFC]
- BS_PUSHLIKE constant [MFC]
- BS_RADIOBUTTON constant [MFC]
- BS_PUSHBUTTON constant [MFC]
- BS_DEFPUSHBUTTON constant [MFC]
- BS_LEFTTEXT constant [MFC]
- button objects (CButton), button styles
- BS_AUTO3STATE constant [MFC]
- BS_3STATE constant [MFC]
- BS_OWNERDRAW constant [MFC]
- BS_AUTORADIOBUTTON constant [MFC]
- BS_GROUPBOX constant [MFC]
- BS_BITMAP constant [MFC]
- BS_CENTER constant [MFC]
- BS_MULTILINE constant [MFC]
- BS_BOTTOM constant [MFC]
- BS_FLAT constant [MFC]
- BS_AUTOCHECKBOX constant [MFC]
- BS_RIGHT constant [MFC]
- BS_CHECKBOX constant [MFC]
- BS_LEFT constant [MFC]
- BS_ICON constant [MFC]
- BS_TOP constant [MFC]
- BS_TEXT constant
ms.assetid: 41206f72-2b92-4250-ae32-31184046402f
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 3ec945c95b81570e52cca03ed4e52355350d8121
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
---
# <a name="button-styles"></a>Estilos de botão
Este tópico descreve os tipos de botão e estilos.  
  
## <a name="button-types"></a>Tipos de botão  
 A tabela a seguir lista os tipos de botão. Opcionalmente, você pode escolher uma das opções a seguir. Se você não especificar um tipo de botão, o padrão é `BS_PUSHBUTTON`.  
  
|Tipo|Descrição|  
|----------|-----------------|  
|`BS_3STATE`|Cria um botão de caixa de seleção com três estados: `BST_CHECKED`, `BST_INDETERMINATE`, e `BST_UNCHECKED`. Clicando no botão envia um `BN_CLICKED` notificação para a janela do proprietário, mas não altera o estado do botão. Por padrão, o texto associado é exibido à direita da caixa de seleção. Para exibir o texto à esquerda da caixa de seleção, use o `BS_LEFTTEXT` ou `BS_RIGHTBUTTON` estilo.|  
|`BS_AUTO3STATE`|Cria um botão de caixa de seleção com três estados: `BST_CHECKED`, `BST_INDETERMINATE`, e `BST_UNCHECKED`. Clicando no botão envia um `BN_CLICKED` notificação para a janela do proprietário e altera o estado do botão. O botão estados ciclo na ordem de `BST_CHECKED`, `BST_INDETERMINATE`, e `BST_UNCHECKED`. Por padrão, o texto associado é exibido à direita da caixa de seleção. Para exibir o texto à esquerda da caixa de seleção, use o `BS_LEFTTEXT` ou `BS_RIGHTBUTTON` estilo.|  
|`BS_AUTOCHECKBOX`|Cria um botão de caixa de seleção com dois estados: `BST_CHECKED` e `BST_UNCHECKED`. Clicando no botão envia um `BN_CLICKED` notificação para a janela do proprietário e altera o estado do botão. Por padrão, o texto associado é exibido à direita da caixa de seleção. Para exibir o texto à esquerda da caixa de seleção, use o `BS_LEFTTEXT` ou `BS_RIGHTBUTTON` estilo.|  
|`BS_AUTORADIOBUTTON`|Cria um botão de opção com dois estados: `BST_CHECKED` e `BST_UNCHECKED`. Botões de opção são geralmente usados em grupos, cada grupo com um máximo de uma opção de ativação cada vez. Clicando no botão envia um `BN_CLICKED` notificação para a janela do proprietário, define o estado do botão de opção clicado `BST_CHECKED`e define os estados de todos os outros botões de opção no grupo de botões para `BST_UNCHECKED`. Por padrão, o texto associado é exibido à direita do botão de opção. Para exibir o texto à esquerda do botão de opção, use o `BS_LEFTTEXT` ou `BS_RIGHTBUTTON` estilo.|  
|`BS_CHECKBOX`|Cria um botão de caixa de seleção com dois estados: `BST_CHECKED` e `BST_UNCHECKED`. Clicando no botão envia um `BN_CLICKED` notificação para a janela do proprietário, mas não altera o estado do botão. Por padrão, o texto associado é exibido à direita da caixa de seleção. Para exibir o texto à esquerda da caixa de seleção, use o `BS_LEFTTEXT` ou `BS_RIGHTBUTTON` estilo.|  
|`BS_COMMANDLINK`|Cria um botão de link de comando. Um botão de comando de link é um botão de comando específico para [!INCLUDE[windowsver](../../build/reference/includes/windowsver_md.md)] que exibe uma seta verde à esquerda do texto principal e uma observação abaixo do texto principal. Você pode definir o texto de anotação usando [CButton::SetNote](../../mfc/reference/cbutton-class.md#setnote).|  
|`BS_DEFCOMMANDLINK`|Cria um botão de link de comando. Um botão de comando de link é um botão de comando específico para [!INCLUDE[windowsver](../../build/reference/includes/windowsver_md.md)] que exibe uma seta verde à esquerda do texto principal e uma observação abaixo do texto principal. Você pode definir o texto de anotação usando [CButton::SetNote](../../mfc/reference/cbutton-class.md#setnote). Se o botão estiver em uma caixa de diálogo, pressionando ENTER chave envia um `BN_CLICKED` notificação para a caixa de diálogo, mesmo quando o botão não tem o foco de entrada.|  
|`BS_DEFPUSHBUTTON`|Cria um botão de comando que tenha uma pesada borda preta. Se o botão estiver em uma caixa de diálogo, pressionando ENTER chave envia um `BN_CLICKED` notificação para a caixa de diálogo, mesmo quando o botão não tem o foco de entrada.|  
|`BS_DEFSPLITBUTTON`|Cria um botão de divisão. Um botão de divisão é um botão de comando específico para [!INCLUDE[windowsver](../../build/reference/includes/windowsver_md.md)] que contém um botão adjacente a uma seta suspensa. Quando você clicar no botão, o comando padrão é executado. Quando você clica na seta suspensa, é exibido um menu de comandos adicionais. Se o botão de divisão está em uma caixa de diálogo, pressionando ENTER chave envia um `BN_CLICKED` notificação para a caixa de diálogo, mesmo quando o botão não tem o foco de entrada|  
|`BS_GROUPBOX`|Cria um retângulo no qual outros botões podem ser agrupados. Texto associado com este estilo é exibido no canto de superior esquerdo do retângulo.|  
|`BS_OWNERDRAW`|Cria um botão de desenho proprietário. O framework chama o `DrawItem` método quando um aspecto visual do botão foi alterado. Esse estilo deve ser definido quando você usa o `CBitmapButton` classe.|  
|`BS_PUSHBUTTON`|Cria um botão de comando que envia um `BN_CLICKED` notificação para a janela do proprietário, quando o usuário clica no botão.|  
|`BS_RADIOBUTTON`|Cria um botão de opção com dois estados: `BST_CHECKED` e `BST_UNCHECKED`. Botões de opção são geralmente usados em grupos, cada grupo com um máximo de uma opção de ativação cada vez. Clicando no botão envia um `BN_CLICKED` notificação para a janela do proprietário, mas não altera o estado de qualquer botão do grupo automaticamente. Por padrão, o texto associado é exibido à direita do botão de opção. Para exibir o texto à esquerda do botão de opção, use o `BS_LEFTTEXT` ou `BS_RIGHTBUTTON` estilo.|  
|`BS_SPLITBUTTON`|Cria um botão de divisão. Um botão de divisão é um botão de comando específico para [!INCLUDE[windowsver](../../build/reference/includes/windowsver_md.md)] que contém um botão adjacente a uma seta suspensa. Quando você clicar no botão, o comando padrão é executado. Quando você clica na seta suspensa, é exibido um menu de comandos adicionais.|  
|`BS_USERBUTTON`|Obsoleto, mas fornecida para compatibilidade com versões de 16 bits do Windows. Aplicativos Win32 devem usar `BS_OWNERDRAW` em vez disso.|  
  
## <a name="radio-button-and-check-box-styles"></a>Estilos de caixa de seleção e botão de opção  
 A tabela a seguir lista os estilos que são específicos para caixas de seleção e botões de opção. Esses estilos são ignorados em todos os outros tipos de botão. Opcionalmente, você pode escolher um ou mais dos procedimentos a seguir.  
  
|Estilo|Descrição|  
|-----------|-----------------|  
|`BS_LEFTTEXT`|Quando combinado com um estilo de caixa de seleção ou botão de opção, o texto aparece no lado esquerdo da caixa de seleção ou botão de opção.|  
|`BS_RIGHTBUTTON`|Quando combinado com um estilo de caixa de seleção ou botão de opção, o texto aparece no lado esquerdo da caixa de seleção ou botão de opção. Este estilo é idêntico de `BS_LEFTTEXT` estilo.|  
|`BS_PUSHLIKE`|Faz com que uma caixa de seleção ou botão de opção aparência e se comportam como um botão de comando. O botão aparece pressionado quando seu estado é `BST_CHECKED`, pressionado e esmaecido quando seu estado é `BST_INDETERMINATE`e liberada quando seu estado é `BST_UNCHECKED`.|  
  
## <a name="text-alignment-styles"></a>Estilos de alinhamento de texto  
 A tabela a seguir lista as opções de alinhamento de texto horizontal e vertical. Opcionalmente, você pode escolher uma das opções a seguir.  
  
|Estilo|Descrição|  
|-----------|-----------------|  
|`BS_LEFT`|Esquerda alinha o texto no retângulo de botão. No entanto, se o botão é uma caixa de seleção ou botão de opção que não tem o `BS_RIGHTBUTTON` estilo, o texto fica alinhado à direita da caixa de seleção ou botão de opção.|  
|`BS_RIGHT`|Direita alinha o texto no retângulo de botão. No entanto, se o botão é uma caixa de seleção ou botão de opção que não tem o `BS_RIGHTBUTTON` de estilo, o texto à direita é alinhado à direita da caixa de seleção ou botão de opção.|  
|`BS_CENTER`|Centraliza o texto horizontalmente no retângulo de botão.|  
|`BS_TOP`|Posiciona o texto na parte superior do retângulo de botão.|  
|`BS_BOTTOM`|Posiciona o texto na parte inferior do retângulo de botão.|  
|`BS_VCENTER`|Centraliza o texto verticalmente no retângulo de botão.|  
  
## <a name="button-content-options"></a>Opções de conteúdo do botão  
 A tabela a seguir lista as opções que indicam o que é exibido no botão. Tipos de botão que exibe apenas texto ignoram esses estilos. Opcionalmente, você pode escolher uma das opções a seguir.  
  
|Estilo|Descrição|  
|-----------|-----------------|  
|`BS_BITMAP`|Especifica que o botão exibe um bitmap.|  
|`BS_ICON`|Especifica que o botão exibe um ícone.|  
|`BS_TEXT`|Especifica que o botão exibe o texto.|  
  
## <a name="other-options"></a>Outras opções  
 A tabela a seguir lista as opções adicionais que você pode usar com qualquer tipo de botão. Opcionalmente, você pode escolher um ou mais dos procedimentos a seguir.  
  
|Estilo|Descrição|  
|-----------|-----------------|  
|`BS_FLAT`|Especifica que o botão é bidimensional e não é desenhado com sombreamento padrão para criar uma imagem tridimensional.|  
|`BS_MULTILINE`|Quebra o texto do botão para várias linhas se a cadeia de caracteres de texto for muito grande para caber em uma única linha no retângulo de botão.|  
|`BS_NOTIFY`|Permite que um botão Enviar `BN_DBLCLK`, `BN_KILLFOCUS`, e `BN_SETFOCUS` mensagens de notificação para sua janela pai. Observe que os botões Enviar o `BN_CLICKED` notificação independentemente desse estilo é especificado.|  
  
## <a name="see-also"></a>Consulte também  
 [Estilos usados pelo MFC](../../mfc/reference/styles-used-by-mfc.md)   
 [CButton::Create](../../mfc/reference/cbutton-class.md#create) [estilos de botão](http://msdn.microsoft.com/library/windows/desktop/bb775951)   



