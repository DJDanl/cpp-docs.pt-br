---
title: /analyze (análise do código)
description: A sintaxe e o uso da opção/Analyze do compilador do Microsoft C++.
ms.date: 07/27/2020
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
ms.openlocfilehash: dcf44f1d282a9dd39205aecb4e75b59a6e8481f9
ms.sourcegitcommit: 9c2b3df9b837879cd17932ae9f61cdd142078260
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/29/2020
ms.locfileid: "92919092"
---
# <a name="analyze-code-analysis"></a>`/analyze` (Análise de código)

Habilita opções de análise e controle de código.

## <a name="syntax"></a>Syntax

::: moniker range=">=msvc-150"

> **`/analyze`**\
> **`/analyze-`**\
> **`/analyze:autolog`**\
> **`/analyze:autolog-`**\
> **`/analyze:autolog:ext`***extensão* do\
> **`/analyze:log`***nome do arquivo*\
> **`/analyze:max_paths`***número* de\
> **`/analyze:only`**\
> **`/analyze:plugin`***plug-in-DLL*\
> **`/analyze:quiet`**\
> **`/analyze:ruleset`** conjunto de *regras*\
> **`/analyze:stacksize`***número* de\
> **`/analyze:WX-`**

::: moniker-end
::: moniker range="msvc-140"

> **`/analyze`**\
> **`/analyze-`**\
> **`/analyze:autolog`**\
> **`/analyze:autolog-`**\
> **`/analyze:autolog:ext`***extensão* do\
> **`/analyze:log`***nome do arquivo*\
> **`/analyze:max_paths`***número* de\
> **`/analyze:only`**\
> **`/analyze:plugin`***plug-in-DLL*\
> **`/analyze:quiet`**\
> **`/analyze:stacksize`***número* de\
> **`/analyze:WX-`**

::: moniker-end

## <a name="arguments"></a>Argumentos

**`/analyze`**\
Ativa a análise no modo padrão. A saída da análise vai para o console ou para a janela de **saída** do Visual Studio, como outras mensagens de erro. Use **`/analyze-`** para desativar explicitamente a análise.

**`/analyze:autolog`**\
Os resultados detalhados do analisador são gravados como XML em um arquivo com o mesmo nome base do arquivo de origem e uma extensão do *`.pftlog`* . **`/analyze:autolog-`** desabilita esse arquivo de log.

**`/analyze:autolog:ext`***extensão* do\
Os resultados detalhados do analisador são gravados como XML em um arquivo com o mesmo nome base do arquivo de origem e uma extensão da *extensão* .

**`/analyze:log`***nome do arquivo*\
Os resultados detalhados do analisador são gravados como XML no arquivo especificado por *filename* .

**`/analyze:max_paths`***número* de\
O parâmetro *Number* usado com essa opção especifica o número máximo de caminhos de código a serem analisados. Se esse parâmetro não for especificado, o número será 256 por padrão. Valores maiores causam uma verificação mais completa, mas a análise pode levar mais tempo.

**`/analyze:only`**\
Normalmente, o compilador gera o código e faz mais verificação de sintaxe depois de executar o analisador. A **`/analyze:only`** opção desativa esse passo de geração de código. Ele torna a análise mais rápida, mas não emite erros de compilador e avisos que a passagem de geração de código do compilador pode encontrar. Se o programa não estiver livre de erros de geração de código, os resultados da análise poderão não ser confiáveis. Recomendamos que você use essa opção somente se o código já passar na verificação da sintaxe de geração de código sem erros.

**`/analyze:plugin`***plug-in-DLL*\
Habilita o plug-in PREfast especificado como parte das execuções de análise de código.

::: moniker range="<=msvc-150"

LocalEspC.dll é o plug-in que implementa verificações de análise de código relacionadas à simultaneidade no intervalo de avisos C261XX. Por exemplo, [C26100](../../code-quality/c26100.md), [C26101](../../code-quality/c26101.md),...,  [C26167](../../code-quality/c26167.md).

Para executar LocalEspC.dll, use esta opção de compilador: **`/analyze:plugin LocalEspC.dll`**

::: moniker-end
::: moniker range=">=msvc-160"

ConcurrencyCheck.dll implementa verificações de análise de código relacionadas à simultaneidade no intervalo de avisos C261XX. Por exemplo, [C26100](../../code-quality/c26100.md), [C26101](../../code-quality/c26101.md),...,  [C26167](../../code-quality/c26167.md).

Para executar ConcurrencyCheck.dll, primeiro execute este comando em um prompt de comando do desenvolvedor:

```cmd
set Esp.Extensions=ConcurrencyCheck.dll
```

Em seguida, use esta opção de compilador: **`/analyze:plugin EspXEngine.dll`** .

Para executar CppCoreCheck.dll, primeiro execute este comando em um prompt de comando do desenvolvedor:

```cmd
set Esp.Extensions=CppCoreCheck.dll
```

Em seguida, use esta opção de compilador: **`/analyze:plugin EspXEngine.dll`** .

::: moniker-end

**`/analyze:quiet`**\
Desativa a saída do analisador no console ou na janela de **saída** do Visual Studio.

::: moniker range=">=msvc-150"

**`/analyze:ruleset`***file_path. RuleSet*\
Permite especificar quais conjuntos de regras analisar, incluindo conjuntos de regras personalizados que você pode criar por conta própria. Quando essa opção é definida, o mecanismo de regras é mais eficiente, pois ele exclui os não membros do conjunto de regras especificado antes da execução. Caso contrário, o mecanismo verificará todas as regras.

Os conjuntos de regras que acompanham o Visual Studio são encontrados em *`%VSINSTALLDIR%\Team Tools\Static Analysis Tools\Rule Sets`* .

O conjunto de regras personalizadas de exemplo a seguir informa ao mecanismo de regras para verificar C6001 e C26494. Você pode posicionar esse arquivo em qualquer lugar, desde que ele tenha uma *`.ruleset`* extensão e forneça o caminho completo no argumento.

```xml
<?xml version="1.0" encoding="utf-8"?>
<RuleSet Name="New Rule Set" Description="New rules to apply." ToolsVersion="15.0">
  <Rules AnalyzerId="Microsoft.Analyzers.NativeCodeAnalysis" RuleNamespace="Microsoft.Rules.Native">
    <Rule Id="C6001" Action="Warning" />
    <Rule Id="C26494" Action="Warning" />
  </Rules>
</RuleSet>
```

::: moniker-end

**`/analyze:stacksize`***número* de\
O parâmetro *Number* que é usado com essa opção especifica o tamanho, em bytes, do quadro de pilha para o qual o aviso [C6262](../../code-quality/c6262.md) é gerado. O espaço antes do *número* é opcional. Se esse parâmetro não for especificado, o tamanho do quadro de pilha será 16 KB por padrão.

**`/analyze:WX-`**\
Os avisos de análise de código não são tratados como erros quando você compila usando o **`/WX`** . Para obter mais informações, consulte [ `/WX` (nível de aviso)](compiler-option-warning-level.md).

## <a name="remarks"></a>Comentários

Para obter mais informações, consulte [análise de código para visão geral de c/C++](../../code-quality/code-analysis-for-c-cpp-overview.md) e [análise de código para avisos de C/c++](../../code-quality/code-analysis-for-c-cpp-warnings.md).

### <a name="to-set-this-compiler-option-in-the-visual-studio-development-environment"></a>Para definir esta opção do compilador no ambiente de desenvolvimento do Visual Studio

1. Abra a caixa de diálogo **Páginas de Propriedades** do projeto. Para obter detalhes, confira [Definir as propriedades de build e do compilador do C++ no Visual Studio](../working-with-project-properties.md).

1. Selecione a **Configuration Properties**  >  página de propriedades geral análise de **código** de propriedades de configuração  >  **General** .

1. Modifique uma ou mais das propriedades de **análise de código** .

### <a name="to-set-this-compiler-option-programmatically"></a>Para definir essa opção do compilador via programação

1. Consulte <xref:Microsoft.VisualStudio.VCProjectEngine.VCCLCompilerTool.EnablePREfast%2A>.

## <a name="see-also"></a>Veja também

[Opções do compilador MSVC](compiler-options.md)\
[Sintaxe de Command-Line do compilador MSVC](compiler-command-line-syntax.md)
