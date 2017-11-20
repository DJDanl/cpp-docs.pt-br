---
title: "-Og (otimizações globais) | Microsoft Docs"
ms.custom: 
ms.date: 09/22/2017
ms.reviewer: 
ms.suite: 
ms.technology: cpp-tools
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords:
- VC.Project.VCCLCompilerTool.GlobalOptimizations
- /og
dev_langs: C++
helpviewer_keywords:
- -Og compiler option [C++]
- global optimizations compiler option [C++]
- automatic register allocation
- /Og compiler option [C++]
- loop structures, optimizing
- common subexpression elimination
- Og compiler option [C++]
ms.assetid: d10630cc-b9cf-4e97-bde3-8d7ee79e9435
caps.latest.revision: "17"
author: corob-msft
ms.author: corob
manager: ghogen
ms.openlocfilehash: a48d01437ad72bcc239de0465b62732efb805dd1
ms.sourcegitcommit: ebec1d449f2bd98aa851667c2bfeb7e27ce657b2
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/24/2017
---
# <a name="og-global-optimizations"></a>/Og (otimizações globais)

Preterido. Fornece otimizações de locais e globais, alocação de registro automático e otimização de loop. Recomendamos que você use um [/O1 (minimizar tamanho)](../../build/reference/o1-o2-minimize-size-maximize-speed.md) ou [/O2 (maximizar velocidade)](../../build/reference/o1-o2-minimize-size-maximize-speed.md) em vez disso.

## <a name="syntax"></a>Sintaxe

> /Og

## <a name="remarks"></a>Comentários

**/Og** foi preterido. Geralmente, essas otimizações agora estão habilitadas por padrão. Para obter mais informações sobre otimizações, consulte [/O1, /O2 (minimizar tamanho, maximizar velocidade)](../../build/reference/o1-o2-minimize-size-maximize-speed.md) ou [/Ox (habilitar mais velocidade otimizações)](../../build/reference/ox-full-optimization.md).

As otimizações a seguir estão disponíveis em **/Og**:

- Eliminação de subexpressão comum locais e globais

     Nessa otimização, o valor de uma subexpressão comum é calculado uma vez. No exemplo a seguir, se os valores de `b` e `c` não alterar entre as três expressões, o compilador pode atribuir o cálculo de `b + c` em uma variável temporária e substitua a variável `b + c`:

    ```C
    a = b + c;
    d = b + c;
    e = b + c;
    ```

     Para a otimização de subexpressão comum local, o compilador examina curtas seções de código para subexpressões comuns. Para a otimização de subexpressão comum global, o compilador pesquisa funções inteiras para subexpressões comuns.

- Alocação de registro automático

     Essa otimização permite que o compilador subexpressões e variáveis de armazenamento usado com frequência nos registros; o `register` palavra-chave é ignorado.

- Otimização de loop

     Essa otimização remove subexpressões invariáveis do corpo de um loop. Um loop ideal contém somente as expressões cujos valores são alterados por meio de cada execução do loop. No exemplo a seguir, a expressão `x + y` não é alterado no corpo do loop:

    ```C
    i = -100;
    while( i < 0 ) {
        i += x + y;
    }
    ```

     Depois da otimização, `x + y` é calculada uma vez, em vez de toda vez que o loop é executado:

    ```C
    i = -100;
    t = x + y;
    while( i < 0 ) {
        i += t;
    }
    ```

     Otimização de loop é muito mais eficaz quando o compilador não pode assumir nenhum alias, definido com [Restrict](../../cpp/extension-restrict.md), [noalias](../../cpp/noalias.md), ou [restringir](../../cpp/restrict.md).

    > [!NOTE]
    > Você pode habilitar ou desabilitar a otimização global em uma base por função de função usando o `optimize` pragma junto com o `g` opção.

 Para obter informações relacionadas, consulte [/Oi (gerar funções intrínsecas)](../../build/reference/oi-generate-intrinsic-functions.md) e [/Ox (habilitar mais velocidade otimizações)](../../build/reference/ox-full-optimization.md).

### <a name="to-set-this-compiler-option-in-the-visual-studio-development-environment"></a>Para definir esta opção do compilador no ambiente de desenvolvimento do Visual Studio

1. Abra a caixa de diálogo **Páginas de Propriedades** do projeto. Para obter detalhes, consulte [trabalhar com propriedades do projeto](../../ide/working-with-project-properties.md).

1. Clique o **C/C++** pasta.

1. Clique o **linha de comando** página de propriedades.

1. Insira a opção de compilador no **opções adicionais** caixa.

### <a name="to-set-this-compiler-option-programmatically"></a>Para definir essa opção do compilador via programação

- Consulte <xref:Microsoft.VisualStudio.VCProjectEngine.VCCLCompilerTool.AdditionalOptions%2A>.

## <a name="see-also"></a>Consulte também

[/O opções (otimizar código)](../../build/reference/o-options-optimize-code.md)

[Opções do Compilador](../../build/reference/compiler-options.md)

[Definindo opções do compilador](../../build/reference/setting-compiler-options.md)