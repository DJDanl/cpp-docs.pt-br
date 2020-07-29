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
ms.openlocfilehash: d95fed3d9af81d89ac03a52a1e6433786118430e
ms.sourcegitcommit: 1f009ab0f2cc4a177f2d1353d5a38f164612bdb1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/27/2020
ms.locfileid: "87223831"
---
# <a name="j-default-char-type-is-unsigned"></a>/J (o tipo char padrão não é assinado)

Altera o **`char`** tipo padrão de **`signed char`** para **`unsigned char`** e o **`char`** tipo é zero-estendido quando ele é ampliado para um **`int`** tipo.

## <a name="syntax"></a>Sintaxe

```
/J
```

## <a name="remarks"></a>Comentários

Se um **`char`** valor for declarado explicitamente como **`signed`** , a opção **/j** não o afetará, e o valor será estendido por assinatura quando for ampliado para um **`int`** tipo.

A opção **/j** define `_CHAR_UNSIGNED` , que é usada com `#ifndef` no arquivo LIMITS. h para definir o intervalo do tipo padrão **`char`** .

ANSI C e C++ não exigem uma implementação específica do **`char`** tipo. Essa opção é útil quando você está trabalhando com dados de caractere que eventualmente serão convertidos em um idioma diferente do inglês.

> [!NOTE]
> Se você usar essa opção de compilador com ATL/MFC, um erro poderá ser gerado. Embora você possa desabilitar esse erro definindo `_ATL_ALLOW_CHAR_UNSIGNED` , essa solução alternativa não tem suporte e nem sempre pode funcionar.

### <a name="to-set-this-compiler-option-in-the-visual-studio-development-environment"></a>Para definir esta opção do compilador no ambiente de desenvolvimento do Visual Studio

1. No **Gerenciador de soluções**, abra o menu de atalho do projeto e, em seguida, escolha **Propriedades**.

1. Na caixa de **diálogo páginas de propriedades** do projeto, no painel esquerdo, em Propriedades de **configuração**, expanda **C/C++** e, em seguida, selecione **linha de comando**.

1. No painel **Opções adicionais** , especifique a opção de compilador **/j** .

### <a name="to-set-this-compiler-option-programmatically"></a>Para definir essa opção do compilador via programação

- Consulte <xref:Microsoft.VisualStudio.VCProjectEngine.VCCLCompilerTool.DefaultCharIsUnsigned%2A>.

## <a name="see-also"></a>Confira também

[Opções do compilador MSVC](compiler-options.md)<br/>
[Sintaxe de linha de comando do compilador MSVC](compiler-command-line-syntax.md)<br/>
[Definição das propriedades de compilação do C++ no Visual Studio](../working-with-project-properties.md)
