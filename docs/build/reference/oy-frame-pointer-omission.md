---
title: -Oy (omissão do ponteiro de quadro) | Microsoft Docs
ms.custom: ''
ms.date: 09/22/2017
ms.technology:
- cpp-tools
ms.topic: reference
f1_keywords:
- VC.Project.VCCLCompilerTool.OmitFramePointers
- /oy
dev_langs:
- C++
helpviewer_keywords:
- omit frame pointer
- Oy compiler option [C++]
- stack frame pointer compiler option [C++]
- -Oy compiler option [C++]
- frame pointer omission compiler option [C++]
- suppress frame pointer creation
- /Oy compiler option [C++]
ms.assetid: c451da86-5297-4c5a-92bc-561d41379853
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: b6feb682d364c4c40fd01e4aff33404c4506d9c1
ms.sourcegitcommit: be2a7679c2bd80968204dee03d13ca961eaa31ff
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/03/2018
ms.locfileid: "32377255"
---
# <a name="oy-frame-pointer-omission"></a>/Oy (omissão do ponteiro de quadro)

Inibe a criação de ponteiros de quadros na pilha de chamadas.

## <a name="syntax"></a>Sintaxe

> /Oy [-]

## <a name="remarks"></a>Comentários

Essa opção acelera chamadas de função, porque nenhum ponteiro de quadro precisa ser configurado e removido. Também libera mais um registro, (EBP no Intel 386 ou posterior) para armazenar variáveis e subexpressões usadas frequentemente.

**/Oy** permite a omissão do ponteiro de quadro e **/Oy-** desabilita omissão. **/Oy** está disponível apenas no x86 compiladores.

Se o seu código requer endereçamento com base em EBP, você pode especificar o **/Oy-** opção após o **/Ox** opção ou use [otimizar](../../preprocessor/optimize.md) com a "**y**" e **off** argumentos para obter o máximo de otimização com base em EBP tratamento. O compilador detecta a maioria das situações em que o tratamento baseado em EBP é necessário (por exemplo, com as funções `_alloca` e `setjmp` e o tratamento estruturado de exceções).

O [/Ox (habilitar mais velocidade otimizações)](../../build/reference/ox-full-optimization.md) e [/O1, /O2 (minimizar tamanho, maximizar velocidade)](../../build/reference/o1-o2-minimize-size-maximize-speed.md) opções implicam **/Oy**. Especificando **/Oy-** depois que o **/Ox**, **/O1**, ou **/O2** desabilita a opção **/Oy**, se ele for explícita ou implícita.

O **/Oy** torna de opção de compilador usando o depurador mais difícil porque o compilador suprime informações de ponteiro de quadro. Se você especificar uma opção de compilador debug ([/Z7, /Zi, /ZI](../../build/reference/z7-zi-zi-debug-information-format.md)), é recomendável que você especifique o **/Oy-** opção após outras opções de compilador de otimização.

### <a name="to-set-this-compiler-option-in-the-visual-studio-development-environment"></a>Para definir esta opção do compilador no ambiente de desenvolvimento do Visual Studio

1. Abra a caixa de diálogo **Páginas de Propriedades** do projeto. Para obter detalhes, consulte [trabalhar com propriedades do projeto](../../ide/working-with-project-properties.md).

1. Clique o **C/C++** pasta.

1. Clique o **otimização** página de propriedades.

1. Modificar o **omitir ponteiros da moldura** propriedade. Essa propriedade adiciona ou remove apenas o **/Oy** opção. Se você deseja adicionar o **/Oy-** opção, clique em **linha de comando** e modificar **opções adicionais**.

### <a name="to-set-this-compiler-option-programmatically"></a>Para definir essa opção do compilador via programação

- Consulte <xref:Microsoft.VisualStudio.VCProjectEngine.VCCLCompilerTool.OmitFramePointers%2A>.

## <a name="see-also"></a>Consulte também

[Opções /O (otimizar código)](../../build/reference/o-options-optimize-code.md)

[Opções do Compilador](../../build/reference/compiler-options.md)

[Definindo opções do compilador](../../build/reference/setting-compiler-options.md)