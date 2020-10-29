---
title: /QIntel-jcc-erratum
description: Descreve a opção/QIntel-jcc-erratum do compilador do Microsoft C/C++ (MSVC).
ms.date: 01/07/2020
f1_keywords:
- QIntel-jcc-erratum
helpviewer_keywords:
- /QIntel-jcc-erratum
- -QIntel-jcc-erratum
ms.openlocfilehash: c66dd4bb25647ce193bce4db5dc4ebb1268277c0
ms.sourcegitcommit: 9c2b3df9b837879cd17932ae9f61cdd142078260
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/29/2020
ms.locfileid: "92921367"
---
# <a name="qintel-jcc-erratum"></a>/QIntel-jcc-erratum

::: moniker range="<=msvc-150"

A opção **/QIntel-JCC-Erratum** está disponível no Visual Studio 2019 versão 16,5 e posterior.

::: moniker-end

::: moniker range=">=msvc-160"

Especifica que o compilador gera instruções para atenuar o impacto no desempenho causado pela atualização de microcódigo da Errata do JCC (salto condicional Code) em determinados processadores Intel.

## <a name="syntax"></a>Syntax

> **/QIntel-jcc-erratum**

## <a name="remarks"></a>Comentários

Em **/QIntel-JCC-Erratum** , o compilador detecta instruções de salto com fusível de salto e de macro que cruzam ou terminam em um limite de 32 bytes. Ele alinha essas instruções ao limite. Essa alteração reduz o impacto no desempenho das atualizações de microcódigo que impedem a errata JCC em determinados processadores Intel. Para obter mais informações sobre a errata, consulte [reduções para a errata do código condicional de salto](https://www.intel.com/content/dam/support/us/en/documents/processors/mitigations-jump-conditional-code-erratum.pdf) no site da Intel.

A opção **/QIntel-JCC-Erratum** está disponível no Visual Studio 2019 versão 16,5 e posterior. Essa opção só está disponível em compiladores que se destinam a x86 e x64. A opção não está disponível em compiladores que visam processadores ARM.

A opção **/QIntel-JCC-Erratum** está desativada por padrão e funciona apenas em compilações otimizadas. Essa opção pode aumentar o tamanho do código.

**/QIntel-JCC-Erratum** é incompatível com [/CLR](clr-common-language-runtime-compilation.md).

### <a name="to-set-this-compiler-option-in-the-visual-studio-development-environment"></a>Para definir esta opção do compilador no ambiente de desenvolvimento do Visual Studio

1. Abra a caixa de diálogo **Páginas de Propriedades** do projeto. Para obter detalhes, confira [Definir as propriedades de build e do compilador do C++ no Visual Studio](../working-with-project-properties.md).

1. Selecione a página de propriedades **configuração** de > geração de código **C/C++** > **Code Generation** .

1. Selecione um valor para habilitar a propriedade de **mitigação da errata Intel JCC** . Escolha **OK** para aplicar a alteração.

### <a name="to-set-this-compiler-option-programmatically"></a>Para definir essa opção do compilador via programação

- Consulte <xref:Microsoft.VisualStudio.VCProjectEngine.VCCLCompilerTool.AdditionalOptions%2A>.

## <a name="see-also"></a>Veja também

[Opções de/q (operações de nível baixo)](q-options-low-level-operations.md)\
[Opções do compilador MSVC](compiler-options.md)\
[Sintaxe da linha de comando do compilador MSVC](compiler-command-line-syntax.md)

::: moniker-end
