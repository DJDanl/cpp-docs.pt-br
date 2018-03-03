---
title: C2818 de erro do compilador | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-tools
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords:
- C2818
dev_langs:
- C++
helpviewer_keywords:
- C2818
ms.assetid: 715fc7c9-0c6d-452b-b7f5-1682cea5e907
caps.latest.revision: 
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: f409acd9ba18972ca414c81cbcabd279e8903bcd
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="compiler-error-c2818"></a>C2818 de erro do compilador
'aplicação de operador ->' sobrecarregado é recursiva através do tipo 'type'  
  
 Uma redefinição do operador de acesso de membro de classe contém uma recursiva `return` instrução. Para redefinir o `->` operador com recursão, você deve mover a rotina recursiva para uma função distinta chamada do operador substituir a função.