---
title: Limites de inteiro C++ | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-language
ms.tgt_pltfrm: 
ms.topic: article
dev_langs:
- C++
helpviewer_keywords:
- limits, integer
- limits, integer constants
- integer limits
ms.assetid: 0c23cbd6-29fb-4d9c-b689-5984e19748de
caps.latest.revision: 11
author: mikeblome
ms.author: mblome
manager: ghogen
translation.priority.ht:
- cs-cz
- de-de
- es-es
- fr-fr
- it-it
- ja-jp
- ko-kr
- pl-pl
- pt-br
- ru-ru
- tr-tr
- zh-cn
- zh-tw
ms.translationtype: Human Translation
ms.sourcegitcommit: 3f91eafaf3b5d5c1b8f96b010206d699f666e224
ms.openlocfilehash: c1d45ba449173c5cc2bf3fbed663a7d987c22e1c
ms.contentlocale: pt-br
ms.lasthandoff: 04/01/2017

---
# <a name="c-integer-limits"></a>Limites de inteiro C++
**Seção específica da Microsoft**  
  
 Os limites para tipos de inteiros estão listadas na tabela a seguir. Esses limites são definidos no arquivo de cabeçalho padrão LIMITS.H. O Microsoft C também permite a declaração de variáveis de inteiro dimensionadas, que são tipos integrais de 8, 16 ou 32 bits de tamanho. Para obter mais informações sobre inteiros dimensionados, consulte [Tipos de inteiros dimensionados](../c-language/c-sized-integer-types.md).  
  
### <a name="limits-on-integer-constants"></a>Limites em constantes de inteiro  
  
|**Constante**|Significado|Valor|  
|------------------|-------------|-----------|  
|**CHAR_BIT**|Número de bits na menor variável que não é um campo de bit.|8|  
|**SCHAR_MIN**|Valor mínimo para uma variável do tipo **signed char**.|-128|  
|**SCHAR_MAX**|Valor máximo para uma variável do tipo **signed char**.|127|  
|**UCHAR_MAX**|Valor máximo para uma variável do tipo `unsigned char`.|255 (0xff)|  
|**CHAR_MIN**|Valor mínimo para uma variável do tipo `char`.|-128; 0 se a opção /J for usada|  
|**CHAR_MAX**|Valor máximo para uma variável do tipo `char`.|127; 255 se a opção /J for usada|  
|**MB_LEN_MAX**|Número máximo de bytes em uma constante de vários caracteres.|5|  
|**SHRT_MIN**|Valor mínimo para uma variável do tipo **short**.|-32768|  
|**SHRT_MAX**|Valor máximo para uma variável do tipo **short**.|32767|  
|**USHRT_MAX**|Valor máximo para uma variável do tipo **unsigned short**.|65535 (0xffff)|  
|**INT_MIN**|Valor mínimo para uma variável do tipo `int`.|-2147483647 - 1|  
|**INT_MAX**|Valor máximo para uma variável do tipo `int`.|2147483647|  
|**UINT_MAX**|Valor máximo para uma variável do tipo `unsigned int`.|4294967295 (0xffffffff)|  
|**LONG_MIN**|Valor mínimo para uma variável do tipo **long**.|-2147483647 - 1|  
|**LONG_MAX**|Valor máximo para uma variável do tipo **long**.|2147483647|  
|**ULONG_MAX**|Valor máximo para uma variável do tipo `unsigned long`.|4294967295 (0xffffffff)|  
  
 Se um valor exceder a representação do maior inteiro, o compilador da Microsoft gera um erro.  
  
 **Fim da seção específica da Microsoft**  
  
## <a name="see-also"></a>Consulte também  
 [Constantes de inteiro C](../c-language/c-integer-constants.md)
