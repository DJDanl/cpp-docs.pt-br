---
title: -Ox (habilitar a maioria das otimizações de velocidade) | Microsoft Docs
ms.custom: ''
ms.date: 09/25/2017
ms.technology:
- cpp-tools
ms.topic: reference
f1_keywords:
- VC.Project.VCCLCompilerTool.ToolOptimization
- /ox
dev_langs:
- C++
helpviewer_keywords:
- Ox compiler option [C++]
- fast code [C++]
- /Ox compiler option [C++]
- -Ox compiler option [C++]
ms.assetid: 3ad7c30b-c615-428c-b1d0-2e024f81c760
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: d93bfe44fab0400ce4c3c173473601745f85196c
ms.sourcegitcommit: 92f2fff4ce77387b57a4546de1bd4bd464fb51b6
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/17/2018
ms.locfileid: "45721520"
---
# <a name="ox-enable-most-speed-optimizations"></a>/OX (habilitar a maioria das otimizações de velocidade)

O **/Ox** uma combinação de otimizações que favorecer velocidade habilita a opção de compilador. Em algumas versões do IDE do Visual Studio e a mensagem de Ajuda do compilador, isso é chamado *otimização completa*, mas o **/Ox** habilita a opção de compilador apenas um subconjunto das opções de otimização de velocidade, habilitada por **/O2**.

## <a name="syntax"></a>Sintaxe

> /Ox

## <a name="remarks"></a>Comentários

O **/Ox** compilador opção habilita a **/O** que favorecer a velocidade de opções do compilador. O **/Ox** opção de compilador não inclui adicional [/GF (eliminar cadeias de caracteres duplicadas)](../../build/reference/gf-eliminate-duplicate-strings.md) e [/Gy (habilitar vinculação do nível de função)](../../build/reference/gy-enable-function-level-linking.md) opções habilitadas pelo [/O1 ou/O2 (minimizar tamanho, maximizar velocidade)](../../build/reference/o1-o2-minimize-size-maximize-speed.md). As opções adicionais aplicadas pelo **/O1** e **/O2** pode fazer com que os ponteiros para cadeias de caracteres ou funções para compartilhamento de um endereço de destino, que pode afetar a depuração e a conformidade com a linguagem estrita. O **/Ox** opção é uma maneira fácil de habilitar a maioria das otimizações sem incluir **/GF** e **/Gy**. Para obter mais informações, consulte as descrições do [/GF](../../build/reference/gf-eliminate-duplicate-strings.md) e [/Gy](../../build/reference/gy-enable-function-level-linking.md) opções.

O **/Ox** opção de compilador é o mesmo que usar as seguintes opções em combinação:

- [/OB (expansão de função embutida)](../../build/reference/ob-inline-function-expansion.md), em que o parâmetro de opção é 2 (**/Ob2**)

- [/Og (otimizações globais)](../../build/reference/og-global-optimizations.md)

- [/Oi (gerar funções intrínsecas)](../../build/reference/oi-generate-intrinsic-functions.md)

- [/OT (favorecer código rápido)](../../build/reference/os-ot-favor-small-code-favor-fast-code.md)

- [/Oy (omissão do ponteiro de quadro)](../../build/reference/oy-frame-pointer-omission.md)

**/OX** é mutuamente exclusivo de:

- [/ O1 (tamanho mínimo)](../../build/reference/o1-o2-minimize-size-maximize-speed.md)

- [/ O2 (maximizar velocidade)](../../build/reference/o1-o2-minimize-size-maximize-speed.md)

- [/Od (desabilitar [depuração])](../../build/reference/od-disable-debug.md)

Você pode cancelar a tendência em direção a velocidade do **/Ox** opção de compilador se você especificar **/Oxs**, que combina os **/Ox** opção do compilador com [/Os (favorecer pequenas Código)](../../build/reference/os-ot-favor-small-code-favor-fast-code.md). As opções combinadas favorecerem tamanho menor de código.

Para aplicar todas as otimizações de nível de arquivo disponíveis para builds de versão, é recomendável que você especifique [/O2 (maximizar velocidade)](../../build/reference/o1-o2-minimize-size-maximize-speed.md) em vez de **/Ox**, e [/O1 (minimizar tamanho)](../../build/reference/o1-o2-minimize-size-maximize-speed.md) em vez disso dos **/Oxs**. Para otimização ainda mais na versão compilações, considere também o [/GL (otimização de programa inteiro)](../../build/reference/gl-whole-program-optimization.md) opção de compilador e [/LTCG (geração de código Link-time)](../../build/reference/ltcg-link-time-code-generation.md) a opção de vinculador.

### <a name="to-set-this-compiler-option-in-the-visual-studio-development-environment"></a>Para definir esta opção do compilador no ambiente de desenvolvimento do Visual Studio

1. Abra a caixa de diálogo **Páginas de Propriedades** do projeto. Para obter detalhes, confira [Trabalhando com propriedades do projeto](../../ide/working-with-project-properties.md).

1. Sob **propriedades de configuração**, abra **C/C++** e, em seguida, escolha o **otimização** página de propriedades.

1. Modificar a **otimização** propriedade.

### <a name="to-set-this-compiler-option-programmatically"></a>Para definir essa opção do compilador via programação

- Consulte <xref:Microsoft.VisualStudio.VCProjectEngine.VCCLCompilerTool.Optimization%2A>.

## <a name="see-also"></a>Consulte também

[/O opções (otimizar código)](../../build/reference/o-options-optimize-code.md)
[opções do compilador](../../build/reference/compiler-options.md)<br/>
[Definindo opções do compilador](../../build/reference/setting-compiler-options.md)