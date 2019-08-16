---
title: /Source-charset (definir conjunto de caracteres de origem)
ms.date: 02/06/2019
f1_keywords:
- source-charset
- /source-charset
helpviewer_keywords:
- /execution-charset compiler option
ms.assetid: d3c5bf7f-526d-4ee4-acc5-c1a02a4fc481
ms.openlocfilehash: cd3e4eb3fd305ba6bdd298d18b1edb80f2b98343
ms.sourcegitcommit: fcb48824f9ca24b1f8bd37d647a4d592de1cc925
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/15/2019
ms.locfileid: "69498252"
---
# <a name="source-charset-set-source-character-set"></a>/Source-charset (definir conjunto de caracteres de origem)

Permite especificar o conjunto de caracteres de origem para seu executável.

## <a name="syntax"></a>Sintaxe

```
/source-charset:[IANA_name|.CPID]
```

## <a name="arguments"></a>Arguments

**IANA_name**<br/>
O nome do conjunto de caracteres definido pela IANA.

**CPID**<br/>
O identificador da página de código como um número decimal.

## <a name="remarks"></a>Comentários

Você pode usar a opção **/Source-charset** para especificar um conjunto de caracteres de origem estendido a ser usado quando os arquivos de origem incluírem caracteres que não estão representados no conjunto de caracteres de origem básico. O conjunto de caracteres de origem é a codificação usada para interpretar o texto de origem do seu programa na representação interna usada como entrada para as fases de pré-processamento antes da compilação. A representação interna é então convertida no conjunto de caracteres de execução para armazenar a cadeia de caracteres e os valores de caracteres no executável. Você pode usar o nome do conjunto de caracteres IANA ou ISO ou um ponto (.) seguido por um identificador de página de código decimal de 3 a 5 dígitos para especificar o conjunto de caracteres a ser usado. Para obter uma lista de identificadores de página de código com suporte e nomes de conjuntos de caracteres, consulte identificadores de [página de código](/windows/win32/Intl/code-page-identifiers).

Por padrão, o Visual Studio detecta uma marca de ordem de byte para determinar se o arquivo de origem está em um formato Unicode codificado, por exemplo, UTF-16 ou UTF-8. Se nenhuma marca de ordem de byte for encontrada, ela assumirá que o arquivo de origem é codificado usando a página de código do usuário atual, a menos que você especifique um nome de conjunto de caracteres ou uma página de código usando a opção **/Source-charset** . O Visual Studio permite que você salve C++ seu código-fonte usando qualquer uma das várias codificações de caracteres. Para obter mais informações sobre conjuntos de caracteres de origem e de execução, consulte [conjuntos de caracteres](../../cpp/character-sets.md) na documentação do idioma.

O conjunto de caracteres de origem que você fornece deve mapear os caracteres ASCII de 7 bits para os mesmos pontos de código no conjunto de caracteres ou muitos erros de compilação provavelmente serão seguidos. O conjunto de caracteres de origem também deve ser mapeável para o conjunto de caracteres Unicode estendido encodable por UTF-8. Os caracteres que não são encodable em UTF-8 são representados por um substituto específico da implementação. O compilador da Microsoft usa um ponto de interrogação para esses caracteres.

Se você quiser definir o conjunto de caracteres de origem e o conjunto de caracteres de execução como UTF-8, poderá usar a opção de compilador **/UTF-8** como um atalho. É equivalente a especificar **/Source-charset: UTF-8/Execution-charset: UTF-8** na linha de comando. Qualquer uma dessas opções também habilita a opção **/Validate-charset** por padrão.

### <a name="to-set-this-compiler-option-in-the-visual-studio-development-environment"></a>Para definir esta opção do compilador no ambiente de desenvolvimento do Visual Studio

1. Abra a caixa de diálogo **Páginas de Propriedades** do projeto. Para obter mais informações, confira [Definir as propriedades de build e do compilador do C++ no Visual Studio](../working-with-project-properties.md).

1. Expanda as **Propriedades de configuração**, **CC++/** , a pasta de linha de **comando** .

1. Em **Opções adicionais**, adicione a opção **/Source-charset** e especifique sua codificação preferida.

1. Escolha **OK** para salvar suas alterações.

## <a name="see-also"></a>Consulte também

[Opções do compilador MSVC](compiler-options.md)<br/>
[Sintaxe da linha de comando do compilador MSVC](compiler-command-line-syntax.md)<br/>
[/Execution-charset (definir conjunto de caracteres de execução)](execution-charset-set-execution-character-set.md)<br/>
[/utf-8 (definir conjuntos de caracteres de origem e executáveis como UTF-8)](utf-8-set-source-and-executable-character-sets-to-utf-8.md)<br/>
[/validate-charset (validar quanto à presença de caracteres compatíveis)](validate-charset-validate-for-compatible-characters.md)
