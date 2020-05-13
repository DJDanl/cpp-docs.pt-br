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
ms.openlocfilehash: c4a3048bfa07e9635662534b510fa57caa091f00
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81336085"
---
# <a name="resources-property-page"></a>Página de propriedade de recursos

Para programas nativos de desktop do Windows, a compilação invoca o [Resource Compiler (rc.exe)](/windows/win32/menurc/resource-compiler) para adicionar imagens, tabelas de strings e arquivos *.res* ao binário. As propriedades expostas nesta página de propriedade são passadas para o Compilador de recursos, não para o compilador C++ ou para o linker. Para obter mais informações sobre as propriedades listadas aqui e como elas mapeiam as opções de linha de comando RC, consulte [Usando RC (A Linha de Comando RC)](/windows/win32/menurc/using-rc-the-rc-command-line-). Para obter informações sobre como acessar as páginas de propriedade **Resources,** consulte [O compilador Set C++ e construa propriedades no Visual Studio](../working-with-project-properties.md). Para acessar essas propriedades de forma programática, confira <xref:Microsoft.VisualStudio.VCProjectEngine.VCResourceCompilerTool>.

As propriedades para recursos .NET em aplicativos C++/CLI são expostas na [Página de propriedade de recursos gerenciados](managed-resources-property-page.md).

## <a name="preprocessor-definitions"></a>Definições do Pré-processador

Especifica um ou mais definições para o compilador de recursos. (/d[macro])

## <a name="undefine-preprocessor-definitions"></a>Excluir definições do pré-processador

Desdefinir um símbolo. (/u)

## <a name="culture"></a>Cultura

Lista a cultura (como inglês ou italiano dos EUA) usada nos recursos. (/l [num])

## <a name="additional-include-directories"></a>Diretórios de Inclusão Adicionais

Especifica um ou mais diretórios para adicionar ao caminho de inclusão; usar delimitador de ponto e vírgula se mais de um. (/I[caminho])

## <a name="ignore-standard-include-paths"></a>Ignorar caminhos de inclusão padrão

Impede que o compilador de recursos procure incluir arquivos em diretórios especificados nas variáveis de ambiente INCLUDE. (/X)

## <a name="show-progress"></a>Mostrar progresso

Envie mensagens de progresso para a janela de saída. (/v)

## <a name="suppress-startup-banner"></a>Suprimir Faixa de Inicialização

Suprimir a exibição do banner de inicialização e a mensagem de informação (/nologo)

## <a name="resource-file-name"></a>Nome do arquivo do recurso

Especifica o nome do arquivo de recursos (/fo[file])

## <a name="null-terminate-strings"></a>Cordas de término nula

Anexar nulo a todas as cordas nas tabelas de strings. (/n)

## <a name="see-also"></a>Confira também

[Referência da página de propriedade do projeto C++](property-pages-visual-cpp.md)
