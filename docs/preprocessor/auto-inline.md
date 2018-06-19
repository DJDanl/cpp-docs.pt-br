---
title: auto_inline | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-tools
ms.topic: reference
f1_keywords:
- auto_inline_CPP
- vc-pragma.auto_inline
dev_langs:
- C++
helpviewer_keywords:
- pragmas, auto_inline
- auto_inline pragma
ms.assetid: f7624cd1-be76-429a-881c-65c9040acf43
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: de012a31fe68c68d4e64df2d3fa10b44d9112735
ms.sourcegitcommit: 96cdc2da0d8c3783cc2ce03bd280a5430e1ac01d
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/10/2018
ms.locfileid: "33954015"
---
# <a name="autoinline"></a>auto_inline
Exclui todas as funções definidas dentro do intervalo em que **off** especificado a partir do sendo considerados candidatos para expansão inline automática.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
  
#pragma auto_inline( [{on | off}] )  
```  
  
## <a name="remarks"></a>Comentários  
 Para usar o **auto_inline** pragma, coloque-o imediatamente antes e depois (não no) uma definição de função. O pragma entra em vigor na primeira definição de função, após a consideração do pragma.  
  
## <a name="see-also"></a>Consulte também  
 [Diretivas Pragma e a palavra-chave __Pragma](../preprocessor/pragma-directives-and-the-pragma-keyword.md)