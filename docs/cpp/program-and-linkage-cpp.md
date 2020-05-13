---
title: Unidades de tradução e linkagem (C++)
ms.date: 12/11/2019
ms.assetid: a6493ba0-24e2-4c89-956e-9da1dea660cb
ms.openlocfilehash: 791ec53d4df863b218db463f2b9b9401bf6f466d
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81374324"
---
# <a name="translation-units-and-linkage"></a>Unidades de tradução e vinculação

Em um programa C++, um *símbolo*, por exemplo, um nome de variável ou função, pode ser declarado qualquer número de vezes dentro de seu escopo, mas só pode ser definido uma vez. Esta regra é a "Regra de Uma Definição" (ODR). Uma *declaração* introduz (ou reintroduz) um nome no programa. Uma *definição* introduz um nome. Se o nome representa uma variável, uma definição a inicializa explicitamente. Uma definição de *função* consiste na assinatura mais o corpo da função. Uma definição de classe consiste no nome da classe seguido por um bloco que lista todos os membros da classe. (Os corpos das funções dos membros podem ser definidos separadamente em outro arquivo.)

O exemplo a seguir mostra algumas declarações:

```cpp
int i;
int f(int x);
class C;
```

O exemplo a seguir mostra algumas definições:

```cpp
int i{42};
int f(int x){ return x * i; }
class C {
public:
   void DoSomething();
};
```

Um programa consiste em uma ou mais unidades de *tradução.* Uma unidade de tradução consiste em um arquivo de implementação e todos os cabeçalhos que ele inclui direta ou indiretamente. Os arquivos de implementação normalmente têm uma extensão de arquivo de *cpp* ou *cxx*. Os arquivos de cabeçalho normalmente têm uma extensão de *h* ou *hpp*. Cada unidade de tradução é compilada independentemente pelo compilador. Depois que a compilação é concluída, o linker mescla as unidades de tradução compiladas em um único *programa*. Violações da regra ODR normalmente aparecem como erros de linker. Erros de linker ocorrem quando o mesmo nome tem duas definições diferentes em unidades de tradução diferentes.

Em geral, a melhor maneira de tornar uma variável visível em vários arquivos é colocá-la em um arquivo de cabeçalho. Em seguida, adicione uma diretiva de #include em cada *arquivo cpp* que exija a declaração. Ao adicionar *guardas* ao redor do conteúdo do cabeçalho, você garante que os nomes que ele declara são definidos apenas uma vez.

Em C++20, [os módulos](modules-cpp.md) são introduzidos como uma alternativa melhorada aos arquivos de cabeçalho.

Em alguns casos, pode ser necessário declarar uma variável ou classe global em um arquivo *cpp.* Nesses casos, você precisa de uma maneira de dizer ao compilador e linker que tipo de *vinculação* o nome tem. O tipo de linkagem especifica se o nome do objeto se aplica apenas a um arquivo ou a todos os arquivos. O conceito de vinculação se aplica apenas a nomes globais. O conceito de vinculação não se aplica a nomes que são declarados dentro de um escopo. Um escopo é especificado por um conjunto de chaves de fechamento, como em funções ou definições de classe.

## <a name="external-vs-internal-linkage"></a>Ligação externa vs. interna

Uma *função livre* é uma função definida no escopo global ou namespace. Variáveis globais não const e funções livres por padrão têm *vinculação externa;* eles são visíveis de qualquer unidade de tradução no programa. Portanto, nenhum outro objeto global pode ter esse nome. Um símbolo com *ligação interna* ou *sem vinculação* é visível apenas dentro da unidade de tradução em que é declarado. Quando um nome tem linkagem interna, o mesmo nome pode existir em outra unidade de tradução. As variáveis declaradas com definições de classe ou órgãos de função não têm vinculação.

Você pode forçar um nome global a ter ligação interna declarando-o explicitamente **como estático**. Isso limita sua visibilidade à mesma unidade de tradução em que é declarada. Nesse contexto, **estática** significa algo diferente do que quando aplicado às variáveis locais.

Os seguintes objetos têm vinculação interna por padrão:

- objetos const
- objetos constexpr
- typedefs
- objetos estáticos no escopo de namespace

Para dar a um objeto const vinculação externa, declare-o como **extern** e atribua-lhe um valor:

```cpp
extern const int value = 42;
```

Consulte [extern](extern-cpp.md) para obter mais informações.

## <a name="see-also"></a>Confira também

[Conceitos Básicos](../cpp/basic-concepts-cpp.md)
