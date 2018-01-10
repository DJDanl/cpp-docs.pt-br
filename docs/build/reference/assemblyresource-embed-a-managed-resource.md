---
title: -ASSEMBLYRESOURCE (inserir um recurso gerenciado) | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-tools
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords:
- VC.Project.VCLinkerTool.EmbedManagedResourceFile
- /ASSEMBLYRESOURCE
dev_langs: C++
helpviewer_keywords:
- ASSEMBLYRESOURCE linker option
- assemblies [C++]
- -ASSEMBLYRESOURCE linker option
- assemblies [C++], linking resource files
- /ASSEMBLYRESOURCE linker option
ms.assetid: 0ce6e1fb-921b-4b1b-a59c-d35388d789f2
caps.latest.revision: "12"
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload: cplusplus
ms.openlocfilehash: ed8fd2b127a828eb8279671817cc4f099ae528c6
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="assemblyresource-embed-a-managed-resource"></a>/ASSEMBLYRESOURCE (inserir um recurso gerenciado)
```  
/ASSEMBLYRESOURCE:filename[,[name][,PRIVATE]]  
```  
  
## <a name="parameters"></a>Parâmetros  
 *filename*  
 O recurso gerenciado que você deseja inserir neste assembly.  
  
 *name*  
 Opcional. O nome lógico para o recurso. o nome usado para carregar o recurso. O padrão é o nome do arquivo.  
  
 Opcionalmente, você pode especificar se o arquivo deve ser privado no manifesto do assembly. Por padrão, *nome* é público no assembly.  
  
## <a name="remarks"></a>Comentários  
 Use a opção de /ASSEMBLYRESOURCE. para inserir um recurso em um assembly.  
  
 Recursos são públicos no assembly quando criado com o vinculador. O vinculador não permitem que você renomeie o recurso no assembly.  
  
 Se *filename* é um arquivo de recurso (. resources) do .NET Framework criado, por exemplo, pelo [gerador de arquivo (Resgen.exe)](/dotnet/framework/tools/resgen-exe-resource-file-generator) ou no ambiente de desenvolvimento, ele pode ser acessado com membros de **Resources** namespace (consulte [System.Resources.ResourceManager](https://msdn.microsoft.com/en-us/library/system.resources.resourcemanager.aspx) para obter mais informações). Para todos os outros recursos, use o **GetManifestResource** \* métodos em **System.Reflection.Assembly** classe para acessar o recurso em tempo de execução.  
  
 Outras opções de vinculador que afetam a geração de assembly são:  
  
-   [/ASSEMBLYDEBUG](../../build/reference/assemblydebug-add-debuggableattribute.md)  
  
-   [/ASSEMBLYLINKRESOURCE](../../build/reference/assemblylinkresource-link-to-dotnet-framework-resource.md)  
  
-   [/ASSEMBLYMODULE](../../build/reference/assemblymodule-add-a-msil-module-to-the-assembly.md)  
  
-   [/ DELAYSIGN](../../build/reference/delaysign-partially-sign-an-assembly.md)  
  
-   [/KEYFILE](../../build/reference/keyfile-specify-key-or-key-pair-to-sign-an-assembly.md)  
  
-   [/ KEYCONTAINER](../../build/reference/keycontainer-specify-a-key-container-to-sign-an-assembly.md)  
  
-   [/ NOASSEMBLY](../../build/reference/noassembly-create-a-msil-module.md)  
  
### <a name="to-set-this-linker-option-in-the-visual-studio-development-environment"></a>Para definir esta opção do vinculador no ambiente de desenvolvimento do Visual Studio  
  
1.  Abra a caixa de diálogo **Páginas de Propriedades** do projeto. Para obter detalhes, consulte [configuração Visual C++ Project Properties](../../ide/working-with-project-properties.md).  
  
2.  Clique o **vinculador** pasta.  
  
3.  Clique o **entrada** página de propriedades.  
  
4.  Modificar o **Inserir arquivo de recurso gerenciado** propriedade.  
  
### <a name="to-set-this-linker-option-programmatically"></a>Para definir esta opção do vinculador por meio de programação  
  
1.  Consulte <xref:Microsoft.VisualStudio.VCProjectEngine.VCLinkerTool.EmbedManagedResourceFile%2A>.  
  
## <a name="see-also"></a>Consulte também  
 [Definindo opções de vinculador](../../build/reference/setting-linker-options.md)   
 [Opções do vinculador](../../build/reference/linker-options.md)