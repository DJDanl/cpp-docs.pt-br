---
title: BSCMAKE aviso BK4504 | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-tools
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords: BK4504
dev_langs: C++
helpviewer_keywords: BK4504
ms.assetid: b56ee2d4-ad44-40f4-98c0-75934ea44a6c
caps.latest.revision: "8"
author: corob-msft
ms.author: corob
manager: ghogen
ms.openlocfilehash: f7f6d854fbd74d9ca05ba6797bbd57db52b7a70e
ms.sourcegitcommit: ebec1d449f2bd98aa851667c2bfeb7e27ce657b2
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/24/2017
---
# <a name="bscmake-warning-bk4504"></a>Aviso BK4504 (BSCMAKE)
arquivo contém muitas referências; Ignorando mais referências desta fonte  
  
 O arquivo. cpp contém mais de 64.000 referências de símbolo. Quando BSCMAKE encontrou 64.000 referências em um arquivo, ele ignora todas as referências adicionais.  
  
 Para corrigir o problema, em Dividir o arquivo em dois ou mais arquivos, cada um deles tem menos de 64.000 referências de símbolo, ou usarem o `#pragma component(browser)` diretiva de pré-processamento para símbolos de limite que são gerados para referências específicas. Para obter mais informações, consulte [componente](../../preprocessor/component.md).