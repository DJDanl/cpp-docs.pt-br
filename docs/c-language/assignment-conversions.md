---
title: "Conversões de atribuição | Microsoft Docs"
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
- conversions, assignment
- assignment conversions
ms.assetid: 4ee01013-de32-4aae-b12e-0051d0cde927
caps.latest.revision: 7
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
ms.sourcegitcommit: a937c9d083a7e4331af63323a19fb207142604a0
ms.openlocfilehash: 1bab700c6191f7f09dba0649beac6df569370601
ms.contentlocale: pt-br
ms.lasthandoff: 02/25/2017

---
# <a name="assignment-conversions"></a>Conversões de atribuição
Em operações de atribuição, o tipo do valor que está sendo atribuído é convertido no tipo da variável que recebe a atribuição. O C permite conversões por atribuição entre os tipos integrais e flutuantes, mesmo se as informações forem perdidas na conversão. O método de conversão usado depende dos tipos envolvidos na atribuição, conforme descrito em [Conversões aritméticas comuns](../c-language/usual-arithmetic-conversions.md) e nas seguintes seções:  
  
-   [Conversões de tipos integrais com sinal](../c-language/conversions-from-signed-integral-types.md)  
  
-   [Conversões de tipos integrais sem sinal](../c-language/conversions-from-unsigned-integral-types.md)  
  
-   [Conversões de tipos de ponto flutuante](../c-language/conversions-from-floating-point-types.md)  
  
-   [Conversões de e em tipos de ponteiro](../c-language/conversions-to-and-from-pointer-types.md)  
  
-   [Conversões de outros tipos](../c-language/conversions-from-other-types.md)  
  
 Os qualificadores de tipo não afetam o capacidade de conversão, embora um valor l **const** não possa ser usado no lado esquerdo da atribuição.  
  
## <a name="see-also"></a>Consulte também  
 [Conversões de Tipo](../c-language/type-conversions-c.md)
