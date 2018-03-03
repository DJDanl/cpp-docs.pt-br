---
title: Recurso compilador Erro Fatal RC1120 | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-tools
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords:
- RC1120
dev_langs:
- C++
helpviewer_keywords:
- RC1120
ms.assetid: 4e462931-e42e-42e3-8bfc-847677194286
caps.latest.revision: 
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: 28a35cc2f932cdf655324d05c10bdb875aa895a6
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="resource-compiler-fatal-error-rc1120"></a>Erro fatal RC1120 (compilador de recurso)
sem memória, necessário bytes de números  
  
 O compilador de recurso insuficiente de armazenamento para os itens que ele armazena na pilha. Geralmente, isso é o resultado de ter muitos símbolos.  
  
### <a name="to-fix-by-using-the-following-possible-solutions"></a>Para corrigir usando as seguintes soluções possíveis  
  
1.  Aumente o espaço de arquivo de permuta do Windows. Para obter mais informações sobre como aumentar o espaço de arquivo de permuta, consulte memória virtual na Ajuda do Windows.  
  
2.  Eliminar desnecessário incluem arquivos, especialmente desnecessários `#define`s protótipos de função.  
  
3.  Dividir o arquivo atual em dois ou mais arquivos e compilá-los separadamente.  
  
4.  Remova outros programas ou drivers em execução no sistema, o que poderia ser consumindo uma quantidade significativa de memória.