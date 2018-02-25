---
title: no_namespace | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-tools
ms.tgt_pltfrm: 
ms.topic: reference
f1_keywords:
- no_namespace
dev_langs:
- C++
helpviewer_keywords:
- no_namespace attribute
ms.assetid: 5d81b741-a558-451b-b493-1f3b18967337
caps.latest.revision: 
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: 3e6528ce33689dc05fa037bdd6bc110e5e6a0de9
ms.sourcegitcommit: d51ed21ab2b434535f5c1d553b22e432073e1478
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 02/23/2018
---
# <a name="nonamespace"></a>no_namespace
**Específicas do C++**  
  
 Especifica que o nome do namespace não é gerado pelo compilador.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
no_namespace  
```  
  
## <a name="remarks"></a>Comentários  
 O conteúdo da biblioteca de tipos no arquivo de cabeçalho de `#import` normalmente é definido em um namespace. O nome do namespace é especificado no **biblioteca** instrução do arquivo IDL original. Se o atributo `no_namespace` for especificado, esse namespace não será gerado pelo compilador.  
  
 Se você quiser usar um nome de namespace diferentes, use o [rename_namespace](../preprocessor/rename-namespace.md) atributo em vez disso.  
  
 **TÉRMINO específicas do C++**  
  
## <a name="see-also"></a>Consulte também  
 [atributos de #import](../preprocessor/hash-import-attributes-cpp.md)   
 [#import diretiva](../preprocessor/hash-import-directive-cpp.md)