---
title: /Qsafe_fp_loads
ms.date: 01/24/2018
ms.openlocfilehash: 57aece79dfab617121371e0489aa80f18e143372
ms.sourcegitcommit: faa42c8a051e746d99dcebe70fd4bbaf3b023ace
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/15/2019
ms.locfileid: "57819683"
---
# <a name="qsafefploads"></a>/Qsafe_fp_loads

Requer instruções de movimento de inteiro para valores de ponto flutuante e desabilita determinadas otimizações de carregamento de ponto flutuante.

## <a name="syntax"></a>Sintaxe

> **/Qsafe_fp_loads**

## <a name="remarks"></a>Comentários

**/Qsafe_fp_loads** só está disponível nos compiladores que direcionam o x86; ele não está disponível nos compiladores que direcionam x64 ou ARM.

**/Qsafe_fp_loads** registra do força o compilador a usar instruções de movimento de inteiro em vez de instruções de ponto flutuante de movimentação para mover dados entre a memória e MMX. Essa opção também desabilita a otimização de carregamento de registro para os valores de ponto flutuantes que pode ser carregado em vários caminhos de controle quando o valor pode causar uma exceção no carregamento — por exemplo, um valor NaN.

Essa opção é substituída por [/fp: except](fp-specify-floating-point-behavior.md). **/Qsafe_fp_loads** Especifica um subconjunto do comportamento do compilador que é especificado pela **/fp: except**.

**/Qsafe_fp_loads** é incompatível com [/clr](clr-common-language-runtime-compilation.md) e [Fast](fp-specify-floating-point-behavior.md). Para obter mais informações sobre as opções de compilador de ponto flutuante, consulte [/fp (Especificar comportamento de ponto flutuante)](fp-specify-floating-point-behavior.md).

### <a name="to-set-this-compiler-option-in-the-visual-studio-development-environment"></a>Para definir esta opção do compilador no ambiente de desenvolvimento do Visual Studio

1. Abra a caixa de diálogo **Páginas de Propriedades** do projeto. Para obter detalhes, consulte [propriedades de compilador e de build definida C++ no Visual Studio](../working-with-project-properties.md).

1. Selecione o **propriedades de configuração** > **C/C++** > **linha de comando** página de propriedades.

1. Insira a opção de compilador na **opções adicionais** caixa. Escolher **Okey** para aplicar a alteração.

### <a name="to-set-this-compiler-option-programmatically"></a>Para definir essa opção do compilador via programação

- Consulte <xref:Microsoft.VisualStudio.VCProjectEngine.VCCLCompilerTool.AdditionalOptions%2A>.

## <a name="see-also"></a>Consulte também

[Opções /Q (operações de nível baixo)](q-options-low-level-operations.md)<br/>
[Opções do compilador MSVC](compiler-options.md)<br/>
[Sintaxe de linha de comando do compilador MSVC](compiler-command-line-syntax.md)
