---
title: "Recursos de segurança no CRT | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-standard-libraries
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords:
- _CRT_SECURE_NO_DEPRECATE
- _CRT_NONSTDC_NO_WARNINGS
- _CRT_SECURE_NO_WARNINGS
dev_langs:
- C++
helpviewer_keywords:
- security deprecation warnings [C++]
- CRT_NONSTDC_NO_DEPRECATE
- buffers [C++], buffer overruns
- deprecation warnings (security-related), disabling
- _CRT_NONSTDC_NO_WARNINGS
- security [CRT]
- _CRT_SECURE_NO_WARNINGS
- _CRT_NONSTDC_NO_DEPRECATE
- _CRT_SECURE_NO_DEPRECATE
- security-enhanced CRT
- CRT_SECURE_NO_WARNINGS
- CRT_SECURE_NO_DEPRECATE
- deprecation warnings (security-related)
- buffer overruns
- CRT_NONSTDC_NO_WARNINGS
- CRT, security enhancements
- parameters [C++], validation
ms.assetid: d9568b08-9514-49cd-b3dc-2454ded195a3
caps.latest.revision: 
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: 1d32a69e179acee501c17d96218cc4ef2e10f0c3
ms.sourcegitcommit: 185e11ab93af56ffc650fe42fb5ccdf1683e3847
ms.translationtype: HT
ms.contentlocale: pt-BR
ms.lasthandoff: 01/29/2018
---
# <a name="security-features-in-the-crt"></a>funcionalidades de segurança no CRT
Muitas funções de CRT antigas têm versões mais recentes e mais seguras. Se houver uma função de segurança, a versão mais antiga e menos segura estará marcada como preterida, e a nova versão terá o sufixo `_s` ("seguro").  
  
 Nesse contexto, "preterida" significa que não é recomendável usar uma função; isso não indica que a função está programada para ser removida do CRT.  
  
 As funções seguras não evitam ou corrigem erros de segurança; em vez disso, elas capturam erros quando eles ocorrem. Elas realizam verificações adicionais em busca de condições de erro e, caso encontre um, iniciam um manipulador de erro (consulte [Validação de parâmetro](../c-runtime-library/parameter-validation.md)).  
  
 Por exemplo, a função `strcpy` não possui uma maneira de dizer se a cadeia de caracteres que está copiando é muito grande para o buffer de destino. No entanto, sua contraparte segura, `strcpy_s`, usa o tamanho do buffer como parâmetro, para que possa determinar se uma saturação de buffer ocorrerá. Se você usa `strcpy_s` para copiar onze caracteres em um buffer de 10 caracteres, isso é um erro de sua parte; `strcpy_s` não pode corrigir o erro, mas pode detectá-lo e informar a você invocando o manipulador de parâmetro inválido.  
  
## <a name="eliminating-deprecation-warnings"></a>Eliminar avisos de depreciação  
 Há várias maneiras de eliminar os avisos de depreciação das funções mais antigas e menos seguras. A forma mais simples é definir `_CRT_SECURE_NO_WARNINGS` ou usar o pragma [aviso](../preprocessor/warning.md). As duas opções desabilitarão os avisos de depreciação, mas certamente as questões de segurança que dispararam os avisos ainda existirão. É muito melhor deixar os avisos de depreciação habilitados e tirar proveito dos novos recursos de segurança do CRT.  
  
 No C++, a maneira mais fácil de fazer isso é usar [Sobrecargas de modelo seguro](../c-runtime-library/secure-template-overloads.md), que, em muitos casos eliminará os avisos de depreciação substituindo chamadas a funções preteridas por chamadas a novas versões seguras dessas funções. Por exemplo, considere esta chamada preterida para `strcpy`:  
  
```  
char szBuf[10];   
strcpy(szBuf, "test"); // warning: deprecated   
```  
  
 A definição de `_CRT_SECURE_CPP_OVERLOAD_STANDARD_NAMES` como 1 elimina o aviso alterando a chamada de `strcpy` para `strcpy_s`, o que impede estouros de buffer. Para obter mais informações, consulte [Sobrecargas de modelo seguro](../c-runtime-library/secure-template-overloads.md).  
  
 Para as funções preteridas sem sobrecargas de modelo seguro, considere definitivamente a atualização manual do código a fim de usar as versões seguras.  
  
 Outra fonte de avisos de depreciação, não relacionados à segurança, são as funções POSIX. Substitua os nomes de função POSIX por seus equivalentes padrão (por exemplo, mude [access](../c-runtime-library/reference/access-crt.md) para [_access](../c-runtime-library/reference/access-waccess.md)), ou desabilite os avisos de depreciação relacionados ao POSIX definindo `_CRT_NONSTDC_NO_WARNINGS`. Para obter mais informações, consulte [Compatibilidade](compatibility.md).  
  
## <a name="additional-security-features"></a>Recursos de segurança adicionais  
 Alguns dos recursos de segurança incluem o seguinte:  
  
-   `Parameter Validation`. Os parâmetros passados para as funções de CRT são validados nas funções seguras e em muitas versões preexistentes das funções. Essas validações incluem:  
  
    -   Procurar por valores `NULL` passados para as funções.  
  
    -   Verificar a validade dos valores enumerados.  
  
    -   Verificar se os valores integrais estão em intervalos válidos.  
  
-   Para saber mais, confira [Validação do parâmetro](../c-runtime-library/parameter-validation.md).  
  
-   Um manipulador de parâmetros inválidos também é acessível ao desenvolvedor. Ao encontrar um parâmetro inválido, em vez de declarar e sair do aplicativo, o CRT fornece uma maneira de verificar esses problemas com a função [set_invalid_parameter_handler, _set_thread_local_invalid_parameter_handler](../c-runtime-library/reference/set-invalid-parameter-handler-set-thread-local-invalid-parameter-handler.md).  
  
-   `Sized Buffers`. As funções seguras exigem que o tamanho do buffer seja passado para qualquer função que grave em um buffer. As versões seguras validam se o buffer é grande o suficiente antes da gravação, ajudando a evitar erros de saturação de buffer perigosos que podem permitir a execução do código mal-intencionado. Essas funções normalmente retornam um tipo de código de erro `errno` e invocam o manipulador de parâmetro inválido, se o tamanho do buffer for muito pequeno. Funções que leem de buffers de entrada, como `gets`, têm versões seguras que exigem a especificação de um tamanho máximo.  
  
-   `Null termination`. Algumas funções que deixaram cadeias de caracteres possivelmente não finalizadas têm versões seguras que asseguram a terminação nula apropriada das cadeias de caracteres.  
  
-   `Enhanced error reporting`. As funções seguras retornam códigos de erro com mais informações sobre o erro do as funções preexistentes. Agora, as funções seguras, e muitas das funções preexistentes, definem `errno`, e geralmente também retornam um tipo de código `errno`, para fornecer melhor emissão de relatórios de erro.  
  
-   `Filesystem security`. APIs de E/S de arquivo seguro oferecem suporte o acesso ao arquivo seguro no caso padrão.  
  
-   `Windows security`. APIs de processo seguro impõe políticas de segurança e permitem que as ACLs sejam especificadas.  
  
-   `Format string syntax checking`. Cadeias de caracteres inválidas são detectadas, por exemplo, usando os caracteres de campo do tipo incorreto nas cadeias de caracteres de formato `printf`.  
  
## <a name="see-also"></a>Consulte também  
 [Validação de parâmetro](../c-runtime-library/parameter-validation.md)   
 [Sobrecargas de modelo seguro](../c-runtime-library/secure-template-overloads.md)   
 [Recursos da biblioteca CRT](../c-runtime-library/crt-library-features.md)