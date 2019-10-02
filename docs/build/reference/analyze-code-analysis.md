---
title: /analyze (Análise do código)
ms.date: 10/01/2019
f1_keywords:
- VC.Project.VCCLCompilerTool.EnablePREfast
- /analyze
- VC.Project.VCCLCompilerTool.PREfastAdditionalOptions
- VC.Project.VCCLCompilerTool.PREfastAdditionalPlugins
helpviewer_keywords:
- /analyze compiler option [C++]
- -analyze compiler option [C++]
- analyze compiler option [C++]
ms.assetid: 81da536a-e030-4bd4-be18-383927597d08
ms.openlocfilehash: d647045d76dc32544f8146424b220547890b0943
ms.sourcegitcommit: 4517932a67bbf2db16cfb122d3bef57a43696242
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/02/2019
ms.locfileid: "71816328"
---
# <a name="analyze-code-analysis"></a>/analyze (Análise do código)

Habilita opções de análise e controle de código.

## <a name="syntax"></a>Sintaxe

```cmd
/analyze[-][:WX-][:log filename][:quiet][:stacksize number][:max_paths number][:only][:ruleset]
```

## <a name="arguments"></a>Argumentos

/Analyze ativa a análise no modo padrão. A saída da análise vai para a janela de **saída** como outras mensagens de erro. Use **/Analyze-** para desativar explicitamente a análise.

/analyze: WX-especificando **/analyze: WX-** significa que os avisos de análise de código não são tratados como erros quando você compila usando **/WX**. Para obter mais informações, consulte [/w, /W0, /W1, /W2, /W3, /W4, /w1, /w2, /w3, /w4, /Wall, /wd, /we, /wo, /Wv, /WX (Nível de Aviso)](compiler-option-warning-level.md).

/analyze: log `filename` os resultados detalhados do analisador são gravados como XML no arquivo especificado por `filename`.

/analyze: Quiet desativa a saída do analisador na janela de **saída** .

/analyze: stacksize `number` o parâmetro `number` que é usado com essa opção especifica o tamanho, em bytes, do quadro de pilha para o qual o aviso [C6262](/visualstudio/code-quality/c6262) é gerado. O espaço antes de `number` é opcional. Se esse parâmetro não for especificado, o tamanho do quadro da pilha será de 16 KB por padrão.

/analyze: max_paths `number` o parâmetro `number` que é usado com essa opção especifica o número máximo de caminhos de código a serem analisados. Se esse parâmetro não for especificado, o número será 256 por padrão. Valores maiores executam uma verificação mais completa, mas a análise pode demorar mais.

/analyze: apenas normalmente, o compilador gera código e faz mais verificação de sintaxe depois de executar o analisador. A opção **/analyze: only** desativa essa passagem de geração de código; Isso torna a análise mais rápida, mas erros de compilação e avisos que podem ter sido descobertos pelo passo de geração de código do compilador não são emitidos. Se o programa não estiver livre de erros de geração de código, os resultados da análise poderão não ser confiáveis; consequentemente, recomendamos que você use essa opção apenas se o código já tiver passado na verificação da sintaxe de geração de código sem erros.

/analyze: RuleSet `<file_path>.ruleset` permite que você especifique quais conjuntos de regras analisar, incluindo conjuntos de regras personalizadas que você pode criar por conta própria. Quando essa opção é definida, o mecanismo de regras é mais eficiente porque exclui não membros do conjunto de regras especificado antes da execução. Quando a opção não estiver definida, o mecanismo verificará todas as regras.

Os conjuntos de regras que acompanham o Visual Studio são encontrados em **%VSINSTALLDIR%\Team Tools\Static Analysis Tools\Rule sets.**

O conjunto de regras personalizadas de exemplo a seguir informa ao mecanismo de regras para verificar C6001 e C26494. Você pode posicionar esse arquivo em qualquer lugar, desde que ele tenha uma extensão `.ruleset` e forneça o caminho completo no argumento.

```xml
<?xml version="1.0" encoding="utf-8"?>
<RuleSet Name="New Rule Set" Description=" " ToolsVersion="15.0">
  <Rules AnalyzerId="Microsoft.Analyzers.NativeCodeAnalysis" RuleNamespace="Microsoft.Rules.Native">
    <Rule Id="C6001" Action="Warning" />
    <Rule Id="C26494" Action="Warning" />
  </Rules>
</RuleSet>
```

/analyze: plugin habilita o plug-in PREfast especificado como parte das execuções de análise de código.
LocalEspC. dll é o plug-in que implementa verificações de análise de código relacionadas à simultaneidade no intervalo de avisos de C261XX. Por exemplo, [C26100](/visualstudio/code-quality/c26100), [C26101](/visualstudio/code-quality/c26101),..., [C26167](/visualstudio/code-quality/c26167).

Para executar LocalEspC. dll, use esta opção de compilador: **/analyze: plugin LocalEspC. dll**

Para executar CppCoreCheck. dll, primeiro execute este comando em um prompt de comando do desenvolvedor:

```cmd
set Esp.Extensions=CppCoreCheck.dll
```

Em seguida, use esta opção de compilador: **/analyze: plugin EspXEngine. dll**.

## <a name="remarks"></a>Comentários

Para obter mais informações, consulte [análise de código paraC++ c/visão geral](/visualstudio/code-quality/code-analysis-for-c-cpp-overview) e [análise deC++ código para c/Warnings](/visualstudio/code-quality/code-analysis-for-c-cpp-warnings).

### <a name="to-set-this-compiler-option-in-the-visual-studio-development-environment"></a>Para definir esta opção do compilador no ambiente de desenvolvimento do Visual Studio

1. Abra a caixa de diálogo **Páginas de Propriedades** do projeto. Para obter detalhes, confira [Definir as propriedades de build e do compilador do C++ no Visual Studio](../working-with-project-properties.md).

1. Expanda o nó **Propriedades de Configuração**.

1. Expanda o nó **análise de código** .

1. Selecione a página de propriedades **geral** .

1. Modifique uma ou mais das propriedades de **análise de código** .

### <a name="to-set-this-compiler-option-programmatically"></a>Para definir essa opção do compilador via programação

1. Consulte <xref:Microsoft.VisualStudio.VCProjectEngine.VCCLCompilerTool.EnablePREfast%2A>.

## <a name="see-also"></a>Consulte também

- [Opções do compilador MSVC](compiler-options.md)
- [Sintaxe da linha de comando do compilador MSVC](compiler-command-line-syntax.md)
