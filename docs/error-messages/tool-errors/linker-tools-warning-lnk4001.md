---
title: Aviso LNK4001 das ferramentas de vinculador | Documentos do Microsoft
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-tools
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords:
- LNK4001
dev_langs:
- C++
helpviewer_keywords:
- LNK4001
ms.assetid: 0a8b1c3a-64ce-4311-b7c0-065995059246
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
ms.openlocfilehash: 7c00778af6740f1941b8f62836d4a169a1ca8f6b
ms.contentlocale: pt-br
ms.lasthandoff: 02/25/2017

---
# <a name="linker-tools-warning-lnk4001"></a>Aviso LNK4001 (Ferramentas de Vinculador)
nenhum arquivo de objeto especificado; bibliotecas usadas  
  
 O vinculador foi passado um ou mais arquivos. lib, mas nenhum arquivo. obj.  
  
 Como o vinculador não é capaz de acessar informações em um arquivo. lib que é capaz de acessar um arquivo. obj, esse aviso indica que você precisa especificar explicitamente as outras opções de vinculador. Por exemplo, você terá que especificar o [/máquina](../../build/reference/machine-specify-target-platform.md), [/out](../../build/reference/out-output-file-name.md), ou [/ENTRY](../../build/reference/entry-entry-point-symbol.md) opções.
