---
title: R6025 de erro de tempo de execução C | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- R6025
dev_langs:
- C++
helpviewer_keywords:
- R6025
ms.assetid: afa06d98-9c36-445b-b3e7-b6409bc8e779
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: abdbdbf918462dfb83eff07190c32af1f1b3d015
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
---
# <a name="c-runtime-error-r6025"></a>R6025 de erro de tempo de execução do C
chamada de função virtual pura  
  
> [!NOTE]
>  Se você receber essa mensagem de erro durante a execução de um aplicativo, o aplicativo foi desligado porque ele tem um problema interno. O motivo mais comum para esse erro é um bug no aplicativo ou uma instalação corrompida.  
>   
>  Você pode tentar corrigir esse erro com estas etapas:  
>   
>  -   Use o **aplicativos e recursos** ou **programas e recursos** página o **painel de controle** para reparar ou reinstalar o programa.  
> -   Verificar **Windows Update** no **painel de controle** para atualizações de software.  
> -   Verifique se há uma versão atualizada do aplicativo. Se o problema persistir, entre em contato com o fornecedor do aplicativo.  
  
 **Informações para os programadores**  
  
 Nenhum objeto instanciado para lidar com a chamada de função virtual pura.  
  
 Esse erro é causado por chamando uma função virtual em uma classe base abstrata através de um ponteiro que é criada por uma conversão para o tipo de classe derivada, mas, na verdade, um ponteiro para a classe base. Isso pode ocorrer quando a conversão de um **void\***  para um ponteiro para uma classe quando o **void\***  foi criado durante a construção da classe base.  
  
 Para obter mais informações, consulte o [o suporte da Microsoft](http://go.microsoft.com/fwlink/p/?linkid=75220) site.