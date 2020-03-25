---
title: Editor de cadeiaC++de caracteres ()
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
ms.openlocfilehash: 1f9b21893bd361d02b3446360b24a97f4d1d1365
ms.sourcegitcommit: 857fa6b530224fa6c18675138043aba9aa0619fb
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/24/2020
ms.locfileid: "80214403"
---
# <a name="string-editor-c"></a>Editor de cadeiaC++de caracteres ()

Uma tabela de cadeia de caracteres é um recurso do Windows que contém uma lista de IDs, valores e legendas para todas as cadeias de caracteres do seu aplicativo. Por exemplo, os prompts da barra de status estão localizados na tabela de cadeia de caracteres.

Ao desenvolver um aplicativo, você pode ter várias tabelas de cadeia de caracteres — uma para cada idioma ou condição. No entanto, um módulo executável tem apenas uma tabela de cadeia de caracteres. Um aplicativo em execução pode fazer referência a várias tabelas de cadeias de caracteres se você colocar as tabelas em DLLs diferentes.

As tabelas de cadeia de caracteres facilitam a localização do aplicativo em diferentes idiomas. Se todas as cadeias de caracteres estiverem em uma tabela de cadeia, você poderá localizar o aplicativo traduzindo as cadeias de caracteres (e outros recursos) sem alterar o código-fonte. Essa situação é mais desejável do que localizar e substituir manualmente várias cadeias de caracteres em arquivos de origem.

> [!NOTE]
> O Windows não permite a criação de tabelas de cadeia de caracteres vazias. Se você criar uma tabela de cadeia de caracteres sem entradas, ela será excluída automaticamente quando você salvar o arquivo de recurso.

## <a name="how-to"></a>Instruções

O **Editor de cadeia de caracteres** permite:

### <a name="to-find-a-string-resource-in-the-string-table"></a>Para localizar um recurso de cadeia de caracteres na tabela de cadeias de caracteres

1. Abra a tabela de cadeia de caracteres clicando duas vezes em seu ícone no [modo de exibição de recursos](how-to-create-a-resource-script-file.md#create-resources).

1. Vá para o menu **editar** > **Localizar e substituir** e escolha **Localizar**.

1. Na caixa **Localizar** , selecione uma cadeia de caracteres de pesquisa anterior na lista suspensa ou digite o texto da legenda ou o identificador de recurso da cadeia de caracteres que você deseja localizar.

1. Selecione qualquer uma das opções de **localização** e selecione **Localizar próximo**.

> [!TIP]
> Para usar [expressões regulares](/visualstudio/ide/using-regular-expressions-in-visual-studio) ao pesquisar arquivos, use o comando **localizar nos arquivos** no menu **Editar** .
>
> Digite uma expressão regular para corresponder a um padrão ou selecione o botão à direita da caixa **Localizar** para exibir uma lista de expressões de pesquisa regulares. Quando você seleciona uma expressão nessa lista, ela é substituída como o texto de pesquisa na caixa **Localizar** .
>
> Se você usar expressões regulares, certifique-se de que a caixa de seleção **usar: expressões regulares** esteja marcada.

### <a name="to-add-or-delete-a-string-resource"></a>Para adicionar ou excluir um recurso de cadeia de caracteres

Você pode inserir ou excluir entradas rapidamente na tabela de cadeia de caracteres usando o **Editor de cadeia de caracteres**. Novas cadeias de caracteres são colocadas no final da tabela e recebem o próximo identificador disponível. Você pode editar as propriedades de **ID**, **valor**ou **legenda** no [janela Propriedades](/visualstudio/ide/reference/properties-window) conforme necessário.

O **Editor de cadeia de caracteres** garante que você não use uma ID que já esteja em uso. Se você selecionar uma ID que já está em uso, o **Editor de cadeia de caracteres** o notificará e atribuirá uma ID exclusiva genérica, por exemplo `IDS_STRING58113`.

#### <a name="to-add-a-string-table-entry"></a>Para adicionar uma entrada de tabela de cadeia de caracteres

1. Abra a tabela de cadeia de caracteres clicando duas vezes em seu ícone no [modo de exibição de recursos](how-to-create-a-resource-script-file.md#create-resources).

1. Clique com o botão direito do mouse na tabela de cadeia de caracteres e escolha **nova cadeia de caracteres**.

1. No **Editor de cadeia de caracteres**, selecione uma **ID** na lista suspensa **ID** ou digite uma *ID* diretamente no local.

1. Edite o **valor**, se necessário.

1. Digite uma entrada para a **legenda**.

   > [!NOTE]
   > Cadeias de caracteres nulas não são permitidas em tabelas de cadeias do Windows Se você criar uma entrada na tabela de cadeia de caracteres que é uma cadeia de caracteres nula, receberá uma mensagem solicitando que **Insira uma cadeia de caracteres para essa entrada de tabela**.

#### <a name="to-delete-a-string-table-entry"></a>Para excluir uma entrada de tabela de cadeia de caracteres

Selecione a entrada que você deseja excluir e siga um destes procedimentos:

- Vá para o menu **editar** > **excluir**.

- Clique com o botão direito do mouse na cadeia de caracteres a ser excluída e escolha **excluir**.

- Pressione a tecla **delete** .

### <a name="to-move-a-string-from-one-resource-script-file-to-another"></a>Para mover uma cadeia de caracteres de um arquivo de script de recurso para outro

1. [Abra as tabelas de cadeia de caracteres em ambos os arquivos. rc](../windows/how-to-create-a-resource-script-file.md).

1. Clique com o botão direito do mouse na cadeia de caracteres para mover e escolha **recortar**.

1. Coloque o cursor na janela do **Editor de cadeia de caracteres** de destino.

1. No arquivo *. rc* para o qual você deseja mover a cadeia de caracteres, clique com o botão direito do mouse e escolha **colar**.

> [!NOTE]
> Se a **ID** ou o **valor** da cadeia de caracteres movida estiver em conflito com uma **ID** ou **valor** existente no arquivo de destino, essa **ID** ou o **valor** da cadeia de caracteres movida será alterado.

### <a name="to-change-the-properties-of-a-string-resource"></a>Para alterar as propriedades de um recurso de cadeia de caracteres

Você pode usar a edição in-loco para alterar as propriedades de **ID**, **valor**e **legenda** .

> [!NOTE]
>  Você também pode editar as propriedades de uma cadeia de caracteres na [janela Propriedades](/visualstudio/ide/reference/properties-window).

#### <a name="to-change-a-string-or-its-identifier"></a>Para alterar uma cadeia de caracteres ou seu identificador

1. Abra a tabela de cadeia de caracteres clicando duas vezes em seu ícone no [modo de exibição de recursos](how-to-create-a-resource-script-file.md#create-resources).

1. Selecione a cadeia de caracteres que você deseja editar e clique duas vezes na coluna **ID**, **valor**ou **legenda** e, em seguida, você pode:

   - Selecione uma **ID** na lista suspensa **ID** ou digite uma *ID* diretamente no local.

   - Digite um número diferente na coluna **valor** .

   - Digite edições na coluna **legenda** .

#### <a name="to-change-the-caption-property-of-multiple-string-resources"></a>Para alterar a propriedade Caption de vários recursos de cadeia de caracteres

1. Abra a tabela de cadeia de caracteres clicando duas vezes em seu ícone no [modo de exibição de recursos](how-to-create-a-resource-script-file.md#create-resources).

1. Selecione as cadeias de caracteres que você deseja alterar mantendo a tecla **Ctrl** pressionada ao selecionar cada uma delas.

1. Na [janela Propriedades](/visualstudio/ide/reference/properties-window), digite um novo valor para a propriedade que você deseja alterar.

1. Pressione **Enter**.

### <a name="to-add-formatting-or-special-characters-to-a-string-resource"></a>Para adicionar formatação ou caracteres especiais a um recurso de cadeia de caracteres

1. Abra a tabela de cadeia de caracteres clicando duas vezes em seu ícone no [modo de exibição de recursos](how-to-create-a-resource-script-file.md#create-resources).

1. Selecione a cadeia de caracteres que você deseja modificar.

1. Na [janela Propriedades](/visualstudio/ide/reference/properties-window), adicione qualquer uma das sequências de escape padrão listadas abaixo ao texto na caixa **legenda** e pressione **Enter**.

   |Para obter isso...|Digite isto...|
   |-----------------|---------------|
   | Nova linha | \\n |
   | Retorno de carro | \\r |
   | Tab | \\t |
   | Barra invertida (\\) | \\\\ |
   | Caractere ASCII | \\DDD (notação octal) |
   | Alerta (Bell) | \\a |

   > [!NOTE]
   > O **Editor de cadeia de caracteres** não dá suporte ao conjunto completo de caracteres asci de escape. Você só pode usar os listados acima.

## <a name="requirements"></a>Requisitos

Win32

## <a name="see-also"></a>Confira também

[Editores de recursos](../windows/resource-editors.md)
[cadeias de caracteres](/windows/win32/menurc/strings)<br/>
[Sobre cadeias de caracteres](/windows/win32/menurc/about-strings)<br/>
[Personalizando layouts de janela](/visualstudio/ide/customizing-window-layouts-in-visual-studio)
