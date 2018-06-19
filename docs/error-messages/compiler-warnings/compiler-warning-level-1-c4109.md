---
title: Compilador (nível 1) de aviso C4109 | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- C4109
dev_langs:
- C++
helpviewer_keywords:
- C4109
ms.assetid: 9e8d95c6-e05d-47e0-bd87-78974b3cc06c
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: fe0a8e766355dd5f8015fb49bbe584d699b0edaf
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
ms.locfileid: "33272767"
---
# <a name="compiler-warning-level-1-c4109"></a>Compilador C4109 de aviso (nível 1)
identificador inesperado 'Identificador'  
  
 O pragma que contém o identificador inesperado será ignorado.  
  
## <a name="example"></a>Exemplo  
  
```  
// C4109.cpp  
// compile with: /W1 /LD  
#pragma init_seg( abc ) // C4109  
```