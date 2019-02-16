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
ms.openlocfilehash: dbb1d1d4b865380abde189ae6a72a1bfc3755840
ms.sourcegitcommit: 470de1337035dd33682d935b4b6c6d8b1bdb0bbb
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 02/15/2019
ms.locfileid: "56320842"
---
# <a name="how-to-create-resources-c"></a>Como: Criar recursos (C++)

O **exibição de recurso** janela exibe os arquivos de recursos incluídos em seus projetos. Expandir a pasta superior (por exemplo, *Project1.rc*) mostra os tipos de recursos em que o arquivo e a expansão de cada tipo de recurso mostra os recursos individuais desse tipo.

> [!TIP]
> Para abrir a janela de exibição de recursos, selecione **exibição de recurso** sobre o **exibição** menu (ou usar **Ctrl** + **Shift**  +  **E**).
>
> Você também pode usar o botão direito do mouse no **exibição de recurso** janela para abrir um menu de atalho de comandos ou clique duas vezes na barra de título para encaixar ou desencaixar a janela. Clicando duas vezes na barra de título fornece comandos adicionais que permitem que você controle o comportamento da janela. Para obter mais informações, consulte [Windows Management](/visualstudio/ide/customizing-window-layouts-in-visual-studio).

O **exibição de recurso** o windows inclui o **adicionar recurso** caixa de diálogo com as propriedades a seguir para adicionar recursos a um projeto de aplicativo da área de trabalho do Windows C++:

|Propriedade|Descrição|
|--|----|
|**Tipo de recurso**|Especifica o tipo de recurso que você deseja criar.<br/><br/>Você pode expandir as categorias de recursos de caixa de cursor e a caixa de diálogo para revelar os recursos adicionais. Esses recursos estão localizados no Visual Studio de ...\Microsoft \<versão\>\VC\VCResourceTemplates\\< LCID\>\mfc.rct. Se você adicionar arquivos. rct, colocá-los neste diretório ou especificar outro [caminho de inclusão](../windows/how-to-specify-include-directories-for-resources.md). Os recursos nesses arquivos, em seguida, aparecem no segundo nível sob a categoria apropriada. Não há nenhum limite predefinido para o número de arquivos. rct que você pode adicionar.<br/><br/>Os recursos mostrados no nível superior no controle de árvore são os recursos padrão que são fornecidos pelo Visual Studio.|
|**Novo**|Cria um recurso com base no tipo selecionado na **tipo de recurso** caixa e abre o recurso no editor apropriado. Por exemplo, se você criar um recurso de caixa de diálogo, ele abre na [editor de caixa de diálogo](../windows/dialog-editor.md).|
|**Importarar**|Abre o **importação** caixa de diálogo onde você pode navegar para o recurso você deseja importar para seu projeto atual. Você pode importar um bitmap, ícone, cursor, HTML, som (. WAV) ou arquivo de recurso personalizado.|
|**Personalizado**|Abre o **novo recurso personalizado** caixa de diálogo onde você pode criar um recurso personalizado. Recursos personalizados somente são editados no editor binário.|

O **adicionar recurso** caixa de diálogo inclui as **novo recurso personalizado** caixa de diálogo com a propriedade a seguir para criar um novo recurso personalizado em um projeto C++:

|Propriedade|Descrição|
|--|----|
|**Tipo de recurso**|Fornece uma caixa de texto para inserir o nome de um tipo de recurso personalizado. Visual C++ escreve o nome automaticamente quando você sair do **novo recurso personalizado** caixa de diálogo.|

> [!NOTE]
> O **Editor de recursos** ou **exibição de recurso** não está disponível nas edições Express.

## <a name="resource-scripts"></a>Scripts de recurso

Antes de criar e adicionar novos recursos ao seu projeto, você deve primeiro criar um script de recurso (arquivo. rc).

> [!NOTE]
> Você só pode adicionar um script de recurso (arquivo. rc) a um projeto existente que é carregado no IDE do Visual Studio. Você não pode criar um script de recurso autônomo (fora do projeto). Modelos de recursos (arquivos. rct) podem ser criados a qualquer momento.

### <a name="to-create-a-resource-script"></a>Para criar um script de recurso

1. Colocar o foco na sua pasta de projeto existente no **Gerenciador de soluções**, por exemplo, *MyProject*.

   > [!NOTE]
   > Não confunda a pasta do projeto com a pasta da solução no **Gerenciador de soluções**. Se você colocar o foco a **solução** pasta, suas opções na **Adicionar Novo Item** caixa de diálogo será diferente.

1. No menu **Projeto**, selecione **Adicionar Novo Item**.

1. Selecione o **Visual C++** pasta, em seguida, escolha **arquivo de recurso (. rc)** no painel direito.

1. Forneça um nome para seu script de recurso nas **nome** caixa de texto e selecione **abrir**.

### <a name="to-open-a-resource-script"></a>Para abrir um script de recurso

Você pode exibir recursos em um script de recurso sem ter um projeto aberto. O arquivo de script será aberto em uma janela de documento em vez de **exibição de recurso** janela.

> [!NOTE]
> Alguns comandos só estão disponíveis quando o arquivo é aberto autônomo (fora de um projeto). Abrir um arquivo autônomo significa abri-lo sem primeiro carregar o projeto.
>
> Por exemplo, para salvar um arquivo em um formato diferente ou como um nome de arquivo diferente (como o **Salvar como** comando não está disponível para o arquivo dentro de um projeto). Se você abrir o projeto usando primeiro **arquivo** > **abra** > **projeto**, esses comandos não estão disponíveis.

#### <a name="to-open-a-resource-script-outside-of-a-project"></a>Para abrir um script de recurso fora de um projeto

1. Dos **arquivo** menu, selecione **aberto**, em seguida, escolha **arquivo**.

1. Navegue até o arquivo de script de recurso, realce o arquivo e escolha **aberto**.

#### <a name="to-open-multiple-resource-scripts-outside-of-a-project"></a>Para abrir vários scripts de recurso fora de um projeto

1. Abra ambos os arquivos de recurso autônomos. Por exemplo, abra *Source1.rc* e *Source2.rc*.

1. Dos **arquivo** menu, escolha **abra**, em seguida, selecione **arquivo**.

1. Navegue até o primeiro arquivo de script de recurso que deseja abrir (*Source1.rc*), realce o arquivo e escolha **abrir**.

1. Repita a etapa anterior para abrir o segundo arquivo. RC (*Source2.rc*).

   Os dois arquivos. rc agora estão abertos em janelas de documentos separada.

1. Use o **janela** menu (ou atalho dos arquivos. rc) e escolha **novo grupo de guias horizontais** ou **novo grupo de guias verticais**.

   Os windows agora são lado a lado para que você pode exibi-los simultaneamente.

Pode haver ocasiões quando desejar exibir o conteúdo do arquivo de script (. rc) do recurso do seu projeto sem abrir um recurso, como uma caixa de diálogo dentro do seu editor de recurso específico. Por exemplo, você talvez queira procurar uma cadeia de caracteres em todas as caixas de diálogo no arquivo de recurso sem precisar abrir cada um deles separadamente.

Você pode facilmente abrir o arquivo de recurso no formato de texto para exibir todos os recursos que ele contém e concluir operações globais com suporte pelo editor de texto.

> [!NOTE]
> Os editores de recursos não ler diretamente. rc ou `resource.h` arquivos. O compilador de recurso compila-os em arquivos de .aps, que são consumidos pelos editores de recursos. Esse arquivo é uma etapa de compilação e armazena apenas dados simbólicos. Como com um normal de processo de compilação, as informações que não seja simbólicas (por exemplo, comentários) são descartadas durante o processo de compilação. Sempre que o arquivo .aps obtém fora de sincronia com o arquivo. RC, o arquivo. rc for gerado novamente (por exemplo, quando você salva, o editor de recurso substitui o arquivo. RC e o `resource.h` arquivo). Todas as alterações para os próprios recursos permanecem incorporadas no arquivo. RC, mas os comentários são perdidos depois que o arquivo. RC é substituído. Para obter informações sobre como preservar comentários, consulte [incluir recursos em tempo de compilação](../windows/how-to-include-resources-at-compile-time.md).

### <a name="to-open-a-resource-script-file-in-text-format"></a>Para abrir um arquivo de script de recurso no formato de texto

1. Dos **arquivo** menu, selecione **aberto**, em seguida, escolha **arquivo**.

1. No **abrir arquivo** caixa de diálogo, navegue até o arquivo de script de recurso que você deseja exibir no formato de texto.

1. Realce o arquivo e, em seguida, selecione a seta suspensa na **abrir** botão (à direita do botão).

1. Escolher **abrir com** no menu suspenso e selecione **Editor de código-fonte (texto)**.

1. Dos **abrir como** lista suspensa, selecione **texto**.

   O recurso é aberto na **código-fonte** editor.

> [!TIP]
> Um atalho aqui é para o botão direito do mouse no arquivo. rc no **Gerenciador de soluções**, escolha **abrir com...**  e selecione **Editor de código-fonte (texto)**.

## <a name="resources"></a>Recursos

Você pode criar um recurso como um novo recurso de padrão (um recurso que não é baseado em um modelo) ou como um recurso que seguem o padrão depois de um modelo.

Quando você cria um novo recurso, Visual C++ atribui um nome exclusivo a ele, por exemplo, `IDD_Dialog1`. Você pode personalizar essa ID de recurso, editando as propriedades para o recurso no editor de recursos associado ou nos [janela de propriedades](/visualstudio/ide/reference/properties-window).

> [!NOTE]
> Não especifique um nome de recurso ou ID é reservado pelo Visual Studio. Nomes reservados são DESIGNINFO, HWB, e TEXTINCLUDE e o ID reservado é 255.

### <a name="to-create-a-resource"></a>Para criar um recurso

Você pode criar um novo recurso usando um dos seguintes:

- Na **exibição de recurso**, selecione o arquivo. RC, em seguida, usar **editar** > **adicionar recurso** e escolha o tipo de recurso a ser adicionado ao seu projeto.

   > [!TIP]
   > Você pode também com o botão direito no arquivo. rc no **exibição de recurso** e escolha **adicionar recurso** no menu de atalho.

- Na **Gerenciador de soluções**, clique na pasta do projeto, selecione **Add** > **adicionar recurso** e escolha o tipo de recurso a ser adicionado ao seu projeto.

   > [!NOTE]
   > Se você ainda não tiver um arquivo. rc em seu projeto, esta etapa criará um. Você pode, em seguida, repita essa etapa para adicionar tipos de recursos específicos para o novo arquivo. rc.

- Na [Class View](/visualstudio/ide/viewing-the-structure-of-code), a classe com o botão direito, selecione **Add** > **adicionar recurso** e escolha o tipo de recurso a ser adicionado ao seu projeto.

- No **Project** menu, selecione **adicionar recurso**.

### <a name="support-for-mfc"></a>Suporte para MFC

Normalmente, se você criar um aplicativo do Microsoft Foundation Class (MFC) para Windows usando o [Assistente de aplicativo MFC](../mfc/reference/mfc-application-wizard.md), o assistente gera um conjunto básico de arquivos (incluindo um arquivo de script (. rc) do recurso) que contém os principais recursos das MFC. No entanto, ao editar um arquivo. RC para um aplicativo do Windows que não se baseia no MFC, os seguintes recursos específicos do MFC não estão disponíveis: Assistentes de código do MFC, cadeias de caracteres prompt do menu, listam conteúdo para controles de caixa de combinação e hospedagem de controles ActiveX.

#### <a name="to-add-mfc-support-to-a-resource-script-file"></a>Para adicionar suporte MFC para um arquivo de script de recurso

1. Abra o arquivo de script de recurso.

1. Na **exibição de recurso**, realce a pasta de recursos (por exemplo, *RC*).

1. No [janela de propriedades](/visualstudio/ide/reference/properties-window), defina o **modo MFC** propriedade a ser **verdadeiro**.

   > [!NOTE]
   > Além de definir essa propriedade, o arquivo. rc deve fazer parte de um projeto MFC. Por exemplo, apenas configurando **modo MFC** à **verdadeiro** em um. rc arquivo em um projeto do Win32 não dará os recursos do MFC.

## <a name="resource-templates"></a>Modelos de recursos

Um modelo de recurso é um recurso personalizado que você salvou como um arquivo. rct. Um modelo de recursos, em seguida, serve como um ponto de partida para a criação de recursos. Modelos de recursos economizar tempo no desenvolvimento de outros recursos ou grupos de recursos que compartilham recursos, como controles padrão ou repetidas de elementos. Por exemplo, se você quiser incluir um botão de ajuda com um ícone do logotipo da empresa em várias caixas de diálogo, criar um novo modelo de caixa de diálogo e personalizá-lo com o botão de Ajuda e o logotipo.

Depois de personalizar o modelo de recursos, salvar suas alterações na pasta de modelo (ou o local especificado no caminho de inclusão) para que apareça em seu tipo de recurso no novo modelo de recurso do **adicionar recurso** caixa de diálogo. Agora você pode usar o novo modelo de recurso com a frequência conforme necessário.

> [!NOTE]
> O editor de recursos fornece automaticamente uma ID de recurso exclusivo. Você pode revisar os [propriedades do recurso](../windows/changing-the-properties-of-a-resource.md) conforme necessário.

> [!NOTE]
> Colocar arquivos de modelo de idioma específico em subdiretórios do diretório modelo principal. Por exemplo, coloque os arquivos de modelo apenas em inglês no... \\< diretório de modelo de recurso\>\1033. Visual Studio procura novos arquivos RCT no Visual Studio de \Program Files\Microsoft \<versão\>\VC\VCResourceTemplates, no Visual Studio de \Program Files\Microsoft \<versão > \VC\VCResourceTemplates\\< LCID\> (por exemplo, 1033 para inglês), *ou* em qualquer lugar a [caminho de inclusão](../windows/how-to-specify-include-directories-for-resources.md). Se você preferir armazenar seus arquivos RCT em outro local, por exemplo, Meus documentos, você precisará adicionar essa pasta ao caminho de inclusão para que o Visual Studio pode encontrar o arquivo RCT.

### <a name="to-create-a-resource-template"></a>Para criar um modelo de recurso

1. Na **Gerenciador de soluções**, clique em seu projeto.

1. No menu de atalho, selecione **Add** > **Adicionar Novo Item**.

1. No **modelos:** painel, selecione **arquivo de modelo de recursos (. rct)**.

1. Forneça um nome e local para o novo arquivo. rct e escolha **aberto**.

   O novo arquivo. rct é adicionado ao seu projeto e aparece na **Gerenciador de soluções** sob o **recursos** pasta.

1. Clique duas vezes no arquivo. rct para abri-lo em uma janela do documento. Para adicionar recursos, o arquivo na janela do documento com o botão direito e escolha **adicionar recurso**.

   Você pode personalizar esses recursos e salve o arquivo. rct.

### <a name="to-create-a-new-resource-from-a-template"></a>Para criar um novo recurso de um modelo

1. No **exibição de recurso** painel, clique com botão direito no arquivo. RC e escolha **adicionar recurso** no menu de atalho.

1. Selecione o sinal de adição (**+**) ao lado de um recurso para expandir o nó de recursos e exibir todos os modelos disponíveis para esse recurso.

1. Clique duas vezes o modelo que você deseja usar.

1. Modificar o recurso adicionado conforme necessário em seu editor de recursos.

### <a name="to-convert-an-existing-resource-file-to-a-template"></a>Para converter um arquivo de recurso existente em um modelo

1. Abra o arquivo. rc como um arquivo autônomo.

1. Sobre o **arquivo** menu, selecione **salve \< *filename*> como**.

1. Especifique um local e escolha **Okey**.

## <a name="requirements"></a>Requisitos

Win32

## <a name="see-also"></a>Consulte também

[Arquivos de recurso](../windows/resource-files-visual-studio.md)<br/>
[Gerenciar recursos](../windows/how-to-copy-resources.md)<br/>
[Incluir recursos em tempo de compilação](../windows/how-to-include-resources-at-compile-time.md)<br/>