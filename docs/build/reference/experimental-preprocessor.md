---
title: '/experimental: pré-processador (habilitar o modo de conformidade do pré-processador)'
description: 'Use a opção de compilador/experimental: pré-processador para habilitar o suporte experimental ao compilador para um pré-processador de conformidade padrão.'
ms.date: 09/10/2020
f1_keywords:
- preprocessor
- /experimental:preprocessor
helpviewer_keywords:
- preprocessor conformance
- /experimental:preprocessor
- Enable preprocessor conformance mode
ms.openlocfilehash: 9a98289434e7154d2ec8b8753d990876a8218acf
ms.sourcegitcommit: 6280a4c629de0f638ebc2edd446de2a9b11f0406
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/12/2020
ms.locfileid: "90042089"
---
# <a name="experimentalpreprocessor-enable-preprocessor-conformance-mode"></a>`/experimental:preprocessor` (Habilitar o modo de conformidade do pré-processador)

Essa opção está obsoleta a partir do Visual Studio 2019 versão 16,5, substituída pela [`/Zc:preprocessor`](zc-preprocessor.md) opção do compilador. **`/experimental:preprocessor`** habilita um pré-processador experimental baseado em token que está em conformidade com os padrões do C++ 11, incluindo os recursos de pré-processador do C99. Para obter mais informações, consulte [visão geral do MSVC New pré-processador](../../preprocessor/preprocessor-experimental-overview.md).

## <a name="syntax"></a>Sintaxe

> **`/experimental:preprocessor`**\[**`-`**]

## <a name="remarks"></a>Comentários

Use a **`/experimental:preprocessor`** opção do compilador para habilitar o pré-processador de conformidade experimental. Você pode usar **`/experimental:preprocessor-`** a opção para especificar explicitamente o pré-processador tradicional.

A **`/experimental:preprocessor`** opção está disponível a partir do Visual Studio 2017 versão 15,8. A partir do Visual Studio 2019 versão 16,5, o novo pré-processador está concluído e disponível na [`/Zc:preprocessor`](zc-preprocessor.md) opção do compilador.

### <a name="to-set-this-compiler-option-in-the-visual-studio-development-environment"></a>Para definir esta opção do compilador no ambiente de desenvolvimento do Visual Studio

1. Abra a caixa de diálogo **Páginas de Propriedades** do projeto. Para obter detalhes, confira [Definir as propriedades de build e do compilador do C++ no Visual Studio](../working-with-project-properties.md).

1. Selecione a **Configuration Properties**  >  página de propriedade de linha de comando**C/C++** Propriedades de configuração  >  **Command Line** .

1. Modifique a propriedade **Opções adicionais** para incluir *`/experimental:preprocessor`* e, em seguida, escolha **OK**.

## <a name="see-also"></a>Confira também

[/Zc (conformidade)](zc-conformance.md)
