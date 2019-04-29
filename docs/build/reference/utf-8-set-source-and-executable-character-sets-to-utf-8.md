---
title: /UTF-8 (Definir origem e executáveis conjuntos de caracteres UTF-8)
ms.date: 11/04/2016
f1_keywords:
- /utf-8
helpviewer_keywords:
- /utf-8 compiler option
ms.assetid: f0e1f3cb-6cae-46eb-9483-04ed13d9b504
ms.openlocfilehash: 5ac15c63041e76b8bb0d292868bb982c21866078
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62317283"
---
# <a name="utf-8-set-source-and-executable-character-sets-to-utf-8"></a>/UTF-8 (Definir origem e executáveis conjuntos de caracteres UTF-8)

Especifica o conjunto de caracteres de origem e o caractere de execução definida como UTF-8.

## <a name="syntax"></a>Sintaxe

```
/utf-8
```

## <a name="remarks"></a>Comentários

Você pode usar o **/utf-8** opção para especificar conjuntos de caracteres de origem e de execução, conforme codificado com UTF-8. Ele equivale à especificação **/origem-charset:utf-/execution 8-charset:utf-8** na linha de comando. Além disso, qualquer uma dessas opções permite que o **/validate-charset** opção por padrão. Para obter uma lista de identificadores de páginas de código de suporte e os nomes do conjunto de caracteres, consulte [identificadores de páginas de código](/windows/desktop/Intl/code-page-identifiers).

Por padrão, o Visual Studio detecta uma marca de ordem de byte para determinar se o arquivo de origem está em um formato codificado de Unicode, por exemplo, UTF-16 ou UTF-8. Se nenhuma marca de ordem de byte for encontrada, ele pressupõe que o arquivo de origem é codificado usando a página de código do usuário atual, a menos que você especificou uma página de código, usando **/utf-8** ou o **/source-charset** opção. Visual Studio permite que você salvar seu código-fonte C++, usando qualquer uma das várias codificações de caracteres. Para obter informações sobre conjuntos de caracteres de origem e de execução, consulte [conjuntos de caracteres](../../cpp/character-sets.md) na documentação do idioma.

### <a name="to-set-this-compiler-option-in-the-visual-studio-development-environment"></a>Para definir esta opção do compilador no ambiente de desenvolvimento do Visual Studio

1. Abra o projeto **páginas de propriedade** caixa de diálogo. Para obter mais informações, consulte [propriedades de compilador e de build definida C++ no Visual Studio](../working-with-project-properties.md).

1. Expanda o **propriedades de configuração**, **C/C++**, **linha de comando** pasta.

1. Na **opções adicionais**, adicione o **/utf-8** opção para especificar a codificação preferencial.

1. Escolha **OK** para salvar suas alterações.

## <a name="see-also"></a>Consulte também

[Opções do compilador MSVC](compiler-options.md)<br/>
[Sintaxe da linha de comando do compilador MSVC](compiler-command-line-syntax.md)<br/>
[/Execution-charset (definir execução de conjunto de caracteres)](execution-charset-set-execution-character-set.md)<br/>
[/source-charset (definir conjunto de caracteres de origem)](source-charset-set-source-character-set.md)<br/>
[/validate-charset (validar quanto à presença de caracteres compatíveis)](validate-charset-validate-for-compatible-characters.md)
