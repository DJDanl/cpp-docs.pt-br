---
title: NMAKE aviso U4004 | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- U4004
dev_langs:
- C++
helpviewer_keywords:
- U4004
ms.assetid: 5086bbcb-42d7-4677-a877-1a02202a86a2
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 532abf2f62616d6e748c9a4e34f5c983f0853276
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
---
# <a name="nmake-warning-u4004"></a>Aviso U4004 (NMAKE)
muitas regras para targetname' destino'  
  
 Mais de um bloco de descrição foi especificado para o determinado destino usando dois-pontos único (**:**) como separadores. NMAKE executado os comandos no primeiro bloco de descrição e ignorado blocos posteriores.  
  
 Para especificar o mesmo destino em várias dependências, use dois-pontos duplo (`::`) como o separador em cada linha de dependência.