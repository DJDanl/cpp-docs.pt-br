---
title: Erro fatal C1854 | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- devlang-cpp
ms.topic: error-reference
f1_keywords:
- C1854
dev_langs:
- C++
helpviewer_keywords:
- C1854
ms.assetid: 8c21a9cc-1737-475c-9e57-8725cd8937c1
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: e517832720e31bfae88e79ad879f1427b9c25a48
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
---
# <a name="fatal-error-c1854"></a>Erro fatal C1854
  
> não é possível substituir informação formada durante a criação de cabeçalho pré-compilado no arquivo de objeto: '*filename*'  
  
Você especificou o [/Yu (usar pré-compilado arquivo de cabeçalho)](../../build/reference/yu-use-precompiled-header-file.md) opção depois de especificar o [/Yc (criar a arquivo de cabeçalho pré-compilado)](../../build/reference/yc-create-precompiled-header-file.md) opção para o mesmo arquivo.  
  
Para corrigir esse problema, em geral, definir apenas um arquivo em seu projeto para ser compilada usando o **/Yc** opção e definir todos os outros arquivos para compilar usando o **/Yu** opção. Para obter detalhes sobre o uso do **/Yc** opção e como configurá-lo no IDE do Visual Studio, consulte [/Yc (criar a arquivo de cabeçalho pré-compilado)](../../build/reference/yc-create-precompiled-header-file.md). Para obter mais informações sobre o uso de cabeçalhos pré-compilados, consulte [criando arquivos de cabeçalho pré-compilado](../../build/reference/creating-precompiled-header-files.md).  
