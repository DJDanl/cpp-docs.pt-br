---
title: "Alternando controles de caixa de diálogo e código | Microsoft Docs"
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
- events [C++], viewing for controls
- Windows messages [C++], controls
- messages [C++], viewing for dialog boxes
- Dialog editor, accessing code
- code [C++], switching from Dialog Editor
- controls [C++], jumping to code
- Dialog editor, switching between controls and code
ms.assetid: 7da73815-b853-4203-ba45-bbe570695122
caps.latest.revision: 
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload:
- cplusplus
- uwp
ms.openlocfilehash: 81f8ea53cf6c4428913ce7ebfa4183c135208024
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="switching-between-dialog-box-controls-and-code"></a>Alternando controles de caixa de diálogo e código
Em aplicativos MFC, você pode clicar duas vezes em controles de caixa de diálogo para ir para o seu código de manipulador de ou para criar rapidamente o stub de funções de manipulador.  
  
 Com um controle selecionado, clique no **ControlEvents** botão ou o **mensagens** no botão de [janela propriedades](/visualstudio/ide/reference/properties-window) para exibir uma lista completa de eventos e mensagens do Windows disponível para o item selecionado. Escolha na lista para criar ou editar funções de manipulador.  
  
### <a name="to-jump-to-code-from-the-dialog-editor"></a>Para ir para o código do editor de caixa de diálogo  
  
1.  Clique duas vezes em um controle dentro da caixa de diálogo para saltar para a declaração para sua função de tratamento de mensagens implementada mais recentemente. (Para classes de caixa de diálogo baseado na ATL, você sempre ir para a definição do construtor.)  
  
### <a name="to-view-events-for-a-control"></a>Para exibir eventos de um controle  
  
1.  Com um controle selecionado, clique o **ControlEvents** no botão de [janela propriedades](/visualstudio/ide/reference/properties-window).  
  
    > [!NOTE]
    >  Clicando o **ControlEvents** quando o *caixa de diálogo* tem foco expõe uma lista de todos os controles na caixa de diálogo, você pode, em seguida, expandir para editar os eventos para os controles individuais.  
  
     Quando um único controle tem foco na caixa de diálogo, você pode clique duas vezes e selecionar **Adicionar manipulador de eventos** no menu de atalho. Isso permite que você especifique a classe à qual o manipulador é adicionado. Para obter mais informações, consulte [adicionando um manipulador de eventos](../ide/adding-an-event-handler-visual-cpp.md).  
  
### <a name="to-view-messages-for-a-dialog-box"></a>Para exibir mensagens para uma caixa de diálogo  
  
1.  Com a caixa de diálogo selecionada, clique o **mensagens** no botão de [janela propriedades](/visualstudio/ide/reference/properties-window).  
  
 Para obter informações sobre como adicionar recursos a projetos gerenciados, consulte [recursos em aplicativos de área de trabalho](/dotnet/framework/resources/index) no *guia do desenvolvedor do .NET Framework.* Para obter informações sobre como adicionar manualmente os arquivos de recurso para projetos gerenciados, acessar recursos, exibir recursos estáticos e atribuir cadeias de caracteres de recurso para propriedades, consulte [criando arquivos de recursos para aplicativos de área de trabalho](/dotnet/framework/resources/creating-resource-files-for-desktop-apps). Para obter informações sobre globalização e localização de recursos em aplicativos gerenciados, consulte [Globalizing e localização de aplicativos do .NET Framework](/dotnet/standard/globalization-localization/index).  
  
 Requisitos  
  
 Win32  
  
## <a name="see-also"></a>Consulte também  
 [Editor de caixa de diálogo](../windows/dialog-editor.md)

