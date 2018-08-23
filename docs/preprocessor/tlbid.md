---
title: tlbid | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-tools
ms.topic: reference
f1_keywords:
- tlbid
dev_langs:
- C++
helpviewer_keywords:
- tlbid attribute
ms.assetid: 54b06785-191b-4e77-a9a5-485f2b4acb09
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 1ec0150e63209728cf2f02c854fe03702b8a45b4
ms.sourcegitcommit: d4c803bd3a684d7951bf88dcecf1f14af43ae411
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/10/2018
ms.locfileid: "42539150"
---
# <a name="tlbid"></a>tlbid
**Específico do C++**  
  
Permite carregar bibliotecas diferentes de biblioteca de tipos primárias.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
tlbid(number)  
```  
  
### <a name="parameters"></a>Parâmetros  
*número*  
O número da biblioteca de tipos em `filename`.  
  
## <a name="remarks"></a>Comentários  
 
Se várias bibliotecas de tipos são criadas em uma única DLL, é possível carregar bibliotecas que não sejam a biblioteca de tipos principal usando **tlbid**.  
  
Por exemplo:  
  
```  
#import <MyResource.dll> tlbid(2)  
```  
  
equivale a:  
  
```  
LoadTypeLib("MyResource.dll\\2");  
```  
  
**FIM de específico de C++**  
  
## <a name="see-also"></a>Consulte também  
 
[atributos de #import](../preprocessor/hash-import-attributes-cpp.md)   
[#import diretiva](../preprocessor/hash-import-directive-cpp.md)