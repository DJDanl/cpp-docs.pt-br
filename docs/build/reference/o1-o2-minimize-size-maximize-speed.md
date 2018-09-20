---
title: -O1, - O2 (minimizar tamanho, maximizar velocidade) | Microsoft Docs
ms.custom: ''
ms.date: 09/25/2017
ms.technology:
- cpp-tools
ms.topic: reference
f1_keywords:
- /o2
- /o1
dev_langs:
- C++
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
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 24e57be50c2138cb9e772f6e6a2527300c9296ea
ms.sourcegitcommit: 799f9b976623a375203ad8b2ad5147bd6a2212f0
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/19/2018
ms.locfileid: "46446472"
---
# <a name="o1-o2-minimize-size-maximize-speed"></a>/O1, /O2 (minimizar tamanho, maximizar velocidade)

Seleciona um conjunto predefinido de opções que afetam o tamanho e velocidade do código gerado.

## <a name="syntax"></a>Sintaxe

> / / O1 O2

## <a name="remarks"></a>Comentários

O **/O1** e **/O2** opções do compilador são uma maneira rápida para definir várias opções de otimização específicas ao mesmo tempo. O **/O1** opção define as opções de otimização individuais que criam o código menor na maioria dos casos. O **/O2** opção define as opções que criam o código mais rápido na maioria dos casos. O **/O2** é a opção padrão para builds de versão. Esta tabela mostra as opções específicas que são definidas por **/O1** e **/O2**:

|Opção|Equivalente a|
|------------|-------------------|
|**/ O1** (minimizar tamanho)|[/Og](../../build/reference/og-global-optimizations.md) [/Os](../../build/reference/os-ot-favor-small-code-favor-fast-code.md) [/Oy](../../build/reference/oy-frame-pointer-omission.md) [/Ob2](../../build/reference/ob-inline-function-expansion.md) [/GF](../../build/reference/gf-eliminate-duplicate-strings.md) [/Gy](../../build/reference/gy-enable-function-level-linking.md)|
|**/ O2** (maximizar velocidade)|[/Og](../../build/reference/og-global-optimizations.md) [/Oi](../../build/reference/oi-generate-intrinsic-functions.md) [/Ot](../../build/reference/os-ot-favor-small-code-favor-fast-code.md) [/Oy](../../build/reference/oy-frame-pointer-omission.md) [/Ob2](../../build/reference/ob-inline-function-expansion.md) [/GF](../../build/reference/gf-eliminate-duplicate-strings.md) [/Gy](../../build/reference/gy-enable-function-level-linking.md)|

**/ O1** e **/O2** são mutuamente exclusivos.

> [!NOTE]
> **x86 específico** essas opções implicam o uso da omissão de ponteiro de quadro ([/Oy](../../build/reference/oy-frame-pointer-omission.md)) opção.

### <a name="to-set-this-compiler-option-in-the-visual-studio-development-environment"></a>Para definir esta opção do compilador no ambiente de desenvolvimento do Visual Studio

1. Abra a caixa de diálogo **Páginas de Propriedades** do projeto. Para obter detalhes, confira [Trabalhando com propriedades do projeto](../../ide/working-with-project-properties.md).

1. Sob **propriedades de configuração**, abra **C/C++** e, em seguida, escolha o **otimização** página de propriedades.

1. Modificar a **otimização** propriedade.

### <a name="to-set-this-compiler-option-programmatically"></a>Para definir essa opção do compilador via programação

- Consulte <xref:Microsoft.VisualStudio.VCProjectEngine.VCCLCompilerTool.Optimization%2A>.

## <a name="see-also"></a>Consulte também

[Opções /O (otimizar código)](../../build/reference/o-options-optimize-code.md)<br/>
[Opções do Compilador](../../build/reference/compiler-options.md)<br/>
[Definindo opções do compilador](../../build/reference/setting-compiler-options.md)<br/>
[/EH (modelo de tratamento de exceções)](../../build/reference/eh-exception-handling-model.md)
