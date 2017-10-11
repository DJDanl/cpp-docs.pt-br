---
title: "Ligação externa | Microsoft Docs"
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
- linkage [C++], external
- external linkage, about external linkage
- external linkage
ms.assetid: a6f8ea69-b405-4cdd-bf12-ad5462b73183
caps.latest.revision: 6
author: mikeblome
ms.author: mblome
manager: ghogen
ms.translationtype: HT
ms.sourcegitcommit: 16d1bf59dfd4b3ef5f037aed9c0f6febfdf1a2e8
ms.openlocfilehash: c4a1981d2dd22f9ed8928b1d1daf71612b057e71
ms.contentlocale: pt-br
ms.lasthandoff: 10/09/2017

---
# <a name="external-linkage"></a>Ligação externa
Se a primeira instrução no nível do escopo de arquivo em um identificador não usar o especificador de classe de armazenamento **static**, o objeto tem vínculos externos.  
  
 Se a declaração de um identificador para uma função não tiver um *storage-class-specifier*, a ligação será determinada exatamente como se tivesse sido declarada com o *storage-class-specifier* `extern`. Se a declaração de um identificador para um objeto tiver escopo de arquivo e nenhum *storage-class-specifier*, a ligação será externa.  
  
 O nome de um identificador de vinculação externa designa a mesma função ou o mesmo objeto de dados como qualquer outra declaração para o mesmo nome com vinculação externa. As duas declarações podem estar na mesma unidade de tradução ou em unidades de tradução diferentes. Se o objeto ou a função também tiverem tempo de vida global, o objeto ou a função são compartilhados em todo o programa.  
  
## <a name="see-also"></a>Consulte também  
 [Usando extern para especificar a ligação](../cpp/using-extern-to-specify-linkage.md)
