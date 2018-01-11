---
title: "Enumerações &lt;codecvt&gt; | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords: codecvt/std::codecvt_mode
ms.assetid: 46a8b073-01bc-46d3-b3d3-a8540f9422c1
helpviewer_keywords: std::codecvt_mode
caps.latest.revision: "10"
manager: ghogen
ms.openlocfilehash: bba1b53abb7286c64bdaf79ec8cb2004ba67a9dd
ms.sourcegitcommit: ebec1d449f2bd98aa851667c2bfeb7e27ce657b2
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/24/2017
---
# <a name="ltcodecvtgt-enums"></a>Enumerações &lt;codecvt&gt;
  
##  <a name="codecvt_mode"></a>  Enumeração codecvt_mode  
 Especifica informações de configuração para facetas de [localidade](../standard-library/locale-class.md).  
  
```  
enum codecvt_mode {  
    consume_header = 4,  
    generate_header = 2,  
    little_endian = 1  
 };  
```  
  
### <a name="remarks"></a>Comentários  
 A enumeração define três constantes que fornecem informações de configuração para as facetas de localidade declaradas em [\<codecvt>](../standard-library/codecvt.md). Os valores distintos são:  
  
- `consume_header`, para consumir uma sequência de cabeçalho inicial ao ler uma sequência multibyte e determinar a extremidade da sequência multibyte subsequente a ser lida  
  
- `generate_header`, para gerar uma sequência de cabeçalho inicial ao escrever uma sequência multibyte para anunciar a extremidade da sequência multibyte subsequente a ser escrita  
  
- `little_endian`, para gerar uma sequência multibyte em ordem little endian em oposição à ordem big endian padrão  
  
 Essas constantes podem estar ORed juntas em combinações arbitrárias.  
  
## <a name="see-also"></a>Consulte também  
 [\<codecvt>](../standard-library/codecvt.md)

