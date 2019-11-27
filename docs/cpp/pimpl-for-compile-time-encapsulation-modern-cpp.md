---
title: Pimpl para encapsulamento do tempo de compilação (C++ moderno)
ms.date: 11/04/2016
ms.topic: conceptual
ms.assetid: c3e8a90a-b328-4990-82bb-e1b147f76e07
ms.openlocfilehash: f1eb06ad3a52be486f085babf699677951b1ee71
ms.sourcegitcommit: 654aecaeb5d3e3fe6bc926bafd6d5ace0d20a80e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 11/20/2019
ms.locfileid: "74245184"
---
# <a name="pimpl-for-compile-time-encapsulation-modern-c"></a>Pimpl para encapsulamento do tempo de compilação (C++ moderno)

O *idioma pimpl* é uma técnica C++ moderna para ocultar a implementação, para minimizar o acoplamento e para separar interfaces. Pimpl é curto para "ponteiro para implementação". Talvez você já esteja familiarizado com o conceito, mas conheça-o por outros nomes, como Cheshire Cat ou idioma do firewall do compilador.

## <a name="why-use-pimpl"></a>Por que usar o pimpl?

Veja como o idioma pimpl pode melhorar o ciclo de vida do desenvolvimento de software:

- Minimização de dependências de compilação.

- Separação de interface e implementação.

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

O idioma pimpl evita a recompilação em cascata e layouts de objeto frágil. Ele é adequado para tipos populares (transitivamente).

## <a name="pimpl-implementation"></a>Implementação de Pimpl

Defina a classe `impl` no arquivo. cpp.

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

Considere se é para adicionar suporte para especialização de permuta sem lançamento.

## <a name="see-also"></a>Consulte também

[Bem-vindo de volta paraC++](../cpp/welcome-back-to-cpp-modern-cpp.md)<br/>
[Referência da linguagem C++](../cpp/cpp-language-reference.md)<br/>
[Biblioteca padrão C++](../standard-library/cpp-standard-library-reference.md)
