---
title: Ligação interna
ms.date: 11/04/2016
helpviewer_keywords:
- internal linkage
- linkage [C++], internal
ms.assetid: 80be7b51-c930-43db-94d6-4f09a64077bf
ms.openlocfilehash: 2871ee68b7ae880d6ec5c33ea69eb1bfcc3e284c
ms.sourcegitcommit: a1676bf6caae05ecd698f26ed80c08828722b237
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/29/2020
ms.locfileid: "91509906"
---
# <a name="internal-linkage"></a>Ligação interna

Se a declaração de um identificador de escopo de arquivo para um objeto ou uma função contiver o *especificador de classe de armazenamento* **`static`** , o identificador terá um vínculo interno. Caso contrário, o identificador terá vinculação externa. Consulte [Classes de armazenamento](../c-language/c-storage-classes.md) para obter uma discussão do *storage-class-specifier* não terminal.

Em uma unidade de conversão, cada instância de um identificador com vinculação interna denota o mesmo identificador ou a mesma função. Os identificadores vinculados internamente são exclusivos de uma unidade de conversão.

## <a name="see-also"></a>Consulte também

[Usando extern para especificar a ligação](../cpp/extern-cpp.md)
