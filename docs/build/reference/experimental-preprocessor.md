---
title: '/experimental: pré-processador (habilitar o modo de conformidade do pré-processador)'
description: 'Use a opção de compilador/experimental: pré-processador para habilitar o suporte experimental ao compilador para um pré-processador de conformidade padrão.'
ms.date: 10/31/2019
f1_keywords:
- preprocessor
- /experimental:preprocessor
helpviewer_keywords:
- preprocessor conformance
- /experimental:preprocessor
- Enable preprocessor conformance mode
ms.openlocfilehash: cb1ac63d2c12083975139455d8625544cb419adf
ms.sourcegitcommit: 2362d15b5eb18d27773c3f7522da3d0eed9e2571
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 11/07/2019
ms.locfileid: "73754048"
---
# <a name="experimentalpreprocessor-enable-preprocessor-conformance-mode"></a>/experimental: pré-processador (habilitar o modo de conformidade do pré-processador)

Essa opção habilita um pré-processador experimental baseado em token que está mais em conformidade com os padrões do C++ 11, incluindo os recursos de pré-processador do C99. Para obter mais informações, consulte [visão geral do pré-processador do MSVC experimental](../../preprocessor/preprocessor-experimental-overview.md).

## <a name="syntax"></a>Sintaxe

> **/experimental: pré-processador**[ **-** ]

## <a name="remarks"></a>Comentários

Use a opção de compilador **/experimental: pré-processador** para habilitar o pré-processador de conformidade experimental. Você pode usar a opção **/experimental: pré-processador-** para especificar explicitamente o pré-processador tradicional.

A opção **/experimental: pré-processador** está disponível a partir do Visual Studio 2017 versão 15,8.

### <a name="to-set-this-compiler-option-in-the-visual-studio-development-environment"></a>Para definir esta opção do compilador no ambiente de desenvolvimento do Visual Studio

1. Abra a caixa de diálogo **Páginas de Propriedades** do projeto. Para obter detalhes, confira [Definir as propriedades de build e do compilador do C++ no Visual Studio](../working-with-project-properties.md).

1. Selecione a página de propriedades **Propriedades da Configuração** > **C/C++**  > **Linha de Comando**.

1. Modifique a propriedade **Opções adicionais** para incluir **/experimental: pré-processador** e, em seguida, escolha **OK**.

## <a name="see-also"></a>Consulte também

[/Zc (conformidade)](zc-conformance.md)
