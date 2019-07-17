---
title: '&lt;complex&gt;'
ms.date: 11/04/2016
f1_keywords:
- <complex>
- std::<complex>
helpviewer_keywords:
- complex header
ms.assetid: 5e728995-3059-496a-9ce9-61d1bfbe4f2b
ms.openlocfilehash: e3d4330f8b0fcbce940f6647ebb8920f0b1969b6
ms.sourcegitcommit: 3590dc146525807500c0477d6c9c17a4a8a2d658
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/16/2019
ms.locfileid: "68244680"
---
# <a name="ltcomplexgt"></a>&lt;complex&gt;

Define a classe de modelo do contêiner `complex` e seus modelos de suporte.

## <a name="requirements"></a>Requisitos

**Cabeçalho**: \<complexo>

**Namespace:** std

## <a name="remarks"></a>Comentários

Um número complexo é um par ordenado de números reais. Em termos puramente geométricos, o plano complexo é o plano real bidimensional. As qualidades especiais do plano complexo que o diferencial do plano real acontecem devido a ele ter uma estrutura algébrica adicional. Essa estrutura algébrica tem duas operações fundamentais:

- Adição definida como (*uma*, *b*) + (*c*, *1!d*) = (*um* + *c* , *b* + *1!d*)

- Multiplicação definida como (*uma*, *b*) \* (*c*, *1!d*) = (*CA*  -  *bd*, *ad* + *bc*)

O conjunto de números complexos com as operações de adição e multiplicação complexas é um campo no sentido algébrico padrão:

- As operações de adição e multiplicação são comutativas e associativas e a multiplicação se distribui sobre a adição exatamente como ocorre com a adição e a multiplicação reais no campo de números reais.

- O número complexo (0, 0) é a identidade de adição e (1, 0) é a identidade de multiplicação.

- O inverso de adição para um número complexo (*uma*, *b*) é (-*um*, -*b*) e o inverso de multiplicação para todos esses números complexos exceto (0, 0) é

   (*a*/(*a*<sup>2</sup> + *b*<sup>2</sup>), -*b*/(*a*<sup>2</sup> + *b*<sup>2</sup>))

Por que representa um número complexo *z* = (*um*, *b*) na forma *z* = *um*  +  *bi*, onde *eu*<sup>2</sup> = -1, as regras de álgebra do conjunto de números reais pode ser aplicada ao conjunto de números complexos e aos seus componentes. Por exemplo:

   (1 + 2*i*) \* (2 + 3*i*) = 1 \* (2 + 3*i*) + 2*i* \* (2 + 3*i*) = (2 + 3*i*) + (4*i* + 6*i*<sup>2</sup>) = (2 - 6) + (3 + 4)*i* = -4 + 7*i*

O sistema de números complexos é um campo, mas não é um campo ordenado. Não há nenhuma ordenação dos números complexos como há para o campo de números reais e seus subconjuntos para que as desigualdades não podem ser aplicadas a números complexos como estão em números reais.

Há três formas comuns de representar um número complexo *z*:

- Cartesiana: *z* = *um* + *bi*

- Polar: *z* = *r* (cos *p* + *eu* sin *p*)

- Exponencial: *z* = *r* \* *eletrônico*<sup>*ip*</sup>

Os termos usados nessas representações padrão de um número complexo são referidas como o seguinte:

- O componente cartesiano real ou parte real *a*.

- O componente cartesiano imaginário ou parte imaginária *b*.

- O módulo ou valor absoluto de um número complexo *r*.

- O argumento ou ângulo de fase *p* em radianos.

A menos que especificado de outra forma, funções que podem retornar vários valores são necessárias para retornar um valor de entidade de segurança para seus argumentos de maior que - π e menor que ou igual a + π para manter a eles com valor único. Todos os ângulos devem ser expresso em radianos, em que há 2π radianos (360 graus) em um círculo.

## <a name="members"></a>Membros

### <a name="functions"></a>Funções

|||
|-|-|
|[abs](../standard-library/complex-functions.md#abs)|Calcula o módulo de um número complexo.|
|[acos](../standard-library/complex-functions.md#acos)||
|[acosh](../standard-library/complex-functions.md#acosh)||
|[arg](../standard-library/complex-functions.md#arg)|Extrai o argumento de um número complexo.|
|[asin](../standard-library/complex-functions.md#asin)||
|[asinh](../standard-library/complex-functions.md#asinh)||
|[atan](../standard-library/complex-functions.md#atan)||
|[atanh](../standard-library/complex-functions.md#atanh)||
|[conj](../standard-library/complex-functions.md#conj)|Retorna o conjugado complexo de um número complexo.|
|[cos](../standard-library/complex-functions.md#cos)|Retorna o cosseno de um número complexo.|
|[cosh](../standard-library/complex-functions.md#cosh)|Retorna o cosseno hiperbólico de um número complexo.|
|[exp](../standard-library/complex-functions.md#exp)|Retorna a função exponencial de um número complexo.|
|[imag](../standard-library/complex-functions.md#imag)|Extrai o componente imaginário de um número complexo.|
|[log](../standard-library/complex-functions.md#log)|Retorna o logaritmo natural de um número complexo.|
|[log10](../standard-library/complex-functions.md#log10)|Retorna o logaritmo de base 10 de um número complexo.|
|[norm](../standard-library/complex-functions.md#norm)|Extrai a norma de um número complexo.|
|[polar](../standard-library/complex-functions.md#polar)|Retorna o número complexo, que corresponde a um módulo e um argumento especificado, na forma cartesiana.|
|[pow](../standard-library/complex-functions.md#pow)|Avalia o número complexo obtido elevando uma base que é um número complexo à potência de outro número complexo.|
|[PROJ](../standard-library/complex-functions.md#proj)||
|[real](../standard-library/complex-functions.md#real)|Extrai o componente real de um número complexo.|
|[sin](../standard-library/complex-functions.md#sin)|Retorna o seno de um número complexo.|
|[sinh](../standard-library/complex-functions.md#sinh)|Retorna o seno hiperbólico de um número complexo.|
|[sqrt](../standard-library/complex-functions.md#sqrt)|Retorna a raiz quadrada de um número complexo.|
|[tan](../standard-library/complex-functions.md#tan)|Retorna a tangente de um número complexo.|
|[tanh](../standard-library/complex-functions.md#tanh)|Retorna a tangente hiperbólica de um número complexo.|

### <a name="operators"></a>Operadores

|||
|-|-|
|[operator!=](../standard-library/complex-operators.md#op_neq)|Testa a desigualdade entre dois números complexos, um ou ambos podem pertencer ao subconjunto do tipo das partes reais e imaginárias.|
|[operator*](../standard-library/complex-operators.md#op_star)|Multiplica dois números complexos, um ou ambos podem pertencer ao subconjunto do tipo das partes reais e imaginárias.|
|[operator+](../standard-library/complex-operators.md#op_add)|Adiciona dois números complexos, um ou ambos podem pertencer ao subconjunto do tipo das partes reais e imaginárias.|
|[operator-](../standard-library/complex-operators.md#operator-)|Subtrai dois números complexos, um ou ambos podem pertencer ao subconjunto do tipo das partes reais e imaginárias.|
|[operator/](../standard-library/complex-operators.md#op_div)|Divide dois números complexos, um ou ambos podem pertencer ao subconjunto do tipo das partes reais e imaginárias.|
|[operator<\<](../standard-library/complex-operators.md#op_lt_lt)|Uma função de modelo que insere um número complexo no fluxo de saída.|
|[operator==](../standard-library/complex-operators.md#op_eq_eq)|Testa a igualdade entre dois números complexos, um ou ambos podem pertencer ao subconjunto do tipo das partes reais e imaginárias.|
|[operator>>](../standard-library/complex-operators.md#op_gt_gt)|Uma função de modelo que extrai um valor complexo do fluxo de entrada.|

### <a name="classes"></a>Classes

|||
|-|-|
|[complex\<double>](../standard-library/complex-double.md)|A classe de modelo explicitamente especializada descreve um objeto que armazena um par ordenado de objetos, ambos do tipo **duplas**, em que o primeiro representa a parte real de um número complexo e o segundo representa a parte imaginária.|
|[complex\<float>](../standard-library/complex-float.md)|A classe de modelo explicitamente especializada descreve um objeto que armazena um par ordenado de objetos, ambos do tipo **float**, em que o primeiro representa a parte real de um número complexo e o segundo representa a parte imaginária.|
|[complex\<long double>](../standard-library/complex-long-double.md)|A classe de modelo explicitamente especializada descreve um objeto que armazena um par ordenado de objetos, ambos do tipo **longo duplo**, em que o primeiro representa a parte real de um número complexo e o segundo representa a parte imaginária.|
|[complex](../standard-library/complex-class.md)|A classe de modelo descreve um objeto usado para representar o sistema de números complexos e efetuar operações aritméticas complexas.|

### <a name="literals"></a>Literais

O cabeçalho \<complex> define os seguintes [literais definidos pelo usuário](../cpp/user-defined-literals-cpp.md) que criam um número complexo com a parte real sendo zero e a parte imaginária sendo o valor do parâmetro de entrada.

|||
|-|-|
|`constexpr complex<long double> operator""il(long double d)`<br /><br /> `constexpr complex<long double> operator""il(unsigned long long d)`|Retorna: `complex<long double>{0.0L, static_cast<long double>(d)}`|
|`constexpr complex<double> operator""i(long double d)`<br /><br /> `constexpr complex<double> operator""i(unsigned long long d)`|Retorna: `complex<double>{0.0, static_cast<double>(d)}`.|
|`constexpr complex<float> operator""if(long double d)`<br /><br /> `constexpr complex<float> operator""if(unsigned long long d)`|Retorna: `complex<float>{0.0f, static_cast<float>(d)}`.|

## <a name="see-also"></a>Consulte também

[Referência de Arquivos de Cabeçalho](../standard-library/cpp-standard-library-header-files.md)<br/>
[Acesso Thread-Safe na Biblioteca Padrão C++](../standard-library/thread-safety-in-the-cpp-standard-library.md)<br/>
