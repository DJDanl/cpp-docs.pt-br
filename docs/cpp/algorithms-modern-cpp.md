---
title: "Algoritmos (C++ moderno) | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "article"
dev_langs: 
  - "C++"
ms.assetid: 6f758d3c-a7c7-4a50-92bb-97b2f6d4ab27
caps.latest.revision: 15
caps.handback.revision: 15
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Algoritmos (C++ moderno)
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Para programação em C\+\+ moderno, recomendamos que você use os algoritmos da [Biblioteca de Modelos Padrão](../standard-library/cpp-standard-library-reference.md) \(STL\).  Eis alguns exemplos importantes:  
  
-   `for_each`, que é o algoritmo transversal padrão. \(Também `transform` para a semântica não local.\)  
  
-   `find_if`, que é o algoritmo de pesquisa padrão.  
  
-   `sort`, `lower_bound` e os outros algoritmos de classificação e de pesquisa padrão.  
  
 Para gravar um comparador, usar lambdas restritos `<` e  *nomeados* quando puder.  
  
```cpp  
  
auto comp = [](const widget& w1, const widget& w2)  
      { return w1.weight() < w2.weight(); }  
  
sort( v.begin(), v.end(), comp );  
  
auto i = lower_bound( v.begin(), v.end(), comp );  
  
```  
  
## Loops  
 Quando possível, use loops baseados em intervalos `for` ou chamadas de algoritmo, ou ambos, em vez de loops gravados para à mão.  `copy`, `transform`, `count_if`, `remove_if` e outros como eles são muito melhores do que loops escritos a mão, uma vez que a intenção são óbvias e eles permitem que você escreva código sem bugs.  Além disso, muitos algoritmos de STL possuem otimizações de implementação que os torna mais eficientes.  
  
 Em vez de C\+\+ antigo como este:  
  
```cpp  
  
for( auto i = strings.begin(); i != strings.end(); ++i ) {  
  :::  
  :::  
}  
  
auto i = v.begin();  
  
for( ; i != v.end(); ++i ) {  
  if (*i > x && *i < y) break;  
}  
  
```  
  
 Use C\+\+ moderno assim:  
  
```cpp  
  
for_each( begin(strings), end(strings), [](string& s) {  
  :::  
  :::  
} );  
auto i = find_if( begin(v), end(v),  [=](int i) { return i > x && i < y; }  );  
  
```  
  
### Loops for baseados em intervalo  
 O loop baseado em intervalo `for` é recurso da linguagem C\+\+11, não um algoritmo STL.  Isso deve ser mencionado neste debate sobre circuitos.  Loops `for` com base no intervalo são uma extensão da palavra\-chave `for` e fornecem um meio conveniente e eficiente de gravar loops que são iterados em um intervalo de valores.  Recipientes, cadeias de caracteres e matrizes de STL são prontos para loops `for` com base em intervalos.  Para ativar essa nova sintaxe de iteração para seu tipo definido pelo usuário, adicione o suporte a seguir:  
  
-   Um método de `begin` que retorna um iterador para o início da estrutura e um método de `end` que retorna um iterador no final da estrutura.  
  
-   Suporte no iterador para esses métodos: `operator*`, `operator!=` e `operator++` \(versão de prefixo\).  
  
 Esses métodos podem ser membros ou funções autônomas.  
  
## Números Aleatórios  
 Não ha segredo de que a antiga função `rand()` do CRT tinha várias falhas, que foram longamente discutidas pela comunidade do C\+\+.  No C\+\+ moderno, você não tem que lidar com esses defeitos — nem precisa inventar seu próprio gerador de número aleatório distribuído uniformemente — porque as ferramentas para a criação rápida e fácil estão disponíveis no STL, conforme mostrado em [\<random\>](../standard-library/random.md).  
  
## Consulte também  
 [Bem\-vindo ao C\+\+](../Topic/Welcome%20Back%20to%20C++%20\(Modern%20C++\).md)   
 [Referência de linguagem C\+\+](../cpp/cpp-language-reference.md)   
 [Biblioteca Padrão C\+\+](../standard-library/cpp-standard-library-reference.md)