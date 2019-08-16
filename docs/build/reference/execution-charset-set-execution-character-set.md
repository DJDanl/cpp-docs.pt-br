---
title: /Execution-charset (definir conjunto de caracteres de execução)
ms.date: 02/06/2019
f1_keywords:
- execution-charset
- /execution-charset
helpviewer_keywords:
- /execution-charset compiler option
- -execution-charset compiler option
ms.assetid: 0e02f487-2236-45bc-95f3-5760933a8f96
ms.openlocfilehash: 44e83524867bc8a914706e1f5b45b61bc4a48087
ms.sourcegitcommit: fcb48824f9ca24b1f8bd37d647a4d592de1cc925
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/15/2019
ms.locfileid: "69492909"
---
# <a name="execution-charset-set-execution-character-set"></a>/Execution-charset (definir conjunto de caracteres de execução)

Permite especificar o conjunto de caracteres de execução para seu executável.

## <a name="syntax"></a>Sintaxe

```
/execution-charset:[IANA_name|.CPID]
```

## <a name="arguments"></a>Arguments

*IANA_name*<br/>
O nome do conjunto de caracteres definido pela IANA.

*CPID*<br/>
O identificador da página de código.

## <a name="remarks"></a>Comentários

Você pode usar a opção **/Execution-charset** para especificar um conjunto de caracteres de execução. O conjunto de caracteres de execução é a codificação usada para o texto do seu programa que é inserido para a fase de compilação após todas as etapas de pré-processamento. Esse conjunto de caracteres é usado para a representação interna de qualquer cadeia de caracteres ou literais de caracteres no código compilado. Defina essa opção para especificar o conjunto de caracteres de execução estendida a ser usado quando os arquivos de origem incluírem caracteres que não são representáveis no conjunto de caracteres de execução básica. Você pode usar o nome do conjunto de caracteres IANA ou ISO ou um ponto (.) seguido por um identificador de página de código decimal de 3 a 5 dígitos para especificar o conjunto de caracteres a ser usado. Para obter uma lista de identificadores de página de código com suporte e nomes de conjuntos de caracteres, consulte identificadores de [página de código](/windows/win32/Intl/code-page-identifiers).

Por padrão, o Visual Studio detecta uma marca de ordem de byte para determinar se o arquivo de origem está em um formato Unicode codificado, por exemplo, UTF-16 ou UTF-8. Se nenhuma marca de ordem de byte for encontrada, ela assumirá que o arquivo de origem está codificado usando a página de código do usuário atual, a menos que você tenha especificado um nome de conjunto de caracteres ou página de código usando a opção **/Source-charset** ou a opção **/UTF-8** . O Visual Studio permite que você salve C++ seu código-fonte usando qualquer uma das várias codificações de caracteres. Para obter informações sobre conjuntos de caracteres de origem e de execução, consulte [conjuntos de caracteres](../../cpp/character-sets.md) na documentação do idioma.

Se você quiser definir o conjunto de caracteres de origem e o conjunto de caracteres de execução como UTF-8, poderá usar a opção de compilador **/UTF-8** como um atalho. É equivalente a especificar **/Source-charset: UTF-8/Execution-charset: UTF-8** na linha de comando. Qualquer uma dessas opções também habilita a opção **/Validate-charset** por padrão.

### <a name="to-set-this-compiler-option-in-the-visual-studio-development-environment"></a>Para definir esta opção do compilador no ambiente de desenvolvimento do Visual Studio

1. Abra a caixa de diálogo **Páginas de Propriedades** do projeto. Para obter mais informações, confira [Definir as propriedades de build e do compilador do C++ no Visual Studio](../working-with-project-properties.md).

1. Expanda as **Propriedades de configuração**, **CC++/** , a pasta de linha de **comando** .

1. Em **Opções adicionais**, adicione a opção **/Execution-charset** e especifique sua codificação preferida.

1. Escolha **OK** para salvar suas alterações.

## <a name="see-also"></a>Consulte também

[Opções do compilador MSVC](compiler-options.md)<br/>
[Sintaxe da linha de comando do compilador MSVC](compiler-command-line-syntax.md)<br/>
[/source-charset (definir conjunto de caracteres de origem)](source-charset-set-source-character-set.md)<br/>
[/utf-8 (definir conjuntos de caracteres de origem e executáveis como UTF-8)](utf-8-set-source-and-executable-character-sets-to-utf-8.md)<br/>
[/validate-charset (validar quanto à presença de caracteres compatíveis)](validate-charset-validate-for-compatible-characters.md)
