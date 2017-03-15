---
title: "Vari&#225;veis de ambiente LINK | Microsoft Docs"
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
  - "link"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "variáveis de ambiente [C++], LINK"
  - "variável de ambiente LIB"
  - "ferramenta LINK [C++], variáveis de ambiente"
  - "variáveis, ambiente"
ms.assetid: 9a3d3291-0cc4-4a7d-9d50-80e351b90708
caps.latest.revision: 8
caps.handback.revision: 8
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Vari&#225;veis de ambiente LINK
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

A ferramenta LINK usa as seguintes variáveis de ambiente:  
  
-   LINK e \_LINK\_, se definido.  A ferramenta LINK precede as opções e argumentos definidos na variável de ambiente LINK e acrescenta as opções e argumentos definidos na variável de ambiente \_LINK\_ para os argumentos de linha de comando antes do processamento.  
  
-   LIB, se definido.  As ferramentas LINK usa o caminho LIB ao procurar um objeto, biblioteca ou outro arquivo especificado na linha de comando ou pelo [\/base](../../build/reference/base-base-address.md) opção.  Ele também usa o caminho da biblioteca para localizar um arquivo. PDB chamado em um objeto.  A variável LIB pode conter uma ou mais especificações de caminho, separadas por ponto e vírgula.  Um caminho deve apontar para o subdiretório \\lib da instalação do Visual C\+\+.  
  
-   CAMINHO, se a ferramenta precisa ser executado CVTRES e não é possível localizar o arquivo no mesmo diretório do próprio LINK.  \(LINK requer CVTRES vincular um arquivo. res\). CAMINHO deve apontar para o subdiretório \\bin de sua instalação do Visual C\+\+.  
  
-   TMP, para especificar um diretório ao vincular arquivos OMF ou. res.  
  
## Consulte também  
 [Definindo opções de vinculador](../../build/reference/setting-linker-options.md)   
 [Opções de vinculador](../../build/reference/linker-options.md)   
 [Definindo as variáveis de caminho e ambiente para compilações de linha de comando](../../build/setting-the-path-and-environment-variables-for-command-line-builds.md)