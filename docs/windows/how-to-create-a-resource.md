---
title: 'Como: Criar um recurso (C++)'
ms.date: 11/04/2016
f1_keywords:
- vs.resourceview.F1
- vc.editors.insertresource
- vc.editors.newcustomresource
helpviewer_keywords:
- toolbars [C++], resources
- resource toolbars
- resources [C++], creating
- resources [C++], viewing
- Resource View window
- resources [C++], adding
- Add Resource dialog box [C++]
- Custom Resource Type dialog box [C++]
ms.assetid: aad44914-9145-45a3-a7d8-9de89b366716
ms.openlocfilehash: fdf158bab7894497dbcfb147eb2c6e061879be75
ms.sourcegitcommit: 63c072f5e941989636f5a2b13800b68bb7129931
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 02/06/2019
ms.locfileid: "55764045"
---
# <a name="how-to-create-a-resource-c"></a>Como: Criar um recurso (C++)

O **exibição de recurso** janela exibe os arquivos de recursos incluídos em seus projetos. Expandir a pasta superior (por exemplo, Project1.rc) mostra os tipos de recurso dentro desse arquivo. rc. Expandir cada tipo de recurso mostra os recursos individuais desse tipo.

> [!NOTE]
> Essas informações não se aplica a recursos em aplicativos da plataforma Universal do Windows. Para obter mais informações sobre isso, consulte [recursos do aplicativo e o sistema de gerenciamento de recursos](/windows/uwp/app-resources/).

> [!NOTE]
> **Exibição de recurso** não tem suporte nas edições Express.

Para obter informações sobre como adicionar recursos a projetos gerenciados, consulte [recursos em aplicativos de área de trabalho](/dotnet/framework/resources/index) na *guia do desenvolvedor do .NET Framework*.

> [!NOTE]
> Se seu projeto já não contiver um arquivo. RC, consulte [criando um novo arquivo de Script de recurso](../windows/how-to-create-a-resource-script-file.md).

O **exibição de recurso** janela usa o **adicionar recurso** caixa de diálogo para adicionar recursos a um projeto de aplicativo da área de trabalho do Windows C++. Essa caixa de diálogo tem as seguintes propriedades:

|Propriedade|Descrição|
|---|---|
|**Tipo de recurso**|Especifica o tipo de recurso que você deseja criar.<br/><br/>Você pode expandir as categorias de recursos de caixa de cursor e a caixa de diálogo para revelar os recursos adicionais. Esses recursos estão localizados no Visual Studio de ...\Microsoft `version`\VC\VCResourceTemplates\\< LCID\>\mfc.rct. Se você adicionar arquivos. rct, você deve colocá-los neste diretório ou você deve especificar um [caminho de inclusão](../windows/how-to-specify-include-directories-for-resources.md) para eles. Os recursos nesses arquivos, em seguida, aparecem no segundo nível sob a categoria apropriada. Não há nenhum limite predefinido para o número de arquivos. rct que você pode adicionar.<br/><br/>Os recursos mostrados no nível superior no controle de árvore são os recursos padrão que são fornecidos pelo Visual Studio.|
|**Novo**|Cria um recurso com base no tipo que você selecionou na **tipo de recurso** caixa. O recurso é aberto no editor apropriado. Por exemplo, se você criar um recurso de caixa de diálogo, ele abre na [editor de caixa de diálogo](../windows/dialog-editor.md).|
|**Importarar**|Abre o **importação** caixa de diálogo na qual você pode navegar para um recurso você deseja importar para seu projeto atual. Você pode importar um bitmap, o ícone, o cursor, o arquivo de recurso do HTML, som (. Arquivo de recurso WAV) ou arquivo de recurso personalizado.|
|**Personalizado**|Abre o **novo recurso personalizado** caixa de diálogo na qual você pode criar um recurso personalizado. Recursos personalizados podem ser editados no editor binário.|

O **novo recurso personalizado** caixa de diálogo permite que você crie um novo recurso personalizado em um projeto C++. Essa caixa de diálogo tem a seguinte propriedade:

|Propriedade|Descrição|
|---|---|
|**Tipo de recurso**|Fornece uma caixa de texto para que você insira o nome de um tipo de recurso personalizado. Visual C++ escreve o nome automaticamente quando você sair do **novo recurso personalizado** caixa de diálogo.|

Quando você cria um novo recurso, Visual C++ atribui um nome exclusivo a ele, por exemplo, `IDD_Dialog1`. Você pode personalizar essa ID de recurso, editando as propriedades para o recurso no editor de recursos associado ou nos [janela de propriedades](/visualstudio/ide/reference/properties-window).

Você pode criar um recurso como um novo recurso de padrão (um recurso que não é baseado em um modelo) ou como um recurso em conformidade com um [modelo](../windows/how-to-use-resource-templates.md).

> [!NOTE]
> Não especifique um nome de recurso ou ID é reservado pelo Visual Studio. Os nomes reservados são DESIGNINFO, HWB, e TEXTINCLUDE e o ID reservado é 255.

## <a name="to-open-the-resource-view-window"></a>Para abrir a janela de exibição de recurso

Selecione **exibição de recurso** sobre o **exibição** menu.

   \- ou -

Pressione **Ctrl** + **Shift** + **E**.

> [!TIP]
> Clique duas vezes no **exibição de recurso** janela para iniciar um menu de atalho de comandos. Você também pode clicar duas vezes na barra de título para encaixar ou desencaixar a janela. Clicando duas vezes na barra de título fornece comandos adicionais que permitem que você controle o comportamento da janela. Para obter mais informações, consulte [Windows Management](/visualstudio/ide/customizing-window-layouts-in-visual-studio).

## <a name="to-create-a-new-resource-in-resource-view"></a>Para criar um novo recurso no modo de exibição de recurso

1. Com foco em seu arquivo. rc no **exibição de recurso**, selecione o **editar** menu e escolha **adicionar recurso** (ou clique com botão direito no arquivo. rc no **domododeexibiçãoderecursos** e escolha **adicionar recurso** no menu de atalho).

   > [!NOTE]
   > Se seu projeto já não contiver um arquivo. RC, consulte [criando um novo arquivo de Script de recurso](../windows/how-to-create-a-resource-script-file.md).

1. No **adicionar recurso** caixa de diálogo, escolha o tipo de recurso que você deseja adicionar ao seu projeto.

## <a name="to-create-a-new-resource-in-solution-explorer"></a>Para criar um novo recurso no Gerenciador de soluções

1. Na **Gerenciador de soluções**, clique na pasta do projeto e escolha **Add**, em seguida, clique em **adicionar recurso** no menu de atalho.

   Se você ainda não tiver um arquivo. rc em seu projeto, esta etapa criará um. Você pode, em seguida, repita essa etapa para adicionar tipos de recursos específicos para o novo arquivo. rc.

2. No **adicionar recurso** caixa de diálogo, escolha o tipo de recurso que você deseja adicionar ao seu projeto.

## <a name="to-create-a-new-resource-in-class-view"></a>Para criar um novo recurso no modo de exibição de classe

1. Na [Class View](/visualstudio/ide/viewing-the-structure-of-code), sua classe com o botão direito e escolha **Add**, em seguida, selecione **adicionar recurso** no menu de atalho.

2. No **adicionar recurso** caixa de diálogo, escolha o tipo de recurso que você deseja adicionar ao seu projeto.

## <a name="to-create-a-new-resource-from-the-project-menu"></a>Para criar um novo recurso no menu projeto

Dos **Project** menu, escolha **adicionar recurso**.

## <a name="requirements"></a>Requisitos

Win32

## <a name="see-also"></a>Consulte também

[Trabalhando com arquivos de recurso](../windows/working-with-resource-files.md)<br/>
[Arquivos de recurso](../windows/resource-files-visual-studio.md)<br/>
[Editores de recursos](../windows/resource-editors.md)<br/>
