---
title: "/NOLOGO (suprimir faixa de inicializa&#231;&#227;o) (vinculador) | Microsoft Docs"
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
  - "VC.Project.VCLinkerTool.SuppressStartupBanner"
  - "/nologo"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Opção de vinculador /NOLOGO"
  - "faixas, suprimindo a inicialização"
  - "mensagem de direitos autorais"
  - "opção de vinculador NOLOGO"
  - "opção de vinculador -NOLOGO"
  - "opção de vinculador suprimir faixa de inicialização"
  - "números de versão, impedindo exibição de vinculador"
ms.assetid: 3b20dddd-eca6-4545-a331-9f70bf720197
caps.latest.revision: 7
caps.handback.revision: 7
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# /NOLOGO (suprimir faixa de inicializa&#231;&#227;o) (vinculador)
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

```  
/NOLOGO  
```  
  
## Comentários  
 A opção \/NOLOGO impede a exibição da mensagem e o número de versão dos direitos reservados.  
  
 Essa opção também elimina o eco de arquivos de comando.  Para obter detalhes, consulte [Arquivos de comando de LINK](../../build/reference/link-command-files.md).  
  
 Por padrão, essa informação é enviada pelo vinculador à janela saída.  Na linha de comando, são enviadas para a saída padrão e podem ser redirecionadas para um arquivo.  
  
### Para definir esta opção do vinculador no ambiente de desenvolvimento do Visual Studio  
  
1.  Essa opção só deve ser usada de linha de comando.  
  
### Para definir essa opção de vinculador por meio de programação  
  
1.  Essa opção do vinculador não pode ser modificada programaticamente.  
  
## Consulte também  
 [Definindo opções de vinculador](../../build/reference/setting-linker-options.md)   
 [Opções de vinculador](../../build/reference/linker-options.md)