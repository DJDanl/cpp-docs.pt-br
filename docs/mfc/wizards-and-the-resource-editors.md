---
title: Assistentes e os editores de recursos | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-windows
ms.tgt_pltfrm: 
ms.topic: article
dev_langs:
- C++
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
caps.latest.revision: 
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: 1fd81a8548dbb746da4afa5b89bc49ee801cbaeb
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="wizards-and-the-resource-editors"></a>Assistentes e os editores de recursos
O Visual C++ inclui vários assistentes para uso na programação de MFC, juntamente com vários editores de recursos integrados. Para controles do ActiveX programação, o [Assistente de controle ActiveX](../mfc/reference/mfc-activex-control-wizard.md) serve a uma finalidade semelhante a que o Assistente de aplicativo do MFC. Enquanto você pode escrever aplicativos MFC sem a maioria dessas ferramentas, as ferramentas consideravelmente simplificarem e acelerar o seu trabalho.  
  
##  <a name="_core_use_appwizard_to_create_an_mfc_application"></a>Use o Assistente de aplicativo MFC para criar um aplicativo MFC  
 Use o [Assistente de aplicativo MFC](../mfc/reference/mfc-application-wizard.md) para criar um projeto no Visual C++, o que pode incluir OLE e suporte de banco de dados. Arquivos de projeto contém seu aplicativo, documento, exibição e classes de janela com moldura; recursos padrão, incluindo menus e uma barra de ferramentas opcional; outros necessários arquivos do Windows; e arquivos. rtf opcional que contém o padrão tópicos de Ajuda do Windows que você pode revisar e incrementar para criar o arquivo de Ajuda do seu programa.  
  
##  <a name="_core_use_classwizard_to_manage_classes_and_windows_messages"></a>Use o modo de exibição de classe para gerenciar Classes e mensagens do Windows  
 Ajuda do modo de exibição de classe criar funções de manipulador de mensagens do Windows e comandos, criar e gerenciar classes, criar variáveis de membro de classe, propriedades e métodos de automação, criar classes de banco de dados e muito mais.  
  
> [!NOTE]
>  Exibição de classe também ajuda você a substituir funções virtuais nas classes MFC. Selecione a classe e a função virtual para substituir. O restante do processo é semelhante ao tratamento de mensagens, conforme descrito nos parágrafos a seguir.  
  
 Aplicativos em execução no Windows são [mensagem direcionado](../mfc/message-handling-and-mapping.md). Ações de usuário e outros eventos que ocorrem no programa em execução com que o Windows enviar mensagens para o windows no programa. Por exemplo, se o usuário clica com o mouse em uma janela, o Windows envia um `WM_LBUTTONDOWN` quando o botão esquerdo do mouse é pressionado e uma mensagem `WM_LBUTTONUP` mensagem quando o botão é liberado. O Windows também envia **WM_COMMAND** mensagens quando o usuário seleciona os comandos da barra de menus.  
  
 Estrutura MFC, vários objetos, como documentos, exibições, janelas de quadro, modelos de documento e o objeto de aplicativo, podem "tratar" mensagens. Tal objeto fornece uma "função de manipulador" como um de seus membros funções e o framework mapeia a mensagem de entrada para seu manipulador.  
  
 Uma grande parte de sua tarefa de programação é escolher quais mensagens para mapear para quais objetos e, em seguida, Implementando esse mapeamento. Para fazer isso, você pode usar modo de exibição de classe e a janela Propriedades.  
  
 A janela Propriedades criará funções de membro de manipulador de mensagens vazia e você usar o editor de código fonte para implementar o corpo do manipulador. Você também pode criar ou editar classes (incluindo as classes de sua preferência, não derivados de classes MFC) e seus membros com o modo de exibição de classe. Para obter mais informações sobre como usar o modo de exibição de classe e sobre os assistentes que adicionar código a um projeto, consulte [adicionando funcionalidade com assistentes de código](../ide/adding-functionality-with-code-wizards-cpp.md).  
  
##  <a name="_core_use_the_resource_editors_to_create_and_edit_resources"></a>Use os editores de recursos para criar e editar recursos  
 Use o Visual C++ [editores de recursos](../windows/resource-editors.md) para criar e editar os menus, caixas de diálogo, controles personalizados, as teclas de aceleração, bitmaps, ícones, cursores, cadeias de caracteres e recursos de versão. A partir do Visual C++ versão 4.0, um editor de barra de ferramentas facilita criando barras de ferramentas muito mais.  
  
 Para ajudá-lo ainda mais, a biblioteca Microsoft Foundation Class fornece um arquivo chamado comum. RES, que contém recursos de "clip-art" que você pode copiar de comuns. RES e colar em seu próprio arquivo de recurso. COMUNS. RES inclui botões de barra de ferramentas, comuns cursores, ícones e muito mais. Você pode usar, modificar e redistribuir esses recursos em seu aplicativo. Para obter mais informações sobre comum. RES, consulte o [exemplo clip-art](../visual-cpp-samples.md).  
  
 O Assistente de aplicativo MFC, os assistentes do Visual C++, editores de recursos e a estrutura do MFC não muito trabalho para você e facilitar o gerenciamento de seu código muito mais fácil. A maior parte do seu código específico do aplicativo está em suas classes de documento e exibição.  
  
## <a name="see-also"></a>Consulte também  
 [Usando as classes para escrever aplicativos para Windows](../mfc/using-the-classes-to-write-applications-for-windows.md)
