---
title: NMAKE Erro Fatal U1035 | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-tools
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords: U1035
dev_langs: C++
helpviewer_keywords: U1035
ms.assetid: 68f0cc59-007e-4109-ac30-7ac4ac447e6d
caps.latest.revision: "6"
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload: cplusplus
ms.openlocfilehash: 0d7730f882b40c24822cb4b8e2c6a12147cacf2d
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="nmake-fatal-error-u1035"></a>Erro fatal U1035 (NMAKE)
Erro de sintaxe: esperado ':' ou '=' separador  
  
 Qualquer um dos dois-pontos (**:**) ou um sinal de igual (**=**) era esperado.  
  
### <a name="to-fix-by-checking-the-following-possible-causes"></a>Para corrigir verificando as possíveis causas a seguir  
  
1.  Dois-pontos não seguem um destino.  
  
2.  Dois-pontos e nenhum espaço (por exemplo, r:) seguida de um única letra destino. NMAKE interpretado-lo como uma especificação de unidade.  
  
3.  Dois-pontos não seguem uma regra de inferência de tipos.  
  
4.  Uma definição de macro não foi seguida por um sinal de igual.  
  
5.  Um caractere seguido de uma barra invertida (**\\**) que foi usado para continuar a um comando para uma nova linha.  
  
6.  Uma cadeia de caracteres apareceu que não tenha seguido a qualquer regra de sintaxe NMAKE.  
  
7.  Makefile foi formatado por um processador de texto.