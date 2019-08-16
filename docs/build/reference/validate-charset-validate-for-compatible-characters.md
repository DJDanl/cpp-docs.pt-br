---
title: /validate-charset (validar quanto à presença de caracteres compatíveis)
ms.date: 02/06/2019
f1_keywords:
- /validate-charset
- validate-charset
helpviewer_keywords:
- /validate-charset compiler option
ms.assetid: 50360fd0-4d32-4a4f-95d0-53d38c12ad4c
ms.openlocfilehash: 2390aa98b9416eb538f529c8c370c888cccf4734
ms.sourcegitcommit: fcb48824f9ca24b1f8bd37d647a4d592de1cc925
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/15/2019
ms.locfileid: "69498168"
---
# <a name="validate-charset-validate-for-compatible-characters"></a>/validate-charset (validar quanto à presença de caracteres compatíveis)

Valida que o texto do arquivo de origem contém apenas caracteres representáveis como UTF-8.

## <a name="syntax"></a>Sintaxe

```
/validate-charset[-]
```

## <a name="remarks"></a>Comentários

Você pode usar a opção **/Validate-charset** para validar que o código-fonte contém apenas caracteres que podem ser representados tanto no conjunto de caracteres de origem quanto no conjunto de caracteres de execução. Essa verificação é habilitada automaticamente quando você especifica opções de compilador **/Source-charset**, **/Execution-charset**ou **/UTF-8** . Você pode desabilitar essa verificação explicitamente especificando a opção **/Validate-charset-** .

Por padrão, o Visual Studio detecta uma marca de ordem de byte para determinar se o arquivo de origem está em um formato Unicode codificado, por exemplo, UTF-16 ou UTF-8. Se nenhuma marca de ordem de byte for encontrada, ela assumirá que o arquivo de origem está codificado usando a página de código do usuário atual, a menos que você tenha especificado uma página de código usando **/UTF-8** ou a opção **/Source-charset** . O Visual Studio permite que você salve C++ seu código-fonte usando qualquer uma das várias codificações de caracteres. Para obter informações sobre conjuntos de caracteres de origem e de execução, consulte [conjuntos de caracteres](../../cpp/character-sets.md) na documentação do idioma. Para obter uma lista de identificadores de página de código com suporte e nomes de conjuntos de caracteres, consulte identificadores de [página de código](/windows/win32/Intl/code-page-identifiers).

O Visual Studio usa UTF-8 como a codificação de caractere interna durante a conversão entre o conjunto de caracteres de origem e o conjunto de caracteres de execução. Se um caractere no arquivo de origem não puder ser representado no conjunto de caracteres de execução, a conversão UTF-8 substituirá um caractere de ponto de interrogação '? '. A opção **/Validate-charset** faz com que a compilação relate um aviso se isso ocorrer.

### <a name="to-set-this-compiler-option-in-the-visual-studio-development-environment"></a>Para definir esta opção do compilador no ambiente de desenvolvimento do Visual Studio

1. Abra a caixa de diálogo **Páginas de Propriedades** do projeto. Para obter mais informações, confira [Definir as propriedades de build e do compilador do C++ no Visual Studio](../working-with-project-properties.md).

1. Expanda as **Propriedades de configuração**, **CC++/** , a pasta de linha de **comando** .

1. Em **Opções adicionais**, adicione a opção **/Validate-charset** e especifique sua codificação preferida.

1. Escolha **OK** para salvar suas alterações.

## <a name="see-also"></a>Consulte também

[Opções do compilador MSVC](compiler-options.md)<br/>
[Sintaxe da linha de comando do compilador MSVC](compiler-command-line-syntax.md)<br/>
[/Execution-charset (definir conjunto de caracteres de execução)](execution-charset-set-execution-character-set.md)<br/>
[/source-charset (definir conjunto de caracteres de origem)](source-charset-set-source-character-set.md)<br/>
[/utf-8 (definir conjuntos de caracteres de origem e executáveis como UTF-8)](utf-8-set-source-and-executable-character-sets-to-utf-8.md)
