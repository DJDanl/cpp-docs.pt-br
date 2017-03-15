---
title: C2857 de erro do compilador | Documentos do Microsoft
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords:
- C2857
dev_langs:
- C++
helpviewer_keywords:
- C2857
ms.assetid: b57302bd-58ec-45ae-992a-1e282d5eeccc
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
ms.openlocfilehash: 58862c7251cecf33bc02ddbde64c30183c52a08c
ms.lasthandoff: 02/25/2017

---
# <a name="compiler-error-c2857"></a>C2857 de erro do compilador
' #include ' instrução especificada com a opção de linha de comando /Ycfilename não foi encontrada no arquivo de origem  
  
 O [/Yc](../../build/reference/yc-create-precompiled-header-file.md) opção especifica o nome de um arquivo de inclusão não está incluído no arquivo de origem que está sendo compilado.  
  
 Esse erro pode ser causado por um `#include` instrução em um bloco de compilação condicional não é compilado.
