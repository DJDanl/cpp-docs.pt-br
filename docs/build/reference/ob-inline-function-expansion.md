---
title: /Ob (expansão de função embutida)
ms.date: 09/25/2017
f1_keywords:
- VC.Project.VCCLWCECompilerTool.InlineFunctionExpansion
- VC.Project.VCCLCompilerTool.InlineFunctionExpansion
- /ob
helpviewer_keywords:
- inline functions, function expansion compiler option [C++]
- -Ob1 compiler option [C++]
- -Ob0 compiler option [C++]
- /Ob0 compiler option [C++]
- /Ob1 compiler option [C++]
- any suitable compiler option [C++]
- Ob2 compiler option [C++]
- Ob1 compiler option [C++]
- /Ob2 compiler option [C++]
- Ob compiler option [C++]
- -Ob2 compiler option [C++]
- disable compiler option [C++]
- -Ob compiler option [C++]
- /Ob compiler option [C++]
- only __inline compiler option [C++]
- Ob0 compiler option [C++]
- inline expansion, compiler option
ms.assetid: f134e6df-e939-4980-a01d-47425dbc562a
ms.openlocfilehash: 6bf16e5725916e81e64d80c0a1f96bf502c8826c
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62320221"
---
# <a name="ob-inline-function-expansion"></a>/Ob (expansão de função embutida)

Controla a expansão embutida de funções.

## <a name="syntax"></a>Sintaxe

> /Ob{0|1|2}

## <a name="arguments"></a>Arguments

**0**<br/>
Desabilita expansões embutido. Por padrão, expansão ocorre, a critério do compilador em todas as funções, geralmente denominados *automática inlining*.

**1**<br/>
Permite expansão apenas das funções marcadas [embutido](../../cpp/inline-functions-cpp.md), `__inline`, ou `__forceinline`, ou em uma função de membro C++ definidos em uma declaração de classe.

**2**<br/>
O valor padrão. Permite a expansão das funções marcadas como `inline`, `__inline`, ou `__forceinline`e qualquer outra função que o compilador escolhe.

**/ Ob2** está em vigor quando [/O1, / O2 (minimizar tamanho, maximizar velocidade)](o1-o2-minimize-size-maximize-speed.md) ou [/Ox (habilitar mais otimizações de velocidade)](ox-full-optimization.md) é usado.

Essa opção exige que você habilite otimizações usando **/O1**, **/O2**, **/Ox**, ou **/Og**.

## <a name="remarks"></a>Comentários

O compilador trata as opções de expansão embutida e as palavras-chave como sugestões. Não há nenhuma garantia de que todas as funções serão embutidas expandidas. Você pode desabilitar expansões embutido, mas você não pode forçar o compilador a embutir uma função específica, mesmo ao usar o `__forceinline` palavra-chave.

Você pode usar o `#pragma` [auto_inline](../../preprocessor/auto-inline.md) diretiva para excluir funções da consideração como candidatos para a expansão embutida. Consulte também o `#pragma` [intrínseco](../../preprocessor/intrinsic.md) diretiva.

> [!NOTE]
> Informações coletadas de execuções de teste de criação de perfil substituem as otimizações que seriam em vigor se você especificar **/Ob**, **/Os**, ou **/Ot**. Para obter mais informações, consulte [otimizações guiadas pelo perfil](../profile-guided-optimizations.md).

### <a name="to-set-this-compiler-option-in-the-visual-studio-development-environment"></a>Para definir esta opção do compilador no ambiente de desenvolvimento do Visual Studio

1. Abra a caixa de diálogo **Páginas de Propriedades** do projeto. Para obter detalhes, consulte [propriedades de compilador e de build definida C++ no Visual Studio](../working-with-project-properties.md).

1. Expandir **propriedades de configuração**, **C/C++** e selecione **otimização**.

1. Modificar a **expansão embutida de função** propriedade.

### <a name="to-set-this-compiler-option-programmatically"></a>Para definir essa opção do compilador via programação

- Consulte <xref:Microsoft.VisualStudio.VCProjectEngine.VCCLCompilerTool.InlineFunctionExpansion%2A>.

## <a name="see-also"></a>Consulte também

[Opções /O (otimizar código)](o-options-optimize-code.md)<br/>
[Opções do compilador MSVC](compiler-options.md)<br/>
[Sintaxe da linha de comando do compilador MSVC](compiler-command-line-syntax.md)
