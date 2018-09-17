---
title: -Yd (colocar informações de depuração no arquivo de objeto) | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-tools
ms.topic: reference
f1_keywords:
- /yd
dev_langs:
- C++
helpviewer_keywords:
- /Yd compiler option [C++]
- -Yd compiler option [C++]
- debugging [C++], debug information files
- Yd compiler option [C++]
ms.assetid: c5a699fe-65ce-461e-964c-7f5eb2a8320a
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 38d678e6a16f9c87aace611e33cbc792d2a3b59e
ms.sourcegitcommit: 92f2fff4ce77387b57a4546de1bd4bd464fb51b6
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/17/2018
ms.locfileid: "45713551"
---
# <a name="yd-place-debug-information-in-object-file"></a>/Yd (colocar informações de depuração no arquivo de projeto)

À prova completa de informações em todos os arquivos de objeto de depuração criado de um arquivo de cabeçalho pré-compilado (. pch) quando usado com o [/Yc](../../build/reference/yc-create-precompiled-header-file.md) e [/Z7](../../build/reference/z7-zi-zi-debug-information-format.md) opções. Preterido.

## <a name="syntax"></a>Sintaxe

```
/Yd
```

## <a name="remarks"></a>Comentários

**/Yd** foi preterido; Visual C++ agora dá suporte a vários objetos de gravar em um arquivo. PDB única, use **/Zi** em vez disso. Para obter uma lista de opções do compilador preterido, consulte **preteridos e removidos opções do compilador** na [opções de compilador listadas por categoria](../../build/reference/compiler-options-listed-by-category.md).

A menos que você precisa distribuir informações de depuração que contém uma biblioteca, use o [/Zi](../../build/reference/z7-zi-zi-debug-information-format.md) opção em vez de **/Z7** e **/Yd**.

Armazenar informações de depuração completas em todos os arquivos. obj só é necessário para distribuir as bibliotecas que contêm informações de depuração. Ele reduz a compilação e exige espaço em disco considerável. Quando **/Yc** e **/Z7** são usados sem **/Yd**, o compilador armazena informações de depuração comuns no primeiro arquivo. obj criado a partir do arquivo. pch. O compilador não inserir essas informações em arquivos. obj criados posteriormente do arquivo. pch; ele insere referências cruzadas para as informações. Não importa quantos arquivos. obj usam o arquivo. pch, apenas um arquivo. obj contém as informações de depuração comuns.

Embora essa resultados de comportamento padrão com mais rapidez tempos de build e reduz as exigências de espaço em disco, não é desejável se uma pequena alteração requer a recriação do arquivo. obj que contém as informações de depuração comuns. Nesse caso, o compilador deve recompilar todos os arquivos. obj que contém referências cruzadas no arquivo. obj original. Além disso, se um arquivo. pch comum é usado por projetos diferentes, a dependência de referências cruzadas para um arquivo. obj único é difícil.

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

## <a name="examples"></a>Exemplos

Suponha que você tenha dois arquivos base, F.cpp e G.cpp, cada uma contendo esses **#include** instruções:

```
#include "windows.h"
#include "etc.h"
```

O comando a seguir cria o cabeçalho pré-compilado ETC.pch e o arquivo de objeto F.obj arquivo:

```
CL /YcETC.H /Z7 F.CPP
```

O arquivo de objeto F.obj inclui o tipo e informações de símbolo para o Windows. h e ETC.h (e quaisquer outros arquivos de cabeçalho incluem). Agora você pode usar o cabeçalho pré-compilado ETC.pch para compilar o arquivo de origem G.cpp:

```
CL /YuETC.H /Z7 G.CPP
```

O arquivo de objeto G.obj não inclui as informações de depuração para o cabeçalho pré-compilado, mas simplesmente faz referência a essas informações no arquivo F.obj. Observe que você deve vincular com o arquivo F.obj.

Se o cabeçalho pré-compilado não foi compilado com **/Z7**, você ainda pode usá-lo em compilações posteriores usando **/Z7**. No entanto, as informações de depuração são colocadas no arquivo de objeto atual e símbolos locais para funções e tipos definidos no cabeçalho pré-compilado não estão disponíveis para o depurador.

## <a name="see-also"></a>Consulte também

[Opções do Compilador](../../build/reference/compiler-options.md)<br/>
[Definindo opções do compilador](../../build/reference/setting-compiler-options.md)