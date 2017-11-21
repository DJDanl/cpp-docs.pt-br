---
title: Erro M6108 | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-tools
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords: M6108
dev_langs: C++
helpviewer_keywords: M6108
ms.assetid: 054893b4-49bc-45d9-882f-7cb50ba387c0
caps.latest.revision: "7"
author: corob-msft
ms.author: corob
manager: ghogen
ms.openlocfilehash: 6527a595673fddd9fe320097d093858d1c2c0ca1
ms.sourcegitcommit: ebec1d449f2bd98aa851667c2bfeb7e27ce657b2
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/24/2017
---
# <a name="math-error-m6108"></a>Erro M6108 (Math)
raiz quadrada  
  
 O operando em uma operação de raiz quadrada foi negativo.  
  
 Programa será encerrado com código de saída 136.  
  
> [!NOTE]
>  O `sqrt` função na biblioteca de tempo de execução do C e a função intrínseca FORTRAN **SQRT** não gerar esse erro. C `sqrt` função verifica o argumento antes de executar a operação e retorna um valor de erro se o operando for negativo. O FORTRAN **SQRT** função gera o erro de domínio [M6201](../../error-messages/tool-errors/math-error-m6201.md) em vez desse erro.