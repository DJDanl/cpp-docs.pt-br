---
title: /U, /u (indefinir símbolos)
description: Use as opções/U e/u do compilador do Microsoft C/C++ para não definir símbolos de pré-processador.
ms.date: 09/03/2020
f1_keywords:
- VC.Project.VCCLCompilerTool.UndefinePreprocessorDefinitions
- VC.Project.VCCLWCECompilerTool.UndefinePreprocessorDefinitions
- VC.Project.VCCLCompilerTool.UndefineAllPreprocessorDefinitions
- /u
- VC.Project.VCCLWCECompilerTool.UndefineAllPreprocessorDefinitions
helpviewer_keywords:
- -U compiler option [C++]
- Undefine Symbols compiler option
- /U compiler option [C++]
- U compiler option [C++]
ms.assetid: 7bc0474f-6d1f-419b-807d-0d8816763b2a
ms.openlocfilehash: 78effabba2fa72e5ab7f2dfc6ef91f22383b063f
ms.sourcegitcommit: 0df2b7ab4e81284c5248e4584767591dcc1950c3
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/09/2020
ms.locfileid: "89609201"
---
# <a name="u-u-undefine-symbols"></a>/U, /u (indefinir símbolos)

A **`/U`** opção do compilador não define o símbolo de pré-processador especificado. A **`/u`** opção do compilador não define os símbolos específicos da Microsoft que o compilador define.

## <a name="syntax"></a>Sintaxe

> **`/U`**\[ ]*símbolo*\
> **`/u`**

## <a name="arguments"></a>Argumentos

*símbolo*<br/>
O símbolo de pré-processador a ser redefinido.

## <a name="remarks"></a>Comentários

Nenhuma das **`/U`** Opções e **`/u`** pode desdefinir um símbolo criado usando a **`#define`** diretiva.

A **`/U`** opção pode desdefinir um símbolo que foi definido anteriormente usando a **`/D`** opção.

Por padrão, o compilador pode definir um grande número de símbolos específicos da Microsoft. Aqui estão algumas regras comuns:

| Símbolo | Função |
|--|--|
| `_CHAR_UNSIGNED` | O tipo de caractere padrão não é assinado. Definido quando a [`/J`](j-default-char-type-is-unsigned.md) opção é especificada. |
| `_CPPRTTI` | Definido para o código compilado com a [`/GR`](gr-enable-run-time-type-information.md) opção. |
| `_CPPUNWIND` | Definido para o código compilado com a [`/EHsc`](eh-exception-handling-model.md) opção. |
| `_DLL` | Definido quando a [`/MD`](md-mt-ld-use-run-time-library.md) opção é especificada. |
| `_M_IX86` | Por padrão, definido como 600 para destinos x86. |
| `_MSC_VER` | Definido como um valor inteiro exclusivo para cada versão do compilador. Para obter mais informações, consulte [macros predefinidas](../../preprocessor/predefined-macros.md). |
| `_WIN32` | Definido para aplicativos WIN32. Sempre definido. |
| `_MT` | Definido quando a [`/MD`](md-mt-ld-use-run-time-library.md) [`/MT`](md-mt-ld-use-run-time-library.md) opção or é especificada. |

Para obter uma lista completa de macros predefinidas específicas da Microsoft, consulte [macros predefinidas](../../preprocessor/predefined-macros.md).

### <a name="to-set-this-compiler-option-in-the-visual-studio-development-environment"></a>Para definir esta opção do compilador no ambiente de desenvolvimento do Visual Studio

1. Abra a caixa de diálogo **Páginas de Propriedades** do projeto. Para obter detalhes, confira [Definir as propriedades de build e do compilador do C++ no Visual Studio](../working-with-project-properties.md).

1. Selecione a **Configuration Properties**  >  página de propriedades avançada**C/C++** Properties  >  **Advanced** .

1. Modifique as propriedades de definição de **pré-processador** de definição ou **Desdefinição de todas as definições de pré-processador** .

### <a name="to-set-this-compiler-option-programmatically"></a>Para definir essa opção do compilador via programação

- Consulte <xref:Microsoft.VisualStudio.VCProjectEngine.VCCLCompilerTool.UndefineAllPreprocessorDefinitions%2A> ou <xref:Microsoft.VisualStudio.VCProjectEngine.VCCLCompilerTool.UndefinePreprocessorDefinitions%2A>.

## <a name="see-also"></a>Confira também

[Opções do compilador MSVC](compiler-options.md)<br/>
[Sintaxe da linha de comando do compilador MSVC](compiler-command-line-syntax.md)<br/>
[**`/J`** (O tipo de caractere padrão não é assinado)](j-default-char-type-is-unsigned.md)<br/>
[**`/GR`** (Habilitar informações de tipo de tempo de execução)](gr-enable-run-time-type-information.md)<br/>
[**`/EH`** (Modelo de tratamento de exceção)](eh-exception-handling-model.md)<br/>
[**`/MD`**, **`/MT`** , **`/LD`** (Use biblioteca de tempo de execução)](md-mt-ld-use-run-time-library.md)
