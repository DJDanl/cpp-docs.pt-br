---
title: VERSÃO (C/C++) | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.reviewer: ''
ms.suite: ''
ms.technology:
- cpp-tools
ms.tgt_pltfrm: ''
ms.topic: article
f1_keywords:
- VERSION
dev_langs:
- C++
helpviewer_keywords:
- VERSION .def file statement
ms.assetid: 3533b97c-5183-45f9-9ca8-4e63462b5d26
caps.latest.revision: 7
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: 63ea65a8e3732ee17cc30b3382aa7ebc56e48f59
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="version-cc"></a>VERSION (C/C++)
Informa LINK para colocar um número no cabeçalho do arquivo .exe ou DLL.  
  
```  
VERSION major[.minor]  
```  
  
## <a name="remarks"></a>Comentários  
 O *principais* e *secundária* argumentos são números decimais no intervalo de 0 a 65.535. O padrão é a versão 0.0.  
  
 É uma maneira equivalente para especificar um número de versão com o [informações de versão](../../build/reference/version-version-information.md) (/ versão) opção.  
  
## <a name="see-also"></a>Consulte também  
 [Regras para instruções de definição do módulo](../../build/reference/rules-for-module-definition-statements.md)