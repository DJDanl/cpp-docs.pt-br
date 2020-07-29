---
title: Aviso do compilador (nível 1) C4503
ms.date: 05/14/2018
f1_keywords:
- C4503
helpviewer_keywords:
- C4503
ms.assetid: 7c5a98ae-5b6d-41d8-b881-12d3ffd5e392
ms.openlocfilehash: 1d3af2b5629906679db46f6f669084c11a41f7ca
ms.sourcegitcommit: 1f009ab0f2cc4a177f2d1353d5a38f164612bdb1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/27/2020
ms.locfileid: "87233243"
---
# <a name="compiler-warning-level-1-c4503"></a>Aviso do compilador (nível 1) C4503

> '*Identifier*': tamanho de nome decorado excedido, o nome foi truncado

## <a name="remarks"></a>Comentários

Este aviso do compilador é obsoleto e não é gerado no Visual Studio 2017 e em compiladores posteriores.

O nome decorado era maior do que o limite do compilador (4096) e foi truncado. Para evitar esse aviso e o truncamento, reduza o número de argumentos ou os comprimentos de nome de identificadores usados. Nomes decorados que são maiores que o limite do compilador têm um hash aplicado e não estão em perigo de uma colisão de nome.

Ao usar uma versão mais antiga do Visual Studio, esse aviso pode ser emitido quando o código contém modelos especializados em modelos repetidamente. Por exemplo, um mapa de mapas (da biblioteca C++ Standard). Nessa situação, você pode tornar seus TYPEDEFs um tipo (a **`struct`** , por exemplo) que contenham o mapa.

No entanto, você pode decidir não reestruturar seu código.  É possível enviar um aplicativo que gera C4503, mas se você receber erros de tempo de link em um símbolo truncado, pode ser mais difícil determinar o tipo do símbolo no erro. A depuração também pode ser mais difícil; o depurador pode ter mapeamento difícil do nome do símbolo para o nome do tipo. No entanto, a exatidão do programa não é afetada pelo nome truncado.

## <a name="example"></a>Exemplo

O exemplo a seguir gera C4503 em compiladores antes do Visual Studio 2017:

```cpp
// C4503.cpp
// compile with: /W1 /EHsc /c
// C4503 expected
#include <string>
#include <map>

class Field{};

typedef std::map<std::string, Field> Screen;
typedef std::map<std::string, Screen> WebApp;
typedef std::map<std::string, WebApp> WebAppTest;
typedef std::map<std::string, WebAppTest> Hello;
Hello MyWAT;
```

Este exemplo mostra uma maneira de reescrever seu código para resolver C4503:

```cpp
// C4503b.cpp
// compile with: /W1 /EHsc /c
#include <string>
#include <map>

class Field{};

struct Screen2 {
   std::map<std::string, Field> Element;
};

struct WebApp2 {
   std::map<std::string, Screen2> Element;
};

struct WebAppTest2 {
   std::map<std::string, WebApp2> Element;
};

struct Hello2 {
   std::map<std::string, WebAppTest2> Element;
};

Hello2 MyWAT2;
```
