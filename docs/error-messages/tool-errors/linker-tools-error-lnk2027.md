---
title: Ferramentas de vinculador LNK2027 erro | Documentos do Microsoft
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-tools
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords:
- LNK2027
dev_langs:
- C++
helpviewer_keywords:
- LNK2027
ms.assetid: e2f857a8-8e8a-4697-bbff-12ccb84a35c1
caps.latest.revision: 6
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
ms.openlocfilehash: 527cf8b8d525d1164ccff93675dda572f2ba75fd
ms.contentlocale: pt-br
ms.lasthandoff: 02/25/2017

---
# <a name="linker-tools-error-lnk2027"></a>Erro das Ferramentas de Vinculador LNK2027
módulo não resolvidos referência 'module'  
  
 Um arquivo passado para o vinculador tem uma dependência em um módulo que não foi especificado com **/ASSEMBLYMODULE** nem passada diretamente para o vinculador.  
  
 Para resolver LNK2027, siga um destes procedimentos:  
  
-   Não passe para o vinculador do arquivo que tem a dependência de módulo.  
  
-   Especificar o módulo com **/ASSEMBLYMODULE**.  
  
-   Se o módulo for um. netmodule seguro, passe o módulo diretamente para o vinculador.  
  
 Para obter mais informações, consulte [/ASSEMBLYMODULE (Adicionar um módulo MSIL ao Assembly)](../../build/reference/assemblymodule-add-a-msil-module-to-the-assembly.md) e [arquivos. netmodule como entrada de vinculador](../../build/reference/netmodule-files-as-linker-input.md).
