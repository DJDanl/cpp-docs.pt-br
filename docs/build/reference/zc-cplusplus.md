---
title: /Zc:__cplusplus (Habilitar a macro __cplusplus atualizada)
ms.date: 05/16/2019
f1_keywords:
- /Zc:__cplusplus
helpviewer_keywords:
- -Zc:__cplusplus compiler option (C++)
- __cplusplus macro (C++)
ms.openlocfilehash: 43392438eabc7cc7f6decb1349d112a0ce5bd0f5
ms.sourcegitcommit: a10c9390413978d36b8096b684d5ed4cf1553bc8
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/17/2019
ms.locfileid: "65837544"
---
# <a name="zccplusplus-enable-updated-cplusplus-macro"></a>/Zc:__cplusplus (Habilitar a macro __cplusplus atualizada)

A opção do compilador **/Zc:__cplusplus** habilita a macro do pré-processador **\_\_cplusplus** para relatar um valor atualizado para o suporte recente de padrões da linguagem C++. Por padrão, o Visual Studio sempre retorna o valor "199711L" para a macro do pré-processador **\_\_cplusplus**.

## <a name="syntax"></a>Sintaxe

> **/Zc:__cplusplus**[**-**]

## <a name="remarks"></a>Comentários

A macro do pré-processador **\_\_cplusplus** normalmente é usada para relatar o suporte a uma versão específica do padrão do C++. Como muitos códigos existentes parecem depender do valor dessa macrocorrespondência "199711L", o compilador não alterará o valor da macro, a menos que você o aceite explicitamente usando a opção do compilador **/Zc:__cplusplus**. A opção **/Zc:__cplusplus** está disponível no Visual Studio 2017 versão 15.7 em diante e está desativado por padrão. Em versões anteriores do Visual Studio e por padrão ou se **/Zc:__cplusplus-** for especificado, o Visual Studio retornará o valor "199711L" para a macro do pré-processador **\_\_cplusplus**. A opção [/permissive-](permissive-standards-conformance.md) não habilita **/Zc:__cplusplus**.

Quando a opção **/Zc:__cplusplus** estiver habilitada, o valor relatado pela macro **\_\_cplusplus** dependerá da configuração da opção da versão [/std](std-specify-language-standard-version.md). Esta tabela mostra os possíveis valores para a macro:

|Opção /Zc:__cplusplus|Opção /std:c++|Valor de __cplusplus|
|-|-|-|
Zc:__cplusplus|/std:c++14 (padrão)|201402L
Zc:__cplusplus|/std:c++17|201703L
Zc:__cplusplus|/std:c++latest|201704L
Zc:__cplusplus- (desabilitado)|Qualquer valor|199711L
Não especificado|Qualquer valor|199711L

O compilador não dá suporte a opções de padrões para C++98, C++03 ou C++11.

Para obter uma detecção mais refinada de alterações no conjunto de ferramentas do compilador, use a macro predefinida [_MSC_VER](../../preprocessor/predefined-macros.md). O valor dessa macro interna é incrementado para cada atualização do conjunto de ferramentas no Visual Studio 2017 e versões posteriores. A macro predefinida [_MSVC_LANG](../../preprocessor/predefined-macros.md) relatará a versão padrão se a opção **/Zc:__cplusplus** estiver habilitada ou desabilitada. Quando **/Zc:__cplusplus** estiver habilitado, `__cplusplus == _MSVC_LANG`.

### <a name="to-set-this-compiler-option-in-visual-studio"></a>Para definir essa opção do compilador no Visual Studio

1. Abra a caixa de diálogo **Páginas de Propriedades** do projeto. Para obter detalhes, confira [Definir as propriedades de build e do compilador do C++ no Visual Studio](../working-with-project-properties.md).

1. Selecione a página de propriedades **Propriedades da Configuração** > **C/C++** > **Linha de Comando**.

1. Adicione **/Zc:__cplusplus** ou **/Zc:__cplusplus-** ao painel **Opções adicionais:**.

## <a name="see-also"></a>Consulte também

- [/Zc (conformidade)](zc-conformance.md)
- [/std (Especificar versão padrão da linguagem)](std-specify-language-standard-version.md)
- [Macros predefinidas](../../preprocessor/predefined-macros.md)
