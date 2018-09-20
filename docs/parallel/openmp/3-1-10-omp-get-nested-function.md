---
title: 3.1.10 função omp_get_nested | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-parallel
ms.topic: conceptual
dev_langs:
- C++
ms.assetid: 48736a25-5c6e-4e2d-aad0-421087663a3c
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: d019dd757080bbc87ff7aaab1a8745b2a3156b39
ms.sourcegitcommit: 799f9b976623a375203ad8b2ad5147bd6a2212f0
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/19/2018
ms.locfileid: "46392268"
---
# <a name="3110-ompgetnested-function"></a>3.1.10 função omp_get_nested

O `omp_get_nested` função retorna um valor diferente de zero se o paralelismo aninhado estiver habilitado e 0 se ele estiver desabilitado. Para obter mais informações sobre o paralelismo aninhada, consulte a seção 3.1.9 na página de 40. O formato é o seguinte:

```
#include <omp.h>
int omp_get_nested(void);
```

Se uma implementação não implementar paralelismo aninhado, essa função sempre retorna 0.