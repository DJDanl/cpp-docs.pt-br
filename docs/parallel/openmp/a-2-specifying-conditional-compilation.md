---
title: Especificação de compilação condicional a. 2 | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-parallel
ms.topic: conceptual
dev_langs:
- C++
ms.assetid: de4a21b9-f987-4738-9f13-c4795f6f2dff
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: d54245a2df2f38bed2674a3bb3923f8212d35459
ms.sourcegitcommit: 7019081488f68abdd5b2935a3b36e2a5e8c571f8
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/07/2018
ms.locfileid: "33690589"
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