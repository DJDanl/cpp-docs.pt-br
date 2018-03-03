---
title: "Adicionando manipuladores de eventos para controles de caixa de diálogo | Microsoft Docs"
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
- Dialog editor, adding event handlers to controls
- controls [C++], event handlers
- dialog box controls, events
- event handlers, for dialog box controls
ms.assetid: f9c70f24-ea6f-44df-82eb-78a2deaee769
caps.latest.revision: 
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload:
- cplusplus
- uwp
ms.openlocfilehash: afe50d56d6b96cc4bc0b871f72c27feb0a750e89
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="adding-event-handlers-for-dialog-box-controls"></a>Adicionando manipuladores de eventos para controles da caixa de diálogo
Para caixas de diálogo de projeto que já estão associadas uma classe, você pode tirar proveito de alguns atalhos quando você cria manipuladores de eventos. Você pode criar rapidamente um manipulador para o evento de notificação de controle padrão ou para qualquer mensagem aplicável do Windows.  
  
#### <a name="to-create-a-handler-for-the-default-control-notification-event"></a>Para criar um manipulador para o evento de notificação de controle padrão  
  
1.  Clique duas vezes no controle. Abre o editor de texto.  
  
2.  Adicione o código de manipulador de notificações de controle no editor de texto.  
  
#### <a name="to-create-a-handler-for-any-applicable-windows-message"></a>Para criar um manipulador de qualquer mensagem aplicável do Windows  
  
1.  Clique no controle para o qual você deseja manipular o evento de notificação.  
  
2.  No [janela propriedades](/visualstudio/ide/reference/properties-window), clique no **ControlEvents** botão para exibir a lista de eventos comuns do Windows associada ao controle. Por exemplo, o padrão **Okey** botão o **sobre** caixa de diálogo lista os eventos de notificação a seguir:  
  
 **BN_CLICKED**  
  
 **BN_DOUBLECLICKED**  
  
 **BN_KILLFOCUS**  
  
 **BN_SETFOCUS**  
  
    > [!NOTE]
    >  Como alternativa, selecione a caixa de diálogo e clique no **ControlEvents** botão para exibir a lista de eventos comuns do Windows para todos os controles na caixa de diálogo.  
  
3.  No **propriedades** janela, clique na coluna direita próximo ao evento de tratar e, em seguida, selecione o nome do evento de notificação sugerido (por exemplo, **OnBnClickedOK** identificadores **BN_CLICKED** ).  
  
    > [!NOTE]
    >  Como alternativa, você pode fornecer um nome de manipulador de eventos de sua escolha, em vez de selecionar o nome do manipulador de eventos padrão.  
  
     Depois que você tiver selecionado o evento, o Visual Studio abre o Editor de texto e exibe o código do manipulador de eventos. Por exemplo, o código a seguir é adicionado para o padrão **OnBnClickedOK**:  
  
 ```  
    void CAboutDlg::OnBnClickedOk(void)  
 { *// TODO: Add your control notification handler code here  
 }  
 ```  
  
 Se você deseja adicionar o manipulador de eventos para uma classe diferente de uma implementação de caixa de diálogo, use o [Assistente de manipulador de eventos](../ide/event-handler-wizard.md). Para obter mais informações, consulte [adicionando um manipulador de eventos](../ide/adding-an-event-handler-visual-cpp.md).  
  
 Para obter informações sobre como adicionar recursos a projetos gerenciados, consulte [recursos em aplicativos de área de trabalho](/dotnet/framework/resources/index) no *guia do desenvolvedor do .NET Framework.* Para obter informações sobre como adicionar manualmente os arquivos de recurso para projetos gerenciados, acessar recursos, exibir recursos estáticos e atribuir cadeias de caracteres de recurso para propriedades, consulte [criando arquivos de recursos para aplicativos de área de trabalho](/dotnet/framework/resources/creating-resource-files-for-desktop-apps). Para obter informações sobre globalização e localização de recursos em aplicativos gerenciados, consulte [Globalizing e localização de aplicativos do .NET Framework](/dotnet/standard/globalization-localization/index).  
  
### <a name="requirements"></a>Requisitos  
 Win32  
  
## <a name="see-also"></a>Consulte também  
 [Eventos de controle padrão](../windows/default-control-events.md)   
 [Definindo variáveis de membro para controles de caixa de diálogo](../windows/defining-member-variables-for-dialog-controls.md)   
 [Controles de caixa de diálogo e tipos de variáveis](../ide/dialog-box-controls-and-variable-types.md)   
 [Adicionando uma classe](../ide/adding-a-class-visual-cpp.md)   
 [Adicionar uma função de membro](../ide/adding-a-member-function-visual-cpp.md)   
 [Adicionar uma variável de membro](../ide/adding-a-member-variable-visual-cpp.md)   
 [Substituindo uma função Virtual](../ide/overriding-a-virtual-function-visual-cpp.md)   
 [Manipulador de mensagens do MFC](../mfc/reference/adding-an-mfc-message-handler.md)

