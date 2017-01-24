---
title: "Limites de campo do caminho | Microsoft Docs"
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
  - "_MAX_EXT"
  - "_MAX_DIR"
  - "_MAX_PATH"
  - "_MAX_FNAME"
  - "_MAX_DRIVE"
dev_langs: 
  - "C++"
  - "C"
helpviewer_keywords: 
  - "Constante _MAX_DIR"
  - "Constante _MAX_DRIVE"
  - "Constante _MAX_EXT"
  - "Constante _MAX_FNAME"
  - "Constante _MAX_PATH"
  - "Constante MAX_DIR"
  - "Constante MAX_DRIVE"
  - "Constante MAX_EXT"
  - "Constante MAX_FNAME"
  - "constantes de campo de caminho"
  - "caminhos, limite máximo"
ms.assetid: 2b5d0e43-1347-45b4-8397-24a8a45c444e
caps.latest.revision: 8
caps.handback.revision: 8
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Limites de campo do caminho
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

## Sintaxe  
  
```  
#include <stdlib.h>  
```  
  
## Comentários  
 Essas constantes definem o comprimento máximo para o caminho e para os campos individuais no caminho.  
  
|Constante|Significado|  
|---------------|-----------------|  
|`_MAX_DIR`|Comprimento máximo do componente de diretório|  
|`_MAX_DRIVE`|Comprimento máximo do componente de movimentação|  
|`_MAX_EXT`|Comprimento máximo do componente de extensão|  
|`_MAX_FNAME`|Comprimento máximo do componente de nome de arquivo|  
|`_MAX_PATH`|Comprimento máximo do caminho completo|  
  
> [!NOTE]
>  O tempo de execução C oferece suporte aos comprimentos de caminho até 32768 caracteres de comprimento, mas é até o sistema operacional, especificamente o sistema de arquivos, para dar suporte a esses caminhos mais longos.  A soma dos campos não deve exceder `_MAX_PATH` para compatibilidade total com sistemas de arquivos FAT32.  [!INCLUDE[win2kfamily](../c-runtime-library/includes/win2kfamily_md.md)], [!INCLUDE[WinXpFamily](../Token/winxpfamily_md.md)], [!INCLUDE[WinXPSvr](../build/includes/winxpsvr_md.md)], e da suporte a caminhos de sistema de arquivos NTFS do Windows Vista até 32768 caracteres de comprimento, mas apenas ao usar APIs Unicode.  Quando usando nomes de caminho longos, anteponha o caminho de caracteres com \\ \\? \\ e use as versões Unicode das funções de tempo de execução C.  
  
## Consulte também  
 [Constantes globais](../c-runtime-library/global-constants.md)