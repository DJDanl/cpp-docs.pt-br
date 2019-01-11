---
title: Algoritmos (C++ moderno)
ms.date: 11/04/2016
ms.topic: conceptual
ms.assetid: 6f758d3c-a7c7-4a50-92bb-97b2f6d4ab27
ms.openlocfilehash: b972e575c982ae2523ec560a6237eac76ceaf834
ms.sourcegitcommit: a1fad0a266b20b313364a74b16c9ac45d089b1e9
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 01/11/2019
ms.locfileid: "54220147"
---
# <a name="algorithms-modern-c"></a>Algoritmos (C++ moderno)

Para a programação do C++ moderna, é recomendável que você use os algoritmos de [biblioteca padrão C++](../standard-library/cpp-standard-library-reference.md). Aqui estão alguns exemplos importantes:

- **for_each**, que é o algoritmo transversal padrão. (Também **transformar** para a semântica não local.)

- **find_if**, que é o algoritmo de pesquisa padrão.

- **Classificar**, **lower_bound**e o padrão de classificação e algoritmos de pesquisa.

Para gravar um comparador, usar estrito **<** e use *chamado lambdas* quando possível.

```cpp
auto comp = [](const widget& w1, const widget& w2)
     { return w1.weight() < w2.weight(); }

sort( v.begin(), v.end(), comp );

auto i = lower_bound( v.begin(), v.end(), comp );
```

## <a name="loops"></a>Loops

Quando possível, use baseado em intervalo **para** loops ou chamadas de algoritmo ou ambos, em vez de loops gravados para à mão. **cópia**, **transformar**, **count_if**, **remove_if**, e outros como eles são muito melhores do que loops manuscritos porque a intenção são óbvias e eles torna mais fácil escrever código livre de bugs. Além disso, muitos algoritmos da biblioteca padrão C++ têm as otimizações de implementação que os tornam mais eficientes.

Em vez de C++ antigo como este:

```cpp
for ( auto i = strings.begin(); i != strings.end(); ++i ) {
    /* ... */
}

auto i = v.begin();

for ( ; i != v.end(); ++i ) {
    if (*i > x && *i < y) break;
}
```

Use C++ moderno assim:

```cpp
for_each( begin(strings), end(strings), [](string& s) {
  // ...
} );

auto i = find_if( begin(v), end(v),  [=](int i) { return i > x && i < y; } );
```

### <a name="range-based-for-loops"></a>Baseado em intervalo para loops

Baseado em intervalo **para** loop é um 11 idioma recurso, não é um algoritmo de biblioteca padrão C++. Mas ele merece ser mencionado neste debate sobre loops. Baseado em intervalo **para** loops são uma extensão das **para** palavra-chave e fornecem uma maneira conveniente e eficiente para gravar loops que iterar sobre um intervalo de valores. Contêineres da biblioteca padrão C++, cadeias de caracteres e matrizes já estão prontos para baseado em intervalo **para** loops. Para habilitar essa nova sintaxe de iteração para seu tipo definido pelo usuário, adicione o suporte a seguir:

- Um `begin` método que retorna um iterador para o início da estrutura e um `end` método que retorna um iterador para o final da estrutura.

- Suporte no iterador para esses métodos: **operador**<strong>\*</strong>, **operador! =**, e **operator + +** (versão de prefixo).

Esses métodos podem ser membros ou funções autônomas.

## <a name="random-numbers"></a>Números aleatórios

Não é segredo que o CRT antigo `rand()` função possui várias falhas, que foi discutidas em detalhes na comunidade do C++. No C++ moderno, você não precisa lidar com esses defeitos — nem precisa inventar seu próprio gerador de números aleatórios distribuído uniformemente — porque as ferramentas para criá-los de forma rápida e fácil estão disponíveis na biblioteca C++ padrão, conforme mostrado na [ \<random >](../standard-library/random.md).

## <a name="see-also"></a>Consulte também

[Bem-vindo ao C++ (C++ moderno)](../cpp/welcome-back-to-cpp-modern-cpp.md)<br/>
[Referência da linguagem C++](../cpp/cpp-language-reference.md)<br/>
[Biblioteca Padrão do C++](../standard-library/cpp-standard-library-reference.md)<br/>
