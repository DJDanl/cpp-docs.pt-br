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
ms.openlocfilehash: f5bd922089bcf189c403a97679a593a985603a12
ms.sourcegitcommit: 799f9b976623a375203ad8b2ad5147bd6a2212f0
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/19/2018
ms.locfileid: "46446251"
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
 
[atributos de #import](../preprocessor/hash-import-attributes-cpp.md)<br/>
[#import diretiva](../preprocessor/hash-import-directive-cpp.md)