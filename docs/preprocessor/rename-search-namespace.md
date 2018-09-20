---
title: rename_search_namespace | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-tools
ms.topic: reference
f1_keywords:
- rename_search_namespace
dev_langs:
- C++
helpviewer_keywords:
- rename_search_namespace attribute
ms.assetid: 47c9d7fd-59dc-4c62-87a1-9011a0040167
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: a4350492921c59d4bda4ead37933e4c2242b7df9
ms.sourcegitcommit: 799f9b976623a375203ad8b2ad5147bd6a2212f0
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/19/2018
ms.locfileid: "46411151"
---
# <a name="renamesearchnamespace"></a>rename_search_namespace
**Específico do C++**  
  
Tem a mesma funcionalidade que o [rename_namespace](../preprocessor/rename-namespace.md) do atributo, mas é usado em bibliotecas de tipos que você usar o `#import` diretiva com o [auto_search](../preprocessor/auto-search.md) atributo.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
rename_search_namespace("NewName")  
```  
  
### <a name="parameters"></a>Parâmetros  
*NewName*  
O nome do novo namespace.  
  
## <a name="remarks"></a>Comentários  
 
**FIM de específico de C++**  
  
## <a name="see-also"></a>Consulte também  
 
[atributos de #import](../preprocessor/hash-import-attributes-cpp.md)<br/>
[#import diretiva](../preprocessor/hash-import-directive-cpp.md)