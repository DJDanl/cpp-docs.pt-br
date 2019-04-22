---
title: 'Como: Adicionar, editar ou excluir controles (C++)'
ms.date: 02/15/2019
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
ms.openlocfilehash: 2e3e671cd92313ad120d2cd6aae3f7e815e09e65
ms.sourcegitcommit: 72583d30170d6ef29ea5c6848dc00169f2c909aa
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/18/2019
ms.locfileid: "59025358"
---
# <a name="how-to-add-edit-or-delete-controls-c"></a>Como: Adicionar, editar ou excluir controles (C++)

Usando o **Editor de caixa de diálogo**, você pode adicionar, redimensionar, editar e excluir os controles em caixas de diálogo. Você também pode editar as propriedades de um controle, como sua ID, ou se é visível inicialmente no tempo de execução.

O **Editor de caixa de diálogo** guia é exibida na [janela caixa de ferramentas](/visualstudio/ide/reference/toolbox) quando você estiver trabalhando no **caixa de diálogo Editor**. Você também pode personalizar o **caixa de ferramentas** janela para facilitar o uso. Para obter mais informações, consulte [usando a caixa de ferramentas](/visualstudio/ide/using-the-toolbox) e [Mostrar ou ocultar a janela da caixa de ferramentas](showing-or-hiding-the-dialog-editor-toolbar.md).

> [!TIP]
> Ao usar o **Editor de caixa de diálogo**, em muitos casos, você pode selecionar o botão direito do mouse para exibir um menu de atalho de comandos usados com frequência.

## <a name="add-controls"></a>Adicionar controles

### <a name="to-add-a-control"></a>Para adicionar um controle

1. Certifique-se de que a janela com guias da caixa de diálogo é o documento atual no quadro do editor. Se uma caixa de diálogo não for o documento atual, você não verá os **guia do Editor de caixa de diálogo** na **caixa de ferramentas**.

1. No **Editor de caixa de diálogo** guia da **caixa de ferramentas** janela, selecione o controle desejado, e depois:

   - Marque a caixa de diálogo no local onde você deseja colocar o controle e o controle aparece em que você selecionou.

   - Arraste e solte o controle a partir de **caixa de ferramentas** janela para o local em sua caixa de diálogo e, em seguida, pode mover os controles ou alterar seu tamanho e forma.

   - Clique duas vezes no controle de **caixa de ferramentas** janela e aparece em sua caixa de diálogo, em seguida, reposicionar o controle para o local de sua preferência.

### <a name="to-add-multiple-controls"></a>Para adicionar vários controles

1. Enquanto mantém pressionada a **Ctrl** da chave, selecione um controle na **caixa de ferramentas** janela.

1. Versão do **Ctrl** da chave e marque a caixa de diálogo quantas vezes você deseja adicionar o controle específico.

1. Pressione **Esc** para interromper a colocação de controles.

### <a name="to-size-a-control-while-you-add-it"></a>Para dimensionar um controle enquanto você adicioná-lo

1. Selecione um controle na **caixa de ferramentas** janela.

1. Coloque o cursor que aparece como miras, onde você deseja que o canto superior esquerdo do novo controle esteja em sua caixa de diálogo.

1. Selecione e mantenha pressionado o botão do mouse para o canto superior esquerdo do seu controle na caixa de diálogo de ancoragem e arraste o cursor para a direita e para baixo até que o controle é o tamanho desejado.

   > [!NOTE]
   > É possível ancorar qualquer um dos quatro cantos do controle que está sendo desenhado. Esse procedimento usado no canto superior esquerdo como um exemplo.

1. Solte o botão do mouse. O controle liquida para a caixa de diálogo pelo tamanho especificado.

> [!TIP]
> Você pode redimensionar o controle após arrastando-o para a caixa de diálogo, movendo as alças de dimensionamento na borda do controle. Para obter mais informações, consulte [controles individuais do dimensionamento](../windows/sizing-individual-controls.md).

### <a name="to-add-a-custom-control"></a>Para adicionar um controle personalizado

Você pode adicionar controles personalizados à caixa de diálogo, selecionando o **controle personalizado** ícone na **caixa de ferramentas** e arrastando-o para sua caixa de diálogo. Para adicionar um **Syslink** controlar, adicionar um controle personalizado e, em seguida, alterar o controle **classe** propriedade a ser **Syslink**. Essa ação fará com que as propriedades atualizar e mostrar o **Syslink** propriedades do controle. Para obter informações sobre a classe de wrapper do MFC, consulte [CLinkCtrl](../mfc/reference/clinkctrl-class.md).

## <a name="edit-controls"></a>Controles de edição

### <a name="to-edit-the-properties-of-a-control-or-controls"></a>Para editar as propriedades de um controle ou controles

1. Na caixa de diálogo, selecione o controle que você deseja modificar.

   > [!NOTE]
   > Se você selecionar vários controles, somente as propriedades comuns para os controles selecionados podem ser editadas.

1. No [janela de propriedades](/visualstudio/ide/reference/properties-window), alterar as propriedades de seu controle.

   > [!NOTE]
   > Quando você define o **Bitmap** propriedade de um botão, um botão de opção ou um controle de caixa de seleção igual a **verdadeiro**, o estilo BS_BITMAP é implementado para o seu controle. Para obter mais informações, consulte [estilos de botão](../mfc/reference/styles-used-by-mfc.md#button-styles). Para obter um exemplo de associação de um bitmap com um controle, consulte [CButton::SetBitmap](../mfc/reference/cbutton-class.md#setbitmap). Bitmaps não aparecerá no seu controle enquanto você estiver na **Editor de caixa de diálogo**.

### <a name="to-undo-changes-to-the-properties-of-a-control"></a>Para desfazer as alterações nas propriedades de um controle

1. Verifique se o controle tem foco **Editor de caixa de diálogo**.

1. Vá ao menu **edite** > **desfazer**. Se o foco não está no controle, o **desfazer** comando estará disponível.

### <a name="to-define-a-member-variable-for-a-non-button-dialog-box-control"></a>Para definir uma variável de membro para um controle de caixa de diálogo (não-botão)

> [!NOTE]
> Esse processo se aplica somente a controles de caixa de diálogo dentro de um projeto MFC. Projetos ATL devem usar o **novas mensagens do Windows e manipuladores de eventos** caixa de diálogo. Para obter mais informações, consulte [tipos de mensagem associados com objetos de Interface do usuário](../mfc/reference/message-types-associated-with-user-interface-objects.md), [editando um manipulador de mensagem](../mfc/reference/editing-a-message-handler.md), e [definindo um manipulador de mensagens para uma mensagem refletida](../mfc/reference/defining-a-message-handler-for-a-reflected-message.md).

1. No [Editor de caixa de diálogo](../windows/dialog-editor.md), selecione um controle.

1. Ao pressionar o **Ctrl** da chave, clique duas vezes o controle de caixa de diálogo.

   O [assistente Adicionar variável de membro](../ide/add-member-variable-wizard.md) é exibida.

1. Digite as informações apropriadas na **Adicionar variável de membro** assistente. Para obter mais informações, consulte [troca de dados de caixa de diálogo](../mfc/dialog-data-exchange.md).

1. Selecione **Okey** para retornar para o **Editor de caixa de diálogo**.

> [!TIP]
> Para saltar de qualquer controle de caixa de diálogo para seu manipulador existente, clique duas vezes no controle.

Você também pode usar o **variáveis de membro** guia o [MFC Class Wizard](../mfc/reference/mfc-class-wizard.md) para adicionar novas variáveis de membro para uma classe especificada e exibir as variáveis de membro que já foram definidas.

## <a name="delete-controls"></a>Excluir controles

Na caixa de diálogo, selecione o controle, em seguida, pressione a **excluir** da chave, ou vá para o menu **editar** > **excluir**.

## <a name="other-issues"></a>Outros Problemas

### <a name="troubleshooting"></a>Solução de problemas

Depois de adicionar um controle comum ou um controle rich edit para uma caixa de diálogo, ela não aparecerá quando você testa a caixa de diálogo ou a própria caixa de diálogo não aparecerá, por exemplo:

1. Crie um projeto do Win32, modificando as configurações do aplicativo, portanto, você cria um aplicativo do Windows (não um aplicativo de console).

1. Na [exibição de recurso](how-to-create-a-resource-script-file.md#create-resources), clique duas vezes no *. rc* arquivo.

1. Sob a opção de caixa de diálogo, clique duas vezes o **sobre** caixa.

1. Adicionar um **controle de endereço IP** à caixa de diálogo.

1. Salvar e **recompilar tudo**.

1. Execute o programa.

1. Na caixa de diálogo **ajudar** menu, selecione o **sobre** de comando e observar nenhuma caixa de diálogo é exibida.

Atualmente, o **Editor de caixa de diálogo** automaticamente não adiciona código ao seu projeto quando você arrasta e solta os seguintes controles comuns ou controles em uma caixa de diálogo de edição avançada. Nem o Visual Studio fornece um erro ou aviso quando esse problema ocorre. Para corrigir, adicione o código para o controle manualmente.

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
> Você pode usar o atual [CRichEditCtrl](../mfc/reference/cricheditctrl-class.md) classe com o controle RichEdit 1.0 mais antigo, mas `CRichEditCtrl` foi projetado apenas para dar suporte ao controle RichEdit 2.0. Como RichEdit 1.0 e 2.0 de RichEdit são semelhantes, a maioria dos métodos funcionará. No entanto, há algumas diferenças entre os controles de 1.0 e 2.0, portanto, alguns métodos podem funcionar incorretamente ou não funcionar em todos os.

### <a name="activex-controls"></a>Controles ActiveX

Visual Studio permite que você inserir controles ActiveX em sua caixa de diálogo. Para obter mais informações, consulte [controles ActiveX do MFC](../mfc/mfc-activex-controls.md) e [contêineres de controle ActiveX](../mfc/activex-control-containers.md).

O **Inserir controle ActiveX** caixa de diálogo permite que você inserir controles ActiveX em sua caixa de diálogo enquanto estiver usando o [Editor de caixa de diálogo](../windows/dialog-editor.md). Essa caixa de diálogo contém as seguintes propriedades:

|Propriedade|Descrição|
|---|---|
|**Controle ActiveX**|Exibe uma lista de controles ActiveX.<br/><br/>Inserindo um controle nessa caixa de diálogo não gera uma classe wrapper. Se você precisar de uma classe wrapper, use [Class View](/visualstudio/ide/viewing-the-structure-of-code) para criar um, consulte [adicionando uma classe](../ide/adding-a-class-visual-cpp.md).<br/><br/>Se um controle ActiveX não aparecer na caixa de diálogo, tente instalar o controle de acordo com as instruções do fornecedor.|
|**Path**|Exibe o arquivo no qual o controle ActiveX é encontrado.|

> [!CAUTION]
> Ele pode não ser legal para distribuir todos os controles ActiveX em seu sistema. Consulte o contrato de licença para softwares que instalados os controles ou entre em contato com a empresa de software.

#### <a name="to-add-an-activex-control"></a>Para adicionar um controle ActiveX

1. Abra uma caixa de diálogo **Editor de caixa de diálogo**.

1. Clique com botão direito em qualquer lugar no corpo da caixa de diálogo e selecione **Inserir controle ActiveX**.

   O **Inserir controle ActiveX** caixa de diálogo aparece, mostrando todos os controles ActiveX em seu sistema. Na parte inferior da caixa de diálogo, o caminho para o arquivo de controle ActiveX é exibida.

1. Selecione o controle que você deseja adicionar à sua caixa de diálogo e escolha **Okey**.

   O controle aparece na caixa de diálogo onde você pode editá-lo ou criar manipuladores para ele como faria qualquer outro controle.

> [!TIP]
> Você pode usar o menu de atalho a **Editor de caixa de diálogo** rapidamente adicionar controles ActiveX registrados para uma caixa de diálogo, ou tente adicionar controles ActiveX para o **caixa de ferramentas** janela para facilitar o acesso.

#### <a name="to-edit-properties-for-an-activex-control"></a>Para editar as propriedades de um controle ActiveX

Controles ActiveX fornecidos por fornecedores independentes podem vir equipados com suas próprias propriedades e características. Essas propriedades são exibidas na **propriedades** janela, incluindo qualquer propriedade páginas criadas pelos gravadores do controle ActiveX são exibidas na **páginas de propriedades** caixa de diálogo (para exibir as  **Página de propriedades** para um controle ActiveX específico, selecione o **página de propriedades** botão o [janela propriedades](/visualstudio/ide/reference/properties-window)).

- Selecione o **ActiveX** controlar e vá para o menu **exibição** > **página de propriedades** para exibir as propriedades. Faça as alterações necessárias na página de propriedades.

   Várias guias são exibidas na página de propriedades para um controle ActiveX, dependendo das folhas de propriedades que são fornecidos como parte do controle ActiveX.

> [!NOTE]
> Este procedimento se aplica a usando a página de propriedades para editar os controles ActiveX. Você também pode procurar e editar propriedades do ActiveX no novo **propriedades** janela.

## <a name="requirements"></a>Requisitos

Win32

## <a name="see-also"></a>Consulte também

[Gerenciar controles de caixa de diálogo](controls-in-dialog-boxes.md)<br/>
[Como: Controles de layout](arrangement-of-controls-on-dialog-boxes.md)<br/>
[Como: Definir acesso e valores de controle](defining-mnemonics-access-keys.md)<br/>

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