---
title: -DELAYLOAD (importação de carga com atraso) | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-tools
ms.topic: reference
f1_keywords:
- /delayload
- VC.Project.VCLinkerTool.DelayLoadDLLS
dev_langs:
- C++
helpviewer_keywords:
- DELAYLOAD linker option
- -DELAYLOAD linker option
- /DELAYLOAD linker option
- delayed loading of DLLs, /DELAYLOAD option
ms.assetid: 39ea0f1e-5c01-450f-9c75-2d9761ff9b28
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 509464ba78a6b7693a849d9f753b13328ab868f9
ms.sourcegitcommit: 997e6b7d336cddb388bb6e9e56527725fcaa0624
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/08/2018
ms.locfileid: "48860739"
---
# <a name="delayload-delay-load-import"></a>/DELAYLOAD (importação de carga com atraso)

> **/DELAYLOAD:**_dllname_

## <a name="parameters"></a>Parâmetros

*dllname*<br/>
O nome de uma DLL que você deseja atrasar a carga.

## <a name="remarks"></a>Comentários

A opção /DELAYLOAD faz com que a DLL especificada pelo `dllname` seja carregada apenas na primeira chamada pelo programa para uma função nessa DLL. Para obter mais informações, consulte [suporte do vinculador para DLLs Delay-Loaded](../../build/reference/linker-support-for-delay-loaded-dlls.md). Você pode usar essa opção quantas vezes for necessário para especificar quantas DLLs desejar. Você deve usar o Delayimp.lib quando vincular o programa ou pode implementar sua própria função auxiliar de carga com atraso.

O [/Delay](../../build/reference/delay-delay-load-import-settings.md) opção especifica a associação e carregamento de opções para cada DLL carregadas com atraso.

### <a name="to-set-this-linker-option-in-the-visual-studio-development-environment"></a>Para definir esta opção do vinculador no ambiente de desenvolvimento do Visual Studio

1. Abra a caixa de diálogo **Páginas de Propriedades** do projeto. Para obter detalhes, confira [Trabalhando com propriedades do projeto](../../ide/working-with-project-properties.md).

1. No **vinculador** pasta, selecione a **entrada** página de propriedades.

1. Modificar a **Atrasar DLLs carregadas** propriedade.

### <a name="to-set-this-linker-option-programmatically"></a>Para definir esta opção do vinculador por meio de programação

- Consulte <xref:Microsoft.VisualStudio.VCProjectEngine.VCLinkerTool.DelayLoadDLLs%2A>.

## <a name="see-also"></a>Consulte também

[Definindo opções de vinculador](../../build/reference/setting-linker-options.md)<br/>
[Opções do vinculador](../../build/reference/linker-options.md)
