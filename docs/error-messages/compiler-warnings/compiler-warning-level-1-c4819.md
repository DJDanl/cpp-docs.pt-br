---
title: "Compilador aviso (nível 1) C4819 | Documentos do Microsoft"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords:
- C4819
dev_langs:
- C++
helpviewer_keywords:
- C4819
ms.assetid: c0316e85-249c-414d-9df0-622d077c6bc2
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
ms.openlocfilehash: 56264eae92e26561048c81541f0efc53085d28d1
ms.lasthandoff: 02/25/2017

---
# <a name="compiler-warning-level-1-c4819"></a>C4819 do compilador (nível 1) de aviso
O arquivo contém um caractere que não pode ser representado na página de código atual (número). Salve o arquivo no formato Unicode para evitar a perda de dados.  
  
 C4819 ocorre quando um arquivo de origem ANSI é compilado em um sistema com uma página de código que não pode representar todos os caracteres no arquivo.  
  
 Para resolver C4819, salve o arquivo no formato Unicode. No Visual Studio, escolha **arquivo**, **opções de salvamento avançadas**. No **opções de salvamento avançadas** caixa de diálogo, selecione uma codificação que pode representar todos os caracteres no arquivo — por exemplo, UTF-8 — e, em seguida, escolha **Okey**.
