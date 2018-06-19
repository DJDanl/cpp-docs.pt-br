---
title: 2.7 ambiente de dados | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-parallel
ms.topic: conceptual
dev_langs:
- C++
ms.assetid: 74e44b3c-e18c-4773-8e78-cd6c4413ae57
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: d1b0f253ce14ffc5d3740e582a9a51feea56ad32
ms.sourcegitcommit: 7019081488f68abdd5b2935a3b36e2a5e8c571f8
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/07/2018
ms.locfileid: "33690059"
---
# <a name="27-data-environment"></a>2.7 Ambiente de dados
Esta seção apresenta uma diretiva e várias cláusulas para controlar o ambiente de dados durante a execução de regiões paralelas, da seguinte maneira:  
  
-   Um **threadprivate** diretiva (consulte a seção a seguir) é fornecida para tornar o escopo de arquivo, escopo de namespace ou escopo de bloco estático variáveis local a um thread.  
  
-   As cláusulas que podem ser especificadas em diretivas para controlar os atributos de compartilhamento de variáveis para a duração das construções paralelas ou compartilhamento de trabalho são descritas na [seção 2.7.2](../../parallel/openmp/2-7-2-data-sharing-attribute-clauses.md) na página 25.