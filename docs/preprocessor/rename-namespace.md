---
title: rename_namespace | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-tools
ms.tgt_pltfrm: 
ms.topic: reference
f1_keywords:
- rename_namespace
dev_langs:
- C++
helpviewer_keywords:
- rename_namespace attribute
ms.assetid: 45006d2b-36cd-4bec-98b9-3b8ec45299e3
caps.latest.revision: 
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: 37b2c01479cb489f7ed573f55a48f5807161bf63
ms.sourcegitcommit: d51ed21ab2b434535f5c1d553b22e432073e1478
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 02/23/2018
---
# <a name="renamenamespace"></a>rename_namespace
**Específicas do C++**  
  
 Renomeia o namespace que contém o conteúdo da biblioteca de tipos.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
rename_namespace("NewName")  
```  
  
#### <a name="parameters"></a>Parâmetros  
 `NewName`  
 O nome do novo namespace.  
  
## <a name="remarks"></a>Comentários  
 Ele usa um único argumento, *NewName*, que especifica o novo nome para o namespace.  
  
 Para remover o namespace, use o [no_namespace](../preprocessor/no-namespace.md) atributo em vez disso.  
  
 **TÉRMINO específicas do C++**  
  
## <a name="see-also"></a>Consulte também  
 [atributos de #import](../preprocessor/hash-import-attributes-cpp.md)   
 [#import diretiva](../preprocessor/hash-import-directive-cpp.md)