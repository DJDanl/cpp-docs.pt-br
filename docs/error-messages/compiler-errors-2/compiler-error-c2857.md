---
title: C2857 de erro do compilador | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- C2857
dev_langs:
- C++
helpviewer_keywords:
- C2857
ms.assetid: b57302bd-58ec-45ae-992a-1e282d5eeccc
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 4bb2ec5047646bea420bf109f18a72d87a8f7c44
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
---
# <a name="compiler-error-c2857"></a>C2857 de erro do compilador
' #include ' instrução especificada com a opção de linha de comando /Ycfilename não foi encontrada no arquivo de origem  
  
 O [/Yc](../../build/reference/yc-create-precompiled-header-file.md) opção especifica o nome de um arquivo de inclusão não está incluído no arquivo de origem que está sendo compilado.  
  
 Esse erro pode ser causado por um `#include` instrução em um bloco de compilação condicional não está compilado.