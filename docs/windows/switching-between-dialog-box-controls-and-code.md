---
title: Alternando controles de caixa de diálogo e código | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-windows
ms.topic: conceptual
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
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- uwp
ms.openlocfilehash: b288e97030cad7e38caf19fb47f7a058c3ead61d
ms.sourcegitcommit: 37a10996022d738135999cbe71858379386bab3d
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/08/2018
ms.locfileid: "39643102"
---
# <a name="switching-between-dialog-box-controls-and-code"></a>Alternando controles de caixa de diálogo e código
Em aplicativos MFC, você pode clicar duas vezes em controles de caixa de diálogo para saltar para o seu código de manipulador ou crie rapidamente stub de funções do manipulador.  
  
 Com um controle selecionado, clique no **ControlEvents** botão ou o **mensagens** botão o [janela propriedades](/visualstudio/ide/reference/properties-window) para exibir uma lista completa de mensagens do Windows e eventos disponível para o item selecionado. Escolha na lista para criar ou editar funções de manipulador.  
  
### <a name="to-jump-to-code-from-the-dialog-editor"></a>Para ir para código do editor de caixa de diálogo  
  
1.  Clique duas vezes em um controle dentro da caixa de diálogo para ir para a declaração para sua função de manipulação de mensagens implementada mais recentemente. (Para classes de caixa de diálogo com base em ATL, você sempre ir para a definição do construtor.)  
  
### <a name="to-view-events-for-a-control"></a>Para exibir eventos de um controle  
  
1.  Com um controle selecionado, clique o **ControlEvents** botão na [janela propriedades](/visualstudio/ide/reference/properties-window).  
  
    > [!NOTE]
    >  Clicar a **ControlEvents** botão quando o *caixa de diálogo* tem foco expõe uma lista de todos os controles na caixa de diálogo, você pode, em seguida, expandir para editar os eventos para os controles individuais.  
  
     Quando um único controle tem o foco na caixa de diálogo, você pode clique duas vezes e selecionar **Adicionar manipulador de eventos** no menu de atalho. Isso permite que você especificar a classe à qual o manipulador é adicionado. Para obter mais informações, consulte [adicionando um manipulador de eventos](../ide/adding-an-event-handler-visual-cpp.md).  
  
### <a name="to-view-messages-for-a-dialog-box"></a>Para exibir mensagens para uma caixa de diálogo  
  
1.  Com a caixa de diálogo selecionada, clique o **mensagens** botão na [janela propriedades](/visualstudio/ide/reference/properties-window).  
  
 Para obter informações sobre como adicionar recursos a projetos gerenciados, consulte [recursos em aplicativos de área de trabalho](/dotnet/framework/resources/index) na *guia do desenvolvedor do .NET Framework*. Para obter informações sobre como adicionar manualmente os arquivos de recursos a projetos gerenciados, acessar recursos, exibir recursos estáticos e atribuir cadeias de caracteres de recurso a propriedades, consulte [criando arquivos de recursos para aplicativos de área de trabalho](/dotnet/framework/resources/creating-resource-files-for-desktop-apps). Para obter informações sobre globalização e localização de recursos em aplicativos gerenciados, consulte [Globalizing e Localizando aplicativos do .NET Framework](/dotnet/standard/globalization-localization/index).  
  
## <a name="requirements"></a>Requisitos  
 Win32  
  
## <a name="see-also"></a>Consulte também  
 [Editor de caixa de diálogo](../windows/dialog-editor.md)