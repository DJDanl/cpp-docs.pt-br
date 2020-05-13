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
ms.openlocfilehash: 04d9f2cf615636b151af93a3c3880f7357496048
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81365273"
---
# <a name="wizards-and-the-resource-editors"></a>Assistentes e os editores de recursos

Visual C++ inclui vários assistentes para uso na programação do MFC, juntamente com muitos editores de recursos integrados. Para a programação de controles ActiveX, o [ActiveX Control Wizard](../mfc/reference/mfc-activex-control-wizard.md) serve a um propósito muito parecido com o do MFC Application Wizard. Embora você possa escrever aplicativos MFC sem a maioria dessas ferramentas, as ferramentas simplificam e aceleram muito o seu trabalho.

## <a name="use-the-mfc-application-wizard-to-create-an-mfc-application"></a><a name="_core_use_appwizard_to_create_an_mfc_application"></a>Use o assistente de aplicativo do MFC para criar um aplicativo MFC

Use o [Assistente de Aplicativos Do MFC](../mfc/reference/mfc-application-wizard.md) para criar um projeto De MFC no Visual C++, que pode incluir o suporte ao OLE e ao banco de dados. Os arquivos do projeto contêm as classes de aplicativos, documentos, visualizações e janelas de quadros; recursos padrão, incluindo menus e uma barra de ferramentas opcional; outros arquivos windows necessários; e arquivos .rtf opcionais contendo tópicos padrão de ajuda do Windows que você pode revisar e aumentar para criar o arquivo de ajuda do seu programa.

## <a name="use-class-view-to-manage-classes-and-windows-messages"></a><a name="_core_use_classwizard_to_manage_classes_and_windows_messages"></a>Use a exibição de classe para gerenciar classes e mensagens do Windows

O Class View ajuda você a criar funções de manipulador para mensagens e comandos do Windows, criar e gerenciar classes, criar variáveis de membros de classe, criar métodos e propriedades de automação, criar classes de banco de dados e muito mais.

> [!NOTE]
> A exibição de classe também ajuda você a substituir funções virtuais nas classes MFC. Selecione a classe e a função virtual para substituir. O resto do processo é semelhante ao tratamento de mensagens, conforme descrito nos parágrafos a seguir.

Os aplicativos que são executados no Windows são [orientados por mensagens](../mfc/message-handling-and-mapping.md). Ações do usuário e outros eventos que ocorrem no programa em execução fazem com que o Windows envie mensagens para as janelas do programa. Por exemplo, se o usuário clicar no mouse em uma janela, o Windows envia uma mensagem WM_LBUTTONDOWN quando o botão esquerdo do mouse é pressionado e uma mensagem WM_LBUTTONUP quando o botão é liberado. O Windows também envia mensagens WM_COMMAND quando o usuário seleciona comandos na barra de menus.

Na estrutura do MFC, vários objetos, como documentos, visualizações, janelas de quadros, modelos de documentos e o objeto do aplicativo, podem "lidar" com mensagens. Tal objeto fornece uma "função de manipulador" como uma de suas funções de membro, e a estrutura mapeia a mensagem recebida para seu manipulador.

Grande parte de sua tarefa de programação é escolher quais mensagens mapear para quais objetos e, em seguida, implementar esse mapeamento. Para isso, você usa o Class View e o [Class Wizard](reference/mfc-class-wizard.md).

O [Assistente de Classe](reference/mfc-class-wizard.md) criará funções vazias de membro do manipulador de mensagens e você usará o editor de código fonte para implementar o corpo do manipulador. Você também pode criar ou editar classes (incluindo classes próprias, não derivadas de classes MFC) e seus membros com o Class View. Para obter mais informações sobre como usar a exibição de classe e sobre assistentes que adicionam código a um projeto, consulte [Adicionar funcionalidade com assistentes de código](../ide/adding-functionality-with-code-wizards-cpp.md).

## <a name="use-the-resource-editors-to-create-and-edit-resources"></a><a name="_core_use_the_resource_editors_to_create_and_edit_resources"></a>Use os editores de recursos para criar e editar recursos

Use os [editores de recursos](../windows/resource-editors.md) Do Visual C++ para criar e editar menus, caixas de diálogo, controles personalizados, teclas do acelerador, bitmaps, ícones, cursores, strings e recursos de versão. A partir da versão 4.0 do Visual C++, um editor de barras de ferramentas facilita muito a criação de barras de ferramentas.

Para ajudá-lo ainda mais, a Biblioteca de Classes da Microsoft Foundation fornece um arquivo chamado COMMON. RES, que contém recursos de "clip art" que você pode copiar do COMMON. RES e colar em seu próprio arquivo de recursos. Comum. O RES inclui botões de barra de ferramentas, cursores comuns, ícones e muito mais. Você pode usar, modificar e redistribuir esses recursos em sua aplicação. Para obter mais informações sobre COMMON. RES, veja a [amostra de Clipart.](../overview/visual-cpp-samples.md)

O Assistente de Aplicativos Do MFC, os assistentes Visuais C++, os editores de recursos e a estrutura do MFC trabalham muito para você e tornam o gerenciamento do seu código muito mais fácil. A maior parte do código específico do aplicativo está no documento e nas classes de exibição.

## <a name="see-also"></a>Confira também

[Usando as classes para escrever aplicativos para Windows](../mfc/using-the-classes-to-write-applications-for-windows.md)
