---
title: "Erros de posição do arquivo | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-language
ms.tgt_pltfrm: 
ms.topic: article
dev_langs: C++
helpviewer_keywords: file pointers [C++], file position errors
ms.assetid: d5e59d8b-08c0-4927-a338-0b2d8234ce24
caps.latest.revision: "6"
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload: cplusplus
ms.openlocfilehash: fc55622f724a903c94fe49a935b906d2826297ea
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: HT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="file-position-errors"></a>Erros de posição do arquivo
**ANSI 4.9.9.1, 4.9.9.4** O valor para o qual a macro `errno` é definida pela função `fgetpos` ou `ftell` em caso de falha  
  
 Quando `fgetpos` ou `ftell` falha, `errno` é definido como a contaste de manifesto `EINVAL` se a posição for inválida ou EBADF, se o número do arquivo estiver incorreto. As constantes também são definidas em ERRNO.H.  
  
## <a name="see-also"></a>Consulte também  
 [Funções de biblioteca](../c-language/library-functions.md)