---
title: "Compatibilidade | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "article"
f1_keywords: 
  - "c.programs"
dev_langs: 
  - "C++"
  - "C"
helpviewer_keywords: 
  - "CRT, compatibilidade"
  - "compatibilidade, bibliotecas de tempo de execução do C"
  - "compatibilidade"
ms.assetid: 346709cb-edda-4909-9a19-3d253eddb6b7
caps.latest.revision: 18
caps.handback.revision: 18
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Compatibilidade
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

A biblioteca de tempo de execução C Universal \(UCRT\) oferece suporte à maioria da biblioteca padrão C necessária para conformidade de C\+\+. Ele implementa a biblioteca de C99 \(ISO\/IEC 9899:1999\), com as exceções das macros de tipo genérico definidas em \< tgmath \> e a compatibilidade de tipo estrito em \< Complex. h \>. O UCRT também implementa um grande subconjunto do POSIX. 1 \(ISO\/IEC 9945\-1:1996, a Interface de programa do aplicativo de sistema POSIX\) biblioteca C, mas não é totalmente compatível com qualquer padrão POSIX específico.  Além disso, o UCRT implementa várias funções específicas da Microsoft e macros que não fazem parte de um padrão.  
  
 Funções específicas para a implementação da Microsoft do Visual C\+\+ são encontradas na biblioteca vcruntime.  Muitas dessas funções são para uso interno e não podem ser chamadas pelo código do usuário. Alguns estão documentados para uso na depuração e a implementação de compatibilidade.  
  
 O padrão C\+\+ reserva nomes que começam com um sublinhado no namespace global para a implementação. Como as funções POSIX estão no namespace global, mas não fazem parte da biblioteca de tempo de execução C padrão, as implementações específicas da Microsoft dessas funções têm um sublinhado à esquerda. Para fins de portabilidade, o UCRT também suporta os nomes padrão, mas o compilador do Visual C\+\+ emite um aviso de substituição quando o código que os utiliza é compilado. Somente os nomes POSIX padrão estão obsoletas, não as funções. Para suprimir o aviso, defina `_CRT_NONSTDC_NO_WARNINGS` antes de incluir os cabeçalhos no código que usa os nomes originais do POSIX.  
  
 Determinadas funções na biblioteca C padrão têm um histórico de uso não seguro, devido a parâmetros incorretas e buffers desmarcadas. Essas funções geralmente são a origem dos problemas de segurança no código. A Microsoft criou um conjunto de versões mais seguras dessas funções que verificam o uso do parâmetro e invocam o manipulador de parâmetro inválido quando é detectado um problema em tempo de execução.  Por padrão, o compilador do Visual C\+\+ emite um aviso de substituição quando uma função é usada com uma variante mais segura disponível. Quando você compila seu código c\+\+, você pode definir `_CRT_SECURE_CPP_OVERLOAD_STANDARD_NAMES` como 1 para eliminar a maioria dos avisos. Isso usa sobrecargas de modelo para chamar as variantes mais seguras, mantendo o código\-fonte portátil. Para suprimir o aviso, defina `_CRT_SECURE_NO_WARNINGS` antes de incluir os cabeçalhos no código que usa essas funções. Para obter mais informações, consulte [Recursos de segurança no CRT](../Topic/Security%20Features%20in%20the%20CRT.md).  
  
 Exceto conforme indicado na documentação para funções específicas, o UCRT é compatível com a API do Windows.  Não há suporte para determinadas funções em aplicativos do Windows 8 Store ou em aplicativos universais do Windows no Windows 10. Essas funções são listadas na [funções de CRT não têm suportadas com \/ZW](http://msdn.microsoft.com/library/windows/apps/jj606124.aspx), que enumera as funções não oferece suportadas a [tempo de execução do Windows](http://msdn.microsoft.com/pt-br/9a1a18b8-9802-4ec5-b9de-0d2dfdf414e9).  
  
## Artigos relacionados  
  
|Título|Descrição|  
|------------|---------------|  
|[Windows Store Apps, the Windows Runtime, and the C Run\-Time](../c-runtime-library/windows-store-apps-the-windows-runtime-and-the-c-run-time.md)|Descreve quando rotinas UCRT não são compatíveis com aplicativos universais do Windows ou aplicativos da Windows Store.|  
|[Conformidade com ANSI C](../c-runtime-library/ansi-c-compliance.md)|Descreve compatíveis com o padrão de nomenclatura de UCRT.|  
|[UNIX](../Topic/UNIX.md)|Fornece diretrizes para portar programas para UNIX.|  
|[Plataformas Windows \(CRT\)](../Topic/Windows%20Platforms%20\(CRT\).md)|Lista os sistemas operacionais que têm o suporte do CRT.|  
|[Compatibilidade com versões anteriores](../c-runtime-library/backward-compatibility.md)|Descreve como mapear nomes de CRT antigos para os novos.|  
|[Recursos da biblioteca CRT](../c-runtime-library/crt-library-features.md)|Fornece uma visão geral dos arquivos de biblioteca \(. lib\) do CRT e as opções do compilador associado.|