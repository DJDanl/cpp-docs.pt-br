---
title: Compatibilidade
ms.date: 11/04/2016
f1_keywords:
- c.programs
helpviewer_keywords:
- CRT, compatibility
- compatibility, C run-time libraries
- compatibility
ms.assetid: 346709cb-edda-4909-9a19-3d253eddb6b7
ms.openlocfilehash: 5e9d2edca8da128343bd14ea86a8c1c0023a244b
ms.sourcegitcommit: 7d64c5f226f925642a25e07498567df8bebb00d4
ms.translationtype: HT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/08/2019
ms.locfileid: "65446673"
---
# <a name="compatibility"></a>Compatibilidade

A biblioteca UCRT (Biblioteca Em Tempo de Execução do C Universal) dá suporte à maioria das bibliotecas padrão C necessárias para conformidade com C++. Ela implementa a biblioteca C99 (ISO/IEC 9899:1999), com as exceções das macros de tipo genérico definidas em \<tgmath.h> e a compatibilidade de tipo estrito em \<complex.h>. O UCRT também implementa um grande subconjunto da biblioteca C POSIX.1 (ISO/IEC 9945-1:1996, a Interface de Programa Aplicativo do Sistema POSIX), mas ela não está totalmente em conformidade com qualquer padrão POSIX.  Além disso, o UCRT implementa várias funções e macros específicas da Microsoft que não fazem parte de um padrão.

Funções específicas para a implementação pela Microsoft do Visual C++ são encontradas na biblioteca vcruntime.  Muitas dessas funções são para uso interno e não podem ser chamadas pelo código do usuário. Algumas estão documentadas para uso em compatibilidade de implementação e depuração.

O padrão C++ reserva nomes que começam com um sublinhado no namespace global para a implementação. Como as funções POSIX estão no namespace global, mas não fazem parte da biblioteca em tempo de execução do C padrão, as implementações específicas da Microsoft dessas funções têm um sublinhado inicial. Para fins de portabilidade, o UCRT também dá suporte a nomes padrão, mas o compilador do Microsoft C++ emite um aviso de substituição quando o código que os usa é compilado. Somente os nomes POSIX padrão são preteridos, não as funções. Para suprimir o aviso, defina `_CRT_NONSTDC_NO_WARNINGS` antes de incluir cabeçalhos no código que usa os nomes originais POSIX.

Determinadas funções na biblioteca C padrão têm um histórico de uso não seguro, devido a parâmetros mal empregados e buffers não verificados. Essas funções geralmente são a origem dos problemas de segurança no código. A Microsoft criou um conjunto de versões mais seguras dessas funções que verificam o uso do parâmetro e invocam o manipulador de parâmetro inválido quando um problema é detectado no tempo de execução.  Por padrão, o compilador do Microsoft C++ emite um aviso de substituição quando uma função é usada com uma variante mais segura disponível. Quando você compila seu código em C++, é possível definir `_CRT_SECURE_CPP_OVERLOAD_STANDARD_NAMES` como 1 para eliminar a maioria dos avisos. Isso usa sobrecargas do modelo para chamar as variantes mais seguras ao manter o código-fonte portátil. Para suprimir o aviso, defina `_CRT_SECURE_NO_WARNINGS` antes de incluir cabeçalhos no código que usa essas funções. Para obter mais informações, consulte [Recursos de segurança no CRT](../c-runtime-library/security-features-in-the-crt.md).

Exceto conforme indicado na documentação para funções específicas, o UCRT é compatível com a API do Windows.  Algumas funções não são compatíveis com os aplicativos da Store para o Windows 8 ou com os aplicativos da UWP (Plataforma Universal do Windows) no Windows 10. Essas funções estão listadas na página [Funções de CRT sem suporte em aplicativos da Plataforma Universal do Windows](../cppcx/crt-functions-not-supported-in-universal-windows-platform-apps.md), que enumera as funções com as quais o Windows Runtime e a [UWP](/uwp) não são compatíveis.

## <a name="related-articles"></a>Artigos relacionados

|Título|Descrição|
|-----------|-----------------|
|[Os aplicativos UWP, o Windows Runtime e o tempo de execução C](../c-runtime-library/windows-store-apps-the-windows-runtime-and-the-c-run-time.md)|Descreve quando as rotinas de UCRT não são compatíveis com aplicativos universais do Windows ou com aplicativos da Microsoft Store.|
|[Conformidade com ANSI C](../c-runtime-library/ansi-c-compliance.md)|Descreve a nomenclatura em conformidade com padrão no UCRT.|
|[UNIX](../c-runtime-library/unix.md)|Fornece diretrizes para portabilidade de programas em UNIX.|
|[Plataformas Windows (CRT)](../c-runtime-library/windows-platforms-crt.md)|Lista os sistemas operacionais aos quais o CRT dá suporte.|
|[Compatibilidade com versões anteriores](../c-runtime-library/backward-compatibility.md)|Descreve como mapear nomes de CRT antigos para os novos.|
|[Recursos da biblioteca CRT](../c-runtime-library/crt-library-features.md)|Fornece uma visão geral dos arquivos de biblioteca (.lib) do CRT e as opções do compilador associado.|