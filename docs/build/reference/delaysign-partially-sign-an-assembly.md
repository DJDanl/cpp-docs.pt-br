---
title: "/DELAYSIGN (assinar parcialmente um assembly) | Microsoft Docs"
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
  - "/delaysign"
  - "VC.Project.VCLinkerTool.DelaySign"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Opção de vinculador /DELAYSIGN"
  - "opção de vinculador DELAYSIGN"
  - "opção de vinculador -DELAYSIGN"
ms.assetid: 15244d30-3ecb-492f-a408-ffe81f38de20
caps.latest.revision: 11
caps.handback.revision: 11
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# /DELAYSIGN (assinar parcialmente um assembly)
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

```  
/DELAYSIGN[:NO]  
```  
  
## Comentários  
 where,  
  
 NOT  
 Especifica que o assembly não deve ser parcialmente assinado.  
  
## Comentários  
 Use **\/DELAYSIGN** se você só quiser colocar a chave pública no assembly.  A opção é **\/DELAYSIGN:NO**.  
  
 A opção de **\/DELAYSIGN** não tem nenhum efeito a menos que usado com [\/KEYFILE](../../build/reference/keyfile-specify-key-or-key-pair-to-sign-an-assembly.md) ou [\/KEYCONTAINER](../../build/reference/keycontainer-specify-a-key-container-to-sign-an-assembly.md).  
  
 Quando você solicita um assembly totalmente assinado, o compilador o uso do arquivo que contém o manifesto do assembly \(metadados\) e os sinais que picam com a chave privada.  A assinatura digital resultante é armazenada no arquivo que contém o manifesto.  Quando um assembly é atraso assinado, o vinculador não computa e não armazena a assinatura, mas o espaço das reservas no arquivo para que a assinatura poderá ser adicionado posteriormente.  
  
 Por exemplo, o uso **\/DELAYSIGN** permite que um verificador coloque o assembly no cache global.  Depois de teste, você pode totalmente assinar o assembly colocando a chave privada no assembly.  
  
 Consulte [Assemblies de nome forte \(assinatura de assembly\)](../../dotnet/strong-name-assemblies-assembly-signing-cpp-cli.md) e [Atrasando a assinatura de um assembly](../Topic/Delay%20Signing%20an%20Assembly.md) para obter mais informações sobre como assinar um assembly.  
  
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