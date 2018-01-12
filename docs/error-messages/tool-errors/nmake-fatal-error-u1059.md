---
title: NMAKE Erro Fatal U1059 | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-tools
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords: U1059
dev_langs: C++
helpviewer_keywords: U1059
ms.assetid: b21d9198-9c63-40d0-b589-80e17294ce24
caps.latest.revision: "6"
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload: cplusplus
ms.openlocfilehash: fb9ba98b0f82c158e4e11859e85af72efdbbc244
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="nmake-fatal-error-u1059"></a>Erro fatal U1059 (NMAKE)
Erro de sintaxe: '}' ausente em dependente  
  
 Um caminho de pesquisa para um dependente foi especificado incorretamente. Ou um espaço existia no caminho ou a chave de fechamento (**}**) foi omitido.  
  
 A sintaxe para uma especificação de diretório para um dependente é  
  
 **{**   
 ***diretórios* } dependentes**  
  
 onde `directories` Especifica um ou mais caminhos, cada um separado por ponto e vírgula (**;**). Não são permitidos espaços.  
  
 Se parte ou todo um caminho de pesquisa é substituído por uma macro, verifique se que existem sem espaços na expansão de macro.