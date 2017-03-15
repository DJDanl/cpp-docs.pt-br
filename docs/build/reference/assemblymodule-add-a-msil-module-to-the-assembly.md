---
title: "/ASSEMBLYMODULE (adicionar um m&#243;dulo MSIL ao assembly) | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "article"
f1_keywords: 
  - "/assemblymodule"
  - "VC.Project.VCLinkerTool.AddModuleNamesToAssembly"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Opção de vinculador /ASSEMBLYMODULE"
  - "assemblies [C++]"
  - "assemblies [C++], adicionando módulos a"
  - "opção de vinculador ASSEMBLYMODULE"
  - "opção de vinculador -ASSEMBLYMODULE"
ms.assetid: 67357da8-e4b6-49fd-932c-329a5777f143
caps.latest.revision: 11
caps.handback.revision: 11
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# /ASSEMBLYMODULE (adicionar um m&#243;dulo MSIL ao assembly)
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

```  
/ASSEMBLYMODULE:filename  
```  
  
## Comentários  
 onde:  
  
 *filename*  
 O módulo que você deseja incluir nesse assembly.  
  
## Comentários  
 A opção \/ASSEMBLYMODULE permite que você adicione uma referência a um assembly do módulo.  As informações de tipo no módulo não estará disponível para o programa do assembly que adicionou a referência do módulo.  No entanto, as informações de tipo no módulo estará disponível para qualquer programa que faz referência ao assembly.  
  
 Use [\#using](../../preprocessor/hash-using-directive-cpp.md) ao adicionar uma referência a um assembly do módulo e fazem informações disponíveis do tipo de módulo para o programa de assembly.  
  
 Por exemplo, considere o seguinte cenário:  
  
1.  Crie um módulo com [\/LN](../../build/reference/ln-create-msil-module.md).  
  
2.  Use \/ASSEMBLYMODULE em um projeto diferente incluir o módulo na compilação atual, que criará um assembly.  Esse projeto não referenciará o módulo com `#using`.  
  
3.  Qualquer projeto que fazem referência a esse assembly pode também usar tipos do módulo.  
  
 Outras opções do vinculador que afetam a geração do assembly são:  
  
-   [\/ASSEMBLYDEBUG](../Topic/-ASSEMBLYDEBUG%20\(Add%20DebuggableAttribute\).md)  
  
-   [\/ASSEMBLYLINKRESOURCE](../../build/reference/assemblylinkresource-link-to-dotnet-framework-resource.md)  
  
-   [\/ASSEMBLYRESOURCE](../../build/reference/assemblyresource-embed-a-managed-resource.md)  
  
-   [\/DELAYSIGN](../../build/reference/delaysign-partially-sign-an-assembly.md)  
  
-   [\/NOASSEMBLY](../../build/reference/noassembly-create-a-msil-module.md)  
  
-   [\/KEYFILE](../../build/reference/keyfile-specify-key-or-key-pair-to-sign-an-assembly.md)  
  
-   [\/KEYCONTAINER](../../build/reference/keycontainer-specify-a-key-container-to-sign-an-assembly.md)  
  
 O vinculador Visual C\+\+ aceita arquivos de .netmodule como a entrada e o arquivo de saída gerada pelo vinculador será um assembly ou em um .netmodule sem dependência de tempo de execução em qualquer um dos .netmodules que foram registrados no vinculador.  Para obter mais informações, consulte [Arquivos .netmodule como entrada de vinculador](../Topic/.netmodule%20Files%20as%20Linker%20Input.md).  
  
### Para definir esta opção do vinculador no ambiente de desenvolvimento do Visual Studio  
  
1.  Abra a caixa de diálogo **Páginas de Propriedade** do projeto.  Para obter detalhes, consulte [Configurando as propriedades de projeto do Visual C\+\+](../../ide/working-with-project-properties.md).  
  
2.  Clique na pasta **Vinculador**.  
  
3.  Clique na página de propriedades de **Entrada** .  
  
4.  Modifique a propriedade de **Adicionar Módulo a Assembly** .  
  
### Para definir essa opção de vinculador por meio de programação  
  
-   Consulte <xref:Microsoft.VisualStudio.VCProjectEngine.VCLinkerTool.AddModuleNamesToAssembly%2A>.  
  
## Consulte também  
 [Definindo opções de vinculador](../../build/reference/setting-linker-options.md)   
 [Opções de vinculador](../../build/reference/linker-options.md)