---
title: /Qsafe_fp_loads | Microsoft Docs
ms.custom: 
ms.date: 01/24/2018
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-tools
ms.tgt_pltfrm: 
ms.topic: article
dev_langs:
- C++
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: e079e084c641318c9bec0820263487139b4d5076
ms.sourcegitcommit: 9a0a287d6940591523af959ebdac5affa36220da
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 01/25/2018
---
# <a name="qsafefploads"></a>/Qsafe_fp_loads

Requer as instruções de movimentação de inteiro para valores de ponto flutuante e desabilita determinadas otimizações de carregamento de ponto flutuante.

## <a name="syntax"></a>Sintaxe

> **/Qsafe_fp_loads**

## <a name="remarks"></a>Comentários

**/Qsafe_fp_loads** só está disponível nos compiladores de destino x86; ele não está disponível nos compiladores que x64 ou ARM de destino.

**/Qsafe_fp_loads** força o compilador para usar instruções de movimentação de inteiro em vez de instruções de ponto flutuante de movimentação para mover dados entre a memória e MMX registra. Essa opção também desabilita a otimização de carga de registro para valores de ponto flutuante que pode ser carregado em vários caminhos de controle quando o valor pode causar uma exceção ao carregar — por exemplo, um valor de NaN.

Essa opção é substituída por [/fp: exceto](../../build/reference/fp-specify-floating-point-behavior.md). **/Qsafe_fp_loads** Especifica um subconjunto do comportamento do compilador que é especificado pelo **/fp: exceto**.

**/Qsafe_fp_loads** é incompatível com [/clr](../../build/reference/clr-common-language-runtime-compilation.md) e [Fast](../../build/reference/fp-specify-floating-point-behavior.md). Para obter mais informações sobre as opções de compilador de ponto flutuante, consulte [/fp (Especificar comportamento de ponto flutuante)](../../build/reference/fp-specify-floating-point-behavior.md).

### <a name="to-set-this-compiler-option-in-the-visual-studio-development-environment"></a>Para definir esta opção do compilador no ambiente de desenvolvimento do Visual Studio

1. Abra a caixa de diálogo **Páginas de Propriedades** do projeto. Para obter detalhes, consulte [trabalhar com propriedades do projeto](../../ide/working-with-project-properties.md).

1. Selecione o **propriedades de configuração** > **C/C++** > **linha de comando** página de propriedades.

1. Insira a opção de compilador no **opções adicionais** caixa. Escolha **Okey** para aplicar a alteração.

### <a name="to-set-this-compiler-option-programmatically"></a>Para definir essa opção do compilador via programação

- Consulte <xref:Microsoft.VisualStudio.VCProjectEngine.VCCLCompilerTool.AdditionalOptions%2A>.

## <a name="see-also"></a>Consulte também

[Opções /Q (operações de nível baixo)](../../build/reference/q-options-low-level-operations.md)  
[Opções do Compilador](../../build/reference/compiler-options.md)  
[Definindo opções do compilador](../../build/reference/setting-compiler-options.md)  
