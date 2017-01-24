---
title: "/DEFAULTLIB (especificar biblioteca padr&#227;o) | Microsoft Docs"
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
  - "VC.Project.VCLinkerTool.DefaultLibraries"
  - "/defaultlib"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Opção de vinculador /DEFAULTLIB"
  - "opção de vinculador DEFAULTLIB"
  - "opção de vinculador -DEFAULTLIB"
  - "bibliotecas, adicionando à lista de"
ms.assetid: 6af7ff49-c170-4a13-97e2-2b9ae2de20c9
caps.latest.revision: 9
caps.handback.revision: 9
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# /DEFAULTLIB (especificar biblioteca padr&#227;o)
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

```  
/DEFAULTLIB:library  
```  
  
## Comentários  
 onde:  
  
 *biblioteca*  
 O nome de uma biblioteca para pesquisar ao resolver referências externas.  
  
## Comentários  
 A opção \/DEFAULTLIB adiciona uma *biblioteca* à lista de bibliotecas que VINCULAM pesquisas ao resolver referencia.  Uma biblioteca especificada com \/DEFAULTLIB é pesquisada depois que as bibliotecas especificadas na linha de comando antes das bibliotecas padrão e nomeadas em arquivos de .obj.  
  
 A opção de [Ignorar todas as bibliotecas padrão](../../build/reference/nodefaultlib-ignore-libraries.md) \(\/NODEFAULTLIB\) substitui \/DEFAULTLIB:*biblioteca*.  [Ignorar bibliotecas](../../build/reference/nodefaultlib-ignore-libraries.md) \(\/NODEFAULTLIB: a opção*de biblioteca*\) substitui \/DEFAULTLIB:*biblioteca* quando o mesmo nome *da biblioteca* é especificado em ambos.  
  
### Para definir esta opção do vinculador no ambiente de desenvolvimento do Visual Studio  
  
-   Essa opção do vinculador não está disponível no ambiente de desenvolvimento do Visual Studio.  Para adicionar uma biblioteca para o estágio de link, use a propriedade de **Dependências Adicionais** da página de propriedades de **Entrada** .  
  
### Para definir essa opção de vinculador por meio de programação  
  
-   Consulte <xref:Microsoft.VisualStudio.VCProjectEngine.VCLinkerTool.AdditionalOptions%2A>.  
  
## Consulte também  
 [Definindo opções de vinculador](../../build/reference/setting-linker-options.md)   
 [Opções de vinculador](../../build/reference/linker-options.md)