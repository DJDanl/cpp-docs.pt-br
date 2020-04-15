---
title: Editor de cordas (C++)
ms.date: 02/14/2019
f1_keywords:
- vc.editors.string.F1
- vc.editors.string
helpviewer_keywords:
- String editor
- string tables
- string tables [C++], String editor
- string editing
- string editing, string tables
- resource editors [C++], String editor
- strings [C++], editing
- strings [C++], searching
- strings [C++]
- strings [C++], adding to string tables
- string tables [C++], deleting strings
- strings [C++], deleting in string tables
- string tables [C++], adding strings
- strings [C++], moving between files
- resource script files [C++], moving strings
- string editing, moving strings between resources
- String editor [C++], moving strings between files
- resource identifiers, string properties
- string tables [C++], changing strings
- strings [C++], properties
- String editor [C++], changing properties of multiple strings
- string tables [C++], changing caption of multiple strings
- special characters, adding to strings
- ASCII characters, adding to strings
- strings [C++], formatting
- strings [C++], special characters
ms.assetid: f71ab8de-3068-4e29-8e28-5a33d18dd416
ms.openlocfilehash: b0fb077752cf1912e07175c68cdc8acfe758b0c4
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81370235"
---
# <a name="string-editor-c"></a>Editor de cordas (C++)

Uma tabela de strings é um recurso do Windows que contém uma lista de IDs, valores e legendas para todas as strings do seu aplicativo. Por exemplo, as solicitações de barra de status estão localizadas na tabela de strings.

Ao desenvolver um aplicativo, você pode ter várias tabelas de strings - uma para cada idioma ou condição. No entanto, um módulo executável tem apenas uma tabela de strings. Um aplicativo em execução pode referenciar várias tabelas de strings se você colocar as tabelas em DLLs diferentes.

Tabelas de strings facilitam a localização do seu aplicativo em diferentes idiomas. Se todas as strings estiverem em uma tabela de strings, você pode localizar o aplicativo traduzindo as strings (e outros recursos) sem alterar o código-fonte. Esta situação é mais desejável do que encontrar e substituir manualmente várias strings em arquivos de origem.

> [!NOTE]
> O Windows não permite a criação de tabelas de strings vazias. Se você criar uma tabela de strings sem entradas, ela será excluída automaticamente quando você salvar o arquivo de recursos.

## <a name="how-to"></a>Instruções

O **Editor de strings** permite:

### <a name="to-find-a-string-resource-in-the-string-table"></a>Para encontrar um recurso de string na tabela de strings

1. Abra a tabela de strings clicando duas vezes em seu ícone na [Exibição de recursos](how-to-create-a-resource-script-file.md#create-resources).

1. Vá para o menu **Editar** > **Encontrar e Substituir** e escolher **Encontrar**.

1. Na caixa Encontrar o **quê,** selecione uma seqüência de pesquisa anterior na lista de desímpara das listas gotas ou digite o texto da legenda ou o identificador de recursos da string que deseja encontrar.

1. Selecione qualquer uma das opções **Encontrar** e selecione **Encontrar a seguir**.

> [!TIP]
> Para usar [expressões regulares](/visualstudio/ide/using-regular-expressions-in-visual-studio) ao pesquisar arquivos, use o comando **Encontrar em Arquivos** no menu **Editar.**
>
> Digite uma expressão regular para corresponder a um padrão ou selecione o botão à direita da caixa **Encontrar o que** é para exibir uma lista de expressões de pesquisa regulares. Quando você seleciona uma expressão desta lista, ela é substituída como o texto de pesquisa na caixa **Encontrar o que** é.
>
> Se você usar expressões regulares, certifique-se de que a caixa de seleção **Use: Regular Expressões** será selecionada.

### <a name="to-add-or-delete-a-string-resource"></a>Para adicionar ou excluir um recurso de string

Você pode inserir ou excluir rapidamente entradas na tabela de strings usando o **Editor de cordas**. Novas cordas são colocadas na extremidade da tabela e recebem o próximo identificador disponível. Você pode editar as propriedades **ID,** **Value**ou **Caption** na [janela Propriedades](/visualstudio/ide/reference/properties-window) conforme necessário.

O **Editor de Cordas** garante que você não use um ID que já está em uso. Se você selecionar um ID já em uso, o **Editor de strings** irá `IDS_STRING58113`notificá-lo e, em seguida, atribuir um ID genérico exclusivo, por exemplo .

#### <a name="to-add-a-string-table-entry"></a>Para adicionar uma entrada de tabela de strings

1. Abra a tabela de strings clicando duas vezes em seu ícone na [Exibição de recursos](how-to-create-a-resource-script-file.md#create-resources).

1. Clique com o botão direito do mouse dentro da tabela de strings e escolha **Nova string**.

1. No **Editor de cordas,** selecione um **ID** na lista de isto de **id** ou digite um *ID* diretamente no lugar.

1. Editar o **Valor,** se necessário.

1. Digite uma entrada para **a Legenda**.

   > [!NOTE]
   > As seqüências nulas não são permitidas nas tabelas de strings do Windows. Se você criar uma entrada na tabela de strings que é uma seqüência de caracteres nula, você receberá uma mensagem pedindo para **você, por favor, digite uma seqüência para esta entrada de tabela**.

#### <a name="to-delete-a-string-table-entry"></a>Para excluir uma entrada de tabela de strings

Selecione a entrada que deseja excluir e faça uma das seguintes:

- Ir para menu **Editar** > **excluir**.

- Clique com o botão direito do mouse na seqüência para excluir e escolher **Excluir**.

- Pressione a **tecla Excluir.**

### <a name="to-move-a-string-from-one-resource-script-file-to-another"></a>Para mover uma seqüência de um arquivo de script de recurso para outro

1. [Abra as tabelas de string em ambos os arquivos .rc](../windows/how-to-create-a-resource-script-file.md).

1. Clique com o botão direito do mouse na seqüência para mover e escolher **Cortar**.

1. Coloque o cursor na janela do **Editor de cordas** alvo.

1. No arquivo *.rc* para o qual você deseja mover a seqüência, clique com o botão direito do mouse e escolha **Colar**.

> [!NOTE]
> Se o **ID** ou **o Valor** da seqüência de string saqueado entrarem em conflito com um **ID** ou **valor** existente no arquivo de destino, esse **ID** ou o **Valor** da seqüência de strings mudou.

### <a name="to-change-the-properties-of-a-string-resource"></a>Para alterar as propriedades de um recurso de string

Você pode usar a edição no local para alterar as propriedades **ID,** **Value**e **Caption.**

> [!NOTE]
> Você também pode editar as propriedades de uma seqüência na [janela Propriedades](/visualstudio/ide/reference/properties-window).

#### <a name="to-change-a-string-or-its-identifier"></a>Para alterar uma seqüência ou seu identificador

1. Abra a tabela de strings clicando duas vezes em seu ícone na [Exibição de recursos](how-to-create-a-resource-script-file.md#create-resources).

1. Selecione a seqüência de string que deseja editar e clique duas vezes na coluna **ID,** **Value**ou **Caption,** e então você pode:

   - Selecione um **ID** na lista de isto de ida do **ID** ou digite um *ID* diretamente no lugar.

   - Digite um número diferente na coluna **Valor.**

   - Digite edições na coluna **Legenda.**

#### <a name="to-change-the-caption-property-of-multiple-string-resources"></a>Para alterar a propriedade de legenda de vários recursos de string

1. Abra a tabela de strings clicando duas vezes em seu ícone na [Exibição de recursos](how-to-create-a-resource-script-file.md#create-resources).

1. Selecione as strings que deseja alterar segurando a tecla **Ctrl** enquanto seleciona cada uma delas.

1. Na [janela Propriedades,](/visualstudio/ide/reference/properties-window)digite um novo valor para a propriedade que deseja alterar.

1. Pressione **Enter**.

### <a name="to-add-formatting-or-special-characters-to-a-string-resource"></a>Para adicionar formatação ou caracteres especiais a um recurso de string

1. Abra a tabela de strings clicando duas vezes em seu ícone na [Exibição de recursos](how-to-create-a-resource-script-file.md#create-resources).

1. Selecione a seqüência que deseja modificar.

1. Na [janela Propriedades](/visualstudio/ide/reference/properties-window), adicione qualquer uma das seqüências de escape padrão listadas abaixo ao texto na caixa **Legenda** e **pressione Enter**.

   |Para conseguir isso...|Digite isso...|
   |-----------------|---------------|
   | Nova linha | \\n |
   | Retorno de carro | \\R |
   | Tab | \\t |
   | Barra invertida (\\) | \\\\ |
   | Personagem ASCII | \\ddd (notação octal) |
   | Alerta (sino) | \\a |

   > [!NOTE]
   > O **Editor de cordas** não suporta o conjunto completo de caracteres ASCI fugitivos. Você só pode usar os listados acima.

## <a name="requirements"></a>Requisitos

Win32

## <a name="see-also"></a>Confira também

[Strings de editores](../windows/resource-editors.md)
de[recursos](/windows/win32/menurc/strings)<br/>
[Sobre Strings](/windows/win32/menurc/about-strings)<br/>
[Personalizando layouts de janela](/visualstudio/ide/customizing-window-layouts-in-visual-studio)
