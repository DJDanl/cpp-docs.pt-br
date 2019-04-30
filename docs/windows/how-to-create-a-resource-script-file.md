---
title: 'Como: Criar recursos (C++)'
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
ms.openlocfilehash: c22df99240c0fa076124e33224a4f6f4ab9a957e
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62376819"
---
# <a name="how-to-create-resources-c"></a>Como: Criar recursos (C++)

Você pode criar recursos para seu projeto por:

- Usando um arquivo de script de recurso.

   > [!NOTE]
   > Essa etapa é necessária antes de adicionar recursos.

- Adicionando recursos ao seu projeto e usando o **exibição de recurso**.

- Usando um modelo de recurso para criar recursos personalizados.

## <a name="use-resource-script-files"></a>Usar arquivos de Script de recurso

Antes de criar e adicionar novos recursos ao seu projeto, crie primeiro um arquivo de script (. rc) do recurso.

> [!NOTE]
> Você só pode adicionar um arquivo de script de recurso a um projeto existente carregado no IDE do Visual Studio. Você não pode criar um script de recurso autônomo fora do projeto, embora os arquivos de modelo (. rct) de recurso podem ser criados a qualquer momento.

### <a name="to-create-a-resource-script-file"></a>Para criar um arquivo de script de recurso

1. Colocar o foco na sua pasta de projeto existente no **Gerenciador de soluções**, por exemplo, *MyProject*.

   > [!NOTE]
   > Não confunda a pasta do projeto com a pasta da solução no **Gerenciador de soluções**. Se você colocar o foco na **solução** pasta, você não terá o mesmo **Adicionar Novo Item** escolhas.

1. No menu, acesse **Project** > **Adicionar Novo Item**.

1. Selecione o **Visual C++** pasta e escolha **arquivo de recurso (. rc)** no painel direito.

1. Forneça um nome para seu arquivo de script de recurso nas **nome** caixa de texto e selecione **abrir**.

### <a name="to-open-a-resource-script-file"></a>Para abrir um arquivo de script de recurso

Você pode exibir recursos em um arquivo de script de recurso sem ter um projeto aberto. O arquivo de script é aberto em uma janela de documento em vez de **exibição de recurso**.

> [!NOTE]
> Alguns comandos só estarão disponíveis se o arquivo é aberto autônomo, ou seja, fora de um projeto sem primeiro carregar o projeto. Por exemplo, para usar o **Salvar como** de comando e salvar um arquivo com um nome de arquivo ou formato diferente, o arquivo deve ser aberto autônomo.

- Para abrir um arquivo de script de recurso fora de um projeto, no menu, acesse **arquivo** > **abra**e escolha **arquivo**. Navegue até o arquivo de script de recurso, realce o arquivo e escolha **aberto**.

    > [!NOTE]
    > Pode haver ocasiões em que você deseja exibir o conteúdo do arquivo de script de recurso do seu projeto sem usar os editores de recursos para abrir um recurso. Por exemplo, você talvez queira procurar uma cadeia de caracteres em todas as caixas de diálogo no arquivo de recurso sem precisar abrir cada um deles separadamente. Você pode facilmente abrir o arquivo de recurso no formato de texto para exibir todos os recursos que ele contém e concluir operações globais com suporte pelo editor de texto.
    >
    > Para abrir um arquivo de script de recurso no formato de texto, use a seta suspensa no lado direito do **abra** botão na etapa anterior e escolha **abrir com**. Selecione **Editor de código-fonte (texto)** e para o **abrir como** lista suspensa, selecione **texto** e o recurso é aberto no **código-fonte** Editor.

- Para abrir o recurso de vários scripts seguem a mesma etapa acima para cada arquivo que você deseja abrir, por exemplo, *Source1.rc* e *Source2.rc*. Em seguida, quando ambos os arquivos. rc estão abertos em janelas de documentos separados, ou use o **janela** menu ou clique em um dos arquivos e escolha **novo grupo de guias horizontais** ou **novo grupo de guias verticais** . Os windows agora são lado a lado para que você pode exibi-los simultaneamente.

> [!TIP]
> Você pode abrir arquivos de script do recurso clicando com o arquivo. rc no **Gerenciador de soluções**, selecionando **abrir com** e selecionando **Editor de código-fonte (texto)**.

Quando você cria um aplicativo do Microsoft Foundation Class (MFC) para Windows usando o [Assistente de aplicativo MFC](../mfc/reference/mfc-application-wizard.md), o assistente gera um conjunto básico de arquivos, incluindo um arquivo de script (. rc) do recurso) que contém os principais recursos do MFC. No entanto, esses recursos específicos do MFC não estão disponíveis ao editar um arquivo. RC para aplicativos do Windows que não se baseia no MFC. Isso inclui assistentes de código, cadeias de caracteres de prompt do menu, Listar conteúdo para controles de caixa de combinação e hospedagem de controles ActiveX.

- Para adicionar suporte MFC, com o arquivo de script de recurso aberto, no **exibição de recurso**, realce a pasta de recursos (por exemplo, *RC*). Em seguida, nos [janela de propriedades](/visualstudio/ide/reference/properties-window), defina **modo MFC** para **verdadeiro**.

  > [!NOTE]
  > Além de configuração **modo MFC**, o arquivo. rc deve fazer parte de um projeto MFC. Apenas definindo **modo MFC** à **verdadeiro** em um. rc arquivo em um projeto do Win32 não dará os recursos do MFC.

## <a name="create-resources"></a>Criar recursos

Você pode criar um recurso como um novo recurso padrão, que significa que um recurso que não é baseado em um modelo, ou como um recurso que seguem o padrão depois de um modelo.

Use o **exibição de recurso** janela para exibir os arquivos de recursos incluídos em seus projetos. Expandir a pasta superior, por exemplo, *Project1.rc*, mostra os tipos de recurso dentro desse arquivo. Expanda cada tipo de recurso para mostrar os recursos individuais desse tipo.

> [!TIP]
> Para abrir o **exibição de recurso** janela, vá ao menu **exibição** > **exibição de recurso** ou pressione **Ctrl** +  **SHIFT**+**E**.

Você também pode usar o botão direito do mouse no **exibição de recurso** janela para iniciar um menu de atalho de comandos ou clique duas vezes a barra de título para encaixar e desencaixar a janela. Clique com botão direito a barra de título para os comandos que controlam o comportamento da janela. Para obter mais informações, consulte [Windows Management](/visualstudio/ide/customizing-window-layouts-in-visual-studio).

O **exibição de recurso** o windows inclui o **adicionar recurso** caixa de diálogo com as propriedades a seguir para adicionar recursos a um projeto de aplicativo da área de trabalho do Windows C++:

| Propriedade | Descrição |
|---|---|
| **Tipo de recurso** | Especifique o tipo de recurso que você deseja criar.<br/><br/>Você pode expandir as categorias de recursos de caixa de cursor e a caixa de diálogo para revelar os recursos adicionais, que estão localizados no *... \Microsoft visual Studio \<versão\>\VC\VCResourceTemplates\\< LCID\>\mfc.rct*. Se você precisar adicionar arquivos. rct, colocá-los aqui ou especificar outro [caminho de inclusão](../windows/how-to-specify-include-directories-for-resources.md). Recursos mostrados no nível superior no controle de árvore são os recursos padrão fornecidos pelo Visual Studio. Recursos em arquivos. rct aparecem no segundo nível sob a categoria apropriada. Não há nenhum limite predefinido para o número de arquivos. rct que você pode adicionar.<br/><br/> |
| **Novo** | Criar um recurso com base no tipo selecionado na **tipo de recurso** caixa e abra o recurso no editor apropriado.<br/><br/>Por exemplo, se você criar um recurso de caixa de diálogo, ele abre o recurso nas [Editor de caixa de diálogo](../windows/dialog-editor.md). |
| **Importarar** | Abra o **importação** caixa de diálogo para navegar até o recurso que você deseja importar para seu projeto atual.<br/><br/>Você pode importar um bitmap, ícone, cursor, HTML, som (. WAV) ou arquivo de recurso personalizado. |
| **Personalizado** | Abra o **novo recurso personalizado** caixa de diálogo para criar um recurso personalizado.<br/><br/>Também inclui um **tipo de recurso** propriedade que fornece uma caixa de texto para que você insira o nome do tipo de recurso personalizado. Visual C++ usa maiuscula automaticamente o nome quando você sair. Recursos personalizados só são editados na [Editor binário](../windows/binary-editor.md). |

Quando você cria um novo recurso, Visual C++ atribui um nome exclusivo a ele, por exemplo, `IDD_Dialog1`. Você pode personalizar essa ID de recurso, editando as propriedades do recurso no editor de recursos associado ou nos [janela de propriedades](/visualstudio/ide/reference/properties-window).

> [!NOTE]
> Não especifique um nome de recurso ou ID é reservado pelo Visual Studio. Nomes reservados são `DESIGNINFO`, `HWB`, e `TEXTINCLUDE`, e o ID reservado é `255`.

### <a name="to-create-a-resource"></a>Para criar um recurso

- Na **exibição de recurso**, selecione o arquivo. RC, em seguida, usar **editar** > **adicionar recurso** e escolha o tipo de recurso a ser adicionado ao seu projeto.

   > [!TIP]
   > Você pode também com o botão direito no arquivo. rc no **exibição de recurso** e escolha **adicionar recurso** no menu de atalho.

- Na **Gerenciador de soluções**, clique na pasta do projeto, selecione **Add** > **adicionar recurso** e escolha o tipo de recurso a ser adicionado ao seu projeto.

   > [!NOTE]
   > Se você ainda não tiver um arquivo. rc em seu projeto, esta etapa criará um. Você pode, em seguida, repita essa etapa para adicionar tipos de recursos específicos para o novo arquivo. rc.

- Na [Class View](/visualstudio/ide/viewing-the-structure-of-code), a classe com o botão direito, selecione **Add** > **adicionar recurso** e escolha o tipo de recurso a ser adicionado ao seu projeto.

- Use o menu **Project** > **adicionar recurso**.

## <a name="use-resource-templates"></a>Usar modelos de recurso

Um modelo de recurso é um recurso personalizado que você salvou como um arquivo. rct. Um modelo de recursos, em seguida, serve como um ponto de partida para a criação de recursos. Modelos de recursos economizar tempo no desenvolvimento de outros recursos ou grupos de recursos que compartilham recursos, como controles padrão ou repetidas de elementos. Por exemplo, se você quiser incluir um botão de ajuda com um ícone do logotipo da empresa em várias caixas de diálogo, criar um novo modelo de caixa de diálogo e personalizá-lo com o botão de Ajuda e o logotipo.

Depois de personalizar um modelo de recursos, salvar suas alterações na pasta de modelo ou o local especificado no caminho de inclusão, para que apareça em seu tipo de recurso no novo modelo de recurso do **adicionar recurso** caixa de diálogo. Agora você pode usar o novo modelo de recurso com a frequência conforme necessário.

> [!NOTE]
> O editor de recursos fornece automaticamente uma ID de recurso exclusivo. Você pode revisar os [propriedades do recurso](../windows/changing-the-properties-of-a-resource.md) conforme necessário.

> [!NOTE]
> Colocar arquivos de modelo de idioma específico em subdiretórios do diretório modelo principal. Por exemplo, arquivos de modelo somente em inglês entrar *... \\< diretório de modelo de recurso\>\1033*.
>
> Visual Studio procura novos arquivos. rct *\Program Files\Microsoft Visual Studio \<versão\>\VC\VCResourceTemplates*, *\Program Files\Microsoft Visual Studio \< versão > \VC\VCResourceTemplates\\< LCID\>*  (por exemplo, um LCID 1033 para inglês), ou em qualquer lugar a [incluir caminho](../windows/how-to-specify-include-directories-for-resources.md). Se você preferir armazenar seus arquivos. rct em outro local, você deve adicionar o local para o caminho de inclusão.

### <a name="to-create-and-use-a-resource-template"></a>Criar e usar um modelo de recursos

1. Na **Gerenciador de soluções**, clique em seu projeto e selecione **Add** > **Add New Item**.

1. No **modelos:** painel, selecione **arquivo de modelo de recursos (. rct)**.

1. Forneça um nome e local para seu novo *. rct* do arquivo e escolha **abrir**.

   O novo *. rct* arquivo é adicionado ao seu projeto e aparece na **Gerenciador de soluções** sob o **recursos** pasta.

1. Clique duas vezes o *. rct* arquivo para abri-lo em uma janela do documento. Para adicionar recursos, o arquivo na janela do documento com o botão direito e escolha **adicionar recurso**.

   Você pode personalizar os recursos adicionados e salvar a *. rct* arquivo.

1. No **exibição de recurso** painel, clique com botão direito a *. rc* arquivo e escolha **adicionar recurso**.

1. Selecione o sinal de adição (**+**) ao lado de um recurso para expandir o nó de recursos e exibir os modelos disponíveis para esse recurso.

1. Clique duas vezes o modelo que você deseja usar.

   Você pode modificar o recurso adicionado conforme necessário em seu editor de recursos.

### <a name="to-convert-an-existing-resource-file-to-a-template"></a>Para converter um arquivo de recurso existente em um modelo

Com o arquivo de script de recurso aberto, no menu, vá para **arquivo** > **salvar \< *filename*> como**. Especifique um local e escolha **Okey**.

## <a name="requirements"></a>Requisitos

Win32

## <a name="see-also"></a>Consulte também

[Arquivos de recurso](../windows/resource-files-visual-studio.md)<br/>
[Como: Gerenciar recursos](../windows/how-to-copy-resources.md)<br/>
[Como: incluir recursos em tempo de compilação](../windows/how-to-include-resources-at-compile-time.md)<br/>