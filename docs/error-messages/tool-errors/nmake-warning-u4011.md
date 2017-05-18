---
title: NMAKE aviso U4011 | Documentos do Microsoft
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-tools
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords:
- U4011
dev_langs:
- C++
helpviewer_keywords:
- U4011
ms.assetid: e8244514-eba6-4285-8853-7baeefdcd8a4
caps.latest.revision: 7
author: corob-msft
ms.author: corob
manager: ghogen
translation.priority.ht:
- cs-cz
- de-de
- es-es
- fr-fr
- it-it
- ja-jp
- ko-kr
- pl-pl
- pt-br
- ru-ru
- tr-tr
- zh-cn
- zh-tw
ms.translationtype: Machine Translation
ms.sourcegitcommit: 3168772cbb7e8127523bc2fc2da5cc9b4f59beb8
ms.openlocfilehash: ffdb5677fdd50f4b61a9a2dd8c81972a713c57bc
ms.contentlocale: pt-br
ms.lasthandoff: 02/25/2017

---
# <a name="nmake-warning-u4011"></a>Aviso U4011 (NMAKE)
'target': nem todos os dependentes disponíveis; destino não compilado  
  
 Um dependente do destino especificado não existe ou foi desatualizado e um comando para atualizar o dependente retornou um código de saída diferente de zero. A opção /K disse NMAKE para continuar processando partes relacionadas de compilação e emita um código de saída 1 quando a sessão NMAKE for concluída.  
  
 Esse aviso é precedido por aviso [U4010](../../error-messages/tool-errors/nmake-warning-u4010.md) para cada dependente que falhou ao ser criado ou atualizado.
