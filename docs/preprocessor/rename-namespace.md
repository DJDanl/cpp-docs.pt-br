---
title: rename_namespace | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-tools
ms.topic: reference
f1_keywords:
- rename_namespace
dev_langs:
- C++
helpviewer_keywords:
- rename_namespace attribute
ms.assetid: 45006d2b-36cd-4bec-98b9-3b8ec45299e3
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: a51114787dde2f858a8409538083282ef292d599
ms.sourcegitcommit: d55ac596ba8f908f5d91d228dc070dad31cb8360
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/07/2018
ms.locfileid: "33839385"
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