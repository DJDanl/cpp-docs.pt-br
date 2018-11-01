---
title: /MACHINE (especificar plataforma de destino)
ms.date: 11/04/2016
f1_keywords:
- VC.Project.VCLinkerTool.TargetMachine
- /machine
helpviewer_keywords:
- mapfiles, creating linker
- target platform
- -MACHINE linker option
- /MACHINE linker option
- MACHINE linker option
ms.assetid: 8d41bf4b-7e53-4ab9-9085-d852b08d31c2
ms.openlocfilehash: 872370269e9ab8acaaa8cafe7fb47b1121bcbb97
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50546416"
---
# <a name="machine-specify-target-platform"></a>/MACHINE (especificar plataforma de destino)

```
/MACHINE:{ARM|EBC|X64|X86}
```

## <a name="remarks"></a>Comentários

A opção /MACHINE Especifica a plataforma de destino para o programa.

Normalmente, você não precisa especificar a opção /MACHINE. LINK infere o tipo de máquina de arquivos. obj. No entanto, em algumas circunstâncias, o LINK não é possível determinar o tipo de máquina e problemas de um [das LNK1113 de erro das ferramentas de vinculador](../../error-messages/tool-errors/linker-tools-error-lnk1113.md). Se ocorrer um erro, especifique /MACHINE.

### <a name="to-set-this-linker-option-in-the-visual-studio-development-environment"></a>Para definir esta opção do vinculador no ambiente de desenvolvimento do Visual Studio

1. Abra a caixa de diálogo **Páginas de Propriedades** do projeto. Para obter detalhes, consulte [configuração de propriedades do projeto Visual C++](../../ide/working-with-project-properties.md).

1. Clique o **vinculador** pasta.

1. Clique o **avançado** página de propriedades.

1. Modificar a **computador de destino** propriedade.

### <a name="to-set-this-linker-option-programmatically"></a>Para definir esta opção do vinculador por meio de programação

1. Consulte <xref:Microsoft.VisualStudio.VCProjectEngine.VCLinkerTool.TargetMachine%2A>.

## <a name="see-also"></a>Consulte também

[Definindo opções de vinculador](../../build/reference/setting-linker-options.md)<br/>
[Opções do vinculador](../../build/reference/linker-options.md)