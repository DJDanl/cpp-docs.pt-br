---
title: Classe seed_seq
ms.date: 11/04/2016
f1_keywords:
- random/std::seed_seq
- random/std::seed_seq::result_type
- random/std::seed_seq::generate
- random/std::seed_seq::size
- random/std::seed_seq::param
helpviewer_keywords:
- std::seed_seq [C++]
- std::seed_seq [C++], result_type
- std::seed_seq [C++], generate
- std::seed_seq [C++], size
- std::seed_seq [C++], param
ms.assetid: cba114f7-9ac6-4f2f-b773-9c84805401d6
ms.openlocfilehash: 5309042e9f26875e0cf5c2024cc74910fef21148
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50592485"
---
# <a name="seedseq-class"></a>Classe seed_seq

Armazena um vetor de valores inteiros sem sinal que pode fornecer uma semente aleatória para um mecanismo de número aleatório.

## <a name="syntax"></a>Sintaxe

```cpp
class seed_seq
   {
public:
   // types
   typedef unsigned int result_type;

   // constructors
   seed_seq();
   template <class T>
      seed_seq(initializer_list<T> initlist);
   template <class InputIterator>
      seed_seq(InputIterator begin, InputIterator end);

   // generating functions
   template <class RandomAccessIterator>
      void generate(RandomAccessIterator begin, RandomAccessIterator end);

   // property functions
   size_t size() const;
   template <class OutputIterator>
      void param(OutputIterator dest) const;

   // no copy functions
   seed_seq(const seed_seq&) = delete;
   void operator=(const seed_seq&) = delete;
   };
```

## <a name="types"></a>Tipos

```cpp
typedef unsigned int result_type;
```

O tipo dos elementos da sequência de sementes. Um tipo inteiro sem sinal de 32 bits.

## <a name="constructors"></a>Construtores

```cpp
seed_seq();
```

Construtor padrão, inicializa para ter uma sequência interna vazia.

```cpp
template<class T>
seed_seq(initializer_list<T> initlist);
```

Usa `initlist` para definir a sequência interna.
O `T` deve ser um tipo inteiro.

```cpp
template<class InputIterator>
seed_seq(InputIterator begin, InputIterator end);
```

Inicializa a sequência interna usando todos os elementos no intervalo do iterador de entrada fornecido.
O `iterator_traits<InputIterator>::value_type` deve ser um tipo inteiro.

## <a name="members"></a>Membros

### <a name="generating-functions"></a>Gerando funções

```cpp
template<class RandomAccessIterator>
void generate(RandomAccessIterator begin,
          RandomAccessIterator end);
```

Preenche os elementos da sequência fornecida usando um algoritmo interno. Esse algoritmo é afetado pela sequência interna com a qual o `seed_seq` foi inicializado.
Não faz nada se `begin == end`.

### <a name="property-functions"></a>Funções de propriedade

```cpp
size_t size() const;
```

Retorna o número de elementos no `seed_seq`.

```cpp
template<class OutputIterator>
void param(OutputIterator dest) const;
```

Copia a sequência interna no iterador de saída `dest`.

## <a name="example"></a>Exemplo

O exemplo de código a seguir exercita os três construtores e gera saída das instâncias `seed_seq` resultantes quando atribuído a uma matriz. Para ver um exemplo que use `seed_seq` com um gerador de número aleatório, consulte [\<random>](../standard-library/random.md).

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

```Output
seed_seq::size(): 0
seed_seq::param():
Generating a sequence of 5 elements into an array:
505382999
163489202
3932644188
763126080
73937346

seed_seq::size(): 3
seed_seq::param(): 1701 1729 1791
Generating a sequence of 5 elements into an array:
1730669648
1954224479
2809786021
1172893117
2393473414

seed_seq::size(): 7
seed_seq::param(): 65 32 66 32 67 32 68
Generating a sequence of 5 elements into an array:
3139879222
3775111734
1084804564
2485037668
1985355432
```

## <a name="remarks"></a>Comentários

Funções membro dessa classe não geram exceções.

## <a name="requirements"></a>Requisitos

**Cabeçalho:** \<random>

**Namespace:** std

## <a name="see-also"></a>Consulte também

[\<random>](../standard-library/random.md)<br/>
