---
title: Programas e ligação (C++)
ms.date: 04/09/2018
ms.assetid: a6493ba0-24e2-4c89-956e-9da1dea660cb
ms.openlocfilehash: 4f509979a293f194333e610fbdae7be9d32ec121
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50559845"
---
# <a name="program-and-linkage-c"></a>Programa e ligação (C++)

Em um programa C++, uma *símbolo*, por exemplo um nome de variável ou função, pode ser declarado como qualquer número de vezes dentro de seu escopo, mas só pode ser definido uma vez. Essa é a regra de definição de um (ODR). Um *declaração* um nome para o programa apresenta (ou apresenta novamente). Um *definição* introduz um nome e, no caso de uma variável explicitamente inicializa-o. Um *definição de função* consiste a assinatura e o corpo da função.

Estas são as declarações:

```cpp
int i;
int f(int x);
```

Essas são definições:

```cpp
int i{42};
int f(int x){ return x * i; }
```

Um programa consiste em um ou mais *unidades de tradução*. Uma unidade de tradução consiste em um arquivo de implementação (. cpp,. cxx, etc.) e todos os cabeçalhos (. h, .hpp, etc.) que inclui o direta ou indiretamente. Cada unidade de tradução é compilada de forma independente pelo compilador, após o qual o vinculador mescla as unidades de conversão compilada em um único *programa*. As violações de regra ODR normalmente aparecem como erros de vinculador quando o mesmo nome tem duas definições diferentes em diferentes unidades de conversão.

Em geral, a melhor maneira de tornar uma variável visível em vários arquivos é colocá-lo em um arquivo de cabeçalho e adicionar um #include diretiva em todos os arquivos. cpp que requer a declaração. Adicionando *incluem guardas* em todo o conteúdo do cabeçalho, você certifique-se de que os nomes que ele declara são definidos apenas uma vez.

No entanto, em alguns casos, pode ser necessário declarar uma variável global ou uma classe em um arquivo. cpp. Nesses casos, você precisa de uma forma de dizer ao compilador e vinculador se o nome do objeto se aplica apenas ao arquivo de um ou todos os arquivos.

## <a name="linkage-vs-scope"></a>Vinculação versus escopo

O conceito de *vinculação* refere-se a visibilidade dos símbolos globais (por exemplo, variáveis, nomes de tipos e nomes de função) dentro do programa como um todo nas unidades de conversão. O conceito de *escopo* refere-se aos símbolos são declarados dentro de um bloco, como um namespace, classe ou corpo da função. Esses símbolos são visíveis somente dentro do escopo no qual eles são definidos; o conceito de vinculação não se aplica a eles.

## <a name="external-vs-internal-linkage"></a>Externo versus vinculação interna

Um *livre função* é uma função que é definida no global ou escopo de namespace. Variáveis globais de non-const e funções gratuitas por padrão têm *vinculação externa*; estão visíveis de qualquer unidade de conversão no programa. Portanto, nenhum objeto outro global (variável, definição de classe, etc.) pode ter esse nome. Um símbolo com *vinculação interna* ou *nenhuma vinculação* é visível somente dentro da unidade de tradução na qual ela é declarada. Quando um nome tem vinculação interna, o mesmo nome pode existir em outra unidade de tradução. As variáveis declaradas com definições de classe ou corpos de função não têm nenhuma vinculação.

Você pode forçar um nome global ter vinculação interna, declarando explicitamente como **estático**. Isso limita sua visibilidade na mesma unidade de tradução na qual ela é declarada. Observe que, neste contexto **estático** significa algo diferente de quando aplicados a variáveis locais.

Os seguintes objetos têm vinculação interna, por padrão:
- objetos constantes
- objetos de constexpr
- typedefs
- objetos estáticos no escopo de namespace

Para dar uma vinculação externa do objeto const, declare-o como **extern** e atribua um valor:

```cpp
extern const int value = 42;
```

Ver [extern](extern-cpp.md) para obter mais informações.

## <a name="see-also"></a>Consulte também

[Conceitos básicos](../cpp/basic-concepts-cpp.md)