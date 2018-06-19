---
title: RC4005 de aviso do compilador de recurso | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- RC4005
dev_langs:
- C++
helpviewer_keywords:
- RC4005
ms.assetid: 71f03b4a-c9a9-415d-920f-bf2e58507f93
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 724764e443d4ab999c1df1247e9f5572ebdb2078
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
ms.locfileid: "33322478"
---
# <a name="resource-compiler-warning-rc4005"></a>Aviso RC4005 (compilador de recurso)
'Identificador': redefinição de macro  
  
 O identificador está definido duas vezes. O compilador usado a segunda definição de macro.  
  
 Esse aviso pode ser causado por definindo uma macro na linha de comando e no código com um `#define` diretiva. Ele também pode ser causado por macros importadas de arquivos de inclusão.  
  
 Para eliminar o aviso, remova uma das definições ou use um `#undef` diretiva antes da definição de segundo.