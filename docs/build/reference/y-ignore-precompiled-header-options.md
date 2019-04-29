---
title: /Y- (ignorar opções de cabeçalho pré-compilado)
ms.date: 11/04/2016
f1_keywords:
- /y-
helpviewer_keywords:
- Y- compiler option [C++]
- -Y- compiler option [C++]
- /Y- compiler option [C++]
ms.assetid: cfaecb36-58db-46b8-b04d-cca6072b1b7a
ms.openlocfilehash: c56c25d587d84e599718d2e1a74d469def3501f7
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62316178"
---
# <a name="y--ignore-precompiled-header-options"></a>/Y- (ignorar opções de cabeçalho pré-compilado)

Faz com que todos os outros `/Y` compilador opções a serem ignorados (e em si não pode ser substituído).

## <a name="syntax"></a>Sintaxe

```
/Y-
```

## <a name="remarks"></a>Comentários

Para obter mais informações sobre cabeçalhos pré-compilados, consulte:

- [/Y (cabeçalhos pré-compilados)](y-precompiled-headers.md)

- [Arquivos de cabeçalho pré-compilado](../creating-precompiled-header-files.md)

### <a name="to-set-this-compiler-option-in-the-visual-studio-development-environment"></a>Para definir esta opção do compilador no ambiente de desenvolvimento do Visual Studio

1. Abra a caixa de diálogo **Páginas de Propriedades** do projeto. Para obter detalhes, consulte [propriedades de compilador e de build definida C++ no Visual Studio](../working-with-project-properties.md).

1. Clique o **C/C++** pasta.

1. Clique o **linha de comando** página de propriedades.

1. Digite a opção de compilador na **opções adicionais** caixa.

### <a name="to-set-this-compiler-option-programmatically"></a>Para definir essa opção do compilador via programação

- Consulte <xref:Microsoft.VisualStudio.VCProjectEngine.VCCLCompilerTool.AdditionalOptions%2A>.

## <a name="see-also"></a>Consulte também

[Opções do compilador MSVC](compiler-options.md)<br/>
[Sintaxe da linha de comando do compilador MSVC](compiler-command-line-syntax.md)
