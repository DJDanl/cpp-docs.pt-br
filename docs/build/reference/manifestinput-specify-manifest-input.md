---
title: "/MANIFESTINPUT (especificar entrada de manifesto) | Microsoft Docs"
ms.custom: ""
ms.date: "12/15/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "article"
dev_langs: 
  - "C++"
ms.assetid: a0b0c21e-1f9b-4d8c-bb3f-178f57fa7f1b
caps.latest.revision: 5
caps.handback.revision: 5
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# /MANIFESTINPUT (especificar entrada de manifesto)
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Especifica um arquivo de entrada de manifesto para incluir no manifesto que é inserido na imagem.  
  
## Sintaxe  
  
```c#  
/MANIFESTINPUT:filename  
```  
  
#### Parâmetros  
 `filename`  
 O arquivo de manifesto a ser incluído no manifesto inserido.  
  
## Comentários  
 A opção de **\/MANIFESTINPUT** especifica o caminho de um arquivo de entrada para usar para criar o manifesto inserido em uma imagem executável.  Se você tiver vários arquivos de entrada de manifesto, use a opção várias vezes — uma vez para cada arquivo de entrada.  Os arquivos de entrada de manifesto são mesclados para criar o manifesto inserido.  Esta opção requer a opção de **\/MANIFEST:EMBED**.  
  
 Esta opção não pode ser definida diretamente no [!INCLUDE[vsprvs](../../assembler/masm/includes/vsprvs_md.md)].  Em vez disso, use a propriedade **Arquivos de Manifesto Adicionais** do projeto para especificar arquivos de manifesto adicionais a serem incluídos.  Para obter mais informações, consulte [Caixa de diálogo Entrada e Saída, Ferramenta de Manifesto, Propriedades de Configuração, Páginas de Propriedade de \<Projectname\>](../../ide/input-and-output-manifest-tool.md).  
  
## Consulte também  
 [Definindo opções de vinculador](../../build/reference/setting-linker-options.md)   
 [Opções de vinculador](../../build/reference/linker-options.md)