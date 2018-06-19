---
title: 'Como: adicionar comandos de controle de formulários do roteamento para o Windows | Microsoft Docs'
ms.custom: get-started-article
ms.date: 11/04/2016
ms.technology:
- cpp-cli
ms.topic: conceptual
dev_langs:
- C++
helpviewer_keywords:
- command routing [C++], adding to Windows Forms controls
- Windows Forms controls [C++], command routing
ms.assetid: bf138ece-b463-442a-b0a0-de7063a760c0
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- dotnet
ms.openlocfilehash: 4c13b0bedf7c81431449aaed8d4fa8f067cdf3d9
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
ms.locfileid: "33133643"
---
# <a name="how-to-add-command-routing-to-the-windows-forms-control"></a>Como adicionar roteamento de comando ao controle dos Windows Forms
[CWinFormsView](../mfc/reference/cwinformsview-class.md) encaminha os comandos e as mensagens UI do comando de atualização para o controle de usuário para permitir que ele trate comandos MFC (por exemplo, itens de menu do quadro e botões de barra de ferramentas).  
  
 O controle de usuário usa [ICommandTarget::Initialize](../mfc/reference/icommandtarget-interface.md#initialize) para armazenar uma referência ao objeto de origem de comando no `m_CmdSrc`, conforme mostrado no exemplo a seguir. Para usar `ICommandTarget` você deve adicionar uma referência a mfcmifc80.  
  
 `CWinFormsView` trata de várias das notificações de exibição comuns do MFC, encaminhando-os para o controle de usuário gerenciado. Essas notificações incluem o [OnInitialUpdate](../mfc/reference/iview-interface.md#oninitialupdate), [OnUpdate](../mfc/reference/iview-interface.md#onupdate) e [OnActivateView](../mfc/reference/iview-interface.md#onactivateview) métodos.  
  
 Este tópico pressupõe que você concluiu anteriormente [como: criar o controle de usuário e o Host em uma caixa de diálogo](../dotnet/how-to-create-the-user-control-and-host-in-a-dialog-box.md) e [como: criar o controle de usuário e uma exibição MDI Host](../dotnet/how-to-create-the-user-control-and-host-mdi-view.md).  
  
### <a name="to-create-the-mfc-host-application"></a>Para criar o aplicativo de host do MFC  
  
1.  Abra a biblioteca de controle de formulários do Windows criados no [como: criar o controle de usuário e o Host em uma caixa de diálogo](../dotnet/how-to-create-the-user-control-and-host-in-a-dialog-box.md).  
  
2.  Adicione uma referência ao mfcmifc80, que pode ser feito clicando no nó do projeto no **Solution Explorer**, selecionando **adicionar**, **referência**e, em seguida, navegando até Microsoft Visual Studio 10.0\VC\atlmfc\lib.  
  
3.  Abra UserControl1.Designer.cs e adicione a seguinte instrução using:  
  
    ```  
    using Microsoft.VisualC.MFC;  
    ```  
  
4.  Além disso, em UserControl1.Designer.cs, altere esta linha:  
  
    ```  
    partial class UserControl1  
    ```  
  
     Para isso:  
  
    ```  
    partial class UserControl1 : System.Windows.Forms.UserControl, ICommandTarget  
    ```  
  
5.  Adicionar como a primeira linha da definição de classe para `UserControl1`:  
  
    ```  
    private ICommandSource m_CmdSrc;  
    ```  
  
6.  Adicione as seguintes definições de método para `UserControl1` (criaremos a ID do controle MFC na próxima etapa):  
  
    ```  
    public void Initialize (ICommandSource cmdSrc)  
    {  
       m_CmdSrc = cmdSrc;  
       // need ID of control in MFC dialog and callback function   
       m_CmdSrc.AddCommandHandler(32771, new CommandHandler (singleMenuHandler));  
    }  
  
    private void singleMenuHandler (uint cmdUI)  
    {  
       // User command handler code  
       System.Windows.Forms.MessageBox.Show("Custom menu option was clicked.");  
    }  
    ```  
  
7.  Abra o aplicativo do MFC criado na [como: criar o controle de usuário e uma exibição MDI Host](../dotnet/how-to-create-the-user-control-and-host-mdi-view.md).  
  
8.  Adicionar uma opção de menu que invocará `singleMenuHandler`.  
  
     Vá para **exibição recursos** (Ctrl + Shift + E), expanda o **Menu** pasta e, em seguida, clique duas vezes em **IDR_MFC02TYPE**. Exibe o editor de menu.  
  
     Adicionar uma opção de menu na parte inferior do **exibição** menu. Observe a ID da opção de menu no **propriedades** janela. Salve o arquivo.  
  
     Em **Solution Explorer**, abra o arquivo Resource.h, copie o valor de ID para a opção de menu que você acabou de adicionar e cole esse valor como o primeiro parâmetro para o `m_CmdSrc.AddCommandHandler` chamar do projeto c# `Initialize` método (substituindo `32771` se necessário).  
  
9. Compile e execute o projeto.  
  
     No menu **Compilar**, clique em **Compilar Solução**.  
  
     Sobre o **depurar** menu, clique em **iniciar sem depuração**.  
  
     Selecione a opção de menu que você adicionou. Observe que o método no arquivo. dll é chamado.  
  
## <a name="see-also"></a>Consulte também  
 [Hospedando um controle de usuário do Windows Forms como uma exibição MFC](../dotnet/hosting-a-windows-forms-user-control-as-an-mfc-view.md)   
 [Interface ICommandSource](../mfc/reference/icommandsource-interface.md)   
 [Interface ICommandTarget](../mfc/reference/icommandtarget-interface.md)   
 [CommandHandler](http://msdn.microsoft.com/Library/22096734-e074-4aca-8523-4b15590109f9)