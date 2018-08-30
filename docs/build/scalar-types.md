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
ms.openlocfilehash: 6af598ec6e27138f4e666007018ce803177697b3
ms.sourcegitcommit: 9a0905c03a73c904014ec9fd3d6e59e4fa7813cd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/29/2018
ms.locfileid: "43211135"
---
# <a name="scalar-types"></a>Tipos escalares
Embora o acesso de dados pode ter nenhum alinhamento, é recomendável que os dados sejam alinhados no seu limite natural para evitar a perda de desempenho (ou um múltiplo dele). Enums são inteiros constantes e são tratados como inteiros de 32 bits. A tabela a seguir descreve a definição de tipo e o armazenamento recomendado para ela, pois pertence ao alinhamento usando os seguintes valores de alinhamento:  
  
-   Byte - 8 bits  
  
-   Palavra - 16 bits  
  
-   Palavra dupla - 32 bits  
  
-   Word Quad - 64 bits  
  
-   Octa Word - 128 bits  
  
|||||  
|-|-|-|-|  
|Tipo escalar|Tipo de dados C|Tamanho de armazenamento (em bytes)|Alinhamento recomendado|  
|**INT8**|**char**|1|Byte|  
|**UINT8**|**unsigned char**|1|Byte|  
|**INT16**|**short**|2|Palavra|  
|**UINT16**|**unsigned short**|2|Palavra|  
|**INT32**|**int**, **longo**|4|Palavras duplas|  
|**UINT32**|**int sem sinal, unsigned long**|4|Palavras duplas|  
|**INT64**|**__int64**|8|Quadword|  
|**UINT64**|**unsigned __int64**|8|Quadword|  
|**FP32 (único precisão)**|**float**|4|Palavras duplas|  
|**FP64 (duplas precisão)**|**double**|8|Quadword|  
|**PONTEIRO**|<strong>\*</strong>|8|Quadword|  
|**__m64**|**struct __m64**|8|Quadword|  
|**__m128**|**struct __m128**|16|Octaword|  
  
## <a name="see-also"></a>Consulte também  
 [Tipos e armazenamento](../build/types-and-storage.md)