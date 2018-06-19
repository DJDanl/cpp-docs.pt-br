---
title: Compilador (nível 1) de aviso C4041 | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- C4041
dev_langs:
- C++
helpviewer_keywords:
- C4041
ms.assetid: 107ee9fd-4b88-4f22-a18f-a20726831095
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: dfd8c933522e523329c41ebe666a5a7e3c198cb0
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
ms.locfileid: "33286091"
---
# <a name="compiler-warning-level-1-c4041"></a>Compilador C4041 de aviso (nível 1)
limite do compilador: saída do navegador de terminação  
  
 Informações sobre o navegador excedeu o limite do compilador.  
  
 Esse aviso pode ser causado por compilar com [/FR](../../build/reference/fr-fr-create-dot-sbr-file.md) (incluindo variáveis locais informações do navegador).  
  
### <a name="to-fix-by-using-the-following-possible-solutions"></a>Para corrigir usando as seguintes soluções possíveis  
  
1.  Compile com /Fr (informações do navegador sem variáveis locais).  
  
2.  Desabilite a saída do navegador (compilar sem /FR ou /Fr).