---
title: C2818 de erro do compilador | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- C2818
dev_langs:
- C++
helpviewer_keywords:
- C2818
ms.assetid: 715fc7c9-0c6d-452b-b7f5-1682cea5e907
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 10d7f419d528fcd2445b82e29d92442002624909
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
---
# <a name="compiler-error-c2818"></a>C2818 de erro do compilador
'aplicação de operador ->' sobrecarregado é recursiva através do tipo 'type'  
  
 Uma redefinição do operador de acesso de membro de classe contém uma recursiva `return` instrução. Para redefinir o `->` operador com recursão, você deve mover a rotina recursiva para uma função distinta chamada do operador substituir a função.