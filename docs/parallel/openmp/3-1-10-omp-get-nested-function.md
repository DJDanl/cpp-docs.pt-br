---
title: "3.1.10 função omp_get_nested | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-windows
ms.tgt_pltfrm: 
ms.topic: article
dev_langs:
- C++
ms.assetid: 48736a25-5c6e-4e2d-aad0-421087663a3c
caps.latest.revision: 
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: 36b213ee45018e7cc0ccf3a1cb99dcbd640d4457
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="3110-ompgetnested-function"></a>3.1.10 função omp_get_nested
O `omp_get_nested` função retorna um valor diferente de zero se paralelismo aninhado está habilitado e 0 se ele estiver desabilitado. Para obter mais informações sobre o paralelismo aninhada, consulte a seção 3.1.9 na página 40. O formato é o seguinte:  
  
```  
#include <omp.h>  
int omp_get_nested(void);  
```  
  
 Se uma implementação não implementar paralelismo aninhado, essa função sempre retorna 0.