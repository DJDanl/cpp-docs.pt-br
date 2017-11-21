---
title: NOME (C/C++) | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-tools
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords: name
dev_langs: C++
helpviewer_keywords: NAME .def file statement
ms.assetid: 5c9b6bd8-9275-46a5-afba-f17a5936dc26
caps.latest.revision: "7"
author: corob-msft
ms.author: corob
manager: ghogen
ms.openlocfilehash: 46bbbef9df3f68f322196962042039b32b4e0113
ms.sourcegitcommit: ebec1d449f2bd98aa851667c2bfeb7e27ce657b2
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/24/2017
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