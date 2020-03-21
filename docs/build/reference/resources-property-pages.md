---
title: Recursos
ms.date: 08/28/2019
ms.topic: article
ms.assetid: dade2f6b-c51f-4c33-9023-41956ae4b5f6
f1_keywords:
- VC.Project.VCResourceCompilerTool.PreprocessorDefinitions
- VC.Project.VCResourceCompilerTool.UndefineProcessorDefinitions
- VC.Project.VCResourceCompilerTool.Culture
- VC.Project.VCResourceCompilerTool.AdditionalIncludeDirectories
- VC.Project.VCResourceCompilerTool.IgnoreStandardIncludePath
- VC.Project.VCResourceCompilerTool.ShowProgress
- VC.Project.VCResourceCompilerTool.SuppressStartupBanner
- VC.Project.VCResourceCompilerTool.ResourceOutputFileName
- VC.Project.VCResourceCompilerTool.NullTerminateStrings
- vc.project.AdditionalOptionsPage
ms.openlocfilehash: 4f3688da4feb11f673e11372e5df086dc8c7e21a
ms.sourcegitcommit: 8e285a766523e653aeeb34d412dc6f615ef7b17b
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/21/2020
ms.locfileid: "80078286"
---
# <a name="resources-property-page"></a>Página de propriedades de recursos

Para programas nativos da área de trabalho do Windows, a compilação invoca o [compilador de recurso (RC. exe)](/windows/win32/menurc/resource-compiler) para adicionar imagens, tabelas de cadeia de caracteres e arquivos *. res* ao binário. As propriedades expostas nesta página de propriedades são passadas para o compilador de recurso C++ , não para o compilador ou o vinculador. Para obter mais informações sobre as propriedades listadas aqui e como elas são mapeadas para as opções de linha de comando RC, consulte [usando o RC (a linha de comando RC)](/windows/win32/menurc/using-rc-the-rc-command-line-). Para obter informações sobre como acessar as páginas de propriedades de **recursos** , consulte [ C++ definir compilador e propriedades de compilação no Visual Studio](../working-with-project-properties.md). Para acessar essas propriedades de forma programática, confira <xref:Microsoft.VisualStudio.VCProjectEngine.VCResourceCompilerTool>.

As propriedades de recursos do C++.net em aplicativos/CLI são expostas na [página de propriedades recursos gerenciados](managed-resources-property-page.md).

## <a name="preprocessor-definitions"></a>Definições do Pré-processador

Especifica uma ou mais definições para o compilador de recurso. (/d [macro])

## <a name="undefine-preprocessor-definitions"></a>Excluir as definições do pré-processador

Desdefina um símbolo. /u

## <a name="culture"></a>Cultura

Lista a cultura (como inglês americano ou italiano) usada nos recursos. (/l [num])

## <a name="additional-include-directories"></a>Diretórios de Inclusão Adicionais

Especifica um ou mais diretórios a serem adicionados ao caminho de inclusão; Use o delimitador de ponto-e-vírgula se houver mais de um. (/I [caminho])

## <a name="ignore-standard-include-paths"></a>Ignorar caminhos de inclusão padrão

Impede que o compilador de recursos procure por arquivos de inclusão em diretórios especificados nas variáveis de ambiente INCLUDE. /X

## <a name="show-progress"></a>Mostrar progresso

Enviar mensagens de progresso para a janela de saída. /v

## <a name="suppress-startup-banner"></a>Suprimir Faixa de Inicialização

Suprimir a exibição da faixa de inicialização e mensagem de informação (/nologo)

## <a name="resource-file-name"></a>Nome do arquivo de recurso

Especifica o nome do arquivo de recurso (/fo [File])

## <a name="null-terminate-strings"></a>Cadeias de caracteres de término nulas

Anexar nulos a todas as cadeias de caracteres nas tabelas de cadeias. opção

## <a name="see-also"></a>Confira também

[C++referência de página de propriedades do projeto](property-pages-visual-cpp.md)