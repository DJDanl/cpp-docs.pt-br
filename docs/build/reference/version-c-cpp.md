---
title: VERSÃO (C/C++) | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-tools
ms.topic: reference
f1_keywords:
- VERSION
dev_langs:
- C++
helpviewer_keywords:
- VERSION .def file statement
ms.assetid: 3533b97c-5183-45f9-9ca8-4e63462b5d26
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: fcaf4e113af6182a2d3d735e4c668b62336e2c79
ms.sourcegitcommit: be2a7679c2bd80968204dee03d13ca961eaa31ff
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/03/2018
ms.locfileid: "32375016"
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