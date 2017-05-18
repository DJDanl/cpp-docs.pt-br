---
title: Erro fatal C1060 | Documentos do Microsoft
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-tools
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords:
- C1060
dev_langs:
- C++
helpviewer_keywords:
- C1060
ms.assetid: feaf305c-c84c-4160-b974-50e283412849
caps.latest.revision: 11
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
ms.openlocfilehash: d01b2443df3217b2279e1f08c9de24069fd2b57d
ms.contentlocale: pt-br
ms.lasthandoff: 02/25/2017

---
# <a name="fatal-error-c1060"></a>Erro fatal C1060
o compilador está fora do espaço de heap  
  
 O sistema operacional ou a biblioteca de tempo de execução não pode preencher uma solicitação de memória.  
  
### <a name="to-fix-this-error-try-the-following-possible-solutions"></a>Para corrigir esse erro tente as seguintes soluções possíveis  
  
1.  Se o compilador também emite erros [C1076](../../error-messages/compiler-errors-1/fatal-error-c1076.md) e [C3859](../../error-messages/compiler-errors-2/compiler-error-c3859.md), use o [/Zm](../../build/reference/zm-specify-precompiled-header-memory-allocation-limit.md) opção de compilador para diminuir o limite de alocação de memória. Mais espaço de heap está disponível para o aplicativo se você diminuir a alocação da memória restante.  
  
     Se o [/Zm](../../build/reference/zm-specify-precompiled-header-memory-allocation-limit.md) opção já estiver definida, tente removê-lo. O espaço de heap pode se esgotar porque o limite de alocação de memória especificado na opção é muito alto. O compilador usa um limite padrão se você remover o [/Zm](../../build/reference/zm-specify-precompiled-header-memory-allocation-limit.md) opção.  
  
2.  Se você estiver compilando em uma plataforma de 64 bits, use o conjunto de ferramentas do compilador de 64 bits. Para obter informações, consulte [como: habilitar um 64-Bit Visual C++ conjunto de ferramentas na linha de comando](../../build/how-to-enable-a-64-bit-visual-cpp-toolset-on-the-command-line.md).  
  
3.  No Windows de 32 bits, tente usar o [3 GB](http://go.microsoft.com/fwlink/?LinkId=177831) . ini.  
  
4.  Aumente o tamanho do arquivo de permuta do Windows.  
  
5.  Feche outros programas em execução.  
  
6.  Elimine arquivos de inclusão desnecessários.  
  
7.  Elimine variáveis globais desnecessárias, por exemplo, alocando memória dinamicamente em vez de declarar uma matriz grande.  
  
8.  Elimine declarações não usadas.  
  
9. Divida o arquivo atual em arquivos menores.
