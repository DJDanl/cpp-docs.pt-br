---
title: /link (passar opções para o vinculador)
ms.date: 03/25/2019
f1_keywords:
- /link
helpviewer_keywords:
- /link compiler option [C++]
- pass options to linker
- link compiler option [C++]
- linker [C++], passing options to
- -link compiler option [C++]
- cl.exe compiler [C++], passing options to linker
ms.assetid: 16902a94-c094-4328-841f-3ac94ca04848
ms.openlocfilehash: ef81a6617df811660506c08434f3b65e29155794
ms.sourcegitcommit: 6e4dd21759caaed262a7255735cf8d6e8fb9f4d7
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/26/2019
ms.locfileid: "58476832"
---
# <a name="link-pass-options-to-linker"></a>/link (passar opções para o vinculador)

Passa uma ou mais opções de vinculador para o vinculador.

## <a name="syntax"></a>Sintaxe

> **/link** *linker-options*

## <a name="arguments"></a>Arguments

*linker-options*<br/>
As opções a serem passados para o vinculador ou opção de vinculador.

## <a name="remarks"></a>Comentários

O **/link** opção e suas opções de vinculador devem aparecer após quaisquer nomes de arquivo e opções de CL. Um espaço é necessário entre **/link** e `linkeroptions`. Para obter mais informações, consulte [referência de vinculador MSVC](linking.md).

## <a name="example"></a>Exemplo

Essa linha de comando de exemplo compila *hello.cpp* e o vincula ao arquivo de objeto existente *there.obj*. Em seguida, passa adicional **/VERSION** comando para o vinculador:

`cl /W4 /EHsc hello.cpp there.obj /link /VERSION:3.14`

### <a name="to-set-this-compiler-option-in-the-visual-studio-development-environment"></a>Para definir esta opção do compilador no ambiente de desenvolvimento do Visual Studio

Normalmente, o IDE envia comandos separados para compilar e vincular o seu código. Você pode definir as opções do vinculador em suas páginas de propriedade do projeto.

1. Abra a caixa de diálogo **Páginas de Propriedades** do projeto. Para obter detalhes, consulte [propriedades de compilador e de build definida C++ no Visual Studio](../working-with-project-properties.md).

1. Selecione o **propriedades de configuração** > **vinculador** pasta.

1. Modifique uma ou mais propriedades. Escolha **OK** para salvar suas alterações.

### <a name="to-set-this-compiler-option-programmatically"></a>Para definir essa opção do compilador via programação

- Essa opção do compilador não pode ser alterada programaticamente.

## <a name="see-also"></a>Consulte também

[Opções do compilador MSVC](compiler-options.md)<br/>
[Sintaxe da linha de comando do compilador MSVC](compiler-command-line-syntax.md)
