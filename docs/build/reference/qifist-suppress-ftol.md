---
title: /QIfist (suprimir _ftol)
ms.date: 11/04/2016
f1_keywords:
- /qifist
helpviewer_keywords:
- QIfist compiler option [C++]
- -QIfist compiler option [C++]
- /QIfist compiler option [C++]
ms.assetid: 1afd32a5-f658-4b66-85f4-e0ce4cb955bd
ms.openlocfilehash: 5d6e12a1003ea125b0da4bfef580d8096e97553a
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81336095"
---
# <a name="qifist-suppress-_ftol"></a>/QIfist (suprimir _ftol)

Preterido. Suprime a chamada da função auxiliar `_ftol` quando é necessária uma conversão de um tipo de ponto flutuante para um tipo integral.

## <a name="syntax"></a>Sintaxe

```
/QIfist
```

## <a name="remarks"></a>Comentários

> [!NOTE]
> **/QIfist** só está disponível no compilador x86; esta opção de compilador não está disponível nos compiladores que visam x64 orARM.

Além de converter de um tipo de ponto `_ftol` flutuante para o tipo integral, a função garante que o modo de arredondamento da unidade de ponto flutuante (FPU) esteja em direção a zero (truncado), definindo os bits 10 e 11 da palavra de controle. Isso garante que a conversão de um tipo de ponto flutuante para um tipo integral ocorra conforme descrito pela norma ANSI C (a porção fracionada do número é descartada). Ao usar **/QIfist,** essa garantia não se aplica mais. O modo de arredondamento será um dos quatro documentados nos manuais de referência da Intel:

- Rodada em direção ao mais próximo (mesmo número se equidistante)

- Rodada em direção ao infinito negativo

- Rodada em direção ao infinito positivo

- Rodada em direção a zero

Você pode usar a função [_control87, _controlfp, \__control87_2](../../c-runtime-library/reference/control87-controlfp-control87-2.md) C Run-Time para modificar o comportamento de arredondamento da FPU. O modo de arredondamento padrão da FPU é "Round em direção ao mais próximo". O uso **de /QIfist** pode melhorar o desempenho da sua aplicação, mas não sem risco. Você deve testar minuciosamente as partes do seu código que são sensíveis aos modos de arredondamento antes de confiar no código construído com **/QIfist** em ambientes de produção.

[/arch (x86)](arch-x86.md) e **/QIfist** não podem ser usados na mesma compilação.

> [!NOTE]
> **/QIfist** não está em vigor por padrão porque os bits de arredondamento também afetam o ponto flutuante para arredondamento de ponto flutuante (que ocorre após cada cálculo), então quando você define as bandeiras para arredondamento estilo C (em direção a zero), seus cálculos de ponto flutuante podem ser diferentes. **/QIfist** não deve ser usado se o seu código depender do comportamento esperado de truncar a porção fracionada do número de ponto flutuante. Se você não tiver certeza, não use **/QIfist**.

A opção **/QIfist** é preterida a partir do Visual Studio 2005. O compilador fez melhorias significativas na velocidade de conversão de flutuação para int. Para obter uma lista de opções de compilador preteridos, consulte **Opções de compilador depreciadas e removidas** em [opções de compilador listadas por categoria](compiler-options-listed-by-category.md).

### <a name="to-set-this-compiler-option-in-the-visual-studio-development-environment"></a>Para definir esta opção do compilador no ambiente de desenvolvimento do Visual Studio

1. Abra a caixa de diálogo **Páginas de Propriedades** do projeto. Para obter detalhes, confira [Definir as propriedades de build e do compilador do C++ no Visual Studio](../working-with-project-properties.md).

1. Clique na pasta **C/C++.**

1. Clique na página de propriedade Linha de **Comando.**

1. Digite a opção compilador na **caixa Opções adicionais.**

### <a name="to-set-this-compiler-option-programmatically"></a>Para definir essa opção do compilador via programação

- Consulte <xref:Microsoft.VisualStudio.VCProjectEngine.VCCLCompilerTool.AdditionalOptions%2A>.

## <a name="see-also"></a>Confira também

[Opções /Q (operações de baixo nível)](q-options-low-level-operations.md)<br/>
[Opções do compilador MSVC](compiler-options.md)<br/>
[Sintaxe da linha de comando do compilador MSVC](compiler-command-line-syntax.md)
