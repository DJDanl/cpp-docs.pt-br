---
title: "Formato de imagem | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "article"
dev_langs: 
  - "C++"
ms.assetid: 3ca3654b-42fe-4253-9f2e-723644041aa0
caps.latest.revision: 8
caps.handback.revision: 8
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Formato de imagem
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

O formato de imagem é executável PE32\+.  Imagens do executável \(DLL\) e EXEs são restritas para um tamanho máximo de 2 gigabytes, então a atacar relativo com um deslocamento de 32 bits podem ser usadas para endereçar dados de imagem estáticos.  Esses dados incluem a tabela de endereços de importação, constantes de cadeia de caracteres, globais dados estáticos, e assim por diante.  
  
## Consulte também  
 [Convenções de software x64](../build/x64-software-conventions.md)