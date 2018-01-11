---
title: Algoritmos (C++ moderno) | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-language
ms.tgt_pltfrm: 
ms.topic: article
dev_langs: C++
ms.assetid: 6f758d3c-a7c7-4a50-92bb-97b2f6d4ab27
caps.latest.revision: "15"
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload: cplusplus
ms.openlocfilehash: 5d89f6b5116459018cb50eb58b976f6f853ed088
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="algorithms-modern-c"></a>Algoritmos (C++ moderno)
Para programação C++ moderna, recomendamos que você use os algoritmos no [biblioteca padrão C++](../standard-library/cpp-standard-library-reference.md). Aqui estão alguns exemplos importantes:  
  
-   `for_each`, que é o algoritmo padrão de passagem. (Também `transform` para semântica não no local.)  
  
-   `find_if`, que é o algoritmo de pesquisa padrão.  
  
-   `sort`, `lower_bound`e o padrão de classificação e algoritmos de pesquisa.  
  
 Para gravar um comparador, use strict `<` e usar *chamado lambdas* quando você pode.  
  
```cpp  
auto comp = [](const widget& w1, const widget& w2)  
      { return w1.weight() < w2.weight(); }  
  
sort( v.begin(), v.end(), comp );  
  
auto i = lower_bound( v.begin(), v.end(), comp );  
```  
  
## <a name="loops"></a>Loops  
 Quando possível, use baseada em intervalo `for` loops ou chamadas de algoritmo ou ambos, em vez de loops manual.`copy`, `transform`, `count_if`, `remove_if`, e outros, como eles são muito melhores do que os loops manuscritos porque sua intenção é óbvio e eles facilitam a escrever código livre de bug. Além disso, muitos algoritmos de biblioteca padrão C++ tem otimizações de implementação que torná-los mais eficiente.  
  
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
  
 Use C++ moderno como este:  
  
```cpp  
for_each( begin(strings), end(strings), [](string& s) {  
   // ...  
} );  
  
auto i = find_if( begin(v), end(v),  [=](int i) { return i > x && i < y; } );  
```  
  
### <a name="range-based-for-loops"></a>Com base em intervalo para loops  
 O intervalo com base em `for` loop é um 11 linguagem recurso do C++, não é um algoritmo de biblioteca padrão C++. Mas ele merece menção nesta discussão sobre loops. Com base em intervalo `for` loops são uma extensão do `for` palavra-chave e fornecem uma maneira eficiente e conveniente de escrever loops iterar em um intervalo de valores. Biblioteca padrão C++ contêineres, cadeias de caracteres e matrizes são prontas para baseada em intervalo `for` loops. Para habilitar essa nova sintaxe de iteração para o tipo definido pelo usuário, adicione o seguinte suporte:  
  
-   Um `begin` método que retorna um iterador para o início da estrutura e um `end` método que retorna um iterador até o final da estrutura.  
  
-   Suporte no iterador para estes métodos: `operator*`, `operator!=`, e `operator++` (versão de prefixo).  
  
 Esses métodos podem ser membros ou funções autônomas.  
  
## <a name="random-numbers"></a>Números aleatórios  
 Não é segredo que o antigo CRT `rand()` função tem muitas falhas, que foram discutidas em detalhes na comunidade do C++. Em C++ moderna, você não precisa lidar com essas limitações, também não é necessário para seu próprio uniformemente distribuído gerador de número aleatório de estoque — porque as ferramentas para criá-los de forma rápida e fácil estão disponíveis na biblioteca C++ padrão, conforme mostrado no [ \<aleatória >](../standard-library/random.md).  
  
## <a name="see-also"></a>Consulte também  
 [Bem-vindo novamente para C++](../cpp/welcome-back-to-cpp-modern-cpp.md)   
 [Referência da linguagem C++](../cpp/cpp-language-reference.md)   
 [Biblioteca Padrão do C++](../standard-library/cpp-standard-library-reference.md)