---
title: "/ASSEMBLYLINKRESOURCE (Link para recurso do .NET Framework) | Microsoft Docs"
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
  - "/ASSEMBLYLINKRESOURCE"
  - "VC.Project.VCLinkerTool.AssemblyLinkResource"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Opção de vinculador /ASSEMBLYLINKRESOURCE"
  - "opção de vinculador ASSEMBLYLINKRESOURCE"
  - "opção de vinculador -ASSEMBLYLINKRESOURCE"
ms.assetid: 8b6ad184-1b33-47a4-8513-4803cf915b64
caps.latest.revision: 9
caps.handback.revision: 9
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# /ASSEMBLYLINKRESOURCE (Link para recurso do .NET Framework)
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

```  
/ASSEMBLYLINKRESOURCE:filename  
```  
  
## Comentários  
 onde:  
  
 *filename*  
 O arquivo de recursos do .NET Framework à qual você deseja vincular do assembly.  
  
## Comentários  
 A opção \/ASSEMBLYLINKRESOURCE cria um link para um recurso do .NET Framework no arquivo de saída; o arquivo de recursos que não é colocado no arquivo de saída.  [\/ASSEMBLYRESOURCE](../../build/reference/assemblyresource-embed-a-managed-resource.md) inserir um arquivo de recursos no arquivo de saída.  
  
 Os recursos vinculados são públicos no assembly quando forem criados com o vinculador.  
  
 \/ASSEMBLYLINKRESOURCE requer que a compilação inclui [\/clr](../../build/reference/clr-common-language-runtime-compilation.md); [\/LN](../../build/reference/ln-create-msil-module.md) ou [\/NOASSEMBLY](../../build/reference/noassembly-create-a-msil-module.md) não são permitidas com \/ASSEMBLYLINKRESOURCE.  
  
 Se *o nome de arquivo* é um arquivo de recursos do .NET Framework criado, por exemplo, por [Resgen.exe](../Topic/Resgen.exe%20\(Resource%20File%20Generator\).md) ou no ambiente de desenvolvimento, pode ser acessado com membros do namespace **System.Resources** .  Para obter mais informações, consulte [System.Resources.ResourceManager](https://msdn.microsoft.com/en-us/library/system.resources.resourcemanager.aspx).  Para todos recursos demais, use **GetManifestResource**\* métodos na classe de **System.Reflection.Assembly** para acessar em tempo de execução do recurso.  
  
 *o nome de arquivo* pode ser qualquer formato de arquivo.  Por exemplo, talvez você queira fazer parte de DLL nativa do assembly, portanto pode ser instalado em cachê de assembly global e ser acessado de código gerenciado no assembly.  
  
 Outras opções do vinculador que afetam a geração do assembly são:  
  
-   [\/ASSEMBLYDEBUG](../Topic/-ASSEMBLYDEBUG%20\(Add%20DebuggableAttribute\).md)  
  
-   [\/ASSEMBLYMODULE](../../build/reference/assemblymodule-add-a-msil-module-to-the-assembly.md)  
  
-   [\/ASSEMBLYRESOURCE](../../build/reference/assemblyresource-embed-a-managed-resource.md)  
  
-   [\/DELAYSIGN](../../build/reference/delaysign-partially-sign-an-assembly.md)  
  
-   [\/KEYCONTAINER](../../build/reference/keycontainer-specify-a-key-container-to-sign-an-assembly.md)  
  
-   [\/KEYFILE](../../build/reference/keyfile-specify-key-or-key-pair-to-sign-an-assembly.md)  
  
-   [\/NOASSEMBLY](../../build/reference/noassembly-create-a-msil-module.md)  
  
### Para definir esta opção do vinculador no ambiente de desenvolvimento do Visual Studio  
  
1.  Abra a caixa de diálogo **Páginas de Propriedade** do projeto.  Para obter detalhes, consulte [Configurando as propriedades de projeto do Visual C\+\+](../../ide/working-with-project-properties.md).  
  
2.  Clique na pasta **Vinculador**.  
  
3.  Clique na página de propriedades de **Linha de Comando**.  
  
4.  Digite a opção na caixa de **Opções Adicionais** .  
  
### Para definir essa opção de vinculador por meio de programação  
  
-   Consulte <xref:Microsoft.VisualStudio.VCProjectEngine.VCLinkerTool.AdditionalOptions%2A>.  
  
## Consulte também  
 [Definindo opções de vinculador](../../build/reference/setting-linker-options.md)   
 [Opções de vinculador](../../build/reference/linker-options.md)