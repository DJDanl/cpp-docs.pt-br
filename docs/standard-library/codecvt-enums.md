---
title: "Enumerações &lt;codecvt&gt; | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords: []
ms.assetid: 46a8b073-01bc-46d3-b3d3-a8540f9422c1
caps.latest.revision: 10
manager: ghogen
ms.translationtype: Machine Translation
ms.sourcegitcommit: 4ecf60434799708acab4726a95380a2d3b9dbb3a
ms.openlocfilehash: 268723c43d61761e2b0a01d337adecc3336e01f3
ms.contentlocale: pt-br
ms.lasthandoff: 04/19/2017

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


