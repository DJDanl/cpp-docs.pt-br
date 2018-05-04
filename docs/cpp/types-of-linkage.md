---
title: Tipos de vinculação | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-language
ms.topic: language-reference
dev_langs:
- C++
helpviewer_keywords:
- no linkage
- linkage [C++], none
- linkage [C++], types of
- types [C++], linkage
- internal linkage, types of linkage
- external linkage, linkage types
ms.assetid: 41326c7f-4602-4bad-a648-697604858ba0
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: dfddf0105603311179340a0c6b0b2e8fb328b134
ms.sourcegitcommit: be2a7679c2bd80968204dee03d13ca961eaa31ff
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/03/2018
---
# <a name="types-of-linkage"></a>Tipos de ligação
A maneira como os nomes de objetos e funções são compartilhados entre unidades de conversão é chamada de vinculação. Esses nomes podem ter:  
  
-   Vinculação interna, referindo-se somente aos elementos do programa dentro de suas próprias unidades de conversão; não são compartilhados com outras unidades de conversão.  
  
     O mesmo nome em outra unidade de conversão pode se referir a um objeto diferente ou a uma classe diferente. Os nomes com vinculação interna são às vezes referidos como sendo locais para suas unidades de conversão.  
  
     Um exemplo de declaração de um nome com vinculação interna é:  
  
    ```  
    static int i;   // The static keyword ensures internal linkage.  
    ```  
  
-   Vinculação externa, caso em que podem se referir a elementos do programa em qualquer unidade de conversão do programa — o elemento do programa é compartilhado entre as unidades de conversão.  
  
     O mesmo nome em outra unidade de conversão refere-se garantidamente ao mesmo objeto ou classe. Os nomes com vinculação externa às vezes são referidos como sendo globais.  
  
     Um exemplo de declaração de um nome com vinculação externa é:  
  
    ```  
    extern int i;  
    ```  
  
-   Nenhum vínculo, caso em que se referem a entidades exclusivas. O mesmo nome em outro escopo pode não se referir ao mesmo objeto. Um exemplo é uma enumeração. (Observe, entretanto, que você pode passar um ponteiro para um objeto sem vinculação. Isso torna o objeto acessível em outras unidades de conversão.)  
  
## <a name="see-also"></a>Consulte também  
 [Programa e ligação](../cpp/program-and-linkage-cpp.md)