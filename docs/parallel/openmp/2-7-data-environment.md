---
title: 2.7 ambiente de dados | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-windows
ms.tgt_pltfrm: 
ms.topic: article
dev_langs:
- C++
ms.assetid: 74e44b3c-e18c-4773-8e78-cd6c4413ae57
caps.latest.revision: 
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: e018a2c1b20bef640852ced913dc90266e733c06
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="27-data-environment"></a>2.7 Ambiente de dados
Esta seção apresenta uma diretiva e várias cláusulas para controlar o ambiente de dados durante a execução de regiões paralelas, da seguinte maneira:  
  
-   Um **threadprivate** diretiva (consulte a seção a seguir) é fornecida para tornar o escopo de arquivo, escopo de namespace ou escopo de bloco estático variáveis local a um thread.  
  
-   As cláusulas que podem ser especificadas em diretivas para controlar os atributos de compartilhamento de variáveis para a duração das construções paralelas ou compartilhamento de trabalho são descritas na [seção 2.7.2](../../parallel/openmp/2-7-2-data-sharing-attribute-clauses.md) na página 25.