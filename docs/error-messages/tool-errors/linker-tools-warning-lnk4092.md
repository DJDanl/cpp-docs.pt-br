---
title: Aviso LNK4092 das ferramentas de vinculador | Documentos do Microsoft
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-tools
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords:
- LNK4092
dev_langs:
- C++
helpviewer_keywords:
- LNK4092
ms.assetid: d569ec47-a338-40e1-940b-8a8061459acb
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
ms.openlocfilehash: 64d4e7a96009f8b3f2de1ee83f143427542ded65
ms.contentlocale: pt-br
ms.lasthandoff: 02/25/2017

---
# <a name="linker-tools-warning-lnk4092"></a>Aviso LNK4092 (Ferramentas de Vinculador)
seção gravável compartilhada 'seção' contém realocações; imagem pode não funcionar corretamente  
  
 O vinculador emite esse aviso sempre que houver uma sessão compartilhada para avisá-lo de um problema potencialmente grave.  
  
 É uma maneira de compartilhar dados entre vários processos marcar uma seção como "compartilhada". No entanto, a marcação de uma seção como compartilhada pode causar problemas. Por exemplo, você tem uma DLL que contém declarações assim em uma seção de dados compartilhado:  
  
```  
int var = 1;  
int *pvar = &var;  
```  
  
 O vinculador não pode resolver `pvar` porque seu valor depende de onde a DLL é carregada na memória, então ele coloca um registro de realocação na DLL. Quando a DLL é carregada na memória, o endereço do `var` podem ser resolvidos e `pvar` atribuído. Se outro processo carrega a DLL mesmo, mas não pode carregá-lo no mesmo endereço, a realocação para o endereço de `var` será atualizado para o segundo processo e o espaço de endereço do processo primeiro apontará para o endereço incorreto.
