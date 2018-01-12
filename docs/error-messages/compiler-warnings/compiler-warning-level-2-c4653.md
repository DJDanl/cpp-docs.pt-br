---
title: "Compilador (nível 2) do aviso C4653 | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-tools
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords: C4653
dev_langs: C++
helpviewer_keywords: C4653
ms.assetid: 90ec3317-3d39-4b4c-bcd1-97e7c799e1b6
caps.latest.revision: "7"
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload: cplusplus
ms.openlocfilehash: 8eb855e1c11136cd88c1c1e796d9759581e3ceb3
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="compiler-warning-level-2-c4653"></a>Compilador C4653 de aviso (nível 2)
opção de compilador 'option' inconsistente com cabeçalho pré-compilado; opção de linha de comando atual ignorada  
  
 Uma opção especificada com a usar cabeçalhos pré-compilados ([/Yu](../../build/reference/yu-use-precompiled-header-file.md)) opção estava inconsistente com as opções especificadas quando o cabeçalho pré-compilado foi criado. Esta compilação usado a opção especificada quando o cabeçalho pré-compilado foi criado.  
  
 Esse aviso pode ocorrer quando um valor diferente para a opção de estruturas de pacote ([/Zp](../../build/reference/zp-struct-member-alignment.md)) foi especificado durante a compilação do cabeçalho pré-compilado.