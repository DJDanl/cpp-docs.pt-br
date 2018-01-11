---
title: Ferramentas de vinculador LNK2027 erro | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-tools
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords: LNK2027
dev_langs: C++
helpviewer_keywords: LNK2027
ms.assetid: e2f857a8-8e8a-4697-bbff-12ccb84a35c1
caps.latest.revision: "6"
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload: cplusplus
ms.openlocfilehash: 554dac121c066dac4c05685be1b937298344a76a
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="linker-tools-error-lnk2027"></a>Erro das Ferramentas de Vinculador LNK2027
módulo não resolvidas referência 'module'  
  
 Um arquivo passado para o vinculador tem uma dependência em um módulo que não foi especificado com **/ASSEMBLYMODULE** nem passado diretamente para o vinculador.  
  
 Para resolver LNK2027, siga um destes procedimentos:  
  
-   Não passe para o vinculador o arquivo que possui a dependência de módulo.  
  
-   Especifique o módulo com **/ASSEMBLYMODULE**.  
  
-   Se o módulo for um. netmodule seguro, passe o módulo diretamente para o vinculador.  
  
 Para obter mais informações, consulte [/ASSEMBLYMODULE (Adicionar um módulo MSIL ao Assembly)](../../build/reference/assemblymodule-add-a-msil-module-to-the-assembly.md) e [. netmodule arquivos como entrada de vinculador](../../build/reference/netmodule-files-as-linker-input.md).