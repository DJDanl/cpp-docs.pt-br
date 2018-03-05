---
title: "volátil (C++) | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-language
ms.tgt_pltfrm: 
ms.topic: language-reference
f1_keywords:
- volatile_cpp
dev_langs:
- C++
helpviewer_keywords:
- interrupt handlers and volatile keyword [C++]
- volatile keyword [C++]
- volatile objects
- objects [C++], volatile
ms.assetid: 81db4a85-ed5a-4a2c-9a53-5d07a771d2de
caps.latest.revision: 
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: 02560da98c583281cc05921f2e924a12f41688c3
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="volatile-c"></a>volatile (C++)
Um qualificador de tipo que você pode usar para declarar que um objeto pode ser modificado no programa pelo hardware.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
  
volatile declarator ;  
```  
  
## <a name="remarks"></a>Comentários  
 Você pode usar o [/volátil](../build/reference/volatile-volatile-keyword-interpretation.md) opção de compilador para modificar como o compilador interpreta essa palavra-chave.  
  
 O Visual Studio interpreta a palavra-chave `volatile` de modo diferente de acordo com a arquitetura de destino. Para ARM, se nenhum **/volátil** opção de compilador for especificada, o compilador executa como se **/volatile:iso** foram especificadas. Para arquiteturas diferentes ARM, se nenhum **/volátil** opção de compilador for especificada, o compilador executa como se **/volatile:ms** foram especificados; portanto, para arquiteturas diferentes de ARM é fortemente Recomendamos que você especificar **/volatile:iso**e usar os primitivos de sincronização explícita e intrínsecos do compilador ao lidar com a memória que é compartilhada entre threads.  
  
 Você pode usar o qualificador `volatile` para fornecer acesso aos locais de memória usados por processos assíncronos, como manipuladores de interrupção.  
  
 Quando `volatile` é usado em uma variável que também tenha o [Restrict](../cpp/extension-restrict.md) palavra-chave, `volatile` terá precedência.  
  
 Se um membro `struct` é marcado como `volatile`, `volatile` é propagado para a estrutura inteira. Se uma estrutura não tem um tamanho que pode ser copiado na arquitetura atual usando uma instrução, `volatile` pode ser completamente perdido nessa estrutura.  
  
 A palavra-chave `volatile` pode não ter nenhum efeito sobre um campo se uma das seguintes condições for verdadeira:  
  
-   O tamanho do campo volátil excede o tamanho máximo que pode ser copiado na arquitetura atual usando uma instrução.  
  
-   O tamanho do contentor `struct` mais externo (ou se for um membro de uma `struct` possivelmente aninhada) excede o tamanho máximo que pode ser copiado para a arquitetura atual usando uma instrução.  
  
 Embora o processador não reorganize acessos de memória sem cache, as variáveis sem cache devem ser marcadas como `volatile` para garantir que o compilador não reorganize os acessos de memória.  
  
 Objetos que são declarados como `volatile` não são usados em determinadas otimizações porque seus valores podem ser alterados a qualquer momento.  O sistema sempre lê o valor atual de um objeto volátil quando solicitado, mesmo que uma instrução anterior tenha solicitado um valor do mesmo objeto.  Além disso, o valor do objeto é gravado imediatamente na atribuição.  
  
## <a name="iso-compliant"></a>Compatível com ISO  
 Se você estiver familiarizado com a c# palavra-chave volatile ou familiarizado com o comportamento de `volatile` em versões anteriores do Visual C++, lembre-se que o C++ 11 padrão ISO `volatile` palavra-chave é diferente e tem suporte no Visual Studio quando o [/ volátil: iso](../build/reference/volatile-volatile-keyword-interpretation.md) opção de compilador é especificada. (Para ARM, ela é especificada por padrão). A palavra-chave `volatile` no código C++11 ISO padrão deve ser usada somente para acesso de hardware. Não a use para comunicação entre threads. Para comunicação entre thread, usar mecanismos como [std::atomic\<T >](../standard-library/atomic.md) do [biblioteca padrão C++](../standard-library/cpp-standard-library-reference.md).  
  
## <a name="end-of-iso-compliant"></a>Fim de compatível com ISO  
  
## <a name="microsoft-specific"></a>Específico da Microsoft  
 Quando o **/volatile:ms** é usada a opção de compilador — por padrão quando arquiteturas diferentes ARM são direcionadas — o compilador gera o código extra para manter a ordem entre as referências a objetos voláteis além de manutenção ordenação de referências a outros objetos globais. Em particular:  
  
-   Uma gravação em um objeto volátil (também conhecida como gravação volátil) tem semântica de versão; ou seja, uma referência a um objeto global ou estático que ocorre antes de uma gravação em um objeto volátil na sequência da instrução ocorrerá antes dessa gravação volátil no binário compilado.  
  
-   Uma leitura de um objeto volátil (também conhecida como leitura volátil) tem semântica de aquisição; ou seja, uma referência a um objeto global ou estático que ocorre depois de uma leitura de memória volátil na sequência da instrução ocorrerá depois dessa leitura volátil no binário compilado.  
  
 Isso permite que os objetos voláteis sejam usados para versões e bloqueios de memória em aplicativos multithread.  
  
> [!NOTE]
>  Quando ele se baseia na garantia aprimorada que fornecido quando o **/volatile:ms** opção de compilador é usada, o código é não-portáteis.  
  
**Fim da seção específica da Microsoft**  
  
## <a name="see-also"></a>Consulte também  
 [Palavras-chave](../cpp/keywords-cpp.md)   
 [const](../cpp/const-cpp.md)   
 [Ponteiros const e volatile](../cpp/const-and-volatile-pointers.md)