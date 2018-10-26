---
title: Registrador da ATL e árvores de análise | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-atl
ms.topic: conceptual
dev_langs:
- C++
helpviewer_keywords:
- parse trees
ms.assetid: 668ce2dd-a1c3-4ca0-8135-b25267cb6a85
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 4ab66fa38898c302c180be841d7e06133ee22638
ms.sourcegitcommit: a9dcbcc85b4c28eed280d8e451c494a00d8c4c25
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/25/2018
ms.locfileid: "50078122"
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

