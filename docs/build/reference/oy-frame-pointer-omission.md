---
title: /Oy (omissão do ponteiro de quadro)
ms.date: 11/19/2018
f1_keywords:
- VC.Project.VCCLCompilerTool.OmitFramePointers
- /oy
helpviewer_keywords:
- omit frame pointer
- Oy compiler option [C++]
- stack frame pointer compiler option [C++]
- -Oy compiler option [C++]
- frame pointer omission compiler option [C++]
- suppress frame pointer creation
- /Oy compiler option [C++]
ms.assetid: c451da86-5297-4c5a-92bc-561d41379853
ms.openlocfilehash: 7884f52cc22766c6b1a864fc01abcd73f92cfabb
ms.sourcegitcommit: 8105b7003b89b73b4359644ff4281e1595352dda
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/14/2019
ms.locfileid: "57817953"
---
# <a name="oy-frame-pointer-omission"></a>/Oy (omissão do ponteiro de quadro)

Inibe a criação de ponteiros de quadros na pilha de chamadas.

## <a name="syntax"></a>Sintaxe

> /Oy[-]

## <a name="remarks"></a>Comentários

Essa opção acelera chamadas de função, porque nenhum ponteiro de quadro precisa ser configurado e removido. Ele também libera mais um registro para uso geral.

**/Oy** permite a omissão do ponteiro de quadro e **/Oy-** desabilita a omissão. No x64 compiladores **/Oy** e **/Oy-** não estão disponíveis.

Se o seu código exigir endereçamento com base em quadros, você pode especificar o **/Oy-** opção após o **/Ox** opção ou use [otimizar](../../preprocessor/optimize.md) com o "**y**"e **logoff** argumentos para obter a máxima otimização com endereçamento baseado em quadro. O compilador detecta a maioria das situações em que o endereçamento com base em quadro é necessário (por exemplo, com o `_alloca` e `setjmp` funções e com a manipulação de exceção estruturada).

O [/Ox (habilitar mais otimizações de velocidade)](ox-full-optimization.md) e [/O1, / O2 (minimizar tamanho, maximizar velocidade)](o1-o2-minimize-size-maximize-speed.md) opções implicam **/Oy**. Especificando **/Oy-** depois que o **/Ox**, **/O1**, ou **/O2** opção desabilita **/Oy**, seja ele explícita ou implícita.

O **/Oy** faz de opção de compilador usando o depurador mais difícil porque o compilador suprime as informações de ponteiro de quadro. Se você especificar uma opção de compilador debug ([/Z7, /Zi, /ZI](z7-zi-zi-debug-information-format.md)), é recomendável que você especifique a **/Oy-** opção após outras opções de compilador de otimização.

### <a name="to-set-this-compiler-option-in-the-visual-studio-development-environment"></a>Para definir esta opção do compilador no ambiente de desenvolvimento do Visual Studio

1. Abra a caixa de diálogo **Páginas de Propriedades** do projeto. Para obter detalhes, consulte [propriedades de compilador e de build definida C++ no Visual Studio](../working-with-project-properties.md).

1. Selecione o **propriedades de configuração** > **C/C++** > **otimização** página de propriedades.

1. Modificar a **omite ponteiros de quadros** propriedade. Essa propriedade adiciona ou remove apenas o **/Oy** opção. Se você deseja adicionar o **/Oy-** opção, selecione a **linha de comando** propriedade página e modificar **opções adicionais**.

### <a name="to-set-this-compiler-option-programmatically"></a>Para definir essa opção do compilador via programação

- Consulte <xref:Microsoft.VisualStudio.VCProjectEngine.VCCLCompilerTool.OmitFramePointers%2A>.

## <a name="see-also"></a>Consulte também

[Opções /O (otimizar código)](o-options-optimize-code.md)<br/>
[Opções do compilador MSVC](compiler-options.md)<br/>
[Sintaxe de linha de comando do compilador MSVC](compiler-command-line-syntax.md)<br/>
