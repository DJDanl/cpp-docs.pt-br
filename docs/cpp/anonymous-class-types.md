---
title: Tipos de classe anônima
ms.date: 11/04/2016
helpviewer_keywords:
- class types [C++], anonymous
- anonymous class types
ms.assetid: 9ba667b2-8c2a-4c29-82a6-fa120b9233c8
ms.openlocfilehash: 815cc4a81addc673349a3133b24ed73cfe0207e2
ms.sourcegitcommit: a6d63c07ab9ec251c48bc003ab2933cf01263f19
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/05/2019
ms.locfileid: "74857665"
---
# <a name="anonymous-class-types"></a>Tipos de classe anônima

As classes podem ser anônimas, ou seja, elas podem ser declaradas sem um *identificador*. Isso é útil quando você substitui um nome de classe por um nome de **typedef** , como no seguinte:

```cpp
typedef struct
{
    unsigned x;
    unsigned y;
} POINT;
```

> [!NOTE]
>  O uso de classes anônimas mostradas no exemplo anterior é útil para preservar a compatibilidade com o código C existente. Em alguns códigos C, o uso de **typedef** em conjunto com estruturas anônimas é predominante.

As classes anônimas também são úteis quando você quer que uma referência a um membro da classe apareça como se não estivesse contida em uma classe separada, como a seguir:

```cpp
struct PTValue
{
    POINT ptLoc;
    union
    {
        int  iValue;
        long lValue;
    };
};

PTValue ptv;
```

No código anterior, `iValue` pode ser acessado usando o operador de seleção de membro de objeto ( **.** ) da seguinte maneira:

```cpp
int i = ptv.iValue;
```

As classes anônimas estão sujeitas a determinadas restrições. (Para obter mais informações sobre uniões anônimas, consulte [uniões](../cpp/unions.md).) Classes anônimas:

- Não é possível ter um construtor ou um destruidor.

- Não é possível ser transmitido como argumentos para as funções (a menos que a verificação de tipos seja derrotada usando reticências).

- Não é possível ser retornado como valores de retorno de funções.

## <a name="anonymous-structs"></a>Structs anônimos

**Seção específica da Microsoft**

Uma extensão do Microsoft C permite que você declare uma variável de estrutura dentro de outra estrutura sem nomeá-la. Essas estruturas aninhadas são chamadas de estruturas anônimas. O C++ não permite estruturas anônimas.

Você pode acessar os membros de uma estrutura anônima como se fossem membros da estrutura que os contém.

```cpp
// anonymous_structures.c
#include <stdio.h>

struct phone
{
    int  areacode;
    long number;
};

struct person
{
    char   name[30];
    char   gender;
    int    age;
    int    weight;
    struct phone;    // Anonymous structure; no name needed
} Jim;

int main()
{
    Jim.number = 1234567;
    printf_s("%d\n", Jim.number);
}
//Output: 1234567
```

**Fim da seção específica da Microsoft**
