---
title: Unidades de tradução e vinculaçãoC++()
ms.date: 12/11/2019
ms.assetid: a6493ba0-24e2-4c89-956e-9da1dea660cb
ms.openlocfilehash: e4e86dc15280bc7aa079f552014975b7ddc68e51
ms.sourcegitcommit: 857fa6b530224fa6c18675138043aba9aa0619fb
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/24/2020
ms.locfileid: "80188318"
---
# <a name="translation-units-and-linkage"></a>Unidades de tradução e vinculação

Em um C++ programa, um *símbolo*, por exemplo, uma variável ou um nome de função, pode ser declarado qualquer número de vezes dentro de seu escopo, mas só pode ser definido uma vez. Essa regra é a "regra de definição única" (ODR). Uma *declaração* apresenta (ou reintroduz) um nome para o programa. Uma *definição* introduz um nome. Se o nome representar uma variável, uma definição a inicializará explicitamente. Uma *definição de função* consiste na assinatura mais o corpo da função. Uma definição de classe consiste no nome da classe seguido por um bloco que lista todos os membros da classe. (Os corpos de funções de membro podem, opcionalmente, ser definidos separadamente em outro arquivo.)

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

Um programa consiste em uma ou mais *unidades de tradução*. Uma unidade de tradução consiste em um arquivo de implementação e todos os cabeçalhos que ele inclui direta ou indiretamente. Os arquivos de implementação normalmente têm uma extensão de arquivo *cpp* ou *cxx*. Normalmente, os arquivos de cabeçalho têm uma extensão de *h* ou *HPP*. Cada unidade de tradução é compilada independentemente pelo compilador. Após a conclusão da compilação, o vinculador mescla as unidades de tradução compiladas em um único *programa*. As violações da regra ODR normalmente aparecem como erros do vinculador. Os erros do vinculador ocorrem quando o mesmo nome tem duas definições diferentes em unidades de tradução diferentes.

Em geral, a melhor maneira de tornar uma variável visível em vários arquivos é colocá-la em um arquivo de cabeçalho. Em seguida, adicione uma diretiva #include em cada arquivo *cpp* que exija a declaração. Ao adicionar as *proteções include* no conteúdo do cabeçalho, você garante que os nomes declarados sejam definidos apenas uma vez.

No C++ 20, os [módulos](modules-cpp.md) são introduzidos como uma alternativa aprimorada para arquivos de cabeçalho.

Em alguns casos, pode ser necessário declarar uma variável global ou uma classe em um arquivo *cpp* . Nesses casos, você precisa de uma maneira de informar ao compilador e ao vinculador qual tipo de *ligação* o nome tem. O tipo de vínculo especifica se o nome do objeto se aplica apenas a um arquivo ou a todos os arquivos. O conceito de ligação se aplica somente a nomes globais. O conceito de ligação não se aplica a nomes declarados dentro de um escopo. Um escopo é especificado por um conjunto de chaves de circunscrição, como nas definições de função ou classe.

## <a name="external-vs-internal-linkage"></a>Vínculo externo vs. interno

Uma *função gratuita* é uma função que é definida em escopo global ou de namespace. Variáveis globais não const e funções gratuitas por padrão têm *vínculo externo*; Eles são visíveis de qualquer unidade de tradução no programa. Portanto, nenhum outro objeto global pode ter esse nome. Um símbolo com *vínculo interno* ou *nenhum vínculo* é visível somente na unidade de tradução em que é declarado. Quando um nome tem ligação interna, o mesmo nome pode existir em outra unidade de tradução. Variáveis declaradas com definições de classe ou corpos de função não têm vínculos.

Você pode forçar um nome global a ter um vínculo interno declarando-o explicitamente como **estático**. Isso limita sua visibilidade à mesma unidade de tradução na qual ela é declarada. Nesse contexto, **estático** significa algo diferente quando aplicado às variáveis locais.

Os seguintes objetos têm vínculo interno por padrão:
- objetos const
- objetos constexpr
- typedefs
- objetos estáticos no escopo do namespace

Para dar um objeto const de vínculo externo, declare-o como **externo** e atribua um valor a ele:

```cpp
extern const int value = 42;
```

Consulte [externo](extern-cpp.md) para obter mais informações.

## <a name="see-also"></a>Confira também

[Conceitos básicos](../cpp/basic-concepts-cpp.md)
