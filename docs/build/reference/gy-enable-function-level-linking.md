---
title: -Gy (habilitar vinculação do nível de função) | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-tools
ms.topic: reference
f1_keywords:
- VC.Project.VCCLCompilerTool.EnableFunctionLevelLinking
- /gy
- VC.Project.VCCLWCECompilerTool.EnableFunctionLevelLinking
dev_langs:
- C++
helpviewer_keywords:
- enable function-level linking compiler option [C++]
- COMDAT function
- Gy compiler option [C++]
- -Gy compiler option [C++]
- /Gy compiler option [C++]
- packaged functions
ms.assetid: 0d3cf14c-ed7d-4ad3-b4b6-104e56f61046
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 09faa1a1d2b6743b7fce31af32ba4fe1572b592e
ms.sourcegitcommit: 92f2fff4ce77387b57a4546de1bd4bd464fb51b6
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/17/2018
ms.locfileid: "45704997"
---
# <a name="gy-enable-function-level-linking"></a>/Gy (habilitar vinculação do nível de função)

Permite que o compilador empacote funções individuais no formato de funções empacotadas (COMDATs).

## <a name="syntax"></a>Sintaxe

```
/Gy[-]
```

## <a name="remarks"></a>Comentários

O vinculador requer que funções sejam empacotados separadamente como COMDATs para excluir ou ordenar funções individuais em um arquivo DLL ou .exe.

Você pode usar a opção de vinculador [/OPT (otimizações)](../../build/reference/opt-optimizations.md) para excluir as funções empacotadas do arquivo .exe.

Você pode usar a opção de vinculador [/ORDER (colocar funções na ordem)](../../build/reference/order-put-functions-in-order.md) para incluir funções empacotadas em uma ordem especificada no arquivo .exe.

Funções embutidas são empacotadas sempre se eles são instanciados como chamadas (que ocorre, por exemplo, se o inlining é desativado ou tomar o endereço de uma função). Além disso, funções de membro de C++ definidas na declaração de classe são empacotadas automaticamente; outras funções não são e selecionar essa opção é necessária para compilá-los como funções empacotadas.

> [!NOTE]
>  O [/ZI](../../build/reference/z7-zi-zi-debug-information-format.md) opcional usada para editar e continuar, define automaticamente a **/Gy** opção.

### <a name="to-set-this-compiler-option-in-the-visual-studio-development-environment"></a>Para definir esta opção do compilador no ambiente de desenvolvimento do Visual Studio

1. Abra a caixa de diálogo **Páginas de Propriedades** do projeto. Para obter detalhes, confira [Trabalhando com propriedades do projeto](../../ide/working-with-project-properties.md).

1. Clique o **C/C++** pasta.

1. Clique o **geração de código** página de propriedades.

1. Modificar a **habilitar vinculação do nível de função** propriedade.

### <a name="to-set-this-compiler-option-programmatically"></a>Para definir essa opção do compilador via programação

- Consulte <xref:Microsoft.VisualStudio.VCProjectEngine.VCCLCompilerTool.EnableFunctionLevelLinking%2A>.

## <a name="see-also"></a>Consulte também

[Opções do Compilador](../../build/reference/compiler-options.md)<br/>
[Definindo opções do compilador](../../build/reference/setting-compiler-options.md)