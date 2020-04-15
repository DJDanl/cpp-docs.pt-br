---
title: Como adicionar roteamento de comando ao controle dos Windows Forms
ms.custom: get-started-article
ms.date: 11/04/2016
helpviewer_keywords:
- command routing [C++], adding to Windows Forms controls
- Windows Forms controls [C++], command routing
ms.assetid: bf138ece-b463-442a-b0a0-de7063a760c0
ms.openlocfilehash: ad64a12051c22a0cfca99d3ec9c5abef579902f4
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81365164"
---
# <a name="how-to-add-command-routing-to-the-windows-forms-control"></a>Como adicionar roteamento de comando ao controle dos Windows Forms

[CWinFormsView](../mfc/reference/cwinformsview-class.md) rode comandos e mensagens de ida e futura de comando de atualização para o controle do usuário para permitir que ele manuseie comandos MFC (por exemplo, itens de menu de quadros e botões de barra de ferramentas).

O controle do usuário usa [ICommandTarget::Initialize](../mfc/reference/icommandtarget-interface.md#initialize) para armazenar `m_CmdSrc`uma referência ao objeto de origem de comando em , como mostrado no exemplo a seguir. Para `ICommandTarget` usar, você deve adicionar uma referência ao mfcmifc80.dll.

`CWinFormsView`lida com várias das notificações comuns de visualização de MFC, encaminhando-as para o controle gerenciado do usuário. Essas notificações incluem os [métodos OnInitialUpdate,](../mfc/reference/iview-interface.md#oninitialupdate) [OnUpdate](../mfc/reference/iview-interface.md#onupdate) e [OnActivateView.](../mfc/reference/iview-interface.md#onactivateview)

Este tópico pressupõe que você tenha concluído anteriormente [Como: Criar o Controle do Usuário e o Host em uma Caixa de Diálogo](../dotnet/how-to-create-the-user-control-and-host-in-a-dialog-box.md) e [Como: Criar o Controle do Usuário e a Visualização MDI do Host](../dotnet/how-to-create-the-user-control-and-host-mdi-view.md).

### <a name="to-create-the-mfc-host-application"></a>Para criar o aplicativo de host MFC

1. Abrir a biblioteca de controle de formulários do Windows criada em [Como: Criar o controle do usuário e hospedar em uma caixa de diálogo](../dotnet/how-to-create-the-user-control-and-host-in-a-dialog-box.md).

1. Adicione uma referência ao mfcmifc80.dll, o que você pode fazer clicando com o botão direito do mouse no nó do projeto no **Solution Explorer,** selecionando **Adicionar,** **Referenciar**e, em seguida, navegar para o Microsoft Visual Studio 10.0\VC\atlmfc\lib.

1. Abra UserControl1.Designer.cs e adicione a seguinte declaração usando:

    ```
    using Microsoft.VisualC.MFC;
    ```

1. Além disso, em UserControl1.Designer.cs, mude esta linha:

    ```
    partial class UserControl1
    ```

   para isto:

    ```
    partial class UserControl1 : System.Windows.Forms.UserControl, ICommandTarget
    ```

1. Adicione isso como a primeira linha `UserControl1`da definição de classe para:

    ```
    private ICommandSource m_CmdSrc;
    ```

1. Adicione as seguintes `UserControl1` definições de método para (criaremos o ID do controle MFC na próxima etapa):

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

1. Abra o aplicativo MFC que você criou em [Como: Criar o Controle do Usuário e a Visualização MDI do Host](../dotnet/how-to-create-the-user-control-and-host-mdi-view.md).

1. Adicione uma opção de `singleMenuHandler`menu que irá invocar .

   Vá para **Exibição de recursos** (Ctrl+Shift+E), expanda a pasta **Menu** e clique duas vezes **IDR_MFC02TYPE**. Isso exibe o editor do menu.

   Adicione uma opção de menu na parte inferior do menu **Exibir.** Observe o ID da opção de menu na janela **Propriedades.** Salve o arquivo.

   No **Solution Explorer,** abra o arquivo Resource.h, copie o valor de ID para a opção de `m_CmdSrc.AddCommandHandler` menu que você acabou `Initialize` de adicionar `32771` e cole esse valor como o primeiro parâmetro para a chamada no método do projeto C# (substituindo se necessário).

1. Compile e execute o projeto.

   No menu **Compilar**, clique em **Compilar Solução**.

   No menu **Debug,** clique em **Iniciar sem depuração**.

   Selecione a opção de menu adicionada. Observe que o método no .dll é chamado.

## <a name="see-also"></a>Confira também

[Hospedando um controle de usuário do Windows Forms como uma exibição do MFC](../dotnet/hosting-a-windows-forms-user-control-as-an-mfc-view.md)<br/>
[Interface ICommandSource](../mfc/reference/icommandsource-interface.md)<br/>
[Interface ICommandTarget](../mfc/reference/icommandtarget-interface.md)
