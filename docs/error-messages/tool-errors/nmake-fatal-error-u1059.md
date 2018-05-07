---
title: NMAKE Erro Fatal U1059 | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- U1059
dev_langs:
- C++
helpviewer_keywords:
- U1059
ms.assetid: b21d9198-9c63-40d0-b589-80e17294ce24
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 6eb038befdb7c587c6fe2a734003abba585c3e2a
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
---
# <a name="nmake-fatal-error-u1059"></a>Erro fatal U1059 (NMAKE)
Erro de sintaxe: '}' ausente em dependente  
  
 Um caminho de pesquisa para um dependente foi especificado incorretamente. Ou um espaço existia no caminho ou a chave de fechamento (**}**) foi omitido.  
  
 A sintaxe para uma especificação de diretório para um dependente é  
  
 **{**   
 ***diretórios* } dependentes**  
  
 onde `directories` Especifica um ou mais caminhos, cada um separado por ponto e vírgula (**;**). Não são permitidos espaços.  
  
 Se parte ou todo um caminho de pesquisa é substituído por uma macro, verifique se que existem sem espaços na expansão de macro.