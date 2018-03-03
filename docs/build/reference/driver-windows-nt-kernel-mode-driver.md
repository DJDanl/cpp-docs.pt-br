---
title: -DRIVER (Driver de modo de Kernel do Windows NT) | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-tools
ms.tgt_pltfrm: 
ms.topic: article
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
caps.latest.revision: 
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: 29234e3c0e368c7710f9071c753422bc4e6ef2b5
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="driver-windows-nt-kernel-mode-driver"></a>/DRIVER (driver de modo Kernel do Windows NT)

>/ O DRIVER [: UPONLY |: WDM]

## <a name="remarks"></a>Comentários

Use o **/DRIVER** opção de vinculador para criar um driver de modo de kernel do Windows NT.

**/Driver: uponly** faz com que o vinculador adicionar o **IMAGE_FILE_UP_SYSTEM_ONLY** bit nas características no cabeçalho de saída para especificar que ele é um uniprocessador (UP) do driver. O sistema operacional irá recusar carregar um driver UP em um sistema de multiprocessador (MP).

**/Driver: WDM** faz com que o vinculador definir o **IMAGE_DLLCHARACTERISTICS_WDM_DRIVER** bit no campo de DllCharacteristics do cabeçalho opcional.

Se **/DRIVER** não for especificado, esses bits não são definidos pelo vinculador.

Se **/DRIVER** for especificado:

- **/Fixed:** está em vigor. Para obter mais informações, consulte [/FIXED (Endereço Básico Fixo)](../../build/reference/fixed-fixed-base-address.md).

- A extensão do arquivo de saída é definida como sys. Use **/out** para alterar o nome de arquivo padrão e a extensão. Para obter mais informações, consulte [/OUT (Nome do Arquivo de Saída)](../../build/reference/out-output-file-name.md).

### <a name="to-set-this-linker-option-in-the-visual-studio-development-environment"></a>Para definir esta opção do vinculador no ambiente de desenvolvimento do Visual Studio

1. Abra a caixa de diálogo **Páginas de Propriedades** do projeto. Para obter detalhes, consulte [configuração Visual C++ Project Properties](../../ide/working-with-project-properties.md).

1. Clique o **vinculador** pasta.

1. Clique o **sistema** página de propriedades.

1. Modificar o **Driver** propriedade.

### <a name="to-set-this-linker-option-programmatically"></a>Para definir esta opção do vinculador por meio de programação

- Consulte [VCLinkerTool.driver propriedade](https://docs.microsoft.com/dotnet/api/microsoft.visualstudio.vcprojectengine.vclinkertool.driver?view=visualstudiosdk-2017#Microsoft_VisualStudio_VCProjectEngine_VCLinkerTool_driver).

## <a name="see-also"></a>Consulte também

[Definindo opções de vinculador](../../build/reference/setting-linker-options.md)   
[Opções do vinculador](../../build/reference/linker-options.md)
