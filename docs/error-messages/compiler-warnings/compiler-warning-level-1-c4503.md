---
title: Compilador (nível 1) de aviso C4503 | Microsoft Docs
ms.custom: ''
ms.date: 05/14/2018
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- C4503
dev_langs:
- C++
helpviewer_keywords:
- C4503
ms.assetid: 7c5a98ae-5b6d-41d8-b881-12d3ffd5e392
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: f60fdb44c5368ccc5c5f089002614332d95a63fe
ms.sourcegitcommit: 19a108b4b30e93a9ad5394844c798490cb3e2945
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/17/2018
---
# <a name="compiler-warning-level-1-c4503"></a>Compilador C4503 de aviso (nível 1)

> '*identificador*': decorado excedido, comprimento do nome nome foi truncado

## <a name="remarks"></a>Comentários

Esse aviso do compilador é obsoleto e não é gerado no Visual Studio de 2017 e compiladores posteriores.

O nome decorado era maior que o limite do compilador (4096) e foi truncado. Para evitar esse aviso e o truncamento, reduza o número de argumentos ou os comprimentos de nome dos identificadores usados. Nomes que são mais do que o limite do compilador um hash aplicado e não estão em risco de uma colisão de nomes decorados.

Ao usar uma versão mais antiga do Visual Studio, esse aviso pode ser emitido quando seu código contém modelos especializado repetidamente em modelos. Por exemplo, um mapa de mapas (da biblioteca padrão C++). Nessa situação, você pode fazer um tipo de suas definições de tipo (uma **struct**, por exemplo) que contém o mapa.

No entanto, você pode, decidir não reestruture seu código.  É possível enviar um aplicativo que gera C4503, mas se você receber erros de tempo de link em um símbolo truncado, pode ser mais difícil determinar o tipo do símbolo no erro. Depuração pode também ser mais difícil; o depurador pode ter dificuldade mapear o nome do símbolo para o nome de tipo. A exatidão do programa, no entanto, não é afetada pelo nome truncado.

## <a name="example"></a>Exemplo

O exemplo a seguir gera C4503 em compiladores antes de 2017 do Visual Studio:

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