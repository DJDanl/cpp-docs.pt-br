---
title: Adicionando, editando ou excluindo controles
ms.date: 11/04/2016
f1_keywords:
- vc.editors.dialog.dialog
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
ms.openlocfilehash: 648ac3329409ba221881f75eaa51e1779091b0f0
ms.sourcegitcommit: eb2b34a24e6edafb727e87b138499fa8945f981e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 02/14/2019
ms.locfileid: "56264862"
---
# <a name="adding-editing-or-deleting-controls"></a>Adicionando, editando ou excluindo controles

Usando o **caixa de diálogo** editor, você pode adicionar, redimensionar, editar e excluir os controles em caixas de diálogo. Você também pode editar as propriedades de um controle, como sua ID, ou se é visível inicialmente no tempo de execução.

O **Editor de caixa de diálogo** guia é exibida na [janela caixa de ferramentas](/visualstudio/ide/reference/toolbox) quando você estiver trabalhando no **caixa de diálogo** editor. Você também pode personalizar o **caixa de ferramentas** janela para facilitar o uso. Para obter mais informações, consulte [usando a caixa de ferramentas](/visualstudio/ide/using-the-toolbox) e [Mostrar ou ocultar a janela da caixa de ferramentas](showing-or-hiding-the-dialog-editor-toolbar.md).

Você pode usar o menu de atalho a **caixa de diálogo** editor para adicionar rapidamente registrado controles ActiveX a uma caixa de diálogo, e você pode adicionar controles ActiveX para o **caixa de ferramentas** para acesso rápido.

Para obter informações sobre como adicionar recursos a projetos gerenciados, consulte [recursos em aplicativos de área de trabalho](/dotnet/framework/resources/index) na *guia do desenvolvedor do .NET Framework*. Para obter informações sobre como adicionar manualmente os arquivos de recursos a projetos gerenciados, acessar recursos, exibir recursos estáticos e atribuir cadeias de caracteres de recurso a propriedades, consulte [criando arquivos de recursos para aplicativos de área de trabalho](/dotnet/framework/resources/creating-resource-files-for-desktop-apps). Para obter informações sobre globalização e localização de recursos em aplicativos gerenciados, consulte [Globalizing e Localizando aplicativos do .NET Framework](/dotnet/standard/globalization-localization/index).

## <a name="to-add-a-control"></a>Para adicionar um controle

Para adicionar controles à sua nova caixa de diálogo, arraste os controles do **caixa de ferramentas** à caixa de diálogo que você está criando. Em seguida, você pode mover os controles ou alterar seu tamanho e forma.

Você pode adicionar controles personalizados à caixa de diálogo, selecionando o **controle personalizado** ícone na **caixa de ferramentas** e arrastando-o para sua caixa de diálogo. Para adicionar um **Syslink** controlar, adicionar um controle personalizado e, em seguida, alterar o controle **classe** propriedade a ser **Syslink**. Essa ação fará com que as propriedades atualizar e mostrar o **Syslink** propriedades do controle. Para obter informações sobre a classe de wrapper do MFC, consulte [CLinkCtrl](../mfc/reference/clinkctrl-class.md).

### <a name="to-add-a-control-to-a-dialog-box"></a>Para adicionar um controle a uma caixa de diálogo

1. Certifique-se de que a janela com guias da caixa de diálogo é o documento atual no quadro do editor. Se uma caixa de diálogo não for o documento atual, você não verá os **guia do Editor de caixa de diálogo** na **caixa de ferramentas**.

1. No **Editor de caixa de diálogo** guia da **caixa de ferramentas** janela, selecione o controle, em seguida, você deseja:

   Marque a caixa de diálogo no local onde você deseja colocar o controle. O controle aparece em que você selecionou.

   \- ou -

   Arraste e solte o controle a partir de **caixa de ferramentas** janela para o local em sua caixa de diálogo.

   \- ou -

   Clique duas vezes no controle na **caixa de ferramentas** janela (ele é exibido na caixa de diálogo), em seguida, reposicionar o controle para o local de sua preferência.

### <a name="to-add-multiple-controls"></a>Para adicionar vários controles

1. Enquanto mantém pressionada a **Ctrl** da chave, selecione um controle na **caixa de ferramentas** janela.

1. Versão do **Ctrl** da chave e marque a caixa de diálogo quantas vezes você deseja adicionar o controle específico.

1. Pressione **Esc** para interromper a colocação de controles.

### <a name="to-size-a-control-while-you-add-it"></a>Para dimensionar um controle enquanto você adicioná-lo

1. Selecione um controle na **caixa de ferramentas** janela.

1. Coloque o cursor (que aparece como cruzada cruzes) onde você deseja que o canto superior esquerdo do novo controle esteja em sua caixa de diálogo.

1. Selecione e mantenha pressionado o botão do mouse para o canto superior esquerdo do seu controle na caixa de diálogo de ancoragem e arraste o cursor para a direita e para baixo até que o controle é o tamanho desejado.

   > [!NOTE]
   > Na verdade, é possível ancorar qualquer um dos quatro cantos do controle que está sendo desenhado. Esse procedimento usado no canto superior esquerdo como um exemplo.

1. Solte o botão do mouse. O controle liquida para a caixa de diálogo pelo tamanho especificado.

   > [!TIP]
   > Você pode redimensionar o controle após arrastando-o para a caixa de diálogo, movendo as alças de dimensionamento na borda do controle. Para obter mais informações, consulte [controles individuais do dimensionamento](../windows/sizing-individual-controls.md).

### <a name="to-add-an-activex-control"></a>Para adicionar um controle ActiveX

Visual Studio permite que você inserir controles ActiveX em sua caixa de diálogo. Para obter mais informações, consulte [controles ActiveX do MFC](../mfc/mfc-activex-controls.md) e [contêineres de controle ActiveX](../mfc/activex-control-containers.md).

O **Inserir controle ActiveX** caixa de diálogo permite que você inserir controles ActiveX em sua caixa de diálogo enquanto estiver usando o [editor de caixa de diálogo](../windows/dialog-editor.md). Essa caixa de diálogo contém as seguintes propriedades:

|Propriedade|Descrição|
|---|---|
|**Controle ActiveX**|Exibe uma lista de controles Active X. Inserindo um controle nessa caixa de diálogo não gera uma classe wrapper. Se você precisar de uma classe wrapper, use [Class View](/visualstudio/ide/viewing-the-structure-of-code) criá-lo (para obter mais informações, consulte [adicionando uma classe](../ide/adding-a-class-visual-cpp.md)). Se um controle Active X não aparecer na caixa de diálogo, tente instalar o controle de acordo com as instruções do fornecedor.|
|**Path**|Exibe o arquivo no qual o controle ActiveX é encontrado.|

#### <a name="to-see-the-activex-controls-available"></a>Para ver os controles ActiveX disponíveis

1. Abra uma caixa de diálogo no editor de caixa de diálogo.

1. Clique com botão direito em qualquer lugar no corpo da caixa de diálogo.

1. No menu de atalho, selecione **Inserir controle ActiveX**.

   O **Inserir controle ActiveX** caixa de diálogo aparece, mostrando todos os controles ActiveX em seu sistema. Na parte inferior da caixa de diálogo, o caminho para o arquivo de controle ActiveX é exibida.

#### <a name="to-add-an-activex-control-to-a-dialog-box"></a>Para adicionar um controle ActiveX a uma caixa de diálogo

1. No **Inserir controle ActiveX** caixa de diálogo, selecione o controle que você deseja adicionar à sua caixa de diálogo e selecione **Okey**.

   O controle aparece na caixa de diálogo onde você pode editá-lo ou criar manipuladores para ele como faria qualquer outro controle.

   > [!NOTE]
   > Você pode adicionar controles ActiveX para o **caixa de ferramentas** janela para facilitar o acesso.

   > [!CAUTION]
   > Ele pode não ser legal para distribuir todos os controles ActiveX em seu sistema. Consulte o contrato de licença para softwares que instalados os controles ou entre em contato com a empresa de software.

## <a name="to-edit-a-control"></a>Para editar um controle

### <a name="to-edit-the-properties-of-a-control-or-controls"></a>Para editar as propriedades de um controle ou controles

1. Na caixa de diálogo, selecione o controle que você deseja modificar.

   > [!NOTE]
   > Se você selecionar vários controles, somente as propriedades comuns para os controles selecionados podem ser editadas.

1. No [janela de propriedades](/visualstudio/ide/reference/properties-window), alterar as propriedades de seu controle.

   > [!NOTE]
   > Quando você define o **Bitmap** propriedade de um botão, um botão de opção ou um controle de caixa de seleção igual a **verdadeiro**, o estilo BS_BITMAP é implementado para o seu controle. Para obter mais informações, consulte [estilos de botão](../mfc/reference/styles-used-by-mfc.md#button-styles). Para obter um exemplo de associação de um bitmap com um controle, consulte [CButton::SetBitmap](../mfc/reference/cbutton-class.md#setbitmap). Bitmaps não aparecerá no seu controle enquanto você estiver na **caixa de diálogo** editor de recursos.

### <a name="to-undo-changes-to-the-properties-of-a-control"></a>Para desfazer as alterações nas propriedades de um controle

1. Verifique se o controle tem foco **caixa de diálogo** editor.

1. Escolher **desfazer** da **editar** menu (se o foco não está no controle, o **desfazer** comando estará disponível).

### <a name="to-edit-properties-for-an-activex-control"></a>Para editar as propriedades de um controle ActiveX

Controles ActiveX fornecidos por fornecedores independentes podem vir equipados com suas próprias propriedades e características. Propriedades para controles ActiveX são exibidas na **propriedades** janela. Além disso, as páginas de propriedade criadas pelos gravadores do controle ActiveX são exibidas na **páginas de propriedades** caixa de diálogo (para exibir o **página de propriedades** para um controle ActiveX específico, clique o **Página de propriedades** botão o [janela propriedades](/visualstudio/ide/reference/properties-window)).

Várias guias são exibidas na página de propriedades para um controle ActiveX, dependendo das folhas de propriedades que são fornecidos como parte do controle ActiveX.

> [!NOTE]
> O procedimento a seguir se aplica a usando a página de propriedades para editar os controles ActiveX. Você também pode procurar e editar propriedades do ActiveX no novo **propriedades** janela.

1. Selecione o **ActiveX** controle.

1. Sobre o **modo de exibição** menu, selecione **página de propriedades** e exibir as propriedades.

1. Faça as alterações necessárias na página de propriedades.

### <a name="to-define-a-member-variable-for-a-non-button-dialog-box-control"></a>Para definir uma variável de membro para um controle de caixa de diálogo (não-botão)

Para definir uma variável de membro de qualquer controle de caixa de diálogo, exceto os botões, você pode usar o método a seguir.

> [!NOTE]
> Esse processo se aplica somente a controles de caixa de diálogo dentro de um projeto MFC. Projetos ATL devem usar o **novas mensagens do Windows e manipuladores de eventos** caixa de diálogo. Para obter mais informações, consulte [tipos de mensagem associados com objetos de Interface do usuário](../mfc/reference/message-types-associated-with-user-interface-objects.md), [editando um manipulador de mensagem](../mfc/reference/editing-a-message-handler.md), e [definindo um manipulador de mensagens para uma mensagem refletida](../mfc/reference/defining-a-message-handler-for-a-reflected-message.md).

1. No [editor de caixa de diálogo](../windows/dialog-editor.md), selecione um controle.

1. Ao pressionar o **Ctrl** da chave, clique duas vezes o controle de caixa de diálogo.

   O [assistente Adicionar variável de membro](../ide/add-member-variable-wizard.md) é exibida.

1. Digite as informações apropriadas na **Adicionar variável de membro** assistente. Para obter mais informações, consulte [troca de dados de caixa de diálogo](../mfc/dialog-data-exchange.md).

1. Selecione **Okey** para retornar para o **caixa de diálogo** editor.

   > [!TIP]
   > Para saltar de qualquer controle de caixa de diálogo para seu manipulador existente, clique duas vezes no controle.

Você também pode usar o **variáveis de membro** guia o [MFC Class Wizard](../mfc/reference/mfc-class-wizard.md) para adicionar novas variáveis de membro para uma classe especificada e exibir as variáveis de membro que já foram definidas.

## <a name="to-delete-a-control"></a>Para excluir um controle

Na caixa de diálogo, selecione o controle e pressione a **excluir** chave.

   \- ou -

Sobre o **edite** menu, selecione **excluir**.

   > [!TIP]
   > Ao usar o **caixa de diálogo** editor, em muitos casos, você pode clicar no botão direito do mouse para exibir um menu de atalho de comandos usados com frequência.

## <a name="known-issue"></a>Problema conhecido

Depois de adicionar um controle comum ou um controle rich edit para uma caixa de diálogo, ela não aparecerá quando você testa a caixa de diálogo ou a própria caixa de diálogo não aparecerá.

Para ver um exemplo do problema:

1. Crie um projeto do Win32, modificando as configurações do aplicativo, portanto, você cria um aplicativo do Windows (não um aplicativo de console).

1. Na [exibição de recurso](../windows/resource-view-window.md), clique duas vezes no arquivo. rc.

1. Sob a opção de caixa de diálogo, clique duas vezes o **sobre** caixa.

1. Adicionar um **controle de endereço IP** à caixa de diálogo.

1. Salvar e **recompilar tudo**.

1. Execute o programa.

1. Na caixa de diálogo **ajudar** menu, clique no **sobre** comando; nenhuma caixa de diálogo caixa é exibida.

Atualmente, o **caixa de diálogo** editor automaticamente não adiciona código ao seu projeto quando você arrasta e solta os seguintes controles comuns ou controles em uma caixa de diálogo de edição avançada. Nem o Visual Studio fornece um erro ou aviso quando esse problema ocorre. Para corrigir, adicione o código para o controle manualmente.

||||
|-|-|-|
|Controle deslizante|Controle de árvore|Seletor de data e hora|
|Controle de rotação|Controle de guia|Calendário mensal|
|Controle de progresso|Controle de animação|Controle de endereço IP|
|Tecla de acesso|Controle de edição avançada|Caixa de combinação estendida|
|Controle de lista|Controle de edição avançada 2.0|Controle personalizado|

Para usar controles comuns em uma caixa de diálogo, você precisará chamar [InitCommonControlsEx](/windows/desktop/api/commctrl/nf-commctrl-initcommoncontrolsex) ou `AFXInitCommonControls` antes de criar a caixa de diálogo.

Para usar controles RichEdit, você deve chamar `LoadLibrary`. Para obter mais informações, consulte [sobre como editar controles sofisticados](/windows/desktop/Controls/about-rich-edit-controls) no SDK do Windows e [visão geral do controle de edição de Rich](../mfc/overview-of-the-rich-edit-control.md).

> [!NOTE]
> Para usar um controle RichEdit com MFC, você deve primeiro chamar [AfxInitRichEdit2](../mfc/reference/application-information-and-management.md#afxinitrichedit2) para carregar o controle RichEdit 2.0 (RICHED20. DLL), ou chamar [AfxInitRichEdit](../mfc/reference/application-information-and-management.md#afxinitrichedit) para carregar o controle de 1.0 RichEdit mais antigos (RICHED32. DLL).
>
> Você pode usar o atual [CRichEditCtrl](../mfc/reference/cricheditctrl-class.md) classe com o controle RichEdit 1.0 mais antigo, mas `CRichEditCtrl` foi projetado apenas para dar suporte ao controle RichEdit 2.0. Como RichEdit 1.0 e 2.0 de RichEdit são semelhantes, a maioria dos métodos funcionará. No entanto, observe que há algumas diferenças entre os controles de 1.0 e 2.0, portanto, alguns métodos podem funcionar incorretamente ou não funcionar em todos os.

## <a name="requirements"></a>Requisitos

Win32

## <a name="see-also"></a>Consulte também

[Editor de caixa de diálogo](../windows/dialog-editor.md)<br/>
[Controles em caixas de diálogo](controls-in-dialog-boxes.md)<br/>
[Arquivos de recurso](../windows/resource-files-visual-studio.md)<br/>

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