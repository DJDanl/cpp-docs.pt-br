---
title: Compatibilidade
description: Descreve a compatibilidade da Microsoft Universal C Runtime Library (UCRT) com a biblioteca C padrão, POSIX, o CRT seguro e aplicativos da Store.
ms.date: 9/11/2020
ms.topic: conceptual
helpviewer_keywords:
- CRT, compatibility
- compatibility, C runtime libraries
- compatibility
ms.assetid: 346709cb-edda-4909-9a19-3d253eddb6b7
ms.openlocfilehash: 10c21f3f471c105ac4e40bda449aaf8987edba25
ms.sourcegitcommit: 9451db8480992017c46f9d2df23fb17b503bbe74
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/30/2020
ms.locfileid: "91590037"
---
# <a name="compatibility"></a>Compatibilidade

A Universal C Runtime Library (UCRT) oferece suporte à maior parte da biblioteca padrão C necessária para a conformidade com o C++. Ele implementa a biblioteca C99 (ISO/IEC 9899:1999), com determinadas exceções:

- compatibilidade de tipo estrita no \<complex.h> .
- `aligned_alloc`, que provavelmente não será implementado porque o sistema operacional Windows não dá suporte a alocações alinhadas. Use o não padrão `_aligned_malloc` , em vez disso.
- `strerrorlen_s`
- suporte Atomic no \<stdatomic.h>
- suporte a Threading no \<threads.h>

O UCRT também implementa um grande subconjunto do POSIX. 1 (ISO/IEC 9945-1:1996, a biblioteca de programa do aplicativo do sistema POSIX) C. No entanto, ele não está totalmente em conformidade com qualquer padrão POSIX específico. O UCRT também implementa várias funções e macros específicas da Microsoft que não fazem parte de um padrão.

Funções específicas para a implementação pela Microsoft do Visual C++ são encontradas na biblioteca vcruntime.  Muitas dessas funções são para uso interno e não podem ser chamadas pelo código do usuário. Algumas estão documentadas para uso em compatibilidade de implementação e depuração.

O padrão C++ reserva nomes que começam com um sublinhado no namespace global para a implementação. As funções POSIX e a biblioteca de tempo de execução específica da Microsoft estão no namespace global, mas não fazem parte da biblioteca de tempo de execução C padrão. É por isso que as implementações preferenciais da Microsoft dessas funções têm um sublinhado à esquerda. Para fins de portabilidade, o UCRT também dá suporte a nomes padrão, mas o compilador do Microsoft C++ emite um aviso de substituição quando o código que os usa é compilado. Somente os nomes padrão são preteridos, e não as próprias funções. Para suprimir o aviso, defina `_CRT_NONSTDC_NO_WARNINGS` antes de incluir cabeçalhos no código que usa os nomes originais POSIX.

Determinadas funções na biblioteca C padrão têm um histórico de uso não seguro, devido a parâmetros mal empregados e buffers não verificados. Essas funções geralmente são a origem dos problemas de segurança no código. A Microsoft criou um conjunto de versões mais seguras dessas funções que verificam o uso de parâmetros. Eles invocam o manipulador de parâmetro inválido quando um problema é detectado em tempo de execução.  Por padrão, o compilador do Microsoft C++ emite um aviso de substituição quando uma função é usada com uma variante mais segura disponível. Ao compilar seu código como C++, você pode definir `_CRT_SECURE_CPP_OVERLOAD_STANDARD_NAMES` como 1 para eliminar a maioria dos avisos. Essa macro permite sobrecargas de modelo para chamar as variantes mais seguras e, ao mesmo tempo, manter o código-fonte portátil. Para suprimir o aviso, defina `_CRT_SECURE_NO_WARNINGS` antes de incluir cabeçalhos no código que usa essas funções. Para obter mais informações, consulte [Recursos de segurança no CRT](../c-runtime-library/security-features-in-the-crt.md).

Exceto conforme indicado na documentação para funções específicas, o UCRT é compatível com a API do Windows.  Determinadas funções não têm suporte em aplicativos da Windows Store ou do Plataforma Universal do Windows ([UWP](/uwp)). Essas funções são listadas em [funções CRT sem suporte em aplicativos plataforma universal do Windows](../cppcx/crt-functions-not-supported-in-universal-windows-platform-apps.md).

## <a name="related-articles"></a>Artigos relacionados

|Título|Descrição|
|-----------|-----------------|
|[Aplicativos UWP, o Windows Runtime e o tempo de execução do C](../c-runtime-library/windows-store-apps-the-windows-runtime-and-the-c-run-time.md)|Descreve quando as rotinas UCRT não são compatíveis com aplicativos universais do Windows ou Microsoft Store aplicativos.|
|[Conformidade com ANSI C](../c-runtime-library/ansi-c-compliance.md)|Descreve a nomenclatura em conformidade com padrão no UCRT.|
|[UNIX](../c-runtime-library/unix.md)|Fornece diretrizes para portabilidade de programas em UNIX.|
|[Plataformas Windows (CRT)](../c-runtime-library/windows-platforms-crt.md)|Lista os sistemas operacionais aos quais o CRT dá suporte.|
|[Compatibilidade com versões anteriores](../c-runtime-library/backward-compatibility.md)|Descreve como mapear nomes de CRT antigos para os novos.|
|[Recursos da biblioteca CRT](../c-runtime-library/crt-library-features.md)|Fornece uma visão geral dos arquivos de biblioteca (.lib) do CRT e as opções do compilador associado.|
