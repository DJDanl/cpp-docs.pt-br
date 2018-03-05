---
title: "Ligação interna | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-language
ms.tgt_pltfrm: 
ms.topic: article
dev_langs:
- C++
helpviewer_keywords:
- internal linkage
- linkage [C++], internal
ms.assetid: 80be7b51-c930-43db-94d6-4f09a64077bf
caps.latest.revision: 
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: e6ca8a9e9804aa6c14077b023d0014062067f324
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: HT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="internal-linkage"></a>Ligação interna
Se a declaração de um identificador de escopo do arquivo de um objeto ou de uma função contiver o *storage-class-specifier* **static**, o identificador terá vinculação interna. Caso contrário, o identificador terá vinculação externa. Consulte [Classes de armazenamento](../c-language/c-storage-classes.md) para obter uma discussão do *storage-class-specifier* não terminal.  
  
 Em uma unidade de conversão, cada instância de um identificador com vinculação interna denota o mesmo identificador ou a mesma função. Os identificadores vinculados internamente são exclusivos de uma unidade de conversão.  
  
## <a name="see-also"></a>Consulte também  
 [Usando extern para especificar a ligação](../cpp/using-extern-to-specify-linkage.md)