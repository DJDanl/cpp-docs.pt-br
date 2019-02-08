---
title: 'Como: Criar um arquivo de Script de recurso (C++)'
ms.date: 11/04/2016
f1_keywords:
- vc.editors.resource
- vc.resvw.add.MFC
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
ms.assetid: 82be732a-cdcd-4a58-8de7-976d1418f86b
ms.openlocfilehash: 9055e0f787c238276d3134c2fa6a8afae0102433
ms.sourcegitcommit: 5a7dbd640376e13379f5d5b2cf66c4842e5e737b
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 02/08/2019
ms.locfileid: "55905674"
---
# <a name="how-to-create-a-resource-script-file-c"></a>Como: Criar um arquivo de Script de recurso (C++)

> [!NOTE]
> O **Editor de recurso** não está disponível nas edições Express.
>
> Este material se aplica a aplicativos de área de trabalho do Windows. Projetos em linguagens .NET não usem arquivos de script de recurso. Para obter mais informações, consulte [arquivos de recurso](../windows/resource-files-visual-studio.md).

## <a name="to-create-a-new-resource-script-rc-file"></a>Para criar um novo arquivo de script (. rc) do recurso

1. Colocar o foco na sua pasta de projeto existente no **Gerenciador de soluções**, por exemplo, `MyProject`.

   > [!NOTE]
   > Não confunda a pasta do projeto com a pasta da solução no **Gerenciador de soluções**. Se você colocar o foco a **solução** pasta, suas escolhas no **Adicionar Novo Item** caixa de diálogo (na etapa 3) será diferente.

1. No menu **Projeto**, selecione **Adicionar Novo Item**.

1. No **Adicionar Novo Item** caixa de diálogo, selecione o **Visual C++** pasta, em seguida, escolha **arquivo de recurso (. rc)** no painel direito.

1. Forneça um nome para seu arquivo de script de recurso nas **nome** texto caixa e, em seguida, escolha **abrir**.

Agora você pode [criar](../windows/how-to-create-a-resource.md) e adicionar novos recursos ao seu arquivo. rc.

> [!NOTE]
> Você só pode adicionar um script de recurso (arquivo. rc) a um projeto existente que é carregado no IDE do Visual Studio. Você não pode criar um arquivo. rc autônomo (fora do projeto um). [Modelos de recursos](../windows/how-to-use-resource-templates.md) (arquivos. rct) podem ser criados a qualquer momento.

## <a name="to-open-a-resource-script-file-outside-of-a-c-project-standalone"></a>Para abrir um arquivo de script de recurso fora de um projeto do C++ (autônomo)

Você pode exibir recursos em um arquivo. rc sem a necessidade de abrir um projeto. O arquivo. RC será aberto em uma janela de documento em vez de abertura na [exibição de recurso](../windows/resource-view-window.md) janela (como quando o arquivo é aberto dentro de um projeto).

> [!NOTE]
> Isso é uma distinção importante porque alguns comandos estão disponíveis somente quando o arquivo é aberto autônomo (fora de um projeto). Por exemplo, você só pode salvar um arquivo em um formato diferente ou como um nome de arquivo diferentes quando o arquivo é aberto fora de um projeto (o **Salvar como** comando não está disponível quando um arquivo é aberto dentro de um projeto).

### <a name="to-open-an-rc-file-outside-a-project"></a>Para abrir um arquivo. rc fora de um projeto

1. Dos **arquivo** menu, escolha **abra**, em seguida, selecione **arquivo**.

1. No **abrir arquivo** diálogo caixa, navegue até o arquivo de script de recurso que você deseja exibir, realce o arquivo e selecione **abrir**.

   > [!NOTE]
   > Se você abrir o projeto pela primeira vez (**arquivo**, **abra**, **projeto**), alguns comandos não estarão disponíveis para você. Abrir um arquivo "autônomo" significa abri-lo sem primeiro carregar o projeto.

### <a name="to-open-multiple-rc-files-outside-a-project"></a>Para abrir vários arquivos. rc fora de um projeto

1. Abra ambos os arquivos de recurso autônomos. Por exemplo, abra `Source1.rc` e `Source2.rc`.

   1. Dos **arquivo** menu, escolha **abra**, em seguida, selecione **arquivo**.

   1. No **abrir arquivo** diálogo caixa, navegue até o primeiro arquivo de script de recurso que deseja abrir (`Source1.rc`), realce o arquivo e escolha **abrir**.

   1. Repita a etapa anterior para abrir o segundo arquivo. RC (`Source2.rc`).

       Os arquivos. rc agora estão abertos em janelas de documentos separada.

1. Quando ambos os arquivos. rc estão abertos, lado a lado as janelas para que você pode exibir simultaneamente:

   - Dos **janela** menu, escolha **novo grupo de guias horizontais** ou **novo grupo de guias verticais**.

       \- ou -

   - Clique em um dos arquivos. RC e escolha **novo grupo de guias horizontais** ou **novo grupo de guias verticais** no menu de atalho.

> [!NOTE]
> Se seu projeto já não contiver um arquivo. RC, consulte [criando um novo arquivo de Script de recurso](../windows/how-to-create-a-resource-script-file.md).

## <a name="to-open-a-resource-script-file-in-text-format"></a>Para abrir um arquivo de script de recurso no formato de texto

Pode haver ocasiões quando desejar exibir o conteúdo do arquivo de script (. rc) do recurso do seu projeto sem abrir um recurso, como uma caixa de diálogo dentro do seu editor de recurso específico. Por exemplo, você talvez queira procurar uma cadeia de caracteres em todas as caixas de diálogo no arquivo de recurso sem precisar abrir cada um deles separadamente.

> [!NOTE]
> Se seu projeto já não contiver um arquivo. RC, consulte [criando um novo arquivo de Script de recurso](../windows/how-to-create-a-resource-script-file.md).

Você pode facilmente abrir o arquivo de recurso no formato de texto para exibir todos os recursos que ele contém e concluir operações globais com suporte pelo editor de texto.

> [!NOTE]
> Os editores de recursos não ler diretamente. rc ou `resource.h` arquivos. O compilador de recurso compila-os em arquivos de .aps, que são consumidos pelos editores de recursos. Esse arquivo é uma etapa de compilação e armazena apenas dados simbólicos. Como com um normal de processo de compilação, as informações que não seja simbólicas (por exemplo, comentários) são descartadas durante o processo de compilação. Sempre que o arquivo .aps obtém fora de sincronia com o arquivo. RC, o arquivo. rc for gerado novamente (por exemplo, quando você salva, o editor de recurso substitui o arquivo. RC e o arquivo Resource h). Todas as alterações para os próprios recursos permanecerão incorporadas no arquivo. RC, mas comentários sempre serão perdidos depois que o arquivo. RC é substituído. Para obter informações sobre como preservar comentários, consulte [incluindo recursos em tempo de compilação](../windows/how-to-include-resources-at-compile-time.md).

### <a name="to-open-a-resource-script-file-as-text"></a>Para abrir um arquivo de script de recurso como texto

1. Do **arquivo** menu escolher **aberto**, em seguida, escolha **arquivo**.

1. No **abrir arquivo** caixa de diálogo, navegue até o arquivo de script de recurso que você deseja exibir no formato de texto.

1. Realce o arquivo e, em seguida, selecione a seta suspensa na **abrir** botão (localizado à direita do botão).

1. Escolher **abrir com** no menu suspenso.

1. No **abrir com** caixa de diálogo, selecione **Editor de código-fonte (texto)**.

1. Dos **abrir como** lista suspensa, selecione **texto**.

   O recurso é aberto na **código-fonte** editor.

\- ou -

1. Na **Gerenciador de soluções**, clique com botão direito no arquivo. rc.

1. No menu de atalho, escolha **abrir com...** , em seguida, selecione **Editor de código-fonte (texto)**.

## <a name="to-add-mfc-support-to-resource-script-files"></a>Para adicionar suporte MFC aos arquivos de script de recurso

Normalmente, quando você cria um aplicativo MFC para Windows usando o [Assistente de aplicativo MFC](../mfc/reference/mfc-application-wizard.md), o assistente gera um conjunto básico de arquivos (incluindo um arquivo de script (. rc) do recurso) que contém os principais recursos do Microsoft Foundation classes (MFC). No entanto, se você estiver editando um arquivo. RC para um aplicativo do Windows que não é baseado no MFC, os seguintes recursos específicos da estrutura MFC não estão disponíveis:

- Assistentes de código do MFC

- Cadeias de caracteres de prompt do menu

- Listar o conteúdo para controles de caixa de combinação

- Hospedagem de controles ActiveX

No entanto, você pode adicionar suporte MFC aos arquivos. rc existentes que não o tiver.

> [!NOTE]
> Estas etapas exigem o MFC.

### <a name="to-add-mfc-support-to-rc-files"></a>Para adicionar suporte MFC aos arquivos. rc

1. Abra o arquivo de script de recurso.

1. Na [exibição de recurso](../windows/resource-view-window.md), realce a pasta de recursos (por exemplo, RC).

1. No [janela de propriedades](/visualstudio/ide/reference/properties-window), defina o **modo MFC** propriedade a ser **verdadeiro**.

   > [!NOTE]
   > Além de definir esse sinalizador, o arquivo. rc deve fazer parte de um projeto MFC. Por exemplo, apenas configurando **modo MFC** à **verdadeiro** em um arquivo. rc em Win32 project não dará os recursos do MFC.

## <a name="requirements"></a>Requisitos

Win32

## <a name="see-also"></a>Consulte também

[Arquivos de recurso](../windows/resource-files-visual-studio.md)<br/>
[Editores de recursos](../windows/resource-editors.md)