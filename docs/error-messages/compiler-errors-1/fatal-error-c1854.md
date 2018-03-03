---
title: Erro fatal C1854 | Microsoft Docs
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
caps.latest.revision: 
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: 0e0a26e902b1a40203bb4323bce8e28e687e9647
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="fatal-error-c1854"></a>Erro fatal C1854
  
> não é possível substituir informação formada durante a criação de cabeçalho pré-compilado no arquivo de objeto: '*filename*'  
  
Você especificou o [/Yu (usar pré-compilado arquivo de cabeçalho)](../../build/reference/yu-use-precompiled-header-file.md) opção depois de especificar o [/Yc (criar a arquivo de cabeçalho pré-compilado)](../../build/reference/yc-create-precompiled-header-file.md) opção para o mesmo arquivo.  
  
Para corrigir esse problema, em geral, definir apenas um arquivo em seu projeto para ser compilada usando o **/Yc** opção e definir todos os outros arquivos para compilar usando o **/Yu** opção. Para obter detalhes sobre o uso do **/Yc** opção e como configurá-lo no IDE do Visual Studio, consulte [/Yc (criar a arquivo de cabeçalho pré-compilado)](../../build/reference/yc-create-precompiled-header-file.md). Para obter mais informações sobre o uso de cabeçalhos pré-compilados, consulte [criando arquivos de cabeçalho pré-compilado](../../build/reference/creating-precompiled-header-files.md).  
