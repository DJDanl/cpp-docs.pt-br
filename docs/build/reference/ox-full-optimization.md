---
title: /Ox (habilitar a maioria das otimizações de velocidade)
description: A opção MSVC/Ox combina algumas das opções de otimização do compilador para a velocidade em uma única opção.
ms.date: 07/08/2020
f1_keywords:
- VC.Project.VCCLCompilerTool.ToolOptimization
- /Ox
- /Oxs
helpviewer_keywords:
- Ox compiler option [C++]
- fast code [C++]
- /Ox compiler option [C++]
- -Ox compiler option [C++]
ms.assetid: 3ad7c30b-c615-428c-b1d0-2e024f81c760
ms.openlocfilehash: 10893fe1cf032f2ab56f27aa4af95b050c2ec37e
ms.sourcegitcommit: 80c8a512b361bd84e38958beb1a1bf6db7434021
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/09/2020
ms.locfileid: "86180832"
---
# <a name="ox-enable-most-speed-optimizations"></a>`/Ox`(Habilitar a maioria das otimizações de velocidade)

A **`/Ox`** opção do compilador permite uma combinação de otimizações que favorecem a velocidade. Em algumas versões do IDE do Visual Studio e da mensagem de ajuda do compilador, ela é chamada de *otimização completa*, mas a **`/Ox`** opção do compilador permite apenas um subconjunto das opções de otimização de velocidade habilitadas pelo **`/O2`** .

## <a name="syntax"></a>Sintaxe

> **`/Ox`**

## <a name="remarks"></a>Comentários

A **`/Ox`** opção do compilador habilita as **`/O`** Opções do compilador que favorecem a velocidade. A **`/Ox`** opção do compilador não inclui as opções adicional [ `/GF` (eliminar cadeias de caracteres duplicadas)](gf-eliminate-duplicate-strings.md) e [ `/Gy` (habilitar vinculação no nível de função)](gy-enable-function-level-linking.md) habilitadas pelo [ `/O1` ou `/O2` (Minimizar tamanho, maximizar velocidade)](o1-o2-minimize-size-maximize-speed.md). As opções adicionais aplicadas pelo **`/O1`** e **`/O2`** podem causar ponteiros para cadeias de caracteres ou funções para compartilhar um endereço de destino, o que pode afetar a depuração e a conformidade do idioma estrito. A **`/Ox`** opção é uma maneira fácil de habilitar a maioria das otimizações sem incluir **`/GF`** e **`/Gy`** . Para obter mais informações, consulte as descrições das [`/GF`](gf-eliminate-duplicate-strings.md) [`/Gy`](gy-enable-function-level-linking.md) Opções e.

A **`/Ox`** opção do compilador é a mesma que usar as seguintes opções em combinação:

- [ `/Ob` (Expansão de função embutida)](ob-inline-function-expansion.md), em que o parâmetro Option é 2 ( **`/Ob2`** )

- [`/Oi`(Gerar funções intrínsecas)](oi-generate-intrinsic-functions.md)

- [`/Ot`(Favorecer código rápido)](os-ot-favor-small-code-favor-fast-code.md)

- [`/Oy`(Omissão de ponteiros de quadros)](oy-frame-pointer-omission.md)

**`/Ox`** é mutuamente exclusivo de:

- [`/O1`(Minimizar tamanho)](o1-o2-minimize-size-maximize-speed.md)

- [`/O2`(Maximizar velocidade)](o1-o2-minimize-size-maximize-speed.md)

- [`/Od`(Desabilitar (Depurar))](od-disable-debug.md)

Você pode cancelar o Bias em direção à velocidade da **`/Ox`** opção do compilador se especificar **`/Oxs`** , que combina a **`/Ox`** opção do compilador com [ `/Os` (favorecer código pequeno)](os-ot-favor-small-code-favor-fast-code.md). As opções combinadas favorecem o tamanho de código menor.  A **`/Oxs`** opção é exatamente a mesma que especificar **`/Ox`** **`/Os`** quando as opções aparecem nessa ordem.

Para aplicar todas as otimizações de nível de arquivo disponíveis para compilações de versão, recomendamos especificar [ `/O2` (maximizar velocidade)](o1-o2-minimize-size-maximize-speed.md) em vez de e **`/Ox`** [ `/O1` (Minimizar tamanho)](o1-o2-minimize-size-maximize-speed.md) em vez de **`/Oxs`** . Para obter ainda mais otimização nas compilações de versão, considere também a opção de compilador [ `/GL` (otimização do programa inteiro)](gl-whole-program-optimization.md) e a opção de vinculador [ `/LTCG` (geração de código de tempo de vinculação)](ltcg-link-time-code-generation.md) .

### <a name="to-set-this-compiler-option-in-the-visual-studio-development-environment"></a>Para definir esta opção do compilador no ambiente de desenvolvimento do Visual Studio

1. Abra a caixa de diálogo **Páginas de Propriedades** do projeto. Para obter detalhes, confira [Definir as propriedades de build e do compilador do C++ no Visual Studio](../working-with-project-properties.md).

1. Selecione a página de propriedades de otimização de **configuração**de  >  **C/C++**  >  **Optimization** .

1. Modifique a propriedade de **otimização** .

### <a name="to-set-this-compiler-option-programmatically"></a>Para definir essa opção do compilador via programação

- Consulte <xref:Microsoft.VisualStudio.VCProjectEngine.VCCLCompilerTool.Optimization%2A>.

## <a name="see-also"></a>Veja também

[`/O`Opções (otimizar código)](o-options-optimize-code.md)<br/>
[Opções do compilador MSVC](compiler-options.md)<br/>
[Sintaxe de linha de comando do compilador MSVC](compiler-command-line-syntax.md)
