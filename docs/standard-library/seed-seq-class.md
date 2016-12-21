---
title: "Classe seed_seq | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "article"
f1_keywords: 
  - "tr1::seed_seq"
  - "std::tr1::seed_seq"
  - "tr1.seed_seq"
  - "seed_seq"
  - "std.tr1.seed_seq"
  - "random/std::tr1::seed_seq"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Classe seed_seq"
ms.assetid: cba114f7-9ac6-4f2f-b773-9c84805401d6
caps.latest.revision: 19
caps.handback.revision: 12
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Classe seed_seq
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Armazena um vetor de valores inteiros sem sinal que pode fornecer uma semente aleatória para um mecanismo de número aleatório.  
  
## Sintaxe  
  
```  
class seed_seq  
{  
public:  
    // types  
    typedef unsigned int result_type;  
  
    // constructors  
    seed_seq();  
  
    template<class T>  
    seed_seq(initializer_list<T> initlist);  
  
    template<class InputIterator>  
    seed_seq(InputIterator begin, InputIterator end);  
  
    // generating functions  
    template<class RandomAccessIterator>  
    void generate(RandomAccessIterator begin, RandomAccessIterator end);  
  
    // property functions  
    size_t size() const;  
  
    template<class OutputIterator>  
    void param(OutputIterator dest) const;  
  
    // no copy functions  
    seed_seq(const seed_seq&) = delete;  
    void operator=(const seed_seq&) = delete;  
};  
```  
  
## Tipos  
 `typedef unsigned int result_type;`   
O tipo dos elementos da sequência de propagação. Um tipo de inteiro não assinado de 32 bits.  
  
## Construtores  
 `seed_seq();`   
Construtor padrão, inicializa com uma sequência interna vazia.  
  
 `template<class T>`   
 `seed_seq(initializer_list<T> initlist);`   
Usa `initlist` para definir a sequência interna.  
`T` deve ser um tipo inteiro.  
  
 `template<class InputIterator>`   
 `seed_seq(InputIterator begin, InputIterator end);`   
Inicializa a sequência interna usando todos os elementos no intervalo de iterador de entrada fornecido.  
`iterator_traits<InputIterator>::value_type` deve ser um tipo inteiro.  
  
## Membros  
  
### Funções de geração  
 `template<class RandomAccessIterator> void generate(RandomAccessIterator begin, RandomAccessIterator end);`   
Preenche os elementos da sequência fornecida usando um algoritmo interno. Esse algoritmo é afetado pela sequência interna com a qual `seed_seq` foi inicializado.  
Não faz nada se `begin == end`.  
  
### Funções de propriedade  
 `size_t size() const;`   
Retorna o número de elementos de `seed_seq`.  
  
 `template<class OutputIterator> void param(OutputIterator dest) const;`   
Copia a sequência interna no iterador de saída `dest`.  
  
## Exemplo  
 O exemplo de código a seguir exercita os três construtores e gera a saída de resultante `seed_seq` instâncias quando atribuído a uma matriz. Para obter um exemplo que usa `seed_seq` com um gerador de número aleatório, consulte [\<random\>](../standard-library/random.md).  
  
```cpp  
#include <iostream>  
#include <random>  
#include <string>  
#include <array>  
  
using namespace std;  
  
void test(const seed_seq& sseq) {  
    cout << endl << "seed_seq::size(): " << sseq.size() << endl;  
  
    cout << "seed_seq::param(): ";  
    ostream_iterator<unsigned int> out(cout, " ");  
    sseq.param(out);  
    cout << endl;  
  
    cout << "Generating a sequence of 5 elements into an array: " << endl;  
    array<unsigned int, 5> seq;  
    sseq.generate(seq.begin(), seq.end());  
    for (unsigned x : seq) { cout << x << endl; }  
}  
  
int main()  
{  
    seed_seq seed1;  
    test(seed1);  
  
    seed_seq seed2 = { 1701, 1729, 1791 };  
    test(seed2);  
  
    string sstr = "A B C D"; // seed string  
    seed_seq seed3(sstr.begin(), sstr.end());  
    test(seed3);  
}  
```  
  
## Saída  
  
```Output  
  
seed_seq::Size(): seed_seq::param() 0: gerar uma sequência de 5 elementos em uma matriz: 505382999 163489202 3932644188 763126080 73937346 seed_seq::size(): seed_seq::param() 3: 1701 1729 1791 gerar uma sequência de 5 elementos em uma matriz: 1730669648 1954224479 2809786021 1172893117 2393473414 seed_seq::size(): seed_seq::param() 7: 32 65 32 66 32 67 68 gerar uma sequência de 5 elementos em uma matriz : 3139879222 3775111734 1084804564 2485037668 1985355432  
```  
  
## Comentários  
 Funções de membro dessa classe não lançam exceções.  
  
## Requisitos  
 **Cabeçalho:** \< random \>  
  
 **Namespace:** std  
  
## Consulte também  
 [\<random\>](../standard-library/random.md)