---
title: -Analisar (análise de código) | Microsoft Docs
ms.custom: ''
ms.date: 04/26/2018
ms.technology:
- cpp-tools
ms.topic: reference
f1_keywords:
- VC.Project.VCCLCompilerTool.EnablePREfast
- /analyze
- VC.Project.VCCLCompilerTool.PREfastAdditionalOptions
- VC.Project.VCCLCompilerTool.PREfastAdditionalPlugins
dev_langs:
- C++
helpviewer_keywords:
- /analyze compiler option [C++]
- -analyze compiler option [C++]
- analyze compiler option [C++]
ms.assetid: 81da536a-e030-4bd4-be18-383927597d08
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 89f0402eedbe6e49d6ce4095dc8c91ec69e15447
ms.sourcegitcommit: 92f2fff4ce77387b57a4546de1bd4bd464fb51b6
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/17/2018
ms.locfileid: "45723600"
---
# <a name="analyze-code-analysis"></a>/analyze (Análise do código)

Habilita opções de análise e controle de código.

## <a name="syntax"></a>Sintaxe

```cmd
/analyze[-][:WX-][:log filename][:quiet][:stacksize number][:max_paths number][:only][:ruleset]
```

## <a name="arguments"></a>Arguments

/ANALYZE ativa na análise no modo padrão. Resultado da análise vai para o **saída** janela como outras mensagens de erro. Use **/ANALYZE -** desativar explicitamente a análise.

/ANALYZE: WX-especificando **/ANALYZE: WX -** significa que os avisos de análise de código não é tratadas como erros quando você compila usando **/WX**. Para obter mais informações, consulte [/w, /W0, /W1, /W2, /W3, /W4, /w1, /w2, /w3, /w4, /Wall, /wd, /we, /wo, /Wv, /WX (Nível de Aviso)](../../build/reference/compiler-option-warning-level.md).

/ANALYZE: log `filename` resultados detalhados do analisador são gravados como XML no arquivo especificado por `filename`.

/ANALYZE: quiet folheios de desativar a saída do analisador para o **saída** janela.

/ANALYZE: stacksize `number` as `number` parâmetro que é usado com essa opção especifica o tamanho, em bytes, do quadro da pilha para o qual o aviso [C6262](/visualstudio/code-quality/c6262) é gerado. Se esse parâmetro não for especificado, o tamanho do quadro da pilha será de 16 KB por padrão.

/ANALYZE: max_paths `number` o `number` parâmetro que é usado com essa opção especifica o número máximo de caminhos de código a ser analisado. Se esse parâmetro não for especificado, o número será 256 por padrão. Valores maiores executam uma verificação mais completa, mas a análise pode demorar mais.

/ANALYZE: apenas normalmente, o compilador gera o código e faz mais verificação depois de executar o analisador de sintaxe. O **/ANALYZE: apenas** opção desativa essa passagem de geração de código; isso torna a análise mais rápida, mas erros de compilação e avisos que podem ter sido identificados pela aprovação da geração de código do compilador não serão emitidos. Se o programa não estiver livre de erros de geração de código, os resultados da análise poderão não ser confiáveis; consequentemente, recomendamos que você use essa opção apenas se o código já tiver passado na verificação da sintaxe de geração de código sem erros.

/ANALYZE: ruleset `<file_path>.ruleset` permite que você especifique qual regra define para analisar, incluindo conjuntos de regras personalizados que você pode criar por conta própria. Quando essa opção estiver definida, o mecanismo de regras é mais eficiente, pois ele exclui os não membros da regra especificada definida antes da execução. Quando a opção não estiver definida, o mecanismo verifica todas as regras.

Os conjuntos de regras que são fornecidos com o Visual Studio são encontrados no **%VSINSTALLDIR%\Team Tools\Static análise Tools\Rule conjuntos.**

O conjunto de regra personalizada de exemplo a seguir informa ao mecanismo de regras para verificar se há C6001 e C26494. Você pode colocar esse arquivo em qualquer lugar desde que ele tenha um `.ruleset` extensão e fornecer o caminho completo no argumento.

```xml
<?xml version="1.0" encoding="utf-8"?>
<RuleSet Name="New Rule Set" Description=" " ToolsVersion="15.0">
  <Rules AnalyzerId="Microsoft.Analyzers.NativeCodeAnalysis" RuleNamespace="Microsoft.Rules.Native">
    <Rule Id="C6001" Action="Warning" />
    <Rule Id="C26494" Action="Warning" />
  </Rules>
</RuleSet>
```

/ANALYZE: plug-in permite que o plug-in PREfast especificado como parte da análise de código é executada.
LocalEspC.dll é o plug-in que implementa a análise de código relacionados à simultaneidade faz check-in os avisos de intervalo de C261XX. Por exemplo, [C26100](/visualstudio/code-quality/c26100), [C26101](/visualstudio/code-quality/c26101),..., [C26167](/visualstudio/code-quality/c26167).

Para executar LocalEspC.dll, use essa opção do compilador: **/ANALYZE: plug-in LocalEspC.dll**

Para executar CppCoreCheck.dll, execute este comando em um prompt de comando do desenvolvedor:

```cmd
set Esp.Extensions=CppCoreCheck.dll
```

Em seguida, usar essa opção do compilador: **/ANALYZE: plug-in EspXEngine.dll**.

## <a name="remarks"></a>Comentários

Para obter mais informações, consulte [análise de código para visão geral do C/C++](/visualstudio/code-quality/code-analysis-for-c-cpp-overview) e [análise de código para avisos do C/C++](/visualstudio/code-quality/code-analysis-for-c-cpp-warnings).

### <a name="to-set-this-compiler-option-in-the-visual-studio-development-environment"></a>Para definir esta opção do compilador no ambiente de desenvolvimento do Visual Studio

1. Abra a caixa de diálogo **Páginas de Propriedades** do projeto. Para obter detalhes, confira [Trabalhando com propriedades do projeto](../../ide/working-with-project-properties.md).

1. Expanda o nó **Propriedades de Configuração**.

1. Expanda o **análise de código** nó.

1. Selecione o **geral** página de propriedades.

1. Modificar um ou mais dos **análise de código** propriedades.

### <a name="to-set-this-compiler-option-programmatically"></a>Para definir essa opção do compilador via programação

1. Consulte <xref:Microsoft.VisualStudio.VCProjectEngine.VCCLCompilerTool.EnablePREfast%2A>.

## <a name="see-also"></a>Consulte também

- [Opções do Compilador](../../build/reference/compiler-options.md)
- [Definindo opções do compilador](../../build/reference/setting-compiler-options.md)