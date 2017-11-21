---
title: "3.1.10 função omp_get_nested | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-windows
ms.tgt_pltfrm: 
ms.topic: article
dev_langs: C++
ms.assetid: 48736a25-5c6e-4e2d-aad0-421087663a3c
caps.latest.revision: "6"
author: mikeblome
ms.author: mblome
manager: ghogen
ms.openlocfilehash: 0447fd872a44d2c1eefb751e501eba4df5ec8b8f
ms.sourcegitcommit: ebec1d449f2bd98aa851667c2bfeb7e27ce657b2
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/24/2017
---
# <a name="3110-ompgetnested-function"></a>3.1.10 função omp_get_nested
O `omp_get_nested` função retorna um valor diferente de zero se paralelismo aninhado está habilitado e 0 se ele estiver desabilitado. Para obter mais informações sobre o paralelismo aninhada, consulte a seção 3.1.9 na página 40. O formato é o seguinte:  
  
```  
#include <omp.h>  
int omp_get_nested(void);  
```  
  
 Se uma implementação não implementar paralelismo aninhado, essa função sempre retorna 0.