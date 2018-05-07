---
title: Erro fatal C1060 | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- C1060
dev_langs:
- C++
helpviewer_keywords:
- C1060
ms.assetid: feaf305c-c84c-4160-b974-50e283412849
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 5aa168c185bafbfd6fadf3f0d5f1320ba4f43d60
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
---
# <a name="fatal-error-c1060"></a>Erro fatal C1060
o compilador está fora do espaço de heap  
  
 O sistema operacional ou a biblioteca de tempo de execução não pode preencher uma solicitação de memória.  
  
### <a name="to-fix-this-error-try-the-following-possible-solutions"></a>Para corrigir esse erro tente as seguintes soluções possíveis  
  
1.  Se o compilador emite também erros [C1076](../../error-messages/compiler-errors-1/fatal-error-c1076.md) e [C3859](../../error-messages/compiler-errors-2/compiler-error-c3859.md), use o [/Zm](../../build/reference/zm-specify-precompiled-header-memory-allocation-limit.md) opção de compilador para diminuir o limite de alocação de memória. Mais espaço de heap está disponível para o aplicativo se você diminuir a alocação da memória restante.  
  
     Se o [/Zm](../../build/reference/zm-specify-precompiled-header-memory-allocation-limit.md) opção já está definida, tente removê-lo. O espaço de heap pode se esgotar porque o limite de alocação de memória especificado na opção é muito alto. O compilador usa um limite padrão se você remover o [/Zm](../../build/reference/zm-specify-precompiled-header-memory-allocation-limit.md) opção.  
  
2.  Se você estiver compilando em uma plataforma de 64 bits, use o conjunto de ferramentas do compilador de 64 bits. Para obter informações, consulte [como: habilitar um 64-Bit Visual C++ conjunto de ferramentas na linha de comando](../../build/how-to-enable-a-64-bit-visual-cpp-toolset-on-the-command-line.md).  
  
3.  No Windows de 32 bits, tente usar o [3 GB](http://go.microsoft.com/fwlink/p/?linkid=177831) . ini.  
  
4.  Aumente o tamanho do arquivo de permuta do Windows.  
  
5.  Feche outros programas em execução.  
  
6.  Elimine arquivos de inclusão desnecessários.  
  
7.  Elimine variáveis globais desnecessárias, por exemplo, alocando memória dinamicamente em vez de declarar uma matriz grande.  
  
8.  Elimine declarações não usadas.  
  
9. Divida o arquivo atual em arquivos menores.