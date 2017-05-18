---
title: RC4005 de aviso do compilador de recurso | Documentos do Microsoft
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-tools
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords:
- RC4005
dev_langs:
- C++
helpviewer_keywords:
- RC4005
ms.assetid: 71f03b4a-c9a9-415d-920f-bf2e58507f93
caps.latest.revision: 6
author: corob-msft
ms.author: corob
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
ms.translationtype: Machine Translation
ms.sourcegitcommit: 3168772cbb7e8127523bc2fc2da5cc9b4f59beb8
ms.openlocfilehash: 0822ded31af1de15bb224ca5bfe736e8596f84b1
ms.contentlocale: pt-br
ms.lasthandoff: 02/25/2017

---
# <a name="resource-compiler-warning-rc4005"></a>Aviso RC4005 (compilador de recurso)
'identifier': redefinição de macro  
  
 O identificador está definido duas vezes. O compilador usado da segunda definição de macro.  
  
 Esse aviso pode ser causado por definindo uma macro na linha de comando e no código com um `#define` diretiva. Ele também pode ser causado por macros importadas de arquivos de inclusão.  
  
 Para eliminar o aviso, remova uma das definições ou use um `#undef` diretiva antes da definição de segundo.
