---
title: C2483 de erro do compilador | Microsoft Docs
ms.custom: ''
ms.date: 09/15/2017
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- C2483
dev_langs:
- C++
helpviewer_keywords:
- C2483
ms.assetid: 5762b325-914b-442d-a604-e4617ba04038
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 0a10fd33ebeef43904db964fc327fb749029f963
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
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