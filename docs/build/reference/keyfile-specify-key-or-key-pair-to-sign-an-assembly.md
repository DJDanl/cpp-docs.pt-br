---
title: "/KEYFILE (especificar chave ou par de chaves para assinar um assembly) | Microsoft Docs"
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
  - "/keyfile"
  - "VC.Project.VCLinkerTool.KeyFile"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Opção de vinculador /KEYFILE"
  - "opção de vinculador KEYFILE"
  - "opção de vinculador -KEYFILE"
ms.assetid: 9b71f8c0-541c-4fe5-a0c7-9364f42ecb06
caps.latest.revision: 12
caps.handback.revision: 12
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# /KEYFILE (especificar chave ou par de chaves para assinar um assembly)
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

```  
/KEYFILE:filename  
```  
  
## Comentários  
 onde:  
  
 *filename*  
 Arquivo que contém a chave.  Coloque a cadeia de caracteres entre aspas duplas \(” "\) se contiver um espaço.  
  
## Comentários  
 O vinculador insere a chave pública no manifesto do assembly e assinar o assembly final com a chave privada.  Para gerar um arquivo de chave, digite [sn \- k](../Topic/Sn.exe%20\(Strong%20Name%20Tool\).md) `file` na linha de comando.  Um assembly assinado tem um nome forte.  
  
 Se você compila com [\/LN](../../build/reference/ln-create-msil-module.md), o nome do arquivo da chave será realizado no módulo e inserida no assembly que é criado quando você cria um assembly que inclua uma referência explícita ao módulo, por meio de [\#using](../../preprocessor/hash-using-directive-cpp.md), ou ao vincular a [\/ASSEMBLYMODULE](../../build/reference/assemblymodule-add-a-msil-module-to-the-assembly.md).  
  
 Você também pode transmitir suas informações de criptografia ao vinculador com [\/KEYCONTAINER](../../build/reference/keycontainer-specify-a-key-container-to-sign-an-assembly.md).  Use [\/DELAYSIGN](../../build/reference/delaysign-partially-sign-an-assembly.md) se você desejar um assembly parcialmente assinado.  Consulte [Assemblies de nome forte \(assinatura de assembly\)](../../dotnet/strong-name-assemblies-assembly-signing-cpp-cli.md) para obter mais informações sobre como assinar um assembly.  
  
 No caso de **\/KEYFILE** e **\/KEYCONTAINER** são especificados \(a opção de linha de comando ou pelo atributo personalizado\), o vinculador primeiro tentará o contêiner de chave.  Se isso for bem\-sucedida, o assembly é assinado com as informações do contêiner de chave.  Se o vinculador não localizar o contêiner de chave, o tentará o arquivo especificado com a \/KEYFILE.  Se isso ocorrer, o assembly é assinado com as informações do arquivo de chave e as informações fundamentais será instalado no contêiner de chave \(semelhantemente a sn \- i\) de forma que na compilação seguir, o contêiner chave é válido.  
  
 Observe que um arquivo de chave pode conter apenas a chave pública.  
  
 Consulte [Criando e usando assemblies de nome forte](../Topic/Creating%20and%20Using%20Strong-Named%20Assemblies.md) para obter mais informações sobre como assinar um assembly.  
  
 Outras opções do vinculador que afetam a geração do assembly são:  
  
-   [\/ASSEMBLYDEBUG](../Topic/-ASSEMBLYDEBUG%20\(Add%20DebuggableAttribute\).md)  
  
-   [\/ASSEMBLYLINKRESOURCE](../../build/reference/assemblylinkresource-link-to-dotnet-framework-resource.md)  
  
-   [\/ASSEMBLYMODULE](../../build/reference/assemblymodule-add-a-msil-module-to-the-assembly.md)  
  
-   [\/ASSEMBLYRESOURCE](../../build/reference/assemblyresource-embed-a-managed-resource.md)  
  
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