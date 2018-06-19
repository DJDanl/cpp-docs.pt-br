---
title: Erro fatal C1852 | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- C1852
dev_langs:
- C++
helpviewer_keywords:
- C1852
ms.assetid: fa011004-b8d6-46f1-ba80-4785e4ce137f
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: d11160eea5e978a0c1ef67255d4e96b48fe2d101
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
ms.locfileid: "33199505"
---
# <a name="fatal-error-c1852"></a>Erro fatal C1852
'filename' não é um arquivo de cabeçalho pré-compilado válido  
  
 O arquivo não é um cabeçalho pré-compilado.  
  
### <a name="to-fix-by-checking-the-following-possible-causes"></a>Para corrigir verificando as possíveis causas a seguir  
  
1.  Arquivo inválido especificado com **/Yu** ou **#pragma hdrstop**.  
  
2.  O compilador assumirá uma extensão de arquivo de. pch se você não especifique o contrário.