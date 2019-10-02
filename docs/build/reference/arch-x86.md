---
title: /arch (x86)
ms.date: 10/01/2019
ms.assetid: 9dd5a75d-06e4-4674-aade-33228486078d
ms.openlocfilehash: b1e5501f6edd3eb016395380ff476250c0c388b9
ms.sourcegitcommit: 4517932a67bbf2db16cfb122d3bef57a43696242
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/02/2019
ms.locfileid: "71816312"
---
# <a name="arch-x86"></a>/arch (x86)

Especifica a arquitetura para a geração de código no x86. Consulte também [/Arch (x64)](arch-x64.md) e [/Arch (ARM)](arch-arm.md).

## <a name="syntax"></a>Sintaxe

```
/arch:[IA32|SSE|SSE2|AVX|AVX2|AVX512]
```

## <a name="arguments"></a>Argumentos

**/arch:IA32**<br/>
Não especifica instruções aprimoradas e especifica x87 para cálculos de ponto flutuante.

**/arch:SSE**<br/>
Habilita o uso de instruções SSE.

**/arch:SSE2**<br/>
Habilita o uso de instruções SSE2. Essa é a instrução padrão em plataformas x86 se nenhuma opção **/Arch** for especificada.

**/arch:AVX**<br/>
Habilita o uso de instruções Intel Advanced Vector Extensions.

**/arch:AVX2**<br/>
Habilita o uso de instruções Intel Advanced Vector Extensions 2.

**/Arch: AVX512**<br/>
Habilita o uso de instruções 512 de extensões de vetor avançadas da Intel.

## <a name="remarks"></a>Comentários

A opção **/Arch** habilita ou desabilita o uso de determinadas extensões de conjunto de instruções, especialmente para cálculo de vetor, disponível em processadores da Intel e AMD. Em geral, os processadores introduzidos mais recentemente podem dar suporte a extensões adicionais sobre aquelas com suporte dos processadores mais antigos, embora você deva consultar a documentação de um processador específico ou testar o suporte à extensão do conjunto de instruções usando [_ _ CPUID](../../intrinsics/cpuid-cpuidex.md) antes de executar o código usando uma extensão de conjunto de instruções.

**/Arch** afeta apenas a geração de código para funções nativas. Quando você usa [/CLR](clr-common-language-runtime-compilation.md) para compilar, **/Arch** não tem efeito na geração de código para funções gerenciadas.

As opções de **/Arch** referem-se às extensões do conjunto de instruções com as seguintes características:

- **IA32** é o conjunto de instruções x86 de 32 bits herdado sem nenhuma operação de vetor e usando x87 para cálculos de ponto flutuante.

- A **SSE** permite o cálculo com vetores de até quatro valores de ponto flutuante de precisão simples. Instruções de ponto flutuante escalares correspondentes foram adicionadas também.

- O **SSE2** permite o cálculo com vetores de 128 bits de valores inteiros de precisão simples, de precisão dupla e de 1, 2, 4 ou 8 bytes. Instruções escalares de precisão dupla também foram adicionadas.

- O **AVX** introduziu uma codificação de instrução alternativa para instruções escalares de vetor e de ponto flutuante que permite vetores de 128 bits ou 256 bits e estende todos os resultados de vetor para o tamanho de vetor completo. (Para compatibilidade herdada, as instruções de vetor estilo SSE preservam todos os bits além do bit 127.) A maioria das operações de ponto flutuante são estendidas para 256 bits.

- **AVX2** estende a maioria das operações de inteiros para os vetores de 256 bits e habilita o uso de instruções de FMA (adição de multiplicação) com fusível.

- O **AVX512** introduziu outro formulário de codificação de instrução que permite vetores de 512 bits, além de alguns outros recursos opcionais. Também foram adicionadas instruções para operações adicionais.

O otimizador escolhe quando e como usar instruções de vetor dependendo de qual **/Arch** é especificado. As computações escalares de ponto flutuante são executadas com as instruções SSE ou AVX quando disponíveis. Algumas convenções de chamada especificam a passagem de argumentos de ponto flutuante na pilha x87 e, como resultado, seu código pode usar uma mistura de instruções x87 e SSE/AVX para cálculos de ponto flutuante. Instruções de vetor de inteiro também podem ser usadas para algumas operações de inteiro de 64 bits quando disponíveis.

Além das instruções escalares de vetor e de ponto flutuante, cada opção **/Arch** também pode habilitar o uso de outras instruções não vetoriais associadas a essa opção. Um exemplo é a família de instruções CMOVcc que apareceu pela primeira vez nos processadores Intel Pentium Pro. Como as instruções SSE foram introduzidas com o processador subseqüente Intel Pentium III, as instruções de CMOVcc podem ser geradas, exceto quando **/Arch: IA32** for especificado.

As operações de ponto flutuante normalmente são arredondadas para precisão dupla (64 bits) no código x87, mas você pode usar `_controlfp` para modificar a palavra de controle de FP, incluindo a definição do controle de precisão para precisão estendida (80 bits) ou de precisão única (32 bits). Para obter mais informações, consulte [_control87, _controlfp, \__control87_2](../../c-runtime-library/reference/control87-controlfp-control87-2.md). SSE e AVX têm instruções separadas de precisão simples e de precisão dupla para cada operação, portanto, não há nenhum equivalente para o código SSE/AVX. Isso pode alterar a forma como os resultados são arredondados quando o resultado de uma operação de ponto flutuante é usado diretamente em um cálculo adicional em vez de atribuí-lo a uma variável de usuário. Considere o seguinte:

```cpp
r = f1 * f2 + d;  // Different results are possible on SSE/SSE2.
```

Com atribuição explícita:

```cpp
t = f1 * f2;   // Do f1 * f2, round to the type of t.
r = t + d;     // This should produce the same overall result
               // whether x87 stack is used or SSE/SSE2 is used.
```

**/Arch** e [/QIfist](qifist-suppress-ftol.md) não podem ser usados no mesmo compiland. A opção **/QIfist** altera o comportamento de arredondamento da conversão de ponto flutuante para inteiro. O comportamento padrão é truncar (arredondar para zero), enquanto a opção **/QIfist** especifica o uso do modo de arredondamento do ambiente de ponto flutuante. Como isso altera o comportamento de todas as conversões de ponto flutuante para inteiro, esse sinalizador foi preterido. Ao compilar para SSE ou AVX, você pode arredondar um valor de ponto flutuante para um inteiro usando o modo de arredondamento do ambiente de ponto flutuante usando uma sequência de função intrínseca:

```cpp
int convert_float_to_int(float x) {
    return _mm_cvtss_si32(_mm_set_ss(x));
}

int convert_double_to_int(double x) {
    return _mm_cvtsd_si32(_mm_set_sd(x));
}
```

As macros `_M_IX86_FP`, `__AVX__`, `__AVX2__`, `__AVX512F__`, `__AVX512CD__`, `__AVX512BW__`, `__AVX512DQ__` e `__AVX512VL__` indicam qual opção de compilador, se houver, **/Arch** foi usada. Para obter mais informações, confira [Macros predefinidas](../../preprocessor/predefined-macros.md). A opção **/Arch: AVX2** e a macro `__AVX2__` foram introduzidas no Visual Studio 2013 atualização 2, versão 12.0.34567.1. Suporte limitado para **/Arch: AVX512** foi adicionado ao visual Studio 2017 e expandido no visual Studio 2019.

### <a name="to-set-this-compiler-option-for-avx-avx2-avx512-ia32-sse-or-sse2-in-visual-studio"></a>Para definir essa opção de compilador para AVX, AVX2, AVX512, IA32, SSE ou SSE2 no Visual Studio

1. Abra a caixa de diálogo **páginas de propriedades** do projeto. Para obter mais informações, confira [Definir as propriedades de build e do compilador do C++ no Visual Studio](../working-with-project-properties.md).

1. Selecione as **Propriedades de configuração**, **CC++ /** Folder.

1. Selecione a página de propriedades **geração de código** .

1. Modifique a propriedade **habilitar conjunto de instruções avançado** .

### <a name="to-set-this-compiler-option-programmatically"></a>Para definir essa opção do compilador via programação

- Consulte <xref:Microsoft.VisualStudio.VCProjectEngine.VCCLCompilerTool.EnableEnhancedInstructionSet%2A>.

## <a name="see-also"></a>Consulte também

[/arch (arquitetura mínima de CPU)](arch-minimum-cpu-architecture.md)<br/>
[Opções do compilador MSVC](compiler-options.md)<br/>
[Sintaxe da linha de comando do compilador MSVC](compiler-command-line-syntax.md)
