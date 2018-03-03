---
title: "Compilador (nível 1) de aviso C4041 | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-tools
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords:
- C4041
dev_langs:
- C++
helpviewer_keywords:
- C4041
ms.assetid: 107ee9fd-4b88-4f22-a18f-a20726831095
caps.latest.revision: 
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: 42779d33cad8fc867b08b412d2ded294360a0812
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="compiler-warning-level-1-c4041"></a>Compilador C4041 de aviso (nível 1)
limite do compilador: saída do navegador de terminação  
  
 Informações sobre o navegador excedeu o limite do compilador.  
  
 Esse aviso pode ser causado por compilar com [/FR](../../build/reference/fr-fr-create-dot-sbr-file.md) (incluindo variáveis locais informações do navegador).  
  
### <a name="to-fix-by-using-the-following-possible-solutions"></a>Para corrigir usando as seguintes soluções possíveis  
  
1.  Compile com /Fr (informações do navegador sem variáveis locais).  
  
2.  Desabilite a saída do navegador (compilar sem /FR ou /Fr).