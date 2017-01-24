---
title: "Tipos de liga&#231;&#227;o | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "language-reference"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "vinculação externa, tipos de vinculação"
  - "vinculação interna, tipos de vinculação"
  - "vinculação [C++], nenhum"
  - "vinculação [C++], tipos de"
  - "sem vinculação"
  - "tipos [C++], vinculação"
ms.assetid: 41326c7f-4602-4bad-a648-697604858ba0
caps.latest.revision: 7
caps.handback.revision: 7
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Tipos de liga&#231;&#227;o
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

A maneira como os nomes de objetos e funções são compartilhados entre unidades de conversão é chamada de vinculação.  Esses nomes podem ter:  
  
-   Vinculação interna, referindo\-se somente aos elementos do programa dentro de suas próprias unidades de conversão; não são compartilhados com outras unidades de conversão.  
  
     O mesmo nome em outra unidade de conversão pode se referir a um objeto diferente ou a uma classe diferente.  Os nomes com vinculação interna são às vezes referidos como sendo locais para suas unidades de conversão.  
  
     Um exemplo de declaração de um nome com vinculação interna é:  
  
    ```  
    static int i;   // The static keyword ensures internal linkage.  
    ```  
  
-   Vinculação externa, caso em que podem se referir a elementos do programa em qualquer unidade de conversão do programa — o elemento do programa é compartilhado entre as unidades de conversão.  
  
     O mesmo nome em outra unidade de conversão refere\-se garantidamente ao mesmo objeto ou classe.  Os nomes com vinculação externa às vezes são referidos como sendo globais.  
  
     Um exemplo de declaração de um nome com vinculação externa é:  
  
    ```  
    extern int i;  
    ```  
  
-   Nenhum vínculo, caso em que se referem a entidades exclusivas.  O mesmo nome em outro escopo pode não se referir ao mesmo objeto.  Um exemplo é uma enumeração.  \(Observe, entretanto, que você pode passar um ponteiro para um objeto sem vinculação.  Isso torna o objeto acessível em outras unidades de conversão.\)  
  
## Consulte também  
 [Programa e ligação](../cpp/program-and-linkage-cpp.md)