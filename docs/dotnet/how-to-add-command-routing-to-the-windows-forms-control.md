---
title: 'Como: Adicionar comando de controle de formulários do roteamento para o Windows'
ms.custom: get-started-article
ms.date: 11/04/2016
helpviewer_keywords:
- command routing [C++], adding to Windows Forms controls
- Windows Forms controls [C++], command routing
ms.assetid: bf138ece-b463-442a-b0a0-de7063a760c0
ms.openlocfilehash: 8f633cf744314833409a3ffeacf8c850429e099c
ms.sourcegitcommit: dedd4c3cb28adec3793329018b9163ffddf890a4
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/11/2019
ms.locfileid: "57750292"
---
# <a name="how-to-add-command-routing-to-the-windows-forms-control"></a>Como: Adicionar comando de controle de formulários do roteamento para o Windows

[CWinFormsView](../mfc/reference/cwinformsview-class.md) roteia comandos e mensagens de interface do usuário do comando de atualização para o controle de usuário para permitir a manipulação de comandos MFC (por exemplo, itens de menu do quadro e botões da barra de ferramentas).

O controle de usuário usa [ICommandTarget::Initialize](../mfc/reference/icommandtarget-interface.md#initialize) para armazenar uma referência ao objeto de origem de comando no `m_CmdSrc`, conforme mostrado no exemplo a seguir. Usar `ICommandTarget` você deve adicionar uma referência a mfcmifc80.dll.

`CWinFormsView` manipula várias das notificações de exibição comuns do MFC ao encaminhá-las para o controle de usuário gerenciado. Essas notificações incluem o [OnInitialUpdate](../mfc/reference/iview-interface.md#oninitialupdate), [OnUpdate](../mfc/reference/iview-interface.md#onupdate) e [OnActivateView](../mfc/reference/iview-interface.md#onactivateview) métodos.

Este tópico pressupõe que você concluiu previamente [como: Criar o controle de usuário e o Host em uma caixa de diálogo](../dotnet/how-to-create-the-user-control-and-host-in-a-dialog-box.md) e [como: Criar o modo de exibição de controle de usuário e o Host MDI](../dotnet/how-to-create-the-user-control-and-host-mdi-view.md).

### <a name="to-create-the-mfc-host-application"></a>Para criar o aplicativo de host do MFC

1. Abra a biblioteca de controle do Windows Forms criado no [como: Criar o controle de usuário e o Host em uma caixa de diálogo](../dotnet/how-to-create-the-user-control-and-host-in-a-dialog-box.md).

1. Adicione uma referência a mfcmifc80.dll, o que pode ser feito clicando com o nó do projeto no **Gerenciador de soluções**, selecionando **Add**, **referência**e, em seguida, navegando até Microsoft Visual Studio 10.0\VC\atlmfc\lib.

1. Abra o UserControl1.Designer.cs e adicione a seguinte instrução using:

    ```
    using Microsoft.VisualC.MFC;
    ```

1. Além disso, em UserControl1.Designer.cs, altere esta linha:

    ```
    partial class UserControl1
    ```

   para isto:

    ```
    partial class UserControl1 : System.Windows.Forms.UserControl, ICommandTarget
    ```

1. Adicione isso como a primeira linha da definição de classe para `UserControl1`:

    ```
    private ICommandSource m_CmdSrc;
    ```

1. Adicione as seguintes definições de método para `UserControl1` (nós criaremos a identificação do controle MFC na próxima etapa):

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

1. Abra o aplicativo do MFC que você criou na [como: Criar o modo de exibição de controle de usuário e o Host MDI](../dotnet/how-to-create-the-user-control-and-host-mdi-view.md).

1. Adicionar uma opção de menu que invocará `singleMenuHandler`.

   Vá para **exibição de recurso** (Ctrl + Shift + E), expanda o **Menu** pasta e clique duas vezes em **IDR_MFC02TYPE**. Isso exibe o editor de menu.

   Adicionar uma opção de menu na parte inferior a **exibição** menu. Observe a ID da opção no menu de **propriedades** janela. Salve o arquivo.

   Na **Gerenciador de soluções**, abra o arquivo Resource. h, copie o valor da ID para a opção de menu que você acabou de adicionar e cole esse valor como o primeiro parâmetro para o `m_CmdSrc.AddCommandHandler` chamar do projeto c# `Initialize` método (substituindo `32771` se necessário).

9. Compile e execute o projeto.

   No menu **Compilar**, clique em **Compilar Solução**.

   Sobre o **Debug** menu, clique em **iniciar sem depuração**.

   Selecione a opção de menu que você adicionou. Observe que o método no arquivo. dll é chamado.

## <a name="see-also"></a>Consulte também

[Hospedando um controle de usuário do Windows Forms como uma exibição do MFC](../dotnet/hosting-a-windows-forms-user-control-as-an-mfc-view.md)<br/>
[Interface ICommandSource](../mfc/reference/icommandsource-interface.md)<br/>
[Interface ICommandTarget](../mfc/reference/icommandtarget-interface.md)
