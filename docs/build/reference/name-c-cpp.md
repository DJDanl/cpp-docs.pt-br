---
title: NOME (C/C++) | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-tools
ms.topic: reference
f1_keywords:
- name
dev_langs:
- C++
helpviewer_keywords:
- NAME .def file statement
ms.assetid: 5c9b6bd8-9275-46a5-afba-f17a5936dc26
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: a94b82a65cf68d9802d7bf9620e4128ab6b35071
ms.sourcegitcommit: be2a7679c2bd80968204dee03d13ca961eaa31ff
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/03/2018
---
# <a name="name-cc"></a>NAME (C/C++)
Especifica um nome para o arquivo de saída principal.  
  
```  
NAME [application][BASE=address]  
```  
  
## <a name="remarks"></a>Comentários  
 É uma maneira equivalente para especificar um nome de arquivo de saída com o [/out](../../build/reference/out-output-file-name.md) é a opção de vinculador e uma maneira equivalente para definir o endereço base com o [/BASE](../../build/reference/base-base-address.md) opção de vinculador. Se ambos forem especificados, OUT substitui **nome**.  
  
 Se você criar uma DLL, o nome afetará apenas o nome da DLL.  
  
## <a name="see-also"></a>Consulte também  
 [Regras para instruções de definição do módulo](../../build/reference/rules-for-module-definition-statements.md)