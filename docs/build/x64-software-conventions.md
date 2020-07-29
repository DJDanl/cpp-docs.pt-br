---
title: Convenções de software x64
ms.date: 12/17/2018
helpviewer_keywords:
- x64 coding conventions
- Visual C++, x64 calling conventions
ms.assetid: 750f3d97-1706-4840-b2fc-41a007329a08
ms.openlocfilehash: 4755cfcf98c9eadbd944e06a56f86ca89a33b0a3
ms.sourcegitcommit: 1f009ab0f2cc4a177f2d1353d5a38f164612bdb1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/27/2020
ms.locfileid: "87223766"
---
# <a name="x64-software-conventions"></a>Convenções de software x64

Esta seção descreve a metodologia de Convenção de chamada do C++ para x64, a extensão de 64 bits para a arquitetura x86.

## <a name="overview-of-x64-calling-conventions"></a>Visão geral das convenções de chamada x64

Duas diferenças importantes entre x86 e x64 são o recurso de endereçamento de 64 bits e um conjunto simples de registros de 16 64 bits para uso geral. Considerando o conjunto de registros expandido, o x64 usa a Convenção de chamada [__fastcall](../cpp/fastcall.md) e um modelo de tratamento de exceção baseado em RISC. A **`__fastcall`** Convenção usa registros para os primeiros quatro argumentos e o quadro de pilha para passar argumentos adicionais. Para obter detalhes sobre a Convenção de chamada x64, incluindo o uso de registro, parâmetros de pilha, valores de retorno e desenrolamento de pilha, consulte [Convenção de chamada x64](x64-calling-convention.md).

## <a name="enable-optimization-for-x64"></a>Habilitar a otimização para x64

A opção de compilador a seguir ajuda a otimizar seu aplicativo para x64:

- [/favor (otimizar para especificações de arquitetura)](../build/reference/favor-optimize-for-architecture-specifics.md)

## <a name="types-and-storage"></a>Tipos e armazenamento

Esta seção descreve a enumeração e o armazenamento de tipos de dados para a arquitetura x64.

### <a name="scalar-types"></a>Tipos escalares

Embora seja possível acessar dados com qualquer alinhamento, é recomendável alinhar os dados em seu limite natural ou alguns vários para evitar a perda de desempenho. Enums são inteiros constantes e são tratados como inteiros de 32 bits. A tabela a seguir descreve a definição de tipo e o armazenamento recomendado para dados, pois ele pertence ao alinhamento usando os seguintes valores de alinhamento:

- Bits de byte 8

- Palavras-16 bits

- Doubleword-32 bits

- Quadword-64 bits

- Octaword-128 bits

|||||
|-|-|-|-|
|Tipo escalar|Tipo de dados C|Tamanho do armazenamento (em bytes)|Alinhamento recomendado|
|**INT8**|**`char`**|1|Byte|
|**UINT8**|**`unsigned char`**|1|Byte|
|**INT16**|**`short`**|2|Word|
|**UINT16**|**`unsigned short`**|2|Word|
|**INT32**|**`int`**, **`long`**|4|Doubleword|
|**UINT32**|**int não assinado, longo sem sinal**|4|Doubleword|
|**INT64**|**`__int64`**|8|Quadword|
|**UINT64**|**unsigned __int64**|8|Quadword|
|**FP32 (precisão única)**|**`float`**|4|Doubleword|
|**FP64 (precisão dupla)**|**`double`**|8|Quadword|
|**REFERE**|__\*__|8|Quadword|
|**`__m64`**|**__m64 de struct**|8|Quadword|
|**`__m128`**|**__m128 de struct**|16|Octaword|

### <a name="aggregates-and-unions"></a>Agregações e uniões

Outros tipos, como matrizes, structs e uniões, têm requisitos de alinhamento mais estritos que garantem a agregação consistente e o armazenamento de União e a recuperação de dados. Aqui estão as definições para matriz, estrutura e União:

- Array

   Contém um grupo ordenado de objetos de dados adjacentes. Cada objeto é chamado de *elemento*. Todos os elementos dentro de uma matriz têm o mesmo tamanho e tipo de dados.

- Estrutura

   Contém um grupo ordenado de objetos de dados. Ao contrário dos elementos de uma matriz, os objetos de dados dentro de uma estrutura podem ter tipos e tamanhos de dados diferentes. Cada objeto de dados em uma estrutura é chamado de *membro*.

- Union

   Um objeto que contém qualquer um de um conjunto de membros nomeados. Os membros do conjunto nomeado podem ser de qualquer tipo. O armazenamento alocado para uma União é igual ao armazenamento necessário para o maior membro dessa União, além de qualquer preenchimento necessário para alinhamento.

A tabela a seguir mostra o alinhamento altamente sugerido para os membros escalares de uniões e estruturas.

||||
|-|-|-|
|Tipo escalar|Tipo de dados C|Alinhamento necessário|
|**INT8**|**`char`**|Byte|
|**UINT8**|**`unsigned char`**|Byte|
|**INT16**|**`short`**|Word|
|**UINT16**|**`unsigned short`**|Word|
|**INT32**|**`int`**, **`long`**|Doubleword|
|**UINT32**|**int não assinado, longo sem sinal**|Doubleword|
|**INT64**|**`__int64`**|Quadword|
|**UINT64**|**unsigned __int64**|Quadword|
|**FP32 (precisão única)**|**`float`**|Doubleword|
|**FP64 (precisão dupla)**|**`double`**|Quadword|
|**REFERE**|<strong>\*</strong>|Quadword|
|**`__m64`**|**__m64 de struct**|Quadword|
|**`__m128`**|**__m128 de struct**|Octaword|

As regras de alinhamento agregado a seguir se aplicam:

- O alinhamento de uma matriz é o mesmo que o alinhamento de um dos elementos da matriz.

- O alinhamento do início de uma estrutura ou de uma União é o alinhamento máximo de qualquer membro individual. Cada membro dentro da estrutura ou União deve ser colocado em seu alinhamento adequado, conforme definido na tabela anterior, que pode exigir preenchimento interno implícito, dependendo do membro anterior.

- O tamanho da estrutura deve ser um múltiplo integral de seu alinhamento, o que pode exigir preenchimento posterior ao último membro. Como as estruturas e as uniões podem ser agrupadas em matrizes, cada elemento da matriz de uma estrutura ou União deve começar e terminar no alinhamento adequado determinado anteriormente.

- É possível alinhar os dados de forma que eles sejam maiores que os requisitos de alinhamento, desde que as regras anteriores sejam mantidas.

- Um compilador individual pode ajustar a embalagem de uma estrutura por motivos de tamanho. Por exemplo, [/ZP (alinhamento de Membro struct)](../build/reference/zp-struct-member-alignment.md) permite ajustar a embalagem de estruturas.

### <a name="examples-of-structure-alignment"></a>Exemplos de alinhamento da estrutura

Os quatro exemplos a seguir declaram uma estrutura alinhada ou União, e os valores correspondentes ilustram o layout dessa estrutura ou União na memória. Cada coluna em uma figura representa um byte de memória e o número na coluna indica o deslocamento desse byte. O nome na segunda linha de cada figura corresponde ao nome de uma variável na declaração. As colunas sombreadas indicam o preenchimento necessário para alcançar o alinhamento especificado.

#### <a name="example-1"></a>Exemplo 1

```C
// Total size = 2 bytes, alignment = 2 bytes (word).

_declspec(align(2)) struct {
    short a;      // +0; size = 2 bytes
}
```

![Layout de estrutura do exemplo de conversão AMD 1](../build/media/vcamd_conv_ex_1_block.png "Layout de estrutura do exemplo de conversão AMD 1")

#### <a name="example-2"></a>Exemplo 2

```C
// Total size = 24 bytes, alignment = 8 bytes (quadword).

_declspec(align(8)) struct {
    int a;       // +0; size = 4 bytes
    double b;    // +8; size = 8 bytes
    short c;     // +16; size = 2 bytes
}
```

![Layout da estrutura do exemplo de conversão AMD 2](../build/media/vcamd_conv_ex_2_block.png "Layout da estrutura do exemplo de conversão AMD 2")

#### <a name="example-3"></a>Exemplo 3

```C
// Total size = 12 bytes, alignment = 4 bytes (doubleword).

_declspec(align(4)) struct {
    char a;       // +0; size = 1 byte
    short b;      // +2; size = 2 bytes
    char c;       // +4; size = 1 byte
    int d;        // +8; size = 4 bytes
}
```

![Layout da estrutura do exemplo de conversão AMD 2](../build/media/vcamd_conv_ex_3_block.png "Layout da estrutura do exemplo de conversão AMD 2")

#### <a name="example-4"></a>Exemplo 4

```C
// Total size = 8 bytes, alignment = 8 bytes (quadword).

_declspec(align(8)) union {
    char *p;      // +0; size = 8 bytes
    short s;      // +0; size = 2 bytes
    long l;       // +0; size = 4 bytes
}
```

![Exemplo de conversão AMD 4 Union layouit](../build/media/vcamd_conv_ex_4_block.png "Exemplo de conversão AMD 4 Union layouit")

### <a name="bitfields"></a>Campos de bits

Os campos de bits de estrutura são limitados a 64 bits e podem ser do tipo assinado int, não assinado int, Int64 ou Int64 não assinado. Os campos de bits que cruzam o limite de tipo irão ignorar bits para alinhar o campo de teletexto ao alinhamento de tipo seguinte. Por exemplo, Integer bitfields pode não cruzar um limite de 32 bits.

### <a name="conflicts-with-the-x86-compiler"></a>Conflitos com o compilador x86

Os tipos de dados maiores que 4 bytes não são alinhados automaticamente na pilha quando você usa o compilador x86 para compilar um aplicativo. Como a arquitetura do compilador x86 é uma pilha alinhada de 4 bytes, qualquer item maior que 4 bytes, por exemplo, um inteiro de 64 bits, não pode ser alinhado automaticamente a um endereço de 8 bytes.

Trabalhar com dados não alinhados tem duas implicações.

- Pode levar mais tempo para acessar locais não alinhados do que é necessário para acessar locais alinhados.

- Os locais não alinhados não podem ser usados em operações interbloqueadas.

Se você precisar de um alinhamento mais estrito, use `__declspec(align(N))` em suas declarações de variável. Isso faz com que o compilador alinhe dinamicamente a pilha para atender às suas especificações. No entanto, o ajuste dinâmico da pilha em tempo de execução pode causar uma execução mais lenta do seu aplicativo.

## <a name="register-usage"></a>Registrar uso

A arquitetura x64 fornece para 16 registros de uso geral (em seguida chamados de registros inteiros), bem como 16 registros XMM/YMM disponíveis para uso de ponto flutuante. Os registros voláteis são registros a partir do zero presumidos pelo chamador para serem destruídos em uma chamada. Os registros não voláteis são obrigados a manter seus valores em uma chamada de função e devem ser salvos pelo receptor da chamada se usados.

### <a name="register-volatility-and-preservation"></a>Registrar volatilidade e preservação

A tabela a seguir descreve como cada registro é usado nas chamadas de função:

||||
|-|-|-|
|Registre-se|Status|Uso|
|RAX|Volátil|Registro de valores retornados|
|RCX|Volátil|Primeiro argumento inteiro|
|RDX|Volátil|Segundo argumento inteiro|
|R8|Volátil|Terceiro argumento inteiro|
|R9|Volátil|Quarto argumento inteiro|
|R10, R11|Volátil|Deve ser preservado, conforme a necessidade do chamador; usado em instruções syscall/sysret|
|R12, R15|Não volátil|Deve ser preservado pelo receptor da chamada|
|RDI|Não volátil|Deve ser preservado pelo receptor da chamada|
|RSI|Não volátil|Deve ser preservado pelo receptor da chamada|
|RBX|Não volátil|Deve ser preservado pelo receptor da chamada|
|RBP|Não volátil|Pode ser usado como um ponteiro de quadro; deve ser preservado pelo receptor da chamada|
|RSP|Não volátil|Ponteiro de pilha|
|XMM0, YMM0|Volátil|Primeiro argumento FP; primeiro argumento de tipo Vector quando **`__vectorcall`** é usado|
|XMM1, YMM1|Volátil|Segundo argumento FP; segundo argumento de tipo de vetor quando **`__vectorcall`** é usado|
|XMM2, YMM2|Volátil|Terceiro argumento FP; terceiro argumento de tipo de vetor quando **`__vectorcall`** é usado|
|XMM3, YMM3|Volátil|Quarto argumento FP; quarto argumento de tipo de vetor quando **`__vectorcall`** é usado|
|XMM4, YMM4|Volátil|Deve ser preservado conforme necessário pelo chamador; quinto argumento de tipo de vetor quando **`__vectorcall`** é usado|
|XMM5, YMM5|Volátil|Deve ser preservado conforme necessário pelo chamador; sexto argumento de tipo de vetor quando **`__vectorcall`** é usado|
|XMM6:XMM15, YMM6:YMM15|Não volátil (XMM), Volátil (metade superior de YMM)|Deve ser preservado pelo receptor. Os registros YMM devem ser preservados conforme necessário pelo chamador.|

Na função Exit e na entrada de função para chamadas da biblioteca de tempo de execução C e chamadas de sistema do Windows, o sinalizador de direção no registro de sinalizadores de CPU deve ser limpo.

## <a name="stack-usage"></a>Uso da pilha

Para obter detalhes sobre alocação de pilha, alinhamento, tipos de função e quadros de pilha em x64, consulte [uso de pilha x64](stack-usage.md).

## <a name="prolog-and-epilog"></a>Prólogo e epílogo

Cada função que aloca espaço de pilha, chama outras funções, salva registros não voláteis ou usa o tratamento de exceções deve ter um prólogo cujos limites de endereço são descritos nos dados de desenrolamento associados à entrada da respectiva tabela de funções e epilogs a cada saída para uma função. Para obter detalhes sobre o prólogo necessário e o código epílogo em x64, consulte [prólogo e epílogo de x64](prolog-and-epilog.md).

## <a name="x64-exception-handling"></a>Tratamento de exceções x64

Para obter informações sobre as convenções e estruturas de dados usadas para implementar o tratamento de exceções estruturado e o comportamento de manipulação de exceção do C++ no x64, consulte [manipulação de exceção de x64](exception-handling-x64.md).

## <a name="intrinsics-and-inline-assembly"></a>Intrínsecos e assembly embutido

Uma das restrições para o compilador x64 é não ter suporte embutido para Assembler. Isso significa que as funções que não podem ser escritas em C ou C++ precisarão ser escritas como sub-rotinas ou como funções intrínsecas com suporte pelo compilador. Determinadas funções são sensíveis ao desempenho, enquanto outras não. Funções sensíveis ao desempenho devem ser implementadas como funções intrínsecas.

Os intrínsecores suportados pelo compilador são descritos em [intrínsecos do compilador](../intrinsics/compiler-intrinsics.md).

## <a name="image-format"></a>Formato da imagem

O formato de imagem executável x64 é PE32 +. Imagens executáveis (DLLs e EXEs) são restritas a um tamanho máximo de 2 gigabytes, portanto, o endereçamento relativo com uma substituição de 32 bits pode ser usado para endereçar dados de imagem estáticos. Esses dados incluem a tabela de endereços de importação, constantes de cadeia de caracteres, dados globais estáticos e assim por diante.

## <a name="see-also"></a>Confira também

[Convenções de chamada](../cpp/calling-conventions.md)
