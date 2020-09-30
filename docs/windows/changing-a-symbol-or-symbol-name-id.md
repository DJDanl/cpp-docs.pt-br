---
title: 'Como: Gerenciar símbolos'
ms.date: 02/14/2019
f1_keywords:
- vc.editors.symbol.changing
- vc.editors.symbol.restrictions.name
- vc.editors.symbol.changing.value
- vc.editors.symbol.restrictions.value
- vc.editors.symbol.changing.header
- vc.editors.symbol.changing.unassigned
- vc.editors.symbol.shared.calculated
helpviewer_keywords:
- symbol names
- symbols [C++], names
- restrictions, symbol names
- numeric values
- symbols [C++], numeric values
- numeric values, changing symbols
- symbols [C++], value restrictions
- restrictions, symbol values
- resource files [C++], multiple
- Resource Includes dialog box [C++]
- symbol header files [C++], changing names
- symbols [C++], symbol header files
- Resource.h
- symbols [C++], unassigned
- Change Symbol dialog box [C++]
- unassigned symbols
- symbols [C++], deleting
- symbols [C++], read-only
- symbols [C++], shared
- symbols [C++], calculated
- read-only symbols
- symbol directives
- calculated symbols
- shared symbols
ms.assetid: 26541832-8dba-4177-b642-e08f94502ea7
ms.openlocfilehash: 67a5c801c13038e7215473edecc2d41a8f7086e0
ms.sourcegitcommit: a1676bf6caae05ecd698f26ed80c08828722b237
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/29/2020
ms.locfileid: "91505719"
---
# <a name="how-to-manage-symbols"></a>Como: Gerenciar símbolos

Quando você cria um novo recurso ou objeto de recurso, o ambiente de desenvolvimento atribui a ele um nome de símbolo padrão, por exemplo, `IDD_DIALOG1` . Você pode usar a [janela Propriedades](/visualstudio/ide/reference/properties-window) para alterar o nome do símbolo padrão ou para alterar o nome de qualquer símbolo já associado a um recurso.

Para os símbolos associados a um único recurso, você também pode usar a janela **Propriedades** para alterar o valor do símbolo. Você pode usar a [caixa de diálogo símbolos de recurso](./creating-new-symbols.md) para alterar o valor de símbolos não atribuídos no momento a um recurso.

Normalmente, todas as definições de símbolo são salvas em `Resource.h` . No entanto, talvez seja necessário alterar esse nome de arquivo para que você possa, por exemplo, trabalhar com mais de um arquivo de recurso no mesmo diretório.

> [!NOTE]
> Se o seu projeto ainda não contiver um arquivo. rc, consulte [como: criar recursos](how-to-create-a-resource-script-file.md).

## <a name="symbol-name-restrictions"></a>Restrições de nome do símbolo

As restrições de nomes de símbolo são as seguintes:

- Todos os [símbolos](symbols-resource-identifiers.md) devem ser exclusivos dentro do escopo do aplicativo para evitar definições de símbolo conflitantes nos arquivos de cabeçalho.

- Os caracteres válidos para um nome de símbolo incluem A-Z, a-z, 0-9 e sublinhados (_).

- Os nomes de símbolo não podem começar com um número e são limitados a 247 caracteres.

- Os nomes de símbolo não podem conter espaços.

- Os nomes de símbolos não diferenciam maiúsculas de minúsculas, mas o caso da primeira definição de símbolo é preservado.

   O arquivo de cabeçalho que define os símbolos é usado pelo compilador/Editor de recurso e programa (s) C++ para referenciar os recursos definidos em um arquivo de recurso. Para dois nomes de símbolo que diferem apenas no caso, o programa C++ verá dois símbolos separados, enquanto o compilador/Editor de recursos verá ambos os nomes como referência a um único símbolo.

> [!NOTE]
> Se você não seguir o esquema de nome de símbolo padrão (ID * _ [palavra-chave]) descrito abaixo e o nome do símbolo for igual a uma palavra-chave conhecida pelo compilador de script de recurso, tentar compilar o arquivo de script de recurso resultará em uma geração de erro aparentemente aleatória que é difícil de diagnosticar. Para evitar isso, siga o esquema de nomenclatura padrão.

Os nomes de símbolo têm prefixos descritivos que indicam o tipo de recurso ou objeto que representam. Esses prefixos descritivos começam com a ID de combinação de texto. A biblioteca do MFC (Microsoft Foundation Class) usa as convenções de nomenclatura de símbolo mostradas na tabela a seguir:

|Categoria|Prefixo|Uso|
|--------------|------------|---------|
|Recursos|IDR_, IDD_, IDC_, IDI_, IDB_|Acelerador ou menu (e recursos associados ou personalizados), caixa de diálogo, cursor, ícone, bitmap|
|Itens de menu|ID_|Item de menu|
|Comandos|ID_|Comando|
|Controles e janelas filhas|IDC_|Control|
|Cadeias de caracteres|IDS_|Cadeia de caracteres na tabela de cadeias de caracteres|
|MFC|AFX_|Reservado para símbolos do MFC predefinidos|

### <a name="to-change-a-symbol-name-id"></a>Para alterar um nome de símbolo (ID)

1. Em [modo de exibição de recursos](how-to-create-a-resource-script-file.md#create-resources), selecione o recurso.

1. Na janela **Propriedades** , digite um novo nome de símbolo ou selecione na lista de símbolos existentes na caixa **ID** .

   Se você digitar um novo nome de símbolo, ele será atribuído automaticamente a um valor.

> [!NOTE]
> Você pode usar a [caixa de diálogo símbolos de recurso](./creating-new-symbols.md) para alterar os nomes de símbolos não atribuídos no momento a um recurso.

## <a name="symbol-value-restrictions"></a>Restrições de valor do símbolo

Um valor de símbolo pode ser qualquer inteiro expresso da maneira normal para `#define` diretivas de pré-processador. Aqui estão alguns exemplos de valores de símbolo:

```
18
4001
0x0012
-3456
```

Os valores de símbolo para recursos como aceleradores, bitmaps, cursores, caixas de diálogo, ícones, menus, tabelas de cadeia de caracteres e informações de versão devem ser números decimais no intervalo de 0 a 32.767, mas não podem ser hexadecimais. Os valores de símbolo de partes de recursos, como controles de caixa de diálogo ou cadeias de caracteres individuais na tabela de cadeias, podem ser de 0 a 65.534 ou de-32.768 a 32.767. Para obter mais informações sobre intervalos de números, consulte [TN023: recursos padrão do MFC](../mfc/tn023-standard-mfc-resources.md).

Os símbolos de recurso são números de 16 bits. Você pode inseri-los como assinados ou não assinados, no entanto, eles são usados internamente como inteiros não assinados, portanto, números negativos serão convertidos em seu valor positivo correspondente.

Algumas limitações dos valores de símbolo são:

- O ambiente de desenvolvimento do Visual Studio e o MFC usam alguns intervalos de números para fins especiais. Todos os números com o conjunto de bits mais significativo (-32.768 a-1 ou 32.768 a 65.534, dependendo do sinal) são reservados pelo MFC.

- Você não pode definir um valor de símbolo usando outras cadeias de caracteres de símbolo. Por exemplo, a seguinte definição de símbolo não é suportada:

    ```cpp
    #define IDC_MYEDIT  IDC_OTHEREDIT  //not supported
    ```

- Você não pode usar macros de pré-processador com argumentos como definições de valor. O exemplo a seguir não é uma expressão válida, independentemente do que `ID` é avaliado em tempo de compilação:

    ```cpp
    #define   IDD_ABOUT  ID(7) //not supported
    ```

- Seu aplicativo pode ter um arquivo existente contendo símbolos definidos com expressões.

### <a name="to-change-a-symbol-value"></a>Para alterar um valor de símbolo

1. Em [modo de exibição de recursos](how-to-create-a-resource-script-file.md#create-resources), selecione o recurso.

1. Na janela **Propriedades** , digite o nome do símbolo seguido por um sinal de igual e um número inteiro na caixa **ID** , por exemplo:

    ```
    IDC_EDITNAME=5100
    ```

   O novo valor é armazenado no arquivo de cabeçalho de símbolo na próxima vez que você salvar o projeto. Somente o nome do símbolo permanece visível na caixa ID e o sinal de igual e o valor não são exibidos depois que são validados.

## <a name="change-or-delete-symbols"></a>Alterar ou excluir símbolos

Na caixa de [diálogo símbolos de recurso](./creating-new-symbols.md), você pode editar ou excluir os símbolos existentes que ainda não estão atribuídos a um recurso ou objeto.

### <a name="to-change-an-unassigned-symbol"></a>Para alterar um símbolo não atribuído

1. Na caixa **nome** , selecione o símbolo não atribuído e escolha **alterar**.

1. Edite o nome ou o valor do símbolo nas caixas fornecidas na caixa de diálogo **alterar símbolo** .

> [!NOTE]
> Para alterar um símbolo atribuído a um recurso ou objeto, você deve usar o editor de recursos ou a janela **Propriedades** .

### <a name="to-delete-an-unassigned-unused-symbol"></a>Para excluir um símbolo não atribuído (não usado)

Na caixa de diálogo **símbolos de recurso** , selecione o símbolo que você deseja excluir e escolha **excluir**.

> [!NOTE]
> Antes de excluir um símbolo não usado em um arquivo de recurso, certifique-se de que ele não seja usado em outro lugar no programa ou por arquivos de recurso incluídos no momento da compilação.

## <a name="include-symbols"></a>Incluir símbolos

Na primeira vez que o ambiente de desenvolvimento lê um arquivo de recurso criado por outro aplicativo, ele marca todos os arquivos de cabeçalho incluídos como somente leitura. Embora você possa usar a [caixa de diálogo recursos incluem](./how-to-include-resources-at-compile-time.md) para adicionar outros arquivos de cabeçalho de símbolo somente leitura.

Um motivo para que você queira usar definições de símbolo somente leitura é para arquivos de símbolo que você planeja compartilhar entre vários projetos.

Você também pode usar arquivos de símbolo incluídos quando tiver recursos existentes com definições de símbolo que usam expressões em vez de inteiros simples para definir o valor do símbolo. Por exemplo:

```cpp
#define   IDC_CONTROL1 2100
#define   IDC_CONTROL2 (IDC_CONTROL1+1)
```

O ambiente interpretará corretamente esses símbolos calculados, desde que:

- Os símbolos calculados são colocados em um arquivo de símbolos somente leitura.

- O arquivo de recursos contém recursos para os quais esses símbolos calculados já estão atribuídos.

- Uma expressão numérica é esperada.

> [!NOTE]
> Se uma cadeia de caracteres ou uma expressão numérica for esperada, a expressão não será avaliada.

### <a name="to-include-shared-read-only-symbols-in-your-resource-file"></a>Para incluir símbolos compartilhados (somente leitura) no arquivo de recursos

1. Em [modo de exibição de recursos](how-to-create-a-resource-script-file.md#create-resources), clique com o botão direito do mouse no arquivo *. rc* e selecione o [recurso inclui](./how-to-include-resources-at-compile-time.md).

1. Na caixa **diretivas de símbolo somente leitura** , use a `#include` diretiva do compilador para especificar o arquivo no qual você deseja que os símbolos somente leitura sejam mantidos.

   Não chame o arquivo `Resource.h` , já que esse é o nome de arquivo normalmente usado pelo ficheiro de cabeçalho de símbolo principal.

   > [!NOTE]
   > O que você digita na caixa **diretivas de símbolo somente leitura** é incluído no arquivo de recursos exatamente conforme você o digita. Verifique se o que você digita não contém erros ortográficos ou de sintaxe.

   Use a caixa **diretivas de símbolo somente leitura** para incluir arquivos somente com definições de símbolo. Não inclua definições de recurso, caso contrário, as definições de recursos duplicadas serão criadas quando o arquivo for salvo.

1. Coloque os símbolos no arquivo especificado.

   Os símbolos nos arquivos incluídos dessa maneira são avaliados cada vez que você abre o arquivo de recursos, mas eles não são substituídos no disco quando você salva o arquivo.

1. Selecione **OK**.

### <a name="to-change-the-name-of-the-resource-symbol-header-file"></a>Para alterar o nome do arquivo de cabeçalho de símbolo de recurso

1. Em [modo de exibição de recursos](how-to-create-a-resource-script-file.md#create-resources), clique com o botão direito do mouse no arquivo *. rc* e escolha [recursos incluir](./how-to-include-resources-at-compile-time.md).

1. Na caixa **arquivo de cabeçalho de símbolo** , digite o novo nome para o arquivo de inclusão.

## <a name="requirements"></a>Requisitos

Win32

## <a name="see-also"></a>Consulte também

[Identificadores de recurso (símbolos)](symbols-resource-identifiers.md)<br/>
[Como: criar símbolos](creating-new-symbols.md)<br/>
[IDs de símbolo predefinidas](predefined-symbol-ids.md)<br/>
