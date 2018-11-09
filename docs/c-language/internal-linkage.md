---
title: Ligação interna
ms.date: 11/04/2016
helpviewer_keywords:
- internal linkage
- linkage [C++], internal
ms.assetid: 80be7b51-c930-43db-94d6-4f09a64077bf
ms.openlocfilehash: 857badd1284378a066c6c19c7159c1535e313593
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: HT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50452360"
---
# <a name="internal-linkage"></a>Ligação interna

Se a declaração de um identificador de escopo do arquivo de um objeto ou de uma função contiver o *storage-class-specifier* **static**, o identificador terá vinculação interna. Caso contrário, o identificador terá vinculação externa. Consulte [Classes de armazenamento](../c-language/c-storage-classes.md) para obter uma discussão do *storage-class-specifier* não terminal.

Em uma unidade de conversão, cada instância de um identificador com vinculação interna denota o mesmo identificador ou a mesma função. Os identificadores vinculados internamente são exclusivos de uma unidade de conversão.

## <a name="see-also"></a>Consulte também

[Usando extern para especificar a ligação](../cpp/using-extern-to-specify-linkage.md)