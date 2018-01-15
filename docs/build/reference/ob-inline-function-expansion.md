---
title: "-Ob (expansão de função embutida) | Microsoft Docs"
ms.custom: 
ms.date: 09/25/2017
ms.reviewer: 
ms.suite: 
ms.technology: cpp-tools
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords:
- VC.Project.VCCLWCECompilerTool.InlineFunctionExpansion
- VC.Project.VCCLCompilerTool.InlineFunctionExpansion
- /ob
dev_langs: C++
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
caps.latest.revision: "13"
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload: cplusplus
ms.openlocfilehash: b83d470eaf6a30698d8c2836620a0688daa35cc1
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="ob-inline-function-expansion"></a>/Ob (expansão de função embutida)

Expressão embutida de controles de funções.

## <a name="syntax"></a>Sintaxe

> /OB {0 | 1 | 2}

## <a name="arguments"></a>Arguments

**0**  
Desabilita expansões embutida. Por padrão, expansão ocorre ao julgamento do compilador em todas as funções, conhecida como *automática inlining*.

**1**  
Permite expansão apenas de funções assinaladas como [embutido](../../cpp/inline-functions-cpp.md), `__inline`, ou `__forceinline`, ou em uma função de membro de C++ definidas em uma declaração de classe.

**2**  
O valor padrão. Permite que a expansão das funções assinaladas como `inline`, `__inline`, ou `__forceinline`e qualquer outra função que o compilador escolha.

**/Ob2** está em vigor quando [/O1, /O2 (minimizar tamanho, maximizar velocidade)](../../build/reference/o1-o2-minimize-size-maximize-speed.md) ou [/Ox (habilitar mais velocidade otimizações)](../../build/reference/ox-full-optimization.md) é usado.

Essa opção requer que você habilite otimizações usando **/O1**, **/O2**, **/Ox**, ou **/Og**.  

## <a name="remarks"></a>Comentários

O compilador trata as opções de expansão embutida e as palavras-chave como sugestões. Não há nenhuma garantia de qualquer função linha expandida. Você pode desabilitar expansões embutida, mas não é possível forçar o compilador embutido uma determinada função, mesmo ao usar o `__forceinline` palavra-chave.

Você pode usar o `#pragma` [auto_inline](../../preprocessor/auto-inline.md) diretiva para excluir funções da consideração como candidatos para expansão embutida. Consulte também o `#pragma` [intrínseco](../../preprocessor/intrinsic.md) diretiva.

> [!NOTE]
> Informações coletadas de execuções de teste de criação de perfil substituem otimizações que estariam em vigor se você especificar **/Ob**, **/Os**, ou **/Ot**. Para obter mais informações, consulte [Profile-Guided otimizações](../../build/reference/profile-guided-optimizations.md).

### <a name="to-set-this-compiler-option-in-the-visual-studio-development-environment"></a>Para definir esta opção do compilador no ambiente de desenvolvimento do Visual Studio

1. Abra a caixa de diálogo **Páginas de Propriedades** do projeto. Para obter detalhes, consulte [trabalhar com propriedades do projeto](../../ide/working-with-project-properties.md).

1. Expanda **propriedades de configuração**, **C/C++**e selecione **otimização**.

1. Modificar o **expansão de função embutida** propriedade.

### <a name="to-set-this-compiler-option-programmatically"></a>Para definir essa opção do compilador via programação

- Consulte <xref:Microsoft.VisualStudio.VCProjectEngine.VCCLCompilerTool.InlineFunctionExpansion%2A>.

## <a name="see-also"></a>Consulte também

[/O opções (otimizar código)](../../build/reference/o-options-optimize-code.md)  
[Opções do Compilador](../../build/reference/compiler-options.md)  
[Definindo opções do compilador](../../build/reference/setting-compiler-options.md)