---
title: '/Zc: pré-processador (habilitar o modo de conformidade do pré-processador)'
description: 'Use a opção de compilador/Zc: pré-processador para habilitar o suporte do compilador para um pré-processador de conformidade padrão.'
ms.date: 09/10/2020
f1_keywords:
- preprocessor
- /Zc:preprocessor
helpviewer_keywords:
- preprocessor conformance
- /Zc:preprocessor
- Enable preprocessor conformance mode
ms.openlocfilehash: 356434e4892966b9a9304021dd5d8770dcc2f8b1
ms.sourcegitcommit: 6280a4c629de0f638ebc2edd446de2a9b11f0406
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/12/2020
ms.locfileid: "90042897"
---
# <a name="zcpreprocessor-enable-preprocessor-conformance-mode"></a>`/Zc:preprocessor` (Habilitar o modo de conformidade do pré-processador)

Essa opção habilita um pré-processador baseado em token que está em conformidade com os padrões C99 e C++ 11 e posteriores. Para obter mais informações, consulte [visão geral do MSVC New pré-processador](../../preprocessor/preprocessor-experimental-overview.md).

## <a name="syntax"></a>Sintaxe

> **`/Zc:preprocessor`**[**-**]

## <a name="remarks"></a>Comentários

Use a **`/Zc:preprocessor`** opção do compilador para habilitar o pré-processador de conformidade. Você pode usar **`/Zc:preprocessor-`** a opção para especificar explicitamente o pré-processador tradicional (não compatível).

A **`/Zc:preprocessor`** opção está disponível a partir do Visual Studio 2019 versão 16,5. Uma versão anterior e incompleta da nova opção de pré-processador está disponível em versões do Visual Studio a partir do Visual Studio 2017 versão 15,8. Para obter mais informações, consulte [`/experimental:preprocessor`](experimental-preprocessor.md).

### <a name="to-set-this-compiler-option-in-the-visual-studio-development-environment"></a>Para definir esta opção do compilador no ambiente de desenvolvimento do Visual Studio

1. Abra a caixa de diálogo **Páginas de Propriedades** do projeto. Para obter detalhes, confira [Definir as propriedades de build e do compilador do C++ no Visual Studio](../working-with-project-properties.md).

1. Selecione a **Configuration Properties**  >  página de propriedade de linha de comando**C/C++** Propriedades de configuração  >  **Command Line** .

1. Modifique a propriedade **Opções adicionais** para incluir *`/Zc:preprocessor`* e, em seguida, escolha **OK**.

## <a name="see-also"></a>Confira também

[/Zc (conformidade)](zc-conformance.md)
