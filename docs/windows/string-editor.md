---
title: Editor de cadeia de caracteres (C++)
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
ms.openlocfilehash: 47d5835356863383b32baffc4475e01a652e9856
ms.sourcegitcommit: 72583d30170d6ef29ea5c6848dc00169f2c909aa
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/18/2019
ms.locfileid: "59037179"
---
# <a name="string-editor-c"></a>Editor de cadeia de caracteres (C++)

Uma tabela de cadeia de caracteres é um recurso do Windows que contém uma lista de IDs, valores e as legendas para todas as cadeias de caracteres do seu aplicativo. Por exemplo, os prompts de barra de status estão localizados na tabela de cadeia de caracteres.

Ao desenvolver um aplicativo, você pode ter várias tabelas de cadeia de caracteres — uma para cada idioma ou a condição. No entanto, um módulo executável tem apenas uma tabela de cadeia de caracteres. Um aplicativo em execução pode fazer referência a várias tabelas de cadeia de caracteres se você colocar as tabelas em DLLs diferentes.

Tabelas de cadeia de caracteres tornam fácil localizar seu aplicativo em diferentes idiomas. Se todas as cadeias de caracteres estão em uma tabela de cadeia de caracteres, você pode localizar o aplicativo, convertendo as cadeias de caracteres (e outros recursos) sem alterar o código-fonte. Essa situação é mais desejável do que manualmente Localizando e substituindo várias cadeias de caracteres em arquivos de origem.

> [!NOTE]
> Windows não permitem a criação de tabelas de cadeia de caracteres vazia. Se você criar uma tabela de cadeia de caracteres sem entradas, ele é excluído automaticamente quando você salvar o arquivo de recurso.

## <a name="how-to"></a>Como

O **Editor de cadeia de caracteres** permite que você:

### <a name="to-find-a-string-resource-in-the-string-table"></a>Para localizar um recurso de cadeia de caracteres na tabela de cadeia de caracteres

1. Abra a tabela de cadeia de caracteres clicando duas vezes em seu ícone no [exibição de recurso](how-to-create-a-resource-script-file.md#create-resources).

1. Vá ao menu **edite** > **localizar e substituir** e escolha **localizar**.

1. No **localizar** caixa, selecione uma cadeia de caracteres de pesquisa anterior na lista suspensa ou digite o identificador de texto ou recurso de legenda da cadeia de caracteres que você deseja localizar.

1. Selecione qualquer uma da **encontrar** opções e selecione **Localizar próximo**.

> [!TIP]
> Para usar [expressões regulares](/visualstudio/ide/using-regular-expressions-in-visual-studio) ao pesquisar arquivos, use o **localizar nos arquivos** comando os **editar** menu.
>
> Digite uma expressão regular para corresponder a um padrão ou selecione o botão à direita do **localizar** caixa para exibir uma lista de expressões regulares de pesquisa. Quando você seleciona uma expressão dessa lista, ele será substituído como o texto de pesquisa na **localizar** caixa.
>
> Se você usar expressões regulares, certifique-se a **usar: Expressões regulares** caixa de seleção está selecionada.

### <a name="to-add-or-delete-a-string-resource"></a>Para adicionar ou excluir um recurso de cadeia de caracteres

Rapidamente, você pode inserir ou excluir as entradas para a tabela de cadeia de caracteres usando o **Editor de cadeia de caracteres**. Novas cadeias de caracteres são colocadas no final da tabela e recebem o próximo identificador disponível. Você pode editar a **identificação**, **valor**, ou **legenda** propriedades no [janela propriedades](/visualstudio/ide/reference/properties-window) conforme necessário.

O **Editor de cadeia de caracteres** torna-se de que você não use uma ID que já está em uso. Se você selecionar uma ID já em uso, o **Editor de cadeia de caracteres** irá notificá-lo e, em seguida, atribuir uma ID exclusiva genérica, por exemplo `IDS_STRING58113`.

#### <a name="to-add-a-string-table-entry"></a>Para adicionar uma entrada de tabela de cadeia de caracteres

1. Abra a tabela de cadeia de caracteres clicando duas vezes em seu ícone no [exibição de recurso](how-to-create-a-resource-script-file.md#create-resources).

1. Clique dentro da tabela de cadeia de caracteres e escolha **nova cadeia de caracteres**.

1. No **Editor de cadeia de caracteres**, selecione um **ID** do **ID** lista suspensa ou digite uma *ID* diretamente no local.

1. Editar o **valor**, se necessário.

1. Digite uma entrada para o **legenda**.

   > [!NOTE]
   > Cadeias de caracteres nulas não são permitidas em tabelas de cadeia de caracteres do Windows. Se você criar uma entrada na tabela de cadeia de caracteres que é uma cadeia de caracteres nula, você receberá uma mensagem solicitando que você **insira uma cadeia de caracteres para esta entrada de tabela**.

#### <a name="to-delete-a-string-table-entry"></a>Para excluir uma entrada de tabela de cadeia de caracteres

Selecione a entrada que você deseja excluir e siga um destes procedimentos:

- Vá ao menu **edite** > **excluir**.

- Com a cadeia de caracteres para excluir e escolha o botão direito **excluir**.

- Pressione a **excluir** chave.

### <a name="to-move-a-string-from-one-resource-script-file-to-another"></a>Para mover uma cadeia de caracteres do arquivo de script de um recurso para outro

1. [Abra as tabelas de cadeia de caracteres em ambos os arquivos. rc](../windows/how-to-create-a-resource-script-file.md).

1. Com a cadeia de caracteres para mover e escolha o botão direito **Recortar**.

1. Coloque o cursor no destino **Editor de cadeia de caracteres** janela.

1. No *. rc* arquivo ao qual você deseja mover a cadeia de caracteres, com o botão direito e escolha **colar**.

> [!NOTE]
> Se o **ID** ou **valor** dos conflitos com um cadeia de caracteres movidos **ID** ou **valor** no arquivo de destino, qualquer que **Identificação** ou o **valor** das alterações de cadeia de caracteres movidos.

### <a name="to-change-the-properties-of-a-string-resource"></a>Para alterar as propriedades de um recurso de cadeia de caracteres

Você pode usar a edição in-loco para alterar o **identificação**, **valor**, e **legenda** propriedades.

> [!NOTE]
>  Você também pode editar as propriedades da cadeia de caracteres na [janela de propriedades](/visualstudio/ide/reference/properties-window).

#### <a name="to-change-a-string-or-its-identifier"></a>Para alterar uma cadeia de caracteres ou seu identificador

1. Abra a tabela de cadeia de caracteres clicando duas vezes em seu ícone no [exibição de recurso](how-to-create-a-resource-script-file.md#create-resources).

1. Selecione a cadeia de caracteres que você deseja editar e clique duas vezes o **identificação**, **valor**, ou **legenda** coluna, em seguida, você pode:

   - Selecione uma **ID** da **ID** lista suspensa ou digite um *ID* diretamente no local.

   - Digite um número diferente na **valor** coluna.

   - Digite as edições na **legenda** coluna.

#### <a name="to-change-the-caption-property-of-multiple-string-resources"></a>Para alterar a propriedade caption de vários recursos de cadeia de caracteres

1. Abra a tabela de cadeia de caracteres clicando duas vezes em seu ícone no [exibição de recurso](how-to-create-a-resource-script-file.md#create-resources).

1. Selecione as cadeias de caracteres que você deseja alterar, mantendo pressionada a **Ctrl** da chave conforme você seleciona cada uma delas.

1. No [janela de propriedades](/visualstudio/ide/reference/properties-window), digite um novo valor para a propriedade que você deseja alterar.

1. Pressione **ENTER**.

### <a name="to-add-formatting-or-special-characters-to-a-string-resource"></a>Para adicionar formatação ou caracteres especiais a um recurso de cadeia de caracteres

1. Abra a tabela de cadeia de caracteres clicando duas vezes em seu ícone no [exibição de recurso](how-to-create-a-resource-script-file.md#create-resources).

1. Selecione a cadeia de caracteres que você deseja modificar.

1. No [janela de propriedades](/visualstudio/ide/reference/properties-window), adicione qualquer uma das sequências de escape padrão listados abaixo para o texto na **legenda** caixa e pressione **Enter**.

   |Para obter isso...|Digite isto...|
   |-----------------|---------------|
   | Nova linha | \\n |
   | Retorno de carro | \\r |
   | Tabulação | \\t |
   | Barra invertida (\\) | \\\\ |
   | Caractere ASCII | \\DDD (notação octal) |
   | alerta (sino) | \\a |

   > [!NOTE]
   > O **Editor de cadeia de caracteres** não dá suporte a todo o conjunto de caracteres de escape ASCI. Você pode usar apenas aqueles listados acima.

## <a name="requirements"></a>Requisitos

Win32

## <a name="see-also"></a>Consulte também

[Editores de recursos](../windows/resource-editors.md)
<!--
[Strings](https://msdn.microsoft.com/library/windows/desktop/ms646979.aspx)<br/>
[About Strings](/windows/desktop/menurc/about-strings)<br/>
[Customizing window layouts](/visualstudio/ide/customizing-window-layouts-in-visual-studio)-->