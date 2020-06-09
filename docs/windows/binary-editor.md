---
title: Editor de binários (C++)
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
ms.openlocfilehash: 955cce012ac30c3413d7d458e263643d0aefa711
ms.sourcegitcommit: c21b05042debc97d14875e019ee9d698691ffc0b
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 06/09/2020
ms.locfileid: "84615345"
---
# <a name="binary-editor-c"></a>Editor de binários (C++)

> [!CAUTION]
> A edição de recursos como caixas de diálogo, imagens ou menus no **Editor binário** é perigosa. A edição incorreta pode corromper o recurso, tornando-o ilegível em seu editor nativo.

O **Editor binário** permite que você edite qualquer recurso no nível binário no formato HEXADECIMAL ou ASCII. Você também pode usar o [comando find](/visualstudio/ide/reference/find-command) para pesquisar cadeias de caracteres ASCII ou bytes hexadecimais. Use o **Editor binário** somente quando precisar exibir ou fazer alterações secundárias em recursos personalizados ou tipos de recursos sem suporte no ambiente do Visual Studio. O **Editor binário** não está disponível nas Express Editions.

- Para abrir o **Editor binário** em um novo arquivo, vá para menu **arquivo**  >  **novo**  >  **arquivo**, selecione o tipo de arquivo que você deseja editar e, em seguida, selecione a seta para soltar ao lado do botão **abrir** e escolha **abrir com**o  >  **Editor binário**.

- Para abrir o **Editor de binários** em um arquivo existente, vá para menu **arquivo**  >  **abrir**  >  **arquivo**, selecione o arquivo que você deseja editar e, em seguida, selecione a seta para soltar ao lado do botão **abrir** e escolha **abrir com**o  >  **Editor binário**.

   ![Editor de binários](../mfc/media/vcbinaryeditor2.gif "vcBinaryEditor2")<br/>
   Dados binários de uma caixa de diálogo exibida no **Editor de binários**

Somente determinados valores ASCII são representados no **Editor binário** (0X20 a 0x7E). Os caracteres estendidos são exibidos como períodos na seção valor ASCII do painel direito do **Editor binário**. Os caracteres imprimíveis são valores ASCII de 32 a 126.

> [!TIP]
> Ao usar o **Editor binário**, em muitas instâncias, você pode clicar com o botão direito do mouse para exibir um menu de atalho de comandos específicos do recurso. Os comandos disponíveis dependem do que o cursor está apontando. Por exemplo, se você clicar com o botão direito do mouse enquanto aponta para o **Editor binário** com valores hexadecimais selecionados, o menu de atalho mostrará os comandos **recortar**, **copiar**e **colar** .

## <a name="how-to"></a>Instruções

O **Editor binário** permite:

### <a name="to-open-a-windows-desktop-resource-for-binary-editing"></a>Para abrir um recurso de área de trabalho do Windows para edição binária

1. Em [modo de exibição de recursos](how-to-create-a-resource-script-file.md#create-resources), selecione o arquivo de recurso específico que você deseja editar.

1. Clique com o botão direito do mouse no recurso e selecione **Abrir dados binários**.

> [!NOTE]
> Se você usar a janela **modo de exibição de recursos** para abrir um recurso com um formato que o Visual Studio não reconhece, como RCDATA ou um recurso personalizado, o recurso será aberto automaticamente no **Editor binário**.

### <a name="to-open-a-managed-resource-for-binary-editing"></a>Para abrir um recurso gerenciado para edição binária

1. Em **Gerenciador de soluções**, selecione o arquivo de recurso específico que você deseja editar.

1. Clique com o botão direito do mouse no recurso e selecione **abrir com**.

1. Na caixa de diálogo **abrir com** , escolha **Editor de binários**.

> [!NOTE]
> Você pode usar o [Editor de imagem](image-editor-for-icons.md) e o **Editor binário** para trabalhar com arquivos de recursos em projetos gerenciados. Todos os recursos gerenciados que você deseja editar devem ser recursos vinculados. Os editores de recursos do Visual Studio não oferecem suporte à edição de recursos inseridos.

### <a name="to-edit-a-resource"></a>Para editar um recurso

Se você quiser usar o **Editor binário** em um recurso já sendo editado em outra janela do editor, feche a outra janela do editor primeiro.

1. Selecione o byte que você deseja editar.

   A tecla **Tab** move o foco entre as seções HEXADECIMAL e ASCII do **Editor binário**. Você pode usar as teclas **Page Up** e **Page Down** para percorrer o recurso uma tela por vez.

1. Digite o novo valor.

   O valor é alterado imediatamente nas seções hexadecimal e ASCII e os deslocamentos de foco para o próximo valor na linha.

> [!NOTE]
> O **Editor binário** aceita alterações automaticamente quando você fecha o editor.

### <a name="to-find-binary-data"></a>Para localizar dados binários

Você pode pesquisar por cadeias de caracteres ASCII ou bytes hexadecimais. Por exemplo, para localizar *Olá*, você pode pesquisar a cadeia de caracteres *Hello* ou seu valor hexadecimal, *48 65 6C 6C 6F*.

1. Vá para o menu **Editar**  >  [Localizar](/visualstudio/ide/reference/find-command).

1. Na caixa **Localizar** , selecione uma cadeia de caracteres de pesquisa anterior na lista suspensa ou digite os dados que você deseja localizar.

1. Selecione qualquer uma das opções de **localização** e escolha **Localizar próximo**.

### <a name="to-create-a-new-custom-or-data-resource"></a>Para criar um novo recurso personalizado ou de dados

Você pode criar um novo recurso personalizado ou de dados colocando o recurso em um arquivo separado usando a sintaxe de arquivo de script de recurso normal (. rc) e, em seguida, incluindo esse arquivo clicando com o botão direito do mouse em seu projeto no **Gerenciador de soluções** e selecionando o **recurso inclui**.

1. [Crie um arquivo. rc](how-to-create-a-resource-script-file.md) que contenha o recurso personalizado ou de dados.

   Você pode digitar dados personalizados em um arquivo. rc como cadeias de caracteres entre aspas terminadas em nulo ou como números inteiros em formato decimal, hexadecimal ou octal.

1. Em **Gerenciador de soluções**, clique com o botão direito do mouse no arquivo. rc do projeto e selecione o **recurso inclui**.

1. Na caixa **diretivas de tempo de compilação** , digite uma `#include` instrução que forneça o nome do arquivo que contém o recurso personalizado, por exemplo:

    ```cpp
    #include mydata.rc
    ```

   Verifique se a sintaxe e a ortografia do que você digitou estão corretas. O conteúdo da caixa de **diretivas de tempo de compilação** é inserido no arquivo de script de recurso exatamente como você os digita.

1. Selecione **OK** para registrar suas alterações.

Outra maneira de criar um recurso personalizado é importar um arquivo externo como o recurso personalizado, consulte [como: gerenciar recursos](../windows/how-to-import-and-export-resources.md).

> [!NOTE]
> A criação de novos recursos de dados ou personalizados requer Win32.

## <a name="requirements"></a>Requisitos

Nenhum

## <a name="see-also"></a>Consulte também

[Editores de recursos](resource-editors.md)
