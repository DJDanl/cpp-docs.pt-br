---
title: Erro do compilador C2603
ms.date: 11/04/2016
f1_keywords:
- C2603
helpviewer_keywords:
- C2603
ms.assetid: 9ca520d0-f082-4b65-933d-17c3bcf8b02c
ms.openlocfilehash: 5391aed09b7fd448a9d72ea7cc17cd5c26fc5f04
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62215395"
---
# <a name="compiler-error-c2603"></a>Erro do compilador C2603

> '*função*': Objetos estáticos do excesso escopo de bloco com construtores/destrutores na função

Nas versões do compilador do Visual C++ antes do Visual Studio 2015, ou quando o [/Zc:threadSafeInit-](../../build/reference/zc-threadsafeinit-thread-safe-local-static-initialization.md) opção de compilador for especificada, há um limite de 31 no número de objetos estáticos, você pode ter em uma função embutida visível externamente .

Para resolver esse problema, é recomendável adotar uma versão mais recente do conjunto de ferramentas de compilador do Visual C++, ou se for possível, remova a opção do compilador /Zc:threadSafeInit-. Se isso não for possível, considere a combinação de seus objetos estáticos. Se os objetos forem do mesmo tipo, considere o uso de uma única matriz estática desse tipo e fazer referência a membros individuais conforme necessário.

## <a name="example"></a>Exemplo

O código a seguir gera C2603 e mostra uma maneira de corrigir isso:

```cpp
// C2603.cpp
// Compile by using: cl /W4 /c /Zc:threadSafeInit- C2603.cpp
struct C { C() {} };
extern inline void f1() {
    static C C01, C02, C03, C04, C05, C06, C07, C08, C09, C10;
    static C C11, C12, C13, C14, C15, C16, C17, C18, C19, C20;
    static C C21, C22, C23, C24, C25, C26, C27, C28, C29, C30, C31;
    static C C32;   // C2603 Comment this line out to avoid error
}
```
