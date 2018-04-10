---
title: -I (adicionais diretórios de inclusão) | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.reviewer: ''
ms.suite: ''
ms.technology:
- cpp-tools
ms.tgt_pltfrm: ''
ms.topic: article
f1_keywords:
- VC.Project.VCCLWCECompilerTool.AdditionalIncludeDirectories
- VC.Project.VCCLCompilerTool.AdditionalIncludeDirectories
- /I
- VC.Project.VCNMakeTool.IncludeSearchPath
dev_langs:
- C++
helpviewer_keywords:
- /I compiler option [C++]
- Additional Include Directories compiler option
- I compiler option [C++]
- -I compiler option [C++]
- set include directories
- include directories, compiler option [C++]
ms.assetid: 3e9add2a-5ed8-4d15-ad79-5b411e313a49
caps.latest.revision: 11
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: bfbf962a92af22d3e724c592fec6cf812b610dc7
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="i-additional-include-directories"></a>/I (diretórios de inclusão adicionais)
Adiciona uma pasta à lista de diretórios pesquisada em busca de arquivos de inclusão.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
/I[ ]directory  
```  
  
## <a name="arguments"></a>Arguments  
 `directory`  
 O diretório a ser adicionado à lista de diretórios pesquisado por arquivos de inclusão.  
  
## <a name="remarks"></a>Comentários  
 Para adicionar mais de um diretório, use esta opção mais de uma vez. Diretórios são pesquisados até que o arquivo de inclusão especificado for encontrado.  
  
 Você pode usar essa opção com a ignorar caminhos de inclusão padrão ([/X (ignorar caminhos de inclusão padrão)](../../build/reference/x-ignore-standard-include-paths.md)) opção.  
  
 O compilador procura diretórios na seguinte ordem:  
  
1.  Diretórios que contêm o arquivo de origem.  
  
2.  Diretórios especificados com o **/i** opção, na ordem em que CL encontrá-las.  
  
3.  Diretórios especificados no **incluir** variável de ambiente.  
  
### <a name="to-set-this-compiler-option-in-the-visual-studio-development-environment"></a>Para definir esta opção do compilador no ambiente de desenvolvimento do Visual Studio  
  
1.  Abra a caixa de diálogo **Páginas de Propriedades** do projeto. Para obter detalhes, consulte [trabalhar com propriedades do projeto](../../ide/working-with-project-properties.md).  
  
2.  Clique o **C/C++** pasta.  
  
3.  Clique o **geral** página de propriedades.  
  
4.  Modificar o **diretórios de inclusão adicionais** propriedade.  
  
### <a name="to-set-this-compiler-option-programmatically"></a>Para definir essa opção do compilador via programação  
  
-   Consulte <xref:Microsoft.VisualStudio.VCProjectEngine.VCCLCompilerTool.AdditionalIncludeDirectories%2A>.  
  
## <a name="example"></a>Exemplo  
 O comando a seguir procura os arquivos de inclusão solicitados por MAIN.c na seguinte ordem: primeiro no diretório que contém MAIN.c, em seguida, no diretório \INCLUDE, em seguida, no diretório \MY\INCLUDE e finalmente nos diretórios atribuído de inclusão variável de ambiente.  
  
```  
CL /I \INCLUDE /I\MY\INCLUDE MAIN.C  
```  
  
## <a name="see-also"></a>Consulte também  
 [Opções do compilador](../../build/reference/compiler-options.md)   
 [Definindo opções do compilador](../../build/reference/setting-compiler-options.md)