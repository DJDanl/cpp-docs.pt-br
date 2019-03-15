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
ms.openlocfilehash: 7af88c91793688d23cf35177ae7a5250b04832a8
ms.sourcegitcommit: 8105b7003b89b73b4359644ff4281e1595352dda
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/14/2019
ms.locfileid: "57816588"
---
# <a name="qifist-suppress-ftol"></a>/QIfist (suprimir _ftol)

Preterido. Suprime a chamada da função auxiliar `_ftol` quando é necessária uma conversão de um tipo de ponto flutuante para um tipo integral.

## <a name="syntax"></a>Sintaxe

```
/QIfist
```

## <a name="remarks"></a>Comentários

> [!NOTE]
>  **/Qifist** só está disponível no compilador destinado a x86; essa opção do compilador não está disponível nos compiladores destinados x64 orARM.

Além de converter de um tipo de ponto flutuante para tipo integral, o `_ftol` função garante que o modo de arredondamento da unidade de ponto flutuante (FPU) está em direção a zero (truncado), definindo bits 10 e 11 da palavra de controle. Isso garante que a conversão de um tipo de ponto flutuante para um tipo integral ocorre conforme descrito pelo padrão ANSI C (a parte fracionária do número é descartada). Ao usar **/QIfist**, essa garantia não se aplica. O modo de arredondamento será um dos quatro conforme documentado em manuais de referência da Intel:

- Arredondar para número mais próximo (mesmo se equidistante)

- Arredondar para o infinito negativo

- Arredondar para o infinito positivo

- Arredondar para zero

Você pode usar o [_control87, controlfp, \__control87_2](../../c-runtime-library/reference/control87-controlfp-control87-2.md) função de tempo de execução C para modificar o comportamento de arredondamento de FPU. O padrão de arredondamento do modo do FPU é "Round em direção a mais próximo." Usando o **/QIfist** pode melhorar o desempenho do seu aplicativo, mas não sem riscos. Você deve testar completamente as partes do seu código que são sensíveis a modos de arredondamento antes de depender do código compilado com **/QIfist** em ambientes de produção.

[/arch (x86)](arch-x86.md) e **/QIfist** não pode ser usado no mesmo compiland.

> [!NOTE]
>  **/Qifist** é não em vigor por padrão porque o arredondamento bits também afetam flutuante de ponto flutuante ponto arredondamento (que ocorre após cada cálculo), portanto, quando você define os sinalizadores para o arredondamento de estilo C (em direção a zero), seu ponto flutuante cálculos podem ser diferentes. **/Qifist** não deve ser usado se seu código depende do comportamento esperado de truncar a parte fracionária do número de ponto flutuante. Se você não tiver certeza, não use **/QIfist**.

O **/QIfist** opção foi preterida a partir do Visual Studio 2005. O compilador fez aprimoramentos significativos na float para int velocidade de conversão. Para obter uma lista de opções do compilador preterido, consulte **preteridos e removidos opções do compilador** na [opções de compilador listadas por categoria](compiler-options-listed-by-category.md).

### <a name="to-set-this-compiler-option-in-the-visual-studio-development-environment"></a>Para definir esta opção do compilador no ambiente de desenvolvimento do Visual Studio

1. Abra a caixa de diálogo **Páginas de Propriedades** do projeto. Para obter detalhes, consulte [propriedades de compilador e de build definida C++ no Visual Studio](../working-with-project-properties.md).

1. Clique o **C/C++** pasta.

1. Clique o **linha de comando** página de propriedades.

1. Digite a opção de compilador na **opções adicionais** caixa.

### <a name="to-set-this-compiler-option-programmatically"></a>Para definir essa opção do compilador via programação

- Consulte <xref:Microsoft.VisualStudio.VCProjectEngine.VCCLCompilerTool.AdditionalOptions%2A>.

## <a name="see-also"></a>Consulte também

[Opções /Q (operações de nível baixo)](q-options-low-level-operations.md)<br/>
[Opções do compilador MSVC](compiler-options.md)<br/>
[Sintaxe de linha de comando do compilador MSVC](compiler-command-line-syntax.md)
