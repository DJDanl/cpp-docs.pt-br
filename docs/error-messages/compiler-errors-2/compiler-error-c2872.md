---
title: Erro do compilador C2872 | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- C2872
dev_langs:
- C++
helpviewer_keywords:
- C2872
ms.assetid: c619ef97-6e0e-41d7-867c-f8d28a07d553
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 8eb494d3a8ba2e2569f68dbfd0164c7bf6a9ae29
ms.sourcegitcommit: 072e12d6b7a242765bdcc9afe4a14a284ade01fc
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/26/2018
ms.locfileid: "50136218"
---
# <a name="compiler-error-c2872"></a>Erro do compilador C2872

'*símbolo*': símbolo ambíguo

O compilador não pode determinar o símbolo que você está referenciando. Mais de um símbolo com o nome especificado está no escopo. Consulte as observações que a mensagem de erro para os locais de arquivo e as declarações a seguir o compilador encontrado para o símbolo ambíguo. Para corrigir esse problema, você pode qualificar totalmente o símbolo ambíguo usando seu namespace, por exemplo, `std::byte` ou `::byte`. Você também pode usar um [alias de namespace](../../cpp/namespaces-cpp.md#namespace_aliases) para dar um nome curto conveniente para uso de um namespace incluído quando desambiguação de símbolos em seu código-fonte.

C2872 pode ocorrer se um arquivo de cabeçalho inclui um [diretiva using](../../cpp/namespaces-cpp.md#using_directives), e um arquivo de cabeçalho subsequente é incluído que contém um tipo que também está no namespace especificado no `using` diretiva. Especifique um `using` diretiva somente depois de todos os arquivos de cabeçalho são especificados com `#include`.

C2872 pode ocorrer no Visual Studio 2013 devido a um conflito entre o `Windows::Foundation::Metadata::Platform` enum tipo e o C + + c++ /CLI definido pelo CX `Platform` namespace. Para contornar esse problema, siga estas etapas:

- Remova a cláusula "using namespace Windows::Foundation::Metadata" dos arquivos de projeto.

- Especifique o nome totalmente qualificado para qualquer tipo que está incluído neste namespace.

## <a name="example"></a>Exemplo

O exemplo a seguir gera C2872, pois uma referência ambígua é feita a uma variável chamada `i`; duas variáveis com o mesmo nome estão no escopo:

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
