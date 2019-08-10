---
title: /Ob (expansão de função embutida)
ms.date: 08/08/2019
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
ms.openlocfilehash: 7eb3db1e359349eaf5125a6c8a46a3ac7d847f2f
ms.sourcegitcommit: 46d24d6e70c03e05484923d9efc6ed5150e96a64
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/09/2019
ms.locfileid: "68915476"
---
# <a name="ob-inline-function-expansion"></a>/Ob (expansão de função embutida)

Controla a expansão embutida de funções. Por padrão, ao otimizar, a expansão ocorre no critério do compilador em todas as funções, muitas vezes chamadas deautolinhado.

## <a name="syntax"></a>Sintaxe

::: moniker range=">=vs-2019"

> **/OB** {**0**|12|**3**}|

::: moniker-end

::: moniker range="<=vs-2017"

> **/OB** {**0**|12|}

::: moniker-end

## <a name="arguments"></a>Arguments

**0**\
O valor padrão em [/OD](od-disable-debug.md). Desabilita expansões embutidas.

**1**\
Permite a expansão somente de funções marcadas como [inline](../../cpp/inline-functions-cpp.md), [__inline](../../cpp/inline-functions-cpp.md)ou [__forceinline](../../cpp/inline-functions-cpp.md), ou C++ em uma função de membro definida em uma declaração de classe.

**2**\
O valor padrão em [/O1](o1-o2-minimize-size-maximize-speed.md) e [/O2](o1-o2-minimize-size-maximize-speed.md). Permite que o compilador expanda qualquer função não explicitamente marcada para não-alinhamento.

::: moniker range=">=vs-2019"

**3**\
Esta opção especifica o inalinhamento mais agressivo do que **/Ob2**, mas tem as mesmas restrições. A opção **/Ob3** está disponível a partir do Visual Studio 2019.

::: moniker-end

## <a name="remarks"></a>Comentários

O compilador trata as opções de expansão embutida e as palavras-chave como sugestões. Não há nenhuma garantia de que qualquer função será expandida embutida. Você pode desabilitar expansões embutidas, mas não pode forçar o compilador a embutir uma função específica, mesmo ao usar `__forceinline` a palavra-chave.

Para excluir funções da consideração como candidatos à expansão embutida, você pode usar [_ declspec (noinline)](../../cpp/noinline.md)ou uma região marcada por [#pragma auto_inline (desativado)](../../preprocessor/auto-inline.md) e [#pragma diretivas de auto_inline (on)](../../preprocessor/auto-inline.md) . Para obter informações sobre outra maneira de fornecer dicas de inalinhamento para o compilador, consulte a diretiva [intrínseca #pragma](../../preprocessor/intrinsic.md) .

> [!NOTE]
> As informações coletadas de execuções de testes de criação de perfil substituem as otimizações que, de outra forma, seriam efetivadas porque você especificou **/OB**, **/os**ou **/OT**. Para obter mais informações, confira [Otimizações guiadas por perfil](../profile-guided-optimizations.md).

### <a name="to-set-this-compiler-option-in-the-visual-studio-development-environment"></a>Para definir esta opção do compilador no ambiente de desenvolvimento do Visual Studio

1. Abra a caixa de diálogo **Páginas de Propriedades** do projeto. Para obter detalhes, confira [Definir as propriedades de build e do compilador do C++ no Visual Studio](../working-with-project-properties.md).

1. Selecione a página de propriedades **configuração** >  > **C/C++** **otimização** .

1. Modifique a propriedade de **expansão de função embutida** .

::: moniker range=">=vs-2019"

A opção **/Ob3** não está disponível na propriedade de **expansão de função embutida** . Para definir **/Ob3**:

1. Abra a caixa de diálogo **Páginas de Propriedades** do projeto. Para obter detalhes, confira [Definir as propriedades de build e do compilador do C++ no Visual Studio](../working-with-project-properties.md).

1. Selecione a página de **Propriedades** > configuração **CC++ /** > linha de comando.

1. Insira **/Ob3** em **Opções adicionais**.

::: moniker-end

### <a name="to-set-this-compiler-option-programmatically"></a>Para definir essa opção do compilador via programação

- Consulte <xref:Microsoft.VisualStudio.VCProjectEngine.VCCLCompilerTool.InlineFunctionExpansion%2A>.

## <a name="see-also"></a>Consulte também

[Opções/o (otimizar código)](o-options-optimize-code.md)\
[Opções do compilador MSVC](compiler-options.md)\
[Sintaxe da linha de comando do compilador MSVC](compiler-command-line-syntax.md)
