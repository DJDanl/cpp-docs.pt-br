---
title: Sem ligação
ms.date: 11/04/2016
helpviewer_keywords:
- no linkage
- linkage [C++], none
ms.assetid: 5a413082-1034-4e04-b76b-8d14668bf434
ms.openlocfilehash: a7c9a5b8f0ba92830500e55818093981a044d2df
ms.sourcegitcommit: 1f009ab0f2cc4a177f2d1353d5a38f164612bdb1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/27/2020
ms.locfileid: "87218800"
---
# <a name="no-linkage"></a>Sem ligação

Se uma declaração de um identificador dentro de um bloco não incluir o **`extern`** especificador de classe de armazenamento, o identificador não terá nenhum vínculo e será exclusivo para a função.

Os seguintes identificadores não têm nenhuma vinculação:

- Um identificador declarado como qualquer coisa que não seja um objeto ou uma função

- Um identificador declarado como um parâmetro de função

- Um identificador de escopo de bloco para um objeto declarado sem o **`extern`** especificador de classe de armazenamento

Se um identificador não tem nenhuma vinculação, declarar o mesmo nome novamente (em um declarador ou especificador de tipo) no mesmo nível de escopo gera um erro de redefinição de símbolo.

## <a name="see-also"></a>Confira também

[Usando extern para especificar a ligação](../cpp/using-extern-to-specify-linkage.md)
