---
title: '/ZC: trigraphs (substituição de trígrafos) | Microsoft Docs'
ms.custom: ''
ms.date: 03/06/2018
ms.technology:
- cpp-tools
ms.topic: reference
f1_keywords:
- /Zc
dev_langs:
- C++
helpviewer_keywords:
- -Zc compiler options (C++)
- /Zc compiler options (C++)
- Conformance compiler options
- Zc compiler options (C++)
ms.assetid: e3d6058f-400d-4966-a3aa-800cfdf69cbf
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: ce8c9d13fa062ddac0f31eac0e20fba1266c7a8c
ms.sourcegitcommit: 92f2fff4ce77387b57a4546de1bd4bd464fb51b6
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/17/2018
ms.locfileid: "45707727"
---
# <a name="zctrigraphs-trigraphs-substitution"></a>/Zc:trigraphs (substituição de trígrafos)

Quando **/ZC: trigraphs** for especificado, o compilador substitui uma sequência de caracteres de trígrafo usando um caractere de pontuação correspondente.

## <a name="syntax"></a>Sintaxe

> **/Zc:trigraphs**[**-**]

## <a name="remarks"></a>Comentários

Um *trígrafo* consiste em dois pontos de interrogação consecutivos ("??") seguido por um terceiro caractere exclusivo. O padrão da linguagem C oferece suporte a trígrafos para arquivos de origem que usam um conjunto de caracteres que não contenha representações gráficas convenientes para alguns caracteres de pontuação. Por exemplo, quando trígrafos são habilitados, o compilador substitui o "?? = "trígrafo usando o caractere '#'. Por meio de c++14, os trígrafos tem suporte como em C. O padrão c++17 remove trígrafos da linguagem C++. No código C++, o **/ZC: trigraphs** opção de compilador habilita a substituição de sequências de trígrafo por caractere de pontuação correspondente. **/ZC:trigraphs-** desabilita a substituição de trígrafos.

O **/ZC: trigraphs** opção está desativada por padrão, e a opção não é afetada quando o [/permissive--](permissive-standards-conformance.md) opção for especificada.

Para obter uma lista de trígrafos C/C++ e um exemplo que mostra como usar trígrafos, consulte [Trígrafos](../../c-language/trigraphs.md).

## <a name="to-set-this-compiler-option-in-the-visual-studio-development-environment"></a>Para definir esta opção do compilador no ambiente de desenvolvimento do Visual Studio

1. Abra a caixa de diálogo **Páginas de Propriedades** do projeto. Para obter detalhes, confira [Trabalhando com propriedades do projeto](../../ide/working-with-project-properties.md).

1. Selecione o **propriedades de configuração** > **C/C++** > **linha de comando** página de propriedades.

1. Modificar a **opções adicionais** propriedade incluir **/ZC: trigraphs** ou **/Zc:trigraphs-** e, em seguida, escolha **Okey**.

## <a name="see-also"></a>Consulte também

[/Zc (conformidade)](../../build/reference/zc-conformance.md)<br/>
[Trígrafos](../../c-language/trigraphs.md)<br/>
