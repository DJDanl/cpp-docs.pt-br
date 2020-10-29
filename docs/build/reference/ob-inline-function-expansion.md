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
ms.openlocfilehash: 56a755de69b4f2ce6b659959eca5b25a6d75bfdc
ms.sourcegitcommit: 9c2b3df9b837879cd17932ae9f61cdd142078260
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/29/2020
ms.locfileid: "92921185"
---
# <a name="ob-inline-function-expansion"></a>/Ob (expansão de função embutida)

Controla a expansão embutida de funções. Por padrão, ao otimizar, a expansão ocorre no critério do compilador em todas as funções, muitas vezes chamadas de *autolinhado* .

## <a name="syntax"></a>Syntax

::: moniker range=">=msvc-160"

> **/OB** { **0** | **1** | **2** | **3** }

::: moniker-end

::: moniker range="<=msvc-150"

> **/OB** { **0** | **1** | **2** }

::: moniker-end

## <a name="arguments"></a>Argumentos

**0**\
O valor padrão em [/OD](od-disable-debug.md). Desabilita expansões embutidas.

**1**\
Permite a expansão somente de funções marcadas como [inline](../../cpp/inline-functions-cpp.md), [__inline](../../cpp/inline-functions-cpp.md)ou [__forceinline](../../cpp/inline-functions-cpp.md)ou em uma função membro do C++ definida em uma declaração de classe.

**2**\
O valor padrão em [/O1](o1-o2-minimize-size-maximize-speed.md) e [/O2](o1-o2-minimize-size-maximize-speed.md). Permite que o compilador expanda qualquer função não explicitamente marcada para não-alinhamento.

::: moniker range=">=msvc-160"

**Beta**\
Esta opção especifica o inalinhamento mais agressivo do que **/Ob2** , mas tem as mesmas restrições. A opção **/Ob3** está disponível a partir do Visual Studio 2019.

::: moniker-end

## <a name="remarks"></a>Comentários

O compilador trata as opções de expansão embutida e as palavras-chave como sugestões. Não há nenhuma garantia de que qualquer função será expandida embutida. Você pode desabilitar expansões embutidas, mas não pode forçar o compilador a embutir uma função específica, mesmo ao usar a **`__forceinline`** palavra-chave.

Para excluir funções da consideração como candidatos à expansão embutida, você pode usar [__declspec (noinline)](../../cpp/noinline.md)ou uma região marcada pelas diretivas [#pragma auto_inline (desativado)](../../preprocessor/auto-inline.md) e [#pragma auto_inline (on)](../../preprocessor/auto-inline.md) . Para obter informações sobre outra maneira de fornecer dicas de inalinhamento para o compilador, consulte a diretiva [intrínseca #pragma](../../preprocessor/intrinsic.md) .

> [!NOTE]
> As informações coletadas de execuções de testes de criação de perfil substituem as otimizações que, de outra forma, seriam efetivadas porque você especificou **/OB** , **/os** ou **/OT** . Para obter mais informações, confira [Otimizações guiadas por perfil](../profile-guided-optimizations.md).

### <a name="to-set-this-compiler-option-in-the-visual-studio-development-environment"></a>Para definir esta opção do compilador no ambiente de desenvolvimento do Visual Studio

1. Abra a caixa de diálogo **Páginas de Propriedades** do projeto. Para obter detalhes, confira [Definir as propriedades de build e do compilador do C++ no Visual Studio](../working-with-project-properties.md).

1. Selecione a página de propriedades de otimização de **configuração** de  >  **C/C++**  >  **Optimization** .

1. Modifique a propriedade de **expansão de função embutida** .

::: moniker range=">=msvc-160"

A opção **/Ob3** não está disponível na propriedade de **expansão de função embutida** . Para definir **/Ob3** :

1. Abra a caixa de diálogo **Páginas de Propriedades** do projeto. Para obter detalhes, confira [Definir as propriedades de build e do compilador do C++ no Visual Studio](../working-with-project-properties.md).

1. Selecione a página de propriedades **Propriedades de Configuração** > **C/C++** > **Linha de Comando** .

1. Insira **/Ob3** em **Opções adicionais** .

::: moniker-end

### <a name="to-set-this-compiler-option-programmatically"></a>Para definir essa opção do compilador via programação

- Consulte <xref:Microsoft.VisualStudio.VCProjectEngine.VCCLCompilerTool.InlineFunctionExpansion%2A>.

## <a name="see-also"></a>Veja também

[Opções/o (otimizar código)](o-options-optimize-code.md)\
[Opções do compilador MSVC](compiler-options.md)\
[Sintaxe de Command-Line do compilador MSVC](compiler-command-line-syntax.md)
