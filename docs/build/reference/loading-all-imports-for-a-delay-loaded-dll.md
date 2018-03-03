---
title: "Carregando todas as importações para uma DLL carregada com atraso | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-tools
ms.tgt_pltfrm: 
ms.topic: article
dev_langs:
- C++
helpviewer_keywords:
- __HrLoadAllImportsForDll linker option
ms.assetid: 975fcd97-1a56-4a16-9698-e1a249d2d592
caps.latest.revision: 
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: 8afa206e62702407d9974802f9422c8597d772ce
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="loading-all-imports-for-a-delay-loaded-dll"></a>Carregando todas as importações para uma DLL carregada com atraso
O **hrloadallimportsfordll** função, que é definida em delayhlp.cpp, informa o vinculador para carregar todas as importações de uma DLL que foi especificada com o [/delayload](../../build/reference/delayload-delay-load-import.md) opção de vinculador.  
  
 Carregando todas as importações permite que você coloque em um lugar no seu código de tratamento de erros e não precisa usar em torno de chamadas reais para as importações de tratamento de exceção. Ele também evita uma situação em que seu aplicativo parcialmente falha através de um processo como resultado o código auxiliar Falha ao carregar uma importação.  
  
 Chamando **hrloadallimportsfordll** não altera o comportamento de ganchos e erro tratamento; consulte [tratamento de erros e notificação](../../build/reference/error-handling-and-notification.md) para obter mais informações.  
  
 O nome da DLL passado para **hrloadallimportsfordll** é comparado com o nome armazenado dentro da própria DLL e diferencia maiusculas de minúsculas.  
  
 O exemplo a seguir mostra como chamar **hrloadallimportsfordll**:  
  
```  
if (FAILED(__HrLoadAllImportsForDll("delay1.dll"))) {  
   printf ( "failed on snap load, exiting\n" );  
   exit(2);  
}  
```  
  
## <a name="see-also"></a>Consulte também  
 [Suporte do vinculador para DLLs carregadas com atraso](../../build/reference/linker-support-for-delay-loaded-dlls.md)