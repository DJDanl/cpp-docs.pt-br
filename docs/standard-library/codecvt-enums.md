---
title: "Enumerações &lt;codecvt&gt; | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.tgt_pltfrm: 
ms.topic: article
ms.assetid: 46a8b073-01bc-46d3-b3d3-a8540f9422c1
caps.latest.revision: 10
manager: ghogen
translationtype: Machine Translation
ms.sourcegitcommit: 3168772cbb7e8127523bc2fc2da5cc9b4f59beb8
ms.openlocfilehash: 21162b7c25e09f2f77d2da1f4ee7797e68ec1e94
ms.lasthandoff: 02/25/2017

---
# <a name="ltcodecvtgt-enums"></a>Enumerações &lt;codecvt&gt;
  
##  <a name="a-namecodecvtmodeenumerationa--codecvtmode-enumeration"></a><a name="codecvt_mode_enumeration"></a>  Enumeração codecvt_mode  
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


