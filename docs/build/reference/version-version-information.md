---
title: -VERSION (informações de versão) | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.reviewer: ''
ms.suite: ''
ms.technology:
- cpp-tools
ms.tgt_pltfrm: ''
ms.topic: article
f1_keywords:
- VC.Project.VCLinkerTool.Version
- /version
dev_langs:
- C++
helpviewer_keywords:
- -VERSION linker option
- Version Information linker option
- version numbers, specifying in .exe
- /VERSION linker option
- VERSION linker option
ms.assetid: b86d0e86-dca6-4316-aee2-d863ccb9f223
caps.latest.revision: 9
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: aeb8d2845c5e8daa931e354b149fc1c35b37fbd7
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="version-version-information"></a>/VERSION (informações da versão)
```  
/VERSION:major[.minor]  
```  
  
## <a name="remarks"></a>Comentários  
 em que:  
  
 *principais*e *secundária*  
 O número de versão que você deseja no cabeçalho do arquivo .exe ou. dll.  
  
## <a name="remarks"></a>Comentários  
 A opção /VERSION informa o vinculador para colocar um número de versão no cabeçalho do arquivo .exe ou. dll. Use DUMPBIN [/HEADERS](../../build/reference/headers.md) para ver o campo de versão de imagem do OPTIONAL HEADER VALUES para ver o efeito de /Version.  
  
 O *principais* e *secundária* argumentos são números decimais no intervalo de 0 a 65.535. O padrão é a versão 0.0.  
  
 As informações especificadas com /VERSION não afetam as informações de versão que aparece para um aplicativo quando você exibir suas propriedades no Explorador de arquivos. Essas informações de versão vêm de um arquivo de recurso que é usado para criar o aplicativo. Consulte [Editor de informações de versão](../../windows/version-information-editor.md) para obter mais informações.  
  
 Outra maneira de inserir um número de versão é com o [versão](../../build/reference/version-c-cpp.md) instrução de definição de módulo.  
  
### <a name="to-set-this-linker-option-in-the-visual-studio-development-environment"></a>Para definir esta opção do vinculador no ambiente de desenvolvimento do Visual Studio  
  
1.  Abra a caixa de diálogo **Páginas de Propriedades** do projeto. Para obter detalhes, consulte [configuração Visual C++ Project Properties](../../ide/working-with-project-properties.md).  
  
2.  Clique o **vinculador** pasta.  
  
3.  Clique o **geral** página de propriedades.  
  
4.  Modificar o **versão** propriedade.  
  
### <a name="to-set-this-linker-option-programmatically"></a>Para definir esta opção do vinculador por meio de programação  
  
-   Consulte <xref:Microsoft.VisualStudio.VCProjectEngine.VCLinkerTool.Version%2A>.  
  
## <a name="see-also"></a>Consulte também  
 [Definindo opções de vinculador](../../build/reference/setting-linker-options.md)   
 [Opções do vinculador](../../build/reference/linker-options.md)