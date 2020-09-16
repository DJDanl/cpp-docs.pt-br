---
title: deprecated (C++)
ms.date: 03/28/2017
f1_keywords:
- deprecated_cpp
helpviewer_keywords:
- __declspec keyword [C++], deprecated
- deprecated __declspec keyword
ms.assetid: beef1129-9434-4cb3-8392-f1eb29e04805
ms.openlocfilehash: 44cb33bae43b32b12dda95423aec5484f61aa596
ms.sourcegitcommit: c1fd917a8c06c6504f66f66315ff352d0c046700
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/16/2020
ms.locfileid: "90683410"
---
# <a name="deprecated-c"></a>deprecated (C++)

Este tópico é sobre a declaração declspec preterida específica da Microsoft. Para obter informações sobre o atributo C++ 14 `[[deprecated]]` e orientação sobre quando usar esse atributo versus o declspec ou pragma específico da Microsoft, consulte [atributos padrão do C++](attributes.md).

Com as exceções indicadas abaixo, a **`deprecated`** declaração oferece a mesma funcionalidade que o pragma [preterido](../preprocessor/deprecated-c-cpp.md) :

- A **`deprecated`** declaração permite que você especifique formas específicas de sobrecargas de função como preteridas, enquanto o formulário pragma se aplica a todas as formas sobrecarregadas de um nome de função.

- A **`deprecated`** declaração permite que você especifique uma mensagem que será exibida no momento da compilação. O texto da mensagem pode ser de uma macro.

- As macros só podem ser marcadas como preteridas com o **`deprecated`** pragma.

Se o compilador encontrar o uso de um identificador substituído ou o atributo padrão [`[[deprecated]]`](attributes.md) , um aviso de [C4996](../error-messages/compiler-warnings/compiler-warning-level-3-c4996.md) será gerado.

## <a name="examples"></a>Exemplos

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
