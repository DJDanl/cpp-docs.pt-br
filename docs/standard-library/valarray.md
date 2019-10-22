---
title: '&lt;valarray&gt;'
ms.date: 11/04/2016
f1_keywords:
- <valarray>
helpviewer_keywords:
- valarray header
ms.assetid: 30835415-21c1-4801-8f24-6bbef7dd8ecd
ms.openlocfilehash: ed90273fe293ae2e08c3c91762c12c42bb368c16
ms.sourcegitcommit: 590e488e51389066a4da4aa06d32d4c362c23393
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/21/2019
ms.locfileid: "72688769"
---
# <a name="ltvalarraygt"></a>&lt;valarray&gt;

Define o modelo de classe valarray e vários modelos e funções de classe de suporte.

## <a name="requirements"></a>Requisitos

**Cabeçalho:** \<valarray>

**Namespace:** std

> [!NOTE]
> A biblioteca \<valarray > usa a instrução ' #include < initializer_list > '.

## <a name="remarks"></a>Comentários

Esses modelos e funções de classe são permitidos latitude incomum no interesse do desempenho aprimorado. Especificamente, qualquer função que retorna o tipo `valarray<T1>` pode retornar um objeto de algum outro tipo T2. Nesse caso, qualquer função que aceite um ou mais argumentos do tipo `valarray<T2>` deve ter sobrecargas que aceitem combinações arbitrárias desses argumentos, cada uma substituída por um argumento do tipo T2.

## <a name="members"></a>Membros

### <a name="functions"></a>Funções

|||
|-|-|
|[abs](../standard-library/valarray-functions.md#abs)|Opera nos elementos de uma valarray de entrada retornando uma valarray cujos elementos são iguais ao valor absoluto dos elementos da valarray de entrada.|
|[acos](../standard-library/valarray-functions.md#acos)|Opera nos elementos de uma valarray de entrada retornando uma valarray cujos elementos são iguais ao arco cosseno dos elementos da valarray de entrada.|
|[asin](../standard-library/valarray-functions.md#asin)|Opera nos elementos de uma valarray de entrada retornando uma valarray cujos elementos são iguais ao arco seno dos elementos da valarray de entrada.|
|[atan](../standard-library/valarray-functions.md#atan)|Opera nos elementos de uma valarray de entrada retornando uma valarray cujos elementos são iguais ao valor de entidade de segurança do arco tangente dos elementos da valarray de entrada.|
|[atan2](../standard-library/valarray-functions.md#atan2)|Retorna uma valarray cujos elementos são iguais ao arco tangente dos componentes cartesianos especificados por uma combinação de constantes e de elementos de valarrays.|
|[begin](../standard-library/valarray-functions.md#begin)||
|[cos](../standard-library/valarray-functions.md#cos)|Opera nos elementos de uma valarray de entrada retornando uma valarray cujos elementos são iguais ao cosseno dos elementos da valarray de entrada.|
|[cosh](../standard-library/valarray-functions.md#cosh)|Opera nos elementos de uma valarray de entrada retornando uma valarray cujos elementos são iguais ao cosseno hiperbólico dos elementos da valarray de entrada.|
|[end](../standard-library/valarray-functions.md#end)||
|[exp](../standard-library/valarray-functions.md#exp)|Opera nos elementos de uma valarray de entrada retornando uma valarray cujos elementos são iguais ao exponencial natural dos elementos da valarray de entrada.|
|[log](../standard-library/valarray-functions.md#log)|Opera nos elementos de uma valarray de entrada retornando uma valarray cujos elementos são iguais ao logaritmo natural dos elementos da valarray de entrada.|
|[log10](../standard-library/valarray-functions.md#log10)|Opera nos elementos de uma valarray de entrada retornando uma valarray cujos elementos são iguais ao logaritmo de base 10 ou comum dos elementos da valarray de entrada.|
|[pow](../standard-library/valarray-functions.md#pow)|Opera nos elementos de constantes e de valarrays de entrada retornando uma valarray cujos elementos são iguais a uma base especificada pelos elementos de uma valarray de entrada ou uma constante elevada a um expoente especificado pelos elementos de uma constante ou de uma valarray de entrada.|
|[sin](../standard-library/valarray-functions.md#sin)|Opera nos elementos de uma valarray de entrada retornando uma valarray cujos elementos são iguais ao seno dos elementos da valarray de entrada.|
|[sinh](../standard-library/valarray-functions.md#sinh)|Opera nos elementos de uma valarray de entrada retornando uma valarray cujos elementos são iguais ao seno hiperbólico dos elementos da valarray de entrada.|
|[sqrt](../standard-library/valarray-functions.md#sqrt)|Opera nos elementos de uma valarray de entrada retornando uma valarray cujos elementos são iguais à raiz quadrada dos elementos da valarray de entrada.|
|[swap](../standard-library/valarray-functions.md#swap)||
|[tan](../standard-library/valarray-functions.md#tan)|Opera nos elementos de uma valarray de entrada retornando uma valarray cujos elementos são iguais à tangente dos elementos da valarray de entrada.|
|[tanh](../standard-library/valarray-functions.md#tanh)|Opera nos elementos de uma valarray de entrada retornando uma valarray cujos elementos são iguais à tangente hiperbólica dos elementos da valarray de entrada.|

### <a name="operators"></a>Operadores

|||
|-|-|
|[operator!=](../standard-library/valarray-operators.md#op_neq)|Testa se os elementos correspondentes de duas valarrays de tamanhos iguais são diferentes ou se todos os elementos de uma valarray são diferentes de um valor especificado do tipo de elemento da valarray.|
|[operator%](../standard-library/valarray-operators.md#op_mod)|Obtém o resto da divisão dos elementos correspondentes de duas valarrays de tamanhos iguais, da divisão de uma valarray por um valor especificado do tipo de elemento da valarray ou da divisão de um valor especificado por uma valarray.|
|[operator&](../standard-library/valarray-operators.md#op_amp)|Obtém o `AND` bit a bit entre os elementos correspondentes de duas valarrays de tamanhos iguais ou entre uma valarray e um valor especificado do tipo de elemento.|
|[operator&&](../standard-library/valarray-operators.md#op_amp_amp)|Obtém o `AND` lógico entre os elementos correspondentes de duas valarrays de tamanhos iguais ou entre uma valarray e um valor especificado do tipo de elemento da valarray.|
|[operator>](../standard-library/valarray-operators.md#op_gt)|Testa se os elementos de uma valarray são maiores que os elementos de uma valarray de tamanho igual ou se todos os elementos de uma valarray são maiores ou menores que um valor especificado do tipo de elemento da valarray.|
|[operator>=](../standard-library/valarray-operators.md#op_gt_eq)|Testa se os elementos de uma valarray são maiores ou iguais aos elementos de uma valarray de tamanho igual ou se todos os elementos de uma valarray são maiores, menores ou iguais a um valor especificado.|
|[operator>>](../standard-library/valarray-operators.md#op_gt_gt)|Desloca para a direita os bits de cada elemento de uma valarray por um número especificado de posições ou por um valor elemento a elemento especificado por uma segunda valarray.|
|[operator<](../standard-library/valarray-operators.md#op_lt)|Testa se os elementos de uma valarray são menores que os elementos de uma valarray de tamanho igual ou se todos os elementos de uma valarray são maiores ou menores que um valor especificado.|
|[operator<=](../standard-library/valarray-operators.md#op_lt_eq)|Testa se os elementos de uma valarray são menores ou iguais aos elementos de uma valarray de tamanho igual ou se todos os elementos de uma valarray são maiores, menores ou iguais a um valor especificado.|
|[operator<<](../standard-library/valarray-operators.md#op_lt_lt)|Desloca para a esquerda os bits de cada elemento de uma valarray por um número especificado de posições ou por um valor elemento a elemento especificado por uma segunda valarray.|
|[operator*](../standard-library/valarray-operators.md#op_star)|Obtém o produto elemento a elemento entre os elementos correspondentes de duas valarrays de tamanhos iguais ou entre uma valarray de um valor especificado do tipo de elemento da valarray.|
|[operator+](../standard-library/valarray-operators.md#op_add)|Obtém a soma elemento a elemento entre os elementos correspondentes de duas valarrays de tamanhos iguais ou entre uma valarray de um valor especificado do tipo de elemento da valarray.|
|[operator-](../standard-library/valarray-operators.md#operator-)|Obtém a subtração elemento a elemento entre os elementos correspondentes de duas valarrays de tamanhos iguais ou entre uma valarray de um valor especificado do tipo de elemento da valarray.|
|[operator/](../standard-library/valarray-operators.md#op_div)|Obtém o quociente elemento a elemento entre os elementos correspondentes de duas valarrays de tamanhos iguais ou entre uma valarray de um valor especificado do tipo de elemento da valarray.|
|[operator==](../standard-library/valarray-operators.md#op_eq_eq)|Testa se os elementos correspondentes de duas valarrays de tamanhos iguais são iguais ou se todos os elementos de uma valarray são iguais a um valor especificado do tipo de elemento da valarray.|
|[operator^](../standard-library/valarray-operators.md#op_xor)|Obtém o bit a bit exclusivo `OR` entre os elementos correspondentes de duas valarrays de tamanhos iguais ou entre uma valarray e um valor especificado do tipo de elemento.|
|[operator&#124;](../standard-library/valarray-operators.md#op_or)|Obtém o `OR` bit a bit entre os elementos correspondentes de duas valarrays de tamanhos iguais ou entre uma valarray e um valor especificado do tipo de elemento.|
|[operator&#124;&#124;](../standard-library/valarray-operators.md#op_lor)|Obtém o `OR` lógico entre os elementos correspondentes de duas valarrays de tamanhos iguais ou entre uma valarray e um valor especificado do tipo de elemento da valarray.|

### <a name="classes"></a>Classes

|||
|-|-|
|[Classe gslice](../standard-library/gslice-class.md)|Uma classe de utilitário para valarray usada para definir fatias multidimensionais de um valarray.|
|[Classe gslice_array](../standard-library/gslice-array-class.md)|Um modelo de classe auxiliar interno que dá suporte a objetos de fatia geral, fornecendo operações entre as matrizes de subconjuntos definidas pela fatia geral de um valarray.|
|[Classe indirect_array](../standard-library/indirect-array-class.md)|Um modelo de classe auxiliar interno que dá suporte a objetos que são subconjuntos de valarrays fornecendo operações entre as matrizes de subconjuntos definidas especificando um subconjunto de índices de um valarray pai.|
|[Classe mask_array](../standard-library/mask-array-class.md)|Um modelo de classe auxiliar interno que dá suporte a objetos que são subconjuntos de valarrays pai, especificados com uma expressão booleana, fornecendo operações entre as matrizes de subconjuntos.|
|[Classe slice](../standard-library/slice-class.md)|Uma classe de utilitário para valarray usada para definir subconjuntos unidimensionais, parecidos com um vetor de uma valarray.|
|[Classe slice_array](../standard-library/slice-array-class.md)|Um modelo de classe auxiliar interno que dá suporte a objetos de fatia, fornecendo operações entre as matrizes de subconjuntos definidas pela fatia de um valarray.|
|[Classe valarray](../standard-library/valarray-class.md)|O modelo de classe descreve um objeto que controla uma sequência de elementos do tipo `Type` que são armazenados como uma matriz e projetados para executar operações matemáticas de alta velocidade, otimizadas para desempenho computacional.|

### <a name="specializations"></a>Especializações

|||
|-|-|
|[Classe valarray\<bool>](../standard-library/valarray-bool-class.md)|Uma versão especializada do modelo de classe valarray \<**tipo**> a elementos do tipo **bool**.|

## <a name="see-also"></a>Consulte também

[Referência de Arquivos de Cabeçalho](../standard-library/cpp-standard-library-header-files.md)\
[Acesso Thread-Safe na Biblioteca Padrão C++](../standard-library/thread-safety-in-the-cpp-standard-library.md)
