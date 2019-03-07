---
title: 'Como: Incluir recursos em tempo de compilação (C++)'
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
ms.openlocfilehash: 74c70db5c04a6b56ec7bb2630c8d829151ec4225
ms.sourcegitcommit: b4645761ce5acf8c2fc7a662334dd5a471ea976d
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/07/2019
ms.locfileid: "57562829"
---
# <a name="how-to-include-resources-at-compile-time-c"></a>Como: Incluir recursos em tempo de compilação (C++)

Por padrão que todos os recursos estão localizados em um arquivo de script (. rc) do recurso, no entanto há muitas razões para colocar recursos em um arquivo que não seja o arquivo. rc principal:

- Para adicionar comentários a instruções de recursos que não são excluídas quando você salvar o arquivo. rc.

- Para incluir recursos que já foram desenvolvidos e testados e não precisa de modificação adicional. Todos os arquivos que são incluídos, mas não tem uma extensão. rc não será editáveis por editores de recursos.

- Para incluir recursos que estão sendo usados por diferentes projetos ou que fazem parte de um sistema de controle de versão do código-fonte. Esses recursos devem existir em um local central onde as modificações afetará todos os projetos.

- Para incluir recursos (como recursos RCDATA) que são um formato personalizado. Recursos RCDATA tenham requisitos especiais em que você não pode usar uma expressão como um valor para o `nameID` campo.

Se você tiver seções em seus arquivos. rc existentes que atendem a qualquer uma dessas condições, coloque essas seções em um ou mais arquivos. rc separam e incluem-los no seu projeto usando o **inclui recursos** caixa de diálogo.

## <a name="resource-includes"></a>Recurso inclui

Você pode adicionar recursos de outros arquivos ao seu projeto em tempo de compilação listando-os na **diretivas de tempo de compilação** caixa de **inclui recursos** caixa de diálogo. Use o **recurso inclui** caixa de diálogo para modificar a disposição de trabalho normal do ambiente de projeto de armazenar todos os recursos no arquivo. rc de projeto e todas as [símbolos](../windows/symbols-resource-identifiers.md) em `Resource.h`.

Para começar, abra o **recurso inclui** caixa de diálogo clicando em um arquivo. rc no [exibição de recurso](/windows/how-to-create-a-resource-script-file#create-resources), selecione **recurso inclui** e observe as seguintes propriedades:

| Propriedade | Descrição |
|---|---|
| **Arquivo de cabeçalho de símbolo** | Permite que você altere o nome do arquivo de cabeçalho em que as definições de símbolo para os arquivos de recurso são armazenadas.<br/><br/>Para obter mais informações, consulte [alterando os nomes dos arquivos de cabeçalho do símbolo](../windows/changing-the-names-of-symbol-header-files.md). |
| **Diretivas de símbolo somente leitura** | Permite que você inclua arquivos de cabeçalho que contêm símbolos que não devem ser modificados.<br/><br/>Por exemplo, arquivos de símbolo a ser compartilhada com outros projetos. Isso também pode incluir arquivos. h do MFC. Para obter mais informações, consulte [incluindo compartilhados (somente leitura) ou símbolos calculados](../windows/including-shared-read-only-or-calculated-symbols.md). |
| **Diretivas de tempo de compilação** | Permite que você inclua arquivos de recursos que são criados e editados separadamente dos recursos em seu arquivo de recurso principal, contêm diretivas de tempo de compilação (por exemplo, essas diretivas que incluem condicionalmente recursos) ou contêm recursos em um formato personalizado.<br/><br/>Você também pode usar o **caixa de diretivas de tempo de compilação** para incluir arquivos de recursos padrão do MFC. |

> [!NOTE]
> Entradas nessas caixas de texto aparecem no arquivo. rc marcado pelo `TEXTINCLUDE 1`, `TEXTINCLUDE 2`, e `TEXTINCLUDE 3` , respectivamente. Para obter mais informações, consulte [TN035: Usando vários arquivos de recurso e arquivos de cabeçalho com o Visual C++](../mfc/tn035-using-multiple-resource-files-and-header-files-with-visual-cpp.md).

Depois que as alterações forem feitas em seu arquivo de recurso usando o **recurso inclui** caixa de diálogo, você deve fechar e reabrir o *. rc* arquivo para que as alterações entrem em vigor.

### <a name="to-include-resources-in-your-project-at-compile-time"></a>Para incluir recursos em seu projeto em tempo de compilação

1. Coloque os recursos em um arquivo de script de recurso com um nome de arquivo exclusivo. Não use *projectname.rc*, porque esse é o nome do arquivo usado para o arquivo de script de recurso principal.

1. Com o botão direito do *. rc* de arquivo no [exibição de recurso](/windows/how-to-create-a-resource-script-file#create-resources) e selecione **recurso inclui**.

1. No **diretivas de tempo de compilação** caixa, adicione o [#include](../preprocessor/hash-include-directive-c-cpp.md) diretiva do compilador para incluir o novo arquivo de recurso no arquivo de recurso principal no ambiente de desenvolvimento.

Os recursos em arquivos incluídos dessa maneira são feitos apenas parte do executável no tempo de compilação e não estão disponíveis para edição ou modificação quando você estiver trabalhando em um arquivo. rc principal do seu projeto. Arquivos. rc incluído precisam ser abertas separadamente e todos os arquivos incluídos sem a extensão. rc não será editáveis por editores de recursos.

### <a name="to-specify-include-directories-for-a-specific-resource-rc-file"></a>Para especificar diretórios de inclusão para um arquivo de recurso específico (. rc)

1. Clique com botão direito do *. rc* de arquivo no **Gerenciador de soluções** e selecione **propriedades**.

1. Selecione o **recursos** nó no painel esquerdo e especifique adicionais incluem os diretórios no **diretórios de inclusão adicionais** propriedade.

### <a name="to-find-symbols-in-resources"></a>Para localizar símbolos em recursos

1. Vá ao menu **edite** > [Localizar símbolo](/visualstudio/ide/go-to).

   > [!TIP]
   > Para usar [expressões regulares](/visualstudio/ide/using-regular-expressions-in-visual-studio) em sua pesquisa, selecione [localizar nos arquivos](/visualstudio/ide/reference/find-command) no **editar** menu, em vez de **Localizar símbolo**. Selecione o **uso: Expressões regulares** caixa de seleção a [caixa de diálogo Localizar](/visualstudio/ide/finding-and-replacing-text) e, no **localizar** caixa, você pode escolher uma expressão regular pesquisa na lista suspensa. Quando você seleciona uma expressão dessa lista, ele será substituído como o texto de pesquisa na **localizar** caixa.

1. No **localizar** caixa, selecione uma cadeia de caracteres de pesquisa anterior na lista suspensa ou digite a tecla de atalho que você deseja localizar, por exemplo, `ID_ACCEL1`.

1. Selecione qualquer uma da **encontrar** opções e escolha **Localizar próximo**.

> [!NOTE]
> Você não pode pesquisar símbolos em recursos binários, acelerador ou cadeia de caracteres.

## <a name="requirements"></a>Requisitos

Win32

## <a name="see-also"></a>Consulte também

[Arquivos de recurso](../windows/resource-files-visual-studio.md)<br/>
[Como: Criar recursos](../windows/how-to-create-a-resource-script-file.md)<br/>
[Como: Gerenciar recursos](../windows/how-to-copy-resources.md)<br/>