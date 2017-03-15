---
title: Erro fatal C1382 | Documentos do Microsoft
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords:
- C1382
dev_langs:
- C++
helpviewer_keywords:
- C1382
ms.assetid: 7a100f8c-3179-4927-a2f1-98de4c753850
caps.latest.revision: 9
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
ms.openlocfilehash: 4ac537178a2723413454f9a6055ed1d6dfb81c5c
ms.lasthandoff: 02/25/2017

---
# <a name="fatal-error-c1382"></a>Erro fatal C1382
o arquivo PCH 'file' foi recriado como 'obj' foi gerada. Recompile esse objeto  
  
 Ao usar [/LTCG](../../build/reference/ltcg-link-time-code-generation.md), o compilador detectou um arquivo. pch mais recente que um. CIL obj que aponta para ele. As informações no arquivo. obj CIL estão desatualizadas. Recrie o objeto.  
  
 C1382 também pode ocorrer se você compilar com **/Yc**, mas também passar fonte vários arquivos de código para o compilador.  Para resolver, não use **/Yc** ao passar fonte vários arquivos de código para o compilador.  Para obter mais informações, consulte [/Yc (criar a arquivo de cabeçalho pré-compilado)](../../build/reference/yc-create-precompiled-header-file.md).
