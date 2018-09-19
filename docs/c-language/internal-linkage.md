---
title: Ligação interna | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-language
ms.topic: language-reference
dev_langs:
- C++
helpviewer_keywords:
- internal linkage
- linkage [C++], internal
ms.assetid: 80be7b51-c930-43db-94d6-4f09a64077bf
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 09b5a02b7892bff0233e37bbd63020a4d2904ec3
ms.sourcegitcommit: 913c3bf23937b64b90ac05181fdff3df947d9f1c
ms.translationtype: HT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/18/2018
ms.locfileid: "46094202"
---
# <a name="internal-linkage"></a>Ligação interna

Se a declaração de um identificador de escopo do arquivo de um objeto ou de uma função contiver o *storage-class-specifier* **static**, o identificador terá vinculação interna. Caso contrário, o identificador terá vinculação externa. Consulte [Classes de armazenamento](../c-language/c-storage-classes.md) para obter uma discussão do *storage-class-specifier* não terminal.

Em uma unidade de conversão, cada instância de um identificador com vinculação interna denota o mesmo identificador ou a mesma função. Os identificadores vinculados internamente são exclusivos de uma unidade de conversão.

## <a name="see-also"></a>Consulte também

[Usando extern para especificar a ligação](../cpp/using-extern-to-specify-linkage.md)