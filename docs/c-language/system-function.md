---
title: "Função system | Microsoft Docs"
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
- system function
ms.assetid: 0786ccdc-20cd-4d96-b3d8-3230507c3066
caps.latest.revision: 7
author: mikeblome
ms.author: mblome
manager: ghogen
ms.translationtype: HT
ms.sourcegitcommit: 16d1bf59dfd4b3ef5f037aed9c0f6febfdf1a2e8
ms.openlocfilehash: 965cca807ddbe9f0eb31144f75a7e3c6e4a80e77
ms.contentlocale: pt-br
ms.lasthandoff: 10/09/2017

---
# <a name="system-function"></a>Função system
**ANSI 4.10.4.5** O conteúdo e o modo de execução de cadeia de caracteres pela função **system**  
  
 A função **system** executa um comando interno do sistema operacional ou um arquivo .EXE, .COM (.CMD no Windows NT) ou .BAT em um programa C em vez da linha de comando.  
  
 A função system localiza o interpretador de comandos, que normalmente é CMD.EXE no sistema operacional Windows NT ou em COMMAND.COM no Windows. A função system passará a cadeia de caracteres do argumento ao interpretador de comandos.  
  
 Para obter mais informações, consulte [system, _wsystem](../c-runtime-library/reference/system-wsystem.md).  
  
## <a name="see-also"></a>Consulte também  
 [Funções de biblioteca](../c-language/library-functions.md)
