---
title: Recurso compilador Erro Fatal RC1120 | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- RC1120
dev_langs:
- C++
helpviewer_keywords:
- RC1120
ms.assetid: 4e462931-e42e-42e3-8bfc-847677194286
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: d117f7b106e14cde2def5477fab5ad0fc92a6411
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
ms.locfileid: "33321929"
---
# <a name="resource-compiler-fatal-error-rc1120"></a>Erro fatal RC1120 (compilador de recurso)
sem memória, necessário bytes de números  
  
 O compilador de recurso insuficiente de armazenamento para os itens que ele armazena na pilha. Geralmente, isso é o resultado de ter muitos símbolos.  
  
### <a name="to-fix-by-using-the-following-possible-solutions"></a>Para corrigir usando as seguintes soluções possíveis  
  
1.  Aumente o espaço de arquivo de permuta do Windows. Para obter mais informações sobre como aumentar o espaço de arquivo de permuta, consulte memória virtual na Ajuda do Windows.  
  
2.  Eliminar desnecessário incluem arquivos, especialmente desnecessários `#define`s protótipos de função.  
  
3.  Dividir o arquivo atual em dois ou mais arquivos e compilá-los separadamente.  
  
4.  Remova outros programas ou drivers em execução no sistema, o que poderia ser consumindo uma quantidade significativa de memória.