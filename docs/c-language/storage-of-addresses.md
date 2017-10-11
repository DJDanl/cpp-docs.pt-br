---
title: "Armazenamento de endereços | Microsoft Docs"
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
- storage [C++], addresses
- addresses [C++], storage of
ms.assetid: 423b2402-b847-4788-ad70-943b7c9c5c8b
caps.latest.revision: 7
author: mikeblome
ms.author: mblome
manager: ghogen
ms.translationtype: HT
ms.sourcegitcommit: 16d1bf59dfd4b3ef5f037aed9c0f6febfdf1a2e8
ms.openlocfilehash: 3d0e996ac191ba3091925a85937e7636a2425215
ms.contentlocale: pt-br
ms.lasthandoff: 10/09/2017

---
# <a name="storage-of-addresses"></a>Armazenamento de endereços
A quantidade de armazenamento necessária para um endereço e o significado do endereço dependem da implementação do compilador. Não há garantia de que ponteiros para tipos diferentes tenham o mesmo tamanho. Portanto, **sizeof(char \*)** não é necessariamente igual a **sizeof(int \*)**.  
  
 **Seção específica da Microsoft**  
  
 Para o compilador Microsoft C, **sizeof(char \*)** é igual a **sizeof(int \*)**.  
  
 **Fim da seção específica da Microsoft**  
  
## <a name="see-also"></a>Consulte também  
 [Declarações de ponteiro](../c-language/pointer-declarations.md)
