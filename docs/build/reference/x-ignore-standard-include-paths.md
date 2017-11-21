---
title: "-X (Ignorar padrão incluir caminhos) | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-tools
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords:
- /x
- VC.Project.VCCLCompilerTool.OVERWRITEStandardIncludePath
- VC.Project.VCCLWCECompilerTool.OVERWRITEStandardIncludePath
dev_langs: C++
helpviewer_keywords:
- /X compiler option [C++]
- include files, ignore standard path
- -X compiler option [C++]
- include directories, ignore standard
- X compiler option
- Ignore Standard Include Paths compiler option
ms.assetid: 16bdf2cc-c8dc-46e4-bdcc-f3caeba5e1ef
caps.latest.revision: "9"
author: corob-msft
ms.author: corob
manager: ghogen
ms.openlocfilehash: 5ed251e1b937d14c42d105d98c2771ed0a2d6172
ms.sourcegitcommit: ebec1d449f2bd98aa851667c2bfeb7e27ce657b2
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/24/2017
---
# <a name="x-ignore-standard-include-paths"></a>/X (ignorar demarcadores de inclusão padrão)
Impede que o compilador procurando por arquivos de inclusão nos diretórios especificados nas variáveis de ambiente PATH e INCLUDE.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
/X  
```  
  
## <a name="remarks"></a>Comentários  
 Você pode usar essa opção com o [/I (diretórios de inclusão adicionais)](../../build/reference/i-additional-include-directories.md) (**/i**`directory`) opção.  
  
### <a name="to-set-this-compiler-option-in-the-visual-studio-development-environment"></a>Para definir esta opção do compilador no ambiente de desenvolvimento do Visual Studio  
  
1.  Abra a caixa de diálogo **Páginas de Propriedades** do projeto. Para obter detalhes, consulte [trabalhar com propriedades do projeto](../../ide/working-with-project-properties.md).  
  
2.  Clique o **C/C++** pasta.  
  
3.  Clique o **pré-processador** página de propriedades.  
  
4.  Modificar o **ignorar caminho de inclusão padrão** propriedade.  
  
### <a name="to-set-this-compiler-option-programmatically"></a>Para definir essa opção do compilador via programação  
  
-   Consulte <xref:Microsoft.VisualStudio.VCProjectEngine.VCCLCompilerTool.IgnoreStandardIncludePath%2A>.  
  
## <a name="example"></a>Exemplo  
 No comando a seguir, `/X` informa ao compilador para ignorar os locais especificados, as variáveis de ambiente PATH e INCLUDE e `/I` Especifica o diretório no qual procurar incluem arquivos:  
  
```  
CL /X /I \ALT\INCLUDE MAIN.C  
```  
  
## <a name="see-also"></a>Consulte também  
 [Opções do compilador](../../build/reference/compiler-options.md)   
 [Definindo opções do compilador](../../build/reference/setting-compiler-options.md)