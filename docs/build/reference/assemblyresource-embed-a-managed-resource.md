---
title: "/ASSEMBLYRESOURCE (inserir um recurso gerenciado) | Microsoft Docs"
ms.custom: ""
ms.date: "12/14/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "article"
f1_keywords: 
  - "VC.Project.VCLinkerTool.EmbedManagedResourceFile"
  - "/ASSEMBLYRESOURCE"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Opção de vinculador /ASSEMBLYRESOURCE"
  - "assemblies [C++]"
  - "assemblies [C++], vinculando arquivos de recursos"
  - "opção de vinculador ASSEMBLYRESOURCE"
  - "opção de vinculador -ASSEMBLYRESOURCE"
ms.assetid: 0ce6e1fb-921b-4b1b-a59c-d35388d789f2
caps.latest.revision: 12
caps.handback.revision: 12
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# /ASSEMBLYRESOURCE (inserir um recurso gerenciado)
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

```  
/ASSEMBLYRESOURCE:filename[,[name][,PRIVATE]]  
```  
  
## Parâmetros  
 *filename*  
 O recurso gerenciado que você deseja inserir nesse assembly.  
  
 *name*  
 Opcional.  O nome lógico do recurso; o nome usado para carregar o recurso.  O padrão é o nome do arquivo.  
  
 Opcionalmente, você pode especificar se o arquivo é particular no manifesto do assembly.  Por padrão, *name* é public no assembly.  
  
## Comentários  
 Use a opção \/ASSEMBLYRESOURCE inserir um recurso em um assembly.  
  
 Os recursos são públicos no assembly quando forem criados com o vinculador.  O vinculador não permite renomear o recurso no assembly.  
  
 Se *o nome de arquivo* é um arquivo de recursos do.NET Framework \(.resources\) criado, por exemplo, por [Gerador de Arquivo de recursos \(Resgen.exe\)](../Topic/Resgen.exe%20\(Resource%20File%20Generator\).md) ou no ambiente de desenvolvimento, pode ser acessado com membros do namespace **System.Resources** \(consulte [System.Resources.ResourceManager](https://msdn.microsoft.com/en-us/library/system.resources.resourcemanager.aspx) para obter mais informações\).  Para todos recursos demais, use **GetManifestResource**\* métodos na classe de **System.Reflection.Assembly** para acessar em tempo de execução do recurso.  
  
 Outras opções do vinculador que afetam a geração do assembly são:  
  
-   [\/ASSEMBLYDEBUG](../Topic/-ASSEMBLYDEBUG%20\(Add%20DebuggableAttribute\).md)  
  
-   [\/ASSEMBLYLINKRESOURCE](../../build/reference/assemblylinkresource-link-to-dotnet-framework-resource.md)  
  
-   [\/ASSEMBLYMODULE](../../build/reference/assemblymodule-add-a-msil-module-to-the-assembly.md)  
  
-   [\/DELAYSIGN](../../build/reference/delaysign-partially-sign-an-assembly.md)  
  
-   [\/KEYFILE](../../build/reference/keyfile-specify-key-or-key-pair-to-sign-an-assembly.md)  
  
-   [\/KEYCONTAINER](../../build/reference/keycontainer-specify-a-key-container-to-sign-an-assembly.md)  
  
-   [\/NOASSEMBLY](../../build/reference/noassembly-create-a-msil-module.md)  
  
### Para definir esta opção do vinculador no ambiente de desenvolvimento do Visual Studio  
  
1.  Abra a caixa de diálogo **Páginas de Propriedade** do projeto.  Para obter detalhes, consulte [Configurando as propriedades de projeto do Visual C\+\+](../../ide/working-with-project-properties.md).  
  
2.  Clique na pasta **Vinculador**.  
  
3.  Clique na página de propriedades de **Entrada** .  
  
4.  Modifique a propriedade de **Inserir Arquivo de Recurso Gerenciado** .  
  
### Para definir essa opção de vinculador por meio de programação  
  
1.  Consulte <xref:Microsoft.VisualStudio.VCProjectEngine.VCLinkerTool.EmbedManagedResourceFile%2A>.  
  
## Consulte também  
 [Definindo opções de vinculador](../../build/reference/setting-linker-options.md)   
 [Opções de vinculador](../../build/reference/linker-options.md)