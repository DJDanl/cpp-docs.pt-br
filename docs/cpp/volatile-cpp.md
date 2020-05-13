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
ms.openlocfilehash: 841b2e1e4ffbec87a170c45be8ad0cd0f831a0ef
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81371906"
---
# <a name="volatile-c"></a>volatile (C++)

Um qualificador de tipo que você pode usar para declarar que um objeto pode ser modificado no programa pelo hardware.

## <a name="syntax"></a>Sintaxe

```
volatile declarator ;
```

## <a name="remarks"></a>Comentários

Você pode usar o interruptor do compilador [/volátil](../build/reference/volatile-volatile-keyword-interpretation.md) para modificar a forma como o compilador interpreta esta palavra-chave.

Visual Studio interpreta a palavra-chave **volátil** de forma diferente dependendo da arquitetura de destino. Para ARM, se nenhuma opção de compilador **/volátil** for especificada, o compilador será executado como se **/volátil:iso** fosse especificado. Para arquiteturas diferentes do ARM, se nenhuma opção de compilador **/volátil** for especificada, o compilador será executado como se **/volátil:ms** fosse especificado; portanto, para arquiteturas diferentes da ARM recomendamos fortemente que você especifique **/volátil:iso**, e use primitivos de sincronização explícita e intrínsecas do compilador quando você está lidando com a memória que é compartilhada entre os segmentos.

Você pode usar o qualificador **volátil** para fornecer acesso a locais de memória que são usados por processos assíncronos, como manipuladores de interrupção.

Quando **volátil** é usado em uma variável que também tem a [__restrict](../cpp/extension-restrict.md) palavra-chave, **volátil** tem precedência.

Se um membro **de estrutura** é marcado como **volátil,** então **o volátil** é propagado para toda a estrutura. Se uma estrutura não tiver um comprimento que possa ser copiado na arquitetura atual usando uma instrução, **o volátil** pode ser completamente perdido nessa estrutura.

A palavra-chave **volátil** pode não ter efeito em um campo se uma das seguintes condições for verdadeira:

- O tamanho do campo volátil excede o tamanho máximo que pode ser copiado na arquitetura atual usando uma instrução.

- O comprimento da **estrutura**externa contendo — ou se é membro de uma **estrutura**possivelmente aninhada — excede o tamanho máximo que pode ser copiado na arquitetura atual usando uma instrução.

Embora o processador não reordenem acessos de memória não cacheáveis, variáveis não cacheáveis devem ser marcadas como **voláteis** para garantir que o compilador não reordenem os acessos à memória.

Objetos declarados como **voláteis** não são usados em certas otimizações porque seus valores podem mudar a qualquer momento.  O sistema sempre lê o valor atual de um objeto volátil quando solicitado, mesmo que uma instrução anterior tenha solicitado um valor do mesmo objeto.  Além disso, o valor do objeto é gravado imediatamente na atribuição.

## <a name="iso-compliant"></a>Compatível com ISO

Se você estiver familiarizado com a palavra-chave c# volátil, ou familiarizado com o comportamento de **volátil** em versões anteriores do compilador Microsoft C++ (MSVC), saiba que a palavra-chave **volátil** C++11 ISO Standard é diferente e é suportada no MSVC quando a opção [/volátil:iso](../build/reference/volatile-volatile-keyword-interpretation.md) compilador for especificada. (Para ARM, ela é especificada por padrão). A palavra-chave **volátil** no código Padrão ISO C++11 deve ser usada apenas para acesso ao hardware; não o use para comunicação entre segmentos. Para comunicação entre segmentos, use mecanismos como [std::atomic\<T>](../standard-library/atomic.md) da Biblioteca Padrão [C++.](../standard-library/cpp-standard-library-reference.md)

## <a name="end-of-iso-compliant"></a>Fim de compatível com ISO

**Específico da Microsoft**

Quando a opção **/volátil:ms** compilador é usada — por padrão, quando arquiteturas diferentes da ARM são direcionadas — o compilador gera código extra para manter o pedido entre referências a objetos voláteis, além de manter pedidos a referências a outros objetos globais. Especialmente:

- Uma gravação em um objeto volátil (também conhecida como gravação volátil) tem semântica de versão; ou seja, uma referência a um objeto global ou estático que ocorre antes de uma gravação em um objeto volátil na sequência da instrução ocorrerá antes dessa gravação volátil no binário compilado.

- Uma leitura de um objeto volátil (também conhecida como leitura volátil) tem semântica de aquisição; ou seja, uma referência a um objeto global ou estático que ocorre depois de uma leitura de memória volátil na sequência da instrução ocorrerá depois dessa leitura volátil no binário compilado.

Isso permite que os objetos voláteis sejam usados para versões e bloqueios de memória em aplicativos multithread.

> [!NOTE]
> Quando ele se baseia na garantia aprimorada que é fornecida quando a opção de compilador **/volátil:ms** é usada, o código não é portátil.

**Fim específico da Microsoft**

## <a name="see-also"></a>Confira também

[Palavras-chave](../cpp/keywords-cpp.md)<br/>
[const](../cpp/const-cpp.md)<br/>
[Ponteiros const e volatile](../cpp/const-and-volatile-pointers.md)
