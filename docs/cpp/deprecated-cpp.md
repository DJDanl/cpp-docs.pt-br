---
title: deprecated (C++)
ms.date: 03/28/2017
f1_keywords:
- deprecated_cpp
helpviewer_keywords:
- __declspec keyword [C++], deprecated
- deprecated __declspec keyword
ms.assetid: beef1129-9434-4cb3-8392-f1eb29e04805
ms.openlocfilehash: 34f9c10cd898b0359463d5933141822576fa4a11
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50485846"
---
# <a name="deprecated-c"></a>deprecated (C++)

Este tópico é sobre específicos da Microsoft preterido declspec declaração. Para obter informações sobre o c++14 `[[deprecated]]` atributo e diretrizes sobre quando usar esse atributo versus o declspec específico da Microsoft ou o pragma, consulte [atributos padrão do C++](attributes.md).

Com as exceções indicadas abaixo, o **preterido** declaração oferece a mesma funcionalidade que o [preterida](../preprocessor/deprecated-c-cpp.md) pragma:

- O **preterido** declaração permite especificar formatos específicos de sobrecargas de função como preteridos, enquanto que o formato do pragma se aplica a todos os formatos sobrecarregados de um nome de função.

- O **preterido** declaração permite que você especifique uma mensagem que será exibido no tempo de compilação. O texto da mensagem pode ser de uma macro.

- Macros podem ser marcadas como preteridas com o **preterido** pragma.

Se o compilador encontra o uso de um identificador preterido ou a standard [ `[[deprecated]]` ](attributes.md) atributo, uma [C4996](../error-messages/compiler-warnings/compiler-warning-level-3-c4996.md) aviso é gerado.

## <a name="example"></a>Exemplo

O exemplo a seguir mostra como marcar funções como preteridas e como especificar uma mensagem que será exibida no tempo de compilação, quando a função preterida for usada.

```cpp
// deprecated.cpp
// compile with: /W3
#define MY_TEXT "function is deprecated"
void func1(void) {}
__declspec(deprecated) void func1(int) {}
__declspec(deprecated("** this is a deprecated function **")) void func2(int) {}
__declspec(deprecated(MY_TEXT)) void func3(int) {}

int main() {
   func1();
   func1(1);   // C4996
   func2(1);   // C4996
   func3(1);   // C4996
}
```

## <a name="example"></a>Exemplo

O exemplo a seguir mostra como marcar classes como preteridas e como especificar uma mensagem que será exibida no tempo de compilação, quando a classe preterida for usada.

```cpp
// deprecate_class.cpp
// compile with: /W3
struct __declspec(deprecated) X {
   void f(){}
};

struct __declspec(deprecated("** X2 is deprecated **")) X2 {
   void f(){}
};

int main() {
   X x;   // C4996
   X2 x2;   // C4996
}
```

## <a name="see-also"></a>Consulte também

[__declspec](../cpp/declspec.md)<br/>
[Palavras-chave](../cpp/keywords-cpp.md)