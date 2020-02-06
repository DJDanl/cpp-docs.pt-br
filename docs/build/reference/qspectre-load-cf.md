---
title: /Qspectre-load-cf
description: Descreve a opção Microsoft CC++ /Compiler (MSVC)/Qspectre-load-cf.
ms.date: 01/28/2020
helpviewer_keywords:
- /Qspectre-load-cf
no-loc:
- Qspectre-load-cf
ms.openlocfilehash: c32b843df517cb6fbe662fba0b592cbf745f1764
ms.sourcegitcommit: 0f4ee9056d65043fa5a715f0ad1031c0ed30e2b6
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 02/05/2020
ms.locfileid: "77035518"
---
# /Qspectre-load-cf

Especifica a geração de compilador de instruções de serialização para cada instrução de fluxo de controle que contém uma carga. Essa opção executa um subconjunto das atenuações feitas pela opção [/Qspectre-Load](qspectre-load.md) .

## <a name="syntax"></a>Sintaxe

> **/Qspectre-load-cf**

## <a name="remarks"></a>Comentários

**/Qspectre-load-cf** faz com que o compilador detecte instruções de fluxo de controle `JMP`, `RET`e `CALL` que são carregadas da memória e para inserir instruções de serialização após a carga. Sempre que possível, essas instruções são divididas em uma carga e uma transferência de fluxo de controle. A carga é seguida por um `LFENCE` para garantir que a carga seja protegida. Há casos em que o compilador não pode dividir instruções, como a instrução `JMP`, para que ele use uma técnica de mitigação alternativa. Por exemplo, o compilador atenua `jmp [rax]` adicionando instruções para carregar o destino de forma não destrutiva antes de inserir um LFENCE, como mostrado aqui:

```asm
    xor rbx, [rax]
    xor rbx, [rax]  ; force a load of [rax]
    lfence          ; followed by an LFENCE
    jmp [rax]
```

Como **/Qspectre-load-cf** para a especulação de todas as cargas em instruções de fluxo de controle, o impacto no desempenho é alto. A mitigação não é adequada em todos os lugares. Se houver blocos de código críticos de desempenho que não exigem proteção, você poderá desabilitar essas atenuações usando `__declspec(spectre(nomitigation))`.

A opção **/Qspectre-load-cf** está desativada por padrão e dá suporte a todos os níveis de otimização.

A opção de **Qspectre-load-cfde/** está disponível no Visual Studio 2019 versão 16,5 e posterior. Essa opção só está disponível em compiladores destinados a processadores x86 e x64. Ele não está disponível em compiladores que visam processadores ARM.

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
