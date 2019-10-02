---
title: /arch (x64)
ms.date: 10/01/2019
ms.assetid: ecda22bf-5bed-43f4-99fb-88aedd83d9d8
ms.openlocfilehash: 0ade6d9f744339ebaf38981d81334340b56080cb
ms.sourcegitcommit: 4517932a67bbf2db16cfb122d3bef57a43696242
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/02/2019
ms.locfileid: "71816223"
---
# <a name="arch-x64"></a>/arch (x64)

Especifica a arquitetura da geração de código em x64. Consulte também [/Arch (x86)](arch-x86.md) e [/Arch (ARM)](arch-arm.md).

## <a name="syntax"></a>Sintaxe

```
/arch:[AVX|AVX2|AVX512]
```

## <a name="arguments"></a>Argumentos

**/arch:AVX**<br/>
Habilita o uso de instruções Intel Advanced Vector Extensions.

**/arch:AVX2**<br/>
Habilita o uso de instruções Intel Advanced Vector Extensions 2.

**/Arch: AVX512**<br/>
Habilita o uso de instruções 512 de extensões de vetor avançadas da Intel.

## <a name="remarks"></a>Comentários

A opção **/Arch** permite o uso de determinadas extensões de conjunto de instruções, especialmente para o cálculo de vetor, disponível em processadores da Intel e AMD. Em geral, os processadores introduzidos mais recentemente podem dar suporte a extensões adicionais sobre aquelas com suporte dos processadores mais antigos, embora você deva consultar a documentação de um processador específico ou testar o suporte à extensão do conjunto de instruções usando [_ _ CPUID](../../intrinsics/cpuid-cpuidex.md) antes de executar o código usando uma extensão de conjunto de instruções.

**/Arch** afeta apenas a geração de código para funções nativas. Quando você usa [/CLR](clr-common-language-runtime-compilation.md) para compilar, **/Arch** não tem efeito na geração de código para funções gerenciadas.

As extensões de processador têm as seguintes características:

- O modo padrão usa instruções SSE2 para cálculos de vetor e ponto flutuante escalares. Essas instruções permitem o cálculo com vetores de 128 bits de valores inteiros de precisão simples, de precisão dupla e de 1, 2, 4 ou 8 bytes, bem como valores de ponto flutuante escalares de precisão simples e dupla.

- O **AVX** introduziu uma codificação de instrução alternativa para instruções escalares de vetor e de ponto flutuante que permite vetores de 128 bits ou 256 bits e estende todos os resultados de vetor para o tamanho de vetor completo. (Para compatibilidade herdada, as instruções de vetor estilo SSE preservam todos os bits além do bit 127.) A maioria das operações de ponto flutuante são estendidas para 256 bits.

- **AVX2** estende a maioria das operações de inteiros para os vetores de 256 bits e habilita o uso de instruções de FMA (adição de multiplicação) com fusível.

- O **AVX-512** introduziu outro formulário de codificação de instrução que permite vetores de 512 bits, além de alguns outros recursos opcionais. Também foram adicionadas instruções para operações adicionais.

Cada opção **/Arch** também pode habilitar o uso de outras instruções não vetoriais associadas a essa opção. Um exemplo é o uso de determinadas instruções BMI quando **/Arch: AVX2** é especificado.

O símbolo de pré-processador `__AVX__` é definido quando a opção de compilador **/Arch: AVX**, **/Arch: AVX2** ou **/Arch: AVX512** é especificada. O símbolo de pré-processador `__AVX2__` é definido quando a opção de compilador **/Arch: AVX2** ou **/Arch: AVX512** é especificada. Os símbolos de pré-processador `__AVX512F__`, `__AVX512CD__`, `__AVX512BW__`, `__AVX512DQ__` e `__AVX512VL__` são definidos quando a opção de compilador **/Arch: AVX512** é especificada. Para obter mais informações, confira [Macros predefinidas](../../preprocessor/predefined-macros.md). A opção **/Arch: AVX2** foi introduzida no Visual Studio 2013 atualização 2, versão 12.0.34567.1. Suporte limitado para **/Arch: AVX512** foi adicionado ao visual Studio 2017 e expandido no visual Studio 2019.

### <a name="to-set-the-archavx-archavx2-or-archavx512-compiler-option-in-visual-studio"></a>Para definir a opção de compilador/arch: AVX,/Arch: AVX2 ou/Arch: AVX512 no Visual Studio

1. Abra a caixa de diálogo **páginas de propriedades** do projeto. Para obter mais informações, confira [Definir as propriedades de build e do compilador do C++ no Visual Studio](../working-with-project-properties.md).

1. Selecione as **Propriedades de configuração**, **CC++ /** Folder.

1. Selecione a página de propriedades **geração de código** .

1. Na caixa suspensa **habilitar conjunto de instruções avançado** , escolha extensões de **vetor avançadas (/Arch: AVX)** , **extensões de vetor avançadas 2 (/Arch: AVX2)** ou **extensões de vetor avançadas 512 (/Arch: AVX512)** .

### <a name="to-set-this-compiler-option-programmatically"></a>Para definir essa opção do compilador via programação

- Consulte <xref:Microsoft.VisualStudio.VCProjectEngine.VCCLCompilerTool.EnableEnhancedInstructionSet%2A>.

## <a name="see-also"></a>Consulte também

[/arch (arquitetura mínima de CPU)](arch-minimum-cpu-architecture.md)<br/>
[Opções do compilador MSVC](compiler-options.md)<br/>
[Sintaxe da linha de comando do compilador MSVC](compiler-command-line-syntax.md)
