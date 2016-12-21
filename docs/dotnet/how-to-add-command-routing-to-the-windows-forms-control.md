---
title: "Como adicionar roteamento de comando ao controle dos Windows Forms | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "get-started-article"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "roteamento de comando [C++], adicionando controles de Windows Forms"
  - "Roteamento de comando de controles do Windows Forms [C++]"
ms.assetid: bf138ece-b463-442a-b0a0-de7063a760c0
caps.latest.revision: 13
caps.handback.revision: 13
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Como adicionar roteamento de comando ao controle dos Windows Forms
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

[CWinFormsView](../mfc/reference/cwinformsview-class.md) roteia comandos e as mensagens UI de comando de atualização para o controle de usuário para permitir que ele manipule comandos MFC (por exemplo, itens de menu do quadro e botões de barra de ferramentas).  
  
 O controle de usuário usa [ICommandTarget::Initialize](../Topic/ICommandTarget::Initialize.md) para armazenar uma referência ao objeto de origem de comando na `m_CmdSrc`, conforme mostrado no exemplo a seguir. Usar `ICommandTarget` você deve adicionar uma referência a mfcmifc80.  
  
 `CWinFormsView` lida com várias das notificações de exibição comuns do MFC, encaminhando-los para o controle de usuário gerenciado. Essas notificações incluem o [OnInitialUpdate](../Topic/IView::OnInitialUpdate.md), [OnUpdate](../Topic/IView::OnUpdate.md) e [OnActivateView](../Topic/IView::OnActivateView.md) métodos o [IView Interface](../Topic/IView%20Interface.md).  
  
 Este tópico pressupõe que você concluiu previamente [como: criar o controle de usuário e o Host em uma caixa de diálogo](../dotnet/how-to-create-the-user-control-and-host-in-a-dialog-box.md) e [como: criar o controle de usuário e uma exibição MDI Host](../dotnet/how-to-create-the-user-control-and-host-mdi-view.md).  
  
### <a name="to-create-the-mfc-host-application"></a>Para criar o aplicativo de host do MFC  
  
1.  Abra a biblioteca de controle do Windows Forms criado no [como: criar o controle de usuário e o Host em uma caixa de diálogo](../dotnet/how-to-create-the-user-control-and-host-in-a-dialog-box.md).  
  
2.  Adicione uma referência ao mfcmifc80, que pode ser feito clicando no nó do projeto no **Solution Explorer**, selecionando **Add**, **referência**, e, em seguida, navegando até o Microsoft Visual Studio 10.0\VC\atlmfc\lib.  
  
3.  Abra UserControl1.Designer.cs e adicione a seguinte instrução using:  
  
    ```  
    using Microsoft.VisualC.MFC;  
    ```  
  
4.  Além disso, no UserControl1.Designer.cs, altere esta linha:  
  
    ```  
    partial class UserControl1  
    ```  
  
     Para isso:  
  
    ```  
    partial class UserControl1 : System.Windows.Forms.UserControl, ICommandTarget  
    ```  
  
5.  Adicionar isto como a primeira linha da definição de classe para `UserControl1`:  
  
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
  
7.  Abra o aplicativo MFC criado na [como: criar o controle de usuário e uma exibição MDI Host](../dotnet/how-to-create-the-user-control-and-host-mdi-view.md).  
  
8.  Adicionar uma opção de menu que irá chamar `singleMenuHandler`.  
  
     Vá para **exibição recurso** (Ctrl + Shift + E), expanda o **Menu** pasta e clique duas vezes em **IDR_MFC02TYPE**. Isso exibe o editor de menu.  
  
     Adicionar uma opção de menu na parte inferior da **exibição** menu. Observe a ID da opção no menu de **propriedades** janela. Salve o arquivo.  
  
     Em **Solution Explorer**, abra o arquivo Resource.h, copie o valor de ID para a opção de menu que você acabou de adicionar e cole esse valor como o primeiro parâmetro para o `m_CmdSrc.AddCommandHandler` chamar do projeto c# `Initialize` método (substituindo `32771` se necessário).  
  
9. Compile e execute o projeto.  
  
     Sobre o **criar** menu, clique em **Build Solution**.  
  
     Sobre o **Depurar** menu, clique em **Iniciar sem depuração**.  
  
     Selecione a opção de menu que você adicionou. Observe que o método no arquivo. dll é chamado.  
  
## <a name="see-also"></a>Consulte também  
 [Hospedando um controle de usuário do Windows Forms como uma exibição MFC](../dotnet/hosting-a-windows-forms-user-control-as-an-mfc-view.md)   
 [Interface ICommandSource](../mfc/reference/icommandsource-interface.md)   
 [Interface ICommandTarget](../mfc/reference/icommandtarget-interface.md)   
 [CommandHandler](../Topic/CommandHandler%20Delegate.md)