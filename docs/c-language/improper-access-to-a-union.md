---
title: "Acesso inadequado a uma união | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-language
ms.tgt_pltfrm: 
ms.topic: article
dev_langs: C++
ms.assetid: b273d984-62a8-4003-9a87-bf0149d3f2dd
caps.latest.revision: "7"
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload: cplusplus
ms.openlocfilehash: 71fe791e776450d21878144447cf95cdedb34875
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: HT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="improper-access-to-a-union"></a>Acesso inadequado a uma união
**ANSI 3.3.2.3** Um membro de um objeto de união é acessado usando um membro de um tipo diferente  
  
 Se uma união de dois tipos é declarada e um valor é armazenado, mas a união é acessada com o outro tipo, os resultados são não confiáveis.  
  
 Por exemplo, uma união de **float** e `int` é declarada. Um valor **float** é armazenado, mas o programa acessa posteriormente o valor como `int`. Nessa situação, o valor dependeria do armazenamento interno de valores **float**. O valor inteiro não seria confiável.  
  
## <a name="see-also"></a>Consulte também  
 [Estruturas, uniões, enumerações e campos de bit](../c-language/structures-unions-enumerations-and-bit-fields.md)