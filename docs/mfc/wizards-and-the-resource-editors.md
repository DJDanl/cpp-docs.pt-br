---
title: Assistentes e os editores de recursos
ms.date: 11/04/2016
helpviewer_keywords:
- application wizards [MFC], and MFC
- MFC, resource editors
- resource editors, MFC
- MFC Application Wizard
- editors [MFC], resource
- wizards [MFC]
- wizards [MFC], MFC programming
- MFC, wizards
- Class View tool, managing Windows messages
ms.assetid: f5dd4d13-9dc1-4a49-b6bf-5b3cb45fa8ba
ms.openlocfilehash: fb1a523ca82cd8e1a4256da657efe9702517beda
ms.sourcegitcommit: 3caf5261b3ea80d9cf14038c116ba981d655cd13
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/11/2019
ms.locfileid: "70907363"
---
# <a name="wizards-and-the-resource-editors"></a>Assistentes e os editores de recursos

O C++ Visual inclui vários assistentes para uso na programação do MFC, juntamente com muitos editores de recursos integrados. Para a programação de controles ActiveX, o [Assistente de controle ActiveX](../mfc/reference/mfc-activex-control-wizard.md) atende a uma finalidade muito parecida com a do assistente de aplicativo do MFC. Embora você possa escrever aplicativos MFC sem a maioria dessas ferramentas, as ferramentas simplificam muito e aceleram seu trabalho.

##  <a name="_core_use_appwizard_to_create_an_mfc_application"></a>Usar o assistente de aplicativo MFC para criar um aplicativo MFC

Use o [Assistente de aplicativo MFC](../mfc/reference/mfc-application-wizard.md) para criar um projeto MFC no C++Visual, que pode incluir o suporte a OLE e a banco de dados. Os arquivos no projeto contêm suas classes de aplicativo, documento, exibição e janela de quadro. recursos padrão, incluindo menus e uma barra de ferramentas opcional; outros arquivos do Windows necessários; e os arquivos. rtf opcionais que contêm tópicos de ajuda padrão do Windows que você pode revisar e aumentar para criar o arquivo de ajuda do programa.

##  <a name="_core_use_classwizard_to_manage_classes_and_windows_messages"></a>Usar Modo de Exibição de Classe para gerenciar classes e mensagens do Windows

Modo de Exibição de Classe ajuda a criar funções de manipulador para mensagens e comandos do Windows, criar e gerenciar classes, criar variáveis de membro de classe, criar métodos e propriedades de automação, criar classes de banco de dados e muito mais.

> [!NOTE]
>  Modo de Exibição de Classe também ajuda a substituir as funções virtuais nas classes do MFC. Selecione a classe e a função virtual a serem substituídas. O restante do processo é semelhante à manipulação de mensagens, conforme descrito nos parágrafos a seguir.

Aplicativos em execução no Windows são [orientados por mensagem](../mfc/message-handling-and-mapping.md). As ações do usuário e outros eventos que ocorrem no programa em execução fazem com que o Windows envie mensagens para as janelas do programa. Por exemplo, se o usuário clicar no mouse em uma janela, o Windows enviará uma mensagem WM_LBUTTONDOWN quando o botão esquerdo do mouse for pressionado e uma mensagem WM_LBUTTONUP quando o botão for liberado. O Windows também envia mensagens WM_COMMAND quando o usuário seleciona comandos na barra de menus.

Na estrutura do MFC, vários objetos, como documentos, exibições, janelas de quadros, modelos de documentos e o objeto de aplicativo, podem "manipular" mensagens. Tal objeto fornece uma "função de manipulador" como uma de suas funções membro, e a estrutura mapeia a mensagem de entrada para seu manipulador.

Uma grande parte da sua tarefa de programação é escolher quais mensagens mapear para quais objetos e, em seguida, implementar esse mapeamento. Para fazer isso, você usa Modo de Exibição de Classe e o [Assistente de classe](reference/mfc-class-wizard.md).

O [Assistente de classe](reference/mfc-class-wizard.md) criará funções de membro de manipulador de mensagens vazias e você usará o editor de código-fonte para implementar o corpo do manipulador. Você também pode criar ou editar classes (incluindo classes próprias, não derivadas de classes MFC) e seus membros com Modo de Exibição de Classe. Para obter mais informações sobre como usar Modo de Exibição de Classe e sobre assistentes que adicionam código a um projeto, consulte [adicionando funcionalidade com assistentes de código](../ide/adding-functionality-with-code-wizards-cpp.md).

##  <a name="_core_use_the_resource_editors_to_create_and_edit_resources"></a>Usar os editores de recursos para criar e editar recursos

Use os C++ [editores de recursos](../windows/resource-editors.md) visuais para criar e editar menus, caixas de diálogo, controles personalizados, teclas de aceleração, bitmaps, ícones, cursores, cadeias de caracteres e recursos de versão. A partir da C++ versão 4,0 do Visual, um editor de barra de ferramentas facilita muito a criação de barras de ferramentas.

Para ajudá-lo ainda mais, a biblioteca MFC fornece um arquivo chamado COMMON. RES, que contém recursos de "clip-art" que você pode copiar de comum. RES e cole em seu próprio arquivo de recursos. Common. RES inclui botões da barra de ferramentas, cursores comuns, ícones e muito mais. Você pode usar, modificar e redistribuir esses recursos em seu aplicativo. Para obter mais informações sobre o COMMON. RES, consulte o [exemplo de clipart](../overview/visual-cpp-samples.md).

O assistente de aplicativo do MFC, C++ os assistentes visuais, os editores de recursos e a estrutura MFC fazem muito trabalho para você e facilita muito o gerenciamento de seu código. A maior parte do código específico do aplicativo está no documento e na exibição de classes.

## <a name="see-also"></a>Consulte também

[Usando as classes para escrever aplicativos para Windows](../mfc/using-the-classes-to-write-applications-for-windows.md)
