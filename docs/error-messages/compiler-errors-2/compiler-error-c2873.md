---
title: C2873 de erro do compilador | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-tools
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords:
- C2873
dev_langs:
- C++
helpviewer_keywords:
- C2873
ms.assetid: 7a10036b-400e-4364-bd2f-dcd7370c5e28
caps.latest.revision: 
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: 34c06abc5824f6ac08de88f8c155ed0bba35cf9d
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="compiler-error-c2873"></a>C2873 de erro do compilador
'symbol': símbolo não pode ser usado em uma declaração de using  
  
 Um `using` diretiva está falta um [namespace](../../cpp/namespaces-cpp.md) palavra-chave. Isso faz com que o compilador a interpretar incorretamente o código como um [usando declaração](../../cpp/using-declaration.md) em vez de [usando diretiva](../../cpp/namespaces-cpp.md#using_directives).