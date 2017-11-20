---
title: Erro fatal C1013 | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-tools
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords: C1013
dev_langs: C++
helpviewer_keywords: C1013
ms.assetid: 5514a679-efe7-4055-bdd3-5693ca0c332f
caps.latest.revision: "6"
author: corob-msft
ms.author: corob
manager: ghogen
ms.openlocfilehash: 72196927de45c639b8aea7e26bb721c57b6d7c1d
ms.sourcegitcommit: ebec1d449f2bd98aa851667c2bfeb7e27ce657b2
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/24/2017
---
# <a name="fatal-error-c1013"></a>Erro fatal C1013
limite do compilador: muitos parênteses abertos  
  
 Uma expressão contém muitos níveis de parênteses em uma única expressão. Simplifique a expressão ou dividi-la em várias instruções.  
  
 Antes do Visual C++ 6.0 Service Pack 3, o limite de parênteses aninhados em uma única expressão foi 59. Atualmente, o limite de parênteses aninhados é 256.