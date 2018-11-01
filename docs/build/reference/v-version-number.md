---
title: /V (número de versão)
ms.date: 11/04/2016
f1_keywords:
- /v
helpviewer_keywords:
- embedding version strings
- /V compiler option [C++]
- version numbers, specifying for .obj
- V compiler option [C++]
- -V compiler option [C++]
ms.assetid: 3e93fb7a-5dfd-49a6-bd49-3dca8052e0f3
ms.openlocfilehash: 23c6ebfc0d67c6d00ed0e26d2e23806234cbb6af
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50463824"
---
# <a name="v-version-number"></a>/V (número de versão)

Preterido. Insere uma cadeia de caracteres de texto no arquivo. obj.

## <a name="syntax"></a>Sintaxe

```
/Vstring
```

## <a name="arguments"></a>Arguments

*string*<br/>
Uma cadeia de caracteres especificando o número de versão ou o aviso de direitos autorais a ser inserido em um arquivo. obj.

## <a name="remarks"></a>Comentários

O rótulo de stringcan um arquivo. obj, com um número de versão ou um aviso de direitos autorais. Qualquer caractere de espaço ou tabulação deverão ser colocado entre aspas duplas ("), se elas são uma parte da cadeia de caracteres. Uma barra invertida (\\) devem preceder qualquer aspas duplas se elas são uma parte da cadeia de caracteres. Um espaço entre **/V** e `string` é opcional.

Você também pode usar [comentário (C/C++)](../../preprocessor/comment-c-cpp.md) com o argumento de tipo de comentário do compilador para colocar o nome e número de versão do compilador no arquivo. obj.

O **/V** opção foi preterida a partir do Visual Studio 2005; **/V** era, principalmente usadas para dar suporte à criação de drivers de dispositivo virtual (VxDs), e não há suporte para a criação de VxDs pelo conjunto de ferramentas do Visual C++. Para obter uma lista de opções do compilador preterido, consulte **preteridos e removidos opções do compilador** na [opções de compilador listadas por categoria](../../build/reference/compiler-options-listed-by-category.md).

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