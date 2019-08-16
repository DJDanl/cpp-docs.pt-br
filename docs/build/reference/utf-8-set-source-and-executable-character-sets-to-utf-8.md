---
title: /UTF-8 (definir conjuntos de caracteres de origem e executáveis como UTF-8)
ms.date: 11/04/2016
f1_keywords:
- /utf-8
helpviewer_keywords:
- /utf-8 compiler option
ms.assetid: f0e1f3cb-6cae-46eb-9483-04ed13d9b504
ms.openlocfilehash: 1ff0f23ad0758642c73b1b35d6d4dd1be20899cb
ms.sourcegitcommit: fcb48824f9ca24b1f8bd37d647a4d592de1cc925
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/15/2019
ms.locfileid: "69498173"
---
# <a name="utf-8-set-source-and-executable-character-sets-to-utf-8"></a>/UTF-8 (definir conjuntos de caracteres de origem e executáveis como UTF-8)

Especifica o conjunto de caracteres de origem e o conjunto de caracteres de execução como UTF-8.

## <a name="syntax"></a>Sintaxe

```
/utf-8
```

## <a name="remarks"></a>Comentários

Você pode usar a opção **/UTF-8** para especificar os conjuntos de caracteres de origem e de execução como codificados usando UTF-8. É equivalente a especificar **/Source-charset: UTF-8/Execution-charset: UTF-8** na linha de comando. Qualquer uma dessas opções também habilita a opção **/Validate-charset** por padrão. Para obter uma lista de identificadores de página de código com suporte e nomes de conjuntos de caracteres, consulte identificadores de [página de código](/windows/win32/Intl/code-page-identifiers).

Por padrão, o Visual Studio detecta uma marca de ordem de byte para determinar se o arquivo de origem está em um formato Unicode codificado, por exemplo, UTF-16 ou UTF-8. Se nenhuma marca de ordem de byte for encontrada, ela assumirá que o arquivo de origem está codificado usando a página de código do usuário atual, a menos que você tenha especificado uma página de código usando **/UTF-8** ou a opção **/Source-charset** . O Visual Studio permite que você salve C++ seu código-fonte usando qualquer uma das várias codificações de caracteres. Para obter informações sobre conjuntos de caracteres de origem e de execução, consulte [conjuntos de caracteres](../../cpp/character-sets.md) na documentação do idioma.

### <a name="to-set-this-compiler-option-in-the-visual-studio-development-environment"></a>Para definir esta opção do compilador no ambiente de desenvolvimento do Visual Studio

1. Abra a caixa de diálogo **Páginas de Propriedades** do projeto. Para obter mais informações, confira [Definir as propriedades de build e do compilador do C++ no Visual Studio](../working-with-project-properties.md).

1. Expanda as **Propriedades de configuração**, **CC++/** , a pasta de linha de **comando** .

1. Em **Opções adicionais**, adicione a opção **/UTF-8** para especificar sua codificação preferida.

1. Escolha **OK** para salvar suas alterações.

## <a name="see-also"></a>Consulte também

[Opções do compilador MSVC](compiler-options.md)<br/>
[Sintaxe da linha de comando do compilador MSVC](compiler-command-line-syntax.md)<br/>
[/Execution-charset (definir conjunto de caracteres de execução)](execution-charset-set-execution-character-set.md)<br/>
[/source-charset (definir conjunto de caracteres de origem)](source-charset-set-source-character-set.md)<br/>
[/validate-charset (validar quanto à presença de caracteres compatíveis)](validate-charset-validate-for-compatible-characters.md)
