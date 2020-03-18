---
title: /Zc:trigraphs (substituição de trígrafos)
ms.date: 03/06/2018
f1_keywords:
- /Zc:trigraphs
helpviewer_keywords:
- -Zc compiler options (C++)
- /Zc compiler options (C++)
- Conformance compiler options
- Zc compiler options (C++)
ms.assetid: e3d6058f-400d-4966-a3aa-800cfdf69cbf
ms.openlocfilehash: 0e4c98e09551d39e3ff7978767b21f1d2c5bb318
ms.sourcegitcommit: 63784729604aaf526de21f6c6b62813882af930a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/17/2020
ms.locfileid: "79438658"
---
# <a name="zctrigraphs-trigraphs-substitution"></a>/Zc:trigraphs (substituição de trígrafos)

Quando **/Zc: trigrafos** é especificado, o compilador substitui uma sequência de caracteres de trigraph usando um caractere de pontuação correspondente.

## <a name="syntax"></a>Sintaxe

> **/Zc: trigrafos**[ **-** ]

## <a name="remarks"></a>Comentários

Um *trigraph* consiste em dois pontos de interrogação consecutivos ("??") seguidos por um terceiro caractere exclusivo. O padrão de linguagem C dá suporte a trigrafos para arquivos de origem que usam um conjunto de caracteres que não contém representações gráficas convenientes para alguns caracteres de pontuação. Por exemplo, quando os trigrafos estão habilitados, o compilador substitui o "?? = "trigraph usando o caractere ' # '. Por meio do C++ 14, há suporte para trigrafos como em C. O padrão C++ 17 remove trigrafos da C++ linguagem. No C++ código, a opção de compilador **/Zc: trigraphs** permite a substituição de sequências de trigraph pelo caractere de pontuação correspondente. **/Zc: trigrafos-desabilita a substituição de** trigraph.

A opção **/Zc: trigrafos** está desativada por padrão e a opção não é afetada quando a opção [/permissive-](permissive-standards-conformance.md) é especificada.

Para obter uma lista de CC++ /trigrafos e um exemplo que mostra como usar trigrafos, consulte [trigrafos](../../c-language/trigraphs.md).

## <a name="to-set-this-compiler-option-in-the-visual-studio-development-environment"></a>Para definir esta opção do compilador no ambiente de desenvolvimento do Visual Studio

1. Abra a caixa de diálogo **Páginas de Propriedades** do projeto. Para obter detalhes, confira [Definir as propriedades de build e do compilador do C++ no Visual Studio](../working-with-project-properties.md).

1. Selecione a página de propriedades **Propriedades da Configuração** > **C/C++**  > **Linha de Comando**.

1. Modifique a propriedade **Opções adicionais** para incluir **/Zc: trigrafis** ou **/Zc: trigrafos-** e escolha **OK**.

## <a name="see-also"></a>Consulte também

[/Zc (conformidade)](zc-conformance.md)<br/>
[Trígrafos](../../c-language/trigraphs.md)<br/>
