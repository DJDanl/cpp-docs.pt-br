---
title: Pimpl para encapsulamento do tempo de compilação (C++ moderno)
ms.date: 11/04/2016
ms.topic: conceptual
ms.assetid: c3e8a90a-b328-4990-82bb-e1b147f76e07
ms.openlocfilehash: 9a73ea1df099003061081d108a3f3f6eef601fb9
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50594357"
---
# <a name="pimpl-for-compile-time-encapsulation-modern-c"></a>Pimpl para encapsulamento do tempo de compilação (C++ moderno)

O *pimpl idiom* é uma técnica de C++ moderna para ocultar a implementação, para minimizar o acoplamento e separar interfaces. Pimpl é "ponteiro para a implementação de" curto para. Você já pode estar familiarizado com o conceito, mas o conheça por outros nomes como gato Cheshire ou Firewall de compilador de linguagem.

## <a name="why-use-pimpl"></a>Por que usar pimpl?

Aqui está como a linguagem pimpl pode melhorar o ciclo de vida de desenvolvimento de software:

- Minimização das dependências de compilação.

- Separação da interface e implementação.

- Portabilidade.

## <a name="pimpl-header"></a>Cabeçalho Pimpl

```cpp
// my_class.h
class my_class {
   //  ... all public and protected stuff goes here ...
private:
   class impl; unique_ptr<impl> pimpl; // opaque type here
};
```

A linguagem pimpl evita cascatas de recompilação e layouts de objeto frágil. Ele é adequado para tipos populares (temporariamente).

## <a name="pimpl-implementation"></a>Implementação de Pimpl

Definir o `impl` classe no arquivo. cpp.

```cpp
// my_class.cpp
class my_class::impl {  // defined privately here
  // ... all private data and functions: all of these
  //     can now change without recompiling callers ...
};
my_class::my_class(): pimpl( new impl )
{
  // ... set impl values ...
}
```

## <a name="best-practices"></a>Práticas recomendadas

Considere a possibilidade de adicionar suporte para a especialização de troca de não lançamento.

## <a name="see-also"></a>Consulte também

[Bem-vindo outra vez ao C++](../cpp/welcome-back-to-cpp-modern-cpp.md)<br/>
[Referência da linguagem C++](../cpp/cpp-language-reference.md)<br/>
[Biblioteca Padrão do C++](../standard-library/cpp-standard-library-reference.md)