---
title: Erro fatal C1037 | Documentos do Microsoft
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-csharp
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords:
- C1037
dev_langs:
- C++
helpviewer_keywords:
- C1037
ms.assetid: 79103bca-ccfb-42e7-aef9-9b90c15b162f
caps.latest.revision: 7
author: corob-msft
ms.author: corob
manager: ghogen
translation.priority.ht:
- de-de
- es-es
- fr-fr
- it-it
- ja-jp
- ko-kr
- ru-ru
- zh-cn
- zh-tw
translation.priority.mt:
- cs-cz
- pl-pl
- pt-br
- tr-tr
translationtype: Machine Translation
ms.sourcegitcommit: 3168772cbb7e8127523bc2fc2da5cc9b4f59beb8
ms.openlocfilehash: 3554fdcb999a0588749fe5718b52c1435b0abf97
ms.lasthandoff: 02/25/2017

---
# <a name="fatal-error-c1037"></a>Erro fatal C1037
não é possível abrir o arquivo de objeto  
  
 O arquivo de objeto especificado por [/Fo](../../build/reference/fo-object-file-name.md) não pode ser aberto.  
  
### <a name="to-fix-by-checking-the-following-possible-causes"></a>Para corrigir verificando as possíveis causas a seguir  
  
1.  Nome de arquivo inválido.  
  
2.  Memória insuficiente para abrir o arquivo.  
  
3.  Outro processo está usando o arquivo.  
  
4.  Um arquivo somente leitura tem o mesmo nome.  
  
 No Visual C++ .NET (versão 1300 do compilador), há um bug que requer que a localidade do usuário para definir corretamente quando o nome do arquivo (ou o caminho de diretório para o nome do arquivo) contém caracteres MBCS. Definir a localidade do sistema não é suficiente; a localidade do usuário deve ser configurada para processar caracteres MBCS.
