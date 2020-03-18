---
title: pragma preterido
ms.date: 08/29/2019
f1_keywords:
- vc-pragma.deprecated
helpviewer_keywords:
- deprecated pragma
- pragmas, deprecated
ms.assetid: 9c046f12-7875-499a-8d5d-12f8642fed2d
ms.openlocfilehash: 5694c5175ff23952c601884243b428a842278b7d
ms.sourcegitcommit: 63784729604aaf526de21f6c6b62813882af930a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/17/2020
ms.locfileid: "79446485"
---
# <a name="deprecated-pragma"></a>pragma preterido

O pragma **preterido** permite que você indique que uma função, tipo ou qualquer outro identificador pode não ter mais suporte em uma versão futura ou não deve mais ser usado.

> [!NOTE]
> Para obter informações sobre o atributo `[[deprecated]]` do C++ 14 e orientação sobre quando usar esse atributo em vez do modificador de `__declspec(deprecated)` da Microsoft ou o pragma **preterido** , consulte [ C++atributos em ](../cpp/attributes.md).

## <a name="syntax"></a>Sintaxe

> **#pragma preterido (** *identifier1* [ **,** *identifier2* ...] **)**

## <a name="remarks"></a>Comentários

Quando o compilador encontra um identificador especificado por um pragma **substituído** , ele emite o aviso do compilador [C4995](../error-messages/compiler-warnings/compiler-warning-level-3-c4995.md).

Você pode preterir nomes de macro. Coloque o nome da macro entre aspas. Caso contrário, haverá uma expansão na macro.

Como o pragma **preterido** funciona em todos os identificadores correspondentes e não leva em conta as assinaturas, não é a melhor opção para a substituição de versões específicas de funções sobrecarregadas. Qualquer nome de função correspondente que é colocado no escopo dispara o aviso.

Recomendamos que você use o atributo `[[deprecated]]` do C++ 14, quando possível, em vez do pragma **preterido** . O modificador de Declaração [__declspec (preterido)](../cpp/deprecated-cpp.md) específico da Microsoft também é uma opção melhor em muitos casos do que o pragma **preterido** . O atributo `[[deprecated]]` e o modificador `__declspec(deprecated)` permitem que você especifique o status preterido para formulários específicos de funções sobrecarregadas. O aviso de diagnóstico só aparece em referências à função sobrecarregada específica à qual o atributo ou o modificador se aplica.

## <a name="example"></a>{1&gt;Exemplo&lt;1}

```cpp
// pragma_directive_deprecated.cpp
// compile with: /W3
#include <stdio.h>
void func1(void) {
}

void func2(void) {
}

int main() {
   func1();
   func2();
   #pragma deprecated(func1, func2)
   func1();   // C4995
   func2();   // C4995
}
```

O exemplo a seguir mostra como preterir uma classe:

```cpp
// pragma_directive_deprecated2.cpp
// compile with: /W3
#pragma deprecated(X)
class X {  // C4995
public:
   void f(){}
};

int main() {
   X x;   // C4995
}
```

## <a name="see-also"></a>Consulte também

[Diretivas pragma e a palavra-chave __pragma](../preprocessor/pragma-directives-and-the-pragma-keyword.md)