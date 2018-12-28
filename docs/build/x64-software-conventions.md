---
title: x64 convenções de software
ms.date: 12/17/2018
helpviewer_keywords:
- x64 coding conventions
- Visual C++, x64 calling conventions
ms.assetid: 750f3d97-1706-4840-b2fc-41a007329a08
ms.openlocfilehash: eea2059a8c06a8ba4d032b87fb41d7d51bc8eac2
ms.sourcegitcommit: ff3cbe4235b6c316edcc7677f79f70c3e784ad76
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/19/2018
ms.locfileid: "53627288"
---
# <a name="x64-software-conventions"></a>x64 convenções de software

Esta seção descreve a metodologia de convenção de chamada para x64, a extensão de 64 bits para x86 de C++ arquitetura.

## <a name="overview-of-x64-calling-conventions"></a>Visão geral das convenções de chamada x64

Duas diferenças importantes entre o x86 e x64 são a capacidade de endereçamento de 64 bits e um conjunto simples de 16 a 64-bit registra para uso geral. Dado o conjunto de registro expandida, x64 usa o [fastcall](../cpp/fastcall.md) convenção de chamada e um modelo de tratamento de exceções com base em RISC. O `__fastcall` convenção usa registros para os primeiros quatro argumentos e o quadro de pilha para passar argumentos adicionais. Para obter detalhes sobre o x64 convenção de chamada, incluindo o uso de registro de pilha de parâmetros, retornar valores e o desenrolamento de pilha, consulte [convenção de chamada de x64](x64-calling-convention.md).

## <a name="enable-optimization-for-x64"></a>Habilitar a otimização para x64

A opção de compilador a seguir ajuda a otimizar o aplicativo para x64:

- [/favor (otimizar para especificações da arquitetura)](../build/reference/favor-optimize-for-architecture-specifics.md)

## <a name="types-and-storage"></a>Tipos e armazenamento

Esta seção descreve a enumeração e o armazenamento de tipos de dados para o x64 de arquitetura.

### <a name="scalar-types"></a>tipos escalares

Embora seja possível acessar os dados com nenhum alinhamento, é recomendável para alinhar os dados em seu limite natural ou um múltiplo, para evitar a perda de desempenho. Enums são inteiros constantes e são tratados como inteiros de 32 bits. A tabela a seguir descreve a definição de tipo e o armazenamento recomendado para os dados, pois pertence ao alinhamento usando os seguintes valores de alinhamento:

- Byte - 8 bits

- Palavra - 16 bits

- Palavras duplas - 32 bits

- Quadword - 64 bits

- Octaword - 128 bits

|||||
|-|-|-|-|
|Tipo escalar|Tipo de dados C|Tamanho de armazenamento (em bytes)|Alinhamento recomendado|
|**INT8**|**char**|1|Byte|
|**UINT8**|**unsigned char**|1|Byte|
|**INT16**|**short**|2|Palavra|
|**UINT16**|**unsigned short**|2|Palavra|
|**INT32**|**int**, **longo**|4|Palavras duplas|
|**UINT32**|**int sem sinal, unsigned long**|4|Palavras duplas|
|**INT64**|**__int64**|8|Quadword|
|**UINT64**|**unsigned __int64**|8|Quadword|
|**FP32 (único precisão)**|**float**|4|Palavras duplas|
|**FP64 (duplas precisão)**|**double**|8|Quadword|
|**PONTEIRO**|__\*__|8|Quadword|
|**__m64**|**struct __m64**|8|Quadword|
|**__m128**|**struct __m128**|16|Octaword|

### <a name="aggregates-and-unions"></a>Agregações e uniões

Outros tipos, como matrizes, estruturas e uniões, têm requisitos de alinhamento mais rígidos que garantem consistente agregada e união armazenamento e recuperação de dados. Aqui estão as definições de matriz, a estrutura e união:

- Matriz

   Contém um grupo ordenado de objetos de dados adjacentes. Cada objeto é chamado de um *elemento*. Todos os elementos dentro de uma matriz tem o mesmo tamanho e tipo de dados.

- Estrutura

   Contém um grupo ordenado de objetos de dados. Diferentemente dos elementos de uma matriz, os objetos dentro de uma estrutura de dados podem ter tamanhos e tipos de dados diferentes. Cada objeto de dados em uma estrutura é chamada uma *membro*.

- União

   Um objeto que contém qualquer um de um conjunto de membros nomeados. Os membros do conjunto nomeado podem ser de qualquer tipo. O armazenamento alocado para uma união é igual para o armazenamento necessário para o maior membro dessa união, além de qualquer preenchimento necessários para o alinhamento.

A tabela a seguir mostra o alinhamento fortemente sugerido para os membros de escalares de uniões e estruturas.

||||
|-|-|-|
|Tipo escalar|Tipo de dados C|Alinhamento necessário|
|**INT8**|**char**|Byte|
|**UINT8**|**unsigned char**|Byte|
|**INT16**|**short**|Palavra|
|**UINT16**|**unsigned short**|Palavra|
|**INT32**|**int**, **longo**|Palavras duplas|
|**UINT32**|**int sem sinal, unsigned long**|Palavras duplas|
|**INT64**|**__int64**|Quadword|
|**UINT64**|**unsigned __int64**|Quadword|
|**FP32 (único precisão)**|**float**|Palavras duplas|
|**FP64 (duplas precisão)**|**double**|Quadword|
|**PONTEIRO**|<strong>\*</strong>|Quadword|
|**__m64**|**struct __m64**|Quadword|
|**__m128**|**struct __m128**|Octaword|

As seguintes regras de alinhamento de agregação se aplicam:

- O alinhamento de uma matriz é o mesmo que o alinhamento de um dos elementos da matriz.

- O alinhamento de início de uma estrutura ou uma união é o alinhamento máximo de qualquer membro individual. Cada membro dentro da estrutura ou união deve ser colocado em seu alinhamento adequado, conforme definido na tabela anterior, que pode exigir o preenchimento interno implícito, dependendo do membro anterior.

- Tamanho da estrutura deve ser um múltiplo inteiro de seu alinhamento, que pode exigir o preenchimento após o último membro. Já que estruturas e uniões podem ser agrupadas em matrizes, cada elemento da matriz de uma estrutura ou união deve começar e terminar no alinhamento adequado previamente determinado.

- É possível alinhar dados de maneira a ser maior do que os requisitos de alinhamento, desde que as regras anteriores são mantidas.

- Um compilador individual pode ajustar o empacotamento de uma estrutura por motivos de tamanho. Por exemplo [/Zp (alinhamento de membro de Struct)](../build/reference/zp-struct-member-alignment.md) permite ajustar o empacotamento de estruturas.

### <a name="examples-of-structure-alignment"></a>Exemplos de alinhamento da estrutura

Os quatro exemplos a seguir cada declaram que uma estrutura alinhada ou união e os números correspondentes ilustram o layout da estrutura ou união na memória. Cada coluna em uma figura representa um byte de memória, e o número na coluna indica o deslocamento do que bytes. O nome da segunda linha de cada figura corresponde ao nome de uma variável na declaração. Colunas sombreadas indicam o preenchimento que é necessário para alcançar o alinhamento especificado.

#### <a name="example-1"></a>Exemplo 1

```C
// Total size = 2 bytes, alignment = 2 bytes (word).

_declspec(align(2)) struct {
    short a;      // +0; size = 2 bytes
}
```

![Layout de estrutura de exemplo 1 de conversão AMD](../build/media/vcamd_conv_ex_1_block.png "layout da estrutura AMD conversão exemplo 1")

#### <a name="example-2"></a>Exemplo 2

```C
// Total size = 24 bytes, alignment = 8 bytes (quadword).

_declspec(align(8)) struct {
    int a;       // +0; size = 4 bytes
    double b;    // +8; size = 8 bytes
    short c;     // +16; size = 2 bytes
}
```

![Layout de estrutura de exemplo 2 de conversão AMD](../build/media/vcamd_conv_ex_2_block.png "layout da estrutura AMD conversão exemplo 2")

#### <a name="example-3"></a>Exemplo 3:

```C
// Total size = 22 bytes, alignment = 4 bytes (doubleword).

_declspec(align(4)) struct {
    char a;       // +0; size = 1 byte
    short b;      // +2; size = 2 bytes
    char c;       // +4; size = 1 byte
    int d;        // +8; size = 4 bytes
}
```

![Layout de estrutura de exemplo 2 de conversão AMD](../build/media/vcamd_conv_ex_3_block.png "layout da estrutura AMD conversão exemplo 2")

#### <a name="example-4"></a>Exemplo 4

```C
// Total size = 8 bytes, alignment = 8 bytes (quadword).

_declspec(align(8)) union {
    char *p;      // +0; size = 8 bytes
    short s;      // +0; size = 2 bytes
    long l;       // +0; size = 4 bytes
}
```

![AMD conversão exemplo 4 união layouit](../build/media/vcamd_conv_ex_4_block.png "layouit union do AMD conversão exemplo 4")

### <a name="bitfields"></a>Campos de bits

Campos de bits da estrutura são limitados a 64 bits e pode ser do tipo assinado int, int sem sinal, int64 ou int64 sem sinal. Os campos de bits que cruzam o limite de tipo ignorará o bits para alinhar o campo de bits para o alinhamento do tipo Avançar. Por exemplo, os campos de bits de inteiro não podem cruzar um limite de 32 bits.

### <a name="conflicts-with-the-x86-compiler"></a>Está em conflito com o x86 compilador

Tipos de dados que são maiores do que 4 bytes não são alinhadas automaticamente na pilha quando você usa o x86 compilador para compilar um aplicativo. Porque a arquitetura para x86 de compilador é uma pilha alinhado de 4 bytes, algo maior do que 4 bytes, por exemplo, um inteiro de 64 bits, não pode ser alinhada automaticamente para um endereço de 8 bytes.

Trabalhar com dados não alinhados tem implicações de dois.

- Pode levar mais tempo para acessar locais não alinhados, que é necessário para acessar locais alinhados.

- Locais não alinhados não podem ser usados em operações interconectadas.

Se você precisar de mais de alinhamento estrito, use `__declspec(align(N))` em suas declarações de variável. Isso faz com que o compilador alinhar dinamicamente a pilha para atender às suas especificações. No entanto, ajustar dinamicamente a pilha em tempo de execução pode causar a execução mais lenta do seu aplicativo.

## <a name="register-usage"></a>Uso do registro

X64 arquitetura fornece para 16 registros de uso geral (citados como registros de inteiros), bem como para 16 registros XMM/YMM registra disponíveis para uso de ponto flutuante. Os registros voláteis são registros a partir do zero presumidos pelo chamador para serem destruídos em uma chamada. Os registros não voláteis são obrigados a manter seus valores em uma chamada de função e devem ser salvos pelo receptor da chamada se usados.

### <a name="register-volatility-and-preservation"></a>Registrar a volatilidade e preservação

A tabela a seguir descreve como cada registro é usado nas chamadas de função:

||||
|-|-|-|
|Registro|Status|Uso|
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
|XMM0, YMM0|Volátil|Primeiro argumento FP; primeiro argumento de tipo vetorial quando `__vectorcall` for usado|
|XMM1, YMM1|Volátil|Segundo argumento FP; segundo argumento de tipo vetorial quando `__vectorcall` for usado|
|XMM2, YMM2|Volátil|Terceiro argumento FP; terceiro argumento de tipo vetorial quando `__vectorcall` for usado|
|XMM3, YMM3|Volátil|Quarto argumento FP; quarto argumento de tipo vetorial quando `__vectorcall` for usado|
|XMM4, YMM4|Volátil|Deve ser preservado conforme necessário pelo chamador; quinto argumento de tipo vetorial quando `__vectorcall` for usado|
|XMM5, YMM5|Volátil|Deve ser preservado conforme necessário pelo chamador; sexto argumento de tipo vetorial quando `__vectorcall` for usado|
|XMM6:XMM15, YMM6:YMM15|Não volátil (XMM), Volátil (metade superior de YMM)|Deve ser preservado pelo receptor da chamada. Os registros YMM devem ser preservados conforme necessário pelo chamador.|

Na saída da função e na entrada da função de biblioteca em tempo de execução C chamadas e chamadas do sistema Windows, o sinalizador de direção do CPU register sinalizadores é esperado a ser apagado.

## <a name="stack-usage"></a>Uso da pilha

Para obter detalhes sobre a alocação da pilha, alinhamento, tipos de função e quadros de pilha em x64, consulte [uso de pilha x64](stack-usage.md).

## <a name="prolog-and-epilog"></a>Prólogo e epílogo

Cada função que aloca espaço em pilha, chama outras funções, salva os registros não voláteis ou usa o tratamento de exceção deve ter um prólogo cujos limites de endereço são descritos nos dados de desenrolamento associados com a entrada da tabela de função respectiva e epílogos em cada saída para uma função. Para obter detalhes sobre o prólogo necessário e o código de epílogo em x64, consulte [x64 prólogo e epílogo](prolog-and-epilog.md).

## <a name="x64-exception-handling"></a>x64 tratamento de exceção

Para obter informações sobre as convenções e estruturas de dados usadas para implementar o tratamento de exceções estruturado e comportamento em x64 de tratamento de exceções C++, consulte [x64 tratamento de exceção](exception-handling-x64.md).

## <a name="intrinsics-and-inline-assembly"></a>Intrínsecos e embutida de assembly

Uma das restrições para o x64 compilador é fazer com que não há suporte de assembler embutido. Isso significa que funções que não pode ser gravada em C ou C++ será terá que ser escrito como sub-rotinas ou funções intrínsecas suportadas pelo compilador. Determinadas funções são dependentes do desempenho, enquanto outros não são. Funções de diferenciação de desempenho devem ser implementadas como funções intrínsecas.

Os intrínsecos suportados pelo compilador são descritos em [intrínsecos do compilador](../intrinsics/compiler-intrinsics.md).

## <a name="image-format"></a>Formato de imagem

X64 é o formato de imagem executável PE32 +. Imagens executáveis (DLLs e EXEs) são restritas a um tamanho máximo de 2 gigabytes, para que o endereçamento relativo com um deslocamento de 32 bits pode ser usado para tratar dados de imagem estática. Esses dados incluem a tabela de endereços de importação, constantes de cadeia de caracteres, os dados globais estáticos e assim por diante.

## <a name="see-also"></a>Consulte também

[Convenções de chamada](../cpp/calling-conventions.md)