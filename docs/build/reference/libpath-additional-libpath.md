---
title: -LIBPATH (Libpath adicional) | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-tools
ms.topic: reference
f1_keywords:
- /libpath
- VC.Project.VCLinkerTool.AdditionalLibraryDirectories
dev_langs:
- C++
helpviewer_keywords:
- LIBPATH linker option
- /LIBPATH linker option
- Additional Libpath linker option
- environment library path override
- -LIBPATH linker option
- library path linker option
ms.assetid: 7240af0b-9a3d-4d53-8169-2a92cd6958ba
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 5ccb94ad20735e81fc3d83f757cc0265cdc32169
ms.sourcegitcommit: be2a7679c2bd80968204dee03d13ca961eaa31ff
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/03/2018
ms.locfileid: "32372874"
---
# <a name="libpath-additional-libpath"></a>/LIBPATH (Libpath adicional)
```  
/LIBPATH:dir  
```  
  
## <a name="remarks"></a>Comentários  
 em que:  
  
 `dir`  
 Especifica um caminho que o vinculador pesquisará antes de pesquisar o caminho especificado na opção de ambiente LIB.  
  
## <a name="remarks"></a>Comentários  
 Use a opção /LIBPATH para substituir o caminho da biblioteca de ambiente. O vinculador pesquisar primeiro no caminho especificado por essa opção e, em seguida, pesquise no caminho especificado na variável de ambiente LIB. Você pode especificar apenas um diretório para cada opção /LIBPATH que você inseriu. Se você quiser especificar mais de um diretório, você deve especificar várias opções de /LIBPATH. O vinculador, em seguida, irá procurar as pastas especificadas em ordem.  
  
### <a name="to-set-this-linker-option-in-the-visual-studio-development-environment"></a>Para definir esta opção do vinculador no ambiente de desenvolvimento do Visual Studio  
  
1.  Abra a caixa de diálogo **Páginas de Propriedades** do projeto. Para obter detalhes, consulte [configuração Visual C++ Project Properties](../../ide/working-with-project-properties.md).  
  
2.  Clique o **vinculador** pasta.  
  
3.  Clique o **geral** página de propriedades.  
  
4.  Modificar o **diretórios de biblioteca adicionais** propriedade.  
  
### <a name="to-set-this-linker-option-programmatically"></a>Para definir esta opção do vinculador por meio de programação  
  
-   Consulte <xref:Microsoft.VisualStudio.VCProjectEngine.VCLinkerTool.AdditionalLibraryDirectories%2A>.  
  
## <a name="see-also"></a>Consulte também  
 [Definindo opções de vinculador](../../build/reference/setting-linker-options.md)   
 [Opções do vinculador](../../build/reference/linker-options.md)