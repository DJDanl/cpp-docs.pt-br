---
title: Exibindo e adicionando controles ActiveX a uma caixa de diálogo (C++)
ms.date: 11/04/2016
f1_keywords:
- vc.controls.activex
- vc.editors.dialog.insertActiveXControls
helpviewer_keywords:
- dialog boxes [C++], adding ActiveX controls
- ActiveX controls [C++], adding to dialog boxes
- Insert ActiveX Control dialog box [C++]
- controls [C++], editing properties
- ActiveX controls [C++], properties
ms.assetid: e1c2e3ae-e1b0-40d3-9766-623007073856
ms.openlocfilehash: 139407ec1d4e1bfad6bb06854dc24b86ce7014e8
ms.sourcegitcommit: b488462a6e035131121e6f32d8f3b108cc798b5e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 01/30/2019
ms.locfileid: "55293605"
---
# <a name="viewing-and-adding-activex-controls-to-a-dialog-box-c"></a>Exibindo e adicionando controles ActiveX a uma caixa de diálogo (C++)

Visual Studio permite que você inserir controles ActiveX em sua caixa de diálogo.

O **Inserir controle ActiveX** caixa de diálogo permite que você inserir controles ActiveX em sua caixa de diálogo enquanto estiver usando o [editor de caixa de diálogo](../windows/dialog-editor.md). Essa caixa de diálogo contém as seguintes propriedades:

|Propriedade|Descrição|
|---|---|
|**Controle ActiveX**|Exibe uma lista de controles Active X. Inserindo um controle nessa caixa de diálogo não gera uma classe wrapper. Se você precisar de uma classe wrapper, use [Class View](/visualstudio/ide/viewing-the-structure-of-code) criá-lo (para obter mais informações, consulte [adicionando uma classe](../ide/adding-a-class-visual-cpp.md)). Se um controle Active X não aparecer na caixa de diálogo, tente instalar o controle de acordo com as instruções do fornecedor.|
|**Path**|Exibe o arquivo no qual o controle ActiveX é encontrado.|

Você pode colocar controles na **caixa de ferramentas** janela para facilitar o acesso. Para saber mais, confira [Caixa de Ferramentas](/visualstudio/ide/reference/).

Para obter informações sobre como adicionar recursos a projetos gerenciados, consulte [recursos em aplicativos de área de trabalho](/dotnet/framework/resources/index) na *guia do desenvolvedor do .NET Framework*. Para obter informações sobre como adicionar manualmente os arquivos de recursos a projetos gerenciados, acessar recursos, exibir recursos estáticos e atribuir cadeias de caracteres de recurso a propriedades, consulte [criando arquivos de recursos para aplicativos de área de trabalho](/dotnet/framework/resources/creating-resource-files-for-desktop-apps). Para obter informações sobre globalização e localização de recursos em aplicativos gerenciados, consulte [Globalizing e Localizando aplicativos do .NET Framework](/dotnet/standard/globalization-localization/index).

## <a name="to-see-the-activex-controls-you-have-available"></a>Para ver os controles ActiveX que estão disponíveis

1. Abra uma caixa de diálogo no editor de caixa de diálogo.

1. Clique com botão direito em qualquer lugar no corpo da caixa de diálogo.

1. No menu de atalho, selecione **Inserir controle ActiveX**.

   O **Inserir controle ActiveX** caixa de diálogo aparece, mostrando todos os controles ActiveX em seu sistema. Na parte inferior da caixa de diálogo, o caminho para o arquivo de controle ActiveX é exibida.

## <a name="to-add-an-activex-control-to-a-dialog-box"></a>Para adicionar um controle ActiveX a uma caixa de diálogo

1. No **Inserir controle ActiveX** caixa de diálogo, selecione o controle que você deseja adicionar à sua caixa de diálogo e selecione **Okey**.

   O controle aparece na caixa de diálogo onde você pode editá-lo ou criar manipuladores para ele como faria qualquer outro controle.

   > [!NOTE]
   > Você pode adicionar controles ActiveX para o [janela caixa de ferramentas](/visualstudio/ide/reference/toolbox).

   > [!CAUTION]
   > Ele pode não ser legal para distribuir todos os controles ActiveX em seu sistema. Consulte o contrato de licença para softwares que instalados os controles ou entre em contato com a empresa de software.

   Você pode colocar controles na **caixa de ferramentas** janela para facilitar o acesso. Para saber mais, confira [Caixa de Ferramentas](/visualstudio/ide/reference/toolbox).

## <a name="to-edit-properties-for-an-activex-control"></a>Para editar as propriedades de um controle ActiveX

Controles ActiveX fornecidos por fornecedores independentes podem vir equipados com suas próprias propriedades e características. Propriedades para controles ActiveX são exibidas na **propriedades** janela. Além disso, as páginas de propriedade criadas pelos gravadores do controle ActiveX são exibidas na **páginas de propriedades** caixa de diálogo (para exibir o **página de propriedades** para um controle ActiveX específico, clique o  **Página de propriedades** botão de [janela propriedades](/visualstudio/ide/reference/properties-window)).

Várias guias são exibidas na página de propriedades para um controle ActiveX, dependendo das folhas de propriedades que são fornecidos como parte do controle ActiveX.

> [!NOTE]
> O procedimento a seguir se aplica a usando a página de propriedades para editar os controles ActiveX. Você também pode procurar e editar propriedades do ActiveX no novo **propriedades** janela.

1. Selecione o **ActiveX** controle.

1. Sobre o **modo de exibição** menu, selecione **página de propriedades** e exibir as propriedades.

1. Faça as alterações necessárias na página de propriedades.

## <a name="requirements"></a>Requisitos

Win32

## <a name="see-also"></a>Consulte também

[Controles em caixas de diálogo](../windows/controls-in-dialog-boxes.md)<br/>
[Controles ActiveX do MFC](../mfc/mfc-activex-controls.md)<br/>
[Contêineres de controle ActiveX](../mfc/activex-control-containers.md)<br/>
[Exibindo e adicionando controles ActiveX a uma caixa de diálogo](../windows/viewing-and-adding-activex-controls-to-a-dialog-box.md)<br/>
[Guia Editor de Caixa de Diálogo, caixa de ferramentas](../windows/dialog-editor-tab-toolbox.md)<br/>
[Arquivos de recurso](../windows/resource-files-visual-studio.md)<br/>
