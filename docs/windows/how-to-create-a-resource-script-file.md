---
title: 'Como: criar recursos (C++)'
ms.date: 02/14/2019
f1_keywords:
- vc.editors.resource
- vc.resvw.add.MFC
- vs.resourceview.F1
- vc.editors.insertresource
- vc.editors.newcustomresource
helpviewer_keywords:
- rc files [C++], creating
- .rc files [C++], creating
- resource script files [C++], creating
- resources [C++], viewing
- rc files [C++], viewing resources
- .rc files [C++], viewing resources
- resource script files [C++], viewing resources
- resource script files [C++], opening in text format
- .rc files [C++], opening in text format
- rc files [C++], opening in text format
- rc files [C++], adding MFC support
- .rc files [C++], adding MFC support
- MFC, adding support to resource scripts files
- resource script files [C++], adding MFC support
- toolbars [C++], resources
- resource toolbars
- resources [C++], creating
- Resource View window
- resources [C++], adding
- Add Resource dialog box [C++]
- Custom Resource Type dialog box [C++]
- language-specific template files [C++]
- resource templates
- rct files [C++]
- templates, resource templates
- resources [C++], templates
- .rct files [C++]
ms.assetid: 82be732a-cdcd-4a58-8de7-976d1418f86b
ms.openlocfilehash: c997c7a1b2d7fb3a852a42fa78faf2be6074705e
ms.sourcegitcommit: 3e8fa01f323bc5043a48a0c18b855d38af3648d4
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/06/2020
ms.locfileid: "78866115"
---
# <a name="how-to-create-resources-c"></a>Como: criar recursos (C++)

Você pode criar recursos para seu projeto:

- Usando um arquivo de script de recurso.

   > [!NOTE]
   > Essa etapa é necessária antes de adicionar recursos.

- Adicionar recursos ao seu projeto e usar o **modo de exibição de recursos**.

- Usando um modelo de recurso para criar recursos personalizados.

## <a name="use-resource-script-files"></a>Usar arquivos de script de recurso

Antes de criar e adicionar novos recursos ao seu projeto, você deve primeiro criar um arquivo de script de recurso (. rc).

> [!NOTE]
> Você só pode adicionar um arquivo de script de recurso a um projeto existente carregado no IDE do Visual Studio. Você não pode criar um script de recurso autônomo fora do projeto, embora arquivos de modelo de recurso (. rct) possam ser criados a qualquer momento.

### <a name="to-create-a-resource-script-file"></a>Para criar um arquivo de script de recurso

1. Coloque o foco em sua pasta de projeto existente em **Gerenciador de soluções**, por exemplo, *MyProject*.

   > [!NOTE]
   > Não confunda a pasta do projeto com a pasta da solução em **Gerenciador de soluções**. Se você colocar o foco na pasta da **solução** , não terá as mesmas opções **Adicionar novo item** .

1. No menu, vá para **projeto** > **Adicionar novo item**.

1. Selecione a **pasta C++ Visual** e escolha **arquivo de recurso (. rc)** no painel direito.

1. Forneça um nome para o arquivo de script de recurso na caixa de texto **nome** e selecione **abrir**.

### <a name="to-open-a-resource-script-file"></a>Para abrir um arquivo de script de recurso

Você pode exibir recursos em um arquivo de script de recurso sem ter um projeto aberto. O arquivo de script é aberto em uma janela de documento em oposição ao **modo de exibição de recursos**.

> [!NOTE]
> Alguns comandos só estarão disponíveis se o arquivo for aberto autônomo, o que significa fora de um projeto sem primeiro carregar o projeto. Por exemplo, para usar o comando **salvar como** e salvar um arquivo com um formato ou nome de arquivo diferente, o arquivo deve ser aberto autônomo.

- Para abrir um arquivo de script de recurso fora de um projeto, no menu, vá para **arquivo** > **abrir**e escolha **arquivo**. Navegue até o arquivo de script de recurso, realce o arquivo e escolha **abrir**.

    > [!NOTE]
    > Pode haver ocasiões em que você deseja exibir o conteúdo do arquivo de script de recurso do projeto sem usar os editores de recursos para abrir um recurso. Por exemplo, talvez você queira procurar uma cadeia de caracteres em todas as caixas de diálogo no arquivo de recursos sem precisar abrir cada uma separadamente. Você pode abrir facilmente o arquivo de recursos no formato de texto para exibir todos os recursos que ele contém e concluir as operações globais com suporte no editor de texto.
    >
    > Para abrir um arquivo de script de recurso em formato de texto, use a seta suspensa no lado direito do botão **abrir** na etapa anterior e escolha **abrir com**. Selecione **Editor de código-fonte (texto)** e, na lista suspensa **abrir como** , selecione **texto** e o recurso será aberto no editor de **código-fonte** .

- Para abrir vários scripts de recurso, siga a mesma etapa acima para cada arquivo que você deseja abrir, por exemplo, *origem1. rc* e *origem2. rc*. Em seguida, quando os arquivos. rc estiverem abertos em janelas de documentos separadas, use o menu **janela** ou clique com o botão direito do mouse em um dos arquivos e escolha **novo grupo de guias horizontais** ou **novo grupo de guias verticais**. Agora, as janelas são colocadas em ladrilho para que você possa exibi-las simultaneamente.

> [!TIP]
> Você pode abrir arquivos de script de recurso clicando com o botão direito do mouse no arquivo. RC em **Gerenciador de soluções**, selecionando **abrir com** e escolhendo **Editor de código-fonte (texto)** .

Quando você cria um aplicativo MFC (Microsoft Foundation Class) para Windows usando o [Assistente de aplicativo MFC](../mfc/reference/mfc-application-wizard.md), o assistente gera um conjunto básico de arquivos, incluindo um arquivo de script de recurso (. rc)) que contém os principais recursos do MFC. No entanto, esses recursos específicos do MFC não estão disponíveis ao editar um arquivo. rc para aplicativos do Windows que não são baseados no MFC. Isso inclui assistentes de código, cadeias de caracteres de prompt de menu, conteúdo de lista para controles de caixa de combinação e Hospedagem de controles ActiveX.

- Para adicionar suporte a MFC, com o arquivo de script de recurso aberto, em **modo de exibição de recursos**, realce a pasta recursos (por exemplo, *MFC. rc*). Em seguida, na [janela Propriedades](/visualstudio/ide/reference/properties-window), defina o **modo MFC** como **true**.

  > [!NOTE]
  > Além de definir o **modo MFC**, o arquivo. rc deve fazer parte de um projeto MFC. Apenas a configuração do **modo MFC** como **true** em um arquivo. RC em um projeto Win32 não fornecerá recursos do MFC.

## <a name="create-resources"></a>Criar recursos

Você pode criar um recurso como um novo recurso padrão, o que significa um recurso que não se baseia em um modelo ou como um recurso padronizado após um modelo.

Use a janela **modo de exibição de recursos** para exibir arquivos de recursos incluídos em seus projetos. Expandir a pasta superior, por exemplo, *Projeto1. rc*, mostra os tipos de recursos dentro desse arquivo. Expanda cada tipo de recurso para mostrar os recursos individuais desse tipo.

> [!TIP]
> Para abrir a janela **modo de exibição de recursos** , vá para **modo de exibição** de menu > outro > do **Windows** **modo de exibição de recursos** ou pressione **Ctrl**+**Shift**+**E**.

Você também pode usar o botão direito do mouse na janela **modo de exibição de recursos** para iniciar um menu de atalho de comandos ou clicar duas vezes na barra de título para encaixar e desencaixar a janela. Clique com o botão direito do mouse na barra de título para obter comandos que controlam o comportamento da janela. Para obter mais informações, consulte [Gerenciamento do Windows](/visualstudio/ide/customizing-window-layouts-in-visual-studio).

O **modo de exibição de recursos** Windows inclui a caixa de diálogo **Adicionar recurso** com as seguintes propriedades para adicionar recursos a C++ um projeto de aplicativo da área de trabalho do Windows:

| Propriedade | DESCRIÇÃO |
|---|---|
| **Tipo de recurso** | Especifique o tipo de recurso que você deseja criar.<br/><br/>Você pode expandir as categorias de recurso de cursor e caixa de diálogo para revelar recursos adicionais, que estão localizados em *.. \Microsoft Visual Studio \<versão\>\VC\VCResourceTemplates\\< LCID\>\mfc.rct*. Se você precisar adicionar arquivos. RCT, coloque-os aqui ou especifique outro [caminho de inclusão](../windows/how-to-specify-include-directories-for-resources.md). Os recursos mostrados no nível superior no controle de árvore são os recursos padrão fornecidos pelo Visual Studio. Os recursos nos arquivos. rct aparecem no segundo nível sob a categoria apropriada. Não há limite predefinido para o número de arquivos. rct que você pode adicionar.<br/><br/> |
| **Novo** | Crie um recurso com base no tipo selecionado na caixa **tipo de recurso** e abra o recurso no editor apropriado.<br/><br/>Por exemplo, se você criar um recurso de caixa de diálogo, ele abrirá o recurso no [Editor de caixa de diálogo](../windows/dialog-editor.md). |
| **Importaçãoação** | Abra a caixa de diálogo **importar** para navegar até o recurso que você deseja importar para o projeto atual.<br/><br/>Você pode importar um bitmap, ícone, cursor, HTML, som (. WAV) ou arquivo de recurso personalizado. |
| **Custom** | Abra a caixa de diálogo **novo recurso personalizado** para criar um recurso personalizado.<br/><br/>Também inclui uma propriedade de **tipo de recurso** que fornece uma caixa de texto para inserir o nome do tipo de recurso personalizado. O C++ Visual automaticamente coloca em maiúscula o nome quando você sai. Os recursos personalizados são editados apenas no [Editor de binários](../windows/binary-editor.md). |

Quando você cria um novo recurso, o C++ Visual atribui um nome exclusivo a ele, por exemplo, `IDD_Dialog1`. Você pode personalizar essa ID de recurso editando as propriedades de recurso no editor de recursos associado ou no [janela Propriedades](/visualstudio/ide/reference/properties-window).

> [!NOTE]
> Não especifique um nome de recurso ou uma ID que seja reservada pelo Visual Studio. Os nomes reservados são `DESIGNINFO`, `HWB`e `TEXTINCLUDE`, e a ID reservada é `255`.

### <a name="to-create-a-resource"></a>Para criar um recurso

- Em **modo de exibição de recursos**, selecione o arquivo. rc e, em seguida, use **Editar** > **Adicionar recurso** e escolha o tipo de recurso a ser adicionado ao seu projeto.

   > [!TIP]
   > Você também pode clicar com o botão direito do mouse no arquivo. RC em **modo de exibição de recursos** e escolher **Adicionar recurso** no menu de atalho.

- Em **Gerenciador de soluções**, clique com o botão direito do mouse na pasta do projeto, selecione **Adicionar** > **Adicionar recurso** e escolha o tipo de recurso a ser adicionado ao seu projeto.

   > [!NOTE]
   > Se você ainda não tiver um arquivo. RC em seu projeto, esta etapa criará um. Em seguida, você pode repetir essa etapa para adicionar tipos de recursos específicos ao novo arquivo. rc.

- Em [modo de exibição de classe](/visualstudio/ide/viewing-the-structure-of-code), clique com o botão direito do mouse na classe, selecione **Adicionar** > **Adicionar recurso** e escolha o tipo de recurso a ser adicionado ao seu projeto.

- Use o menu de **projeto** > **Adicionar recurso**.

## <a name="use-resource-templates"></a>Usar modelos de recursos

Um modelo de recurso é um recurso personalizado que você salvou como um arquivo. RCT. Um modelo de recurso, então, serve como um ponto de partida para a criação de recursos. Os modelos de recursos economizam tempo no desenvolvimento de recursos adicionais ou grupos de recursos que compartilham recursos, como controles padrão ou elementos repetidos. Por exemplo, se você quiser incluir um botão de ajuda com um ícone de logotipo da empresa em várias caixas de diálogo, crie um novo modelo de caixa de diálogo e personalize-o com o botão ajuda e o logotipo.

Depois de personalizar um modelo de recurso, salve as alterações na pasta do modelo ou no local especificado no caminho de inclusão, para que o novo modelo de recurso seja exibido sob seu tipo de recurso na caixa de diálogo **Adicionar recurso** . Agora você pode usar o novo modelo de recurso sempre que necessário.

> [!NOTE]
> O editor de recursos fornece automaticamente uma ID de recurso exclusiva. Você pode revisar as [Propriedades de recurso](../windows/changing-the-properties-of-a-resource.md) conforme necessário.

> [!NOTE]
> Coloque arquivos de modelo específicos do idioma em subdiretórios do diretório principal do modelo. Por exemplo, arquivos de modelo somente em inglês entram em *..\\< diretório de modelo de recurso\>\ 1033*.
>
> O Visual Studio procura novos arquivos. rct em *\Program Files\Microsoft visual studio \<versão\>\VC\VCResourceTemplates*, *\Program files\microsoft visual studio \<versão > \VC\VCRESOURCETEMPLATES\\< LCID*\>(como um LCID de 1033 para inglês) ou em qualquer lugar no [caminho de inclusão](../windows/how-to-specify-include-directories-for-resources.md). Se preferir armazenar seus arquivos. rct em outro local, você deverá adicionar o local ao caminho de inclusão.

### <a name="to-create-and-use-a-resource-template"></a>Para criar e usar um modelo de recurso

1. Em **Gerenciador de soluções**, clique com o botão direito do mouse em seu projeto e selecione **Adicionar** > **Adicionar novo item**.

1. No painel **modelos:** , selecione **arquivo de modelo de recurso (. rct)** .

1. Forneça um nome e um local para o novo arquivo *. rct* e escolha **abrir**.

   O novo arquivo *. rct* é adicionado ao seu projeto e aparece na **Gerenciador de soluções** na pasta **recursos** .

1. Clique duas vezes no arquivo *. rct* para abri-lo em uma janela de documento. Para adicionar recursos, clique com o botão direito do mouse no arquivo na janela do documento e escolha **Adicionar recurso**.

   Você pode personalizar seus recursos adicionados e salvar o arquivo *. rct* .

1. No painel de **modo de exibição de recursos** , clique com o botão direito do mouse no arquivo *. rc* e escolha **Adicionar recurso**.

1. Selecione o sinal de adição ( **+** ) ao lado de um recurso para expandir o nó de recursos e exibir os modelos disponíveis para esse recurso.

1. Clique duas vezes no modelo que você deseja usar.

   Você pode modificar o recurso adicionado conforme necessário em seu editor de recursos.

### <a name="to-convert-an-existing-resource-file-to-a-template"></a>Para converter um arquivo de recurso existente em um modelo

Com o arquivo de script de recurso aberto, no menu, vá para **arquivo** > **salvar \<*nome*do arquivo > como**. Especifique um local e escolha **OK**.

## <a name="requirements"></a>Requisitos

Win32

## <a name="see-also"></a>Confira também

[Arquivos de recurso](../windows/resource-files-visual-studio.md)<br/>
[Como: gerenciar recursos](../windows/how-to-copy-resources.md)<br/>
[Como incluir recursos em tempo de compilação](../windows/how-to-include-resources-at-compile-time.md)<br/>