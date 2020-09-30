---
title: Sem ligação
ms.date: 11/04/2016
helpviewer_keywords:
- no linkage
- linkage [C++], none
ms.assetid: 5a413082-1034-4e04-b76b-8d14668bf434
ms.openlocfilehash: 69ead5d12d6689370e9ae04a54d5f5a8db06eca5
ms.sourcegitcommit: a1676bf6caae05ecd698f26ed80c08828722b237
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/29/2020
ms.locfileid: "91500748"
---
# <a name="no-linkage"></a>Sem ligação

Se uma declaração de um identificador dentro de um bloco não incluir o **`extern`** especificador de classe de armazenamento, o identificador não terá nenhum vínculo e será exclusivo para a função.

Os seguintes identificadores não têm nenhuma vinculação:

- Um identificador declarado como qualquer coisa que não seja um objeto ou uma função

- Um identificador declarado como um parâmetro de função

- Um identificador de escopo de bloco para um objeto declarado sem o **`extern`** especificador de classe de armazenamento

Se um identificador não tem nenhuma vinculação, declarar o mesmo nome novamente (em um declarador ou especificador de tipo) no mesmo nível de escopo gera um erro de redefinição de símbolo.

## <a name="see-also"></a>Consulte também

[Usando extern para especificar a ligação](../cpp/extern-cpp.md)
