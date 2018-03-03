---
title: "-ASSEMBLYMODULE (Adicionar um módulo MSIL ao Assembly) | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-tools
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords:
- /assemblymodule
- VC.Project.VCLinkerTool.AddModuleNamesToAssembly
dev_langs:
- C++
helpviewer_keywords:
- ASSEMBLYMODULE linker option
- assemblies [C++], adding modules to
- assemblies [C++]
- /ASSEMBLYMODULE linker option
- -ASSEMBLYMODULE linker option
ms.assetid: 67357da8-e4b6-49fd-932c-329a5777f143
caps.latest.revision: 
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: efe45bd6a3225f50e1f842c6d247aae9626302a3
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="assemblymodule-add-a-msil-module-to-the-assembly"></a>/ASSEMBLYMODULE (adicionar um módulo MSIL ao assembly)
```  
/ASSEMBLYMODULE:filename  
```  
  
## <a name="remarks"></a>Comentários  
 em que:  
  
 *filename*  
 O módulo que você deseja incluir nesse assembly.  
  
## <a name="remarks"></a>Comentários  
 A opção /ASSEMBLYMODULE permite adicionar uma referência de módulo a um assembly. Informações de tipo no módulo não estarão disponíveis para o programa assembly que adicionou a referência do módulo. No entanto, informações de tipo no módulo estarão disponíveis para qualquer programa que referencia o assembly.  
  
 Use [#using](../../preprocessor/hash-using-directive-cpp.md) para adicionar uma referência a um assembly de módulo e disponibilizar informações de tipo do módulo para o programa de assembly.  
  
 Por exemplo, considere o seguinte cenário:  
  
1.  Criar um módulo com [/LN](../../build/reference/ln-create-msil-module.md).  
  
2.  Use /ASSEMBLYMODULE em um projeto diferente para incluir o módulo na compilação atual, que criará um assembly. Este projeto não fará referência para o módulo com `#using`.  
  
3.  Qualquer projeto que faz referência a esse assembly agora também pode usar tipos de módulo.  
  
 Outras opções de vinculador que afetam a geração de assembly são:  
  
-   [/ASSEMBLYDEBUG](../../build/reference/assemblydebug-add-debuggableattribute.md)  
  
-   [/ASSEMBLYLINKRESOURCE](../../build/reference/assemblylinkresource-link-to-dotnet-framework-resource.md)  
  
-   [/ASSEMBLYRESOURCE](../../build/reference/assemblyresource-embed-a-managed-resource.md)  
  
-   [/ DELAYSIGN](../../build/reference/delaysign-partially-sign-an-assembly.md)  
  
-   [/ NOASSEMBLY](../../build/reference/noassembly-create-a-msil-module.md)  
  
-   [/KEYFILE](../../build/reference/keyfile-specify-key-or-key-pair-to-sign-an-assembly.md)  
  
-   [/ KEYCONTAINER](../../build/reference/keycontainer-specify-a-key-container-to-sign-an-assembly.md)  
  
 O vinculador do Visual C++ aceita arquivos. netmodule como entrada e o arquivo de saída produzido pelo vinculador será um assembly ou. netmodule com nenhuma dependência de tempo de execução em qualquer uma da. netmodules que foram inseridos para o vinculador.  Para obter mais informações, consulte [. netmodule arquivos como entrada de vinculador](../../build/reference/netmodule-files-as-linker-input.md).  
  
### <a name="to-set-this-linker-option-in-the-visual-studio-development-environment"></a>Para definir esta opção do vinculador no ambiente de desenvolvimento do Visual Studio  
  
1.  Abra a caixa de diálogo **Páginas de Propriedades** do projeto. Para obter detalhes, consulte [configuração Visual C++ Project Properties](../../ide/working-with-project-properties.md).  
  
2.  Clique o **vinculador** pasta.  
  
3.  Clique o **entrada** página de propriedades.  
  
4.  Modificar o **Adicionar módulo ao Assembly** propriedade.  
  
### <a name="to-set-this-linker-option-programmatically"></a>Para definir esta opção do vinculador por meio de programação  
  
-   Consulte <xref:Microsoft.VisualStudio.VCProjectEngine.VCLinkerTool.AddModuleNamesToAssembly%2A>.  
  
## <a name="see-also"></a>Consulte também  
 [Definindo opções de vinculador](../../build/reference/setting-linker-options.md)   
 [Opções do vinculador](../../build/reference/linker-options.md)