---
title: "PRJ0002 de erro de compilação de projeto | Documentos do Microsoft"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords:
- PRJ0002
dev_langs:
- C++
helpviewer_keywords:
- PRJ0002
ms.assetid: 1c820b1f-9a24-4681-80ed-4fcbfd7caa00
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
ms.openlocfilehash: d05b6c882397b16745c0adb94d12998a6cb52bc4
ms.lasthandoff: 02/25/2017

---
# <a name="project-build-error-prj0002"></a>Erro de Build PRJ0002 no Projeto
resultado do erro retornado da linha de comando' '.  
  
 Um comando, ***linha de comando***, que foi formado de entrada do usuário no **páginas de propriedade** caixa de diálogo, retornada um código de erro, mas nenhuma informação será exibida na janela de saída.  
  
 A resolução para esse erro depende de qual ferramenta gerou o erro. Para MIDL, você terá uma ideia do que deu errado se /o (redirecionamento de saída) é definido.  
  
 Um arquivo em lotes, como uma etapa de compilação personalizada ou evento de compilação, que não é informativo sobre condições de falha também pode ser o motivo para esse erro.
