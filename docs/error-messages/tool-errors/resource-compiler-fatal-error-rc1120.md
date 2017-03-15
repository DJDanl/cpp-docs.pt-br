---
title: Recurso compilador Erro Fatal RC1120 | Documentos do Microsoft
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords:
- RC1120
dev_langs:
- C++
helpviewer_keywords:
- RC1120
ms.assetid: 4e462931-e42e-42e3-8bfc-847677194286
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
translationtype: Machine Translation
ms.sourcegitcommit: 3168772cbb7e8127523bc2fc2da5cc9b4f59beb8
ms.openlocfilehash: 270317b1caede6e297038771dd33d8a5098788ac
ms.lasthandoff: 02/25/2017

---
# <a name="resource-compiler-fatal-error-rc1120"></a>Erro fatal RC1120 (compilador de recurso)
sem memória, necessário bytes de números  
  
 O compilador de recurso insuficiente de armazenamento para itens que ele armazena em seu heap. Geralmente, esse é o resultado de ter muitos símbolos.  
  
### <a name="to-fix-by-using-the-following-possible-solutions"></a>Para corrigir, usando as seguintes soluções possíveis  
  
1.  Aumente o espaço de arquivo de permuta do Windows. Para obter mais informações sobre como aumentar o espaço do arquivo de permuta, consulte memória virtual na Ajuda do Windows.  
  
2.  Eliminar desnecessário incluem arquivos, especialmente desnecessários `#define`s protótipos de função.  
  
3.  Dividir o arquivo atual em dois ou mais arquivos e compilá-los separadamente.  
  
4.  Remova outros programas ou drivers em execução no sistema, o que poderia estar consumindo uma quantidade significativa de memória.
