---
title: C2482 de erro do compilador | Microsoft Docs
ms.custom: 
ms.date: 09/15/2017
ms.reviewer: 
ms.suite: 
ms.technology: cpp-tools
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords: C2482
dev_langs: C++
helpviewer_keywords: C2482
ms.assetid: 98c87da2-625c-4cc2-9bf7-78d15921e779
caps.latest.revision: "9"
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload: cplusplus
ms.openlocfilehash: c4a5d081e7a19f09f10e40e3799f724f44b295fc
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
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
