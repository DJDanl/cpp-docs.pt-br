---
title: /arch (ARM)
ms.date: 11/04/2016
ms.assetid: 4f1406ff-f174-487c-a126-8ab06cf447c1
ms.openlocfilehash: bf12abd140a56b1b914156083ecbbd3e61e7285a
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50495543"
---
# <a name="arch-arm"></a>/arch (ARM)

Especifica a arquitetura para a geração de código no ARM. Consulte também [/arch (x86)](../../build/reference/arch-x86.md) e [/arch (x64)](../../build/reference/arch-x64.md).

## <a name="syntax"></a>Sintaxe

```
/arch:[ARMv7VE|VFPv4]
```

## <a name="arguments"></a>Arguments

**arch:armv7ve**<br/>
Habilita o uso de instruções de Extensões de Virtualização ARMv7VE.

**/arch:VFPv4**<br/>
Habilita o uso de instruções ARM VFPv4. Se essa opção não for especificada, VFPv3 é o padrão.

## <a name="remarks"></a>Comentários

O `_M_ARM_FP` macro (para ARM) indica que, se houver, **/arch** opção de compilador foi usada. Para obter mais informações, consulte [Macros predefinidas](../../preprocessor/predefined-macros.md).

Quando você usa [/clr](../../build/reference/clr-common-language-runtime-compilation.md) para compilar, **/arch** não tem efeito sobre a geração de código para funções gerenciadas. **/arch** somente afeta geração de código para funções nativas.

### <a name="to-set-the-archarmv7ve-or-archvfpv4-compiler-option-in-visual-studio"></a>Para definir a opção do compilador /arch:ARMv7VE ou /arch:VFPv4 no Visual Studio

1. Abra o **páginas de propriedade** caixa de diálogo para o projeto. Para obter mais informações, confira [Trabalhando com propriedades do projeto](../../ide/working-with-project-properties.md).

1. Selecione o **C/C++** pasta.

1. Selecione o **linha de comando** página de propriedades.

1. No **opções adicionais** caixa, adicione `/arch:ARMv7VE` ou `/arch:VFPv4`.

### <a name="to-set-this-compiler-option-programmatically"></a>Para definir essa opção do compilador via programação

- Consulte <xref:Microsoft.VisualStudio.VCProjectEngine.VCCLCompilerTool.EnableEnhancedInstructionSet%2A>.

## <a name="see-also"></a>Consulte também

[/arch (arquitetura mínima de CPU)](../../build/reference/arch-minimum-cpu-architecture.md)<br/>
[Opções do Compilador](../../build/reference/compiler-options.md)<br/>
[Definindo opções do compilador](../../build/reference/setting-compiler-options.md)