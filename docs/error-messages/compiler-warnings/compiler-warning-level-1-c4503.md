---
title: Compilador aviso (nível 1) C4503
ms.date: 05/14/2018
f1_keywords:
- C4503
helpviewer_keywords:
- C4503
ms.assetid: 7c5a98ae-5b6d-41d8-b881-12d3ffd5e392
ms.openlocfilehash: 94c88511d87c3adf3cf5687a94948c83ebc5b3d5
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50459781"
---
# <a name="compiler-warning-level-1-c4503"></a>Compilador aviso (nível 1) C4503

> '*identificador*': decorado excedido, comprimento do nome nome foi truncado

## <a name="remarks"></a>Comentários

Esse aviso do compilador está obsoleto e não é gerado no Visual Studio 2017 e posteriores compiladores.

O nome decorado era maior que o limite do compilador (4096) e foi truncado. Para evitar esse aviso e o truncamento, reduza o número de argumentos ou os comprimentos de nome dos identificadores usados. Nomes que são mais tempo do que o limite do compilador um hash aplicado e não estão em perigo de uma colisão de nomes decorados.

Ao usar uma versão mais antiga do Visual Studio, esse aviso pode ser emitido quando seu código contém modelos especializado em modelos repetidamente. Por exemplo, um mapa de mapas (da biblioteca padrão C++). Nessa situação, você pode tornar um tipo de suas definições de tipo (um **struct**, por exemplo) que contém o mapa.

No entanto, você pode, decidir não reestruturar seu código.  É possível enviar um aplicativo que gera C4503, mas se você obtiver erros em tempo de link em um símbolo truncado, pode ser mais difícil de determinar o tipo do símbolo no erro. A depuração pode também ser mais difícil; o depurador pode ter dificuldade em lidar mapeando o nome do símbolo para o nome do tipo. A correção do programa, no entanto, não é afetada pelo nome truncado.

## <a name="example"></a>Exemplo

O exemplo a seguir gera C4503 nos compiladores antes do Visual Studio 2017:

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

Este exemplo mostra uma maneira de reescrever o código para resolver C4503:

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