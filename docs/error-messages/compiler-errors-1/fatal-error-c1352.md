---
title: Erro fatal C1352 | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-tools
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords: C1352
dev_langs: C++
helpviewer_keywords: C1352
ms.assetid: d044e8b0-b6ef-4d57-8eb5-6254071be707
caps.latest.revision: "7"
author: corob-msft
ms.author: corob
manager: ghogen
ms.openlocfilehash: 71f2bf8ef42896447d48c9cb3581006c2e3d7620
ms.sourcegitcommit: ebec1d449f2bd98aa851667c2bfeb7e27ce657b2
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/24/2017
---
# <a name="fatal-error-c1352"></a>Erro fatal C1352
MSIL inválido ou corrompido na função 'function' do módulo 'file'  
  
 Um. netmodule foi passado para o compilador, mas o compilador a corrupção detectada no arquivo.  Peça à pessoa que produziu o. netmodule para investigar.  
  
 O compilador não verifica arquivos. netmodule para todos os tipos de danos.  No entanto, ele, verifica que todos os caminhos de controle em uma função contém uma instrução return.  
  
 Para obter mais informações, consulte [. netmodule arquivos como entrada de vinculador](../../build/reference/netmodule-files-as-linker-input.md).