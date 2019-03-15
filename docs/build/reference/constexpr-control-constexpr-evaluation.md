---
title: /constexpr (avaliação de constexpr de controle)
ms.date: 08/15/2017
f1_keywords:
- /constexpr
- -constexpr
helpviewer_keywords:
- /constexpr control constexpr evaluation [C++]
- -constexpr control constexpr evaluation [C++]
- constexpr control constexpr evaluation [C++]
ms.assetid: 76d56784-f5ad-401d-841d-09d1059e8b8c
ms.openlocfilehash: 178acc548fb9c89dcfde104d2a12d85637440e28
ms.sourcegitcommit: 8105b7003b89b73b4359644ff4281e1595352dda
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/14/2019
ms.locfileid: "57810179"
---
# <a name="constexpr-control-constexpr-evaluation"></a>/constexpr (avaliação de constexpr de controle)

Use o **/constexpr** opções do compilador para parâmetros de controle para **constexpr** avaliação em tempo de compilação.

## <a name="syntax"></a>Sintaxe

> **/constexpr: Depth**<em>N</em>
>  **/constexpr: Backtrace**<em>N</em>
>  **/constexpr: Steps** <em>N</em>

## <a name="arguments"></a>Arguments

**profundidade**<em>N</em> limitar a profundidade de recursivo **constexpr** invocação de função *N* níveis. O padrão é 512.

**Backtrace**<em>N</em> mostrar até *N* **constexpr** avaliações no diagnóstico. O padrão é 10.

**etapas**<em>N</em> Terminate **constexpr** avaliação após *N* etapas. O padrão é 100.000.

## <a name="remarks"></a>Comentários

O **/constexpr** opções do compilador controlam o tempo de compilação de avaliação do **constexpr** expressões. Etapas de avaliação, os níveis de recursão e profundidade backtrace são controlados para impedir que o compilador gastando muito tempo na **constexpr** avaliação. Para obter mais informações sobre o **constexpr** elemento de linguagem, consulte [constexpr (C++)](../../cpp/constexpr-cpp.md).

O **/constexpr** opções estão disponíveis no Visual Studio 2015.

### <a name="to-set-this-compiler-option-in-the-visual-studio-development-environment"></a>Para definir esta opção do compilador no ambiente de desenvolvimento do Visual Studio

1. Abra seu projeto **páginas de propriedade** caixa de diálogo.

2. Sob **propriedades de configuração**, expanda o **C/C++** pasta e escolha o **linha de comando** página de propriedades.

3. Insira qualquer **/constexpr** opções de compilador na **opções adicionais** caixa. Escolher **Okey** ou **aplicar** para salvar suas alterações.

### <a name="to-set-this-compiler-option-programmatically"></a>Para definir essa opção do compilador via programação

- Consulte <xref:Microsoft.VisualStudio.VCProjectEngine.VCCLCompilerTool.AdditionalOptions%2A>.

## <a name="see-also"></a>Consulte também

[Opções do compilador MSVC](compiler-options.md)<br/>
[Sintaxe de linha de comando do compilador MSVC](compiler-command-line-syntax.md)
