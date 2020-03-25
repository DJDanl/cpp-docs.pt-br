---
title: Erro PRJ0044 (compilação de projeto)
ms.date: 11/04/2016
f1_keywords:
- PRJ0044
helpviewer_keywords:
- PRJ0044
ms.assetid: 5d78c45a-f9e9-4d2b-a3b6-5a5d1421ab84
ms.openlocfilehash: ab2fd5f6562ac85c9c86cafc851315c21cd28da3
ms.sourcegitcommit: 857fa6b530224fa6c18675138043aba9aa0619fb
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/24/2020
ms.locfileid: "80192089"
---
# <a name="project-build-error-prj0044"></a>Erro PRJ0044 (compilação de projeto)

A propriedade ' dependências adicionais ' para a regra de compilação personalizada ' regra ' atribuída ao arquivo ' file ' é inválida. A propriedade continha ' String ', que é avaliada como ' value '.

A propriedade de **dependências adicional** é avaliada como uma cadeia de caracteres vazia ou para uma cadeia de caracteres que contiveva um caractere inválido (qualquer caracter que não pode estar em um nome de arquivo ou diretório). Regras de compilação personalizadas precisam da saída da ação de compilação.

Para obter mais informações, consulte [especificando ferramentas de Build personalizadas](../../build/specifying-custom-build-tools.md).

## <a name="see-also"></a>Confira também

[Erros e avisos de build do projeto (PRJxxxx)](../../error-messages/tool-errors/project-build-errors-and-warnings-prjxxxx.md)
