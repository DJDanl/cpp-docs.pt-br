---
title: RC4005 de aviso do compilador de recurso | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-tools
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords: RC4005
dev_langs: C++
helpviewer_keywords: RC4005
ms.assetid: 71f03b4a-c9a9-415d-920f-bf2e58507f93
caps.latest.revision: "6"
author: corob-msft
ms.author: corob
manager: ghogen
ms.openlocfilehash: 44c7239ffc814c17966bf3777218d3f8d88c9996
ms.sourcegitcommit: ebec1d449f2bd98aa851667c2bfeb7e27ce657b2
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/24/2017
---
# <a name="resource-compiler-warning-rc4005"></a>Aviso RC4005 (compilador de recurso)
'Identificador': redefinição de macro  
  
 O identificador está definido duas vezes. O compilador usado a segunda definição de macro.  
  
 Esse aviso pode ser causado por definindo uma macro na linha de comando e no código com um `#define` diretiva. Ele também pode ser causado por macros importadas de arquivos de inclusão.  
  
 Para eliminar o aviso, remova uma das definições ou use um `#undef` diretiva antes da definição de segundo.