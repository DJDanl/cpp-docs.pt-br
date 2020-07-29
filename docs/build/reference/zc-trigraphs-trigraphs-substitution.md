---
title: /Zc:trigraphs (substituição de trígrafos)
description: Uma opção de compilador do Microsoft C++ que controla o suporte de conformidade para trigrafos.
ms.date: 07/25/2020
f1_keywords:
- /Zc:trigraphs
helpviewer_keywords:
- -Zc compiler options (C++)
- /Zc compiler options (C++)
- Conformance compiler options
- Zc compiler options (C++)
ms.assetid: e3d6058f-400d-4966-a3aa-800cfdf69cbf
ms.openlocfilehash: e24f3d2f0064c3acc04b4c3774f47f6e442d5ddd
ms.sourcegitcommit: 1f009ab0f2cc4a177f2d1353d5a38f164612bdb1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/27/2020
ms.locfileid: "87211847"
---
# <a name="zctrigraphs-trigraphs-substitution"></a>`/Zc:trigraphs`(Substituição de trigrafos)

Quando **`/Zc:trigraphs`** é especificado, o compilador substitui uma sequência de caracteres de trigraph usando um caractere de pontuação correspondente.

## <a name="syntax"></a>Sintaxe

> **`/Zc:trigraphs`**[**`-`**]

## <a name="remarks"></a>Comentários

Um *trigraph* consiste em dois pontos de interrogação consecutivos ( **`??`** ) seguidos por um terceiro caractere exclusivo. O padrão de linguagem C dá suporte a trigrafos para arquivos de origem que usam um conjunto de caracteres que não contém representações gráficas convenientes para alguns caracteres de pontuação. Por exemplo, quando os trigrafos estão habilitados, o compilador substitui o **`??=`** trigraph usando o **`#`** caractere. Por meio do C++ 14, há suporte para trigrafos como em C. O padrão C++ 17 remove trigrafos da linguagem C++. No código C++, a **`/Zc:trigraphs`** opção de compilador permite a substituição de sequências de trigraphs pelo caractere de pontuação correspondente. **`/Zc:trigraphs-`** desabilita a substituição de trigraph.

A **`/Zc:trigraphs`** opção está desativada por padrão e a opção não é afetada quando a [`/permissive-`](permissive-standards-conformance.md) opção é especificada.

Para obter uma lista de trigrafos C/C++ e um exemplo que mostra como usar trigrafos, consulte [trigrafos](../../c-language/trigraphs.md).

## <a name="to-set-this-compiler-option-in-the-visual-studio-development-environment"></a>Para definir esta opção do compilador no ambiente de desenvolvimento do Visual Studio

1. Abra a caixa de diálogo **Páginas de Propriedades** do projeto. Para obter detalhes, confira [Definir as propriedades de build e do compilador do C++ no Visual Studio](../working-with-project-properties.md).

1. Selecione a **Configuration Properties**  >  página de propriedade de linha de comando**C/C++** Propriedades de configuração  >  **Command Line** .

1. Modifique a propriedade **Opções adicionais** para incluir **`/Zc:trigraphs`** ou **`/Zc:trigraphs-`** e, em seguida, escolha **OK**.

## <a name="see-also"></a>Confira também

[`/Zc`Conformidade](zc-conformance.md)<br/>
[Trígrafos](../../c-language/trigraphs.md)
