---
title: /QIntel-jcc-erratum
description: Descreve a opção/QIntel-jcc-erratum doC++ Microsoft C/Compiler (MSVC).
ms.date: 01/07/2020
f1_keywords:
- QIntel-jcc-erratum
helpviewer_keywords:
- /QIntel-jcc-erratum
- -QIntel-jcc-erratum
ms.openlocfilehash: f311da04b833b06124c5e6237ea83a31319858ca
ms.sourcegitcommit: a930a9b47bd95599265d6ba83bb87e46ae748949
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 01/22/2020
ms.locfileid: "76520875"
---
# <a name="qintel-jcc-erratum"></a>/QIntel-jcc-erratum

::: moniker range="<=vs-2017"

A opção **/QIntel-JCC-Erratum** está disponível no Visual Studio 2019 versão 16,5 e posterior.

::: moniker-end

::: moniker range=">=vs-2019"

Especifica que o compilador gera instruções para atenuar o impacto no desempenho causado pela atualização de microcódigo da Errata do JCC (salto condicional Code) em determinados processadores Intel.

## <a name="syntax"></a>Sintaxe

> **/QIntel-jcc-erratum**

## <a name="remarks"></a>Comentários

Em **/QIntel-JCC-Erratum**, o compilador detecta instruções de salto com fusível de salto e de macro que cruzam ou terminam em um limite de 32 bytes. Ele alinha essas instruções ao limite. Essa alteração reduz o impacto no desempenho das atualizações de microcódigo que impedem a errata JCC em determinados processadores Intel. Para obter mais informações sobre a errata, consulte [reduções para a errata do código condicional de salto](https://www.intel.com/content/dam/support/us/en/documents/processors/mitigations-jump-conditional-code-erratum.pdf) no site da Intel.

A opção **/QIntel-JCC-Erratum** está disponível no Visual Studio 2019 versão 16,5 e posterior. Essa opção só está disponível em compiladores que se destinam a x86 e x64. A opção não está disponível em compiladores que visam processadores ARM.

A opção **/QIntel-JCC-Erratum** está desativada por padrão e funciona apenas em compilações otimizadas. Essa opção pode aumentar o tamanho do código.

**/QIntel-JCC-Erratum** é incompatível com [/CLR](clr-common-language-runtime-compilation.md).

### <a name="to-set-this-compiler-option-in-the-visual-studio-development-environment"></a>Para definir esta opção do compilador no ambiente de desenvolvimento do Visual Studio

1. Abra a caixa de diálogo **Páginas de Propriedades** do projeto. Para obter detalhes, confira [Definir as propriedades de build e do compilador do C++ no Visual Studio](../working-with-project-properties.md).

1. Selecione as **Propriedades de configuração** > página de propriedades de **geração de código** **C/C++**  >.

1. Selecione um valor para habilitar a propriedade de **mitigação da errata Intel JCC** . Escolha **OK** para aplicar a alteração.

### <a name="to-set-this-compiler-option-programmatically"></a>Para definir essa opção do compilador via programação

- Consulte <xref:Microsoft.VisualStudio.VCProjectEngine.VCCLCompilerTool.AdditionalOptions%2A>.

## <a name="see-also"></a>Veja também

[Opções de/q (operações de nível baixo)](q-options-low-level-operations.md)\
[Opções do compilador MSVC](compiler-options.md)\
[Sintaxe de linha de comando do compilador MSVC](compiler-command-line-syntax.md)

::: moniker-end
