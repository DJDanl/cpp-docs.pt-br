---
title: Aviso LNK4092 das ferramentas de vinculador | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-tools
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords: LNK4092
dev_langs: C++
helpviewer_keywords: LNK4092
ms.assetid: d569ec47-a338-40e1-940b-8a8061459acb
caps.latest.revision: "6"
author: corob-msft
ms.author: corob
manager: ghogen
ms.openlocfilehash: 3771cfc08a091a796e67e8c11a16c842e6a4346a
ms.sourcegitcommit: ebec1d449f2bd98aa851667c2bfeb7e27ce657b2
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/24/2017
---
# <a name="linker-tools-warning-lnk4092"></a>Aviso LNK4092 (Ferramentas de Vinculador)
seção compartilhada 'seção' contém realocações; imagem pode não ser executada corretamente  
  
 O vinculador emite esse aviso sempre que houver uma seção compartilhada para avisá-lo de um problema potencialmente grave.  
  
 É uma maneira de compartilhar dados entre vários processos marcar uma seção como "compartilhado". No entanto, a marcação de uma seção como compartilhada pode causar problemas. Por exemplo, você tem uma DLL que contém declarações assim em uma seção de dados compartilhado:  
  
```  
int var = 1;  
int *pvar = &var;  
```  
  
 Não é possível resolver o vinculador `pvar` como seu valor depende de onde a DLL é carregada na memória, portanto ele coloca um registro de realocação na DLL. Quando a DLL é carregada na memória, o endereço do `var` podem ser resolvidos e `pvar` atribuído. Se outro processo carrega a DLL do mesmo, mas não pode carregá-lo no mesmo endereço, a realocação para o endereço do `var` serão atualizados para o processo de segundo e o espaço de endereço do processo primeiro apontará para o endereço errado.