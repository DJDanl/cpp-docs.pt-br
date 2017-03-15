---
title: Erro Fatal de CVTRES CVT1100 | Documentos do Microsoft
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords:
- CVT1100
dev_langs:
- C++
helpviewer_keywords:
- CVT1100
ms.assetid: 886e88dd-5818-4b5f-84f2-d2a3d75f0aaf
caps.latest.revision: 7
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
ms.openlocfilehash: d1555bf91d8b3dc14ace4597919737024a0183d4
ms.lasthandoff: 02/25/2017

---
# <a name="cvtres-fatal-error-cvt1100"></a>Erro fatal CVT1100 (CVTRES)
Duplicar recursos —: tipo, nome: nome, linguagem:, sinalizadores: sinalizadores, tamanho:  
  
 O recurso fornecido foi especificado mais de uma vez.  
  
 Este erro pode ocorrer se o vinculador está criando uma biblioteca de tipos e você não especificar [/TLBID](../../build/reference/tlbid-specify-resource-id-for-typelib.md) e um recurso em seu projeto já usa 1. Nesse caso, especifique /TLBID e outro número até 65535.
