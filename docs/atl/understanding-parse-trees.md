---
title: Registrador de ATL e árvores de análise
ms.date: 11/04/2016
helpviewer_keywords:
- parse trees
ms.assetid: 668ce2dd-a1c3-4ca0-8135-b25267cb6a85
ms.openlocfilehash: ff74ff879e757a569232ff19244d3f7598063465
ms.sourcegitcommit: 6280a4c629de0f638ebc2edd446de2a9b11f0406
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/12/2020
ms.locfileid: "90040282"
---
# <a name="understanding-parse-trees"></a>Compreendendo as árvores de análise

Você pode definir uma ou mais árvores de análise no script do registrador, em que cada árvore de análise tem o seguinte formato:

> \<root key>{\<registry expression>}+

em que:

> \<root key> :: = HKEY_CLASSES_ROOT \| HKEY_CURRENT_USER \|\
> &emsp;HKEY_LOCAL_MACHINE \| HKEY_USERS \|\
> &emsp;HKEY_PERFORMANCE_DATA \| HKEY_DYN_DATA \|\
> &emsp;HKEY_CURRENT_CONFIG \| HKCR \| HKCU \|\
> &emsp;HKLM \| HKU \| HKPD \| HKDD \| HKCC

> \<registry expression>::= \<Add Key> \|\<Delete Key>

> \<Add Key>:: = \[ **ForceRemove** \| **NoRemove** \| **Val**] \<Key Name> [ \<Key Value> ] [{ \<Add Key> }]

> \<Delete Key> :: = **Excluir**\<Key Name>

> \<Key Name> ::= **'**\<AlphaNumeric>+**'**

> \<AlphaNumeric> :: = *qualquer caractere não nulo, ou seja, ASCII 0*

> \<Key Value> ::= \<Key Type>\<Key Name>

> \<Key Type> :: = **s** \| **d**

> \<Key Value> ::= **'**\<AlphaNumeric>**'**

> [!NOTE]
> `HKEY_CLASSES_ROOT` e `HKCR` são equivalentes; `HKEY_CURRENT_USER` e `HKCU` são equivalentes; e assim por diante.

Uma árvore de análise pode adicionar várias chaves e subchaves ao \<root key> . Ao fazer isso, ele mantém o identificador de uma subchave aberto até que o analisador tenha concluído a análise de todas as suas subchaves. Essa abordagem é mais eficiente do que operar em uma única chave por vez, como visto no exemplo a seguir:

```rgs
HKEY_CLASSES_ROOT
{
    'MyVeryOwnKey'
    {
        'HasASubKey'
        {
            'PrettyCool'
        }
    }
}
```

Aqui, o registrador inicialmente é aberto (cria) `HKEY_CLASSES_ROOT\MyVeryOwnKey` . Em seguida, ele vê que `MyVeryOwnKey` tem uma subchave. Em vez de fechar a chave para `MyVeryOwnKey` , o registrador retém o identificador e abre (cria) `HasASubKey` usando esse identificador pai. (O registro do sistema pode ser mais lento quando não há identificador pai aberto.) Portanto, abrir `HKEY_CLASSES_ROOT\MyVeryOwnKey` e abrir `HasASubKey` o com `MyVeryOwnKey` como o pai é mais rápido do que abrir `MyVeryOwnKey` , fechar `MyVeryOwnKey` e abrir `MyVeryOwnKey\HasASubKey` .

## <a name="see-also"></a>Confira também

[Criando scripts de registrador](../atl/creating-registrar-scripts.md)
