---
title: 'Como: Adicionar, editar ou excluir controles (C++)'
ms.date: 02/15/2019
f1_keywords:
- vc.controls.activex
- vc.editors.dialog.insertActiveXControls
helpviewer_keywords:
- Dialog Editor [C++], creating controls
- dialog boxes [C++], adding controls to
- Toolbox [C++], Dialog Editor tab
- controls [C++], types
- syslink controls in dialog boxes
- custom controls [C++], dialog boxes
- controls [C++], standard
- Dialog Editor [C++], creating controls
- controls [C++], adding to dialog boxes
- controls [C++], adding multiple
- dialog box controls [C++], size
- controls [C++], sizing
- dialog boxes [C++], adding ActiveX controls
- ActiveX controls [C++], adding to dialog boxes
- Insert ActiveX Control dialog box [C++]
- controls [C++], editing properties
- ActiveX controls [C++], properties
- controls [C++], undoing changes
- controls [C++], editing properties
- dialog box controls [C++], editing properties
- dialog box controls [C++], deleting
- controls [C++], deleting
- Dialog Editor [C++], default control events
- controls [C++], default control events
- events [C++], controls
- dialog box controls [C++], events
- member variables, defining for controls
- variables, dialog box control member variables
- controls [C++], member variables
- Dialog Editor [C++], defining member variables for controls
- controls [C++], troubleshooting
- Dialog Editor [C++], troubleshooting
- dialog boxes [C++], troubleshooting
- InitCommonControls
- RichEdit 1.0 control
- rich edit controls [C++], RichEdit 1.0
ms.assetid: 73cef03f-5c8c-456a-87d1-1458dff185cf
ms.openlocfilehash: ad14a0500336bc1ca61e00bcd6d9a6e1088afc81
ms.sourcegitcommit: 857fa6b530224fa6c18675138043aba9aa0619fb
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/24/2020
ms.locfileid: "80167518"
---
# <a name="how-to-add-edit-or-delete-controls-c"></a>Como: Adicionar, editar ou excluir controles (C++)

Usando o **Editor de caixa de diálogo**, você pode adicionar, redimensionar, editar e excluir controles em caixas de diálogo. Você também pode editar as propriedades de um controle, como sua ID, ou se ela está visível inicialmente em tempo de execução.

A guia **Editor de caixa de diálogo** é exibida na [janela caixa de ferramentas](/visualstudio/ide/reference/toolbox) quando você está trabalhando no editor de caixa de **diálogo**. Você também pode personalizar a janela **caixa de ferramentas** para facilitar o uso. Para obter mais informações, consulte [usando a caixa de ferramentas](/visualstudio/ide/using-the-toolbox) e [Mostrar ou ocultar a janela caixa de ferramentas](showing-or-hiding-the-dialog-editor-toolbar.md).

> [!TIP]
> Ao usar o **Editor de caixa de diálogo**, em muitas instâncias, você pode selecionar o botão direito do mouse para exibir um menu de atalho de comandos usados com frequência.

## <a name="add-controls"></a>adicionar controles

### <a name="to-add-a-control"></a>Para adicionar um controle

1. Certifique-se de que a janela com guias da caixa de diálogo é o documento atual no quadro do editor. Se uma caixa de diálogo não for o documento atual, você não verá a **guia Editor de caixa de diálogo** na **caixa de ferramentas**.

1. Na guia **Editor de diálogo** da janela **caixa de ferramentas** , selecione o controle desejado e, em seguida:

   - Selecione a caixa de diálogo no local onde você deseja posicionar o controle e o controle aparecerá onde você selecionou.

   - Arraste e solte o controle da janela da caixa de **ferramentas** para o local em seu diálogo. Você pode mover o controle ao contrário ou alterar seu tamanho e forma.

   - Clique duas vezes no controle na janela da caixa de **ferramentas** e ele aparecerá em seu diálogo. Reposicione o controle para o local de sua preferência.

### <a name="to-add-multiple-controls"></a>Para adicionar vários controles

1. Mantendo pressionada a tecla **Ctrl** , selecione um controle na janela **caixa de ferramentas** .

1. Solte a tecla **Ctrl** e selecione a caixa de diálogo quantas vezes desejar para adicionar o controle específico.

1. Pressione **ESC** para parar de colocar os controles.

### <a name="to-size-a-control-while-you-add-it"></a>Para dimensionar um controle enquanto você o adiciona

1. Selecione um controle na janela **caixa de ferramentas** .

1. Coloque o cursor que aparece como Cruz, onde você deseja que o canto superior esquerdo do novo controle esteja em sua caixa de diálogo.

1. Selecione e mantenha o botão do mouse pressionado para ancorar o canto superior esquerdo do seu controle na caixa de diálogo. Em seguida, arraste o cursor para a direita e para baixo, até que o controle seja o tamanho desejado.

   > [!NOTE]
   > Você pode ancorar qualquer um dos quatro cantos do controle que está desenhando. Este procedimento usou o canto superior esquerdo como exemplo.

1. Solte o botão do mouse. O controle é liquidado na caixa de diálogo no tamanho especificado.

> [!TIP]
> Você pode redimensionar o controle depois de soltá-lo na caixa de diálogo movendo as alças de dimensionamento na borda do controle. Para obter mais informações, consulte [dimensionando controles individuais](../windows/sizing-individual-controls.md).

### <a name="to-add-a-custom-control"></a>Para adicionar um controle personalizado

Você pode adicionar controles personalizados à caixa de diálogo. Selecione o ícone de **controle personalizado** na caixa de **ferramentas** e arraste-o para a caixa de diálogo. Para adicionar um controle de `Syslink`, adicione um controle personalizado e, em seguida, altere a propriedade **Class** do controle para `Syslink`. Essa ação fará com que as propriedades sejam atualizadas e mostre as propriedades do controle de `Syslink`. Para obter informações sobre a classe de invólucro do MFC, consulte [CLinkCtrl](../mfc/reference/clinkctrl-class.md).

## <a name="edit-controls"></a>Editar controles

### <a name="to-edit-the-properties-of-a-control-or-controls"></a>Para editar as propriedades de um controle ou controles

1. Na caixa de diálogo, selecione o controle que você deseja modificar.

   > [!NOTE]
   > Se você selecionar vários controles, somente as propriedades comuns aos controles selecionados poderão ser editadas.

1. No [janela Propriedades](/visualstudio/ide/reference/properties-window), altere as propriedades do seu controle.

   > [!NOTE]
   > Quando você define a propriedade **bitmap** para um controle de botão, botão de opção ou caixa de seleção igual a **verdadeiro**, o estilo BS_BITMAP é implementado para seu controle. Para obter mais informações, consulte [estilos de botão](../mfc/reference/styles-used-by-mfc.md#button-styles). Para obter um exemplo de como associar um bitmap a um controle, consulte [CButton:: SetBitmap](../mfc/reference/cbutton-class.md#setbitmap). Os bitmaps não serão exibidos no seu controle enquanto você estiver no **Editor da caixa de diálogo**.

### <a name="to-undo-changes-to-the-properties-of-a-control"></a>Para desfazer alterações nas propriedades de um controle

1. Verifique se o controle tem foco no **Editor da caixa de diálogo**.

1. Vá para menu **editar** > **desfazer**. Se o foco não estiver no controle, o comando **desfazer** não estará disponível.

### <a name="to-define-a-member-variable-for-a-non-button-dialog-box-control"></a>Para definir uma variável de membro para um controle de caixa de diálogo (não botão)

> [!NOTE]
> Esse processo se aplica somente a controles de caixa de diálogo dentro de um projeto MFC. Os projetos da ATL devem usar a nova caixa de diálogo **mensagens e manipuladores de eventos do Windows** . Para obter mais informações, consulte [tipos de mensagem associados a objetos de interface do usuário](../mfc/reference/message-types-associated-with-user-interface-objects.md), [editando um manipulador de mensagens](../mfc/reference/editing-a-message-handler.md)e [definindo um manipulador de mensagens para uma mensagem refletida](../mfc/reference/defining-a-message-handler-for-a-reflected-message.md).

1. No [Editor de caixa de diálogo](../windows/dialog-editor.md), selecione um controle.

1. Ao pressionar a tecla **Ctrl** , clique duas vezes no controle da caixa de diálogo.

   O [Assistente para Adicionar variável de membro](../ide/add-member-variable-wizard.md) é exibido.

1. Digite as informações apropriadas no Assistente para **Adicionar variável de membro** . Para obter mais informações, consulte [caixa de diálogo troca de dados](../mfc/dialog-data-exchange.md).

1. Selecione **OK** para retornar ao **Editor de caixa de diálogo**.

> [!TIP]
> Para saltar de qualquer controle de caixa de diálogo para seu manipulador existente, clique duas vezes no controle.

Você também pode usar a guia **variáveis de membro** no [Assistente de classe MFC](../mfc/reference/mfc-class-wizard.md) para adicionar novas variáveis de membro para uma classe especificada e exibir variáveis de membro já definidas.

## <a name="delete-controls"></a>Excluir controles

Na caixa de diálogo, selecione o controle, pressione a tecla **delete** ou vá para o menu **Editar** > **excluir**.

## <a name="other-issues"></a>Outros problemas

### <a name="troubleshooting"></a>solução de problemas

Depois que você adicionar um controle comum ou um controle de edição rico a uma caixa de diálogo, ele não aparecerá quando você testar a caixa de diálogo. Ou, a própria caixa de diálogo não aparecerá. Por exemplo:

1. Crie um projeto do Win32, modificando as configurações do aplicativo para que você crie um aplicativo do Windows (não um aplicativo de console).

1. Em [modo de exibição de recursos](how-to-create-a-resource-script-file.md#create-resources), clique duas vezes no arquivo *. rc* .

1. Na opção de diálogo, clique duas vezes na caixa **sobre** .

1. Adicione um **controle de endereço IP** à caixa de diálogo.

1. Salvar e **Recompilar tudo**.

1. Execute o programa.

1. No menu **ajuda** da caixa de diálogo, selecione o comando **sobre** e observe que nenhuma caixa de diálogo é exibida.

Atualmente, o **Editor de caixa de diálogo** não adiciona automaticamente o código ao seu projeto quando você arrasta e solta os seguintes controles comuns ou controles de edição avançados em uma caixa de diálogo. Nem o Visual Studio fornece um erro ou aviso quando esse problema ocorre. Para corrigir, adicione o código para o controle manualmente.

||||
|-|-|-|
|Controle deslizante|Controle de árvore|Seletor de data e hora|
|Controle de rotação|Controle guia|Month Calendar|
|Controle de progresso|Controle de animação|Controle de endereço IP|
|Tecla de acesso|Controle de edição rico|Caixa de combinação estendida|
|Controle de lista|Controle rich edit 2,0|Controle personalizado|

Para usar controles comuns em uma caixa de diálogo, você precisa chamar [InitCommonControlsEx](/windows/win32/api/commctrl/nf-commctrl-initcommoncontrolsex) ou `AFXInitCommonControls` antes de criar a caixa de diálogo.

Para usar controles RichEdit, você deve chamar `LoadLibrary`. Para obter mais informações, consulte [sobre os controles de edição avançados](/windows/win32/Controls/about-rich-edit-controls) no SDK do Windows e [visão geral do controle de edição rico](../mfc/overview-of-the-rich-edit-control.md).

> [!NOTE]
> Para usar um controle RichEdit com MFC, você deve primeiro chamar [o AfxInitRichEdit2](../mfc/reference/application-information-and-management.md#afxinitrichedit2) para carregar o controle RichEdit 2,0 (Riched20. DLL) ou chame [AfxInitRichEdit](../mfc/reference/application-information-and-management.md#afxinitrichedit) para carregar o controle RichEdit 1,0 mais antigo (riched32. DLL).
>
> Você pode usar a classe [CRichEditCtrl](../mfc/reference/cricheditctrl-class.md) atual com o controle RichEdit 1,0 mais antigo, mas `CRichEditCtrl` é projetada apenas para dar suporte ao controle RichEdit 2,0. Como o RichEdit 1,0 e o RichEdit 2,0 são semelhantes, a maioria dos métodos funcionará. No entanto, há algumas diferenças entre os controles 1,0 e 2,0, de modo que alguns métodos podem funcionar incorretamente ou não funcionar.

### <a name="activex-controls"></a>Controles ActiveX

O Visual Studio permite que você insira controles ActiveX em sua caixa de diálogo. Para obter mais informações, consulte [controles ActiveX do MFC](../mfc/mfc-activex-controls.md) e [contêineres de controle ActiveX](../mfc/activex-control-containers.md).

A caixa de diálogo **Inserir controle ActiveX** permite que você insira controles ActiveX em sua caixa de diálogo ao usar o [Editor de caixa](../windows/dialog-editor.md)de diálogo. Essa caixa de diálogo contém as seguintes propriedades:

|Propriedade|DESCRIÇÃO|
|---|---|
|**Controle ActiveX**|Exibe uma lista de controles ActiveX.<br/><br/>A inserção de um controle dessa caixa de diálogo não gera uma classe wrapper. Se você precisar de uma classe wrapper, use [modo de exibição de classe](/visualstudio/ide/viewing-the-structure-of-code) para criar uma, consulte [adicionando uma classe](../ide/adding-a-class-visual-cpp.md).<br/><br/>Se um controle ActiveX não aparecer nessa caixa de diálogo, tente instalar o controle de acordo com as instruções do fornecedor.|
|**Caminho**|Exibe o arquivo no qual o controle ActiveX é encontrado.|

> [!CAUTION]
> Talvez não seja legal distribuir todos os controles ActiveX em seu sistema. Consulte o contrato de licença para o software que instalou os controles ou contate a empresa do software.

#### <a name="to-add-an-activex-control"></a>Para adicionar um controle ActiveX

1. Abra uma caixa de diálogo no **Editor de caixas de diálogo**.

1. Clique com o botão direito do mouse em qualquer lugar no corpo da caixa de diálogo e selecione **Inserir controle ActiveX**.

   A caixa de diálogo **Inserir controle ActiveX** é exibida, mostrando todos os controles ActiveX em seu sistema. Na parte inferior da caixa de diálogo, o caminho para o arquivo de controle ActiveX é exibido.

1. Selecione o controle que você deseja adicionar à caixa de diálogo e escolha **OK**.

   O controle aparece na caixa de diálogo, onde você pode editá-lo ou criar manipuladores para ele da mesma forma que faria com qualquer outro controle.

> [!TIP]
> Você pode usar o menu de atalho no **Editor** de caixa de diálogo para adicionar rapidamente controles ActiveX registrados a uma caixa de diálogo ou tentar adicionar controles ActiveX à janela **caixa de ferramentas** para facilitar o acesso.

#### <a name="to-edit-properties-for-an-activex-control"></a>Para editar as propriedades de um controle ActiveX

Os controles ActiveX fornecidos por fornecedores independentes podem vir equipados com suas próprias propriedades e características. Essas propriedades são exibidas na janela **Propriedades** . Todas as páginas de propriedades criadas pelos gravadores do controle ActiveX são exibidas na caixa de diálogo **páginas de propriedades** . (Para exibir a **página de propriedades** de um controle ActiveX específico, selecione o botão **página de propriedades** na [janela Propriedades](/visualstudio/ide/reference/properties-window)).

- Selecione o controle **ActiveX** e vá para a **exibição** de menu > **página de propriedades** para exibir as propriedades. Faça alterações conforme necessário na página de propriedades.

   Várias guias são exibidas na página de propriedades de um controle ActiveX, dependendo das folhas de propriedades que são fornecidas como parte do controle ActiveX.

> [!NOTE]
> Esse procedimento se aplica ao uso da página de propriedades para editar controles ActiveX. Você também pode procurar e editar propriedades do ActiveX na janela novas **Propriedades** .

## <a name="requirements"></a>Requisitos

Win32

## <a name="see-also"></a>Confira também

[Gerenciar controles da caixa de diálogo](controls-in-dialog-boxes.md)<br/>
[Como: controles de layout](arrangement-of-controls-on-dialog-boxes.md)<br/>
[Como definir o acesso e os valores de controle](defining-mnemonics-access-keys.md)

<!-- excluded links
[Mapping Messages to Functions](../mfc/reference/mapping-messages-to-functions.md)<br/>
[Adding Functionality with Code Wizards](../ide/adding-functionality-with-code-wizards-cpp.md)<br/>
[Adding a Class](../ide/adding-a-class-visual-cpp.md)<br/>
[Adding a Member Function](../ide/adding-a-member-function-visual-cpp.md)<br/>
[Adding a Member Variable](../ide/adding-a-member-variable-visual-cpp.md)<br/>
[Overriding a Virtual Function](../ide/overriding-a-virtual-function-visual-cpp.md)<br/>
[MFC Message Handler](../mfc/reference/adding-an-mfc-message-handler.md)
[Declaring a Variable Based on Your New Control Class](../mfc/reference/declaring-a-variable-based-on-your-new-control-class.md)<br/>
-->
