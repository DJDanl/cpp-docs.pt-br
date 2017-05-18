---
title: Erro fatal C1033 | Documentos do Microsoft
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-tools
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords:
- C1033
dev_langs:
- C++
helpviewer_keywords:
- C1033
ms.assetid: 09976c03-8450-4cf7-8b43-1b91c2c2b9f9
caps.latest.revision: 9
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
ms.translationtype: Machine Translation
ms.sourcegitcommit: 3168772cbb7e8127523bc2fc2da5cc9b4f59beb8
ms.openlocfilehash: d7df1b8e518c7844f8c4404a9b64485f121071c2
ms.contentlocale: pt-br
ms.lasthandoff: 02/25/2017

---
# <a name="fatal-error-c1033"></a>Erro fatal C1033
não é possível abrir o pdb de banco de dados do programa  
  
 Esse erro pode ser causado por um erro de disco.  
  
 No Visual C++ .NET 2002, a localidade do usuário deve ser definida corretamente quando o nome do arquivo (ou o caminho de diretório para o nome do arquivo) contém caracteres MBCS. Definir a localidade do sistema não é suficiente; a localidade do usuário deve ser configurada para processar caracteres MBCS.  
  
 Para obter mais informações, consulte [http://support.microsoft.com/default.aspx?scid=kb;en-us;246007](http://support.microsoft.com/default.aspx?scid=kb;en-us;246007).
