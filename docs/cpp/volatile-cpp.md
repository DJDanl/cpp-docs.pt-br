---
title: volatile (C++)
ms.date: 11/04/2016
f1_keywords:
- volatile_cpp
helpviewer_keywords:
- interrupt handlers and volatile keyword [C++]
- volatile keyword [C++]
- volatile objects
- objects [C++], volatile
ms.assetid: 81db4a85-ed5a-4a2c-9a53-5d07a771d2de
ms.openlocfilehash: 73243841b2ad02bcc165b2910ac54283028e6cf3
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62243920"
---
# <a name="volatile-c"></a>volatile (C++)

Um qualificador de tipo que você pode usar para declarar que um objeto pode ser modificado no programa pelo hardware.

## <a name="syntax"></a>Sintaxe

```
volatile declarator ;
```

## <a name="remarks"></a>Comentários

Você pode usar o [/volatile](../build/reference/volatile-volatile-keyword-interpretation.md) comutador de compilador para modificar como o compilador interpreta essa palavra-chave.

Visual Studio interpreta a **volátil** palavra-chave diferente dependendo da arquitetura de destino. Para ARM, se nenhum **/volatile** opção de compilador for especificada, o compilador executa como se **/volatile: ISO** foram especificadas. Para arquiteturas que não sejam ARM, se nenhum **/volátil** opção de compilador for especificada, o compilador executa como se **/volatile: MS** foram especificados; portanto, para arquiteturas diferentes de ARM é fortemente é recomendável que você especificar **/volatile: ISO**e usar primitivos de sincronização explícitos e intrínsecos do compilador quando você está lidando com a memória que é compartilhada entre threads.

Você pode usar o **volátil** qualificador para fornecer acesso aos locais de memória que são usados por processos assíncronos, como manipuladores de interrupção.

Quando **volátil** é usado em uma variável que também tem a [Restrict](../cpp/extension-restrict.md) palavra-chave **volátil** terá precedência.

Se um **struct** membro estiver marcado como **volátil**, em seguida, **volátil** é propagada para a estrutura inteira. Se uma estrutura não tem um comprimento que pode ser copiado na arquitetura atual usando uma instrução, **volátil** pode ser completamente perdido nessa estrutura.

O **volátil** palavra-chave não pode ter nenhum efeito em um campo se uma das seguintes condições for verdadeira:

- O tamanho do campo volátil excede o tamanho máximo que pode ser copiado na arquitetura atual usando uma instrução.

- O comprimento do que mais externo contém **struct**— ou se for um membro de um possivelmente aninhada **struct**— excede o tamanho máximo que pode ser copiado na arquitetura atual usando uma instrução.

Embora o processador não reorganize acessos de memória, variáveis não armazenável em cache devem ser marcadas como **volátil** garantir que o compilador não reorganize a memória acessa.

Objetos que são declarados como **volátil** não são usados em determinadas otimizações porque seus valores podem ser alterados a qualquer momento.  O sistema sempre lê o valor atual de um objeto volátil quando solicitado, mesmo que uma instrução anterior tenha solicitado um valor do mesmo objeto.  Além disso, o valor do objeto é gravado imediatamente na atribuição.

## <a name="iso-compliant"></a>Compatível com ISO

Se você estiver familiarizado com a c# palavra-chave volátil ou familiarizado com o comportamento de **volátil** em versões anteriores do Visual C++, lembre-se que o ISO padrão C++11 **volátil** palavra-chave é diferente e é com suporte no Visual Studio quando o [/volatile: ISO](../build/reference/volatile-volatile-keyword-interpretation.md) for especificada a opção de compilador. (Para ARM, ela é especificada por padrão). O **volátil** palavra-chave no C + + 11 padrão ISO código deve ser usada somente para acesso de hardware; não a use para comunicação entre threads. Para comunicação entre threads, use mecanismos como [std:: Atomic\<T >](../standard-library/atomic.md) partir os [biblioteca padrão C++](../standard-library/cpp-standard-library-reference.md).

## <a name="end-of-iso-compliant"></a>Fim de compatível com ISO

## <a name="microsoft-specific"></a>Específico da Microsoft

Quando o **/volatile: MS** é usada a opção de compilador — por padrão quando arquiteturas que não sejam ARM são direcionadas — o compilador gera códigos adicionais para manter a ordem entre referências a objetos voláteis, além de manter ordem para referências a outros objetos globais. Em particular:

- Uma gravação em um objeto volátil (também conhecida como gravação volátil) tem semântica de versão; ou seja, uma referência a um objeto global ou estático que ocorre antes de uma gravação em um objeto volátil na sequência da instrução ocorrerá antes dessa gravação volátil no binário compilado.

- Uma leitura de um objeto volátil (também conhecida como leitura volátil) tem semântica de aquisição; ou seja, uma referência a um objeto global ou estático que ocorre depois de uma leitura de memória volátil na sequência da instrução ocorrerá depois dessa leitura volátil no binário compilado.

Isso permite que os objetos voláteis sejam usados para versões e bloqueios de memória em aplicativos multithread.

> [!NOTE]
>  Quando depende da garantia aprimorada que é fornecida quando o **/volatile: MS** opção de compilador é usada, o código é não portátil.

**Fim da seção específica da Microsoft**

## <a name="see-also"></a>Consulte também

[Palavras-chave](../cpp/keywords-cpp.md)<br/>
[const](../cpp/const-cpp.md)<br/>
[Ponteiros const e volatile](../cpp/const-and-volatile-pointers.md)