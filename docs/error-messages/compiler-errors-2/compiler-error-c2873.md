---
title: C2873 de erro do compilador | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- C2873
dev_langs:
- C++
helpviewer_keywords:
- C2873
ms.assetid: 7a10036b-400e-4364-bd2f-dcd7370c5e28
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 94a04d650729bdda949754c5070a6c307d390929
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
ms.locfileid: "33244372"
---
# <a name="compiler-error-c2873"></a>C2873 de erro do compilador
'symbol': símbolo não pode ser usado em uma declaração de using  
  
 Um `using` diretiva está falta um [namespace](../../cpp/namespaces-cpp.md) palavra-chave. Isso faz com que o compilador a interpretar incorretamente o código como um [usando declaração](../../cpp/using-declaration.md) em vez de [usando diretiva](../../cpp/namespaces-cpp.md#using_directives).