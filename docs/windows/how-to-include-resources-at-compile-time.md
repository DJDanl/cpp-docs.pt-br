---
title: 'Como: Incluir recursos em tempo de compilação (C++)'
ms.date: 11/04/2016
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
ms.assetid: 357e93c2-0a29-42f9-806f-882f688b8924
ms.openlocfilehash: 52145d2a656a7cac0d07a43ceaf298fbebb5ad40
ms.sourcegitcommit: 63c072f5e941989636f5a2b13800b68bb7129931
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 02/06/2019
ms.locfileid: "55764071"
---
# <a name="how-to-include-resources-at-compile-time"></a>Como: Incluir recursos em tempo de compilação

Normalmente, é fácil e conveniente para trabalhar com a organização padrão de todos os recursos em um arquivo de script (. rc) do recurso. No entanto, você pode adicionar recursos em outros arquivos ao seu projeto atual em tempo de compilação listando-os no **diretivas de tempo de compilação** caixa de **inclui recursos** caixa de diálogo.

Há várias razões para colocar recursos em um arquivo que não seja o arquivo. rc principal:

- Para adicionar comentários a instruções de recursos que não são excluídas quando você salvar o arquivo. rc.

   Os editores de recursos não lidos diretamente. rc ou `resource.h` arquivos. O compilador de recurso compila-os em arquivos de .aps, que são consumidos pelos editores de recursos. Esse arquivo é uma etapa de compilação e armazena apenas dados simbólicos. Como com um normal de processo de compilação, as informações que não são simbólicas (por exemplo, comentários) serão descartadas durante o processo de compilação. Sempre que o arquivo .aps obtém fora de sincronia com o arquivo. RC, o arquivo. rc for gerado novamente (por exemplo, quando você salva, o editor de recurso substitui o arquivo. RC e o `resource.h` arquivo). Todas as alterações para os próprios recursos permanecerão incorporadas no arquivo. RC, mas comentários sempre serão perdidos depois que o arquivo. RC é substituído.

- Para incluir recursos que já foram desenvolvidos e testados e não precisa de modificação adicional. (Todos os arquivos que são incluídos, mas não tem uma extensão. rc não será editáveis por editores de recursos).

- Para incluir recursos que estão sendo usados por vários projetos diferentes ou que fazem parte de um sistema de controle de versão do código-fonte e, portanto, deve existir em um local central onde as modificações afetará todos os projetos.

- Para incluir recursos (como recursos RCDATA) que estão em um formato personalizado. Recursos RCDATA podem ter requisitos especiais. Por exemplo, você não pode usar uma expressão como um valor para o campo de nameID. Consulte a documentação do SDK do Windows para obter mais informações.

Se você tiver seções em seus arquivos. rc existentes que atendem a qualquer uma dessas condições, você deve colocar as seções em um ou mais arquivos. rc separam e incluem-los no seu projeto usando o **inclui recursos** caixa de diálogo. O *Projectname*arquivo .rc2 criado no subdiretório \res de um novo projeto é usado para essa finalidade.

Você pode usar o **recurso inclui** caixa de diálogo em um projeto do C++ para modificar a disposição de trabalho normal do ambiente de armazenar todos os recursos no arquivo. rc de projeto e todas as [símbolos](../windows/symbols-resource-identifiers.md) em Resource. h.

Para abrir o **recurso inclui** do arquivo na caixa de diálogo, clique com botão direito um. rc [exibição de recurso](../windows/resource-view-window.md), em seguida, escolha **recurso inclui** no menu de atalho. Essa caixa de diálogo tem as seguintes propriedades:

|Propriedade|Descrição|
|---|---|
|**Arquivo de cabeçalho de símbolo**|Permite que você altere o nome do arquivo de cabeçalho em que as definições de símbolo para o arquivo de recurso são armazenadas. Para obter mais informações, consulte [alterando os nomes dos arquivos de cabeçalho do símbolo](../windows/changing-the-names-of-symbol-header-files.md).|
|**Diretivas de símbolo somente leitura**|Permite que você inclua arquivos de cabeçalho que contêm símbolos que não devem ser modificados durante uma sessão de edição. Por exemplo, você pode incluir um arquivo de símbolo que é compartilhado entre vários projetos. Você também pode incluir arquivos. h do MFC. Para obter mais informações, consulte [incluindo compartilhados (somente leitura) ou símbolos calculados](../windows/including-shared-read-only-or-calculated-symbols.md).|
|**Diretivas de tempo de compilação**|Permite que você inclua arquivos de recursos que são criados e editados separadamente dos recursos em seu arquivo de recurso principal, contêm diretivas de tempo de compilação (por exemplo, essas diretivas que incluem condicionalmente recursos) ou contêm recursos em um formato personalizado. Você também pode usar o **caixa de diretivas de tempo de compilação** para incluir arquivos de recursos padrão do MFC. Para obter mais informações, consulte [incluindo recursos em tempo de compilação](../windows/how-to-include-resources-at-compile-time.md).|

> [!NOTE]
> Entradas nessas caixas de texto aparecem no arquivo. rc marcado pelo `TEXTINCLUDE 1`, `TEXTINCLUDE 2`, e `TEXTINCLUDE 3` , respectivamente. Para obter mais informações, consulte [TN035: Usando vários arquivos de recurso e arquivos de cabeçalho com o Visual C++](../mfc/tn035-using-multiple-resource-files-and-header-files-with-visual-cpp.md).

Depois de fazer alterações em seu arquivo de recurso usando o **inclui recursos** caixa de diálogo, você precisa fechar o arquivo. RC e, em seguida, reabri-lo para que as alterações entrem em vigor. Para obter mais informações, consulte [incluindo recursos em tempo de compilação](../windows/how-to-include-resources-at-compile-time.md).

Para obter informações sobre como adicionar recursos a projetos gerenciados, consulte [recursos em aplicativos de área de trabalho](/dotnet/framework/resources/index) no guia do desenvolvedor do .NET Framework.

## <a name="to-include-resources-in-your-project-at-compile-time"></a>Para incluir recursos em seu projeto em tempo de compilação

1. Coloque os recursos em um arquivo de script de recurso com um nome de arquivo exclusivo. Não use *projectname*. RC, porque esse nome é o nome do arquivo usado para o arquivo de script de recurso principal.

1. Clique com botão direito no arquivo. RC (no [exibição de recurso](../windows/resource-view-window.md)) e escolha **recurso inclui** no menu de atalho.

1. No **diretivas de tempo de compilação** caixa, adicione o [#include](../preprocessor/hash-include-directive-c-cpp.md) diretiva do compilador para incluir o novo arquivo de recurso no arquivo de recurso principal no ambiente de desenvolvimento.

   Os recursos em arquivos incluídos dessa maneira são feitos uma parte do seu arquivo executável no tempo de compilação. Eles não estão diretamente disponíveis para edição ou modificação quando você estiver trabalhando em um arquivo. rc principal do seu projeto. Abra arquivos. rc incluído separadamente. Todos os arquivos que são incluídos, mas não tem uma extensão. rc não será editáveis por editores de recursos.

## <a name="to-specify-include-directories-for-a-specific-resource-rc-file-c"></a>Para especificar diretórios de inclusão para um recurso específico (arquivo. rc) (C++)

1. Clique com botão direito no arquivo. rc no Gerenciador de soluções e selecione **propriedades** no menu de atalho.

1. No **páginas de propriedades** caixa de diálogo, selecione o **recursos** nó no painel esquerdo, em seguida, especificar diretórios de inclusão adicionais a **dediretóriosdeinclusãoadicionais**propriedade.

## <a name="requirements"></a>Requisitos

Win32

## <a name="see-also"></a>Consulte também

[Arquivos de recurso](../windows/resource-files-visual-studio.md)<br/>
[Editores de recursos](../windows/resource-editors.md)<br/>
[TN035: Usando vários arquivos de recurso e arquivos de cabeçalho com o Visual C++](../mfc/tn035-using-multiple-resource-files-and-header-files-with-visual-cpp.md)<br/>
[Símbolos: identificadores de recursos](../windows/symbols-resource-identifiers.md)<br/>
