---
title: C2482 de erro do compilador | Microsoft Docs
ms.custom: ''
ms.date: 09/15/2017
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- C2482
dev_langs:
- C++
helpviewer_keywords:
- C2482
ms.assetid: 98c87da2-625c-4cc2-9bf7-78d15921e779
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: f2c4725dd357854db504272e5b8b9d88641b143d
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
---
# <a name="compiler-error-c2482"></a>C2482 de erro do compilador

>'*identificador*': inicialização dinâmica de dados 'thread' não permitidos

Essa mensagem de erro é obsoleta no Visual Studio 2015 e versões posteriores. Nas versões anteriores, as variáveis declaradas usando o `thread` atributo não pode ser inicializado com uma expressão que requer avaliação do tempo de execução. Uma expressão estática é necessário para inicializar `thread` dados.

## <a name="example"></a>Exemplo

O exemplo a seguir gera C2482 no Visual Studio 2013 e anteriores:

```cpp
// C2482.cpp
// compile with: /c
#define Thread __declspec( thread )
Thread int tls_i = tls_i;   // C2482

int j = j;   // OK in C++; C error
Thread int tls_i = sizeof( tls_i );   // Okay in C and C++
```
