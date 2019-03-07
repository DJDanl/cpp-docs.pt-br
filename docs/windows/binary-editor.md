---
title: Editor binário (C++)
ms.date: 02/14/2019
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
ms.openlocfilehash: df693e87bc9a370409eb43155d3f976a9f00cdac
ms.sourcegitcommit: b4645761ce5acf8c2fc7a662334dd5a471ea976d
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/07/2019
ms.locfileid: "57562855"
---
# <a name="binary-editor-c"></a>Editor binário (C++)

> [!CAUTION]
> Edição de recursos, como caixas de diálogo, imagens ou menus na **Editor binário** é perigoso. A edição incorreta pode corromper o recurso, tornando-a ilegível em seu editor nativo.

O **Editor binário** permite que você edite qualquer recurso no nível binário em formato hexadecimal ou ASCII. Você também pode usar o [comando Find](/visualstudio/ide/reference/find-command) para pesquisar cadeias de caracteres ASCII ou bytes hexadecimais. Use o **Editor binário** somente quando precisar exibir ou fazer pequenas alterações em recursos personalizados ou tipos de recursos não suportados pelo ambiente do Visual Studio. O **Editor binário** não está disponível nas edições Express.

- Para abrir o **Editor binário** em um novo arquivo, vá ao menu **arquivo** > **novo** > **arquivo**, selecione o tipo de arquivo que deseja editar e, em seguida, selecione a seta suspensa ao lado de **aberto** botão e escolha **abrir com** > **Editor binário**.

- Para abrir o **Editor binário** em um arquivo existente, vá ao menu **arquivo** > **abrir** > **arquivo**, selecione o arquivo que deseja editar e, em seguida, selecione a seta suspensa ao lado de **aberto** botão e escolha **abrir com** > **Editor binário**.

   ![Binary Editor](../mfc/media/vcbinaryeditor2.gif "vcBinaryEditor2")<br/>
   Dados binários para uma caixa de diálogo exibida no **Editor binário**

Apenas determinados valores ASCII são representados na **Editor binário** (0x20 por meio de 0x7E). Caracteres estendidos são exibidos como pontos na seção de valor ASCII do painel à direita do **Editor binário**. Os caracteres imprimíveis são valores ASCII 32 a 126.

> [!TIP]
> Ao usar o **Editor binário**, em muitos casos você pode clique com botão direito para exibir um menu de atalho de comandos específicos ao recurso. Os comandos disponíveis dependem do que o cursor está apontando. Por exemplo, se o botão direito do mouse enquanto estiver apontando para o **Editor binário** com valores hexadecimais selecionados, mostra o menu de atalho a **Recortar**, **cópia**e **Colar** comandos.

## <a name="how-to"></a>Como

O **Editor binário** permite que você:

### <a name="to-open-a-windows-desktop-resource-for-binary-editing"></a>Para abrir um recurso de área de trabalho do Windows para edição binária

1. Na [exibição de recurso](/windows/how-to-create-a-resource-script-file#create-resources), selecione o arquivo de recurso específico que você deseja editar.

1. O recurso com o botão direito e selecione **abrir dados binários**.

> [!NOTE]
> Se você usar o **exibição de recurso** janela para abrir um recurso com um formato que o Visual Studio não reconhece, como RCDATA ou um recurso personalizado, o recurso é aberto automaticamente na **Editor binário**.

### <a name="to-open-a-managed-resource-for-binary-editing"></a>Para abrir um recurso gerenciado para edição binária

1. Na **Gerenciador de soluções**, selecione o arquivo de recurso específico que você deseja editar.

1. O recurso com o botão direito e selecione **abrir com**.

1. No **abrir com** diálogo caixa, escolha **Editor binário**.

> [!NOTE]
> Você pode usar o [Editor de imagens](../windows/image-editor-for-icons.md) e o **Editor binário** para trabalhar com arquivos de recursos em projetos gerenciados. Todos os recursos gerenciados que você deseja editar devem ser recursos vinculados. Os editores de recursos do Visual Studio não oferecem suporte à edição de recursos inseridos.

### <a name="to-edit-a-resource"></a>Para editar um recurso

Se você quiser usar o **Editor binário** em um recurso já está sendo editado em outra janela do editor, feche a janela do editor primeiro.

1. Selecione o byte que você deseja editar.

   O **guia** chave move o foco entre hexadecimal e seções ASCII as **Editor binário**. Você pode usar o **Page Up** e **Page Down** chaves para mover por meio da tela de um recurso por vez.

1. Digite o novo valor.

   O valor é alterado imediatamente em hexadecimal e seções de ASCII e o foco muda para o próximo valor na linha.

> [!NOTE]
> O **Editor binário** aceita alterações automaticamente quando você fecha o editor.

### <a name="to-find-binary-data"></a>Para localizar dados binários

Você pode procurar cadeias de caracteres ASCII ou bytes hexadecimais. Por exemplo, para encontrar *Hello*, você pode pesquisar a cadeia de caracteres *Hello* ou seu valor hexadecimal, *48 65 6C 6 6F de C*.

1. Vá ao menu **edite** > [localizar](/visualstudio/ide/reference/find-command).

1. No **localizar** caixa, selecione uma cadeia de caracteres de pesquisa anterior na lista suspensa ou digite os dados que você deseja localizar.

1. Selecione qualquer uma da **encontrar** opções e escolha **Localizar próximo**.

### <a name="to-create-a-new-custom-or-data-resource"></a>Para criar um novo recurso personalizado ou dados

Você pode criar um novo recurso personalizado ou dados colocando o recurso em um arquivo separado, usando a sintaxe de arquivo de script (. rc) do recurso normal e, em seguida, incluindo o arquivo clicando com o seu projeto no **Gerenciador de soluções** e selecionando  **Inclui recurso**.

1. [Crie um arquivo. rc](../windows/how-to-create-a-resource-script-file.md) que contém o recurso personalizado ou dados.

   Você pode digitar os dados personalizados em um arquivo. rc como cadeias de caracteres entre aspas terminada em nulo, ou como números inteiros em formato decimal, hexadecimal ou octal.

1. Na **Gerenciador de soluções**, o arquivo. RC do seu projeto com o botão direito e selecione **recurso inclui**.

1. No **diretivas de tempo de compilação** , digite um `#include` instrução que fornece o nome do arquivo que contém o recurso personalizado, por exemplo:

    ```cpp
    #include mydata.rc
    ```

   Verifique se a sintaxe e a ortografia do que você digita estão corretos. O conteúdo a **diretivas de tempo de compilação** caixa são inseridos no arquivo de script de recurso exatamente como você os digita.

1. Selecione **Okey** para registrar as alterações.

Outra maneira de criar um recurso personalizado é importar um arquivo externo como o recurso personalizado, consulte [como: Gerenciar recursos](../windows/how-to-import-and-export-resources.md).

> [!NOTE]
> Criação de novos recursos personalizados ou de dados requer Win32.

## <a name="requirements"></a>Requisitos

Nenhum

## <a name="see-also"></a>Consulte também

[Editores de recursos](../windows/resource-editors.md)