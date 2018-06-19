---
title: inject_statement | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-tools
ms.topic: reference
f1_keywords:
- inject_statement
dev_langs:
- C++
helpviewer_keywords:
- inject_statement attribute
ms.assetid: 07d6f0f4-d9fb-4e18-aa62-f235f142ff5e
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 115f5b3d7012ae3e9073d81e0c1005dcb513e045
ms.sourcegitcommit: d55ac596ba8f908f5d91d228dc070dad31cb8360
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/07/2018
ms.locfileid: "33849334"
---
# <a name="injectstatement"></a>inject_statement
**Específicas do C++**  
  
 Insere seu argumento como texto de origem no cabeçalho da biblioteca de tipos.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
inject_statement("source_text")  
```  
  
#### <a name="parameters"></a>Parâmetros  
 `source_text`  
 Texto de origem a ser inserido no arquivo de cabeçalho da biblioteca de tipos.  
  
## <a name="remarks"></a>Comentários  
 O texto é colocado no início da declaração do namespace que envolve o conteúdo da biblioteca de tipos no arquivo de cabeçalho.  
  
 **TÉRMINO específicas do C++**  
  
## <a name="see-also"></a>Consulte também  
 [atributos de #import](../preprocessor/hash-import-attributes-cpp.md)   
 [#import diretiva](../preprocessor/hash-import-directive-cpp.md)