---
title: C3610 de erro do compilador | Documentos do Microsoft
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords:
- C3610
dev_langs:
- C++
helpviewer_keywords:
- C3610
ms.assetid: 9349a348-9d37-4a00-9eab-481039268d31
caps.latest.revision: 8
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
ms.sourcegitcommit: c243063a9770542f137d5950e8a269f771960f74
ms.openlocfilehash: 31cef33981bbc2063bf68e433f9d3ba32780363d
ms.lasthandoff: 02/25/2017

---
# <a name="compiler-error-c3610"></a>C3610 de erro do compilador
'valuetype': tipo de valor deve ser 'box' antes do método 'method' pode ser chamado  
  
 Por padrão, um tipo de valor não está no heap gerenciado. Antes de chamar métodos de classes de tempo de execução do .NET, como `Object`, você precisa mover o tipo de valor para o heap gerenciado.  
  
 C3610 só está acessível usando a opção de compilador obsoleto **/CLR: oldSyntax**.  

