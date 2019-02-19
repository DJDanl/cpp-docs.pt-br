---
title: Sem ligação
ms.date: 11/04/2016
helpviewer_keywords:
- no linkage
- linkage [C++], none
ms.assetid: 5a413082-1034-4e04-b76b-8d14668bf434
ms.openlocfilehash: c80cb814145ac986864fe351e664d8472f3bf880
ms.sourcegitcommit: f4be868c0d1d78e550fba105d4d3c993743a1f4b
ms.translationtype: HT
ms.contentlocale: pt-BR
ms.lasthandoff: 02/12/2019
ms.locfileid: "56152840"
---
# <a name="no-linkage"></a>Sem ligação

Se uma declaração de um identificador em um bloco não inclui o especificador de classe de armazenamento `extern`, o identificador não tem nenhuma vinculação e é exclusivo à função.

Os seguintes identificadores não têm nenhuma vinculação:

- Um identificador declarado como qualquer coisa que não seja um objeto ou uma função

- Um identificador declarado como um parâmetro de função

- Um identificador de escopo de bloco referente a um objeto declarado sem o especificador de classe de armazenamento `extern`

Se um identificador não tem nenhuma vinculação, declarar o mesmo nome novamente (em um declarador ou especificador de tipo) no mesmo nível de escopo gera um erro de redefinição de símbolo.

## <a name="see-also"></a>Consulte também

[Usando extern para especificar a ligação](../cpp/using-extern-to-specify-linkage.md)
