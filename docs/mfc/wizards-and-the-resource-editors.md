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
ms.openlocfilehash: 41cbb86b4245bd78baecd222b5573ba5e877243a
ms.sourcegitcommit: c7f90df497e6261764893f9cc04b5d1f1bf0b64b
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/05/2019
ms.locfileid: "58773821"
---
# <a name="wizards-and-the-resource-editors"></a>Assistentes e os editores de recursos

O Visual C++ inclui vários assistentes para uso na programação do MFC, junto com muitos editores de recursos integrados. Para controles do ActiveX programação, o [Assistente de controle ActiveX](../mfc/reference/mfc-activex-control-wizard.md) serve a uma finalidade muito parecido com o Assistente de aplicativo do MFC. Embora você possa gravar aplicativos MFC sem a maioria dessas ferramentas, as ferramentas bastante simplificarem e acelerar seu trabalho.

##  <a name="_core_use_appwizard_to_create_an_mfc_application"></a> Use o Assistente de aplicativo do MFC para criar um aplicativo do MFC

Use o [Assistente de aplicativo MFC](../mfc/reference/mfc-application-wizard.md) para criar um projeto MFC no Visual C++, que pode incluir OLE e suporte de banco de dados. Arquivos no projeto contêm seu aplicativo, documento, exibição e classes de janela com moldura; recursos padrão, incluindo menus e uma barra de ferramentas opcional; outros necessários arquivos do Windows; e arquivos. rtf opcional que contém o padrão tópicos da Ajuda do Windows que você pode revisar e incrementar o para criar o arquivo de Ajuda do seu programa.

##  <a name="_core_use_classwizard_to_manage_classes_and_windows_messages"></a> Use o modo de exibição de classe para gerenciar Classes e as mensagens do Windows

Ajuda do modo de exibição de classe criar funções de manipulador de mensagens do Windows e comandos, criar e gerenciar classes, crie variáveis de membro de classe, criar propriedades e métodos de automação, criar classes de banco de dados e muito mais.

> [!NOTE]
>  Modo de exibição de classe também ajuda você a substituir funções virtuais nas classes do MFC. Selecione a classe e a função virtual para substituir. O restante do processo é semelhante à manipulação de mensagens, conforme descrito nos parágrafos a seguir.

São aplicativos em execução no Windows [mensagem controlado por](../mfc/message-handling-and-mapping.md). Ações de usuário e outros eventos que ocorrem no programa em execução fazem com que o Windows enviar mensagens para o windows no programa. Por exemplo, à se o usuário clica com o mouse em uma janela, o Windows envia uma mensagem WM_LBUTTONDOWN quando o botão esquerdo do mouse é pressionado e uma mensagem WM_LBUTTONUP quando o botão é liberado. Windows também envia mensagens WM_COMMAND quando o usuário seleciona os comandos da barra de menus.

No framework MFC, vários objetos, como documentos, exibições, janelas de quadro, modelos de documento e o objeto de aplicativo, podem "manipulam" as mensagens. Esse objeto fornece uma "função de manipulador" como um dos seus membros funções e o framework mapeia a mensagem de entrada para seu manipulador.

Uma grande parte da tarefa de programação é escolher quais mensagens para mapear para quais objetos e, em seguida, implementar esse mapeamento. Para fazer isso, você pode usar modo de exibição de classe e na janela Propriedades.

A janela Propriedades criará funções de membro vazio do manipulador de mensagens, e você usar o editor de código fonte para implementar o corpo do manipulador. Você também pode criar ou editar classes (incluindo suas próprias classes, não derivadas de classes do MFC) e seus membros com o modo de exibição de classe. Para obter mais informações sobre como usar o modo de exibição de classe e sobre os assistentes que adicionam o código a um projeto, consulte [adicionando funcionalidade com assistentes de código](../ide/adding-functionality-with-code-wizards-cpp.md).

##  <a name="_core_use_the_resource_editors_to_create_and_edit_resources"></a> Use os editores de recursos para criar e editar recursos

Usar o Visual C++ [editores de recursos](../windows/resource-editors.md) para criar e editar os menus, caixas de diálogo, controles personalizados, teclas de aceleração, bitmaps, ícones, cursores, cadeias de caracteres e recursos de versão. A partir do Visual C++ versão 4.0, um editor de barra de ferramentas facilita criar barras de ferramentas.

Para ajudá-lo ainda mais, a biblioteca Microsoft Foundation Class fornece um arquivo chamado comum. RES, que contém os recursos de "clip-art" que você pode copiar de comuns. RES e colado em seu próprio arquivo de recurso. COMUM. RES inclui botões de barra de ferramentas, cursores comuns, ícones e muito mais. Você pode usar, modificar e redistribuir esses recursos em seu aplicativo. Para obter mais informações sobre o comum. RES, consulte o [exemplo de clip-art](../overview/visual-cpp-samples.md).

O Assistente de aplicativo do MFC, os assistentes do Visual C++, editores de recursos e a estrutura MFC não muito trabalho para você e facilitar o gerenciamento de seu código muito mais fácil. A maior parte do seu código específico do aplicativo está em suas classes de documento e exibição.

## <a name="see-also"></a>Consulte também

[Usando as classes para escrever aplicativos para Windows](../mfc/using-the-classes-to-write-applications-for-windows.md)
