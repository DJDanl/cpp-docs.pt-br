---
title: /Gy (habilitar vinculação do nível de função)
ms.date: 11/04/2016
f1_keywords:
- VC.Project.VCCLCompilerTool.EnableFunctionLevelLinking
- /gy
- VC.Project.VCCLWCECompilerTool.EnableFunctionLevelLinking
helpviewer_keywords:
- enable function-level linking compiler option [C++]
- COMDAT function
- Gy compiler option [C++]
- -Gy compiler option [C++]
- /Gy compiler option [C++]
- packaged functions
ms.assetid: 0d3cf14c-ed7d-4ad3-b4b6-104e56f61046
ms.openlocfilehash: 9643b8b4b4b26b3f7a8a59ed0085601b1a53094d
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62270718"
---
# <a name="gy-enable-function-level-linking"></a>/Gy (habilitar vinculação do nível de função)

Permite que o compilador empacote funções individuais no formato de funções empacotadas (COMDATs).

## <a name="syntax"></a>Sintaxe

```
/Gy[-]
```

## <a name="remarks"></a>Comentários

O vinculador requer que funções sejam empacotados separadamente como COMDATs para excluir ou ordenar funções individuais em um arquivo DLL ou .exe.

Você pode usar a opção de vinculador [/OPT (otimizações)](opt-optimizations.md) para excluir as funções empacotadas do arquivo .exe.

Você pode usar a opção de vinculador [/ORDER (colocar funções na ordem)](order-put-functions-in-order.md) para incluir funções empacotadas em uma ordem especificada no arquivo .exe.

Funções embutidas são empacotadas sempre se eles são instanciados como chamadas (que ocorre, por exemplo, se o inlining é desativado ou tomar o endereço de uma função). Além disso, funções de membro de C++ definidas na declaração de classe são empacotadas automaticamente; outras funções não são e selecionar essa opção é necessária para compilá-los como funções empacotadas.

> [!NOTE]
>  O [/ZI](z7-zi-zi-debug-information-format.md) opcional usada para editar e continuar, define automaticamente a **/Gy** opção.

### <a name="to-set-this-compiler-option-in-the-visual-studio-development-environment"></a>Para definir esta opção do compilador no ambiente de desenvolvimento do Visual Studio

1. Abra a caixa de diálogo **Páginas de Propriedades** do projeto. Para obter detalhes, consulte [propriedades de compilador e de build definida C++ no Visual Studio](../working-with-project-properties.md).

1. Clique o **C/C++** pasta.

1. Clique o **geração de código** página de propriedades.

1. Modificar a **habilitar vinculação do nível de função** propriedade.

### <a name="to-set-this-compiler-option-programmatically"></a>Para definir essa opção do compilador via programação

- Consulte <xref:Microsoft.VisualStudio.VCProjectEngine.VCCLCompilerTool.EnableFunctionLevelLinking%2A>.

## <a name="see-also"></a>Consulte também

[Opções do compilador MSVC](compiler-options.md)<br/>
[Sintaxe da linha de comando do compilador MSVC](compiler-command-line-syntax.md)
