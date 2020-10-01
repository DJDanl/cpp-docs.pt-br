---
title: funcionalidades de segurança no CRT
description: Uma visão geral das funções CRT seguras no tempo de execução do Microsoft C.
ms.date: 09/29/2020
ms.topic: conceptual
f1_keywords:
- _CRT_SECURE_NO_DEPRECATE
- _CRT_NONSTDC_NO_WARNINGS
- _CRT_SECURE_NO_WARNINGS
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
ms.openlocfilehash: 963f5510350aa3be25586811889189d28a5f7b66
ms.sourcegitcommit: 9451db8480992017c46f9d2df23fb17b503bbe74
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/30/2020
ms.locfileid: "91589881"
---
# <a name="security-features-in-the-crt"></a>funcionalidades de segurança no CRT

Muitas funções de CRT antigas têm versões mais recentes e mais seguras. Se houver uma função de segurança, a versão mais antiga e menos segura estará marcada como preterida, e a nova versão terá o sufixo `_s` ("seguro").

Neste contexto, "preterido" significa que usar a função não é recomendado. Não significa que a função está agendada para ser removida do CRT.

As funções seguras não impedem ou corrigem erros de segurança. Em vez disso, eles capturam erros quando ocorrem. Eles fazem verificações adicionais para condições de erro. Se houver um erro, eles invocarão um manipulador de erro (consulte [validação de parâmetro](../c-runtime-library/parameter-validation.md)).

Por exemplo, a `strcpy` função não pode determinar se a cadeia de caracteres que ela está copiando é muito grande para o buffer de destino. Sua contraparte segura, `strcpy_s` , usa o tamanho do buffer como um parâmetro. Portanto, ele pode determinar se ocorrerá uma saturação do buffer. Se você usar `strcpy_s` para copiar 11 caracteres em um buffer de 10 caracteres, isso é um erro de sua parte; o `strcpy_s` não pode corrigir o erro. Mas ele pode detectar seu erro e informá-lo invocando o manipulador de parâmetro inválido.

## <a name="eliminating-deprecation-warnings"></a>Eliminar avisos de depreciação

Há várias maneiras de eliminar os avisos de depreciação das funções mais antigas e menos seguras. A forma mais simples é definir `_CRT_SECURE_NO_WARNINGS` ou usar o pragma [aviso](../preprocessor/warning.md). O desabilitará os avisos de reprovação, mas os problemas de segurança que causaram os avisos ainda existem. É melhor deixar os avisos de substituição habilitados e aproveitar os novos recursos de segurança do CRT.

No C++, a maneira mais fácil de fazer isso é usar [sobrecargas de modelo seguras](../c-runtime-library/secure-template-overloads.md). Isso eliminará os avisos de reprovação, em muitos casos, substituindo as chamadas para funções preteridas por chamadas para versões seguras dessas funções. Por exemplo, considere esta chamada preterida para `strcpy`:

```
char szBuf[10];
strcpy(szBuf, "test"); // warning: deprecated
```

A definição de `_CRT_SECURE_CPP_OVERLOAD_STANDARD_NAMES` como 1 elimina o aviso alterando a chamada de `strcpy` para `strcpy_s`, o que impede estouros de buffer. Para obter mais informações, consulte [Sobrecargas de modelo seguro](../c-runtime-library/secure-template-overloads.md).

Para as funções preteridas sem sobrecargas de modelo seguro, considere definitivamente a atualização manual do código a fim de usar as versões seguras.

Outra fonte de avisos de depreciação, não relacionados à segurança, são as funções POSIX. Substitua os nomes de função POSIX por seus equivalentes padrão (por exemplo, mude [access](../c-runtime-library/reference/access-crt.md) para [_access](../c-runtime-library/reference/access-waccess.md)), ou desabilite os avisos de depreciação relacionados ao POSIX definindo `_CRT_NONSTDC_NO_WARNINGS`. Para obter mais informações, consulte [Compatibilidade](compatibility.md).

## <a name="additional-security-features"></a>Recursos de segurança adicionais

Alguns dos recursos de segurança incluem:

- `Parameter Validation`. Proteger funções e muitas de suas contrapartes não seguras, validar parâmetros. A validação pode incluir:

  - Verificando valores **nulos** .
  - Verificar a validade dos valores enumerados.
  - Verificar se os valores integrais estão em intervalos válidos.

- Para saber mais, confira [Validação do parâmetro](../c-runtime-library/parameter-validation.md).

- Um manipulador de parâmetros inválidos também é acessível ao desenvolvedor. Quando uma função encontra um parâmetro inválido, em vez de declarar e sair do aplicativo, o CRT permite que você verifique esses problemas por meio de [_set_invalid_parameter_handler _set_thread_local_invalid_parameter_handler](../c-runtime-library/reference/set-invalid-parameter-handler-set-thread-local-invalid-parameter-handler.md).

- `Sized Buffers`. Você deve passar o tamanho do buffer para qualquer função segura que grave em um buffer. As versões seguras validam que o buffer é grande o suficiente antes de gravar nele. O que ajuda a evitar erros de saturação de buffer perigosos que poderiam permitir a execução de código mal-intencionado. Essas funções geralmente retornam um `errno` código de erro e invocam o manipulador de parâmetro inválido se o tamanho do buffer for muito pequeno. Funções que leem de buffers de entrada, como `gets`, têm versões seguras que exigem a especificação de um tamanho máximo.

- `Null termination`. Algumas funções que deixaram cadeias de caracteres não terminadas têm versões seguras, o que garante que as cadeias de caracteres sejam encerradas corretamente.

- `Enhanced error reporting`. As funções seguras retornam códigos de erro com mais informações de erro do que estavam disponíveis com as funções pré-existentes. As funções seguras e muitas das funções preexistentes agora são definidas `errno` e geralmente retornam um `errno` tipo de código também, para fornecer um melhor relatório de erros.

- `Filesystem security`. APIs de E/S de arquivo seguro oferecem suporte o acesso ao arquivo seguro no caso padrão.

- `Windows security`. APIs de processo seguro impõe políticas de segurança e permitem que as ACLs sejam especificadas.

- `Format string syntax checking`. Cadeias de caracteres inválidas são detectadas, por exemplo, usando os caracteres de campo do tipo incorreto nas cadeias de caracteres de formato `printf`.

## <a name="see-also"></a>Confira também

[Validação de parâmetro](../c-runtime-library/parameter-validation.md)<br/>
[Sobrecargas de modelo seguro](../c-runtime-library/secure-template-overloads.md)<br/>
[Recursos da biblioteca CRT](../c-runtime-library/crt-library-features.md)
