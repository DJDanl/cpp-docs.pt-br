---
title: '&lt;complex&gt;'
ms.date: 11/04/2016
f1_keywords:
- <complex>
- std::<complex>
helpviewer_keywords:
- complex header
ms.assetid: 5e728995-3059-496a-9ce9-61d1bfbe4f2b
ms.openlocfilehash: f63fe99238450b8dffbf459ab078a8ecf6623b77
ms.sourcegitcommit: ec6dd97ef3d10b44e0fedaa8e53f41696f49ac7b
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/25/2020
ms.locfileid: "88831496"
---
# <a name="ltcomplexgt"></a>&lt;complex&gt;

Define o modelo de classe de contêiner `complex` e seus modelos de suporte.

## <a name="requirements"></a>Requisitos

**Cabeçalho**: \<complex>

**Namespace:** std

## <a name="remarks"></a>Comentários

Um número complexo é um par ordenado de números reais. Em termos puramente geométricos, o plano complexo é o plano real bidimensional. As qualidades especiais do plano complexo que o diferencial do plano real acontecem devido a ele ter uma estrutura algébrica adicional. Essa estrutura algébrica tem duas operações fundamentais:

- Adição definida como (*a*, *b*) + (*c*, *d*) = (*a*  +  *c*, *b*  +  *d*)

- Multiplicação definida como (*a*, *b*) \* (*c*, *d*) = (*CA*  -  *BD*, *ad*  +  *BC*)

O conjunto de números complexos com as operações de adição e multiplicação complexas é um campo no sentido algébrico padrão:

- As operações de adição e multiplicação são comutativas e associativas e a multiplicação se distribui sobre a adição exatamente como ocorre com a adição e a multiplicação reais no campo de números reais.

- O número complexo (0, 0) é a identidade de adição e (1, 0) é a identidade de multiplicação.

- O inverso aditivo para um número complexo (*a*, *b*) é (-*a*,-*b*) e o inverso multiplicativa para todos esses números complexos, exceto (0, 0) é

   (*a*/(*a*<sup>2</sup>  +  *b*<sup>2</sup>),-*b*/(*a*<sup>2</sup>  +  *b*<sup>2</sup>))

Ao representar um número complexo *z* = (*a*, *b*) no formato *z*  =  *a*  +  *bi*, onde *i*<sup>2</sup> =-1, as regras para a Algebra do conjunto de números reais podem ser aplicadas ao conjunto de números complexos e aos seus componentes. Por exemplo:

   (1 + 2*i*) \* (2 + 3*i*) = 1 \* (2 + 3*i*) + 2*i* \* (2 + 3*i*) = (2 + 3*i*) + (4*i* + 6*i*<sup>2</sup>) = (2-6) + (3 + 4)*i* =-4 + 7*i*

O sistema de números complexos é um campo, mas não é um campo ordenado. Não há nenhuma ordem dos números complexos, pois há para o campo de números reais e seus subconjuntos, portanto, as desigualdades não podem ser aplicadas a números complexos, pois são para números reais.

Há três formas comuns de representar um número complexo *z*:

- Cartesiano: *z*  =  *a*  +  *bi*

- Polar: *z*  =  *r* (cos *p*  +  *i* sin *p*)

- Exponencial: *z*  =  *r* \* *e*<sup>*IP*</sup>

Os termos usados nessas representações padrão de um número complexo são referidas como o seguinte:

- O componente cartesiano real ou parte real *a*.

- O componente cartesiano imaginário ou parte imaginária *b*.

- O módulo ou valor absoluto de um *r*de número complexo.

- O argumento ou ângulo de fase *p* em radianos.

A menos que especificado de outra forma, as funções que podem retornar vários valores são necessárias para retornar um valor principal para seus argumentos maiores que-π e menor ou igual a + π para mantê-los com um único valor. Todos os ângulos devem ser expressos em radianos, onde há 2π radianos (360 graus) em um círculo.

## <a name="members"></a>Membros

### <a name="functions"></a>Funções

|Nome|Descrição|
|-|-|
|[ABS](../standard-library/complex-functions.md#abs)|Calcula o módulo de um número complexo.|
|[acos](../standard-library/complex-functions.md#acos)||
|[acosh](../standard-library/complex-functions.md#acosh)||
|[ARG](../standard-library/complex-functions.md#arg)|Extrai o argumento de um número complexo.|
|[ASIN](../standard-library/complex-functions.md#asin)||
|[asinh](../standard-library/complex-functions.md#asinh)||
|[ATAN](../standard-library/complex-functions.md#atan)||
|[atanh](../standard-library/complex-functions.md#atanh)||
|[conj](../standard-library/complex-functions.md#conj)|Retorna o conjugado complexo de um número complexo.|
|[exibi](../standard-library/complex-functions.md#cos)|Retorna o cosseno de um número complexo.|
|[cosh](../standard-library/complex-functions.md#cosh)|Retorna o cosseno hiperbólico de um número complexo.|
|[exp](../standard-library/complex-functions.md#exp)|Retorna a função exponencial de um número complexo.|
|[imag](../standard-library/complex-functions.md#imag)|Extrai o componente imaginário de um número complexo.|
|[Façam](../standard-library/complex-functions.md#log)|Retorna o logaritmo natural de um número complexo.|
|[log10](../standard-library/complex-functions.md#log10)|Retorna o logaritmo de base 10 de um número complexo.|
|[norm](../standard-library/complex-functions.md#norm)|Extrai a norma de um número complexo.|
|[polar](../standard-library/complex-functions.md#polar)|Retorna o número complexo, que corresponde a um módulo e um argumento especificado, na forma cartesiana.|
|[pow](../standard-library/complex-functions.md#pow)|Avalia o número complexo obtido elevando uma base que é um número complexo à potência de outro número complexo.|
|[proj](../standard-library/complex-functions.md#proj)||
|[real](../standard-library/complex-functions.md#real)|Extrai o componente real de um número complexo.|
|[Sin](../standard-library/complex-functions.md#sin)|Retorna o seno de um número complexo.|
|[sinh](../standard-library/complex-functions.md#sinh)|Retorna o seno hiperbólico de um número complexo.|
|[sqrt](../standard-library/complex-functions.md#sqrt)|Retorna a raiz quadrada de um número complexo.|
|[queimado](../standard-library/complex-functions.md#tan)|Retorna a tangente de um número complexo.|
|[Tanh](../standard-library/complex-functions.md#tanh)|Retorna a tangente hiperbólica de um número complexo.|

### <a name="operators"></a>Operadores

|Nome|Descrição|
|-|-|
|[operador! =](../standard-library/complex-operators.md#op_neq)|Testa a desigualdade entre dois números complexos, um ou ambos podem pertencer ao subconjunto do tipo das partes reais e imaginárias.|
|[operador](../standard-library/complex-operators.md#op_star)|Multiplica dois números complexos, um ou ambos podem pertencer ao subconjunto do tipo das partes reais e imaginárias.|
|[operador +](../standard-library/complex-operators.md#op_add)|Adiciona dois números complexos, um ou ambos podem pertencer ao subconjunto do tipo das partes reais e imaginárias.|
|[operador](../standard-library/complex-operators.md#operator-)|Subtrai dois números complexos, um ou ambos podem pertencer ao subconjunto do tipo das partes reais e imaginárias.|
|[operador](../standard-library/complex-operators.md#op_div)|Divide dois números complexos, um ou ambos podem pertencer ao subconjunto do tipo das partes reais e imaginárias.|
|[<do operador \<](../standard-library/complex-operators.md#op_lt_lt)|Uma função de modelo que insere um número complexo no fluxo de saída.|
|[operador = =](../standard-library/complex-operators.md#op_eq_eq)|Testa a igualdade entre dois números complexos, um ou ambos podem pertencer ao subconjunto do tipo das partes reais e imaginárias.|
|[>>do operador ](../standard-library/complex-operators.md#op_gt_gt)|Uma função de modelo que extrai um valor complexo do fluxo de entrada.|

### <a name="classes"></a>Classes

|Nome|Descrição|
|-|-|
|[complexos\<double>](../standard-library/complex-double.md)|O modelo de classe explicitamente especializado descreve um objeto que armazena um par ordenado de objetos, ambos os tipos **`double`** , em que o primeiro representa a parte real de um número complexo e o segundo representa a parte imaginária.|
|[complexos\<float>](../standard-library/complex-float.md)|O modelo de classe explicitamente especializado descreve um objeto que armazena um par ordenado de objetos, ambos os tipos **`float`** , em que o primeiro representa a parte real de um número complexo e o segundo representa a parte imaginária.|
|[complexos\<long double>](../standard-library/complex-long-double.md)|O modelo de classe explicitamente especializado descreve um objeto que armazena um par ordenado de objetos, ambos os tipos **`long double`** , em que o primeiro representa a parte real de um número complexo e o segundo representa a parte imaginária.|
|[complexos](../standard-library/complex-class.md)|O modelo de classe descreve um objeto usado para representar o sistema de números complexos e executar operações aritméticas complexas.|

### <a name="literals"></a>Literais

O \<complex> cabeçalho define os seguintes [literais definidos pelo usuário](../cpp/user-defined-literals-cpp.md) que criam um número complexo com a parte real sendo zero e a parte imaginário é o valor do parâmetro de entrada.

|Declaração|Descrição|
|-|-|
|`constexpr complex<long double> operator""il(long double d)`<br />`constexpr complex<long double> operator""il(unsigned long long d)`|Retorna: `complex<long double>{0.0L, static_cast<long double>(d)}`|
|`constexpr complex<double> operator""i(long double d)`<br />`constexpr complex<double> operator""i(unsigned long long d)`|Retorna: `complex<double>{0.0, static_cast<double>(d)}`.|
|`constexpr complex<float> operator""if(long double d)`<br />`constexpr complex<float> operator""if(unsigned long long d)`|Retorna: `complex<float>{0.0f, static_cast<float>(d)}`.|

## <a name="see-also"></a>Confira também

[Referência de arquivos de cabeçalho](../standard-library/cpp-standard-library-header-files.md)\
[Segurança de thread na biblioteca padrão C++](../standard-library/thread-safety-in-the-cpp-standard-library.md)
