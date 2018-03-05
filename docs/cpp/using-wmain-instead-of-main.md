---
title: Usando wmain em vez main | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-language
ms.tgt_pltfrm: 
ms.topic: language-reference
f1_keywords:
- wmain
dev_langs:
- C++
helpviewer_keywords:
- main function, vs. wmain
- wmain function
ms.assetid: 7abb1257-b85c-413a-b913-d45b1582a71d
caps.latest.revision: 
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: d43ab12c42315d735220af8f91c40d8b6a5cc4f9
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="using-wmain-instead-of-main"></a>Usando wmain em vez main
## <a name="microsoft-specific"></a>Específico da Microsoft  
 No modelo de programação Unicode, é possível definir uma versão de caractere largo da função **main**. Use **wmain** em vez de **principal** se você quiser escrever código portátil que esteja de acordo com a especificação Unicode.  
  
 Parâmetros formais são declarados para **wmain** usando um formato semelhante ao de **main**. Em seguida, pode passar argumentos de caractere largo e, opcionalmente, um ponteiro de ambiente de caractere largo para o programa. Os parâmetros `argv` e `envp` de **wmain** são do tipo `wchar_t*`.  
  
 Se seu programa usa uma **principal** função, o ambiente de caracteres multibyte é criado pelo sistema operacional na inicialização do programa. Uma cópia de caractere largo do ambiente é criada somente quando necessário (por exemplo, por uma chamada para o [wgetenv](../c-runtime-library/reference/getenv-wgetenv.md) ou [wputenv](../c-runtime-library/reference/putenv-wputenv.md) funções). Na primeira chamada para `_wputenv`, ou na primeira chamada para `_wgetenv` se um ambiente MBCS já existir, um ambiente correspondente de cadeia de caracteres largos será criado. Em seguida, a variável global `_wenviron`, uma versão de caractere largo da variável global `_environ`, apontará para esse ambiente. Nesse momento, duas cópias do ambiente (MBCS e Unicode) existirão simultaneamente e serão mantidas pelo sistema operacional durante toda a vida do programa.  
  
 Da mesma forma, se seu programa usa uma **wmain** função, um ambiente de MBCS (ASCII) é criado na primeira chamada para `_putenv` ou `getenv`e é apontada pelo `_environ` variável global.  
  
 Para obter mais informações sobre o ambiente de MBCS, consulte [byte e conjuntos de caracteres Multibyte](../c-runtime-library/single-byte-and-multibyte-character-sets.md) no *referência da biblioteca de tempo de execução.*  
  
**Fim da seção específica da Microsoft**  
  
## <a name="see-also"></a>Consulte também  
 [main: inicialização do programa](../cpp/main-program-startup.md)