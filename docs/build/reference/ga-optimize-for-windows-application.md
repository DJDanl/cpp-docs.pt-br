---
title: /GA (otimizar para aplicativo do Windows)
ms.date: 11/04/2016
f1_keywords:
- VC.Project.VCCLCompilerTool.OptimizeForWindowsApplication
- /ga
helpviewer_keywords:
- /GA compiler option [C++]
- GA compiler option [C++]
- -GA compiler option [C++]
- Optimize for Windows compiler options
ms.assetid: be97323e-15a0-4836-862c-95980b51926a
ms.openlocfilehash: 85efa03a3f3d267580cbb0442839afb18ac6c313
ms.sourcegitcommit: fcb48824f9ca24b1f8bd37d647a4d592de1cc925
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/15/2019
ms.locfileid: "69492862"
---
# <a name="ga-optimize-for-windows-application"></a>/GA (otimizar para aplicativo do Windows)

Resulta em um código mais eficiente para um arquivo. exe para acessar variáveis de armazenamento local de thread (TLS).

## <a name="syntax"></a>Sintaxe

```
/GA
```

## <a name="remarks"></a>Comentários

**/GA** acelera o acesso a dados declarados com [_ declspec (thread)](../../cpp/declspec.md) em um programa baseado no Windows. Quando essa opção é definida, a macro [__tls_index](/windows/win32/ProcThread/thread-local-storage) é considerada como 0.

O uso de **/GA** para uma DLL pode resultar na geração de código inadequado.

### <a name="to-set-this-compiler-option-in-the-visual-studio-development-environment"></a>Para definir esta opção do compilador no ambiente de desenvolvimento do Visual Studio

1. Abra a caixa de diálogo **Páginas de Propriedades** do projeto. Para obter detalhes, confira [Definir as propriedades de build e do compilador do C++ no Visual Studio](../working-with-project-properties.md).

1. Clique na pasta **CC++ /** .

1. Clique na página de propriedades de **linha de comando** .

1. Digite a opção do compilador na caixa **Opções adicionais** .

### <a name="to-set-this-compiler-option-programmatically"></a>Para definir essa opção do compilador via programação

- Consulte <xref:Microsoft.VisualStudio.VCProjectEngine.VCCLCompilerTool.AdditionalOptions%2A>.

## <a name="see-also"></a>Consulte também

[Opções do compilador MSVC](compiler-options.md)<br/>
[Sintaxe da linha de comando do compilador MSVC](compiler-command-line-syntax.md)
