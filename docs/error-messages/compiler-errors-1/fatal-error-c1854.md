---
title: Erro fatal C1854 | Documentos do Microsoft
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords:
- C1854
dev_langs:
- C++
helpviewer_keywords:
- C1854
ms.assetid: 8c21a9cc-1737-475c-9e57-8725cd8937c1
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
translationtype: Machine Translation
ms.sourcegitcommit: 3168772cbb7e8127523bc2fc2da5cc9b4f59beb8
ms.openlocfilehash: 7c1f3add044c68a749ee01843a6de3a5398f351e
ms.lasthandoff: 02/25/2017

---
# <a name="fatal-error-c1854"></a>Erro fatal C1854
não é possível substituir informações formadas durante a criação do cabeçalho pré-compilado no arquivo de objeto: 'filename'  
  
 Você especificou o **/Yu** opção (use o cabeçalho pré-compilado) depois de especificar o **/Yc** (criar cabeçalho pré-compilado) opção para o mesmo arquivo. Determinadas declarações (como declarações incluindo `__declspec` `dllexport`) faça isso inválido.
