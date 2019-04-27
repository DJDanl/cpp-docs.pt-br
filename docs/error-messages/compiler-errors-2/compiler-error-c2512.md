---
title: Erro do compilador C2512
ms.date: 02/09/2018
f1_keywords:
- C2512
helpviewer_keywords:
- C2512
ms.assetid: 15206da9-1164-451a-b869-280e00711aad
ms.openlocfilehash: 16a1da0e882cd178c9e01737480d74eb23c7c38c
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62164820"
---
# <a name="compiler-error-c2512"></a>Erro do compilador C2512

> '*identificador*': nenhum construtor padrão apropriado disponível

Um *construtor padrão*, um construtor que não requer nenhum argumento, não está disponível para a classe especificada, estrutura ou união. O compilador fornece um construtor padrão somente se nenhum construtor definido pelo usuário é fornecidas.

Se você fornecer um construtor que aceita um parâmetro não nulo e para permitir que sua classe a ser criado sem parâmetros (por exemplo, como os elementos de uma matriz), você também deve fornecer um construtor padrão. O construtor padrão pode ser um construtor com valores padrão para todos os parâmetros.

## <a name="example"></a>Exemplo

Uma causa comum de erro C2512 é quando você define um construtor de classe ou struct que aceita argumentos e, em seguida, tentar declarar uma instância de sua classe ou struct sem nenhum argumento. Por exemplo, `struct B` a seguir declara um construtor que exige um `char *` argumento, mas não uma que não usa argumentos. No `main`, uma instância de B é declarada, mas nenhum argumento for fornecido. O compilador gera C2512 porque ele não é possível encontrar um construtor padrão para o B.

```cpp
// C2512.cpp
// Compile with: cl /W4 c2512.cpp
// C2512 expected
struct B {
   B (char *) {}
   // Uncomment the following line to fix.
   // B() {}
};

int main() {
   B b;   // C2512 - This requires a default constructor
}
```

Você pode corrigir esse problema definindo um construtor padrão para sua estrutura ou classe, como `B() {}`, ou um construtor onde todos os argumentos têm valores padrão, como `B (char * = nullptr) {}`.
