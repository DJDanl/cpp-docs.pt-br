---
title: "Compilador aviso (nível 3) C4192 | Documentos do Microsoft"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords:
- C4192
dev_langs:
- C++
helpviewer_keywords:
- C4192
ms.assetid: ea5f91fa-8c96-4f3f-ac42-0c8a86d4e5df
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
ms.openlocfilehash: fea75794f6a3edbed99613bdfad0b43784086a70
ms.lasthandoff: 02/25/2017

---
# <a name="compiler-warning-level-3-c4192"></a>Compilador C4192 de aviso (nível 3)
excluindo automaticamente 'name' durante a importação de biblioteca de tipos 'library'  
  
 A `#import` biblioteca contém um item *nome*, que é também definida nos cabeçalhos do sistema Win32. Devido a limitações de bibliotecas de tipos, nomes como **IUnknown** ou GUID geralmente são definidas em uma biblioteca de tipos, duplicar a definição dos cabeçalhos do sistema. `#import`detecta esses itens e recusar incorporá-las nos arquivos de cabeçalho. TLH e. TLI.  
  
 Para substituir esse comportamento, use `#import` atributos [no_auto_exclude](../../preprocessor/no-auto-exclude.md) e [include ()](../../preprocessor/include-parens.md).
