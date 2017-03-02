---
title: Erro fatal C1067 | Documentos do Microsoft
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords:
- C1067
dev_langs:
- C++
helpviewer_keywords:
- C1067
ms.assetid: e2c94be6-4573-4571-aac9-73d657fe9f96
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
translationtype: Machine Translation
ms.sourcegitcommit: 3168772cbb7e8127523bc2fc2da5cc9b4f59beb8
ms.openlocfilehash: b89c34cdf09152785ef1e2175b2a3259f77f08e9
ms.lasthandoff: 02/25/2017

---
# <a name="fatal-error-c1067"></a>Erro fatal C1067
limite do compilador : limite de 64K no tamanho de um registro de tipos foi excedido  
  
 Esse erro pode ocorrer se um símbolo tem um nome decorado exceder 247 caracteres.  Para resolver, diminua o nome do símbolo.  
  
 Quando o compilador gera informações de depuração, ele emite registros do tipo para definir tipos encontrados no código-fonte.  Por exemplo, registros de tipo incluem estruturas simples e listas de argumentos de funções.  Alguns desses registros de tipo podem ser listas grandes.  
  
 Há um limite de 64K para o tamanho de qualquer tipo de registro.  Se esse limite de 64K for excedido este erro ocorrerá.  
  
 C1067 também pode ocorrer se houver muitos símbolos com nomes longos ou se uma classe, estrutura ou união tem muitos membros.
