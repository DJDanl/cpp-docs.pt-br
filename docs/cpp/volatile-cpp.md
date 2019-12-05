---
title: volatile (C++)
ms.date: 05/07/2019
f1_keywords:
- volatile_cpp
helpviewer_keywords:
- interrupt handlers and volatile keyword [C++]
- volatile keyword [C++]
- volatile objects
- objects [C++], volatile
ms.assetid: 81db4a85-ed5a-4a2c-9a53-5d07a771d2de
ms.openlocfilehash: 572fe244a076492e3f3316dd6d00f6fe7d7c3c9c
ms.sourcegitcommit: a6d63c07ab9ec251c48bc003ab2933cf01263f19
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/05/2019
ms.locfileid: "74857197"
---
# <a name="volatile-c"></a>volatile (C++)

Um qualificador de tipo que você pode usar para declarar que um objeto pode ser modificado no programa pelo hardware.

## <a name="syntax"></a>Sintaxe

```
volatile declarator ;
```

## <a name="remarks"></a>Comentários

Você pode usar a opção de compilador [/volatile](../build/reference/volatile-volatile-keyword-interpretation.md) para modificar como o compilador interpreta essa palavra-chave.

O Visual Studio interpreta a palavra-chave **volatile** de forma diferente, dependendo da arquitetura de destino. Para o ARM, se nenhuma opção de compilador **/volatile** for especificada, o compilador executará como se **/volatile: ISO** fosse especificado. Para arquiteturas diferentes de ARM, se nenhuma opção de compilador **/volatile** for especificada, o compilador executará como se **/volatile: MS** fosse especificado; Portanto, para arquiteturas diferentes do ARM, é altamente recomendável que você especifique **/volatile: ISO**e use primitivos de sincronização explícitos e intrínsecos do compilador quando estiver lidando com a memória que é compartilhada entre threads.

Você pode usar o qualificador **volátil** para fornecer acesso a locais de memória que são usados por processos assíncronos, como manipuladores de interrupção.

Quando **volátil** é usado em uma variável que também tem a palavra-chave [__restrict](../cpp/extension-restrict.md) , **volatile** tem precedência.

Se um membro **struct** for marcado como **volátil**, o **volátil** será propagado para toda a estrutura. Se uma estrutura não tiver um comprimento que possa ser copiado na arquitetura atual usando uma instrução, **volatile** pode ser completamente perdido nessa estrutura.

A palavra-chave **volatile** pode não ter nenhum efeito em um campo se uma das seguintes condições for verdadeira:

- O tamanho do campo volátil excede o tamanho máximo que pode ser copiado na arquitetura atual usando uma instrução.

- O comprimento da **estrutura**de conteúdo mais externa, ou se for um membro de um **struct**possivelmente aninhado, excede o tamanho máximo que pode ser copiado na arquitetura atual usando uma instrução.

Embora o processador não reordene os acessos de memória não armazenáveis em cache, as variáveis não armazenáveis em cache devem ser marcadas como **voláteis** para garantir que o compilador não reordene os acessos de memória.

Os objetos declarados como **voláteis** não são usados em determinadas otimizações porque seus valores podem ser alterados a qualquer momento.  O sistema sempre lê o valor atual de um objeto volátil quando solicitado, mesmo que uma instrução anterior tenha solicitado um valor do mesmo objeto.  Além disso, o valor do objeto é gravado imediatamente na atribuição.

## <a name="iso-compliant"></a>Compatível com ISO

Se você estiver familiarizado com a C# palavra-chave volátil ou estiver familiarizado com o comportamento de **volátil** em versões anteriores do C++ compilador da Microsoft (MSVC), lembre-se de que a palavra-chave **volátil** padrão ISO 11 do c++ é diferente e tem suporte em MSVC quando a opção de compilador [/volatile: ISO](../build/reference/volatile-volatile-keyword-interpretation.md) é especificada. (Para ARM, ela é especificada por padrão). A palavra-chave **volátil** no código ISO 11 do c++ é ser usada somente para acesso de hardware; Não o use para comunicação entre threads. Para comunicação entre threads, use mecanismos como [std:: Atomic\<t >](../standard-library/atomic.md) da [ C++ biblioteca padrão](../standard-library/cpp-standard-library-reference.md).

## <a name="end-of-iso-compliant"></a>Fim de compatível com ISO

**Seção específica da Microsoft**

Quando a opção de compilador **/volatile: MS** é usada – por padrão, quando há arquiteturas diferentes de ARM, o compilador gera código extra para manter a ordenação entre referências a objetos voláteis, além de manter a ordenação para referências a outros objetos globais. Em particular:

- Uma gravação em um objeto volátil (também conhecida como gravação volátil) tem semântica de versão; ou seja, uma referência a um objeto global ou estático que ocorre antes de uma gravação em um objeto volátil na sequência da instrução ocorrerá antes dessa gravação volátil no binário compilado.

- Uma leitura de um objeto volátil (também conhecida como leitura volátil) tem semântica de aquisição; ou seja, uma referência a um objeto global ou estático que ocorre depois de uma leitura de memória volátil na sequência da instrução ocorrerá depois dessa leitura volátil no binário compilado.

Isso permite que os objetos voláteis sejam usados para versões e bloqueios de memória em aplicativos multithread.

> [!NOTE]
>  Quando ele se baseia na garantia avançada que é fornecida quando a opção de compilador **/volatile: MS** é usada, o código não é portátil.

**Fim da seção específica da Microsoft**

## <a name="see-also"></a>Consulte também

[Palavras-chave](../cpp/keywords-cpp.md)<br/>
[const](../cpp/const-cpp.md)<br/>
[Ponteiros const e volatile](../cpp/const-and-volatile-pointers.md)