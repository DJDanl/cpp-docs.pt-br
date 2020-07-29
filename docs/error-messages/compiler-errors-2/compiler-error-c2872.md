---
title: Erro do compilador C2872
ms.date: 11/04/2016
f1_keywords:
- C2872
helpviewer_keywords:
- C2872
ms.assetid: c619ef97-6e0e-41d7-867c-f8d28a07d553
ms.openlocfilehash: f57b250f87bd7f2c5808b5a681ddfe49dfa5e876
ms.sourcegitcommit: 1f009ab0f2cc4a177f2d1353d5a38f164612bdb1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/27/2020
ms.locfileid: "87228889"
---
# <a name="compiler-error-c2872"></a>Erro do compilador C2872

'*Symbol*': símbolo ambíguo

O compilador não pode determinar a qual símbolo você está se referindo. Mais de um símbolo com o nome especificado está no escopo. Consulte as observações após a mensagem de erro para os locais de arquivo e as declarações que o compilador encontrou para o símbolo ambíguo. Para corrigir esse problema, você pode qualificar totalmente o símbolo ambíguo usando seu namespace, por exemplo, `std::byte` ou `::byte` . Você também pode usar um [alias de namespace](../../cpp/namespaces-cpp.md#namespace_aliases) para dar a um namespace incluído um nome curto conveniente para uso ao eliminar a ambiguidade de símbolos em seu código-fonte.

C2872 pode ocorrer se um arquivo de cabeçalho incluir uma [diretiva using](../../cpp/namespaces-cpp.md#using_directives), e um arquivo de cabeçalho subsequente estiver incluído que contenha um tipo que também esteja no namespace especificado na **`using`** diretiva. Especifique uma **`using`** diretiva somente depois que todos os arquivos de cabeçalho forem especificados com `#include` .

C2872 pode ocorrer em Visual Studio 2013 devido a um conflito entre o `Windows::Foundation::Metadata::Platform` tipo enum e o namespace C++/CX-defined `Platform` . Para contornar esse problema, siga estas etapas:

- Remova a cláusula "usando o namespace Windows:: Foundation:: Metadata" dos arquivos do projeto.

- Especifique o nome totalmente qualificado para qualquer tipo que esteja incluído neste namespace.

## <a name="example"></a>Exemplo

O exemplo a seguir gera C2872, porque uma referência ambígua é feita em uma variável chamada `i` ; duas variáveis com o mesmo nome estão no escopo:

```cpp
// C2872.cpp
// compile with: cl /EHsc C2872.cpp
namespace A {
   int i;
}

using namespace A;
int i;
int main() {
   ::i++;   // ok, uses i from global namespace
   A::i++;   // ok, uses i from namespace A
   i++;   // C2872 ambiguous: ::i or A::i?
   // To fix this issue, use the fully qualified name
   // for the intended variable.
}
```
