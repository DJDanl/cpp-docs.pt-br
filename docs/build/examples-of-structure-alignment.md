---
title: Exemplos de alinhamento da estrutura | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-tools
ms.tgt_pltfrm: 
ms.topic: article
dev_langs: C++
helpviewer_keywords:
- structure alignment
- examples [C++], structure alignment
ms.assetid: 03d137bf-5cc4-472e-9583-6498f2534199
caps.latest.revision: "16"
author: corob-msft
ms.author: corob
manager: ghogen
ms.openlocfilehash: 9420a191174d0f2c03d7d3e30f797106784a3dc0
ms.sourcegitcommit: ebec1d449f2bd98aa851667c2bfeb7e27ce657b2
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/24/2017
---
# <a name="examples-of-structure-alignment"></a>Exemplos de alinhamento da estrutura
Os quatro exemplos a seguir cada declarar que uma estrutura alinhada ou union e os números correspondentes a ilustrar o layout da estrutura ou união na memória. Cada coluna em uma figura representa um byte de memória e o número na coluna indica o deslocamento do que byte. O nome da segunda linha de cada figura corresponde ao nome de uma variável na declaração. As colunas sombreadas indicam o preenchimento que é necessário para alcançar o alinhamento especificado.  
  
 ![Exemplo de conversão AMD](../build/media/vcamd_conv_ex_1.png "vcAmd_conv_ex_1")  
Exemplo 1  
  
 ![Exemplo de conversão AMD](../build/media/vcamd_conv_ex_2.png "vcAmd_conv_ex_2")  
Exemplo 2  
  
 ![Exemplo de conversão AMD](../build/media/vcamd_conv_ex_3.png "vcAmd_conv_ex_3")  
Exemplo 3:  
  
 ![Exemplo de conversão AMD](../build/media/vcamd_conv_ex_4.png "vcAmd_conv_ex_4")  
Exemplo 4  
  
## <a name="see-also"></a>Consulte também  
 [Tipos e armazenamento](../build/types-and-storage.md)