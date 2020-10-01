---
title: Inicialização CRT
description: Descreve como o CRT Inicializa o estado global no código nativo.
ms.topic: conceptual
ms.date: 11/04/2016
helpviewer_keywords:
- CRT initialization [C++]
ms.assetid: e7979813-1856-4848-9639-f29c86b74ad7
ms.openlocfilehash: 25f1e2a7e5b7d91c729bb45bd79ba9a8720cead1
ms.sourcegitcommit: 9451db8480992017c46f9d2df23fb17b503bbe74
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/30/2020
ms.locfileid: "91589764"
---
# <a name="crt-initialization"></a>Inicialização CRT

Este tópico descreve como o CRT Inicializa o estado global no código nativo.

Por padrão, o vinculador inclui a biblioteca CRT, que fornece seu próprio código de inicialização. Esse código de inicialização inicializa a biblioteca CRT, chama inicializadores globais e, em seguida, chama a função `main` fornecida pelo usuário para aplicativos de console.

## <a name="initializing-a-global-object"></a>Inicializando um objeto global

Considere o seguinte código:

```
int func(void)
{
    return 3;
}

int gi = func();

int main()
{
    return gi;
}
```

Segundo o padrão C/C++, `func()` deve ser chamado antes que `main()` seja executado. Mas, quem chama?

Uma maneira de determinar o chamador é definir um ponto de interrupção no `func()` , depurar o aplicativo e examinar a pilha. Isso é possível porque o código-fonte CRT está incluído no Visual Studio.

Ao procurar as funções na pilha, você verá que o CRT está chamando uma lista de ponteiros de função. Essas funções são semelhantes a `func()` , ou construtores para instâncias de classe.

O CRT Obtém a lista de ponteiros de função do compilador do Microsoft C++. Quando o compilador vê um inicializador global, ele gera um inicializador dinâmico na `.CRT$XCU` seção, em que `CRT` é o nome da seção e `XCU` é o nome do grupo. Para obter uma lista de inicializadores dinâmicos, execute o comando **DUMPBIN/ALL Main. obj**e, em seguida, pesquise a `.CRT$XCU` seção. Isso se aplica quando Main. cpp é compilado como um arquivo C++, não um arquivo C. Ele será semelhante ao exemplo a seguir:

```
SECTION HEADER #6
.CRT$XCU name
       0 physical address
       0 virtual address
       4 size of raw data
     1F2 file pointer to raw data (000001F2 to 000001F5)
     1F6 file pointer to relocation table
       0 file pointer to line numbers
       1 number of relocations
       0 number of line numbers
40300040 flags
         Initialized Data
         4 byte align
         Read Only

RAW DATA #6
  00000000: 00 00 00 00                                      ....

RELOCATIONS #6
                                               Symbol    Symbol
Offset    Type              Applied To         Index     Name
--------  ----------------  -----------------  --------  -------
00000000  DIR32             00000000           C         ??__Egi@@YAXXZ (void __cdecl `dynamic initializer for 'gi''(void))
```

A CRT define dois ponteiros:

- `__xc_a` em `.CRT$XCA`

- `__xc_z` em `.CRT$XCZ`

Nenhum outro grupo tem outros símbolos definidos, exceto `__xc_a` e `__xc_z` .

Agora, quando lê vários grupos `.CRT`, o vinculador os combina em uma seção e os classifica em ordem alfabética. Isso significa que os inicializadores globais definidos pelo usuário (que o compilador Microsoft C++ coloca em `.CRT$XCU`) sempre virão depois de `.CRT$XCA` e antes de `.CRT$XCZ`.

A seção será semelhante ao exemplo a seguir:

```
.CRT$XCA
            __xc_a
.CRT$XCU
            Pointer to Global Initializer 1
            Pointer to Global Initializer 2
.CRT$XCZ
            __xc_z
```

Portanto, a biblioteca CRT usa `__xc_a` e `__xc_z` para determinar o início e o término da lista de inicializadores globais devido à forma como eles são dispostos na memória depois que a imagem é carregada.

## <a name="see-also"></a>Confira também

[Recursos da biblioteca CRT](../c-runtime-library/crt-library-features.md)
