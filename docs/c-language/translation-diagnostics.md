---
title: "Translação: diagnóstico | Microsoft Docs"
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
ms.assetid: 3730ca7c-0147-452d-bd4a-6a1e97e9793e
caps.latest.revision: 
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: 10349357fa0411357b702ff48ff9407c1f5b91e7
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: HT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="translation-diagnostics"></a>Translação: diagnóstico
**ANSI 2.1.1.3** Como um diagnóstico é identificado  
  
 O Microsoft C gera mensagens de erro no formato:  
  
```  
  
filename( line-number ) : diagnostic Cnumbermessage  
```  
  
 em que *filename* é o nome do arquivo de origem em que o erro foi encontrado; *line-number* é o número de linha em que o compilador detectou o erro; `diagnostic` é um "erro" ou um "aviso"; `number` é um número exclusivo de quatro dígitos (precedido de **C**, conforme observado na sintaxe) que identifica o erro ou o aviso; `message` é uma mensagem explicativa.  
  
## <a name="see-also"></a>Consulte também  
 [Comportamento definido pela implementação](../c-language/implementation-defined-behavior.md)