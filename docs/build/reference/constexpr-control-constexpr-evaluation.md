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
ms.openlocfilehash: 7b3ae1cd732fe1ec234e2734ea4c6fa86db9d5af
ms.sourcegitcommit: 1f009ab0f2cc4a177f2d1353d5a38f164612bdb1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/27/2020
ms.locfileid: "87223857"
---
# <a name="constexpr-control-constexpr-evaluation"></a>/constexpr (avaliação de constexpr de controle)

Use as opções do compilador **/constexpr** para controlar parâmetros para **`constexpr`** avaliação em tempo de compilação.

## <a name="syntax"></a>Sintaxe

> **/constexpr: profundidade**<em>N</em>\
> **/constexpr: backtrace**<em>N</em>\
> **/constexpr: etapas**<em>N</em>

## <a name="arguments"></a>Argumentos

a **profundidade**<em>N</em> limita a profundidade da **`constexpr`** invocação de função recursiva para *N* níveis. O padrão é 512.

o **backtrace**<em>N</em> mostra até *N* **`constexpr`** avaliações no diagnóstico. O padrão é 10.

**etapas**<em>N</em> terminar **`constexpr`** avaliação após *N* etapas. O padrão é 100.000.

## <a name="remarks"></a>Comentários

As opções do compilador **/constexpr** controlam a avaliação de expressões em tempo de compilação **`constexpr`** . As etapas de avaliação, os níveis de recursão e a profundidade de backtrace são controlados para evitar que o compilador gaste muito tempo na **`constexpr`** avaliação. Para obter mais informações sobre o **`constexpr`** elemento Language, consulte [Constexpr (C++)](../../cpp/constexpr-cpp.md).

As opções **/constexpr** estão disponíveis a partir do Visual Studio 2015.

### <a name="to-set-this-compiler-option-in-the-visual-studio-development-environment"></a>Para definir esta opção do compilador no ambiente de desenvolvimento do Visual Studio

1. Abra a caixa de diálogo **páginas de propriedades** do projeto.

2. Em **Propriedades de configuração**, expanda a pasta **C/C++** e escolha a página de propriedades de **linha de comando** .

3. Insira as opções do compilador **/constexpr** na caixa **Opções adicionais** . Escolha **OK** ou **aplicar** para salvar suas alterações.

### <a name="to-set-this-compiler-option-programmatically"></a>Para definir essa opção do compilador via programação

- Consulte <xref:Microsoft.VisualStudio.VCProjectEngine.VCCLCompilerTool.AdditionalOptions%2A>.

## <a name="see-also"></a>Confira também

[Opções do compilador MSVC](compiler-options.md)<br/>
[Sintaxe de linha de comando do compilador MSVC](compiler-command-line-syntax.md)
