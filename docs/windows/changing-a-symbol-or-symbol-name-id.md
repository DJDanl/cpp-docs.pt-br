---
title: Alterando um símbolo
ms.date: 11/04/2016
f1_keywords:
- vc.editors.symbol.changing
- vc.editors.symbol.restrictions.name
- vc.editors.symbol.changing.value
- vc.editors.symbol.restrictions.value
- vc.editors.symbol.changing.header
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
ms.assetid: 26541832-8dba-4177-b642-e08f94502ea7
ms.openlocfilehash: 7d2890c2d2c05f1ee0309446dfe2de9917f85707
ms.sourcegitcommit: 63c072f5e941989636f5a2b13800b68bb7129931
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 02/06/2019
ms.locfileid: "55763980"
---
# <a name="changing-a-symbol"></a>Alterando um símbolo

Quando você cria um novo recurso ou objeto de recurso, o ambiente de desenvolvimento atribui a ele um nome de símbolo padrão, por exemplo, IDD_DIALOG1. Você pode usar o [janela de propriedades](/visualstudio/ide/reference/properties-window) para alterar o nome de símbolo padrão ou para alterar o nome de qualquer símbolo já está associado com um recurso.

Símbolos associados com um único recurso, você também pode usar o **propriedades** janela para alterar o valor de símbolo. Você pode usar o [caixa de diálogo símbolos de recurso](../windows/resource-symbols-dialog-box.md) para alterar o valor de símbolos que não estão atribuídos a um recurso. Para obter mais informações, consulte [alterando símbolos não atribuídos](../windows/changing-unassigned-symbols.md).

Normalmente, todos os símbolos definições são salvos no `Resource.h`. No entanto, talvez você precise alterar isso incluir o nome de arquivo para que você pode, por exemplo, trabalhar com mais de um arquivo de recurso no mesmo diretório.

Para obter informações sobre como adicionar recursos a projetos gerenciados, consulte [recursos em aplicativos de área de trabalho](/dotnet/framework/resources/index) na *guia do desenvolvedor do .NET Framework*.

## <a name="to-change-a-resources-symbol-name-id"></a>Para alterar o nome do recurso do símbolo (ID)

1. Na [exibição de recurso](../windows/resource-view-window.md), selecione o recurso.

   > [!NOTE]
   > Se seu projeto já não contiver um arquivo. RC, consulte [criando um novo arquivo de Script de recurso](../windows/how-to-create-a-resource-script-file.md).

1. No **propriedades** janela, digite um novo nome de símbolo ou selecione na lista de símbolos existentes na **ID** caixa.

   Se você digitar um novo nome de símbolo, ele é automaticamente atribuído a um valor.

Você pode usar o [caixa de diálogo símbolos de recurso](../windows/resource-symbols-dialog-box.md) para alterar os nomes de símbolos que não estão atribuídos a um recurso. Para obter mais informações, consulte [alterando símbolos não atribuídos](../windows/changing-unassigned-symbols.md).

### <a name="symbol-name-restrictions"></a>Restrições de nome de símbolo

As restrições em nomes de símbolos são da seguinte maneira:

- Todos os [símbolos](../windows/symbols-resource-identifiers.md) deve ser exclusivo dentro do escopo do aplicativo. Isso impede que as definições conflitantes do símbolo nos arquivos de cabeçalho.

- Caracteres válidos para um nome de símbolo incluem A-Z, a-z, 0 a 9 e sublinhados (_).

- Nomes de símbolo não podem começar com um número e são limitados a 247 caracteres.

- Nomes de símbolo não podem conter espaços.

- Nomes de símbolos não diferenciam maiusculas de minúsculas, mas no caso da primeira definição de símbolo é preservado. O arquivo de cabeçalho que define os símbolos é usado pelo compilador/editor de recursos e programas do C++ para fazer referência a recursos definidos em um arquivo de recurso. Dois nomes de símbolo que diferem apenas em maiusculas, o programa de C++ verá dois símbolos separados, enquanto o compilador/editor de recurso verá os dois nomes como uma referência a um único símbolo.

   > [!NOTE]
   > Se você não seguir o esquema de nome de símbolo padrão (ID*_[keyword]) descritas abaixo, e seu nome de símbolo, por acaso, é o mesmo como uma palavra-chave conhecida do compilador do script de recurso, tentar criar o arquivo de script de recurso resulta em erro aparentemente aleatório geração que é difícil de diagnosticar. Para evitar isso, seguem o esquema de nomenclatura padrão.

Nomes de símbolos têm prefixos descritivos que indicam o tipo de recurso ou objeto que eles representam. Esses prefixos descritivos começam com a ID da combinação de texto. O Microsoft Foundation Class Library (MFC) usa as convenções de nomenclatura de símbolo mostradas na tabela a seguir.

|Categoria|Prefixo|Use|
|--------------|------------|---------|
|Recursos|IDR_ IDD_ IDC_ IDI_ IDB_|Acelerador ou menu (e recursos associados ou personalizados) caixa de diálogo Bitmap do ícone de Cursor|
|Itens de menu|ID_|Item de menu|
|Comandos|ID_|Comando|
|Controles e janelas filho|IDC_|Controle|
|Cadeias de caracteres|IDS_|Cadeia de caracteres na tabela de cadeia de caracteres|
|MFC|AFX_|Reservado para símbolos predefinidos do MFC|

## <a name="to-change-a-symbol-value-assigned-to-a-single-resource-or-object"></a>Para alterar um valor de símbolo atribuído a um único recurso ou objeto

1. Na [exibição de recurso](../windows/resource-view-window.md), selecione o recurso.

   > [!NOTE]
   > Se seu projeto já não contiver um arquivo. RC, consulte [criando um novo arquivo de Script de recurso](../windows/how-to-create-a-resource-script-file.md).

1. No **propriedades** , digite o nome do símbolo seguido por um sinal de igual e um número inteiro na **ID** caixa, por exemplo:

    ```
    IDC_EDITNAME=5100
    ```

O novo valor é armazenado no arquivo de cabeçalho de símbolo na próxima vez que você salvar o projeto. Somente o nome do símbolo permanece visível na caixa ID. o sinal de igual e o valor não são exibidos depois que eles sejam validados.

### <a name="symbol-value-restrictions"></a>Restrições de valor de símbolo

Um valor de símbolo pode ser qualquer inteiro expressado da maneira normal para #define as diretivas de pré-processamento. Aqui estão alguns exemplos de valores de símbolo:

```
18
4001
0x0012
-3456
```

Valores de símbolo para os recursos (aceleradores, bitmaps, cursores, caixas de diálogo, ícones, menus, tabelas de cadeia de caracteres e informações de versão) devem ser números decimais no intervalo entre 0 e 32.767 (mas não podem ser hexadecimais). Valores de símbolo para partes de recursos, como controles de caixa de diálogo ou cadeias de caracteres individuais na tabela de cadeia de caracteres, podem ser de 0 a 65.534 ou de -32.768 a 32.767.

Símbolos de recurso são números de 16 bits. Você pode inseri-las como com ou sem sinal, no entanto, eles são usados internamente como números inteiros sem sinal. Números negativos então serão convertidos em seu valor positivo correspondente.

Aqui estão algumas limitações de valores de símbolo:

- O ambiente de desenvolvimento do Visual Studio e o MFC usam alguns intervalos de número para fins especiais. Todos os números com o conjunto de bits mais significativo (-32.768 a -1 ou 32.768 para 65.534, dependendo do sinal) são reservados pelo MFC.

- Você não pode definir um valor de símbolo usando outras cadeias de caracteres de símbolo. Por exemplo, não há suporte para a definição de símbolo a seguir:

    ```cpp
    #define IDC_MYEDIT  IDC_OTHEREDIT  //not supported
    ```

- Você não pode usar macros de pré-processador com argumentos como definições de valor. Por exemplo:

    ```cpp
    #define   IDD_ABOUT  ID(7) //not supported
    ```

   não é uma expressão válida, independentemente de qual `ID` é avaliada como em tempo de compilação.

- Seu aplicativo pode ter um arquivo existente que contém símbolos definidos com expressões. Para obter mais informações sobre como incluir os símbolos como símbolos somente leitura, consulte [usando compartilhados (somente leitura) ou símbolos calculados](../windows/including-shared-read-only-or-calculated-symbols.md).

Para obter mais informações sobre intervalos de número, consulte [TN023: Recursos MFC padrão](../mfc/tn023-standard-mfc-resources.md).

## <a name="to-change-the-name-of-the-resource-symbol-header-file"></a>Para alterar o nome do arquivo de cabeçalho de símbolo de recurso

1. Na [exibição de recurso](../windows/resource-view-window.md), clique com botão direito seu arquivo. RC e escolha [recurso inclui](../windows/resource-includes-dialog-box.md) no menu de atalho.

   > [!NOTE]
   > Se seu projeto já não contiver um arquivo. RC, consulte [criando um novo arquivo de Script de recurso](../windows/how-to-create-a-resource-script-file.md).

1. No **arquivo de cabeçalho de símbolo** , digite o novo nome para o arquivo de inclusão.

## <a name="requirements"></a>Requisitos

Win32

## <a name="see-also"></a>Consulte também

[IDs de símbolos predefinidos](../windows/predefined-symbol-ids.md)<br/>
[Exibindo símbolos de recurso](../windows/viewing-resource-symbols.md)<br/>
