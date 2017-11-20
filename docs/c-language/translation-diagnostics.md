---
title: "Translação: diagnóstico | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-language
ms.tgt_pltfrm: 
ms.topic: article
dev_langs: C++
ms.assetid: 3730ca7c-0147-452d-bd4a-6a1e97e9793e
caps.latest.revision: "6"
author: mikeblome
ms.author: mblome
manager: ghogen
ms.openlocfilehash: bb7f826be88ebec640a6f3b40b38478eea91ed36
ms.sourcegitcommit: ebec1d449f2bd98aa851667c2bfeb7e27ce657b2
ms.translationtype: HT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/24/2017
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