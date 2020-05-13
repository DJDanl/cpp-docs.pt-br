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
ms.openlocfilehash: 3daf5dd5f9912194fd5d8aaeb4c7a312be142b69
ms.sourcegitcommit: 6b749db14b4cf3a2b8d581fda6fdd8cb98bc3207
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/05/2020
ms.locfileid: "82825333"
---
# <a name="o1-o2-minimize-size-maximize-speed"></a>/O1, /O2 (minimizar tamanho, maximizar velocidade)

Seleciona um conjunto predefinido de opções que afetam o tamanho e a velocidade do código gerado.

## <a name="syntax"></a>Sintaxe

> O1
> /O2

## <a name="remarks"></a>Comentários

As opções de compilador **/O1** e **/O2** são uma maneira rápida de definir várias opções de otimização específicas de uma vez. A opção **/O1** define as opções de otimização individuais que criam o menor código na maioria dos casos. A opção **/O2** define as opções que criam o código mais rápido na maioria dos casos. A opção **/O2** é o padrão para compilações de versão. Esta tabela mostra as opções específicas que são definidas por **/O1** e **/O2**:

|Opção|Equivalente a|
|------------|-------------------|
|**/O1** (tamanho minimizado)|[/Og](og-global-optimizations.md) [/os](os-ot-favor-small-code-favor-fast-code.md) [/Oy](oy-frame-pointer-omission.md) [/Ob2](ob-inline-function-expansion.md) [/GF](gf-eliminate-duplicate-strings.md) [/GY](gy-enable-function-level-linking.md)|
|**/O2** (maximizar velocidade)|[/Og](og-global-optimizations.md) [/Oi](oi-generate-intrinsic-functions.md) [/OT](os-ot-favor-small-code-favor-fast-code.md) [/Oy](oy-frame-pointer-omission.md) [/Ob2](ob-inline-function-expansion.md) [/GF](gf-eliminate-duplicate-strings.md) [/GY](gy-enable-function-level-linking.md)|

**/O1** e **/O2** são mutuamente exclusivos.

> [!NOTE]
> **Específico do x86**\
> Essas opções implicam o uso da opção[/Oy](oy-frame-pointer-omission.md)(omissão de ponteiro de quadro).

### <a name="to-set-this-compiler-option-in-the-visual-studio-development-environment"></a>Para definir esta opção do compilador no ambiente de desenvolvimento do Visual Studio

1. Abra a caixa de diálogo **Páginas de Propriedades** do projeto. Para obter detalhes, confira [Definir as propriedades de build e do compilador do C++ no Visual Studio](../working-with-project-properties.md).

1. Em **Propriedades de configuração**, abra **C/C++** e, em seguida, escolha a página de propriedades **otimização** .

1. Modifique a propriedade de **otimização** .

### <a name="to-set-this-compiler-option-programmatically"></a>Para definir essa opção do compilador via programação

- Consulte <xref:Microsoft.VisualStudio.VCProjectEngine.VCCLCompilerTool.Optimization%2A>.

## <a name="see-also"></a>Confira também

[Opções/o (otimizar código)](o-options-optimize-code.md)<br/>
[Opções do compilador MSVC](compiler-options.md)<br/>
[Sintaxe da linha de comando do compilador MSVC](compiler-command-line-syntax.md)<br/>
[/EH (modelo de tratamento de exceções)](eh-exception-handling-model.md)
