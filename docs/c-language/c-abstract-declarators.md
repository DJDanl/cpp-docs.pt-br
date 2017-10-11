---
title: Declaradores abstratos C | Microsoft Docs
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
- declarators, abstract
- abstract declarations
ms.assetid: 6a556ad7-0555-421a-aa02-294d77cda8b5
caps.latest.revision: 8
author: mikeblome
ms.author: mblome
manager: ghogen
ms.translationtype: HT
ms.sourcegitcommit: 16d1bf59dfd4b3ef5f037aed9c0f6febfdf1a2e8
ms.openlocfilehash: ae6f7ca131e30c179d556e225600243500ae9379
ms.contentlocale: pt-br
ms.lasthandoff: 10/09/2017

---
# <a name="c-abstract-declarators"></a>Declaradores abstratos C
Um declarador abstrato é um declarador sem um identificador, consistindo em um ou mais modificadores de ponteiro, matriz ou função. O modificador de ponteiro (**\***) sempre precede o identificador em um declarador; os modificadores de matriz (**[ ]**) e de função ( **( )** ) seguem o identificador. Sabendo disso, você pode determinar onde o identificador apareceria em um declarador abstrato e interpretar o declarador corretamente. Consulte [Interpretar declaradores mais complexos](../c-language/interpreting-more-complex-declarators.md) para obter mais informações e exemplos de declaradores complexos. Geralmente, `typedef` pode ser usado para simplificar declaradores. Consulte [Declarações de Typedef](../c-language/typedef-declarations.md).  
  
 Os declaradores abstratos podem ser complexos. Os parênteses em um declarador abstrato complexo especificam uma determinada interpretação, como fazem no caso dos declaradores complexos em declarações.  
  
 Estes exemplos ilustram declaradores abstratos:  
  
```  
int *         // The type name for a pointer to type int:  
  
int *[3]      // An array of three pointers to int  
  
int (*) [5]   // A pointer to an array of five int  
  
int *()       // A function with no parameter specification  
              // returning a pointer to int  
  
// A pointer to a function taking no arguments and   
// returning an int  
  
int (*) ( void )    
  
// An array of an unspecified number of constant pointers to   
// functions each with one parameter that has type unsigned int   
// and an unspecified number of other parameters returning an int   
  
int (*const []) ( unsigned int, ... )  
```  
  
> [!NOTE]
>  O declarador abstrato que consiste em um conjunto de parênteses vazios, **( )**, não é permitido porque é ambíguo. É impossível determinar se o lugar do identificador implícito é dentro dos parênteses (nesse caso, ele é um tipo não modificado) ou antes dos parênteses (nesse caso, ele é um tipo de função).  
  
## <a name="see-also"></a>Consulte também  
 [Declaradores e declarações de variável](../c-language/declarators-and-variable-declarations.md)
