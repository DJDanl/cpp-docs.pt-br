---
title: -DRIVER (Driver de modo de Kernel do Windows NT) | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-tools
ms.topic: reference
f1_keywords:
- VC.Project.VCLinkerTool.driver
- /driver
dev_langs:
- C++
helpviewer_keywords:
- kernel mode driver
- -DRIVER linker option
- DRIVER linker option
- /DRIVER linker option
ms.assetid: aeee8e28-5d97-40f5-ba16-9f370fe8a1b8
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 8ae096c502cdc94d47a516caf4c29ac4f3eceb4b
ms.sourcegitcommit: 92f2fff4ce77387b57a4546de1bd4bd464fb51b6
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/17/2018
ms.locfileid: "45705543"
---
# <a name="driver-windows-nt-kernel-mode-driver"></a>/DRIVER (driver de modo Kernel do Windows NT)

>/ O DRIVER [: UPONLY |: WDM]

## <a name="remarks"></a>Comentários

Use o **/DRIVER** opção de vinculador para criar um driver de modo de kernel do Windows NT.

**/Driver: uponly** faz com que o vinculador adicionar o **image_file_up_system_only nas** bit características no cabeçalho de saída para especificar que ele é um uniprocessador (UP) do driver. O sistema operacional irá recusar carregar um driver UP em um sistema de multiprocessador (MP).

**/Driver: WDM** faz com que o vinculador defina o **IMAGE_DLLCHARACTERISTICS_WDM_DRIVER** bit no campo DllCharacteristics do cabeçalho opcional.

Se **/DRIVER** não for especificado, esses bits não são definidos pelo vinculador.

Se **/DRIVER** for especificado:

- **/Fixed: no** está em vigor. Para obter mais informações, consulte [/FIXED (Endereço Básico Fixo)](../../build/reference/fixed-fixed-base-address.md).

- A extensão do arquivo de saída é definida como. sys. Use **/out** para alterar o nome de arquivo padrão e a extensão. Para obter mais informações, consulte [/OUT (Nome do Arquivo de Saída)](../../build/reference/out-output-file-name.md).

### <a name="to-set-this-linker-option-in-the-visual-studio-development-environment"></a>Para definir esta opção do vinculador no ambiente de desenvolvimento do Visual Studio

1. Abra a caixa de diálogo **Páginas de Propriedades** do projeto. Para obter detalhes, consulte [configuração de propriedades do projeto Visual C++](../../ide/working-with-project-properties.md).

1. Clique o **vinculador** pasta.

1. Clique o **sistema** página de propriedades.

1. Modificar a **Driver** propriedade.

### <a name="to-set-this-linker-option-programmatically"></a>Para definir esta opção do vinculador por meio de programação

- Ver [VCLinkerTool.driver propriedade](https://docs.microsoft.com/dotnet/api/microsoft.visualstudio.vcprojectengine.vclinkertool.driver?view=visualstudiosdk-2017#Microsoft_VisualStudio_VCProjectEngine_VCLinkerTool_driver).

## <a name="see-also"></a>Consulte também

[Definindo opções de vinculador](../../build/reference/setting-linker-options.md)<br/>
[Opções do vinculador](../../build/reference/linker-options.md)
