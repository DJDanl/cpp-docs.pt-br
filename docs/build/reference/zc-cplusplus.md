---
title: /ZC:__cplusplus (habilitar macro de cplusplus atualizado)
ms.date: 05/30/2018
f1_keywords:
- /Zc:__cplusplus
helpviewer_keywords:
- -Zc:__cplusplus compiler option (C++)
- __cplusplus macro (C++)
ms.openlocfilehash: 89545f541f32374a47dce7f87958e61873c1b47c
ms.sourcegitcommit: 8105b7003b89b73b4359644ff4281e1595352dda
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/14/2019
ms.locfileid: "57810088"
---
# <a name="zccplusplus-enable-updated-cplusplus-macro"></a>/ZC:__cplusplus (habilitar macro de cplusplus atualizado)

O **/Zc:__cplusplus** compilador opção habilita a  **\_ \_cplusplus** macro do pré-processador para relatar um valor atualizado para suporte de padrões de linguagem C++ recente. Por padrão, o Visual Studio sempre retorna o valor "199711L" para o  **\_ \_cplusplus** macro do pré-processador.

## <a name="syntax"></a>Sintaxe

> **/Zc:__cplusplus**[**-**]

## <a name="remarks"></a>Comentários

O  **\_ \_cplusplus** macro do pré-processador normalmente é usado para suporte ao relatório para uma versão específica do C++ padrão. Porque muitos códigos existentes de parece dependem do valor desta macro correspondência "199711L", o compilador não altera o valor da macro, a menos que você explicitamente opt-in usando o **/Zc:__cplusplus** opção de compilador. O **/Zc:__cplusplus** opção está disponível a partir do Visual Studio 2017 versão 15.7 e está desativado por padrão. Em versões anteriores do Visual Studio e, por padrão, ou se **/Zc:__cplusplus-** for especificado, o valor "199711 L" do Visual Studio retorna para o  **\_ \_cplusplus** macro do pré-processador. O [/permissive--](permissive-standards-conformance.md) opção não permite **/Zc:__cplusplus**.

Quando o **/Zc:__cplusplus** opção estiver habilitada, o valor relatado pelo  **\_ \_cplusplus** macro depende o [/std](std-specify-language-standard-version.md) switch de versão configuração. Esta tabela mostra os valores possíveis para a macro:

|Comutador /ZC:__cplusplus|/std:c++ switch|__cplusplus value|
|-|-|-|
Zc:__cplusplus|/std: c + + 14 (padrão)|201402L
Zc:__cplusplus|/std:c++17|201703L
Zc:__cplusplus|/std:c++latest|201704L
ZC:__cplusplus-(desabilitado)|Qualquer valor|199711L
Não especificado|Qualquer valor|199711L

O compilador não oferece suporte a comutadores de padrões para c++98, c++03 ou c++11.

Para mais refinados de detecção de alterações para o conjunto de ferramentas do compilador, use o [msc_ver](../../preprocessor/predefined-macros.md) macro predefinida. O valor desta macro interna é incrementado para cada atualização de conjunto de ferramentas no Visual Studio 2017 e versões posteriores. O [_MSVC_LANG](../../preprocessor/predefined-macros.md) macro predefinida relata a versão padrão se o **/Zc:__cplusplus** opção está habilitada ou desabilitada. Quando **/Zc:__cplusplus** estiver habilitada, `__cplusplus == _MSVC_LANG`.

### <a name="to-set-this-compiler-option-in-visual-studio"></a>Para definir essa opção do compilador no Visual Studio

1. Abra a caixa de diálogo **Páginas de Propriedades** do projeto. Para obter detalhes, consulte [propriedades de compilador e de build definida C++ no Visual Studio](../working-with-project-properties.md).

1. Selecione o **propriedades de configuração** > **C/C++** > **linha de comando** página de propriedades.

1. Adicione **/Zc:__cplusplus** ou **/Zc:__cplusplus-** para o **opções adicionais:** painel.

## <a name="see-also"></a>Consulte também

- [/Zc (conformidade)](zc-conformance.md)
- [/STD (especificar versão de idioma padrão)](std-specify-language-standard-version.md)
- [Macros predefinidas](../../preprocessor/predefined-macros.md)
