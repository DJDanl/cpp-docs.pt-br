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
ms.openlocfilehash: e64aa7b2ca9e50ebdc0760f64a9b25e851b45310
ms.sourcegitcommit: 8105b7003b89b73b4359644ff4281e1595352dda
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/14/2019
ms.locfileid: "57818122"
---
# <a name="machine-specify-target-platform"></a>/MACHINE (especificar plataforma de destino)

```
/MACHINE:{ARM|EBC|X64|X86}
```

## <a name="remarks"></a>Comentários

A opção /MACHINE Especifica a plataforma de destino para o programa.

Normalmente, você não precisa especificar a opção /MACHINE. LINK infere o tipo de máquina de arquivos. obj. No entanto, em algumas circunstâncias, o LINK não é possível determinar o tipo de máquina e problemas de um [das LNK1113 de erro das ferramentas de vinculador](../../error-messages/tool-errors/linker-tools-error-lnk1113.md). Se ocorrer um erro, especifique /MACHINE.

### <a name="to-set-this-linker-option-in-the-visual-studio-development-environment"></a>Para definir esta opção do vinculador no ambiente de desenvolvimento do Visual Studio

1. Abra a caixa de diálogo **Páginas de Propriedades** do projeto. Para obter detalhes, consulte [propriedades de compilador e de build definida C++ no Visual Studio](../working-with-project-properties.md).

1. Clique o **vinculador** pasta.

1. Clique o **avançado** página de propriedades.

1. Modificar a **computador de destino** propriedade.

### <a name="to-set-this-linker-option-programmatically"></a>Para definir esta opção do vinculador por meio de programação

1. Consulte <xref:Microsoft.VisualStudio.VCProjectEngine.VCLinkerTool.TargetMachine%2A>.

## <a name="see-also"></a>Consulte também

[Referência de vinculador MSVC](linking.md)<br/>
[Opções do vinculador MSVC](linker-options.md)
