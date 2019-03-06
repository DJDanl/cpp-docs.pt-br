---
title: /OX (habilitar a maioria das otimizações de velocidade)
ms.date: 10/18/2018
f1_keywords:
- VC.Project.VCCLCompilerTool.ToolOptimization
- /Ox
- /Oxs
helpviewer_keywords:
- Ox compiler option [C++]
- fast code [C++]
- /Ox compiler option [C++]
- -Ox compiler option [C++]
ms.assetid: 3ad7c30b-c615-428c-b1d0-2e024f81c760
ms.openlocfilehash: 9f93d67a24f254dff1604c11635c9fa2da7e4557
ms.sourcegitcommit: bff17488ac5538b8eaac57156a4d6f06b37d6b7f
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/05/2019
ms.locfileid: "57414532"
---
# <a name="ox-enable-most-speed-optimizations"></a>/OX (habilitar a maioria das otimizações de velocidade)

O **/Ox** uma combinação de otimizações que favorecer velocidade habilita a opção de compilador. Em algumas versões do IDE do Visual Studio e a mensagem de Ajuda do compilador, isso é chamado *otimização completa*, mas o **/Ox** habilita a opção de compilador apenas um subconjunto das opções de otimização de velocidade, habilitada por **/O2**.

## <a name="syntax"></a>Sintaxe

> **/Ox**

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

Você pode cancelar a tendência em direção a velocidade do **/Ox** opção de compilador se você especificar **/Oxs**, que combina os **/Ox** opção do compilador com [/Os (favorecer pequenas Código)](../../build/reference/os-ot-favor-small-code-favor-fast-code.md). As opções combinadas favorecerem tamanho menor de código.  O **/Oxs** opção é exatamente o mesmo que especificar **/Ox** **/Os** quando as opções são exibidas nessa ordem.

Para aplicar todas as otimizações de nível de arquivo disponíveis para builds de versão, é recomendável que você especifique [/O2 (maximizar velocidade)](../../build/reference/o1-o2-minimize-size-maximize-speed.md) em vez de **/Ox**, e [/O1 (minimizar tamanho)](../../build/reference/o1-o2-minimize-size-maximize-speed.md) em vez disso dos **/Oxs**. Para otimização ainda mais na versão compilações, considere também o [/GL (otimização de programa inteiro)](../../build/reference/gl-whole-program-optimization.md) opção de compilador e [/LTCG (geração de código Link-time)](../../build/reference/ltcg-link-time-code-generation.md) a opção de vinculador.

### <a name="to-set-this-compiler-option-in-the-visual-studio-development-environment"></a>Para definir esta opção do compilador no ambiente de desenvolvimento do Visual Studio

1. Abra a caixa de diálogo **Páginas de Propriedades** do projeto. Para obter detalhes, confira [Trabalhando com propriedades do projeto](../../ide/working-with-project-properties.md).

1. Sob **propriedades de configuração**, abra **C/C++** e, em seguida, escolha o **otimização** página de propriedades.

1. Modificar a **otimização** propriedade.

### <a name="to-set-this-compiler-option-programmatically"></a>Para definir essa opção do compilador via programação

- Consulte <xref:Microsoft.VisualStudio.VCProjectEngine.VCCLCompilerTool.Optimization%2A>.

## <a name="see-also"></a>Consulte também

[Opções /O (otimizar código)](../../build/reference/o-options-optimize-code.md)<br/>
[Opções do Compilador](../../build/reference/compiler-options.md)<br/>
[Definindo opções do compilador](../../build/reference/setting-compiler-options.md)
