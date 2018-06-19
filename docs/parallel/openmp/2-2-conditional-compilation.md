---
title: 2.2 compilação condicional | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-parallel
ms.topic: conceptual
dev_langs:
- C++
ms.assetid: 8f9c914d-736c-48cf-899d-c8029dbe1e32
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: b3d8c7073548c015d9982b721387176a0ca658c2
ms.sourcegitcommit: 7019081488f68abdd5b2935a3b36e2a5e8c571f8
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/07/2018
ms.locfileid: "33685899"
---
# <a name="22-conditional-compilation"></a>2.2 Compilação condicional
O _**OPENMP** nome de macro é definido pelas implementações OpenMP compatível como a constante decimal *yyyymm*, que será o ano e o mês da especificação aprovada. Esta macro não deve ser o assunto de uma **#define** ou um **#undef** diretiva de pré-processamento.  
  
```  
#ifdef _OPENMP  
iam = omp_get_thread_num() + index;  
#endif  
```  
  
 Se fornecedores definam ampliações OpenMP, eles podem especificar macros predefinidas adicionais.