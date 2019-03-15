---
title: /O1, /O2 (minimizar tamanho, maximizar velocidade)
ms.date: 09/25/2017
f1_keywords:
- /o2
- /o1
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
ms.openlocfilehash: d33fe6bceae09267fd3f79ffe3dc26864e87c764
ms.sourcegitcommit: 8105b7003b89b73b4359644ff4281e1595352dda
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/14/2019
ms.locfileid: "57820579"
---
# <a name="o1-o2-minimize-size-maximize-speed"></a>/O1, /O2 (minimizar tamanho, maximizar velocidade)

Seleciona um conjunto predefinido de opções que afetam o tamanho e velocidade do código gerado.

## <a name="syntax"></a>Sintaxe

> /O1 /O2

## <a name="remarks"></a>Comentários

O **/O1** e **/O2** opções do compilador são uma maneira rápida para definir várias opções de otimização específicas ao mesmo tempo. O **/O1** opção define as opções de otimização individuais que criam o código menor na maioria dos casos. O **/O2** opção define as opções que criam o código mais rápido na maioria dos casos. O **/O2** é a opção padrão para builds de versão. Esta tabela mostra as opções específicas que são definidas por **/O1** e **/O2**:

|Opção|Equivalente a|
|------------|-------------------|
|**/ O1** (minimizar tamanho)|[/Og](og-global-optimizations.md) [/Os](os-ot-favor-small-code-favor-fast-code.md) [/Oy](oy-frame-pointer-omission.md) [/Ob2](ob-inline-function-expansion.md) [/GF](gf-eliminate-duplicate-strings.md) [/Gy](gy-enable-function-level-linking.md)|
|**/ O2** (maximizar velocidade)|[/Og](og-global-optimizations.md) [/Oi](oi-generate-intrinsic-functions.md) [/Ot](os-ot-favor-small-code-favor-fast-code.md) [/Oy](oy-frame-pointer-omission.md) [/Ob2](ob-inline-function-expansion.md) [/GF](gf-eliminate-duplicate-strings.md) [/Gy](gy-enable-function-level-linking.md)|

**/ O1** e **/O2** são mutuamente exclusivos.

> [!NOTE]
> **x86 específico** essas opções implicam o uso da omissão de ponteiro de quadro ([/Oy](oy-frame-pointer-omission.md)) opção.

### <a name="to-set-this-compiler-option-in-the-visual-studio-development-environment"></a>Para definir esta opção do compilador no ambiente de desenvolvimento do Visual Studio

1. Abra a caixa de diálogo **Páginas de Propriedades** do projeto. Para obter detalhes, consulte [propriedades de compilador e de build definida C++ no Visual Studio](../working-with-project-properties.md).

1. Sob **propriedades de configuração**, abra **C/C++** e, em seguida, escolha o **otimização** página de propriedades.

1. Modificar a **otimização** propriedade.

### <a name="to-set-this-compiler-option-programmatically"></a>Para definir essa opção do compilador via programação

- Consulte <xref:Microsoft.VisualStudio.VCProjectEngine.VCCLCompilerTool.Optimization%2A>.

## <a name="see-also"></a>Consulte também

[Opções /O (otimizar código)](o-options-optimize-code.md)<br/>
[Opções do compilador MSVC](compiler-options.md)<br/>
[Sintaxe de linha de comando do compilador MSVC](compiler-command-line-syntax.md)<br/>
[/EH (modelo de tratamento de exceções)](eh-exception-handling-model.md)
