---
title: C2030 de erro do compilador | Documentos do Microsoft
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords:
- C2030
dev_langs:
- C++
helpviewer_keywords:
- C2030
ms.assetid: 5806cead-64df-4eff-92de-52c9a3f5ee62
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
ms.sourcegitcommit: 84964b0a49b236bae056125de8155b18880eb378
ms.openlocfilehash: b38e76d73cf6e933145d8d382b653b8a5ed1892e
ms.lasthandoff: 02/25/2017

---
# <a name="compiler-error-c2030"></a>Erro do Compilador C2030
um destruidor com acessibilidade 'privada protegida' não pode ser membro de uma classe declarada 'lacrada'  
  
 Uma classe de tempo de execução do Windows declarados como `sealed` não pode ter um destruidor privado protegido. Somente públicos destruidores não virtual virtual e privados são permitidos em tipos lacrados. Para obter mais informações, consulte [classes e estruturas Ref](http://msdn.microsoft.com/Library/3d736b82-0bf0-48cf-bac1-cc9d110b70d1).  
  
 Para corrigir esse erro, altere a acessibilidade do destruidor.
