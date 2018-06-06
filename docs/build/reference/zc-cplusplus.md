---
title: /ZC:__cplusplus (habilitar macro de cplusplus atualizado)
ms.custom: ''
ms.date: 05/30/2018
ms.technology:
- cpp-tools
ms.topic: reference
f1_keywords:
- /Zc:__cplusplus
dev_langs:
- C++
helpviewer_keywords:
- -Zc:__cplusplus compiler option (C++)
- __cplusplus macro (C++)
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: a796794c0086b09c15ee88442e0fea4d1b114d98
ms.sourcegitcommit: a4454b91d556a3dc43d8755cdcdeabcc9285a20e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 06/04/2018
ms.locfileid: "34705706"
---
# <a name="zccplusplus-enable-updated-cplusplus-macro"></a>/ZC:__cplusplus (habilitar macro de cplusplus atualizado)

O **/Zc:__cplusplus** compilador opção habilita o  **\_ \_cplusplus** macro de pré-processador para relatar um valor atualizado para suporte de padrões de linguagem C++ recente. Por padrão, o Visual Studio sempre retorna o valor "199711L" para o  **\_ \_cplusplus** macro de pré-processador.

## <a name="syntax"></a>Sintaxe

> **/ZC:__cplusplus**[**-**]

## <a name="remarks"></a>Comentários

O  **\_ \_cplusplus** macro de pré-processador é comumente usado para suporte a relatórios de uma versão específica do padrão do C++. Porque parece muito código existente que dependem do valor desta macro correspondência "199711L", o compilador não altera o valor da macro a menos que você explicitamente participar usando o **/Zc:__cplusplus** opção de compilador. O **/Zc:__cplusplus** opção está disponível no Visual Studio 2017 versão 15,7 e está desativado por padrão. Em versões anteriores do Visual Studio e, por padrão, ou se **/Zc:__cplusplus-** for especificado, o Visual Studio retorna o valor "199711 L" para o  **\_ \_cplusplus** macro de pré-processador. O [/ permissivo-](permissive-standards-conformance.md) não habilitar a opção **/Zc:__cplusplus**.

Quando o **/Zc:__cplusplus** opção é habilitada, o valor relatado pelo  **\_ \_cplusplus** macro depende o [/std](std-specify-language-standard-version.md) switch de versão configuração. Esta tabela mostra os valores possíveis para a macro:

|Opção /ZC:__cplusplus|opção /std:c++|valor de cplusplus|
|-|-|-|
ZC:__cplusplus|/std:c + + 14 (padrão)|201402L
ZC:__cplusplus|/std:c + + 17|201703L
ZC:__cplusplus|/std:c + + mais recente|201704L
ZC:__cplusplus-(desabilitado)|Qualquer valor|199711L
Não foi especificado|Qualquer valor|199711L

O compilador não dá suporte a comutadores de padrões de C + + 98, C + + 03 ou C++ 11.

Para detectar refinado de alterações para o conjunto de ferramentas do compilador, use o [msc_ver](../../preprocessor/predefined-macros.md) macro predefinida. O valor desta macro interna é incrementado para cada atualização de conjunto de ferramentas no Visual Studio de 2017 e versões posteriores. O [_MSVC_LANG](../../preprocessor/predefined-macros.md) macro predefinida informa a versão padrão se o **/Zc:__cplusplus** opção está habilitada ou desabilitada. Quando **/Zc:__cplusplus** estiver habilitado, `__cplusplus == _MSVC_LANG`.

### <a name="to-set-this-compiler-option-in-visual-studio"></a>Para definir essa opção do compilador no Visual Studio

1. Abra a caixa de diálogo **Páginas de Propriedades** do projeto. Para obter detalhes, consulte [trabalhar com propriedades do projeto](../../ide/working-with-project-properties.md).

1. Selecione o **propriedades de configuração** > **C/C++** > **linha de comando** página de propriedades.

1. Adicionar **/Zc:__cplusplus** ou **/Zc:__cplusplus-** para o **opções adicionais:** painel.

## <a name="see-also"></a>Consulte também

- [/Zc (conformidade)](zc-conformance.md)
- [/STD (versão padrão de especificar idioma)](std-specify-language-standard-version.md)
- [Macros predefinidas](../../preprocessor/predefined-macros.md)
