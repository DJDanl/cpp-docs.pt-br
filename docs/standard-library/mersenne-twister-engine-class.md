---
title: Classe mersenne_twister_engine
ms.date: 11/04/2016
f1_keywords:
- random/std::mersenne_twister_engine
helpviewer_keywords:
- mersenne_twister_engine class
ms.assetid: 7ee968fa-a1cc-450f-890f-7305de062685
ms.openlocfilehash: 79613c76b3ea6dc15643e83a15d5bd6d90b60c6a
ms.sourcegitcommit: 590e488e51389066a4da4aa06d32d4c362c23393
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/21/2019
ms.locfileid: "72687697"
---
# <a name="mersenne_twister_engine-class"></a>Classe mersenne_twister_engine

Gera uma sequência aleatória e de alta qualidade de inteiros com base no algoritmo Mersenne Twister.

## <a name="syntax"></a>Sintaxe

```cpp
template <class UIntType,
    size_t W, size_t N, size_t M, size_t R,
    UIntType A, size_t U, UIntType D, size_t S,
    UIntType B, size_t T, UIntType C, size_t L, UIntType F>
class mersenne_twister_engine;
```

### <a name="parameters"></a>Parâmetros

@No__t_1 de *UIntType*
O tipo de resultado inteiro sem sinal. Para ver os tipos possíveis, consulte [\<random>](../standard-library/random.md).

*W* \
**Tamanho da palavra**. Tamanho de cada palavra da sequência de estado, em bits. **Pré-condição**: `2u < W ≤ numeric_limits<UIntType>::digits`

*N* \
**Tamanho do estado**. A quantidade de elementos (valores) presentes na sequência de estado.

*M* \
**Tamanho do deslocamento**. A quantidade de elementos a serem ignorados a cada mudança. **Pré-condição**: `0 < M ≤ N`

*R*\
**Bits da máscara**. **Pré-condição**: `R ≤ W`

*Um* \
**Máscara XOR**. **Pré-condição**: `A ≤ (1u<<W) - 1u`

*U*, *S*, *T*, *L* \
**Parâmetros de deformação do deslocamento**. Usados como valores de deslocamento durante a codificação (deformação). Pré-condição: `U,S,T,L ≤ W`

*D*, *B*, *C* \
**Parâmetros de deformação da máscara de bits**. Usados como valores da máscara de bits durante a codificação (deformação). Pré-condição: `D,B,C ≤ (1u<<W) - 1u`

@No__t_1 de *F*
**Multiplicador de inicialização**. Usado para ajudar a iniciar a sequência. Pré-condição: `F ≤ (1u<<W) - 1u`

## <a name="members"></a>Membros

||||
|-|-|-|
|`mersenne_twister_engine::mersenne_twister_engine`|`mersenne_twister_engine::min`|`mersenne_twister_engine::discard`|
|`mersenne_twister_engine::operator()`|`mersenne_twister_engine::max`|`mersenne_twister_engine::seed`|

`default_seed` é um membro constante, definido como `5489u`, usado como valor padrão do parâmetro `mersenne_twister_engine::seed` e construtor de valor único.

Para obter mais informações sobre membros do mecanismo, consulte [\<random>](../standard-library/random.md).

## <a name="remarks"></a>Comentários

Esse modelo de classe descreve um mecanismo de número aleatório, retornando valores no intervalo fechado [`0`, `2`<sup>W</sup>  -  `1`]. Esse mecanismo tem um valor integral alto com `W * (N - 1) + R` bits. Ele extrai os *bits de* cada vez desse valor grande e, quando ele usou todos os bits, ele muda o valor grande deslocando e misturando os bits para que ele tenha um novo conjunto de bits para extrair. O estado do mecanismo é o último `N` valores de `W` bits usados se `operator()` tiver sido chamado pelo menos *N* vezes, caso contrário, os valores de `W` bits de `M` que foram usados e os últimos `N - M` valores da semente.

O gerador torce o valor grande que ele mantém usando um registro de deslocamento de comentários generalizado entrelaçado definido pelos valores de deslocamento *N* e *M*, um valor de trança *R*e uma máscara XOR condicional *a*. Além disso, os bits do registro de deslocamento bruto são embaralhados (violados) de acordo com uma matriz de embaralhamento de bits definida pelos valores *U*, *D*, *S*, *B*, *T*, *C*e *L*.

O argumento do modelo `UIntType` deve ser suficientemente grande para comportar valores até `2`<sup>W</sup> - `1`. Os valores dos demais argumentos do modelo devem satisfazer estes requisitos: `2u < W, 0 < M, M ≤ N, R ≤ W, U ≤ W, S ≤ W, T ≤ W, L ≤ W, W ≤ numeric_limits<UIntType>::digits, A ≤ (1u<<W) - 1u, B ≤ (1u<<W) - 1u, C ≤ (1u<<W) - 1u, D ≤ (1u<<W) - 1u, and F ≤ (1u<<W) - 1u`.

Embora seja possível construir um gerador diretamente do mecanismo, recomendamos que você use um desses typedefs predefinidos:

`mt19937`: mecanismo Mersenne Twister de 32 bits (Matsumoto e Nishimura, 1998).

```cpp
typedef mersenne_twister_engine<unsigned int, 32, 624, 397,
    31, 0x9908b0df,
    11, 0xffffffff,
    7, 0x9d2c5680,
    15, 0xefc60000,
    18, 1812433253> mt19937;
```

`mt19937_64`: mecanismo Mersenne Twister de 64 bits (Matsumoto e Nishimura, 2000).

```cpp
typedef mersenne_twister_engine<unsigned long long, 64, 312, 156,
    31, 0xb5026f5aa96619e9ULL,
    29, 0x5555555555555555ULL,
    17, 0x71d67fffeda60000ULL,
    37, 0xfff7eee000000000ULL,
    43, 6364136223846793005ULL> mt19937_64;
```

Para saber mais sobre o algoritmo Mersenne Twister, consulte o artigo da Wikipedia [Mersenne Twister](https://go.microsoft.com/fwlink/p/?linkid=402356).

## <a name="example"></a>Exemplo

Para obter um exemplo de código, consulte [\<random>](../standard-library/random.md).

## <a name="requirements"></a>Requisitos

**Cabeçalho:** \<random>

**Namespace:** std

## <a name="see-also"></a>Consulte também

[\<random>](../standard-library/random.md)
