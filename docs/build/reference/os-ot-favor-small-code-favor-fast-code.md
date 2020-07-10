---
title: /Os, /Ot (favorecer código pequeno, favorecer código rápido)
description: As opções do compilador MSVC/os e/OT especificam se é para favorecer o tamanho ou a velocidade ao otimizar o código.
ms.date: 07/08/2020
f1_keywords:
- VC.Project.VCCLWCECompilerTool.FavorSizeOrSpeed
- /os
- VC.Project.VCCLCompilerTool.FavorSizeOrSpeed
helpviewer_keywords:
- favor fast code compiler option [C++]
- /Os compiler option [C++]
- Ot compiler option [C++]
- /Ot compiler option [C++]
- small machine code
- -Ot compiler option [C++]
- fast code
- favor small code compiler option [C++]
- Os compiler option [C++]
- -Os compiler option [C++]
ms.assetid: 9a340806-fa15-4308-892c-355d83cac0f2
ms.openlocfilehash: 384019ddf7b80b8dd4e00197d73d1e4ac536634c
ms.sourcegitcommit: 80c8a512b361bd84e38958beb1a1bf6db7434021
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/09/2020
ms.locfileid: "86180819"
---
# <a name="os-ot-favor-small-code-favor-fast-code"></a>`/Os`, `/Ot` (Favorecer código pequeno, favorecer código rápido)

Minimiza ou maximiza o tamanho de EXEs e DLLs.

## <a name="syntax"></a>Sintaxe

> **`/Os`**\
> **`/Ot`**

## <a name="remarks"></a>Comentários

**`/Os`**(Favorecer código pequeno) minimiza o tamanho de EXEs e DLLs instruindo o compilador a favorecer o tamanho em velocidade. O compilador pode reduzir muitas construções C e C++ para funcionar sequências semelhantes de código de máquina. Ocasionalmente, essas diferenças oferecem compensações de tamanho versus velocidade. As **`/Os`** **`/Ot`** Opções e permitem que você especifique uma preferência para uma na outra:

**`/Ot`**(Favorecer código rápido) maximiza a velocidade de EXEs e DLLs instruindo o compilador a favorecer a velocidade em relação ao tamanho. **`/Ot`** é o padrão quando as otimizações são habilitadas. O compilador pode reduzir muitas construções C e C++ para funcionar sequências semelhantes de código de máquina. Ocasionalmente, essas diferenças oferecem compensações de tamanho versus velocidade. A **`/Ot`** opção é implícita pela [`/O2`](o1-o2-minimize-size-maximize-speed.md) opção (maximizar velocidade). A **`/O2`** opção combina várias opções para produzir código mais rápido.

> [!NOTE]
> As informações coletadas de execuções de teste de criação de perfil substituem as otimizações que, de outra forma, seriam efetivadas se você especificar **`/Ob`** , **`/Os`** ou **`/Ot`** . Para obter mais informações, confira [Otimizações guiadas por perfil](../profile-guided-optimizations.md).

### <a name="x86-specific-example"></a>exemplo específico de x86

O código de exemplo a seguir demonstra a diferença entre a **`/Os`** opção (favorecer código pequeno) e a **`/Ot`** opção (favorecer código rápido):

> [!NOTE]
> Este exemplo descreve o comportamento esperado ao usar **`/Os`** ou **`/Ot`** . No entanto, o comportamento do compilador da versão para a versão pode resultar em otimizações diferentes para o código abaixo.

```c
/* differ.c
  This program implements a multiplication operator
  Compile with /Os to implement multiply explicitly as multiply.
  Compile with /Ot to implement as a series of shift and LEA instructions.
*/
int differ(int x)
{
    return x * 71;
}
```

Conforme mostrado no fragmento do código da máquina abaixo, quando *`differ.c`* é compilado para Size ( **`/Os`** ), o compilador implementa a expressão de multiplicação na instrução de retorno explicitamente como uma multiplicação para produzir uma sequência de código curta, mas mais lenta:

```asm
mov    eax, DWORD PTR _x$[ebp]
imul   eax, 71                  ; 00000047H
```

Como alternativa, quando *`differ.c`* é compilado para Speed ( **`/Ot`** ), o compilador implementa a expressão de multiplicação na instrução return como uma série de Shift e `LEA` instruções para produzir uma sequência de código rápida, mas mais longa:

```asm
mov    eax, DWORD PTR _x$[ebp]
mov    ecx, eax
shl    eax, 3
lea    eax, DWORD PTR [eax+eax*8]
sub    eax, ecx
```

### <a name="to-set-this-compiler-option-in-the-visual-studio-development-environment"></a>Para definir esta opção do compilador no ambiente de desenvolvimento do Visual Studio

1. Abra a caixa de diálogo **Páginas de Propriedades** do projeto. Para obter detalhes, confira [Definir as propriedades de build e do compilador do C++ no Visual Studio](../working-with-project-properties.md).

1. Selecione a página de propriedades de otimização de **configuração**de  >  **C/C++**  >  **Optimization** .

1. Modifique a propriedade **favorecer tamanho ou velocidade** .

### <a name="to-set-this-compiler-option-programmatically"></a>Para definir essa opção do compilador via programação

- Consulte <xref:Microsoft.VisualStudio.VCProjectEngine.VCCLCompilerTool.FavorSizeOrSpeed%2A>.

## <a name="see-also"></a>Veja também

[/O opções (otimizar código)](o-options-optimize-code.md)<br/>
[Opções do compilador MSVC](compiler-options.md)<br/>
[Sintaxe da linha de comando do compilador MSVC](compiler-command-line-syntax.md)
