---
title: Tipos escalares | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-tools
ms.topic: conceptual
dev_langs:
- C++
ms.assetid: 07c9195e-b6c7-4083-8ef0-8a93032e4d1e
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 5490bb33cafd8d2942e434ab9c50e34441506463
ms.sourcegitcommit: be2a7679c2bd80968204dee03d13ca961eaa31ff
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/03/2018
---
# <a name="scalar-types"></a>Tipos escalares
Embora o acesso de dados pode vir de qualquer alinhamento, é recomendável que ser alinhados no seu limite natural para evitar a perda de desempenho (ou um múltiplo dele). Enumerações são inteiros constantes e são tratadas como inteiros de 32 bits. A tabela a seguir descreve a definição de tipo e o armazenamento recomendado para ela relacionada à alinhamento usando os seguintes valores de alinhamento:  
  
-   Byte - 8 bits  
  
-   Palavra - 16 bits  
  
-   Palavra dupla - 32 bits  
  
-   Word Quad - 64 bits  
  
-   Octa Word - 128 bits  
  
|||||  
|-|-|-|-|  
|Tipo de escalar|Tipo de dados C|Tamanho de armazenamento (em bytes)|Alinhamento recomendado|  
|**INT8**|`char`|1|Byte|  
|**UINT8**|`unsigned char`|1|Byte|  
|**INT16**|**short**|2|Palavra|  
|**UINT16**|**unsigned short**|2|Palavra|  
|**INT32**|**int, long**|4|Doubleword|  
|**UINT32**|**int não assinado, longo não assinado**|4|Doubleword|  
|**INT64**|`__int64`|8|Quadword|  
|**UINT64**|**unsigned __int64**|8|Quadword|  
|**FP32 (único precisão)**|**float**|4|Doubleword|  
|**FP64 (dupla precisão)**|**double**|8|Quadword|  
|**PONTEIRO**|**\***|8|Quadword|  
|`__m64`|**struct __m64**|8|Quadword|  
|`__m128`|**struct __m128**|16|Octaword|  
  
## <a name="see-also"></a>Consulte também  
 [Tipos e armazenamento](../build/types-and-storage.md)