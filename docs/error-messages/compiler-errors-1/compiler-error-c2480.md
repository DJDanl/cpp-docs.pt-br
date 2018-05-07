---
title: C2480 de erro do compilador | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- C2480
dev_langs:
- C++
helpviewer_keywords:
- C2480
ms.assetid: 1a58d1c2-971b-4084-96fa-f94aa51c02f1
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 987cefa42b3f3f8d9588e446ca181c0b7cd48f8c
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
---
# <a name="compiler-error-c2480"></a>C2480 de erro do compilador
'Identificador': 'thread' só é válido para itens de dados de extensão static  
  
 Não é possível usar o `thread` com uma variável automática, o membro de dados não estático, o parâmetro de função ou em declarações de função ou definições de atributo.  
  
 Use o `thread` atributo para variáveis globais, os membros de dados estáticos e variáveis estáticas locais apenas.  
  
 O exemplo a seguir gera C2480:  
  
```  
// C2480.cpp  
// compile with: /c  
__declspec( thread ) void func();   // C2480  
__declspec( thread ) static int i;   // OK  
```