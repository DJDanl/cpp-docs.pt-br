---
title: "Arquivos de entrada LINK | Microsoft Docs"
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
  - "entrada de comando para arquivos de vinculador [C++]"
  - "Arquivos  [C++], LINK"
  - "importar bibliotecas [C++], arquivos de vinculador"
  - "arquivos de entrada [C++], LINK"
  - "ferramenta LINK [C++], arquivos de entrada"
  - "vinculador [C++], arquivos de entrada"
  - "arquivos de definição de módulo"
  - "arquivos de definição de módulo, arquivos de vinculador"
  - "recursos [C++], arquivos de vinculador"
ms.assetid: bb26fcc5-509a-4620-bc3e-b6c6e603a412
caps.latest.revision: 8
caps.handback.revision: 8
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Arquivos de entrada LINK
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Você fornece o vinculador com arquivos que contêm objetos, bibliotecas de importação e do padrão, recursos, definições do módulo, e a entrada de comando.  O LINK não usa extensões de arquivo para fazer suposições sobre o conteúdo de um arquivo.  Em vez disso, o LINK examinará cada arquivo de entrada para determinar que tipo de arquivo é.  
  
 Os arquivos do objeto na linha de comando são processados na ordem em que aparecem na linha de comando.  As bibliotecas são pesquisadas na ordem de linha de comando além disso, com a seguinte aviso: Símbolos que não são resolvidos ao colocar em um arquivo de objeto de uma biblioteca são pesquisados nessa biblioteca primeiro e, nas bibliotecas de linha de comando e das políticas de [\/DEFAULTLIB \(especificar biblioteca padrão\)](../../build/reference/defaultlib-specify-default-library.md) , a algumas bibliotecas no início da linha de comando.  
  
> [!NOTE]
>  O LINK não aceita um ponto\-e\-vírgula \(ou qualquer outro caractere\) como o início de um comentário em arquivos de resposta e arquivos de ordem.  Os ponto\-e\-vírgulas só serão reconhecidos como o início dos comentários na definição o arquivo .def \(\).  
  
 O LINK usa os seguintes tipos de arquivos de entrada:  
  
-   [arquivos de .obj](../../build/reference/dot-obj-files-as-linker-input.md)  
  
-   [arquivos de .netmodule](../Topic/.netmodule%20Files%20as%20Linker%20Input.md)  
  
-   [arquivos de .lib](../../build/reference/dot-lib-files-as-linker-input.md)  
  
-   [arquivos de .exp](../../build/reference/dot-exp-files-as-linker-input.md)  
  
-   [arquivos .def](../../build/reference/dot-def-files-as-linker-input.md)  
  
-   [arquivos .pdb](../../build/reference/dot-pdb-files-as-linker-input.md)  
  
-   [arquivos de .res](../../build/reference/dot-res-files-as-linker-input.md)  
  
-   [arquivos de .exe](../Topic/.Exe%20Files%20as%20Linker%20Input.md)  
  
-   [arquivos .txt](../../build/reference/dot-txt-files-as-linker-input.md)  
  
-   [arquivos de .ilk](../../build/reference/dot-ilk-files-as-linker-input.md)  
  
## Consulte também  
 [Definindo opções de vinculador](../../build/reference/setting-linker-options.md)   
 [Opções de vinculador](../../build/reference/linker-options.md)