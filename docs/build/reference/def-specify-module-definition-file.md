---
title: -DEF (especificar arquivo de definição de módulo) | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-tools
ms.topic: reference
f1_keywords:
- VC.Project.VCLinkerTool.ModuleDefinitionFile
- /def
dev_langs:
- C++
helpviewer_keywords:
- module definition files, specifying
- DEF linker option
- -DEF linker option
- module definition files
- /DEF linker option
ms.assetid: 6497fa68-65f0-48ca-8f66-b87166fc631a
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: f0c712b81fbb755edd132c6f97efc906ba4f5ff9
ms.sourcegitcommit: be2a7679c2bd80968204dee03d13ca961eaa31ff
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/03/2018
ms.locfileid: "32371145"
---
# <a name="def-specify-module-definition-file"></a>/DEF (especificar arquivo de definição do módulo)
```  
/DEF:filename  
```  
  
## <a name="remarks"></a>Comentários  
 em que:  
  
 *filename*  
 O nome de um arquivo de definição de módulo (. def) a serem passados para o vinculador.  
  
## <a name="remarks"></a>Comentários  
 A opção /DEF passa um arquivo de definição de módulo (. def) ao vinculador. Apenas um arquivo. def pode ser especificado para o LINK. Para obter detalhes sobre os arquivos. def, consulte [arquivos de definição de módulo](../../build/reference/module-definition-dot-def-files.md).  
  
### <a name="to-set-this-linker-option-in-the-visual-studio-development-environment"></a>Para definir esta opção do vinculador no ambiente de desenvolvimento do Visual Studio  
  
1.  Abra a caixa de diálogo **Páginas de Propriedades** do projeto. Para obter detalhes, consulte [configuração Visual C++ Project Properties](../../ide/working-with-project-properties.md).  
  
2.  Clique o **vinculador** pasta.  
  
3.  Clique o **entrada** página de propriedades.  
  
4.  Modificar o **arquivo de definição de módulo** propriedade.  
  
 Para especificar um arquivo. def do ambiente de desenvolvimento, você deve adicioná-lo ao projeto junto com outros arquivos e, em seguida, especifique o arquivo para a opção /DEF.  
  
### <a name="to-set-this-linker-option-programmatically"></a>Para definir esta opção do vinculador por meio de programação  
  
-   Consulte <xref:Microsoft.VisualStudio.VCProjectEngine.VCLinkerTool.ModuleDefinitionFile%2A>.  
  
## <a name="see-also"></a>Consulte também  
 [Definindo opções de vinculador](../../build/reference/setting-linker-options.md)   
 [Opções do vinculador](../../build/reference/linker-options.md)