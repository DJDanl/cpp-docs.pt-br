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
ms.openlocfilehash: 5bbdda07eacdb003515a40a93a232c0f8626ca89
ms.sourcegitcommit: aed09c9c05e6b031c8a9f87a8d6bbdaf253485e8
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 06/27/2019
ms.locfileid: "67412236"
---
# <a name="os-ot-favor-small-code-favor-fast-code"></a>/Os, /Ot (favorecer código pequeno, favorecer código rápido)

Minimiza a ou maximiza o tamanho de EXEs e DLLs.

## <a name="syntax"></a>Sintaxe

```
/Os
/Ot
```

## <a name="remarks"></a>Comentários

**/Os** (favorecer código pequeno) minimiza o tamanho de EXEs e DLLs ao instruir o compilador a favorecer tamanho sobre velocidade. O compilador pode reduzir muitas construções de C e C++ em sequências funcionalmente semelhantes do código de máquina. Ocasionalmente, essas diferenças oferecem vantagens e desvantagens de tamanho e velocidade. O **/Os** e **/Ot** opções permitem que você especificar a preferência de um ou outro:

**/OT** (favorecer código rápido) maximiza a velocidade de EXEs e DLLs ao instruir o compilador a favorecer velocidade sobre tamanho. (Esse é o padrão). O compilador pode reduzir muitas construções de C e C++ em sequências funcionalmente semelhantes do código de máquina. Ocasionalmente, essas diferenças oferecem vantagens e desvantagens de tamanho e velocidade. O **/Ot** opção indicada pelo maximizar velocidade ([/O2](o1-o2-minimize-size-maximize-speed.md)) opção. O **/O2** opção combina várias opções para produzir um código muito rápido.

Se você usar **/Os** ou **/Ot**, em seguida, você também deve especificar [/Og](og-global-optimizations.md) para otimizar o código.

> [!NOTE]
>  Informações coletadas de execuções de teste de criação de perfil substituirá as otimizações que seriam em vigor se você especificar **/Ob**, **/Os**, ou **/Ot**. Para obter mais informações, [otimizações guiadas pelo perfil](../profile-guided-optimizations.md).

**x86 específico**

O exemplo de código a seguir demonstra a diferença entre a favorecer código pequeno ( **/Os**) opções e a favorecer código rápido ( **/Ot**) opção:

> [!NOTE]
>  A seguir descreve o comportamento esperado ao usar **/Os** ou **/Ot**. No entanto, o comportamento do compilador de versão para versão pode resultar em otimizações diferentes para o código a seguir.

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

Conforme mostrado no fragmento de código de máquina abaixo, quando DIFFER.c é compilado para o tamanho ( **/Os**), o compilador implementa a multiplicar a expressão na instrução return explicitamente como um multiply para produzir uma sequência mais lenta mas curta de código:

```
mov    eax, DWORD PTR _x$[ebp]
imul   eax, 71                  ; 00000047H
```

Como alternativa, quando DIFFER.c for compilado para velocidade ( **/Ot**), o compilador implementa a multiplicar a expressão na instrução de retorno como uma série de shift e `LEA` instruções para produzir uma sequência, mas mais rápida de código:

```
mov    eax, DWORD PTR _x$[ebp]
mov    ecx, eax
shl    eax, 3
lea    eax, DWORD PTR [eax+eax*8]
sub    eax, ecx
```

**END x86 específico**

### <a name="to-set-this-compiler-option-in-the-visual-studio-development-environment"></a>Para definir esta opção do compilador no ambiente de desenvolvimento do Visual Studio

1. Abra a caixa de diálogo **Páginas de Propriedades** do projeto. Para obter detalhes, confira [Definir as propriedades de build e do compilador do C++ no Visual Studio](../working-with-project-properties.md).

1. Clique o **C/C++** pasta.

1. Clique o **otimização** página de propriedades.

1. Modificar a **favoreça tamanho ou velocidade** propriedade.

### <a name="to-set-this-compiler-option-programmatically"></a>Para definir essa opção do compilador via programação

- Consulte <xref:Microsoft.VisualStudio.VCProjectEngine.VCCLCompilerTool.FavorSizeOrSpeed%2A>.

## <a name="see-also"></a>Consulte também

[Opções /O (otimizar código)](o-options-optimize-code.md)<br/>
[Opções do compilador MSVC](compiler-options.md)<br/>
[Sintaxe da linha de comando do compilador MSVC](compiler-command-line-syntax.md)
