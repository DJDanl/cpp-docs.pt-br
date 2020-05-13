---
title: /Os, /Ot (favorecer código pequeno, favorecer código rápido)
ms.date: 11/04/2016
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
ms.openlocfilehash: 0eda9461b3ef730e0e0a832aa94a688e03c7e1bb
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81336183"
---
# <a name="os-ot-favor-small-code-favor-fast-code"></a>/Os, /Ot (favorecer código pequeno, favorecer código rápido)

Minimiza ou maximiza o tamanho de EXEs e DLLs.

## <a name="syntax"></a>Sintaxe

```
/Os
/Ot
```

## <a name="remarks"></a>Comentários

**/Os** (Favor Small Code) minimiza o tamanho de EXEs e DLLs instruindo o compilador a favorecer o tamanho sobre a velocidade. O compilador pode reduzir muitos construtos C e C++ a seqüências funcionalmente semelhantes de código da máquina. Ocasionalmente, essas diferenças oferecem compensações de tamanho versus velocidade. As opções **/Os** e **/Ot** permitem especificar uma preferência para uma sobre a outra:

**/Ot** (Favor Fast Code) maximiza a velocidade de EXEs e DLLs instruindo o compilador a favorecer a velocidade sobre o tamanho. (Este é o padrão.) O compilador pode reduzir muitos construtos C e C++ a seqüências funcionalmente semelhantes de código da máquina. Ocasionalmente, essas diferenças oferecem compensações de tamanho versus velocidade. A **opção /Ot** está implícita na opção Maximizar velocidade[(/O2).](o1-o2-minimize-size-maximize-speed.md) A **opção /O2** combina várias opções para produzir código muito rápido.

Se você usar **/Os** ou **/Ot**, então você também deve especificar [/Og](og-global-optimizations.md) para otimizar o código.

> [!NOTE]
> As informações coletadas a partir de testes de criação de perfil serão anuladas por otimizações que de outra forma estariam em vigor se você especificar **/Ob**, **/Os**, ou **/Ot**. Para obter mais informações, [otimizações guiadas por perfil](../profile-guided-optimizations.md).

**Específico para x86**

O código de exemplo a seguir demonstra a diferença entre as opções Favor Small Code **( /Os)** e a opção Favor Fast Code (**/Ot):**

> [!NOTE]
> O seguinte descreve o comportamento esperado ao usar **/Os** ou **/Ot**. No entanto, o comportamento do compilador da versão para a versão pode resultar em diferentes otimizações para o código abaixo.

```
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

Como mostrado no fragmento do código da máquina abaixo, quando DIFFERENT.c é compilado para tamanho (**/Os),** o compilador implementa a expressão multiplicada na instrução de retorno explicitamente como uma multiplicação para produzir uma seqüência curta, mas mais lenta de código:

```
mov    eax, DWORD PTR _x$[ebp]
imul   eax, 71                  ; 00000047H
```

Alternativamente, quando DIFFERENT.c é compilado para velocidade (**/Ot),** o compilador implementa a expressão `LEA` multiplicada na instrução de retorno como uma série de turnos e instruções para produzir uma seqüência rápida, mas mais longa de código:

```
mov    eax, DWORD PTR _x$[ebp]
mov    ecx, eax
shl    eax, 3
lea    eax, DWORD PTR [eax+eax*8]
sub    eax, ecx
```

**END x86 Específico**

### <a name="to-set-this-compiler-option-in-the-visual-studio-development-environment"></a>Para definir esta opção do compilador no ambiente de desenvolvimento do Visual Studio

1. Abra a caixa de diálogo **Páginas de Propriedades** do projeto. Para obter detalhes, confira [Definir as propriedades de build e do compilador do C++ no Visual Studio](../working-with-project-properties.md).

1. Clique na pasta **C/C++.**

1. Clique na página **de propriedade Otimização.**

1. Modifique a propriedade Tamanho ou Velocidade do **favor.**

### <a name="to-set-this-compiler-option-programmatically"></a>Para definir essa opção do compilador via programação

- Consulte <xref:Microsoft.VisualStudio.VCProjectEngine.VCCLCompilerTool.FavorSizeOrSpeed%2A>.

## <a name="see-also"></a>Confira também

[/O Opções (Otimizar código)](o-options-optimize-code.md)<br/>
[Opções do compilador MSVC](compiler-options.md)<br/>
[Sintaxe da linha de comando do compilador MSVC](compiler-command-line-syntax.md)
