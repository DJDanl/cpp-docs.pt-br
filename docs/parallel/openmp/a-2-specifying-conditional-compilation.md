---
title: "Especificação de compilação condicional a. 2 | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-windows
ms.tgt_pltfrm: 
ms.topic: article
dev_langs: C++
ms.assetid: de4a21b9-f987-4738-9f13-c4795f6f2dff
caps.latest.revision: "8"
author: mikeblome
ms.author: mblome
manager: ghogen
ms.openlocfilehash: b0888a8bfc3d920ed3338b2ab6182c09cb75097a
ms.sourcegitcommit: ebec1d449f2bd98aa851667c2bfeb7e27ce657b2
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/24/2017
---
# <a name="a2---specifying-conditional-compilation"></a>A.2   Especificando compilação condicional
Os exemplos a seguir ilustram o uso de compilação condicional usando a macro OpenMP `_OPENMP` ([seção 2.2](../../parallel/openmp/2-2-conditional-compilation.md) na página 8). Com OpenMP compilação, a `_OPENMP` macro torna-se definida.  
  
```  
# ifdef _OPENMP   
    printf_s("Compiled by an OpenMP-compliant implementation.\n");  
# endif  
```  
  
 O operador de pré-processador definido permite que mais de uma macro ser testado em uma única diretiva.  
  
```  
# if defined(_OPENMP) && defined(VERBOSE)  
    printf_s("Compiled by an OpenMP-compliant implementation.\n");  
# endif  
```