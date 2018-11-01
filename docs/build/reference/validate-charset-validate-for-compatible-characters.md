---
title: /Validate-charset (validar quanto caracteres compatíveis)
ms.date: 11/04/2016
f1_keywords:
- /validate-charset
- validate-charset
helpviewer_keywords:
- /validate-charset compiler option
ms.assetid: 50360fd0-4d32-4a4f-95d0-53d38c12ad4c
ms.openlocfilehash: 243d225f5acde0c6099050539687726ea082c898
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50590483"
---
# <a name="validate-charset-validate-for-compatible-characters"></a>/Validate-charset (validar quanto caracteres compatíveis)

Valida que o texto do arquivo de origem contém apenas caracteres representáveis como UTF-8.

## <a name="syntax"></a>Sintaxe

```
/validate-charset[-]
```

## <a name="remarks"></a>Comentários

Você pode usar o **/validate-charset** opção para validar que o código-fonte contém somente o conjunto de caracteres que podem ser representados no caractere de origem e o conjunto de caracteres de execução. Essa verificação é habilitada automaticamente quando você especifica **/source-charset**, **/execution-charset**, ou **/utf-8** opções do compilador. Você poderá desabilitar explicitamente essa verificação, especificando o **/ validate-charset -** opção.

Por padrão, o Visual Studio detecta uma marca de ordem de byte para determinar se o arquivo de origem está em um formato codificado de Unicode, por exemplo, UTF-16 ou UTF-8. Se nenhuma marca de ordem de byte for encontrada, ele pressupõe que o arquivo de origem é codificado usando a página de código do usuário atual, a menos que você especificou uma página de código, usando **/utf-8** ou o **/source-charset** opção. Visual Studio permite que você salvar seu código-fonte C++, usando qualquer uma das várias codificações de caracteres. Para obter informações sobre conjuntos de caracteres de origem e de execução, consulte [conjuntos de caracteres](../../cpp/character-sets.md) na documentação do idioma. Para obter uma lista de identificadores de páginas de código de suporte e os nomes do conjunto de caracteres, consulte [identificadores de páginas de código](/windows/desktop/Intl/code-page-identifiers).

O Visual Studio usa UTF-8 como a codificação de caracteres interno durante a conversão entre o conjunto de caracteres de origem e o conjunto de caracteres de execução. Se um caractere no arquivo de origem não pode ser representado no conjunto de caracteres de execução, a conversão de UTF-8 substitui um ponto de interrogação '?' caracteres. O **/validate-charset** opção faz com que a compilação para relatar um aviso se isso ocorrer.

### <a name="to-set-this-compiler-option-in-the-visual-studio-development-environment"></a>Para definir esta opção do compilador no ambiente de desenvolvimento do Visual Studio

1. Abra o projeto **páginas de propriedade** caixa de diálogo. Para obter mais informações, confira [Trabalhando com propriedades do projeto](../../ide/working-with-project-properties.md).

1. Expanda o **propriedades de configuração**, **C/C++**, **linha de comando** pasta.

1. Na **opções avançadas**, adicione o **/validate-charset** opção e especifique a codificação preferencial.

1. Escolher **Okey** para salvar suas alterações.

## <a name="see-also"></a>Consulte também

[Opções do Compilador](../../build/reference/compiler-options.md)<br/>
[Definindo opções do compilador](../../build/reference/setting-compiler-options.md)<br/>
[/Execution-charset (definir execução de conjunto de caracteres)](../../build/reference/execution-charset-set-execution-character-set.md)<br/>
[/source-charset (definir conjunto de caracteres de origem)](../../build/reference/source-charset-set-source-character-set.md)<br/>
[/utf-8 (definir conjuntos de caracteres de origem e executáveis como UTF-8)](../../build/reference/utf-8-set-source-and-executable-character-sets-to-utf-8.md)