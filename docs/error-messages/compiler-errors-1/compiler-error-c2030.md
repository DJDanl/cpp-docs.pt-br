---
title: Erro do compilador C2030 | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- C2030
dev_langs:
- C++
helpviewer_keywords:
- C2030
ms.assetid: 5806cead-64df-4eff-92de-52c9a3f5ee62
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: ceccc1088e32382167e7e6400360b30de07fde1d
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
ms.locfileid: "33167886"
---
# <a name="compiler-error-c2030"></a>Erro do Compilador C2030
um destruidor com acessibilidade 'privada protegida' não pode ser um membro de uma classe declarada 'lacrada'  
  
 Uma classe de tempo de execução do Windows é declarado como `sealed` não pode ter um destruidor privado e protegido. Somente públicas destruidores não virtual privados e virtuais são permitidas em tipos lacrados. Para obter mais informações, consulte [classes e estruturas Ref](../../cppcx/ref-classes-and-structs-c-cx.md).  
  
 Para corrigir esse erro, altere a acessibilidade do destruidor.