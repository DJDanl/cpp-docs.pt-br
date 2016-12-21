---
title: "/WINMD (Gera metadados do Windows | Microsoft Docs"
ms.custom: ""
ms.date: "12/16/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "article"
f1_keywords: 
  - "VC.Project.VCLinkerTool.GenerateWindowsMetadata"
dev_langs: 
  - "C++"
ms.assetid: bcfb4901-411e-4c9e-9f78-23028b6e5fcc
caps.latest.revision: 9
caps.handback.revision: 9
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# /WINMD (Gera metadados do Windows
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Habilita a geração de um arquivo de metadados de Tempo de Execução do Windows \(.winmd\).  
  
```  
  
/WINMD[:{NO|ONLY}]  
```  
  
## Comentários  
 \/WINMD  
 A configuração padrão para aplicativos de [!INCLUDE[win8_appname_long](../../build/includes/win8_appname_long_md.md)] .  O vinculador gerencia o arquivo executável binário e os metadados de .winmd arquivo.  
  
 \/WINMD:NO  
 O vinculador gerencie somente o arquivo executável binário, mas não um arquivo de .winmd.  
  
 \/WINMD:ONLY  
 O vinculador gerencie somente o arquivo de .winmd, mas não o arquivo executável binário.  
  
 Por padrão, o nome do arquivo de saída tem o formato `binaryname`.winmd.  Para especificar um nome de arquivo diferente, use a opção de [\/WINMDFILE](../Topic/-WINMDFILE%20\(Specify%20winmd%20File\).md) .  
  
### Para definir esta opção do vinculador no ambiente de desenvolvimento do Visual Studio  
  
1.  Abra a caixa de diálogo **Páginas de Propriedade** do projeto.  Para obter detalhes, consulte [Trabalhando com propriedades do projeto](../../ide/working-with-project-properties.md).  
  
2.  Selecione a pasta do **Vinculador**.  
  
3.  Selecione a página de propriedades de **Metadados do Windows** .  
  
4.  Na caixa de listagem suspensa de **Gerar o Metadados do Windows** , selecione a opção desejada.  
  
## Consulte também  
 [Definindo opções de vinculador](../../build/reference/setting-linker-options.md)   
 [Opções de vinculador](../../build/reference/linker-options.md)