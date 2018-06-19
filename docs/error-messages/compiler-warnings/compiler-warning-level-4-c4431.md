---
title: Compilador (nível 4) de aviso C4431 | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- C4431
dev_langs:
- C++
helpviewer_keywords:
- C4431
ms.assetid: 58434ab6-dd8d-427b-953a-602fb7453ae6
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 2bb5a76a1ddf1f1104fe88511c9bf9bf88bf6602
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
ms.locfileid: "33292250"
---
# <a name="compiler-warning-level-4-c4431"></a>Compilador C4431 de aviso (nível 4)
faltando especificador de tipo - int assumido. Observação: C não suporta mais default-int  
  
 Esse erro pode ser gerado como resultado do trabalho de conformidade do compilador que foi feito para o Visual C++ 2005: Visual C++ não cria mais identificadores não tipados como int por padrão. O tipo de um identificador deve ser especificado explicitamente.  
  
 Esse aviso é desativada por padrão. Consulte [compilador avisos que está desativado por padrão](../../preprocessor/compiler-warnings-that-are-off-by-default.md) para obter mais informações.  
  
## <a name="example"></a>Exemplo  
 O exemplo a seguir gera C4431.  
  
```  
// C4431.c  
// compile with: /c /W4  
#pragma warning(default:4431)  
i;   // C4431  
int i;   // OK  
```