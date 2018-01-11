---
title: tlbid | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-tools
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords: tlbid
dev_langs: C++
helpviewer_keywords: tlbid attribute
ms.assetid: 54b06785-191b-4e77-a9a5-485f2b4acb09
caps.latest.revision: "4"
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload: cplusplus
ms.openlocfilehash: 812b105fc02782b611b3f55061e448062dcd07c7
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
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