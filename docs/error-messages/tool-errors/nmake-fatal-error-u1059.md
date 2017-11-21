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
ms.openlocfilehash: 70b1546068678c811f6123d3c8059dfd6d914f4d
ms.sourcegitcommit: ebec1d449f2bd98aa851667c2bfeb7e27ce657b2
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/24/2017
---
# <a name="nmake-fatal-error-u1059"></a>Erro fatal U1059 (NMAKE)
Erro de sintaxe: '}' ausente em dependente  
  
 Um caminho de pesquisa para um dependente foi especificado incorretamente. Ou um espaço existia no caminho ou a chave de fechamento (**}**) foi omitido.  
  
 A sintaxe para uma especificação de diretório para um dependente é  
  
 **{**   
 ***diretórios* } dependentes**  
  
 onde `directories` Especifica um ou mais caminhos, cada um separado por ponto e vírgula (**;**). Não são permitidos espaços.  
  
 Se parte ou todo um caminho de pesquisa é substituído por uma macro, verifique se que existem sem espaços na expansão de macro.