---
title: Naked | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-language
ms.tgt_pltfrm: 
ms.topic: article
dev_langs: C++
helpviewer_keywords:
- naked keyword [C], storage-class attribute
- naked keyword [C]
- prolog code
- epilog code
ms.assetid: 23b1209b-93ba-46ad-a60f-2327c1933eaf
caps.latest.revision: "8"
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload: cplusplus
ms.openlocfilehash: 474cb57ced17088c0ce9be8613a9373c702afe69
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: HT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="naked-c"></a>Naked (C)
**Seção específica da Microsoft**  
  
 O atributo de classe de armazenamento naked é uma extensão específica da Microsoft na linguagem C. O compilador gera um código sem código de prólogo e de epílogo para funções declaradas com o atributo de classe de armazenamento naked. As funções naked são úteis quando você precisa escrever suas próprias sequências de código de prólogo/epílogo usando o código de assembler embutido. As funções naked são úteis para escrever drivers para dispositivo virtuais.  
  
 Para obter informações específicas sobre como usar o atributo naked, consulte [Funções naked](../c-language/naked-functions.md).  
  
 **Fim da seção específica da Microsoft**  
  
## <a name="see-also"></a>Consulte também  
 [Atributos de classe de armazenamento estendido C](../c-language/c-extended-storage-class-attributes.md)