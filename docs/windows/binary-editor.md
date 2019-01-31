---
title: Editor binário (C++)
ms.date: 11/04/2016
f1_keywords:
- vc.editors.binary.F1
- vc.editors.binary
helpviewer_keywords:
- editors, Binary
- resources [C++], editing
- resource editors [C++], Binary editor
- Binary editor
- binary data, editing
- resources [C++], opening for binary editing
- binary data
- hexadecimal bytes in binary data
- strings [C++], searching for
- file searches [C++]
- binary data, finding
- ASCII characters, finding in binary data
- custom resources [C++]
- data resources [C++]
- resources [C++], creating
ms.assetid: 2483c48b-1252-4dbc-826b-82e6c1a0e9cb
ms.openlocfilehash: 06c4a224b745f5aba8c9105d32489f8ca3109e1c
ms.sourcegitcommit: b488462a6e035131121e6f32d8f3b108cc798b5e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 01/30/2019
ms.locfileid: "55293592"
---
# <a name="binary-editor-c"></a>Editor binário (C++)

> [!WARNING]
> O **Editor binário** não está disponível nas edições Express.

Editor binário permite que você edite qualquer recurso no nível binário em formato hexadecimal ou ASCII. Você também pode usar o [comando Find](/visualstudio/ide/reference/find-command) para pesquisar cadeias de caracteres ASCII ou bytes hexadecimais. Você deve usar o **binário** editor somente quando precisar exibir ou fazer pequenas alterações em recursos personalizados ou tipos de recursos não suportados pelo ambiente do Visual Studio.

Para abrir o **Editor binário**, primeiro escolha **arquivo** > **novo** > **arquivo** no menu principal, selecione o arquivo que deseja editar e, em seguida, clique na seta suspensa ao lado de **aberto** botão e escolha **abrir com** > **Editor binário**.

> [!CAUTION]
> Edição de recursos, como caixas de diálogo, imagens ou menus no editor binário é perigoso. A edição incorreta pode corromper o recurso, tornando-a ilegível em seu editor nativo.

> [!TIP]
> Ao usar o **binário** editor, em muitos casos, pode clicar duas vezes para exibir um menu de atalho de comandos específicos ao recurso. Os comandos disponíveis dependem do que o cursor está apontando. Por exemplo, se você clicar em enquanto estiver apontando para o **binário** o menu de atalho do editor com valores hexadecimais selecionados, mostra as **Recortar**, **cópia**, e **colar**  comandos.

## <a name="binary-editor-how-to"></a>Instruções de Editor binário

Com o **binário** editor, consulte as seguintes ações:

### <a name="to-open-a-resource-for-binary-editing"></a>Para abrir um recurso para edição binária

#### <a name="to-open-a-windows-desktop-resource"></a>Para abrir um recurso de área de trabalho do Windows

1. Na [exibição de recurso](../windows/resource-view-window.md), selecione o arquivo de recurso específico que você deseja editar.

   > [!NOTE]
   > Se seu projeto já não contiver um arquivo. RC, consulte [criando um novo arquivo de Script de recurso](../windows/how-to-create-a-resource-script-file.md).

1. O recurso com o botão direito e clique em **abrir dados binários** no menu de atalho.

   > [!NOTE]
   > Se você usar o [exibição de recurso](../windows/resource-view-window.md) janela para abrir um recurso com um formato que o Visual Studio não reconhece (como RCDATA ou um recurso personalizado), o recurso é aberta automaticamente na **binário** editor.

#### <a name="to-open-a-managed-resource"></a>Para abrir um recurso gerenciado

1. Na **Gerenciador de soluções**, selecione o arquivo de recurso específico que você deseja editar.

1. O recurso de atalho e escolha **abrir com** no menu de atalho.

1. No **abrir com** diálogo caixa, escolha **Editor binário**.

   > [!NOTE]
   > Você pode usar o [editor de imagens](../windows/image-editor-for-icons.md) e o [editor binário](binary-editor.md) para trabalhar com arquivos de recursos em projetos gerenciados. Todos os recursos gerenciados que você deseja editar devem ser recursos vinculados. Os editores de recursos do Visual Studio não oferecem suporte à edição de recursos inseridos.

![Binary Editor](../mfc/media/vcbinaryeditor2.gif "vcBinaryEditor2")<br/>
Dados binários para uma caixa de diálogo exibida no Editor binário

Apenas determinados valores ASCII são representados no editor binário (0x20 por meio de 0x7E). Caracteres estendidos são exibidos como pontos na seção de valor ASCII do editor binário (painel direito). Os caracteres "imprimíveis" são valores ASCII 32 a 126.

> [!NOTE]
> Se você quiser usar o **binário** editor em um recurso já está sendo editado em outra janela do editor, feche a janela do editor primeiro.

### <a name="to-edit-a-resource-in-the-binary-editor"></a>Para editar um recurso no editor binário

1. Selecione o byte que você deseja editar.

   O **guia** chave move o foco entre hexadecimal e seções ASCII a **binário** editor. Você pode usar o **Page Up** e **Page Down** chaves para mover por meio da tela de um recurso por vez.

1. Digite o novo valor.

   O valor é alterado imediatamente em hexadecimal e seções de ASCII e o foco muda para o próximo valor na linha.

   > [!NOTE]
   > O **binário** editor aceita alterações automaticamente quando você fecha o editor.

### <a name="to-find-binary-data"></a>Para localizar dados binários

Você pode procurar cadeias de caracteres ASCII ou bytes hexadecimais. Por exemplo, para localizar o "Hello", você pode pesquisar a cadeia de caracteres "Hello" ou para "48 65 6C 6F de C 6" (o equivalente hexadecimal).

1. Dos **edite** menu, escolha [localizar](/visualstudio/ide/reference/find-command).

1. No **localizar** caixa, selecione uma cadeia de caracteres de pesquisa anterior na lista suspensa ou digite os dados que você deseja localizar.

1. Selecione qualquer uma da **localizar** opções.

1. Selecione **Localizar próximo**.

### <a name="to-create-a-new-custom-or-data-resource"></a>Para criar um novo recurso personalizado ou dados

Você pode criar um novo recurso personalizado ou dados colocando o recurso em um arquivo separado, usando a sintaxe de arquivo de script (. rc) do recurso normal e, em seguida, incluindo o arquivo clicando com o seu projeto no **Gerenciador de soluções** e clicando em  **Inclui recurso** no menu de atalho.

1. [Crie um arquivo. rc](../windows/how-to-create-a-resource-script-file.md) que contém o recurso personalizado ou dados.

   Você pode digitar os dados personalizados em um arquivo. rc como cadeias de caracteres entre aspas terminada em nulo, ou como números inteiros em formato decimal, hexadecimal ou octal.

1. Na **Gerenciador de soluções**, o arquivo. RC do seu projeto com o botão direito e clique em **recurso inclui** no menu de atalho.

1. No **diretivas de tempo de compilação** , digite um `#include` instrução que fornece o nome do arquivo que contém o recurso personalizado. Por exemplo:

    ```cpp
    #include mydata.rc
    ```

   Verifique se a sintaxe e a ortografia do que você digita estão corretos. O conteúdo a **diretivas de tempo de compilação** caixa são inseridos no arquivo de script de recurso exatamente como você digitou-los.

1. Selecione **Okey** para registrar as alterações.

É outra maneira de criar um recurso personalizado importar um arquivo externo como o recurso personalizado. Para obter mais informações, consulte [importando e exportando recursos](../windows/how-to-import-and-export-resources.md).

> [!NOTE]
> Criação de novos recursos personalizados ou de dados requer Win32.

## <a name="managed-resources"></a>Recursos gerenciados

Você pode usar o [editor de imagens](../windows/image-editor-for-icons.md) e o **binário** editor para trabalhar com arquivos de recursos em projetos de gerenciados. Todos os recursos gerenciados que você deseja editar devem ser recursos vinculados. Os editores de recursos do Visual Studio não oferecem suporte à edição de recursos inseridos.

Para obter informações sobre como adicionar recursos a projetos gerenciados, consulte [recursos em aplicativos de área de trabalho](/dotnet/framework/resources/index) na *guia do desenvolvedor do .NET Framework*. Para obter informações sobre como adicionar manualmente os arquivos de recursos a projetos gerenciados, acessar recursos, exibir recursos estáticos e atribuir cadeias de caracteres de recurso a propriedades, consulte [criando arquivos de recursos para aplicativos de área de trabalho](/dotnet/framework/resources/creating-resource-files-for-desktop-apps). Para obter informações sobre globalização e localização de recursos em aplicativos gerenciados, consulte [Globalizing e Localizando aplicativos do .NET Framework](/dotnet/standard/globalization-localization/index).

## <a name="requirements"></a>Requisitos

Nenhum

## <a name="see-also"></a>Consulte também

[Editores de recursos](../windows/resource-editors.md)