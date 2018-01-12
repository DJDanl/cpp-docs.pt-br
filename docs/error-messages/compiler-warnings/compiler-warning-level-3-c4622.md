---
title: "Compilador aviso (nível 3) C4622 | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-tools
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords: C4622
dev_langs: C++
helpviewer_keywords: C4622
ms.assetid: d3c879f0-4492-4f4b-b26d-230993f3a933
caps.latest.revision: "7"
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload: cplusplus
ms.openlocfilehash: 52f4491d26cfa56f48ed479b30daeafe9cc01adf
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="compiler-warning-level-3-c4622"></a>Compilador C4622 de aviso (nível 3)
substituindo informação de depuração formada durante a criação do cabeçalho pré-compilado no arquivo de objeto: 'file'  
  
 Informações do CodeView no arquivo especificado eram perdidas quando ele foi compilado com o [/Yu](../../build/reference/yu-use-precompiled-header-file.md) opção (usar cabeçalhos pré-compilados).  
  
 Renomeie o arquivo de objeto (usando [/Fo](../../build/reference/fo-object-file-name.md)) ao criar ou usando o cabeçalho pré-compilado de arquivo e vincular a usar o novo arquivo de objeto.