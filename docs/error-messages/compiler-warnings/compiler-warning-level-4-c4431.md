---
title: "Compilador aviso (nível 4) C4431 | Documentos do Microsoft"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords:
- C4431
dev_langs:
- C++
helpviewer_keywords:
- C4431
ms.assetid: 58434ab6-dd8d-427b-953a-602fb7453ae6
caps.latest.revision: 9
author: corob-msft
ms.author: corob
manager: ghogen
translation.priority.ht:
- cs-cz
- de-de
- es-es
- fr-fr
- it-it
- ja-jp
- ko-kr
- pl-pl
- pt-br
- ru-ru
- tr-tr
- zh-cn
- zh-tw
translationtype: Machine Translation
ms.sourcegitcommit: 3168772cbb7e8127523bc2fc2da5cc9b4f59beb8
ms.openlocfilehash: bf21f5d82dbb9a1b271ff24b1267889d712ab49e
ms.lasthandoff: 02/25/2017

---
# <a name="compiler-warning-level-4-c4431"></a>Compilador C4431 de aviso (nível 4)
faltando especificador de tipo - int assumido. Observação: C não suporta mais default-int  
  
 Esse erro pode ser gerado como resultado de trabalho de conformidade do compilador que foi feito no Visual C++ 2005: Visual C++ não cria mais identificadores não tipados como int por padrão. O tipo de um identificador deve ser especificado explicitamente.  
  
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
