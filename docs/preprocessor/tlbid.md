---
title: tlbid | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-tools
ms.tgt_pltfrm: 
ms.topic: reference
f1_keywords:
- tlbid
dev_langs:
- C++
helpviewer_keywords:
- tlbid attribute
ms.assetid: 54b06785-191b-4e77-a9a5-485f2b4acb09
caps.latest.revision: 
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: 52cb9237537e151e699974fe91c5a7a99725513f
ms.sourcegitcommit: d51ed21ab2b434535f5c1d553b22e432073e1478
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 02/23/2018
---
# <a name="tlbid"></a>tlbid
**Específicas do C++**  
  
 Permite carregar bibliotecas diferentes de biblioteca de tipos primárias.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
tlbid(number)  
```  
  
#### <a name="parameters"></a>Parâmetros  
 `number`  
 O número da biblioteca de tipos em `filename`.  
  
## <a name="remarks"></a>Comentários  
 Caso várias bibliotecas de tipos estejam compiladas em uma única DLL, é possível carregar bibliotecas que não sejam a biblioteca de tipos principal usando `tlbid`.  
  
 Por exemplo:  
  
```  
#import <MyResource.dll> tlbid(2)  
```  
  
 equivale a:  
  
```  
LoadTypeLib("MyResource.dll\\2");  
```  
  
 **TÉRMINO específicas do C++**  
  
## <a name="see-also"></a>Consulte também  
 [atributos de #import](../preprocessor/hash-import-attributes-cpp.md)   
 [#import diretiva](../preprocessor/hash-import-directive-cpp.md)