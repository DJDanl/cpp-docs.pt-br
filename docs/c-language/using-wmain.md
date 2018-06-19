---
title: Usando wmain | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-language
ms.topic: language-reference
dev_langs:
- C++
helpviewer_keywords:
- wmain function
ms.assetid: d0300812-adc4-40c6-bba3-b2da25468c80
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: c1fd0c47ac994e18bc9d520230508428eaed70b2
ms.sourcegitcommit: be2a7679c2bd80968204dee03d13ca961eaa31ff
ms.translationtype: HT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/03/2018
ms.locfileid: "32389586"
---
# <a name="using-wmain"></a>Usando wmain
**Seção específica da Microsoft**  
  
 No modelo de programação Unicode, é possível definir uma versão de caractere largo da função **main**. Use **wmain** em vez de **main** se você quiser escrever um código portátil que obedeça ao modelo de programação Unicode.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
wmain( int argc, wchar_t *argv[ ], wchar_t *envp[ ] )  
```  
  
## <a name="remarks"></a>Comentários  
 Parâmetros formais são declarados para **wmain** usando um formato semelhante ao de **main**. Em seguida, pode passar argumentos de caractere largo e, opcionalmente, um ponteiro de ambiente de caractere largo para o programa. Os parâmetros `argv` e `envp` de **wmain** são do tipo `wchar_t*`. Por exemplo:  
  
 Se seu programa usa uma função **main**, o ambiente de caractere multibyte é criado pela biblioteca em tempo de execução na inicialização do programa. Uma cópia de caractere amplo do ambiente é criada apenas quando necessário (por exemplo, por uma chamada para as funções `_wgetenv` ou `_wputenv`). Na primeira chamada para `_wputenv`, ou na primeira chamada para `_wgetenv` se um ambiente MBCS já existir, um ambiente correspondente de cadeia de caracteres largos será criado. Em seguida, a variável global `_wenviron`, uma versão de caractere largo da variável global `_environ`, apontará para esse ambiente. Nesse momento, duas cópias do ambiente (MBCS e Unicode) existirão simultaneamente e serão mantidas pelo sistema operacional durante toda a vida do programa.  
  
 Da mesma forma, se seu programa usar uma função **wmain**, um ambiente de caractere amplo será criado na inicialização do programa e apontado pela variável global `_wenviron`. Um ambiente de MBCS (ASCII) é criado na primeira chamada para `_putenv` ou `getenv` e apontado pela variável global `_environ`.  
  
 Para obter mais informações sobre o ambiente de MBCS, consulte [Internacionalização](../c-runtime-library/internationalization.md) na *Referência da biblioteca em tempo de execução.*  
  
 **Fim da seção específica da Microsoft**  
  
## <a name="see-also"></a>Consulte também  
 [Função main e execução do programa](../c-language/main-function-and-program-execution.md)