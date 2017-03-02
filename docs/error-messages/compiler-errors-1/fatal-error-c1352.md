---
title: Erro fatal C1352 | Documentos do Microsoft
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-csharp
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords:
- C1352
dev_langs:
- C++
helpviewer_keywords:
- C1352
ms.assetid: d044e8b0-b6ef-4d57-8eb5-6254071be707
caps.latest.revision: 7
author: corob-msft
ms.author: corob
manager: ghogen
translation.priority.ht:
- de-de
- es-es
- fr-fr
- it-it
- ja-jp
- ko-kr
- ru-ru
- zh-cn
- zh-tw
translation.priority.mt:
- cs-cz
- pl-pl
- pt-br
- tr-tr
translationtype: Machine Translation
ms.sourcegitcommit: 3168772cbb7e8127523bc2fc2da5cc9b4f59beb8
ms.openlocfilehash: db8e3be196283a64e58f050918dd951332fb9546
ms.lasthandoff: 02/25/2017

---
# <a name="fatal-error-c1352"></a>Erro fatal C1352
MSIL inválido ou corrompido na função 'function' do módulo 'arquivo'  
  
 Um. netmodule foi passado para o compilador, mas o compilador detectou danos no arquivo.  Peça à pessoa que produziu a. netmodule investigar.  
  
 O compilador não verifica arquivos. netmodule para todos os tipos de corrupção.  No entanto, ele, verifique todos os caminhos de controle em uma função contêm uma instrução return.  
  
 Para obter mais informações, consulte [arquivos. netmodule como entrada de vinculador](../../build/reference/netmodule-files-as-linker-input.md).
