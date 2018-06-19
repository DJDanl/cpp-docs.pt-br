---
title: Carregando todas as importações para uma DLL carregada com atraso | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-tools
ms.topic: reference
dev_langs:
- C++
helpviewer_keywords:
- __HrLoadAllImportsForDll linker option
ms.assetid: 975fcd97-1a56-4a16-9698-e1a249d2d592
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 6f054479a6681ba6de57690295fe3ce9f6c83696
ms.sourcegitcommit: be2a7679c2bd80968204dee03d13ca961eaa31ff
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/03/2018
ms.locfileid: "32374366"
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