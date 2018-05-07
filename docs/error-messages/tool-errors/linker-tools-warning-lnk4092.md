---
title: Aviso LNK4092 das ferramentas de vinculador | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- LNK4092
dev_langs:
- C++
helpviewer_keywords:
- LNK4092
ms.assetid: d569ec47-a338-40e1-940b-8a8061459acb
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 72edd9e75dbc781355396e38f767a64c1ded3aa9
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
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