---
title: Registrador da ATL e árvores de análise
ms.date: 11/04/2016
helpviewer_keywords:
- parse trees
ms.assetid: 668ce2dd-a1c3-4ca0-8135-b25267cb6a85
ms.openlocfilehash: e1aea573e78e6f6a9a86bc4e3987ee448815f329
ms.sourcegitcommit: c3093251193944840e3d0a068ecc30e6449624ba
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/04/2019
ms.locfileid: "57273316"
---
# <a name="understanding-parse-trees"></a>Noções básicas sobre árvores de análise

Você pode definir uma ou mais árvores de análise em seu script de registrador, onde cada árvore de análise tem a seguinte forma:

```
<root key>{<registry expression>}+
```

em que:

```
<root key> ::= HKEY_CLASSES_ROOT | HKEY_CURRENT_USER |
    HKEY_LOCAL_MACHINE | HKEY_USERS |
    HKEY_PERFORMANCE_DATA | HKEY_DYN_DATA |
    HKEY_CURRENT_CONFIG | HKCR | HKCU |
    HKLM | HKU | HKPD | HKDD | HKCC
<registry expression> ::= <Add Key> | <Delete Key>
<Add Key> ::= [ForceRemove | NoRemove | val]<Key Name> [<Key Value>][{<Add Key>}]
<Delete Key> ::= Delete<Key Name>
<Key Name> ::= '<AlphaNumeric>+'
<AlphaNumeric> ::= any character not NULL, i.e. ASCII 0
<Key Value> ::== <Key Type><Key Name>
<Key Type> ::= s | d
<Key Value> ::= '<AlphaNumeric>'
```

> [!NOTE]
> `HKEY_CLASSES_ROOT` e `HKCR` forem equivalentes; `HKEY_CURRENT_USER` e `HKCU` são equivalentes; e assim por diante.

Uma árvore de análise pode adicionar várias chaves e subchaves para a \<chave raiz >. Dessa forma, ele mantém o identificador de uma subchave aberta até que o analisador conclui a análise de todas as suas subchaves. Essa abordagem é mais eficiente do que o operando em uma única chave de cada vez, conforme mostrado no exemplo a seguir:

```
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

Aqui, o registrador abre inicialmente (cria) `HKEY_CLASSES_ROOT\MyVeryOwnKey`. Em seguida, vê que `MyVeryOwnKey` tiver uma subchave. Em vez de fechar a chave para `MyVeryOwnKey`, o registrador retém o identificador e abre (cria) `HasASubKey` usando esse identificador pai. (O registro do sistema pode ser mais lento quando nenhum identificador pai é aberto.) Assim, abrindo `HKEY_CLASSES_ROOT\MyVeryOwnKey` e, em seguida, abrindo `HasASubKey` com `MyVeryOwnKey` como o pai é mais rápido do que a abertura `MyVeryOwnKey`, fechando `MyVeryOwnKey`e, em seguida, abrindo `MyVeryOwnKey\HasASubKey`.

## <a name="see-also"></a>Consulte também

[Criando scripts do Registrador](../atl/creating-registrar-scripts.md)
