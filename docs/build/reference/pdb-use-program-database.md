---
title: -PDB (Usar banco de dados de programa) | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-tools
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords:
- /pdb
- VC.Project.VCLinkerTool.ProgramDatabaseFile
dev_langs: C++
helpviewer_keywords:
- -PDB linker option
- /PDB linker option
- PDB linker option
- PDB files, creating
- .pdb files, creating
ms.assetid: d23db0ce-10cb-427a-bc60-d6b2a852723d
caps.latest.revision: "8"
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload: cplusplus
ms.openlocfilehash: 9b8b255e88a199397463d26d408d425234571552
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="pdb-use-program-database"></a>/PDB (usar banco de dados do programa)
```  
/PDB:filename  
```  
  
## <a name="remarks"></a>Comentários  
 em que:  
  
 *filename*  
 Um nome de usuário especificado para o banco de dados do programa (PDB) que o vinculador cria. Ele substitui o nome padrão.  
  
## <a name="remarks"></a>Comentários  
 Por padrão, quando [/Debug](../../build/reference/debug-generate-debug-info.md) for especificado, o vinculador cria um banco de dados do programa (PDB) que contém informações de depuração. O nome de arquivo padrão para o PDB tem o nome base do programa e a extensão. PDB.  
  
 Use /PDB:*filename* para especificar o nome do arquivo PDB. Se /DEBUG não for especificado, a opção /PDB é ignorada.  
  
 Um arquivo PDB pode ser de até 2GB.  
  
 Para obter mais informações, consulte [arquivos. PDB como entrada de vinculador](../../build/reference/dot-pdb-files-as-linker-input.md).  
  
### <a name="to-set-this-linker-option-in-the-visual-studio-development-environment"></a>Para definir esta opção do vinculador no ambiente de desenvolvimento do Visual Studio  
  
1.  Abra a caixa de diálogo **Páginas de Propriedades** do projeto. Para obter detalhes, consulte [configuração Visual C++ Project Properties](../../ide/working-with-project-properties.md).  
  
2.  Clique o **vinculador** pasta.  
  
3.  Clique o **depurar** página de propriedades.  
  
4.  Modificar o **gerar arquivo de banco de dados do programa** propriedade.  
  
### <a name="to-set-this-linker-option-programmatically"></a>Para definir esta opção do vinculador por meio de programação  
  
-   Consulte <xref:Microsoft.VisualStudio.VCProjectEngine.VCLinkerTool.ProgramDatabaseFile%2A>.  
  
## <a name="see-also"></a>Consulte também  
 [Definindo opções de vinculador](../../build/reference/setting-linker-options.md)   
 [Opções do vinculador](../../build/reference/linker-options.md)