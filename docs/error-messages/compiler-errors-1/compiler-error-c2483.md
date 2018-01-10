---
title: C2483 de erro do compilador | Microsoft Docs
ms.custom: 
ms.date: 09/15/2017
ms.reviewer: 
ms.suite: 
ms.technology: cpp-tools
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords: C2483
dev_langs: C++
helpviewer_keywords: C2483
ms.assetid: 5762b325-914b-442d-a604-e4617ba04038
caps.latest.revision: "10"
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload: cplusplus
ms.openlocfilehash: 5f7f9f30724c02d44e054bf16ff1460370c30e06
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="compiler-error-c2483"></a>C2483 de erro do compilador

>'*identificador*': o objeto com o construtor ou destruidor não pode ser declarado 'thread'

Essa mensagem de erro é obsoleta no Visual Studio 2015 e versões posteriores. Nas versões anteriores, as variáveis declaradas com o `thread` atributo não pode ser inicializado com um construtor ou outra expressão que requer avaliação do tempo de execução. Uma expressão estática é necessário para inicializar `thread` dados.

## <a name="example"></a>Exemplo

O exemplo a seguir gera C2483 no Visual Studio 2013 e versões anteriores.

```cpp
// C2483.cpp
// compile with: /c
__declspec(thread) struct A {
   A(){}
   ~A(){}
} aa;   // C2483 error  

__declspec(thread) struct B {} b;   // OK
```

## <a name="see-also"></a>Consulte também

[thread](../../cpp/thread.md)