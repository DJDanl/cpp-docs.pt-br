---
title: Erro fatal C1352 | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- C1352
dev_langs:
- C++
helpviewer_keywords:
- C1352
ms.assetid: d044e8b0-b6ef-4d57-8eb5-6254071be707
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 524b0bf5d25953c5c38cbe0e23dc5c7d9f3cb7be
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
ms.locfileid: "33226813"
---
# <a name="fatal-error-c1352"></a>Erro fatal C1352
MSIL inválido ou corrompido na função 'function' do módulo 'file'  
  
 Um. netmodule foi passado para o compilador, mas o compilador a corrupção detectada no arquivo.  Peça à pessoa que produziu o. netmodule para investigar.  
  
 O compilador não verifica arquivos. netmodule para todos os tipos de danos.  No entanto, ele, verifica que todos os caminhos de controle em uma função contém uma instrução return.  
  
 Para obter mais informações, consulte [. netmodule arquivos como entrada de vinculador](../../build/reference/netmodule-files-as-linker-input.md).