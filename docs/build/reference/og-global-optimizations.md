---
title: /Og (otimizações globais)
description: Descreve a opção de compilador MSVC preterida/Og, usada anteriormente para habilitar otimizações globais.
ms.date: 07/08/2020
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
ms.openlocfilehash: 7dde5e97bd8690dc491916de8fb279e80a2c9ed4
ms.sourcegitcommit: 1f009ab0f2cc4a177f2d1353d5a38f164612bdb1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/27/2020
ms.locfileid: "87215199"
---
# <a name="og-global-optimizations"></a>`/Og`(Otimizações globais)

Preterido. Fornece otimizações locais e globais, alocação de registro automático e otimização de loop. É recomendável usar [ `/O1` (Minimizar tamanho)](o1-o2-minimize-size-maximize-speed.md) ou [ `/O2` (maximizar velocidade)](o1-o2-minimize-size-maximize-speed.md) em vez disso.

## <a name="syntax"></a>Sintaxe

> **`/Og`**

## <a name="remarks"></a>Comentários

**`/Og`** é preterido. Essas otimizações agora estão habilitadas por padrão quando quaisquer otimizações são habilitadas. Para obter mais informações sobre otimizações, consulte [ `/O1` `/O2` (Minimizar tamanho, maximizar velocidade)](o1-o2-minimize-size-maximize-speed.md)ou [ `/Ox` (habilitar a maioria das otimizações de velocidade)](ox-full-optimization.md).

As seguintes otimizações estão disponíveis em **`/Og`** :

- Eliminação de subexpressão comum local e global

   Nessa otimização, o valor de uma subexpressão comum é calculado uma vez. No exemplo a seguir, se os valores de `b` e `c` não forem alterados entre as três expressões, o compilador poderá atribuir o cálculo de `b + c` a uma variável temporária e usar essa variável para `b + c` :

    ```C
    a = b + c;
    d = b + c;
    e = b + c;
    ```

   Para a otimização de subexpressão comum local, o compilador examina seções curtas de código para subexpressões comuns. Para a otimização global de subexpressão comum, o compilador pesquisa funções inteiras para subexpressões comuns.

- Alocação de registro automática

   Essa otimização permite que o compilador armazene as variáveis e subexpressãos usadas com frequência nos registros; a **`register`** palavra-chave é ignorada.

- Otimização de loop

   Essa otimização remove subexpressões invariáveis do corpo de um loop. Um loop ideal contém apenas expressões cujos valores são alterados em cada execução do loop. No exemplo a seguir, a expressão `x + y` não é alterada no corpo do loop:

    ```C
    i = -100;
    while( i < 0 ) {
        i += x + y;
    }
    ```

   Após a otimização, `x + y` é calculada uma vez em vez de cada vez que o loop é executado:

    ```C
    i = -100;
    t = x + y;
    while( i < 0 ) {
        i += t;
    }
    ```

   A otimização de loop é muito mais eficaz quando o compilador pode não assumir nenhum alias, que você define com [`__restrict`](../../cpp/extension-restrict.md) , [`noalias`](../../cpp/noalias.md) ou [`restrict`](../../cpp/restrict.md) .

   > [!NOTE]
   > Você pode habilitar ou desabilitar a otimização global em uma base de função por função usando o `optimize` pragma junto com a `g` opção.

Para obter informações relacionadas, consulte [ `/Oi` (gerar funções intrínsecas)](oi-generate-intrinsic-functions.md) e [ `/Ox ` (habilitar a maioria das otimizações de velocidade)](ox-full-optimization.md).

### <a name="to-set-this-compiler-option-in-the-visual-studio-development-environment"></a>Para definir esta opção do compilador no ambiente de desenvolvimento do Visual Studio

1. Abra a caixa de diálogo **Páginas de Propriedades** do projeto. Para obter detalhes, confira [Definir as propriedades de build e do compilador do C++ no Visual Studio](../working-with-project-properties.md).

1. Selecione a **Configuration Properties**  >  página de propriedade de linha de comando**C/C++** Propriedades de configuração  >  **Command Line** .

1. Insira a opção do compilador na caixa **Opções adicionais** .

### <a name="to-set-this-compiler-option-programmatically"></a>Para definir essa opção do compilador via programação

- Consulte <xref:Microsoft.VisualStudio.VCProjectEngine.VCCLCompilerTool.AdditionalOptions%2A>.

## <a name="see-also"></a>Confira também

[Sintaxe de linha de comando do compilador MSVC](compiler-command-line-syntax.md)
