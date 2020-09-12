---
title: /DRIVER (driver de modo Kernel do Windows NT)
ms.date: 11/04/2016
f1_keywords:
- VC.Project.VCLinkerTool.driver
- /driver
helpviewer_keywords:
- kernel mode driver
- -DRIVER linker option
- DRIVER linker option
- /DRIVER linker option
ms.assetid: aeee8e28-5d97-40f5-ba16-9f370fe8a1b8
ms.openlocfilehash: c935c20d6c1c009cff64d48e0c0122c8b91bbba3
ms.sourcegitcommit: 6280a4c629de0f638ebc2edd446de2a9b11f0406
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/12/2020
ms.locfileid: "90041153"
---
# <a name="driver-windows-nt-kernel-mode-driver"></a>/DRIVER (driver de modo Kernel do Windows NT)

>/DRIVER [: UPSOMENTE |: WDM]

## <a name="remarks"></a>Comentários

Use a opção de vinculador **/Driver** para criar um driver de modo kernel do Windows NT.

**/Driver:** faz com que o vinculador adicione o **IMAGE_FILE_UP_SYSTEM_ONLY** bit às características no cabeçalho de saída para especificar que ele é um driver uniprocessador (up). O sistema operacional se recusará a carregar um driver ativo em um sistema de multiprocessador (MP).

**/Driver: WDM** faz com que o vinculador defina o **IMAGE_DLLCHARACTERISTICS_WDM_DRIVER** bit no campo DLLCHARACTERISTICS do cabeçalho opcional.

Se **/Driver** não for especificado, esses bits não serão definidos pelo vinculador.

Se **/Driver** for especificado:

- **/Fixed: não** está em vigor. Para obter mais informações, consulte [/Fixed (endereço base fixo)](fixed-fixed-base-address.md).

- A extensão do arquivo de saída é definida como. sys. Use **/out** para alterar o nome de arquivo e a extensão padrão. Para obter mais informações, consulte [/out (nome do arquivo de saída)](out-output-file-name.md).

### <a name="to-set-this-linker-option-in-the-visual-studio-development-environment"></a>Para definir esta opção do vinculador no ambiente de desenvolvimento do Visual Studio

1. Abra a caixa de diálogo **Páginas de Propriedades** do projeto. Para obter detalhes, confira [Definir as propriedades de build e do compilador do C++ no Visual Studio](../working-with-project-properties.md).

1. Clique na pasta **Vinculador**.

1. Clique na página de propriedades do **sistema** .

1. Modifique a propriedade do **Driver** .

### <a name="to-set-this-linker-option-programmatically"></a>Para definir esta opção do vinculador por meio de programação

- Consulte a [Propriedade VCLinkerTool. Driver](/dotnet/api/microsoft.visualstudio.vcprojectengine.vclinkertool.driver).

## <a name="see-also"></a>Confira também

[Referência de vinculador MSVC](linking.md)<br/>
[Opções do vinculador MSVC](linker-options.md)
