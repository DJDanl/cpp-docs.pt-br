---
title: Programas e ligação (C++) | Microsoft Docs
ms.custom: ''
ms.date: 04/09/2018
ms.technology:
- cpp-language
ms.topic: language-reference
dev_langs:
- C++
ms.assetid: a6493ba0-24e2-4c89-956e-9da1dea660cb
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 2dba8698461636e292771fc1e5a4f5ac0a633e73
ms.sourcegitcommit: d06966efce25c0e66286c8047726ffe743ea6be0
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 06/19/2018
ms.locfileid: "36238663"
---
# <a name="program-and-linkage-c"></a>Programa e ligação (C++)

Em um programa C++, um *símbolo*, por exemplo um nome de variável ou função, pode ser declarado várias vezes dentro de seu escopo, mas só pode ser definida uma vez. Essa é a regra de definição de um (ODR). Um *declaração* apresenta (ou novamente apresenta) em um nome para o programa. Um *definição* apresenta um nome e, no caso de uma variável, explicitamente inicializa. Um *definição de função* consiste de assinatura e o corpo da função.

Estas são as declarações:

```cpp
int i;
int f(int x);
```

Estas são as definições de:

```cpp
int i{42};
int f(int x){ return x * i; }
```

Um programa consiste em um ou mais *unidades de tradução*. Uma unidade de tradução consiste em um arquivo de implementação (. cpp,. cxx, etc.) e todos os cabeçalhos (. h, .hpp, etc.) que inclui direta ou indiretamente. Cada unidade de tradução é compilada independentemente pelo compilador, após o qual o vinculador mescla as unidades de tradução compilados em um único *programa*. Violações da regra ODR geralmente aparecem como erros de vinculador quando o mesmo nome tem duas definições diferentes em diferentes unidades de conversão.

Em geral, a melhor maneira de tornar uma variável visível em vários arquivos é colocá-la em um arquivo de cabeçalho e adicionar um #include diretiva em todos os arquivos. cpp que requer a declaração. Adicionando *incluem protege* ao redor do conteúdo de cabeçalho, garantir que os nomes declara são definidos apenas uma vez.

No entanto, em alguns casos pode ser necessário declarar uma variável global ou classe em um arquivo. cpp. Nesses casos, você precisa informar ao compilador e vinculador se o nome do objeto se aplica apenas ao arquivo de um ou todos os arquivos de uma maneira.

## <a name="linkage-vs-scope"></a>Vinculação versus escopo

O conceito de *vinculação* refere-se a visibilidade dos símbolos globais (por exemplo, variáveis, nomes de tipos e nomes de função) do programa, como um todo em unidades de tradução. O conceito de *escopo* refere-se os símbolos são declarados dentro de um bloco, como um namespace, classe ou corpo de função. Esses símbolos são visíveis somente dentro do escopo no qual eles são definidos; o conceito de ligação não se aplicam a eles. 

## <a name="external-vs-internal-linkage"></a>Externo versus vinculação interna

Um *livre função* é uma função que é definida em global ou escopo de namespace. Variáveis globais não-const e as funções gratuitas por padrão têm *vinculação externa*; estão visíveis de qualquer unidade de tradução no programa. Portanto, nenhum objeto outros global (variável, definição de classe, etc.) pode ter esse nome. Um símbolo com *vinculação interna* ou *sem ligação* estará visível somente na unidade de tradução no qual ela é declarada. Quando um nome tem vinculação interna, o mesmo nome pode existir em outra unidade de tradução. Variáveis declaradas com definições de classe ou corpos de função tem sem ligação. 

Você pode forçar um nome global para que a vinculação interna declarando explicitamente como **estático**. Isto limita sua visibilidade na mesma unidade de tradução no qual ela é declarada. Observe que, neste contexto, **estático** significa algo diferente de quando aplicados a variáveis locais.

Os seguintes objetos têm vinculação interna por padrão:
- objetos constantes
- objetos de constexpr
- typedefs
- objetos estáticos no escopo de namespace

Para dar uma ligação externa do objeto const, declare-o como **extern** e atribua o valor:

```cpp
extern const int value = 42;
```

Consulte [extern](extern-cpp.md) para obter mais informações.

## <a name="see-also"></a>Consulte também

 [Conceitos básicos](../cpp/basic-concepts-cpp.md)