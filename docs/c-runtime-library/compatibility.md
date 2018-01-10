---
title: Compatibilidade | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-standard-libraries
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords: c.programs
dev_langs: C++
helpviewer_keywords:
- CRT, compatibility
- compatibility, C run-time libraries
- compatibility
ms.assetid: 346709cb-edda-4909-9a19-3d253eddb6b7
caps.latest.revision: "18"
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload: cplusplus
ms.openlocfilehash: f14d330ada8f71cc3556b7151189968b43cff4ca
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: HT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="compatibility"></a>Compatibilidade
A biblioteca UCRT (Biblioteca Em Tempo de Execução do C Universal) dá suporte à maioria das bibliotecas padrão C necessárias para conformidade com C++. Ela implementa a biblioteca C99 (ISO/IEC 9899:1999), com as exceções das macros de tipo genérico definidas em \<tgmath.h> e a compatibilidade de tipo estrito em \<complex.h>. O UCRT também implementa um grande subconjunto da biblioteca C POSIX.1 (ISO/IEC 9945-1:1996, a Interface de Programa Aplicativo do Sistema POSIX), mas ela não está totalmente em conformidade com qualquer padrão POSIX.  Além disso, o UCRT implementa várias funções e macros específicas da Microsoft que não fazem parte de um padrão.  
  
 Funções específicas para a implementação pela Microsoft do Visual C++ são encontradas na biblioteca vcruntime.  Muitas dessas funções são para uso interno e não podem ser chamadas pelo código do usuário. Algumas estão documentadas para uso em compatibilidade de implementação e depuração.  
  
 O padrão C++ reserva nomes que começam com um sublinhado no namespace global para a implementação. Como as funções POSIX estão no namespace global, mas não fazem parte da biblioteca em tempo de execução do C padrão, as implementações específicas da Microsoft dessas funções têm um sublinhado inicial. Para fins de portabilidade, o UCRT também dá suporte a nomes padrão, mas o compilador do Visual C++ emite um aviso de substituição quando o código que os usa é compilado. Somente os nomes POSIX padrão são preteridos, não as funções. Para suprimir o aviso, defina `_CRT_NONSTDC_NO_WARNINGS` antes de incluir cabeçalhos no código que usa os nomes originais POSIX.  
  
 Determinadas funções na biblioteca C padrão têm um histórico de uso não seguro, devido a parâmetros mal empregados e buffers não verificados. Essas funções geralmente são a origem dos problemas de segurança no código. A Microsoft criou um conjunto de versões mais seguras dessas funções que verificam o uso do parâmetro e invocam o manipulador de parâmetro inválido quando um problema é detectado no tempo de execução.  Por padrão, o compilador do Visual C++ emite um aviso de substituição quando uma função é usada com uma variante mais segura disponível. Quando você compila seu código em C++, é possível definir `_CRT_SECURE_CPP_OVERLOAD_STANDARD_NAMES` como 1 para eliminar a maioria dos avisos. Isso usa sobrecargas do modelo para chamar as variantes mais seguras ao manter o código-fonte portátil. Para suprimir o aviso, defina `_CRT_SECURE_NO_WARNINGS` antes de incluir cabeçalhos no código que usa essas funções. Para obter mais informações, consulte [Recursos de segurança no CRT](../c-runtime-library/security-features-in-the-crt.md).  
  
 Exceto conforme indicado na documentação para funções específicas, o UCRT é compatível com a API do Windows.  Não há suporte para determinadas funções em aplicativos da Windows 8 Store ou em aplicativos universais do Windows no Windows 10. Essas funções são listadas em [Funções CRT sem suporte com /ZW](http://msdn.microsoft.com/library/windows/apps/jj606124.aspx), que enumera as funções às quais o [Windows Runtime](http://msdn.microsoft.com/en-us/9a1a18b8-9802-4ec5-b9de-0d2dfdf414e9) não dá suporte.  
  
## <a name="related-articles"></a>Artigos relacionados  
  
|Título|Descrição|  
|-----------|-----------------|  
|[Aplicativos da Windows Store, Windows Runtime e Tempo de Execução C](../c-runtime-library/windows-store-apps-the-windows-runtime-and-the-c-run-time.md)|Descreve quando as rotinas UCRT não são compatíveis com aplicativos universais do Windows ou aplicativos da Windows Store.|  
|[Conformidade com ANSI C](../c-runtime-library/ansi-c-compliance.md)|Descreve a nomenclatura em conformidade com padrão no UCRT.|  
|[UNIX](../c-runtime-library/unix.md)|Fornece diretrizes para portabilidade de programas em UNIX.|  
|[Plataformas Windows (CRT)](../c-runtime-library/windows-platforms-crt.md)|Lista os sistemas operacionais aos quais o CRT dá suporte.|  
|[Compatibilidade com versões anteriores](../c-runtime-library/backward-compatibility.md)|Descreve como mapear nomes de CRT antigos para os novos.|  
|[Recursos da biblioteca CRT](../c-runtime-library/crt-library-features.md)|Fornece uma visão geral dos arquivos de biblioteca (.lib) do CRT e as opções do compilador associado.|