---
title: "R6025 de erro de tempo de execução C | Documentos do Microsoft"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords:
- R6025
dev_langs:
- C++
helpviewer_keywords:
- R6025
ms.assetid: afa06d98-9c36-445b-b3e7-b6409bc8e779
caps.latest.revision: 8
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
ms.openlocfilehash: c2fb577aaf88e7de6c2098fe27dfc6c96c91988c
ms.lasthandoff: 02/25/2017

---
# <a name="c-runtime-error-r6025"></a>R6025 de erro de tempo de execução do C
chamada de função virtual pura  
  
> [!NOTE]
>  Se você receber essa mensagem de erro durante a execução de um aplicativo, o aplicativo foi encerrado porque ele tem um problema interno. O motivo mais comum para esse erro é um bug no aplicativo ou uma instalação corrompida.  
>   
>  Você pode tentar corrigir esse erro com estas etapas:  
>   
>  -   Use o **os aplicativos e recursos** ou **programas e recursos** página de **painel de controle** para reparar ou reinstalar o programa.  
> -   Verificar **Windows Update** no **painel de controle** atualizações de software.  
> -   Verifique se há uma versão atualizada do aplicativo. Se o problema persistir, entre em contato com o fornecedor do aplicativo.  
  
 **Informações para programadores**  
  
 Nenhum objeto instanciado para lidar com a chamada de função virtual pura.  
  
 Esse erro é causado por chamar uma função virtual em uma classe base abstrata através de um ponteiro que é criado por uma conversão para o tipo da classe derivada, mas é, na verdade, um ponteiro para a classe base. Isso pode ocorrer quando a conversão de um **void\* ** em um ponteiro para uma classe quando o **void\* ** foi criado durante a construção da classe base.  
  
 Para obter mais informações, consulte o [suporte da Microsoft](http://go.microsoft.com/fwlink/?LinkId=75220) site.
