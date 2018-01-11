---
title: C2857 de erro do compilador | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-tools
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords: C2857
dev_langs: C++
helpviewer_keywords: C2857
ms.assetid: b57302bd-58ec-45ae-992a-1e282d5eeccc
caps.latest.revision: "7"
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload: cplusplus
ms.openlocfilehash: c4bf637f0abb5affdb21deb8e081c8b5156afd88
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="compiler-error-c2857"></a>C2857 de erro do compilador
' #include ' instrução especificada com a opção de linha de comando /Ycfilename não foi encontrada no arquivo de origem  
  
 O [/Yc](../../build/reference/yc-create-precompiled-header-file.md) opção especifica o nome de um arquivo de inclusão não está incluído no arquivo de origem que está sendo compilado.  
  
 Esse erro pode ser causado por um `#include` instrução em um bloco de compilação condicional não está compilado.