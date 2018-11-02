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
ms.openlocfilehash: 8de7de7a4164916b9662e3a78fe00dd0a40cecc9
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50542890"
---
# <a name="y--ignore-precompiled-header-options"></a>/Y- (ignorar opções de cabeçalho pré-compilado)

Faz com que todos os outros `/Y` compilador opções a serem ignorados (e em si não pode ser substituído).

## <a name="syntax"></a>Sintaxe

```
/Y-
```

## <a name="remarks"></a>Comentários

Para obter mais informações sobre cabeçalhos pré-compilados, consulte:

- [/Y (cabeçalhos pré-compilados)](../../build/reference/y-precompiled-headers.md)

- [Criando arquivos de cabeçalho pré-compilado](../../build/reference/creating-precompiled-header-files.md)

### <a name="to-set-this-compiler-option-in-the-visual-studio-development-environment"></a>Para definir esta opção do compilador no ambiente de desenvolvimento do Visual Studio

1. Abra a caixa de diálogo **Páginas de Propriedades** do projeto. Para obter detalhes, confira [Trabalhando com propriedades do projeto](../../ide/working-with-project-properties.md).

1. Clique o **C/C++** pasta.

1. Clique o **linha de comando** página de propriedades.

1. Digite a opção de compilador na **opções adicionais** caixa.

### <a name="to-set-this-compiler-option-programmatically"></a>Para definir essa opção do compilador via programação

- Consulte <xref:Microsoft.VisualStudio.VCProjectEngine.VCCLCompilerTool.AdditionalOptions%2A>.

## <a name="see-also"></a>Consulte também

[Opções do Compilador](../../build/reference/compiler-options.md)<br/>
[Definindo opções do compilador](../../build/reference/setting-compiler-options.md)