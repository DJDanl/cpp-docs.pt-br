---
title: /Og (otimizações globais)
ms.date: 09/22/2017
f1_keywords:
- VC.Project.VCCLCompilerTool.GlobalOptimizations
- /og
helpviewer_keywords:
- -Og compiler option [C++]
- global optimizations compiler option [C++]
- automatic register allocation
- /Og compiler option [C++]
- loop structures, optimizing
- common subexpression elimination
- Og compiler option [C++]
ms.assetid: d10630cc-b9cf-4e97-bde3-8d7ee79e9435
ms.openlocfilehash: 5e45273b6b609f1bf78504a519c1fb98e2147f76
ms.sourcegitcommit: 8105b7003b89b73b4359644ff4281e1595352dda
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/14/2019
ms.locfileid: "57818525"
---
# <a name="og-global-optimizations"></a>/Og (otimizações globais)

Preterido. Fornece otimizações de locais e globais, alocação o registro automático e a otimização de loop. É recomendável que você use um [/O1 (minimizar tamanho)](o1-o2-minimize-size-maximize-speed.md) ou [/O2 (maximizar velocidade)](o1-o2-minimize-size-maximize-speed.md) em vez disso.

## <a name="syntax"></a>Sintaxe

> /Og

## <a name="remarks"></a>Comentários

**/Og** foi preterido. Geralmente, essas otimizações agora estão habilitadas por padrão. Para obter mais informações sobre as otimizações, consulte [/O1, / O2 (minimizar tamanho, maximizar velocidade)](o1-o2-minimize-size-maximize-speed.md) ou [/Ox (habilitar mais otimizações de velocidade)](ox-full-optimization.md).

As seguintes otimizações estão disponíveis sob **/Og**:

- Eliminação de subexpressão comum global e local

   Dessa otimização, o valor de uma subexpressão comum é calculado uma vez. No exemplo a seguir, se os valores de `b` e `c` não alterar entre as três expressões, o compilador pode atribuir o cálculo da `b + c` a uma variável temporária e substitua a variável para `b + c`:

    ```C
    a = b + c;
    d = b + c;
    e = b + c;
    ```

   Para a otimização de subexpressão comum local, o compilador examina curtas seções de código para subexpressões comuns. Para a otimização de subexpressão comum global, o compilador procura funções inteiras para subexpressões comuns.

- Alocação de registro automático

   Essa otimização permite que o compilador repositório usado frequentemente variáveis e subexpressões em registros; o `register` palavra-chave é ignorado.

- Otimização de loop

   Essa otimização remove subexpressões invariáveis do corpo de um loop. Um loop ideal contém somente as expressões cujos valores são alterados por meio de cada execução do loop. No exemplo a seguir, a expressão `x + y` não é alterado no corpo do loop:

    ```C
    i = -100;
    while( i < 0 ) {
        i += x + y;
    }
    ```

   Depois da otimização, `x + y` é calculada uma vez em vez de toda vez que o loop é executado:

    ```C
    i = -100;
    t = x + y;
    while( i < 0 ) {
        i += t;
    }
    ```

   Otimização de loop é muito mais eficaz quando o compilador não pode presumir nenhuma criação de alias, você pode definir com [Restrict](../../cpp/extension-restrict.md), [noalias](../../cpp/noalias.md), ou [restringir](../../cpp/restrict.md).

   > [!NOTE]
   > Você pode habilitar ou desabilitar a otimização global em uma base de função por função usando o `optimize` pragma junto com o `g` opção.

Para obter informações relacionadas, consulte [/Oi (gerar funções intrínsecas)](oi-generate-intrinsic-functions.md) e [/Ox (habilitar mais otimizações de velocidade)](ox-full-optimization.md).

### <a name="to-set-this-compiler-option-in-the-visual-studio-development-environment"></a>Para definir esta opção do compilador no ambiente de desenvolvimento do Visual Studio

1. Abra a caixa de diálogo **Páginas de Propriedades** do projeto. Para obter detalhes, consulte [propriedades de compilador e de build definida C++ no Visual Studio](../working-with-project-properties.md).

1. Clique o **C/C++** pasta.

1. Clique o **linha de comando** página de propriedades.

1. Insira a opção de compilador na **opções adicionais** caixa.

### <a name="to-set-this-compiler-option-programmatically"></a>Para definir essa opção do compilador via programação

- Consulte <xref:Microsoft.VisualStudio.VCProjectEngine.VCCLCompilerTool.AdditionalOptions%2A>.

## <a name="see-also"></a>Consulte também

[Sintaxe de linha de comando do compilador MSVC](compiler-command-line-syntax.md)
