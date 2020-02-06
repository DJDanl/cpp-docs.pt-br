---
title: /Qspectre-load
description: Descreve a opção/Qspectre-Load doC++ Microsoft C/Compiler (MSVC).
ms.date: 01/28/2020
helpviewer_keywords:
- /Qspectre-load
ms.openlocfilehash: a766cf9b7eef11b7c5819cbdaa7706ab5b80c608
ms.sourcegitcommit: 0f4ee9056d65043fa5a715f0ad1031c0ed30e2b6
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 02/05/2020
ms.locfileid: "77035525"
---
# <a name="qspectre-load"></a>/Qspectre-load

Especifica a geração de compilador de instruções de serialização para cada instrução de carga. Essa opção estende o sinalizador **/Qspectre** , reduzindo qualquer possível **ataque de canal lateral de execução especulativa** com base em cargas.

## <a name="syntax"></a>Sintaxe

> **/Qspectre-load**

## <a name="remarks"></a>Comentários

**/Qspectre-Load** faz com que o compilador detecte cargas da memória e insira instruções de serialização depois delas. As instruções de fluxo de controle que carregam memória, incluindo `RET` e `CALL`, são divididas em uma carga e uma transferência de fluxo de controle. A carga é seguida por um `LFENCE` para garantir que a carga seja protegida. Há casos em que o compilador não pode dividir as instruções de fluxo de controle, como a instrução `jmp`, para que ele use uma técnica de mitigação alternativa. Por exemplo, o compilador atenua `jmp [rax]` adicionando instruções para carregar o destino de forma não destrutiva antes de inserir um LFENCE, como mostrado aqui:

```asm
    xor rbx, [rax]
    xor rbx, [rax]  ; force a load of [rax]
    lfence          ; followed by an LFENCE
    jmp [rax]
```

Como **/Qspectre-Load** interrompe a especulação de todas as cargas, o impacto no desempenho é alto. A mitigação não é adequada em todos os lugares. Se houver blocos de código críticos de desempenho que não exigem proteção, você poderá desabilitar essas atenuações usando `__declspec(spectre(nomitigation))`. Para obter mais informações, consulte [__declspec Spectre](../../cpp/spectre.md).

A opção **/Qspectre-Load** está desativada por padrão e dá suporte a todos os níveis de otimização.

A opção **/Qspectre-Load** está disponível no Visual Studio 2019 versão 16,5 e posterior. Essa opção só está disponível em compiladores destinados a processadores x86 e x64. Ele não está disponível em compiladores que visam processadores ARM.

### <a name="to-set-this-compiler-option-in-the-visual-studio-development-environment"></a>Para definir esta opção do compilador no ambiente de desenvolvimento do Visual Studio

1. Abra a caixa de diálogo **Páginas de Propriedades** do projeto. Para obter detalhes, confira [Definir as propriedades de build e do compilador do C++ no Visual Studio](../working-with-project-properties.md).

2. Selecione as **Propriedades de configuração** > página de propriedades de **geração de código** **C/C++**  > .

3. Selecione um novo valor para a propriedade de **mitigação Spectre** . Escolha **OK** para aplicar a alteração.

### <a name="to-set-this-compiler-option-programmatically"></a>Para definir essa opção do compilador via programação

- Consulte <xref:Microsoft.VisualStudio.VCProjectEngine.VCCLCompilerTool.AdditionalOptions%2A>.

## <a name="see-also"></a>Consulte também

[Opções de/q (operações de nível baixo)](q-options-low-level-operations.md)\
[Opções do compilador MSVC](compiler-options.md)\
[Sintaxe de linha de comando do compilador MSVC](compiler-command-line-syntax.md)
