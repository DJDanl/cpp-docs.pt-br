---
title: Compilador (nível 2) do aviso C4653 | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- C4653
dev_langs:
- C++
helpviewer_keywords:
- C4653
ms.assetid: 90ec3317-3d39-4b4c-bcd1-97e7c799e1b6
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: c312b7530fa11bb734dc99a872b36e926890f658
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
---
# <a name="compiler-warning-level-2-c4653"></a>Compilador C4653 de aviso (nível 2)
opção de compilador 'option' inconsistente com cabeçalho pré-compilado; opção de linha de comando atual ignorada  
  
 Uma opção especificada com a usar cabeçalhos pré-compilados ([/Yu](../../build/reference/yu-use-precompiled-header-file.md)) opção estava inconsistente com as opções especificadas quando o cabeçalho pré-compilado foi criado. Esta compilação usado a opção especificada quando o cabeçalho pré-compilado foi criado.  
  
 Esse aviso pode ocorrer quando um valor diferente para a opção de estruturas de pacote ([/Zp](../../build/reference/zp-struct-member-alignment.md)) foi especificado durante a compilação do cabeçalho pré-compilado.