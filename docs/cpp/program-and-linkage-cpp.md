---
title: Programa e ligação (C++) | Microsoft Docs
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
ms.openlocfilehash: 4154f0951b46b1c8badc0224845d2881cc8ad573
ms.sourcegitcommit: be2a7679c2bd80968204dee03d13ca961eaa31ff
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/03/2018
ms.locfileid: "32421361"
---
# <a name="program-and-linkage--c"></a>Programa e ligação (C++)

Em um programa C++, cada global de símbolos pode ser definido apenas uma vez, mesmo que o programa consiste em várias unidades de tradução. Uma unidade de tradução consiste em um arquivo de implementação (. cpp, .hpp,. cxx, etc.) e todos os cabeçalhos que inclui direta ou indiretamente. Um programa consiste em uma ou mais unidades de tradução vinculadas. 

## <a name="linkage-vs-scope"></a>Vinculação versus escopo

O conceito de *vinculação* refere-se a visibilidade dos símbolos globais (por exemplo, variáveis, nomes de tipos e nomes de função) do programa, como um todo em unidades de tradução. O conceito de *escopo* refere-se os símbolos são declarados dentro de um bloco, como um namespace, classe ou corpo de função. Esses símbolos são visíveis somente dentro do escopo no qual eles são definidos; o conceito de ligação não se aplicam a eles.

## <a name="external-vs-internal-linkage"></a>Externo versus vinculação interna

Funções livres por padrão e variáveis globais não-const possuem vínculo externo; eles são visíveis a partir de qualquer unidade de tradução no programa. Você pode substituir esse comportamento, explicitamente declará-los como **estático** que limita sua visibilidade na mesma unidade de tradução na qual eles são declarados. O significado de **estático** é diferente de seu significado quando aplicado a variáveis locais. As variáveis declaradas como **const** tem vinculação interna por padrão.

## <a name="extern-constexpr-linkage"></a>Vinculação de constexpr extern

Em versões anteriores do Visual Studio, o compilador sempre forneceu uma vinculação de interna de variável constexpr mesmo quando a variável foi marcado como externo. No Visual Studio 2017 versão 15.5, uma nova opção de compilador, (/Zc:externConstexpr), habilita o comportamento correto em conformidade com os padrões. Eventualmente, isso se tornará o padrão.

```cpp
extern constexpr int x = 10; //error LNK2005: "int const x" already defined
```

Se um arquivo de cabeçalho contém um constexpr variável extern declarado, ele precisa ser marcado como **__declspec(selectany)** para ter corretamente suas declarações duplicadas combinadas:

```cpp
extern constexpr __declspec(selectany) int x = 10;
```

## <a name="see-also"></a>Consulte também

 [Conceitos básicos](../cpp/basic-concepts-cpp.md)