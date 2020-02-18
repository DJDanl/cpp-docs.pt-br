---
title: /analyze (análise do código)
ms.date: 10/15/2019
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
ms.openlocfilehash: c0cebe1cbd160bdec257a960f90039c1af3bfee2
ms.sourcegitcommit: 7bea0420d0e476287641edeb33a9d5689a98cb98
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 02/17/2020
ms.locfileid: "77416049"
---
# <a name="analyze-code-analysis"></a>/analyze (análise do código)

Habilita opções de análise e controle de código.

## <a name="syntax"></a>Sintaxe

> **/Analyze**[-] [ **: WX-** ] [ **: log** *filename*] [ **: Quiet**] [ **: stacksize** *Number*] [ **: max_paths** *número*] [ **: only**] [ **:** RuleSet *RuleSet*] [ **:p** *plug-in-lugin-dll*]

## <a name="arguments"></a>Argumentos

**/analyze**\
Ativa a análise no modo padrão. A saída da análise vai para a janela de **saída** como outras mensagens de erro. Use **/Analyze-** para desativar explicitamente a análise.

**/analyze: WX-** \
Os avisos de análise de código não são tratados como erros quando você compila usando **/WX**. Para obter mais informações, consulte [/WX (nível de aviso)](compiler-option-warning-level.md).

**/analyze:** *nome de arquivo* de log\
Os resultados detalhados do analisador são gravados como XML no arquivo especificado por *filename*.

**/analyze: quiet**\
Desativa a saída do analisador na janela de **saída** .

**/analyze: stacksize** *número*\
O parâmetro *Number* que é usado com essa opção especifica o tamanho, em bytes, do quadro de pilha para o qual o aviso [C6262](/cpp/code-quality/c6262) é gerado. O espaço antes do *número* é opcional. Se esse parâmetro não for especificado, o tamanho do quadro de pilha será 16 KB por padrão.

**/analyze:** *número* de max_paths\
O parâmetro *Number* usado com essa opção especifica o número máximo de caminhos de código a serem analisados. Se esse parâmetro não for especificado, o número será 256 por padrão. Valores maiores causam uma verificação mais completa, mas a análise pode levar mais tempo.

**/analyze: somente**\
Normalmente, o compilador gera o código e faz mais verificação de sintaxe depois de executar o analisador. A opção **/analyze: only** desativa essa passagem de geração de código. Ele torna a análise mais rápida, mas erros de compilação e avisos que a passagem de geração de código do compilador podem encontrar não são emitidos. Se o programa não estiver livre de erros de geração de código, os resultados da análise poderão não ser confiáveis. Recomendamos que você use essa opção somente se o código já passar na verificação da sintaxe de geração de código sem erros.

**/analyze: ruleset** *file_path. RuleSet*\
Permite especificar quais conjuntos de regras analisar, incluindo conjuntos de regras personalizados que você pode criar por conta própria. Quando essa opção é definida, o mecanismo de regras é mais eficiente, pois ele exclui os não membros do conjunto de regras especificado antes da execução. Caso contrário, o mecanismo verificará todas as regras.

Os conjuntos de regras que acompanham o Visual Studio são encontrados em *%VSINSTALLDIR%\Team Tools\Static Analysis Tools\Rule sets.*

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

**/analyze:** plugin *plug-in-DLL*\
Habilita o plug-in PREfast especificado como parte das execuções de análise de código.

::: moniker range="<=vs-2017"

LocalEspC. dll é o plug-in que implementa verificações de análise de código relacionadas à simultaneidade no intervalo de avisos de C261XX. Por exemplo, [C26100](/cpp/code-quality/c26100), [C26101](/cpp/code-quality/c26101),..., [C26167](/cpp/code-quality/c26167).

Para executar LocalEspC. dll, use esta opção de compilador: **/analyze: plugin LocalEspC. dll**

::: moniker-end
::: moniker range=">=vs-2019"

ConcurrencyCheck. dll implementa verificações de análise de código relacionadas à simultaneidade no intervalo de avisos do C261XX. Por exemplo, [C26100](/cpp/code-quality/c26100), [C26101](/cpp/code-quality/c26101),..., [C26167](/cpp/code-quality/c26167).

Para executar ConcurrencyCheck. dll, primeiro execute este comando em um prompt de comando do desenvolvedor:

```cmd
set Esp.Extensions=ConcurrencyCheck.dll
```

Em seguida, use esta opção de compilador: **/analyze: plugin EspXEngine. dll**.

::: moniker-end

Para executar CppCoreCheck. dll, primeiro execute este comando em um prompt de comando do desenvolvedor:

```cmd
set Esp.Extensions=CppCoreCheck.dll
```

Em seguida, use esta opção de compilador: **/analyze: plugin EspXEngine. dll**.

## <a name="remarks"></a>Comentários

Para obter mais informações, consulte [análise de código paraC++ c/visão geral](/cpp/code-quality/code-analysis-for-c-cpp-overview) e [análise deC++ código para c/Warnings](/cpp/code-quality/code-analysis-for-c-cpp-warnings).

### <a name="to-set-this-compiler-option-in-the-visual-studio-development-environment"></a>Para definir esta opção do compilador no ambiente de desenvolvimento do Visual Studio

1. Abra a caixa de diálogo **Páginas de Propriedades** do projeto. Para obter detalhes, confira [Definir as propriedades de build e do compilador do C++ no Visual Studio](../working-with-project-properties.md).

1. Selecione as **Propriedades de configuração** > **análise de código** > página de propriedades **geral** .

1. Modifique uma ou mais das propriedades de **análise de código** .

### <a name="to-set-this-compiler-option-programmatically"></a>Para definir essa opção do compilador via programação

1. Consulte <xref:Microsoft.VisualStudio.VCProjectEngine.VCCLCompilerTool.EnablePREfast%2A>.

## <a name="see-also"></a>Confira também

[Opções do compilador MSVC](compiler-options.md)\
[Sintaxe da linha de comando do compilador MSVC](compiler-command-line-syntax.md)
