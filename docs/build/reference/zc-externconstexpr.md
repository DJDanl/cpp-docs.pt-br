---
title: /Zc:externConstexpr (Habilitar variáveis constexpr externas)
ms.date: 02/28/2018
f1_keywords:
- /Zc:externConstexpr
helpviewer_keywords:
- -Zc:externConstexpr compiler option (C++)
- extern constexpr variables (C++)
ms.assetid: 4da5e33a-2e4d-4ed2-8616-bd8f43265c27
ms.openlocfilehash: db5a8892bcc11538c3ff883a0e9a3a27db0ee14f
ms.sourcegitcommit: a1676bf6caae05ecd698f26ed80c08828722b237
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/29/2020
ms.locfileid: "91502799"
---
# <a name="zcexternconstexpr-enable-extern-constexpr-variables"></a>`/Zc:externConstexpr` (Habilitar variáveis constexpr externas)

A **`/Zc:externConstexpr`** opção do compilador informa ao compilador para estar em conformidade com o padrão C++ e permitir vínculo externo para **`constexpr`** variáveis. Por padrão, o Visual Studio sempre fornece uma **`constexpr`** variável interna de vinculação, mesmo se você especificar a **`extern`** palavra-chave.

## <a name="syntax"></a>Sintaxe

> **`/Zc:externConstexpr`**[**`-`**]

## <a name="remarks"></a>Comentários

A **`/Zc:externConstexpr`** opção do compilador faz com que o compilador aplique vínculo externo a variáveis declaradas usando `extern constexpr` . Em versões anteriores do Visual Studio e, por padrão, ou se **`/Zc:externConstexpr-`** for especificado, o Visual Studio aplicará vínculo interno a **`constexpr`** variáveis, mesmo se a **`extern`** palavra-chave for usada. A **`/Zc:externConstexpr`** opção está disponível a partir do Visual Studio 2017 atualização 15,6. e está desativado por padrão. A [`/permissive-`](permissive-standards-conformance.md) opção não habilita **`/Zc:externConstexpr`** .

Se um arquivo de cabeçalho contiver uma variável declarada `extern constexpr` , ele deverá ser marcado [`__declspec(selectany)`](../../cpp/selectany.md) para mesclar as declarações duplicadas em uma única instância no binário vinculado. Caso contrário, você poderá ver erros de vinculador, por exemplo, LNK2005, para violações da regra de uma definição.

### <a name="to-set-this-compiler-option-in-visual-studio"></a>Para definir essa opção do compilador no Visual Studio

1. Abra a caixa de diálogo **Páginas de Propriedades** do projeto. Para obter detalhes, confira [Definir as propriedades de build e do compilador do C++ no Visual Studio](../working-with-project-properties.md).

1. Selecione a **Configuration Properties**  >  página de propriedade de linha de comando**C/C++** Propriedades de configuração  >  **Command Line** .

1. Adicione **`/Zc:externConstexpr`** ou **`/Zc:externConstexpr-`** ao painel **Opções adicionais:** .

## <a name="see-also"></a>Consulte também

[`/Zc` Conformidade](zc-conformance.md)<br/>
[`auto` Chaves](../../cpp/auto-cpp.md)
