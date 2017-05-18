---
title: "Compilador aviso (nível 4) C4611 | Documentos do Microsoft"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-tools
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords:
- C4611
dev_langs:
- C++
helpviewer_keywords:
- C4611
ms.assetid: bd90d0a6-75f9-4e97-968d-dda6773e9fd8
caps.latest.revision: 7
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
ms.translationtype: Machine Translation
ms.sourcegitcommit: 3168772cbb7e8127523bc2fc2da5cc9b4f59beb8
ms.openlocfilehash: ec0b470f6c5b9838f4ec2384b435724be0fa8a05
ms.contentlocale: pt-br
ms.lasthandoff: 02/25/2017

---
# <a name="compiler-warning-level-4-c4611"></a>Compilador C4611 de aviso (nível 4)
interação entre 'function' e destruição de objeto C++ é não-portáteis  
  
 Em algumas plataformas, funções que incluem **catch** pode não oferecer suporte a semântica de objeto C++ de destruição quando estiver fora do escopo.  
  
 Para evitar comportamento inesperado, evite usar **catch** em funções que têm construtores e destruidores.  
  
 Esse aviso é emitido somente uma vez; consulte [aviso pragma](../../preprocessor/warning.md).
