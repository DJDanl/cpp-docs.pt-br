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
ms.openlocfilehash: 8724ae4d018948c0f6aa9456f229db96878d7bf2
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81328274"
---
# <a name="gy-enable-function-level-linking"></a>/Gy (habilitar vinculação do nível de função)

Permite que o compilador empacote funções individuais no formato de funções empacotadas (COMDATs).

## <a name="syntax"></a>Sintaxe

```
/Gy[-]
```

## <a name="remarks"></a>Comentários

O linker exige que as funções sejam embaladas separadamente como COMDATs para excluir ou ordenar funções individuais em um arquivo DLL ou .exe.

Você pode usar a opção linker [/OPT (Optimizações)](opt-optimizations.md) para excluir funções embaladas não referenciadas do arquivo .exe.

Você pode usar a opção linker [/ORDER (Put Functions in Order)](order-put-functions-in-order.md) para incluir funções empacotadas em uma ordem especificada no arquivo .exe.

As funções inline são sempre embaladas se elas forem instanciadas como chamadas (o que ocorre, por exemplo, se o inline estiver desligado ou você tomar um endereço de função). Além disso, as funções de membro C++ definidas na declaração de classe são automaticamente embaladas; outras funções não são, e a seleção dessa opção é necessária para compilá-las como funções empacotadas.

> [!NOTE]
> A opção [/ZI,](z7-zi-zi-debug-information-format.md) usada para Editar e Continuar, define automaticamente a opção **/Gy.**

### <a name="to-set-this-compiler-option-in-the-visual-studio-development-environment"></a>Para definir esta opção do compilador no ambiente de desenvolvimento do Visual Studio

1. Abra a caixa de diálogo **Páginas de Propriedades** do projeto. Para obter detalhes, confira [Definir as propriedades de build e do compilador do C++ no Visual Studio](../working-with-project-properties.md).

1. Clique na pasta **C/C++.**

1. Clique na página **de propriedade Geração de Código.**

1. Modificar a **propriedade Ativar vinculação em nível de função.**

### <a name="to-set-this-compiler-option-programmatically"></a>Para definir essa opção do compilador via programação

- Consulte <xref:Microsoft.VisualStudio.VCProjectEngine.VCCLCompilerTool.EnableFunctionLevelLinking%2A>.

## <a name="see-also"></a>Confira também

[Opções do compilador MSVC](compiler-options.md)<br/>
[Sintaxe da linha de comando do compilador MSVC](compiler-command-line-syntax.md)
