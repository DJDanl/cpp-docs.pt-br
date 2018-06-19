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
ms.openlocfilehash: 74d65caa8a0ea140f93bf156e3c14a85232e6e56
ms.sourcegitcommit: be2a7679c2bd80968204dee03d13ca961eaa31ff
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/03/2018
ms.locfileid: "32372250"
---
# <a name="delayload-delay-load-import"></a>/DELAYLOAD (importação de carga com atraso)
```  
/DELAYLOAD:dllname  
```  
  
## <a name="parameters"></a>Parâmetros  
 `dllname`  
 O nome de uma DLL que você deseja atrasar a carga.  
  
## <a name="remarks"></a>Comentários  
 A opção /DELAYLOAD faz com que a DLL especificada pelo `dllname` seja carregada apenas na primeira chamada pelo programa para uma função nessa DLL. Para obter mais informações, consulte [suporte de vinculador para DLLs Delay-Loaded](../../build/reference/linker-support-for-delay-loaded-dlls.md). Você pode usar essa opção quantas vezes for necessário para especificar quantas DLLs desejar. Você deve usar o Delayimp.lib quando vincular o programa ou pode implementar sua própria função auxiliar de carga com atraso.  
  
 O [/Delay](../../build/reference/delay-delay-load-import-settings.md) opção especifica a associação e carregando opções para cada DLL carregada com atraso.  
  
### <a name="to-set-this-linker-option-in-the-visual-studio-development-environment"></a>Para definir esta opção do vinculador no ambiente de desenvolvimento do Visual Studio  
  
1.  Abra a caixa de diálogo **Páginas de Propriedades** do projeto. Para obter detalhes, consulte [trabalhar com propriedades do projeto](../../ide/working-with-project-properties.md).  
  
2.  No **vinculador** pasta, selecione o **entrada** página de propriedades.  
  
3.  Modificar o **Atrasar DLLs carregadas** propriedade.  
  
### <a name="to-set-this-linker-option-programmatically"></a>Para definir esta opção do vinculador por meio de programação  
  
-   Consulte <xref:Microsoft.VisualStudio.VCProjectEngine.VCLinkerTool.DelayLoadDLLs%2A>.  
  
## <a name="see-also"></a>Consulte também  
 [Definindo opções de vinculador](../../build/reference/setting-linker-options.md)   
 [Opções do vinculador](../../build/reference/linker-options.md)