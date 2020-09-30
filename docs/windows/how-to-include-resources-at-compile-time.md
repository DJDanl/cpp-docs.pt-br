---
title: 'Como: incluir recursos em tempo de compilação (C++)'
ms.date: 02/14/2019
f1_keywords:
- vs.resvw.resource.including
- vc.resvw.resource.including
- vc.editors.resourceincludes
helpviewer_keywords:
- comments [C++], compiled files
- resources [C++], including at compile time
- projects [C++], including resources
- '#include directive'
- include directive (#include)
- Resource Includes dialog box [C++]
- rc files [C++], changing storage
- symbol header files [C++], changing
- .rc files [C++], changing storage
- symbol header files [C++], read-only
- symbols [C++], symbol header files
- directories [C++], specifying include paths for resources
- include files [C++], specifying for resources
- resources [C++], including in projects
- symbols [C++], finding
- resources [C++], searching for symbols
ms.assetid: 357e93c2-0a29-42f9-806f-882f688b8924
ms.openlocfilehash: 5ac4cba4e8ad8a08fa1010758c5a343501d3af2c
ms.sourcegitcommit: a1676bf6caae05ecd698f26ed80c08828722b237
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/29/2020
ms.locfileid: "91504413"
---
# <a name="how-to-include-resources-at-compile-time-c"></a>Como: incluir recursos em tempo de compilação (C++)

Por padrão, todos os recursos estão localizados em um arquivo de script de recurso (. rc), no entanto, há muitas razões para inserir recursos em um arquivo diferente do arquivo Main. rc:

- Para adicionar comentários a instruções de recurso que não serão excluídas quando você salvar o arquivo. rc.

- Para incluir recursos que já foram desenvolvidos e testados e não precisam de modificações adicionais. Todos os arquivos incluídos, mas não têm uma extensão. rc, não serão editáveis pelos editores de recursos.

- Para incluir recursos que estão sendo usados por projetos diferentes, ou que fazem parte de um sistema de controle de versão de código-fonte. Esses recursos devem existir em um local central, onde as modificações afetarão todos os projetos.

- Para incluir recursos (como recursos RCDATA) que são um formato personalizado. Os recursos RCDATA têm requisitos especiais em que você não pode usar uma expressão como um valor para o `nameID` campo.

Se você tiver seções em seus arquivos. rc existentes que atendam a qualquer uma dessas condições, coloque essas seções em um ou mais arquivos. rc separados e inclua-as em seu projeto usando a caixa de diálogo **recursos incluídos** .

## <a name="resource-includes"></a>Recurso inclui

Você pode adicionar recursos de outros arquivos ao seu projeto no momento da compilação, listando-os na caixa **diretivas de tempo de compilação** na caixa de diálogo **recursos incluem** . Use a caixa de diálogo **recursos incluídos** para modificar a organização de trabalho normal do ambiente do projeto de armazenar todos os recursos no arquivo Project. rc e todos os [símbolos](../windows/symbols-resource-identifiers.md) no `Resource.h` .

Para começar, abra a caixa de diálogo **recursos de inclusão** clicando com o botão direito do mouse em um arquivo. rc em [modo de exibição de recursos](how-to-create-a-resource-script-file.md#create-resources), selecione o **recurso inclui** e observe as seguintes propriedades:

| Propriedade | Descrição |
|---|---|
| **Arquivo de cabeçalho de símbolo** | Permite alterar o nome do arquivo de cabeçalho em que as definições de símbolo para os arquivos de recursos são armazenadas.<br/><br/>Para obter mais informações, consulte [alterando os nomes dos arquivos de cabeçalho de símbolo](./changing-a-symbol-or-symbol-name-id.md). |
| **Diretivas de símbolo somente leitura** | Permite que você inclua arquivos de cabeçalho que contenham símbolos que não devem ser modificados.<br/><br/>Por exemplo, os arquivos de símbolo a serem compartilhados com outros projetos. Isso também pode incluir arquivos MFC. h. Para obter mais informações, consulte [incluindo símbolos compartilhados (somente leitura) ou calculados](./changing-a-symbol-or-symbol-name-id.md). |
| **Diretivas de tempo de compilação** | Permite que você inclua arquivos de recurso que são criados e editados separadamente dos recursos em seu arquivo de recurso principal, contêm diretivas de tempo de compilação (como as diretivas que incluem os recursos condicionalmente) ou contêm recursos em um formato personalizado.<br/><br/>Você também pode usar a **caixa de diretivas de tempo de compilação** para incluir arquivos de recursos padrão do MFC. |

> [!NOTE]
> As entradas nessas caixas de texto aparecem no arquivo. rc marcado por `TEXTINCLUDE 1` , `TEXTINCLUDE 2` e `TEXTINCLUDE 3` respectivamente. Para obter mais informações, consulte [TN035: usando vários arquivos de recursos e arquivos de cabeçalho com Visual C++](../mfc/tn035-using-multiple-resource-files-and-header-files-with-visual-cpp.md).

Depois que as alterações forem feitas no arquivo de recursos usando a caixa de diálogo **recursos incluídos** , você deverá fechar e reabrir o arquivo *. rc* para que as alterações entrem em vigor.

### <a name="to-include-resources-in-your-project-at-compile-time"></a>Para incluir recursos em seu projeto no momento da compilação

1. Coloque os recursos em um arquivo de script de recurso com um nome de arquivo exclusivo. Não use *ProjectName. rc*, pois esse é o nome do arquivo usado para o arquivo de script de recurso principal.

1. Clique com o botão direito do mouse no arquivo *. rc* em [modo de exibição de recursos](how-to-create-a-resource-script-file.md#create-resources) e selecione o **recurso inclui**.

1. Na caixa **diretivas de tempo de compilação** , adicione o [#include](../preprocessor/hash-include-directive-c-cpp.md) diretiva de compilador para incluir o novo arquivo de recurso no arquivo de recurso principal no ambiente de desenvolvimento.

Os recursos nos arquivos incluídos dessa maneira só fazem parte do executável no momento da compilação e não estão disponíveis para edição ou modificação quando você está trabalhando no arquivo Main. rc do seu projeto. Os arquivos. rc incluídos precisam ser abertos separadamente e todos os arquivos incluídos sem a extensão. RC não serão editáveis pelos editores de recursos.

### <a name="to-specify-include-directories-for-a-specific-resource-rc-file"></a>Para especificar diretórios de inclusão para um arquivo de recurso específico (. rc)

1. Clique com o botão direito do mouse no arquivo *. rc* em **Gerenciador de soluções** e selecione **Propriedades**.

1. Selecione o nó **recursos** no painel esquerdo e especifique os diretórios de inclusão adicionais na propriedade **incluir diretórios adicionais** .

### <a name="to-find-symbols-in-resources"></a>Para localizar símbolos em recursos

1. Vá para o menu **Editar**  >  [símbolo de localização](/visualstudio/ide/go-to).

   > [!TIP]
   > Para usar [expressões regulares](/visualstudio/ide/using-regular-expressions-in-visual-studio) em sua pesquisa, selecione [Localizar em arquivos](/visualstudio/ide/reference/find-command) no menu **Editar** em vez de **Localizar símbolo**. Marque a caixa de seleção **usar: expressões regulares** na [caixa de diálogo Localizar](/visualstudio/ide/finding-and-replacing-text) e na caixa **Localizar** , você pode escolher uma expressão de pesquisa regular na lista suspensa. Quando você seleciona uma expressão nessa lista, ela é substituída como o texto de pesquisa na caixa **Localizar** .

1. Na caixa **Localizar** , selecione uma cadeia de caracteres de pesquisa anterior na lista suspensa ou digite a tecla aceleradora que você deseja localizar, por exemplo, `ID_ACCEL1` .

1. Selecione qualquer uma das opções de **localização** e escolha **Localizar próximo**.

> [!NOTE]
> Não é possível pesquisar símbolos em recursos de cadeia de caracteres, acelerador ou binário.

## <a name="requirements"></a>Requisitos

Win32

## <a name="see-also"></a>Consulte também

[Arquivos de recurso](../windows/resource-files-visual-studio.md)<br/>
[Como: criar recursos](../windows/how-to-create-a-resource-script-file.md)<br/>
[Como: gerenciar recursos](../windows/how-to-copy-resources.md)<br/>
