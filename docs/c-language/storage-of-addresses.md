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
translation.priority.ht:
- cs-cz
- de-de
- es-es
- fr-fr
- it-it
- ja-jp
- ko-kr
- pl-pl
- pt-br
- ru-ru
- tr-tr
- zh-cn
- zh-tw
ms.translationtype: Human Translation
ms.sourcegitcommit: a937c9d083a7e4331af63323a19fb207142604a0
ms.openlocfilehash: 78ed46fc8412f351d46d3a2b4c37348382d7aaa5
ms.contentlocale: pt-br
ms.lasthandoff: 02/25/2017

---
# <a name="storage-of-addresses"></a>Armazenamento de endereços
A quantidade de armazenamento necessária para um endereço e o significado do endereço dependem da implementação do compilador. Não há garantia de que ponteiros para tipos diferentes tenham o mesmo tamanho. Portanto, **sizeof(char \*)** não é necessariamente igual a **sizeof(int \*)**.  
  
 **Seção específica da Microsoft**  
  
 Para o compilador Microsoft C, **sizeof(char \*)** é igual a **sizeof(int \*)**.  
  
 **Fim da seção específica da Microsoft**  
  
## <a name="see-also"></a>Consulte também  
 [Declarações de ponteiro](../c-language/pointer-declarations.md)
