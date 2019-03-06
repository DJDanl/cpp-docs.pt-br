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
ms.openlocfilehash: 6406b604ab74d29d8bc6c9bc0920fd0cf0bd055b
ms.sourcegitcommit: bff17488ac5538b8eaac57156a4d6f06b37d6b7f
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/05/2019
ms.locfileid: "57426141"
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

**/ Ob2** está em vigor quando [/O1, / O2 (minimizar tamanho, maximizar velocidade)](../../build/reference/o1-o2-minimize-size-maximize-speed.md) ou [/Ox (habilitar mais otimizações de velocidade)](../../build/reference/ox-full-optimization.md) é usado.

Essa opção exige que você habilite otimizações usando **/O1**, **/O2**, **/Ox**, ou **/Og**.

## <a name="remarks"></a>Comentários

O compilador trata as opções de expansão embutida e as palavras-chave como sugestões. Não há nenhuma garantia de que todas as funções serão embutidas expandidas. Você pode desabilitar expansões embutido, mas você não pode forçar o compilador a embutir uma função específica, mesmo ao usar o `__forceinline` palavra-chave.

Você pode usar o `#pragma` [auto_inline](../../preprocessor/auto-inline.md) diretiva para excluir funções da consideração como candidatos para a expansão embutida. Consulte também o `#pragma` [intrínseco](../../preprocessor/intrinsic.md) diretiva.

> [!NOTE]
> Informações coletadas de execuções de teste de criação de perfil substituem as otimizações que seriam em vigor se você especificar **/Ob**, **/Os**, ou **/Ot**. Para obter mais informações, consulte [otimizações guiadas pelo perfil](../../build/reference/profile-guided-optimizations.md).

### <a name="to-set-this-compiler-option-in-the-visual-studio-development-environment"></a>Para definir esta opção do compilador no ambiente de desenvolvimento do Visual Studio

1. Abra a caixa de diálogo **Páginas de Propriedades** do projeto. Para obter detalhes, confira [Trabalhando com propriedades do projeto](../../ide/working-with-project-properties.md).

1. Expandir **propriedades de configuração**, **C/C++** e selecione **otimização**.

1. Modificar a **expansão embutida de função** propriedade.

### <a name="to-set-this-compiler-option-programmatically"></a>Para definir essa opção do compilador via programação

- Consulte <xref:Microsoft.VisualStudio.VCProjectEngine.VCCLCompilerTool.InlineFunctionExpansion%2A>.

## <a name="see-also"></a>Consulte também

[Opções /O (otimizar código)](../../build/reference/o-options-optimize-code.md)<br/>
[Opções do Compilador](../../build/reference/compiler-options.md)<br/>
[Definindo opções do compilador](../../build/reference/setting-compiler-options.md)
