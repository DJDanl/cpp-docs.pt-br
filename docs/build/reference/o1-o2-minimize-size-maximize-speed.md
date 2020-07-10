---
title: /O1, /O2 (minimizar tamanho, maximizar velocidade)
description: As opções do compilador MSVC/O1 e/O2 especificam todas as otimizações para tamanho mínimo ou velocidade máxima.
ms.date: 07/08/2020
f1_keywords:
- /O2
- /O1
helpviewer_keywords:
- maximize speed compiler option [C++]
- minimize size compiler option [C++]
- -O2 compiler option [C++]
- fast code
- small code
- O2 compiler option [C++]
- /O2 compiler option [C++]
- -O1 compiler option [C++]
- O1 compiler option [C++]
- /O1 compiler option [C++]
ms.assetid: 2d1423f5-53d9-44da-8908-b33a351656c2
ms.openlocfilehash: c1eda8395e604468cbb23572ec930d6171984fe4
ms.sourcegitcommit: 80c8a512b361bd84e38958beb1a1bf6db7434021
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/09/2020
ms.locfileid: "86180897"
---
# <a name="o1-o2-minimize-size-maximize-speed"></a>`/O1`, `/O2` (Tamanho minimizado, velocidade maximizada)

Seleciona um conjunto predefinido de opções que afetam o tamanho e a velocidade do código gerado.

## <a name="syntax"></a>Sintaxe

> **`/O1`**\
> **`/O2`**

## <a name="remarks"></a>Comentários

As **`/O1`** **`/O2`** Opções de compilador e são uma maneira rápida de definir várias opções de otimização específicas de uma vez. A **`/O1`** opção define as opções de otimização individuais que criam o menor código na maioria dos casos. A **`/O2`** opção define as opções que criam o código mais rápido na maioria dos casos. A **`/O2`** opção é o padrão para compilações de versão. Esta tabela mostra as opções específicas que são definidas por **`/O1`** e **`/O2`** :

| Opção | Equivalente a |
|--|--|
| **`/O1`**(Minimizar tamanho) | [`/Og`](og-global-optimizations.md) [`/Os`](os-ot-favor-small-code-favor-fast-code.md) [`/Oy`](oy-frame-pointer-omission.md) [`/Ob2`](ob-inline-function-expansion.md) [`/GF`](gf-eliminate-duplicate-strings.md) [`/Gy`](gy-enable-function-level-linking.md) |
| **`/O2`**(Maximizar velocidade) | [`/Og`](og-global-optimizations.md) [`/Oi`](oi-generate-intrinsic-functions.md) [`/Ot`](os-ot-favor-small-code-favor-fast-code.md) [`/Oy`](oy-frame-pointer-omission.md) [`/Ob2`](ob-inline-function-expansion.md) [`/GF`](gf-eliminate-duplicate-strings.md) [`/Gy`](gy-enable-function-level-linking.md) |

**`/O1`** e **`/O2`** são mutuamente exclusivos.

> [!NOTE]
> **específico do x86**\
> Essas opções implicam o uso da opção de omissão do ponteiro de quadro ( [`/Oy`](oy-frame-pointer-omission.md) ).

### <a name="to-set-this-compiler-option-in-the-visual-studio-development-environment"></a>Para definir esta opção do compilador no ambiente de desenvolvimento do Visual Studio

1. Abra a caixa de diálogo **Páginas de Propriedades** do projeto. Para obter detalhes, confira [Definir as propriedades de build e do compilador do C++ no Visual Studio](../working-with-project-properties.md).

1. Selecione a página de propriedades de otimização de **configuração**de  >  **C/C++**  >  **Optimization** .

1. Modifique a propriedade de **otimização** .

### <a name="to-set-this-compiler-option-programmatically"></a>Para definir essa opção do compilador via programação

- Consulte <xref:Microsoft.VisualStudio.VCProjectEngine.VCCLCompilerTool.Optimization%2A>.

## <a name="see-also"></a>Veja também

[`/O`opções (otimizar código)](o-options-optimize-code.md)<br/>
[Opções do compilador MSVC](compiler-options.md)<br/>
[Sintaxe da linha de comando do compilador MSVC](compiler-command-line-syntax.md)<br/>
[`/EH`(Modelo de tratamento de exceção)](eh-exception-handling-model.md)
