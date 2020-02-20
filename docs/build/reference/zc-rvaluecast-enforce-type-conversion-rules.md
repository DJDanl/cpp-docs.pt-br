---
title: /Zc:rvalueCast (Aplicar regras de conversão de tipo)
ms.date: 02/18/2020
f1_keywords:
- rvaluecast
- /Zc:rvalueCast
- VC.Project.VCCLCompilerTool.EnforceTypeConversionRules
helpviewer_keywords:
- -Zc compiler options (C++)
- rvaluecast
- Enforce type conversion rules
- /Zc compiler options (C++)
- Zc compiler options (C++)
ms.assetid: 7825277d-e565-4c48-b0fb-76ac0b0c6e38
ms.openlocfilehash: ac74192cad8a62e4c82b480038e727b114362cdd
ms.sourcegitcommit: b9aaaebe6e7dc5a18fe26f73cc7cf5fce09262c1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 02/20/2020
ms.locfileid: "77504565"
---
# <a name="zcrvaluecast-enforce-type-conversion-rules"></a>/Zc:rvalueCast (Aplicar regras de conversão de tipo)

Quando a opção **`/Zc:rvalueCast`** é especificada, o compilador identifica corretamente um tipo de referência rvalue como o resultado de uma operação de conversão. Seu comportamento está em conformidade com o padrão C++ 11. Quando a opção não for especificada, o comportamento do compilador será o mesmo do Visual Studio 2012.

## <a name="syntax"></a>Sintaxe

> **`/Zc:rvalueCast`**\
> **`/Zc:rvalueCast-`**

## <a name="remarks"></a>Comentários

Se **`/Zc:rvalueCast`** for especificado, o compilador seguirá a seção 5,4 do padrão do c++ 11 e tratará somente as expressões de conversão que resultam em tipos de não referência e expressões de conversão que resultam em referências de rvalue a tipos que não são de função como tipos de rvalue. Por padrão, ou se **`/Zc:rvalueCast-`** for especificado, o compilador não está em conformidade e trata todas as expressões de conversão que resultam em referências a rvalue como rvalues. Para conformidade e para eliminar erros no uso de conversões, recomendamos que você use **`/Zc:rvalueCast`** .

Por padrão, **`/Zc:rvalueCast`** é off ( **`/Zc:rvalueCast-`** ). A opção de compilador [/permissive-](permissive-standards-conformance.md) define implicitamente essa opção, mas pode ser substituída usando **`/Zc:rvalueCast-`** .

Use **`/Zc:rvalueCast`** se você passar uma expressão de conversão como um argumento para uma função que usa um tipo de referência rvalue. O comportamento padrão causa erro do compilador [C2664](../../error-messages/compiler-errors-2/compiler-error-c2664.md) quando o compilador determina incorretamente o tipo da expressão de conversão. Este exemplo mostra um erro do compilador no código correto quando **`/Zc:rvalueCast`** não é especificado:

```cpp
// Test of /Zc:rvalueCast
// compile by using:
// cl /c /Zc:rvalueCast- make_thing.cpp
// cl /c /Zc:rvalueCast make_thing.cpp

#include <utility>

template <typename T>
struct Thing {
   // Construct a Thing by using two rvalue reference parameters
   Thing(T&& t1, T&& t2)
      : thing1(t1), thing2(t2) {}

   T& thing1;
   T& thing2;
};

// Create a Thing, using move semantics if possible
template <typename T>
Thing<T> make_thing(T&& t1, T&& t2)
{
   return (Thing<T>(std::forward<T>(t1), std::forward<T>(t2)));
}

struct Test1 {
   long a;
   long b;

   Thing<long> test() {
      // Use identity casts to create rvalues as arguments
      return make_thing(static_cast<long>(a), static_cast<long>(b));
   }
};
```

Talvez o comportamento do compilador padrão não relate o erro C2102 quando apropriado. Neste exemplo, o compilador não relatará um erro se o endereço de um Rvalue criado por uma conversão de identidade for obtido quando **`/Zc:rvalueCast`** não for especificado:

```cpp
int main() {
   int a = 1;
   int *p = &a;   // Okay, take address of lvalue
                  // Identity cast creates rvalue from lvalue;
   p = &(int)a;   // problem: should cause C2102: '&' requires l-value
}
```

Para obter mais informações sobre problemas de conformidade C++no Visual, consulte [comportamento não padrão](../../cpp/nonstandard-behavior.md).

### <a name="to-set-this-compiler-option-in-the-visual-studio-development-environment"></a>Para definir esta opção do compilador no ambiente de desenvolvimento do Visual Studio

1. Abra a caixa de diálogo **Páginas de Propriedades** do projeto. Para obter detalhes, confira [Definir as propriedades de build e do compilador do C++ no Visual Studio](../working-with-project-properties.md).

1. Selecione as **Propriedades de configuração** > página de propriedades de **linguagem** **CC++ /**  > .

1. Defina a propriedade **impor regras de conversão de tipo** como **`/Zc:rvalueCast`** ou **`/Zc:rvalueCast-`** . Escolha **OK** ou **aplicar** para salvar suas alterações.

## <a name="see-also"></a>Confira também

[/Zc (conformidade)](zc-conformance.md)
