---
title: /Zc:auto (deduzir tipo variável)
ms.date: 02/28/2018
f1_keywords:
- /Zc:auto
helpviewer_keywords:
- -Zc compiler options (C++)
- Deduce variable type (C++)
- /Zc compiler options (C++)
- Zc compiler options (C++)
ms.assetid: 5f5bc102-44c3-4688-bbe1-080594dcee5c
ms.openlocfilehash: 6bb1c8f2b14c483cbd46ecb6534a33db020e23e0
ms.sourcegitcommit: a1676bf6caae05ecd698f26ed80c08828722b237
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/29/2020
ms.locfileid: "91502829"
---
# <a name="zcauto-deduce-variable-type"></a>`/Zc:auto` (Deduzir tipo de variável)

A **`/Zc:auto`** opção do compilador informa ao compilador como usar a [ `auto` palavra-chave](../../cpp/auto-cpp.md) para declarar variáveis. Se você especificar a opção default, **`/Zc:auto`** , o compilador deduzirá o tipo da variável declarada de sua expressão de inicialização. Se você especificar **`/Zc:auto-`** , o compilador alocará a variável para a classe de armazenamento automática.

## <a name="syntax"></a>Sintaxe

> **`/Zc:auto`**[**`-`**]

## <a name="remarks"></a>Comentários

O padrão C++ define um significado original e revisado para a **`auto`** palavra-chave. Antes do Visual Studio 2010, a palavra-chave declara uma variável na classe de armazenamento automático; ou seja, uma variável que tem um tempo de vida local. A partir do Visual Studio 2010, a palavra-chave deduz o tipo de uma variável da expressão de inicialização da declaração. Use a **`/Zc:auto`** opção do compilador para instruir o compilador a usar o significado revisado da **`auto`** palavra-chave. A **`/Zc:auto`** opção está ativada por padrão. A [`/permissive-`](permissive-standards-conformance.md) opção não altera a configuração padrão de **`/Zc:auto`** .

O compilador emite uma mensagem de diagnóstico apropriada se o uso da **`auto`** palavra-chave contradiz a **`/Zc:auto`** opção do compilador atual. Para obter mais informações, consulte [ `auto` palavra-chave](../../cpp/auto-cpp.md). Para obter mais informações sobre problemas de conformidade com o Visual C++, consulte [comportamento não padrão](../../cpp/nonstandard-behavior.md).

### <a name="to-set-this-compiler-option-in-visual-studio"></a>Para definir essa opção do compilador no Visual Studio

1. Abra a caixa de diálogo **Páginas de Propriedades** do projeto. Para obter detalhes, confira [Definir as propriedades de build e do compilador do C++ no Visual Studio](../working-with-project-properties.md).

1. Selecione a **Configuration Properties**  >  página de propriedade de linha de comando**C/C++** Propriedades de configuração  >  **Command Line** .

1. Adicione **`/Zc:auto`** ou **`/Zc:auto-`** ao painel **Opções adicionais:** .

## <a name="see-also"></a>Consulte também

[`/Zc` Conformidade](zc-conformance.md)<br/>
[`auto` Chaves](../../cpp/auto-cpp.md)
