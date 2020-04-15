---
title: /J (o tipo char padrão não é assinado)
ms.date: 11/04/2016
f1_keywords:
- VC.Project.VCCLCompilerTool.DefaultCharIsUnsigned
- VC.Project.VCCLWCECompilerTool.DefaultCharIsUnsigned
- /j
helpviewer_keywords:
- defaults, char type
- char data type
- -J compiler option [C++]
- /J compiler option [C++]
- J compiler option [C++]
- default char type is unsigned
ms.assetid: 50973667-6638-491e-9c41-bff73acae19f
ms.openlocfilehash: 7bcf0f2eb2bef08757250999d0a6696b256fb15c
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81322191"
---
# <a name="j-default-char-type-is-unsigned"></a>/J (o tipo char padrão não é assinado)

Altera o `char` tipo `signed char` `unsigned char`padrão de `char` para , e o tipo é `int` zero estendido quando é ampliado para um tipo.

## <a name="syntax"></a>Sintaxe

```
/J
```

## <a name="remarks"></a>Comentários

Se `char` um valor for explicitamente `signed`declarado como , a opção **/J** não o afeta, e o `int` valor é estendido quando é ampliado para um tipo.

A opção **/J** define `_CHAR_UNSIGNED`, `#ifndef` que é usado com o arquivo LIMITS.h para definir o intervalo do tipo padrão. `char`

ANSI C e C++ não exigem `char` uma implementação específica do tipo. Essa opção é útil quando você está trabalhando com dados de caracteres que eventualmente serão traduzidos para um idioma diferente do inglês.

> [!NOTE]
> Se você usar esta opção de compilador com ATL/MFC, um erro pode ser gerado. Embora você possa desativar esse `_ATL_ALLOW_CHAR_UNSIGNED`erro definindo, esta solução não é suportada e pode nem sempre funcionar.

### <a name="to-set-this-compiler-option-in-the-visual-studio-development-environment"></a>Para definir esta opção do compilador no ambiente de desenvolvimento do Visual Studio

1. No **Solution Explorer,** abra o menu de atalho para o projeto e escolha **Propriedades**.

1. Na caixa de diálogo Páginas de **propriedade** do projeto, no painel esquerdo em Propriedades **de configuração,** expanda **C/C++** e selecione **Linha de comando**.

1. No **painel Opções adicionais,** especifique a opção **compilador /J.**

### <a name="to-set-this-compiler-option-programmatically"></a>Para definir essa opção do compilador via programação

- Consulte <xref:Microsoft.VisualStudio.VCProjectEngine.VCCLCompilerTool.DefaultCharIsUnsigned%2A>.

## <a name="see-also"></a>Confira também

[Opções do compilador MSVC](compiler-options.md)<br/>
[Sintaxe da linha de comando do compilador MSVC](compiler-command-line-syntax.md)<br/>
[Definição das propriedades de compilação do C++ no Visual Studio](../working-with-project-properties.md)
