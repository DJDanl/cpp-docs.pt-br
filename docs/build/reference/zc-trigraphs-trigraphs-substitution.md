---
title: "/ZC: trigraphs (substituição de trígrafos) | Microsoft Docs"
ms.custom: 
ms.date: 03/06/2018
ms.technology:
- cpp-tools
ms.topic: article
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
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: 5fdc5fc6432335e964a05185b7647b152a57d8f4
ms.sourcegitcommit: eeb2b5ad8d3d22514a7b9bd7d756511b69ae0ccf
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/15/2018
---
# <a name="zctrigraphs-trigraphs-substitution"></a>/Zc:trigraphs (substituição de trígrafos)

Quando **/ZC: trigraphs** for especificado, o compilador substitui uma sequência de caracteres trigraph usando um caractere de pontuação correspondente.

## <a name="syntax"></a>Sintaxe

> **/Zc:trigraphs**[**-**]  

## <a name="remarks"></a>Comentários

Um *trigraph* consiste em dois consecutivas de pontos de interrogação ("?") seguido por um terceiro caractere exclusivo. A padrão de linguagem C oferece suporte a trígrafos para arquivos de origem que usam um conjunto de caracteres que não contém representações gráficas convenientes para alguns caracteres de pontuação. Por exemplo, quando trígrafos estão habilitados, o compilador substitui o "? = "trigraph usando o caractere '#'. Por meio de C++ 14, trígrafos têm suporte em C. O padrão C++ 17 remove trígrafos a linguagem C++. No código C++, o **/ZC: trigraphs** opção de compilador permite a substituição das sequências de trigraph pelo caractere de pontuação correspondente. **/ZC:trigraphs-** desabilita a substituição de trigraph.

O **/ZC: trigraphs** opção está desativada por padrão, e a opção não é afetada quando o [/ permissivo-](permissive-standards-conformance.md) opção é especificada.

Para obter uma lista de trígrafos C/C++ e um exemplo que mostra como usar trígrafos, consulte [Trígrafos](../../c-language/trigraphs.md).

## <a name="to-set-this-compiler-option-in-the-visual-studio-development-environment"></a>Para definir esta opção do compilador no ambiente de desenvolvimento do Visual Studio

1. Abra a caixa de diálogo **Páginas de Propriedades** do projeto. Para obter detalhes, consulte [trabalhar com propriedades do projeto](../../ide/working-with-project-properties.md).

1. Selecione o **propriedades de configuração** > **C/C++** > **linha de comando** página de propriedades.

1. Modificar o **opções adicionais** propriedade incluir **/ZC: trigraphs** ou **/Zc:trigraphs-** e, em seguida, escolha **Okey**.

## <a name="see-also"></a>Consulte também

[/Zc (conformidade)](../../build/reference/zc-conformance.md)<br/>
[Trígrafos](../../c-language/trigraphs.md)<br/>
