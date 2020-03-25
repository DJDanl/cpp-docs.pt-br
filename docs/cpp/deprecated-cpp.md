---
title: deprecated (C++)
ms.date: 03/28/2017
f1_keywords:
- deprecated_cpp
helpviewer_keywords:
- __declspec keyword [C++], deprecated
- deprecated __declspec keyword
ms.assetid: beef1129-9434-4cb3-8392-f1eb29e04805
ms.openlocfilehash: e4689d3cb1a1757e2ac3bf4ca9eef7670ad5c655
ms.sourcegitcommit: 857fa6b530224fa6c18675138043aba9aa0619fb
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/24/2020
ms.locfileid: "80189475"
---
# <a name="deprecated-c"></a>deprecated (C++)

Este tópico é sobre a declaração declspec preterida específica da Microsoft. Para obter informações sobre o atributo `[[deprecated]]` do c++ 14 e orientação sobre quando usar esse atributo versus o declspec ou pragma específico da Microsoft, consulte [ C++ atributos padrão](attributes.md).

Com as exceções indicadas abaixo, a Declaração **preterida** oferece a mesma funcionalidade que o pragma [preterido](../preprocessor/deprecated-c-cpp.md) :

- A Declaração **preterida** permite que você especifique formas específicas de sobrecargas de função como preteridas, enquanto o formulário pragma se aplica a todas as formas sobrecarregadas de um nome de função.

- A Declaração **preterida** permite especificar uma mensagem que será exibida no momento da compilação. O texto da mensagem pode ser de uma macro.

- As macros só podem ser marcadas como preteridas com o pragma **preterido** .

Se o compilador encontrar o uso de um identificador preterido ou do atributo de [`[[deprecated]]`](attributes.md) padrão, um aviso de [C4996](../error-messages/compiler-warnings/compiler-warning-level-3-c4996.md) será gerado.

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

## <a name="see-also"></a>Confira também

[__declspec](../cpp/declspec.md)<br/>
[Palavras-chave](../cpp/keywords-cpp.md)
