---
title: C2857 de erro do compilador | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-tools
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
ms.translationtype: MT
ms.sourcegitcommit: 35b46e23aeb5f4dbfd2a0dd44b906389dd5bfc88
ms.openlocfilehash: ca0f2b8847600096c9e39de24c58e6a0021fa83f
ms.contentlocale: pt-br
ms.lasthandoff: 10/10/2017

---
# <a name="compiler-error-c2857"></a>C2857 de erro do compilador
' #include ' instrução especificada com a opção de linha de comando /Ycfilename não foi encontrada no arquivo de origem  
  
 O [/Yc](../../build/reference/yc-create-precompiled-header-file.md) opção especifica o nome de um arquivo de inclusão não está incluído no arquivo de origem que está sendo compilado.  
  
 Esse erro pode ser causado por um `#include` instrução em um bloco de compilação condicional não está compilado.
