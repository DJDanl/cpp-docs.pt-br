---
title: 'Translação: diagnóstico | Microsoft Docs'
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-language
ms.topic: language-reference
dev_langs:
- C++
ms.assetid: 3730ca7c-0147-452d-bd4a-6a1e97e9793e
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 1c6a59abc48e5a6bc2aa727508b61abe120c8425
ms.sourcegitcommit: be2a7679c2bd80968204dee03d13ca961eaa31ff
ms.translationtype: HT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/03/2018
ms.locfileid: "32385147"
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